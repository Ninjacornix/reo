using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    [DllImport("user32.dll", EntryPoint = "SendMessageW")] static extern nint GraphicsPreviewMessage(nint window, uint message, nint wParam, nint lParam);
    [DllImport("user32.dll")] static extern nint GetCapture();
    [DllImport("user32.dll", EntryPoint = "GetDC")] static extern nint GraphicsPreviewDc(nint window);
    [DllImport("user32.dll", EntryPoint = "ReleaseDC")] static extern int GraphicsPreviewReleaseDc(nint window, nint dc);
    [DllImport("user32.dll", EntryPoint = "InvalidateRect")] static extern bool GraphicsPreviewInvalidate(nint window, nint rect, bool erase);
    [DllImport("gdi32.dll", EntryPoint = "GetPixel")] static extern uint GraphicsPreviewPixel(nint dc, int x, int y);
    static nint GraphicsPreviewPoint(int x, int y) => (nint)unchecked((int)(((uint)(ushort)y << 16) | (ushort)x));
    async Task TestGraphicsUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        var timings = new List<object>();
        double productionFps = 0, productionGpuMilliseconds = 0;
        object? productionPacing = null;
        EventHandler? fadeObserver = null;
        double entryMinimumOpacity = 1, exitMinimumOpacity = 1;
        void Check(bool valid, string name) { if (!valid) throw new IOException(name); checks.Add(name); }
        async Task Settle() => await Dispatcher.InvokeAsync(UpdateLayout, DispatcherPriority.ApplicationIdle);
        async Task Wait(Func<bool> condition, string name) {
            for (int i = 0; i < 400 && !condition(); i++) await Task.Delay(50);
            Check(condition(), name);
            await Settle();
        }
        string Hash() => graphicsPreviewFrame == null ? "" : Convert.ToHexString(SHA256.HashData(graphicsPreviewFrame.Bgra));
        double Luma() => graphicsPreviewFrame!.Bgra.Where((_, i) => i % 4 != 3).Average(b => (double)b);
        void CheckNoBars(string name) {
            var frame = graphicsPreviewFrame!;
            bool SceneRow(int y) => Enumerable.Range(0, frame.Width).Count(x => {
                int pixel = (y * frame.Width + x) * 4;
                return frame.Bgra[pixel] + frame.Bgra[pixel + 1] + frame.Bgra[pixel + 2] > 0;
            }) > frame.Width * .95;
            Check(SceneRow(0) && SceneRow(frame.Height - 1), name);
        }
        void Slider(System.Windows.Controls.Slider slider, double value) =>
            ((IRangeValueProvider)new SliderAutomationPeer(slider).GetPattern(PatternInterface.RangeValue)!).SetValue(value);
        async Task Frame(Action change, string name) {
            int count = graphicsPreviewFrames;
            change();
            await Wait(() => graphicsPreviewFrames > count && graphicsPreviewPublishedOptions == ReadGraphicsPreviewOptions() &&
                graphicsPreviewFrame?.Bgra.Length > 0, name);
            timings.Add(new { name, renderMilliseconds = graphicsPreviewRenderMilliseconds, previewFps = graphicsPreviewFps,
                rasterWidth = graphicsPreviewFrame!.RenderWidth, rasterHeight = graphicsPreviewFrame.RenderHeight });
        }
        void Capture(string name) {
            UpdateLayout();
            var image = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            image.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(image));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Graphics diagnostics use an isolated settings home");
            timer.Stop(); graphicsPreviewTestTime = 1;
            GamePicker.SelectedValue = "file1";
            await LoadArtworkAsync();
            Check(GameDisc1.Artwork?.PixelWidth == 1280 && GameDisc2.Artwork?.PixelWidth == 1280,
                "Public previews retain both verified DVD labels while personal covers are redacted");
            fadeObserver = (_, _) => entryMinimumOpacity = Math.Min(entryMinimumOpacity, PageContent.Opacity);
            CompositionTarget.Rendering += fadeObserver;
            ShowPage("Graphics");
            Check(pageTransition == SystemParameters.ClientAreaAnimation && animatePage == SystemParameters.ClientAreaAnimation &&
                OutgoingPage.Source == null,
                "Entering Graphics restores the foreground fade without capturing the native preview");
            GraphicsGpuView.Visibility = Visibility.Visible; UpdateLayout();
            Check(!GraphicsGpuView.HasPresentedFrame, "The native loading surface is checked before the first GPU presentation");
            GraphicsPreviewInvalidate(GraphicsGpuView.Handle, 0, true);
            GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x000F, 0, 0);
            var loadingDc = GraphicsPreviewDc(GraphicsGpuView.Handle);
            uint loadingColor;
            try { loadingColor = GraphicsPreviewPixel(loadingDc, 4, 4); }
            finally { GraphicsPreviewReleaseDc(GraphicsGpuView.Handle, loadingDc); }
            var background = Palette.Background;
            Check(loadingColor == (uint)(background.R | background.G << 8 | background.B << 16),
                "The native preview paints the launcher background instead of flashing white during loading");
            await Wait(() => graphicsScene != null && graphicsPreviewFrames > 0, "Kevin loads and renders without launching the game");
            CompositionTarget.Rendering -= fadeObserver; fadeObserver = null;
            Check(!SystemParameters.ClientAreaAnimation || entryMinimumOpacity < .99,
                "Graphics entry visibly changes foreground opacity during rendered frames");
            await Wait(() => !pageTransition, "Graphics finishes the common page fade");
            await Frame(() => InvalidateGraphicsPreview(), "A fully opaque GPU frame is presented after the fade");
            byte[] opaque = graphicsPreviewFrame!.Bgra.ToArray();
            await Frame(() => { PageContent.Opacity = .5; InvalidateGraphicsPreview(); },
                "The native GPU preview receives the actual foreground opacity");
            byte[] half = graphicsPreviewFrame!.Bgra;
            int maximumBlendError = 0;
            for (int i = 0; i < half.Length; i++) {
                if (i % 4 == 3) continue;
                int channel = i % 4 == 0 ? Palette.Background.B : i % 4 == 1 ? Palette.Background.G : Palette.Background.R;
                maximumBlendError = Math.Max(maximumBlendError, Math.Abs(half[i] - (int)Math.Round((opaque[i] + channel) * .5)));
            }
            Check(maximumBlendError <= 1, "Every presented GPU pixel follows the same opacity blend as the WPF foreground");
            await Frame(() => { PageContent.Opacity = 0; InvalidateGraphicsPreview(); }, "Zero opacity reaches the native GPU image");
            Check(graphicsPreviewFrame!.Bgra.Where((_, i) => i % 4 != 3).Select((value, i) =>
                value == (i % 3 == 0 ? Palette.Background.B : i % 3 == 1 ? Palette.Background.G : Palette.Background.R)).All(equal => equal),
                "At zero opacity the native image is exactly the launcher's background, with no unfaded Kevin");
            await Frame(() => { PageContent.Opacity = 1; InvalidateGraphicsPreview(); }, "Normal preview opacity is restored");
            Check(GraphicsPreviewTitle.Text == "PREVIEW", "The graphics scene is labelled Preview");
            var choices = new[] { WindowSize, AspectRatio, ScreenFit, InternalResolution, TextureFilter, AnisotropicFilter, AntiAlias, Filter };
            Check(choices.Zip(choices.Skip(1)).Where(p => ReferenceEquals(p.First.Parent, p.Second.Parent) == false)
                .All(p => p.Second.TranslatePoint(new Point(), GraphicsSettingsList).Y -
                    p.First.TranslatePoint(new Point(0, p.First.ActualHeight), GraphicsSettingsList).Y >= 7),
                "Graphics dropdowns have visible vertical spacing");
            Check(graphicsScene!.Source.Contains(".pak", StringComparison.OrdinalIgnoreCase), "Kevin comes from the existing extracted asset pak");
            Check(graphicsScene.HasOriginalAnimation, "Kevin plays the original extracted idle animation from the existing pak");
            Check(graphicsScene.HasHandgun && graphicsScene.HasOriginalAnimation && !graphicsScene.HasHandgunStance,
                "Kevin holds the extracted handgun in the complete original relaxed idle pose");
            Check(graphicsScene.Meshes.Sum(m => m.Indices.Length) / 3 > 3000 && graphicsScene.Textures.Count > 0,
                "The preview uses the textured game mesh rather than an image or stand-in shape");
            Check(!game.Running && !launching && RoomPreview.Effect == null, "The isolated preview runs without the game and avoids applying color twice");
            Check(graphicsPreviewGpuStats.Hardware == 1 && GraphicsGpuView.Renderer.DeviceName.Length > 0,
                "Kevin's preview uses an actual hardware Direct3D GPU device");
            Check(!System.Windows.Controls.ToolTipService.GetIsEnabled(GpuMovies) &&
                !System.Windows.Controls.ToolTipService.GetIsEnabled(WindowSize),
                "Launcher options no longer show hover tooltips");
            Check(GraphicsPreviewPane.ActualWidth <= 380 && GraphicsPreviewPane.ActualWidth < GraphicsSettingsScroll.ActualWidth,
                "The live character preview uses a narrower right-hand column");
            var imageCenter = RoomPreview.TranslatePoint(new Point(RoomPreview.ActualWidth / 2, RoomPreview.ActualHeight / 2), GraphicsPreviewStage);
            Check(Math.Abs(imageCenter.X - GraphicsPreviewStage.ActualWidth / 2) < 1 &&
                Math.Abs(imageCenter.Y - GraphicsPreviewStage.ActualHeight / 2) < 1,
                "The full-height character image stays centered inside the narrower crop");

            await Frame(() => {
                Fullscreen.IsChecked = false;
                WindowSize.SelectedItem = DisplayOptions.Sizes[0]; AspectRatio.SelectedIndex = 0; ScreenFit.SelectedIndex = 0;
                InternalResolution.SelectedIndex = 0; TextureFilter.SelectedIndex = 0; AnisotropicFilter.SelectedIndex = 0;
                AntiAlias.SelectedIndex = 0; Filter.SelectedIndex = 0;
                Slider(Brightness, 100); Slider(Gamma, 1);
            }, "Every picture control reaches the live renderer through its real settings event");
            Capture("file1-native");
            CheckNoBars("The live scene fills the top and bottom edges without letterbox bars");
            var original = Hash();
            Check(graphicsPreviewFrame!.RenderHeight == 448, "Native GPU preview preserves the game's 448-line sampling density");
            await Frame(() => InternalResolution.SelectedIndex = 1, "2x resolution publishes a new live frame");
            Check(graphicsPreviewFrame!.RenderHeight == 896 && Hash() != original, "2x changes the actual GPU raster resolution and image pixels");
            await Frame(() => InternalResolution.SelectedIndex = 2, "4x resolution publishes a new live frame");
            Check(graphicsPreviewFrame!.RenderHeight > 896 && Hash() != original, "4x increases GPU scene sampling rather than changing only the label");
            Capture("file1-high-resolution");
            await Frame(() => InternalResolution.SelectedIndex = 0, "Native resolution can be restored live");
            original = Hash();
            await Frame(() => TextureFilter.SelectedIndex = 1, "Bilinear texture filtering updates the scene");
            Check(Hash() != original, "Texture filtering changes the sampled model and room textures");
            original = Hash();
            await Frame(() => AnisotropicFilter.SelectedIndex = 4, "16x anisotropic filtering updates the scene");
            Check(Hash() != original, "Anisotropic sampling changes the oblique room floor pixels");
            await Frame(() => AnisotropicFilter.SelectedIndex = 0, "Anisotropic filtering can be disabled live");
            original = Hash();
            await Frame(() => AntiAlias.SelectedIndex = 1, "FXAA updates the live scene");
            Check(Hash() != original, "FXAA changes rendered edge pixels");
            original = Hash();
            await Frame(() => AntiAlias.SelectedIndex = 2, "SMAA preview updates the live scene");
            Check(Hash() != original, "The morphological anti-aliasing preview changes the edge pixels");
            original = Hash();
            await Frame(() => Filter.SelectedIndex = 1, "Nearest image scaling updates the live scene");
            Check(Hash() != original, "Nearest output scaling changes the presented pixels");
            await Frame(() => Filter.SelectedIndex = 0, "Bilinear image scaling can be restored live");
            original = Hash();
            await Frame(() => AspectRatio.SelectedIndex = 1, "Widescreen camera updates the live scene");
            Check(Hash() != original && settings.ResolvedWidescreen, "Widescreen shows a differently projected room");
            original = Hash();
            await Frame(() => AspectRatio.SelectedIndex = 2, "Stretched widescreen updates the live scene");
            Check(Hash() != original && !settings.ResolvedWidescreen, "Stretched output and a wider camera give distinct previews");
            original = Hash();
            await Frame(() => ScreenFit.SelectedIndex = 3, "Fill screen fit updates the live scene");
            Check(Hash() != original, "Screen fit changes image placement and cropping");
            await Frame(() => { ScreenFit.SelectedIndex = 0; AspectRatio.SelectedIndex = 0; }, "Original picture shape is restored live");
            original = Hash();
            await Frame(() => WindowSize.SelectedItem = DisplayOptions.Sizes[3], "Window resolution updates the virtual output immediately");
            Check(Hash() != original, "Changing window shape affects the displayed preview");
            CheckNoBars("A widescreen virtual output still fills the portrait preview without black bars");
            await Frame(() => Fullscreen.IsChecked = true, "Borderless fullscreen updates the preview output and saves immediately");
            Check(settings.Fullscreen && !WindowSize.IsEnabled, "Fullscreen preserves the window size choice while disabling its selector");
            await Frame(() => { Fullscreen.IsChecked = false; WindowSize.SelectedItem = DisplayOptions.Sizes[0]; }, "Windowed output is restored");
            int counterResolution = InternalResolution.SelectedIndex, counterAnisotropy = AnisotropicFilter.SelectedIndex;
            await Frame(() => {
                InternalResolution.SelectedIndex = 2; AnisotropicFilter.SelectedIndex = 4;
                PerformanceOverlay.IsChecked = true;
            }, "The in-game FPS setting can be changed while the preview keeps rendering");
            await Task.Delay(1500);
            Check(GraphicsPreviewState.Text.Contains("FPS") && !GraphicsPreviewState.Text.Contains("GPU") && !GraphicsPreviewState.Text.Contains("ms") &&
                graphicsPreviewFps > 0 && graphicsPreviewRenderMilliseconds > 0,
                "The preview header displays only FPS while GPU timing remains available to diagnostics");
            graphicsPreviewSuppressReadback = true; InvalidateGraphicsPreview();
            await Wait(() => graphicsPreviewFrame?.Bgra.Length == 0,
                "Production GPU rendering does not read pixels back to the CPU");
            int productionBegin = graphicsPreviewFrames;
            int compBegin = graphicsPreviewCompositionPulses, busyBegin = graphicsPreviewBusyPulses,
                budgetBegin = graphicsPreviewBudgetPulses, timerBegin = graphicsPreviewTimerPulses;
            var productionClock = System.Diagnostics.Stopwatch.StartNew();
            await Task.Delay(2000);
            productionFps = (graphicsPreviewFrames - productionBegin) / productionClock.Elapsed.TotalSeconds;
            productionGpuMilliseconds = graphicsPreviewGpuStats.GpuMilliseconds;
            productionPacing = new { compositionPulses = graphicsPreviewCompositionPulses - compBegin,
                busyPulses = graphicsPreviewBusyPulses - busyBegin, budgetPulses = graphicsPreviewBudgetPulses - budgetBegin,
                timerPulses = graphicsPreviewTimerPulses - timerBegin, seconds = productionClock.Elapsed.TotalSeconds };
            Check(productionFps > 30 && productionGpuMilliseconds > 0,
                "The uncapped GPU preview exceeds the former 30 FPS limit without diagnostic readback");
            graphicsPreviewSuppressReadback = false;
            await Frame(InvalidateGraphicsPreview, "Diagnostic capture can resume after measuring the production GPU path");
            Capture("performance-counter");
            await Frame(() => {
                PerformanceOverlay.IsChecked = false;
                InternalResolution.SelectedIndex = counterResolution; AnisotropicFilter.SelectedIndex = counterAnisotropy;
            }, "The in-game FPS setting and previous preview quality can be restored");

            double dark = Luma();
            await Frame(() => Slider(Brightness, 125), "Brightness responds to native slider automation without waiting for the save timer");
            Check(Luma() > dark && BrightnessValue.Text == "125%", "Brightness visibly increases the rendered picture luminance");
            double bright = Luma();
            await Frame(() => Slider(Gamma, 1.4), "Gamma responds to native slider automation immediately");
            Check(Luma() > bright && GammaValue.Text == 1.4.ToString("F2"), "Gamma visibly lifts the rendered midtones");
            Capture("file1-picture-adjusted");
            await Frame(() => ResetColor(this, new()), "Reset restores brightness and gamma in the live picture");
            string forward = Hash();
            var screenPoint = GraphicsGpuView.PointToScreen(new Point(40, 40));
            Check(GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0084, 0,
                GraphicsPreviewPoint((int)screenPoint.X, (int)screenPoint.Y)) == 1,
                "The native preview accepts hit testing instead of passing mouse input through");
            await Frame(() => {
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0201, 1, GraphicsPreviewPoint(20, 20));
                Check(GraphicsGpuView.Rotation.Dragging && GetCapture() == GraphicsGpuView.Handle,
                    "A native mouse press starts dragging and captures the preview window");
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0200, 1, GraphicsPreviewPoint(140, 45));
            }, "Dragging Kevin updates the actual GPU model rotation");
            Check(Hash() != forward, "Turning Kevin changes the rendered model and handgun view");
            GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0202, 0, GraphicsPreviewPoint(140, 45));
            Check(!GraphicsGpuView.Rotation.Dragging && GetCapture() != GraphicsGpuView.Handle,
                "A native mouse release ends dragging and releases capture");
            float yaw = GraphicsGpuView.Rotation.Yaw, pitch = GraphicsGpuView.Rotation.Pitch;
            await Task.Delay(250);
            Check(GraphicsGpuView.Rotation.Yaw == yaw && GraphicsGpuView.Rotation.Pitch == pitch,
                "Kevin's viewing angle stops immediately after release with no velocity");
            Capture("rotated-kevin");
            string rotated = Hash();
            GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0201, 1, GraphicsPreviewPoint(140, 45));
            await Frame(() => GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0200, 1, GraphicsPreviewPoint(140, 180)),
                "A vertical mouse drag leaves the preview upright");
            GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0202, 0, GraphicsPreviewPoint(140, 180));
            Check(Hash() == rotated && GraphicsGpuView.Rotation.Pitch == 0 && GraphicsGpuView.Rotation.Yaw == yaw,
                "Vertical dragging changes neither the viewing angle nor the GPU image");
            double scrollOffset = GraphicsSettingsScroll.VerticalOffset;
            await Frame(() => GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x020A, (nint)(240 << 16),
                GraphicsPreviewPoint((int)screenPoint.X, (int)screenPoint.Y)), "Native mouse-wheel input zooms the GPU scene in");
            Check(GraphicsGpuView.Rotation.Zoom > 1 && Hash() != rotated && GraphicsGpuView.Rotation.Yaw == yaw &&
                GraphicsGpuView.Rotation.Pitch == pitch && GraphicsSettingsScroll.VerticalOffset == scrollOffset,
                "Wheel zoom changes rendered pixels while preserving rotation and the settings scroll position");
            Capture("zoomed-kevin");
            await Frame(() => GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x020A, (nint)unchecked(-240 << 16),
                GraphicsPreviewPoint((int)screenPoint.X, (int)screenPoint.Y)), "Native mouse-wheel input zooms the GPU scene back out");
            Check(Math.Abs(GraphicsGpuView.Rotation.Zoom - 1) < .001 && Hash() == rotated,
                "Opposite wheel input restores the same rendered framing");
            await Frame(() => { GraphicsGpuView.Rotation.Reset(); InvalidateGraphicsPreview(); }, "The default Kevin view can be restored");
            Check(UpdateButton.TranslatePoint(new Point(0, UpdateButton.ActualHeight), this).Y >= ((FrameworkElement)Content).ActualHeight - 30,
                "Check for updates stays at the bottom of the sidebar");
            Check(UpdateState.Visibility == Visibility.Collapsed, "Empty update status does not reserve space below the update button");
            Check(Brightness.Value == 100 && Gamma.Value == 1, "Reset preserves the two original color defaults");
            await Task.Delay(350);
            var stored = JsonSerializer.Deserialize<Settings>(File.ReadAllText(path))!;
            Check(stored.Brightness == 100 && stored.Gamma == 1 && stored.ResolvedAntiAliasing == settings.ResolvedAntiAliasing &&
                stored.InternalResolution == settings.InternalResolution, "The same picture selections persist for the next game launch");

            string frozen = Hash(); int before = graphicsPreviewFrames;
            await Frame(() => { graphicsPreviewTestTime = 2; InvalidateGraphicsPreview(); },
                "The idle animation advances to a second authored pose");
            Check(Hash() != frozen, "Original idle motion changes the rendered character after the handgun transition has settled");
            Capture("idle-next-pose");
            graphicsPreviewTestTime = null;
            await Wait(() => graphicsPreviewFrames >= before + 3 && Hash() != frozen, "Kevin's skeletal idle visibly changes frames over time");
            graphicsPreviewTestTime = 1;
            fadeObserver = (_, _) => exitMinimumOpacity = Math.Min(exitMinimumOpacity, PageContent.Opacity);
            CompositionTarget.Rendering += fadeObserver;
            ShowPage("Audio");
            Check(pageTransition == SystemParameters.ClientAreaAnimation && animatePage == SystemParameters.ClientAreaAnimation &&
                OutgoingPage.Source == null,
                "Leaving Graphics restores the lightweight foreground fade");
            before = graphicsPreviewFrames; await Task.Delay(550);
            CompositionTarget.Rendering -= fadeObserver; fadeObserver = null;
            Check(!SystemParameters.ClientAreaAnimation || exitMinimumOpacity < .99,
                "Graphics exit visibly changes foreground opacity during rendered frames");
            Check(!graphicsPreviewTimer.IsEnabled && graphicsPreviewFrames == before && !graphicsPreviewClock.IsRunning,
                "Leaving Graphics pauses animation and stops background preview rendering");
            ShowPage("Graphics"); await Wait(() => graphicsPreviewFrames > before, "Returning to Graphics resumes the preview");
            launching = true; RefreshGraphicsPreviewActivity();
            before = graphicsPreviewFrames; await Task.Delay(100);
            Check(!graphicsPreviewTimer.IsEnabled && graphicsPreviewFrames == before,
                "Preparing a game launch suspends preview work and prevents stale frames being published");
            launching = false; RefreshGraphicsPreviewActivity();
            await Wait(() => graphicsPreviewFrames > before, "The preview resumes when launch preparation ends");

            Width = MinWidth; Height = MinHeight; await Task.Delay(200); await Settle();
            var stage = GraphicsPreviewStage.TranslatePoint(new Point(), this);
            GraphicsSettingsScroll.ScrollToEnd(); await Settle();
            var after = GraphicsPreviewStage.TranslatePoint(new Point(), this);
            var gamma = Gamma.TranslatePoint(new Point(), GraphicsSettingsScroll);
            Check((after - stage).Length < .1 && gamma.Y >= -1 && gamma.Y + Gamma.ActualHeight <= GraphicsSettingsScroll.ViewportHeight + 1,
                "Scrolling the settings reaches gamma while the right-side model remains fixed and visible");
            Check(GraphicsPreviewPane.TranslatePoint(new Point(), this).X > GraphicsSettingsScroll.TranslatePoint(new Point(), this).X +
                GraphicsSettingsScroll.ActualWidth && PageGraphics.ActualWidth <= SettingsScroll.ViewportWidth + 1,
                "At minimum size the preview remains to the right without horizontal overflow");
            await Frame(() => InvalidateGraphicsPreview(), "The compact preview redraws at its actual viewport dimensions");
            Capture("file1-compact-picture");

            await Frame(() => {
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0201, 1, GraphicsPreviewPoint(20, 20));
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0200, 1, GraphicsPreviewPoint(70, 20));
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x0202, 0, GraphicsPreviewPoint(70, 20));
                GraphicsPreviewMessage(GraphicsGpuView.Handle, 0x020A, (nint)(120 << 16), 0);
            }, "The shared preview can retain a nondefault viewing angle and zoom");
            float sharedYaw = GraphicsGpuView.Rotation.Yaw, sharedZoom = GraphicsGpuView.Rotation.Zoom;
            var sharedScene = graphicsScene;
            var sharedSource = graphicsPreviewSource;
            var sharedClock = graphicsPreviewClock.Elapsed;
            double sharedSeconds = graphicsPreviewClock.Elapsed.TotalSeconds;
            int previous = graphicsPreviewFrames;
            GamePicker.SelectedValue = "file2"; RefreshGraphicsPreviewSource();
            Check(ReferenceEquals(graphicsScene, sharedScene) && graphicsPreviewSource == sharedSource &&
                GraphicsGpuView.Visibility == Visibility.Visible && PreviewEmpty.Visibility == Visibility.Collapsed,
                "Switching to File #2 preserves the same loaded scene with no loading screen");
            await Wait(() => graphicsPreviewFrames > previous, "The shared preview keeps rendering after changing games");
            Check(graphicsPreviewClock.Elapsed >= sharedClock && graphicsPreviewClock.Elapsed.TotalSeconds >= sharedSeconds,
                "Changing games does not reset the animation clock");
            Check(GraphicsGpuView.Rotation.Yaw == sharedYaw && GraphicsGpuView.Rotation.Zoom == sharedZoom,
                "Changing games preserves the user's preview angle and zoom");
            Check(FindName("GraphicsEditionLabel") == null, "Graphics has no File #1 or File #2 edition label");
            GamePicker.SelectedValue = "file1"; RefreshGraphicsPreviewSource();
            Check(ReferenceEquals(graphicsScene, sharedScene) && graphicsPreviewSource == sharedSource,
                "Switching back to File #1 reuses the same character and GPU scene");
            Width = 1320; Height = 920; GraphicsSettingsScroll.ScrollToTop(); await Settle();
            await Frame(() => InvalidateGraphicsPreview(), "The File #2 preview follows the resized viewport");
            Capture("shared-preview");

            WindowState = WindowState.Minimized; RefreshGraphicsPreviewActivity();
            Check(!graphicsPreviewTimer.IsEnabled, "Minimizing the launcher stops preview rendering");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = true, checks, timings,
                gpu = GraphicsGpuView.Renderer.DeviceName, featureLevel = graphicsPreviewGpuStats.FeatureLevel,
                productionFps, productionGpuMilliseconds, productionPacing, entryMinimumOpacity, exitMinimumOpacity,
                inputMethod = "Native preview hit testing and mouse messages including capture, drag, release and wheel; real selection events and slider automation; rendered pixels checked at fixed animation time." }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() },
                new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            if (fadeObserver != null) CompositionTarget.Rendering -= fadeObserver;
            launching = false;
            timer.Stop(); graphicsPreviewTimer.Stop(); colorSaveTimer.Stop(); audioSaveTimer.Stop();
            Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
        }
    }
}
