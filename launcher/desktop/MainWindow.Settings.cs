namespace Outbreak.Launcher.Desktop;

// Ports of RC1 MainWindow.Display.cs, MainWindow.Color.cs and MainWindow.Developer.cs.
public partial class MainWindow {
    void UpdateScreenFitHint() {
        AspectRatio.IsEnabled = settings.ResolvedFit != "stretch";
        if (this.FindNameScope()?.Find("ScreenFitHint") is not TextBlock hint)
            return;
        hint.Text = settings.ResolvedFit switch {
            "stretch" => "Fills the window. Picture proportions follow the window size.",
            "center" =>
                "Keeps the original pixel height, centered. Shrinks only when needed to fit.",
            "fill" => "Fills the window at the selected ratio. Edges may be cropped.",
            _ => "Centers the picture at the selected ratio, with black borders where needed."
        };
        if (settings.ResolvedAspect != "4:3" && settings.ResolvedFit != "stretch")
            hint.Text += settings.ResolvedWidescreen
                ? " Widescreen shows more of each room; menus, the HUD and text are stretched, movies stay 4:3."
                : " Stretched widens the original 4:3 picture; the camera view is unchanged.";
    }

    readonly DispatcherTimer colorSaveTimer = new() { Interval = TimeSpan.FromMilliseconds(250) };
    void InitializeColorPreview() {
        colorSaveTimer.Tick += (_, _) => {
            colorSaveTimer.Stop();
            SaveSettings(this, new());
        };
        Closed += (_, _) => colorSaveTimer.Stop();
        Closing += (_, _) => {
            if (colorSaveTimer.IsEnabled) {
                colorSaveTimer.Stop();
                SaveSettings(this, new());
            }
        };
        UpdateColorPreview();
    }
    void UpdateColorPreview() {
        int brightness = (int)Math.Round(Brightness.Value);
        double gamma = Math.Round(Gamma.Value, 2);
        BrightnessValue.Text = $"{brightness}%";
        GammaValue.Text = gamma.ToString("F2");
    }
    void ColorChanged(object? sender, Avalonia.Controls.Primitives.RangeBaseValueChangedEventArgs e) {
        if (!initialized)
            return;
        UpdateColorPreview();
        InvalidateGraphicsPreview();
        colorSaveTimer.Stop();
        colorSaveTimer.Start();
    }
    void ResetColor(object? sender, RoutedEventArgs e) {
        Brightness.Value = 100;
        Gamma.Value = 1;
    }

    void InitializeDeveloper() {
        var options = settings.Developer;
        DevNetworkTrace.IsChecked = options.NetworkTrace;
        DevTransportLog.IsChecked = options.TransportLog;
        DevSnapTrace.IsChecked = options.SnapTrace;
        DevFrameTiming.IsChecked = options.FrameTiming;
        DevGameClock.IsChecked = options.GameClock;
        DevCriServer.IsChecked = options.CriServerTiming;
        DevSlowdowns.IsChecked = options.RecordSlowdowns;
        DevStrictSlowdowns.IsChecked = options.StrictSlowdowns;
    }
    void DeveloperSettingChanged(object? sender, RoutedEventArgs e) {
        if (!initialized) return;
        var options = settings.Developer;
        options.NetworkTrace = DevNetworkTrace.IsChecked == true;
        options.TransportLog = DevTransportLog.IsChecked == true;
        options.SnapTrace = DevSnapTrace.IsChecked == true;
        options.FrameTiming = DevFrameTiming.IsChecked == true;
        options.GameClock = DevGameClock.IsChecked == true;
        options.CriServerTiming = DevCriServer.IsChecked == true;
        options.RecordSlowdowns = DevSlowdowns.IsChecked == true;
        options.StrictSlowdowns = DevStrictSlowdowns.IsChecked == true;
        DevStrictSlowdowns.IsEnabled = options.RecordSlowdowns;
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Could not save settings: " + error.Message;
        }
    }
    void RefreshDeveloperUi() {
        DevGameClock.IsEnabled = settings.Game.Id == "file1";
        DevCriServer.IsEnabled = settings.Game.Id == "file1";
        DevStrictSlowdowns.IsEnabled = DevSlowdowns.IsChecked == true;
        DeveloperSessionNote.Visibility = game.Running || launching ? Visibility.Visible : Visibility.Collapsed;
        var performance = game.PerformanceStatus;
        PerformanceRecordingStatus.Text = performance == null ? "Not recording. Enable for your next launch." : performance.State + " · " + performance.Detail;
        MarkPerformanceProblem.IsEnabled = game.Running && performance?.State is ("recording" or "limited recording");
    }
    void OpenSessionFolders(object? sender, RoutedEventArgs e) =>
        OpenFolder(Path.Combine(Settings.Home, "sessions"));
    string? performanceNotified, performanceErrorNotified;
    void RefreshPerformanceNotification() {
        var performance = game.PerformanceStatus;
        if (performance?.Latest is {} latest && performanceNotified != latest) {
            performanceNotified = latest;
            Status.Text = "Performance report saved";
        }
        if (performance?.State == "unavailable" && performanceErrorNotified != performance.Detail) {
            performanceErrorNotified = performance.Detail;
            Status.Text = performance.Detail;
        }
    }
    void OpenPerformanceReports(object? sender, RoutedEventArgs e) {
        string sessions = Path.Combine(Settings.Home, "sessions");
        try { OpenFolder(SlowdownMonitor.LatestReport(sessions) ?? sessions); }
        catch (Exception error) { Status.Text = "Could not open reports: " + error.Message; }
    }
    void MarkProblem(object? sender, RoutedEventArgs e) {
        try { game.Performance?.MarkProblem(); }
        catch (Exception error) { Status.Text = "Could not mark problem: " + error.Message; }
    }
    async void ExportPerformanceReport(object? sender, RoutedEventArgs e) {
        try {
            string? report = await Task.Run(() => SlowdownMonitor.LatestReport(Path.Combine(Settings.Home, "sessions")));
            if (report == null) { Status.Text = "No performance reports have been saved yet."; return; }
            var dialog = new SaveFileDialog { Title = "Export performance report", Filter = "ZIP archive (*.zip)|*.zip",
                FileName = "Outbreak-performance-" + Path.GetFileName(report) + ".zip" };
            if (await dialog.ShowDialog(this) != true) return;
            await Task.Run(() => SlowdownMonitor.Export(report, dialog.FileName));
            Status.Text = "Performance report exported.";
        } catch (Exception error) { Status.Text = "Could not export report: " + error.Message; }
    }
}
