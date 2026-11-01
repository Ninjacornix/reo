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
    static void Fixture(string root, string version, string probe, bool launcher) {
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
        Require(File.Exists(Path.Combine(root, "hostfxr.dll")) && File.Exists(Path.Combine(root, "hostpolicy.dll")),
                "Publish the launcher and cross-test probe as self-contained Windows packages first.");
        File.WriteAllText(Path.Combine(root, "distribution.json"), JsonSerializer.Serialize(new {
            format = 2, updateFormat = 2, installMode = "local-build", version,
            platform = "win-x64", source = Updates.Repository
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
            foreach (bool cancel in new[] { true, false }) {
                string scenario = Path.Combine(output, cancel ? "cancel" : "install"),
                       home = Path.Combine(scenario, "selected storage"), target = Path.Combine(scenario, "installation"),
                       work = Path.Combine(home, "updates", Guid.NewGuid().ToString("N")),
                       source = Path.Combine(work, "new"), close = Path.Combine(scenario, "parent-close");
                Fixture(target, "0.1.0", probe, true);
                Fixture(source, "0.2.0", probe, false);
                Storage.Configure(target, home);
                await Storage.Initialize(target, false, null, default);
                File.WriteAllText(Path.Combine(home, "keep-save.txt"), "owned save fixture");
                Process? parent = null, worker = null;
                try {
                    parent = Start(probe, "--update-parent-check", close);
                    var plan = new UpdatePlan(work, source, target, "v0.2.0", parent.Id,
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
                    Require(Updates.InstalledVersion(target) == Updates.ParseVersion(cancel ? "0.1.0" : "0.2.0"),
                            "Canceled or committed update published the wrong version.");
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
            File.WriteAllText(Path.Combine(output, "report.json"), JsonSerializer.Serialize(new {
                passed = true, workerEntry = true, malformedArgumentsRejected = true, customStorage = true,
                readyWithParentLease = true, cancellation = true, installation = true, restart = true, storagePreserved = true
            }));
            return 0;
        } finally {
            Storage.Close();
            Environment.SetEnvironmentVariable("DOTNET_DISABLE_GUI_ERRORS", oldGui);
        }
    }
}
