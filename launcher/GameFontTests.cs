using System.Buffers.Binary;
using System.IO;
using System.Windows;
using System.Windows.Media;

namespace Outbreak.Launcher;
internal static class GameFontTests {
    internal static void Run(Action<bool, string> check) {
        byte[] atlas = new byte[780800];
        check(GameFont.GlyphIndex('A') == 220 && GameFont.GlyphIndex('a') == 252 &&
            GameFont.GlyphIndex('0') == 203, "Dialogue font maps Latin characters to Shift-JIS slots");
        check(GameFont.GlyphIndex(' ') == 0 && GameFont.GlyphIndex('\\') == 31 &&
            GameFont.GlyphIndex('\'') == 38 && GameFont.GlyphIndex('"') == 40,
            "Dialogue font maps spaces, paths and quotes");
        int a = 'A' - 32, offset = 220 * 100;
        atlas[offset + 3 * 5] = 0x1b; // four distinct coverage samples, most significant first
        var pixels = GameFont.Decode(atlas);
        check(pixels[a, 0, 3] == 0 && pixels[a, 1, 3] == 1 && pixels[a, 2, 3] == 2 &&
            pixels[a, 3, 3] == 3, "Dialogue font retains all four antialiasing levels in the right order");
        foreach (byte[] invalid in new[] { Array.Empty<byte>(), atlas[..^1], new byte[780801] }) {
            bool rejected = false;
            try { GameFont.Decode(invalid); } catch (InvalidDataException) { rejected = true; }
            check(rejected, "Dialogue font rejects truncated or oversized glyph tables");
        }
        check(FontContours.Trace(pixels, a).Count > 0 && FontContours.Trace(pixels, 0).Count == 0,
            "Dialogue font traces nonempty glyphs and preserves spaces");
        var ring = new byte[95, 20, 20];
        for (int y = 4; y < 12; y++) for (int x = 4; x < 12; x++)
            if (x < 6 || x >= 10 || y < 6 || y >= 10) ring[a, x, y] = 3;
        var contours = FontContours.Trace(ring, a);
        long Area(List<FontContours.Point> c) => c.Select((v, i) =>
            (long)v.X * c[(i + 1) % c.Count].Y - (long)c[(i + 1) % c.Count].X * v.Y).Sum();
        check(contours.Count == 2 && Area(contours[0]) * Area(contours[1]) < 0,
            "Dialogue contours preserve counters with opposite winding");
        byte[] built = BitmapTypeface.Build(pixels, GameFont.FamilyName);
        check(built.SequenceEqual(BitmapTypeface.Build(pixels, GameFont.FamilyName)), "Game typeface generation is deterministic");
        uint sum = 0;
        for (int i = 0; i < built.Length; i += 4)
            sum = unchecked(sum + BinaryPrimitives.ReadUInt32BigEndian(built.AsSpan(i, 4)));
        check(sum == 0xb1b0afba, "Game typeface has the TrueType whole-file checksum");
        string folder = Path.Combine(Path.GetTempPath(), "reo-font-test-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(folder);
        string path = Path.Combine(folder, "synthetic.ttf");
        try {
            File.WriteAllBytes(path, built);
            var font = GameFont.Load(path);
            var typeface = new Typeface(font, FontStyles.Normal, FontWeights.Normal, FontStretches.Normal);
            bool loaded = typeface.TryGetGlyphTypeface(out var face);
            check(loaded && face.GlyphCount == 96, "WPF loads generated game typeface without system font fallback");
            check(loaded && face.CharacterToGlyphMap.TryGetValue('A', out ushort glyph) && glyph == 34 && face.AdvanceWidths[glyph] > 0,
                "Generated dialogue font maps ASCII to the decoded glyph");
            check(loaded && !face.CharacterToGlyphMap.ContainsKey('\u00e9'), "Unsupported characters remain available for WPF font fallback");
        } finally {
            // WPF can retain a read handle; leave only this tiny synthetic temp file if locked.
            try { File.Delete(path); Directory.Delete(folder); }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException) { }
        }
    }
}
