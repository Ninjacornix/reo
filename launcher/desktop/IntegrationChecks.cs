using System.Text.Json;
using System.Diagnostics;
namespace Outbreak.Launcher.Desktop;
internal static class IntegrationChecks {
    internal static async Task<int> Run(string[] args) {
        bool service=args.Contains("--service-check");string flag=service?"--service-check":"--runtime-check";
        string output=Path.GetFullPath(args[Array.IndexOf(args,flag)+1]);Directory.CreateDirectory(output);File.Delete(Path.Combine(output,"report.json"));
        string root=PlatformPaths.FindRoot(AppContext.BaseDirectory);Storage.Configure(root,Path.Combine(output,"data"));
        using var deadline=new CancellationTokenSource(TimeSpan.FromMinutes(4));
        try {
            if(service) {
                using var server=new HostedServer();await server.Start(root,"127.0.0.1",deadline.Token,Settings.Home,32000);
                if(!server.Running)throw new IOException("Four server workers did not start.");
                using var client=new HttpClient(new SocketsHttpHandler{UseProxy=false});
                string username="test"+Guid.NewGuid().ToString("N")[..5],password=Guid.NewGuid().ToString("N")[..15];
                var endpoint=new Uri("http://127.0.0.1:42128/reweb/signup/create_id.html");
                await AutomaticAccount.Register(client,endpoint,username,password,deadline.Token);
                await AutomaticAccount.Register(client,endpoint,username,password,deadline.Token);
                bool rejected=false;try{await AutomaticAccount.Register(client,endpoint,username,"wrongpassword12",deadline.Token);}catch(AccountNameTakenException){rejected=true;}
                if(!rejected)throw new IOException("Server accepted the wrong credential.");
                File.WriteAllText(Path.Combine(output,"report.json"),JsonSerializer.Serialize(new{passed=true,workers=4,registration=true,repeatLogin=true,collisionRejected=true}));return 0;
            }
            var record=PlatformPaths.NativeRecord(root)??throw new IOException("Native game record missing.");
            var settings=new Settings{Exe=record["executable"],Iso=record["iso"],InputDeviceId="keyboard",CoopMode="offline",AntiAliasing=false,GpuMovies=false,LauncherBackgroundMovies=false};
            using var controller=new Controller();controller.Configure(settings);
            var game=new GameSession();
            try {
                await game.Launch(root,settings,controller,diagnosticRoute:"gameplay",cancel:deadline.Token);
                var clock=Stopwatch.StartNew();bool reached=false;
                while(game.Running&&clock.Elapsed.TotalSeconds<100) {
                    await Task.Delay(500,deadline.Token);
                    string log=File.ReadAllText(Path.Combine(game.Logs!,"stderr.log"))+File.ReadAllText(Path.Combine(game.Logs!,"stdout.log"));
                    if(log.Contains("[TEST-ROUTE] reached gameplay")){reached=true;break;}
                }
                if(game.Process is {} process)await PlatformRuntime.Stop(process);
                if(!reached)throw new IOException("Common GameSession did not reach gameplay. Inspect "+game.Logs);
                File.WriteAllText(Path.Combine(output,"report.json"),JsonSerializer.Serialize(new{passed=true,reachedGameplay=true,logs=game.Logs,executable=game.Process!.StartInfo.FileName,exitCode=game.Process.ExitCode}));return 0;
            }finally{if(game.Process is {} process&&!process.HasExited)await PlatformRuntime.Stop(process);}
        }catch(Exception error){File.WriteAllText(Path.Combine(output,"report.json"),JsonSerializer.Serialize(new{passed=false,error=error.Message,utc=DateTime.UtcNow}));throw;}finally{Storage.Close();}
    }
}
