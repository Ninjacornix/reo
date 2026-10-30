using System.Diagnostics;
using System.IO;
using System.Net.Http;
using System.Text.Json;
using System.Windows;

namespace Outbreak.Launcher;
public partial class MainWindow {
    LauncherRelease? availableUpdate;
    CancellationTokenSource? updateCancellation;
    bool updating, updateRestarting, checkingUpdate;
    async void CheckForUpdates(object sender, RoutedEventArgs e) {
        if (updating)
            return;
        if (availableUpdate == null) {
            await CheckUpdates(false);
            return;
        }
        if (!AppLayout.Packaged(root)) {
            Process.Start(new ProcessStartInfo(ReleasesUrl) { UseShellExecute = true });
            return;
        }
        if (game.Running || launching || backingUp) {
            Status.Text = "Close the game before installing an update.";
            return;
        }
        if (availableUpdate.RequiresRebuild &&
            MessageBox.Show(this,
                            $"After updating to {availableUpdate.Tag}, the game is built again the first time you press Play. " +
                                "This is a one-time setup like the first one and can take a while.\n\nInstall the update now?",
                            "Update needs a game rebuild", MessageBoxButton.YesNo,
                            MessageBoxImage.Information) != MessageBoxResult.Yes)
            return;
        updating = true;
        updateCancellation = new CancellationTokenSource(TimeSpan.FromMinutes(20));
        UpdateButton.IsEnabled = false;
        UpdateProgress.Value = 0;
        UpdateProgress.Visibility = Visibility.Visible;
        UpdateCancel.Visibility = Visibility.Visible;
        UpdatePlan? preparedPlan = null;
        try {
            using var client = Updates.Client();
            var progress = new Progress<UpdateProgress>(value => {
                UpdateState.Text = value.Stage + "...";
                UpdateProgress.Value = value.Percent;
                Status.Text = value.Stage == "Downloading"
                                  ? $"Downloading {availableUpdate.Tag} - {value.Percent:0}%"
                                  : value.Stage + " update...";
            });
            var plan = await Updates.Prepare(client, availableUpdate, root, progress,
                                             updateCancellation.Token);
            preparedPlan = plan;
            UpdateState.Text = "Preparing restart...";
            await Updates.StartWorker(plan, updateCancellation.Token);
            updateCancellation.Token.ThrowIfCancellationRequested();
            File.WriteAllText(Path.Combine(plan.Work, "commit.json"), "{}");
            updateRestarting = true;
            Application.Current.Shutdown();
        } catch (OperationCanceledException) {
            Status.Text = "Update canceled. Your installation has not been changed.";
        } catch (Exception error)
            when (error is IOException or HttpRequestException or UnauthorizedAccessException or
                      JsonException or InvalidOperationException or KeyNotFoundException or
                          System.ComponentModel.Win32Exception) {
            Status.Text = "Could not update: " + error.Message;
        } finally {
            if (!updateRestarting && preparedPlan != null)
                File.WriteAllText(Path.Combine(preparedPlan.Work, "cancel.json"), "{}");
            updateCancellation.Dispose();
            updateCancellation = null;
            if (!updateRestarting) {
                updating = false;
                UpdateButton.IsEnabled = true;
                UpdateProgress.Visibility = Visibility.Collapsed;
                UpdateCancel.Visibility = Visibility.Collapsed;
                UpdateState.Text = "Update not installed. You can retry.";
            }
        }
    }
    async Task CheckUpdates(bool quiet) {
        if (updating || checkingUpdate)
            return;
        checkingUpdate = true;
        UpdateButton.IsEnabled = false;
        UpdateState.Text = "Checking GitHub...";
        using var cancellation = new CancellationTokenSource(TimeSpan.FromSeconds(25));
        try {
            using var client = Updates.Client();
            var installed = Updates.InstalledVersion(root);
            availableUpdate = await Updates.Check(client, installed, cancellation.Token,
                                                  Updates.PrereleaseChannel(root));
            if (availableUpdate == null) {
                UpdateState.Text = "No newer release available.";
                if (!quiet)
                    Status.Text = "No newer published Windows release was found.";
            } else {
                UpdateButton.Content = AppLayout.Packaged(root) ? "Install " + availableUpdate.Tag
                                                                : "View " + availableUpdate.Tag;
                UpdateState.Text = !AppLayout.Packaged(root)
                                       ? "Use a release package to install updates."
                                   : availableUpdate.RequiresRebuild
                                       ? "Update available. The game is rebuilt once afterwards."
                                       : "Update available. Restarts launcher.";
                if (!quiet)
                    Status.Text = "New release: " + availableUpdate.Tag;
            }
        } catch (Exception error)
            when (error is IOException or HttpRequestException or JsonException or
                      OperationCanceledException or InvalidOperationException or
                          UnauthorizedAccessException or KeyNotFoundException) {
            UpdateState.Text = "";
            if (!quiet)
                Status.Text = error.Message;
        } finally {
            checkingUpdate = false;
            UpdateButton.IsEnabled = true;
        }
    }
    void CancelUpdate(object sender, RoutedEventArgs e) => updateCancellation?.Cancel();
    void ReportUpdateResult() {
        int at = Array.IndexOf(args, "--update-complete");
        bool success = at >= 0;
        if (!success)
            at = Array.IndexOf(args, "--update-failed");
        if (at < 0 || at + 1 >= args.Length)
            return;
        try {
            using var receipt = JsonDocument.Parse(File.ReadAllText(args[at + 1]));
            Status.Text =
                success
                    ? "Updated to " + receipt.RootElement.GetProperty("version").GetString()
                    : (receipt.RootElement.TryGetProperty("rollbackSucceeded", out var restored) &&
                               restored.GetBoolean()
                           ? "Update failed; previous installation kept. "
                           : "Update failed. Check its backup and logs. ") +
                          receipt.RootElement.GetProperty("error").GetString();
        } catch (Exception error)
            when (error is IOException or JsonException or UnauthorizedAccessException) {
            Status.Text =
                success ? "Update installed." : "Update did not complete. Check the update logs.";
        }
    }
}
