using System.IO;
using System.Windows;

namespace Outbreak.Launcher;
public partial class App : Application
{
    Mutex? singleInstance;
    protected override void OnStartup(StartupEventArgs e)
    {
        base.OnStartup(e);
        try
        {
            if (e.Args.Contains("--self-test")) { SelfTest.Run(); Shutdown(); return; }
            bool diagnostic = e.Args.Any(arg => arg is "--screenshot" or "--probe-controller" or "--smoke-launch");
            if (!diagnostic)
            {
                singleInstance = new Mutex(true, "Local\\Outbreak-Launcher", out bool created);
                if (!created) { MessageBox.Show("The Outbreak launcher is already open.", "RE: Outbreak"); Shutdown(); return; }
            }
            var window = new MainWindow(e.Args); MainWindow = window; window.Show();
        }
        catch (Exception error)
        {
            Directory.CreateDirectory(Settings.Home);
            File.WriteAllText(Path.Combine(Settings.Home, "launcher-error.log"), error.ToString());
            if (!e.Args.Contains("--self-test")) MessageBox.Show(error.Message, "RE: Outbreak");
            Shutdown(1);
        }
    }
    protected override void OnExit(ExitEventArgs e) { singleInstance?.Dispose(); base.OnExit(e); }
}
