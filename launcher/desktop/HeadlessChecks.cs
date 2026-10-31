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
        var window=new MainWindow(["--data-home",Path.Combine(Path.GetFullPath(output),"data"),"--static-capture"]);
        window.Show();Dispatcher.UIThread.RunJobs();
        var deadline=System.Diagnostics.Stopwatch.StartNew();
        while(window.Initialization is {} load&&!load.IsCompleted&&deadline.Elapsed.TotalSeconds<120) {
            Dispatcher.UIThread.RunJobs();Thread.Sleep(10);
        }
        if(window.Initialization is {IsCompleted:false})throw new TimeoutException("Asset initialization did not finish.");
        window.Initialization?.GetAwaiter().GetResult();
        int checks=0;
        void Check(bool condition,string why){if(!condition)throw new IOException(why);checks++;}
        T Control<T>(string name) where T:Avalonia.Controls.Control=>window.FindControl<T>(name)??throw new IOException("Missing RC1 control: "+name);
        window.ShowPage("Graphics");Dispatcher.UIThread.RunJobs();
        var resolution=Control<ComboBox>("InternalResolution");resolution.IsDropDownOpen=true;Dispatcher.UIThread.RunJobs();
        Check(resolution.GetRealizedContainers().Any(),"Dropdown does not populate RC1 choices.");resolution.IsDropDownOpen=false;
        Control<ComboBox>("InternalResolution").SelectedIndex=2;
        Check(window.Settings.InternalResolution==4,"Resolution selector does not reach shared settings.");
        window.ShowPage("Audio");Dispatcher.UIThread.RunJobs();
        var music=Control<Slider>("MusicVolume");
        var track=music.GetVisualDescendants().OfType<Track>().First();track.Value=37;
        Check(music.Value==37,"Dragging the audio track does not update its slider.");
        Dispatcher.UIThread.RunJobs();
        Check(track.Orientation==Avalonia.Layout.Orientation.Horizontal&&track.DecreaseButton!.Bounds.Width>0&&track.DecreaseButton.Bounds.Height>0,"Slider fill track is not laid out horizontally.");
        Check(window.Settings.MusicVolume==37,"Audio slider does not reach shared settings.");
        Control<CheckBox>("Fullscreen").IsChecked=true;
        Check(window.Settings.Fullscreen&&!Control<ComboBox>("WindowSize").IsEnabled,"Fullscreen toggle does not update window controls.");
        Control<ListBox>("GameCasePicker").SelectedIndex=1;
        Check(window.Settings.Game.Id=="file2"&&Control<ListBox>("GamePicker").SelectedIndex==1,"Case and disc selectors lost synchronization.");
        Control<ListBox>("GamePicker").SelectedIndex=0;
        Check(window.Settings.Game.Id=="file1"&&Control<ListBox>("GameCasePicker").SelectedIndex==0,"Disc selection does not update the case.");
        Control<ComboBox>("InternalResolution").SelectedIndex=0;Control<Slider>("MusicVolume").Value=100;Control<CheckBox>("Fullscreen").IsChecked=false;
        Control<Button>("NavGraphics").RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        Check(Control<Control>("PageGraphics").IsVisible&&!Control<Control>("PagePlay").IsVisible,"RC1 navigation command is not connected.");
        window.Settings.Save();
        Check(Settings.Load(window.Root).MusicVolume==100,"Settings cannot round-trip on this OS.");
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
        Check(window.Settings.ResolvedCoopMode=="host"&&Control<Control>("HostOptions").IsVisible&&!Control<Control>("JoinOptions").IsVisible,"Host mode did not reveal its RC1 controls.");
        using(var bitmap=window.CaptureRenderedFrame())bitmap!.Save(Path.Combine(output,"Coop-host.png"));
        Control<RadioButton>("ModeJoin").IsChecked=true;Dispatcher.UIThread.RunJobs();
        Check(window.Settings.ResolvedCoopMode=="join"&&Control<Control>("JoinOptions").IsVisible&&!Control<Control>("HostOptions").IsVisible,"Join mode did not reveal its RC1 controls.");
        using(var bitmap=window.CaptureRenderedFrame())bitmap!.Save(Path.Combine(output,"Coop-join.png"));
        Control<RadioButton>("ModeOffline").IsChecked=true;
        window.ShowPage("Setup");var developer=Control<Expander>("DeveloperFiles");developer.IsExpanded=true;Dispatcher.UIThread.RunJobs();
        Check(developer.GetVisualDescendants().OfType<Border>().Any(b=>b.Name=="OptionsBody"&&b.IsVisible&&b.Bounds.Height>0),"RC1 expandable section did not open.");developer.IsExpanded=false;
        bool mediaChecked=false;
        string? ffmpeg=null;try{ffmpeg=PlatformServices.Ffmpeg();}catch(IOException){}
        if(ffmpeg!=null) {
            string clip=Path.Combine(Path.GetFullPath(output),"decoder-fixture.avi");
            var start=new ProcessStartInfo(ffmpeg){UseShellExecute=false,RedirectStandardError=true};
            foreach(string argument in new[]{"-hide_banner","-loglevel","error","-y","-f","lavfi","-i","testsrc2=size=64x64:rate=10","-t","1","-c:v","mpeg4",clip})start.ArgumentList.Add(argument);
            using(var child=Process.Start(start)!) {string error=child.StandardError.ReadToEnd();Check(child.WaitForExit(15000)&&child.ExitCode==0,"Bundled FFmpeg fixture failed: "+error);}
            using var surface=new VideoSurface();int frames=0;surface.FrameReady+=()=>frames++;surface.Play([clip]);
            var timer=Stopwatch.StartNew();while(frames<3&&timer.Elapsed.TotalSeconds<15){Dispatcher.UIThread.RunJobs();Thread.Sleep(10);}
            Check(frames>=3&&surface.HasVideo,"Background-video worker did not decode frames.");surface.Stop();Check(!surface.HasVideo,"Stopped video retained its frame.");mediaChecked=true;
        }
        File.WriteAllText(Path.Combine(output,"visual-brushes.txt"),string.Join("\n",window.GetVisualDescendants().OfType<Avalonia.Controls.Control>().Select(c=>$"{c.GetType().Name} {c.Name} {c.Bounds} bg={c.GetValue(TemplatedControl.BackgroundProperty)}")));
        window.Close();
        File.WriteAllText(Path.Combine(output,"report.json"),JsonSerializer.Serialize(new{passed=true,pages=12,checks,mediaChecked}));
        return 0;
    }
}
