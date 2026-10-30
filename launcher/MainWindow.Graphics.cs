using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly DispatcherTimer graphicsPreviewTimer = new() { Interval = TimeSpan.FromMilliseconds(33) };
    readonly Stopwatch graphicsPreviewClock = new();
    readonly GameScenePreviewRenderer graphicsPreviewEnvironment = new();
    GamePreviewScene? graphicsScene;
    WriteableBitmap? graphicsPreviewBitmap;
    PreviewFrame? graphicsPreviewFrame;
    PreviewRenderOptions? graphicsPreviewOptions;
    PreviewRenderOptions? graphicsPreviewPublishedOptions;
    string graphicsPreviewSource = "";
    int graphicsPreviewVersion, graphicsPreviewFrames;
    double graphicsPreviewRenderMilliseconds, graphicsPreviewFps;
    long graphicsPreviewLastPublish;
    long graphicsPreviewNextFrame;
    int graphicsPreviewCompositionPulses, graphicsPreviewBusyPulses, graphicsPreviewBudgetPulses, graphicsPreviewTimerPulses;
    bool graphicsPreviewCompositionHooked;
    GpuPreviewStats graphicsPreviewGpuStats;
    readonly Queue<double> graphicsPreviewFrameIntervals = new();
    bool graphicsPreviewBusy, graphicsPreviewClosed, graphicsPreviewFaulted;
    double? graphicsPreviewTestTime;
    bool graphicsPreviewSuppressReadback;
    CancellationTokenSource? graphicsPreviewLoad;
    bool GraphicsPreviewReadback => !graphicsPreviewSuppressReadback && (args.Contains("--test-graphics-ui") || args.Contains("--screenshot"));

    void InitializeGraphicsPreview() {
        graphicsPreviewTimer.Tick += async (_, _) => {
            graphicsPreviewTimerPulses++;
            graphicsPreviewTimer.Stop();
            await RenderGraphicsPreview();
        };
        PageGraphics.IsVisibleChanged += (_, _) => RefreshGraphicsPreviewActivity();
        StateChanged += (_, _) => RefreshGraphicsPreviewActivity();
        GraphicsPreviewStage.SizeChanged += (_, _) => InvalidateGraphicsPreview();
        GraphicsGpuView.RotationChanged += (_, _) => InvalidateGraphicsPreview();
        Closed += (_, _) => {
            graphicsPreviewClosed = true;
            graphicsPreviewTimer.Stop(); graphicsPreviewClock.Stop();
            StopGraphicsPreviewComposition();
            GraphicsGpuView.Renderer.Dispose();
            graphicsPreviewLoad?.Cancel(); graphicsPreviewLoad?.Dispose();
        };
    }

    bool GraphicsPreviewActive => !graphicsPreviewClosed && PageGraphics.IsVisible &&
        WindowState != WindowState.Minimized && !game.Running && !launching;

    void RefreshGraphicsPreviewActivity() {
        if (graphicsPreviewClosed) return;
        if (GraphicsPreviewActive) {
            RefreshGraphicsPreviewSource();
            if (graphicsScene != null && !graphicsPreviewFaulted) {
                if (!graphicsPreviewClock.IsRunning) {
                    graphicsPreviewClock.Start();
                    GraphicsPreviewState.Text = "Live preview";
                }
                ScheduleGraphicsPreview();
            }
        } else {
            graphicsPreviewTimer.Stop(); graphicsPreviewClock.Stop();
            StopGraphicsPreviewComposition();
            graphicsPreviewNextFrame = 0;
            graphicsPreviewLastPublish = 0; graphicsPreviewFrameIntervals.Clear(); graphicsPreviewFps = 0;
            if (graphicsScene != null) GraphicsPreviewState.Text = "Preview paused";
        }
    }

    void ScheduleGraphicsPreview() {
        if (!GraphicsPreviewActive || graphicsScene == null || graphicsPreviewFaulted) return;
        if (!graphicsPreviewCompositionHooked) {
            CompositionTarget.Rendering += GraphicsPreviewCompositionFrame;
            graphicsPreviewCompositionHooked = true;
        }
        if (graphicsPreviewBusy || graphicsPreviewTimer.IsEnabled) return;
        double remaining = (graphicsPreviewNextFrame - Stopwatch.GetTimestamp()) * 1000.0 / Stopwatch.Frequency;
        graphicsPreviewTimer.Interval = TimeSpan.FromMilliseconds(Math.Max(1, remaining));
        graphicsPreviewTimer.Start();
    }
    void GraphicsPreviewCompositionFrame(object? sender, EventArgs e) {
        graphicsPreviewCompositionPulses++;
        if (graphicsPreviewBusy) graphicsPreviewBusyPulses++;
        else if (Stopwatch.GetTimestamp() < graphicsPreviewNextFrame) graphicsPreviewBudgetPulses++;
        if (Stopwatch.GetTimestamp() >= graphicsPreviewNextFrame && !graphicsPreviewBusy) _ = RenderGraphicsPreview();
    }
    void StopGraphicsPreviewComposition() {
        if (!graphicsPreviewCompositionHooked) return;
        CompositionTarget.Rendering -= GraphicsPreviewCompositionFrame; graphicsPreviewCompositionHooked = false;
    }

    async void RefreshGraphicsPreviewSource() {
        if (!PageGraphics.IsVisible || !IsLoaded || graphicsPreviewClosed) return;
        string firstImport = settings.ImportFolder("file1"), secondImport = settings.ImportFolder("file2");
        string home = Settings.Home;
        string key = home + "|" + firstImport + "|" + secondImport;
        if (key == graphicsPreviewSource) return;
        graphicsPreviewSource = key;
        graphicsPreviewLoad?.Cancel(); graphicsPreviewLoad?.Dispose();
        var cancellation = graphicsPreviewLoad = new CancellationTokenSource();
        graphicsPreviewTimer.Stop(); graphicsPreviewClock.Reset();
        StopGraphicsPreviewComposition(); graphicsPreviewNextFrame = 0;
        graphicsScene = null; graphicsPreviewBitmap = null; graphicsPreviewFrame = null;
        graphicsPreviewLastPublish = 0; graphicsPreviewFrameIntervals.Clear(); graphicsPreviewFps = 0;
        graphicsPreviewFaulted = false; graphicsPreviewVersion++;
        RoomPreview.Source = null; RoomPreview.Effect = null;
        GraphicsGpuView.Visibility = Visibility.Collapsed; RoomPreview.Visibility = Visibility.Collapsed;
        PreviewEmpty.Text = "Loading Kevin…"; PreviewEmpty.Visibility = Visibility.Visible;
        GraphicsPreviewState.Text = "Loading";
        try {
            var scene = await Task.Run(() => GamePreviewAssets.LoadShared(firstImport, secondImport, home), cancellation.Token);
            if (cancellation.IsCancellationRequested || graphicsPreviewClosed || key != graphicsPreviewSource) return;
            graphicsScene = scene;
            if (scene == null) {
                PreviewEmpty.Text = "Import the game or export its asset pack to preview Kevin.";
                GraphicsPreviewState.Text = "Preview unavailable";
                return;
            }
            InvalidateGraphicsPreview(); RefreshGraphicsPreviewActivity();
        } catch (OperationCanceledException) { }
        catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or
            JsonException or ArgumentException or NotSupportedException or OverflowException) {
            if (cancellation.IsCancellationRequested || graphicsPreviewClosed || key != graphicsPreviewSource) return;
            PreviewEmpty.Text = "Kevin’s preview could not be loaded. Check the game import or asset pack.";
            GraphicsPreviewState.Text = "Preview unavailable";
            System.Diagnostics.Debug.WriteLine(error);
        }
    }

    PreviewRenderOptions ReadGraphicsPreviewOptions() {
        var size = DisplayOptions.Size(settings.WindowSize);
        if (settings.Fullscreen) {
            var dpi = VisualTreeHelper.GetDpi(this);
            size = new((int)(SystemParameters.PrimaryScreenWidth * dpi.DpiScaleX),
                (int)(SystemParameters.PrimaryScreenHeight * dpi.DpiScaleY));
        }
        return new(settings.ResolvedInternalResolution, settings.TextureLinear, settings.ResolvedAnisotropy,
            settings.ResolvedAntiAliasing, settings.ResolvedAspect, settings.ResolvedWidescreen,
            settings.ResolvedFit, settings.LinearFilter, (int)Math.Round(Brightness.Value),
            Math.Round(Gamma.Value, 2), size.Width, size.Height, CoverPreview: true);
    }

    void InvalidateGraphicsPreview() {
        if (!initialized || graphicsPreviewClosed) return;
        graphicsPreviewOptions = ReadGraphicsPreviewOptions();
        graphicsPreviewVersion++;
        if (GraphicsPreviewActive && graphicsScene != null && !graphicsPreviewBusy && !graphicsPreviewFaulted)
            _ = RenderGraphicsPreview();
    }

    async Task RenderGraphicsPreview() {
        if (!GraphicsPreviewActive || graphicsScene == null || graphicsPreviewBusy || graphicsPreviewFaulted ||
            GraphicsPreviewStage.ActualWidth < 32 || GraphicsPreviewStage.ActualHeight < 32) return;
        if (Stopwatch.GetTimestamp() < graphicsPreviewNextFrame) { ScheduleGraphicsPreview(); return; }
        var scene = graphicsScene;
        var options = graphicsPreviewOptions ?? ReadGraphicsPreviewOptions();
        int version = graphicsPreviewVersion;
        double seconds = graphicsPreviewTestTime ?? graphicsPreviewClock.Elapsed.TotalSeconds;
        GraphicsGpuView.Visibility = Visibility.Visible;
        UpdateLayout();
        nint window = GraphicsGpuView.Handle;
        if (window == 0) { ScheduleGraphicsPreview(); return; }
        var size = GraphicsGpuView.PixelSize;
        int height = Math.Clamp(size.Height, 32, 4096), width = Math.Clamp(size.Width, 32, 4096);
        float yaw = GraphicsGpuView.Rotation.Yaw, pitch = GraphicsGpuView.Rotation.Pitch, zoom = GraphicsGpuView.Rotation.Zoom;
        bool readback = GraphicsPreviewReadback;
        float opacity = (float)PageContent.Opacity;
        graphicsPreviewTimer.Stop();
        graphicsPreviewBusy = true;
        // Poll the swap-chain readiness without blocking WPF. Skinning and GPU
        // work only run when DXGI has room for another displayed frame.
        graphicsPreviewNextFrame = Stopwatch.GetTimestamp() + Stopwatch.Frequency * 8 / 1000;
        try {
            var result = await Task.Run(() => GraphicsGpuView.Renderer.Render(window, scene,
                graphicsPreviewEnvironment.EnvironmentMeshes, graphicsPreviewEnvironment.EnvironmentTextures,
                options, seconds, width, height, yaw, pitch, zoom, readback, opacity));
            if (!GraphicsPreviewActive || scene != graphicsScene || version != graphicsPreviewVersion) return;
            var frame = result.Frame;
            graphicsPreviewGpuStats = result.Stats;
            if (!result.Presented && !readback) return;
            if (result.Presented) GraphicsGpuView.HasPresentedFrame = true;
            if (frame.Bgra.Length != 0) {
                var dpi = VisualTreeHelper.GetDpi(this);
                if (graphicsPreviewBitmap == null || graphicsPreviewBitmap.PixelWidth != frame.Width || graphicsPreviewBitmap.PixelHeight != frame.Height)
                    graphicsPreviewBitmap = new WriteableBitmap(frame.Width, frame.Height, dpi.PixelsPerInchX, dpi.PixelsPerInchY, PixelFormats.Bgra32, null);
                graphicsPreviewBitmap.WritePixels(new Int32Rect(0, 0, frame.Width, frame.Height), frame.Bgra, frame.Width * 4, 0);
                RoomPreview.Width = GraphicsGpuView.ActualWidth; RoomPreview.Height = GraphicsGpuView.ActualHeight;
                RoomPreview.Effect = null; RoomPreview.Source = graphicsPreviewBitmap; RoomPreview.Visibility = Visibility.Visible;
            }
            graphicsPreviewFrame = frame; graphicsPreviewPublishedOptions = options; graphicsPreviewFrames++;
            graphicsPreviewRenderMilliseconds = graphicsPreviewGpuStats.GpuMilliseconds;
            long published = Stopwatch.GetTimestamp();
            if (graphicsPreviewLastPublish != 0) {
                graphicsPreviewFrameIntervals.Enqueue((published - graphicsPreviewLastPublish) / (double)Stopwatch.Frequency);
                if (graphicsPreviewFrameIntervals.Count > 15) graphicsPreviewFrameIntervals.Dequeue();
                graphicsPreviewFps = graphicsPreviewFrameIntervals.Count / graphicsPreviewFrameIntervals.Sum();
            }
            graphicsPreviewLastPublish = published;
            PreviewEmpty.Visibility = Visibility.Collapsed;
            GraphicsPreviewState.Text = $"{graphicsPreviewFps:0} FPS";
        } catch (OperationCanceledException) when (graphicsPreviewClosed || !GraphicsPreviewActive) { }
        catch (Exception error) when (error is IOException or InvalidDataException or ArgumentException or OverflowException or
            DllNotFoundException or EntryPointNotFoundException or BadImageFormatException) {
            graphicsPreviewFaulted = true; graphicsPreviewTimer.Stop();
            StopGraphicsPreviewComposition(); GraphicsGpuView.Visibility = Visibility.Collapsed;
            GraphicsPreviewState.Text = "Preview unavailable";
            PreviewEmpty.Text = "Kevin’s GPU preview could not be rendered."; PreviewEmpty.Visibility = Visibility.Visible;
            Debug.WriteLine(error);
        } finally {
            graphicsPreviewBusy = false;
            ScheduleGraphicsPreview();
        }
    }
}
