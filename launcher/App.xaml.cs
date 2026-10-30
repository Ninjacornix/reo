using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class App : Application {
    static App() {
        // Disable hover popups consistently, including controls created in code
        // and controls inside dropdowns. Accessible names/help remain available.
        ToolTipService.IsEnabledProperty.OverrideMetadata(typeof(FrameworkElement), new FrameworkPropertyMetadata(false));
        ToolTipService.IsEnabledProperty.OverrideMetadata(typeof(FrameworkContentElement), new FrameworkPropertyMetadata(false));
        EventManager.RegisterClassHandler(typeof(FrameworkElement), ToolTipService.ToolTipOpeningEvent,
            new ToolTipEventHandler((_, e) => e.Handled = true));
        EventManager.RegisterClassHandler(typeof(FrameworkContentElement), ToolTipService.ToolTipOpeningEvent,
            new ToolTipEventHandler((_, e) => e.Handled = true));
    }
    Mutex? singleInstance;
    protected override async void OnStartup(StartupEventArgs e) {
        base.OnStartup(e);
        try {
            int wait = Array.IndexOf(e.Args, "--wait-for-launcher-exit");
            if (wait >= 0 && wait + 2 < e.Args.Length && int.TryParse(e.Args[wait + 1], out int pid) &&
                long.TryParse(e.Args[wait + 2], out long ticks)) {
                try {
                    using var parent = System.Diagnostics.Process.GetProcessById(pid);
                    if (parent.StartTime.ToUniversalTime().Ticks == ticks)
                        await parent.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(15));
                } catch (ArgumentException) { }
            }
            string storageRoot = AppLayout.FindRoot(AppContext.BaseDirectory);
            int storage = Array.IndexOf(e.Args, "--data-home");
            if (storage >= 0 && (storage + 1 >= e.Args.Length || e.Args[storage + 1].StartsWith("--")))
                throw new ArgumentException("--data-home requires a folder.");
            Storage.Configure(storageRoot, storage >= 0 ? e.Args[storage + 1] : null);
            int existingCompilerTest = Array.IndexOf(e.Args, "--test-existing-compiler");
            if (existingCompilerTest >= 0 && existingCompilerTest + 2 < e.Args.Length) {
                await Task.Run(
                    () => PortableCompilerSetupTests.CheckExisting(
                        e.Args[existingCompilerTest + 1], e.Args[existingCompilerTest + 2]));
                Shutdown();
                return;
            }
            int compilerTest = Array.IndexOf(e.Args, "--test-compiler-setup");
            if (compilerTest >= 0 && compilerTest + 2 < e.Args.Length) {
                await Task.Run(() => PortableCompilerSetupTests.Run(e.Args[compilerTest + 1],
                                                                    e.Args[compilerTest + 2]));
                Shutdown();
                return;
            }
            int inspect = Array.IndexOf(e.Args, "--check-iso");
            if (inspect >= 0 && inspect + 2 < e.Args.Length) {
                try {
                    using var image = new DiscImage(e.Args[inspect + 1]);
                    var verified = DiscValidation.Check(image, GameDefinition.First,
                                                        DiscImport.FirstElfSha256, default);
                    File.WriteAllText(e.Args[inspect + 2],
                                      System.Text.Json.JsonSerializer.Serialize(
                                          new { supported = true, verified.Description,
                                                elfSha256 = verified.Sha256 }));
                    Shutdown();
                } catch (InvalidDataException error) {
                    File.WriteAllText(e.Args[inspect + 2],
                                      System.Text.Json.JsonSerializer.Serialize(
                                          new { supported = false, error = error.Message }));
                    Shutdown(2);
                }
                return;
            }
            int discTest = Array.IndexOf(e.Args, "--test-disc-import");
            if (discTest >= 0 && discTest + 1 < e.Args.Length) {
                int checks = 0;
                DiscImportTests.Run((valid, message) => {
                    if (!valid)
                        throw new IOException(message);
                    checks++;
                });
                File.WriteAllText(e.Args[discTest + 1], System.Text.Json.JsonSerializer.Serialize(
                                                            new { passed = true, checks }));
                Shutdown();
                return;
            }
            int hostTest = Array.IndexOf(e.Args, "--test-coop-host");
            if (hostTest >= 0 && hostTest + 2 < e.Args.Length) {
                await HostedServerTests.Run(AppLayout.FindRoot(AppContext.BaseDirectory),
                                            e.Args[hostTest + 1], e.Args[hostTest + 2]);
                Shutdown();
                return;
            }
            int lobbyTest = Array.IndexOf(e.Args, "--test-lobby");
            if (lobbyTest >= 0 && lobbyTest + 3 < e.Args.Length) {
                await LobbyAutomationLiveTest.Run(e.Args[lobbyTest + 1], e.Args[lobbyTest + 2],
                                                  e.Args[lobbyTest + 3]);
                Shutdown();
                return;
            }
            int fixture = Array.IndexOf(e.Args, "--test-update");
            if (fixture >= 0 && fixture + 1 < e.Args.Length) {
                string target =
                    Updates.CanonicalDirectory(AppLayout.FindRoot(AppContext.BaseDirectory));
                var parentFolder = Directory.GetParent(target);
                if (parentFolder?.Parent == null || Path.GetFileName(target) != "installed" ||
                    !Updates.CanonicalDirectory(parentFolder.Parent.FullName)
                         .Equals(Updates.CanonicalDirectory(Path.GetTempPath()),
                                 StringComparison.OrdinalIgnoreCase) ||
                    !parentFolder.Name.StartsWith("reo-update-smoke-", StringComparison.Ordinal))
                    throw new IOException(
                        "Updater smoke tests can only replace an isolated temporary installation.");
                string stage = Path.GetFullPath(e.Args[fixture + 1]),
                       work = Directory.GetParent(stage)!.FullName;
                using var parent = System.Diagnostics.Process.GetCurrentProcess();
                var plan = new UpdatePlan(work, stage, target,
                                          "v" + Updates.InstalledVersion(stage).ToString(3),
                                          parent.Id, parent.StartTime.ToUniversalTime().Ticks);
                await Updates.StartWorker(plan, default);
                File.WriteAllText(Path.Combine(work, "commit.json"), "{}");
                Shutdown();
                return;
            }
            int checkUpdate = Array.IndexOf(e.Args, "--check-updates");
            if (checkUpdate >= 0 && checkUpdate + 1 < e.Args.Length) {
                using var client = Updates.Client();
                var installed =
                    Updates.InstalledVersion(AppLayout.FindRoot(AppContext.BaseDirectory));
                var release = await Updates.Check(client, installed, default);
                File.WriteAllText(e.Args[checkUpdate + 1],
                                  System.Text.Json.JsonSerializer.Serialize(
                                      new { installed = installed.ToString(3),
                                            available = release?.Tag, api = Updates.LatestApi },
                                      Updates.Json));
                Shutdown();
                return;
            }
            int update = Array.IndexOf(e.Args, "--apply-update");
            if (update >= 0 && update + 1 < e.Args.Length) {
                Shutdown(await UpdateWorker.Run(e.Args[update + 1]));
                return;
            }
            int preparePaks = Array.IndexOf(e.Args, "--prepare-asset-paks");
            int importPak = Array.IndexOf(e.Args, "--import-asset-pak");
            if (importPak >= 0) {
                if (importPak + 3 >= e.Args.Length) throw new ArgumentException("--import-asset-pak <source.pak> <mod-folder> <new-result.json>");
                string result = e.Args[importPak + 3]; if (File.Exists(result)) throw new IOException("Choose a new import result file.");
                await Task.Run(() => AssetPaks.Import(e.Args[importPak + 1], e.Args[importPak + 2]));
                File.WriteAllText(result, System.Text.Json.JsonSerializer.Serialize(AssetPaks.Load(e.Args[importPak + 2]).Select(p => new { Id = p.Manifest?.Id, Game = p.Manifest?.Game, p.Error })));
                Shutdown(); return;
            }
            int testExports = Array.IndexOf(e.Args, "--test-asset-exports");
            if (testExports >= 0 && testExports + 1 < e.Args.Length) {
                int checks = 0;
                AssetExportTests.Run((valid, name) => { if (!valid) throw new IOException(name); checks++; });
                File.WriteAllText(e.Args[testExports + 1], System.Text.Json.JsonSerializer.Serialize(new { passed = true, checks }));
                Shutdown(); return;
            }
            int exportAssets = Array.IndexOf(e.Args, "--export-original-assets");
            int importGamePak = Array.IndexOf(e.Args, "--import-game-pak");
            if (importGamePak >= 0) {
                if (importGamePak + 4 >= e.Args.Length) throw new ArgumentException("--import-game-pak <game> <pak> <data-home> <new-result.json>");
                string resultPath = e.Args[importGamePak + 4];
                if (File.Exists(resultPath)) throw new IOException("Choose a new game PAK result file.");
                var result = await GamePaks.Ensure(e.Args[importGamePak + 2], e.Args[importGamePak + 1], home: e.Args[importGamePak + 3]);
                File.WriteAllText(resultPath, System.Text.Json.JsonSerializer.Serialize(result));
                Shutdown(); return;
            }
            if (exportAssets >= 0) {
                if (exportAssets + 4 >= e.Args.Length) throw new ArgumentException("--export-original-assets <game> <import-root> <output-home> <result.json>");
                string selectedGame = e.Args[exportAssets + 1], imported = Path.GetFullPath(e.Args[exportAssets + 2]);
                string resultPath = Path.GetFullPath(e.Args[exportAssets + 4]);
                if (File.Exists(resultPath)) throw new IOException("Choose a new export result file.");
                var disc = new ImportedDisc(imported, Path.Combine(imported, "data", GameDefinition.Find(selectedGame).ElfName), 0, 0, true);
                var result = await AssetExports.Ensure(disc, selectedGame, home: e.Args[exportAssets + 3]);
                Directory.CreateDirectory(Path.GetDirectoryName(resultPath)!);
                File.WriteAllText(resultPath, System.Text.Json.JsonSerializer.Serialize(result));
                Shutdown(); return;
            }
            int testPaks = Array.IndexOf(e.Args, "--test-asset-paks");
            if (testPaks >= 0 && testPaks + 1 < e.Args.Length) {
                int checks = 0;
                AssetPakTests.Run((valid, name) => { if (!valid) throw new IOException(name); checks++; });
                File.WriteAllText(e.Args[testPaks + 1], System.Text.Json.JsonSerializer.Serialize(new { passed = true, checks }));
                Shutdown(); return;
            }
            if (preparePaks >= 0) {
                if (preparePaks + 4 >= e.Args.Length) throw new ArgumentException("--prepare-asset-paks <game> <import-data> <pack-folder> <new-session-folder>");
                string selectedGame = e.Args[preparePaks + 1], data = e.Args[preparePaks + 2], folder = e.Args[preparePaks + 3], session = e.Args[preparePaks + 4];
                var installed = AssetPaks.Load(folder);
                if (installed.Any(p => p.Error.Length != 0)) throw new IOException(string.Join("; ", installed.Where(p => p.Error.Length != 0).Select(p => p.Error)));
                var packs = installed.Where(p => p.Manifest?.Game == selectedGame).ToList();
                if (packs.Count == 0) throw new IOException("No asset packs for the selected game.");
                if (Directory.Exists(session)) throw new IOException("Choose a new session folder.");
                int cacheArg = Array.IndexOf(e.Args, "--asset-cache");
                if (cacheArg >= 0 && cacheArg + 1 >= e.Args.Length) throw new ArgumentException("--asset-cache requires a directory.");
                string assetCache = cacheArg >= 0 ? Path.GetFullPath(e.Args[cacheArg + 1]) : Path.Combine(Path.GetFullPath(session), "cache");
                await Task.Run(() => AssetPaks.Prepare(packs, data, selectedGame, session, assetCache));
                Shutdown(); return;
            }
            int import = Array.IndexOf(e.Args, "--import-iso");
            if (import >= 0) {
                string Option(string name) {
                    int at = Array.IndexOf(e.Args, name);
                    return at >= 0 && at + 1 < e.Args.Length
                               ? e.Args[at + 1]
                               : throw new ArgumentException("Missing " + name);
                }
                var result = await DiscImport.Ensure(
                    Option("--import-iso"), GameDefinition.First, DiscImport.FirstElfSha256,
                    home: e.Args.Contains("--import-home") ? Option("--import-home") : null);
                File.WriteAllText(
                    Option("--import-result"),
                    System.Text.Json.JsonSerializer.Serialize(
                        result,
                        new System.Text.Json.JsonSerializerOptions { WriteIndented = true }));
                Shutdown();
                return;
            }
            if (e.Args.Contains("--self-test")) {
                SelfTest.Run();
                Shutdown();
                return;
            }
            int videoTest = Array.IndexOf(e.Args, "--test-background-videos");
            if (videoTest >= 0 && videoTest + 4 < e.Args.Length) {
                await Task.Run(() => BackgroundVideoTests.VerifyOwnedDiscs(e.Args[videoTest + 1], e.Args[videoTest + 2],
                    e.Args[videoTest + 3], e.Args[videoTest + 4]));
                Shutdown();
                return;
            }
            if (e.Args.Contains("--test-coop-session")) {
                int smoke = Array.IndexOf(e.Args, "--smoke-launch");
                if (smoke < 0 || smoke + 2 >= e.Args.Length)
                    throw new ArgumentException("--test-coop-session requires --smoke-launch <exe> <result.json>.");
                _ = CoopSmokeOptions.Parse(e.Args);
            }
            bool diagnostic = e.Args.Any(arg => arg is "--screenshot" or "--probe-controller" or
                                                       "--smoke-launch" or "--test-background-playback");
            diagnostic |= e.Args.Contains("--data-home") && e.Args.Any(arg => arg is
                "--test-graphics-ui" or "--test-disc-selectors" or "--test-audio-ui" or
                "--test-launcher-ui" or "--test-developer-ui" or "--test-game-files-ui" or "--test-coop-ui" or "--test-memory-cards-ui" or "--test-controls-ui" or "--test-mods-ui" or "--test-cheats-ui" or "--test-play-layout");
            if (!diagnostic) {
                singleInstance = new Mutex(true, "Local\\Outbreak-Launcher", out bool created);
                if (!created) {
                    MessageBox.Show("The Outbreak launcher is already open.", "RE: Outbreak");
                    Shutdown();
                    return;
                }
            }
            string installation = AppLayout.FindRoot(AppContext.BaseDirectory);
            if (AppLayout.Packaged(installation) && Updates.InstallationBusy(installation)) {
                MessageBox.Show(
                    "An update is being installed. The launcher will restart when it is ready.",
                    "RE: Outbreak");
                Shutdown();
                return;
            }
            ShutdownMode = ShutdownMode.OnExplicitShutdown;
            bool importOldData = !e.Args.Any(arg => arg.StartsWith("--test-") ||
                arg is "--smoke-launch" or "--screenshot" or "--probe-controller");
            await Storage.Initialize(installation, importOldData, null, default, !diagnostic);
            var window = new MainWindow(e.Args);
            MainWindow = window;
            window.Show();
            ShutdownMode = ShutdownMode.OnMainWindowClose;
        } catch (Exception error) {
            string log = "";
            try {
                // A failed first migration must not create files in its empty
                // destination, otherwise retrying would look like a conflict.
                string logFolder = Storage.Initialized ? Settings.Home : AppContext.BaseDirectory;
                Directory.CreateDirectory(logFolder);
                log = Path.Combine(logFolder, "launcher-error.log");
                File.WriteAllText(log, error.ToString());
            } catch { log = ""; }
            if (!e.Args.Contains("--smoke-launch") && !e.Args.Contains("--test-coop-session") &&
                !e.Args.Contains("--test-coop-host") && !e.Args.Contains("--self-test") &&
                !e.Args.Contains("--test-lobby") &&
                !e.Args.Contains("--import-iso") && !e.Args.Contains("--prepare-asset-paks") && !e.Args.Contains("--test-asset-paks") &&
                !e.Args.Contains("--test-asset-exports") && !e.Args.Contains("--export-original-assets") && !e.Args.Contains("--import-game-pak") && !e.Args.Contains("--import-asset-pak") && !e.Args.Contains("--test-update") &&
                !e.Args.Contains("--check-updates") && !e.Args.Contains("--screenshot") &&
                !e.Args.Contains("--test-disc-import") && !e.Args.Contains("--check-iso") &&
                !e.Args.Contains("--test-compiler-setup") &&
                !e.Args.Contains("--test-existing-compiler") && !e.Args.Contains("--test-background-videos") &&
                !e.Args.Contains("--test-background-playback") && !e.Args.Contains("--test-cheats-ui") &&
                !e.Args.Contains("--test-mods-ui") && !e.Args.Contains("--test-launcher-ui") && !e.Args.Contains("--test-developer-ui") && !e.Args.Contains("--test-game-files-ui") && !e.Args.Contains("--test-coop-ui") && !e.Args.Contains("--test-memory-cards-ui") && !e.Args.Contains("--test-controls-ui") &&
                !e.Args.Contains("--test-graphics-ui") && !e.Args.Contains("--test-disc-selectors") && !e.Args.Contains("--test-play-layout"))
                MessageBox.Show(error.GetBaseException().Message +
                                (log.Length > 0 ? "\n\nDetails: " + log : "\n\nKeep the launcher in a folder you can write to, such as your Games folder."),
                                "RE: Outbreak");
            Shutdown(1);
        }
    }
    protected override void OnExit(ExitEventArgs e) {
        Storage.Close();
        singleInstance?.Dispose();
        base.OnExit(e);
    }
}
