using Microsoft.Win32;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Text.Json;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Outbreak.Launcher;
public partial class MainWindow : Window {
    readonly string root;
    readonly Settings settings;
    readonly Controller controller = new();
    readonly GameSession game = new();
    readonly DispatcherTimer timer = new() { Interval = TimeSpan.FromMilliseconds(16) };
    readonly string[] args;
    bool initialized, launching, previousRunning, backingUp, graphicsPreparing;
    public MainWindow(string[] arguments) {
        args = arguments;
        root = AppLayout.FindRoot(AppContext.BaseDirectory);
        settings = Settings.Load(root);
        controller.Configure(settings);
        InitializeComponent();
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
        initialized = true;
        ShowPage("Play");
        UpdateSaves();
        InitializeInput();
        RefreshGameUi();
        RefreshMods();
        SourceInitialized += (_, _) => controller.Attach(new WindowInteropHelper(this).Handle);
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
        GpuMovies.IsChecked = movieDecoder.Gpu && settings.GpuMovies;
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
    void Navigate(object sender, RoutedEventArgs e) => ShowPage((string)((Button)sender).Tag);
    void ShowPage(string name) {
        if (!PreparePageChange(name))
            return;
        RefreshBackgroundVideos();
        UpdateArtworkVisibility();
        foreach (string page in new[] { "Play", "Graphics", "Audio", "Controller", "Saves", "Coop", "Mods",
                                        "Cheats", "Setup", "Launcher", "Logs", "Developer" }) {
            ((FrameworkElement)FindName("Page" + page)).Visibility =
                page == name ? Visibility.Visible : Visibility.Collapsed;
            var button = (Button)FindName("Nav" + page);
            System.Windows.Controls.Primitives.Selector.SetIsSelected(button, page == name);
            button.Background = page == name ? Palette.Brush(Palette.Accent, Palette.Selection) : Brushes.Transparent;
            button.Foreground = (Brush)FindResource(page == name ? "Ink" : "Muted");
            button.BorderBrush = page == name ? Palette.Brush(Palette.Accent) : Brushes.Transparent;
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
    void SettingChanged(object sender, SelectionChangedEventArgs e) => SaveSettings(sender, e);
    void SaveSettings(object sender, RoutedEventArgs e) {
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
            if (!ReferenceEquals(sender, audioMixer) && currentPage != "Graphics")
                Status.Text = "Saved · Changes apply on the next launch";
        } catch (IOException error) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
        SessionSummary.Text = "GPU rendering / " + controller.SelectedDevice.Name;
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
        if (currentPage == "Cheats" && CheatSessionNote.IsVisible != (running || launching))
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
    async void LaunchGame(object sender, RoutedEventArgs e) {
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
                    Status.Text = AccountStatus.Text;
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
                DiscValidationStatus.Foreground = (Brush)FindResource("Danger");
            }
            LaunchButton.IsEnabled = true;
            LaunchButton.Content = PlayButtonLabel;
        } finally {
            SetLaunching(false);
            EndDiscImport();
        }
    }
    async void BrowseFile(object sender, RoutedEventArgs e) {
        if (updating || updateRestarting || launching || game.Running || backingUp)
            return;
        string kind = (string)((Button)sender).Tag;
        var dialog = new OpenFileDialog { Title = "Choose game file",
                                          Filter = kind == "exe"   ? "Executable (*.exe)|*.exe"
                                                   : kind == "iso" ? "Disc image (*.iso)|*.iso"
                                                                   : "ELF file|*.*",
                                          CheckFileExists = true };
        if (dialog.ShowDialog(this) != true)
            return;
        settings.SetFile(kind, dialog.FileName);
        RefreshGameUi();
        SaveSettings(sender, e);
        if (kind == "iso")
            await CheckSelectedDisc();
    }
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
        Process.Start(new ProcessStartInfo("explorer.exe", folder) { UseShellExecute = true });
    }
    void OpenSaves(object sender, RoutedEventArgs e) => OpenFolder(settings.CardFolder(root));
    void OpenLogs(object sender, RoutedEventArgs e) => OpenFolder(
        CurrentLogPath.Length > 0 ? Path.GetDirectoryName(CurrentLogPath)!
                                  : game.Logs ?? Path.Combine(Settings.Home, "sessions"));
    async void BackupSaves(object sender, RoutedEventArgs e) {
        if (launching || backingUp || updating) return;
        if (game.Running ||
            Process.GetProcesses().Any(
                p => p.ProcessName.StartsWith("reo_recomp", StringComparison.OrdinalIgnoreCase) ||
                     p.ProcessName == "reo_launcher_game")) {
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
        if (dialog.ShowDialog(this) != true)
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
    void OnClosing(object? sender, CancelEventArgs e) {
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
    async void OnLoaded(object sender, RoutedEventArgs e) {
        int playLayoutTest = Array.IndexOf(args, "--test-play-layout");
        if (playLayoutTest >= 0 && playLayoutTest + 1 < args.Length) {
            await TestPlayLayout(args[playLayoutTest + 1]);
            return;
        }
        int launcherUiTest = Array.IndexOf(args, "--test-launcher-ui");
        if (launcherUiTest >= 0 && launcherUiTest + 1 < args.Length) {
            await TestLauncherUi(args[launcherUiTest + 1]);
            return;
        }
        int developerUiTest = Array.IndexOf(args, "--test-developer-ui");
        if (developerUiTest >= 0 && developerUiTest + 1 < args.Length) {
            await TestDeveloperUi(args[developerUiTest + 1]);
            return;
        }
        int gameFilesTest = Array.IndexOf(args, "--test-game-files-ui");
        if (gameFilesTest >= 0 && gameFilesTest + 1 < args.Length) {
            await TestGameFilesUi(args[gameFilesTest + 1]);
            return;
        }
        int coopUiTest = Array.IndexOf(args, "--test-coop-ui");
        if (coopUiTest >= 0 && coopUiTest + 1 < args.Length) {
            await TestCoopUi(args[coopUiTest + 1]);
            return;
        }
        int cardsUiTest = Array.IndexOf(args, "--test-memory-cards-ui");
        if (cardsUiTest >= 0 && cardsUiTest + 1 < args.Length) {
            await TestMemoryCardsUi(args[cardsUiTest + 1]);
            return;
        }
        int graphicsUiTest = Array.IndexOf(args, "--test-graphics-ui");
        if (graphicsUiTest >= 0 && graphicsUiTest + 1 < args.Length) {
            await TestGraphicsUi(args[graphicsUiTest + 1]);
            return;
        }
        int controlsUiTest = Array.IndexOf(args, "--test-controls-ui");
        if (controlsUiTest >= 0 && controlsUiTest + 1 < args.Length) {
            await TestControlsUi(args[controlsUiTest + 1]);
            return;
        }
        int modsUiTest = Array.IndexOf(args, "--test-mods-ui");
        if (modsUiTest >= 0 && modsUiTest + 1 < args.Length) {
            await TestModsUi(args[modsUiTest + 1]);
            return;
        }
        int cheatsUiTest = Array.IndexOf(args, "--test-cheats-ui");
        if (cheatsUiTest >= 0 && cheatsUiTest + 1 < args.Length) {
            await TestCheatsUi(args[cheatsUiTest + 1]);
            return;
        }
        int audioUiTest = Array.IndexOf(args, "--test-audio-ui");
        if (audioUiTest >= 0 && audioUiTest + 1 < args.Length) {
            await TestAudioUi(args[audioUiTest + 1]);
            return;
        }
        int discSelectorTest = Array.IndexOf(args, "--test-disc-selectors");
        if (discSelectorTest >= 0 && discSelectorTest + 1 < args.Length) {
            await TestDiscSelectors(args[discSelectorTest + 1]);
            return;
        }
        int backgroundTest = Array.IndexOf(args, "--test-background-playback");
        if (backgroundTest >= 0 && backgroundTest + 1 < args.Length) {
            await TestBackgroundPlayback(args[backgroundTest + 1]);
            return;
        }
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
        int probe = Array.IndexOf(args, "--probe-controller");
        int page = Array.IndexOf(args, "--page");
        if (page >= 0 && page + 1 < args.Length &&
            new[] { "Play", "Graphics", "Audio", "Controller", "Saves", "Coop", "Mods", "Cheats", "Setup",
                    "Launcher", "Logs", "Developer" }
                .Contains(args[page + 1]))
            ShowPage(args[page + 1]);
        if (screenshot >= 0 && screenshot + 1 < args.Length) {
            if (args.Contains("--preview-file2")) {
                settings.SelectedGame = "file2";
                RefreshGameUi();
            }
            if (args.Contains("--compact-preview")) {
                Width = MinWidth;
                Height = MinHeight;
            }
            if (args.Contains("--controller-page"))
                ShowPage("Controller");
            if (args.Contains("--preview-keyboard")) {
                controller.Select("keyboard");
                controller.Poll();
                UpdateInputUi();
            }
            if (args.Contains("--preview-bindings"))
                ShowBindings(this, new());
            if (args.Contains("--preview-sticks"))
                ShowInputLayout(this, new());
            if (args.Contains("--scroll-end"))
                await Dispatcher.InvokeAsync(SettingsScroll.ScrollToEnd,
                                       System.Windows.Threading.DispatcherPriority.Loaded);
            // Capture the same artwork used by the live launcher, without private paths.
            await LoadArtworkAsync();
            await Task.Delay(1500);
            if (args.Contains("--public-preview")) {
                // First-run state without this PC's disc, build or user-supplied cover art.
                // Nothing here is saved.
                initialized = false;
                settings.Iso = "";
                settings.Exe = AppLayout.Native(root, "file1");
                discCheck = null;
                RefreshGameUi();
                graphicsCards = Array.Empty<string>();
                CoopHost.Text = "";
                AccountUsername.Text = "";
                settings.CoopHost = "";
                settings.AccountUsername = "";
                settings.CoopMode = args.Contains("--preview-join") ? "join" : "offline";
                (settings.CoopMode == "join" ? ModeJoin : ModeOffline).IsChecked = true;
                RefreshOnlineUi();
                LaunchButton.Content = PlayButtonLabel;
                initialized = true;
            }
            if (args.Contains("--preview-color")) {
                initialized = false;
                if (args.Contains("--preview-bright")) {
                    Brightness.Value = 125;
                    Gamma.Value = 1.25;
                }
                UpdateColorPreview();
                initialized = true;
                SettingsScroll.ScrollToVerticalOffset(410);
                UpdateLayout();
                await Task.Delay(200);
            }
            if (args.Contains("--preview-setup-download") ||
                args.Contains("--preview-setup-prepare")) {
                var progress = BeginDiscImport();
                progress.Report(args.Contains("--preview-setup-download")
                                    ? new(90671806, 181343612,
                                          "Downloading Windows x64 build tools",
                                          "Downloading compiler")
                                    : new(2800, 5601, "Preparing Windows x64 build tools",
                                          "Preparing compiler"));
                await Task.Delay(150);
            }
            if (args.Contains("--preview-server-setup")) {
                initialized = false;
                settings.CoopMode = "host";
                ModeHost.IsChecked = true;
                initialized = true;
                RefreshOnlineUi();
                HostSetupActivity.Visibility = Visibility.Visible;
                HostStatus.Text = "Opening your game...";
                ReportHostSetup(new(0, 0,
                                    "Downloading Python 3.12 for your private server environment",
                                    "Preparing Python"));
                SettingsScroll.ScrollToVerticalOffset(200);
                await Task.Delay(150);
            }
            if (args.Contains("--preview-status")) {
                Status.Text = "Saved · Developer recordings apply on the next launch";
                await Task.Delay(400);
            }
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96,
                                                PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using (var output = File.Create(args[screenshot + 1])) encoder.Save(output);
            if (!args.Contains("--keep-open")) {
                importCancellation?.Dispose();
                importCancellation = null;
                Close();
            }
        }
        if (probe >= 0 && probe + 1 < args.Length) {
            ShowPage("Controller");
            await Task.Delay(4000);
            File.WriteAllText(
                args[probe + 1],
                JsonSerializer.Serialize(
                    new { selectedDevice = controller.SelectedDevice,
                          availableDevices = controller.AvailableDevices,
                          connected = controller.Connected, reports = controller.Reports,
                          transport = controller.Transport, state = controller.State,
                          nativeXInput = SelfTest.Probe(controller) },
                    new JsonSerializerOptions { WriteIndented = true }));
            Close();
        }
        int smoke = Array.IndexOf(args, "--smoke-launch");
        if (smoke >= 0 && smoke + 2 < args.Length) {
            var coopCheck = CoopSmokeOptions.Parse(args);
            try {
            if (coopCheck?.AllowConcurrent != true && !args.Contains("--test-roster-probe") && !args.Contains("--test-peer-room") && Process.GetProcesses().Any(
                    p => p.ProcessName.StartsWith("reo_recomp",
                                                  StringComparison.OrdinalIgnoreCase) ||
                         p.ProcessName == "reo_launcher_game"))
                throw new InvalidOperationException(
                    "Another game is active; refusing concurrent launch check.");
            var snapshot =
                JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
            if (args.Contains("--test-memory-card")) {
                snapshot.MemoryCardFile1 =
                    Path.Combine(Settings.Home, "test-cards", "launcher-diagnostic");
                snapshot.MemoryCardFile2 =
                    Path.Combine(Settings.Home, "test-cards", "launcher-diagnostic-file2");
                Directory.CreateDirectory(snapshot.MemoryCardFile2);
                if(args.Contains("--test-roster-probe") || args.Contains("--test-peer-room"))
                    snapshot.MemoryCardFile1 = Path.Combine(Settings.Home,"test-cards","roster-"+Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(snapshot.MemoryCardFile1);
                snapshot.SelectCard(args.Contains("--test-file2") ? snapshot.MemoryCardFile2 : snapshot.MemoryCardFile1);
                if (!args.Contains("--test-physical-pad")) controller.Select("keyboard");
            }
            int file2Test = Array.IndexOf(args, "--test-file2");
            if (file2Test >= 0 && file2Test + 1 < args.Length) {
                snapshot.SelectedGame = "file2";
                snapshot.SecondExe = Path.GetFullPath(args[smoke + 1]);
                snapshot.SecondIso = Path.GetFullPath(args[file2Test + 1]);
            } else {
                snapshot.SelectedGame = "file1";
                snapshot.Exe = Path.GetFullPath(args[smoke + 1]);
            }
            snapshot.DualSense = true;
            if (args.Contains("--test-controls")) {
                snapshot.Fullscreen = false;
                snapshot.WindowSize = 0;
            }
            if (args.Contains("--test-sync-vif")) snapshot.AsyncVif = false;
            if (args.Contains("--test-cpu-movies")) snapshot.GpuMovies = false;
            bool displayTest = args.Contains("--display-test");
            if (displayTest) {
                snapshot.AspectRatio = args.Contains("--test-16x9") ? "16:9" : "4:3";
                snapshot.ScreenFit = args.Contains("--test-stretch")  ? "stretch"
                                     : args.Contains("--test-center") ? "center"
                                     : args.Contains("--test-fill")   ? "fill"
                                                                      : "fit";
                snapshot.Fullscreen = args.Contains("--test-fullscreen");
                snapshot.WindowSize = args.Contains("--test-4k")     ? 6
                                      : args.Contains("--test-1440p") ? 5
                                      : args.Contains("--test-native-output") ? 7
                                      : args.Contains("--test-1080p")  ? 4
                                      : args.Contains("--test-720p") ? 3
                                                                     : 0;
                snapshot.TextureLinear = args.Contains("--test-linear-textures");
                snapshot.PerformanceOverlay = args.Contains("--test-performance-overlay");
                snapshot.InternalResolution = args.Contains("--test-internal-4x") ? 4
                                              : args.Contains("--test-internal-2x") ? 2 : 1;
                snapshot.Anisotropy = args.Contains("--test-anisotropic") ? 16 : 1;
                snapshot.LinearFilter = !args.Contains("--test-nearest");
                snapshot.AntiAliasing = !args.Contains("--test-aa-off");
                snapshot.AntiAliasingMode = args.Contains("--test-aa-off") ? "off"
                                            : args.Contains("--test-smaa") ? "smaa"
                                                                           : "fxaa";
                snapshot.Brightness = 100;
                snapshot.Gamma = 1.0;
                if (args.Contains("--test-bright")) {
                    snapshot.Brightness = 125;
                    snapshot.Gamma = 1.25;
                }
            }
            string? diagnosticRoute = displayTest && file2Test < 0
                                          ? args.Contains("--test-room")        ? "gameplay"
                                            : args.Contains("--test-main-menu") ? "main-menu"
                                            : args.Contains("--test-character") ? "character"
                                                                                : "title"
                                          : null;
            LobbyAutomation.Options? diagnosticLobby = null;
            if (coopCheck != null) {
                coopCheck.Prepare(snapshot);
                if (!OnlineOptions.Configured(snapshot))
                    throw new InvalidOperationException("Co-op is not enabled for this edition in the current launcher build.");
                controller.Configure(snapshot);
                controller.Select("keyboard");
                HostNetworking.Current = new(snapshot.SignupPort, snapshot.GamePort);
                if (coopCheck.StartServer)
                    await hostedServer.Start(root, coopCheck.Address, stateHome: coopCheck.AccountHome,
                                             game: snapshot.Game.Id);
                if (coopCheck.Mode == "host") {
                    lanResponder = new LanDiscovery.Responder(
                        () => new(coopCheck.Player, coopCheck.Address, Updates.DefaultVersion,
                                  hostRoomReady && game.Running, snapshot.SignupPort, snapshot.Game.Id),
                        () => game.Running ? game.HostRandomizerConfiguration : null,
                        System.Net.IPAddress.Loopback);
                }
                if (coopCheck.Lobby) {
                    diagnosticLobby = new(coopCheck.Mode == "host", coopCheck.Room, coopCheck.Address,
                                          ready => hostRoomReady = ready, snapshot.Game.Id);
                    diagnosticRoute = null;
                } else diagnosticRoute = "network-auto";
            }
            if (args.Contains("--test-builtin-cheats")) {
                snapshot.CheatsEnabled = true;
                snapshot.EnabledCheats = Cheats.Builtins("file1").Select(g => g.Id).ToList();
            }
            string? testCheatFile = null;
            int testMod = Array.IndexOf(args, "--test-mod");
            if (testMod >= 0) {
                if (testMod + 1 >= args.Length)
                    throw new ArgumentException("--test-mod requires an installed mod ID.");
                snapshot.ActiveMods = new() { args[testMod + 1] };
                snapshot.CheatsEnabled = false;
                snapshot.EnabledCheats.Clear();
                snapshot.CoopMode = "offline";
                snapshot.HostServer = false;
                snapshot.CoopHost = "";
                diagnosticRoute = "gameplay";
            }
            if (args.Contains("--test-no-mods")) {
                snapshot.ActiveMods.Clear();
                snapshot.CheatsEnabled = false;
                snapshot.EnabledCheats.Clear();
            }
            if (args.Contains("--test-pickup")) diagnosticRoute = "gameplay-pickup";
            if (args.Contains("--test-room-preview")) diagnosticRoute = "gameplay-preview";
            if (args.Contains("--test-enemies")) diagnosticRoute = "gameplay-enemies";
            if (args.Contains("--test-enemy-combat")) diagnosticRoute = "gameplay-enemy-combat";
            if (args.Contains("--test-roster-probe")) diagnosticRoute = "gameplay-roster-probe";
            if (args.Contains("--test-cheats")) {
                string folder = Cheats.Folder("file1");
                Directory.CreateDirectory(folder);
                testCheatFile =
                    Path.Combine(folder, "__test-" + Guid.NewGuid().ToString("N") + ".pnach");
                string text = "[Diagnostic padding write]\npatch=2,EE,0056FFF0,word,13579BDF";
                File.WriteAllText(testCheatFile, text);
                snapshot.CheatsEnabled = true;
                snapshot.EnabledCheats =
                    Cheats.Parse(text, Path.GetFileName(testCheatFile)).Select(g => g.Id).ToList();
            }
            try {
                uint? diagnosticSeed = null;
                int seedArgument = Array.IndexOf(args, "--test-fixed-seed");
                if (seedArgument >= 0) {
                    if (seedArgument + 1 >= args.Length || !uint.TryParse(args[seedArgument + 1], out uint seed))
                        throw new ArgumentException("--test-fixed-seed requires a uint32 seed.");
                    diagnosticSeed = seed;
                }
                await game.Launch(root, snapshot, controller, diagnosticRoute,
                                  lobby: diagnosticLobby, diagnosticSeed: diagnosticSeed,
                                  diagnosticColdCache: args.Contains("--test-cold-shaders"),
                                  accountHome: coopCheck?.AccountHome, workingDirectory: coopCheck?.Work);
                if (coopCheck != null)
                    File.WriteAllText(Path.Combine(coopCheck.Folder, "running.json"), JsonSerializer.Serialize(
                        new { game = snapshot.Game.Id, player = coopCheck.Player, mode = coopCheck.Mode,
                              pid = game.Process!.Id, image = game.Process.StartInfo.FileName,
                              creationFileTime = game.Process.StartTime.ToFileTimeUtc(),
                              logs = game.Logs, map = controller.MapName, card = snapshot.CardFolder(root),
                              accountHome = coopCheck.AccountHome, workingDirectory = coopCheck.Work },
                        new JsonSerializerOptions { WriteIndented = true }));
                UpdateRandomizerSeed();
            } finally {
                if (testCheatFile != null)
                    File.Delete(testCheatFile);
            }
            previousRunning = true;
            if (args.Contains("--test-wait-graphics"))
                await game.WaitForGraphicsReadyAsync(TimeSpan.FromMinutes(10));
            await Task.Delay(coopCheck != null                         ? coopCheck.Seconds * 1000
                             : args.Contains("--test-controls")        ? 60000
                             : args.Contains("--test-file2")           ? (args.Contains("--test-quick-display") ? 25000 : 60000)
                             : args.Contains("--test-auto-network")    ? 240000
                             : args.Contains("--test-roster-probe")   ? 95000
                             : args.Contains("--test-quick-display") ? 25000
                             : args.Contains("--test-room-preview")  ? 80000
                               : args.Contains("--test-enemy-long") ? 420000
                               : args.Contains("--test-enemies") || args.Contains("--test-enemy-combat") ? 180000
                             : args.Contains("--test-pickup")        ? 120000
                             : args.Contains("--test-room")          ? 180000
                             : args.Contains("--test-memory-card")   ? 300000
                             : displayTest ? args.Contains("--test-character") ? 110000 : 65000
                                           : 10000);
            object? windowState = game.Running ? GameSession.InspectWindow(game.Process!) : null;
            string? module =
                game.Running
                    ? game.Process!.Modules.Cast<ProcessModule>()
                          .FirstOrDefault(m => string.Equals(m.ModuleName, "XINPUT1_4.dll",
                                                             StringComparison.OrdinalIgnoreCase))
                          ?.FileName
                    : null;
            bool close = game.Running && game.Process!.CloseMainWindow();
            if (game.Running)
                await Task.WhenAny(game.Process!.WaitForExitAsync(), Task.Delay(25000));
            bool exited = !game.Running;
            File.WriteAllText(
                args[smoke + 2],
                JsonSerializer.Serialize(
                    new { windowState, copiedImage = game.Process!.StartInfo.FileName,
                          logs = game.Logs, controllerConnected = controller.Connected,
                          xinputModule = module, closePosted = close, exited,
                          exitCode = exited ? game.Process.ExitCode : (int?)null },
                    new JsonSerializerOptions { WriteIndented = true }));
            if (exited)
                Close();
            } catch (Exception error) when (coopCheck != null) {
                bool forced = false;
                if (game.Running) {
                    game.Process!.CloseMainWindow();
                    await Task.WhenAny(game.Process.WaitForExitAsync(), Task.Delay(5000));
                    if (game.Running) {
                        // This window owns the diagnostic process and its disposable card.
                        game.Process.Kill();
                        forced = true;
                        await game.Process.WaitForExitAsync();
                    }
                }
                string result = Path.GetFullPath(args[smoke + 2]);
                Directory.CreateDirectory(Path.GetDirectoryName(result)!);
                File.WriteAllText(result, JsonSerializer.Serialize(new {
                    failed = true, error = error.GetBaseException().Message, logs = game.Logs,
                    forcedStop = forced, session = coopCheck.Folder, coopVerdict = "not-verified"
                }, new JsonSerializerOptions { WriteIndented = true }));
                hostedServer.Dispose();
                Application.Current.Shutdown(1);
            }
        }
    }
}
