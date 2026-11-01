using Avalonia.Controls.Primitives;
using Avalonia.Media.Imaging;
using System.ComponentModel;
using System.Diagnostics;
using System.Text.Json;

namespace Outbreak.Launcher.Desktop;

// Port of RC1 launcher/MainWindow.xaml.cs. Keep handlers in the same order and wording.
public partial class MainWindow : Window {
    internal readonly string root;
    internal readonly Settings settings;
    readonly Controller controller = new();
    readonly GameSession game = new();
    readonly DispatcherTimer timer = new() { Interval = TimeSpan.FromMilliseconds(16) };
    readonly string[] args;
    bool initialized, launching, previousRunning, backingUp, graphicsPreparing;
    // Headless captures hold animations and movies so every capture is deterministic.
    internal readonly bool staticCapture;
    public MainWindow() : this([]) { }
    public MainWindow(string[] arguments) {
        args = arguments;
        staticCapture = args.Contains("--static-capture");
        if (staticCapture) SystemParameters.ClientAreaAnimation = false;
        root = PlatformPaths.FindRoot(AppContext.BaseDirectory);
        settings = Settings.Load(root);
        if (staticCapture) settings.LauncherBackgroundMovies = false;
        if (!OperatingSystem.IsWindows() && PlatformPaths.NativeRecord(root) is { } record) {
            if (!File.Exists(settings.Exe) && record.TryGetValue("executable", out var exe)) settings.Exe = exe;
            if (!File.Exists(settings.Iso) && record.TryGetValue("iso", out var iso)) settings.Iso = iso;
            if (!Directory.Exists(settings.ImportedFile1) && record.TryGetValue("data", out var data))
                settings.ImportedFile1 = Path.GetDirectoryName(data)!;
        }
        controller.Configure(settings);
        InitializeComponent();
        if (staticCapture)
            foreach (var view in new Control[] { GameCase1, GameCase2, GameDisc1, GameDisc2 })
                if (view is GameCaseView gameCase) gameCase.Hold(true); else ((GameDiscView)view).Hold(true);
        InitializeLauncherSettings();
        InitializeBackgroundVideos();
        InitializeStatusToast();
        InitializeWindowLayout();
        RefreshStorageUi();
        VersionLabel.Text = Updates.BuildLabel(root);
        DeveloperFiles.Visibility =
            AppLayout.Packaged(root) ? Visibility.Collapsed : Visibility.Visible;
        WindowSize.ItemsSource = DisplayOptions.MenuSizes;
        WindowSize.SelectedItem = DisplayOptions.Size(settings.WindowSize);
        Filter.SelectedIndex = settings.LinearFilter ? 0 : 1;
        AspectRatio.SelectedIndex = Math.Max(0, Array.IndexOf(DisplayOptions.AspectChoices,
            (settings.ResolvedAspect, settings.ResolvedWidescreen)));
        ScreenFit.SelectedIndex = Array.IndexOf(DisplayOptions.Fits, settings.ResolvedFit);
        UpdateScreenFitHint();
        Fullscreen.IsChecked = settings.Fullscreen;
        PerformanceOverlay.IsChecked = settings.PerformanceOverlay;
        AsyncVif.IsChecked = settings.AsyncVif;
        GpuMovies.IsChecked = settings.GpuMovies;
        InitializeDeveloper();
        InitializeOnline();
        TextureFilter.SelectedIndex = settings.TextureLinear ? 1 : 0;
        InternalResolution.SelectedIndex =
            Array.IndexOf(DisplayOptions.InternalScales, settings.ResolvedInternalResolution);
        AnisotropicFilter.SelectedIndex =
            Array.IndexOf(new[] { 1, 2, 4, 8, 16 }, settings.ResolvedAnisotropy);
        AntiAlias.SelectedIndex = settings.ResolvedAntiAliasing switch { "smaa" => 2, "fxaa" => 1,
                                                                         _ => 0 };
        WindowSize.IsEnabled = !settings.Fullscreen;
        Brightness.Value = settings.Brightness;
        Gamma.Value = settings.Gamma;
        InitializeColorPreview();
        InitializeGraphicsPreview();
        InitializeAudio();
        SizeChanged += (_, _) => { UpdateCheatLayout(); UpdateModLayout(); };
        InitializeViewEvents();
        initialized = true;
        ShowPage("Play");
        UpdateSaves();
        InitializeInput();
        RefreshGameUi();
        RefreshMods();
        Opened += (_, _) => {
            if (OperatingSystem.IsWindows() && TryGetPlatformHandle() is { HandleDescriptor: "HWND" } handle) controller.Attach(handle.Handle);
        };
        timer.Tick += Tick;
        timer.Start();
        Closing += OnClosing;
        Closing += (_, e) => {
            if (!e.Cancel && !updateRestarting)
                updateCancellation?.Cancel();
        };
        Closed += (_, _) => {
            artworkCancellation.Cancel();
            timer.Stop();
            accountPreparation?.Cancel();
            publicLookup?.Cancel();
            lanResponder?.Dispose();
            hostedServer.Dispose();
            if (portsForwarded)
                HostNetworking.ClosePorts().Wait(
                    TimeSpan.FromSeconds(5)); // do not leave router ports open
            controller.Dispose();
        };
        Loaded += OnLoaded;
        Loaded += async (_, _) => await LoadArtworkAsync();
        Loaded += async (_, _) => await CheckMovieDecoderAsync();
    }
    MovieDecoderChoice? movieDecoder;
    async Task CheckMovieDecoderAsync() {
        movieDecoder = await MovieDecoder.Choose(CancellationToken.None);
        GpuMovies.IsEnabled = movieDecoder.Gpu;
        // Reflecting the probe is not a user change: keep the saved choice and stay silent.
        bool wasInitialized = initialized;
        initialized = false;
        try { GpuMovies.IsChecked = movieDecoder.Gpu && settings.GpuMovies; }
        finally { initialized = wasInitialized; }
        UpdateGpuMoviesHint();
    }
    void UpdateGpuMoviesHint() {
        if (movieDecoder == null)
            return;
        // Shown on hover, including while the option is unavailable, so the reason stays visible.
        string gpu = movieDecoder.GpuName.Length != 0 ? movieDecoder.GpuName : "This graphics card";
        GpuMovies.ToolTip = !movieDecoder.Gpu
            ? movieDecoder.Reason + ". Movies decode on the processor."
            : GpuMovies.IsChecked == true
                ? gpu + " decodes MPEG-2 video. Uncheck to decode movies on the processor."
                : gpu + " can decode movies; the processor decodes them instead.";
    }
    void Navigate(object? sender, RoutedEventArgs e) {
        if (sender is Button { IsEnabled: true, Tag: string page }) ShowPage(page);
    }
    internal void ShowPage(string name) {
        if (!PreparePageChange(name))
            return;
        RefreshBackgroundVideos();
        UpdateArtworkVisibility();
        foreach (string page in new[] { "Play", "Graphics", "Audio", "Controller", "Saves", "Coop", "Mods",
                                        "Cheats", "Setup", "Launcher", "Logs", "Developer" }) {
            ((Control)FindName("Page" + page)).Visibility =
                page == name ? Visibility.Visible : Visibility.Collapsed;
            var button = (Button)FindName("Nav" + page);
            button.Classes.Set("selected", page == name);
            button.Background = page == name ? VisualPalette.Brush(Palette.Accent, Palette.Selection) : Brushes.Transparent;
            button.Foreground = (IBrush)FindResource(page == name ? "Ink" : "Muted");
            button.BorderBrush = page == name ? VisualPalette.Brush(Palette.Accent) : Brushes.Transparent;
        }
        SettingsScroll.Visibility = name == "Logs" ? Visibility.Collapsed : Visibility.Visible;
        // Graphics has its own settings scroller. Play also needs scrolling when
        // setup notices and the full game descriptions exceed a compact window.
        SettingsScroll.VerticalScrollBarVisibility = name == "Graphics" ? ScrollBarVisibility.Disabled : ScrollBarVisibility.Auto;
        if (name == "Play") SettingsScroll.ScrollToVerticalOffset(playScrollOffset);
        RefreshGraphicsPreviewActivity();
        if (name == "Logs")
            RefreshLogSessions();
        if (name == "Saves")
            UpdateSaves();
        if (name == "Coop")
            RefreshOnlineUi();
        if (name == "Cheats")
            RefreshCheats();
        if (name == "Mods")
            RefreshMods();
        if (name == "Setup")
            _ = EstimateRemoval();
        AnimatePageChange();
    }
    void SettingChanged(object? sender, SelectionChangedEventArgs e) => SaveSettings(sender, e);
    void SaveSettings(object? sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        if (WindowSize.SelectedItem is OutputSize outputSize)
            settings.WindowSize = Array.IndexOf(DisplayOptions.Sizes, outputSize);
        settings.LinearFilter = Filter.SelectedIndex == 0;
        var aspect = DisplayOptions.AspectChoices[
            Math.Clamp(AspectRatio.SelectedIndex, 0, DisplayOptions.AspectChoices.Length - 1)];
        settings.AspectRatio = aspect.Aspect;
        settings.WidescreenCamera = aspect.Widescreen;
        settings.ScreenFit =
            DisplayOptions
                .Fits[Math.Clamp(ScreenFit.SelectedIndex, 0, DisplayOptions.Fits.Length - 1)];
        UpdateScreenFitHint();
        settings.Fullscreen = Fullscreen.IsChecked == true;
        settings.PerformanceOverlay = PerformanceOverlay.IsChecked == true;
        settings.AsyncVif = AsyncVif.IsChecked == true;
        if (GpuMovies.IsEnabled) // greyed out on an incompatible GPU; keep the saved choice
            settings.GpuMovies = GpuMovies.IsChecked == true;
        UpdateGpuMoviesHint();
        settings.TextureLinear = TextureFilter.SelectedIndex == 1;
        settings.InternalResolution = DisplayOptions.InternalScales[
            Math.Clamp(InternalResolution.SelectedIndex, 0, DisplayOptions.InternalScales.Length - 1)];
        settings.Anisotropy =
            new[] { 1, 2, 4, 8, 16 }[Math.Clamp(AnisotropicFilter.SelectedIndex, 0, 4)];
        settings.AntiAliasing = AntiAlias.SelectedIndex > 0;
        settings.AntiAliasingMode = AntiAlias.SelectedIndex switch {
            2 => "smaa",
            1 => "fxaa",
            _ => "off"
        };
        settings.Brightness = (int)Math.Round(Brightness.Value);
        settings.Gamma = Math.Round(Gamma.Value, 2);
        ReadAudioSettings();
        WindowSize.IsEnabled = !settings.Fullscreen;
        try {
            settings.Save();
            if (!ReferenceEquals(sender, audioSender) && currentPage != "Graphics")
                Status.Text = "Saved · Changes apply on the next launch";
        } catch (IOException error) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
        SessionSummary.Text = "GPU rendering / " + controller.SelectedDevice.Name;
        PublishLiveSettings();
        InvalidateGraphicsPreview();
    }
    void Tick(object? sender, EventArgs e) {
        RefreshArtworkActivity();
        controller.Publish();
        // Keep input publication at 60 Hz; hidden controller plots and binding
        // controls only need the slower device refresh, not a redraw every frame.
        if (currentPage == "Controller" || captureTarget.Length != 0 || slowUiTick == 0)
            UpdateInputUi();
        bool running = game.Running;
        if (currentPage == "Graphics") RefreshGraphicsPreviewActivity();
        if (running != previousRunning)
            RefreshBackgroundVideos();
        StopButton.IsEnabled = running;
        CheatControls.IsEnabled = !running && !launching;
        if (currentPage == "Mods" && ModControls.IsEnabled == (running || launching))
            UpdateModState();
        if (currentPage == "Cheats" && CheatSessionNote.IsEffectivelyVisible != (running || launching))
            UpdateCheatState();
        if (++slowUiTick >= 30) {
            slowUiTick = 0;
            RefreshGameUi();
            if (PageLogs.Visibility == Visibility.Visible)
                RefreshLog();
        }
        BackupButton.IsEnabled = !updating && !running && !launching && !backingUp;
        RefreshCardAvailability();
        if (previousRunning && !running) {
            Status.Text = $"Game closed · Exit code {game.Process!.ExitCode} · Session logs saved";
            LaunchButton.Content = PlayButtonLabel;
            LaunchButton.IsEnabled = true;
            controller.SessionEnabled = false;
            hostRoomReady = false;
            UpdateSaves();
        }
        previousRunning = running;
        if (running && game.GraphicsStatus is string preparing) {
            graphicsPreparing = true;
            Status.Text = preparing;
        } else {
            if (graphicsPreparing && running && game.NetworkStatus == null)
                Status.Text = "Game running";
            graphicsPreparing = false;
        }
        if (game.NetworkStatus != null && !graphicsPreparing)
            Status.Text = game.NetworkStatus;
    }
    async void LaunchGame(object? sender, RoutedEventArgs e) {
        string mode = settings.ResolvedCoopMode;
        if (mode == "host" && serverStarting) {
            Status.Text = "Wait until your game is open for friends (see Co-op).";
            return;
        }
        if (updating || updateRestarting || launching || game.Running || backingUp)
            return;
        if (ModConfigurationProblem() is string modProblem) {
            ShowPage("Mods");
            foreach (var row in modRows.Where(r => r.SeedError?.Visibility == Visibility.Visible)) {
                row.Options!.IsExpanded = true;
                row.SeedInput!.BringIntoView(); row.SeedInput.Focus();
                break;
            }
            Status.Text = modProblem;
            return;
        }
        if (mode != "offline" && OnlineOptions.Supported(settings.Game.Id)) {
            string? problem = OnlineOptions.Error(settings) ??
                              (mode == "host" && (!hostedServer.Running || hostedServer.GameId != settings.Game.Id)
                                   ? "Your game is not open for friends. See Co-op."
                                   : null);
            if (problem != null) {
                Status.Text = problem;
                ShowPage("Coop");
                return;
            }
        }
        SetLaunching(true);
        LaunchButton.IsEnabled = false;
        LaunchButton.Content = "Preparing…";
        Status.Text = "Preparing game...";
        try {
            var snapshot =
                JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
            LobbyAutomation.Options? lobby = null;
            if (OnlineOptions.Configured(snapshot)) {
                Status.Text = "Checking your player name...";
                await RefreshJoinHost();
                if (!await PrepareLauncherAccount()) {
                    Status.Text = AccountStatus.Text ?? "";
                    LaunchButton.IsEnabled = true;
                    LaunchButton.Content = PlayButtonLabel;
                    ShowPage("Coop");
                    return;
                }
                lobby = LobbyOptions();
                snapshot.JoinHostName = settings.JoinHostName;
                snapshot.JoinSignupPort = settings.JoinSignupPort;
                snapshot.JoinRoomName = settings.JoinRoomName;
            }
            var progress = BeginDiscImport();
            await game.Launch(root, snapshot, controller, importProgress: progress,
                              cancel: importCancellation!.Token, lobby: lobby);
            if (game.Imported != null) {
                settings.SetImport(game.Imported.Root);
                if (game.OriginalAssets != null) settings.RememberGamePak(game.OriginalAssets);
                try {
                    settings.Save();
                } catch (Exception error)
                    when (error is IOException or UnauthorizedAccessException) {
                    System.Diagnostics.Debug.WriteLine(error);
                }
            }
            previousRunning = true;
            LaunchButton.Content = "Game running";
            UpdateRandomizerSeed();
            Status.Text = "Game running · Keep the launcher open for input" +
                          (game.RandomizerSeedSummary is { } seed ? " · " + seed : "") +
                          (game.MovieStatus is { } movies ? " · " + movies : "");
        } catch (OperationCanceledException) {
            controller.SessionEnabled = false;
            Status.Text = "Import canceled.";
            LaunchButton.IsEnabled = true;
            LaunchButton.Content = PlayButtonLabel;
        } catch (Exception error) {
            controller.SessionEnabled = false;
            Status.Text = "Could not launch: " + error.Message;
            if (error is InvalidDataException) {
                DiscValidationStatus.Text = error.Message;
                DiscValidationStatus.Foreground = (IBrush)FindResource("Danger");
            }
            LaunchButton.IsEnabled = true;
            LaunchButton.Content = PlayButtonLabel;
        } finally {
            SetLaunching(false);
            EndDiscImport();
        }
    }
    async void BrowseFile(object? sender, RoutedEventArgs e) {
        if (updating || updateRestarting || launching || game.Running || backingUp)
            return;
        string kind = (string)((Button)sender!).Tag!;
        if (kind == "iso") { ChooseIso(); return; }
        var dialog = new OpenFileDialog { Title = "Choose game file",
                                          Filter = kind == "exe"   ? ExecutableFilter("Executable", "*.exe")
                                                   : kind == "iso" ? "Disc image (*.iso)|*.iso"
                                                                   : "ELF file|*.*",
                                          CheckFileExists = true };
        if (await dialog.ShowDialog(this) != true)
            return;
        settings.SetFile(kind, dialog.FileName);
        RefreshGameUi();
        SaveSettings(sender, e);
        if (kind == "iso")
            await CheckSelectedDisc();
    }
    // Windows filters by .exe; macOS and Linux game executables have no extension.
    static string ExecutableFilter(string label, string patterns) =>
        OperatingSystem.IsWindows() ? $"{label} ({patterns})|{patterns}" : $"{label}|*";
    void UpdateSaves() {
        RefreshCards();
        string folder = settings.CardFolder(root);
        try {
            int count = Directory.Exists(folder)
                ? Directory.EnumerateFiles(folder, "*", SearchOption.AllDirectories)
                    .Count(p => !Path.GetRelativePath(folder, p).Split(Path.DirectorySeparatorChar)
                        .Any(part => part.StartsWith(".reo-", StringComparison.Ordinal)))
                : 0;
            SaveCount.Text = count == 0 ? "Empty card" : $"{count} {(count == 1 ? "file" : "files")} stored";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            SaveCount.Text = "Card files are unavailable.";
        }
    }
    void OpenFolder(string folder) {
        Directory.CreateDirectory(folder);
        if (OperatingSystem.IsWindows())
            Process.Start(new ProcessStartInfo("explorer.exe", folder) { UseShellExecute = true });
        else
            Process.Start(new ProcessStartInfo(folder) { UseShellExecute = true });
    }
    void OpenSaves(object? sender, RoutedEventArgs e) => OpenFolder(settings.CardFolder(root));
    void OpenLogs(object? sender, RoutedEventArgs e) => OpenFolder(
        CurrentLogPath.Length > 0 ? Path.GetDirectoryName(CurrentLogPath)!
                                  : game.Logs ?? Path.Combine(Settings.Home, "sessions"));
    static bool NativeGameRunning() => Process.GetProcesses().Any(
        p => p.ProcessName.StartsWith("reo_recomp", StringComparison.OrdinalIgnoreCase) ||
             p.ProcessName == "reo_launcher_game");
    async void BackupSaves(object? sender, RoutedEventArgs e) {
        if (launching || backingUp || updating) return;
        if (game.Running || NativeGameRunning()) {
            Status.Text = "Close the game before backing up memory cards.";
            return;
        }
        string folder = settings.CardFolder(root);
        if (!Directory.Exists(folder) ||
            !Directory.EnumerateFiles(folder, "*", SearchOption.AllDirectories).Any()) {
            Status.Text = "No save files to back up yet.";
            return;
        }
        var dialog = new SaveFileDialog {
            Title = "Back up memory cards", Filter = "ZIP archive (*.zip)|*.zip",
            FileName = "Outbreak-" + settings.Game.Id + "-saves-" + DateTime.Now.ToString("yyyyMMdd-HHmmss") + ".zip"
        };
        if (await dialog.ShowDialog(this) != true)
            return;
        backingUp = true;
        RefreshGameUi();
        RefreshCards();
        BackupButton.IsEnabled = false;
        try {
            await Task.Run(() => MemoryCards.Backup(folder, dialog.FileName));
            Status.Text = "Memory-card backup saved.";
        } catch (Exception error) {
            Status.Text = "Backup failed: " + error.Message;
        } finally {
            backingUp = false;
            BackupButton.IsEnabled = true;
            RefreshGameUi();
            RefreshCards();
        }
    }
    void OnClosing(object? sender, WindowClosingEventArgs e) {
        if (storageChanging) {
            e.Cancel = true;
            Status.Text = "Wait for the storage copy to finish, or cancel it in the progress window.";
            return;
        }
        if (backingUp) {
            e.Cancel = true;
            Status.Text = "Wait for the memory-card backup to finish before closing.";
            return;
        }
        if (importCancellation != null && !game.Running) {
            closeAfterImport = true;
            importCancellation.Cancel();
            e.Cancel = true;
            return;
        }
        if (game.Running || launching) {
            e.Cancel = true;
            WindowState = WindowState.Minimized;
            Status.Text = "Launcher minimized · Input stays connected until the game closes";
        }
    }
    async void OnLoaded(object? sender, RoutedEventArgs e) {
        if (staticCapture) return;
        _ = DetectGraphicsCard();
        ReportUpdateResult();
        if (!args.Any(a => a.StartsWith("--test-") || a is "--smoke-launch" or "--screenshot" or
                                                           "--probe-controller"))
        {
            _ = CheckUpdates(true);
            _ = DownloadArtworkAsync();
        }
        if (args.Contains("--preview-artwork-download"))
            _ = DownloadArtworkAsync();
        if (settings.ResolvedCoopMode == "host" && args.Length == 0)
            await StartHosting();
        int screenshot = Array.IndexOf(args, "--screenshot");
        int page = Array.IndexOf(args, "--page");
        if (page >= 0 && page + 1 < args.Length &&
            new[] { "Play", "Graphics", "Audio", "Controller", "Saves", "Coop", "Mods", "Cheats", "Setup",
                    "Launcher", "Logs", "Developer" }
                .Contains(args[page + 1]))
            ShowPage(args[page + 1]);
        if (screenshot >= 0 && screenshot + 1 < args.Length) {
            // Capture the same artwork used by the live launcher, without private paths.
            await LoadArtworkAsync();
            int delay = Array.IndexOf(args, "--screenshot-delay");
            await Task.Delay(delay >= 0 && delay + 1 < args.Length && int.TryParse(args[delay + 1], out int ms) ? ms : 1500);
            UpdateLayout();
            var size = new PixelSize((int)Bounds.Width, (int)Bounds.Height);
            using var bitmap = new RenderTargetBitmap(size, new Vector(96, 96));
            bitmap.Render(this);
            bitmap.Save(args[screenshot + 1]);
            if (!args.Contains("--keep-open")) {
                importCancellation?.Dispose();
                importCancellation = null;
                Close();
            }
        }
    }
}
