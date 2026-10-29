using System.IO;
using System.Windows;
using System.Diagnostics;
using Microsoft.Win32;

namespace Outbreak.Launcher;
public partial class MainWindow {
    // Result of the quick read-only check of the chosen ISO (boot file, serial, executable hash).
    sealed record DiscCheck(string Game, string Path, long Length, long WriteTicks, bool Ok, string Message) {
        public bool Matches(string iso, string game) {
            try {
                var file = new FileInfo(iso);
                return Game == game && file.Exists && string.Equals(file.FullName, Path, StringComparison.OrdinalIgnoreCase) &&
                       file.Length == Length && file.LastWriteTimeUtc.Ticks == WriteTicks;
            } catch (Exception error) when (error is IOException or ArgumentException or
                                                UnauthorizedAccessException or NotSupportedException) {
                return false;
            }
        }
    }
    DiscCheck? discCheck;
    bool checkingDisc;
    async Task CheckSelectedDisc() {
        string iso = settings.GetIso();
        if (!Playable(settings.Game.Id) || checkingDisc || !File.Exists(iso) ||
            discCheck?.Matches(iso, settings.Game.Id) == true)
            return;
        var file = new FileInfo(iso);
        var game = settings.Game;
        checkingDisc = true;
        RefreshImportUi();
        try {
            string message = DiscImport.Ready(settings)
                                 ? DiscValidation.VerifiedFor(game.Id)
                                 : await Task.Run(() => {
                                       using var image = new DiscImage(file.FullName);
                                       return DiscValidation.Check(image, game, DiscImport.ExpectedElf(game.Id),
                                                                   CancellationToken.None).Description;
                                   });
            discCheck = new(game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, true, message);
        } catch (Exception error) when (error is InvalidDataException or IOException or
                                            UnauthorizedAccessException) {
            discCheck = new(game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, false,
                            error is InvalidDataException ? error.Message
                                                          : "The ISO could not be read: " + error.Message);
        } finally {
            checkingDisc = false;
            RefreshGameUi();
        }
    }
    async void ChooseIso() {
        if (updating || updateRestarting || launching || game.Running || backingUp)
            return;
        var dialog = new OpenFileDialog { Title = "Choose your " + settings.Game.Name + " disc image",
                                          Filter = "Disc image (*.iso)|*.iso", CheckFileExists = true };
        if (dialog.ShowDialog(this) != true)
            return;
        settings.SetFile("iso", dialog.FileName);
        SaveSettings(this, new());
        RefreshGameUi();
        await CheckSelectedDisc();
        if (discCheck is { Ok: true } && !DiscImport.Ready(settings)) ShowPage("Setup");
    }
    // ---- Remove game ----
    int removalEstimate;
    async void RemoveOptionsChanged(object sender, RoutedEventArgs e) => await EstimateRemoval();
    async Task EstimateRemoval() {
        int ticket = ++removalEstimate;
        var targets = GameRemoval.Targets(root, settings, settings.Game.Id, RemoveSaves.IsChecked == true,
                                          RemoveTools.IsChecked == true);
        RemoveSize.Text = "Measuring...";
        long size = await Task.Run(() => GameRemoval.Size(targets));
        if (ticket != removalEstimate)
            return;
        RemoveSize.Text = targets.Count == 0 ? "Nothing to remove." : "Frees about " + Gigabytes(size) + ".";
        RemoveGameButton.IsEnabled = targets.Count > 0 && !updating && !game.Running && !launching &&
                                     !backingUp && importCancellation == null;
    }
    async void RemoveGame(object sender, RoutedEventArgs e) {
        if (updating || game.Running || launching || backingUp || importCancellation != null) {
            Status.Text = "Close the game and wait for setup to finish before removing it.";
            return;
        }
        bool tools = RemoveTools.IsChecked == true, saves = RemoveSaves.IsChecked == true;
        if (tools && (hostedServer.Running || serverStarting)) {
            Status.Text = "Stop hosting (Co-op: Play alone) before removing the hosting tools.";
            return;
        }
        var targets = GameRemoval.Targets(root, settings, settings.Game.Id, saves, tools);
        if (targets.Count == 0) {
            Status.Text = "Nothing to remove.";
            return;
        }
        long size = await Task.Run(() => GameRemoval.Size(targets));
        string list = string.Join("\n", targets.Select(t => "\u2022 " + t.What).Distinct());
        if (MessageBox.Show(this,
                            $"Remove {settings.Game.Name} from this PC?\n\n{list}\n\nFrees about {Gigabytes(size)}. " +
                                "Your ISO file is kept." + (saves ? " Save games are deleted." : " Save games are kept.") +
                                "\nPlaying again needs the one-time setup again.",
                            "Remove game", MessageBoxButton.YesNo, MessageBoxImage.Warning,
                            MessageBoxResult.No) != MessageBoxResult.Yes)
            return;
        RemoveGameButton.IsEnabled = false;
        Status.Text = "Removing game files...";
        var failed = await Task.Run(() => GameRemoval.Remove(targets));
        settings.SetFile("iso", "");
        settings.SetImport("");
        discCheck = null;
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
        }
        Status.Text = failed.Count == 0
                          ? $"{settings.Game.Name} removed. Freed about {Gigabytes(size)}."
                          : "Some files are in use and were kept: " + string.Join(", ", failed);
        RefreshGameUi();
        UpdateSaves();
        await EstimateRemoval();
    }

    CancellationTokenSource? importCancellation;
    bool closeAfterImport;
    IProgress<ImportProgress> BeginDiscImport() {
        var source = new CancellationTokenSource();
        importCancellation = source;
        DiscProgress.Value = 0;
        DiscProgress.IsIndeterminate = true;
        SetupStage.Text = "Preparing game";
        SetupCounts.Text = "";
        SetupDetail.Text = "Checking imported files";
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
            DiscProgress.Value = Math.Clamp(value.Percent, 0, 100);
            SetupStage.Text = value.Stage;
            SetupCounts.Text = SetupProgressText.Counts(value);
            SetupDetail.Text = value.File;
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
            ImportState.Text = value.Total > 0 ? $"{value.Stage} {value.Percent:0}% - {value.File}"
                                               : $"{value.Stage} - {value.File}";
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
        RefreshOriginalAssetExportUi();
        ExistingBuildHint.Text = AppLayout.Packaged(root)
            ? "Choose reo_recomp.exe from a compatible launcher build. Keep its entire folder, including local-build.json, DLLs and shaders. Your ISO is still required."
            : "Choose " + (settings.Game.Id == "file2" ? "reo_recomp_file2.exe" : "reo_recomp.exe") +
              " from your developer build. Keep its DLLs and shaders together. Your ISO is still required.";
        SupportedDiscHint.Text = DiscValidation.RequiredFor(settings.Game.Id) +
            " PAL, Japanese and other revisions are unsupported.";
        ChooseIsoButton.IsEnabled =
            Playable(settings.Game.Id) && !updating && !game.Running && !launching && !backingUp;
        bool idle = !updating && !game.Running && !launching && !backingUp;
        bool verified = discCheck is { Ok: true } && discCheck.Matches(settings.GetIso(), settings.Game.Id);
        ImportDiscButton.IsEnabled = Playable(settings.Game.Id) && settings.FilesPresent(root) &&
                                     verified && idle;
        ExistingBuildButton.IsEnabled = Playable(settings.Game.Id) && idle;
        if (importCancellation != null)
            return;
        bool known = discCheck != null && discCheck.Matches(settings.GetIso(), settings.Game.Id);
        DiscValidationStatus.Text = !Playable(settings.Game.Id) || !File.Exists(settings.GetIso()) ? ""
                                    : checkingDisc || !known ? "Checking disc..."
                                    : discCheck!.Ok ? "✓ " + discCheck.Message
                                                    : "✗ " + discCheck.Message;
        DiscValidationStatus.Foreground = (System.Windows.Media.Brush)FindResource(
            !known || checkingDisc ? "Muted" : discCheck!.Ok ? "Good" : "Danger");
        if (File.Exists(settings.GetIso()) && !known && !checkingDisc)
            _ = CheckSelectedDisc();
        ImportState.Text =
            AppLayout.Packaged(root) && !LocalGameBuild.Available(root, settings.Game.Id)
                ? "This package is missing setup files for " + settings.Game.Name + "."
            : DiscImport.Ready(settings) ? "Game data imported."
            : File.Exists(settings.GetIso())
                ? "Import copies the disc and builds the game once. It downloads build tools (about 173 MB) and can take a while."
                : "Choose ISO to start setup. " + DiscValidation.RequiredFor(settings.Game.Id);
    }
    async void UseExistingBuild(object sender, RoutedEventArgs e) {
        if (updating || game.Running || launching || backingUp)
            return;
        var dialog = new OpenFileDialog { Title = "Choose a completed RE: Outbreak build",
                                          Filter = AppLayout.Packaged(root) ? "Native game (reo_recomp.exe)|reo_recomp.exe"
                                              : "Native game|reo_recomp.exe;reo_recomp_file2.exe",
                                          CheckFileExists = true };
        string cached = LocalGameBuild.TargetPath(root, settings.Game.Id);
        if (File.Exists(cached))
            dialog.InitialDirectory = Path.GetDirectoryName(cached);
        if (dialog.ShowDialog(this) != true)
            return;
        if (!AppLayout.Packaged(root) && !LocalGameBuild.Available(root, settings.Game.Id)) {
            // Developer checkout without a build kit: use the chosen build directly.
            settings.SetFile("exe", dialog.FileName);
            settings.Save();
            Status.Text = "Using the selected game build.";
            RefreshGameUi();
            return;
        }
        launching = true;
        try {
            var progress = BeginDiscImport();
            RefreshGameUi();
            string imported = await LocalGameBuild.ImportExisting(root, dialog.FileName, progress,
                                                                  importCancellation!.Token, game: settings.Game.Id);
            if (!AppLayout.Packaged(root))
                settings.SetFile("exe", imported);
            settings.Save();
            Status.Text =
                DiscImport.Ready(settings)
                    ? "Existing game build ready. Compilation skipped."
                    : "Game build imported. Choose your ISO for game data; compilation will be skipped.";
        } catch (OperationCanceledException) {
            Status.Text = "Build import canceled. Previous build preserved.";
        } catch (Exception error) {
            Status.Text = "Could not use existing build: " + error.Message;
        } finally {
            launching = false;
            EndDiscImport();
            RefreshGameUi();
        }
    }
    void CancelImport(object sender, RoutedEventArgs e) => importCancellation?.Cancel();
    async void ImportDisc(object sender, RoutedEventArgs e) => await ImportSelectedDisc();
    async Task ImportSelectedDisc() {
        if (updating || game.Running || launching || backingUp)
            return;
        if (AppLayout.Packaged(root) ? !LocalGameBuild.Available(root, settings.Game.Id)
                                     : !File.Exists(settings.GetExe())) {
            Status.Text = "This installation is missing its compatible local build kit.";
            return;
        }
        launching = true;
        bool exportingOriginalAssets = false;
        try {
            var progress = BeginDiscImport();
            RefreshGameUi();
            var imported = await DiscImport.Ensure(settings.GetIso(), settings.Game,
                                                   DiscImport.ExpectedElf(settings, root), progress,
                                                   importCancellation!.Token);
            settings.SetImport(imported.Root);
            if (AppLayout.Packaged(root))
                await LocalGameBuild.Ensure(root, imported, progress, importCancellation!.Token, game: settings.Game.Id);
            settings.Save();
            OriginalAssetExport? originalAssets = null;
            if (settings.WantsOriginalAssetPaks()) {
                exportingOriginalAssets = true;
                originalAssets = await AssetExports.Ensure(imported, settings.Game.Id, progress, importCancellation!.Token);
            }
            Status.Text = originalAssets != null ? $"Game ready. {originalAssets.Entries:N0} original assets {(originalAssets.Reused ? "already exported" : "exported")}."
                : imported.Reused ? "Game data is already imported." : "Game imported. Ready to play.";
        } catch (OperationCanceledException) {
            Status.Text = exportingOriginalAssets ? "Asset export canceled. Imported game files are kept." : "Import canceled.";
        } catch (Exception error) {
            Status.Text = exportingOriginalAssets ? "Game ready. Original asset export failed: " + error.Message : "Could not import: " + error.Message;
            if (!exportingOriginalAssets && error is InvalidDataException) {
                var file = new FileInfo(settings.GetIso());
                discCheck = new(settings.Game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, false,
                                error.Message);
                DiscValidationStatus.Text = error.Message;
                DiscValidationStatus.Foreground =
                    (System.Windows.Media.Brush)FindResource("Danger");
            }
        } finally {
            launching = false;
            EndDiscImport();
            RefreshGameUi();
        }
    }
}
