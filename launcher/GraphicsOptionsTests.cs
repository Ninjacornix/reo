using System.Globalization;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class GraphicsOptionsTests {
    internal static void Run(Action<bool, string> check) {
        var culture = CultureInfo.CurrentCulture;
        try {
            CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo("hr-HR");
            foreach (string game in new[] { "file1", "file2" }) {
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
}
