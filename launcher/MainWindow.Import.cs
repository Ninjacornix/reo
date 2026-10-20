using System.IO;
using System.Windows;
using System.Diagnostics;

namespace Outbreak.Launcher;
public partial class MainWindow {
    CancellationTokenSource? importCancellation;
    bool closeAfterImport;
    IProgress<ImportProgress> BeginDiscImport() {
        var source = new CancellationTokenSource();
        importCancellation = source;
        DiscProgress.Value = 0;
        DiscValidationStatus.Text = "";
        ImportActivity.Visibility = Visibility.Visible;
        var elapsed = Stopwatch.StartNew();
        var stageClock = Stopwatch.StartNew();
        string stage = "";
        long total = -1;
        long stageStart = 0;
        static string Duration(TimeSpan time) =>
            time.TotalHours >= 1 ? $"{(int)time.TotalHours}h {time.Minutes:00}m"
                                 : $"{(int)time.TotalMinutes}m {time.Seconds:00}s";
        return new Progress<ImportProgress>(value => {
            if (importCancellation != source)
                return;
            DiscProgress.Value = value.Percent;
            DiscProgress.IsIndeterminate = value.Total <= 0;
            if (stage != value.Stage || total != value.Total) {
                stage = value.Stage;
                total = value.Total;
                stageStart = value.Completed;
                stageClock.Restart();
            }
            string eta = "estimating...";
            if (value.Total > 0 && value.Completed >= value.Total)
                eta = "done";
            else if (value.Completed > stageStart && value.Total > value.Completed &&
                     stageClock.Elapsed.TotalSeconds >= 3) {
                double seconds = stageClock.Elapsed.TotalSeconds * (value.Total - value.Completed) /
                                 (value.Completed - stageStart);
                eta = "about " + Duration(TimeSpan.FromSeconds(Math.Min(seconds, 7 * 86400)));
            }
            ImportTiming.Text = $"Elapsed {Duration(elapsed.Elapsed)} · Stage ETA {eta}";
            ImportState.Text = $"{value.Stage} {value.Percent:0}% - {value.File}";
            if (value.Stage == "Checking ISO") {
                DiscValidationStatus.Text = value.File;
                DiscValidationStatus.Foreground = (System.Windows.Media.Brush)FindResource("Muted");
            }
            Status.Text = $"{value.Stage} - {value.Percent:0}%";
        });
    }
    void EndDiscImport() {
        importCancellation?.Dispose();
        importCancellation = null;
        ImportActivity.Visibility = Visibility.Collapsed;
        DiscProgress.IsIndeterminate = false;
        RefreshImportUi();
        if (closeAfterImport && !game.Running)
            Close();
    }
    void RefreshImportUi() {
        SupportedDiscHint.Text =
            settings.Game.Id == "file1"
                ? DiscValidation.Required + " PAL, Japanese and other revisions are unsupported."
                : "File #2 is not supported in this release.";
        ChooseIsoButton.IsEnabled =
            settings.Game.Id == "file1" && !updating && !game.Running && !launching && !backingUp;
        ImportDiscButton.IsEnabled = settings.Game.Id == "file1" && settings.FilesPresent(root) &&
                                     !updating && !game.Running && !launching && !backingUp;
        if (importCancellation != null)
            return;
        ImportState.Text =
            settings.Game.Id == "file2" ? "File #2 is a placeholder. ISO import and play will be " +
                                              "enabled with its native build."
            : DiscImport.Ready(settings) ? "Game data imported."
            : File.Exists(settings.GetIso())
                ? "Import once to play without mounting the ISO. Keep the ISO for game data reads."
                : "Choose your ISO. File #1 supports the NTSC-U v2.00 disc (SLUS-20765).";
    }
    void CancelImport(object sender, RoutedEventArgs e) => importCancellation?.Cancel();
    async void ImportDisc(object sender, RoutedEventArgs e) => await ImportSelectedDisc();
    async Task ImportSelectedDisc() {
        if (updating || game.Running || launching || backingUp)
            return;
        if (AppLayout.Packaged(root) ? !LocalGameBuild.Available(root)
                                     : !File.Exists(settings.GetExe())) {
            Status.Text = "This installation is missing its compatible local build kit.";
            return;
        }
        launching = true;
        try {
            var progress = BeginDiscImport();
            RefreshGameUi();
            var imported = await DiscImport.Ensure(settings.GetIso(), settings.Game,
                                                   DiscImport.ExpectedElf(settings, root), progress,
                                                   importCancellation!.Token);
            settings.SetImport(imported.Root);
            if (AppLayout.Packaged(root))
                await LocalGameBuild.Ensure(root, imported, progress, importCancellation!.Token);
            settings.Save();
            Status.Text = imported.Reused ? "Game data is already imported."
                                          : "Game imported. Ready to play.";
        } catch (OperationCanceledException) {
            Status.Text = "Import canceled.";
        } catch (Exception error) {
            Status.Text = "Could not import: " + error.Message;
            if (error is InvalidDataException) {
                DiscValidationStatus.Text = error.Message;
                DiscValidationStatus.Foreground =
                    (System.Windows.Media.Brush)FindResource("Accent");
            }
        } finally {
            launching = false;
            EndDiscImport();
            RefreshGameUi();
        }
    }
}
