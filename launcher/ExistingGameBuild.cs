using System.IO;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

public static partial class LocalGameBuild {
    public static Task<string>
    ImportExisting(string root, string executable, IProgress<ImportProgress>? progress = null,
                   CancellationToken cancel = default, string game = "file1") => Task.Run(async () => {
        ExpandPayload(root, progress, cancel, game);
        return await ImportExistingVerified(root, executable, DiscImport.ExpectedElf(game), progress,
                                            cancel, game: game);
    }, cancel);

    internal static async Task<string>
    ImportExistingVerified(string root, string executable, string expectedElf,
                           IProgress<ImportProgress>? progress = null,
                           CancellationToken cancel = default, string? home = null, string game = "file1") {
        cancel.ThrowIfCancellationRequested();
        executable = Path.GetFullPath(executable);
        if (!Path.GetFileName(executable)
                 .Equals("reo_recomp.exe", StringComparison.OrdinalIgnoreCase))
            throw new IOException("Choose reo_recomp.exe from a completed launcher build.");
        string source = Path.GetDirectoryName(executable)!;
        string record = Inside(source, "local-build.json");
        if (!File.Exists(record))
            throw new IOException(
                "This EXE has no local-build.json record. Select a completed launcher build and keep its entire build folder.");
        var kit = ReadKit(KitFolder(root, game), expectedElf, cancel);
        string kitHash = Sha(Path.Combine(KitFolder(root, game), ManifestName));
        progress?.Report(new(0, 0, "Checking build version, executable and companion files",
                             "Checking existing build"));
        if (!Ready(source, kitHash, kit) || !File.Exists(executable) || !IsPe(executable))
            throw new IOException(
                "This build is incompatible, incomplete or modified. Use a completed build for this launcher's game version and build kit, or import your ISO to compile it.");
        var receipt =
            JsonSerializer.Deserialize<LocalBuildReceipt>(File.ReadAllText(record), Json)!;
        string target = TargetPath(root, game, home: home), ready = Path.GetDirectoryName(target)!,
               cache = Path.GetDirectoryName(ready)!;
        Directory.CreateDirectory(cache);
        using var lease = new FileStream(Path.Combine(cache, "build.lock"), FileMode.OpenOrCreate,
                                         FileAccess.ReadWrite, FileShare.None);
        if (source.Equals(ready, StringComparison.OrdinalIgnoreCase)) {
            progress?.Report(new(1, 1, "Existing game build is ready; compilation skipped",
                                 "Checking existing build"));
            return target;
        }
        string staging = Inside(cache, "existing-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        try {
            long total =
                     receipt.Outputs.Sum(file => new FileInfo(Inside(source, file.Path)).Length),
                 done = 0;
            var buffer = new byte[1048576];
            foreach (var file in receipt.Outputs) {
                cancel.ThrowIfCancellationRequested();
                string from = Inside(source, file.Path), to = Inside(staging, file.Path);
                Directory.CreateDirectory(Path.GetDirectoryName(to)!);
                await using var input = File.OpenRead(from);
                using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                await using (var output =
                                 new FileStream(to, FileMode.CreateNew, FileAccess.Write)) {
                    int count;
                    while ((count = await input.ReadAsync(buffer, cancel)) != 0) {
                        await output.WriteAsync(buffer.AsMemory(0, count), cancel);
                        hash.AppendData(buffer, 0, count);
                        done += count;
                        progress?.Report(
                            new(done, total, "Copying " + file.Path, "Importing existing build"));
                    }
                }
                if (Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant() != file.Sha256)
                    throw new IOException(
                        "The selected build changed while copying. Close tools modifying that folder and retry.");
            }
            File.WriteAllText(Path.Combine(staging, "local-build.json"),
                              JsonSerializer.Serialize(receipt, Json));
            if (!Ready(staging, kitHash, kit) ||
                Sha(Path.Combine(KitFolder(root, game), ManifestName)) != kitHash)
                throw new IOException(
                    "The build or kit changed during import. Retry with an unchanged build folder.");
            cancel.ThrowIfCancellationRequested();
            string? previous = null;
            if (Directory.Exists(ready)) {
                previous = ready + ".previous-" + Guid.NewGuid().ToString("N");
                Directory.Move(ready, previous);
            }
            try {
                Directory.Move(staging, ready);
            } catch {
                if (previous != null && !Directory.Exists(ready))
                    Directory.Move(previous, ready);
                throw;
            }
            progress?.Report(new(1, 1, "Existing game build is ready; compilation skipped",
                                 "Checking existing build"));
            return target;
        } finally {
            if (Directory.Exists(staging) &&
                Path.GetDirectoryName(Path.GetFullPath(staging)) == Path.GetFullPath(cache))
                Directory.Delete(staging, true);
        }
    }
}
