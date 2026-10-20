using System.Diagnostics;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
public record ImportProgress(long Completed, long Total, string File, string Stage = "Importing") {
    public double Percent => Total == 0 ? 0 : Completed * 100.0 / Total;
}
public record ImportedDisc(string Root, string Elf, int Files, long Bytes, bool Reused) {
    public string Verification { get; init; } = "";
}
public record ImportedFile(string Name, long Length, string Sha256);
public record ImportManifest(int Version, string Game, string Source, long SourceLength,
                             long SourceWriteTicks, string ElfSha256, ImportedFile[] Files);
public static class DiscImport {
    public const string FirstElfSha256 =
        "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46";
    static readonly Dictionary<string, ImportManifest> manifests =
        new(StringComparer.OrdinalIgnoreCase);
    public static string ExpectedElf(Settings settings, string root) {
        if (settings.Game.Id == "file1")
            return FirstElfSha256;
        string reference = settings.GetElf(root);
        if (!File.Exists(reference))
            throw new IOException("This release does not include a supported File #2 build.");
        using var stream = File.OpenRead(reference);
        return Convert.ToHexString(SHA256.HashData(stream)).ToLowerInvariant();
    }
    static ImportManifest? Manifest(string folder) {
        lock (manifests) {
            if (manifests.TryGetValue(folder, out var manifest))
                return manifest;
            try {
                manifest = JsonSerializer.Deserialize<ImportManifest>(
                    File.ReadAllText(Path.Combine(folder, "import.json")));
            } catch (Exception error)
                when (error is IOException or JsonException or UnauthorizedAccessException) {
                return null;
            }
            if (manifest != null)
                manifests[folder] = manifest;
            return manifest;
        }
    }
    static bool Matches(ImportManifest? m, string source, FileInfo file, GameDefinition game,
                        string? expected = null) =>
        m is { Version : 1 } && m.Game == game.Id
        && string.Equals(m.Source, source, StringComparison.OrdinalIgnoreCase) &&
        m.SourceLength == file.Length && m.SourceWriteTicks == file.LastWriteTimeUtc.Ticks &&
        (expected == null || m.ElfSha256 == expected);
    public static bool Ready(Settings settings, string? gameId = null) {
        try {
            var game = GameDefinition.Find(gameId ?? settings.Game.Id);
            string folder = settings.ImportFolder(game.Id);
            if (folder.Length == 0 || !File.Exists(settings.GetIso(game.Id)))
                return false;
            var source = new FileInfo(settings.GetIso(game.Id));
            return Matches(Manifest(folder), source.FullName, source, game,
                           game.Id == "file1" ? FirstElfSha256 : null) &&
                   File.Exists(Path.Combine(folder, "data", game.ElfName));
        } catch (Exception error)
            when (error is IOException or UnauthorizedAccessException or ArgumentException) {
            return false;
        }
    }
    static bool Complete(string folder, ImportManifest m, GameDefinition game) {
        string data = Path.Combine(folder, "data");
        foreach (var item in m.Files) {
            if (!SafeRelative(item.Name))
                return false;
            var file = new FileInfo(Path.Combine(data, item.Name));
            if (!file.Exists || file.Length != item.Length)
                return false;
        }
        using var elf = File.OpenRead(Path.Combine(data, game.ElfName));
        return Convert.ToHexString(SHA256.HashData(elf))
            .Equals(m.ElfSha256, StringComparison.OrdinalIgnoreCase);
    }
    static bool SafeRelative(string name) =>
        !Path.IsPathRooted(name) && name.Length != 0 &&
        !name.Split(new[] { '/', '\\' })
             .Any(p => p is "" or "." or ".." || p.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0);
    public static Task<ImportedDisc> Ensure(string iso, GameDefinition game, string expectedElf,
                                            IProgress<ImportProgress>? progress = null,
                                            CancellationToken cancel = default,
                                            string? home = null) =>
        Task.Run(() => Extract(iso, game, expectedElf, progress, cancel, home), cancel);
    static ImportedDisc Extract(string iso, GameDefinition game, string expectedElf,
                                IProgress<ImportProgress>? progress, CancellationToken cancel,
                                string? home) {
        iso = Path.GetFullPath(iso);
        var source = new FileInfo(iso);
        progress?.Report(
            new(0, 0, "Checking game, region and executable revision", "Checking ISO"));
        using var image = new DiscImage(iso);
        var verified = DiscValidation.Check(image, game, expectedElf, cancel);
        string elfHash = verified.Sha256;
        progress?.Report(new(1, 1, verified.Description, "Checking ISO"));
        string parent = Path.Combine(home ?? Path.Combine(Settings.Home, "imports"), game.Id);
        Directory.CreateDirectory(parent);
        using var lease = new FileStream(Path.Combine(parent, "import.lock"), FileMode.OpenOrCreate,
                                         FileAccess.ReadWrite, FileShare.None);
        string identity = Convert
                              .ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(
                                  iso + "\n" + source.Length + "\n" +
                                  source.LastWriteTimeUtc.Ticks + "\n" + expectedElf)))
                              .ToLowerInvariant();
        string target = Path.Combine(parent, identity);
        var old = Manifest(target);
        if (Matches(old, iso, source, game, expectedElf) && Complete(target, old!, game))
            return new(target, Path.Combine(target, "data", game.ElfName), old!.Files.Length,
                       old.Files.Sum(f => f.Length), true) { Verification = verified.Description };
        long total = image.Entries.Where(e => !e.Directory).Sum(e => e.Length);
        string temp = Path.Combine(parent, identity + ".import-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        try {
            var drive = new DriveInfo(Path.GetPathRoot(temp)!);
            if (drive.AvailableFreeSpace < total + 64 * 1024 * 1024)
                throw new IOException("Not enough disk space to import this disc.");
            string data = Path.Combine(temp, "data");
            Directory.CreateDirectory(data);
            var files = new List<ImportedFile>();
            long copied = 0;
            var reportClock = Stopwatch.StartNew();
            progress?.Report(new(0, total, "Reading disc"));
            foreach (var entry in image.Entries) {
                cancel.ThrowIfCancellationRequested();
                string output = Path.Combine(data, entry.Name);
                if (entry.Directory) {
                    Directory.CreateDirectory(output);
                    continue;
                }
                Directory.CreateDirectory(Path.GetDirectoryName(output)!);
                using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                using (var stream = new FileStream(output, FileMode.CreateNew, FileAccess.Write,
                                                   FileShare.None, 1024 * 1024)) {
                    image.Copy(entry, stream, cancel, n => {
                        copied += n;
                        if (reportClock.ElapsedMilliseconds >= 100) {
                            progress?.Report(new(copied, total, entry.Name));
                            reportClock.Restart();
                        }
                    }, hash);
                    stream.Flush();
                }
                files.Add(new(entry.Name, entry.Length,
                              Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant()));
            }
            cancel.ThrowIfCancellationRequested();
            var record =
                new ImportManifest(1, game.Id, iso, source.Length, source.LastWriteTimeUtc.Ticks,
                                   elfHash, files.ToArray());
            File.WriteAllText(Path.Combine(temp, "import.json"),
                              JsonSerializer.Serialize(
                                  record, new JsonSerializerOptions { WriteIndented = true }));
            if (Directory.Exists(target))
                Directory.Move(target, target + ".previous-" + Guid.NewGuid().ToString("N"));
            Directory.Move(temp, target);
            lock (manifests) manifests[target] = record;
            progress?.Report(new(total, total, "Imported"));
            return new(target, Path.Combine(target, "data", game.ElfName), files.Count, total,
                       false) { Verification = verified.Description };
        } finally {
            // Only the newly created, private staging directory is removed.
            if (Directory.Exists(temp) &&
                Path.GetDirectoryName(Path.GetFullPath(temp)) == Path.GetFullPath(parent))
                Directory.Delete(temp, true);
        }
    }
}
