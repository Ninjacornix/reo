using System.IO;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class ExistingGameBuildTests {
    internal static async Task Run(Action<bool, string> check) {
        string root =
            Path.Combine(Path.GetTempPath(), "reo-existing-game-" + Guid.NewGuid().ToString("N"));
        string source = Path.Combine(root, "source"), kitFolder = Path.Combine(root, "build-kit"),
               cache = Path.Combine(root, "cache");
        Directory.CreateDirectory(source);
        Directory.CreateDirectory(kitFolder);
        string exe = Path.Combine(source, "reo_recomp.exe"),
               elf = Path.Combine(root, "fixture.elf");
        string Sha(string file) =>
            Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(file))).ToLowerInvariant();
        var pe = new byte[128];
        BitConverter.GetBytes((ushort)0x5a4d).CopyTo(pe, 0);
        BitConverter.GetBytes(64).CopyTo(pe, 60);
        BitConverter.GetBytes(0x4550).CopyTo(pe, 64);
        BitConverter.GetBytes((ushort)0x8664).CopyTo(pe, 68);
        File.WriteAllBytes(exe, pe);
        File.WriteAllText(elf, "Synthetic disc input; no game data");
        File.WriteAllText(Path.Combine(source, "runtime.dll"),
                          "Synthetic companion, never executed");
        File.WriteAllText(Path.Combine(kitFolder, "tool.bin"), "Synthetic tool, never executed");
        var kit = new LocalBuildKit(
            1, "fixture", "win-x64", Sha(elf),
            new[] { new BuildKitFile("tool.bin", Sha(Path.Combine(kitFolder, "tool.bin"))) },
            new[] { new LocalBuildStep("Never run", "tool.bin", new[] { "{output}" }) },
            new[] { "reo_recomp.exe", "runtime.dll" });
        string manifest = Path.Combine(kitFolder, LocalGameBuild.ManifestName);
        File.WriteAllText(manifest, JsonSerializer.Serialize(kit));
        var receipt = new LocalBuildReceipt(
            1, Sha(manifest), kit.ElfSha256, "win-x64",
            kit.Outputs.Select(name => new BuildKitFile(name, Sha(Path.Combine(source, name))))
                .ToArray());
        string record = Path.Combine(source, "local-build.json");
        void WriteReceipt(LocalBuildReceipt value) =>
            File.WriteAllText(record, JsonSerializer.Serialize(value));
        async Task<bool> Refused() {
            try {
                await LocalGameBuild.ImportExistingVerified(root, exe, kit.ElfSha256, home: cache);
                return false;
            } catch (IOException) {
                return true;
            }
        }
        try {
            check(await Refused(), "a bare game EXE is refused without its build receipt");
            WriteReceipt(receipt with { KitSha256 = new string('0', 64) });
            check(await Refused(), "a game built with a different kit is refused");
            WriteReceipt(receipt);
            File.Move(Path.Combine(source, "runtime.dll"), Path.Combine(source, "held.dll"));
            check(await Refused(), "missing companion files are refused");
            File.Move(Path.Combine(source, "held.dll"), Path.Combine(source, "runtime.dll"));
            string target =
                await LocalGameBuild.ImportExistingVerified(root, exe, kit.ElfSha256, home: cache);
            check(File.Exists(target) && Sha(target) == Sha(exe) &&
                      File.Exists(Path.Combine(Path.GetDirectoryName(target)!, "runtime.dll")),
                  "complete existing build and companions are admitted");
            check(File.Exists(exe) && File.Exists(record), "original build is preserved");
            int builds = 0;
            var disc = new ImportedDisc(root, elf, 1, 1, true);
            string reused = await LocalGameBuild.EnsureVerified(root, disc, kit.ElfSha256,
                                                                home: cache, runner: (_, _) => {
                                                                    builds++;
                                                                    return Task.FromResult(99);
                                                                });
            check(reused == target && builds == 0,
                  "imported executable skips the compiler on next launch");
            File.AppendAllText(Path.Combine(source, "runtime.dll"), "tampered");
            check(await Refused() && Sha(target) == receipt.Outputs[0].Sha256,
                  "failed replacement preserves the admitted game");
            using var cancellation = new CancellationTokenSource();
            cancellation.Cancel();
            bool cancelled = false;
            try {
                await LocalGameBuild.ImportExistingVerified(
                    root, exe, kit.ElfSha256, cancel: cancellation.Token, home: cache);
            } catch (OperationCanceledException) {
                cancelled = true;
            }
            check(cancelled && File.Exists(target), "cancellation preserves the existing build");
            bool unsupported = false;
            try {
                await LocalGameBuild.ImportExisting(root, exe);
            } catch (IOException) {
                unsupported = true;
            }
            check(unsupported, "public import rejects synthetic unsupported game identity");
        } finally {
            Directory.Delete(root, true);
        }
    }
}
