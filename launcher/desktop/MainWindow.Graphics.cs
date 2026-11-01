using System.Diagnostics;
using System.Text.Json;

namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.Graphics.cs. The same scheduling, labels and pacing; RC1's native GPU
// child window becomes the renderer's frames presented by GraphicsPreviewHost.
public partial class MainWindow {
    readonly DispatcherTimer graphicsPreviewTimer = new() { Interval = TimeSpan.FromMilliseconds(33) };
    readonly Stopwatch graphicsPreviewClock = new();
    readonly GameScenePreviewRenderer graphicsPreviewEnvironment = new();
    GamePreviewScene? graphicsScene;
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
    readonly Queue<double> graphicsPreviewFrameIntervals = new();
    bool graphicsPreviewBusy, graphicsPreviewClosed, graphicsPreviewFaulted;
    double? graphicsPreviewTestTime;
    CancellationTokenSource? graphicsPreviewLoad;

    void InitializeGraphicsPreview() {
        graphicsPreviewTimer.Tick += async (_, _) => {
            graphicsPreviewTimerPulses++;
            graphicsPreviewTimer.Stop();
            await RenderGraphicsPreview();
        };
        PageGraphics.PropertyChanged += (_, e) => { if (e.Property == IsVisibleProperty) RefreshGraphicsPreviewActivity(); };
        WindowStateChanged += RefreshGraphicsPreviewActivity;
        GraphicsPreviewStage.SizeChanged += (_, _) => InvalidateGraphicsPreview();
        GraphicsGpuView.RotationChanged += (_, _) => InvalidateGraphicsPreview();
        Closed += (_, _) => {
            graphicsPreviewClosed = true;
            graphicsPreviewTimer.Stop(); graphicsPreviewClock.Stop();
            StopGraphicsPreviewComposition();
            graphicsPreviewLoad?.Cancel(); graphicsPreviewLoad?.Dispose();
        };
    }

    bool GraphicsPreviewActive => !graphicsPreviewClosed && PageGraphics.IsEffectivelyVisible &&
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
        if (!GraphicsPreviewActive || graphicsScene == null || graphicsPreviewFaulted || staticCapture && graphicsPreviewFrames > 0) return;
        if (!graphicsPreviewCompositionHooked) {
            RequestAnimationFrame(GraphicsPreviewCompositionFrame);
            graphicsPreviewCompositionHooked = true;
        }
        if (graphicsPreviewBusy || graphicsPreviewTimer.IsEnabled) return;
        double remaining = (graphicsPreviewNextFrame - Stopwatch.GetTimestamp()) * 1000.0 / Stopwatch.Frequency;
        graphicsPreviewTimer.Interval = TimeSpan.FromMilliseconds(Math.Max(1, remaining));
        graphicsPreviewTimer.Start();
    }
    // CompositionTarget.Rendering: one callback per composed frame while the preview is active.
    void GraphicsPreviewCompositionFrame(TimeSpan time) {
        if (!graphicsPreviewCompositionHooked) return;
        graphicsPreviewCompositionPulses++;
        if (graphicsPreviewBusy) graphicsPreviewBusyPulses++;
        else if (Stopwatch.GetTimestamp() < graphicsPreviewNextFrame) graphicsPreviewBudgetPulses++;
        if (Stopwatch.GetTimestamp() >= graphicsPreviewNextFrame && !graphicsPreviewBusy) _ = RenderGraphicsPreview();
        if (graphicsPreviewCompositionHooked) RequestAnimationFrame(GraphicsPreviewCompositionFrame);
    }
    void StopGraphicsPreviewComposition() {
        graphicsPreviewCompositionHooked = false;
    }

    async void RefreshGraphicsPreviewSource() {
        if (!PageGraphics.IsEffectivelyVisible || !IsLoaded || graphicsPreviewClosed) return;
        string firstImport = settings.ImportFolder("file1"), secondImport = settings.ImportFolder("file2");
        string home = Settings.Home;
        string key = home + "|" + firstImport + "|" + secondImport;
        if (key == graphicsPreviewSource) return;
        graphicsPreviewSource = key;
        graphicsPreviewLoad?.Cancel(); graphicsPreviewLoad?.Dispose();
        var cancellation = graphicsPreviewLoad = new CancellationTokenSource();
        graphicsPreviewTimer.Stop(); graphicsPreviewClock.Reset();
        StopGraphicsPreviewComposition(); graphicsPreviewNextFrame = 0;
        graphicsScene = null; graphicsPreviewFrame = null;
        graphicsPreviewLastPublish = 0; graphicsPreviewFrameIntervals.Clear(); graphicsPreviewFps = 0;
        graphicsPreviewFaulted = false; graphicsPreviewVersion++;
        RoomPreview.Source = null;
        GraphicsGpuView.HasPresentedFrame = false;
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
        if (settings.Fullscreen && (Screens.ScreenFromWindow(this) ?? Screens.Primary) is { } screen)
            size = new(screen.Bounds.Width, screen.Bounds.Height);
        return new(settings.ResolvedInternalResolution, settings.TextureLinear, settings.ResolvedAnisotropy,
            settings.ResolvedAntiAliasing, settings.ResolvedAspect, settings.ResolvedWidescreen,
            settings.ResolvedFit, settings.LinearFilter, (int)Math.Round(Brightness.Value),
            Math.Round(Gamma.Value, 2), size.Width, size.Height, CoverPreview: true);
    }

    void InvalidateGraphicsPreview() {
        if (!initialized || graphicsPreviewClosed) return;
        graphicsPreviewOptions = ReadGraphicsPreviewOptions();
        graphicsPreviewVersion++;
        if (staticCapture) graphicsPreviewFrames = 0;
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
        double seconds = graphicsPreviewTestTime ?? (staticCapture ? 0 : graphicsPreviewClock.Elapsed.TotalSeconds);
        GraphicsGpuView.Visibility = Visibility.Visible;
        UpdateLayout();
        var size = GraphicsGpuView.PixelSize;
        int height = Math.Clamp(size.Height, 32, 4096), width = Math.Clamp(size.Width, 32, 4096);
        float yaw = GraphicsGpuView.Rotation.Yaw, pitch = GraphicsGpuView.Rotation.Pitch, zoom = GraphicsGpuView.Rotation.Zoom;
        graphicsPreviewTimer.Stop();
        graphicsPreviewBusy = true;
        // One frame in flight. The next frame starts when this one is displayed.
        graphicsPreviewNextFrame = Stopwatch.GetTimestamp() + Stopwatch.Frequency * 16 / 1000; // RC1 presents at display rate: about 60 fps
        var started = Stopwatch.GetTimestamp();
        try {
            var frame = await Task.Run(() => graphicsPreviewEnvironment.Render(scene, options, seconds, width, height, yaw, pitch, zoom));
            if (!GraphicsPreviewActive || scene != graphicsScene || version != graphicsPreviewVersion) return;
            GraphicsGpuView.Present(frame);
            graphicsPreviewFrame = frame; graphicsPreviewPublishedOptions = options; graphicsPreviewFrames++;
            graphicsPreviewRenderMilliseconds = Stopwatch.GetElapsedTime(started).TotalMilliseconds;
            long published = Stopwatch.GetTimestamp();
            if (graphicsPreviewLastPublish != 0) {
                graphicsPreviewFrameIntervals.Enqueue((published - graphicsPreviewLastPublish) / (double)Stopwatch.Frequency);
                if (graphicsPreviewFrameIntervals.Count > 15) graphicsPreviewFrameIntervals.Dequeue();
                graphicsPreviewFps = graphicsPreviewFrameIntervals.Count / graphicsPreviewFrameIntervals.Sum();
            }
            graphicsPreviewLastPublish = published;
            PreviewEmpty.Visibility = Visibility.Collapsed;
            GraphicsPreviewState.Text = staticCapture ? "Live preview" : $"{graphicsPreviewFps:0} FPS";
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
