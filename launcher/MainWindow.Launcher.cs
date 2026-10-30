using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    void InitializeLauncherSettings() {
        LauncherFontPicker.SelectedValue = settings.ResolvedLauncherFont;
        LauncherLanguagePicker.SelectedValue = "en";
        LauncherBackgroundMovies.IsChecked = settings.LauncherBackgroundMovies;
        ApplyLauncherFont();
    }
    void ApplyLauncherFont() {
        FontFamily font = settings.ResolvedLauncherFont switch {
            "tahoma" => new FontFamily("Tahoma"),
            "segoe-ui" => new FontFamily("Segoe UI"),
            _ => ownedGameFont ?? new FontFamily("Segoe UI")
        };
        if (!Equals(Application.Current.Resources["GameDisplayFont"], font))
            Application.Current.Resources["GameDisplayFont"] = font;
        LauncherFontHint.Visibility = settings.ResolvedLauncherFont == "outbreak" && !gameFontLoaded
            ? Visibility.Visible : Visibility.Collapsed;
    }
    void LauncherAppearanceChanged(object sender, SelectionChangedEventArgs e) {
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
}
