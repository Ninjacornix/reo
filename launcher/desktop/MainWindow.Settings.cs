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
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Could not save settings: " + error.Message;
        }
    }
    void RefreshDeveloperUi() {
        DevGameClock.IsEnabled = settings.Game.Id == "file1";
        DevCriServer.IsEnabled = settings.Game.Id == "file1";
        DeveloperSessionNote.Visibility = game.Running || launching ? Visibility.Visible : Visibility.Collapsed;
    }
    void OpenSessionFolders(object? sender, RoutedEventArgs e) =>
        OpenFolder(Path.Combine(Settings.Home, "sessions"));
}
