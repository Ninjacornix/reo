using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Windows;

namespace Outbreak.Launcher;

public partial class MainWindow {
    BackgroundVideoPlayer? backgroundPlayer;
    sealed record VideoPreparation(CancellationTokenSource Cancel, Task<string[]> Work);
    readonly Dictionary<string, VideoPreparation> backgroundPreparations = new(StringComparer.OrdinalIgnoreCase);
    string backgroundKey = "";
    bool backgroundClosing, backgroundRemoving;
    ImportProgress? backgroundProgress;

    void LauncherBackgroundMoviesChanged(object sender, RoutedEventArgs e) {
        if (!initialized) return;
        settings.LauncherBackgroundMovies = LauncherBackgroundMovies.IsChecked == true;
        if (!settings.LauncherBackgroundMovies) {
            backgroundPlayer?.Suspend(true);
            foreach (var preparation in backgroundPreparations.Values) {
                preparation.Cancel.Cancel();
                _ = preparation.Work.ContinueWith(_ => preparation.Cancel.Dispose(), TaskScheduler.Default);
            }
            backgroundPreparations.Clear();
            backgroundKey = "";
            backgroundProgress = null;
        }
        RefreshBackgroundVideos();
        UpdateArtworkVisibility();
        try {
            settings.Save();
            Status.Text = settings.LauncherBackgroundMovies ? "Launcher background movies enabled." : "Launcher background movies disabled. Using placeholder images.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
    }

    void InitializeBackgroundVideos() {
        backgroundPlayer = new(BackgroundMovieA, BackgroundMovieB, UpdateArtworkVisibility);
        StateChanged += (_, _) => RefreshBackgroundVideos();
        Loaded += (_, _) => RefreshBackgroundVideos();
        Closed += (_, _) => {
            backgroundClosing = true;
            foreach (var preparation in backgroundPreparations.Values) preparation.Cancel.Cancel();
            backgroundPlayer.Dispose();
        };
    }
    void UpdateArtworkVisibility() {
        BackgroundScene.Visibility = currentPage == "Play" ? Visibility.Visible : Visibility.Collapsed;
        bool video = backgroundPlayer?.HasVideo == true;
        ImageBackgroundShade.Visibility = video ? Visibility.Collapsed : Visibility.Visible;
        VideoBackgroundShade.Visibility = video ? Visibility.Visible : Visibility.Collapsed;
        VideoVignette.Visibility = VideoBackgroundShade.Visibility;
        ArtworkLayer.Visibility = Backdrop.Source != null || OutgoingBackdrop.Source != null || video
            ? Visibility.Visible : Visibility.Collapsed;
    }
    void SetLaunching(bool value) {
        launching = value;
        RefreshBackgroundVideos();
    }
    void RefreshBackgroundVideos() {
        if (backgroundPlayer == null || backgroundClosing || backgroundRemoving) return;
        bool disabled = !settings.LauncherBackgroundMovies || args.Contains("--public-preview") || !SystemParameters.ClientAreaAnimation;
        backgroundPlayer.Suspend(disabled || currentPage != "Play" || game.Running || launching || WindowState == WindowState.Minimized);
        RefreshBackgroundVideoActivity();
        if (!IsLoaded || disabled) return;
        string edition = settings.Game.Id, import = settings.ImportFolder(edition);
        string key = edition + "|" + import;
        if (backgroundKey == key) return;
        backgroundKey = key;
        backgroundProgress = null;
        backgroundPlayer.SetPlaylist(edition, Array.Empty<string>());
        if (import.Length == 0 || !File.Exists(Path.Combine(import, "import.json"))) return;
        if (!backgroundPreparations.TryGetValue(key, out var preparation)) {
            var cancel = new CancellationTokenSource();
            string home = Settings.Home;
            var progress = new Progress<ImportProgress>(value => {
                if (backgroundClosing || cancel.IsCancellationRequested || backgroundKey != key) return;
                backgroundProgress = value;
                RefreshBackgroundVideoActivity();
            });
            preparation = new(cancel, Task.Run(async () => {
                try { return await BackgroundVideos.Prepare(import, edition, home, cancel.Token, progress); }
                catch (OperationCanceledException) { return Array.Empty<string>(); }
                catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                    JsonException or System.Net.Http.HttpRequestException or System.ComponentModel.Win32Exception or InvalidOperationException) {
                    Trace.WriteLine("Background video preparation: " + error.Message);
                    return Array.Empty<string>(); // Optional decoration never interrupts game setup.
                }
            }));
            backgroundPreparations.Add(key, preparation);
        }
        _ = ApplyBackgroundVideos(key, edition, preparation);
        RefreshBackgroundVideoActivity();
    }
    async Task ApplyBackgroundVideos(string key, string edition, VideoPreparation preparation) {
        var paths = await preparation.Work;
        if (settings.LauncherBackgroundMovies && !backgroundClosing && !backgroundRemoving && backgroundKey == key &&
            backgroundPreparations.TryGetValue(key, out var current) && ReferenceEquals(current, preparation))
            backgroundPlayer?.SetPlaylist(edition, paths);
        RefreshBackgroundVideoActivity();
    }
    void PrepareImportedBackgroundVideos() {
        string key = settings.Game.Id + "|" + settings.ImportFolder();
        if (backgroundPreparations.TryGetValue(key, out var previous) && previous.Work.IsCompleted) {
            backgroundPreparations.Remove(key);
            previous.Cancel.Dispose();
        }
        backgroundKey = "";
        RefreshBackgroundVideos();
    }
    void RefreshBackgroundVideoActivity() {
        bool busy = settings.LauncherBackgroundMovies && !backgroundClosing && !backgroundRemoving && !game.Running && !launching && !updating &&
            backgroundPreparations.TryGetValue(backgroundKey, out var preparation) && !preparation.Work.IsCompleted;
        // A fast cache verification on every launch is not another conversion.
        BackgroundVideoActivity.Visibility = busy && backgroundProgress != null ? Visibility.Visible : Visibility.Collapsed;
        BackgroundVideoDetail.Text = backgroundProgress?.File ?? "Preparing background videos";
        BackgroundVideoProgress.IsIndeterminate = backgroundProgress == null;
        BackgroundVideoProgress.Value = backgroundProgress?.Percent ?? 0;
    }
    async Task StopBackgroundPreparation() {
        backgroundRemoving = true;
        RefreshBackgroundVideoActivity();
        backgroundPlayer?.SetPlaylist("", Array.Empty<string>());
        var preparations = backgroundPreparations.Values.ToArray();
        foreach (var preparation in preparations) preparation.Cancel.Cancel();
        await Task.WhenAll(preparations.Select(p => p.Work));
        foreach (var preparation in preparations) preparation.Cancel.Dispose();
        backgroundPreparations.Clear();
        backgroundKey = "";
    }
}
