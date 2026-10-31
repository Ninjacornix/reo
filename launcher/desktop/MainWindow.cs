using Avalonia;
using Avalonia.Controls;
using Avalonia.Markup.Xaml;
using Avalonia.Media;
using Avalonia.VisualTree;
using System.Text.Json;
using Avalonia.Threading;
using Avalonia.Controls.Primitives;
using Avalonia.Platform;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow:Window {
    public string Root {get;}
    public Settings Settings {get;}
    readonly bool staticCapture;
    readonly Controller controller;
    readonly GameSession game=new();
    readonly AudioMixer? audio;
    readonly SubtitleControl? subtitles;
    readonly DispatcherTimer tick=new(){Interval=TimeSpan.FromMilliseconds(16)};
    readonly DispatcherTimer saveTimer=new(){Interval=TimeSpan.FromMilliseconds(250)};
    readonly CancellationTokenSource lifetime=new();
    bool initialized,busy,closed;
    string currentPage="Play";
    internal Task? Initialization {get;private set;}
    public MainWindow():this([]) { }
    public MainWindow(string[]? args) {
        args ??= [];
        staticCapture=args.Contains("--static-capture");
        Root=PlatformPaths.FindRoot(AppContext.BaseDirectory);
        int home=Array.IndexOf(args,"--data-home");
        Storage.Configure(Root,home>=0?args[home+1]:null);
        Settings=Settings.Load(Root);
        if(staticCapture)Settings.LauncherBackgroundMovies=false;
        if(PlatformPaths.NativeRecord(Root) is {} record) {
            if(!File.Exists(Settings.Exe))Settings.Exe=record["executable"];
            if(!File.Exists(Settings.Iso))Settings.Iso=record["iso"];
            if(!Directory.Exists(Settings.ImportedFile1)&&record.TryGetValue("data",out var data))Settings.ImportedFile1=Path.GetDirectoryName(data)!;
        }
        InitializeComponent();
        controller=new();controller.Configure(Settings);
        if(OperatingSystem.IsWindows()) {
            audio=new();subtitles=new();game.AudioMapName=audio.MapName;game.SubtitleMapName=subtitles.MapName;
        }
        VersionLabel.Text="1.0.20-rc1";
        InitializeSettings();
        InitializeCommands();
        initialized=true;
        saveTimer.Tick+=(_,_)=>{saveTimer.Stop();TrySave();};
        tick.Tick+=(_,_)=>Tick();
        Opened+=(_,_)=>{
            if(OperatingSystem.IsWindows()&&TryGetPlatformHandle() is {} handle)controller.Attach(handle.Handle);
            Initialization=InitializeAssets();tick.Start();
        };
        Closing+=OnClosing;
        Closed+=(_,_)=>{
            mediaPreparation?.Cancel();BackgroundMovieA.Dispose();BackgroundMovieB.Dispose();
            closed=true;lifetime.Cancel();tick.Stop();saveTimer.Stop();controller.Dispose();audio?.Dispose();subtitles?.Dispose();
            lan?.Dispose();server.Dispose();if(OperatingSystem.IsWindows())_ = HostNetworking.ClosePorts();Storage.Close();
        };
        BackgroundMovieA.FrameReady+=()=>{
            if(BackgroundMovieA.HasVideo){BackgroundScene.IsVisible=currentPage=="Play";ArtworkLayer.IsVisible=true;ImageBackdropLayer.IsVisible=false;ImageBackgroundShade.IsVisible=false;VideoBackgroundShade.IsVisible=VideoVignette.IsVisible=true;}
        };
        Deactivated+=(_,_)=>NativeControllers.ClearKeys();
        ShowPage("Play");
        RefreshUi();
    }
    public void ShowPage(string page) {
        currentPage=page;
        foreach(string name in new[]{"Play","Graphics","Audio","Controller","Saves","Coop","Mods","Cheats","Setup","Launcher","Logs","Developer"}) {
            if(this.FindControl<Control>("Page"+name) is {} control)control.IsVisible=name==page;
            if(this.FindControl<Button>("Nav"+name) is {} button) {
                button.Classes.Set("selected",name==page);
                button.Background=name==page?new SolidColorBrush(Color.Parse("#40DB6A22")):Brushes.Transparent;
                button.Foreground=new SolidColorBrush(Color.Parse(name==page?"#F3ECDF":"#B3A898"));
            }
        }
        SettingsScroll.IsVisible=page!="Logs";
        SettingsScroll.VerticalScrollBarVisibility=page=="Graphics"?ScrollBarVisibility.Disabled:ScrollBarVisibility.Auto;
        if(page=="Controller")BuildBindings();
        if(page=="Saves")RefreshCards();
        if(page=="Coop")RefreshOnline();
        if(page=="Mods")RefreshMods();
        if(page=="Cheats")RefreshCheats();
        if(page=="Logs")RefreshLogs();
        RefreshBackdrop();
    }
}
