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
    }
}
