using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    int slowUiTick;
    string backdropGame = "";
    bool backdropTransition;
    readonly Dictionary<string, BitmapImage> gameArtwork = new();
    async Task LoadArtworkAsync() {
        await Task.WhenAll(Enumerable.Range(1, 2).Select(async edition => {
            var image = await GameArtwork.FetchAsync(edition);
            if (image == null || !IsLoaded)
                return;
            gameArtwork["file" + edition] = image;
            ((Image)FindName("GamePoster" + edition)).Source = image;
            RefreshBackdrop();
        }));
    }
    void RefreshBackdrop() {
        if (backdropTransition)
            return;
        var cover = gameArtwork.GetValueOrDefault(settings.Game.Id);
        if (backdropGame == settings.Game.Id &&
            (cover == null || ReferenceEquals(Backdrop.Source, cover)))
            return;
        bool first = backdropGame.Length == 0;
        backdropGame = settings.Game.Id;
        var next = cover;
        if (first || !SystemParameters.ClientAreaAnimation) {
            Backdrop.Source = next;
            return;
        }
        backdropTransition = true;
        OutgoingBackdrop.Source = Backdrop.Source;
        Backdrop.Source = next;
        var duration = TimeSpan.FromMilliseconds(450);
        var easing = new CubicEase { EasingMode = EasingMode.EaseInOut };
        var fadeOut = new DoubleAnimation(1, 0, duration) { EasingFunction = easing };
        fadeOut.Completed += (_, _) => {
            OutgoingBackdrop.Source = null;
            OutgoingBackdrop.BeginAnimation(OpacityProperty, null);
            Backdrop.BeginAnimation(OpacityProperty, null);
            backdropTransition = false;
            RefreshBackdrop(); // Honor the latest selection if it changed during the fade.
        };
        Backdrop.BeginAnimation(OpacityProperty,
                                new DoubleAnimation(0, 1, duration) { EasingFunction = easing });
        OutgoingBackdrop.BeginAnimation(OpacityProperty, fadeOut);
    }
    void SelectGame(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching)
            return;
        settings.SelectedGame = (string)((Button)sender).Tag;
        try {
            settings.Save();
        } catch (System.IO.IOException error) {
            Status.Text = error.Message;
        }
        Status.Text = settings.Game.Id == "file2" ? "File #2 is not available yet." : "Ready";
        RefreshGameUi();
        UpdateSaves();
    }
    void ConfigureGame(object sender, RoutedEventArgs e) {
        if (game.Running || launching)
            return;
        SelectGame(sender, e);
        ShowPage("Setup");
    }
    void RefreshGameUi() {
        ExePath.Text = settings.GetExe();
        IsoPath.Text = settings.GetIso();
        ElfPath.Text = settings.GetElf(root);
        bool present = settings.Game.Id == "file1" && settings.FilesPresent(root);
        SkipIntros.IsEnabled = settings.Game.Id == "file1";
        SelectedGameLabel.Text = settings.Game.Name;
        RefreshBackdrop();
        foreach (int n in new[] { 1, 2 }) {
            string id = "file" + n;
            bool selected = settings.Game.Id == id;
            ((Border)FindName("GameCard" + n)).BorderBrush =
                (System.Windows.Media.Brush)FindResource(selected ? "Accent" : "Line");
            ((TextBlock)FindName("GameStatus" + n)).Text =
                id == "file2" ? "Coming later. Native build not yet available."
                : !(AppLayout.Packaged(root) ? LocalGameBuild.Available(root)
                                             : File.Exists(settings.GetExe(id)))
                    ? "Local build kit not installed."
                : settings.FilesPresent(root, id)
                    ? DiscImport.Ready(settings, id) ? "Ready to play." : "ISO ready to import."
                    : "Game files not configured.";
            var select = (Button)FindName("SelectGame" + n);
            select.Content = selected ? "Selected" : "Select";
            select.Background =
                (System.Windows.Media.Brush)FindResource(selected ? "SelectedSurface" : "Surface");
            select.IsEnabled = !game.Running && !launching;
            System.Windows.Automation.AutomationProperties.SetName(
                select, (selected ? "Selected: " : "Select: ") + GameDefinition.Find(id).Name);
            ((Button)FindName("ConfigureGame" + n)).IsEnabled = !game.Running && !launching;
        }
        LaunchButton.IsEnabled = present && OnlineOptions.Error(settings) == null && !updating &&
                                 !updateRestarting && !game.Running && !launching && !backingUp;
        RefreshOnlineUi();
        PlayDisplaySummary.Text =
            (settings.Fullscreen ? "Borderless" : DisplayOptions.Size(settings.WindowSize).Name) +
            " / " +
            (settings.ResolvedFit == "stretch"
                 ? "Stretched"
                 : settings.ResolvedAspect + " " + DisplayOptions.FitName(settings.ResolvedFit)) +
            " / " + (settings.LinearFilter ? "Bilinear" : "Nearest");
        PlayInputSummary.Text = controller.SelectedDevice.Name;
        RefreshReadyCheck();
        RefreshImportUi();
        if (PageCheats.Visibility == Visibility.Visible && cheatsGame != settings.Game.Id)
            RefreshCheats();
    }
    void StopGame(object sender, RoutedEventArgs e) {
        if (!game.Running)
            return;
        Status.Text =
            game.Process!.CloseMainWindow() ? "Closing game..." : "Waiting for the game window...";
    }
}
