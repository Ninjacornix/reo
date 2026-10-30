using System.Windows;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool refreshingGameSource;
    void RefreshGameSourceUi() {
        refreshingGameSource = true;
        UseGamePakSwitch.IsChecked = settings.UsesGamePak();
        UseGamePakSwitch.IsEnabled = !checkingDisc && !launching && !updating && !updateRestarting && !backingUp && !game.Running && importCancellation == null;
        GameSourceLabel.Text = settings.UsesGamePak() ? "Game PAK (.pak)" : "Disc image (.iso)";
        ChooseIsoButton.Content = settings.UsesGamePak() ? "Choose PAK" : "Choose ISO";
        refreshingGameSource = false;
    }
    void GameSourceChanged(object sender, RoutedEventArgs e) {
        if (!initialized || refreshingGameSource || launching || updating || updateRestarting || backingUp || game.Running || importCancellation != null) return;
        settings.SetGamePak(UseGamePakSwitch.IsChecked == true);
        discCheck = null;
        try { settings.Save(); }
        catch (Exception error) when (error is System.IO.IOException or UnauthorizedAccessException) { Status.Text = error.Message; }
        RefreshGameUi();
    }
}
