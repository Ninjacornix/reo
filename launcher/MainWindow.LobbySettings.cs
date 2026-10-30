using System.Windows;

namespace Outbreak.Launcher;
public partial class MainWindow {
    sealed record RoomChoice(int Value, string Label) {
        public override string ToString() => Label;
    }
    bool refreshingLobbySettings;
    string lobbyChoicesEdition = "";
    void InitializeLobbySettings() {
        RoomName.Text = settings.RoomName;
        RoomPlayers.ItemsSource = new[] { new RoomChoice(2, "2 players"), new RoomChoice(3, "3 players"), new RoomChoice(4, "4 players") };
        RefreshLobbySettings();
    }
    void RefreshLobbySettings() {
        refreshingLobbySettings = true;
        try {
            if (lobbyChoicesEdition != settings.Game.Id) {
                RoomWait.ItemsSource = LobbySettings.WaitTimes(settings.Game.Id).Select(n => new RoomChoice(n, n + " minutes")).ToArray();
                lobbyChoicesEdition = settings.Game.Id;
            }
            RoomPlayers.SelectedValue = settings.ResolvedRoomMaxPlayers;
            RoomWait.SelectedValue = settings.ResolvedRoomWaitMinutes;
            RoomSettings.Visibility = settings.ResolvedCoopMode == "host" ? Visibility.Visible : Visibility.Collapsed;
            RoomSettings.IsEnabled = settings.AutoLobby;
        } finally { refreshingLobbySettings = false; }
    }
    void RoomSettingChanged(object sender, RoutedEventArgs e) {
        if (!initialized || refreshingLobbySettings) return;
        settings.RoomName = RoomName.Text.Trim();
        if (RoomPlayers.SelectedValue is int players) settings.RoomMaxPlayers = players;
        if (RoomWait.SelectedValue is int minutes) settings.RoomWaitMinutes = minutes;
        SaveOnlineSettings();
        RefreshOnlineUi();
    }
}
