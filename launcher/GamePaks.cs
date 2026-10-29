using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

// A playable reference retains the imported disc byte for byte. Asset payloads
// already in the ZIP are reused; only the intervening archive ranges are added.
public static class GamePaks {
    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    [return: MarshalAs(UnmanagedType.Bool)]
    static extern bool CreateHardLink(string name, string existing, nint reserved);
    internal sealed record Slice(long Offset, long Bytes, string Entry);
    internal sealed record DataFile(string Name, long Bytes, string Sha256, List<Slice> Slices);
    internal sealed record Manifest(int Format, string Game, string ElfSha256, List<DataFile> Files);
    internal const string Header = "game-data.json";
    static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true };
    static void Require(bool value, string message) { if (!value) throw new IOException(message); }
    static void Safe(string path) {
        Require(!string.IsNullOrWhiteSpace(path) && path.Length < 512 && !path.Contains('\\') &&
            !Path.IsPathRooted(path) && path.Split('/').All(p => p.Length > 0 && p is not "." and not ".." &&
                !p.EndsWith('.') && !p.EndsWith(' ') && p.IndexOfAny(Path.GetInvalidFileNameChars()) < 0 &&
                !Regex.IsMatch(p, @"\A(?:CON|PRN|AUX|NUL|COM[0-9]|LPT[0-9])(?:\.|\z)", RegexOptions.IgnoreCase)), "Unsafe game PAK path.");
    }
    static string Hash(Stream source, CancellationToken cancel) {
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256); byte[] buffer = new byte[1024 * 1024]; int n;
        while ((n = source.Read(buffer)) > 0) { cancel.ThrowIfCancellationRequested(); hash.AppendData(buffer, 0, n); }
        return Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
    }
    internal static void Write(ZipArchive zip, string data, string game, List<OriginalAssetEntry> assets,
                               IProgress<ImportProgress>? progress, CancellationToken cancel) {
        var imported = JsonSerializer.Deserialize<ImportManifest>(File.ReadAllText(Path.Combine(Path.GetDirectoryName(data)!, "import.json")))
            ?? throw new IOException("Missing imported disc manifest. Import the game again before exporting.");
        Require(imported.Game == game && imported.ElfSha256 == DiscImport.ExpectedElf(game), "Wrong imported game identity.");
        var files = new List<DataFile>(); long done = 0, total = imported.Files.Sum(f => f.Length);
        foreach (var file in imported.Files) {
            cancel.ThrowIfCancellationRequested(); string name = file.Name.Replace('\\', '/'); Safe(name);
            using var source = File.OpenRead(Path.Combine(data, name));
            Require(source.Length == file.Length && Hash(source, cancel).Equals(file.Sha256, StringComparison.OrdinalIgnoreCase), "Imported file changed: " + name);
            var slices = new List<Slice>(); long cursor = 0; int gap = 0;
            void Copy(long end) {
                if (end == cursor) return;
                string entry = "_game/" + files.Count + "/" + gap++;
                using var output = zip.CreateEntry(entry, CompressionLevel.Fastest).Open();
                source.Position = cursor; long left = end - cursor; byte[] buffer = new byte[1024 * 1024];
                while (left > 0) {
                    cancel.ThrowIfCancellationRequested(); int n = source.Read(buffer, 0, (int)Math.Min(left, buffer.Length));
                    Require(n > 0, "Truncated game data."); output.Write(buffer, 0, n); left -= n;
                }
                slices.Add(new(cursor, end - cursor, entry)); cursor = end;
            }
            foreach (var asset in assets.Where(a => a.Path.Split('/')[0] == name).OrderBy(a => a.SourceOffset)) {
                Require(asset.SourceOffset >= 0 && asset.Bytes <= source.Length - asset.SourceOffset, "Invalid asset range.");
                // Empty entries and shared/overlapping ranges are legitimate in
                // the originals. Keep their editable copies, but reconstruct a
                // source byte only once, using gaps for any remaining bytes.
                if (asset.Bytes == 0 || asset.SourceOffset < cursor) continue;
                Copy(asset.SourceOffset); slices.Add(new(cursor, asset.Bytes, asset.File)); cursor += asset.Bytes;
            }
            Copy(source.Length); files.Add(new(name, source.Length, file.Sha256.ToLowerInvariant(), slices));
            done += source.Length; progress?.Report(new(done, total, name, "Preserving game boot data"));
        }
        using var writer = new StreamWriter(zip.CreateEntry(Header, CompressionLevel.Fastest).Open());
        writer.Write(JsonSerializer.Serialize(new Manifest(1, game, imported.ElfSha256, files), Json));
    }
    static Manifest Read(ZipArchive zip, string game, string expected) {
        Require(zip.Entries.Count <= 100000, "Too many game PAK members.");
        var members = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var member in zip.Entries) { Safe(member.FullName); Require(members.Add(member.FullName), "Duplicate game PAK member."); }
        var header = zip.GetEntry(Header);
        Require(header != null && header.Length <= 32 * 1024 * 1024, "This PAK has no game boot data. Re-export it with the updated launcher; asset-only and mod PAKs cannot replace an ISO.");
        using var stream = header!.Open();
        var manifest = JsonSerializer.Deserialize<Manifest>(stream, Json);
        Require(manifest is { Format: 1 } && manifest.Game == game && manifest.ElfSha256 == expected &&
            manifest.Files is { Count: > 0 and <= 4096 }, "This game PAK is invalid or belongs to another game.");
        var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase); long total = 0;
        foreach (var file in manifest!.Files) {
            Require(file != null && file.Name != null, "Invalid game PAK file."); Safe(file!.Name!);
            Require(names.Add(file.Name!) && file.Bytes is >= 0 and < 0x100000000L && file.Sha256 != null &&
                Regex.IsMatch(file.Sha256, @"\A[0-9a-f]{64}\z") && file.Slices is { Count: <= 100000 }, "Invalid game PAK file.");
            long cursor = 0;
            foreach (var slice in file.Slices!) {
                Require(slice != null && slice.Entry != null && slice.Offset == cursor && slice.Bytes >= 0 && slice.Bytes <= file.Bytes - cursor, "Invalid game PAK ranges.");
                var member = zip.GetEntry(slice!.Entry!);
                Require(member != null && member.Length == slice.Bytes && ((member.ExternalAttributes >> 16) & 0xF000) != 0xA000, "Missing or invalid game PAK range.");
                cursor += slice.Bytes;
            }
            Require(cursor == file.Bytes, "Incomplete game PAK ranges."); total = checked(total + file.Bytes);
        }
        Require(total <= 8L * 1024 * 1024 * 1024 && names.Contains(GameDefinition.Find(game).ElfName) &&
            names.Contains("NETBIO00.DAT") && names.Contains("NETBIO01.DAT") && (game != "file1" || names.Contains("NETBIO02.DAT")), "Incomplete or oversized game PAK.");
        return manifest;
    }
    public static void Check(string pak, string game) {
        using var zip = ZipFile.OpenRead(pak); _ = Read(zip, game, DiscImport.ExpectedElf(game));
    }
    // Reading ranges sequentially also verifies archive headers, padding and boot files.
    internal static void Verify(ZipArchive zip, string game, IProgress<ImportProgress>? progress, CancellationToken cancel) =>
        Transfer(zip, Read(zip, game, DiscImport.ExpectedElf(game)), null, progress, cancel);
    static void Transfer(ZipArchive zip, Manifest manifest, string? data, IProgress<ImportProgress>? progress, CancellationToken cancel) {
        long completed = 0, total = manifest.Files.Sum(f => f.Bytes); byte[] buffer = new byte[1024 * 1024];
        var clock = System.Diagnostics.Stopwatch.StartNew();
        string stage = data == null ? "Verifying game PAK" : "Preparing game from PAK";
        progress?.Report(new(0, total, "Checking game files", stage));
        foreach (var file in manifest.Files) {
            cancel.ThrowIfCancellationRequested();
            string? target = data == null ? null : Path.Combine(data, file.Name);
            if (target != null) Directory.CreateDirectory(Path.GetDirectoryName(target)!);
            using var output = target == null ? null : new FileStream(target, FileMode.CreateNew, FileAccess.Write);
            using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
            foreach (var slice in file.Slices) {
                using var input = zip.GetEntry(slice.Entry)!.Open(); long count = 0; int n;
                while ((n = input.Read(buffer)) > 0) {
                    cancel.ThrowIfCancellationRequested(); count += n; Require(count <= slice.Bytes, "Oversized game PAK range.");
                    output?.Write(buffer, 0, n); hash.AppendData(buffer, 0, n); completed += n;
                    if (clock.ElapsedMilliseconds >= 100) { progress?.Report(new(completed, total, file.Name, stage)); clock.Restart(); }
                }
                Require(count == slice.Bytes, "Truncated game PAK range.");
            }
            Require(Convert.ToHexString(hash.GetHashAndReset()).Equals(file.Sha256, StringComparison.OrdinalIgnoreCase), "Game PAK checksum failed: " + file.Name);
            progress?.Report(new(completed, total, file.Name, stage));
        }
    }
    public static bool Ready(Settings settings, string? game = null) {
        game ??= settings.Game.Id;
        try {
            var source = new FileInfo(settings.GetGameSource(game));
            var m = JsonSerializer.Deserialize<ImportManifest>(File.ReadAllText(Path.Combine(settings.ImportFolder(game), "import.json")));
            return source.Exists && m is { Version: 2, Source: not null } && m.Game == game && m.Source.Equals(source.FullName, StringComparison.OrdinalIgnoreCase) &&
                m.SourceLength == source.Length && m.SourceWriteTicks == source.LastWriteTimeUtc.Ticks && m.ElfSha256 == DiscImport.ExpectedElf(game) &&
                File.Exists(Path.Combine(settings.ImportFolder(game), "data", GameDefinition.Find(game).ElfName));
        } catch (Exception error) when (error is IOException or JsonException or ArgumentException or UnauthorizedAccessException) { return false; }
    }
    public static Task<ImportedDisc> Ensure(string pak, string game, IProgress<ImportProgress>? progress = null,
        CancellationToken cancel = default, string? home = null, string? existingImport = null) => Task.Run(() => Import(pak, game, progress, cancel, home, existingImport: existingImport), cancel);
    internal static ImportedDisc Import(string pak, string game, IProgress<ImportProgress>? progress, CancellationToken cancel, string? home, string? expected = null, string? existingImport = null) {
        expected ??= DiscImport.ExpectedElf(game);
        var source = new FileInfo(Path.GetFullPath(pak)); long sourceBytes = source.Length, sourceTicks = source.LastWriteTimeUtc.Ticks;
        using var input = source.OpenRead(); using var zip = new ZipArchive(input, ZipArchiveMode.Read, true);
        var manifest = Read(zip, game, expected); cancel.ThrowIfCancellationRequested();
        progress?.Report(new(0, 0, source.Name, "Checking game PAK")); input.Position = 0; string identity = Hash(input, cancel);
        string parent = Path.Combine(home ?? Settings.Home, "imports", game); Directory.CreateDirectory(parent);
        Storage.CheckLinks(parent);
        using var lease = new FileStream(Path.Combine(parent, "import.lock"), FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
        string root = Path.Combine(parent, "pak-" + identity);
        if (Directory.Exists(root)) {
            Storage.CheckLinks(root);
            try {
                var old = JsonSerializer.Deserialize<ImportManifest>(File.ReadAllText(Path.Combine(root, "import.json")));
                if (old is { Version: 2 } && old.Game == game && old.ElfSha256 == expected && manifest.Files.All(f => {
                    var path = new FileInfo(Path.Combine(root, "data", f.Name)); Storage.CheckLinks(path.FullName); return path.Exists && path.Length == f.Bytes;
                })) {
                    using var elf = File.OpenRead(Path.Combine(root, "data", GameDefinition.Find(game).ElfName));
                    if (Hash(elf, cancel) == expected) {
                        if (old.Source != source.FullName || old.SourceLength != sourceBytes || old.SourceWriteTicks != sourceTicks) SaveManifest(root);
                        return Result(true);
                    }
                }
            } catch (Exception error) when (error is IOException or JsonException) { }
        }
        long total = manifest.Files.Sum(f => f.Bytes);
        bool linkExisting = !string.IsNullOrEmpty(existingImport) &&
            new DriveInfo(Path.GetPathRoot(parent)!).DriveFormat.Equals("NTFS", StringComparison.OrdinalIgnoreCase) &&
            Path.GetPathRoot(Path.GetFullPath(existingImport))!.Equals(Path.GetPathRoot(parent), StringComparison.OrdinalIgnoreCase);
        if (linkExisting) {
            foreach (var file in manifest.Files) {
                cancel.ThrowIfCancellationRequested(); string path = Path.Combine(existingImport!, "data", file.Name);
                progress?.Report(new(0, 0, file.Name, "Checking existing game data for PAK"));
                if (!File.Exists(path)) { linkExisting = false; break; }
                Storage.CheckLinks(path); using var old = File.OpenRead(path);
                if (old.Length != file.Bytes || Hash(old, cancel) != file.Sha256) { linkExisting = false; break; }
            }
        }
        Require(linkExisting || new DriveInfo(Path.GetPathRoot(parent)!).AvailableFreeSpace >= total + 64L * 1024 * 1024,
            "Not enough disk space to prepare game files from this PAK. Keep the previous import selected to reuse matching game data, or free up space.");
        string temp = Path.Combine(parent, ".pak-import-" + Guid.NewGuid().ToString("N")); Directory.CreateDirectory(temp);
        try {
            if (linkExisting) {
                Transfer(zip, manifest, null, progress, cancel);
                var links = new List<string>();
                foreach (var file in manifest.Files) {
                    cancel.ThrowIfCancellationRequested(); string target = Path.Combine(temp, "data", file.Name);
                    Directory.CreateDirectory(Path.GetDirectoryName(target)!);
                    if (!CreateHardLink(target, Path.Combine(existingImport!, "data", file.Name), 0)) {
                        // Restricted NTFS files can still refuse links. Remove
                        // only the links created here, then use normal extraction.
                        foreach (string link in links) File.Delete(link);
                        linkExisting = false; break;
                    }
                    links.Add(target);
                }
            }
            if (!linkExisting) {
                Require(new DriveInfo(Path.GetPathRoot(parent)!).AvailableFreeSpace >= total + 64L * 1024 * 1024,
                    "Not enough disk space to extract this PAK. This drive could not reuse the existing import through hard links.");
                Transfer(zip, manifest, Path.Combine(temp, "data"), progress, cancel);
            }
            using (var elf = File.OpenRead(Path.Combine(temp, "data", GameDefinition.Find(game).ElfName)))
                Require(Hash(elf, cancel) == expected, "Game PAK executable is not the supported revision.");
            source.Refresh(); Require(source.Length == sourceBytes && source.LastWriteTimeUtc.Ticks == sourceTicks, "Game PAK changed during import.");
            SaveManifest(temp); cancel.ThrowIfCancellationRequested();
            if (Directory.Exists(root)) Directory.Move(root, root + ".previous-" + Guid.NewGuid().ToString("N"));
            Directory.Move(temp, root); return Result(false);
        } finally {
            if (Directory.Exists(temp) && Path.GetDirectoryName(Path.GetFullPath(temp)) == Path.GetFullPath(parent)) { Storage.CheckLinks(temp); Directory.Delete(temp, true); }
        }
        void SaveManifest(string folder) => File.WriteAllText(Path.Combine(folder, "import.json"), JsonSerializer.Serialize(
            new ImportManifest(2, game, source.FullName, source.Length, source.LastWriteTimeUtc.Ticks, expected,
                manifest.Files.Select(f => new ImportedFile(f.Name, f.Bytes, f.Sha256)).ToArray())));
        ImportedDisc Result(bool reused) => new(root, Path.Combine(root, "data", GameDefinition.Find(game).ElfName), manifest.Files.Count, manifest.Files.Sum(f => f.Bytes), reused) { Verification = "Verified game PAK: " + GameDefinition.Find(game).Name };
    }
}

public sealed partial class Settings {
    public bool UseGamePakFile1 { get; set; }
    public bool UseGamePakFile2 { get; set; }
    public string GamePakFile1 { get; set; } = "";
    public string GamePakFile2 { get; set; } = "";
    public bool UsesGamePak(string? game = null) => (game ?? Game.Id) == "file2" ? UseGamePakFile2 : UseGamePakFile1;
    public string GetGameSource(string? game = null) => UsesGamePak(game) ? ((game ?? Game.Id) == "file2" ? GamePakFile2 : GamePakFile1) : GetIso(game);
    public void SetGamePak(bool enabled) { if (Game.Id == "file2") UseGamePakFile2 = enabled; else UseGamePakFile1 = enabled; }
    public void RememberGamePak(OriginalAssetExport export) {
        string path = Path.Combine(export.Root, "original-assets.pak");
        if (Game.Id == "file2") GamePakFile2 = path; else GamePakFile1 = path;
    }
    public void SetGameSource(string path) {
        if (!UsesGamePak()) SetFile("iso", path); else if (Game.Id == "file2") GamePakFile2 = path; else GamePakFile1 = path;
    }
    public Task<ImportedDisc> PrepareGame(IProgress<ImportProgress>? progress, CancellationToken cancel) => UsesGamePak()
        ? GamePaks.Ensure(GetGameSource(), Game.Id, progress, cancel, existingImport: ImportFolder())
        : DiscImport.Ensure(GetIso(), Game, DiscImport.ExpectedElf(Game.Id), progress, cancel);
}
