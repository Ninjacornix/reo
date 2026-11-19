using System.Globalization;

namespace Outbreak.Launcher;

// Both editions consume the same renderer options. Capture before asynchronous
// disc setup so edits made for the next launch cannot change this launch halfway.
internal sealed record GraphicsOptions(bool Fullscreen, OutputSize Output, bool GpuMovies, bool? GpuMoviesChoice,
                                        IReadOnlyDictionary<string, string> Environment) {
    internal static GraphicsOptions From(Settings settings) {
        var size = DisplayOptions.Size(settings.WindowSize);
        string Number(int value) => value.ToString(CultureInfo.InvariantCulture);
        string Decimal(double value) => value.ToString("F2", CultureInfo.InvariantCulture);
        var environment = new Dictionary<string, string> {
            ["REO_VIF1_ASYNC"] = settings.AsyncVif ? "1" : "0",
            // Replay-validated compiled VU1 programs before partial native kernels (File #1).
            ["REO_VU_WHOLE_FIRST"] = "1",
            // Peers must share one update rate, so online sessions stay at the original 30 Hz.
            ["REO_GAME_RATE"] = settings.GameRate60 && settings.ResolvedCoopMode == "offline" ? "60" : "30",
            ["REO_DISPLAY_ASPECT"] = settings.ResolvedAspect,
            ["REO_WIDESCREEN"] = settings.ResolvedWidescreen ? "1" : "0",
            ["REO_DISPLAY_FIT"] = settings.ResolvedFit,
            ["REO_VSYNC"] = settings.ResolvedVSync,
            ["REO_DISPLAY_FILTER"] = settings.LinearFilter ? "linear" : "nearest",
            ["REO_WINDOW_WIDTH"] = Number(size.Width),
            ["REO_WINDOW_HEIGHT"] = Number(size.Height),
            ["REO_TEXTURE_FILTER"] = settings.TextureLinear ? "linear" : "original",
            ["REO_INTERNAL_RESOLUTION"] = Number(settings.ResolvedInternalResolution),
            ["REO_PERFORMANCE_OVERLAY"] = settings.PerformanceOverlay ? "1" : "0",
            ["REO_GPU_MEMORY_LOG"] = settings.ResolvedInternalResolution > 1 ? "1" : "0",
            ["REO_TEXTURE_ANISOTROPY"] = Number(settings.ResolvedAnisotropy),
            ["REO_POST_AA"] = settings.ResolvedAntiAliasing,
            ["REO_BRIGHTNESS"] = Decimal(Math.Clamp(settings.Brightness, 50, 150) / 100.0),
            ["REO_GAMMA"] = Decimal(
                double.IsFinite(settings.Gamma) ? Math.Clamp(settings.Gamma, 0.5, 2.0) : 1.0)
        };
        return new(settings.Fullscreen, size, settings.GpuMovies, settings.GpuMoviesChoice, environment);
    }
}
