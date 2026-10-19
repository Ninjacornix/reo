using System.IO;
using System.IO.Compression;
using System.Text.Json;

namespace Outbreak.Launcher;

public static partial class LocalGameBuild {
    static string? DistributionValue(string root, string key) {
        try {
            using var document =
                JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "distribution.json")));
            return document.RootElement.TryGetProperty(key, out var value) &&
                           value.ValueKind == JsonValueKind.String
                       ? value.GetString()
                       : null;
        } catch (Exception error)
            when (error is IOException or JsonException or UnauthorizedAccessException) {
            return null;
        }
    }
    static bool
        DigestString(string? value) => value is { Length : 64 } && value.All(Uri.IsHexDigit);
    static string? PayloadIdentity(string root) {
        string? identity = DistributionValue(root, "kitSha256");
        return DigestString(identity) ? identity : null;
    }
    static string PayloadFolder(string root) {
        string legacy = Path.Combine(root, "build-kit");
        return File.Exists(Path.Combine(legacy, ManifestName))
                   ? legacy
                   : Path.Combine(Settings.Home, "build-kits", PayloadIdentity(root) ?? "missing");
    }
    static bool HasPayload(string root) => PayloadIdentity(root) != null
                                           && File.Exists(Path.Combine(root, "build-inputs.zip"));
    static void ExpandPayload(string root, IProgress<ImportProgress>? progress,
                              CancellationToken cancel) {
        if (!HasPayload(root))
            return;
        string destination = PayloadFolder(root), identity = PayloadIdentity(root)!;
        if (File.Exists(Path.Combine(destination, ManifestName)) &&
            Sha(Path.Combine(destination, ManifestName)) == identity)
            return;
        string archive = Path.Combine(root, "build-inputs.zip");
        progress?.Report(new(0, 0, "Checking setup archive", "Preparing build files"));
        string? expected = DistributionValue(root, "inputsSha256");
        if (!DigestString(expected) || Sha(archive) != expected)
            throw new IOException(
                "Setup archive verification failed. Extract the complete release.");
        string parent = Path.GetDirectoryName(destination)!;
        Directory.CreateDirectory(parent);
        using var lease = new FileStream(Inside(parent, identity + ".lock"), FileMode.OpenOrCreate,
                                         FileAccess.ReadWrite, FileShare.None);
        string staging = Inside(parent, identity + ".unpack-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        try {
            using var zip = ZipFile.OpenRead(archive);
            if (zip.Entries.Count > 25000 || zip.Entries.Sum(e => e.Length) > 1024L * 1024 * 1024)
                throw new IOException("Invalid setup archive size.");
            int done = 0;
            foreach (var entry in zip.Entries) {
                cancel.ThrowIfCancellationRequested();
                if (entry.FullName.EndsWith('/'))
                    continue;
                if (((entry.ExternalAttributes >> 16) & 0xF000) == 0xA000 ||
                    (entry.ExternalAttributes & 0x400) != 0)
                    throw new IOException("Setup archive contains a link.");
                string path = Inside(staging, entry.FullName);
                Directory.CreateDirectory(Path.GetDirectoryName(path)!);
                using var input = entry.Open();
                using var output = new FileStream(path, FileMode.CreateNew, FileAccess.Write);
                var buffer = new byte[65536];
                long copied = 0;
                int count;
                while ((count = input.Read(buffer)) != 0) {
                    cancel.ThrowIfCancellationRequested();
                    copied += count;
                    if (copied > entry.Length)
                        throw new IOException("Invalid setup archive entry size.");
                    output.Write(buffer, 0, count);
                }
                if (copied != entry.Length)
                    throw new IOException("Incomplete setup archive entry.");
                if (++done % 50 == 0)
                    progress?.Report(new(done, zip.Entries.Count, "Unpacking setup files",
                                         "Preparing build files"));
            }
            if (Sha(Path.Combine(staging, ManifestName)) != identity)
                throw new IOException("Setup manifest verification failed.");
            cancel.ThrowIfCancellationRequested();
            if (Directory.Exists(destination))
                Directory.Move(destination,
                               destination + ".previous-" + Guid.NewGuid().ToString("N"));
            Directory.Move(staging, destination);
        } finally {
            if (Directory.Exists(staging) &&
                Path.GetDirectoryName(Path.GetFullPath(staging)) == Path.GetFullPath(parent))
                Directory.Delete(staging, true);
        }
    }
}
