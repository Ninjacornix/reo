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
    bool initialized, launching, previousRunning, backingUp;
    public MainWindow(string[] arguments) {
        args = arguments;
        root = AppLayout.FindRoot(AppContext.BaseDirectory);
        settings = Settings.Load(root);
        if (settings.Game.Id == "file2" && !arguments.Contains("--preview-file2"))
            settings.SelectedGame = "file1"; // File #2 is shown as coming later and cannot be selected
        controller.Configure(settings);
        InitializeComponent();
        VersionLabel.Text = Updates.DisplayName;
        DeveloperFiles.Visibility =
            AppLayout.Packaged(root) ? Visibility.Collapsed : Visibility.Visible;
        WindowSize.ItemsSource = DisplayOptions.Sizes;
        WindowSize.SelectedIndex = settings.WindowSize;
        Filter.SelectedIndex = settings.LinearFilter ? 0 : 1;
        AspectRatio.SelectedIndex = settings.ResolvedAspect == "16:9" ? 1 : 0;
        ScreenFit.SelectedIndex = Array.IndexOf(DisplayOptions.Fits, settings.ResolvedFit);
        UpdateScreenFitHint();
        Fullscreen.IsChecked = settings.Fullscreen;
        AsyncVif.IsChecked = settings.AsyncVif;
        InitializeOnline();
        TextureFilter.SelectedIndex = settings.TextureLinear ? 1 : 0;
        AnisotropicFilter.SelectedIndex =
            Array.IndexOf(new[] { 1, 2, 4, 8, 16 }, settings.ResolvedAnisotropy);
        AntiAlias.SelectedIndex = settings.ResolvedAntiAliasing switch { "smaa" => 2, "fxaa" => 1,
                                                                         _ => 0 };
        WindowSize.IsEnabled = !settings.Fullscreen;
        Brightness.Value = settings.Brightness;
        Gamma.Value = settings.Gamma;
        InitializeColorPreview();
        initialized = true;
        ShowPage("Play");
        UpdateSaves();
        InitializeInput();
        RefreshGameUi();
        SourceInitialized += (_, _) => controller.Attach(new WindowInteropHelper(this).Handle);
        timer.Tick += Tick;
        timer.Start();
        Closing += OnClosing;
        Closing += (_, e) => {
            if (!e.Cancel && !updateRestarting)
                updateCancellation?.Cancel();
        };
        Closed += (_, _) => {
            timer.Stop();
            accountPreparation?.Cancel();
            lanResponder?.Dispose();
            hostedServer.Dispose();
            if (portsForwarded)
                HostNetworking.ClosePorts().Wait(
                    TimeSpan.FromSeconds(5)); // do not leave router ports open
            controller.Dispose();
        };
        Loaded += OnLoaded;
        Loaded += async (_, _) => await LoadArtworkAsync();
    }
    void Navigate(object sender, RoutedEventArgs e) => ShowPage((string)((Button)sender).Tag);
    void ShowPage(string name) {
        if (!PreparePageChange(name))
            return;
        double artworkOpacity = name == "Play" ? 0.46 : 0.10;
        if (SystemParameters.ClientAreaAnimation)
            ArtworkLayer.BeginAnimation(OpacityProperty,
                                        new System.Windows.Media.Animation.DoubleAnimation(
                                            artworkOpacity, TimeSpan.FromMilliseconds(220)));
        else {
            ArtworkLayer.BeginAnimation(OpacityProperty, null);
            ArtworkLayer.Opacity = artworkOpacity;
        }
        foreach (string page in new[] { "Play", "Graphics", "Controller", "Saves", "Coop", "Mods",
                                        "Cheats", "Setup", "Logs" }) {
            ((FrameworkElement)FindName("Page" + page)).Visibility =
                page == name ? Visibility.Visible : Visibility.Collapsed;
            var button = (Button)FindName("Nav" + page);
            button.Background = new SolidColorBrush(
                (Color)ColorConverter.ConvertFromString(page == name ? "#3A2B2B" : "#181A1B"));
            button.Foreground = (Brush)FindResource(page == name ? "Ink" : "Muted");
            button.BorderBrush = new SolidColorBrush(
                (Color)ColorConverter.ConvertFromString(page == name ? "#BD6665" : "#181A1B"));
        }
        (PageTitle.Text, PageSubtitle.Text) =
            name switch { "Graphics" => ("Graphics", "Display and image settings."),
                          "Controller" => ("Controls", "Devices and bindings."),
                          "Saves" => ("Save games", "Memory cards and backups."),
                          "Coop" => ("Co-op", "Play together with friends."),
                          "Setup" => ("Game files", "Import your game disc."),
                          "Logs" => ("Log", "Game debug and output."),
                          "Mods" => ("Mods", "Game modifications."),
                          "Cheats" => ("Cheats", "Gameplay adjustments."),
                          _ => ("Play", "Choose your game.") };
        SettingsScroll.Visibility = name == "Logs" ? Visibility.Collapsed : Visibility.Visible;
        if (name == "Logs")
            RefreshLogSessions();
        if (name == "Saves")
            UpdateSaves();
        if (name == "Cheats")
            RefreshCheats();
        if (name == "Setup")
            _ = EstimateRemoval();
        AnimatePageChange();
    }
    void SettingChanged(object sender, SelectionChangedEventArgs e) => SaveSettings(sender, e);
    void SaveSettings(object sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        settings.WindowSize =
            Math.Clamp(WindowSize.SelectedIndex, 0, DisplayOptions.Sizes.Length - 1);
        settings.LinearFilter = Filter.SelectedIndex == 0;
        settings.AspectRatio = AspectRatio.SelectedIndex == 1 ? "16:9" : "4:3";
        settings.ScreenFit =
            DisplayOptions
                .Fits[Math.Clamp(ScreenFit.SelectedIndex, 0, DisplayOptions.Fits.Length - 1)];
        UpdateScreenFitHint();
        settings.Fullscreen = Fullscreen.IsChecked == true;
        settings.AsyncVif = AsyncVif.IsChecked == true;
        settings.TextureLinear = TextureFilter.SelectedIndex == 1;
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
        WindowSize.IsEnabled = !settings.Fullscreen;
        try {
            settings.Save();
            Status.Text = "Saved · Changes apply on the next launch";
        } catch (IOException error) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
        SessionSummary.Text = "GPU rendering / " + controller.SelectedDevice.Name;
    }
    void Tick(object? sender, EventArgs e) {
        controller.Publish();
        UpdateInputUi();
        bool running = game.Running;
        StopButton.IsEnabled = running;
        CheatControls.IsEnabled = settings.Game.Id == "file1" && !running && !launching;
        if (++slowUiTick >= 30) {
            slowUiTick = 0;
            RefreshGameUi();
            if (PageLogs.Visibility == Visibility.Visible)
                RefreshLog();
        }
        BackupButton.IsEnabled = !updating && !running && !launching && !backingUp;
        CardControls.IsEnabled = !updating && !running && !launching && !backingUp;
        if (previousRunning && !running) {
            Status.Text = $"Game closed · Exit code {game.Process!.ExitCode} · Session logs saved";
            LaunchButton.Content = "Play";
            LaunchButton.IsEnabled = true;
            controller.SessionEnabled = false;
            hostRoomReady = false;
            UpdateSaves();
        }
        previousRunning = running;
        if (game.NetworkStatus != null)
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
        if (mode != "offline" && settings.Game.Id == "file1") {
            string? problem = OnlineOptions.Error(settings) ??
                              (mode == "host" && !hostedServer.Running
                                   ? "Your game is not open for friends. See Co-op."
                                   : null);
            if (problem != null) {
                Status.Text = problem;
                ShowPage("Coop");
                return;
            }
        }
        launching = true;
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
                    LaunchButton.Content = "Play";
                    ShowPage("Coop");
                    return;
                }
                lobby = LobbyOptions();
                snapshot.JoinHostName = settings.JoinHostName;
                snapshot.JoinSignupPort = settings.JoinSignupPort;
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
            Status.Text = "Game running · Keep the launcher open for input" +
                          (game.MovieStatus is { } movies ? " · " + movies : "");
        } catch (OperationCanceledException) {
            controller.SessionEnabled = false;
            Status.Text = "Import canceled.";
            LaunchButton.IsEnabled = true;
            LaunchButton.Content = "Play";
        } catch (Exception error) {
            controller.SessionEnabled = false;
            Status.Text = "Could not launch: " + error.Message;
            if (error is InvalidDataException) {
                DiscValidationStatus.Text = error.Message;
                DiscValidationStatus.Foreground = (Brush)FindResource("Danger");
            }
            LaunchButton.IsEnabled = true;
            LaunchButton.Content = "Play";
        } finally {
            launching = false;
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
        int count = Directory.Exists(folder)
                        ? Directory.EnumerateFiles(folder, "*", SearchOption.AllDirectories)
                              .Count(p => !Path.GetRelativePath(folder, p)
                                               .Split(Path.DirectorySeparatorChar)
                                               .Any(part => part.StartsWith(
                                                        ".reo-", StringComparison.Ordinal)))
                        : 0;
        SaveCount.Text = count == 0
                             ? "No memory-card files yet. Create a save from the game's menus."
                             : $"{count} memory-card files · Selected memory card";
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
            FileName = "Outbreak-saves-" + DateTime.Now.ToString("yyyyMMdd-HHmmss") + ".zip"
        };
        if (dialog.ShowDialog(this) != true)
            return;
        backingUp = true;
        BackupButton.IsEnabled = false;
        LaunchButton.IsEnabled = false;
        try {
            string temp = dialog.FileName + "." + Guid.NewGuid().ToString("N") + ".tmp";
            await Task.Run(() => ZipFile.CreateFromDirectory(folder, temp));
            File.Move(temp, dialog.FileName, true);
            Status.Text = "Memory-card backup saved.";
        } catch (Exception error) {
            Status.Text = "Backup failed: " + error.Message;
        } finally {
            backingUp = false;
            BackupButton.IsEnabled = true;
            LaunchButton.IsEnabled = true;
        }
    }
    void OnClosing(object? sender, CancelEventArgs e) {
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
        _ = DetectGraphicsCard();
        ReportUpdateResult();
        if (!args.Any(a => a.StartsWith("--test-") || a is "--smoke-launch" or "--screenshot" or
                                                           "--probe-controller"))
            _ = CheckUpdates(true);
        if (settings.ResolvedCoopMode == "host" && args.Length == 0)
            await StartHosting();
        int screenshot = Array.IndexOf(args, "--screenshot");
        int probe = Array.IndexOf(args, "--probe-controller");
        int page = Array.IndexOf(args, "--page");
        if (page >= 0 && page + 1 < args.Length &&
            new[] { "Play", "Graphics", "Controller", "Saves", "Coop", "Mods", "Cheats", "Setup",
                    "Logs" }
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
                LaunchButton.Content = "Play";
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
            if (Process.GetProcesses().Any(
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
                Directory.CreateDirectory(snapshot.MemoryCardFile1);
                controller.Select("keyboard");
            }
            snapshot.SelectedGame = "file1";
            snapshot.Exe = Path.GetFullPath(args[smoke + 1]);
            snapshot.DualSense = true;
            bool displayTest = args.Contains("--display-test");
            if (displayTest) {
                snapshot.AspectRatio = args.Contains("--test-16x9") ? "16:9" : "4:3";
                snapshot.ScreenFit = args.Contains("--test-stretch")  ? "stretch"
                                     : args.Contains("--test-center") ? "center"
                                     : args.Contains("--test-fill")   ? "fill"
                                                                      : "fit";
                snapshot.Fullscreen = args.Contains("--test-fullscreen");
                snapshot.WindowSize = args.Contains("--test-1080p")  ? 4
                                      : args.Contains("--test-720p") ? 3
                                                                     : 0;
                snapshot.TextureLinear = args.Contains("--test-linear-textures");
                snapshot.Anisotropy = args.Contains("--test-anisotropic") ? 16 : 1;
                snapshot.LinearFilter = !args.Contains("--test-nearest");
                snapshot.AntiAliasing = !args.Contains("--test-aa-off");
                snapshot.AntiAliasingMode = args.Contains("--test-aa-off") ? "off"
                                            : args.Contains("--test-smaa") ? "smaa"
                                                                           : "fxaa";
                if (args.Contains("--test-bright")) {
                    snapshot.Brightness = 125;
                    snapshot.Gamma = 1.25;
                }
            }
            string? diagnosticRoute = displayTest
                                          ? args.Contains("--test-room")        ? "gameplay"
                                            : args.Contains("--test-main-menu") ? "main-menu"
                                            : args.Contains("--test-character") ? "character"
                                                                                : "title"
                                          : null;
            if (args.Contains("--test-auto-network")) {
                snapshot.HostServer = false;
                snapshot.Fullscreen = false;
                snapshot.WindowSize = 0;
                snapshot.CoopHost = "127.0.0.1";
                snapshot.AccountUsername =
                    "auto" +
                    System.Security.Cryptography.RandomNumberGenerator.GetInt32(100000, 999999);
                snapshot.MemoryCardFile1 = Path.Combine(
                    Settings.Home, "test-cards", "auto-network-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(snapshot.MemoryCardFile1);
                diagnosticRoute = "network-auto";
            }
            if (args.Contains("--test-builtin-cheats")) {
                snapshot.CheatsEnabled = true;
                snapshot.EnabledCheats = Cheats.Builtins("file1").Select(g => g.Id).ToList();
            }
            string? testCheatFile = null;
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
                await game.Launch(root, snapshot, controller, diagnosticRoute);
            } finally {
                if (testCheatFile != null)
                    File.Delete(testCheatFile);
            }
            previousRunning = true;
            await Task.Delay(args.Contains("--test-auto-network")    ? 240000
                             : args.Contains("--test-quick-display") ? 25000
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
        }
    }
}
