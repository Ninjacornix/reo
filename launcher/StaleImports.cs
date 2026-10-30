using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

// Explicit cleanup of completed, unselected imports only. Never run on startup
// or after import: a user may still want an older ISO revision's cached data.
internal static class StaleImports {
    internal sealed record Candidate(string Path, string Source, long Bytes);
    static bool Inside(string path, string folder) => Path.GetFullPath(path).TrimEnd(Path.DirectorySeparatorChar)
        .StartsWith(Path.GetFullPath(folder).TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) ||
        Path.GetFullPath(path).TrimEnd(Path.DirectorySeparatorChar).Equals(Path.GetFullPath(folder).TrimEnd(Path.DirectorySeparatorChar), StringComparison.OrdinalIgnoreCase);
    static bool Protected(string path, Settings settings) => new[] {
        settings.ImportedFile1, settings.ImportedFile2, settings.Iso, settings.SecondIso,
        settings.GamePakFile1, settings.GamePakFile2, settings.Exe, settings.SecondExe,
        settings.MemoryCardFile1, settings.MemoryCardFile2
    }.Any(p => !string.IsNullOrWhiteSpace(p) && (Inside(p, path) || Inside(path, p)));

    static Candidate? Read(string path, string parent, string game, Settings settings, CancellationToken cancel) {
        path = Path.GetFullPath(path); parent = Path.GetFullPath(parent);
        if (!string.Equals(Path.GetDirectoryName(path), parent, StringComparison.OrdinalIgnoreCase) ||
            !Regex.IsMatch(Path.GetFileName(path), @"\A(?:pak-)?[0-9a-f]{64}\z") || Protected(path, settings)) return null;
        Storage.CheckLinks(path);
        string receipt = Path.Combine(path, "import.json");
        if (!File.Exists(receipt) || new FileInfo(receipt).Length > 1024 * 1024) return null;
        Storage.CheckLinks(receipt);
        var manifest = JsonSerializer.Deserialize<ImportManifest>(File.ReadAllText(receipt));
        int version = Path.GetFileName(path).StartsWith("pak-", StringComparison.Ordinal) ? 2 : 1;
        if (manifest?.Version != version || manifest.Files is not { Length: > 0 and <= 100000 } || manifest.Game != game ||
            manifest.ElfSha256 != DiscImport.ExpectedElf(game) || string.IsNullOrWhiteSpace(manifest.Source) ||
            !manifest.Files.All(f => f != null && !string.IsNullOrWhiteSpace(f.Name) && f.Length >= 0 && f.Sha256?.Length == 64) ||
            !manifest.Files.Any(f => f.Name == GameDefinition.Find(game).ElfName) ||
            !File.Exists(Path.Combine(path, "data", GameDefinition.Find(game).ElfName))) return null;
        if (Inside(manifest.Source, path)) return null;
        string dataRoot = Path.Combine(path, "data");
        var known = new HashSet<string>(StringComparer.OrdinalIgnoreCase) { receipt, Path.Combine(path, "assets.json") };
        foreach (var file in manifest.Files) {
            string full = Path.GetFullPath(Path.Combine(dataRoot, file.Name));
            if (!Inside(full, dataRoot)) return null;
            known.Add(full);
        }
        long bytes = 0;
        var pending = new Stack<DirectoryInfo>(); pending.Push(new(path));
        while (pending.TryPop(out var folder)) {
            cancel.ThrowIfCancellationRequested();
            foreach (var entry in folder.EnumerateFileSystemInfos()) {
                if (!Inside(entry.FullName, path) || (entry.Attributes & FileAttributes.ReparsePoint) != 0)
                    throw new IOException("Linked files or folders cannot be cleaned: " + path);
                if (entry is DirectoryInfo child) pending.Push(child);
                else {
                    if (!known.Contains(entry.FullName)) throw new IOException("Unknown files are kept: " + path);
                    bytes = checked(bytes + ((FileInfo)entry).Length);
                }
            }
        }
        return new(path, manifest.Source, bytes);
    }
    internal static List<Candidate> Find(Settings settings, string game, string? home = null, CancellationToken cancel = default) {
        string parent = Path.GetFullPath(Path.Combine(home ?? Settings.Home, "imports", GameDefinition.Find(game).Id));
        if (!Directory.Exists(parent)) return new();
        Storage.CheckLinks(parent); var result = new List<Candidate>();
        foreach (string folder in Directory.EnumerateDirectories(parent)) {
            cancel.ThrowIfCancellationRequested();
            try { if (Read(folder, parent, game, settings, cancel) is { } item) result.Add(item); }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException or JsonException or ArgumentException or OverflowException) { }
        }
        return result;
    }
    internal static List<string> Remove(IEnumerable<Candidate> candidates, Settings settings, string game, string? home = null) {
        string parent = Path.GetFullPath(Path.Combine(home ?? Settings.Home, "imports", GameDefinition.Find(game).Id));
        Storage.CheckLinks(parent);
        // Same lock as DiscImport and GamePaks, so setup cannot publish an import
        // while cleanup is validating and removing the reviewed candidates.
        using var lease = new FileStream(Path.Combine(parent, "import.lock"), FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
        var failed = new List<string>();
        foreach (var item in candidates) {
            try {
                // Resolve scope, active selections and every nested link again
                // immediately before the recursive delete; never trust a UI list.
                if (Read(item.Path, parent, game, settings, default) == null) { failed.Add(item.Path); continue; }
                Directory.Delete(Path.GetFullPath(item.Path), true);
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException or JsonException or ArgumentException or OverflowException) { failed.Add(item.Path); }
        }
        return failed;
    }
}
