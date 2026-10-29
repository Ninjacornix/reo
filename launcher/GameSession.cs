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
    public OriginalAssetExport? OriginalAssets { get; private set; }
    public string? NetworkStatus { get; private set; }
    volatile string? graphicsStatus;
    public string? GraphicsStatus => graphicsStatus;
    TaskCompletionSource graphicsReady = new(TaskCreationOptions.RunContinuationsAsynchronously);
    internal Task WaitForGraphicsReadyAsync(TimeSpan timeout) => graphicsReady.Task.WaitAsync(timeout);
    public string? MovieStatus { get; private set; }
    internal string? AudioMapName { get; set; }
    public string? RandomizerSeedSummary { get; private set; }
    readonly RandomizerSeeds randomizerSeeds = new();
    internal byte[]? HostRandomizerConfiguration { get; private set; }
    string? randomizerStopReason;
    public bool Running {
        get {
            try { return Process != null && !Process.HasExited; }
            catch (InvalidOperationException) { return false; } // Created, but not started yet.
        }
    }
    public static string SaveFolder(string root, string game = "file1") =>
        Path.Combine(Settings.Home, "memory-cards", "default", game, "data");

    public async Task Launch(string root, Settings settings, Controller controller,
                             string? diagnosticRoute = null,
                             IProgress<ImportProgress>? importProgress = null,
                             CancellationToken cancel = default,
                             LobbyAutomation.Options? lobby = null,
                             uint? diagnosticSeed = null, bool diagnosticColdCache = false,
                             string? accountHome = null, string? workingDirectory = null) {
        if (Running)
            throw new InvalidOperationException("The launcher already has a game session running.");
        var graphics = GraphicsOptions.From(settings);
        OriginalAssets = null;
        var selectedAssetPaks = AssetPaks.Selected(settings);
        var onlineEnvironment = OnlineOptions.LaunchEnvironment(settings);
        if (diagnosticColdCache && diagnosticRoute == null)
            throw new InvalidOperationException("A private shader cache requires a diagnostic run.");
        var selectedMods = randomizerSeeds.ForLaunch(Mods.Selected(settings), settings.ResolvedCoopMode);
        if (diagnosticSeed is uint fixedSeed) {
            if (diagnosticRoute == null || settings.ResolvedCoopMode != "offline")
                throw new InvalidOperationException("Fixed diagnostic seeds require an offline diagnostic run.");
            foreach (var mod in selectedMods) {
                if (mod.ItemRandomizer != null) mod.ItemRandomizer.Seed = fixedSeed;
                if (mod.WeaponShuffle != null) mod.WeaponShuffle.Seed = fixedSeed;
                if (mod.EnemyRandomizer != null) mod.EnemyRandomizer.Seed = fixedSeed;
            }
        }
        byte[]? randomizerConfiguration = null;
        HostRandomizerConfiguration = null;
        randomizerStopReason = null;
        if (onlineEnvironment.Count > 0 && settings.Game.Id == "file1") {
            var shared = await RandomizerSession.Resolve(settings, selectedMods, cancel);
            randomizerConfiguration = shared.Bytes;
            selectedMods = shared.Mods;
        }
        RandomizerSeedSummary = RandomizerSeeds.Describe(selectedMods);
        NetworkStatus = null;
        graphicsStatus = null;
        graphicsReady = new(TaskCreationOptions.RunContinuationsAsynchronously);
        string sourceExe = settings.GetExe(), iso = settings.GetGameSource();
        var selectedGame = settings.Game;
        if (!AppLayout.Packaged(root) && !File.Exists(sourceExe))
            throw new FileNotFoundException(
                "This game build is missing. Extract the complete release archive.");
        if (!File.Exists(iso))
            throw new FileNotFoundException("Choose the selected game's " + (settings.UsesGamePak() ? "PAK" : "ISO") + " in Game files.");
        Imported = await settings.PrepareGame(importProgress, cancel);
        cancel.ThrowIfCancellationRequested();
        settings.SetImport(Imported.Root);
        if (AppLayout.Packaged(root))
            sourceExe = await LocalGameBuild.Ensure(root, Imported, importProgress, cancel, game: selectedGame.Id);
        if (!settings.UsesGamePak() && settings.WantsOriginalAssetPaks(selectedGame.Id))
            OriginalAssets = await AssetExports.Ensure(Imported, selectedGame.Id, importProgress, cancel);
        string discRoot = Path.Combine(Imported.Root, "data"), discElf = Imported.Elf;
        string proxy = Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll");
        if (!File.Exists(proxy))
            throw new FileNotFoundException("The installation is missing its controller adapter. " +
                                            "Extract the complete release archive.");
        var runtimeFiles = new List<GameImageCache.Input> {
            new(sourceExe, "reo_launcher_game.exe"), new(proxy, "XINPUT1_4.dll"),
            // LLVM/MinGW's xinput import library binds to 1_3; MSVC binds to 1_4.
            // Both builds must read the same selected launcher device.
            new(proxy, "XINPUT1_3.dll")
        };
        string sourceFolder = Path.GetDirectoryName(Path.GetFullPath(sourceExe))!;
        string shaderSource = Path.Combine(sourceFolder, "reo-gpu-present");
        foreach (string shader in new[] { "present_opaque.vert.spv", "present_native.frag.spv",
            "present_smaa_edge.frag.spv", "present_smaa_weights.frag.spv", "present_smaa_blend.frag.spv" }) {
            string input = Path.Combine(shaderSource, shader);
            if (File.Exists(input)) runtimeFiles.Add(new(input, "reo-gpu-present/" + shader));
            else if (!shader.StartsWith("present_smaa_") || graphics.Environment["REO_POST_AA"] == "smaa")
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
        if (settings.UsesGamePak() && !HasMarker(image, "[GAME-PAK-1]"))
            throw new IOException("Playing from PAK needs an updated game build. Rebuild or update the selected game.");
        if (randomizerConfiguration != null && !HasMarker(image, RandomizerSession.Capability))
            throw new IOException("This shared session needs the updated game build with stable randomizer support.");
        Logs = Path.Combine(Settings.Home, "sessions", DateTime.Now.ToString("yyyyMMdd-HHmmss-fff"));
        Directory.CreateDirectory(Logs);
        if (selectedAssetPaks.Count > 0 && !HasMarker(image, AssetPaks.Capability))
            throw new IOException("Asset packs need an updated game build. Rebuild or update the selected game.");
        string assetPlan = await Task.Run(() => AssetPaks.Prepare(selectedAssetPaks, discRoot, selectedGame.Id, Logs, cancel: cancel), cancel);
        string stringPlan = Path.Combine(Logs, ExecutableStrings.PlanName);
        if (File.Exists(stringPlan) && !HasMarker(image, ExecutableStrings.Capability))
            throw new IOException("Executable string replacements need an updated game build. Rebuild or update the selected game.");
        if (randomizerConfiguration != null) {
            File.WriteAllBytes(Path.Combine(Logs,"randomizer-session.json"),randomizerConfiguration);
            File.WriteAllText(Path.Combine(Logs,"randomizer-session.sha256"),RandomizerSession.Digest(randomizerConfiguration));
        }
        Directory.CreateDirectory(SaveFolder(root, selectedGame.Id));
        string work = workingDirectory == null ? AppLayout.Work(root, selectedGame.Id)
                                              : Path.GetFullPath(workingDirectory);
        Directory.CreateDirectory(work);
        var start = new ProcessStartInfo(
            image) { UseShellExecute = false, CreateNoWindow = true,
                     WorkingDirectory = work,
                     RedirectStandardOutput = true, RedirectStandardError = true };
        Storage.ProcessEnvironment(start, accountHome);
        foreach (string arg in new[] { "--game", selectedGame.Id, "--elf", discElf, "--data",
                                       discRoot })
            start.ArgumentList.Add(arg);
        foreach (var key in start.Environment.Keys
                     .Where(k => k.StartsWith("REO_", StringComparison.OrdinalIgnoreCase))
                     .ToArray())
            start.Environment.Remove(key);
        void Set(string key, string value) => start.Environment[key] = value;
        if (assetPlan.Length != 0) Set("REO_ASSET_OVERLAY", assetPlan);
        if (File.Exists(stringPlan)) Set("REO_EXECUTABLE_STRINGS", stringPlan);
        Set("REO_AUDIO_LEVELS", AudioLevels.From(settings).LaunchValue);
        if (AudioMapName != null) Set("REO_AUDIO_MAP", AudioMapName);
        bool automaticAccount = onlineEnvironment.Count > 0 &&
                                await Task.Run(() => SupportsAutomaticAccount(image), cancel);
        if (onlineEnvironment.Count > 0 && !automaticAccount) {
            onlineEnvironment.Remove("REO_COOP_AUTO_ACCOUNT");
            NetworkStatus =
                "This older game build uses manual network login. Automatic login needs the updated game build.";
        }
        foreach (var pair in onlineEnvironment)
            Set(pair.Key, pair.Value);
        // Developer recordings come first so diagnostic routes below keep their own settings.
        foreach (var pair in settings.Developer.Environment(Logs!, onlineEnvironment.Count > 0, selectedGame.Id))
            Set(pair.Key, pair.Value);
        if (start.Environment.ContainsKey("REO_COOP_TRACE_FILE"))
            NetworkTrace.Start(Logs!);
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
        string cheatFile = Cheats.Export(settings, Logs, selectedMods);
        Mods.SaveSession(selectedMods, Logs);
        var weaponShuffle = selectedMods.SingleOrDefault(m => m.WeaponShuffle != null)?.WeaponShuffle;
        if (weaponShuffle != null) {
            if (!SupportsWeaponShuffle(image))
                throw new IOException("This mod needs a game build with weapon shuffle support. Rebuild or update the game.");
            Set("REO_MOD_WEAPON_SHUFFLE_SEED", weaponShuffle.Seed.ToString(System.Globalization.CultureInfo.InvariantCulture));
        }
        if (cheatFile.Length != 0)
        {
            if (File.ReadLines(cheatFile).Contains("builtin unlock") &&
                !HasMarker(image, "[CHEATS-UNLOCK-1] progression"))
                throw new IOException("Unlock everything needs the updated game build. Rebuild or update the game.");
            Set("REO_CHEATS_FILE", cheatFile);
        }
        var itemRandomizer = selectedMods.SingleOrDefault(m => m.ItemRandomizer != null)?.ItemRandomizer;
        if (itemRandomizer != null) {
            if (itemRandomizer.Mode == "global") {
                if (!HasMarker(image, "[MOD-GLOBAL-ITEMS-1] installed"))
                    throw new IOException("This Randomizer needs the updated game build with global item support.");
                if (!HasMarker(image, "[MOD-GLOBAL-MODELS-1] installed"))
                    throw new IOException("This Randomizer needs the updated game build with global item models.");
                string catalogue = GlobalItemCatalogue.Prepare(discRoot, Logs!);
                Set("REO_MOD_GLOBAL_ITEM_CATALOGUE", catalogue);
            }
            if (!HasMarker(image, "[MOD-ITEM-RANDOMIZER-1] installed seed=%u"))
                throw new IOException("This mod needs a game build with item randomizer support. Rebuild or update the game.");
            Set("REO_MOD_ITEM_RANDOMIZER_SEED", itemRandomizer.Seed.ToString(System.Globalization.CultureInfo.InvariantCulture));
            if (itemRandomizer.ExcludeItemTypes.Count != 0) {
                if (!HasMarker(image, "[MOD-ITEM-EXCLUSIONS-1] installed"))
                    throw new IOException("This mod needs a game build with item randomizer exclusions. Rebuild or update the game.");
                Set("REO_MOD_ITEM_EXCLUDE_TYPES", string.Join(",", itemRandomizer.ExcludeItemTypes.Select(
                    t => t.ToString(System.Globalization.CultureInfo.InvariantCulture))));
            }
        }
        if (settings.UsesGamePak()) Set("REO_GAME_PAK", "1");
        else Set("REO_ISO", Path.GetFullPath(iso));
        var enemyRandomizer = selectedMods.SingleOrDefault(m => m.EnemyRandomizer != null)?.EnemyRandomizer;
        if (enemyRandomizer != null) {
            bool species = enemyRandomizer.Mode == "enemyTypes";
            if (!(species ? SupportsEnemySpawnRandomizer(image) : SupportsZombieRandomizer(image)))
                throw new IOException("This mod needs a game build supporting its enemy randomizer mode. Rebuild or update the game.");
            Set(species ? "REO_MOD_ENEMY_SPAWN_SEED" : "REO_MOD_ZOMBIE_RANDOMIZER_SEED",
                enemyRandomizer.Seed.ToString(System.Globalization.CultureInfo.InvariantCulture));
            if(species) {
                if (enemyRandomizer.Pool.Count > 32 && !HasMarker(image, "[MOD-ENEMY-ROSTER-1] installed"))
                    throw new IOException("This Randomizer needs the updated game build with the expanded enemy roster.");
                Set("REO_MOD_ENEMY_POOL", string.Join(";",enemyRandomizer.Pool.Select(p =>
                    string.Join(":",p.Type,p.Model,p.Health,p.Behavior,p.Posture,p.Weight))));
                Set("REO_MOD_ENEMY_SOURCE_BEHAVIORS",string.Join(",",enemyRandomizer.SourceBehaviors));
            }
        }
        Set("REO_NATURAL", "1");
        Set("REO_TURBO", "1"); // existing normal-speed scheduling mode, no time warp
        Set("REO_GS_BACKEND", "parallel");
        Set("REO_GS_THREAD", "1");
        Set("REO_GS_GPU_PRESENT", "1");
        Set("REO_GS_DISPATCH_PACE", "2");
        Set("REO_GS_SPRITE_DEPTH_PARALLEL", "1");
        Set("REO_VIF1_GPU_RESIDENT", "0");
        foreach (var pair in graphics.Environment)
            Set(pair.Key, pair.Value);
        if (diagnosticRoute != null) {
            Set("REO_FRAME_PACING_FILE", Path.Combine(Logs, "frames.csv"));
            Set("REO_VIF_KICK_TIMING_AT", "0");
            Set("REO_VIF_KICK_TIMING_MIN_US", "5000");
            Set("REO_VIF_KICK_TIMING_LIMIT", "256");
            Set("REO_GS_WAIT_LOG", "1");
            Set("REO_IRQ_TIMING_LOG", "1");
            if (diagnosticColdCache) Set("REO_PIPELINE_CACHE_FILE", Path.Combine(Logs, "pipeline.cache"));
            Set("REO_PERFORMANCE_DIAG", graphics.Environment["REO_PERFORMANCE_OVERLAY"]);
            Set("REO_AUDIO_DIAG", "1");
            Set("REO_RUMBLE_DIAG", "1");
            Set("REO_TEST_ROUTE", diagnosticRoute is "gameplay-pickup" or "gameplay-preview" or "gameplay-enemies" or "gameplay-enemy-combat" ? "gameplay" : diagnosticRoute);
            if (settings.CheatsEnabled || selectedMods.Count > 0)
                Set("REO_CHEAT_DIAG", "1");
        }
        if (diagnosticRoute is "gameplay" or "gameplay-pickup") {
            Set(diagnosticRoute == "gameplay-pickup" ? "REO_TEST_INTERACT_QUIT" : "REO_TEST_ROOM_SOAK", "1");
            if (diagnosticRoute == "gameplay-pickup") Set("REO_TEST_WEAPON_PICKUP", "1");
        }
        if (diagnosticRoute is "gameplay" or "gameplay-pickup" or "gameplay-enemies" or "gameplay-enemy-combat") {
            Set("REO_GAME_CLOCK_LOG", "1");
            Set("REO_GAME_CLOCK_FROM_SECS", "0");
            Set("REO_GAME_CLOCK_SECONDS", "300");
            Set("REO_GAME_CLOCK_FILE", Path.Combine(Logs, "clock.csv"));
        }
        if (diagnosticRoute == "gameplay-preview") {
            Set("REO_SHOT_AT", "55,70");
            Set("REO_SHOT_RAM", "1");
        }
        if (diagnosticRoute is "gameplay-enemies" or "gameplay-enemy-combat" or "gameplay-roster-probe") Set("REO_TEST_ENEMIES", "1");
        if (diagnosticRoute == "gameplay-roster-probe") {
            Set("REO_TEST_ROUTE", "gameplay");
            Set("REO_TEST_ENEMY_PROBE", "1");
        }
        if (diagnosticRoute == "gameplay-enemy-combat") Set("REO_TEST_WORLD_TARGET", "8180,13340,30");
        // GPU movies when the rendering GPU has a hardware MPEG-2 decoder and the player left them
        // on in Graphics; otherwise the original CPU decoder.
        MovieDecoderChoice movies = await MovieDecoder.Choose(cancel);
        bool gpuMovies = movies.Gpu && graphics.GpuMovies;
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
        if (settings.ResolvedCoopMode == "host") HostRandomizerConfiguration = randomizerConfiguration;
        try {
            account = automaticAccount
                          ? new AutomaticAccount(accountHome ?? Settings.Home, settings, text => NetworkStatus = text,
                                                 MainWindow.SignupEndpoint(settings, null))
                          : null;
            account?.Bind(start);
            if (randomizerConfiguration != null && settings.ResolvedCoopMode == "join") {
                var current=await RandomizerSession.Fetch(settings.CoopHost,cancel);
                if (!current.AsSpan().SequenceEqual(randomizerConfiguration))
                    throw new IOException("The host started a different session while your game was preparing. Press Play again to use its settings.");
            }
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
        if (randomizerConfiguration != null && settings.ResolvedCoopMode == "join")
            _ = WatchRandomizerSession(Process,Logs,settings.CoopHost,randomizerConfiguration);
        controller.GameProcessId = Process.Id;
        var lightProcess = Process;
        string lightLogs = Logs!;
        // Health addresses currently describe File #1 only; keep the neutral
        // light for File #2 rather than interpret unrelated guest memory.
        controller.SetHealthLight(PadLight.Blue);
        if (selectedGame.Id == "file1")
            _ = Task.Run(() => ControllerHealth.Run(lightProcess, discElf, controller, lightLogs));
        _ = Task.Run(() => ControllerRumble.Trace(lightProcess, controller, lightLogs));
        _ = Pump(Process.StandardOutput, stdout);
        _ = Pump(Process.StandardError, stderr, line => {
            ObserveGraphicsLine(line);
            account?.Observe(line);
        });
        await File.WriteAllTextAsync(
            Path.Combine(Logs, "launch.json"),
            JsonSerializer.Serialize(
                new { pid = Process.Id,
                      game = selectedGame.Id,
                      randomizerSeed = RandomizerSeedSummary,
                      source = sourceExe,
                      image,
                      sha256 = hash,
                      iso = settings.UsesGamePak() ? null : iso,
                      gameSource = iso,
                      gameSourceType = settings.UsesGamePak() ? "pak" : "iso",
                      discRoot,
                      networkConfigured = OnlineOptions.Configured(settings),
                      server = onlineEnvironment.GetValueOrDefault("REO_COOP_HOST"),
                      accountUsername = onlineEnvironment.GetValueOrDefault("REO_COOP_USERNAME"),
                      networkProfileMarker,
                      automaticLobby = keyboardQueue != null,
                      inputDevice = controller.SelectedDevice.Name,
                      fullscreen = graphics.Fullscreen,
                      graphicsEnvironment = graphics.Environment,
                      resolution = graphics.Output,
                      linearScaling = graphics.Environment["REO_DISPLAY_FILTER"] == "linear",
                      textureLinear = graphics.Environment["REO_TEXTURE_FILTER"] == "linear",
                      internalResolution = int.Parse(graphics.Environment["REO_INTERNAL_RESOLUTION"], System.Globalization.CultureInfo.InvariantCulture),
                      performanceOverlay = graphics.Environment["REO_PERFORMANCE_OVERLAY"] == "1",
                      developer = settings.Developer,
                      anisotropy = int.Parse(graphics.Environment["REO_TEXTURE_ANISOTROPY"], System.Globalization.CultureInfo.InvariantCulture),
                      aspectRatio = graphics.Environment["REO_DISPLAY_ASPECT"],
                      widescreenCamera = graphics.Environment["REO_WIDESCREEN"] == "1",
                      screenFit = graphics.Environment["REO_DISPLAY_FIT"],
                      antiAliasing = graphics.Environment["REO_POST_AA"],
                      brightness = (int)Math.Round(100 * double.Parse(graphics.Environment["REO_BRIGHTNESS"], System.Globalization.CultureInfo.InvariantCulture)),
                      gamma = double.Parse(graphics.Environment["REO_GAMMA"], System.Globalization.CultureInfo.InvariantCulture),
                      memoryCard = cardFolder,
                      importedData = discRoot,
                      importReused = Imported.Reused,
                      mountedIso = false,
                      directIso = true,
                      movieDecoder = gpuMovies ? "gpu" : "cpu",
                      gpuMoviesAvailable = movies.Gpu,
                      gpuMoviesSetting = graphics.GpuMovies,
                      movieDecoderGpu = movies.GpuName,
                      movieDecoderReason = movies.Reason },
                new JsonSerializerOptions { WriteIndented = true }));
        _ = ApplyWindow(Process, graphics);
    }
    async Task WatchRandomizerSession(Process process,string logs,string host,byte[] expected) {
        using var stopped=new CancellationTokenSource();
        _ = process.WaitForExitAsync().ContinueWith(_ => { try { stopped.Cancel(); } catch(ObjectDisposedException) { } },TaskScheduler.Default);
        while(!stopped.IsCancellationRequested) {
            try {
                await Task.Delay(2000,stopped.Token);
                var current=await RandomizerSession.Fetch(host,stopped.Token);
                if(current.AsSpan().SequenceEqual(expected)) continue;
                const string message="The host changed sessions. Relaunch to synchronize its randomizer settings.";
                randomizerStopReason=message;
                NetworkStatus=message;
                await File.WriteAllTextAsync(Path.Combine(logs,"randomizer-session-error.txt"),message);
                if(!process.HasExited) process.CloseMainWindow();
                return;
            } catch(OperationCanceledException) { return; }
              catch(IOException) { /* Native networking handles a disconnected host. */ }
              catch(System.Net.Sockets.SocketException) { }
        }
    }
    async Task RecordExit(Process process, string logs, FileStream cardLease,
                          AutomaticAccount? account, LobbyAutomation? automation) {
        try {
            await process.WaitForExitAsync();
        } finally {
            automation?.Dispose();
            account?.Dispose();
            NetworkStatus = randomizerStopReason;
            graphicsStatus = null;
            graphicsReady.TrySetCanceled();
            cardLease.Dispose();
        }
        await Task.Run(() => NetworkTrace.Finish(logs));
        await File.WriteAllTextAsync(Path.Combine(logs, "exit.json"), JsonSerializer.Serialize(new {
            pid = process.Id, exitCode = process.ExitCode, utc = DateTime.UtcNow
        }));
    }
    // Drain pipes independently of the UI: native window messages can wait on the game.
    internal static bool SupportsAutomaticAccount(string image) => HasMarker(image, "[COOP-AUTO] native-password-applied %u");
    internal static bool SupportsWeaponShuffle(string image) => HasMarker(image, "[MOD-WEAPON-SHUFFLE-1] installed seed=%u");
    internal static bool SupportsZombieRandomizer(string image) => HasMarker(image, "[MOD-ZOMBIE-RANDOMIZER-1] installed seed=%u");
    internal static bool SupportsEnemySpawnRandomizer(string image) =>
        HasMarker(image, "[MOD-ENEMY-SPAWN-1] installed seed=%u") &&
        HasMarker(image, RandomizerSession.Capability) && HasMarker(image, "[MOD-ENEMY-ASSETS-1]");
    static bool HasMarker(string image, string value) {
        byte[] marker = System.Text.Encoding.ASCII.GetBytes(value);
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
    internal void ObserveGraphicsLine(string line) {
        const string marker = "[SHADER-WARMUP] ";
        int start = line.IndexOf(marker, StringComparison.Ordinal);
        if (start < 0) return;
        string text = line[(start + marker.Length)..];
        if (text == "ready") {
            graphicsStatus = null;
            graphicsReady.TrySetResult();
            return;
        }
        if (!text.StartsWith("progress ", StringComparison.Ordinal)) return;
        var counts = text[9..].Split('/');
        if (counts.Length == 2 && int.TryParse(counts[0], out int done) &&
            int.TryParse(counts[1], out int total) && total > 0 && done >= 0 && done <= total)
            graphicsStatus = $"Preparing graphics · {(long)done * 100 / total}%";
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
    static async Task ApplyWindow(Process process, GraphicsOptions graphics) {
        for (int i = 0; i < 1200 && !process.HasExited; ++i) {
            await Task.Delay(100).ConfigureAwait(false);
            process.Refresh();
            nint hwnd = process.MainWindowHandle;
            if (hwnd == 0)
                continue;
            _ = GameWindowIcon.Apply(process, hwnd);
            if (graphics.Fullscreen) {
                long style = GetWindowLongPtr(hwnd, -16).ToInt64() & ~0x00CF0000L;
                SetWindowLongPtr(hwnd, -16, new nint(style));
                var info = new MonitorInfo { Size = Marshal.SizeOf<MonitorInfo>() };
                if (GetMonitorInfo(MonitorFromWindow(hwnd, 2), ref info))
                    SetWindowPos(hwnd, 0, info.Monitor.Left, info.Monitor.Top,
                                 info.Monitor.Right - info.Monitor.Left,
                                 info.Monitor.Bottom - info.Monitor.Top, 0x4024);
            } else {
                var size = graphics.Output;
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
                     focused = GetForegroundWindow() == window,
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
    static extern nint GetForegroundWindow();
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
