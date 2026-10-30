using System.IO;
using System.Net.Http;
using System.Windows;

namespace Outbreak.Launcher;

public partial class MainWindow {
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
