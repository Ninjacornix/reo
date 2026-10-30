using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
internal static class ReferencePakModTests {
    public static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-reference-pak-tests-" + Guid.NewGuid().ToString("N")); Directory.CreateDirectory(root);
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                string source = Path.Combine(root, game + ".pak"), mods = Path.Combine(root, game + "-mods");
                byte[] original = "original"u8.ToArray(), changed = "changed asset bytes"u8.ToArray();
                string hash = Convert.ToHexString(SHA256.HashData(original)).ToLowerInvariant();
                var options = new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
                string address = game == "file1" ? "0x00250F30" : "0x00255C50";
                void Write(bool edited, bool csv = false, bool invalid = false, bool padding = false) {
                    File.Delete(source); using var zip = ZipFile.Open(source, ZipArchiveMode.Create);
                    void Json(string name, object value) { using var writer = new StreamWriter(zip.CreateEntry(name).Open()); writer.Write(JsonSerializer.Serialize(value, options)); }
                    Json("asset-reference.json", new { format = 1, kind = "original-assets", game, elfSha256 = DiscImport.ExpectedElf(game) });
                    Json("assets.json", new { format = 1, verified = true, entries = new[] { new { path = "NETBIO00.DAT/0/0", file = "NETBIO00.DAT/00000_native.bin", sha256 = hash } } });
                    using (var output = zip.CreateEntry("NETBIO00.DAT/00000_native.bin").Open()) output.Write(edited ? changed : original);
                    Json("executable-strings/ui-strings.json", new { format = 1, game, elfSha256 = DiscImport.ExpectedElf(game), entries = new[] { new {
                        id = "test", address, maxBytes = 8, originalText = "original", originalBytesHex = Convert.ToHexString(original), originalSha256 = hash,
                        paddingMaxBytes = 24, usePadding = padding, translation = edited && !csv ? (padding ? "LONGER TRANSLATION" : "PAK TEST") : null } } });
                    if (csv) {
                        using var writer = new StreamWriter(zip.CreateEntry("executable-strings/ui-strings.csv").Open(), Encoding.UTF8);
                        writer.Write($"id,address,maxBytes,originalText,translation,usePadding\r\ntest,{address},8,original,{(padding ? "LONGER TRANSLATION" : "PAK CSV")},{padding}\r\n");
                    }
                    if (invalid) Json("../escape", new { invalid = true });
                }
                Write(false);
                try { AssetPaks.Import(source, mods); check(false, game + " unchanged game export is not installed as an empty mod"); }
                catch (IOException) { check(!Directory.Exists(mods), game + " unchanged game export is not installed as an empty mod"); }
                Write(true); byte[] before = File.ReadAllBytes(source); AssetPaks.Import(source, mods);
                var installed = AssetPaks.Load(mods); var manifest = installed.Single().Manifest!;
                check(installed.Single().Error.Length == 0 && manifest.Game == game && manifest.Replace.Count == 1 && manifest.Strings.Single().Text == "PAK TEST",
                    game + " importing an edited export compiles assets and executable strings together");
                using (var zip = ZipFile.OpenRead(installed.Single().File)) {
                    using var input = zip.GetEntry(manifest.Replace.Single().File)!.Open(); using var output = new MemoryStream(); input.CopyTo(output);
                    check(output.ToArray().AsSpan().SequenceEqual(changed) && zip.Entries.Count == 2,
                        game + " compiled mod contains only changed native payloads and its manifest");
                }
                check(File.ReadAllBytes(source).AsSpan().SequenceEqual(before), game + " edited source PAK is preserved during mod import");
                try { AssetPaks.Import(source, mods); check(false, game + " repeated import never overwrites an installed mod"); }
                catch (IOException) { check(AssetPaks.Load(mods).Count == 1, game + " repeated import never overwrites an installed mod"); }
                Write(false, csv: true); string csvMods = Path.Combine(root, game + "-csv"); AssetPaks.Import(source, csvMods);
                var csvManifest = AssetPaks.Load(csvMods).Single().Manifest!;
                check(csvManifest.Replace.Count == 0 && csvManifest.Strings.Single().Text == "PAK CSV", game + " edited CSV alone produces an installable string-only mod");
                Write(true, padding: true); string paddedMods = Path.Combine(root, game + "-padding-json"); AssetPaks.Import(source, paddedMods);
                check(AssetPaks.Load(paddedMods).Single().Manifest!.Strings.Single() is { UsePadding: true, MaxBytes: 24, Text: "LONGER TRANSLATION" },
                      game + " edited JSON explicitly opts into the exported padding budget");
                Write(false, csv: true, padding: true); paddedMods = Path.Combine(root, game + "-padding-csv"); AssetPaks.Import(source, paddedMods);
                check(AssetPaks.Load(paddedMods).Single().Manifest!.Strings.Single() is { UsePadding: true, MaxBytes: 24, Text: "LONGER TRANSLATION" },
                      game + " edited CSV explicitly opts into the exported padding budget");
                Write(true, invalid: true);
                try { AssetPaks.Import(source, Path.Combine(root, game + "-unsafe")); check(false, game + " edited reference import rejects ZIP traversal"); }
                catch (IOException) { check(!File.Exists(Path.Combine(root, "escape")), game + " edited reference import rejects ZIP traversal"); }
                Write(true); using var cancel = new CancellationTokenSource(); cancel.Cancel();
                try { AssetPaks.Import(source, Path.Combine(root, game + "-cancel"), cancel.Token); check(false, game + " edited-reference import honors cancellation"); }
                catch (OperationCanceledException) { check(!Directory.Exists(Path.Combine(root, game + "-cancel")), game + " edited-reference import honors cancellation"); }
            }
        } finally {
            if (Path.GetDirectoryName(Path.GetFullPath(root)) == Path.TrimEndingDirectorySeparator(Path.GetFullPath(Path.GetTempPath())) &&
                Path.GetFileName(root).StartsWith("reo-reference-pak-tests-", StringComparison.Ordinal)) Directory.Delete(root, true);
        }
    }
}
