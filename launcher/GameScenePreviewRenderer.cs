using System.Diagnostics;
using System.IO;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal sealed record PreviewRenderOptions(int InternalResolution, bool TextureLinear, int Anisotropy,
    string AntiAliasing, string Aspect, bool Widescreen, string ScreenFit, bool LinearFilter,
    int Brightness, double Gamma, int WindowWidth = 1280, int WindowHeight = 720, bool CoverPreview = false);

internal sealed record PreviewFrame(int Width, int Height, byte[] Bgra, int RenderWidth, int RenderHeight);
internal sealed record PreviewRenderTimings(double Background, double Animation, double Geometry, double Antialiasing, double Presentation);

// A small, isolated preview renderer. It never starts the game or shares its graphics
// device. Texture sampling, depth, perspective and resolution are actually evaluated
// for each frame; the preview is not a filtered movie or a stack of pre-rendered images.
internal sealed class GameScenePreviewRenderer {
    readonly ConditionalWeakTable<PreviewTexture, Texture> textures = new();
    readonly List<PreviewMesh> environment = new();
    readonly List<PreviewTexture> environmentTextures = new();
    readonly Vector3 lightDirection = Vector3.Normalize(new(-.35f, .85f, .55f));
    float[] depth = Array.Empty<float>();
    uint[] color = Array.Empty<uint>();
    float[] environmentDepth = Array.Empty<float>();
    uint[] environmentColor = Array.Empty<uint>();
    uint[]? environmentFxaa;
    uint[] fxaaResult = Array.Empty<uint>();
    uint[] morphologyResult = Array.Empty<uint>();
    byte[] morphologyEdges = Array.Empty<byte>();
    (int Width, int Height, float Aspect, bool Linear, int Anisotropy, Vector4 Crop)? environmentKey;
    readonly ConditionalWeakTable<PreviewMesh, Vertex[]> transformedVertices = new();
    internal PreviewRenderTimings? LastTimings { get; private set; }
    Presentation? presentation;
    PresentationMap? presentationMap;
    byte[] colorLut = new byte[256];
    (int Brightness, double Gamma)? colorKey;
    Vector4 crop = new(0, 0, 1, 1);
    bool collectCharacterBounds;
    int characterLeft, characterTop, characterRight, characterBottom;
    int renderWidth, renderHeight;
    Matrix4x4 view;
    float tangent, cameraAspect;
    PreviewRenderOptions options = null!;
    readonly record struct Vertex(Vector3 View, Vector2 Uv, float Light);
    readonly record struct Projected(float X, float Y, float InvZ, float U, float V, float Light);
    readonly record struct Presentation(float WindowWidth, float WindowHeight, float PictureX, float PictureY,
        float PictureWidth, float PictureHeight, float ViewX, float ViewY, float ViewWidth, float ViewHeight);
    sealed record PresentationMap(int Width, int Height, int SourceWidth, int SourceHeight, bool Cover,
        Presentation Layout, int[] X0, int[] X1, int[] Y0, int[] Y1, int[] Fx, int[] Fy,
        int[] NearestX, int[] NearestY, bool[] ValidX, bool[] ValidY);

    internal GameScenePreviewRenderer() => BuildEnvironment();
    internal IReadOnlyList<PreviewMesh> EnvironmentMeshes => environment;
    internal IReadOnlyList<PreviewTexture> EnvironmentTextures => environmentTextures;

    internal PreviewFrame Render(GamePreviewScene scene, PreviewRenderOptions requested, double seconds, int width, int height,
                                 float yaw = 0, float pitch = 0, float zoom = 1) {
        ArgumentNullException.ThrowIfNull(scene);
        ArgumentNullException.ThrowIfNull(requested);
        width = Math.Clamp(width, 32, 1600); height = Math.Clamp(height, 32, 1600);
        options = requested with {
            InternalResolution = requested.InternalResolution is 2 or 4 ? requested.InternalResolution : 1,
            Anisotropy = requested.Anisotropy is 2 or 4 or 8 or 16 ? requested.Anisotropy : 1,
            Brightness = Math.Clamp(requested.Brightness, 50, 150),
            Gamma = double.IsFinite(requested.Gamma) ? Math.Clamp(requested.Gamma, .5, 2) : 1,
            WindowWidth = Math.Clamp(requested.WindowWidth, 256, 7680),
            WindowHeight = Math.Clamp(requested.WindowHeight, 224, 4320)
        };
        presentation = LayoutPresentation(width, height);
        crop = options.CoverPreview ? new(
            (presentation.Value.ViewX - presentation.Value.PictureX) / presentation.Value.PictureWidth,
            (presentation.Value.ViewY - presentation.Value.PictureY) / presentation.Value.PictureHeight,
            presentation.Value.ViewWidth / presentation.Value.PictureWidth,
            presentation.Value.ViewHeight / presentation.Value.PictureHeight) : new(0, 0, 1, 1);
        // Cover crops the frustum before rasterization, retaining every selected
        // vertical sample. It omits hidden side pixels rather than lowering quality.
        int fullWidth = options.CoverPreview ? 256 * options.InternalResolution
            : Math.Min(256 * options.InternalResolution, Math.Max(256, width * 2));
        renderWidth = Math.Max(1, (int)Math.Ceiling(fullWidth * crop.Z));
        renderHeight = Math.Max(1, (int)Math.Ceiling(fullWidth * 224.0 / 256 * crop.W));
        if (depth.Length != renderWidth * renderHeight) {
            depth = new float[renderWidth * renderHeight]; color = new uint[depth.Length];
        }
        cameraAspect = options.Widescreen ? Aspect(options.Aspect) : 4f / 3;
        tangent = MathF.Tan(32 * MathF.PI / 360);
        view = Matrix4x4.CreateLookAt(new(2.8f, 1.55f, 4.4f), new(0, .95f, 0), Vector3.UnitY);
        long timestamp = Stopwatch.GetTimestamp();
        var backgroundKey = (renderWidth, renderHeight, cameraAspect, options.TextureLinear, options.Anisotropy, crop);
        if (environmentKey == backgroundKey) {
            environmentDepth.CopyTo(depth, 0); environmentColor.CopyTo(color, 0);
        } else {
            Array.Clear(depth); Array.Fill(color, 0xff111214);
            foreach (var mesh in environment) Draw(mesh, environmentTextures, Matrix4x4.Identity, false);
            environmentDepth = (float[])depth.Clone(); environmentColor = (uint[])color.Clone();
            environmentFxaa = null;
            environmentKey = backgroundKey;
        }
        long afterBackground = Stopwatch.GetTimestamp();
        scene.Animate(double.IsFinite(seconds) ? Math.Max(0, seconds) : 0);
        long afterAnimation = Stopwatch.GetTimestamp();
        float modelHeight = scene.Maximum.Y - scene.Minimum.Y;
        if (!float.IsFinite(modelHeight) || modelHeight < .001f) throw new InvalidDataException("The character has no usable bounds.");
        float scale = 1.8f / modelHeight;
        var center = new Vector3((scene.Minimum.X + scene.Maximum.X) / 2, scene.Minimum.Y,
            (scene.Minimum.Z + scene.Maximum.Z) / 2);
        var model = Matrix4x4.CreateTranslation(-center) * Matrix4x4.CreateScale(scale);
        model *= Matrix4x4.CreateTranslation(0,-.9f,0) *
                 Matrix4x4.CreateFromYawPitchRoll(yaw*MathF.PI/180,pitch*MathF.PI/180,0) *
                 Matrix4x4.CreateScale(Math.Clamp(zoom,.4f,3f)) * Matrix4x4.CreateTranslation(0,.9f,0);
        characterLeft = renderWidth; characterTop = renderHeight; characterRight = characterBottom = -1;
        foreach (var mesh in scene.Meshes) Draw(mesh, scene.Textures, model, true);
        long afterGeometry = Stopwatch.GetTimestamp();
        uint[] filtered = options.AntiAliasing switch {
            "fxaa" => FxaaCharacter(),
            "smaa" => MorphologicalAa(color, renderWidth, renderHeight), _ => color
        };
        long afterAntialiasing = Stopwatch.GetTimestamp();
        var frame = new PreviewFrame(width, height, Present(filtered, width, height), renderWidth, renderHeight);
        long afterPresentation = Stopwatch.GetTimestamp();
        static double Milliseconds(long begin, long end) => (end - begin) * 1000.0 / Stopwatch.Frequency;
        LastTimings = new(Milliseconds(timestamp, afterBackground), Milliseconds(afterBackground, afterAnimation),
            Milliseconds(afterAnimation, afterGeometry), Milliseconds(afterGeometry, afterAntialiasing),
            Milliseconds(afterAntialiasing, afterPresentation));
        return frame;
    }

    void Draw(PreviewMesh mesh, IReadOnlyList<PreviewTexture> sourceTextures, Matrix4x4 model, bool character) {
        if (mesh.Positions.Length > 200_000 || mesh.Indices.Length > 600_000)
            throw new InvalidDataException("The preview mesh exceeds its geometry limit.");
        var transformed = transformedVertices.GetValue(mesh, m => new Vertex[m.Positions.Length]);
        for (int i = 0; i < transformed.Length; i++) {
            var world = Vector3.Transform(mesh.Positions[i], model);
            var normal = i < mesh.Normals.Length ? mesh.Normals[i] : Vector3.UnitY;
            if (normal.LengthSquared() < .001f || !float.IsFinite(normal.X + normal.Y + normal.Z)) normal = Vector3.UnitY;
            normal = Vector3.Normalize(normal);
            float light = .31f + .66f * Math.Max(0, Vector3.Dot(normal, lightDirection));
            if (character) light += .13f;
            transformed[i] = new(Vector3.Transform(world, view), i < mesh.TexCoords.Length ? mesh.TexCoords[i] : Vector2.Zero, light);
        }
        Texture? texture = mesh.TextureIndex >= 0 && mesh.TextureIndex < sourceTextures.Count
            ? textures.GetValue(sourceTextures[mesh.TextureIndex], t => new Texture(t)) : null;
        collectCharacterBounds = character;
        Span<Vertex> clipped = stackalloc Vertex[4];
        for (int i = 0; i + 2 < mesh.Indices.Length; i += 3) {
            int ia = mesh.Indices[i], ib = mesh.Indices[i + 1], ic = mesh.Indices[i + 2];
            if ((uint)ia >= transformed.Length || (uint)ib >= transformed.Length || (uint)ic >= transformed.Length) continue;
            var a = transformed[ia]; var b = transformed[ib]; var c = transformed[ic];
            if (a.View.Z < -.08f && b.View.Z < -.08f && c.View.Z < -.08f) Raster(Project(a), Project(b), Project(c), texture);
            else {
                int count = Clip(a, b, c, clipped);
                for (int p = 1; p + 1 < count; p++) Raster(Project(clipped[0]), Project(clipped[p]), Project(clipped[p + 1]), texture);
            }
        }
    }

    static int Clip(Vertex a, Vertex b, Vertex c, Span<Vertex> output) {
        const float near = .08f;
        Span<Vertex> input = stackalloc Vertex[] { a, b, c };
        int count = 0; var previous = c; bool wasInside = previous.View.Z < -near;
        foreach (var current in input) {
            bool inside = current.View.Z < -near;
            if (inside != wasInside) {
                float amount = (-near - previous.View.Z) / (current.View.Z - previous.View.Z);
                output[count++] = new(Vector3.Lerp(previous.View, current.View, amount),
                    Vector2.Lerp(previous.Uv, current.Uv, amount), previous.Light + (current.Light - previous.Light) * amount);
            }
            if (inside) output[count++] = current;
            previous = current; wasInside = inside;
        }
        return count;
    }
    Projected Project(Vertex vertex) {
        float invZ = -1 / vertex.View.Z;
        return new(((vertex.View.X * invZ / (tangent * cameraAspect) + 1) / 2 - crop.X) * renderWidth / crop.Z,
            ((1 - vertex.View.Y * invZ / tangent) / 2 - crop.Y) * renderHeight / crop.W, invZ,
            vertex.Uv.X * invZ, vertex.Uv.Y * invZ, vertex.Light * invZ);
    }
    static float Edge(Projected a, Projected b, float x, float y) => (x - a.X) * (b.Y - a.Y) - (y - a.Y) * (b.X - a.X);
    void Raster(Projected a, Projected b, Projected c, Texture? texture) {
        float area = Edge(a, b, c.X, c.Y);
        if (!float.IsFinite(area) || Math.Abs(area) < .001f) return;
        if (area < 0) { (b, c) = (c, b); area = -area; }
        int x0 = Math.Max(0, (int)MathF.Floor(Math.Min(a.X, Math.Min(b.X, c.X))));
        int x1 = Math.Min(renderWidth - 1, (int)MathF.Ceiling(Math.Max(a.X, Math.Max(b.X, c.X))));
        int y0 = Math.Max(0, (int)MathF.Floor(Math.Min(a.Y, Math.Min(b.Y, c.Y))));
        int y1 = Math.Min(renderHeight - 1, (int)MathF.Ceiling(Math.Max(a.Y, Math.Max(b.Y, c.Y))));
        if (x0 > x1 || y0 > y1) return;
        if (collectCharacterBounds) {
            characterLeft = Math.Min(characterLeft, x0); characterRight = Math.Max(characterRight, x1);
            characterTop = Math.Min(characterTop, y0); characterBottom = Math.Max(characterBottom, y1);
        }
        float inverse = 1 / area;
        float adx = (c.Y - b.Y) * inverse, bdx = (a.Y - c.Y) * inverse, cdx = (b.Y - a.Y) * inverse;
        float ady = (b.X - c.X) * inverse, bdy = (c.X - a.X) * inverse, cdy = (a.X - b.X) * inverse;
        float qdx = adx * a.InvZ + bdx * b.InvZ + cdx * c.InvZ, qdy = ady * a.InvZ + bdy * b.InvZ + cdy * c.InvZ;
        float udx = adx * a.U + bdx * b.U + cdx * c.U, udy = ady * a.U + bdy * b.U + cdy * c.U;
        float vdx = adx * a.V + bdx * b.V + cdx * c.V, vdy = ady * a.V + bdy * b.V + cdy * c.V;
        bool anisotropic = options.Anisotropy > 1;
        for (int y = y0; y <= y1; y++) {
            float wa = Edge(b, c, x0 + .5f, y + .5f) * inverse;
            float wb = Edge(c, a, x0 + .5f, y + .5f) * inverse;
            float wc = 1 - wa - wb;
            int index = y * renderWidth + x0;
            for (int x = x0; x <= x1; x++, index++, wa += adx, wb += bdx, wc += cdx) {
                if (wa < -.00001f || wb < -.00001f || wc < -.00001f) continue;
                float q = wa * a.InvZ + wb * b.InvZ + wc * c.InvZ;
                if (q <= depth[index]) continue;
                float z = 1 / q, u = (wa * a.U + wb * b.U + wc * c.U) * z, v = (wa * a.V + wb * b.V + wc * c.V) * z;
                Vector4 texel = texture == null ? new(.6f, .6f, .6f, 1) : anisotropic
                    ? texture.Anisotropic(u, v, (udx - u * qdx) * z, (vdx - v * qdx) * z,
                        (udy - u * qdy) * z, (vdy - v * qdy) * z, options.Anisotropy)
                    : texture.Sample(u, v, options.TextureLinear);
                if (texel.W < .35f) continue;
                float light = (wa * a.Light + wb * b.Light + wc * c.Light) * z;
                float fog = Math.Clamp((z - 4) / 16, 0, .65f);
                var rgb = Vector3.Lerp(new(texel.X * light, texel.Y * light, texel.Z * light), new(.055f, .06f, .065f), fog);
                color[index] = Pack(rgb); depth[index] = q;
            }
        }
    }

    static float Aspect(string aspect) => aspect switch { "16:9" => 16f / 9, "21:9" => 43f / 18, "32:9" => 32f / 9, _ => 4f / 3 };
    Presentation LayoutPresentation(int width, int height) {
        float windowW = options.WindowWidth, windowH = options.WindowHeight;
        float aspect = Aspect(options.Aspect), pictureW = windowW, pictureH = windowH;
        if (options.ScreenFit != "stretch") {
            if (options.ScreenFit == "center") {
                pictureH = Math.Min(448 * options.InternalResolution, Math.Min(windowW / aspect, windowH));
                pictureW = pictureH * aspect;
            } else if ((windowW / windowH > aspect) != (options.ScreenFit == "fill")) pictureW = pictureH * aspect;
            else pictureH = pictureW / aspect;
        }
        float pictureX = (windowW - pictureW) / 2, pictureY = (windowH - pictureH) / 2;
        float x = Math.Max(0, pictureX), y = Math.Max(0, pictureY);
        float activeW = Math.Min(windowW, pictureX + pictureW) - x;
        float activeH = Math.Min(windowH, pictureY + pictureH) - y;
        if (options.CoverPreview) {
            float ratio = (float)width / height;
            float visibleW = Math.Min(activeW, activeH * ratio), visibleH = Math.Min(activeH, activeW / ratio);
            return new(windowW, windowH, pictureX, pictureY, pictureW, pictureH,
                x + (activeW - visibleW) / 2, y + (activeH - visibleH) / 2, visibleW, visibleH);
        }
        return new(windowW, windowH, pictureX, pictureY, pictureW, pictureH, 0, 0, windowW, windowH);
    }

    PresentationMap MapPresentation(int width, int height) {
        var layout = presentation!.Value;
        if (presentationMap is { } cached && cached.Width == width && cached.Height == height &&
            cached.SourceWidth == renderWidth && cached.SourceHeight == renderHeight &&
            cached.Layout == layout && cached.Cover == options.CoverPreview) return cached;
        var x0 = new int[width]; var x1 = new int[width]; var y0 = new int[height]; var y1 = new int[height];
        var fx = new int[width]; var fy = new int[height]; var validX = new bool[width]; var validY = new bool[height];
        var nearestX = new int[width]; var nearestY = new int[height];
        float windowScale = Math.Min(width / layout.WindowWidth, height / layout.WindowHeight);
        void Axis(int count, int samples, float window, float pictureOrigin, float pictureSize, float viewOrigin,
            float viewSize, float cropOrigin, float cropSize, int[] first, int[] second, int[] weights, int[] nearest, bool[] valid) {
            float border = (count - window * windowScale) / 2;
            for (int i = 0; i < count; i++) {
                float virtualPixel = options.CoverPreview ? viewOrigin + (i + .5f) * viewSize / count : (i + .5f - border) / windowScale;
                float quantized = MathF.Floor(virtualPixel) + .5f;
                float uv = ((quantized - pictureOrigin) / pictureSize - cropOrigin) / cropSize;
                valid[i] = options.CoverPreview || virtualPixel >= 0 && virtualPixel < window && uv >= 0 && uv < 1;
                float position = Math.Clamp(uv * samples - .5f, 0, samples - 1);
                int low = (int)position;
                first[i] = low; second[i] = Math.Min(low + 1, samples - 1);
                weights[i] = Math.Clamp((int)((position - low) * 256 + .5f), 0, 256);
                nearest[i] = Math.Clamp((int)(uv * samples), 0, samples - 1);
            }
        }
        Axis(width, renderWidth, layout.WindowWidth, layout.PictureX, layout.PictureWidth, layout.ViewX, layout.ViewWidth,
            crop.X, crop.Z, x0, x1, fx, nearestX, validX);
        Axis(height, renderHeight, layout.WindowHeight, layout.PictureY, layout.PictureHeight, layout.ViewY, layout.ViewHeight,
            crop.Y, crop.W, y0, y1, fy, nearestY, validY);
        return presentationMap = new(width, height, renderWidth, renderHeight, options.CoverPreview, layout,
            x0, x1, y0, y1, fx, fy, nearestX, nearestY, validX, validY);
    }
    byte[] Present(uint[] source, int width, int height) {
        byte[] result = new byte[width * height * 4];
        var destination = MemoryMarshal.Cast<byte, uint>(result.AsSpan());
        var map = MapPresentation(width, height);
        if (colorKey != (options.Brightness, options.Gamma)) {
            for (int i = 0; i < 256; i++) colorLut[i] = (byte)Math.Clamp((int)Math.Round(Math.Pow(Math.Clamp(i / 255.0 * options.Brightness / 100, 0, 1), 1 / options.Gamma) * 255), 0, 255);
            colorKey = (options.Brightness, options.Gamma);
        }
        bool neutral = options.Brightness == 100 && options.Gamma == 1;
        bool cover = options.CoverPreview;
        for (int y = 0; y < height; y++) {
            int row0 = map.Y0[y] * renderWidth, row1 = map.Y1[y] * renderWidth, fractionY = map.Fy[y];
            int nearestRow = map.NearestY[y] * renderWidth;
            for (int x = 0; x < width; x++) {
                int index = y * width + x;
                if (!cover && (!map.ValidX[x] || !map.ValidY[y])) { destination[index] = 0xff000000u; continue; }
                uint pixel = options.LinearFilter
                    ? LerpPacked(LerpPacked(source[row0 + map.X0[x]], source[row0 + map.X1[x]], map.Fx[x]),
                        LerpPacked(source[row1 + map.X0[x]], source[row1 + map.X1[x]], map.Fx[x]), fractionY)
                    : source[nearestRow + map.NearestX[x]];
                destination[index] = neutral ? pixel : 0xff000000u | colorLut[pixel & 255] |
                    (uint)colorLut[(pixel >> 8) & 255] << 8 | (uint)colorLut[(pixel >> 16) & 255] << 16;
            }
        }
        return result;
    }
    static uint LerpPacked(uint a, uint b, int weight) {
        uint right = (uint)weight, left = 256 - right;
        return 0xff000000u | (((a & 0x00ff00ff) * left + (b & 0x00ff00ff) * right) >> 8 & 0x00ff00ff) |
            (((a & 0x0000ff00) * left + (b & 0x0000ff00) * right) >> 8 & 0x0000ff00);
    }
    static uint Pack(Vector3 rgb) => 0xff000000u | (uint)(Math.Clamp(rgb.X, 0, 1) * 255) << 16 |
        (uint)(Math.Clamp(rgb.Y, 0, 1) * 255) << 8 | (uint)(Math.Clamp(rgb.Z, 0, 1) * 255);
    static Vector3 Unpack(uint c) => new((c >> 16 & 255) / 255f, (c >> 8 & 255) / 255f, (c & 255) / 255f);
    static uint SampleFrame(uint[] source, int width, int height, float u, float v, bool linear) {
        if (!linear) return source[Math.Clamp((int)(v * height), 0, height - 1) * width + Math.Clamp((int)(u * width), 0, width - 1)];
        float px = u * width - .5f, py = v * height - .5f;
        int x = (int)MathF.Floor(px), y = (int)MathF.Floor(py); float fx = px - x, fy = py - y;
        int x0 = Math.Clamp(x, 0, width - 1), x1 = Math.Clamp(x + 1, 0, width - 1),
            row0 = Math.Clamp(y, 0, height - 1) * width, row1 = Math.Clamp(y + 1, 0, height - 1) * width;
        int wx = Math.Clamp((int)(fx * 256 + .5f), 0, 256), wy = Math.Clamp((int)(fy * 256 + .5f), 0, 256);
        return LerpPacked(LerpPacked(source[row0 + x0], source[row0 + x1], wx),
            LerpPacked(source[row1 + x0], source[row1 + x1], wx), wy);
    }

    sealed class Texture {
        readonly List<(int Width, int Height, Vector4[] Pixels)> levels = new();
        internal Texture(PreviewTexture source) {
            if (source.Width is < 1 or > 4096 || source.Height is < 1 or > 4096 || source.Rgba.Length != source.Width * source.Height * 4)
                throw new InvalidDataException("Invalid preview texture.");
            var first = new Vector4[source.Width * source.Height];
            for (int i = 0; i < first.Length; i++) first[i] = new Vector4(source.Rgba[i * 4], source.Rgba[i * 4 + 1], source.Rgba[i * 4 + 2], source.Rgba[i * 4 + 3]) / 255;
            levels.Add((source.Width, source.Height, first));
            while (levels[^1].Width > 1 || levels[^1].Height > 1) {
                var last = levels[^1]; int width = Math.Max(1, last.Width / 2), height = Math.Max(1, last.Height / 2);
                var pixels = new Vector4[width * height];
                for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) {
                    Vector4 sum = Vector4.Zero;
                    for (int j = 0; j < 2; j++) for (int i = 0; i < 2; i++) sum += last.Pixels[Math.Min(last.Height - 1, y * 2 + j) * last.Width + Math.Min(last.Width - 1, x * 2 + i)];
                    pixels[y * width + x] = sum * .25f;
                }
                levels.Add((width, height, pixels));
            }
        }
        internal Vector4 Sample(float u, float v, bool linear, int mip = 0) {
            if (!float.IsFinite(u + v)) return Vector4.Zero;
            var level = levels[Math.Clamp(mip, 0, levels.Count - 1)];
            u -= MathF.Floor(u); v -= MathF.Floor(v);
            if (!linear) return level.Pixels[Math.Min((int)(v * level.Height), level.Height - 1) * level.Width + Math.Min((int)(u * level.Width), level.Width - 1)];
            float px = u * level.Width - .5f, py = v * level.Height - .5f;
            int x = (int)MathF.Floor(px), y = (int)MathF.Floor(py); float fx = px - x, fy = py - y;
            // Wrapping UVs above bounds each coordinate to [-1, dimension-1].
            // Resolve those four neighbors once instead of eight integer modulo
            // operations for every bilinear tap (including anisotropic taps).
            int x0 = x < 0 ? level.Width - 1 : x, y0 = y < 0 ? level.Height - 1 : y;
            int x1 = x0 + 1 == level.Width ? 0 : x0 + 1, y1 = y0 + 1 == level.Height ? 0 : y0 + 1;
            int row0 = y0 * level.Width, row1 = y1 * level.Width;
            return Vector4.Lerp(Vector4.Lerp(level.Pixels[row0 + x0], level.Pixels[row0 + x1], fx),
                Vector4.Lerp(level.Pixels[row1 + x0], level.Pixels[row1 + x1], fx), fy);
        }
        internal Vector4 Anisotropic(float u, float v, float ux, float vx, float uy, float vy, int maximum) {
            var first = levels[0]; var dx = new Vector2(ux * first.Width, vx * first.Height); var dy = new Vector2(uy * first.Width, vy * first.Height);
            float sx = dx.LengthSquared(), sy = dy.LengthSquared();
            if (sx <= 1 && sy <= 1) return Sample(u, v, true);
            float lx = MathF.Sqrt(sx), ly = MathF.Sqrt(sy); bool alongX = lx > ly;
            float major = Math.Max(lx, ly), minor = Math.Max(1, Math.Min(lx, ly));
            int taps = Math.Clamp((int)MathF.Ceiling(major / minor), 1, maximum);
            float footprint = Math.Max(minor, major / taps);
            int mip = Math.Max(0, (int)MathF.Floor(MathF.Log2(Math.Max(1, footprint))));
            float du = alongX ? ux : uy, dv = alongX ? vx : vy; Vector4 sum = Vector4.Zero;
            for (int i = 0; i < taps; i++) { float offset = (i + .5f) / taps - .5f; sum += Sample(u + du * offset, v + dv * offset, true, mip); }
            return sum / taps;
        }
    }

    uint[] FxaaCharacter() {
        if (environmentFxaa == null) {
            environmentFxaa = (uint[])environmentColor.Clone();
            ApplyFxaa(environmentColor, environmentFxaa, renderWidth, renderHeight, 1, 1, renderWidth - 2, renderHeight - 2);
        }
        if (fxaaResult.Length != color.Length) fxaaResult = new uint[color.Length];
        environmentFxaa.CopyTo(fxaaResult, 0);
        // The directional span is clamped to eight pixels; the furthest sample
        // is half that span plus bilinear coverage. Six pixels includes all of
        // its support, so unchanged background pixels reuse exactly the same AA.
        ApplyFxaa(color, fxaaResult, renderWidth, renderHeight,
            Math.Max(1, characterLeft - 6), Math.Max(1, characterTop - 6),
            Math.Min(renderWidth - 2, characterRight + 6), Math.Min(renderHeight - 2, characterBottom + 6));
        Array.Copy(color, 0, fxaaResult, 0, renderWidth);
        Array.Copy(color, color.Length - renderWidth, fxaaResult, color.Length - renderWidth, renderWidth);
        for (int y = 0; y < renderHeight; y++) {
            int row = y * renderWidth;
            fxaaResult[row] = color[row]; fxaaResult[row + renderWidth - 1] = color[row + renderWidth - 1];
        }
        return fxaaResult;
    }

    // FXAA's luminance range and gradient direction determine subpixel samples.
    static void ApplyFxaa(uint[] source, uint[] result, int width, int height, int left, int top, int right, int bottom) {
        static float Luma(uint c) => ((c >> 16 & 255) * .299f + (c >> 8 & 255) * .587f + (c & 255) * .114f) / 255;
        for (int y = top; y <= bottom; y++) for (int x = left; x <= right; x++) {
            int p = y * width + x; float lm = Luma(source[p]);
            float nw = Luma(source[p - width - 1]), ne = Luma(source[p - width + 1]),
                sw = Luma(source[p + width - 1]), se = Luma(source[p + width + 1]);
            float low = Math.Min(lm, Math.Min(Math.Min(nw, ne), Math.Min(sw, se))), high = Math.Max(lm, Math.Max(Math.Max(nw, ne), Math.Max(sw, se)));
            if (high - low < Math.Max(.0312f, high * .125f)) { result[p] = source[p]; continue; }
            float dx = -((nw + ne) - (sw + se)), dy = (nw + sw) - (ne + se);
            float reduction = Math.Max((nw + ne + sw + se) * .03125f, .0078125f);
            float inverse = 1 / (Math.Min(Math.Abs(dx), Math.Abs(dy)) + reduction);
            dx = Math.Clamp(dx * inverse, -8, 8); dy = Math.Clamp(dy * inverse, -8, 8);
            Vector3 At(float t) => Unpack(SampleFrame(source, width, height, (x + .5f + dx * t) / width, (y + .5f + dy * t) / height, true));
            var a = (At(-1f / 6) + At(1f / 6)) * .5f;
            var b = a * .5f + (At(-.5f) + At(.5f)) * .25f;
            float lb = Vector3.Dot(b, new(.299f, .587f, .114f)); result[p] = Pack(lb < low || lb > high ? a : b);
        }
    }
    // Morphological edge search and neighborhood blending for the SMAA preview.
    // Analytic coverage weights replace the native backend's precomputed area LUT;
    // this is intentionally independent of, and not pixel-identical to, its GPU pass.
    uint[] MorphologicalAa(uint[] source, int width, int height) {
        if (morphologyResult.Length != source.Length) {
            morphologyResult = new uint[source.Length]; morphologyEdges = new byte[source.Length];
        }
        var edges = morphologyEdges; var result = morphologyResult;
        Array.Clear(edges); source.CopyTo(result, 0);
        static bool Different(uint a, uint b) {
            int r = (int)(a >> 16 & 255) - (int)(b >> 16 & 255),
                g = (int)(a >> 8 & 255) - (int)(b >> 8 & 255), bl = (int)(a & 255) - (int)(b & 255);
            // Exactly the same .12 RGB-distance threshold on 8-bit inputs,
            // compared squared to omit two normalizations and a square root.
            return r * r + g * g + bl * bl > 936;
        }
        for (int y = 1; y < height; y++) for (int x = 1; x < width; x++) {
            int p = y * width + x;
            if (Different(source[p], source[p - 1])) edges[p] |= 1;
            if (Different(source[p], source[p - width])) edges[p] |= 2;
        }
        for (int y = 1; y < height - 1; y++) for (int x = 1; x < width - 1; x++) {
            int p = y * width + x; if (edges[p] == 0) continue;
            Vector3 rgb = Unpack(source[p]); float total = 1;
            for (int axis = 0; axis < 2; axis++) {
                int bit = 1 << axis; if ((edges[p] & bit) == 0) continue;
                int stride = axis == 0 ? width : 1, bound = axis == 0 ? height : width, position = axis == 0 ? y : x;
                int a = 0, b = 0;
                while (a < 16 && position - a > 1 && (edges[p - (a + 1) * stride] & bit) != 0) a++;
                while (b < 16 && position + b < bound - 2 && (edges[p + (b + 1) * stride] & bit) != 0) b++;
                float coverage = .5f * (1 - Math.Abs(a - b) / (float)(a + b + 2));
                int across = axis == 0 ? 1 : width;
                rgb += Unpack(source[p - across]) * coverage; total += coverage;
                int other = p - across;
                result[other] = Pack(Vector3.Lerp(Unpack(result[other]), Unpack(source[p]), coverage * .5f));
            }
            result[p] = Pack(rgb / total);
        }
        return result;
    }

    void BuildEnvironment() {
        environmentTextures.Add(Surface(128, 128, true)); environmentTextures.Add(Surface(128, 128, false));
        environmentTextures.Add(new(2, 2, new byte[] { 33, 46, 43, 255, 38, 52, 48, 255, 38, 52, 48, 255, 33, 46, 43, 255 }));
        Quad(new(-5, 0, -5), new(-5, 0, 6), new(5, 0, 6), new(5, 0, -5), Vector3.UnitY, 0, 11, 10);
        Quad(new(-5, 0, -3), new(5, 0, -3), new(5, 3.5f, -3), new(-5, 3.5f, -3), Vector3.UnitZ, 1, 5, 2);
        Quad(new(-5, 0, 6), new(-5, 0, -3), new(-5, 3.5f, -3), new(-5, 3.5f, 6), Vector3.UnitX, 1, 4, 2);
        // A recessed service door and low wall skirting establish a room and scale.
        Box(new(-1.2f, .01f, -2.96f), new(1.2f, 2.65f, -2.82f), 2);
        Box(new(-1.32f, 0, -2.84f), new(-1.2f, 2.75f, -2.68f), 1);
        Box(new(1.2f, 0, -2.84f), new(1.32f, 2.75f, -2.68f), 1);
        Box(new(-1.32f, 2.65f, -2.84f), new(1.32f, 2.77f, -2.68f), 1);
        Box(new(-5, 0, -2.96f), new(5, .19f, -2.86f), 2);
        Box(new(-4.96f, 0, -3), new(-4.84f, .19f, 6), 2);
    }
    static PreviewTexture Surface(int width, int height, bool floor) {
        var rgba = new byte[width * height * 4]; uint noise = 0x76a391u;
        for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) {
            noise = noise * 1664525u + 1013904223u;
            int grain = (int)(noise >> 28) - 8;
            bool seam = floor ? x < 2 || y < 2 || x == 64 || y == 64 : y % 32 < 2 || (x + ((y / 32 & 1) * 32)) % 64 < 2;
            int level = (floor ? ((x / 64 + y / 64) % 2 == 0 ? 94 : 78) : 83) + grain;
            if (seam) level /= 2;
            int at = (y * width + x) * 4;
            rgba[at] = (byte)Math.Clamp(level, 0, 255); rgba[at + 1] = (byte)Math.Clamp(level + (floor ? 2 : 5), 0, 255);
            rgba[at + 2] = (byte)Math.Clamp(level + (floor ? 0 : 3), 0, 255); rgba[at + 3] = 255;
        }
        return new(width, height, rgba);
    }
    void Quad(Vector3 a, Vector3 b, Vector3 c, Vector3 d, Vector3 normal, int texture, float u = 1, float v = 1) =>
        environment.Add(new(new[] { a, b, c, d }, new[] { normal, normal, normal, normal },
            new[] { new Vector2(0, v), new Vector2(u, v), new Vector2(u, 0), new Vector2(0, 0) }, new[] { 0, 1, 2, 0, 2, 3 }, texture));
    void Box(Vector3 a, Vector3 b, int texture) {
        Quad(new(a.X, a.Y, b.Z), new(b.X, a.Y, b.Z), b, new(a.X, b.Y, b.Z), Vector3.UnitZ, texture);
        Quad(new(a.X, a.Y, a.Z), new(a.X, a.Y, b.Z), new(a.X, b.Y, b.Z), new(a.X, b.Y, a.Z), -Vector3.UnitX, texture);
        Quad(new(b.X, a.Y, b.Z), new(b.X, a.Y, a.Z), new(b.X, b.Y, a.Z), b, Vector3.UnitX, texture);
        Quad(new(a.X, b.Y, b.Z), b, new(b.X, b.Y, a.Z), new(a.X, b.Y, a.Z), Vector3.UnitY, texture);
    }
}
