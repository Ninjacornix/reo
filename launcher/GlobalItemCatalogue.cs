using System.IO;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Build from the user's verified disc import. No item definitions or assets are distributed.
internal static class GlobalItemCatalogue {
    sealed record Entry(byte[] Metadata, byte[] Scale, byte[] Priority,
                        SortedSet<(ushort Other, ushort Result, ushort Action)> Combinations);
    internal static string Prepare(string discRoot, string logs, string game = "file1") {
        _ = DiscImport.ExpectedElf(game);
        using var archive = File.OpenRead(Path.Combine(discRoot, "NETBIO00.DAT"));
        byte[] Read(long offset, int size) {
            if (offset < 0 || size < 0 || offset > archive.Length - size)
                throw new IOException("Item catalogue archive range is invalid.");
            archive.Position = offset;
            var bytes = new byte[size]; archive.ReadExactly(bytes); return bytes;
        }
        Dictionary<string, (long Offset, int Size)> Directory(long origin) {
            var header = Read(origin, 8);
            if (!header.AsSpan(0, 4).SequenceEqual("AFS\0"u8))
                throw new IOException("Item catalogue archive is not AFS.");
            int count = BitConverter.ToInt32(header, 4);
            if (count is < 1 or > 65536) throw new IOException("Invalid item archive count.");
            var table = Read(origin + 8, checked(count * 8 + 8));
            uint names = BitConverter.ToUInt32(table, count * 8), namesSize = BitConverter.ToUInt32(table, count * 8 + 4);
            if (namesSize < count * 48) throw new IOException("Item archive names are missing.");
            var result = new Dictionary<string, (long, int)>(StringComparer.OrdinalIgnoreCase);
            for (int i = 0; i < count; ++i) {
                var name = Encoding.ASCII.GetString(Read(origin + names + i * 48L, 32)).TrimEnd('\0', ' ');
                uint offset = BitConverter.ToUInt32(table, i * 8), size = BitConverter.ToUInt32(table, i * 8 + 4);
                if (origin + offset > archive.Length - size || size > int.MaxValue)
                    throw new IOException("Invalid item archive member.");
                if (!result.TryAdd(name, (origin + offset, (int)size)) &&
                    (name.StartsWith("objS", StringComparison.OrdinalIgnoreCase) ||
                     name.StartsWith("item", StringComparison.OrdinalIgnoreCase) || name.EndsWith(".afs", StringComparison.OrdinalIgnoreCase)))
                    throw new IOException("Ambiguous item archive member.");
            }
            return result;
        }
        var outer = Directory(0);
        var entries = new SortedDictionary<ushort, Entry>();
        var models = new Dictionary<int,byte[]>();
        var materials = new Dictionary<int,byte[]>();
        var nativeRows = new Dictionary<int, List<byte[]>>();
        var rom = game == "file2" ? Directory(outer["romdata_usa.afs"].Offset) : null;
        string[] scenarios = game == "file2" ? new[] { "006", "010", "015", "026", "040" }
                                             : new[] { "001", "002", "028", "035", "041" };
        string[] modelScenarios = game == "file2"
            ? scenarios.Concat(new[] { "020", "021", "022", "023", "027", "029", "030" }).ToArray()
            : scenarios;
        foreach (string scenario in modelScenarios) {
            var nested = Directory(outer["r" + scenario + ".afs"].Offset);
            int number=int.Parse(scenario,System.Globalization.CultureInfo.InvariantCulture);
            var bank=nested[$"OBJS{number:00}.NBD"];
            if(bank.Size>2*1024*1024) throw new IOException("Object model bank is too large.");
            models.Add(number,Read(bank.Offset,bank.Size));
            if (rom != null) {
                var material = rom[$"objS{number:00}.mat"];
                if (material.Size > 65536) throw new IOException("Object material table is too large.");
                materials.Add(number,Read(material.Offset,material.Size));
            }
            var member = nested["item" + scenario + ".dat"];
            if (member.Size > 1024 * 1024) throw new IOException("Item definitions are too large.");
            byte[] data = Read(member.Offset, member.Size);
            int U32(int at) {
                if (at < 0 || at > data.Length - 4) throw new IOException("Invalid item definition offset.");
                uint value = BitConverter.ToUInt32(data, at);
                if (value > int.MaxValue) throw new IOException("Invalid item definition value.");
                return (int)value;
            }
            byte[] Slice(int at, int size) {
                if (at < 0 || size < 0 || at > data.Length - size) throw new IOException("Incomplete item definitions.");
                return data.AsSpan(at, size).ToArray();
            }
            int section = U32(0), priorities = U32(16), count = U32(section + 4),
                metadata = checked(section + U32(section + 16)), scales = checked(section + U32(section + 20)),
                combinations = checked(section + U32(section + 28));
            if (U32(section) != 3 || count is < 1 or > 128 || U32(priorities) != count)
                throw new IOException("Unsupported item definitions.");
            var original = new List<byte[]>(); nativeRows.Add(number, original);
            for (int i = 0; i < count; ++i) {
                var row = Slice(metadata + i * 24, 24);
                original.Add(row);
                if (!scenarios.Contains(scenario)) continue;
                ushort type = BitConverter.ToUInt16(row, 18);
                if (type >= 600) continue; // Scenario keys never enter the global catalogue.
                // Personal supplies are fixed starting equipment. Existing scenario
                // definitions remain native; only personal firearms join the gun pool.
                if (game == "file2" && type >= 400 && type is not (400 or 401)) continue;
                if (game == "file2" && (type == 312 ||
                    (type < 200 && (BitConverter.ToUInt32(row, 0) & 1) == 0))) continue;
                if (!entries.TryGetValue(type, out var entry)) {
                    entry = new(row, Slice(scales + i * 4, 4), Slice(priorities + 4 + i * 8, 8), new());
                    entries.Add(type, entry);
                }
                int start = BitConverter.ToUInt16(row, 4);
                if (start == 65535) continue;
                for (int j = 0; j < row[6]; ++j) {
                    var triple = Slice(combinations + (start + j * 3) * 2, 6);
                    entry.Combinations.Add((BitConverter.ToUInt16(triple, 0), BitConverter.ToUInt16(triple, 2), BitConverter.ToUInt16(triple, 4)));
                }
            }
        }
        if (entries.Count is < 1 or > 128) throw new IOException("Global item catalogue exceeds native capacity.");
        if (game == "file2") PrepareFile2(entries, nativeRows, models, materials, logs);
        else GlobalItemModels.Prepare(models, logs);
        GlobalWeaponMotions.Prepare(discRoot, logs, game);
        string path = Path.Combine(logs, "global-items.bin");
        WriteCatalogue(path, entries);
        return path;
    }
    static bool Candidate(byte[] metadata) {
        ushort type = BitConverter.ToUInt16(metadata, 18); uint flags = BitConverter.ToUInt32(metadata, 0);
        if (type >= 600 || type is 312 or 450 or 402 or 404 || (flags & 0x08000000) != 0 ||
            BitConverter.ToUInt16(metadata, 8) == 0) return false;
        bool weapon = (flags & 1) != 0 && (flags & 4) == 0;
        return ((type is >= 200 and < 300) || weapon || (flags & 4) != 0 || type is >= 300 and < 500) &&
               ((flags & 0x40) == 0 || weapon);
    }
    static void PrepareFile2(SortedDictionary<ushort, Entry> entries, Dictionary<int, List<byte[]>> scenarios,
                             Dictionary<int, byte[]> models, Dictionary<int, byte[]> materials, string logs) {
        var banks = new GlobalItemModels.PreparedBanks(models,materials);
        var available = banks.Types;
        string folder = Path.Combine(logs, "global-models"); System.IO.Directory.CreateDirectory(folder);
        var receipts = new List<object>();
        foreach (var (scenario, rows) in scenarios) {
            var existing = rows.Select(r => BitConverter.ToUInt16(r, 18)).ToHashSet();
            var modelTypes = rows.Where(Candidate).Select(r => BitConverter.ToUInt16(r, 18)).ToHashSet();
            var used = new bool[480];
            foreach (var row in rows) {
                int start = BitConverter.ToUInt16(row, 4), size = row[6] * 3;
                if (start == 65535 || size == 0) continue;
                if (start + size > used.Length) throw new IOException("Native item combinations exceed their buffer.");
                Array.Fill(used, true, start, size);
            }
            var selected = new SortedDictionary<ushort, Entry>();
            var omitted = new List<ushort>();
            foreach (var (type, entry) in entries) {
                if (existing.Contains(type) || !Candidate(entry.Metadata)) continue;
                int size = entry.Combinations.Count * 3, start = 0;
                for (; start + size <= used.Length; start += 3)
                    if (!used.AsSpan(start, size).Contains(true)) break;
                var prospective = modelTypes.Append(type).ToHashSet();
                if (rows.Count + selected.Count >= 128 || start + size > used.Length ||
                    !available.Contains(type) || banks.RootCount(scenario, prospective) > 96 ||
                    banks.MaterialCount(scenario,prospective)>96) {
                    omitted.Add(type); continue;
                }
                selected.Add(type, entry); modelTypes.Add(type);
                Array.Fill(used, true, start, size);
            }
            byte[] bank = banks.Build(scenario, modelTypes);
            File.WriteAllBytes(Path.Combine(folder, $"OBJS{scenario:00}.NBD"), bank);
            byte[] material = banks.BuildMaterials(scenario,modelTypes,bank);
            File.WriteAllBytes(Path.Combine(folder,$"OBJS{scenario:00}.MAT"),material);
            File.WriteAllBytes(Path.Combine(logs,$"global-items-{scenario:000}.floor"),banks.Availability(material));
            WriteCatalogue(Path.Combine(logs, $"global-items-{scenario:000}.bin"), selected);
            receipts.Add(new { scenario, nativeDefinitions = rows.Count, addedTypes = selected.Keys,
                omittedTypes = omitted, metadataCount = rows.Count + selected.Count,
                reservedCombinationWords = used.Count(v => v), modelRoots = banks.RootCount(scenario, modelTypes),
                materialEntries = banks.MaterialCount(scenario,modelTypes), modelBytes = bank.Length });
        }
        File.WriteAllText(Path.Combine(logs, "global-items-file2.json"), JsonSerializer.Serialize(receipts,
            new JsonSerializerOptions { WriteIndented = true }));
    }
    static void WriteCatalogue(string path, SortedDictionary<ushort, Entry> entries) {
        using var output = new BinaryWriter(File.Create(path));
        output.Write("RGIC1\0\0\0"u8); output.Write(entries.Count);
        foreach (var (type, entry) in entries) {
            output.Write(type); output.Write(entry.Metadata); output.Write(entry.Scale); output.Write(entry.Priority);
            output.Write((ushort)entry.Combinations.Count);
            foreach (var (other, result, action) in entry.Combinations) {
                output.Write(other); output.Write(result); output.Write(action);
            }
        }
    }
}
