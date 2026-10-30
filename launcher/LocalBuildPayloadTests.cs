using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class LocalBuildPayloadTests {
    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-payload-Čakovec-測試-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        string previousHome = Settings.Home;
        string Hash(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
        var distribution = new Dictionary<string, string>();
        try {
            Storage.Configure(root);
            foreach (string game in new[] { "file1", "file2" }) {
                byte[] manifest = JsonSerializer.SerializeToUtf8Bytes(new { fixture = game });
                string identity = Hash(manifest);
                string archive = Path.Combine(root, game == "file1" ? "build-inputs.zip" : "build-inputs-file2.zip");
                using (var zip = ZipFile.Open(archive, ZipArchiveMode.Create)) {
                    using (var stream = zip.CreateEntry("build-kit.json").Open()) stream.Write(manifest);
                    using (var writer = new StreamWriter(zip.CreateEntry("source/ordinary.txt").Open()))
                        writer.Write(game);
                    // Source trees can be deep even under a short selected storage folder.
                    using (var writer = new StreamWriter(zip.CreateEntry(
                        "source/" + string.Join('/', Enumerable.Repeat(new string('x', 45), 6)) + "/deep.txt").Open()))
                        writer.Write("independent deep-path fixture");
                }
                string prefix = game == "file1" ? "" : "file2";
                distribution[prefix + (game == "file1" ? "kitSha256" : "KitSha256")] = identity;
                distribution[prefix + (game == "file1" ? "inputsSha256" : "InputsSha256")] = Hash(File.ReadAllBytes(archive));
            }
            File.WriteAllText(Path.Combine(root, "distribution.json"), JsonSerializer.Serialize(distribution));
            foreach (string game in new[] { "file1", "file2" }) {
                LocalGameBuild.ExpandPayload(root, null, default, game);
                string identity = distribution[game == "file1" ? "kitSha256" : "file2KitSha256"];
                string kit = Path.Combine(Settings.Home, "build-kits", identity);
                check(Hash(File.ReadAllBytes(Path.Combine(kit, "build-kit.json"))) == identity &&
                      File.ReadAllText(Path.Combine(kit, "source", "ordinary.txt")) == game,
                      game + " expands and verifies its own archive after the other edition's setup");
                check(Directory.GetFiles(kit, "deep.txt", SearchOption.AllDirectories).Single().Length > 260,
                      game + " extracts real source paths beyond MAX_PATH in a Unicode storage folder");
                LocalGameBuild.ExpandPayload(root, null, default, game);
                check(Directory.GetDirectories(Path.Combine(Settings.Home, "build-kits"), "*.previous-*").Length == 0,
                      game + " reuses verified setup without replacing either edition's cache");
            }
        } finally {
            Storage.Configure(root, previousHome);
            Directory.Delete(root, true);
        }
    }
}
