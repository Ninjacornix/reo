using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed class GameSession {
    public Process? Process { get; private set; }
    public string? Logs { get; private set; }
    public ImportedDisc? Imported { get; private set; }
    public string? NetworkStatus { get; private set; }
    public string? MovieStatus { get; private set; }
    public bool Running => Process is { HasExited : false };
    public static string SaveFolder(string root, string game = "file1") =>
        AppLayout.Packaged(root)
            ? Path.Combine(Settings.Home, "memory-cards", "default", game, "data")
            : Path.Combine(root, "build-ninja", GameDefinition.Find(game).PlayFolder, "saves");

    public async Task Launch(string root, Settings settings, Controller controller,
                             string? diagnosticRoute = null,
                             IProgress<ImportProgress>? importProgress = null,
                             CancellationToken cancel = default,
                             LobbyAutomation.Options? lobby = null) {
        if (Running)
            throw new InvalidOperationException("The launcher already has a game session running.");
        var onlineEnvironment = OnlineOptions.LaunchEnvironment(settings);
        NetworkStatus = null;
        string sourceExe = settings.GetExe(), iso = settings.GetIso();
        var selectedGame = settings.Game;
        if (selectedGame.Id != "file1")
            throw new IOException("File #2 is not available in this release.");
        if (!AppLayout.Packaged(root) && !File.Exists(sourceExe))
            throw new FileNotFoundException(
                "This game build is missing. Extract the complete release archive.");
        if (!File.Exists(iso))
            throw new FileNotFoundException("Choose the selected game's ISO in Game files.");
        Imported = await DiscImport.Ensure(
            iso, selectedGame, DiscImport.ExpectedElf(settings, root), importProgress, cancel);
        cancel.ThrowIfCancellationRequested();
        settings.SetImport(Imported.Root);
        if (AppLayout.Packaged(root))
            sourceExe = await LocalGameBuild.Ensure(root, Imported, importProgress, cancel);
        string discRoot = Path.Combine(Imported.Root, "data"), discElf = Imported.Elf;
        string proxy = Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll");
        if (!File.Exists(proxy))
            throw new FileNotFoundException("The installation is missing its controller adapter. " +
                                            "Extract the complete release archive.");
        var runtimeFiles = new List<GameImageCache.Input> {
            new(sourceExe, "reo_launcher_game.exe"), new(proxy, "XINPUT1_4.dll")
        };
        string sourceFolder = Path.GetDirectoryName(Path.GetFullPath(sourceExe))!;
        string shaderSource = Path.Combine(sourceFolder, "reo-gpu-present");
        foreach (string shader in new[] { "present_opaque.vert.spv", "present_native.frag.spv",
            "present_smaa_edge.frag.spv", "present_smaa_weights.frag.spv", "present_smaa_blend.frag.spv" }) {
            string input = Path.Combine(shaderSource, shader);
            if (File.Exists(input)) runtimeFiles.Add(new(input, "reo-gpu-present/" + shader));
            else if (!shader.StartsWith("present_smaa_") || settings.ResolvedAntiAliasing == "smaa")
                throw new FileNotFoundException("The selected build is missing its presentation shader: " + shader);
        }
        // GPU helper shaders (movies, context clears, readbacks) that the game loads from
        // reo-gpu-present; developer builds without them read the source tree instead.
        foreach (string shader in new[] { "movie_ipu_csc_nv12.spv", "resident_image_upload.spv",
            "clear_setup.spv", "clear_bounds.spv", "clear_write.spv", "resident_readback.spv" }) {
            string input = Path.Combine(shaderSource, shader);
            if (File.Exists(input)) runtimeFiles.Add(new(input, "reo-gpu-present/" + shader));
        }
        foreach (string dependency in new[] { "msvcp140.dll", "msvcp140_atomic_wait.dll",
            "vcruntime140.dll", "vcruntime140_1.dll", "libc++.dll", "libunwind.dll", "libwinpthread-1.dll" }) {
            string input = Path.Combine(sourceFolder, dependency);
            if (File.Exists(input)) runtimeFiles.Add(new(input, dependency));
        }
        string vulkanLoader = Path.Combine(sourceFolder, "vulkan-1.dll");
        if (File.Exists(vulkanLoader)) runtimeFiles.Add(new(vulkanLoader, "vulkan-1.dll"));
        var cached = await Task.Run(() => GameImageCache.Prepare(
            Path.Combine(Settings.Home, "game-cache"), runtimeFiles, cancel), cancel);
        string image = cached.Image, hash = cached.Sha256;
        Logs = Path.Combine(Settings.Home, "sessions", DateTime.Now.ToString("yyyyMMdd-HHmmss-fff"));
        Directory.CreateDirectory(Logs);
        Directory.CreateDirectory(SaveFolder(root, selectedGame.Id));
        Directory.CreateDirectory(AppLayout.Work(root, selectedGame.Id));
        var start = new ProcessStartInfo(
            image) { UseShellExecute = false, CreateNoWindow = true,
                     WorkingDirectory = AppLayout.Work(root, selectedGame.Id),
                     RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string arg in new[] { "--game", selectedGame.Id, "--elf", discElf, "--data",
                                       discRoot })
            start.ArgumentList.Add(arg);
        foreach (var key in start.Environment.Keys
                     .Where(k => k.StartsWith("REO_", StringComparison.OrdinalIgnoreCase))
                     .ToArray())
            start.Environment.Remove(key);
        void Set(string key, string value) => start.Environment[key] = value;
        bool automaticAccount = onlineEnvironment.Count > 0 &&
                                await Task.Run(() => SupportsAutomaticAccount(image), cancel);
        if (onlineEnvironment.Count > 0 && !automaticAccount) {
            onlineEnvironment.Remove("REO_COOP_AUTO_ACCOUNT");
            NetworkStatus =
                "This older game build uses manual network login. Automatic login needs the updated game build.";
        }
        foreach (var pair in onlineEnvironment)
            Set(pair.Key, pair.Value);
        string? keyboardQueue = null;
        if (lobby != null && automaticAccount && diagnosticRoute == null) {
            // Title -> Network -> automatic sign-in uses the native route; the launcher then steers
            // the lobby. Pad input from the launcher map also applies while the game is unfocused.
            Set("REO_TEST_ROUTE", "network-auto");
            Set("REO_COOP_TEST_INPUT", "1");
            keyboardQueue = Path.Combine(Logs, "keyboard.bin");
            LobbyAutomation.CreateKeyboardQueue(keyboardQueue);
            Set("REO_COOP_KEYBOARD_FILE", keyboardQueue);
        }
        string cheatFile = Cheats.Export(settings, Logs);
        if (cheatFile.Length != 0)
            Set("REO_CHEATS_FILE", cheatFile);
        Set("REO_ISO", Path.GetFullPath(iso));
        Set("REO_NATURAL", "1");
        Set("REO_TURBO", "1"); // existing normal-speed scheduling mode, no time warp
        Set("REO_GS_BACKEND", "parallel");
        Set("REO_GS_THREAD", "1");
        Set("REO_GS_GPU_PRESENT", "1");
        Set("REO_GS_DISPATCH_PACE", "2");
        Set("REO_GS_SPRITE_DEPTH_PARALLEL", "1");
        Set("REO_VIF1_ASYNC", settings.AsyncVif ? "1" : "0");
        Set("REO_VIF1_GPU_RESIDENT", "0");
        Set("REO_DISPLAY_ASPECT", settings.ResolvedAspect);
        Set("REO_DISPLAY_FIT", settings.ResolvedFit);
        Set("REO_DISPLAY_FILTER", settings.LinearFilter ? "linear" : "nearest");
        var outputSize = DisplayOptions.Size(settings.WindowSize);
        Set("REO_WINDOW_WIDTH", outputSize.Width.ToString());
        Set("REO_WINDOW_HEIGHT", outputSize.Height.ToString());
        Set("REO_TEXTURE_FILTER", settings.TextureLinear ? "linear" : "original");
        Set("REO_TEXTURE_ANISOTROPY", settings.ResolvedAnisotropy.ToString());
        Set("REO_POST_AA", settings.ResolvedAntiAliasing);
        Set("REO_BRIGHTNESS",
            (settings.Brightness / 100.0)
                .ToString("F2", System.Globalization.CultureInfo.InvariantCulture));
        Set("REO_GAMMA",
            settings.Gamma.ToString("F2", System.Globalization.CultureInfo.InvariantCulture));
        if (diagnosticRoute != null) {
            Set("REO_TEST_ROUTE", diagnosticRoute);
            if (settings.CheatsEnabled)
                Set("REO_CHEAT_DIAG", "1");
        }
        if (diagnosticRoute == "gameplay") {
            Set("REO_TEST_ROOM_SOAK", "1");
            Set("REO_GAME_CLOCK_LOG", "1");
            Set("REO_GAME_CLOCK_FROM_SECS", "0");
            Set("REO_GAME_CLOCK_SECONDS", "300");
            Set("REO_GAME_CLOCK_FILE", Path.Combine(Logs, "clock.csv"));
        }
        // GPU movies when the rendering GPU has a hardware MPEG-2 decoder and the player left them
        // on in Graphics; otherwise the original CPU decoder.
        MovieDecoderChoice movies = await MovieDecoder.Choose(cancel);
        bool gpuMovies = movies.Gpu && settings.GpuMovies;
        MovieStatus = gpuMovies   ? "Movies: graphics card"
                      : movies.Gpu ? "Movies: processor (chosen in Graphics)"
                                   : "Movies: processor (" + movies.Reason + ")";
        Set("REO_GPU_MOVIE", gpuMovies ? "1" : "0");
        controller.Select(
            controller.SelectedDevice.Id); // pin the chosen source across hotplug events
        controller.SessionEnabled = true;
        controller.Publish();
        Set("REO_LAUNCHER_PAD_MAP", controller.MapName);
        string cardFolder = settings.CardFolder(root);
        start.Environment["REO_MC0_ROOT"] = cardFolder;
        start.Environment["REO_MC1_ROOT"] = ":none:";
        if (!Directory.Exists(cardFolder) &&
            !string.Equals(cardFolder, Path.GetFullPath(SaveFolder(root, selectedGame.Id)),
                           StringComparison.OrdinalIgnoreCase))
            throw new DirectoryNotFoundException("The selected memory card folder no longer " +
                                                 "exists. Select another card in Save games.");
        var cardLease = MemoryCards.Acquire(cardFolder);
        string networkProfileMarker;
        try {
            networkProfileMarker = OnlineOptions.PrepareMemoryCard(settings, cardFolder, cardLease);
        } catch {
            cardLease.Dispose();
            throw;
        }
        var stdout = new StreamWriter(Path.Combine(Logs, "stdout.log")) { AutoFlush = true };
        var stderr = new StreamWriter(Path.Combine(Logs, "stderr.log")) { AutoFlush = true };
        AutomaticAccount? account = null;
        Process = new Process { StartInfo = start };
        try {
            account = automaticAccount
                          ? new AutomaticAccount(Settings.Home, settings, text => NetworkStatus = text,
                                                 MainWindow.SignupEndpoint(settings, null))
                          : null;
            account?.Bind(start);
            cancel.ThrowIfCancellationRequested();
            if (!Process.Start())
                throw new IOException("Windows could not start the game.");
        } catch {
            account?.Dispose();
            cardLease.Dispose();
            stdout.Dispose();
            stderr.Dispose();
            throw;
        }
        LobbyAutomation? automation = null;
        if (keyboardQueue != null) {
            automation = new LobbyAutomation(Process, discElf, controller, keyboardQueue, lobby!,
                                             text => NetworkStatus = text);
            _ = automation.Run();
        }
        _ = RecordExit(Process, Logs, cardLease, account, automation);
        controller.GameProcessId = Process.Id;
        _ = Pump(Process.StandardOutput, stdout);
        _ = Pump(Process.StandardError, stderr, account == null ? null : account.Observe);
        await File.WriteAllTextAsync(
            Path.Combine(Logs, "launch.json"),
            JsonSerializer.Serialize(
                new { pid = Process.Id,
                      game = selectedGame.Id,
                      source = sourceExe,
                      image,
                      sha256 = hash,
                      iso,
                      discRoot,
                      networkConfigured = OnlineOptions.Configured(settings),
                      server = onlineEnvironment.GetValueOrDefault("REO_COOP_HOST"),
                      accountUsername = onlineEnvironment.GetValueOrDefault("REO_COOP_USERNAME"),
                      networkProfileMarker,
                      automaticLobby = keyboardQueue != null,
                      inputDevice = controller.SelectedDevice.Name,
                      fullscreen = settings.Fullscreen,
                      resolution = DisplayOptions.Size(settings.WindowSize),
                      linearScaling = settings.LinearFilter,
                      textureLinear = settings.TextureLinear,
                      anisotropy = settings.ResolvedAnisotropy,
                      aspectRatio = settings.ResolvedAspect,
                      screenFit = settings.ResolvedFit,
                      antiAliasing = settings.ResolvedAntiAliasing,
                      brightness = settings.Brightness,
                      gamma = settings.Gamma,
                      memoryCard = cardFolder,
                      importedData = discRoot,
                      importReused = Imported.Reused,
                      mountedIso = false,
                      directIso = true,
                      movieDecoder = gpuMovies ? "gpu" : "cpu",
                      gpuMoviesAvailable = movies.Gpu,
                      gpuMoviesSetting = settings.GpuMovies,
                      movieDecoderGpu = movies.GpuName,
                      movieDecoderReason = movies.Reason },
                new JsonSerializerOptions { WriteIndented = true }));
        _ = ApplyWindow(Process, settings);
    }
    async Task RecordExit(Process process, string logs, FileStream cardLease,
                          AutomaticAccount? account, LobbyAutomation? automation) {
        try {
            await process.WaitForExitAsync();
        } finally {
            automation?.Dispose();
            account?.Dispose();
            NetworkStatus = null;
            cardLease.Dispose();
        }
        await File.WriteAllTextAsync(Path.Combine(logs, "exit.json"), JsonSerializer.Serialize(new {
            pid = process.Id, exitCode = process.ExitCode, utc = DateTime.UtcNow
        }));
    }
    // Drain pipes independently of the UI: native window messages can wait on the game.
    internal static bool SupportsAutomaticAccount(string image) {
        byte[] marker = System.Text.Encoding.ASCII.GetBytes("[COOP-AUTO] native-password-applied %u");
        byte[] buffer = new byte[1024 * 1024 + marker.Length];
        using var source = File.OpenRead(image);
        int retained = 0, read;
        while ((read = source.Read(buffer, retained, buffer.Length - retained)) > 0) {
            int length = retained + read;
            if (buffer.AsSpan(0, length).IndexOf(marker) >= 0)
                return true;
            retained = Math.Min(marker.Length - 1, length);
            buffer.AsSpan(length - retained, retained).CopyTo(buffer);
        }
        return false;
    }
    internal static async Task Pump(StreamReader input, StreamWriter output,
                                    Action<string>? observe = null) {
        using (output) {
            string? line;
            while ((line = await input.ReadLineAsync().ConfigureAwait(false)) != null) {
                await output.WriteLineAsync(line).ConfigureAwait(false);
                observe?.Invoke(line);
            }
        }
    }
    static async Task ApplyWindow(Process process, Settings settings) {
        for (int i = 0; i < 1200 && !process.HasExited; ++i) {
            await Task.Delay(100).ConfigureAwait(false);
            process.Refresh();
            nint hwnd = process.MainWindowHandle;
            if (hwnd == 0)
                continue;
            _ = GameWindowIcon.Apply(process, hwnd);
            if (settings.Fullscreen) {
                long style = GetWindowLongPtr(hwnd, -16).ToInt64() & ~0x00CF0000L;
                SetWindowLongPtr(hwnd, -16, new nint(style));
                var info = new MonitorInfo { Size = Marshal.SizeOf<MonitorInfo>() };
                if (GetMonitorInfo(MonitorFromWindow(hwnd, 2), ref info))
                    SetWindowPos(hwnd, 0, info.Monitor.Left, info.Monitor.Top,
                                 info.Monitor.Right - info.Monitor.Left,
                                 info.Monitor.Bottom - info.Monitor.Top, 0x4024);
            } else {
                var size = DisplayOptions.Size(settings.WindowSize);
                var rect = new Rect { Right = size.Width, Bottom = size.Height };
                AdjustWindowRectExForDpi(ref rect, (uint)GetWindowLongPtr(hwnd, -16).ToInt64(),
                                         false, (uint)GetWindowLongPtr(hwnd, -20).ToInt64(),
                                         GetDpiForWindow(hwnd));
                SetWindowPos(hwnd, 0, 80, 60, rect.Right - rect.Left, rect.Bottom - rect.Top,
                             0x4024);
            }
            break;
        }
    }
    public static object? InspectWindow(Process process) {
        if (process.HasExited)
            return null;
        process.Refresh();
        nint window = process.MainWindowHandle;
        if (window == 0 || !GetClientRect(window, out var client) ||
            !GetWindowRect(window, out var bounds))
            return null;
        return new { clientWidth = client.Right - client.Left,
                     clientHeight = client.Bottom - client.Top,
                     x = bounds.Left,
                     y = bounds.Top,
                     width = bounds.Right - bounds.Left,
                     height = bounds.Bottom - bounds.Top,
                     borderless = (GetWindowLongPtr(window, -16).ToInt64() & 0x00CF0000L) == 0 };
    }
    [StructLayout(LayoutKind.Sequential)]
    struct Rect {
        public int Left, Top, Right, Bottom;
    }
    [StructLayout(LayoutKind.Sequential)]
    struct MonitorInfo {
        public int Size;
        public Rect Monitor, Work;
        public uint Flags;
    }
    [DllImport("user32")]
    static extern nint GetWindowLongPtrW(nint hwnd, int index);
    static nint GetWindowLongPtr(nint hwnd, int index) => GetWindowLongPtrW(hwnd, index);
    [DllImport("user32", EntryPoint = "SetWindowLongPtrW")]
    static extern nint SetWindowLongPtr(nint hwnd, int index, nint value);
    [DllImport("user32")]
    static extern bool SetWindowPos(nint hwnd, nint after, int x, int y, int width, int height,
                                    uint flags);
    [DllImport("user32")]
    static extern uint GetDpiForWindow(nint window);
    [DllImport("user32")]
    static extern bool GetClientRect(nint window, out Rect rect);
    [DllImport("user32")]
    static extern bool GetWindowRect(nint window, out Rect rect);
    [DllImport("user32")]
    static extern bool AdjustWindowRectExForDpi(ref Rect rect, uint style, bool menu,
                                                uint extendedStyle, uint dpi);
    [DllImport("user32")]
    static extern nint MonitorFromWindow(nint hwnd, uint flags);
    [DllImport("user32", CharSet = CharSet.Unicode)]
    static extern bool GetMonitorInfo(nint monitor, ref MonitorInfo info);
}
