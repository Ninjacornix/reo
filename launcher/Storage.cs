using System.Diagnostics;
using System.IO;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.Json.Nodes;

namespace Outbreak.Launcher;

public record StorageProgress(long Copied, long Total, string File);

// The small locator stays beside the launcher; all managed state lives in Home.
public static class Storage {
    public const string LocatorName = "storage.json", MarkerName = ".storage-location.json";
    static string? home;
    static FileStream? lease;
    public static bool Initialized { get; private set; }
    static readonly JsonSerializerOptions Json = new() { WriteIndented = true,
        PropertyNameCaseInsensitive = true, PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
    sealed record Locator(int Format, string Folder);
    sealed record Location(string Home, string Installation);
    public static string LegacyHome => Path.Combine(
        Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
        "OutbreakRecomp", "launcher");
    public static string Home => home ??= Resolve(AppLayout.FindRoot(AppContext.BaseDirectory));
    public static string DefaultHome(string root) => Path.Combine(Full(root), "data");
    static string Full(string path) => Path.TrimEndingDirectorySeparator(Path.GetFullPath(path));
    static bool Same(string a, string b) => Full(a).Equals(Full(b), StringComparison.OrdinalIgnoreCase);
    internal static bool Within(string path, string parent) => Same(path, parent) ||
        Full(path).StartsWith(Full(parent) + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase);

    public static string Resolve(string root, string? requested = null) {
        string Validate(string path) {
            path = Full(path);
            if (Within(root, path)) throw new IOException("Choose a dedicated data folder, not the launcher folder or one of its parents.");
            return path;
        }
        if (!string.IsNullOrWhiteSpace(requested)) return Validate(requested);
        string file = Path.Combine(root, LocatorName);
        if (!File.Exists(file)) return DefaultHome(root);
        var value = JsonSerializer.Deserialize<Locator>(File.ReadAllText(file), Json) ??
                    throw new IOException("The storage location file is invalid.");
        if (value.Format != 1 || string.IsNullOrWhiteSpace(value.Folder))
            throw new IOException("The storage location file is invalid.");
        string selected = Validate(Path.IsPathFullyQualified(value.Folder) ? value.Folder : Path.Combine(root, value.Folder));
        if (!Directory.Exists(selected))
            throw new IOException("Your selected storage folder is missing: " + selected +
                ". Reconnect its drive or restore the folder before opening the launcher. The selection is in storage.json beside the launcher.");
        return selected;
    }

    public static void Configure(string root, string? requested = null) {
        home = Resolve(root, requested);
        Initialized = false;
    }
    public static bool NeedsLegacyImport(string destination, string legacy) =>
        !Same(destination, legacy) && !File.Exists(Path.Combine(destination, "settings.json")) &&
        !File.Exists(Path.Combine(destination, MarkerName)) && File.Exists(Path.Combine(legacy, "settings.json"));

    public static async Task Initialize(string root, bool importLegacy, IProgress<StorageProgress>? progress,
                                        CancellationToken cancel, bool exclusive = true) {
        if (importLegacy && NeedsLegacyImport(Home, LegacyHome))
            await CopyData(LegacyHome, Home, root, progress, cancel);
        CheckWritable(Home);
        if (exclusive)
            lease = new FileStream(Path.Combine(Home, ".storage.lock"), FileMode.OpenOrCreate,
                                   FileAccess.ReadWrite, FileShare.None);
        if (importLegacy && !AppLayout.Packaged(root))
            foreach (string game in new[] { "file1", "file2" }) {
                string oldCard = Path.Combine(root, "build-ninja", GameDefinition.Find(game).PlayFolder, "saves");
                string newCard = Path.Combine(Home, "memory-cards", "default", game, "data");
                if (Directory.Exists(oldCard) && !Directory.Exists(newCard))
                    await CopyData(oldCard, newCard, root, progress, cancel, stampLocation: false);
            }
        await Rebase(Home, root, cancel);
        Initialized = true;
    }

    public static void Close() { lease?.Dispose(); lease = null; }

    internal static void CheckWritable(string folder) {
        Directory.CreateDirectory(folder);
        CheckLinks(folder);
        string probe = Path.Combine(folder, ".write-" + Guid.NewGuid().ToString("N"));
        using (new FileStream(probe, FileMode.CreateNew, FileAccess.Write, FileShare.None,
                              1, FileOptions.DeleteOnClose)) { }
    }

    internal static void CheckLinks(string path) {
        for (FileSystemInfo? entry = Directory.Exists(path) ? new DirectoryInfo(path) : new FileInfo(path);
             entry != null; entry = entry is DirectoryInfo d ? d.Parent : ((FileInfo)entry).Directory)
            if (entry.Exists && (entry.Attributes & FileAttributes.ReparsePoint) != 0)
                throw new IOException("Choose a storage folder without symbolic links or junctions.");
    }

    static List<FileInfo> Files(string folder, CancellationToken cancel, List<string> directories) {
        var result = new List<FileInfo>();
        var pending = new Stack<DirectoryInfo>(); pending.Push(new(folder));
        while (pending.TryPop(out var directory)) {
            cancel.ThrowIfCancellationRequested();
            foreach (var entry in directory.EnumerateFileSystemInfos()) {
                if ((entry.Attributes & FileAttributes.ReparsePoint) != 0)
                    throw new IOException("Cannot copy linked files or folders: " + entry.FullName);
                if (entry is DirectoryInfo child) { directories.Add(child.FullName); pending.Push(child); }
                else if (entry.Name != ".storage.lock" && entry.Name != MarkerName &&
                         !entry.Name.EndsWith(".reo-lock", StringComparison.OrdinalIgnoreCase))
                    result.Add((FileInfo)entry);
            }
        }
        return result;
    }

    // Never merge into another profile, and never delete the source data.
    public static async Task CopyData(string source, string destination, string installation,
                                     IProgress<StorageProgress>? progress, CancellationToken cancel, bool stampLocation = true) {
        source = Full(source); destination = Full(destination);
        if (Within(source, destination) || Within(destination, source))
            throw new IOException("Choose a different folder outside the current storage folder.");
        if (!Directory.Exists(source)) throw new IOException("The current storage folder is missing.");
        CheckLinks(source); CheckLinks(destination);
        if (File.Exists(destination) || (Directory.Exists(destination) && Directory.EnumerateFileSystemEntries(destination).Any()))
            throw new IOException("That folder already contains files. Choose a new or empty folder for your launcher data.");
        string parent = Path.GetDirectoryName(destination) ?? throw new IOException("Choose a data folder, not a drive root.");
        CheckWritable(parent);
        var directories = new List<string>();
        var files = Files(source, cancel, directories);
        long total = files.Sum(f => f.Length), copied = 0;
        if (new DriveInfo(Path.GetPathRoot(destination)!).AvailableFreeSpace < total + 16 * 1024 * 1024)
            throw new IOException("There is not enough free space to copy your launcher data.");
        string staging = Path.Combine(parent, ".reo-storage-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        try {
            foreach (string directory in directories)
                Directory.CreateDirectory(Path.Combine(staging, Path.GetRelativePath(source, directory)));
            var buffer = new byte[1024 * 1024];
            foreach (var file in files) {
                cancel.ThrowIfCancellationRequested();
                string relative = Path.GetRelativePath(source, file.FullName), target = Path.Combine(staging, relative);
                Directory.CreateDirectory(Path.GetDirectoryName(target)!);
                using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                await using (var input = new FileStream(file.FullName, FileMode.Open, FileAccess.Read, FileShare.Read,
                                                       buffer.Length, FileOptions.Asynchronous | FileOptions.SequentialScan))
                await using (var output = new FileStream(target, FileMode.CreateNew, FileAccess.Write, FileShare.None,
                                                        buffer.Length, FileOptions.Asynchronous)) {
                    for (int count; (count = await input.ReadAsync(buffer, cancel)) != 0;) {
                        await output.WriteAsync(buffer.AsMemory(0, count), cancel);
                        hash.AppendData(buffer, 0, count); copied += count;
                        progress?.Report(new(copied, total, relative));
                    }
                }
                using (var verify = File.OpenRead(target)) {
                    byte[] actual = await SHA256.HashDataAsync(verify, cancel);
                    if (!hash.GetHashAndReset().AsSpan().SequenceEqual(actual))
                        throw new IOException("Copy verification failed: " + relative);
                }
                File.SetLastWriteTimeUtc(target, file.LastWriteTimeUtc);
            }
            Location previous = ReadLocation(source) ?? new(source, installation);
            if (stampLocation) {
                await RewritePaths(staging, source, destination, previous.Installation, installation, cancel);
                await WriteJson(Path.Combine(staging, MarkerName), new Location(destination, Full(installation)), cancel);
            }
            cancel.ThrowIfCancellationRequested();
            // Only an empty directory can be removed here; unexpected new files abort the operation.
            if (Directory.Exists(destination)) Directory.Delete(destination, false);
            Directory.Move(staging, destination);
        } finally {
            // staging is always the freshly allocated sibling above, never a user-selected path.
            if (Directory.Exists(staging)) Directory.Delete(staging, true);
        }
    }

    public static async Task Select(string root, string source, string destination,
                                    IProgress<StorageProgress>? progress, CancellationToken cancel) {
        if (Same(source, destination)) return;
        // Test the locator's directory before a potentially long copy. Selection publishes last.
        CheckWritable(root);
        await CopyData(source, destination, root, progress, cancel);
        string value = Within(destination, root) ? Path.GetRelativePath(root, destination) : Full(destination);
        await WriteJson(Path.Combine(root, LocatorName), new Locator(1, value), cancel);
    }

    static Location? ReadLocation(string folder) {
        string file = Path.Combine(folder, MarkerName);
        return File.Exists(file) ? JsonSerializer.Deserialize<Location>(File.ReadAllText(file), Json) : null;
    }

    internal static async Task Rebase(string folder, string root, CancellationToken cancel) {
        var previous = ReadLocation(folder);
        if (previous != null && (!Same(previous.Home, folder) || !Same(previous.Installation, root)))
            await RewritePaths(folder, previous.Home, folder, previous.Installation, root, cancel);
        await WriteJson(Path.Combine(folder, MarkerName), new Location(Full(folder), Full(root)), cancel);
    }

    internal static string RebasePath(string value, string oldHome, string newHome, string oldRoot, string newRoot) {
        if (!Path.IsPathFullyQualified(value)) return value;
        if (Within(value, oldHome)) return Path.Combine(newHome, Path.GetRelativePath(oldHome, value));
        if (!Same(oldRoot, newRoot) && Within(value, oldRoot))
            return Path.Combine(newRoot, Path.GetRelativePath(oldRoot, value));
        return value;
    }

    static async Task RewritePaths(string folder, string oldHome, string newHome, string oldRoot, string newRoot,
                                   CancellationToken cancel) {
        // Rewrite mutable launcher metadata, never signed build-kit manifests or game assets.
        var files = new List<string>();
        string settings = Path.Combine(folder, "settings.json");
        if (File.Exists(settings)) files.Add(settings);
        foreach (string sub in new[] { "imports", "server-python", "toolchains" }) {
            string dir = Path.Combine(folder, sub);
            if (!Directory.Exists(dir)) continue;
            files.AddRange(Directory.EnumerateFiles(dir, sub == "imports" ? "import.json" : "setup.json", SearchOption.AllDirectories));
        }
        foreach (string file in files) {
            cancel.ThrowIfCancellationRequested();
            var node = JsonNode.Parse(await File.ReadAllTextAsync(file, cancel));
            void Visit(JsonNode? current) {
                if (current is JsonObject obj)
                    foreach (string key in obj.Select(x => x.Key).ToArray()) {
                        if (obj[key] is JsonValue v && v.TryGetValue<string>(out var value))
                            obj[key] = RebasePath(value, oldHome, newHome, oldRoot, newRoot);
                        else Visit(obj[key]);
                    }
                else if (current is JsonArray array)
                    for (int i = 0; i < array.Count; i++) {
                        if (array[i] is JsonValue v && v.TryGetValue<string>(out var value))
                            array[i] = RebasePath(value, oldHome, newHome, oldRoot, newRoot);
                        else Visit(array[i]);
                    }
            }
            Visit(node);
            await WriteJson(file, node, cancel);
        }
        string python = Path.Combine(folder, "server-python");
        if (Directory.Exists(python))
            foreach (string file in Directory.EnumerateFiles(python, "pyvenv.cfg", SearchOption.AllDirectories)) {
                string text = await File.ReadAllTextAsync(file, cancel);
                text = text.Replace(oldHome, newHome, StringComparison.OrdinalIgnoreCase);
                if (!Same(oldRoot, newRoot)) text = text.Replace(oldRoot, newRoot, StringComparison.OrdinalIgnoreCase);
                await File.WriteAllTextAsync(file, text, cancel);
            }
    }

    internal static async Task WriteJson<T>(string file, T value, CancellationToken cancel) {
        string temp = file + "." + Guid.NewGuid().ToString("N") + ".tmp";
        try {
            await File.WriteAllTextAsync(temp, JsonSerializer.Serialize(value, Json), cancel);
            cancel.ThrowIfCancellationRequested();
            File.Move(temp, file, true);
        } finally { if (File.Exists(temp)) File.Delete(temp); }
    }

    public static void ProcessEnvironment(ProcessStartInfo start, string? folder = null) {
        string temp = Path.Combine(folder ?? Home, "temp"); Directory.CreateDirectory(temp);
        start.Environment["TMP"] = start.Environment["TEMP"] = temp;
    }

    internal static bool ProtectedUpdatePath(string root, string relative) {
        string path = Path.GetFullPath(Path.Combine(root, relative));
        return Same(path, Path.Combine(root, LocatorName)) || Within(path, DefaultHome(root)) || Within(path, Resolve(root));
    }
}
