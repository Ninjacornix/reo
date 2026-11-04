using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;
static class GamePakTests {
    sealed class Progress(Action<ImportProgress> callback) : IProgress<ImportProgress> { public void Report(ImportProgress p) => callback(p); }
    public static void Run(Action<bool, string> check) {
        var settings = new Settings { Iso = "one.iso", SecondIso = "two.iso" };
        check(!settings.UsesGamePak() && settings.GetGameSource() == "one.iso", "ISO remains the default source");
        settings.SetGamePak(true); settings.SetGameSource("one.pak"); settings.SelectedGame = "file2";
        check(!settings.UsesGamePak() && settings.GetGameSource() == "two.iso", "PAK switch is independent per game");
        settings.SetGamePak(true); settings.SetGameSource("two.pak"); settings.SelectedGame = "file1";
        check(settings.GetGameSource() == "one.pak" && settings.Iso == "one.iso", "Switch retains each game's PAK and ISO");
        settings.SetGamePak(false);
        check(settings.GetGameSource() == "one.iso" && settings.GetGameSource("file2") == "two.pak", "Switching back preserves both sources");
        settings.RememberGamePak(new("export-one", 1, 1, false));
        check(!settings.UsesGamePak() && settings.GamePakFile1 == Path.Combine("export-one", "original-assets.pak"), "Export remembers its PAK path without changing source mode");
        check(settings.GamePakFile2 == "two.pak", "Remembering an export leaves the other game's source intact");
        string root = Path.Combine(Path.GetTempPath(), "reo-game-pak-tests-" + Guid.NewGuid().ToString("N")); Directory.CreateDirectory(root);
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                byte[] elf = "synthetic executable for game PAK validation"u8.ToArray();
                string sha(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
                string expected = sha(elf), home = Path.Combine(root, game), pak = Path.Combine(root, game + ".pak");
                var payloads = new Dictionary<string, byte[]> {
                    [GameDefinition.Find(game).ElfName] = elf,
                    ["NETBIO00.DAT"] = "header payload nonzero padding"u8.ToArray(),
                    ["NETBIO01.DAT"] = "second archive"u8.ToArray(),
                    ["BOOT/OVERLAY.BIN"] = new byte[] { 1, 3, 8, 9 },
                    ["EMPTY.BIN"] = Array.Empty<byte>()
                };
                if (game == "file1") payloads["NETBIO02.DAT"] = "third archive"u8.ToArray();
                GamePaks.Manifest Manifest(string? unsafeName = null, bool wrongHash = false, bool gap = false) {
                    var files = payloads.Select((p, i) => new GamePaks.DataFile(i == 0 && unsafeName != null ? unsafeName : p.Key,
                        p.Value.Length, wrongHash && i == 1 ? new string('0', 64) : sha(p.Value),
                        p.Value.Length == 0 ? new() : new() { new(gap && i == 1 ? 1 : 0, p.Value.Length, "bytes/" + i) })).ToList();
                    return new(1, game, expected, files);
                }
                void Write(GamePaks.Manifest manifest, bool header = true, bool duplicate = false) {
                    using var zip = ZipFile.Open(pak, ZipArchiveMode.Create);
                    foreach (var pair in payloads.Select((p, i) => (p.Value, Name: "bytes/" + i))) { using var output = zip.CreateEntry(pair.Name).Open(); output.Write(pair.Value); }
                    if (header) { using var output = zip.CreateEntry(GamePaks.Header).Open(); JsonSerializer.Serialize(output, manifest, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }); }
                    if (duplicate) { using var output = zip.CreateEntry("bytes/0").Open(); output.Write(elf); }
                }
                void Reject(string label, GamePaks.Manifest manifest, bool header = true, bool duplicate = false) {
                    string bad = Path.Combine(root, "bad-" + Guid.NewGuid().ToString("N"));
                    File.Delete(pak); Write(manifest, header, duplicate);
                    try { GamePaks.Import(pak, game, null, default, bad, expected); check(false, label); }
                    catch (IOException) { check(!Directory.Exists(bad) || !Directory.EnumerateDirectories(bad, ".pak-import-*", SearchOption.AllDirectories).Any(), label); }
                }
                Write(Manifest());
                var first = GamePaks.Import(pak, game, null, default, home, expected);
                check(!first.Reused && payloads.All(p => File.ReadAllBytes(Path.Combine(first.Root, "data", p.Key)).AsSpan().SequenceEqual(p.Value)), game + " PAK reconstructs every boot and asset byte without ISO");
                string archive = Path.Combine(first.Root, "data", "NETBIO00.DAT"); var stamp = File.GetLastWriteTimeUtc(archive);
                check(GamePaks.Import(pak, game, null, default, home, expected).Reused && File.GetLastWriteTimeUtc(archive) == stamp, game + " PAK cache reused without rewriting game data");
                string moved = Path.Combine(root, "moved-" + game + ".pak"); File.Move(pak, moved);
                var relocated = GamePaks.Import(moved, game, null, default, home, expected);
                check(relocated.Reused && File.GetLastWriteTimeUtc(archive) == stamp && JsonSerializer.Deserialize<ImportManifest>(File.ReadAllText(Path.Combine(relocated.Root, "import.json")))!.Source == moved,
                    game + " relocated PAK reuses cache and repairs source path");
                File.Move(moved, pak);
                var linked = GamePaks.Import(pak, game, null, default, Path.Combine(root, "linked-" + game), expected, first.Root);
                check(!linked.Reused && payloads.All(p => File.ReadAllBytes(Path.Combine(linked.Root, "data", p.Key)).AsSpan().SequenceEqual(p.Value)), game + " matching existing import reused after PAK verification");
                using (var zip = ZipFile.Open(pak, ZipArchiveMode.Update)) {
                    zip.GetEntry("bytes/1")!.Delete();
                    using var output = zip.CreateEntry("bytes/1").Open(); output.Write(new byte[payloads["NETBIO00.DAT"].Length]);
                }
                try { GamePaks.Import(pak, game, null, default, Path.Combine(root, "corrupt-linked-" + game), expected, first.Root); check(false, game + " existing import cannot hide a corrupt PAK"); }
                catch (IOException) { check(true, game + " existing import cannot hide a corrupt PAK"); }
                File.Delete(pak); Write(Manifest());
                using var partialCancel = new CancellationTokenSource();
                string partialHome = Path.Combine(root, "partial-" + game);
                try {
                    GamePaks.Import(pak, game, new Progress(p => { if (p.Stage == "Preparing game from PAK" && p.Completed > 0) partialCancel.Cancel(); }), partialCancel.Token, partialHome, expected);
                    check(false, game + " cancel removes partially written cache and preserves completed data");
                } catch (OperationCanceledException) {
                    check(!Directory.EnumerateDirectories(partialHome, ".pak-import-*", SearchOption.AllDirectories).Any() && File.Exists(archive),
                        game + " cancel removes partially written cache and preserves completed data");
                }
                using var canceled = new CancellationTokenSource(); canceled.Cancel();
                try { GamePaks.Import(pak, game, null, canceled.Token, Path.Combine(root, "cancel-" + game), expected); check(false, game + " import honors cancellation"); }
                catch (OperationCanceledException) { check(true, game + " import honors cancellation"); }
                var other = game == "file1" ? "file2" : "file1";
                try { GamePaks.Import(pak, other, null, default, home, expected); check(false, game + " wrong edition rejected"); }
                catch (IOException) { check(true, game + " wrong edition rejected"); }
                try { GamePaks.Check(pak, game); check(false, game + " unsupported executable identity rejected"); }
                catch (IOException) { check(true, game + " unsupported executable identity rejected"); }
                Reject(game + " traversal rejected", Manifest("../escape"));
                Reject(game + " device names rejected", Manifest("CON.txt"));
                Reject(game + " archive range gaps rejected", Manifest(gap: true));
                Reject(game + " corrupt payload rejected and staging cleaned", Manifest(wrongHash: true));
                Reject(game + " old asset-only PAK rejected", Manifest(), header: false);
                Reject(game + " duplicate ZIP members rejected", Manifest(), duplicate: true);
                check(File.Exists(archive), game + " bad PAK does not damage a completed import");
            }
        } finally {
            if (Path.GetDirectoryName(Path.GetFullPath(root)) == Path.TrimEndingDirectorySeparator(Path.GetFullPath(Path.GetTempPath())) &&
                Path.GetFileName(root).StartsWith("reo-game-pak-tests-", StringComparison.Ordinal)) Directory.Delete(root, true);
        }
    }
}
