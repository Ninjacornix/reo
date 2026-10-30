using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

public partial class MainWindow {
    async Task TestPlayLayout(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        var samples = new List<object>();
        var shifts = new Dictionary<string, double>();
        bool fallbackSeen = false;
        void Check(bool valid, string name) { if (!valid) throw new IOException(name); checks.Add(name); }
        string Font() => ((FontFamily)Application.Current.Resources["GameDisplayFont"]).Source;
        Dictionary<string, double> Bounds() {
            UpdateLayout();
            return new FrameworkElement[] { NavPlay, NavGraphics, UpdateButton, NextStep, GameCasePicker,
                GameCard1, GameCard2, PlayNetworkSummary, PlayDisplaySummary, PlayInputSummary,
                PlayModsSummary, PlayCheatsSummary, LauncherFooter, LaunchButton }
                .ToDictionary(e => e.Name, e => e.TranslatePoint(new Point(), this).Y);
        }
        void Capture(string name) {
            var image = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            image.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(image));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Play layout diagnostics use an isolated settings home");
            timer.Stop(); settings.LauncherBackgroundMovies = false;
            GamePicker.SelectedValue = "file1"; ShowPage("Play");
            for (int i = 0; i < 200 && !Font().Contains(GameFont.FamilyName); i++) await Task.Delay(50);
            Check(Font().Contains(GameFont.FamilyName), "The owned game font is loaded before measuring switches");
            foreach (bool compact in new[] { false, true }) {
                Width = compact ? MinWidth : 1320; Height = compact ? MinHeight : 920;
                await Task.Delay(200);
                var baseline = Bounds();
                for (int selection = 0; selection < 6; selection++) {
                    string edition = selection % 2 == 0 ? "file2" : "file1";
                    var item = (ListBoxItem)(selection < 3 ? GamePicker : GameCasePicker).Items[selection % 2 == 0 ? 1 : 0];
                    if (selection >= 3) item.Focus();
                    item.IsSelected = true;
                    for (int sample = 0; sample < 12; sample++) {
                        var bounds = Bounds();
                        fallbackSeen |= !Font().Contains(GameFont.FamilyName);
                        foreach (var (name, position) in bounds) {
                            string key = (compact ? "compact/" : "normal/") + name;
                            shifts[key] = Math.Max(shifts.GetValueOrDefault(key), Math.Abs(position - baseline[name]));
                        }
                        samples.Add(new { compact, edition, sample, font = Font(), bounds,
                            scrollOffset = SettingsScroll.VerticalOffset, notice = NextStepTitle.Text,
                            noticeVisible = NextStep.Visibility == Visibility.Visible });
                        await Task.Delay(16);
                    }
                    Check(settings.Game.Id == edition, "Actual " + (selection < 3 ? "footer" : "case") + " selection switches to " + edition);
                    if (selection >= 3) {
                        Check(item.Template.FindName("DiscFocus", item) == null && item.FocusVisualStyle == null,
                            "Focused " + edition + " case has no white rectangular outline");
                        if (!compact && edition == "file2") Capture("focused-file2-case");
                    }
                }
                Capture(compact ? "compact-play" : "normal-play");
                if (compact) {
                    SettingsScroll.ScrollToEnd(); UpdateLayout();
                    var bottom = PlayDisplaySummary.TranslatePoint(new Point(0, PlayDisplaySummary.ActualHeight), SettingsScroll);
                    Check(SettingsScroll.ScrollableHeight > 0 && bottom.Y <= SettingsScroll.ViewportHeight + 1,
                        "The complete Play summary remains reachable in a compact window");
                    Capture("compact-play-scrolled");
                    double offset = SettingsScroll.VerticalOffset;
                    ShowPage("Audio"); await Task.Delay(250);
                    SettingsScroll.ScrollToTop(); UpdateLayout();
                    ShowPage("Play"); await Task.Delay(250); UpdateLayout();
                    Check(Math.Abs(SettingsScroll.VerticalOffset - offset) <= 1,
                        "Returning to Play preserves its own scroll position");
                    SettingsScroll.ScrollToTop(); UpdateLayout();
                }
            }
            int movieArgument = Array.IndexOf(args, "--play-layout-clips");
            if (movieArgument >= 0 && movieArgument + 1 < args.Length) {
                string[] clips = Directory.GetFiles(args[movieArgument + 1], "*.mp4").OrderBy(p => p).Take(2).ToArray();
                Check(clips.Length == 2, "Two local movie clips are available for the crossfade layout check");
                Width = 1320; Height = 920; await Task.Delay(200);
                var baseline = Bounds();
                backgroundPlayer!.Suspend(false); backgroundPlayer.SetPlaylist("file1", clips);
                for (int i = 0; i < 300 && (!backgroundPlayer.HasVideo || backgroundPlayer.IsBlending); i++) await Task.Delay(50);
                Check(backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending, "The actual background video player opens the local clip");
                int transitions = backgroundPlayer.Transitions;
                foreach (var player in new[] { BackgroundMovieA, BackgroundMovieB })
                    if (player.Source != null && player.NaturalDuration.HasTimeSpan)
                        player.Position = player.NaturalDuration.TimeSpan - TimeSpan.FromSeconds(.5);
                for (int i = 0; i < 400; i++) {
                    var bounds = Bounds();
                    foreach (var (name, position) in bounds) {
                        string key = "movie/" + name;
                        shifts[key] = Math.Max(shifts.GetValueOrDefault(key), Math.Abs(position - baseline[name]));
                    }
                    if (backgroundPlayer.Transitions > transitions && !backgroundPlayer.IsBlending) break;
                    await Task.Delay(25);
                }
                Check(backgroundPlayer.Transitions > transitions && !backgroundPlayer.IsBlending,
                    "A real movie crossfade completes without moving Play controls");
                Capture("movie-crossfade-play"); backgroundPlayer.Suspend(true);
            }
            Check(!fallbackSeen, "Switching games never replaces the loaded UI font with the fallback font");
            foreach (var (name, distance) in shifts)
                Check(distance <= 1, name + " remains steady throughout edition switching");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = true, checks, fallbackSeen, shifts, samples }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = false, checks, fallbackSeen, shifts, samples, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            timer.Stop(); Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
        }
    }
}
