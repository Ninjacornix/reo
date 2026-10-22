using System.Globalization;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;
public sealed class CheatGroup {
    public string Id { get; init; } = "";
    public string Name { get; init; } = "";
    public string Description { get; set; } = "";
    public string? Builtin { get; init; }
    public List<CheatWrite> Writes { get; } = new();
    public string Error { get; set; } = "";
    public bool Supported => Error.Length == 0 && (Builtin != null || Writes.Count > 0);
}
public record CheatWrite(int Place, uint Address, int Size, ulong Value);
public static class Cheats {
    public static List<CheatGroup> Builtins(string game) =>
        game != "file1"
            ? new()
            : new() {
                  new() { Id = "builtin.file1.health", Builtin = "health", Name = "Full health",
                          Description = "Keeps your living character at maximum health." },
                  new() { Id = "builtin.file1.infection", Builtin = "infection",
                          Name = "No infection",
                          Description = "Keeps your character's virus gauge at zero." },
                  new() { Id = "builtin.file1.ammo", Builtin = "ammo", Name = "Infinite ammunition",
                          Description = "Keeps carried firearms loaded to their normal capacity." }
              };
    public static string Folder(string game) => Path.Combine(Settings.Home, "cheats", game);
    public static bool DataAddress(uint a,
                                   int size) => size > 0 && a >= 0x370000 &&
                                                (ulong)a + (uint)size <= 0x1fd0000 &&
                                                !(a < 0x900000 && (ulong)a + (uint)size > 0x570000);
    public static List<CheatGroup> Parse(string text, string identity) {
        if (text.Length > 1024 * 1024)
            throw new IOException("Cheat file exceeds 1 MB.");
        var groups = new List<CheatGroup>();
        CheatGroup? current = null;
        CheatGroup Group(string name) {
            if (groups.Count >= 512)
                throw new IOException("Cheat file exceeds 512 groups.");
            var g =
                new CheatGroup { Name = name,
                                 Id = Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(
                                     identity + "\n" + name + "\n" + groups.Count))) };
            groups.Add(g);
            return g;
        }
        int lineNumber = 0;
        foreach (string raw in text.Split('\n')) {
            lineNumber++;
            string line = raw.Split("//", 2) [0].Trim();
            if (line.Length == 0 || line.StartsWith('#') || line.StartsWith(';'))
                continue;
            if (line.StartsWith('[') && line.EndsWith(']')) {
                current = Group(line[1.. ^ 1].Replace("Cheats\\", ""));
                continue;
            }
            int eq = line.IndexOf('=');
            if (eq < 0) {
                (current ??= Group("Ungrouped")).Error =
                    $"Line {lineNumber}: unrecognized command.";
                continue;
            }
            string key = line[..eq].Trim().ToLowerInvariant(), value = line[(eq + 1)..].Trim();
            if (key is "gametitle" or "comment" or "author")
                continue;
            if (key == "description") {
                (current ??= Group("Ungrouped")).Description = value;
                continue;
            }
            current ??= Group("Ungrouped");
            try {
                if (key != "patch")
                    throw new FormatException("Unsupported directive: " + key);
                string[] fields = value.Split(',').Select(x => x.Trim()).ToArray();
                if (fields.Length != 5 ||
                    !fields[1].Equals("EE", StringComparison.OrdinalIgnoreCase))
                    throw new FormatException("Only EE data writes are supported.");
                if (!int.TryParse(fields[0], out int place) || place < 0 || place > 3)
                    throw new FormatException("Unsupported patch timing.");
                uint address = uint.Parse(fields[2], NumberStyles.HexNumber);
                ulong data = ulong.Parse(fields[4], NumberStyles.HexNumber);
                int size =
                    fields[3].ToLowerInvariant() switch { "byte" => 1,
                                                          "short" => 2,
                                                          "word" => 4,
                                                          "double" => 8,
                                                          "extended" => 1 << (int)(address >> 28),
                                                          _ => 0 };
                if (fields[3].Equals("extended", StringComparison.OrdinalIgnoreCase)) {
                    if (address >> 28 > 2)
                        throw new FormatException(
                            "Only RAW 0/1/2 direct-write codes are supported; " +
                            "conditional/pointer/encrypted codes need conversion.");
                    address &= 0x0fffffff;
                } else if (address >= 0x20000000 && address < 0x22000000)
                    address -= 0x20000000;
                else if (address >= 0x80000000 && address < 0x82000000)
                    address -= 0x80000000;
                else if (address >= 0xa0000000 && address < 0xa2000000)
                    address -= 0xa0000000;
                if (size == 0 || (size < 8 && data >= (1UL << (size * 8))))
                    throw new FormatException("Unsupported type or value exceeds write size.");
                if (!DataAddress(address, size))
                    throw new FormatException(
                        "Address is outside supported game data. Native instruction patches and " +
                        "overlay-bank writes are unavailable.");
                if (current.Writes.Count >= 4096)
                    throw new FormatException("Too many writes in one group.");
                current.Writes.Add(new(place, address, size, data));
            } catch (Exception error) when (error is FormatException or OverflowException) {
                current.Error = $"Line {lineNumber}: {error.Message}";
            }
        }
        return groups;
    }
    public static List<CheatGroup> Load(string game) {
        var result = Builtins(game);
        string folder = Folder(game);
        if (!Directory.Exists(folder))
            return result;
        foreach (string file in Directory.EnumerateFiles(folder, "*.pnach").OrderBy(x => x)) {
            try {
                if (new FileInfo(file).Length > 1024 * 1024)
                    throw new IOException("Cheat file exceeds 1 MB.");
                result.AddRange(Parse(File.ReadAllText(file), Path.GetFileName(file)));
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
                result.Add(new CheatGroup { Id = "invalid." + Path.GetFileName(file),
                                            Name = Path.GetFileName(file), Error = error.Message });
            }
        }
        return result;
    }
    public static string Export(Settings settings, string logs, List<ModManifest>? mods = null) {
        mods ??= new();
        if ((!settings.CheatsEnabled && mods.Count == 0) || settings.Game.Id != "file1")
            return "";
        var selected = (settings.CheatsEnabled ? settings.EnabledCheats : new List<string>()).ToHashSet(StringComparer.Ordinal);
        var writes = new List<CheatWrite>();
        var builtins = new List<string>();
        foreach (var g in Load(settings.Game.Id).Where(g => selected.Contains(g.Id))) {
            if (!g.Supported)
                throw new IOException("Cannot enable " + g.Name + ": " + g.Error);
            if (g.Builtin != null)
                builtins.Add("builtin " + g.Builtin);
            writes.AddRange(g.Writes);
        }
        Mods.Append(mods, writes, builtins);
        if (writes.Count == 0 && builtins.Count == 0)
            return "";
        if (writes.Count > 4096)
            throw new IOException("Select fewer cheats (4096 write limit).");
        string file = Path.Combine(logs, "cheats.txt");
        File.WriteAllLines(
            file,
            new[] { builtins.Count > 0 ? "REO-CHEATS-2" : "REO-CHEATS-1" }.Concat(builtins).Concat(
                writes.Select(w => $"{w.Place} {w.Address:X8} {w.Size} {w.Value:X16}")),
            Encoding.ASCII);
        return file;
    }
}
public sealed partial class Settings {
    public bool CheatsEnabled { get; set; }
    public List<string> EnabledCheats { get; set; } = new();
}
