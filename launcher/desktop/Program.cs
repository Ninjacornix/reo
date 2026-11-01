using Avalonia;
using Avalonia.Headless;

namespace Outbreak.Launcher.Desktop;

internal static class Program {
    [STAThread]
    public static int Main(string[] args) {
        if(args.Contains("--display-check")){bool awake=PlatformRuntime.DisplayAvailable();System.Console.WriteLine(System.Text.Json.JsonSerializer.Serialize(new{awakeDisplay=awake}));return awake?0:2;}
        if(args.Contains("--runtime-check")||args.Contains("--service-check")){try{return IntegrationChecks.Run(args).GetAwaiter().GetResult();}catch(Exception error){Console.Error.WriteLine(error);return 1;}}
        if(args.Contains("--headless-check"))return HeadlessChecks.Run(args);
        return BuildAvaloniaApp().StartWithClassicDesktopLifetime(args);
    }
    public static AppBuilder BuildAvaloniaApp()=>AppBuilder.Configure<App>().UsePlatformDetect().LogToTrace();
}
