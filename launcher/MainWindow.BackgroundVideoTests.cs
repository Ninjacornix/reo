using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

public partial class MainWindow {
    async Task TestBackgroundPlayback(string output) {
        if (args.Contains("--measure-background-performance")) {
            await MeasureBackgroundPerformance(output);
            return;
        }
        var checks = new List<string>();
        Directory.CreateDirectory(output);
        void Check(bool valid, string message) {
            if (!valid) throw new IOException(message + ": " + backgroundPlayer?.LastError);
            checks.Add(message);
        }
        async Task Until(Func<bool> condition, int seconds = 20) {
            var clock = Stopwatch.StartNew();
            while (!condition()) {
                if (clock.Elapsed.TotalSeconds > seconds) throw new IOException("Background playback timed out: " + backgroundPlayer?.LastError);
                await Task.Delay(50);
            }
        }
        RenderTargetBitmap Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var png = new PngBitmapEncoder();
            png.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png"));
            png.Save(file);
            return bitmap;
        }
        try {
            Check(SystemParameters.ClientAreaAnimation, "Windows animations enabled for playback verification");
            GamePicker.SelectedValue = "file1";
            RefreshBackgroundVideos();
            await Until(() => backgroundPlayer?.Game == "file1" && backgroundPlayer.HasVideo && backgroundPlayer.Position > 2);
            Check(backgroundPlayer!.CurrentFile.StartsWith(settings.ImportedFile1, StringComparison.OrdinalIgnoreCase), "File #1 plays its own extracted clip");
            if (args.Contains("--test-background-setting")) {
                await LoadArtworkAsync();
                LauncherBackgroundMovies.IsChecked = false;
                Check(!backgroundPlayer.HasVideo && BackgroundMovieA.Source == null && BackgroundMovieB.Source == null,
                    "Disabling background movies immediately closes both decoders");
                Check(Backdrop.Source != null && ArtworkLayer.Visibility == Visibility.Visible && ImageBackgroundShade.Visibility == Visibility.Visible && VideoBackgroundShade.Visibility == Visibility.Collapsed,
                    "Disabling movies restores the normal placeholder image");
                Check(JsonSerializer.Deserialize<Settings>(File.ReadAllText(Path.Combine(Settings.Home, "settings.json")))!.LauncherBackgroundMovies == false,
                    "Disabled preference is saved to settings");
                GamePicker.SelectedValue = "file2";
                await Task.Delay(500);
                Check(!backgroundPlayer.HasVideo && backgroundPreparations.Count == 0 && BackgroundVideoActivity.Visibility == Visibility.Collapsed,
                    "Switching games while disabled does not prepare or play movies");
                Capture("movies-disabled");
                LauncherBackgroundMovies.IsChecked = true;
                await Until(() => backgroundPlayer.Game == "file2" && backgroundPlayer.HasVideo && backgroundPlayer.Position > 1);
                Check(settings.LauncherBackgroundMovies, "Re-enabling movies resumes playback for the selected edition");
                LauncherBackgroundMovies.IsChecked = false;
                await File.WriteAllTextAsync(Path.Combine(output, "playback-result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
                return;
            }
            Check(new[] { BackgroundMovieA, BackgroundMovieB }.All(p => p.IsMuted && p.Volume == 0 && !p.IsHitTestVisible && !p.Focusable),
                  "Both video surfaces are muted, passive and excluded from keyboard focus");
            if (args.Contains("--test-background-game-lifecycle")) {
                foreach (string edition in new[] { "file1", "file2" }) {
                    GamePicker.SelectedValue = edition;
                    await Until(() => backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending && backgroundPlayer.Position > 1);
                    string savedClip = backgroundPlayer.CurrentFile;
                    double savedPosition = backgroundPlayer.Position;
                    bool Closed() => !backgroundPlayer.HasVideo && BackgroundMovieA.Source == null && BackgroundMovieB.Source == null;
                    SetLaunching(true);
                    Check(Closed(), edition + " launch preparation immediately closes both video decoders");
                    await Task.Delay(500);
                    Check(Closed(), edition + " stays suspended while preparing the game");
                    SetLaunching(false); // A failed or canceled launch never creates a game process.
                    await Until(() => backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending);
                    Check(backgroundPlayer.CurrentFile == savedClip && backgroundPlayer.Position >= savedPosition - .75,
                          edition + " canceled launch resumes the saved clip");

                    savedPosition = backgroundPlayer.Position;
                    SetLaunching(true);
                    // A private child waits for input until the test ends its session.
                    // Use the real Running property and UI polling, with no commercial game needed.
                    using var child = Process.Start(new ProcessStartInfo(Path.Combine(Environment.SystemDirectory, "cmd.exe")) {
                        ArgumentList = { "/d", "/c", "set /p REO_BACKGROUND_TEST=" },
                        UseShellExecute = false, CreateNoWindow = true,
                        RedirectStandardInput = true, RedirectStandardOutput = true, RedirectStandardError = true
                    })!;
                    var processProperty = typeof(GameSession).GetProperty(nameof(GameSession.Process))!;
                    try {
                        processProperty.SetValue(game, child);
                        SetLaunching(false); // Preparation is over; the game is still alive.
                        await Until(() => previousRunning);
                        Check(game.Running && Closed(), edition + " running game keeps both decoders closed");
                        ShowPage("Graphics");
                        ShowPage("Play");
                        WindowState = WindowState.Minimized;
                        WindowState = WindowState.Normal;
                        await Task.Delay(1500);
                        Check(game.Running && Closed(), edition + " navigation and window restore cannot restart videos during gameplay");
                        using (File.Open(savedClip, FileMode.Open, FileAccess.Read, FileShare.None)) { }
                        Check(true, edition + " movie is released for exclusive access during gameplay");
                        await child.StandardInput.WriteLineAsync("finished");
                        child.StandardInput.Close();
                        await child.WaitForExitAsync();
                        await Until(() => !previousRunning && backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending);
                        Check(child.ExitCode == 0 && backgroundPlayer.CurrentFile == savedClip &&
                              backgroundPlayer.Position >= savedPosition - .75,
                              edition + " game exit automatically resumes the saved clip without navigation");
                    } finally {
                        if (!child.HasExited) { child.Kill(); await child.WaitForExitAsync(); }
                        previousRunning = false;
                        processProperty.SetValue(game, null);
                        SetLaunching(false);
                    }
                }
                await File.WriteAllTextAsync(Path.Combine(output, "playback-result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
                return;
            }
            Capture("file1");
            double navigationPosition = backgroundPlayer.Position;
            ShowPage("Graphics");
            await Task.Delay(350);
            Check(PageGraphics.Visibility == Visibility.Visible && OutgoingPage.Source == null && !backgroundPlayer.HasVideo &&
                  BackgroundMovieA.Source == null && BackgroundMovieB.Source == null && BackgroundScene.Visibility == Visibility.Collapsed,
                  "Graphics uses the solid background and closes both video decoders");
            Capture("graphics-solid-background");
            foreach (string page in new[] { "Audio", "Controller", "Saves", "Coop", "Mods", "Cheats", "Setup", "Logs", "Developer" }) {
                ShowPage(page);
                await Until(() => currentPage == page && !pageTransition);
                Check(BackgroundScene.Visibility == Visibility.Collapsed && !backgroundPlayer.HasVideo &&
                      BackgroundMovieA.Source == null && BackgroundMovieB.Source == null,
                      page + " uses the solid background without video playback");
            }
            ShowPage("Play");
            await Until(() => backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending);
            Check(backgroundPlayer.Position >= navigationPosition - 0.75 && backgroundPlayer.Position < navigationPosition + 3 &&
                  PagePlay.Visibility == Visibility.Visible && BackgroundScene.Visibility == Visibility.Visible,
                  "Returning to Play restores the video at its saved timestamp");
            await Until(() => backgroundPlayer.Transitions > 0 || backgroundPlayer.IsBlending, 45);
            await Until(() => backgroundPlayer.IsBlending, 45);
            Capture("crossfade");
            await Until(() => !backgroundPlayer.IsBlending);
            Check(backgroundPlayer.Transitions > 0, "Clips crossfade automatically without seeking controls");
            await Until(() => backgroundPlayer.Position >= 4);
            string firstClip = backgroundPlayer.CurrentFile;
            double firstPosition = backgroundPlayer.Position;

            GamePicker.SelectedValue = "file2";
            Check(backgroundPlayer.Game == "file2" && !backgroundPlayer.CurrentFile.StartsWith(settings.ImportedFile1, StringComparison.OrdinalIgnoreCase),
                  "Game selection immediately releases the other edition's video");
            await Until(() => backgroundPlayer.HasVideo && backgroundPlayer.Position > 2);
            Check(backgroundPlayer.CurrentFile.StartsWith(settings.ImportedFile2, StringComparison.OrdinalIgnoreCase), "File #2 plays its own extracted clip");
            var frame = Capture("file2");
            await Task.Delay(1500);
            var later = Capture("file2-motion");
            var area = new Int32Rect(950, 150, 250, 350);
            var pixels = new byte[area.Width * area.Height * 4];
            var laterPixels = new byte[pixels.Length];
            frame.CopyPixels(area, pixels, area.Width * 4, 0);
            later.CopyPixels(area, laterPixels, area.Width * 4, 0);
            Check(!pixels.SequenceEqual(laterPixels), "Rendered background frames advance while launcher controls remain idle");
            double secondPosition = backgroundPlayer.Position;
            string secondClip = backgroundPlayer.CurrentFile;
            GamePicker.SelectedValue = "file1";
            await Until(() => backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending);
            Check(backgroundPlayer.CurrentFile == firstClip && backgroundPlayer.Position >= firstPosition - 0.75 &&
                  backgroundPlayer.Position < firstPosition + 3,
                  "Switching back to File #1 resumes the same clip and timestamp");
            GamePicker.SelectedValue = "file2";
            await Until(() => backgroundPlayer.HasVideo && !backgroundPlayer.IsBlending);
            Check(backgroundPlayer.CurrentFile == secondClip && backgroundPlayer.Position >= secondPosition - 0.75 &&
                  backgroundPlayer.Position < secondPosition + 3,
                  "Switching back to File #2 resumes its independent timestamp");
            bool handled = false;
            SizeMoveHook(IntPtr.Zero, WM_ENTERSIZEMOVE, IntPtr.Zero, IntPtr.Zero, ref handled);
            await Task.Delay(300);
            double heldPosition = backgroundPlayer.Position;
            await Task.Delay(1000);
            Check(backgroundPlayer.HasVideo && Math.Abs(backgroundPlayer.Position - heldPosition) < 0.1,
                  "Moving or resizing the window holds the movie on its current frame");
            SizeMoveHook(IntPtr.Zero, WM_EXITSIZEMOVE, IntPtr.Zero, IntPtr.Zero, ref handled);
            await Until(() => backgroundPlayer.Position > heldPosition + 0.5);
            Check(backgroundPlayer.CurrentFile == secondClip, "Ending the move continues the same clip from the held frame");
            int before = backgroundPlayer.Transitions;
            await Until(() => backgroundPlayer.Transitions > before, 40);
            Check(backgroundPlayer.CurrentFile.EndsWith("demo-2.mp4", StringComparison.OrdinalIgnoreCase),
                  "File #2 also crossfades into its second demonstration clip");
            double minimizedPosition = backgroundPlayer.Position;
            string minimizedClip = backgroundPlayer.CurrentFile;
            WindowState = WindowState.Minimized;
            Check(!backgroundPlayer.HasVideo && BackgroundMovieA.Source == null && BackgroundMovieB.Source == null,
                  "Minimizing closes both decoders and releases movie files");
            WindowState = WindowState.Normal;
            await Until(() => backgroundPlayer.HasVideo && backgroundPlayer.Position > 1);
            Check(backgroundPlayer.Game == "file2", "Restoring resumes the selected game's playlist");
            Check(backgroundPlayer.CurrentFile == minimizedClip && backgroundPlayer.Position >= minimizedPosition - 0.75,
                  "Minimizing also preserves the current clip and timestamp");

            // Exercise decoder failure without altering the user's cache or media.
            backgroundRemoving = true;
            backgroundPlayer.SetPlaylist("file2", new[] { Path.Combine(output, "missing.mp4") });
            await Until(() => backgroundPlayer.LastError.Length != 0);
            await LoadArtworkAsync();
            UpdateArtworkVisibility();
            Check(!backgroundPlayer.HasVideo, "An unplayable movie falls back without interrupting the launcher");
            Check(Backdrop.Source != null && ArtworkLayer.Visibility == Visibility.Visible,
                  "Existing image remains visible when a movie cannot play");
            Capture("image-fallback");
            backgroundPlayer.SetPlaylist("file2", Array.Empty<string>());
            Check(BackgroundMovieA.Source == null && BackgroundMovieB.Source == null, "Empty playlist releases all media for game removal");
            // Exclusive opens prove the player no longer holds the prepared movies.
            foreach (string game in new[] { "file1", "file2" }) {
                var paths = await BackgroundVideos.ReadCache(BackgroundVideos.Folder(settings.ImportFolder(game)), game, default);
                foreach (string path in paths) using (File.Open(path, FileMode.Open, FileAccess.Read, FileShare.None)) { }
            }
            checks.Add("Prepared movies can be opened exclusively after playback stops");
            await File.WriteAllTextAsync(Path.Combine(output, "playback-result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "playback-result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally { Close(); }
    }
    async Task MeasureBackgroundPerformance(string output) {
        Directory.CreateDirectory(output);
        var results = new List<object>();
        try {
            GamePicker.SelectedValue = "file1";
            RefreshBackgroundVideos();
            var timeout = Stopwatch.StartNew();
            while (backgroundPlayer?.HasVideo != true) {
                if (timeout.Elapsed.TotalSeconds > 20) throw new IOException("Playback did not start.");
                await Task.Delay(50);
            }
            async Task Sample(string phase) {
                using var process = Process.GetCurrentProcess();
                var cpu = process.TotalProcessorTime;
                var elapsed = Stopwatch.StartNew();
                var delays = new List<double>();
                int frames = 0;
                void Frame(object? sender, EventArgs e) => frames++;
                CompositionTarget.Rendering += Frame;
                try {
                    while (elapsed.Elapsed.TotalSeconds < 6) {
                        var tick = Stopwatch.StartNew();
                        await Task.Delay(16);
                        delays.Add(tick.Elapsed.TotalMilliseconds);
                    }
                } finally { CompositionTarget.Rendering -= Frame; }
                delays.Sort();
                results.Add(new { phase, cpuCorePercent = (process.TotalProcessorTime - cpu).TotalSeconds / elapsed.Elapsed.TotalSeconds * 100,
                    framesPerSecond = frames / elapsed.Elapsed.TotalSeconds, p95DispatcherMs = delays[(int)(delays.Count * .95)], maxDispatcherMs = delays[^1] });
            }
            backgroundRemoving = true; // Keep periodic readiness updates from resuming a sampled pause.
            backgroundPlayer!.Suspend(true);
            await Task.Delay(500);
            await Sample("image");
            backgroundPlayer.Suspend(false);
            await Task.Delay(2000);
            await Sample("video");
            await File.WriteAllTextAsync(Path.Combine(output, "performance.json"), JsonSerializer.Serialize(new {
                tier = RenderCapability.Tier >> 16, results }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "performance.json"), JsonSerializer.Serialize(new { error = error.ToString() }));
            Environment.ExitCode = 1;
        } finally { Close(); }
    }
}
