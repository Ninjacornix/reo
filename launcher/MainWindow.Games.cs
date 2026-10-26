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
    // File #2 runs only from a developer tree (its native build is not packaged yet).
    bool Playable(string id) => id == "file1" || (id == "file2" && !AppLayout.Packaged(root));
    async Task LoadArtworkAsync() {
        if (args.Contains("--public-preview"))
            return; // user-supplied covers stay out of published screenshots
        await Task.WhenAll(Enumerable.Range(1, 2).Select(async edition => {
            var image = await GameArtwork.FetchAsync(edition);
            if (image == null || !IsLoaded)
                return;
            gameArtwork["file" + edition] = image;
            ((Image)FindName("GamePoster" + edition)).Source = image;
            ((Border)FindName("PosterFrame" + edition)).Visibility = Visibility.Visible;
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
    void GameSelectionChanged(object sender, SelectionChangedEventArgs e) {
        if (GamePicker.SelectedItem is ListBoxItem item && (string)item.Tag != settings.Game.Id)
            SelectGame(item, e);
    }
    void SelectGame(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching || updating || backingUp || updateRestarting)
            return;
        settings.SelectedGame = (string)((FrameworkElement)sender).Tag;
        try {
            if (!args.Contains("--screenshot"))
                settings.Save();
        } catch (System.IO.IOException error) {
            Status.Text = error.Message;
        }
        Status.Text = Playable(settings.Game.Id) ? "Ready" : "File #2 is not available yet.";
        RefreshGameUi();
        UpdateSaves();
    }
    void RefreshGameUi() {
        ExePath.Text = settings.GetExe();
        IsoPath.Text = settings.GetIso();
        ElfPath.Text = settings.GetElf(root);
        bool present = Playable(settings.Game.Id) && settings.FilesPresent(root);
        SelectedGameLabel.Text = settings.Game.Name;
        RefreshBackdrop();
        GamePicker.SelectedValue = settings.Game.Id;
        GamePicker.IsEnabled =
            !game.Running && !launching && !updating && !updateRestarting && !backingUp;
        foreach (int n in new[] { 1, 2 }) {
            string id = "file" + n;
            bool selected = settings.Game.Id == id;
            ((Border)FindName("GameCard" + n)).BorderBrush =
                (System.Windows.Media.Brush)FindResource(selected ? "Accent" : "Line");
            ((TextBlock)FindName("GameStatus" + n)).Text =
                !Playable(id) ? "Coming later"
                : selected && game.Running ? "Running"
                : !(AppLayout.Packaged(root) ? LocalGameBuild.Available(root)
                                             : File.Exists(settings.GetExe(id)))
                    ? (AppLayout.Packaged(root) ? "Setup needed: download incomplete" : "No developer build")
                : !File.Exists(settings.GetIso(id)) ? "Choose your game disc"
                : DiscImport.Ready(settings, id) && File.Exists(settings.GetExe(id)) ? "Ready to play"
                                                                                       : "Not built yet";
        }
        LaunchButton.IsEnabled =
            present && !updating && !updateRestarting && !game.Running && !launching && !backingUp;
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
        ModControls.IsEnabled = settings.Game.Id == "file1" && !game.Running && !launching;
        if (PageMods.Visibility == Visibility.Visible && modsGame != settings.Game.Id)
            RefreshMods();
    }
    void StopGame(object sender, RoutedEventArgs e) {
        if (!game.Running)
            return;
        Status.Text =
            game.Process!.CloseMainWindow() ? "Closing game..." : "Waiting for the game window...";
    }
}
