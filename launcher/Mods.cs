using System.Globalization;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

public sealed class ModManifest {
    public int Format { get; set; }
    public string Id { get; set; } = "";
    public string Name { get; set; } = "";
    public string Version { get; set; } = "";
    public string Description { get; set; } = "";
    public string ElfSha256 { get; set; } = "";
    public List<string> Effects { get; set; } = new();
    public List<ModPatch> Patches { get; set; } = new();
    public WeaponShuffle? WeaponShuffle { get; set; }
    public ItemRandomizer? ItemRandomizer { get; set; }
    public EnemyRandomizer? EnemyRandomizer { get; set; }
}
public sealed class EnemyRandomizer {
    public uint Seed { get; set; }
    public string Mode { get; set; } = "zombieProfiles";
    public List<EnemyProfile> Pool { get; set; } = new();
    public List<int> SourceBehaviors { get; set; } = new() {0};
}
public sealed class EnemyProfile {
    public int Type { get; set; }
    public int Model { get; set; }
    public int Health { get; set; }
    public int Behavior { get; set; }
    public int Posture { get; set; }
    public int Weight { get; set; } = 1;
}
public sealed class ItemRandomizer {
    public uint Seed { get; set; }
    public string Mode { get; set; } = "shuffle";
    public List<int> ExcludeItemTypes { get; set; } = new();
}
public sealed class WeaponShuffle {
    public uint Seed { get; set; }
}
public sealed class ModPatch {
    public string When { get; set; } = "frame";
    public string Address { get; set; } = "";
    public int Size { get; set; }
    public string Value { get; set; } = "";
}
public sealed record InstalledMod(string File, ModManifest? Manifest, string Error);

public static partial class Mods {
    const int MaxBytes = 1024 * 1024;
    public const string RandomizerId = "example.randomizer";
    static readonly HashSet<string> RetiredSamples = new(StringComparer.Ordinal) {
        "example.outbreak-randomizer", "example.item-randomizer", "example.weapon-shuffle",
        "example.zombie-randomizer", "example.ground-enemy-randomizer", "example.practice-mode"
    };
    static readonly JsonSerializerOptions Json = new() {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        WriteIndented = true
    };
    public static string Folder => Path.Combine(Settings.Home, "mods", "file1");
    public static string FolderFor(string game) {
        _ = DiscImport.ExpectedElf(game);
        return Path.Combine(Settings.Home, "mods", game);
    }
    public static bool ConsolidateRandomizers(Settings settings, string? folder = null) {
        folder ??= FolderFor(settings.Game.Id);
        var installed = Load(folder, settings.Game.Id);
        var retired = installed.Where(m => m.Manifest != null && RetiredSamples.Contains(m.Manifest.Id)).ToList();
        if (retired.Count == 0 && !settings.ActiveMods.Any(RetiredSamples.Contains)) return false;

        bool enabled = settings.ActiveMods.Any(id => RetiredSamples.Contains(id) && id != "example.practice-mode");
        if (!installed.Any(m => m.Manifest?.Id == RandomizerId)) {
            string sample = settings.Game.Id == "file2" ? "randomizer-file2.json" : "randomizer.json";
            var randomizer = Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", sample)));
            // Prefer the combined package, then enabled individual packages. Guns are
            // already part of the item pool, so a second weapon shuffle is unnecessary.
            var previous = retired.Select(m => m.Manifest!).OrderByDescending(m => m.Id == "example.outbreak-randomizer")
                .ThenByDescending(m => settings.ActiveMods.Contains(m.Id)).ToList();
            randomizer.ItemRandomizer = previous.FirstOrDefault(m => m.ItemRandomizer != null)?.ItemRandomizer
                ?? randomizer.ItemRandomizer;
            if (!previous.Any(m => m.ItemRandomizer != null) && previous.FirstOrDefault(m => m.WeaponShuffle != null)?.WeaponShuffle is {} guns)
                randomizer.ItemRandomizer!.Seed = guns.Seed;
            randomizer.EnemyRandomizer = previous.FirstOrDefault(m => m.EnemyRandomizer?.Mode == "enemyTypes")?.EnemyRandomizer
                ?? randomizer.EnemyRandomizer;
            Directory.CreateDirectory(folder);
            string target = Path.Combine(folder, RandomizerId + ".json");
            File.WriteAllText(target + ".tmp", JsonSerializer.Serialize(randomizer, Json));
            File.Move(target + ".tmp", target);
        }
        // Keep originals outside the top-level mod list so edited samples remain recoverable.
        foreach (var mod in retired) {
            string archive = Path.Combine(folder, "retired-samples");
            Directory.CreateDirectory(archive);
            string target = Path.Combine(archive, Path.GetFileName(mod.File));
            if (File.Exists(target)) target += "." + Guid.NewGuid().ToString("N");
            File.Move(mod.File, target);
        }
        var updated = settings.ActiveMods.Where(id => !RetiredSamples.Contains(id)).ToList();
        if (enabled && !updated.Contains(RandomizerId)) updated.Add(RandomizerId);
        if (updated.SequenceEqual(settings.ActiveMods)) return false;
        settings.ActiveMods = updated;
        return true;
    }
    public static ModManifest Parse(string text) {
        if (text.Length > MaxBytes) throw new IOException("Mod exceeds 1 MB.");
        ModManifest m;
        try {
            m = JsonSerializer.Deserialize<ModManifest>(text, Json)
                ?? throw new IOException("Mod manifest is empty.");
        } catch (JsonException e) { throw new IOException("Invalid mod JSON: " + e.Message, e); }
        if (m.Format != 1) throw new IOException("Unsupported mod format; expected 1.");
        if (m.Id == null || !Regex.IsMatch(m.Id, @"\A[a-z0-9][a-z0-9.-]{0,79}\z"))
            throw new IOException("Mod ID must use 1–80 lowercase letters, digits, dots or hyphens.");
        if (string.IsNullOrWhiteSpace(m.Name) || m.Name.Length > 120 ||
            string.IsNullOrWhiteSpace(m.Version) || m.Version.Length > 40 ||
            m.Description == null || m.Description.Length > 4000)
            throw new IOException("Mod needs a name and version; description is limited to 4000 characters.");
        if (!string.Equals(m.ElfSha256, DiscImport.FirstElfSha256, StringComparison.OrdinalIgnoreCase) &&
            !string.Equals(m.ElfSha256, DiscImport.SecondElfSha256, StringComparison.OrdinalIgnoreCase))
            throw new IOException("Mod must target a supported Outbreak File #1 or File #2 ELF SHA-256.");
        if (m.Effects == null || m.Patches == null || m.Effects.Count > 3 || m.Patches.Count > 4096)
            throw new IOException("Invalid mod effects or patches (4096 patch limit).");
        if (m.Effects.Any(e => e is not ("health" or "infection" or "ammo")))
            throw new IOException("Supported effects are health, infection and ammo.");
        if (m.WeaponShuffle != null && m.ItemRandomizer != null)
            throw new IOException("Choose either an item randomizer or a weapon shuffle.");
        if (m.EnemyRandomizer is {} enemy) {
            if(enemy.Mode is not ("zombieProfiles" or "enemyTypes"))
                throw new IOException("Supported enemy randomizer modes are zombieProfiles and enemyTypes.");
            if(enemy.Pool == null || enemy.Pool.Count > 128 || enemy.SourceBehaviors == null ||
               enemy.SourceBehaviors.Count == 0 || enemy.SourceBehaviors.Count > 256 ||
               enemy.SourceBehaviors.Any(b => b < 0 || b > 255) || enemy.SourceBehaviors.Distinct().Count()!=enemy.SourceBehaviors.Count)
                throw new IOException("Invalid enemy pool or source behavior list.");
            if((enemy.Mode == "enemyTypes") != (enemy.Pool.Count > 0))
                throw new IOException("enemyTypes requires a pool; zombieProfiles does not accept one.");
            if(enemy.Pool.Any(p => p == null || p.Type < 0 || p.Type >= 64 || p.Model < 0 || p.Model > 255 ||
                p.Health < 1 || p.Health >= 32767 || p.Behavior < 0 || p.Behavior > 255 || p.Posture < 0 || p.Posture > 255 || p.Weight < 1 || p.Weight > 100) ||
               enemy.Pool.Select(p => (p.Type,p.Model)).Distinct().Count()!=enemy.Pool.Count)
                throw new IOException("Enemy profiles need distinct type/model pairs and valid health, behavior and weight.");
        }
        if (m.ItemRandomizer is { } randomizer &&
            (randomizer.Mode is not ("shuffle" or "global") || randomizer.ExcludeItemTypes == null || randomizer.ExcludeItemTypes.Count > 400 ||
             randomizer.ExcludeItemTypes.Any(t => t < 0 || t >= 400) ||
             randomizer.ExcludeItemTypes.Distinct().Count() != randomizer.ExcludeItemTypes.Count))
            throw new IOException("excludeItemTypes must contain distinct ordinary item IDs from 0 to 399.");
        if (m.Effects.Count == 0 && m.Patches.Count == 0 && m.WeaponShuffle == null && m.ItemRandomizer == null && m.EnemyRandomizer == null)
            throw new IOException("Mod must contain an item/enemy randomizer, weapon shuffle, effect or data patch.");
        foreach (var p in m.Patches) _ = Write(p);
        return m;
    }
    public static CheatWrite Write(ModPatch p) {
        if (p == null || p.When is not ("boot" or "frame") || p.Size is not (1 or 2 or 4 or 8) ||
            !uint.TryParse(p.Address, NumberStyles.AllowHexSpecifier, CultureInfo.InvariantCulture, out uint address) ||
            !ulong.TryParse(p.Value, NumberStyles.AllowHexSpecifier, CultureInfo.InvariantCulture, out ulong value) ||
            !Cheats.DataAddress(address, p.Size) || (p.Size < 8 && value >= (1UL << (p.Size * 8))))
            throw new IOException("Invalid mod patch: use boot/frame, a supported EE data address, size 1/2/4/8 and a fitting hexadecimal value. Code and overlay patches are unsupported.");
        return new(p.When == "boot" ? 0 : 1, address, p.Size, value);
    }
    public static List<InstalledMod> Load(string? folder = null, string game = "file1") {
        folder ??= FolderFor(game);
        var result = new List<InstalledMod>();
        if (!Directory.Exists(folder)) return result;
        foreach (var path in Directory.EnumerateFiles(folder, "*.json").OrderBy(x => x, StringComparer.Ordinal)) {
            try {
                if (new FileInfo(path).Length > MaxBytes) throw new IOException("Mod exceeds 1 MB.");
                var manifest = Parse(File.ReadAllText(path));
                if (!manifest.ElfSha256.Equals(DiscImport.ExpectedElf(game), StringComparison.OrdinalIgnoreCase))
                    throw new IOException("This mod targets a different game. Import a package for the selected game.");
                result.Add(new(path, manifest, ""));
            } catch (Exception e) when (e is IOException or UnauthorizedAccessException) {
                result.Add(new(path, null, e.Message));
            }
        }
        var duplicates = result.Where(x => x.Manifest != null).GroupBy(x => x.Manifest!.Id)
            .Where(g => g.Count() > 1).Select(g => g.Key).ToHashSet();
        return result.Select(x => x.Manifest != null && duplicates.Contains(x.Manifest.Id)
            ? x with { Error = "Duplicate mod ID. Keep only one package with this ID." } : x).ToList();
    }
    public static void Import(string source, string? folder = null, string game = "file1") {
        if (new FileInfo(source).Length > MaxBytes) throw new IOException("Mod exceeds 1 MB.");
        string text = File.ReadAllText(source);
        var m = Parse(text);
        if (!m.ElfSha256.Equals(DiscImport.ExpectedElf(game), StringComparison.OrdinalIgnoreCase))
            throw new IOException("This mod targets a different game. Select the matching game before importing.");
        folder ??= FolderFor(game);
        Directory.CreateDirectory(folder);
        if (Load(folder, game).Any(x => x.Manifest?.Id == m.Id))
            throw new IOException("This mod ID is already installed. Delete the installed package before importing an update.");
        string target = Path.Combine(folder, m.Id + ".json");
        using var stream = new FileStream(target, FileMode.CreateNew, FileAccess.Write);
        using var writer = new StreamWriter(stream);
        writer.Write(text);
    }
    public static List<ModManifest> Selected(Settings settings, string? folder = null) {
        // Guests adopt the host's immutable session configuration in GameSession.
        // Their own mod preferences remain saved for subsequent solo/host games.
        if (settings.ResolvedCoopMode == "join") return new();
        if (settings.ActiveMods.Count == 0) return new();
        var installed = Load(folder, settings.Game.Id);
        var selected = new List<ModManifest>();
        foreach (string id in settings.ActiveMods.Distinct().OrderBy(x => x, StringComparer.Ordinal)) {
            var matches = installed.Where(x => x.Manifest?.Id == id).ToList();
            if (matches.Count != 1 || matches[0].Error.Length != 0)
                throw new IOException("Enabled mod is missing, invalid or duplicated: " + id + ". Reload Mods and disable it or repair its JSON file.");
            selected.Add(matches[0].Manifest!);
        }
        if (selected.Count(m => m.WeaponShuffle != null || m.ItemRandomizer != null) > 1)
            throw new IOException("Enable only one pickup randomizer mod at a time.");
        if (selected.Count(m => m.EnemyRandomizer != null) > 1)
            throw new IOException("Enable only one enemy randomizer mod at a time.");
        if (settings.ResolvedCoopMode == "host" && selected.Any(m => m.Effects.Count != 0 || m.Patches.Count != 0))
            throw new IOException("Co-op supports host-controlled randomizers only. Disable effects and data-patch mods.");
        return selected;
    }
    public static void Append(List<ModManifest> mods, List<CheatWrite> writes, List<string> builtins) {
        var occupied = new Dictionary<uint, string>();
        foreach (var w in writes)
            for (uint i = 0; i < w.Size; i++) occupied[w.Address + i] = "selected cheats";
        foreach (var m in mods) {
            foreach (var p in m.Patches) {
                var w = Write(p);
                for (uint i = 0; i < w.Size; i++) {
                    if (occupied.TryGetValue(w.Address + i, out var owner))
                        throw new IOException($"Mod {m.Name} overlaps {owner} at {w.Address + i:X8}. Disable one of the conflicting patches.");
                    occupied[w.Address + i] = m.Name;
                }
                writes.Add(w);
            }
            builtins.AddRange(m.Effects.Distinct().Select(e => "builtin " + e));
        }
        if (writes.Count > 4096) throw new IOException("Mods and cheats exceed the combined 4096 patch limit.");
    }
    public static void SaveSession(List<ModManifest> mods, string logs) =>
        File.WriteAllText(Path.Combine(logs, "mods.json"), JsonSerializer.Serialize(mods, Json));
}
public sealed partial class Settings {
    public List<string> EnabledMods { get; set; } = new();
    public List<string> File2EnabledMods { get; set; } = new();
    [JsonIgnore]
    public List<string> ActiveMods {
        get => Game.Id == "file2" ? File2EnabledMods ??= new() : EnabledMods ??= new();
        set { if (Game.Id == "file2") File2EnabledMods = value; else EnabledMods = value; }
    }
}
