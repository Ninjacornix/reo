using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;
using Outbreak.Launcher;

internal static class Program {
    [StructLayout(LayoutKind.Sequential)]
    struct IoCounters {
        public ulong ReadOperations, WriteOperations, OtherOperations, ReadBytes, WriteBytes,
            OtherBytes;
    }
    [DllImport("kernel32.dll")]
    static extern bool GetProcessIoCounters(nint process, out IoCounters counters);
    static readonly List<object> stages = new();
    static string output = "";
    static readonly JsonSerializerOptions json = new() { WriteIndented = true };
    sealed class ProgressSink(string file) : IProgress<ImportProgress>, IDisposable {
        readonly StreamWriter writer = new(file) { AutoFlush = true };
        readonly Stopwatch watch = Stopwatch.StartNew();
        string stage = "";
        double last = -1;
        public void Report(ImportProgress value) {
            double now = watch.Elapsed.TotalMilliseconds;
            if (stage != value.Stage || now - last >= 1000 ||
                value.Completed == value.Total && value.Total > 0) {
                writer.WriteLine(JsonSerializer.Serialize(
                    new { ms = now, stage = value.Stage, completed = value.Completed,
                          total = value.Total, detail = value.File }));
                if (stage != value.Stage)
                    Console.WriteLine("  " + value.Stage);
                stage = value.Stage;
                last = now;
            }
        }
        public void Dispose() => writer.Dispose();
    }
    static async Task<T> Measure<T>(string name, Func<Task<T>> action) {
        Console.WriteLine("START " + name);
        using var process = Process.GetCurrentProcess();
        process.Refresh();
        TimeSpan cpu = process.TotalProcessorTime;
        GetProcessIoCounters(process.Handle, out var before);
        long allocated = GC.GetTotalAllocatedBytes(), peak = process.WorkingSet64;
        using var sampling = new CancellationTokenSource();
        var sampler = Task.Run(async () => {
            using var sample = Process.GetCurrentProcess();
            try {
                while (true) {
                    sample.Refresh();
                    peak = Math.Max(peak, sample.WorkingSet64);
                    await Task.Delay(50, sampling.Token);
                }
            } catch (OperationCanceledException) {
            }
        });
        var clock = Stopwatch.StartNew();
        try {
            T result = await action();
            clock.Stop();
            process.Refresh();
            GetProcessIoCounters(process.Handle, out var after);
            stages.Add(
                new { name, wallMs = clock.Elapsed.TotalMilliseconds,
                      cpuMs = (process.TotalProcessorTime - cpu).TotalMilliseconds,
                      logicalReadBytes = after.ReadBytes - before.ReadBytes,
                      logicalWriteBytes = after.WriteBytes - before.WriteBytes,
                      logicalReadOperations = after.ReadOperations - before.ReadOperations,
                      logicalWriteOperations = after.WriteOperations - before.WriteOperations,
                      allocatedBytes = GC.GetTotalAllocatedBytes() - allocated,
                      sampledPeakWorkingSetBytes = peak, result });
            File.WriteAllText(Path.Combine(output, "import-stages.json"),
                              JsonSerializer.Serialize(new { productionCodeLinked = true,
                                                             isolatedHome = Settings.Home,
                                                             physicalCacheFlushed = false,
                                                             fullGameCompilation = false, stages },
                                                       json));
            Console.WriteLine($"DONE {name}: {clock.Elapsed.TotalSeconds:0.000}s");
            return result;
        } finally {
            sampling.Cancel();
            await sampler;
        }
    }
    static string Hash(string path) {
        using var file = File.OpenRead(path);
        return Convert.ToHexString(SHA256.HashData(file)).ToLowerInvariant();
    }
    static string BufferedHash(string path) {
        using var file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read,
                                        1048576, FileOptions.SequentialScan);
        return Convert.ToHexString(SHA256.HashData(file)).ToLowerInvariant();
    }
    static string ChunkedHash(string path) {
        using var file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read,
                                        1048576, FileOptions.SequentialScan);
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
        byte[] buffer = new byte[1048576];
        int count;
        while ((count = file.Read(buffer)) != 0)
            hash.AppendData(buffer, 0, count);
        return Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
    }
    static async Task<int> Recheck(string repo, string profile) {
        repo = Path.GetFullPath(repo);
        profile = Path.GetFullPath(profile);
        if (!profile.StartsWith(Path.Combine(repo, "build-ninja") + Path.DirectorySeparatorChar,
                                StringComparison.OrdinalIgnoreCase))
            throw new IOException("Use an owned profile workspace.");
        using var paths = JsonDocument.Parse(File.ReadAllText(Path.Combine(profile, "paths.json")));
        output = Path.Combine(profile, "cache-recheck");
        if (Directory.Exists(output))
            throw new IOException("Recheck output already exists.");
        Directory.CreateDirectory(output);
        Settings.Home = Path.Combine(profile, "home");
        string native = paths.RootElement.GetProperty("native").GetString()!;
        string importedRoot = paths.RootElement.GetProperty("imported").GetString()!;
        using (var imported = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                   importedRoot,
                   "import.json")))) using (var index = new DiscImage(imported.RootElement
                                                                          .GetProperty("Source")
                                                                          .GetString()!)) {
            var entries = index.Entries.Where(e => !e.Directory).ToArray();
            var gaps =
                entries.Zip(entries.Skip(1), (a, b) => b.Offset - a.Offset - a.Length).ToArray();
            File.WriteAllText(
                Path.Combine(output, "disc-census.json"),
                JsonSerializer.Serialize(
                    new { files = entries.Length, totalBytes = entries.Sum(e => e.Length),
                          backwardSeeks = gaps.Count(g => g < 0),
                          backwardsBytes = gaps.Where(g => g < 0).Sum(g => -g),
                          largest = entries.OrderByDescending(e => e.Length).Take(12) },
                    json));
        }
        var files = new List<GameImageCache.Input> { new(native, "reo_launcher_game.exe") };
        foreach (string dll in new[] { "libc++.dll", "libunwind.dll", "libwinpthread-1.dll" })
            files.Add(new(Path.Combine(Path.GetDirectoryName(native)!, dll), dll));
        files.Add(
            new(Path.Combine(repo, "launcher/artifacts/native/XINPUT1_4.dll"), "XINPUT1_4.dll"));
        for (int trial = 0; trial < 3; ++trial)
            _ = await Measure(
                "image-cache-reuse-repeat-" + trial,
                () => Task.Run(() => GameImageCache.Prepare(Path.Combine(Settings.Home, "images"),
                                                            files, default)));
        string? expected = null;
        foreach (int trial in new[] { 0, 1 }) {
            var methods = trial == 0 ? new[] { "default", "buffered", "chunked" }
                                     : new[] { "chunked", "buffered", "default" };
            foreach (string method in methods) {
                string result = await Measure(
                    "hash-" + method + "-" + trial,
                    () => Task.Run(() => method == "default"    ? Hash(native)
                                         : method == "buffered" ? BufferedHash(native)
                                                                : ChunkedHash(native)));
                expected ??= result;
                if (result != expected)
                    throw new IOException("Hash strategies disagree.");
            }
        }
        // Component fixture: real-size reference PE, synthetic game/kit identity, never launchable by public import.
        string fixture = Path.Combine(output, "existing-fixture"),
               source = Path.Combine(fixture, "source"), kit = Path.Combine(fixture, "build-kit");
        Directory.CreateDirectory(source);
        Directory.CreateDirectory(kit);
        string fakeElf = Path.Combine(fixture, "fixture.elf"),
               tool = Path.Combine(kit, "never-run.bin");
        File.WriteAllText(fakeElf, "Profiling fixture, not a game executable");
        File.WriteAllText(tool, "Never execute this fixture");
        var outputs =
            new[] { "reo_recomp.exe", "libc++.dll", "libunwind.dll", "libwinpthread-1.dll" };
        var buildKit = new LocalBuildKit(
            1, "profile-fixture", "win-x64", Hash(fakeElf),
            new[] { new BuildKitFile("never-run.bin", Hash(tool)) },
            new[] { new LocalBuildStep("Never run", "never-run.bin", new[] { "{output}" }) },
            outputs);
        string manifest = Path.Combine(kit, LocalGameBuild.ManifestName);
        File.WriteAllText(manifest, JsonSerializer.Serialize(buildKit));
        _ = await Measure("existing-fixture-preparation-not-import-cost", () => Task.Run(() => {
            foreach (string name in outputs)
                File.Copy(Path.Combine(Path.GetDirectoryName(native)!, name),
                          Path.Combine(source, name));
            var receipt = new LocalBuildReceipt(
                1, Hash(manifest), buildKit.ElfSha256, "win-x64",
                outputs.Select(name => new BuildKitFile(name, Hash(Path.Combine(source, name))))
                    .ToArray());
            File.WriteAllText(Path.Combine(source, "local-build.json"),
                              JsonSerializer.Serialize(receipt));
            return new { syntheticIdentity = true, realSizeReferencePe = true };
        }));
        string admitted =
            await Measure("existing-build-component-import",
                          () => LocalGameBuild.ImportExistingVerified(
                              fixture, Path.Combine(source, "reo_recomp.exe"), buildKit.ElfSha256,
                              home: Path.Combine(fixture, "cache")));
        _ = await Measure(
            "existing-build-component-same-cache",
            () => LocalGameBuild.ImportExistingVerified(fixture, admitted, buildKit.ElfSha256,
                                                        home: Path.Combine(fixture, "cache")));
        return 0;
    }
    static async Task<int> Compare(string repo, string profile, string label) {
        repo = Path.GetFullPath(repo);
        profile = Path.GetFullPath(profile);
        if (!profile.StartsWith(Path.Combine(repo, "build-ninja") + Path.DirectorySeparatorChar,
                                StringComparison.OrdinalIgnoreCase) ||
            label != Path.GetFileName(label))
            throw new IOException("Use an owned profile workspace and simple label.");
        output = Path.Combine(profile, "comparison-" + label);
        if (Directory.Exists(output))
            throw new IOException("Comparison output already exists.");
        Directory.CreateDirectory(output);
        Settings.Home = Path.Combine(profile, "home");
        using var paths = JsonDocument.Parse(File.ReadAllText(Path.Combine(profile, "paths.json")));
        string native = paths.RootElement.GetProperty("native").GetString()!;
        var files = new List<GameImageCache.Input> { new(native, "reo_launcher_game.exe") };
        foreach (string dll in new[] { "libc++.dll", "libunwind.dll", "libwinpthread-1.dll" })
            files.Add(new(Path.Combine(Path.GetDirectoryName(native)!, dll), dll));
        files.Add(
            new(Path.Combine(repo, "launcher/artifacts/native/XINPUT1_4.dll"), "XINPUT1_4.dll"));
        for (int trial = 0; trial < 2; ++trial)
            _ = await Measure(
                "image-cache-reuse-" + trial,
                () => Task.Run(() => GameImageCache.Prepare(Path.Combine(Settings.Home, "images"),
                                                            files, default)));
        string fixture = Path.Combine(profile, "cache-recheck/existing-fixture");
        var kit = JsonSerializer.Deserialize<LocalBuildKit>(
            File.ReadAllText(Path.Combine(fixture, "build-kit/build-kit.json")))!;
        string cache = Path.Combine(output, "owned-cache");
        string admitted = await Measure("existing-build-import",
                                        () => LocalGameBuild.ImportExistingVerified(
                                            fixture, Path.Combine(fixture, "source/reo_recomp.exe"),
                                            kit.ElfSha256, home: cache));
        _ = await Measure("existing-build-same-cache",
                          () => LocalGameBuild.ImportExistingVerified(fixture, admitted,
                                                                      kit.ElfSha256, home: cache));
        // Only this trial's synthetic cache is discarded after verified admission.
        if (Path.GetDirectoryName(Path.GetFullPath(cache)) != Path.GetFullPath(output))
            throw new IOException("Unexpected cache parent.");
        Directory.Delete(cache, true);
        return 0;
    }
    static async Task<int> Main(string[] args) {
        if (args.Length == 4 && args[0] == "--compare")
            return await Compare(args[1], args[2], args[3]);
        if (args.Length == 3 && args[0] == "--recheck")
            return await Recheck(args[1], args[2]);
        if (args.Length != 3) {
            Console.Error.WriteLine(
                "ImportProfile <repo> <supported-iso> <new-build-ninja-output>");
            return 2;
        }
        string repo = Path.GetFullPath(args[0]), iso = Path.GetFullPath(args[1]);
        output = Path.GetFullPath(args[2]);
        string permitted = Path.Combine(repo, "build-ninja") + Path.DirectorySeparatorChar;
        if (!output.StartsWith(permitted, StringComparison.OrdinalIgnoreCase) ||
            Directory.Exists(output))
            throw new IOException("Use a new directory beneath repo/build-ninja.");
        if (new DriveInfo(Path.GetPathRoot(output)!).AvailableFreeSpace < 10L * 1024 * 1024 * 1024)
            throw new IOException("Leave at least 10 GiB free for profiling.");
        Directory.CreateDirectory(output);
        Settings.Home = Path.Combine(output, "home");
        Directory.CreateDirectory(Settings.Home);
        using var cancel = new CancellationTokenSource(TimeSpan.FromMinutes(30));
        using var progress = new ProgressSink(Path.Combine(output, "progress.jsonl"));
        File.WriteAllText(
            Path.Combine(output, "environment.json"),
            JsonSerializer.Serialize(
                new { processors = Environment.ProcessorCount,
                      selectedWorkers = BuildResources.WorkerCount(),
                      isoBytes = new FileInfo(iso).Length,
                      freeDiskBytes = new DriveInfo(Path.GetPathRoot(output)!).AvailableFreeSpace,
                      startedUtc = DateTime.UtcNow },
                json));
        try {
            using (var index = new DiscImage(iso)) {
                var files = index.Entries.Where(e => !e.Directory).ToArray();
                var transitions =
                    files.Zip(files.Skip(1), (a, b) => b.Offset - (a.Offset + a.Length)).ToArray();
                File.WriteAllText(
                    Path.Combine(output, "disc-census.json"),
                    JsonSerializer.Serialize(
                        new { files = files.Length, totalBytes = files.Sum(f => f.Length),
                              backwardSeeks = transitions.Count(n => n < 0),
                              backwardsBytes = transitions.Where(n => n < 0).Sum(n => -n),
                              topFiles = files.OrderByDescending(f => f.Length).Take(12) },
                        json));
            }
            var imported = await Measure("disc-extract-fresh",
                                         () => DiscImport.Ensure(iso, GameDefinition.First,
                                                                 DiscImport.FirstElfSha256,
                                                                 progress, cancel.Token));
            _ = await Measure("disc-reuse", () => DiscImport.Ensure(iso, GameDefinition.First,
                                                                    DiscImport.FirstElfSha256,
                                                                    progress, cancel.Token));
            var state = new Settings { Iso = iso };
            state.SetImport(imported.Root);
            _ = await Measure("disc-readiness-1000", () => {
                int count = 0;
                for (int i = 0; i < 1000; i++)
                    if (DiscImport.Ready(state))
                        count++;
                return Task.FromResult(count);
            });
            string install = Path.Combine(
                repo,
                "build-ninja/slim-release/package-v110-final/RE-Outbreak-v1.0.10-Windows-x64");
            _ = await Measure("kit-expand-fresh", () => Task.Run(() => {
                LocalGameBuild.ProfileExpand(install, progress, cancel.Token);
                return true;
            }));
            _ = await Measure("kit-expand-reuse", () => Task.Run(() => {
                LocalGameBuild.ProfileExpand(install, progress, cancel.Token);
                return true;
            }));
            _ = await Measure("kit-verify-files",
                              () =>
                                  Task.Run(() => LocalGameBuild.ProfileKit(install, cancel.Token)));
            string compiler = await Measure(
                "compiler-setup-fresh",
                () => PortableCompilerSetup.Ensure(PortableCompilerSetup.CompilerHash, progress,
                                                   cancel.Token, Settings.Home));
            _ = await Measure("compiler-setup-reuse", () => PortableCompilerSetup.Ensure(
                                                          PortableCompilerSetup.CompilerHash,
                                                          progress, cancel.Token, Settings.Home));
            _ = await Measure("compiler-discovery-existing",
                              () => PortableCompilerSetup.FindExisting(new[] { compiler }, progress,
                                                                       cancel.Token));
            string native =
                Path.Combine(repo, "build-ninja/portable-release/first-run-output/reo_recomp.exe");
            _ = await Measure("reference-exe-sha256",
                              () => Task.Run(() => new { bytes = new FileInfo(native).Length,
                                                         sha256 = Hash(native) }));
            var cacheInputs =
                new List<GameImageCache.Input> { new(native, "reo_launcher_game.exe") };
            foreach (string dll in new[] { "libc++.dll", "libunwind.dll", "libwinpthread-1.dll" })
                cacheInputs.Add(new(Path.Combine(Path.GetDirectoryName(native)!, dll), dll));
            cacheInputs.Add(new(Path.Combine(repo, "launcher/artifacts/native/XINPUT1_4.dll"),
                                "XINPUT1_4.dll"));
            string images = Path.Combine(Settings.Home, "images");
            _ = await Measure(
                "image-cache-fresh",
                () => Task.Run(() => GameImageCache.Prepare(images, cacheInputs, cancel.Token)));
            _ = await Measure(
                "image-cache-reuse",
                () => Task.Run(() => GameImageCache.Prepare(images, cacheInputs, cancel.Token)));
            File.WriteAllText(
                Path.Combine(output, "paths.json"),
                JsonSerializer.Serialize(new { imported = imported.Root, compiler,
                                               kit = Path.Combine(Settings.Home, "build-kits"),
                                               install, native, gameLaunched = false,
                                               compilerInvoked = false, succeeded = true },
                                         json));
            return 0;
        } catch (Exception error) {
            File.WriteAllText(Path.Combine(output, "error.txt"), error.ToString());
            Console.Error.WriteLine(error);
            return 1;
        }
    }
}
