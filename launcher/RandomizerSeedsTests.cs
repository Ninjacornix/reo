using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class RandomizerSeedsTests {
    internal static void Run(Action<bool, string> check) {
        var source = Mods.Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory,
                                      "examples", "mods", "randomizer.json")));
        source.ItemRandomizer!.Seed = 10; source.EnemyRandomizer!.Seed = 20;
        string original = JsonSerializer.Serialize(source);
        var seeds = new RandomizerSeeds();
        var draws = new Queue<uint>(new[] { 10u, 20u, uint.MaxValue });
        var first = seeds.ForLaunch(new() { source }, "offline", draws.Dequeue).Single();
        check(draws.Count == 0 && first.ItemRandomizer!.Seed == uint.MaxValue &&
              first.EnemyRandomizer!.Seed == uint.MaxValue,
              "Launch rolls a fresh full-range seed instead of either saved seed");
        check(JsonSerializer.Serialize(source) == original &&
              !ReferenceEquals(source.EnemyRandomizer!.Pool, first.EnemyRandomizer!.Pool) &&
              first.EnemyRandomizer.Pool.Count == source.EnemyRandomizer.Pool.Count,
              "Rolling preserves installed settings and the complete editable enemy pool");
        draws = new Queue<uint>(new[] { uint.MaxValue, 356353u });
        var second = seeds.ForLaunch(new() { source }, "host", draws.Dequeue).Single();
        check(draws.Count == 0 && second.ItemRandomizer!.Seed == 356353 &&
              second.EnemyRandomizer!.Seed == 356353,
              "A repeated last-launch seed is rejected; arbitrary seed356353 is supported");
        var third = seeds.ForLaunch(new() { source }, "offline", () => 0).Single();
        check(third.ItemRandomizer!.Seed == 0 && third.EnemyRandomizer!.Seed == 0,
              "Zero is also a valid randomly generated 32-bit seed");
        byte[] published = RandomizerSession.Create("reo01", new() { second });
        var config = RandomizerSession.Parse(published);
        check(config.Items!.Seed == 356353 && config.Enemies!.Seed == 356353,
              "Host publishes the actual new launch seed for all randomizers");
        var guests = seeds.ForLaunch(RandomizerSession.ModsFor(config), "join",
                                   () => throw new InvalidOperationException("Client tried to roll"));
        check(guests.Single().ItemRandomizer!.Seed == 356353 &&
              guests.Single().EnemyRandomizer!.Seed == 356353,
              "Joining adopts the host's seed without generating a local one");
        check(seeds.ForLaunch(new(), "offline", () => throw new InvalidOperationException()).Count == 0,
              "Disabled randomizers do not consume or generate a seed");
        var weapon = new ModManifest { Format = 1, Id = "fixture.weapon-seed", Name = "Fixture",
            Version = "1", ElfSha256 = DiscImport.FirstElfSha256, WeaponShuffle = new() { Seed = 77 } };
        check(seeds.ForLaunch(new() { weapon }, "offline", () => 123).Single().WeaponShuffle!.Seed == 123 &&
              weapon.WeaponShuffle.Seed == 77,
              "Legacy weapon shuffle also receives a fresh launch seed without editing its file");
        check(RandomizerSeeds.Describe(new() { second }) == "Randomizer seed: 356353" &&
              RandomizerSeeds.Describe(new()) == null,
              "Launcher reports the active seed only when a randomizer is enabled");
        check(JsonSerializer.Serialize(source) == original &&
              RandomizerSession.Parse(published).Enemies!.Seed == 356353,
              "Later launches cannot mutate a running host's published configuration");
        var settings = new Settings { SelectedGame = "file1" };
        settings.SetConfiguration(source.Id, new() { UseCustomSeed = true, Seed = 356353 });
        var configured = seeds.ForLaunch(new() { source }, "offline",
            () => throw new InvalidOperationException("Custom seed tried to roll"), settings.ActiveModConfigurations).Single();
        check(configured.ItemRandomizer!.Seed == 356353 && configured.EnemyRandomizer!.Seed == 356353 && JsonSerializer.Serialize(source) == original,
              "Custom seed applies to every randomizer in a copied mod and never rerolls or edits its package");
        foreach (uint value in new[] { 0u, uint.MaxValue }) {
            settings.SetConfiguration(source.Id, new() { UseCustomSeed = true, Seed = value });
            configured = seeds.ForLaunch(new() { source }, "host", () => throw new InvalidOperationException(), settings.ActiveModConfigurations).Single();
            var shared = RandomizerSession.Parse(RandomizerSession.Create("reo01", new() { configured }));
            check(shared.Items!.Seed == value && shared.Enemies!.Seed == value,
                  "Host publishes the full-range custom seed unchanged for items and enemies");
            var joined = seeds.ForLaunch(RandomizerSession.ModsFor(shared), "join", () => throw new InvalidOperationException(), settings.ActiveModConfigurations);
            check(joined.Single().ItemRandomizer!.Seed == value && joined.Single().EnemyRandomizer!.Seed == value,
                  "Joining never applies a local custom seed over the host snapshot");
        }
        settings.SelectedGame = "file2";
        check(!settings.ConfigurationFor(source.Id).UseCustomSeed, "File #2 starts with independent automatic seed preferences for the same mod ID");
        settings.SetConfiguration(source.Id, new() { UseCustomSeed = true, Seed = 42 });
        settings.SelectedGame = "file1";
        check(settings.ConfigurationFor(source.Id).UseCustomSeed && settings.ConfigurationFor(source.Id).Seed == uint.MaxValue,
              "Switching games preserves each game's own custom seed");
        var restored = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
        check(restored.ConfigurationFor(source.Id).Seed == uint.MaxValue && restored.ConfigurationFor(source.Id).UseCustomSeed,
              "Per-mod custom seed mode and value survive settings persistence");
        restored.SelectedGame = "file2";
        check(restored.ConfigurationFor(source.Id).Seed == 42, "Persisted File #2 configuration remains separate");
        foreach (string value in new[] { "0", "356353", "4294967295" })
            check(ModConfiguration.TrySeed(value, out _), "Valid unsigned decimal custom seed is accepted");
        foreach (string value in new[] { "", "-1", "+1", "4294967296", "12.5", "abc", " 42", "42 ", "0x42" })
            check(!ModConfiguration.TrySeed(value, out _), "Invalid or overflowing custom seed is rejected");
        settings.SetConfiguration(source.Id, new() { UseCustomSeed = false, Seed = 356353 });
        var rolled = seeds.ForLaunch(new() { source }, "offline", () => 12345, settings.ActiveModConfigurations).Single();
        check(rolled.ItemRandomizer!.Seed == 12345 && rolled.EnemyRandomizer!.Seed == 12345 && settings.ConfigurationFor(source.Id).Seed == 356353,
              "Automatic mode rolls fresh while remembering the previous custom value");
        settings.SetConfiguration(source.Id, new() { UseCustomSeed = true, Seed = 7 });
        var mixed = seeds.ForLaunch(new() { source, weapon }, "offline", () => 8, settings.ActiveModConfigurations);
        check(mixed[0].ItemRandomizer!.Seed == 7 && mixed[0].EnemyRandomizer!.Seed == 7 && mixed[1].WeaponShuffle!.Seed == 8,
              "A custom-configured mod and an automatic mod resolve their own launch preferences");
    }
}
