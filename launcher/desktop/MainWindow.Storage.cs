using System.Diagnostics;

namespace Outbreak.Launcher.Desktop;

// Ports of RC1 MainWindow.Storage.cs and MainWindow.Artwork.cs.
public partial class MainWindow {
    bool storageChanging;
    string? storageMessage;
    void RefreshStorageUi() {
        StoragePath.Text = Settings.Home;
        bool busy = game.Running || launching || backingUp || updating || updateRestarting ||
                    graphicsPreparing || serverStarting || hostedServer.Running || importCancellation != null ||
                    accountPreparation != null || storageChanging;
        ChooseStorageButton.IsEnabled = !busy;
        StorageStatus.Text = busy ? "Close the game and stop hosting or setup before changing storage."
            : storageMessage ?? "Changing folders copies your data and restarts the launcher. The original folder is kept as a backup.";
    }

    void OpenStorageFolder(object? sender, RoutedEventArgs e) {
        try {
            Directory.CreateDirectory(Settings.Home);
            Process.Start(new ProcessStartInfo(Settings.Home) { UseShellExecute = true });
        } catch (Exception error) {
            storageMessage = "Could not open the storage folder: " + error.GetBaseException().Message;
            RefreshStorageUi();
        }
    }

    async void ChangeStorageFolder(object? sender, RoutedEventArgs e) {
        RefreshStorageUi();
        if (!ChooseStorageButton.IsEnabled) return;
        var picker = new OpenFolderDialog { Title = "Choose a new or empty folder for launcher data",
            InitialDirectory = Path.GetDirectoryName(Settings.Home) ?? root };
        if (await picker.ShowDialog(this) != true || Path.GetFullPath(picker.FolderName).Equals(
                Path.GetFullPath(Settings.Home), StringComparison.OrdinalIgnoreCase)) return;
        storageChanging = true;
        storageMessage = null;
        try {
            await StopBackgroundPreparation();
            settings.Save();
            if (!await StorageProgressWindow.Run(this, "Change storage folder",
                    (progress, cancel) => Storage.Select(root, Settings.Home, picker.FolderName, progress, cancel))) {
                storageMessage = "Cancelled. Your current storage folder is unchanged.";
                return;
            }
            // The new process waits for this instance to release its mutex and storage lease.
            using var parent = Process.GetCurrentProcess();
            var start = new ProcessStartInfo(Environment.ProcessPath!) { UseShellExecute = false,
                WorkingDirectory = root };
            start.ArgumentList.Add("--wait-for-launcher-exit");
            start.ArgumentList.Add(parent.Id.ToString());
            start.ArgumentList.Add(parent.StartTime.ToUniversalTime().Ticks.ToString());
            _ = Process.Start(start) ?? throw new IOException("Could not restart the launcher. Reopen it to use the new folder.");
            storageChanging = false;
            Close();
        } catch (Exception error) {
            storageMessage = "Storage change failed: " + error.GetBaseException().Message + " Your original files are still available.";
        } finally {
            storageChanging = false;
            backgroundRemoving = false;
            RefreshBackgroundVideos();
            ChooseStorageButton.IsEnabled = true;
            RefreshStorageUi();
        }
    }

    readonly CancellationTokenSource artworkCancellation = new();
    bool artworkDownloading, artworkDownloadStarted;
    async Task DownloadArtworkAsync() {
        if (artworkDownloadStarted)
            return;
        artworkDownloadStarted = true;
        try {
            if (await Task.Run(GameArtwork.DownloadsCurrent))
                return;
            if (artworkCancellation.IsCancellationRequested)
                return;
            artworkDownloading = true;
            var progress = new Progress<GameArtwork.DownloadProgress>(value => {
                if (!IsLoaded) return;
                ArtworkDownloadProgress.Value = Math.Clamp(value.Percent, 0, 100);
                ArtworkDownloadDetail.Text = value.Detail;
                RefreshArtworkActivity();
            });
            RefreshArtworkActivity();
            using var client = new HttpClient();
            client.DefaultRequestHeaders.UserAgent.ParseAdd(
                "OutbreakLauncher/1.0 (https://github.com/Ninjacornix/reo)");
            await GameArtwork.DownloadMissing(client, progress, artworkCancellation.Token);
        } catch (Exception error) when (error is IOException or HttpRequestException or
                                              UnauthorizedAccessException or OperationCanceledException) {
            // Missing artwork never blocks setup, launching, or existing local art.
        } finally {
            artworkDownloading = false;
            RefreshArtworkActivity();
            if (IsLoaded) {
                artworkLoadKey = "";
                await LoadArtworkAsync();
            }
        }
    }
    void RefreshArtworkActivity() {
        ArtworkActivity.Visibility = artworkDownloading &&
            ImportActivity.Visibility != Visibility.Visible &&
            HostSetupActivity.Visibility != Visibility.Visible && !updating
                ? Visibility.Visible : Visibility.Collapsed;
    }
}
