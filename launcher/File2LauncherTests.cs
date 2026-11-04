using System.Diagnostics;
using System.IO;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

static class File2LauncherTests {
    public static async Task Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-file2-launcher-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        string Sha(string path) => Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))).ToLowerInvariant();
        try {
            File.WriteAllText(Path.Combine(root, "distribution.json"), "{}");
            string elf = Path.Combine(root, "synthetic.elf");
            File.WriteAllText(elf, "Synthetic input, no game bytes.");
            LocalBuildKit WriteKit(string folder, string abi) {
                Directory.CreateDirectory(Path.Combine(root, folder));
                string tool = Path.Combine(root, folder, "fixture.bin");
                File.WriteAllText(tool, "Synthetic tool, never executed.");
                var kit = new LocalBuildKit(1, abi, "win-x64", Sha(elf),
                    new[] { new BuildKitFile("fixture.bin", Sha(tool)) },
                    new[] { new LocalBuildStep("Fixture", "fixture.bin", new[] { "{output}" }) },
                    new[] { "reo_recomp.exe" });
                File.WriteAllText(Path.Combine(root, folder, LocalGameBuild.ManifestName), JsonSerializer.Serialize(kit));
                return kit;
            }
            WriteKit("build-kit", "file1-fixture");
            check(LocalGameBuild.Available(root) && !LocalGameBuild.Available(root, "file2"),
                  "A File #1 kit does not advertise File #2 setup availability");
            var second = WriteKit("build-kit-file2", "file2-fixture");
            check(LocalGameBuild.Available(root, "file2"), "File #2 discovers its separate kit");
            string cache = Path.Combine(root, "cache");
            string firstPath = LocalGameBuild.TargetPath(root, "file1", cache);
            string secondPath = LocalGameBuild.TargetPath(root, "file2", cache);
            check(firstPath != secondPath && secondPath.Contains(Path.Combine("file2", "")),
                  "File #1 and File #2 builds have separate cache identities");
            var disc = new ImportedDisc(root, elf, 1, new FileInfo(elf).Length, false);
            int runs = 0;
            Task<int> Runner(ProcessStartInfo start, CancellationToken cancel) {
                runs++;
                check(start.FileName.Contains("build-kit-file2"), "File #2 invokes only its selected kit tool");
                var pe = new byte[128];
                BitConverter.GetBytes((ushort)0x5a4d).CopyTo(pe, 0);
                BitConverter.GetBytes(64).CopyTo(pe, 60);
                BitConverter.GetBytes(0x00004550).CopyTo(pe, 64);
                BitConverter.GetBytes((ushort)0x8664).CopyTo(pe, 68);
                File.WriteAllBytes(Path.Combine(start.ArgumentList[0], "reo_recomp.exe"), pe);
                return Task.FromResult(0);
            }
            async Task<string> Build() => await LocalGameBuild.EnsureVerified(root, disc, second.ElfSha256,
                home: cache, runner: Runner, game: "file2");
            string built = await Build();
            check(built == secondPath && File.Exists(built) && !File.Exists(firstPath),
                  "Building File #2 never creates or replaces a File #1 executable");
            check(await Build() == built && runs == 1, "File #2 reuses its verified build receipt");
            bool wrongGame = false;
            try {
                await LocalGameBuild.ImportExistingVerified(root, built, second.ElfSha256, home: cache);
            } catch (IOException) { wrongGame = true; }
            check(wrongGame, "A File #2 build receipt is rejected by the File #1 kit");
            check(await LocalGameBuild.ImportExistingVerified(root, built, second.ElfSha256,
                      home: cache, game: "file2") == built,
                  "File #2 existing-build import uses its own kit and cache");
            var settings = new Settings { SelectedGame = "file2", Iso = "first.iso", SecondIso = "second.iso" };
            settings.SetFile("iso", "");
            check(settings.Iso == "first.iso" && settings.SecondIso == "",
                  "Removing File #2's disc selection preserves File #1's selection");
        } finally { Directory.Delete(root, true); }
    }
}
