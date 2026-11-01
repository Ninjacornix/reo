namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.Launcher.cs and MainWindow.GameFont.cs.
public partial class MainWindow {
    void InitializeLauncherSettings() {
        LauncherFontPicker.SelectedValue = settings.ResolvedLauncherFont;
        LauncherLanguagePicker.SelectedValue = "en";
        LauncherBackgroundMovies.IsChecked = settings.LauncherBackgroundMovies;
        ApplyLauncherFont();
    }
    void ApplyLauncherFont() {
        FontFamily font = settings.ResolvedLauncherFont switch {
            "tahoma" => SystemFont("Tahoma"),
            "segoe-ui" => SystemFont("Segoe UI"),
            _ => ownedGameFont ?? SystemFont("Segoe UI")
        };
        var resources = Application.Current!.Resources;
        if (!resources.TryGetResource("GameDisplayFont", null, out var current) || !Equals(current, font))
            resources["GameDisplayFont"] = font;
        LauncherFontHint.Visibility = settings.ResolvedLauncherFont == "outbreak" && !gameFontLoaded
            ? Visibility.Visible : Visibility.Collapsed;
    }
    // Segoe UI and Tahoma ship with Windows. Other desktops use their metric-compatible system
    // UI face when the named family is not installed.
    static FontFamily SystemFont(string name) => OperatingSystem.IsWindows() ? new FontFamily(name)
        : new FontFamily(name + ", " + (OperatingSystem.IsMacOS() ? "Helvetica Neue" : "DejaVu Sans"));
    void LauncherAppearanceChanged(object? sender, SelectionChangedEventArgs e) {
        if (!initialized) return;
        if (LauncherFontPicker.SelectedValue is not string font) return;
        settings.LauncherFont = font;
        settings.LauncherLanguage = "en";
        RefreshGameFont();
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
    }

    string gameFontRequest = "";
    bool gameFontLoaded;
    FontFamily? ownedGameFont;
    async void RefreshGameFont() {
        // This is the launcher's shared typeface. Keep the first validated owned
        // font across edition changes; swapping to Segoe UI and back reflows every
        // control, description and button while the next font loads.
        ApplyLauncherFont();
        if (gameFontLoaded) return;
        string edition = new[] { settings.Game.Id, "file1", "file2" }.Distinct()
            .FirstOrDefault(id => File.Exists(Path.Combine(settings.ImportFolder(id), "data", "NETBIO00.DAT")))
            ?? settings.Game.Id;
        string import = settings.ImportFolder(edition);
        string request = edition + "|" + import + "|" + Settings.Home;
        if (request == gameFontRequest) return;
        gameFontRequest = request;
        if (!File.Exists(Path.Combine(import, "data", "NETBIO00.DAT"))) return;
        try {
            string path = await Task.Run(() => GameFont.Ensure(import, edition, Settings.Home));
            if (gameFontRequest != request) return;
            var font = OwnedFontCollection.Load(path);
            if (font != null) {
                ownedGameFont = font;
                gameFontLoaded = true;
                ApplyLauncherFont();
            }
        } catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or
                                               ArgumentException or NotSupportedException) {
            // Font extraction is optional: setup and ordinary launcher text stay usable.
        }
    }
}
