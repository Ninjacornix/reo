using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

public sealed record OriginalAssetEntry(string Path, string File, string Name, long Bytes, string Sha256, long SourceOffset);
public sealed record OriginalAssetPack(string File, int Entries, long PayloadBytes, long Bytes, long WriteTicks, string Sha256);
public sealed record OriginalAssetExport(string Root, int Entries, long PayloadBytes, bool Reused);

// Personal original-asset references, separate from installable replacement mods.
public static class AssetExports {
    sealed record Receipt(int Format, string Game, string ElfSha256, string Identity, string Grouping,
                          List<AssetArchive> Archives, List<OriginalAssetPack> Packs);
    sealed record Pointer(int Format, string Folder);
    sealed record Planned(AssetIndexEntry Entry, string File, string Group);
    static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true };
    public const string ReferenceHeader = "asset-reference.json";
    static void Require(bool value, string message) { if (!value) throw new IOException(message); }
    static string[] Archives(string game) => game switch {
        "file1" => new[] { "NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT" },
        "file2" => new[] { "NETBIO00.DAT", "NETBIO01.DAT" },
        _ => throw new IOException("Original asset export supports File #1 and File #2.")
    };
    public static string GameFolder(string game, string? home = null) {
        _ = Archives(game);
        return Path.Combine(Path.GetFullPath(home ?? Settings.Home), "asset-exports", game);
    }
    static List<AssetArchive> Snapshot(string data, string game) => Archives(game).Select(name => {
        var file = new FileInfo(Path.Combine(data, name));
        Require(file.Exists && file.Length < 0x100000000L, "Missing or oversized asset archive: " + name);
        return new AssetArchive(name, file.Length, file.LastWriteTimeUtc.Ticks);
    }).ToList();
    static string Identity(string game, string elf, List<AssetArchive> archives) =>
        Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(JsonSerializer.Serialize(new { game, elf, archives }, Json)))).ToLowerInvariant();
    static bool Within(string path, string parent) => path.Equals(parent, StringComparison.OrdinalIgnoreCase) ||
        path.StartsWith(Path.TrimEndingDirectorySeparator(parent) + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase);
    static void RejectLink(string path) => Require((File.GetAttributes(path) & FileAttributes.ReparsePoint) == 0,
        "Original asset exports cannot use linked files or folders: " + path);
    static void CreateManaged(string home, string game, string identity) {
        string path = home;
        Directory.CreateDirectory(path);
        foreach (string part in new[] { "asset-exports", game, identity }) {
            path = Path.Combine(path, part); Directory.CreateDirectory(path); RejectLink(path);
        }
    }
    static OriginalAssetExport? Reuse(string parent, string game, string elf, string identity, string grouping,
                                      List<AssetArchive> archives) {
        try {
            string folder = grouping, pointer = Path.Combine(parent, grouping + ".json");
            if (File.Exists(pointer)) {
                RejectLink(pointer);
                Require(new FileInfo(pointer).Length <= 4096, "Invalid original export pointer.");
                var value = JsonSerializer.Deserialize<Pointer>(File.ReadAllText(pointer), Json);
                Require(value is { Format: 1 } && value.Folder != null &&
                    Regex.IsMatch(value.Folder, @"\A(?:types|archives|single)(?:-[0-9a-f-]+)?\z") &&
                    (value.Folder == grouping || value.Folder.StartsWith(grouping + "-", StringComparison.Ordinal)), "Invalid original export pointer.");
                folder = value!.Folder!;
            }
            string root = Path.Combine(parent, folder);
            if (!Directory.Exists(root)) return null;
            RejectLink(root);
            string receipt = Path.Combine(root, "export.json");
            if (!File.Exists(receipt) || new FileInfo(receipt).Length > 64 * 1024) return null;
            RejectLink(receipt);
            var record = JsonSerializer.Deserialize<Receipt>(File.ReadAllText(receipt), Json);
            if (record is not { Format: 3 } || record.Game != game || record.ElfSha256 != elf || record.Identity != identity ||
                record.Grouping != grouping || record.Archives == null || !record.Archives.SequenceEqual(archives) ||
                record.Packs == null || record.Packs.Count is < 1 or > 16) return null;
            var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var pack in record.Packs) {
                if (pack == null || pack.File == null || !Regex.IsMatch(pack.File, @"\Aoriginal-[a-z0-9-]+\.pak\z") ||
                    !names.Add(pack.File) || pack.Entries is < 1 or > 200000 || pack.PayloadBytes < 0 ||
                    pack.Sha256 == null || !Regex.IsMatch(pack.Sha256, @"\A[0-9a-f]{64}\z")) return null;
                var file = new FileInfo(Path.Combine(root, pack.File));
                if (!file.Exists || file.Length != pack.Bytes || file.LastWriteTimeUtc.Ticks != pack.WriteTicks) return null;
                RejectLink(file.FullName);
            }
            return new(root, record.Packs.Sum(p => p.Entries), record.Packs.Sum(p => p.PayloadBytes), true);
        } catch (Exception e) when (e is IOException or JsonException or UnauthorizedAccessException or OverflowException) { return null; }
    }
    public static Task<OriginalAssetExport> Ensure(ImportedDisc disc, string game,
        IProgress<ImportProgress>? progress = null, CancellationToken cancel = default, string? home = null) => Task.Run(() => {
            string data = Path.Combine(disc.Root, "data"), expected = DiscImport.ExpectedElf(game);
            cancel.ThrowIfCancellationRequested();
            progress?.Report(new(0, 0, "Checking imported game files", "Preparing original asset export"));
            using (var elf = File.OpenRead(Path.Combine(data, GameDefinition.Find(game).ElfName)))
                Require(Convert.ToHexString(SHA256.HashData(elf)).Equals(expected, StringComparison.OrdinalIgnoreCase),
                    "Original asset export needs the supported game's imported executable.");
            return Export(data, game, expected, progress, cancel, home);
        }, cancel);

    // A supplied index is only for synthetic tests; normal callers build it from the owned import.
    internal static OriginalAssetExport Export(string data, string game, string elf,
        IProgress<ImportProgress>? progress, CancellationToken cancel, string? home, AssetIndex? suppliedIndex = null) {
        const string grouping = "single";
        data = Path.TrimEndingDirectorySeparator(Path.GetFullPath(data)); home = Path.GetFullPath(home ?? Settings.Home);
        var archives = Snapshot(data, game); string identity = Identity(game, elf, archives);
        string parent = Path.Combine(GameFolder(game, home), identity);
        Require(!Within(parent, data) && !Within(data, parent), "Keep original asset exports outside imported game data.");
        CreateManaged(home, game, identity);
        using var lease = new FileStream(Path.Combine(parent, grouping + ".lock"), FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
        var reused = Reuse(parent, game, elf, identity, grouping, archives);
        if (reused != null) { progress?.Report(new(1, 1, reused.Root, "Original assets already exported")); return reused; }
        cancel.ThrowIfCancellationRequested();
        progress?.Report(new(0, 0, "Reading the game's asset index", "Indexing original assets"));
        var index = suppliedIndex ?? AssetPaks.Index(data, game, cancel: cancel);
        Require(index.Game == game && index.Archives.SequenceEqual(archives), "Imported archives changed; retry the asset export.");
        var leaves = index.Entries.Where(e => !e.IsArchive).OrderBy(e => e.Path.Split('/')[0], StringComparer.Ordinal)
            .ThenBy(e => e.Offset).ThenBy(e => e.Path, StringComparer.Ordinal).ToList();
        Require(leaves.Count is > 0 and <= 200000, "No exportable native assets or too many entries.");
        long total = leaves.Sum(e => e.Size);
        // Deflate can grow incompressible data slightly. Reserve headers, manifests
        // and 1% expansion as well as free space for normal launcher activity.
        long sourceBytes = suppliedIndex == null ? Directory.EnumerateFiles(data, "*", SearchOption.AllDirectories).Sum(f => new FileInfo(f).Length) : total;
        long required = checked(sourceBytes + sourceBytes / 100 + leaves.Count * 4096L + 128L * 1024 * 1024);
        Require(new DriveInfo(Path.GetPathRoot(parent)!).AvailableFreeSpace >= required,
            $"Original asset export needs up to {required / (1024.0 * 1024 * 1024):0.00} GB of free space. Game data is already imported.");
        string staging = Path.Combine(parent, ".export-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        var created = new List<string>(); var sources = new Dictionary<string, FileStream>();
        var report = Stopwatch.StartNew(); long completed = 0;
        void Report(string stage, string file, long done, long size, bool force = false) {
            if (!force && report.ElapsedMilliseconds < 100) return;
            progress?.Report(new(done, size, file, stage)); report.Restart();
        }
        try {
            foreach (var archive in archives) sources.Add(archive.File, File.OpenRead(Path.Combine(data, archive.File)));
            var byPath = index.Entries.ToDictionary(e => e.Path, StringComparer.Ordinal);
            var plans = new List<Planned>(leaves.Count);
            foreach (var leaf in leaves) {
                cancel.ThrowIfCancellationRequested();
                plans.Add(new(leaf, FileName(leaf, byPath), "assets"));
            }
            var packs = new List<(string File, List<OriginalAssetEntry> Entries)>();
            byte[] buffer = new byte[1024 * 1024];
            Report("Exporting original assets", "Writing .pak files", 0, total, true);
            foreach (var group in plans.GroupBy(p => p.Group).OrderBy(g => g.Key, StringComparer.Ordinal)) {
                string name = "original-" + group.Key + ".pak", path = Path.Combine(staging, name); created.Add(path);
                var exported = new List<OriginalAssetEntry>();
                using (var file = new FileStream(path, FileMode.CreateNew, FileAccess.Write))
                using (var zip = new ZipArchive(file, ZipArchiveMode.Create)) {
                    foreach (var plan in group) {
                        cancel.ThrowIfCancellationRequested();
                        var source = sources[plan.Entry.Path.Split('/')[0]]; source.Position = plan.Entry.Offset;
                        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                        using (var output = zip.CreateEntry(plan.File, CompressionLevel.Fastest).Open()) {
                            long left = plan.Entry.Size;
                            while (left > 0) {
                                cancel.ThrowIfCancellationRequested(); int n = source.Read(buffer, 0, (int)Math.Min(buffer.Length, left));
                                Require(n > 0, "Truncated original asset: " + plan.Entry.Path);
                                output.Write(buffer, 0, n); hash.AppendData(buffer, 0, n); left -= n; completed += n;
                                Report("Exporting original assets", name + " · " + plan.Entry.Name, completed, total);
                            }
                        }
                        exported.Add(new(plan.Entry.Path, plan.File, plan.Entry.Name, plan.Entry.Size,
                            Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant(), plan.Entry.Offset));
                    }
                    WriteJson(zip, ReferenceHeader, new { format = 1, kind = "original-assets", game, elfSha256 = elf, grouping, category = group.Key, index = "assets.json",
                        executableStrings = suppliedIndex == null ? ElfStringReferences.Prefix + "string-reference.json" : null });
                    WriteJson(zip, "assets.json", new { format = 1, verified = true, game, elfSha256 = elf, entries = exported });
                    if (suppliedIndex == null) {
                        progress?.Report(new(0, 0, "Extracting executable string references", "Exporting original assets"));
                        ElfStringReferences.Write(zip, Path.Combine(data, GameDefinition.Find(game).ElfName), game, cancel);
                        GamePaks.Write(zip, data, game, exported, progress, cancel);
                    }
                }
                packs.Add((name, exported));
            }
            completed = 0; Report("Verifying original asset packs", "Checking exported files", 0, total, true);
            foreach (var pack in packs) {
                using var zip = ZipFile.OpenRead(Path.Combine(staging, pack.File));
                Require(zip.Entries.Count >= pack.Entries.Count + 2, "Incomplete original asset pack.");
                foreach (var entry in pack.Entries) {
                    cancel.ThrowIfCancellationRequested(); var member = zip.GetEntry(entry.File);
                    Require(member != null && member.Length == entry.Bytes, "Exported asset size differs: " + entry.Path);
                    using var input = member!.Open(); using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256); int n;
                    long count = 0;
                    while ((n = input.Read(buffer, 0, buffer.Length)) > 0) {
                        cancel.ThrowIfCancellationRequested(); count += n; Require(count <= entry.Bytes, "Exported asset exceeds its declared size.");
                        hash.AppendData(buffer, 0, n); completed += n;
                        Report("Verifying original asset packs", pack.File + " · " + entry.Name, completed, total);
                    }
                    Require(count == entry.Bytes && Convert.ToHexString(hash.GetHashAndReset()).Equals(entry.Sha256, StringComparison.OrdinalIgnoreCase),
                        "Exported asset hash differs: " + entry.Path);
                }
            }
            if (suppliedIndex == null) {
                using var zip = ZipFile.OpenRead(Path.Combine(staging, "original-assets.pak"));
                GamePaks.Verify(zip, game, progress, cancel);
                ElfStringReferences.Verify(zip, Path.Combine(data, GameDefinition.Find(game).ElfName), game, cancel);
            }
            long compressed = packs.Sum(p => new FileInfo(Path.Combine(staging, p.File)).Length); completed = 0;
            var records = new List<OriginalAssetPack>();
            Report("Checking export files", "Recording pack checksums", 0, compressed, true);
            foreach (var pack in packs) {
                var file = new FileInfo(Path.Combine(staging, pack.File));
                using var input = file.OpenRead(); using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256); int n;
                while ((n = input.Read(buffer, 0, buffer.Length)) > 0) {
                    cancel.ThrowIfCancellationRequested(); hash.AppendData(buffer, 0, n); completed += n;
                    Report("Checking export files", pack.File, completed, compressed);
                }
                records.Add(new(pack.File, pack.Entries.Count, pack.Entries.Sum(e => e.Bytes), file.Length,
                    file.LastWriteTimeUtc.Ticks, Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant()));
            }
            Require(Snapshot(data, game).SequenceEqual(archives), "Imported archives changed during export; retry.");
            cancel.ThrowIfCancellationRequested();
            string receipt = Path.Combine(staging, "export.json"); created.Add(receipt);
            File.WriteAllText(receipt, JsonSerializer.Serialize(new Receipt(3, game, elf, identity, grouping, archives, records), Json));
            string folder = grouping;
            if (Directory.Exists(Path.Combine(parent, folder))) folder += "-" + DateTime.UtcNow.ToString("yyyyMMdd-HHmmss") + "-" + Guid.NewGuid().ToString("N")[..8];
            string destination = Path.Combine(parent, folder); Directory.Move(staging, destination);
            string pointer = Path.Combine(parent, grouping + ".json"), temp = pointer + "." + Guid.NewGuid().ToString("N") + ".tmp";
            try { File.WriteAllText(temp, JsonSerializer.Serialize(new Pointer(1, folder), Json)); File.Move(temp, pointer, true); }
            finally { if (File.Exists(temp)) File.Delete(temp); }
            Report("Original assets exported", destination, 1, 1, true);
            return new(destination, leaves.Count, total, false);
        } finally {
            foreach (var source in sources.Values) source.Dispose();
            // Only this invocation's named files in its new staging directory are
            // removed. Never recurse into unexpected content or existing exports.
            if (Directory.Exists(staging) && Path.GetDirectoryName(Path.GetFullPath(staging)) == Path.GetFullPath(parent) &&
                (File.GetAttributes(staging) & FileAttributes.ReparsePoint) == 0) {
                foreach (string file in created) if (Path.GetDirectoryName(Path.GetFullPath(file)) == Path.GetFullPath(staging))
                    try { File.Delete(file); } catch (IOException) { }
                try { Directory.Delete(staging); } catch (IOException) { }
            }
        }
    }
    static void WriteJson(ZipArchive zip, string file, object value) {
        using var writer = new StreamWriter(zip.CreateEntry(file, CompressionLevel.Fastest).Open(), new UTF8Encoding(false));
        writer.Write(JsonSerializer.Serialize(value, Json));
    }
    static string FileName(AssetIndexEntry leaf, Dictionary<string, AssetIndexEntry> index) {
        var parts = leaf.Path.Split('/'); string key = parts[0], result = parts[0];
        foreach (string part in parts.Skip(1)) {
            key += "/" + part;
            string name = Regex.Replace(index[key].Name, "[^A-Za-z0-9_.-]", "_").Trim('.', ' ');
            if (name.Length > 80) name = name[..80];
            string label = uint.Parse(part).ToString("D5") + (name.Length == 0 ? ".bin" : "_" + name);
            result += "/" + label;
        }
        return result;
    }
}

public sealed partial class Settings {
    public bool ExportOriginalAssetPaksFile1 { get; set; }
    public bool ExportOriginalAssetPaksFile2 { get; set; }
    public bool WantsOriginalAssetPaks(string? game = null) => (game ?? Game.Id) == "file2" ? ExportOriginalAssetPaksFile2 : ExportOriginalAssetPaksFile1;
    public void SetOriginalAssetExport(bool enabled) {
        if (Game.Id == "file2") ExportOriginalAssetPaksFile2 = enabled;
        else ExportOriginalAssetPaksFile1 = enabled;
    }
}
