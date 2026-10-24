using System.Buffers.Binary;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

// Roll once per solo/host launch, before the host publishes its immutable
// session. Work on copies so editable pools and installed manifests stay intact.
internal sealed class RandomizerSeeds {
    static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
    uint? previous;

    internal List<ModManifest> ForLaunch(List<ModManifest> selected, string mode,
                                          Func<uint>? next = null) {
        if (mode == "join" || !selected.Any(m => Seeds(m).Any())) return selected;
        var copies = selected.Select(m => Mods.Parse(JsonSerializer.Serialize(m, Json))).ToList();
        var excluded = selected.SelectMany(Seeds).ToHashSet();
        if (previous is uint last) excluded.Add(last);
        uint seed;
        do { seed = (next ?? Draw)(); } while (excluded.Contains(seed));
        foreach (var mod in copies) {
            if (mod.ItemRandomizer != null) mod.ItemRandomizer.Seed = seed;
            if (mod.WeaponShuffle != null) mod.WeaponShuffle.Seed = seed;
            if (mod.EnemyRandomizer != null) mod.EnemyRandomizer.Seed = seed;
        }
        previous = seed;
        return copies;
    }
    static uint Draw() {
        Span<byte> bytes = stackalloc byte[4];
        RandomNumberGenerator.Fill(bytes);
        return BinaryPrimitives.ReadUInt32LittleEndian(bytes);
    }
    static IEnumerable<uint> Seeds(ModManifest mod) {
        if (mod.ItemRandomizer != null) yield return mod.ItemRandomizer.Seed;
        if (mod.WeaponShuffle != null) yield return mod.WeaponShuffle.Seed;
        if (mod.EnemyRandomizer != null) yield return mod.EnemyRandomizer.Seed;
    }
    internal static string? Describe(List<ModManifest> selected) {
        var seeds = selected.SelectMany(Seeds).Distinct().ToArray();
        if (seeds.Length == 0) return null;
        if (seeds.Length == 1) return $"Randomizer seed: {seeds[0]}";
        // Older hosts may publish separate item and enemy seeds.
        var parts = new List<string>();
        foreach (var mod in selected) {
            if (mod.ItemRandomizer != null) parts.Add($"Items: {mod.ItemRandomizer.Seed}");
            if (mod.WeaponShuffle != null) parts.Add($"Weapons: {mod.WeaponShuffle.Seed}");
            if (mod.EnemyRandomizer != null) parts.Add($"Enemies: {mod.EnemyRandomizer.Seed}");
        }
        return string.Join(" · ", parts);
    }
}
