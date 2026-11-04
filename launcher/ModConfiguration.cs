using System.Globalization;
using System.Text.Json.Serialization;

namespace Outbreak.Launcher;

// Launcher preferences belong to the game and mod ID, not the installed package.
// New configuration controls can use this same storage without rewriting JSON mods.
public sealed class ModConfiguration {
    public bool UseCustomSeed { get; set; }
    public uint Seed { get; set; }
    internal static bool TrySeed(string text, out uint seed) =>
        uint.TryParse(text, NumberStyles.None, CultureInfo.InvariantCulture, out seed);
    internal static bool SupportsSeed(ModManifest manifest) =>
        manifest.ItemRandomizer != null || manifest.WeaponShuffle != null || manifest.EnemyRandomizer != null;
}

public sealed partial class Settings {
    public Dictionary<string, Dictionary<string, ModConfiguration>> ModConfigurations { get; set; } = new();
    [JsonIgnore]
    internal IReadOnlyDictionary<string, ModConfiguration> ActiveModConfigurations =>
        ModConfigurations != null && ModConfigurations.TryGetValue(Game.Id, out var entries) && entries != null
            ? entries : new Dictionary<string, ModConfiguration>();
    internal ModConfiguration ConfigurationFor(string id, uint fallback = 0) =>
        ActiveModConfigurations.TryGetValue(id, out var options) && options != null ? options : new() { Seed = fallback };
    internal void SetConfiguration(string id, ModConfiguration options) {
        ModConfigurations ??= new();
        if (!ModConfigurations.TryGetValue(Game.Id, out var entries) || entries == null)
            ModConfigurations[Game.Id] = entries = new();
        entries[id] = options;
    }
}
