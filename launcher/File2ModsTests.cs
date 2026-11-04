using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class File2ModsTests {
    internal static void Run(Action<bool, string> check) {
        File2ItemModelTests.Run(check);
        string first = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", "randomizer.json"));
        string second = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", "randomizer-file2.json"));
        var mod = Mods.Parse(second);
        check(mod.ElfSha256 == DiscImport.SecondElfSha256 && mod.ItemRandomizer?.Mode == "global" &&
              mod.EnemyRandomizer?.Mode == "enemyTypes" && mod.Patches.Count == 0 && mod.Effects.Count == 0,
              "File #2 sample uses its pinned ELF and independent global item/enemy randomizers");
        var unavailable = new HashSet<int> { 9, 10, 17, 26, 27, 37, 38, 55 };
        check(mod.EnemyRandomizer!.Pool.Count > 0 && mod.EnemyRandomizer.Pool.All(p => !unavailable.Contains(p.Type)),
              "File #2 sample excludes File #1 families without actual File #2 callbacks");
        check(Mods.FolderFor("file1") == Mods.Folder && Mods.FolderFor("file1") != Mods.FolderFor("file2"),
              "Installed mod folders are game-specific and File #1's path stays stable");
        var settings = new Settings { SelectedGame = "file1", EnabledMods = new() { "first.selection" } };
        settings.SelectedGame = "file2";
        check(settings.ActiveMods.Count == 0, "Switching to File #2 does not enable File #1 selections");
        settings.ActiveMods.Add(mod.Id);
        settings.SelectedGame = "file1";
        check(settings.ActiveMods.SequenceEqual(new[] { "first.selection" }), "Switching back preserves File #1 selections");
        string temp = Path.Combine(Path.GetTempPath(), "reo-file2-mods-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        void Reject(Action action, string label) {
            try { action(); check(false, label); } catch (IOException) { check(true, label); }
        }
        try {
            string firstInput = Path.Combine(temp, "first.json"), secondInput = Path.Combine(temp, "second.json");
            File.WriteAllText(firstInput, first); File.WriteAllText(secondInput, second);
            string folder = Path.Combine(temp, "installed");
            Reject(() => Mods.Import(firstInput, folder, "file2"), "File #1 package cannot be imported as File #2");
            Reject(() => Mods.Import(secondInput, folder), "File #2 package cannot be imported as File #1");
            Mods.Import(secondInput, folder, "file2");
            settings.SelectedGame = "file2";
            var selected = Mods.Selected(settings, folder);
            check(selected.Single().ElfSha256 == DiscImport.SecondElfSha256, "File #2 selects its own validated installed package");
            Reject(() => Mods.Import(secondInput, folder, "file2"), "File #2 imports cannot overwrite installed packages");
            settings.SelectedGame = "file1"; settings.EnabledMods = new() { mod.Id };
            Reject(() => Mods.Selected(settings, folder), "A copied File #2 package cannot launch as File #1");
            settings.SelectedGame = "file2";
            var seeds = new RandomizerSeeds();
            var launched = seeds.ForLaunch(selected, "offline", () => 42);
            check(launched.Single().ItemRandomizer!.Seed == 42 && launched.Single().EnemyRandomizer!.Seed == 42 &&
                  selected.Single().ItemRandomizer!.Seed == 2027,
                  "File #2 launch seed is shared across randomizers without changing installed settings");
            var json = new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
            check(JsonSerializer.Serialize(launched.Single().EnemyRandomizer!.Pool, json) ==
                  JsonSerializer.Serialize(selected.Single().EnemyRandomizer!.Pool, json),
                  "File #2 automatic seed selection preserves the complete weighted enemy pool");
            var one = RandomizerSession.Create("reo01", new(), "file1");
            var two = RandomizerSession.Create("reo01", launched, "file2");
            check(RandomizerSession.Parse(two, "file2").Elf == DiscImport.SecondElfSha256 &&
                  RandomizerSession.ModsFor(RandomizerSession.Parse(two)).Single().ItemRandomizer!.Seed == 42,
                  "File #2 host configuration carries its own ELF, pool and seeds");
            Reject(() => RandomizerSession.Parse(one, "file2"), "File #2 join rejects a File #1 host, including an unmodded one");
            Reject(() => RandomizerSession.Parse(two, "file1"), "File #1 join rejects a File #2 host");
            Reject(() => RandomizerSession.Create("reo01", launched), "Host cannot publish a package for the other game");
            settings.ActiveMods.Clear();
            check(Mods.Selected(settings, folder).Count == 0, "Disabling File #2 randomizers clears their launch selection");
        } finally { Directory.Delete(temp, true); }
    }
}
