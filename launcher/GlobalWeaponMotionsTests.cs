using System.IO;

namespace Outbreak.Launcher;

internal static class GlobalWeaponMotionsTests {
    const int Header = 328;
    const uint Missing = uint.MaxValue;
    static uint U(byte[] data, int at) => BitConverter.ToUInt32(data, at);
    static void Put(byte[] data, int at, uint value) => BitConverter.TryWriteBytes(data.AsSpan(at, 4), value);
    static byte[] Clip(byte marker, int length = 32) {
        var clip = Enumerable.Repeat(marker, length).ToArray();
        Put(clip, 0, 0x80000002); Put(clip, 4, 2); Put(clip, 8, (uint)length); return clip;
    }
    static byte[] Bank(IEnumerable<(int Group, int Index, byte[] Clip)> bindings) {
        var entries = bindings.ToArray();
        using var stream = new MemoryStream(); using var writer = new BinaryWriter(stream);
        writer.Write(new byte[Header]);
        var tables = new uint[40][]; var tableOffsets = new uint[40];
        for (int group = 0; group < 40; ++group) {
            int count = (entries.Where(e => e.Group == group).Select(e => e.Index).DefaultIfEmpty(-1).Max() + 5) / 5 * 5;
            tables[group] = Enumerable.Repeat(Missing, count).ToArray();
            tableOffsets[group] = (uint)stream.Position;
            foreach (uint value in tables[group]) writer.Write(value);
        }
        var clips = new Dictionary<byte[], uint>(ReferenceEqualityComparer.Instance);
        foreach (var entry in entries) {
            if (!clips.TryGetValue(entry.Clip, out uint offset)) {
                offset = (uint)stream.Position; clips.Add(entry.Clip, offset); writer.Write(entry.Clip);
            }
            tables[entry.Group][entry.Index] = offset;
        }
        stream.Position = 0; writer.Write(0u); writer.Write(5u);
        for (int group = 0; group < 40; ++group) {
            writer.Write(tables[group].Length); writer.Write(tableOffsets[group]);
        }
        for (int group = 0; group < 40; ++group) {
            stream.Position = tableOffsets[group]; foreach (uint value in tables[group]) writer.Write(value);
        }
        return stream.ToArray();
    }
    static uint Binding(byte[] data, int group, int index) => index >= U(data, 8 + group * 8)
        ? Missing : U(data, (int)U(data, 12 + group * 8) + index * 4);
    static byte[] BoundClip(byte[] data, int group, int index) {
        int offset = checked((int)Binding(data, group, index));
        return data.AsSpan(offset, checked((int)U(data, offset + 8))).ToArray();
    }

    internal static void Run(Action<bool, string> check) {
        var first = Clip(17); var second = Clip(34); var donor = Clip(51); var alternate = Clip(68);
        byte[] original = Bank(new[] { (1, 5, first), (4, 325, second), (4, 326, second) });
        byte[] additions = Bank(new[] { (0, 0, alternate), (1, 6, alternate), (4, 325, alternate),
                                       (4, 330, donor), (4, 331, donor), (24, 325, alternate), (24, 330, donor) });
        byte[] later = Bank(new[] { (4, 330, alternate) });
        var beforeOriginal = original.ToArray(); var beforeDonor = additions.ToArray();
        byte[] merged = GlobalWeaponMotions.Merge(original, new[] { additions, later });
        check(BoundClip(merged, 1, 5).SequenceEqual(first) && BoundClip(merged, 4, 325).SequenceEqual(second),
              "Weapon motion merge preserves existing scenario clips despite conflicting donors");
        check(Binding(merged, 4, 325) == Binding(merged, 4, 326) &&
              Binding(merged, 4, 330) == Binding(merged, 4, 331),
              "Existing and added shared motion offsets retain their alias relationships");
        check(BoundClip(merged, 4, 330).SequenceEqual(donor),
              "Missing weapon motions use stable donor priority");
        check(BoundClip(merged, 24, 325).SequenceEqual(alternate) &&
              BoundClip(merged, 24, 330).SequenceEqual(donor),
              "Female weapon motion groups receive their own source clips");
        check(Binding(merged, 0, 0) == Missing && Binding(merged, 1, 6) == Missing &&
              U(merged, 8) == U(original, 8) && U(merged, 16) == U(original, 16),
              "Nonweapon holes and descriptor counts remain unchanged");
        check(original.SequenceEqual(beforeOriginal) && additions.SequenceEqual(beforeDonor),
              "Preparing weapon motions never modifies imported input bytes");
        check(merged.SequenceEqual(GlobalWeaponMotions.Merge(original, new[] { additions, later })),
              "Weapon motion relocation is deterministic");

        var occupied = Enumerable.Range(0, 188).Select(i => (i / 100, i % 100 * 5, first));
        var large = Bank(occupied);
        var extraWeapons = Bank(Enumerable.Range(0, 31).Select(i => (4, i * 5, donor))
                                         .Concat(new[] { (4, 325, donor), (4, 330, donor) }));
        var limited = GlobalWeaponMotions.Merge(large, new[] { extraWeapons });
        check(Binding(limited, 4, 0) == Missing && Binding(limited, 4, 325) != Missing &&
              Binding(limited, 4, 330) != Missing && BoundClip(limited, 1, 435).SequenceEqual(first),
              "Near-full native tables retain all original motions and fall back to grenade aim/fire only");
        bool Rejects(byte[] bytes, IReadOnlyList<byte[]>? donors = null) {
            try { GlobalWeaponMotions.Merge(bytes, donors ?? Array.Empty<byte[]>()); return false; }
            catch (IOException) { return true; }
        }
        var full = Bank(Enumerable.Range(0, 200).Select(i => (i / 100, i % 100 * 5, first)));
        check(Rejects(full, new[] { additions }), "Native clip-table overflow fails instead of overwriting adjacent memory");
        check(Rejects(new byte[Header - 1]), "Truncated player motion headers are rejected");
        var invalid = original.ToArray(); Put(invalid, 4, 6);
        check(Rejects(invalid), "Unknown player motion formats are rejected");
        invalid = original.ToArray(); Put(invalid, 8, 505);
        check(Rejects(invalid), "Oversized logical motion tables are rejected");
        invalid = original.ToArray(); Put(invalid, 12, (uint)original.Length + 4);
        check(Rejects(invalid), "Motion lookup tables cannot address beyond the file");
        invalid = original.ToArray(); Put(invalid, 12, Header + 1);
        check(Rejects(invalid), "Unaligned motion tables are rejected");
        invalid = original.ToArray(); Put(invalid, (int)U(invalid, 20) + 5 * 4, 4);
        check(Rejects(invalid), "Motion clips cannot alias the container header");
        invalid = original.ToArray(); Put(invalid, (int)Binding(invalid, 1, 5) + 8, uint.MaxValue);
        check(Rejects(invalid), "Clip byte lengths must remain inside the imported file");
        invalid = original.ToArray(); Put(invalid, (int)Binding(invalid, 1, 5), uint.MaxValue);
        check(Rejects(invalid), "Runtime-mutated clip-ID records are not accepted as imported motion data");
        var maximum = Bank(new[] { (0, 0, Clip(1, 3 * 1024 * 1024 - Header - 20)) });
        check(Rejects(maximum, new[] { additions }), "Merged player motions respect the native scratch-buffer bound");
    }
}
