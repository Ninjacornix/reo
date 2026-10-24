using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Original compressed motion clips are relocatable as complete records. Their
// container table offsets are relative to the file; native registration builds
// the final clip IDs and five-channel logical-motion lookup tables.
internal static class GlobalWeaponMotions {
    const int Groups = 40, Header = 8 + Groups * 8, Maximum = 3 * 1024 * 1024;
    const uint Missing = uint.MaxValue;
    sealed record Bank(byte[] Data, uint[][] Tables, Dictionary<uint, byte[]> Clips);

    static uint U(byte[] data, int offset) {
        if (offset < 0 || offset > data.Length - 4) throw new IOException("Incomplete player motions.");
        return BitConverter.ToUInt32(data, offset);
    }

    static Bank Parse(byte[] data) {
        if (data.Length < Header || data.Length > Maximum || U(data, 0) != 0 || U(data, 4) != 5)
            throw new IOException("Unsupported player motion bank.");
        var tables = new uint[Groups][];
        var clips = new Dictionary<uint, byte[]>();
        for (int group = 0; group < Groups; ++group) {
            uint count = U(data, 8 + group * 8), offset = U(data, 12 + group * 8);
            if (count > 500 || count % 5 != 0 || (offset & 3) != 0 || offset < Header || offset > data.Length ||
                count * 4 > data.Length - offset)
                throw new IOException("Invalid player motion table.");
            var entries = new uint[count];
            for (int i = 0; i < entries.Length; ++i) {
                uint clip = U(data, checked((int)offset + i * 4));
                entries[i] = clip;
                if (clip == Missing || clips.ContainsKey(clip)) continue;
                if ((clip & 3) != 0 || clip < Header || clip > data.Length - 12)
                    throw new IOException("Invalid player motion clip offset.");
                uint kind = U(data, (int)clip), size = U(data, (int)clip + 8);
                if ((kind != 0x80000001 && kind != 0x80000002) || size < 12 ||
                    size > data.Length - clip)
                    throw new IOException("Invalid compressed player motion clip.");
                clips.Add(clip, data.AsSpan((int)clip, (int)size).ToArray());
            }
            tables[group] = entries;
        }
        return new(data, tables, clips);
    }

    // Preserve every original binding. Only fill the 400..499 weapon motions
    // (group 4 in each sex's 20-group half); other logical groups stay native.
    internal static byte[] Merge(byte[] original, IReadOnlyList<byte[]> additions, bool grenadeOnly = false) {
        var basis = Parse(original);
        var donors = additions.Select(Parse).ToArray();
        using var stream = new MemoryStream();
        using var writer = new BinaryWriter(stream);
        writer.Write(new byte[Header]);
        var relocated = new Dictionary<string, (uint Offset, byte[] Clip)>();
        var selected = new byte[]?[Groups][];
        var offsets = new uint[Groups][];
        var tableOffsets = new uint[Groups];
        for (int group = 0; group < Groups; ++group) {
            bool weapons = group % 20 == 4;
            int count = basis.Tables[group].Length;
            if (weapons)
                count = Math.Max(count, donors.Select(d => d.Tables[group].Length).DefaultIfEmpty(0).Max());
            selected[group] = new byte[]?[count];
            offsets[group] = new uint[count];
            Array.Fill(offsets[group], Missing);
            tableOffsets[group] = checked((uint)stream.Position);
            for (int index = 0; index < count; ++index) {
                byte[]? clip = index < basis.Tables[group].Length && basis.Tables[group][index] != Missing
                                   ? basis.Clips[basis.Tables[group][index]] : null;
                if (clip == null && weapons && (!grenadeOnly || index is >= 325 and < 350))
                    foreach (var donor in donors) {
                        if (index >= donor.Tables[group].Length || donor.Tables[group][index] == Missing) continue;
                        clip = donor.Clips[donor.Tables[group][index]]; break;
                    }
                selected[group][index] = clip;
                writer.Write(Missing);
            }
        }
        for (int sex = 0; sex < 2; ++sex) {
            int logical = 0;
            for (int group = sex * 20; group < (sex + 1) * 20; ++group)
                for (int i = 0; i < selected[group].Length; i += 5)
                    if (selected[group].Skip(i).Take(5).Any(c => c != null)) ++logical;
            if (logical > 200) {
                // Room 75 already uses 188 logical slots. Preserve them and add
                // only grenade aim/fire/reload motions when the full 400s pool
                // would exceed the native 200-slot scenario allocation.
                if (!grenadeOnly) return Merge(original, additions, grenadeOnly: true);
                throw new IOException("Player weapon motions exceed the native scenario clip table.");
            }
        }
        for (int group = 0; group < Groups; ++group)
            for (int index = 0; index < selected[group].Length; ++index) {
                var clip = selected[group][index];
                if (clip == null) continue;
                string hash = Convert.ToHexString(SHA256.HashData(clip));
                if (relocated.TryGetValue(hash, out var previous)) {
                    if (!previous.Clip.AsSpan().SequenceEqual(clip)) throw new IOException("Player motion hash collision.");
                    offsets[group][index] = previous.Offset;
                } else {
                    while (stream.Position % 4 != 0) writer.Write((byte)0);
                    uint at = checked((uint)stream.Position);
                    if (at > Maximum - clip.Length) throw new IOException("Merged player motions exceed native scratch space.");
                    writer.Write(clip); relocated.Add(hash, (at, clip)); offsets[group][index] = at;
                }
            }
        stream.Position = 0; writer.Write(0u); writer.Write(5u);
        for (int group = 0; group < Groups; ++group) {
            writer.Write(offsets[group].Length); writer.Write(tableOffsets[group]);
        }
        for (int group = 0; group < Groups; ++group) {
            stream.Position = tableOffsets[group];
            foreach (uint offset in offsets[group]) writer.Write(offset);
        }
        return stream.ToArray();
    }

    internal static void Prepare(string discRoot, string logs) {
        using var archive = File.OpenRead(Path.Combine(discRoot, "NETBIO00.DAT"));
        byte[] Read(long offset, int count) {
            if (offset < 0 || count < 0 || offset > archive.Length - count)
                throw new IOException("Invalid player motion archive range.");
            var bytes = new byte[count]; archive.Position = offset; archive.ReadExactly(bytes); return bytes;
        }
        Dictionary<string, (long Offset, int Size)> Directory(long origin) {
            var header = Read(origin, 8);
            if (!header.AsSpan(0, 4).SequenceEqual("AFS\0"u8)) throw new IOException("Invalid player motion archive.");
            int count = checked((int)U(header, 4));
            if (count is < 1 or > 65536) throw new IOException("Invalid player motion archive count.");
            var table = Read(origin + 8, checked(count * 8 + 8));
            uint names = U(table, count * 8), namesSize = U(table, count * 8 + 4);
            if (namesSize < count * 48) throw new IOException("Player motion archive names are missing.");
            var result = new Dictionary<string, (long, int)>(StringComparer.Ordinal);
            for (int i = 0; i < count; ++i) {
                string name = Encoding.ASCII.GetString(Read(origin + names + i * 48L, 32)).TrimEnd('\0', ' ');
                uint offset = U(table, i * 8), size = U(table, i * 8 + 4);
                if (size > int.MaxValue || origin + offset > archive.Length - size)
                    throw new IOException("Invalid player motion archive member.");
                // Legacy enemy members can share names; player-motion members
                // used here must be unique, since they are resolved by name.
                if (!result.TryAdd(name, (origin + offset, (int)size)) &&
                    (name == "romdata_usa.afs" || name.StartsWith("pc_", StringComparison.Ordinal)))
                    throw new IOException("Ambiguous player motion archive member.");
            }
            return result;
        }
        var outer = Directory(0);
        var rom = Directory(outer["romdata_usa.afs"].Offset);
        byte[] Member(string name) {
            var item = rom[name];
            if (item.Size > Maximum) throw new IOException("Player motion member is too large.");
            return Read(item.Offset, item.Size);
        }
        var sources = new[] { "pc_000.bin", "pc_001.bin", "pc_002.bin", "pc_028.bin", "pc_035.bin", "pc_041.bin" }
                          .Select(Member).ToArray();
        string folder = Path.Combine(logs, "global-motions"); System.IO.Directory.CreateDirectory(folder);
        foreach (int id in Enumerable.Range(1, 82).Concat(new[] { 777, 994, 995, 996, 997, 998, 999 })) {
            string name = $"pc_{id:000}.bin";
            if (!rom.ContainsKey(name)) continue;
            File.WriteAllBytes(Path.Combine(folder, name.ToUpperInvariant()), Merge(Member(name), sources));
        }
    }
}
