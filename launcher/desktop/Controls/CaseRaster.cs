using Avalonia.Media.Imaging;
using Avalonia.Platform;
using System.Numerics;
using System.Runtime.InteropServices;
using Vector = Avalonia.Vector;

namespace Outbreak.Launcher.Desktop.Controls;

// RC1 renders the floor layer and the Viewport3D into one BitmapCache at about 720 lines per
// window, then enlarges it with nearest-neighbour scaling. This draws the same scene into that
// bitmap: WPF 3D's per-vertex lighting (ambient, directional fill, spot lamp, ivory specular),
// back materials, perspective-correct texturing, the additive sleeve glare and the floor.
public partial class GameCaseView {
    sealed record Texture(int Width, int Height, int[] Pixels);
    readonly Dictionary<IImage, Texture> rasterTextures = [];
    WriteableBitmap? raster;
    float[] red = [], green = [], blue = [], alpha = [];
    float[] depths = [];
    readonly record struct Vertex(float X, float Y, float InvZ, float U, float V, Vector3 Light, Vector3 Specular);
    static readonly Vector3 Ivory = new(243 / 255f, 236 / 255f, 223 / 255f);
    const double FieldOfView = 34, Ground = -0.97;
    static readonly double Tan = Math.Tan(FieldOfView * Math.PI / 360);

    double CameraDistance(double width, double height) {
        // Enclose the whole case in a sphere, then fit that sphere to the tighter camera angle.
        const double radius = 1.169;
        double horizontal = FieldOfView * Math.PI / 360;
        double vertical = Math.Atan(Math.Tan(horizontal) * height / width);
        return radius / Math.Sin(Math.Min(horizontal, vertical)) * 1.08;
    }
    void RenderCase(DrawingContext dc) {
        if (Bounds.Width <= 0 || Bounds.Height <= 0) return;
        double windowHeight = owner?.Bounds.Height > 0 ? owner.Bounds.Height : Bounds.Height * 2.5;
        // About 720 lines for the whole window: just above a 480p PS2 frame, pixels still visible.
        // The line count is the design, independent of the display's pixel density.
        double scale = Math.Clamp(720 / Math.Max(1, windowHeight), .15, 1);
        int width = Math.Max(1, (int)Math.Ceiling(Bounds.Width * scale)), height = Math.Max(1, (int)Math.Ceiling(Bounds.Height * scale));
        if (raster == null || raster.PixelSize != new PixelSize(width, height)) {
            raster?.Dispose();
            raster = new(new PixelSize(width, height), new Vector(96, 96), PixelFormat.Bgra8888, AlphaFormat.Premul);
            red = new float[width * height]; green = new float[red.Length]; blue = new float[red.Length];
            alpha = new float[red.Length]; depths = new float[red.Length];
        }
        Array.Clear(red); Array.Clear(green); Array.Clear(blue); Array.Clear(alpha); Array.Clear(depths);
        float distance = (float)CameraDistance(Bounds.Width, Bounds.Height);
        float focal = (float)(width / (2 * Tan));
        var camera = new Vector3(0, .02f, distance);
        var rotation = Matrix4x4.CreateRotationX((float)(tilt * Math.PI / 180)) * Matrix4x4.CreateRotationY((float)(turn * Math.PI / 180));
        float level = (float)Math.Clamp(SpotlightLevel, 0, 1);
        Vector2 Project(Vector3 point) {
            float inverse = 1 / (distance - point.Z);
            return new(width / 2f + point.X * focal * inverse, height / 2f - (point.Y - .02f) * focal * inverse);
        }
        RenderFloor(rotation, level, width, height, Project);

        // All three lights are warm ivory at different strengths.
        var ambient = Ivory * (.11f + .26f * level);
        var fillColor = Ivory * (.08f + .11f * level);
        var fillDirection = Vector3.Normalize(new Vector3(1, .4f, 2)); // toward the light (direction -1,-.4,-2)
        var lampColor = Ivory * level;
        var lamp = new Vector3(0, 5, 4);
        var lampAxis = Vector3.Normalize(new Vector3(0, -5, -4));
        // SpotLight cone angles are full apertures, as in Direct3D (inner 14°, outer 26°).
        float innerCos = MathF.Cos(7 * MathF.PI / 180), outerCos = MathF.Cos(13 * MathF.PI / 180);
        var materialSpecular = Ivory * (35 / 255f);
        // Sleeve glare: the lamp's reflection, strongest where the sleeve mirrors it into the camera.
        var half = Vector3.Normalize(Vector3.Normalize(lamp) + Vector3.Normalize(camera));
        var normalFront = Vector3.Normalize(Vector3.TransformNormal(Vector3.UnitZ, rotation));
        var across = Vector3.Normalize(Vector3.TransformNormal(Vector3.UnitX, rotation));
        var up = Vector3.Normalize(Vector3.TransformNormal(Vector3.UnitY, rotation));
        foreach (var mesh in meshes) {
            Texture? texture = mesh.Surface.Image is { } image ? ReadTexture(image) : null;
            var positions = mesh.Positions.Select(p => Vector3.Transform(p.Vector, rotation)).ToArray();
            float glareStrength = 0, glareX = 0, glareY = 0;
            if (mesh.Surface.Glare) {
                float sign = mesh.Surface.Back ? -1 : 1;
                glareStrength = MathF.Pow(Math.Max(0, sign * Vector3.Dot(normalFront, half)), 12) * level;
                glareX = .5f + 2.2f * sign * Vector3.Dot(across, half);
                glareY = .5f - 2.2f * Vector3.Dot(up, half);
                if (glareStrength <= 0) continue;
            }
            for (int i = 0; i < mesh.Indices.Length; i += 3) {
                int ia = mesh.Indices[i], ib = mesh.Indices[i + 1], ic = mesh.Indices[i + 2];
                var a = positions[ia]; var b = positions[ib]; var c = positions[ic];
                var normal = Vector3.Normalize(Vector3.Cross(b - a, c - a));
                if (!float.IsFinite(normal.X)) continue;
                bool backFace = Vector3.Dot(normal, camera - (a + b + c) / 3) < 0;
                // Emissive glare is only visible from the front; BackMaterial lights the reversed normal.
                if (mesh.Surface.Glare && backFace) continue;
                if (backFace) normal = -normal;
                Vertex Shade(Vector3 point, Point uv) {
                    var p = Project(point);
                    var view = Vector3.Normalize(camera - point);
                    var toLamp = Vector3.Normalize(lamp - point);
                    float cone = Vector3.Dot(-toLamp, lampAxis);
                    float spot = Math.Clamp((cone - outerCos) / (innerCos - outerCos), 0, 1);
                    float fillDot = Math.Max(0, Vector3.Dot(normal, fillDirection));
                    float lampDot = Math.Max(0, Vector3.Dot(normal, toLamp));
                    var diffuse = Vector3.Clamp(ambient + fillColor * fillDot + lampColor * (spot * lampDot), Vector3.Zero, Vector3.One);
                    var specular = Vector3.Zero;
                    if (mesh.Specular) {
                        if (fillDot > 0) specular += fillColor * MathF.Pow(Math.Max(0, Vector3.Dot(normal, Vector3.Normalize(fillDirection + view))), 48);
                        if (lampDot > 0 && spot > 0) specular += lampColor * (spot * MathF.Pow(Math.Max(0, Vector3.Dot(normal, Vector3.Normalize(toLamp + view))), 48));
                        specular = Vector3.Clamp(specular * materialSpecular, Vector3.Zero, Vector3.One);
                    }
                    return new(p.X, p.Y, 1 / (distance - point.Z), (float)uv.X, (float)uv.Y, diffuse, specular);
                }
                Triangle(Shade(a, mesh.Uv[ia]), Shade(b, mesh.Uv[ib]), Shade(c, mesh.Uv[ic]), mesh.Surface, texture, width, height, glareX, glareY, glareStrength);
            }
        }
        using (var pixels = raster.Lock()) {
            int[] row = new int[width];
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    int at = y * width + x;
                    float a = Math.Clamp(alpha[at], 0, 1);
                    row[x] = (int)(a * 255 + .5f) << 24 | (int)(Math.Clamp(red[at], 0, a) * 255 + .5f) << 16 |
                             (int)(Math.Clamp(green[at], 0, a) * 255 + .5f) << 8 | (int)(Math.Clamp(blue[at], 0, a) * 255 + .5f);
                }
                Marshal.Copy(row, 0, pixels.Address + y * pixels.RowBytes, width);
            }
        }
        dc.DrawImage(raster, new Rect(Bounds.Size));
    }
    // Source-over a premultiplied colour onto the cache.
    void Blend(int at, float r, float g, float b, float a) {
        red[at] = r + red[at] * (1 - a); green[at] = g + green[at] * (1 - a);
        blue[at] = b + blue[at] * (1 - a); alpha[at] = a + alpha[at] * (1 - a);
    }
    Texture ReadTexture(IImage image) {
        if (rasterTextures.TryGetValue(image, out var texture)) return texture;
        int width = Math.Max(1, (int)Math.Ceiling(image.Size.Width)), height = Math.Max(1, (int)Math.Ceiling(image.Size.Height));
        using var source = new RenderTargetBitmap(new PixelSize(width, height), new Vector(96, 96));
        using (var context = source.CreateDrawingContext()) context.DrawImage(image, new Rect(0, 0, width, height));
        using var bitmap = new WriteableBitmap(new PixelSize(width, height), new Vector(96, 96), PixelFormat.Bgra8888, AlphaFormat.Unpremul);
        int[] pixels = new int[width * height];
        using (var frame = bitmap.Lock()) { source.CopyPixels(frame); for (int y = 0; y < height; y++) Marshal.Copy(frame.Address + y * frame.RowBytes, pixels, y * width, width); }
        texture = new(width, height, pixels); rasterTextures[image] = texture; return texture;
    }
    void Triangle(Vertex a, Vertex b, Vertex c, SceneSurface material, Texture? texture, int width, int height, float glareX, float glareY, float glareStrength) {
        static float Edge(Vertex a, Vertex b, float x, float y) => (x - a.X) * (b.Y - a.Y) - (y - a.Y) * (b.X - a.X);
        float area = Edge(a, b, c.X, c.Y); if (Math.Abs(area) < 1e-7) return;
        int left = Math.Clamp((int)Math.Floor(Math.Min(a.X, Math.Min(b.X, c.X))), 0, width - 1), right = Math.Clamp((int)Math.Ceiling(Math.Max(a.X, Math.Max(b.X, c.X))), 0, width - 1);
        int top = Math.Clamp((int)Math.Floor(Math.Min(a.Y, Math.Min(b.Y, c.Y))), 0, height - 1), bottom = Math.Clamp((int)Math.Ceiling(Math.Max(a.Y, Math.Max(b.Y, c.Y))), 0, height - 1);
        float glareAspect = (float)((ArtWidth + CaseWidth - Profile(SideProfile, CaseDepth)) / (2 * ArtHeight));
        for (int y = top; y <= bottom; y++) for (int x = left; x <= right; x++) {
            float w0 = Edge(b, c, x + .5f, y + .5f) / area, w1 = Edge(c, a, x + .5f, y + .5f) / area, w2 = 1 - w0 - w1;
            if (w0 < 0 || w1 < 0 || w2 < 0) continue;
            float z = w0 * a.InvZ + w1 * b.InvZ + w2 * c.InvZ; int at = y * width + x;
            if (z <= depths[at]) continue;
            float u = (w0 * a.U * a.InvZ + w1 * b.U * b.InvZ + w2 * c.U * c.InvZ) / z, v = (w0 * a.V * a.InvZ + w1 * b.V * b.InvZ + w2 * c.V * c.InvZ) / z;
            if (material.Glare) {
                // EmissiveMaterial adds the radial ivory glare over the cover.
                float gx = (u - glareX) / .24f, gy = (v - glareY) / (.24f * glareAspect);
                float radius = MathF.Sqrt(gx * gx + gy * gy);
                if (radius >= 1) continue;
                float strength = (radius < .3f ? 210 + (150 - 210) * radius / .3f : radius < .65f ? 150 + (40 - 150) * (radius - .3f) / .35f : 40 * (1 - radius) / .35f) / 255f * glareStrength;
                red[at] = Math.Min(alpha[at], red[at] + Ivory.X * strength);
                green[at] = Math.Min(alpha[at], green[at] + Ivory.Y * strength);
                blue[at] = Math.Min(alpha[at], blue[at] + Ivory.Z * strength);
                continue;
            }
            var light = (w0 * a.Light * a.InvZ + w1 * b.Light * b.InvZ + w2 * c.Light * c.InvZ) / z;
            var specular = (w0 * a.Specular * a.InvZ + w1 * b.Specular * b.InvZ + w2 * c.Specular * c.InvZ) / z;
            float r = material.Color.R / 255f, g = material.Color.G / 255f, bl = material.Color.B / 255f;
            if (texture != null) {
                int tx = Math.Clamp((int)(u * texture.Width), 0, texture.Width - 1), ty = Math.Clamp((int)(v * texture.Height), 0, texture.Height - 1);
                int pixel = texture.Pixels[ty * texture.Width + tx]; r = ((pixel >> 16) & 255) / 255f; g = ((pixel >> 8) & 255) / 255f; bl = (pixel & 255) / 255f;
            }
            red[at] = Math.Clamp(r * light.X + specular.X, 0, 1); green[at] = Math.Clamp(g * light.Y + specular.Y, 0, 1);
            blue[at] = Math.Clamp(bl * light.Z + specular.Z, 0, 1); alpha[at] = 1; depths[at] = z;
        }
    }
    // The floor layer: the spotlight pool, the contact patch and the lamp's cast shadow, each with
    // RC1's blur, beneath the case in the same cache.
    // Pool and contact patch depend only on the framing; their blurred masks are cached.
    float[] floorLayer = [], poolMask = [], contactMask = [];
    (int, int, float, float, float) floorKey;
    void RenderFloor(Matrix4x4 rotation, float level, int width, int height, Func<Vector3, Vector2> project) {
        double cacheScale = width / Math.Max(1, Bounds.Width);
        var floor = project(new Vector3(0, (float)Ground, 0));
        float caseWidth = project(new Vector3(.675f, (float)Ground, 0)).X - project(new Vector3(-.675f, (float)Ground, 0)).X;
        var key = (width, height, floor.X, floor.Y, caseWidth);
        if (floorKey != key || poolMask.Length != width * height) {
            floorKey = key;
            poolMask = new float[width * height]; contactMask = new float[width * height]; floorLayer = new float[width * height];
            // Pool: ivory 72 → 0 radial, 2.2 × 0.5 case widths, blur 10.
            Ellipse(poolMask, width, height, floor, caseWidth * 1.1f, caseWidth * .25f, 72 / 255f, (float)(10 * cacheScale));
            // Contact: black 240 → 0 radial, 1.1 case widths × max(10, .18 widths), blur 8.
            Ellipse(contactMask, width, height, floor, caseWidth * .55f, Math.Max(10 * (float)cacheScale, caseWidth * .18f) / 2, 240 / 255f, (float)(8 * cacheScale));
        }
        if (level > 0)
            for (int i = 0; i < poolMask.Length; i++) {
                float a = poolMask[i] * level;
                if (a > 0) Blend(i, Ivory.X * a, Ivory.Y * a, Ivory.Z * a, a);
            }
        float contact = .45f + .55f * level;
        for (int i = 0; i < contactMask.Length; i++) if (contactMask[i] > 0) Blend(i, 0, 0, 0, contactMask[i] * contact);
        if (level <= 0) return;
        // Shadow: the eight corners cast from the lamp onto the floor, as a convex hull.
        var lamp = new Vector3(0, 5, 4);
        var corners = (from x in new[] { -.675f, .675f } from y in new[] { -.95f, .95f } from z in new[] { -.07f, .07f }
                       select Vector3.Transform(new Vector3(x, y, z), rotation)).ToArray();
        var projected = corners.Select(point => {
            float ray = (float)((Ground - lamp.Y) / (point.Y - lamp.Y));
            return project(lamp + (point - lamp) * ray);
        }).OrderBy(p => p.X).ThenBy(p => p.Y).ToArray();
        static float Cross(Vector2 a, Vector2 b, Vector2 c) => (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
        var hull = new List<Vector2>();
        foreach (var p in projected) { while (hull.Count >= 2 && Cross(hull[^2], hull[^1], p) <= 0) hull.RemoveAt(hull.Count - 1); hull.Add(p); }
        int lower = hull.Count;
        foreach (var p in projected.Reverse().Skip(1)) { while (hull.Count > lower && Cross(hull[^2], hull[^1], p) <= 0) hull.RemoveAt(hull.Count - 1); hull.Add(p); }
        if (hull.Count > 1) hull.RemoveAt(hull.Count - 1);
        if (hull.Count < 3) return;
        float blur = (float)(5 * cacheScale);
        float top = hull.Min(p => p.Y), bottom = hull.Max(p => p.Y), left = hull.Min(p => p.X), right = hull.Max(p => p.X);
        int x0 = Math.Clamp((int)(left - blur * 2) - 1, 0, width - 1), x1 = Math.Clamp((int)(right + blur * 2) + 1, 0, width - 1);
        int y0 = Math.Clamp((int)(top - blur * 2) - 1, 0, height - 1), y1 = Math.Clamp((int)(bottom + blur * 2) + 1, 0, height - 1);
        var layer = floorLayer;
        for (int y = y0; y <= y1; y++) Array.Clear(layer, y * width + x0, x1 - x0 + 1);
        for (int y = Math.Max(0, (int)top); y <= Math.Min(height - 1, (int)Math.Ceiling(bottom)); y++)
            for (int x = Math.Max(0, (int)left); x <= Math.Min(width - 1, (int)Math.Ceiling(right)); x++) {
                var point = new Vector2(x + .5f, y + .5f);
                bool inside = true;
                for (int i = 0; i < hull.Count && inside; i++) inside = Cross(hull[i], hull[(i + 1) % hull.Count], point) >= 0;
                if (!inside) {
                    inside = true;
                    for (int i = 0; i < hull.Count && inside; i++) inside = Cross(hull[i], hull[(i + 1) % hull.Count], point) <= 0;
                }
                // Vertical gradient over the shape's bounds: transparent at the top, black 190 at the bottom.
                if (inside) layer[y * width + x] = 190 / 255f * (bottom > top ? (point.Y - top) / (bottom - top) : 1);
            }
        Blur(layer, width, height, blur, x0, y0, x1, y1);
        for (int y = y0; y <= y1; y++)
            for (int x = x0; x <= x1; x++) {
                int i = y * width + x;
                if (layer[i] > 0) Blend(i, 0, 0, 0, Math.Clamp(layer[i] * level, 0, 1));
            }
    }
    void Ellipse(float[] layer, int width, int height, Vector2 center, float radiusX, float radiusY, float peak, float blur) {
        int left = Math.Max(0, (int)(center.X - radiusX - blur)), right = Math.Min(width - 1, (int)(center.X + radiusX + blur));
        int top = Math.Max(0, (int)(center.Y - radiusY - blur)), bottom = Math.Min(height - 1, (int)(center.Y + radiusY + blur));
        for (int y = top; y <= bottom; y++) for (int x = left; x <= right; x++) {
            float dx = (x + .5f - center.X) / radiusX, dy = (y + .5f - center.Y) / radiusY;
            float r = MathF.Sqrt(dx * dx + dy * dy);
            if (r < 1) layer[y * width + x] = peak * (1 - r);
        }
        Blur(layer, width, height, blur, Math.Max(0, left - (int)blur), Math.Max(0, top - (int)blur),
             Math.Min(width - 1, right + (int)blur), Math.Min(height - 1, bottom + (int)blur));
    }
    // WPF BlurEffect (Gaussian, Radius ≈ 3σ), as three box passes per axis.
    static void Blur(float[] layer, int width, int height, float radius, int x0, int y0, int x1, int y1) {
        if (radius < .5f) return;
        double sigma = radius / 3.0;
        int reach = Math.Max(1, (int)Math.Round(Math.Sqrt(12 * sigma * sigma / 3 + 1))) / 2;
        int w = x1 - x0 + 1, h = y1 - y0 + 1;
        if (w <= 0 || h <= 0) return;
        var line = new float[Math.Max(w, h)];
        float scale = 1f / (2 * reach + 1);
        for (int pass = 0; pass < 3; pass++) {
            for (int y = y0; y <= y1; y++) {
                float sum = 0;
                for (int x = x0 - reach; x <= x1 + reach; x++) {
                    int add = x + reach, remove = x - reach - 1;
                    if (add >= x0 && add <= x1) sum += layer[y * width + add];
                    if (remove >= x0 && remove <= x1) sum -= layer[y * width + remove];
                    if (x >= x0 && x <= x1) line[x - x0] = sum * scale;
                }
                Array.Copy(line, 0, layer, y * width + x0, w);
            }
            for (int x = x0; x <= x1; x++) {
                float sum = 0;
                for (int y = y0 - reach; y <= y1 + reach; y++) {
                    int add = y + reach, remove = y - reach - 1;
                    if (add >= y0 && add <= y1) sum += layer[add * width + x];
                    if (remove >= y0 && remove <= y1) sum -= layer[remove * width + x];
                    if (y >= y0 && y <= y1) line[y - y0] = sum * scale;
                }
                for (int y = y0; y <= y1; y++) layer[y * width + x] = line[y - y0];
            }
        }
    }
}
