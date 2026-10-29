using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
internal static class StaleImportTests {
    internal static void Run(Action<bool, string> check) {
        string home = Path.Combine(Path.GetTempPath(), "reo-stale-imports-" + Guid.NewGuid().ToString("N")); Directory.CreateDirectory(home);
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                var settings = new Settings(); string parent = Path.Combine(home, "imports", game); Directory.CreateDirectory(parent);
                string Make(char id, string? otherGame = null, bool pak = false) {
                    string folder = Path.Combine(parent, (pak ? "pak-" : "") + new string(id, 64)); Directory.CreateDirectory(Path.Combine(folder, "data"));
                    string elf = GameDefinition.Find(game).ElfName; File.WriteAllBytes(Path.Combine(folder, "data", elf), new byte[16]);
                    File.WriteAllText(Path.Combine(folder, "import.json"), JsonSerializer.Serialize(new ImportManifest(pak ? 2 : 1, otherGame ?? game,
                        Path.Combine(home, "owned-" + game + ".iso"), 16, 0, DiscImport.ExpectedElf(game), new[] { new ImportedFile(elf, 16, new string('0', 64)) })));
                    return folder;
                }
                string current = Make('a'), stale = Make('b'), unknown = Make('c'), wrongGame = Make('d', game == "file1" ? "file2" : "file1");
                if (game == "file1") settings.ImportedFile1 = current; else settings.ImportedFile2 = current;
                File.WriteAllText(Path.Combine(unknown, "personal.txt"), "keep");
                string unfinished = Path.Combine(parent, ".import-unfinished"); Directory.CreateDirectory(unfinished); File.WriteAllText(Path.Combine(unfinished, "keep"), "pending");
                var found = StaleImports.Find(settings, game, home);
                check(found.Count == 1 && found[0].Path == stale && found[0].Bytes > 16, game + " cleanup lists only completed unselected imports with known files");
                string pak = Make('e', pak: true);
                var oldPak = StaleImports.Find(settings, game, home).Single(c => c.Path == pak);
                check(StaleImports.Remove(new[] { oldPak }, settings, game, home).Count == 0 && !Directory.Exists(pak),
                      game + " version-2 PAK imports can be cleaned independently of ISO imports");
                string malformed = Make('f');
                var broken = JsonSerializer.Serialize(new { Version = 1, Game = game, Source = "old.iso", ElfSha256 = DiscImport.ExpectedElf(game), Files = new object?[] { null } });
                File.WriteAllText(Path.Combine(malformed, "import.json"), broken);
                check(StaleImports.Find(settings, game, home).Count == 1 && Directory.Exists(malformed), game + " malformed import records are preserved without crashing cleanup");
                settings.Iso = Path.Combine(stale, "source.iso");
                check(StaleImports.Find(settings, game, home).Count == 0, game + " cleanup protects remembered source ISOs inside an old folder");
                settings.Iso = "";
                settings.GamePakFile1 = Path.Combine(stale, "source.pak");
                check(StaleImports.Find(settings, game, home).Count == 0, game + " cleanup protects remembered source PAKs even when their switch is off");
                settings.GamePakFile1 = "";
                using (var lease = new FileStream(Path.Combine(parent, "import.lock"), FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None)) {
                    try { StaleImports.Remove(found, settings, game, home); check(false, game + " cleanup shares the setup lock"); }
                    catch (IOException) { check(Directory.Exists(stale), game + " cleanup shares the setup lock"); }
                }
                if (game == "file1") settings.ImportedFile1 = stale; else settings.ImportedFile2 = stale;
                check(StaleImports.Remove(found, settings, game, home).Count == 1 && Directory.Exists(stale), game + " deletion rechecks selection changes after review");
                if (game == "file1") settings.ImportedFile1 = current; else settings.ImportedFile2 = current;
                string outside = Path.Combine(home, "personal"); Directory.CreateDirectory(outside); File.WriteAllText(Path.Combine(outside, "save"), "keep");
                check(StaleImports.Remove(new[] { new StaleImports.Candidate(outside, "", 0) }, settings, game, home).Count == 1 && Directory.Exists(outside),
                      game + " forged cleanup targets outside the game's imports are rejected");
                File.WriteAllText(Path.Combine(stale, "new-personal.txt"), "keep");
                check(StaleImports.Remove(found, settings, game, home).Count == 1 && Directory.Exists(stale), game + " new unknown files after review protect the folder");
                File.Delete(Path.Combine(stale, "new-personal.txt"));
                check(StaleImports.Remove(found, settings, game, home).Count == 0 && !Directory.Exists(stale), game + " confirmed stale fixture is deleted");
                check(Directory.Exists(current) && Directory.Exists(unknown) && Directory.Exists(wrongGame) && Directory.Exists(unfinished) &&
                      File.ReadAllText(Path.Combine(outside, "save")) == "keep", game + " current game, unknown imports, pending setup and personal saves survive cleanup");
            }
        } finally {
            if (Path.GetDirectoryName(Path.GetFullPath(home)) == Path.TrimEndingDirectorySeparator(Path.GetFullPath(Path.GetTempPath())) &&
                Path.GetFileName(home).StartsWith("reo-stale-imports-", StringComparison.Ordinal)) Directory.Delete(home, true);
        }
    }
}
