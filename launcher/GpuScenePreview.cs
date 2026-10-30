using System.IO;
using System.Numerics;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

[StructLayout(LayoutKind.Sequential)]
internal struct GpuPreviewOptions {
    internal int InternalResolution, TextureLinear, Anisotropy, AntiAliasing, Aspect, Widescreen, ScreenFit, OutputLinear, Brightness;
    internal float Gamma;
    internal int WindowWidth, WindowHeight, Cover;
    internal float Yaw, Pitch, Zoom;
    internal float Opacity, BackgroundR, BackgroundG, BackgroundB;
    internal static GpuPreviewOptions From(PreviewRenderOptions o, float yaw, float pitch, float zoom = 1, float opacity = 1) => new() {
        InternalResolution = o.InternalResolution, TextureLinear = o.TextureLinear ? 1 : 0, Anisotropy = o.Anisotropy,
        AntiAliasing = o.AntiAliasing switch { "fxaa" => 1, "smaa" => 2, _ => 0 },
        Aspect = o.Aspect switch { "16:9" => 1, "21:9" => 2, "32:9" => 3, _ => 0 },
        Widescreen = o.Widescreen ? 1 : 0, ScreenFit = o.ScreenFit switch { "center" => 1, "stretch" => 2, "fill" => 3, _ => 0 },
        OutputLinear = o.LinearFilter ? 1 : 0, Brightness = o.Brightness, Gamma = (float)o.Gamma,
        WindowWidth = o.WindowWidth, WindowHeight = o.WindowHeight, Cover = o.CoverPreview ? 1 : 0, Yaw = yaw, Pitch = pitch, Zoom = zoom,
        Opacity = opacity, BackgroundR = Palette.Background.R / 255f,
        BackgroundG = Palette.Background.G / 255f, BackgroundB = Palette.Background.B / 255f
    };
}

[StructLayout(LayoutKind.Sequential)]
internal struct GpuPreviewStats {
    internal uint RenderWidth, RenderHeight, OutputWidth, OutputHeight;
    internal ulong FramesPresented;
    internal double GpuMilliseconds;
    internal uint FeatureLevel, Hardware;
}

internal sealed record GpuPreviewResult(PreviewFrame Frame, GpuPreviewStats Stats, bool Presented);

// GPU resources and the immediate context are used serially. Readback is explicit
// and reserved for diagnostics; production presents straight into the child HWND.
internal sealed class GpuScenePreview : IDisposable {
    const string Library = "Reo.GraphicsPreview";
    readonly object gate = new();
    nint device;
    volatile bool disposed;
    GamePreviewScene? loaded;
    int width, height;
    readonly List<MeshUpload> animated = new();
    internal string DeviceName { get; private set; } = "";
    sealed class MeshUpload {
        internal required PreviewMesh Source;
        internal required int Id;
        internal required float[] Positions, Normals;
    }
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern nint reo_preview_create(nint window);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern void reo_preview_destroy(nint handle);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_resize(nint handle, int width, int height);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_frame_ready(nint handle);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern void reo_preview_clear_scene(nint handle);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_create_texture(nint handle, int width, int height, [In] byte[] rgba);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_create_mesh(nint handle,
        [In] float[] positions, [In] float[] normals, [In] float[] uv, int vertices, [In] int[] indices, int count, int texture, int character);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_update_mesh(nint handle, int mesh, [In] float[] positions, [In] float[] normals);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_render(nint handle, in GpuPreviewOptions options);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_readback(nint handle, [Out] byte[] bgra, int count);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern int reo_preview_get_stats(nint handle, out GpuPreviewStats stats);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern nint reo_preview_device_name(nint handle);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] static extern nint reo_preview_last_error();

    static IOException Error() => new(Marshal.PtrToStringUTF8(reo_preview_last_error()) ?? "The GPU preview failed.");
    static void Check(int result) { if (result <= 0) throw Error(); }

    internal GpuPreviewResult Render(nint window, GamePreviewScene scene, IReadOnlyList<PreviewMesh> room,
        IReadOnlyList<PreviewTexture> roomTextures, PreviewRenderOptions options, double seconds,
        int outputWidth, int outputHeight, float yaw, float pitch, float zoom, bool readback, float opacity = 1) {
        lock (gate) {
            if (disposed) throw new OperationCanceledException();
            if (device == 0) {
                device = reo_preview_create(window);
                if (device == 0) throw Error();
                DeviceName = Marshal.PtrToStringUTF8(reo_preview_device_name(device)) ?? "Direct3D 11 GPU";
                if (disposed) { Destroy(); throw new OperationCanceledException(); }
            }
            if (width != outputWidth || height != outputHeight) {
                Check(reo_preview_resize(device, outputWidth, outputHeight)); width = outputWidth; height = outputHeight;
            }
            if (!readback) {
                int ready = reo_preview_frame_ready(device);
                if (ready < 0) throw Error();
                if (ready == 0) {
                    Check(reo_preview_get_stats(device, out var pending));
                    return new(new(width, height, Array.Empty<byte>(), (int)pending.RenderWidth, (int)pending.RenderHeight), pending, false);
                }
            }
            var center = new Vector3((scene.Minimum.X + scene.Maximum.X) / 2, scene.Minimum.Y,
                (scene.Minimum.Z + scene.Maximum.Z) / 2);
            float scale = 1.8f / (scene.Maximum.Y - scene.Minimum.Y);
            scene.Animate(seconds);
            if (loaded != scene) {
                reo_preview_clear_scene(device); animated.Clear(); loaded = null;
                var environmentTextures = roomTextures.Select(t => Texture(t)).ToArray();
                foreach (var mesh in room) Upload(mesh, environmentTextures, false, Vector3.Zero, 1);
                var textures = scene.Textures.Select(t => Texture(t)).ToArray();
                foreach (var mesh in scene.Meshes) Upload(mesh, textures, true, center, scale);
                loaded = scene;
            } else {
                foreach (var mesh in animated) {
                    Fill(mesh.Source, mesh.Positions, mesh.Normals, center, scale);
                    Check(reo_preview_update_mesh(device, mesh.Id, mesh.Positions, mesh.Normals));
                }
            }
            int rendered = reo_preview_render(device, GpuPreviewOptions.From(options, yaw, pitch, zoom, opacity));
            Check(rendered);
            Check(reo_preview_get_stats(device, out var stats));
            if (stats.Hardware == 0) throw new IOException("The preview did not create a hardware GPU device.");
            byte[] pixels = readback ? new byte[checked(width * height * 4)] : Array.Empty<byte>();
            if (readback) Check(reo_preview_readback(device, pixels, pixels.Length));
            return new(new(width, height, pixels, (int)stats.RenderWidth, (int)stats.RenderHeight), stats, rendered == 1);
        }
    }
    int Texture(PreviewTexture texture) {
        int id = reo_preview_create_texture(device, texture.Width, texture.Height, texture.Rgba);
        if (id < 0) throw Error(); return id;
    }
    void Upload(PreviewMesh mesh, int[] textures, bool character, Vector3 center, float scale) {
        var positions = new float[mesh.Positions.Length * 3]; var normals = new float[positions.Length];
        Fill(mesh, positions, normals, center, scale);
        var uv = new float[mesh.Positions.Length * 2];
        for (int i = 0; i < mesh.TexCoords.Length; i++) { uv[i * 2] = mesh.TexCoords[i].X; uv[i * 2 + 1] = mesh.TexCoords[i].Y; }
        int texture = mesh.TextureIndex >= 0 && mesh.TextureIndex < textures.Length ? textures[mesh.TextureIndex] : -1;
        int id = reo_preview_create_mesh(device, positions, normals, uv, mesh.Positions.Length, mesh.Indices, mesh.Indices.Length, texture, character ? 1 : 0);
        if (id < 0) throw Error();
        if (character) animated.Add(new() { Source = mesh, Id = id, Positions = positions, Normals = normals });
    }
    static void Fill(PreviewMesh mesh, float[] positions, float[] normals, Vector3 center, float scale) {
        for (int i = 0; i < mesh.Positions.Length; i++) {
            var p = (mesh.Positions[i] - center) * scale;
            var n = i < mesh.Normals.Length ? mesh.Normals[i] : Vector3.UnitY;
            int at = i * 3;
            positions[at] = p.X; positions[at + 1] = p.Y; positions[at + 2] = p.Z;
            normals[at] = n.X; normals[at + 1] = n.Y; normals[at + 2] = n.Z;
        }
    }
    void Destroy() { if (device != 0) { reo_preview_destroy(device); device = 0; } loaded = null; animated.Clear(); }
    public void Dispose() {
        disposed = true;
        // Never block the UI thread on DXGI creation/presentation: DXGI may be
        // waiting for that thread to process a window message.
        if (Monitor.TryEnter(gate)) { try { Destroy(); } finally { Monitor.Exit(gate); } }
        else _ = Task.Run(() => { lock (gate) Destroy(); });
    }
}
