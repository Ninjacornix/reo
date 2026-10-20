using System.Diagnostics;
using System.IO;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

static class LocalGameBuildTests {
    public static async Task Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(),
                                   "reo-local-build-test-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(Path.Combine(root, "build-kit", "tools"));
        string cache = Path.Combine(root, "cache");
        string tool = Path.Combine(root, "build-kit", "tools", "fixture.bin");
        string elf = Path.Combine(root, "fixture.elf");
        File.WriteAllText(tool, "Synthetic test tool, not executed.");
        File.WriteAllText(elf, "Synthetic test input; no commercial game bytes.");
        string Sha(string p) =>
            Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(p))).ToLowerInvariant();
        var kit = new LocalBuildKit(
            1, "synthetic-v1", "win-x64", Sha(elf),
            new[] { new BuildKitFile("tools/fixture.bin", Sha(tool)) },
            new[] { new LocalBuildStep("Compile fixture", "tools/fixture.bin",
                                       new[] { "{output}", "--jobs", "{jobs}" }) },
            new[] { "reo_recomp.exe" });
        string manifest = Path.Combine(root, "build-kit", LocalGameBuild.ManifestName);
        void WriteKit(LocalBuildKit value) =>
            File.WriteAllText(manifest, JsonSerializer.Serialize(value));
        WriteKit(kit);
        var disc = new ImportedDisc(root, elf, 1, new FileInfo(elf).Length, false);
        int calls = 0;
        Task<int> Runner(ProcessStartInfo start, CancellationToken cancel) {
            calls++;
            cancel.ThrowIfCancellationRequested();
            check(start.ArgumentList.Count == 3 && start.ArgumentList[1] == "--jobs" &&
                      int.TryParse(start.ArgumentList[2], out int workers) &&
                      workers is >= 1 and <= BuildResources.MaximumWorkers,
                  "native build receives bounded parallel worker count");
            // A synthetic minimal PE header tests admission, not native game execution.
            var pe = new byte[128];
            BitConverter.GetBytes((ushort)0x5a4d).CopyTo(pe, 0);
            BitConverter.GetBytes(64).CopyTo(pe, 60);
            BitConverter.GetBytes(0x00004550).CopyTo(pe, 64);
            BitConverter.GetBytes((ushort)0x8664).CopyTo(pe, 68);
            File.WriteAllBytes(Path.Combine(start.ArgumentList[0], "reo_recomp.exe"), pe);
            return Task.FromResult(0);
        }
        async Task<string> Build(Func<ProcessStartInfo, CancellationToken, Task<int>>? runner =
                                     null,
                                 CancellationToken cancel = default) =>
            await LocalGameBuild.EnsureVerified(root, disc, kit.ElfSha256, cancel: cancel,
                                                home: cache, runner: runner ?? Runner);
        try {
            const ulong gib = 1024UL * 1024 * 1024;
            check(BuildResources.Select(16, 16 * gib) == 12 &&
                      BuildResources.Select(4, 16 * gib) == 3,
                  "available CPU capacity is used within worker limit");
            check(BuildResources.Select(16, 5 * gib) == 3 && BuildResources.Select(16, gib) == 1,
                  "memory pressure limits parallel compilation");
            check(BuildResources.Select(128, 128 * gib) == BuildResources.MaximumWorkers,
                  "high-memory machines respect the maximum worker limit");
            string image = await Build();
            check(File.Exists(image) && calls == 1, "local build creates verified cache");
            check(await Build() == image && calls == 1,
                  "valid cache does not invoke compiler again");
            File.AppendAllText(image, "tampered");
            _ = await Build();
            check(calls == 2, "modified game output is rebuilt");
            WriteKit(kit with { RuntimeAbi = "synthetic-v2" });
            string second = await Build();
            check(second != image && calls == 3, "runtime ABI change invalidates game cache");

            WriteKit(kit with { RuntimeAbi = "failing-fixture" });
            bool failed = false;
            try {
                await Build((_, _) => Task.FromResult(7));
            } catch (IOException) {
                failed = true;
            }
            check(failed && !File.Exists(LocalGameBuild.TargetPath(root, home: cache)),
                  "failed compiler cannot publish ready game");

            WriteKit(kit with { RuntimeAbi = "cancel-fixture" });
            using var cancellation = new CancellationTokenSource();
            cancellation.Cancel();
            bool cancelled = false;
            try {
                await Build(cancel: cancellation.Token);
            } catch (OperationCanceledException) {
                cancelled = true;
            }
            check(cancelled && !File.Exists(LocalGameBuild.TargetPath(root, home: cache)),
                  "cancelled build cannot publish ready game");

            WriteKit(kit with { RuntimeAbi = "modified-tool-fixture" });
            File.AppendAllText(tool, "modified");
            bool toolRejected = false;
            try {
                await Build();
            } catch (IOException) {
                toolRejected = true;
            }
            check(toolRejected && calls == 3, "modified build tool is refused before execution");

            foreach (string bad in new[] { "../escape", "x/../../escape", "C:/escape", "x:escape",
                                           "x//y" }) {
                bool rejected = false;
                try {
                    _ = LocalGameBuild.Inside(root, bad);
                } catch (IOException) {
                    rejected = true;
                }
                check(rejected, "local build rejects path traversal");
            }
            bool wrongElf = false;
            try {
                await LocalGameBuild.Ensure(root, disc, home: cache, runner: Runner);
            } catch (IOException) {
                wrongElf = true;
            }
            check(wrongElf && calls == 3, "public build entry refuses synthetic unsupported ELF");
        } finally {
            // Only this test's newly created directory can be removed.
            if (Directory.Exists(root))
                Directory.Delete(root, recursive: true);
        }
    }
}
