using System.IO;

namespace Outbreak.Launcher;

// Marching squares on the original four-level coverage. Fractional edge crossings
// retain the font's antialiasing as diagonal outlines rather than chunky pixel boxes.
internal static class FontContours {
    internal readonly record struct Point(int X, int Y);
    internal static List<List<Point>> Trace(byte[,,] glyphs, int glyph) {
        int Value(int x, int y) => x is >= 1 and <= 20 && y is >= 1 and <= 20
            ? glyphs[glyph, x - 1, y - 1] : 0;
        var edges = new Dictionary<Point, Point>();
        int left = 20;
        for (int y = 0; y < 20; y++) for (int x = 0; x < 20; x++)
            if (glyphs[glyph, x, y] >= 2) left = Math.Min(left, x);
        if (left == 20) return new();
        for (int y = 0; y <= 20; y++) for (int x = 0; x <= 20; x++) {
            int a = Value(x, y), b = Value(x + 1, y), c = Value(x + 1, y + 1), d = Value(x, y + 1);
            int mask = (a >= 2 ? 1 : 0) | (b >= 2 ? 2 : 0) | (c >= 2 ? 4 : 0) | (d >= 2 ? 8 : 0);
            Point Edge(int edge) {
                int v0, v1, px, py; bool horizontal;
                switch (edge) {
                    case 0: v0 = a; v1 = b; px = x; py = y; horizontal = true; break;
                    case 1: v0 = b; v1 = c; px = x + 1; py = y; horizontal = false; break;
                    case 2: v0 = d; v1 = c; px = x; py = y + 1; horizontal = true; break;
                    default: v0 = a; v1 = d; px = x; py = y; horizontal = false; break;
                }
                int fraction = (96 - v0 * 64) / (v1 - v0);
                return new(px * 64 + (horizontal ? fraction : 0), py * 64 + (horizontal ? 0 : fraction));
            }
            void Add(int from, int to) => edges.Add(Edge(from), Edge(to));
            switch (mask) {
                case 1: Add(0, 3); break; case 2: Add(1, 0); break; case 3: Add(1, 3); break;
                case 4: Add(2, 1); break;
                case 5:
                    if (a + b + c + d >= 6) { Add(0, 1); Add(2, 3); }
                    else { Add(0, 3); Add(2, 1); } break;
                case 6: Add(2, 0); break; case 7: Add(2, 3); break; case 8: Add(3, 2); break;
                case 9: Add(0, 2); break;
                case 10:
                    if (a + b + c + d >= 6) { Add(3, 0); Add(1, 2); }
                    else { Add(1, 0); Add(3, 2); } break;
                case 11: Add(1, 2); break; case 12: Add(3, 1); break;
                case 13: Add(0, 1); break; case 14: Add(3, 0); break;
            }
        }
        var result = new List<List<Point>>();
        while (edges.Count > 0) {
            Point first = edges.First().Key, current = first;
            var contour = new List<Point>();
            do {
                contour.Add(new(current.X - left * 64, 1216 - current.Y));
                if (!edges.Remove(current, out var next)) throw new InvalidDataException("Open game font contour.");
                current = next;
            } while (current != first);
            if (contour.Count >= 3) result.Add(contour);
        }
        return result;
    }
}
