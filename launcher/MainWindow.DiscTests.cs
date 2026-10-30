using System.IO;
using System.Net.Http;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

public partial class MainWindow {
    // Isolated visual fixtures exercise presentation without importing or launching a game.
    async Task TestDiscSelectors(string output) {
        Directory.CreateDirectory(output);
        string settingsPath = Path.Combine(Settings.Home, "settings.json");
        byte[]? savedSettings = File.Exists(settingsPath) ? File.ReadAllBytes(settingsPath) : null;
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        void Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png"));
            encoder.Save(file);
        }
        BitmapSource CaptureFooter(string name) {
            UpdateLayout();
            const double scale = 3;
            var bitmap = new RenderTargetBitmap((int)Math.Ceiling(GamePicker.ActualWidth * scale),
                (int)Math.Ceiling(GamePicker.ActualHeight * scale), 96 * scale, 96 * scale, PixelFormats.Pbgra32);
            var visual = new DrawingVisual();
            using (var drawing = visual.RenderOpen()) {
                var bounds = new Rect(0, 0, GamePicker.ActualWidth, GamePicker.ActualHeight);
                drawing.DrawRectangle(Palette.Brush(Palette.Background), null, bounds);
                drawing.DrawRectangle(new VisualBrush(GamePicker), null, bounds);
            }
            bitmap.Render(visual);
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png"));
            encoder.Save(file);
            return bitmap;
        }
        try {
            timer.Stop();
            settings.LauncherBackgroundMovies = false;
            RefreshBackgroundVideos();
            using var client = new HttpClient();
            client.DefaultRequestHeaders.UserAgent.ParseAdd("REO-Launcher-Artwork-Verification/1.0");
            await GameArtwork.DownloadMissing(client, null, default);
            Check(GameArtwork.DownloadsCurrent(), "All six artwork assets pass size and SHA-256 verification after the real downloader runs");
            artworkLoadKey = "";
            await LoadArtworkAsync();
            Check(GameDisc1.Artwork?.PixelWidth == 1280 && GameDisc2.Artwork?.PixelWidth == 1280,
                  "Both downloaded DVD labels reach their own models");
            // Readiness fixtures contain only dummy files and a manifest; nothing is executed.
            string fixture = Path.GetFullPath(Path.Combine(output, "fixtures", Guid.NewGuid().ToString("N")));
            Directory.CreateDirectory(fixture);
            string executable = Path.Combine(fixture, "presentation-only.exe");
            File.WriteAllText(executable, "Not an executable. UI fixture only.");
            settings.Exe = settings.SecondExe = executable;
            foreach (var definition in new[] { GameDefinition.First, GameDefinition.Second }) {
                string iso = Path.Combine(fixture, definition.Id + ".iso");
                File.WriteAllText(iso, "Not a game image. UI fixture only.");
                if (definition.Id == "file1") settings.Iso = iso; else settings.SecondIso = iso;
            }
            settings.ImportedFile1 = settings.ImportedFile2 = "";
            RefreshGameUi();
            await Task.Delay(300);
            Check(!GameDisc1.IsAvailable && !GameDisc2.IsAvailable,
                  "Choosing ISO files and existing builds without completed imports keeps both DVDs dark");
            foreach (var definition in new[] { GameDefinition.First, GameDefinition.Second }) {
                string import = Path.Combine(fixture, definition.Id);
                Directory.CreateDirectory(Path.Combine(import, "data"));
                var source = new FileInfo(settings.GetIso(definition.Id));
                File.WriteAllText(Path.Combine(import, "data", definition.ElfName), "Readiness fixture only");
                File.WriteAllText(Path.Combine(import, "import.json"), JsonSerializer.Serialize(new ImportManifest(
                    1, definition.Id, source.FullName, source.Length, source.LastWriteTimeUtc.Ticks,
                    DiscImport.ExpectedElf(definition.Id), Array.Empty<ImportedFile>())));
                if (definition.Id == "file1") settings.ImportedFile1 = import; else settings.ImportedFile2 = import;
            }
            RefreshGameUi();
            Check(GameDisc1.IsAvailable && GameDisc2.IsAvailable,
                  "Completed-import readiness fixtures illuminate their installed models");
            var mesh = GameDiscView.Ring(.125, 1, 0);
            Check(mesh.Positions.All(p => Math.Sqrt(p.X * p.X + p.Y * p.Y) >= .1249) &&
                  mesh.TextureCoordinates.All(p => p.X >= 0 && p.X <= 1 && p.Y >= 0 && p.Y <= 1),
                  "DVD mesh preserves the centre hole and maps the label within its image bounds");
            foreach (int selected in new[] { 1, 2 }) {
                var item = (ListBoxItem)GamePicker.Items[selected - 1];
                var peer = new ListBoxItemAutomationPeer(item, new ListBoxAutomationPeer(GamePicker));
                ((ISelectionItemProvider)peer.GetPattern(PatternInterface.SelectionItem)!).Select();
                Check(settings.Game.Id == "file" + selected && GamePicker.SelectedItem == item,
                      "Native accessible selection switches to File #" + selected);
                await Task.Delay(350);
                Check(Math.Abs(GameDisc1.Illumination - (selected == 1 ? 1 : 0)) < .01 &&
                      Math.Abs(GameDisc2.Illumination - (selected == 2 ? 1 : 0)) < .01,
                      "Only selected installed File #" + selected + " lights up");
                var active = selected == 1 ? GameDisc1 : GameDisc2;
                var inactive = selected == 1 ? GameDisc2 : GameDisc1;
                Check(Math.Abs(active.VerticalOffset) < .01 && Math.Abs(inactive.VerticalOffset - 12) < .01 &&
                      inactive.DiscOpacity < active.DiscOpacity && (string)LaunchButton.Content == "Play File #" + selected,
                      "File #" + selected + " selection raises its DVD, dims and lowers the other, and updates the Play label");
                Capture("file" + selected + "-selected");
                var footer = CaptureFooter("file" + selected + "-discs-closeup");
                var pixels = new byte[footer.PixelWidth * footer.PixelHeight * 4];
                footer.CopyPixels(pixels, footer.PixelWidth * 4, 0);
                foreach (int edition in new[] { 0, 1 }) {
                    int red = 0;
                    for (int y = 0; y < footer.PixelHeight; y++)
                        for (int x = edition * footer.PixelWidth / 2; x < (edition + 1) * footer.PixelWidth / 2; x++) {
                            int at = (y * footer.PixelWidth + x) * 4;
                            if (pixels[at + 2] > pixels[at + 1] * 1.5 + 3 && pixels[at + 2] > pixels[at] * 1.4 + 3) red++;
                        }
                    Check(red > 500, "File #" + (edition + 1) + " has visible printed label pixels rather than a bare rim");
                }
            }
            Check(GameDisc1.RasterWidth >= Math.Ceiling(GameDisc1.ActualWidth * VisualTreeHelper.GetDpi(GameDisc1).DpiScaleX * 3) &&
                  GameDisc2.RasterWidth >= Math.Ceiling(GameDisc2.ActualWidth * VisualTreeHelper.GetDpi(GameDisc2).DpiScaleX * 3),
                  "Both DVD models are supersampled at three times the display's pixel density");
            int renders = GameDisc2.RenderCount;
            GameDisc2.IsSelected = false;
            await Task.Delay(350);
            GameDisc2.IsSelected = true;
            await Task.Delay(350);
            Check(GameDisc2.RenderCount == renders,
                  "Selection fades and idle time reuse the cached DVD without rendering the 3D scene again");
            var secondItem = (ListBoxItem)GamePicker.Items[1];
            secondItem.Focus();
            secondItem.RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this),
                Environment.TickCount, Key.Left) { RoutedEvent = Keyboard.KeyDownEvent });
            Check(settings.Game.Id == "file1" && ((ListBoxItem)GamePicker.Items[0]).IsKeyboardFocusWithin,
                  "Left arrow selects and focuses the first DVD using native keyboard navigation");
            var firstItem = (ListBoxItem)GamePicker.Items[0];
            firstItem.RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this),
                Environment.TickCount, Key.Right) { RoutedEvent = Keyboard.KeyDownEvent });
            Check(settings.Game.Id == "file2" && secondItem.IsKeyboardFocusWithin &&
                  secondItem.Template.FindName("DiscFocus", secondItem) == null &&
                  (string)LaunchButton.Content == "Play File #2",
                  "Right arrow focuses and selects the second DVD without a white rectangular outline");
            Capture("keyboard-focus");
            NavPlay.Focus();
            settings.ImportedFile1 = settings.ImportedFile2 = "";
            RefreshGameUi();
            await Task.Delay(350);
            Check(GameDisc1.Illumination == 0 && GameDisc2.Illumination == 0 && GamePicker.IsEnabled,
                  "Uninstalled DVDs stay dark and remain selectable");
            Capture("not-installed");
            GameDisc2.Artwork = null;
            GameDisc2.IsAvailable = true;
            DiscStatus2.Text = "Selected · Ready to play";
            GameDisc2.Hold(true);
            Check(GameDisc2.Illumination == 1, "Reduced-motion/resize hold applies the selected light without animation");
            Capture("offline-fallback");
            GameDisc2.Hold(false);
            artworkLoadKey = "";
            await LoadArtworkAsync();
            Width = MinWidth;
            Height = MinHeight;
            await Task.Delay(350);
            var location = GamePicker.TranslatePoint(new Point(), LauncherFooter);
            var playLocation = LaunchButton.TranslatePoint(new Point(), LauncherFooter);
            Check(GameDisc1.ActualWidth is > 100 and < 230 && GameDisc2.ActualWidth is > 100 and < 230 &&
                  location.X + GamePicker.ActualWidth < playLocation.X &&
                  location.Y + GamePicker.ActualHeight <= LauncherFooter.ActualHeight + 1,
                  "Compact DVDs fit in the persistent footer beside Play at the minimum window size");
            Capture("compact");
            ShowPage("Graphics");
            await Task.Delay(500);
            Check(GamePicker.IsVisible && GameDisc1.IsVisible && GameDisc2.IsVisible &&
                  GameCasePicker.SelectedValue.Equals(GamePicker.SelectedValue),
                  "Footer DVD selectors remain visible on other pages and stay synchronized with Play");
            Capture("graphics-footer");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks, note = "Installed-state images are presentation fixtures, not game-runtime verification."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            if (savedSettings != null) File.WriteAllBytes(settingsPath, savedSettings);
            else File.Delete(settingsPath);
            Close();
        }
    }
}
