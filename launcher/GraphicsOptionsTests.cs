using System.Globalization;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class GraphicsOptionsTests {
    internal static void Run(Action<bool, string> check) {
        MovieDefaults(check);
        var culture = CultureInfo.CurrentCulture;
        try {
            CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo("hr-HR");
            check(GraphicsOptions.From(new Settings()).Environment["REO_VSYNC"] == "on",
                  "Existing settings default to synchronized presentation");
            foreach (string game in new[] { "file1", "file2" }) {
                foreach (string? mode in new string?[] { "on", "off", "adaptive", "invalid", null }) {
                    var saved = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                        new Settings { SelectedGame = game, VSync = mode! }))!;
                    var captured = GraphicsOptions.From(saved);
                    saved.VSync = "off";
                    check(captured.Environment["REO_VSYNC"] ==
                              (mode is "off" or "adaptive" ? mode : "on"),
                          game + " persists and captures VSync with safe fallback");
                }
                var settings = new Settings {
                    SelectedGame = game, Fullscreen = true, WindowSize = 6,
                    InternalResolution = 4, AspectRatio = "16:9", ScreenFit = "fill",
                    LinearFilter = false, TextureLinear = true, Anisotropy = 16,
                    AntiAliasingMode = "smaa", Brightness = 125, Gamma = 1.25,
                    AsyncVif = false, GpuMovies = false, PerformanceOverlay = true
                };
                // Exercise the saved-settings boundary too, including Croatian decimal formatting.
                settings = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
                var launch = GraphicsOptions.From(settings);
                var expected = new Dictionary<string, string> {
                    ["REO_VIF1_ASYNC"] = "0", ["REO_DISPLAY_ASPECT"] = "16:9",
                    ["REO_DISPLAY_FIT"] = "fill", ["REO_DISPLAY_FILTER"] = "nearest",
                    ["REO_WINDOW_WIDTH"] = "3840", ["REO_WINDOW_HEIGHT"] = "2160",
                    ["REO_TEXTURE_FILTER"] = "linear", ["REO_INTERNAL_RESOLUTION"] = "4",
                    ["REO_PERFORMANCE_OVERLAY"] = "1", ["REO_GPU_MEMORY_LOG"] = "1",
                    ["REO_TEXTURE_ANISOTROPY"] = "16", ["REO_POST_AA"] = "smaa",
                    ["REO_BRIGHTNESS"] = "1.25", ["REO_GAMMA"] = "1.25"
                };
                check(expected.All(p => launch.Environment.GetValueOrDefault(p.Key) == p.Value),
                      game + " saved graphics settings reach the renderer contract");
                check(launch.Fullscreen && launch.Output == new OutputSize(3840, 2160) && !launch.GpuMovies,
                      game + " captures window and movie settings");
                settings.Fullscreen = false;
                settings.WindowSize = 7;
                settings.Gamma = 0.5;
                settings.InternalResolution = 1;
                settings.AntiAliasing = false;
                var next = GraphicsOptions.From(settings);
                check(launch.Fullscreen && launch.Output.Width == 3840 && launch.Environment["REO_GAMMA"] == "1.25"
                      && next.Output.Width == 512 && next.Environment["REO_POST_AA"] == "off"
                      && next.Environment["REO_INTERNAL_RESOLUTION"] == "1",
                      game + " next-launch edits cannot alter a launch already preparing");
                foreach (int scale in DisplayOptions.InternalScales)
                foreach (string fit in DisplayOptions.Fits)
                foreach (string aa in new[] { "off", "fxaa", "smaa" }) {
                    settings.InternalResolution = scale;
                    settings.ScreenFit = fit;
                    settings.AntiAliasing = aa != "off";
                    settings.AntiAliasingMode = aa;
                    var options = GraphicsOptions.From(settings).Environment;
                    check(options["REO_INTERNAL_RESOLUTION"] == scale.ToString(CultureInfo.InvariantCulture)
                          && options["REO_DISPLAY_FIT"] == fit && options["REO_POST_AA"] == aa,
                          game + " supports every internal scale, fit and anti-aliasing selection");
                }
            }
            check(GameSession.GraphicsExitDiagnostic("[BOOT] OpenGL 3.3 is unavailable; not opening the game window.")
                  ?.Contains("Install the graphics driver", StringComparison.Ordinal) == true,
                  "Missing OpenGL is identified as a graphics driver error");
            check(GameSession.GraphicsExitDiagnostic("[GPU-MOVIE] failure boundary=nativeMovieQuiescent detail=Create same-adapter native MPEG decoder")
                  ?.Contains("turn off Decode movies on the graphics card", StringComparison.Ordinal) == true,
                  "An actual Direct3D movie decoder failure points to CPU decoding");
            check(GameSession.GraphicsExitDiagnostic("[run] graphics backend failure: Native DXGI swapchain unavailable; orderly shutdown requested")
                  ?.Contains("graphics backend failed", StringComparison.Ordinal) == true,
                  "An orderly graphics backend shutdown is reported as a failure");
            check(GameSession.GraphicsExitDiagnostic("No D3D11 video device") == null &&
                  GameSession.GraphicsExitDiagnostic("[GS-BACKEND] requested=parallel selected=software reason=Vulkan device initialization failed") == null,
                  "Optional capabilities and normal software fallback are not reported as fatal errors");
            var invalid = GraphicsOptions.From(new Settings {
                InternalResolution = 3, Anisotropy = 7, Brightness = 999,
                Gamma = double.NaN, AspectRatio = "invalid", ScreenFit = "invalid"
            });
            check(invalid.Environment["REO_INTERNAL_RESOLUTION"] == "1"
                  && invalid.Environment["REO_TEXTURE_ANISOTROPY"] == "1"
                  && invalid.Environment["REO_BRIGHTNESS"] == "1.50"
                  && invalid.Environment["REO_GAMMA"] == "1.00"
                  && invalid.Environment["REO_DISPLAY_ASPECT"] == "4:3"
                  && invalid.Environment["REO_DISPLAY_FIT"] == "fit", "Invalid graphics values have safe renderer defaults");
        } finally { CultureInfo.CurrentCulture = culture; }
    }
    static void MovieDefaults(Action<bool, string> check) {
        var verified = new MovieDecoderChoice(true, "Verified GPU", "Hardware MPEG-2 decoder available");
        var cpuDefaults = new[] {
            new MovieDecoderChoice(false, "NVIDIA", "REO GPU movies can crash"),
            new MovieDecoderChoice(false, "Intel", "REO GPU movies are untested"),
            new MovieDecoderChoice(false, "", "Movie decoder check is missing"),
            new MovieDecoderChoice(false, "GPU", "No compatible MPEG-2 decoder")
        };
        var legacyOn = JsonSerializer.Deserialize<Settings>("{\"GpuMovies\":true}")!;
        var legacyOff = JsonSerializer.Deserialize<Settings>("{\"GpuMovies\":false}")!;
        check(legacyOn.GpuMoviesChoice == null && verified.UseGpu(legacyOn.GpuMovies, legacyOn.GpuMoviesChoice),
              "Verified GPUs keep the checked legacy default");
        check(!verified.UseGpu(legacyOff.GpuMovies, legacyOff.GpuMoviesChoice),
              "Saved CPU choices are not automatically upgraded to GPU");
        foreach (var cpu in cpuDefaults) {
            check(!cpu.UseGpu(legacyOn.GpuMovies, legacyOn.GpuMoviesChoice),
                  cpu.GpuName + " previously gated CPU playback stays on CPU after migration");
            check(cpu.UseGpu(false, true), cpu.GpuName + " can be explicitly opted into GPU decoding");
        }
        foreach (var probe in cpuDefaults.Append(verified)) {
            check(!probe.UseGpu(true, false), "Explicit CPU decoding wins over every probe result");
            var selected = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                new Settings { GpuMovies = true, GpuMoviesChoice = true }))!;
            var launch = GraphicsOptions.From(selected);
            selected.GpuMoviesChoice = false;
            check(probe.UseGpu(launch.GpuMovies, launch.GpuMoviesChoice),
                  "Explicit GPU choice round-trips and is captured before asynchronous launch setup");
        }
        var unrelatedSave = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(legacyOn))!;
        check(unrelatedSave.GpuMoviesChoice == null,
              "Saving unrelated settings does not turn the legacy default into an explicit GPU choice");
    }
}
