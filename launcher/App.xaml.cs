using System.IO;
using System.Windows;

namespace Outbreak.Launcher;
public partial class App : Application {
    Mutex? singleInstance;
    protected override async void OnStartup(StartupEventArgs e) {
        base.OnStartup(e);
        try {
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
            bool diagnostic = e.Args.Any(arg => arg is "--screenshot" or "--probe-controller" or
                                                       "--smoke-launch");
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
            var window = new MainWindow(e.Args);
            MainWindow = window;
            window.Show();
        } catch (Exception error) {
            Directory.CreateDirectory(Settings.Home);
            string log = Path.Combine(Settings.Home, "launcher-error.log");
            File.WriteAllText(log, error.ToString());
            if (!e.Args.Contains("--test-coop-host") && !e.Args.Contains("--self-test") &&
                !e.Args.Contains("--import-iso") && !e.Args.Contains("--test-update") &&
                !e.Args.Contains("--check-updates") && !e.Args.Contains("--screenshot") &&
                !e.Args.Contains("--test-disc-import") && !e.Args.Contains("--check-iso"))
                MessageBox.Show(error.GetBaseException().Message + "\n\nDetails: " + log,
                                "RE: Outbreak");
            Shutdown(1);
        }
    }
    protected override void OnExit(ExitEventArgs e) {
        singleInstance?.Dispose();
        base.OnExit(e);
    }
}
