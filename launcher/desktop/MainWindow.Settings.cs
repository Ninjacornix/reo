using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Primitives;
using Avalonia.Input;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Threading;
using System.Diagnostics;
using System.Globalization;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    record RoomChoice(int Value,string Label);
    void InitializeSettings() {
        WindowSize.ItemsSource=DisplayOptions.MenuSizes;WindowSize.SelectedItem=DisplayOptions.Size(Settings.WindowSize);
        WindowSize.SelectionChanged+=(_,_)=>{if(WindowSize.SelectedItem is OutputSize size)Settings.WindowSize=Array.IndexOf(DisplayOptions.Sizes,size);Changed();};
        Choice(AspectRatio,Array.IndexOf(DisplayOptions.AspectChoices,(Settings.ResolvedAspect,Settings.ResolvedWidescreen)),index=>{
            var value=DisplayOptions.AspectChoices[Math.Clamp(index,0,6)];Settings.AspectRatio=value.Aspect;Settings.WidescreenCamera=value.Widescreen;
        });
        Choice(ScreenFit,Array.IndexOf(DisplayOptions.Fits,Settings.ResolvedFit),i=>Settings.ScreenFit=DisplayOptions.Fits[Math.Clamp(i,0,3)]);
        Choice(Filter,Settings.LinearFilter?0:1,i=>Settings.LinearFilter=i==0);
        Choice(TextureFilter,Settings.TextureLinear?1:0,i=>Settings.TextureLinear=i==1);
        Choice(InternalResolution,Array.IndexOf(DisplayOptions.InternalScales,Settings.ResolvedInternalResolution),i=>Settings.InternalResolution=DisplayOptions.InternalScales[Math.Clamp(i,0,2)]);
        Choice(AnisotropicFilter,Array.IndexOf(new[]{1,2,4,8,16},Settings.ResolvedAnisotropy),i=>Settings.Anisotropy=new[]{1,2,4,8,16}[Math.Clamp(i,0,4)]);
        Choice(AntiAlias,Settings.ResolvedAntiAliasing switch{"fxaa"=>1,"smaa"=>2,_=>0},i=>{Settings.AntiAliasing=i>0;Settings.AntiAliasingMode=new[]{"off","fxaa","smaa"}[Math.Clamp(i,0,2)];});
        Toggle(Fullscreen,Settings.Fullscreen,v=>Settings.Fullscreen=v);
        Toggle(PerformanceOverlay,Settings.PerformanceOverlay,v=>Settings.PerformanceOverlay=v);
        Toggle(AsyncVif,Settings.AsyncVif,v=>Settings.AsyncVif=v);
        Toggle(GpuMovies,Settings.GpuMovies,v=>Settings.GpuMovies=v);
        Range(Brightness,Settings.Brightness,v=>Settings.Brightness=(int)Math.Round(v));
        Range(Gamma,Settings.Gamma,v=>Settings.Gamma=Math.Round(v,2));
        foreach(var (name,get,set) in new (string,Func<int>,Action<int>)[]{
            ("MasterVolume",()=>Settings.MasterVolume,v=>Settings.MasterVolume=v),
            ("MusicVolume",()=>Settings.MusicVolume,v=>Settings.MusicVolume=v),
            ("SfxVolume",()=>Settings.SfxVolume,v=>Settings.SfxVolume=v),
            ("VoiceVolume",()=>Settings.VoiceVolume,v=>Settings.VoiceVolume=v),
            ("UiVolume",()=>Settings.UiVolume,v=>Settings.UiVolume=v)})
            Range(this.FindControl<Slider>(name)!,get(),v=>set((int)Math.Round(v)));
        Toggle(AudioSubtitles,Settings.ShowSubtitles,v=>Settings.ShowSubtitles=v);
        RefreshAudioOutputs();
        AudioOutputPicker.SelectionChanged+=(_,_)=>{if(AudioOutputPicker.SelectedItem is AudioOutput output){Settings.AudioOutputId=output.Id;Settings.AudioOutputName=output.Name;Changed();}};
        Toggle(RumbleSwitch,Settings.RumbleEnabled,v=>Settings.RumbleEnabled=v);
        Toggle(SwapSticks,Settings.Xbox.SwapSticks,v=>CurrentProfile.SwapSticks=v);
        Toggle(InvertRightY,Settings.Xbox.InvertRightY,v=>CurrentProfile.InvertRightY=v);
        Range(DeadZone,Settings.DeadZone,v=>{Settings.DeadZone=CurrentProfile.DeadZone=(int)Math.Round(v);});
        InputDevicePicker.SelectionChanged+=(_,_)=>{
            if(!initialized||InputDevicePicker.SelectedItem is not InputDevice device)return;
            controller.Select(device.Id);Settings.InputDeviceId=device.Id;BuildBindings();Changed();
        };
        Toggle(EnableCheats,Settings.CheatsEnabled,v=>Settings.CheatsEnabled=v);
        Text(AccountUsername,Settings.AccountUsername,v=>Settings.AccountUsername=v.Trim());
        Text(CoopHost,Settings.CoopHost,v=>Settings.CoopHost=v.Trim());
        Text(RoomName,Settings.RoomName,v=>Settings.RoomName=v.Trim());
        Toggle(AutoLobby,Settings.AutoLobby,v=>Settings.AutoLobby=v);
        Toggle(AutoForward,Settings.AutoForward,v=>Settings.AutoForward=v);
        AutoForward.IsEnabled=OperatingSystem.IsWindows();
        if(!OperatingSystem.IsWindows())ToolTip.SetTip(AutoForward,"Configure router port forwarding manually on this OS.");
        foreach(var mode in new[]{ModeOffline,ModeHost,ModeJoin}) {
            mode.IsChecked=(string?)mode.Tag==Settings.ResolvedCoopMode;
            mode.IsCheckedChanged+=(_,_)=>{if(mode.IsChecked==true){Settings.CoopMode=(string?)mode.Tag;if(Settings.ResolvedCoopMode!="host"&&!game.Running&&server.Running)StopHostedServer();Changed();RefreshOnline();}};
        }
        RoomPlayers.ItemsSource=new[]{new RoomChoice(2,"2 players"),new RoomChoice(3,"3 players"),new RoomChoice(4,"4 players")};Choice(RoomPlayers,Settings.ResolvedRoomMaxPlayers-2,i=>Settings.RoomMaxPlayers=i+2);
        RoomWait.ItemsSource=LobbySettings.WaitTimes(Settings.Game.Id).Select(n=>new RoomChoice(n,n+" minutes")).ToArray();Choice(RoomWait,Array.IndexOf(LobbySettings.WaitTimes(Settings.Game.Id),Settings.ResolvedRoomWaitMinutes),i=>Settings.RoomWaitMinutes=LobbySettings.WaitTimes(Settings.Game.Id)[Math.Clamp(i,0,LobbySettings.WaitTimes(Settings.Game.Id).Length-1)]);
        SignupPortBox.Text=Settings.SignupPort.ToString();GamePortBox.Text=Settings.GamePort.ToString();
        SignupPortBox.LostFocus+=(_,_)=>ReadPorts();GamePortBox.LostFocus+=(_,_)=>ReadPorts();
        Toggle(LauncherBackgroundMovies,Settings.LauncherBackgroundMovies,v=>{Settings.LauncherBackgroundMovies=v;RefreshBackdrop();});
        Choice(LauncherFontPicker,Settings.ResolvedLauncherFont switch{"segoe-ui"=>1,"tahoma"=>2,_=>0},i=>{Settings.LauncherFont=new[]{"outbreak","segoe-ui","tahoma"}[Math.Clamp(i,0,2)];ApplyFont();});
        LauncherLanguagePicker.SelectedIndex=0;
        Toggle(DevNetworkTrace,Settings.Developer.NetworkTrace,v=>Settings.Developer.NetworkTrace=v);
        Toggle(DevTransportLog,Settings.Developer.TransportLog,v=>Settings.Developer.TransportLog=v);
        Toggle(DevSnapTrace,Settings.Developer.SnapTrace,v=>Settings.Developer.SnapTrace=v);
        Toggle(DevFrameTiming,Settings.Developer.FrameTiming,v=>Settings.Developer.FrameTiming=v);
        Toggle(DevGameClock,Settings.Developer.GameClock,v=>Settings.Developer.GameClock=v);
        Toggle(UseGamePakSwitch,Settings.UsesGamePak(),v=>{Settings.SetGamePak(v);RefreshUi();});
        Toggle(ExportOriginalAssets,Settings.WantsOriginalAssetPaks(Settings.Game.Id),v=>Settings.SetOriginalAssetExport(v));
        foreach(var picker in new[]{GameCasePicker,GamePicker}) {
            picker.SelectedValue=Settings.SelectedGame;
            picker.SelectionChanged+=(_,_)=>{
                if(!initialized||busy||game.Running||picker.SelectedValue is not string id)return;
                Settings.SelectedGame=id;if(server.Running&&server.GameId!=id)StopHostedServer();GameCasePicker.SelectedValue=GamePicker.SelectedValue=id;
                Changed();RefreshUi();RefreshCards();RefreshMods();RefreshCheats();RefreshBackdrop();
            };
        }
        KeyDown+=(_,e)=>CaptureKey(e,true);KeyUp+=(_,e)=>CaptureKey(e,false);
    }
    void Choice(ComboBox widget,int selected,Action<int> set) {
        widget.SelectedIndex=Math.Max(0,selected);
        widget.SelectionChanged+=(_,_)=>{if(!initialized||widget.SelectedIndex<0)return;set(widget.SelectedIndex);Changed();};
    }
    void Toggle(ToggleButton widget,bool value,Action<bool> set) {
        widget.IsChecked=value;widget.IsCheckedChanged+=(_,_)=>{if(!initialized)return;set(widget.IsChecked==true);Changed();};
    }
    void Range(Slider widget,double value,Action<double> set) {
        widget.Value=value;widget.ValueChanged+=(_,_)=>{if(!initialized)return;set(widget.Value);Changed();};
    }
    void Text(TextBox widget,string value,Action<string> set) {
        widget.Text=value;widget.TextChanged+=(_,_)=>{if(!initialized)return;set(widget.Text??"");Changed();};
    }
    void Changed() {
        if(!initialized)return;
        saveTimer.Stop();saveTimer.Start();controller.Configure(Settings);
        audio?.Publish(Settings);subtitles?.Publish(Settings.ShowSubtitles);
        if(game.Running&&game.Logs is {} logs&&!OperatingSystem.IsWindows())PlatformRuntime.PublishLive(logs,Settings);
        UpdateLabels();RefreshSummary();RefreshOnline();
    }
    void TrySave(){try{Settings.Save();}catch(IOException e){Notify("Settings could not be saved",e.Message);}}
    void RefreshAudioOutputs() {
        AudioOutputPicker.ItemsSource=OperatingSystem.IsWindows()?AudioOutputs.Choices(AudioOutputs.Enumerate(),Settings.AudioOutputId,Settings.AudioOutputName):new[]{new AudioOutput("","System default",true)};
        AudioOutputPicker.SelectedValue=Settings.AudioOutputId;
    }
    void ReadPorts() {
        if(!int.TryParse(SignupPortBox.Text,out int signup)||!int.TryParse(GamePortBox.Text,out int port)||HostNetworking.PortError(signup,port) is {} error){Notify("Ports","Enter valid, distinct hosting ports above 1023.");return;}
        Settings.SignupPort=signup;Settings.GamePort=port;HostNetworking.Current=new(signup,port);Changed();
    }
    void UpdateLabels() {
        foreach(string name in new[]{"MasterVolume","MusicVolume","SfxVolume","VoiceVolume","UiVolume"})
            this.FindControl<TextBlock>(name+"Value")!.Text=$"{this.FindControl<Slider>(name)!.Value:0}%";
        BrightnessValue.Text=$"{Settings.Brightness}%";GammaValue.Text=Settings.Gamma.ToString("F2",CultureInfo.CurrentCulture);
        AudioEditionLabel.Text=Settings.Game.Id=="file1"?"OUTBREAK / FILE #1":"OUTBREAK / FILE #2";
        AudioChannelNote.Text="VOLUME BALANCE";WindowSize.IsEnabled=!Settings.Fullscreen;
        AspectRatio.IsEnabled=Settings.ResolvedFit!="stretch";
        if(this.FindControl<TextBlock>("ScreenFitHint") is {} hint)hint.Text=Settings.ResolvedFit switch{"stretch"=>"Fills the window. Picture proportions follow the window size.","center"=>"Keeps the original pixel height, centered. Shrinks only when needed to fit.","fill"=>"Fills the window at the selected ratio. Edges may be cropped.",_=>"Centers the picture at the selected ratio, with black borders where needed."};
    }
    void RefreshSummary() {
        PlayNetworkSummary.Text=Settings.ResolvedCoopMode=="offline"?"Single player":!OnlineOptions.Configured(Settings)?"Co-op not set up yet (see Co-op)":Settings.ResolvedCoopMode=="host"?(server.Running?"Hosting at "+server.Address:"Hosting (opening your game...)"):"Joining "+Settings.CoopHost;
        PlayDisplaySummary.Text =
            (Settings.Fullscreen ? "Borderless" : DisplayOptions.Size(Settings.WindowSize).Name) +
            " / " +
            (Settings.ResolvedFit == "stretch"
                 ? "Stretched"
                 : Settings.ResolvedAspect + (Settings.ResolvedAspect == "4:3" ? "" : Settings.ResolvedWidescreen ? " widescreen" : " stretched") +
                       " " + DisplayOptions.FitName(Settings.ResolvedFit)) +
            " / " + (Settings.LinearFilter ? "Bilinear" : "Nearest");
        PlayInputSummary.Text=controller.SelectedDevice.Name;
        PlayModsSummary.Text=ModsSummary();
        PlayCheatsSummary.Text=CheatsSummary();
        SessionSummary.Text="GPU rendering / "+controller.SelectedDevice.Name;
    }
}
