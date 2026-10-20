using System.IO;
using System.IO.Compression;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
public static partial class Updates {
    public static string SafePath(string root, string relative) {
        if (string.IsNullOrEmpty(relative) || relative.Contains('\\') || relative.StartsWith('/') ||
            relative.Split('/').Any(
                part => part.Length == 0 || part is "." or ".." || part.EndsWith('.') ||
                        part.EndsWith(' ') ||
                        part.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0 ||
                        Regex.IsMatch(part, @"^(CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9])(\.|$)",
                                      RegexOptions.IgnoreCase)))
            throw new IOException("Unsafe update package path: " + relative);
        string target = Path.GetFullPath(
            Path.Combine(root, relative.Replace('/', Path.DirectorySeparatorChar)));
        if (!target.StartsWith(Path.GetFullPath(root).TrimEnd(Path.DirectorySeparatorChar) +
                                   Path.DirectorySeparatorChar,
                               StringComparison.OrdinalIgnoreCase))
            throw new IOException("Update path escapes the installation.");
        for (FileSystemInfo? info = new FileInfo(target); info != null;
             info = info is DirectoryInfo directory ? directory.Parent
                                                    : new FileInfo(info.FullName).Directory)
            if (info.Exists && (info.Attributes & FileAttributes.ReparsePoint) != 0)
                throw new IOException("Update paths cannot pass through links or junctions.");
        return target;
    }
    static bool Protected(string relative) =>
        relative.StartsWith(".reo-", StringComparison.OrdinalIgnoreCase) ||
        new[] { "saves", "memory-cards", "imports", "iso", "cheats", "mods", "settings.json" }
            .Contains(relative.Split('/')[0], StringComparer.OrdinalIgnoreCase);
    public static List<PackageFile> Inventory(string root) {
        var list = JsonSerializer.Deserialize<List<PackageFile>>(
                       File.ReadAllText(Path.Combine(root, "package-manifest.json")), Json) ??
                   throw new IOException("Missing package inventory.");
        if (list.Count == 0 || list.Count > MaxPackageEntries)
            throw new IOException("Invalid package inventory size.");
        var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        long total = 0;
        foreach (var file in list) {
            if (file == null)
                throw new IOException("Invalid empty package inventory entry.");
            SafePath(root, file.Path);
            if (!names.Add(file.Path) || Protected(file.Path) ||
                file.Path.Equals("package-manifest.json", StringComparison.OrdinalIgnoreCase) ||
                !Hash(file.Sha256) || file.Bytes < 0 || (total += file.Bytes) > MaxExpanded)
                throw new IOException("Invalid package inventory entry: " + file.Path);
        }
        return list;
    }
    public static List<PackageFile> Validate(string root, Version expected,
                                             CancellationToken cancel = default) {
        bool compact = false, bundledServer = false, serverSource = false;
        using (var doc =
                   JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "distribution.json")))) {
            var d = doc.RootElement;
            compact = d.TryGetProperty("layout", out var layout) &&
                      layout.GetString() == "framework-dependent-single-file";
            bundledServer =
                d.TryGetProperty("bundledServer", out var server) && server.GetBoolean();
            serverSource =
                d.TryGetProperty("serverSourceBundled", out var source) && source.GetBoolean();
            if (d.ValueKind != JsonValueKind.Object || !d.TryGetProperty("format", out _) ||
                !d.TryGetProperty("platform", out _) || !d.TryGetProperty("source", out _) ||
                !d.TryGetProperty("version", out _))
                throw new IOException("Update package identity is incomplete.");
            if (d.GetProperty("format").GetInt32() != 2 ||
                d.GetProperty("platform").GetString() != "win-x64" ||
                d.GetProperty("source").GetString() != Repository ||
                ParseVersion(d.GetProperty("version").GetString() ?? "") != expected ||
                !d.TryGetProperty("updateFormat", out var format) || format.GetInt32() != 2 ||
                !d.TryGetProperty("installMode", out var mode) || mode.GetString() != "local-build")
                throw new IOException(
                    "The release package is not a matching RE: Outbreak Windows update.");
        }
        var files = Inventory(root);
        var names = files.Select(f => f.Path).ToHashSet(StringComparer.OrdinalIgnoreCase);
        string[] requiredFiles =
            compact ? new[] { "distribution.json", "Outbreak.Launcher.exe", "build-inputs.zip",
                              "XINPUT1_4.dll", "REQUIREMENTS.md" }
                    : new[] { "distribution.json",
                              "Outbreak.Launcher.exe",
                              "Outbreak.Launcher.dll",
                              "Outbreak.Launcher.deps.json",
                              "Outbreak.Launcher.runtimeconfig.json",
                              "coreclr.dll",
                              "hostfxr.dll",
                              "build-kit/build-kit.json" };
        foreach (string required in requiredFiles)
            if (!names.Contains(required))
                throw new IOException("Update package is incomplete: " + required);
        if (bundledServer)
            foreach (string required in new[] { "network-server/server-manifest.json",
                                                "network-server/python/python.exe",
                                                "network-server/source/run.py" })
                if (!names.Contains(required))
                    throw new IOException("Update server package is incomplete: " + required);
        if (serverSource)
            foreach (string required in new[] { "network-server/server-manifest.json",
                                                "network-server/requirements.txt",
                                                "network-server/README.md",
                                                "network-server/source/run.py" })
                if (!names.Contains(required))
                    throw new IOException("Update server source is incomplete: " + required);
        if (names.Any(name => name.StartsWith("games/", StringComparison.OrdinalIgnoreCase) ||
                              Path.GetFileName(name).Equals("reo_recomp.exe",
                                                            StringComparison.OrdinalIgnoreCase) ||
                              Path.GetFileName(name).Equals("reo_launcher_game.exe",
                                                            StringComparison.OrdinalIgnoreCase)))
            throw new IOException("Updates must not contain a precompiled game executable.");
        foreach (var file in files) {
            cancel.ThrowIfCancellationRequested();
            string path = SafePath(root, file.Path);
            if (!File.Exists(path) || new FileInfo(path).Length != file.Bytes ||
                !Sha(path).Equals(file.Sha256, StringComparison.OrdinalIgnoreCase))
                throw new IOException("Update file verification failed: " + file.Path);
        }
        return files;
    }
    public static string Extract(string zip, string destination,
                                 CancellationToken cancel = default) {
        Directory.CreateDirectory(destination);
        using var archive = ZipFile.OpenRead(zip);
        if (archive.Entries.Count > MaxPackageEntries)
            throw new IOException("Update archive has too many entries.");
        var roots =
            archive.Entries
                .Where(e => e.FullName == "distribution.json" ||
                            e.FullName.EndsWith("/distribution.json", StringComparison.Ordinal))
                .ToList();
        if (roots.Count != 1)
            throw new IOException("Update archive must contain one application package.");
        string prefix = roots[0].FullName[..^ "distribution.json".Length];
        var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        long total = 0;
        foreach (var entry in archive.Entries) {
            cancel.ThrowIfCancellationRequested();
            if (entry.FullName.EndsWith('/'))
                continue;
            if (!entry.FullName.StartsWith(prefix, StringComparison.Ordinal) ||
                ((entry.ExternalAttributes >> 16) & 0xF000) == 0xA000 ||
                (entry.ExternalAttributes & 0x400) != 0)
                throw new IOException("Unsafe update archive entry.");
            string relative = entry.FullName[prefix.Length..],
                   target = SafePath(destination, relative);
            if (!names.Add(relative) || Protected(relative) ||
                (total += entry.Length) > MaxExpanded)
                throw new IOException("Invalid or oversized update archive.");
            Directory.CreateDirectory(Path.GetDirectoryName(target)!);
            using var source = entry.Open();
            using var output = new FileStream(target, FileMode.CreateNew, FileAccess.Write);
            var buffer = new byte[65536];
            long copied = 0;
            int count;
            while ((count = source.Read(buffer, 0, buffer.Length)) != 0) {
                cancel.ThrowIfCancellationRequested();
                copied += count;
                if (copied > entry.Length)
                    throw new IOException("Invalid expanded file size.");
                output.Write(buffer, 0, count);
            }
            if (copied != entry.Length)
                throw new IOException("Truncated update archive entry.");
        }
        var inventory = Inventory(destination);
        if (names.Count != inventory.Count + 1 ||
            !names.SetEquals(inventory.Select(f => f.Path).Append("package-manifest.json")))
            throw new IOException("Update archive and inventory do not match.");
        return destination;
    }
}
