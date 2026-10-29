using System.IO;

namespace Outbreak.Launcher;
static class ModsTests {
    public static void Run(Action<bool, string> check) {
        File2ModsTests.Run(check);
        string example = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", "no-infection.json"));
        void Reject(Action action, string name) {
            try { action(); } catch (IOException) { check(true, name); return; }
            check(false, name);
        }
        var mod = Mods.Parse(example);
        string Fixture(string id, string config) => $$"""
            { "format": 1, "id": "{{id}}", "name": "Test fixture", "version": "1.0.0",
              "elfSha256": "{{DiscImport.FirstElfSha256}}", {{config}} }
            """;
        string shuffleJson = Fixture("example.weapon-shuffle", "\"weaponShuffle\": {\"seed\": 2027}");
        var shuffle = Mods.Parse(shuffleJson);
        string itemsJson = Fixture("example.item-randomizer", "\"itemRandomizer\": {\"seed\": 2027}");
        var items = Mods.Parse(itemsJson);
        check(Mods.Parse(itemsJson.Replace("\"seed\": 2027", "\"seed\": 2027, \"mode\": \"global\"")).ItemRandomizer!.Mode == "global",
            "Global item catalogue mode parses explicitly");
        Reject(() => Mods.Parse(itemsJson.Replace("\"seed\": 2027", "\"seed\": 2027, \"mode\": \"unknown\"")),
            "Unknown global item mode is rejected");
        string enemiesJson = Fixture("example.zombie-randomizer", "\"enemyRandomizer\": {\"seed\": 2031, \"mode\": \"zombieProfiles\"}");
        var enemies = Mods.Parse(enemiesJson);
        string combinedJson = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", "randomizer.json"));
        var combined = Mods.Parse(combinedJson);
        check(combined.ItemRandomizer?.Seed == 2027 && combined.EnemyRandomizer?.Seed == 2031 && combined.EnemyRandomizer.Mode == "enemyTypes",
            "Randomizer includes the item/gun pool and species mode");
        check(combined.Id == Mods.RandomizerId && combined.Name == "Randomizer" && combined.WeaponShuffle == null &&
            combined.Effects.Count == 0 && combined.Patches.Count == 0, "One Randomizer package without practice effects or a conflicting gun shuffle");
        check(enemies.EnemyRandomizer?.Seed == 2031 && enemies.EnemyRandomizer.Mode == "zombieProfiles", "Zombie randomizer parses without cheats");
        var ground = Mods.Parse(combinedJson);
        check(ground.EnemyRandomizer?.Mode == "enemyTypes" && ground.Effects.Count == 0 && ground.Patches.Count == 0,
            "Ground species mode parses without cheat effects or patches");
        string WithEnemy(string property,string value) {
            var node=System.Text.Json.Nodes.JsonNode.Parse(combinedJson)!;
            node["enemyRandomizer"]![property]=System.Text.Json.Nodes.JsonNode.Parse(value);
            return node.ToJsonString();
        }
        foreach(var invalid in new[]{"null","[]","[{\"type\":64,\"model\":0,\"health\":300}]","[{\"type\":2,\"model\":1,\"health\":0}]",
            "[{\"type\":2,\"model\":256,\"health\":300}]","[{\"type\":2,\"model\":1,\"health\":300,\"weight\":0}]",
            "[{\"type\":2,\"model\":1,\"health\":300},{\"type\":2,\"model\":1,\"health\":400}]"})
            Reject(()=>Mods.Parse(WithEnemy("pool",invalid)),"Invalid enemy pool rejected: "+invalid);
        foreach(var invalid in new[]{"null","[]","[0,0]","[-1]","[256]"})
            Reject(()=>Mods.Parse(WithEnemy("sourceBehaviors",invalid)),"Invalid enemy source behavior rejected: "+invalid);
        Reject(()=>Mods.Parse(WithEnemy("mode","\"zombieProfiles\"")),"Zombie profile mode cannot silently ignore a species pool");
        Reject(() => Mods.Parse(enemiesJson.Replace("2031", "-1")), "Negative enemy seed rejected");
        Reject(() => Mods.Parse(enemiesJson.Replace("zombieProfiles", "allSpecies")), "Unsupported enemy mode rejected");
        Reject(() => Mods.Parse(enemiesJson.Replace("\"zombieProfiles\"", "null")), "Null enemy mode rejected");
        check(items.ItemRandomizer?.Seed == 2027 && items.WeaponShuffle == null, "Item randomizer parses independently");
        string WithExclusions(string values) => itemsJson.Replace("\"seed\": 2027", "\"seed\": 2027, \"excludeItemTypes\": " + values);
        check(Mods.Parse(WithExclusions("[0, 300, 399]")).ItemRandomizer!.ExcludeItemTypes.SequenceEqual(new[] {0, 300, 399}),
            "Custom item exclusions parse");
        foreach (var invalid in new[] { "null", "[-1]", "[400]", "[0,0]", "[1.5]", "[\"0\"]" })
            Reject(() => Mods.Parse(WithExclusions(invalid)), "Invalid item exclusions rejected: " + invalid);
        Reject(() => Mods.Parse(itemsJson.Replace("2027", "-1")), "Negative item seed rejected");
        Reject(() => Mods.Parse(itemsJson.Replace("\"itemRandomizer\":", "\"weaponShuffle\": {\"seed\": 1}, \"itemRandomizer\":")),
            "Two randomizer modes in one package rejected");
        check(shuffle.WeaponShuffle?.Seed == 2027 && shuffle.Effects.Count == 0 && shuffle.Patches.Count == 0,
            "Weapon shuffle is independent of cheat effects");
        Reject(() => Mods.Parse(shuffleJson.Replace("2027", "-1")), "Negative randomizer seed rejected");
        Reject(() => Mods.Parse(shuffleJson.Replace("2027", "4294967296")), "Overflow randomizer seed rejected");
        check(mod.Id == "example.no-infection" && mod.Effects.SequenceEqual(new[] { "infection" }), "Example parses");
        Reject(() => Mods.Parse(example.Replace("\"format\": 1", "\"format\": 2")), "Future schema rejected");
        Reject(() => Mods.Parse(example.Replace(mod.Id, "../escape")), "Unsafe ID rejected");
        Reject(() => Mods.Parse(example.Replace(DiscImport.FirstElfSha256, "wrong")), "Wrong game build rejected");
        Reject(() => Mods.Parse(example.Replace("\"effects\"", "\"efects\"")), "Unknown field rejected");
        Reject(() => Mods.Parse(example.Replace("[\"infection\"]", "null")), "Null effects rejected");
        Reject(() => Mods.Parse(example.Replace("[\"infection\"]", "[\"script\"]")), "Unsupported effect rejected");
        Reject(() => Mods.Parse(example.Replace("[\"infection\"]", "[]")), "Empty mod rejected");
        Reject(() => Mods.Write(new() { Address = "00100000", Size = 4, Value = "0" }), "Code patch rejected");
        Reject(() => Mods.Write(new() { Address = "00580000", Size = 4, Value = "0" }), "Overlay patch rejected");
        Reject(() => Mods.Write(new() { Address = "0056FFFF", Size = 2, Value = "0" }), "Cross-boundary patch rejected");
        Reject(() => Mods.Write(new() { Address = "004A5C40", Size = 1, Value = "100" }), "Overflow rejected");
        Reject(() => Mods.Write(new() { Address = "004A5C40", Size = 3, Value = "0" }), "Invalid width rejected");
        check(Mods.Write(new() { When = "boot", Address = "004A5C40", Size = 2, Value = "1234" }) ==
            new CheatWrite(0, 0x4a5c40, 2, 0x1234), "Boot timing and hex encoding");
        string temp = Path.Combine(Path.GetTempPath(), "reo-mod-check-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        try {
            string folder = Path.Combine(temp, "mods"), source = Path.Combine(temp, "source.json");
            string image = Path.Combine(temp, "image.bin");
            File.WriteAllText(image, "older game build");
            check(!GameSession.SupportsZombieRandomizer(image), "Old build cannot silently ignore zombie randomizer");
            File.WriteAllText(image, new string(' ', 1024 * 1024 - 5) + "[MOD-ZOMBIE-RANDOMIZER-1] installed seed=%u");
            check(GameSession.SupportsZombieRandomizer(image), "Zombie capability detected across read boundary");
            check(!GameSession.SupportsEnemySpawnRandomizer(image), "Zombie-only build cannot accept species swaps");
            File.WriteAllText(image, new string(' ', 1024 * 1024 - 5) + "[MOD-ENEMY-SPAWN-1] installed seed=%u");
            check(!GameSession.SupportsEnemySpawnRandomizer(image), "Old room-family build cannot accept independent species mode");
            File.AppendAllText(image, RandomizerSession.Capability + "[MOD-ENEMY-ASSETS-1]");
            check(GameSession.SupportsEnemySpawnRandomizer(image), "Ground species capability detected across read boundary");
            File.WriteAllText(image, "older game build");
            check(!GameSession.SupportsWeaponShuffle(image), "Old game build cannot silently ignore shuffle");
            File.WriteAllText(image, new string(' ', 1024 * 1024 - 5) + "[MOD-WEAPON-SHUFFLE-1] installed seed=%u");
            check(GameSession.SupportsWeaponShuffle(image), "Shuffle capability detected across read boundary");
            File.WriteAllText(source, example);
            Mods.Import(source, folder);
            Reject(() => Mods.Import(source, folder), "Import does not overwrite existing mod");
            var settings = new Settings { CoopMode = "offline", CheatsEnabled = false,
                EnabledMods = new() { mod.Id } };
            var selected = Mods.Selected(settings, folder);
            File.WriteAllText(source, shuffleJson);
            Mods.Import(source, folder);
            settings.EnabledMods = new() { shuffle.Id };
            check(Mods.Selected(settings, folder).Single().WeaponShuffle?.Seed == 2027,
                "Randomizer selected with cheats disabled");
            check(Cheats.Export(settings, temp, new() { shuffle }) == "", "Randomizer does not export cheats");
            File.WriteAllText(source, shuffleJson.Replace(shuffle.Id, "example.second-shuffle"));
            Mods.Import(source, folder);
            settings.EnabledMods.Add("example.second-shuffle");
            Reject(() => Mods.Selected(settings, folder), "Multiple randomizers rejected");
            File.WriteAllText(source, itemsJson);
            Mods.Import(source, folder);
            File.WriteAllText(source, enemiesJson);
            Mods.Import(source, folder);
            settings.EnabledMods = new() { items.Id, enemies.Id };
            check(Mods.Selected(settings, folder).Count == 2, "Item and enemy randomizers combine");
            check(Cheats.Export(settings, temp, Mods.Selected(settings, folder)) == "", "Combined randomizers need no cheats");
            File.WriteAllText(source, enemiesJson.Replace(enemies.Id, "example.second-enemies"));
            Mods.Import(source, folder);
            settings.EnabledMods.Add("example.second-enemies");
            Reject(() => Mods.Selected(settings, folder), "Two enemy randomizers conflict");
            File.Delete(Path.Combine(folder, enemies.Id + ".json"));
            File.Delete(Path.Combine(folder, "example.second-enemies.json"));
            settings.EnabledMods = new() { shuffle.Id, items.Id };
            Reject(() => Mods.Selected(settings, folder), "Item and weapon randomizer conflict rejected");
            settings.EnabledMods = new() { items.Id };
            check(Mods.Selected(settings, folder).Single().ItemRandomizer?.Seed == 2027,
                "Item randomizer selected with cheats disabled");
            File.Delete(Path.Combine(folder, items.Id + ".json"));
            File.Delete(Path.Combine(folder, shuffle.Id + ".json"));
            File.Delete(Path.Combine(folder, "example.second-shuffle.json"));
            settings.EnabledMods = new() { mod.Id };
            check(selected.Count == 1, "Imported mod selected");
            string manifest = Cheats.Export(settings, temp, selected);
            check(File.ReadAllText(manifest).Contains("builtin infection") &&
                File.ReadAllText(manifest).StartsWith("REO-CHEATS-2"), "Mods reach runtime even with cheats off");
            Mods.SaveSession(selected, temp);
            check(File.ReadAllText(Path.Combine(temp, "mods.json")).Contains(mod.Id), "Session records selected package");
            settings.CoopMode = "join";
            check(Mods.Selected(settings, folder).Count == 0, "Joiners ignore local mods and use host configuration");
            settings.CoopMode = "host";
            Reject(() => Mods.Selected(settings, folder), "Online effect mods rejected");
            settings.CoopMode = "offline";
            File.WriteAllText(Path.Combine(folder, "duplicate.json"), example);
            check(Mods.Load(folder).All(x => x.Error.Length > 0), "Duplicate IDs displayed as errors");
            Reject(() => Mods.Selected(settings, folder), "Duplicate IDs block launch");
            File.Delete(Path.Combine(folder, "duplicate.json"));
            File.WriteAllText(Path.Combine(folder, mod.Id + ".json"), "{");
            check(Mods.Load(folder).Single().Error.Length > 0, "Broken JSON displayed as error");
            Reject(() => Mods.Selected(settings, folder), "Broken enabled mod blocks launch");
            settings.EnabledMods.Clear();
            check(Mods.Selected(settings, folder).Count == 0 && Cheats.Export(settings, temp) == "", "Disabled mods do not apply");
            mod.Effects.Clear();
            mod.Patches.Add(new() { Address = "004A5C40", Size = 2, Value = "1234" });
            var other = Mods.Parse(example);
            other.Id = "example.other";
            other.Patches.Add(new() { Address = "004A5C41", Size = 1, Value = "00" });
            Reject(() => Mods.Append(new() { mod, other }, new(), new()), "Partial byte overlap between mods blocked");
            Reject(() => Mods.Append(new() { mod }, new() { new(1, 0x4a5c41, 1, 0) }, new()), "Mod and cheat overlap blocked");
            string patches = Cheats.Export(settings, temp, new() { mod });
            check(File.ReadAllText(patches).Contains("1 004A5C40 2 0000000000001234"), "Data mod serialized for native runtime");
        } finally { Directory.Delete(temp, true); }
        ConsolidationTests(check, combinedJson, example);
    }
    static void ConsolidationTests(Action<bool, string> check, string combinedJson, string customJson) {
        string temp = Path.Combine(Path.GetTempPath(), "reo-mod-upgrade-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        try {
            var settings = new Settings { CoopMode = "offline", CheatsEnabled = false, EnabledMods = new() {
                "example.outbreak-randomizer", "example.weapon-shuffle", "example.zombie-randomizer", "example.practice-mode"
            } };
            string legacy = combinedJson.Replace(Mods.RandomizerId, "example.outbreak-randomizer")
                .Replace("2027", "444").Replace("2031", "555");
            File.WriteAllText(Path.Combine(temp, "combined.json"), legacy);
            foreach (string id in new[] { "example.item-randomizer", "example.weapon-shuffle",
                "example.zombie-randomizer", "example.ground-enemy-randomizer", "example.practice-mode" })
                File.WriteAllText(Path.Combine(temp, id + ".json"), customJson.Replace("example.no-infection", id));
            File.WriteAllText(Path.Combine(temp, "custom.json"), customJson);
            check(Mods.ConsolidateRandomizers(settings, temp), "Legacy enabled selections migrate");
            var installed = Mods.Load(temp);
            check(installed.Count == 2 && installed.Any(m => m.Manifest?.Id == "example.no-infection"),
                "Retires all six old samples while retaining unrelated mods");
            check(settings.EnabledMods.SequenceEqual(new[] { Mods.RandomizerId }), "Overlapping selections become one enabled Randomizer");
            var selected = Mods.Selected(settings, temp).Single();
            check(selected.ItemRandomizer?.Seed == 444 && selected.EnemyRandomizer?.Seed == 555 &&
                selected.EnemyRandomizer.Mode == "enemyTypes", "Migration preserves combined seeds and species pool");
            check(selected.WeaponShuffle == null && selected.Effects.Count == 0 && Cheats.Export(settings, temp, new() { selected }) == "",
                "Migrated Randomizer includes no practice effects or conflicting weapon shuffle");
            check(Directory.GetFiles(Path.Combine(temp, "retired-samples")).Length == 6 &&
                File.ReadAllText(Path.Combine(temp, "retired-samples", "combined.json")) == legacy,
                "Original installed samples remain recoverable outside the active list");
            check(!Mods.ConsolidateRandomizers(settings, temp), "Migration is idempotent");
            File.WriteAllText(Path.Combine(temp, "combined.json"), legacy.Replace("444", "999"));
            Mods.ConsolidateRandomizers(settings, temp);
            check(Mods.Selected(settings, temp).Single().ItemRandomizer?.Seed == 444,
                "Reimported old samples cannot overwrite the current Randomizer");
            string practiceOnly = Path.Combine(temp, "practice-only");
            Directory.CreateDirectory(practiceOnly);
            File.WriteAllText(Path.Combine(practiceOnly, "practice.json"), customJson.Replace("example.no-infection", "example.practice-mode"));
            var practiceSettings = new Settings { EnabledMods = new() { "example.practice-mode" } };
            check(Mods.ConsolidateRandomizers(practiceSettings, practiceOnly) && practiceSettings.EnabledMods.Count == 0 &&
                Mods.Load(practiceOnly).Single().Manifest?.Name == "Randomizer", "Removing Practice Mode does not enable randomization");
            var missing = new Settings { EnabledMods = new() { "example.weapon-shuffle" } };
            check(Mods.ConsolidateRandomizers(missing, Path.Combine(temp, "missing")) &&
                missing.EnabledMods.SequenceEqual(new[] { Mods.RandomizerId }), "Missing retired selections recover to Randomizer");
            var disabled = new Settings();
            string disabledFolder = Path.Combine(temp, "disabled");
            Directory.CreateDirectory(disabledFolder);
            File.WriteAllText(Path.Combine(disabledFolder, "old.json"), legacy);
            Mods.ConsolidateRandomizers(disabled, disabledFolder);
            check(disabled.EnabledMods.Count == 0 && Mods.Load(disabledFolder).Single().Manifest?.Id == Mods.RandomizerId,
                "Disabled legacy randomizers remain disabled after consolidation");
        } finally { Directory.Delete(temp, true); }
    }
}
