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
    Task artworkLoadTask = Task.CompletedTask;
    string backdropGame = "";
    bool backdropTransition;
    readonly Dictionary<string, BitmapSource> backdropArtwork = new();
    bool Playable(string id) => id is "file1" or "file2";
    string PlayButtonLabel => settings.Game.Id == "file2" ? "Play File #2" : "Play File #1";
    void KeepPlayViewport(object sender, RequestBringIntoViewEventArgs e) {
        // Selecting a case must not automatically scroll the enclosing Play
        // page to fit the entire description. Wheel/scrollbar input stays native.
        e.Handled = true;
    }
    Task LoadArtworkAsync() {
        if (!IsLoaded) return Task.CompletedTask;
        bool publicPreview = args.Contains("--public-preview");
        // Redact personal covers in screenshots, while retaining the verified
        // downloaded DVD labels. A preview must not replace them with bare discs.
        var sources = publicPreview ? new[] { "", "" } : new[] { settings.GetIso("file1"), settings.GetIso("file2") };
        string key = GameArtwork.CacheKey(sources.Concat(new[] { GameArtwork.Folder, GameArtwork.DownloadFolder }));
        if (artworkLoadKey == key)
            return artworkLoadTask;
        artworkLoadKey = key;
        return artworkLoadTask = Task.WhenAll(Enumerable.Range(1, 2).Select(async edition => {
            var coverTask = publicPreview ? Task.FromResult<GameArtwork.CaseArtwork?>(null)
                : GameArtwork.FetchAsync(edition, sources[edition - 1]);
            var discTask = publicPreview ? GameArtwork.FetchVerifiedDownloadedDiscAsync(edition)
                : GameArtwork.FetchDiscAsync(edition, sources[edition - 1]);
            var disc = await discTask;
            disc ??= await GameArtwork.FetchVerifiedDownloadedDiscAsync(edition);
            if (!IsLoaded || artworkLoadKey != key)
                return;
            if (disc != null) ((GameDiscView)FindName("GameDisc" + edition)).Artwork = disc;
            var image = await coverTask;
            if (!IsLoaded || artworkLoadKey != key) return;
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
        if (sender is ListBox picker && picker.SelectedItem is ListBoxItem item && (string)item.Tag != settings.Game.Id)
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
        RefreshDeveloperUi();
        RefreshGameFont();
        ExePath.Text = settings.GetExe();
        IsoPath.Text = settings.GetGameSource();
        ElfPath.Text = settings.GetElf(root);
        bool present = Playable(settings.Game.Id) && settings.FilesPresent(root);
        if (!game.Running && !launching)
            LaunchButton.Content = PlayButtonLabel;
        if (IsLoaded)
            _ = LoadArtworkAsync();
        UpdateAudioAvailability();
        RefreshGraphicsPreviewSource();
        RefreshBackgroundVideos();
        RefreshBackdrop();
        GamePicker.SelectedValue = settings.Game.Id;
        GameCasePicker.SelectedValue = settings.Game.Id;
        GamePicker.IsEnabled =
            !game.Running && !launching && !updating && !updateRestarting && !backingUp;
        GameCasePicker.IsEnabled = GamePicker.IsEnabled;
        foreach (int n in new[] { 1, 2 }) {
            string id = "file" + n;
            bool selected = settings.Game.Id == id;
            var disc = (GameDiscView)FindName("GameDisc" + n);
            disc.IsSelected = selected;
            disc.IsAvailable = DiscImport.Ready(settings, id) && File.Exists(settings.GetExe(id));
            var gameCase = (GameCaseView)FindName("GameCase" + n);
            gameCase.IsSelected = selected;
            gameCase.IsAvailable = disc.IsAvailable;
            string gameStatus =
                !Playable(id) ? "Coming later"
                : selected && game.Running ? "Running"
                : !(AppLayout.Packaged(root) ? LocalGameBuild.Available(root, id)
                                             : File.Exists(settings.GetExe(id)))
                    ? (AppLayout.Packaged(root) ? "Game setup files missing" : "No developer build")
                : !File.Exists(settings.GetGameSource(id)) ? "Choose your game source"
                : DiscImport.Ready(settings, id) && File.Exists(settings.GetExe(id)) ? "Ready to play"
                                                                                       : "Not built yet";
            ((TextBlock)FindName("DiscStatus" + n)).Text = (selected ? "Selected · " : "") + gameStatus;
            System.Windows.Automation.AutomationProperties.SetItemStatus(
                (ListBoxItem)GamePicker.Items[n - 1], gameStatus);
            System.Windows.Automation.AutomationProperties.SetItemStatus(
                (ListBoxItem)GameCasePicker.Items[n - 1], gameStatus);
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
        if (PageMods.Visibility == Visibility.Visible) UpdateModState();
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
