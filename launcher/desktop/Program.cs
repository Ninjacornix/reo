using Avalonia;
using Avalonia.Headless;

namespace Outbreak.Launcher.Desktop;

internal static class Program {
    [STAThread]
    public static int Main(string[] args) {
        int update = Array.IndexOf(args, "--apply-update");
        if (update >= 0) {
            if (!OperatingSystem.IsWindows()) {
                Console.Error.WriteLine("Automatic update installation is only supported on Windows.");
                return 1;
            }
            if (update + 1 >= args.Length || args[update + 1].StartsWith("--")) {
                Console.Error.WriteLine("--apply-update requires an update plan file.");
                return 1;
            }
            // Installer helpers must not create an Avalonia app, claim the UI
            // mutex, or acquire the data lease still held by the parent.
            try { return UpdateWorker.Run(args[update + 1]).GetAwaiter().GetResult(); }
            catch (Exception error) { Console.Error.WriteLine(error); return 1; }
        }
        if (args.Contains("--update-worker-check")) {
            try { return UpdateWorkerChecks.Run(args).GetAwaiter().GetResult(); }
            catch (Exception error) { Console.Error.WriteLine(error); return 1; }
        }
        if(args.Contains("--display-check")){bool awake=PlatformRuntime.DisplayAvailable();System.Console.WriteLine(System.Text.Json.JsonSerializer.Serialize(new{awakeDisplay=awake}));return awake?0:2;}
        if(args.Contains("--runtime-check")||args.Contains("--service-check")){try{return IntegrationChecks.Run(args).GetAwaiter().GetResult();}catch(Exception error){Console.Error.WriteLine(error);return 1;}}
        if(args.Contains("--headless-check")) {
            try{return HeadlessChecks.Run(args);}
            catch(Exception error) {
                // CI annotations are readable without signing in to the job log.
                if(Environment.GetEnvironmentVariable("GITHUB_ACTIONS")=="true")
                    System.Console.WriteLine("::error title=Headless check::"+error.ToString().Replace("%","%25").Replace("\r","").Replace("\n","%0A"));
                System.Console.Error.WriteLine(error);
                return 1;
            }
        }
        return BuildAvaloniaApp().StartWithClassicDesktopLifetime(args);
    }
    public static AppBuilder BuildAvaloniaApp()=>AppBuilder.Configure<App>().UsePlatformDetect().LogToTrace();
}
