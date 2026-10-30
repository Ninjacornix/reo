using System.IO;
using System.Security.Cryptography;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    async Task TestControlsUi(string output) {
        Directory.CreateDirectory(output);
        string settingsPath = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(settingsPath) ? File.ReadAllBytes(settingsPath) : null;
        string file1Import = settings.ImportedFile1, file2Import = settings.ImportedFile2;
        var checks = new List<string>();
        void Check(bool okay, string name) { if (!okay) throw new IOException(name); checks.Add(name); }
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!;
        async Task Settle() => await Dispatcher.InvokeAsync(() => { UpdateLayout(); }, DispatcherPriority.ApplicationIdle);
        async Task Invoke(Button button) {
            ((IInvokeProvider)new ButtonAutomationPeer(button).GetPattern(PatternInterface.Invoke)!).Invoke();
            await Settle();
        }
        async Task Wait(Func<bool> condition, string name) {
            for (int attempt = 0; attempt < 200 && !condition(); attempt++) await Task.Delay(50);
            Check(condition(), name);
            await Settle();
        }
        void Key(Key key) => RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this),
            Environment.TickCount, key) { RoutedEvent = Keyboard.PreviewKeyDownEvent });
        static string Hash(BitmapSource? image) {
            if (image == null) return "";
            byte[] pixels = new byte[image.PixelWidth * image.PixelHeight * 4];
            image.CopyPixels(pixels, image.PixelWidth * 4, 0);
            return Convert.ToHexString(SHA256.HashData(pixels)).ToLowerInvariant();
        }
        void Capture(string name) {
            UpdateLayout();
            var image = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            image.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(image));
            using var stream = File.Create(Path.Combine(output, name + ".png")); encoder.Save(stream);
        }
        void CheckMap(string edition) {
            UpdateLayout();
            Check(ControllerDiagram.IsVisible && bindingButtons.Count == 16 && bindingValues.Count == 16 &&
                bindingLeaders.Count == 16 && InputMapping.Actions.All(a => bindingButtons.ContainsKey(a.Id)) &&
                InputMapping.Camera.All(a => !bindingButtons.ContainsKey(a.Id)),
                edition + " exposes sixteen physical PS2 targets without the camera controls below");
            var boxes = InputMapping.Actions.Select(a => (a.Id, Button: bindingButtons[a.Id])).Select(a =>
                (a.Id, Box: new Rect(Canvas.GetLeft(a.Button), Canvas.GetTop(a.Button), a.Button.ActualWidth, a.Button.ActualHeight))).ToArray();
            Check(boxes.All(a => a.Box.Left >= -1 && a.Box.Top >= -1 && a.Box.Right <= ControllerDiagram.ActualWidth + 1 &&
                a.Box.Bottom <= ControllerDiagram.ActualHeight + 1 && a.Box.Width >= 140 && a.Box.Height >= 48),
                edition + " keeps all sixteen editable button rectangles inside the controller canvas");
            for (int i = 0; i < boxes.Length; i++) for (int j = i + 1; j < boxes.Length; j++) {
                var overlap = Rect.Intersect(boxes[i].Box, boxes[j].Box);
                if (!overlap.IsEmpty && overlap.Width > 1 && overlap.Height > 1)
                    throw new IOException(edition + " binding buttons overlap: " + boxes[i].Id + " / " + boxes[j].Id);
            }
            Check(true, edition + " has no overlapping physical binding buttons");
            Check(bindingButtons.Values.All(b => b.Content is StackPanel panel &&
                panel.Children.OfType<TextBlock>().First().FontSize >= 14) && bindingValues.Values.All(v => v.FontSize >= 16),
                edition + " preserves readable game labels and binding values without shrinking the font");
            Check(bindingButtons.Values.All(b => AutomationProperties.GetName(b).Length > 0 &&
                AutomationProperties.GetHelpText(b).Contains("remap")), edition + " exposes binding labels and remap help to native accessibility");
            Check(controllerArtwork is { IsFrozen: true, PixelWidth: 172, PixelHeight: 116 } &&
                diagramImage?.Source == controllerArtwork && ControllerDiagram.Children.OfType<Image>().Count() == 1,
                edition + " displays only the original controller image without the blue overlay");
            var byId = boxes.ToDictionary(a => a.Id, a => a.Box);
            var artworkBounds = new Rect(Canvas.GetLeft(diagramImage!), Canvas.GetTop(diagramImage!),
                diagramImage!.ActualWidth, diagramImage.ActualHeight);
            Check(boxes.All(b => !b.Box.IntersectsWith(artworkBounds)),
                edition + " keeps every binding box completely outside the controller image");
            Check(ControllerAnchors.All(a => {
                var target = new Point(Canvas.GetLeft(diagramImage!) + a.Value.X * diagramImage!.ActualWidth,
                    Canvas.GetTop(diagramImage) + a.Value.Y * diagramImage.ActualHeight);
                var box = byId[a.Key];
                var points = bindingLeaders[a.Key].Points;
                var tolerance = box; tolerance.Inflate(.5, .5);
                if (points.Count < 2 || (points[^1] - target).Length > .5 || !tolerance.Contains(points[0]) ||
                    (points[0] - points[^1]).Length < 15)
                    throw new IOException(edition + " invalid callout " + a.Key + ": box=" + box + "; start=" +
                        points.FirstOrDefault() + "; end=" + points.LastOrDefault() + "; target=" + target);
                return true;
            }), edition + " connects every outside binding to its own physical control with a visible line");
            // Independently inspected interiors of the actual button faces in the pinned
            // source sprites. Check the rendered endpoints, not just the production anchors.
            var buttonFaces = new Dictionary<string, Rect> {
                ["L2"] = new(33, 5, 7, 5), ["L1"] = new(32, 15, 7, 6),
                ["R2"] = new(126, 5, 6, 5), ["R1"] = new(128, 15, 6, 6),
                ["Up"] = new(31, 47, 6, 5), ["Down"] = new(31, 65, 6, 5),
                ["Left"] = new(22, 55, 5, 6), ["Right"] = new(41, 55, 5, 6),
                ["Triangle"] = new(128, 42, 6, 6), ["Circle"] = new(143, 56, 6, 6),
                ["Cross"] = new(129, 69, 5, 6), ["Square"] = new(116, 56, 5, 6),
                ["Select"] = new(65, 57, 6, 3), ["Start"] = new(96, 57, 5, 3),
                ["L3"] = new(57, 83, 7, 7), ["R3"] = new(102.5, 83, 7, 7)
            };
            Check(buttonFaces.All(a => {
                var local = ControllerDiagram.TranslatePoint(bindingLeaders[a.Key].Points[^1], diagramImage);
                return a.Value.Contains(new Point(local.X * 172 / diagramImage.ActualWidth,
                    local.Y * 116 / diagramImage.ActualHeight));
            }), edition + " lands every rendered endpoint inside its measured button face in the source artwork");
        }
        async Task Artwork(string game, string hash) {
            GamePicker.SelectedValue = game;
            UpdateInputUi(); ShowBindings(this, new());
            await Wait(() => Hash(controllerArtwork) == hash,
                game + " loads its own extracted controller pixels with verified SHA256 " + hash);
            if (args.Contains("--test-owned-game-font")) await Wait(() =>
                ((FontFamily)Application.Current.Resources["GameDisplayFont"]).Source.Contains(GameFont.FamilyName),
                game + " renders labels using the verified owned dialogue font");
        }
        try {
            Check(args.Contains("--data-home"), "Controls diagnostics explicitly select an isolated settings home");
            timer.Stop();
            settings.Keyboard = InputMapping.KeyboardDefaults();
            controller.Select("keyboard"); controller.Poll();
            ShowPage("Controller"); UpdateInputUi(); ShowBindings(this, new());
            await Artwork("file1", "11cf3a1cf939f3406e452ac062b8b2ddd06ba2939345557e7b28deb912a6193a");
            CheckMap("File #1 normal");
            Check(!LayoutTab.IsEnabled && StickSettings.Visibility == Visibility.Collapsed &&
                InputBindingsPanel.IsVisible, "Keyboard selection shows the button map and disables pad-only stick settings");
            NavController.Focus(); SettingsScroll.ScrollToTop(); await Settle(); Capture("file1-normal");

            foreach (var action in InputMapping.Actions) {
                int previous = settings.Keyboard[action.Id];
                await Invoke(bindingButtons[action.Id]);
                Check(captureTarget == action.Id && CapturePanel.IsVisible && bindingValues[action.Id].Text == "Waiting...",
                    action.Id + " starts remapping through its native accessible button");
                Key(System.Windows.Input.Key.F); await Settle();
                var mapped = InputMapping.Keyboard(settings.Keyboard, code => code == 'F');
                bool target = action.Code == InputMapping.LeftTrigger ? mapped.LT == 255 && mapped.Buttons == 0 && mapped.RT == 0 :
                    action.Code == InputMapping.RightTrigger ? mapped.RT == 255 && mapped.Buttons == 0 && mapped.LT == 0 :
                    mapped.Buttons == action.Code && mapped.LT == 0 && mapped.RT == 0;
                Check(settings.Keyboard[action.Id] == 'F' && Stored().Keyboard[action.Id] == 'F' &&
                    bindingValues[action.Id].Text == "F" && captureTarget.Length == 0 && !CapturePanel.IsVisible && target,
                    action.Id + " routed key capture persists and reaches the original PS2 target in the real keyboard mapper");
                Check(bindingButtons[action.Id].IsKeyboardFocused, action.Id + " returns keyboard focus to the rebuilt binding button");
                settings.Keyboard[action.Id] = previous; BuildBindingRows();
            }
            await Invoke(ResetBindingsButton);
            Check(settings.Keyboard.OrderBy(p => p.Key).SequenceEqual(InputMapping.KeyboardDefaults().OrderBy(p => p.Key)) &&
                Stored().Keyboard.OrderBy(p => p.Key).SequenceEqual(InputMapping.KeyboardDefaults().OrderBy(p => p.Key)),
                "Reset bindings restores and persists every keyboard default");
            await Invoke(bindingButtons["Cross"]); await Invoke(bindingButtons["Circle"]);
            Check(captureTarget == "Circle" && bindingValues["Circle"].Text == "Waiting..." && bindingValues["Cross"].Text == "Space" &&
                bindingValues.Values.Count(v => v.Text == "Waiting...") == 1,
                "Selecting another physical target restores the previous value and leaves one waiting target");
            SettingsScroll.ScrollToTop(); await Settle(); Capture("file1-capture");
            await Invoke(CancelCaptureButton);
            Check(captureTarget.Length == 0 && !CapturePanel.IsVisible && settings.Keyboard["Circle"] == 'E' &&
                bindingValues["Circle"].Text == "E", "Cancel closes key capture and preserves the original binding");
            await Invoke(bindingButtons["Cross"]); await Invoke(ClearCaptureButton);
            Check(settings.Keyboard["Cross"] == 0 && Stored().Keyboard["Cross"] == 0 && bindingValues["Cross"].Text == "Unbound" &&
                captureTarget.Length == 0, "Clear binding removes and persists the currently captured physical target");
            var square = bindingButtons["Square"];
            square.ContextMenu!.PlacementTarget = square; square.ContextMenu.IsOpen = true; await Settle();
            var clear = (MenuItem)square.ContextMenu.Items[0];
            ((IInvokeProvider)new MenuItemAutomationPeer(clear).GetPattern(PatternInterface.Invoke)!).Invoke(); await Settle();
            square.ContextMenu.IsOpen = false;
            Check(settings.Keyboard["Square"] == 0 && Stored().Keyboard["Square"] == 0 && bindingValues["Square"].Text == "Unbound",
                "The physical button context menu clears its binding through native menu automation");
            await Invoke(ResetBindingsButton);

            Width = MinWidth; Height = MinHeight; await Task.Delay(200); await Settle();
            CheckMap("File #1 compact");
            SettingsScroll.ScrollToTop(); await Settle(); Capture("compact-file1-top");
            SettingsScroll.ScrollToEnd(); await Settle();
            var reset = ResetBindingsButton.TranslatePoint(new Point(), SettingsScroll);
            Check(PageController.ActualWidth <= SettingsScroll.ViewportWidth + 1 && reset.Y >= -1 &&
                reset.Y + ResetBindingsButton.ActualHeight <= SettingsScroll.ViewportHeight + 1 && GamePicker.IsVisible,
                "Native scrolling reaches all callouts and Reset at minimum size above the fixed DVD footer");
            Capture("compact-file1-bottom");
            await Artwork("file2", "2f5a177c9165a8ad9d53f18a4ff1fee81af4d95269281a7a0c50b74dfdbf0da2");
            CheckMap("File #2 compact");
            SettingsScroll.ScrollToTop(); await Settle(); Capture("compact-file2");
            Width = 1121; Height = 812; await Task.Delay(150); await Settle();
            CheckMap("File #2 intermediate"); Capture("file2-intermediate");
            Width = 1320; Height = 920; await Task.Delay(150); await Settle();
            CheckMap("File #2 normal"); Capture("file2-normal");

            // A missing import must not remove editable mappings or permit a stale async image to win.
            settings.ImportedFile2 = ""; RefreshControllerArtwork();
            await Wait(() => controllerArtwork == null && ControllerDiagram.Visibility == Visibility.Collapsed && bindingButtons.Count == 16,
                "Missing game data falls back to sixteen editable bindings without separate camera rows");
            await Invoke(bindingButtons["Cross"]); Key(System.Windows.Input.Key.G); await Settle();
            Check(settings.Keyboard["Cross"] == 'G' && Stored().Keyboard["Cross"] == 'G' &&
                (string)bindingButtons["Cross"].Content == "G", "Text fallback bindings retain native remapping and persistence");
            Capture("missing-import-fallback");
            settings.ImportedFile2 = file1Import; RefreshControllerArtwork();
            await Task.Delay(100);
            Check(controllerArtwork == null && bindingButtons.Count == 16,
                "An unsupported edition archive leaves every fallback binding editable");
            settings.ImportedFile2 = file2Import; RefreshControllerArtwork();
            GamePicker.SelectedValue = "file1"; UpdateInputUi();
            GamePicker.SelectedValue = "file2"; UpdateInputUi();
            await Wait(() => Hash(controllerArtwork) == "2f5a177c9165a8ad9d53f18a4ff1fee81af4d95269281a7a0c50b74dfdbf0da2" &&
                ControllerDiagram.IsVisible && bindingButtons.Count == 16, "Rapid game/import changes keep the final edition's correct controller artwork");
            await Invoke(ResetBindingsButton);

            var keyboard = new Dictionary<string, int>(settings.Keyboard);
            // This is a saved disconnected selection, never an emulated or injected physical controller.
            controller.Select("xbox:4294967295"); controller.Poll(); UpdateInputUi(); ShowBindings(this, new()); await Settle();
            Check(!controller.SelectedDevice.Available && LayoutTab.IsEnabled && StickSettings.Visibility == Visibility.Visible &&
                bindingButtons.Count == 16,
                "A disconnected Xbox profile shows sixteen pad targets and exposes its independent stick settings");
            var pad = new Dictionary<string, int>(settings.Xbox.Buttons);
            await Invoke(bindingButtons["Cross"]);
            Check(captureTarget.Length == 0 && !CapturePanel.IsVisible && Status.Text.Contains("Connect") &&
                pad.OrderBy(p => p.Key).SequenceEqual(settings.Xbox.Buttons.OrderBy(p => p.Key)),
                "A disconnected physical profile cannot start capture or overwrite pad mappings");
            await Invoke(LayoutTab);
            ((IRangeValueProvider)new SliderAutomationPeer(DeadZone).GetPattern(PatternInterface.RangeValue)!).SetValue(23);
            ((IToggleProvider)new CheckBoxAutomationPeer(SwapSticks).GetPattern(PatternInterface.Toggle)!).Toggle();
            ((IToggleProvider)new CheckBoxAutomationPeer(InvertRightY).GetPattern(PatternInterface.Toggle)!).Toggle();
            UpdateInputUi(); await Settle();
            var persisted = Stored();
            Check(persisted.Xbox.DeadZone == 23 && persisted.Xbox.SwapSticks == (SwapSticks.IsChecked == true) &&
                persisted.Xbox.InvertRightY == (InvertRightY.IsChecked == true) && DeadZoneLabel.Text.Contains("23%") &&
                InputLayoutPanel.IsVisible && !InputBindingsPanel.IsVisible,
                "Pad dead zone, swap and inversion persist through native slider and toggle automation");
            Capture("disconnected-pad-sticks");
            controller.Select("keyboard"); controller.Poll(); UpdateInputUi(); await Settle();
            Check(!LayoutTab.IsEnabled && InputBindingsPanel.IsVisible && !InputLayoutPanel.IsVisible &&
                keyboard.OrderBy(p => p.Key).SequenceEqual(settings.Keyboard.OrderBy(p => p.Key)),
                "Returning to keyboard preserves its bindings and restores the button map automatically");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks, inputMethod = "Native UIA controls and WPF routed key events; no OS input or physical-device simulation."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            timer.Stop(); audioSaveTimer.Stop();
            settings.ImportedFile1 = file1Import; settings.ImportedFile2 = file2Import;
            Close();
            if (saved == null) File.Delete(settingsPath); else File.WriteAllBytes(settingsPath, saved);
        }
    }
}
