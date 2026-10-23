using System.IO;
using System.Text;

namespace Outbreak.Launcher;

// Build from the user's verified disc import. No item definitions or assets are distributed.
internal static class GlobalItemCatalogue {
    sealed record Entry(byte[] Metadata, byte[] Scale, byte[] Priority,
                        SortedSet<(ushort Other, ushort Result, ushort Action)> Combinations);
    internal static string Prepare(string discRoot, string logs) {
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
                result.Add(name, (origin + offset, (int)size));
            }
            return result;
        }
        var outer = Directory(0);
        var entries = new SortedDictionary<ushort, Entry>();
        var models = new Dictionary<int,byte[]>();
        foreach (string scenario in new[] { "001", "002", "028", "035", "041" }) {
            var nested = Directory(outer["r" + scenario + ".afs"].Offset);
            int number=int.Parse(scenario,System.Globalization.CultureInfo.InvariantCulture);
            var bank=nested[$"OBJS{number:00}.NBD"];
            if(bank.Size>2*1024*1024) throw new IOException("Object model bank is too large.");
            models.Add(number,Read(bank.Offset,bank.Size));
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
            for (int i = 0; i < count; ++i) {
                var row = Slice(metadata + i * 24, 24);
                ushort type = BitConverter.ToUInt16(row, 18);
                if (type >= 600) continue; // Scenario keys never enter the global catalogue.
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
        GlobalItemModels.Prepare(models,logs);
        string path = Path.Combine(logs, "global-items.bin");
        using var output = new BinaryWriter(File.Create(path));
        output.Write("RGIC1\0\0\0"u8); output.Write(entries.Count);
        foreach (var (type, entry) in entries) {
            output.Write(type); output.Write(entry.Metadata); output.Write(entry.Scale); output.Write(entry.Priority);
            output.Write((ushort)entry.Combinations.Count);
            foreach (var (other, result, action) in entry.Combinations) {
                output.Write(other); output.Write(result); output.Write(action);
            }
        }
        return path;
    }
}
