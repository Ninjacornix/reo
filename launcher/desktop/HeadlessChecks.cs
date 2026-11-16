using Avalonia;
using Avalonia.Headless;
using Avalonia.Threading;
using Avalonia.Media.Imaging;
using Avalonia.Controls;
using Avalonia.Controls.Primitives;
using Avalonia.Interactivity;
using Avalonia.VisualTree;
using System.Text.Json;
using System.Diagnostics;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

internal static class HeadlessChecks {
    public static int Run(string[] args) {
        string output=args[Array.IndexOf(args,"--headless-check")+1];
        Directory.CreateDirectory(output);File.Delete(Path.Combine(output,"report.json"));
        AppBuilder.Configure<App>().UseHeadless(new AvaloniaHeadlessPlatformOptions{UseHeadlessDrawing=false}).UseSkia().SetupWithoutStarting();
        string dataHome=Path.Combine(Path.GetFullPath(output),"data");
        Storage.Configure(PlatformPaths.FindRoot(AppContext.BaseDirectory),dataHome);
        Task.Run(()=>Storage.Initialize(PlatformPaths.FindRoot(AppContext.BaseDirectory),false,null,default,false)).GetAwaiter().GetResult();
                var window=new MainWindow(["--data-home",dataHome,"--static-capture"]);
        window.Show();Dispatcher.UIThread.RunJobs();
        var deadline=Stopwatch.StartNew();
        while(deadline.Elapsed.TotalSeconds<60&&(!window.IsLoaded||!window.ArtworkLoad.IsCompleted||deadline.Elapsed.TotalSeconds<1)){Dispatcher.UIThread.RunJobs();Thread.Sleep(10);}
        int checks=0;
        void Check(bool condition,string why){if(!condition)throw new IOException(why);checks++;}
        T Control<T>(string name) where T:Avalonia.Controls.Control=>window.FindControl<T>(name)??throw new IOException("Missing RC1 control: "+name);
        window.ShowPage("Controller");Dispatcher.UIThread.RunJobs();
        var input=Control<ComboBox>("InputDevicePicker");
        input.SelectedItem=input.Items.OfType<InputDevice>().First(d=>d.Kind=="keyboard");
        Dispatcher.UIThread.RunJobs();
        Check(Control<StackPanel>("KeyboardStickBindingsPanel").IsVisible &&
              Control<UniformGrid>("KeyboardStickBindings").Children.Count==4,
              "The common launcher lost the RC2 keyboard voice-command bindings.");
        var up=window.GetVisualDescendants().OfType<Button>().First(b=>b.Tag as string=="Up");
        up.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Check(Control<Grid>("CapturePanel").IsVisible,"Keyboard remapping did not enter capture mode.");
        up.Focus();
        window.KeyPress(Key.Up,RawInputModifiers.None,PhysicalKey.ArrowUp,null);
        Dispatcher.UIThread.RunJobs();
        Check(window.settings.Keyboard["Up"]==38 && window.settings.Keyboard["CameraUp"]==0,
              $"Remapping movement to an arrow did not release its old voice command (Up={window.settings.Keyboard["Up"]}, CameraUp={window.settings.Keyboard["CameraUp"]}, capture={Control<TextBlock>("CaptureHint").Text}).");
        window.KeyRelease(Key.Up,RawInputModifiers.None,PhysicalKey.ArrowUp,null);
        Dispatcher.UIThread.RunJobs();
        Check(InputMapping.Keyboard(window.settings.Keyboard,k=>k==38)==new Pad(1),
              "Keyboard movement must send only the digital D-pad after remapping.");
        Control<Button>("ResetBindingsButton").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        // Controls > Modern camera: tab, switch, sliders reach settings and the game environment.
        Control<Button>("ModernCameraTab").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Dispatcher.UIThread.RunJobs();
        Check(Control<StackPanel>("ModernCameraPanel").IsVisible && !Control<StackPanel>("InputBindingsPanel").IsVisible,
              "Modern camera tab does not show its panel.");
        Check(!window.settings.ModernCamera.Enabled && !Control<Slider>("ModernCameraDistance").IsEnabled,
              "Modern camera must start off with its options disabled.");
        Control<CheckBox>("ModernCameraSwitch").IsChecked=true;
        Dispatcher.UIThread.RunJobs();
        Control<Slider>("ModernCameraDistance").Value=420;
        Control<Slider>("ModernCameraShoulder").Value=-50;
        Control<CheckBox>("ModernCameraInvert").IsChecked=true;
        Dispatcher.UIThread.RunJobs();
        var camera=window.settings.ModernCamera;
        Check(camera.Enabled && camera.Distance==420 && camera.Shoulder==-50 && camera.InvertY &&
              Control<Slider>("ModernCameraDistance").IsEnabled,
              "Modern camera controls do not reach saved settings.");
        Check(ModernCamera.Environment(camera)["REO_CAMERA_TPS"].StartsWith("distance=420,side=-50,") &&
              Control<TextBlock>("ModernCameraDistanceLabel").Text=="Distance: 420",
              "Modern camera settings do not reach the game environment or labels.");
        Control<Button>("ModernCameraResetButton").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Dispatcher.UIThread.RunJobs();
        Check(window.settings.ModernCamera is {Enabled:true,Distance:300,Shoulder:35,InvertY:false},
              "Resetting camera settings must keep the switch and restore defaults.");
        Control<CheckBox>("ModernCameraSwitch").IsChecked=false;
        Control<Button>("BindingsTab").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Dispatcher.UIThread.RunJobs();
        Check(!Control<StackPanel>("ModernCameraPanel").IsVisible && Control<StackPanel>("InputBindingsPanel").IsVisible,
              "Returning to Button map must hide the modern camera panel.");
        window.ShowPage("Graphics");Dispatcher.UIThread.RunJobs();
        window.CheckMovieDecoderSettings(Check);
        var sync = Control<ComboBox>("VSync");
        Check(sync.SelectedIndex == 0, "Existing settings must default VSync to On.");
        foreach (var (index, mode) in new[] { (1, "off"), (2, "adaptive"), (0, "on") }) {
            sync.SelectedIndex = index;
            Check(window.settings.ResolvedVSync == mode &&
                      Settings.Load(window.root).ResolvedVSync == mode,
                  "VSync selection did not persist: " + mode);
        }
        var resolution=Control<ComboBox>("InternalResolution");resolution.IsDropDownOpen=true;Dispatcher.UIThread.RunJobs();
        Check(resolution.GetRealizedContainers().Any(),"Dropdown does not populate RC1 choices.");resolution.IsDropDownOpen=false;
        Control<ComboBox>("InternalResolution").SelectedIndex=2;
        Check(window.settings.InternalResolution==4,"Resolution selector does not reach shared settings.");
        window.CheckMovieDecoderSettings(Check);
        window.ShowPage("Audio");Dispatcher.UIThread.RunJobs();
        var music=Control<Slider>("MusicVolume");
        var track=music.GetVisualDescendants().OfType<Track>().First();track.Value=37;
        Check(music.Value==37,"Dragging the audio track does not update its slider.");
        Dispatcher.UIThread.RunJobs();
        Check(track.Orientation==Avalonia.Layout.Orientation.Horizontal&&track.DecreaseButton!.Bounds.Width>0&&track.DecreaseButton.Bounds.Height>0,"Slider fill track is not laid out horizontally.");
        Check(window.settings.MusicVolume==37,"Audio slider does not reach shared settings.");
        Control<CheckBox>("Fullscreen").IsChecked=true;
        Check(window.settings.Fullscreen&&!Control<ComboBox>("WindowSize").IsEnabled,"Fullscreen toggle does not update window controls.");
        Control<ListBox>("GameCasePicker").SelectedIndex=1;
        Check(window.settings.Game.Id=="file2"&&Control<ListBox>("GamePicker").SelectedIndex==1,"Case and disc selectors lost synchronization.");
        Control<ListBox>("GamePicker").SelectedIndex=0;
        Check(window.settings.Game.Id=="file1"&&Control<ListBox>("GameCasePicker").SelectedIndex==0,"Disc selection does not update the case.");
        Control<ComboBox>("InternalResolution").SelectedIndex=0;Control<Slider>("MusicVolume").Value=100;Control<CheckBox>("Fullscreen").IsChecked=false;
        bool installed=DiscImport.Ready(window.settings,"file1")||DiscImport.Ready(window.settings,"file2");
        Check(Control<Button>("NavGraphics").IsEnabled==installed,"RC1 game pages must wait for an installed game.");
        Control<Button>("NavSetup").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Check(Control<Control>("PageSetup").IsVisible&&!Control<Control>("PagePlay").IsVisible,"RC1 navigation command is not connected.");
        window.settings.Save();
        Check(Settings.Load(window.root).MusicVolume==100,"Settings cannot round-trip on this OS.");
        window.ShowPage("Developer");Dispatcher.UIThread.RunJobs();
        var slowdowns=Control<CheckBox>("DevSlowdowns");
        Check(!window.settings.Developer.RecordSlowdowns,"Slowdown recording must be off by default.");
        slowdowns.IsChecked=true;Dispatcher.UIThread.RunJobs();
        Check(window.settings.Developer.RecordSlowdowns&&Settings.Load(window.root).Developer.RecordSlowdowns,"Slowdown recording toggle must reach persisted settings.");
        var sensitive=Control<CheckBox>("DevStrictSlowdowns");
        Check(sensitive.IsEnabled&&!window.settings.Developer.StrictSlowdowns,"Sensitive detection must be opt-in and available when recording is enabled.");
        sensitive.IsChecked=true;Dispatcher.UIThread.RunJobs();
        Check(window.settings.Developer.StrictSlowdowns&&Settings.Load(window.root).Developer.StrictSlowdowns,"Sensitive detection must persist for the next launch.");
        Check(!Control<Button>("MarkPerformanceProblem").IsEnabled&&Control<TextBlock>("PerformanceRecordingStatus").Text!.Contains("Not recording"),"A saved option must not claim an active recorder or enable manual capture before launch.");
        sensitive.IsChecked=false;slowdowns.IsChecked=false;Dispatcher.UIThread.RunJobs();
        string fixture=Path.Combine(Settings.Home,"sessions","20000101-000000-fixture");Directory.CreateDirectory(fixture);
        File.WriteAllText(Path.Combine(fixture,"stderr.log"),"Shared launcher log fixture.\n");File.WriteAllText(Path.Combine(fixture,"stdout.log"),"Shared launcher output fixture.\n");
        window.ShowPage("Logs");Dispatcher.UIThread.RunJobs();
        Check(!Control<Control>("LogEmpty").IsVisible&&Control<TextBox>("DebugLog").Text!.Contains("log fixture"),"Session debug log is not displayed.");
        Control<ComboBox>("LogStreamPicker").SelectedIndex=1;
        Check(Control<TextBox>("DebugLog").Text!.Contains("output fixture"),"Session output selector does not switch logs.");
        foreach(string page in new[]{"Play","Graphics","Audio","Controller","Saves","Coop","Mods","Cheats","Setup","Launcher","Logs","Developer"}) {
            window.ShowPage(page);Dispatcher.UIThread.RunJobs();
            Check(Control<Control>("Page"+page).IsVisible,"Page is hidden: "+page);
            Check(window.GetVisualDescendants().OfType<Avalonia.Controls.Control>().All(c=>double.IsFinite(c.Bounds.Width)&&double.IsFinite(c.Bounds.Height)),"Invalid control bounds: "+page);
            using var bitmap=window.CaptureRenderedFrame();Check(bitmap!=null,"Page did not render: "+page);bitmap!.Save(Path.Combine(output,page+".png"));
        }
        window.ShowPage("Coop");Control<RadioButton>("ModeHost").IsChecked=true;Dispatcher.UIThread.RunJobs();
        Check(window.settings.ResolvedCoopMode=="host"&&Control<Control>("HostOptions").IsVisible&&!Control<Control>("JoinOptions").IsVisible,"Host mode did not reveal its RC1 controls.");
        using(var bitmap=window.CaptureRenderedFrame())bitmap!.Save(Path.Combine(output,"Coop-host.png"));
        Control<RadioButton>("ModeJoin").IsChecked=true;Dispatcher.UIThread.RunJobs();
        Check(window.settings.ResolvedCoopMode=="join"&&Control<Control>("JoinOptions").IsVisible&&!Control<Control>("HostOptions").IsVisible,"Join mode did not reveal its RC1 controls.");
        using(var bitmap=window.CaptureRenderedFrame())bitmap!.Save(Path.Combine(output,"Coop-join.png"));
        Control<RadioButton>("ModeOffline").IsChecked=true;
        window.ShowPage("Setup");var developer=Control<Expander>("DeveloperFiles");
        Check(developer.IsVisible==!AppLayout.Packaged(window.root),"Developer setup visibility does not match the installation type.");
        if(developer.IsVisible) {
            developer.IsExpanded=true;Dispatcher.UIThread.RunJobs();
            Check(developer.GetVisualDescendants().OfType<Border>().Any(b=>b.Name=="OptionsBody"&&b.IsVisible&&b.Bounds.Height>0),"RC1 expandable section did not open.");developer.IsExpanded=false;
        }
        window.CheckGraphicsPreviewReentry(Check);
        window.CheckHostingSummary(Check);
        window.CheckActivityOverlay(Check, output);
        bool mediaChecked=false;
        string? ffmpeg=null;try{ffmpeg=PlatformServices.Ffmpeg();}catch(IOException){}
        Check(!args.Contains("--require-media") || ffmpeg!=null,"This regression run requires a real FFmpeg decoder; video checks must not be skipped.");
        if(ffmpeg!=null) {
            string clip=Path.Combine(Path.GetFullPath(output),"decoder-fixture.avi");
            var start=new ProcessStartInfo(ffmpeg){UseShellExecute=false,RedirectStandardError=true};
            foreach(string argument in new[]{"-hide_banner","-loglevel","error","-y","-f","lavfi","-i","testsrc2=size=64x64:rate=10","-t","1","-c:v","mpeg4",clip})start.ArgumentList.Add(argument);
            using(var child=Process.Start(start)!) {string error=child.StandardError.ReadToEnd();Check(child.WaitForExit(15000)&&child.ExitCode==0,"Bundled FFmpeg fixture failed: "+error);}
            using var surface=new VideoSurface();int frames=0;bool opened=false;surface.MediaOpened+=(_,_)=>opened=true;surface.Open(clip);surface.Play();
            var timer=Stopwatch.StartNew();while(!opened&&timer.Elapsed.TotalSeconds<15){Dispatcher.UIThread.RunJobs();Thread.Sleep(10);}frames=opened?3:0;
            Check(frames>=3&&surface.HasVideo,"Background-video worker did not decode frames.");
            Check(surface.NaturalDuration is {} length&&Math.Abs(length.TotalSeconds-1)<.2,"Background video duration was not read.");
            surface.Pause();double held=surface.Position.TotalSeconds;var pause=Stopwatch.StartNew();while(pause.Elapsed.TotalSeconds<.4){Dispatcher.UIThread.RunJobs();Thread.Sleep(10);}
            Check(surface.Position.TotalSeconds==held,"Paused background video kept advancing.");
            bool ended=false;surface.MediaEnded+=(_,_)=>ended=true;surface.Play();timer.Restart();while(!ended&&timer.Elapsed.TotalSeconds<10){Dispatcher.UIThread.RunJobs();Thread.Sleep(10);}
            Check(ended&&surface.Position.TotalSeconds>.8,"Background video did not reach its end.");
            Check(surface.DecodeCompletion.IsCompleted&&!surface.HasDecoder,"Completed video retained a disposed decoder handle.");
            surface.Close();Check(!surface.HasVideo,"Stopped video retained its frame.");
            // Exercise teardown while the worker is starting, rendering, seeking,
            // and exiting. Wait for every run so faults cannot hide in discarded tasks.
            var decoding=new List<Task>();
            for(int i=0;i<30;i++) {
                surface.Open(clip);surface.Play();decoding.Add(surface.DecodeCompletion);
                if(i%3==0) {
                    var until=Stopwatch.StartNew();
                    while(!surface.HasVideo&&until.Elapsed.TotalSeconds<3){Dispatcher.UIThread.RunJobs();Thread.Sleep(2);}
                    surface.Position=TimeSpan.FromSeconds(.8);decoding.Add(surface.DecodeCompletion);
                }
                surface.Close();Dispatcher.UIThread.RunJobs();
            }
            timer.Restart();while(decoding.Any(t=>!t.IsCompleted)&&timer.Elapsed.TotalSeconds<10){Dispatcher.UIThread.RunJobs();Thread.Sleep(2);}
            Check(decoding.All(t=>t.IsCompletedSuccessfully)&&!surface.HasDecoder,"Cancelled/seeking video left a decoder running or faulted during close.");
            window.CheckBackgroundVideoNavigation(clip,Check);
            mediaChecked=true;
        }
        File.WriteAllText(Path.Combine(output,"visual-brushes.txt"),string.Join("\n",window.GetVisualDescendants().OfType<Avalonia.Controls.Control>().Select(c=>$"{c.GetType().Name} {c.Name} {c.Bounds} bg={c.GetValue(TemplatedControl.BackgroundProperty)}")));
        if(OperatingSystem.IsWindows()&&Environment.GetEnvironmentVariable("GITHUB_ACTIONS")=="true")
            Console.WriteLine("::notice title=GDI metrics Segoe UI (size:height/ascent/descent)::"+Compatibility.GdiText.Metrics("Segoe UI"));
        window.Close();
        File.WriteAllText(Path.Combine(output,"report.json"),JsonSerializer.Serialize(new{passed=true,pages=12,checks,mediaChecked}));
        return 0;
    }
}

public partial class MainWindow {
    internal void CheckBackgroundVideoNavigation(string clip,Action<bool,string> check) {
        // The normal refresh suppresses movies for static captures. Pause only
        // that refresh while this check explicitly supplies an asset-free clip.
        bool ticking=timer.IsEnabled, available=NavDeveloper.IsEnabled;
        timer.Stop();NavDeveloper.IsEnabled=true;
        try {
            for(int i=0;i<6;i++) {
                ShowPage("Play");
                backgroundPlayer!.SetPlaylist("navigation-fixture",[clip]);
                backgroundPlayer.Suspend(false);
                var wait=Stopwatch.StartNew();
                while(!backgroundPlayer.HasVideo&&wait.Elapsed.TotalSeconds<4){Dispatcher.UIThread.RunJobs();Thread.Sleep(2);}
                check(backgroundPlayer.HasVideo,"Synthetic background movie did not start before navigating to Developer: "+backgroundPlayer.LastError);
                // Follow the routed click -> ShowPage -> Suspend -> Close path
                // reported by Windows' unhandled-exception event.
                NavDeveloper.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
                Dispatcher.UIThread.RunJobs();
                check(currentPage=="Developer"&&!backgroundPlayer.HasVideo,"Developer navigation failed to release active background video.");
            }
        } finally {
            backgroundPlayer!.Suspend(true);
            backgroundPlayer.SetPlaylist(settings.Game.Id,[]);
            NavDeveloper.IsEnabled=available;
            if(ticking)timer.Start();
        }
    }
    internal void CheckHostingSummary(Action<bool, string> check) {
        var previousMode = settings.CoopMode;
        string previousHost = settings.CoopHost, previousUsername = settings.AccountUsername;
        try {
            settings.CoopMode = "host";
            settings.CoopHost = "192.0.2.1";
            settings.AccountUsername = "hosttest";
            serverStarting = false;
            RefreshOnlineUi();
            check(PlayNetworkSummary.Text == "Hosting not running (see Co-op)", "Stopped hosting is presented as still opening.");
            check(StartServerButton.IsVisible, "Stopped hosting has no start/retry button after reopening the launcher.");
            serverStarting = true;
            RefreshOnlineUi();
            check(PlayNetworkSummary.Text == "Hosting (opening your game...)", "Active hosting startup is not shown.");
            check(!StartServerButton.IsVisible, "Hosting offers another startup while setup is in progress.");
        } finally {
            serverStarting = false;
            settings.CoopMode = previousMode;
            settings.CoopHost = previousHost;
            settings.AccountUsername = previousUsername;
            RefreshOnlineUi();
        }
    }

    // Exercise the actual layout callback which can synchronously request another preview frame.
    internal void CheckGraphicsPreviewReentry(Action<bool, string> check) {
        ShowPage("Graphics"); Dispatcher.UIThread.RunJobs();
        graphicsPreviewLoad?.Cancel();
        // Showing the page may already have a frame in flight; let it finish so this check owns the next one.
        for (var idle = Stopwatch.StartNew(); graphicsPreviewBusy && idle.Elapsed.TotalSeconds < 20;) {
            Dispatcher.UIThread.RunJobs(); Thread.Sleep(1);
        }
        graphicsScene = null;
        // A collapsed control keeps its last arranged size on some platforms (macOS), so showing it
        // again need not raise SizeChanged. Give it a different size so the render's own layout pass
        // always reaches the callback, as a first show does.
        double previousWidth = GraphicsGpuView.Width;
        GraphicsGpuView.Width = Math.Max(32, GraphicsGpuView.Bounds.Width - 7);
        GraphicsGpuView.Visibility = Visibility.Collapsed;
        UpdateLayout();
        var positions = new[] { System.Numerics.Vector3.Zero, System.Numerics.Vector3.UnitY };
        var skin = new GamePreviewScene.Skin(positions, positions.ToArray(), positions.ToArray(), positions.ToArray(), [[], []]);
        graphicsScene = new([], [], [], [skin], "synthetic layout regression");
        graphicsPreviewFaulted = false;
        graphicsPreviewVersion++;
        graphicsPreviewNextFrame = 0;
        graphicsPreviewTimer.Stop();
        bool reentered = false, ownedDuringLayout = false, nestedCompleted = false;
        void Reenter(object? sender, SizeChangedEventArgs args) {
            if (reentered) return;
            reentered = true;
            ownedDuringLayout = graphicsPreviewBusy;
            nestedCompleted = RenderGraphicsPreview().IsCompleted;
        }
        GraphicsGpuView.SizeChanged += Reenter;
        string guard = $"active={GraphicsPreviewActive} busy={graphicsPreviewBusy} faulted={graphicsPreviewFaulted} stage={GraphicsPreviewStage.ActualWidth}x{GraphicsPreviewStage.ActualHeight} pageVisible={PageGraphics.IsEffectivelyVisible} launching={launching}";
        try {
            var render = RenderGraphicsPreview();
            var deadline = Stopwatch.StartNew();
            while (!render.IsCompleted && deadline.Elapsed.TotalSeconds < 20) {
                Dispatcher.UIThread.RunJobs(); Thread.Sleep(1);
            }
            check(render.IsCompletedSuccessfully, "Preview did not complete after a layout reentry.");
            check(reentered && ownedDuringLayout && nestedCompleted,
                $"Layout preview ownership: callback={reentered}, busy={ownedDuringLayout}, nestedCompleted={nestedCompleted}. {guard}");
        } finally {
            GraphicsGpuView.SizeChanged -= Reenter;
            GraphicsGpuView.Width = previousWidth;
            ShowPage("Play");
            graphicsScene = null;
            graphicsPreviewSource = "";
            graphicsPreviewVersion++;
        }
    }
}
