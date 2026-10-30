using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
static class BundledRandomizerTests {
    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-bundled-mods-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            var settings = new Settings();
            foreach (string game in new[] { "file1", "file2" }) {
                settings.SelectedGame = game;
                string folder = Path.Combine(root, game);
                check(Mods.EnsureBundledRandomizer(settings, folder), game + " installs its bundled Randomizer on first use");
                var mod = Mods.Load(folder, game).Single();
                check(mod.Manifest?.Id == Mods.RandomizerId && mod.Error.Length == 0 &&
                    mod.Manifest.ElfSha256 == DiscImport.ExpectedElf(game) && settings.ActiveMods.Count == 0,
                    game + " offers the matching valid Randomizer without enabling gameplay changes");
                string original = File.ReadAllText(mod.File);
                check(!Mods.EnsureBundledRandomizer(settings, folder) && File.ReadAllText(mod.File) == original,
                    game + " initialization is idempotent and preserves its installed package");
                File.Delete(mod.File);
                var reloaded = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
                check(!Mods.EnsureBundledRandomizer(reloaded, folder) && Mods.Load(folder, game).Count == 0,
                    game + " respects deletion after settings reload");
            }
            settings = new Settings { SelectedGame = "file2" };
            string editedFolder = Path.Combine(root, "edited");
            Directory.CreateDirectory(editedFolder);
            string edited = Path.Combine(editedFolder, Mods.RandomizerId + ".json");
            File.WriteAllText(edited, "User-edited invalid package fixture");
            Mods.EnsureBundledRandomizer(settings, editedFolder);
            check(File.ReadAllText(edited) == "User-edited invalid package fixture",
                "Bundled installation never overwrites an existing invalid or edited package");
        } finally { Directory.Delete(root, true); }
    }
}
