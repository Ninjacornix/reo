using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Markup.Xaml;

namespace Outbreak.Launcher.Desktop;

// Port of RC1 App.xaml.cs desktop startup. The installer is dispatched by Program
// before Avalonia starts; this class handles the interactive startup sequence.
public sealed partial class App : Application {
    Mutex? singleInstance;
    // RC1 turns tooltips off for every element (App static constructor).
    static App() => ToolTip.ToolTipOpeningEvent.AddClassHandler<Control>((_, e) => e.Cancel = true);
    public override void Initialize() => AvaloniaXamlLoader.Load(this);
    public override void OnFrameworkInitializationCompleted() {
        if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop) {
            desktop.ShutdownMode = ShutdownMode.OnExplicitShutdown;
            desktop.Exit += (_, _) => { Storage.Close(); singleInstance?.Dispose(); };
            _ = Start(desktop, desktop.Args ?? []);
        }
        base.OnFrameworkInitializationCompleted();
    }
    static bool StorageLockHeld() {
        string path = Path.Combine(Settings.Home, ".storage.lock");
        try { using var probe = new FileStream(path, FileMode.Open, FileAccess.ReadWrite, FileShare.None); return false; }
        catch (IOException) { return File.Exists(path); }
        catch (UnauthorizedAccessException) { return false; }
    }
    async Task Start(IClassicDesktopStyleApplicationLifetime desktop, string[] args) {
        try {
            int wait = Array.IndexOf(args, "--wait-for-launcher-exit");
            if (wait >= 0 && wait + 2 < args.Length && int.TryParse(args[wait + 1], out int pid) &&
                long.TryParse(args[wait + 2], out long ticks)) {
                try {
                    using var parent = Process.GetProcessById(pid);
                    if (parent.StartTime.ToUniversalTime().Ticks == ticks)
                        await parent.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(15));
                } catch (Exception error) when (error is ArgumentException or TimeoutException or InvalidOperationException) { }
            }
            string storageRoot = PlatformPaths.FindRoot(AppContext.BaseDirectory);
            int storage = Array.IndexOf(args, "--data-home");
            if (storage >= 0 && (storage + 1 >= args.Length || args[storage + 1].StartsWith("--")))
                throw new ArgumentException("--data-home requires a folder.");
            Storage.Configure(storageRoot, storage >= 0 ? args[storage + 1] : null);
            bool diagnostic = args.Any(arg => arg is "--screenshot" or "--probe-controller" or "--smoke-launch");
            if (!diagnostic) {
                singleInstance = new Mutex(true, "Local\\Outbreak-Launcher", out bool created);
                if (!created) {
                    await MessageBox.Show(null, "The Outbreak launcher is already open.", "RE: Outbreak");
                    desktop.Shutdown();
                    return;
                }
            }
            string installation = storageRoot;
            if (AppLayout.Packaged(installation) && Updates.InstallationBusy(installation)) {
                await MessageBox.Show(null,
                    "An update is being installed. The launcher will restart when it is ready.",
                    "RE: Outbreak");
                desktop.Shutdown();
                return;
            }
            bool importOldData = !args.Any(arg => arg.StartsWith("--test-") ||
                arg is "--smoke-launch" or "--screenshot" or "--probe-controller");
            try {
                await Storage.Initialize(installation, importOldData, null, default, !diagnostic);
            } catch (IOException) when (!diagnostic && StorageLockHeld()) {
                // Another launcher instance owns the data folder (the single-instance mutex is
                // per-session on some desktops): report it like RC1's mutex check.
                await MessageBox.Show(null, "The Outbreak launcher is already open.", "RE: Outbreak");
                desktop.Shutdown();
                return;
            }
            var window = new MainWindow(args);
            desktop.MainWindow = window;
            window.Show();
            desktop.ShutdownMode = ShutdownMode.OnMainWindowClose;
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
            if (!args.Contains("--smoke-launch") && !args.Contains("--screenshot"))
                await MessageBox.Show(null, error.GetBaseException().Message +
                                (log.Length > 0 ? "\n\nDetails: " + log : "\n\nKeep the launcher in a folder you can write to, such as your Games folder."),
                                "RE: Outbreak");
            desktop.Shutdown(1);
        }
    }
}
