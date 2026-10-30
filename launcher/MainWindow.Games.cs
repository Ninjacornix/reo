using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Animation;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    int slowUiTick;
    string artworkLoadKey = "";
    string backdropGame = "";
    bool backdropTransition;
    readonly Dictionary<string, BitmapSource> backdropArtwork = new();
    bool Playable(string id) => id is "file1" or "file2";
    async Task LoadArtworkAsync() {
        if (!IsLoaded || args.Contains("--public-preview"))
            return; // user-supplied covers stay out of published screenshots
        var sources = new[] { settings.GetIso("file1"), settings.GetIso("file2") };
        string key = GameArtwork.CacheKey(sources.Concat(new[] { GameArtwork.Folder, GameArtwork.DownloadFolder }));
        if (artworkLoadKey == key)
            return;
        artworkLoadKey = key;
        await Task.WhenAll(Enumerable.Range(1, 2).Select(async edition => {
            var image = await GameArtwork.FetchAsync(edition, sources[edition - 1]);
            if (!IsLoaded || artworkLoadKey != key)
                return;
            var gameCase = (GameCaseView)FindName("GameCase" + edition);
            gameCase.Cover = image?.Front;
            gameCase.BackCover = image?.Back;
            gameCase.SpineCover = image?.Spine;
            if (image == null)
                backdropArtwork.Remove("file" + edition);
            else {
                var front = image.Front;
                var backdrop = new CroppedBitmap(front, new Int32Rect(0,
                    (int)(front.PixelHeight * 0.14), front.PixelWidth,
                    Math.Max(1, (int)(front.PixelHeight * 0.72))));
                backdrop.Freeze();
                backdropArtwork["file" + edition] = backdrop;
            }
            RefreshBackdrop();
        }));
    }
    void RefreshBackdrop() {
        if (backdropTransition)
            return;
        var next = backdropArtwork.GetValueOrDefault(settings.Game.Id);
        if (backdropGame == settings.Game.Id && ReferenceEquals(Backdrop.Source, next))
            return;
        bool first = backdropGame.Length == 0;
        backdropGame = settings.Game.Id;
        UpdateArtworkVisibility();
        if (first || !SystemParameters.ClientAreaAnimation) {
            Backdrop.Source = next;
            UpdateArtworkVisibility();
            return;
        }
        backdropTransition = true;
        OutgoingBackdrop.Source = Backdrop.Source;
        Backdrop.Source = next;
        var duration = TimeSpan.FromMilliseconds(450);
        var easing = new CubicEase { EasingMode = EasingMode.EaseInOut };
        var fade = new DoubleAnimation(1, 0, duration) { EasingFunction = easing };
        fade.Completed += (_, _) => {
            OutgoingBackdrop.Source = null;
            OutgoingBackdrop.BeginAnimation(OpacityProperty, null);
            Backdrop.BeginAnimation(OpacityProperty, null);
            backdropTransition = false;
            UpdateArtworkVisibility();
            RefreshBackdrop();
        };
        Backdrop.BeginAnimation(OpacityProperty, new DoubleAnimation(0, 1, duration) { EasingFunction = easing });
        OutgoingBackdrop.BeginAnimation(OpacityProperty, fade);
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
        RefreshGameFont();
        ExePath.Text = settings.GetExe();
        IsoPath.Text = settings.GetGameSource();
        ElfPath.Text = settings.GetElf(root);
        bool present = Playable(settings.Game.Id) && settings.FilesPresent(root);
        if (IsLoaded)
            _ = LoadArtworkAsync();
        SelectedGameLabel.Text = settings.Game.Name;
        UpdateAudioAvailability();
        RefreshBackgroundVideos();
        RefreshBackdrop();
        GamePicker.SelectedValue = settings.Game.Id;
        GamePicker.IsEnabled =
            !game.Running && !launching && !updating && !updateRestarting && !backingUp;
        foreach (int n in new[] { 1, 2 }) {
            string id = "file" + n;
            bool selected = settings.Game.Id == id;
            var gameCase = (GameCaseView)FindName("GameCase" + n);
            gameCase.IsSelected = selected;
            gameCase.IsAvailable =
                Playable(id) && File.Exists(settings.GetExe(id)) && File.Exists(settings.GetIso(id));
            string gameStatus =
                !Playable(id) ? "Coming later"
                : selected && game.Running ? "Running"
                : !(AppLayout.Packaged(root) ? LocalGameBuild.Available(root, id)
                                             : File.Exists(settings.GetExe(id)))
                    ? (AppLayout.Packaged(root) ? "Game setup files missing" : "No developer build")
                : !File.Exists(settings.GetGameSource(id)) ? "Choose your game source"
                : DiscImport.Ready(settings, id) && File.Exists(settings.GetExe(id)) ? "Ready to play"
                                                                                       : "Not built yet";
            System.Windows.Automation.AutomationProperties.SetItemStatus(
                (ListBoxItem)GamePicker.Items[n - 1], gameStatus);
        }
        LaunchButton.IsEnabled =
            present && !updating && !updateRestarting && !game.Running && !launching && !backingUp;
        RefreshOnlineUi();
        RefreshStorageUi();
        PlayDisplaySummary.Text =
            (settings.Fullscreen ? "Borderless" : DisplayOptions.Size(settings.WindowSize).Name) +
            " / " +
            (settings.ResolvedFit == "stretch"
                 ? "Stretched"
                 : settings.ResolvedAspect + (settings.ResolvedAspect == "4:3" ? "" : settings.ResolvedWidescreen ? " widescreen" : " stretched") +
                       " " + DisplayOptions.FitName(settings.ResolvedFit)) +
            " / " + (settings.LinearFilter ? "Bilinear" : "Nearest");
        PlayInputSummary.Text = controller.SelectedDevice.Name;
        PlayModsSummary.Text = ModsSummary();
        PlayCheatsSummary.Text = CheatsSummary();
        RefreshAssetPakSummary();
        RefreshReadyCheck();
        RefreshImportUi();
        if (PageCheats.Visibility == Visibility.Visible && cheatsGame != settings.Game.Id)
            RefreshCheats();
        ModControls.IsEnabled = !game.Running && !launching;
        if (PageMods.Visibility == Visibility.Visible && modsGame != settings.Game.Id)
            RefreshMods();
    }
    void StopGame(object sender, RoutedEventArgs e) {
        if (!game.Running)
            return;
        Status.Text =
            game.Process!.CloseMainWindow() ? "Closing game..." : "Waiting for the game window...";
    }
    static string NameList(List<string> names) =>
        names.Count == 0 ? "Off"
        : names.Count <= 2 ? string.Join(", ", names)
                           : $"{names[0]}, {names[1]} +{names.Count - 2} more";
    string ModsSummary() {
        // Guests play with the host's mods; their own selection waits for solo or hosted games.
        if (settings.ResolvedCoopMode == "join")
            return "Host's choice";
        if (settings.ActiveMods.Count == 0)
            return "Off";
        try {
            var installed = Mods.Load(null, settings.Game.Id);
            return NameList(settings.ActiveMods.Distinct().Select(id =>
                installed.FirstOrDefault(m => m.Manifest?.Id == id)?.Manifest?.Name is { Length: > 0 } name ? name : id).ToList());
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return settings.ActiveMods.Count + " on";
        }
    }
    string CheatsSummary() {
        if (!settings.CheatsEnabled || settings.EnabledCheats.Count == 0)
            return "Off";
        try {
            return NameList(Cheats.Load(settings.Game.Id).Where(g => settings.EnabledCheats.Contains(g.Id))
                                .Select(g => g.Name).ToList());
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return "On";
        }
    }
}
