using System.Diagnostics;

namespace Outbreak.Launcher.Desktop;

// Ports of RC1 MainWindow.Import.cs, ImportCleanup.cs, AssetExports.cs, GameFiles.cs and GamePaks.cs.
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
        string iso = settings.GetGameSource();
        if (!Playable(settings.Game.Id) || checkingDisc || !File.Exists(iso) ||
            discCheck?.Matches(iso, settings.Game.Id) == true)
            return;
        var file = new FileInfo(iso);
        var game = settings.Game;
        checkingDisc = true;
        RefreshImportUi();
        try {
            string message = DiscImport.Ready(settings)
                                 ? (settings.UsesGamePak() ? "Verified game PAK: " + game.Name : DiscValidation.VerifiedFor(game.Id))
                                 : await Task.Run(() => {
                                       if (settings.UsesGamePak(game.Id)) { GamePaks.Check(file.FullName, game.Id); return "Verified game PAK: " + game.Name; }
                                       using var image = new DiscImage(file.FullName);
                                       return DiscValidation.Check(image, game, DiscImport.ExpectedElf(game.Id),
                                                                   CancellationToken.None).Description;
                                   });
            discCheck = new(game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, true, message);
        } catch (Exception error) when (error is IOException or InvalidDataException or System.Text.Json.JsonException or
                                            UnauthorizedAccessException) {
            discCheck = new(game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, false,
                            error is InvalidDataException ? error.Message
                                                          : "The game source could not be read: " + error.Message);
        } finally {
            checkingDisc = false;
            RefreshGameUi();
        }
    }
    async void ChooseIso() {
        if (updating || updateRestarting || launching || game.Running || backingUp)
            return;
        var dialog = new OpenFileDialog { Title = "Choose your " + settings.Game.Name + (settings.UsesGamePak() ? " game PAK" : " disc image"),
                                          Filter = settings.UsesGamePak() ? "Game PAK (*.pak)|*.pak" : "Disc image (*.iso)|*.iso", CheckFileExists = true };
        if (await dialog.ShowDialog(this) != true)
            return;
        settings.SetGameSource(dialog.FileName);
        SaveSettings(this, new());
        RefreshGameUi();
        ShowPage("Setup");
        await CheckSelectedDisc();
    }
    // ---- Remove game ----
    int removalEstimate;
    async void RemoveOptionsChanged(object? sender, RoutedEventArgs e) {
        if (initialized) await EstimateRemoval();
    }
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
    async void RemoveGame(object? sender, RoutedEventArgs e) {
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
        string list = string.Join("\n", targets.Select(t => "• " + t.What).Distinct());
        if (await MessageBox.Show(this,
                            $"Remove {settings.Game.Name} from this {Computer}?\n\n{list}\n\nFrees about {Gigabytes(size)}. " +
                                "Your source ISO or PAK is kept." + (saves ? " Save games are deleted." : " Save games are kept.") +
                                "\nPlaying again needs the one-time setup again.",
                            "Remove game", MessageBoxButton.YesNo, MessageBoxImage.Warning,
                            MessageBoxResult.No) != MessageBoxResult.Yes)
            return;
        RemoveGameButton.IsEnabled = false;
        Status.Text = "Removing game files...";
        await StopBackgroundPreparation();
        var failed = await Task.Run(() => GameRemoval.Remove(targets));
        settings.SetGameSource("");
        settings.SetImport("");
        backgroundRemoving = false;
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
    static string Computer => OperatingSystem.IsMacOS() ? "Mac" : OperatingSystem.IsWindows() ? "PC" : "computer";

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
                DiscValidationStatus.Foreground = (IBrush)FindResource("Muted");
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
        RefreshGameSourceUi();
        RefreshOriginalAssetExportUi();
        RefreshGameFilesUi();
        ExistingBuildHint.Text = LocalBuildKit
            ? "Choose reo_recomp.exe from a compatible launcher build. Keep its entire folder, including local-build.json, DLLs and shaders. Your selected ISO or game PAK is still required."
            : OperatingSystem.IsWindows()
            ? "Choose " + (settings.Game.Id == "file2" ? "reo_recomp_file2.exe" : "reo_recomp.exe") +
              " from your developer build. Keep its DLLs and shaders together. Your selected ISO or game PAK is still required."
            : "Choose " + (settings.Game.Id == "file2" ? "reo_recomp_file2" : "reo_recomp") +
              " from your native build. Keep its libraries and shaders together. Your selected ISO or game PAK is still required.";
        SupportedDiscHint.Text = settings.UsesGamePak() ? "Choose a complete game PAK exported by this launcher. The first launch prepares a local game-data cache; the ISO is not needed. Older asset-only PAKs need to be re-exported." : DiscValidation.RequiredFor(settings.Game.Id) +
            " PAL, Japanese and other revisions are unsupported.";
        ChooseIsoButton.IsEnabled =
            Playable(settings.Game.Id) && !updating && !game.Running && !launching && !backingUp;
        bool idle = !updating && !game.Running && !launching && !backingUp;
        bool verified = discCheck is { Ok: true } && discCheck.Matches(settings.GetGameSource(), settings.Game.Id);
        ImportDiscButton.IsEnabled = Playable(settings.Game.Id) && settings.FilesPresent(root) &&
                                     verified && idle;
        ExistingBuildButton.IsEnabled = Playable(settings.Game.Id) && idle;
        if (importCancellation != null)
            return;
        bool known = discCheck != null && discCheck.Matches(settings.GetGameSource(), settings.Game.Id);
        DiscValidationStatus.Text = !Playable(settings.Game.Id) || !File.Exists(settings.GetGameSource()) ? ""
                                    : checkingDisc || !known ? "Checking game source..."
                                    : discCheck!.Ok ? "✓ " + discCheck.Message
                                                    : "✗ " + discCheck.Message;
        DiscValidationStatus.Foreground = (IBrush)FindResource(
            !known || checkingDisc ? "Muted" : discCheck!.Ok ? "Good" : "Danger");
        if (File.Exists(settings.GetGameSource()) && !known && !checkingDisc)
            _ = CheckSelectedDisc();
        ImportState.Text =
            LocalBuildKit && !LocalGameBuild.Available(root, settings.Game.Id)
                ? "This package is missing setup files for " + settings.Game.Name + "."
            : DiscImport.Ready(settings) ? "Game data imported."
            : File.Exists(settings.GetGameSource())
                ? (settings.UsesGamePak() ? "Import prepares verified game files from the PAK and builds the game once. It needs extra disk space for the game-data cache." : "Import copies the disc and builds the game once. It downloads build tools (about 173 MB) and can take a while.")
                : (settings.UsesGamePak() ? "Choose PAK to start setup." : "Choose ISO to start setup. " + DiscValidation.RequiredFor(settings.Game.Id));
    }
    async void UseExistingBuild(object? sender, RoutedEventArgs e) {
        if (updating || game.Running || launching || backingUp)
            return;
        var dialog = new OpenFileDialog { Title = "Choose a completed RE: Outbreak build",
                                          Filter = !OperatingSystem.IsWindows() ? "Native game|*"
                                              : LocalBuildKit ? "Native game (reo_recomp.exe)|reo_recomp.exe"
                                              : "Native game|reo_recomp.exe;reo_recomp_file2.exe",
                                          CheckFileExists = true };
        string cached = LocalGameBuild.TargetPath(root, settings.Game.Id);
        if (File.Exists(cached))
            dialog.InitialDirectory = Path.GetDirectoryName(cached);
        if (await dialog.ShowDialog(this) != true)
            return;
        if (!LocalBuildKit && !LocalGameBuild.Available(root, settings.Game.Id)) {
            // Developer checkout without a build kit: use the chosen build directly.
            settings.SetFile("exe", dialog.FileName);
            settings.Save();
            Status.Text = "Using the selected game build.";
            RefreshGameUi();
            return;
        }
        SetLaunching(true);
        try {
            var progress = BeginDiscImport();
            RefreshGameUi();
            string imported = await LocalGameBuild.ImportExisting(root, dialog.FileName, progress,
                                                                  importCancellation!.Token, game: settings.Game.Id);
            if (!LocalBuildKit)
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
            SetLaunching(false);
            EndDiscImport();
            RefreshGameUi();
        }
    }
    void CancelImport(object? sender, RoutedEventArgs e) => importCancellation?.Cancel();
    async void ImportDisc(object? sender, RoutedEventArgs e) => await ImportSelectedDisc();
    async Task ImportSelectedDisc() {
        if (updating || game.Running || launching || backingUp)
            return;
        if (LocalBuildKit ? !LocalGameBuild.Available(root, settings.Game.Id)
                          : !File.Exists(settings.GetExe())) {
            Status.Text = "This installation is missing its compatible local build kit.";
            return;
        }
        SetLaunching(true);
        bool exportingOriginalAssets = false;
        try {
            var progress = BeginDiscImport();
            RefreshGameUi();
            var imported = await settings.PrepareGame(progress, importCancellation!.Token);
            settings.SetImport(imported.Root);
            PrepareImportedBackgroundVideos();
            if (LocalBuildKit)
                await LocalGameBuild.Ensure(root, imported, progress, importCancellation!.Token, game: settings.Game.Id);
            settings.Save();
            OriginalAssetExport? originalAssets = null;
            if (!settings.UsesGamePak() && settings.WantsOriginalAssetPaks()) {
                exportingOriginalAssets = true;
                originalAssets = await AssetExports.Ensure(imported, settings.Game.Id, progress, importCancellation!.Token);
                settings.RememberGamePak(originalAssets); settings.Save();
            }
            Status.Text = originalAssets != null ? $"Game ready. {originalAssets.Entries:N0} original assets {(originalAssets.Reused ? "already exported" : "exported")}."
                : imported.Reused ? "Game data is already imported." : "Game imported. Ready to play.";
        } catch (OperationCanceledException) {
            Status.Text = exportingOriginalAssets ? "Asset export canceled. Imported game files are kept." : "Import canceled.";
        } catch (Exception error) {
            Status.Text = exportingOriginalAssets ? "Game ready. Original asset export failed: " + error.Message : "Could not import: " + error.Message;
            if (!exportingOriginalAssets && error is InvalidDataException) {
                var file = new FileInfo(settings.GetGameSource());
                discCheck = new(settings.Game.Id, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks, false,
                                error.Message);
                DiscValidationStatus.Text = error.Message;
                DiscValidationStatus.Foreground = (IBrush)FindResource("Danger");
            }
        } finally {
            SetLaunching(false);
            EndDiscImport();
            RefreshGameUi();
        }
    }

    async void CleanOldImports(object? sender, RoutedEventArgs e) {
        if (game.Running || launching || updating || updateRestarting || backingUp || importCancellation != null) {
            Status.Text = "Close the game and wait for setup to finish before cleaning old imports."; return;
        }
        string gameId = settings.Game.Id;
        launching = true; RefreshGameUi();
        try {
            Status.Text = "Checking older game imports...";
            var items = await Task.Run(() => StaleImports.Find(settings, gameId));
            if (items.Count == 0) { Status.Text = "No old completed imports to clean. Selected imports are kept."; return; }
            string list = string.Join("\n", items.Select(i => Path.GetFileName(i.Source) + " — " + Gigabytes(i.Bytes) + "\n" + Path.GetFileName(i.Path)));
            if (await MessageBox.Show(this, $"Delete {items.Count} old imports for {GameDefinition.Find(gameId).Name}?\n\n" + list +
                $"\n\nEstimated size: {Gigabytes(items.Sum(i => i.Bytes))}.\nSelected imports, source ISOs/PAKs, saves, exports and mods are kept. " +
                "Playing an older revision again needs its source ISO or PAK to import again.",
                "Clean up old imports", MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No) != MessageBoxResult.Yes) {
                Status.Text = "Old imports kept."; return;
            }
            Status.Text = "Removing reviewed old imports...";
            var failed = await Task.Run(() => StaleImports.Remove(items, settings, gameId));
            Status.Text = $"Removed {items.Count - failed.Count} old imports." +
                (failed.Count == 0 ? " Selected game files are kept." : " Some imports were kept because they changed, are protected or are in use.");
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) { Status.Text = error.Message; }
        finally { launching = false; RefreshGameUi(); }
    }

    bool refreshingOriginalAssetOptions;
    readonly Dictionary<string, string> originalAssetFolders = new();
    void RefreshOriginalAssetExportUi() {
        refreshingOriginalAssetOptions = true;
        try {
            ExportOriginalAssets.IsChecked = settings.WantsOriginalAssetPaks();
            bool idle = !game.Running && !launching && !updating && !updateRestarting && !backingUp && importCancellation == null;
            OriginalAssetOptions.IsEnabled = idle;
            CleanOldImportsButton.IsEnabled = idle;
            ExportOriginalAssets.IsEnabled = idle && !settings.UsesGamePak();
            ExportOriginalAssetsNow.IsEnabled = idle && DiscImport.Ready(settings);
            OpenOriginalAssetExports.IsEnabled = Directory.Exists(AssetExports.GameFolder(settings.Game.Id));
        } finally { refreshingOriginalAssetOptions = false; }
    }
    void OriginalAssetOptionChanged(object? sender, RoutedEventArgs e) {
        if (!initialized || refreshingOriginalAssetOptions || game.Running || launching || importCancellation != null) return;
        try {
            settings.SetOriginalAssetExport(ExportOriginalAssets.IsChecked == true);
            settings.Save();
            Status.Text = settings.WantsOriginalAssetPaks() ? "Original assets will be exported during setup." : "Original asset export is optional. Use Export now after importing.";
        } catch (IOException error) { Status.Text = error.Message; }
    }
    async void ExportOriginalAssetsClicked(object? sender, RoutedEventArgs e) {
        if (updating || updateRestarting || game.Running || launching || backingUp || importCancellation != null || !DiscImport.Ready(settings)) return;
        SetLaunching(true);
        try {
            var progress = BeginDiscImport(); RefreshGameUi();
            string imported = settings.ImportFolder();
            var disc = new ImportedDisc(imported, Path.Combine(imported, "data", settings.Game.ElfName), 0, 0, true);
            var result = await AssetExports.Ensure(disc, settings.Game.Id, progress, importCancellation!.Token);
            settings.RememberGamePak(result); settings.Save();
            originalAssetFolders[settings.Game.Id] = result.Root;
            Status.Text = $"{result.Entries:N0} original assets {(result.Reused ? "already exported" : "exported")}. Use Open exports folder.";
        } catch (OperationCanceledException) { Status.Text = "Asset export canceled. Game files and completed exports are kept."; }
        catch (Exception error) { Status.Text = "Original asset export failed: " + error.Message; }
        finally { SetLaunching(false); EndDiscImport(); RefreshGameUi(); }
    }
    void OpenOriginalAssetExportsClicked(object? sender, RoutedEventArgs e) {
        string folder = originalAssetFolders.GetValueOrDefault(settings.Game.Id) ?? AssetExports.GameFolder(settings.Game.Id);
        if (!Directory.Exists(folder)) return;
        try { Process.Start(new ProcessStartInfo(folder) { UseShellExecute = true }); }
        catch (Exception error) when (error is IOException or System.ComponentModel.Win32Exception) { Status.Text = error.Message; }
    }

    string removalUiEdition = "";
    void RefreshGameFilesUi() {
        GameFilesEdition.Text = settings.Game.Id == "file2" ? "FILE #2" : "FILE #1";
        string executable = settings.GetExe();
        SelectedBuildPath.Text = executable;
        GameFilesBuildState.Text = File.Exists(executable) ? "Build available" : "No build selected";
        bool idle = !updating && !updateRestarting && !game.Running && !launching && !backingUp &&
                    importCancellation == null && !storageChanging;
        DiscFileActions.IsEnabled = BuildFileActions.IsEnabled = GameRemovalControls.IsEnabled = idle;
        DeveloperFiles.IsEnabled = idle;
        if (IsLoaded && PageSetup.IsEffectivelyVisible && removalUiEdition != settings.Game.Id) {
            removalUiEdition = settings.Game.Id;
            _ = EstimateRemoval();
        }
    }

    bool refreshingGameSource;
    void RefreshGameSourceUi() {
        refreshingGameSource = true;
        UseGamePakSwitch.IsChecked = settings.UsesGamePak();
        UseGamePakSwitch.IsEnabled = !checkingDisc && !launching && !updating && !updateRestarting && !backingUp && !game.Running && importCancellation == null;
        GameSourceLabel.Text = settings.UsesGamePak() ? "Game PAK (.pak)" : "Disc image (.iso)";
        ChooseIsoButton.Content = settings.UsesGamePak() ? "Choose PAK" : "Choose ISO";
        refreshingGameSource = false;
    }
    void GameSourceChanged(object? sender, RoutedEventArgs e) {
        if (!initialized || refreshingGameSource || launching || updating || updateRestarting || backingUp || game.Running || importCancellation != null) return;
        settings.SetGamePak(UseGamePakSwitch.IsChecked == true);
        discCheck = null;
        try { settings.Save(); }
        catch (Exception error) when (error is System.IO.IOException or UnauthorizedAccessException) { Status.Text = error.Message; }
        RefreshGameUi();
    }
}
