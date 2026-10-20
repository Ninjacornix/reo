using System.IO;
using System.IO.Compression;
using System.Net.Http;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class PortableCompilerSetup {
    const string Name = "llvm-mingw-20251216-ucrt-x86_64";
    const string Url =
        "https://github.com/mstorsjo/llvm-mingw/releases/download/20251216/llvm-mingw-20251216-ucrt-x86_64.zip";
    const string ArchiveHash = "2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4";
    internal const string CompilerHash =
        "f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3";
    const long ArchiveBytes = 181343612;
    const string Driver = "bin/x86_64-w64-mingw32-clang++.exe";
    record InstalledFile(string Path, long Bytes, string Sha256);
    record Receipt(int Format, string ArchiveSha256, InstalledFile[] Files);
    static readonly HashSet<string> Components =
        new(StringComparer.Ordinal) { "bin",        "include", "lib", "share", "x86_64-w64-mingw32",
                                      "LICENSE.TXT" };
    internal static async Task<string> Ensure(string expectedCompilerHash,
                                              IProgress<ImportProgress>? progress,
                                              CancellationToken cancel, string? home = null) {
        if (expectedCompilerHash != CompilerHash)
            throw new IOException(
                "This build kit needs a different compiler. Download a matching launcher release.");
        if (home == null) {
            string? existing = await FindExisting(Candidates(), progress, cancel);
            if (existing != null)
                return existing;
        }
        string parent = Path.Combine(home ?? Settings.Home, "toolchains");
        Directory.CreateDirectory(parent);
        using var lease = await Lock(parent, progress, cancel);
        string folder = LocalGameBuild.Inside(parent, Name);
        if (await Valid(folder, progress, cancel))
            return folder;
        var drive = new DriveInfo(Path.GetPathRoot(parent)!);
        if (drive.AvailableFreeSpace < 1024L * 1024 * 1024)
            throw new IOException(
                "Compiler setup needs about 1 GB of free disk space. Free some space and retry Import.");
        string zip = LocalGameBuild.Inside(parent,
                                           "download-" + Guid.NewGuid().ToString("N") + ".zip"),
               staging = LocalGameBuild.Inside(parent, "unpack-" + Guid.NewGuid().ToString("N"));
        try {
            await Download(zip, progress, cancel);
            var files = new List<InstalledFile>();
            Directory.CreateDirectory(staging);
            using (var archive = ZipFile.OpenRead(zip)) {
                if (archive.Entries.Count > 20000 ||
                    archive.Entries.Sum(e => e.Length) > 2L * 1024 * 1024 * 1024)
                    throw new IOException("Invalid compiler archive size.");
                var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                var entries = archive.Entries.Where(e => !e.FullName.EndsWith('/')).ToArray();
                int checkedEntries = 0;
                foreach (var entry in entries) {
                    cancel.ThrowIfCancellationRequested();
                    if (!entry.FullName.StartsWith(Name + "/", StringComparison.Ordinal))
                        throw new IOException("Unexpected compiler archive layout.");
                    string relative = entry.FullName[(Name.Length + 1)..];
                    if (!Components.Contains(relative.Split('/')[0]))
                        continue;
                    if (!names.Add(relative) ||
                        ((entry.ExternalAttributes >> 16) & 0xF000) == 0xA000 ||
                        (entry.ExternalAttributes & 0x400) != 0)
                        throw new IOException("Invalid compiler archive entry.");
                    string destination = LocalGameBuild.Inside(staging, relative);
                    Directory.CreateDirectory(Path.GetDirectoryName(destination)!);
                    using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                    using (var input = entry.Open()) using (
                        var output =
                            new FileStream(destination, FileMode.CreateNew, FileAccess.Write)) {
                        var buffer = new byte[65536];
                        long copied = 0;
                        int count;
                        while ((count = input.Read(buffer)) != 0) {
                            cancel.ThrowIfCancellationRequested();
                            copied += count;
                            if (copied > entry.Length)
                                throw new IOException("Invalid compiler entry size.");
                            output.Write(buffer, 0, count);
                            hash.AppendData(buffer, 0, count);
                        }
                        if (copied != entry.Length)
                            throw new IOException("Compiler archive is incomplete.");
                    }
                    files.Add(new(relative, entry.Length,
                                  Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant()));
                    if (++checkedEntries % 100 == 0)
                        progress?.Report(new(checkedEntries, 5601,
                                             "Preparing Windows x64 build tools",
                                             "Preparing compiler"));
                }
            }
            if (files.Count != 5601 ||
                files.SingleOrDefault(f => f.Path == Driver)?.Sha256 != CompilerHash)
                throw new IOException("Compiler archive does not match the supported build tools.");
            await File.WriteAllTextAsync(
                Path.Combine(staging, "compiler-setup.json"),
                JsonSerializer.Serialize(new Receipt(1, ArchiveHash, files.ToArray())), cancel);
            cancel.ThrowIfCancellationRequested();
            if (Directory.Exists(folder))
                Directory.Move(folder, folder + ".previous-" + Guid.NewGuid().ToString("N"));
            Directory.Move(staging, folder);
            progress?.Report(new(1, 1, "Compiler ready", "Preparing compiler"));
            return folder;
        } finally {
            if (File.Exists(zip))
                File.Delete(zip);
            if (Directory.Exists(staging) &&
                Path.GetDirectoryName(Path.GetFullPath(staging)) == Path.GetFullPath(parent))
                Directory.Delete(staging, true);
        }
    }
    static IEnumerable<string> Candidates() {
        foreach (var scope in new[] { EnvironmentVariableTarget.Process,
                                      EnvironmentVariableTarget.User }) {
            string? configured = Environment.GetEnvironmentVariable("REO_LLVM_MINGW", scope);
            if (!string.IsNullOrWhiteSpace(configured))
                yield return configured;
        }
        foreach (string bin in (Environment.GetEnvironmentVariable("PATH") ?? "")
                     .Split(Path.PathSeparator)) {
            string path = bin.Trim().Trim('"');
            if (path.Length > 0 && Path.GetFileName(path.TrimEnd('\\', '/'))
                                       .Equals("bin", StringComparison.OrdinalIgnoreCase))
                yield return path + "/..";
        }
        foreach (string parent in new[] {
                     Path.Combine(Path.GetPathRoot(Environment.SystemDirectory)!, "Tools"),
                     Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles),
                     Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile),
                                  "Tools")
                 })
            if (!string.IsNullOrEmpty(parent)) {
                yield return Path.Combine(parent, Name);
                yield return Path.Combine(parent, "llvm-mingw");
            }
        yield return Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile),
                                  "scoop/apps/llvm-mingw/current");
    }
    internal static async Task<string?> FindExisting(IEnumerable<string> candidates,
                                                     IProgress<ImportProgress>? progress,
                                                     CancellationToken cancel) {
        var seen = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (string candidate in candidates) {
            cancel.ThrowIfCancellationRequested();
            try {
                string folder = Path.TrimEndingDirectorySeparator(
                    Path.GetFullPath(Environment.ExpandEnvironmentVariables(candidate)));
                if (!seen.Add(folder) || !File.Exists(Path.Combine(folder, Driver)))
                    continue;
                progress?.Report(new(0, 0, "Checking an existing compiler", "Checking compiler"));
                if (await Hash(Path.Combine(folder, Driver), cancel) != CompilerHash ||
                    !File.Exists(Path.Combine(folder, "bin/llvm-ar.exe")) ||
                    !File.Exists(Path.Combine(folder, "bin/x86_64-w64-mingw32-windres.exe")) ||
                    !Directory.Exists(Path.Combine(folder, "include/c++")) ||
                    !File.Exists(Path.Combine(folder, "include/windows.h")) ||
                    !File.Exists(Path.Combine(folder, "x86_64-w64-mingw32/lib/libkernel32.a")))
                    continue;
                progress?.Report(new(1, 1, "Using existing LLVM/MinGW; no download needed",
                                     "Checking compiler"));
                return folder;
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                                ArgumentException or NotSupportedException) {
                // An unrelated or inaccessible installation should not prevent automatic setup.
            }
        }
        return null;
    }
    static async Task<bool> Valid(string folder, IProgress<ImportProgress>? progress,
                                  CancellationToken cancel) {
        try {
            var record = JsonSerializer.Deserialize<Receipt>(
                await File.ReadAllTextAsync(Path.Combine(folder, "compiler-setup.json"), cancel));
            if (record is not { Format : 1, Files.Length : 5601 } ||
                record.ArchiveSha256 != ArchiveHash)
                return false;
            var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            int done = 0;
            foreach (var file in record.Files) {
                cancel.ThrowIfCancellationRequested();
                string path = LocalGameBuild.Inside(folder, file.Path);
                if (!names.Add(file.Path) || !File.Exists(path) ||
                    new FileInfo(path).Length != file.Bytes ||
                    await Hash(path, cancel) != file.Sha256)
                    return false;
                if (++done % 100 == 0)
                    progress?.Report(new(done, record.Files.Length, "Checking cached build tools",
                                         "Checking compiler"));
            }
            return record.Files.SingleOrDefault(f => f.Path == Driver)?.Sha256 == CompilerHash;
        } catch (Exception error)
            when (error is IOException or UnauthorizedAccessException or JsonException) {
            return false;
        }
    }
    static async Task<string> Hash(string path, CancellationToken cancel) {
        await using var input = File.OpenRead(path);
        return Convert.ToHexString(await SHA256.HashDataAsync(input, cancel)).ToLowerInvariant();
    }
    static async Task<FileStream> Lock(string parent, IProgress<ImportProgress>? progress,
                                       CancellationToken cancel) {
        while (true) {
            cancel.ThrowIfCancellationRequested();
            try {
                return new FileStream(Path.Combine(parent, "setup.lock"), FileMode.OpenOrCreate,
                                      FileAccess.ReadWrite, FileShare.None);
            } catch (IOException error) when ((error.HResult & 0xffff) is 32 or 33) {
                progress?.Report(
                    new(0, 0, "Waiting for another compiler setup", "Preparing compiler"));
                await Task.Delay(250, cancel);
            }
        }
    }
    static async Task Download(string destination, IProgress<ImportProgress>? progress,
                               CancellationToken cancel) {
        using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        timeout.CancelAfter(TimeSpan.FromMinutes(15));
        try {
            using var client = new HttpClient();
            client.DefaultRequestHeaders.UserAgent.ParseAdd("Outbreak-Launcher/" +
                                                            Updates.DefaultVersion);
            using var response =
                await client.GetAsync(Url, HttpCompletionOption.ResponseHeadersRead, timeout.Token);
            response.EnsureSuccessStatusCode();
            if (response.Content.Headers.ContentLength is long length && length != ArchiveBytes)
                throw new IOException("Unexpected compiler download size.");
            await using (var input = await response.Content.ReadAsStreamAsync(timeout.Token))
                await using (var output =
                                 new FileStream(destination, FileMode.CreateNew, FileAccess.Write,
                                                FileShare.None, 65536, true)) {
                long received = 0, last = 0;
                var buffer = new byte[65536];
                int count;
                progress?.Report(new(0, ArchiveBytes, "Downloading build tools automatically",
                                     "Downloading compiler"));
                while ((count = await input.ReadAsync(buffer, timeout.Token)) != 0) {
                    received += count;
                    if (received > ArchiveBytes)
                        throw new IOException("Compiler download exceeds expected size.");
                    await output.WriteAsync(buffer.AsMemory(0, count), timeout.Token);
                    if (received - last >= 524288) {
                        progress?.Report(new(received, ArchiveBytes,
                                             "Downloading build tools automatically",
                                             "Downloading compiler"));
                        last = received;
                    }
                }
                if (received != ArchiveBytes)
                    throw new IOException("Compiler download was interrupted. Retry Import.");
            }
            progress?.Report(
                new(ArchiveBytes, ArchiveBytes, "Download complete", "Downloading compiler"));
            progress?.Report(new(0, 0, "Verifying compiler download", "Verifying compiler"));
            if (await Hash(destination, cancel) != ArchiveHash)
                throw new IOException(
                    "Compiler download failed SHA-256 verification. Retry Import.");
        } catch (OperationCanceledException) when (!cancel.IsCancellationRequested) {
            throw new IOException(
                "Compiler download timed out. Check your Internet connection and retry Import.");
        }
    }
}
