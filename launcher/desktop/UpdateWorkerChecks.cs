using System.Diagnostics;
using System.Text.Json;

namespace Outbreak.Launcher.Desktop;

// Synthetic packages and a UI-free restart probe. No real installation, account,
// native game, graphics device or launcher window is used by this check.
internal static class UpdateWorkerChecks {
    static void Require(bool condition, string message) {
        if (!condition) throw new IOException(message);
    }
    static void Inventory(string root) {
        var files = Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories)
            .Where(p => Path.GetFileName(p) != "package-manifest.json")
            .Select(p => new PackageFile(Path.GetRelativePath(root, p).Replace('\\', '/'),
                                        new FileInfo(p).Length, Updates.Sha(p)));
        File.WriteAllText(Path.Combine(root, "package-manifest.json"), JsonSerializer.Serialize(files));
    }
    static void Fixture(string root, string version, string probe, bool launcher, string? tag = null) {
        Directory.CreateDirectory(root);
        foreach (string name in new[] { "Outbreak.Launcher.dll", "Outbreak.Launcher.deps.json",
                     "Outbreak.Launcher.runtimeconfig.json", "build-kit/build-kit.json" }) {
            string path = Updates.SafePath(root, name);
            Directory.CreateDirectory(Path.GetDirectoryName(path)!);
            File.WriteAllText(path, version + ":" + name);
        }
        string binaryFolder = launcher ? AppContext.BaseDirectory : Path.GetDirectoryName(probe)!;
        foreach (string file in Directory.EnumerateFiles(binaryFolder)) {
            string name = Path.GetFileName(file);
            if (!name.EndsWith(".dll", StringComparison.OrdinalIgnoreCase) &&
                !name.EndsWith(".deps.json") && !name.EndsWith(".runtimeconfig.json")) continue;
            File.Copy(file, Path.Combine(root, name), true);
        }
        File.Copy(launcher ? Path.Combine(AppContext.BaseDirectory, "Outbreak.Launcher.exe") : probe,
                  Path.Combine(root, "Outbreak.Launcher.exe"), true);
        bool compact = !File.Exists(Path.Combine(binaryFolder, "hostfxr.dll"));
        if (compact) {
            Require(new FileInfo(Path.Combine(root, "Outbreak.Launcher.exe")).Length > 1024 * 1024,
                    "Publish a self-contained single-file launcher and probe first.");
            foreach (string name in new[] { "build-inputs.zip", "XINPUT1_4.dll", "REQUIREMENTS.md" })
                File.WriteAllText(Path.Combine(root, name), "synthetic update fixture");
        } else Require(File.Exists(Path.Combine(root, "hostpolicy.dll")),
                       "Publish the launcher and cross-test probe as self-contained Windows packages first.");
        File.WriteAllText(Path.Combine(root, "distribution.json"), JsonSerializer.Serialize(new {
            format = 2, updateFormat = 2, installMode = "local-build", version,
            platform = "win-x64", source = Updates.Repository, releaseTag = tag,
            layout = compact ? "self-contained-single-file" : "self-contained"
        }));
        Inventory(root);
        Updates.Validate(root, Updates.ParseVersion(version));
    }
    static Process Start(string executable, params string[] args) {
        var info = new ProcessStartInfo(executable) { UseShellExecute = false, CreateNoWindow = true };
        foreach (string arg in args) info.ArgumentList.Add(arg);
        return Process.Start(info) ?? throw new IOException("Could not start owned update fixture.");
    }
    static async Task Stop(Process? process) {
        if (process == null) return;
        try {
            if (!process.HasExited) { process.Kill(true); await process.WaitForExitAsync(); }
        } finally { process.Dispose(); }
    }
    static async Task RejectCommand(string output, params string[] args) {
        string trap = Path.Combine(output, "must-not-open-ui-" + Guid.NewGuid().ToString("N"));
        using var child = Start(Path.Combine(AppContext.BaseDirectory, "Outbreak.Launcher.exe"),
                                  [.. args, "--headless-check", trap]);
        try { await child.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(20)); }
        finally { if (!child.HasExited) { child.Kill(true); await child.WaitForExitAsync(); } }
        Require(child.ExitCode == 1 && !Directory.Exists(trap),
                "Invalid update command entered the UI/headless path instead of refusing the plan.");
    }
    internal static async Task<int> Run(string[] args) {
        if (!OperatingSystem.IsWindows()) throw new PlatformNotSupportedException("Windows update-worker check.");
        int index = Array.IndexOf(args, "--update-worker-check");
        if (index < 0 || index + 2 >= args.Length)
            throw new ArgumentException("--update-worker-check <fresh-output> <cross-tests.exe>");
        string output = Path.GetFullPath(args[index + 1]), probe = Path.GetFullPath(args[index + 2]);
        if (Directory.Exists(output)) throw new IOException("Choose a fresh updater-check directory.");
        Directory.CreateDirectory(output);
        string? oldGui = Environment.GetEnvironmentVariable("DOTNET_DISABLE_GUI_ERRORS");
        Environment.SetEnvironmentVariable("DOTNET_DISABLE_GUI_ERRORS", "1");
        try {
            await RejectCommand(output, "--apply-update");
            await RejectCommand(output, "--apply-update", Path.Combine(output, "missing-plan.json"));
            string[] scenarios = ["cancel", "install", "rc-upgrade", "rc-to-stable"];
            int scenarioAt = Array.IndexOf(args, "--scenario");
            if (scenarioAt >= 0) {
                if (scenarioAt + 1 >= args.Length || !scenarios.Contains(args[scenarioAt + 1]))
                    throw new ArgumentException("Unknown updater check scenario.");
                scenarios = [args[scenarioAt + 1]];
            }
            foreach (string name in scenarios) {
                bool cancel = name == "cancel", rc = name.StartsWith("rc-");
                string before = rc ? "1.0.20" : "0.1.0", after = rc ? "1.0.20" : "0.2.0";
                string? beforeTag = rc ? "v1.0.20-rc1" : null,
                        afterTag = name == "rc-upgrade" ? "v1.0.20-rc2" : rc ? "v1.0.20" : null;
                string scenario = Path.Combine(output, name),
                       home = Path.Combine(scenario, "selected storage"), target = Path.Combine(scenario, "installation"),
                       work = Path.Combine(home, "updates", Guid.NewGuid().ToString("N")),
                       source = Path.Combine(work, "new"), close = Path.Combine(scenario, "parent-close");
                Fixture(target, before, probe, true, beforeTag);
                Fixture(source, after, probe, false, afterTag);
                Storage.Configure(target, home);
                await Storage.Initialize(target, false, null, default);
                File.WriteAllText(Path.Combine(home, "keep-save.txt"), "owned save fixture");
                Process? parent = null, worker = null;
                try {
                    parent = Start(probe, "--update-parent-check", close);
                    var plan = new UpdatePlan(work, source, target, afterTag ?? "v0.2.0", parent.Id,
                                             parent.StartTime.ToUniversalTime().Ticks);
                    using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(30));
                    await Updates.StartWorker(plan, timeout.Token);
                    using (var ready = JsonDocument.Parse(File.ReadAllText(Path.Combine(work, "ready.json"))))
                        worker = Process.GetProcessById(ready.RootElement.GetProperty("pid").GetInt32());
                    Require(!worker.HasExited && !parent.HasExited,
                            "Worker did not become ready while the parent and its storage lease remained active.");
                    File.WriteAllText(Path.Combine(work, cancel ? "cancel.json" : "commit.json"), "{}");
                    if (!cancel) { Storage.Close(); File.WriteAllText(close, "exit"); }
                    await worker.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(30));
                    Require(worker.ExitCode == (cancel ? 2 : 0), "Unexpected update worker exit code.");
                    Require(Updates.InstalledVersion(target) == Updates.ParseVersion(cancel ? before : after),
                            "Canceled or committed update published the wrong version.");
                    if (rc) Require(Updates.InstalledReleaseTag(target) == afterTag,
                                    "Updater lost the RC or stable release identity.");
                    Require(File.ReadAllText(Path.Combine(home, "keep-save.txt")) == "owned save fixture",
                            "Updating touched selected storage.");
                    if (!cancel) {
                        string restarted = Path.Combine(target, "restart-check.json");
                        var clock = Stopwatch.StartNew();
                        while (!File.Exists(restarted) && clock.Elapsed < TimeSpan.FromSeconds(15)) await Task.Delay(50);
                        using var report = JsonDocument.Parse(File.ReadAllText(restarted));
                        var actual = report.RootElement.GetProperty("arguments").EnumerateArray().Select(v => v.GetString()).ToArray();
                        Require(actual[0] == "--update-complete" && actual[2] == "--data-home" && actual[3] == home,
                                "Restart lost the selected storage or success receipt.");
                    } else Require(!File.Exists(Path.Combine(work, "restart.json")), "Canceled update restarted the launcher.");
                } finally {
                    Storage.Close();
                    File.WriteAllText(close, "exit");
                    await Stop(worker); await Stop(parent);
                }
            }
            int legacyAt = Array.IndexOf(args, "--legacy-launcher");
            if (legacyAt >= 0) {
                string legacy = Path.GetFullPath(args[legacyAt + 1]);
                string scenario = Path.Combine(output, "legacy-net8-to-net10"),
                       home = Path.Combine(scenario, "selected storage"), target = Path.Combine(scenario, "installation"),
                       work = Path.Combine(home, "updates", Guid.NewGuid().ToString("N")),
                       source = Path.Combine(work, "new"), close = Path.Combine(scenario, "parent-close");
                Fixture(target, "1.0.20", probe, true, "v1.0.20-rc1");
                File.Copy(legacy, Path.Combine(target, "Outbreak.Launcher.exe"), true);
                Inventory(target);
                Fixture(source, "1.0.21", probe, false, "v1.0.21");
                Storage.Configure(target, home);
                await Storage.Initialize(target, false, null, default);
                File.WriteAllText(Path.Combine(home, "keep-save.txt"), "owned save fixture");
                // Legacy helpers omit --data-home on restart. Real installations
                // preserve the chosen location in the locator beside the launcher.
                File.WriteAllText(Path.Combine(target, Storage.LocatorName),
                                  JsonSerializer.Serialize(new { format = 1, folder = home }));
                Process? parent = null, worker = null;
                try {
                    parent = Start(probe, "--update-parent-check", close);
                    var plan = new UpdatePlan(work, source, target, "v1.0.21", parent.Id,
                                             parent.StartTime.ToUniversalTime().Ticks);
                    using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(30));
                    bool refused = false;
                    try { await Updates.StartWorker(plan, timeout.Token); }
                    catch (IOException) { refused = true; }
                    Require(refused && !File.Exists(Path.Combine(work, "ready.json")),
                            "Historical helper unexpectedly resolved selected storage without --data-home.");
                    Require(Updates.InstalledReleaseTag(target) == "v1.0.20-rc1",
                            "Refused historical handoff changed the installation.");
                    // Explicit storage isolates runtime migration from the historical handoff bug.
                    worker = Start(Path.Combine(work, "helper", "Outbreak.Launcher.exe"),
                                   "--apply-update", Path.Combine(work, "plan.json"), "--data-home", home);
                    var clock = Stopwatch.StartNew();
                    while (!File.Exists(Path.Combine(work, "ready.json")) && !worker.HasExited &&
                           clock.Elapsed < TimeSpan.FromSeconds(20)) await Task.Delay(50);
                    Require(File.Exists(Path.Combine(work, "ready.json")), "Historical worker did not accept explicit storage.");
                    File.WriteAllText(Path.Combine(work, "commit.json"), "{}");
                    Storage.Close(); File.WriteAllText(close, "exit");
                    await worker.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(30));
                    Require(worker.ExitCode == 0 && Updates.InstalledReleaseTag(target) == "v1.0.21",
                            "Historical .NET 8 worker could not install the .NET 10 package.");
                    string restarted = Path.Combine(target, "restart-check.json");
                    clock.Restart();
                    while (!File.Exists(restarted) && clock.Elapsed < TimeSpan.FromSeconds(15)) await Task.Delay(50);
                    Require(File.Exists(restarted) && File.ReadAllText(Path.Combine(home, "keep-save.txt")) == "owned save fixture",
                            "Runtime migration did not restart or preserve selected storage.");
                    using var restartReport = JsonDocument.Parse(File.ReadAllText(restarted));
                    Require(restartReport.RootElement.GetProperty("storage").GetString() == home,
                            "Historical restart lost the persistent storage selection.");
                } finally {
                    Storage.Close(); File.WriteAllText(close, "exit");
                    await Stop(worker); await Stop(parent);
                }
            }
            File.WriteAllText(Path.Combine(output, "report.json"), JsonSerializer.Serialize(new {
                passed = true, workerEntry = true, malformedArgumentsRejected = true, customStorage = true,
                readyWithParentLease = true, scenarios, storagePreserved = true,
                legacyRuntimeMigration = legacyAt >= 0,
                legacyStorageHandoffRejected = legacyAt >= 0
            }));
            return 0;
        } finally {
            Storage.Close();
            Environment.SetEnvironmentVariable("DOTNET_DISABLE_GUI_ERRORS", oldGui);
        }
    }
}
