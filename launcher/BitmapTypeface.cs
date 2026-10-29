using System.Buffers.Binary;
using System.IO;
using System.Text;

namespace Outbreak.Launcher;

// Build TrueType outlines from the game's antialiased 20-dot glyphs. WPF retains
// real text, normal controls and accessibility; no fonts are installed globally.
internal static class BitmapTypeface {
    sealed class Be : MemoryStream {
        internal void U16(int v) { WriteByte((byte)(v >> 8)); WriteByte((byte)v); }
        internal void U32(uint v) { U16((int)(v >> 16)); U16((int)v); }
        internal void Pad() { while (Length % 4 != 0) WriteByte(0); }
    }
    static uint Sum(byte[] data) {
        uint sum = 0;
        for (int i = 0; i < data.Length; i += 4) {
            uint word = 0;
            for (int j = 0; j < 4; j++) word = (word << 8) | (i + j < data.Length ? data[i + j] : 0u);
            sum = unchecked(sum + word);
        }
        return sum;
    }
    internal static byte[] Build(byte[,,] atlas, string family) {
        if (atlas.GetLength(0) != 95 || atlas.GetLength(1) != 20 || atlas.GetLength(2) != 20)
            throw new InvalidDataException("Expected 95 twenty-dot font glyphs.");
        const int glyphs = 96;
        var tables = new SortedDictionary<string, byte[]>(StringComparer.Ordinal);
        var glyf = new Be(); var loca = new Be(); var hmtx = new Be();
        int maxPoints = 0, maxContours = 0;
        loca.U32(0); hmtx.U16(384); hmtx.U16(0); // .notdef, provided by WPF fallback
        for (int code = 32; code <= 126; code++) {
            loca.U32((uint)glyf.Length);
            var contours = FontContours.Trace(atlas, code - 32);
            var points = contours.SelectMany(c => c).ToList();
            int width = points.Count == 0 ? 384 : Math.Max(320, points.Max(p => p.X) + 64);
            hmtx.U16(width); hmtx.U16(points.Count == 0 ? 0 : points.Min(p => p.X));
            if (points.Count == 0) continue;
            maxPoints = Math.Max(maxPoints, points.Count); maxContours = Math.Max(maxContours, contours.Count);
            glyf.U16(contours.Count);
            glyf.U16(points.Min(p => p.X)); glyf.U16(points.Min(p => p.Y));
            glyf.U16(points.Max(p => p.X)); glyf.U16(points.Max(p => p.Y));
            int last = -1;
            foreach (var contour in contours) { last += contour.Count; glyf.U16(last); }
            glyf.U16(0);
            foreach (var point in points) glyf.WriteByte(1);
            int previous = 0;
            foreach (var p in points) { glyf.U16(p.X - previous); previous = p.X; }
            previous = 0;
            foreach (var p in points) { glyf.U16(p.Y - previous); previous = p.Y; }
            glyf.Pad();
        }
        loca.U32((uint)glyf.Length);
        tables["glyf"] = glyf.ToArray(); tables["loca"] = loca.ToArray(); tables["hmtx"] = hmtx.ToArray();

        var head = new Be(); head.U32(0x10000); head.U32(0x10000); head.U32(0); head.U32(0x5f0f3cf5);
        head.U16(3); head.U16(1280); head.Write(new byte[16]); // deterministic timestamps
        head.U16(0); head.U16(-128); head.U16(1408); head.U16(1216);
        head.U16(0); head.U16(8); head.U16(2); head.U16(1); head.U16(0);
        tables["head"] = head.ToArray();
        var hhea = new Be(); hhea.U32(0x10000); hhea.U16(1152); hhea.U16(-128); hhea.U16(0);
        hhea.U16(1408); hhea.U16(0); hhea.U16(0); hhea.U16(1408); hhea.U16(1); hhea.U16(0); hhea.U16(0);
        hhea.Write(new byte[10]); hhea.U16(glyphs); tables["hhea"] = hhea.ToArray();
        var maxp = new Be(); maxp.U32(0x10000); maxp.U16(glyphs); maxp.U16(maxPoints); maxp.U16(maxContours);
        maxp.U16(0); maxp.U16(0); maxp.U16(1); maxp.Write(new byte[16]); tables["maxp"] = maxp.ToArray();

        var cmap = new Be(); cmap.U16(0); cmap.U16(1); cmap.U16(3); cmap.U16(1); cmap.U32(12);
        cmap.U16(4); cmap.U16(32); cmap.U16(0); cmap.U16(4); cmap.U16(4); cmap.U16(1); cmap.U16(0);
        cmap.U16(126); cmap.U16(65535); cmap.U16(0); cmap.U16(32); cmap.U16(65535);
        cmap.U16(-31); cmap.U16(1); cmap.U16(0); cmap.U16(0); tables["cmap"] = cmap.ToArray();
        var name = new Be(); var strings = new Be();
        var names = new Dictionary<int, string> { [1] = family, [2] = "Regular", [3] = family + " v1",
            [4] = family, [5] = "Version 1.0", [6] = family.Replace(" ", "") };
        name.U16(0); name.U16(names.Count); name.U16(6 + 12 * names.Count);
        foreach (var item in names) {
            byte[] bytes = Encoding.BigEndianUnicode.GetBytes(item.Value);
            name.U16(3); name.U16(1); name.U16(0x409); name.U16(item.Key); name.U16(bytes.Length);
            name.U16((int)strings.Length); strings.Write(bytes);
        }
        name.Write(strings.ToArray()); tables["name"] = name.ToArray();
        var post = new Be(); post.U32(0x30000); post.U32(0); post.U16(-64); post.U16(32);
        post.Write(new byte[20]); tables["post"] = post.ToArray();
        var os2 = new Be(); os2.U16(0); os2.U16(480); os2.U16(400); os2.U16(5); os2.U16(0);
        foreach (int v in new[] { 650, 600, 0, 75, 650, 600, 0, 350, 50, 300, 0 }) os2.U16(v);
        os2.Write(new byte[10]); os2.U32(1); os2.Write(new byte[12]); os2.Write("REO "u8);
        os2.U16(0x40); os2.U16(32); os2.U16(126); os2.U16(1152); os2.U16(-128); os2.U16(0);
        os2.U16(1216); os2.U16(128); tables["OS/2"] = os2.ToArray();
        var gasp = new Be(); gasp.U16(0); gasp.U16(1); gasp.U16(65535); gasp.U16(2); tables["gasp"] = gasp.ToArray();

        var output = new Be(); int count = tables.Count, power = 1, selector = 0;
        while (power * 2 <= count) { power *= 2; selector++; }
        output.U32(0x10000); output.U16(count); output.U16(power * 16); output.U16(selector);
        output.U16(count * 16 - power * 16);
        int offset = 12 + count * 16, headOffset = 0;
        foreach (var item in tables) {
            output.Write(Encoding.ASCII.GetBytes(item.Key)); output.U32(Sum(item.Value));
            output.U32((uint)offset); output.U32((uint)item.Value.Length);
            if (item.Key == "head") headOffset = offset;
            offset += (item.Value.Length + 3) & ~3;
        }
        foreach (var item in tables) { output.Write(item.Value); output.Pad(); }
        byte[] result = output.ToArray();
        BinaryPrimitives.WriteUInt32BigEndian(result.AsSpan(headOffset + 8), unchecked(0xb1b0afba - Sum(result)));
        return result;
    }
}
