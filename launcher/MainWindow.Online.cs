using System.IO;
using System.Windows;
using System.Windows.Media;

namespace Outbreak.Launcher;

public partial class MainWindow {
    void InitializeOnline() {
        OnlineLaunch.IsChecked = settings.OnlineLaunch;
        CoopHost.Text = settings.CoopHost;
        AccountUsername.Text = settings.AccountUsername;
        AccountUsername.MaxLength = OnlineOptions.MaxUsernameLength;
    }

    void OnlineSettingChanged(object sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        settings.OnlineLaunch = OnlineLaunch.IsChecked == true;
        settings.CoopHost = CoopHost.Text.Trim();
        settings.AccountUsername = AccountUsername.Text;
        try {
            settings.Save();
            Status.Text = "Saved · Changes apply on the next launch";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
        RefreshGameUi();
    }

    void RefreshOnlineUi() {
        bool supported = settings.Game.Id == "file1";
        CoopControls.IsEnabled =
            supported && !updating && !updateRestarting && !game.Running && !launching;
        CoopUnavailable.Visibility = supported ? Visibility.Collapsed : Visibility.Visible;
        string? error = OnlineOptions.Error(settings);
        CoopValidation.Text = error ?? "";
        CoopValidation.Visibility = error == null ? Visibility.Collapsed : Visibility.Visible;
        CoopValidation.Foreground = (Brush)FindResource("Accent");
        PlayNetworkSummary.Text =
            settings.OnlineLaunch ? "Online / " + settings.CoopHost : "Offline";
        if (!game.Running && !launching)
            LaunchButton.Content = settings.OnlineLaunch ? "Play online" : "Play";
    }
}
