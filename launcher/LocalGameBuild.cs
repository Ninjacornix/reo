using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

public record BuildKitFile(string Path, string Sha256);
public record LocalBuildStep(string Name, string Tool, string[] Arguments);
public record LocalBuildKit(int Format, string RuntimeAbi, string Architecture, string ElfSha256,
                            BuildKitFile[] Files, LocalBuildStep[] Steps, string[] Outputs,
                            string? Toolchain = null);
public record LocalBuildReceipt(int Format, string KitSha256, string ElfSha256, string Architecture,
                                BuildKitFile[] Outputs);

// A kit contains independent tools/runtime inputs; the final game is built only in user storage.
public static class LocalGameBuild {
    public const string ManifestName = "build-kit.json";
    static readonly JsonSerializerOptions Json =
        new() { PropertyNameCaseInsensitive = true, WriteIndented = true };
    static string KitFolder(string root) => Path.Combine(root, "build-kit");
    public static bool Available(string root) => File.Exists(Path.Combine(KitFolder(root),
                                                                          ManifestName));

    public static string TargetPath(string root, string game = "file1", string? home = null) {
        string manifest = Path.Combine(KitFolder(root), ManifestName);
        string kitHash = File.Exists(manifest) ? Sha(manifest) : "missing-build-kit";
        string identity = Convert
                              .ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(
                                  kitHash + "\n" + DiscImport.FirstElfSha256 + "\nwin-x64")))
                              .ToLowerInvariant();
        return Path.Combine(home ?? Path.Combine(Settings.Home, "local-games"), game, identity,
                            "ready", "reo_recomp.exe");
    }

    static string Sha(string file) {
        using var input = File.OpenRead(file);
        return Convert.ToHexString(SHA256.HashData(input)).ToLowerInvariant();
    }

    public static string Inside(string root, string relative) {
        if (string.IsNullOrWhiteSpace(relative) || Path.IsPathRooted(relative) ||
            relative.Contains(':') || relative.Split('/', '\\').Any(p => p is "" or "." or ".."))
            throw new IOException("The build kit contains an invalid relative path.");
        string parent = Path.TrimEndingDirectorySeparator(Path.GetFullPath(root));
        string result = Path.GetFullPath(Path.Combine(parent, relative));
        if (!result.StartsWith(parent + Path.DirectorySeparatorChar,
                               StringComparison.OrdinalIgnoreCase))
            throw new IOException("The build kit path escapes its installation.");
        for (var path = new FileInfo(result) as FileSystemInfo; path != null;
             path = path is FileInfo f ? f.Directory : ((DirectoryInfo)path).Parent) {
            if (path.Exists && (path.Attributes & FileAttributes.ReparsePoint) != 0)
                throw new IOException("Build-kit paths must not traverse symbolic links.");
            if (path.FullName.Equals(parent, StringComparison.OrdinalIgnoreCase))
                break;
        }
        return result;
    }

    static LocalBuildKit ReadKit(string folder, string expectedElf) {
        var kit = JsonSerializer.Deserialize<LocalBuildKit>(
                      File.ReadAllText(Path.Combine(folder, ManifestName)), Json) ??
                  throw new IOException("The local build kit is invalid.");
        if (kit.Format != 1 || kit.Architecture != "win-x64" ||
            !RuntimeInformation.ProcessArchitecture.Equals(Architecture.X64) ||
            string.IsNullOrWhiteSpace(kit.RuntimeAbi) || kit.ElfSha256 != expectedElf ||
            kit.Files is not { Length : > 0 } || kit.Steps is not { Length : > 0 } ||
            kit.Outputs is not { Length : > 0 } ||
            !kit.Outputs.Contains("reo_recomp.exe", StringComparer.OrdinalIgnoreCase))
            throw new IOException("The local build kit is incompatible with this launcher.");
        var unique = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var file in kit.Files) {
            _ = Inside(folder, file.Path);
            if (!unique.Add(file.Path) || file.Sha256?.Length != 64 ||
                !file.Sha256.All(Uri.IsHexDigit))
                throw new IOException("The build kit has invalid or duplicate file records.");
        }
        foreach (var step in kit.Steps)
            if (string.IsNullOrWhiteSpace(step.Name) || step.Arguments == null ||
                !unique.Contains(step.Tool))
                throw new IOException("A build step names an unverified tool.");
        foreach (string output in kit.Outputs)
            _ = Inside(folder, output);
        return kit;
    }

    static bool Ready(string folder, string kitHash, LocalBuildKit kit) {
        try {
            var receipt = JsonSerializer.Deserialize<LocalBuildReceipt>(
                File.ReadAllText(Path.Combine(folder, "local-build.json")), Json);
            if (receipt is not { Format : 1 } || receipt.KitSha256 != kitHash ||
                receipt.ElfSha256 != kit.ElfSha256 || receipt.Architecture != kit.Architecture ||
                receipt.Outputs == null || receipt.Outputs.Length != kit.Outputs.Length)
                return false;
            var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var file in receipt.Outputs) {
                if (!names.Add(file.Path) ||
                    !kit.Outputs.Contains(file.Path, StringComparer.OrdinalIgnoreCase))
                    return false;
                if (Sha(Inside(folder, file.Path)) != file.Sha256)
                    return false;
            }
            return true;
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                            JsonException or ArgumentException) {
            return false;
        }
    }

    public static Task<string>
    Ensure(string root, ImportedDisc disc, IProgress<ImportProgress>? progress = null,
           CancellationToken cancel = default, string? home = null,
           Func<ProcessStartInfo, CancellationToken, Task<int>>? runner = null) =>
        EnsureVerified(root, disc, DiscImport.FirstElfSha256, progress, cancel, home, runner);

    internal static async Task<string>
    EnsureVerified(string root, ImportedDisc disc, string expectedElf,
                   IProgress<ImportProgress>? progress = null, CancellationToken cancel = default,
                   string? home = null,
                   Func<ProcessStartInfo, CancellationToken, Task<int>>? runner = null) {
        string kitFolder = KitFolder(root);
        if (!Available(root))
            throw new IOException(
                "This installation has no local build kit. The precompiled " +
                "game download was withdrawn; a compatible build kit is required.");
        var kit = ReadKit(kitFolder, expectedElf);
        string hash = Sha(Path.Combine(kitFolder, ManifestName));
        if (Sha(disc.Elf) != kit.ElfSha256)
            throw new IOException("The imported ELF does not match this build kit.");
        string executable = TargetPath(root, home: home);
        string ready = Path.GetDirectoryName(executable)!;
        string cache = Path.GetDirectoryName(ready)!;
        Directory.CreateDirectory(cache);
        using var lease = new FileStream(Path.Combine(cache, "build.lock"), FileMode.OpenOrCreate,
                                         FileAccess.ReadWrite, FileShare.None);
        if (Ready(ready, hash, kit))
            return executable;
        // Never compile from a modified input or reuse a partly verified tool installation.
        int verified = 0;
        foreach (var file in kit.Files) {
            cancel.ThrowIfCancellationRequested();
            if (Sha(Inside(kitFolder, file.Path)) != file.Sha256)
                throw new IOException("Build-kit file verification failed: " + file.Path);
            if (++verified % 100 == 0 || verified == kit.Files.Length)
                progress?.Report(
                    new(verified, kit.Files.Length, "Checking build files", "First-run setup"));
        }
        if (hash != Sha(Path.Combine(kitFolder, ManifestName)))
            throw new IOException("The build kit changed during validation.");
        if (kit.Toolchain == "msvc") {
            progress?.Report(
                new(0, kit.Steps.Length, "Checking compiler tools", "First-run setup"));
            await CompilerSetup.Ensure(cancel).ConfigureAwait(false);
        } else if (kit.Toolchain != null && kit.Toolchain != "llvm-mingw")
            throw new IOException("The build kit requests an unsupported compiler toolchain.");
        string work = Path.Combine(cache, "work");
        string output = Path.Combine(work, "output");
        Directory.CreateDirectory(work);
        Directory.CreateDirectory(output);
        var values =
            new Dictionary<string, string> { ["{kit}"] = kitFolder,
                                             ["{work}"] = work,
                                             ["{output}"] = output,
                                             ["{elf}"] = disc.Elf,
                                             ["{disc}"] = Path.Combine(disc.Root, "data"),
                                             ["{jobs}"] =
                                                 Math.Min(4, Math.Max(
                                                                 1, Environment.ProcessorCount / 2))
                                                     .ToString() };
        string Expand(string arg) {
            foreach (var pair in values)
                arg = arg.Replace(pair.Key, pair.Value, StringComparison.Ordinal);
            if (arg.Contains('{') || arg.Contains('}'))
                throw new IOException("A build step contains an unknown substitution.");
            return arg;
        }
        for (int i = 0; i < kit.Steps.Length; ++i) {
            cancel.ThrowIfCancellationRequested();
            var step = kit.Steps[i];
            progress?.Report(new(i, kit.Steps.Length, step.Name, "Building native code"));
            var start = new ProcessStartInfo(Inside(kitFolder, step.Tool)) {
                WorkingDirectory = work, UseShellExecute = false, CreateNoWindow = true,
                RedirectStandardOutput = true, RedirectStandardError = true
            };
            foreach (string arg in step.Arguments)
                start.ArgumentList.Add(Expand(arg));
            int code =
                runner != null
                    ? await runner(start, cancel).ConfigureAwait(false)
                    : await Run(start, Path.Combine(cache, $"step-{i:D3}.log"), cancel, line => {
                          var count = Regex.Match(line, @"^Compiled (\d+)/(\d+)");
                          if (count.Success)
                              progress?.Report(new(long.Parse(count.Groups[1].Value),
                                                   long.Parse(count.Groups[2].Value),
                                                   "Building your game", "Compiling native code"));
                          else if (line.StartsWith("Generating ", StringComparison.Ordinal))
                              progress?.Report(
                                  new(0, 0, "Reading game instructions", "Generating native code"));
                          else if (line.StartsWith("Linking ", StringComparison.Ordinal))
                              progress?.Report(new(0, 0, "Finishing your game build", "Linking"));
                      }).ConfigureAwait(false);
            if (code != 0)
                throw new IOException($"Local build failed during {step.Name} (exit {code}). " +
                                      "The completed game was not replaced. Build logs: " + cache);
        }
        cancel.ThrowIfCancellationRequested();
        // Output is admitted only after all stages succeed and its files are verified.
        var outputs =
            kit.Outputs.Select(name => new BuildKitFile(name, Sha(Inside(output, name)))).ToArray();
        if (new FileInfo(Inside(output, "reo_recomp.exe")).Length < 64 ||
            !IsPe(Inside(output, "reo_recomp.exe")))
            throw new IOException("The local build did not produce a Windows executable.");
        if (hash != Sha(Path.Combine(kitFolder, ManifestName)))
            throw new IOException("The build kit changed during compilation.");
        string staging = Path.Combine(cache, "ready-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        foreach (var file in outputs) {
            string target = Inside(staging, file.Path);
            Directory.CreateDirectory(Path.GetDirectoryName(target)!);
            File.Copy(Inside(output, file.Path), target);
            if (Sha(target) != file.Sha256)
                throw new IOException("A local build output changed during publication.");
        }
        File.WriteAllText(
            Path.Combine(staging, "local-build.json"),
            JsonSerializer.Serialize(
                new LocalBuildReceipt(1, hash, kit.ElfSha256, kit.Architecture, outputs), Json));
        cancel.ThrowIfCancellationRequested();
        if (Directory.Exists(ready))
            Directory.Move(ready, ready + ".previous-" + Guid.NewGuid().ToString("N"));
        Directory.Move(staging, ready);
        progress?.Report(new(kit.Steps.Length, kit.Steps.Length, "Ready", "Building native code"));
        return executable;
    }

    static bool IsPe(string file) {
        using var input = File.OpenRead(file);
        using var reader = new BinaryReader(input);
        if (reader.ReadUInt16() != 0x5a4d)
            return false;
        input.Position = 60;
        uint offset = reader.ReadUInt32();
        if (offset > input.Length - 6)
            return false;
        input.Position = offset;
        return reader.ReadUInt32() == 0x00004550 && reader.ReadUInt16() == 0x8664;
    }

    static async Task<int> Run(ProcessStartInfo start, string log, CancellationToken cancel,
                               Action<string>? report = null) {
        using var process =
            Process.Start(start) ?? throw new IOException("Cannot start build tool.");
        using var writer = new StreamWriter(log, append: false);
        using var gate = new SemaphoreSlim(1);
        async Task Drain(StreamReader reader) {
            while (await reader.ReadLineAsync().ConfigureAwait(false) is {} line) {
                await gate.WaitAsync().ConfigureAwait(false);
                try {
                    await writer.WriteLineAsync(line).ConfigureAwait(false);
                } finally {
                    gate.Release();
                }
                report?.Invoke(line);
            }
        }
        Task stdout = Drain(process.StandardOutput), stderr = Drain(process.StandardError);
        try {
            await process.WaitForExitAsync(cancel).ConfigureAwait(false);
        } catch (OperationCanceledException) {
            if (!process.HasExited)
                process.Kill(entireProcessTree: true);
            await process.WaitForExitAsync().ConfigureAwait(false);
            await Task.WhenAll(stdout, stderr).ConfigureAwait(false);
            throw;
        }
        await Task.WhenAll(stdout, stderr).ConfigureAwait(false);
        return process.ExitCode;
    }
}
