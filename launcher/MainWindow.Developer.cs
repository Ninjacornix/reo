using System.IO;
using System.Windows;

namespace Outbreak.Launcher;
public partial class MainWindow {
    void InitializeDeveloper() {
        var options = settings.Developer;
        DevNetworkTrace.IsChecked = options.NetworkTrace;
        DevTransportLog.IsChecked = options.TransportLog;
        DevSnapTrace.IsChecked = options.SnapTrace;
        DevFrameTiming.IsChecked = options.FrameTiming;
        DevGameClock.IsChecked = options.GameClock;
    }
    void DeveloperSettingChanged(object sender, RoutedEventArgs e) {
        if (!initialized) return;
        var options = settings.Developer;
        options.NetworkTrace = DevNetworkTrace.IsChecked == true;
        options.TransportLog = DevTransportLog.IsChecked == true;
        options.SnapTrace = DevSnapTrace.IsChecked == true;
        options.FrameTiming = DevFrameTiming.IsChecked == true;
        options.GameClock = DevGameClock.IsChecked == true;
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Could not save settings: " + error.Message;
        }
    }
    void RefreshDeveloperUi() {
        DevGameClock.IsEnabled = settings.Game.Id == "file1";
        DeveloperSessionNote.Visibility = game.Running || launching ? Visibility.Visible : Visibility.Collapsed;
    }
    void OpenSessionFolders(object sender, RoutedEventArgs e) =>
        OpenFolder(Path.Combine(Settings.Home, "sessions"));
}
