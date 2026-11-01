using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Input;
using Avalonia.Interactivity;
using Avalonia.Media;
using Avalonia.Platform;
using Avalonia.Platform.Storage;
using Avalonia.Threading;
using System.Diagnostics;
using System.Text.Json;
using Outbreak.Launcher.Desktop.Compatibility;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    readonly HostedServer server=new();
    LanDiscovery.Responder? lan;
    CancellationTokenSource? importCancellation;
    Dictionary<string,string> commands=[];
    readonly Stopwatch uiClock=Stopwatch.StartNew();
    int slowTick;
    bool wasRunning;
    string lastNetworkStatus="";
    public object FindResource(string name)=>new[]{"Hint","ModOption","CheatOption","ModOptionsDropdown","ControllerBindingButton","Section"}.Contains(name)
        ?new Compatibility.Style(name):this.TryFindResource(name,out var value)?value!:throw new KeyNotFoundException(name);
    void InitializeCommands() {
        using var stream=AssetLoader.Open(new Uri("avares://Outbreak.Launcher/Views/Shell.reference.json"));
        using var doc=JsonDocument.Parse(stream);
        commands=doc.RootElement.GetProperty("actions").EnumerateObject().Where(p=>p.Value.TryGetProperty("Click",out _))
            .ToDictionary(p=>p.Name,p=>p.Value.GetProperty("Click").GetString()!);
        AddHandler(Button.ClickEvent,async(_,e)=>{
            if(e.Source is not Button {Name:{} name} button||!commands.TryGetValue(name,out string? command))return;
            try{await Command(command,button);}catch(OperationCanceledException){Notify("Canceled","Completed work and existing data are preserved.");}
            catch(Exception error){Notify("Could not complete operation",error.Message);}
        });
        Status.PropertyChanged+=(_,e)=>{if(e.Property==TextBlock.TextProperty&&!string.IsNullOrWhiteSpace(Status.Text))Notify("Outbreak",Status.Text!);};
        StatusToast.PointerReleased+=(_,_)=>StatusToast.IsVisible=false;
        CardSelection.SelectionChanged+=(_,_)=>{if(CardSelection.SelectedItem is MemoryCardOption card){Settings.SelectCard(card.Folder);Changed();RefreshCardDetails();}};
        LogSessionPicker.SelectionChanged+=(_,_)=>{manualLog=null;LoadLog();};LogStreamPicker.SelectionChanged+=(_,_)=>{manualLog=null;LoadLog();};
        NewCardName.KeyDown+=async(_,e)=>{if(e.Key==Key.Enter)await Command("CreateCard",CreateCardButton);};
        HostAddressPicker.SelectionChanged+=(_,_)=>{if(HostAddressPicker.SelectedItem is HostNetworking.LocalAddress address){Settings.HostAddress=address.Address;Settings.CoopHost=address.Address;Changed();}};
        Point origin=default;float startYaw=0,startPitch=0;bool rotate=false;
        GraphicsGpuView.PointerPressed+=(_,e)=>{rotate=true;origin=e.GetPosition(GraphicsGpuView);startYaw=previewYaw;startPitch=previewPitch;e.Pointer.Capture(GraphicsGpuView);};
        GraphicsGpuView.PointerMoved+=(_,e)=>{if(!rotate)return;var p=e.GetPosition(GraphicsGpuView);previewYaw=startYaw+(float)(p.X-origin.X)*.5f;previewPitch=Math.Clamp(startPitch+(float)(p.Y-origin.Y)*.35f,-70,70);nextPreview=0;};
        GraphicsGpuView.PointerReleased+=(_,e)=>{rotate=false;e.Pointer.Capture(null);};
        GraphicsGpuView.PointerWheelChanged+=(_,e)=>{previewZoom=Math.Clamp(previewZoom*(float)Math.Pow(1.1,e.Delta.Y),.4f,3);nextPreview=0;e.Handled=true;};
    }
    async Task Command(string command,Button sender) {
        switch(command) {
            case "Navigate":ShowPage(sender.Tag as string??sender.Name![3..]);break;
            case "LaunchGame":await Launch();break;
            case "StopGame":if(game.Process is {} process)await PlatformRuntime.Stop(process);break;
            case "NextStepClicked":ShowPage("Setup");break;
            case "BrowseFile":await BrowseFile(sender.Tag as string??"iso");break;
            case "ImportDisc":await Import();break;
            case "UseExistingBuild":await BrowseFile("exe");break;
            case "CancelImport":importCancellation?.Cancel();break;
            case "CancelServerSetup":importCancellation?.Cancel();server.Dispose();break;
            case "ResetColor":Brightness.Value=100;Gamma.Value=1;break;
            case "ResetAudio":foreach(string name in new[]{"MasterVolume","MusicVolume","SfxVolume","VoiceVolume","UiVolume"})this.FindControl<Slider>(name)!.Value=100;break;
            case "ShowBindings":InputBindingsPanel.IsVisible=true;InputLayoutPanel.IsVisible=false;BuildBindings();break;
            case "ShowInputLayout":InputBindingsPanel.IsVisible=false;InputLayoutPanel.IsVisible=true;break;
            case "ResetBindings":ResetBindings();break;
            case "ClearCapturedBinding":ClearCapturedBinding(sender,new());break;
            case "CancelCapture":CancelCapture(sender,new());break;
            case "CreateCard":CreateCard();break;
            case "BrowseCard":await BrowseCard();break;
            case "BackupSaves":await BackupCard();break;
            case "OpenSaves":OpenPath(Settings.CardFolder(Root));break;
            case "AskDeleteCard":AskDeleteCard();break;
            case "ConfirmDeleteCard":DeleteCard();break;
            case "CancelDeleteCard":DeleteCardPanel.IsVisible=false;break;
            case "ImportMod":ImportMod(sender,new());break;
            case "ReloadMods":RefreshMods();break;
            case "OpenModFolder":OpenModFolder(sender,new());break;
            case "ImportCheats":ImportCheats(sender,new());break;
            case "ReloadCheats":RefreshCheats();break;
            case "OpenCheatFolder":OpenCheatFolder(sender,new());break;
            case "StartServerClicked":await StartServer();break;
            case "SearchGamesClicked":await FindHosts();break;
            case "CopyServerAddress":if(Clipboard!=null)await Clipboard.SetValueAsync(Avalonia.Input.DataFormat.Text,Settings.HostAddress);break;
            case "ResetPorts":SignupPortBox.Text="10128";GamePortBox.Text="9091";ReadPorts();break;
            case "AllowFirewall":
                if(OperatingSystem.IsWindows()){bool added=await HostNetworking.AddFirewallRules();Notify("Firewall",added?"Hosting rules added.":"Firewall rules were not added.");}
                else OpenPath(OperatingSystem.IsMacOS()?"x-apple.systempreferences:com.apple.Network-Settings.extension":"https://help.ubuntu.com/community/UFW");break;
            case "OpenSessionFolders":OpenPath(Path.Combine(Settings.Home,"sessions"));break;
            case "OpenLogs":if(LogSessionPicker.SelectedItem is LogSession session)OpenPath(session.Directory);break;
            case "BrowseLog":await BrowseLog();break;
            case "CheckForUpdates":await CheckUpdates();break;
            case "CancelUpdate":importCancellation?.Cancel();break;
            case "OpenStorageFolder":OpenPath(Settings.Home);break;
            case "ChangeStorageFolder":await ChangeStorage();break;
            case "ExportOriginalAssetsClicked":await ExportAssets();break;
            case "OpenOriginalAssetExportsClicked":OpenPath(AssetExports.GameFolder(Settings.Game.Id));break;
            case "CleanOldImports":await CleanImports();break;
            case "RemoveGame":await RemoveSelectedGame();break;
            default:throw new InvalidOperationException("Unknown launcher command: "+command);
        }
    }
    void Tick() {
        controller.Publish();
        if(currentPage=="Controller")UpdateInput();
        if(currentPage=="Graphics")RenderPreview();
        if(++slowTick%30!=0)return;
        bool running=game.Running;
        if(running!=wasRunning){wasRunning=running;controller.SessionEnabled=running;RefreshUi();}
        if(game.NetworkStatus is {} status&&status!=lastNetworkStatus){lastNetworkStatus=status;Notify("Network",status);}
        if(currentPage=="Logs"&&FollowLog.IsChecked==true)LoadLog();
        if(StatusToast.IsVisible&&uiClock.Elapsed.TotalSeconds-toastAt>8)StatusToast.IsVisible=false;
    }
    double toastAt;
    void Notify(string title,string detail) {
        if(closed)return;
        StatusToastTitle.Text=title;StatusToastDetail.Text=detail;StatusToast.Opacity=1;StatusToast.IsVisible=true;toastAt=uiClock.Elapsed.TotalSeconds;
    }
    void RefreshGameUi()=>RefreshUi();
    static string NameList(List<string> names) =>
        names.Count == 0 ? "Off"
        : names.Count <= 2 ? string.Join(", ", names)
                           : $"{names[0]}, {names[1]} +{names.Count - 2} more";
    string ModsSummary() {
        // Guests play with the host's mods; their own selection waits for solo or hosted games.
        if (Settings.ResolvedCoopMode == "join")
            return "Host's choice";
        if (Settings.ActiveMods.Count == 0)
            return "Off";
        try {
            var installed = Mods.Load(null, Settings.Game.Id);
            return NameList(Settings.ActiveMods.Distinct().Select(id =>
                installed.FirstOrDefault(m => m.Manifest?.Id == id)?.Manifest?.Name is { Length: > 0 } name ? name : id).ToList());
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return Settings.ActiveMods.Count + " on";
        }
    }
    string CheatsSummary() {
        if (!Settings.CheatsEnabled || Settings.EnabledCheats.Count == 0)
            return "Off";
        try {
            return NameList(Cheats.Load(Settings.Game.Id).Where(g => Settings.EnabledCheats.Contains(g.Id))
                                .Select(g => g.Name).ToList());
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return "On";
        }
    }
    void RefreshUi() {
        if(!initialized)return;
        bool running=game.Running;
        LaunchButton.Content=Settings.Game.Id=="file2"?"Play File #2":"Play File #1";
        LaunchButton.IsEnabled=!busy&&!running;StopButton.IsEnabled=running;
        GameCasePicker.IsEnabled=GamePicker.IsEnabled=!busy&&!running;
        for(int n=1;n<=2;n++) {
            string id="file"+n;bool available=File.Exists(Settings.GetExe(id))&&File.Exists(Settings.GetGameSource(id));
            var view=this.FindControl<GameCaseView>("GameCase"+n)!;view.IsSelected=id==Settings.Game.Id;view.IsAvailable=available;view.Hold(staticCapture||running||busy);
            var disc=this.FindControl<GameDiscView>("GameDisc"+n)!;disc.IsAvailable=available;disc.IsSelected=id==Settings.Game.Id;disc.Opacity=available?(disc.IsSelected?1:.48):.2;disc.InvalidateVisual();
            this.FindControl<TextBlock>("DiscStatus"+n)!.Text=available?"Ready to play":"Choose your game source";
        }
        bool built=File.Exists(Settings.GetExe()),source=File.Exists(Settings.GetGameSource());
        NextStep.IsVisible=!built||!source;
        NextStepMeasure.Opacity=0;
        NextStepTitle.Text=!built?"No game build found":"Choose your game source";
        NextStepDetail.Text=!built?"Build reo_recomp in this checkout, or choose Use existing build in Game files.":"Select your own game ISO. "+DiscValidation.RequiredFor(Settings.Game.Id);
        NextStepButton.Content=!built?"Game files":"Choose ISO";
        NextStepMeasureTitle.Text="No game build found";NextStepMeasureDetail.Text="Build reo_recomp in this checkout, or choose Use existing build in Game files.";NextStepMeasureButton.Content="Game files";
        IsoPath.Text=Settings.GetGameSource();ExePath.Text=Settings.GetExe();ElfPath.Text=Settings.GetElf(Root);StoragePath.Text=Settings.Home;
        UpdateLabels();RefreshSummary();RefreshOnline();RefreshBackdrop();RefreshGameFiles();
        if(currentPage=="Mods")UpdateModState();if(currentPage=="Cheats")UpdateCheatState();
    }
    async Task RunOperation(Func<IProgress<ImportProgress>,CancellationToken,Task> action) {
        if(busy||game.Running)throw new IOException("Stop the game and wait for the current operation first.");
        busy=true;var progress=BeginDiscImport();RefreshUi();
        try{await action(progress,importCancellation!.Token);TrySave();}
        finally{EndDiscImport();busy=false;RefreshUi();}
    }
    IProgress<ImportProgress> BeginDiscImport() {
        importCancellation=new CancellationTokenSource();ImportActivity.IsVisible=true;
        return new Progress<ImportProgress>(p=>{SetupStage.Text=p.Stage;SetupDetail.Text=p.File;DiscProgress.IsIndeterminate=p.Total==0;DiscProgress.Value=p.Percent;SetupCounts.Text=p.Total>0?$"{p.Completed} / {p.Total}":"";});
    }
    void EndDiscImport(){ImportActivity.IsVisible=false;importCancellation?.Dispose();importCancellation=null;}
    void SetLaunching(bool value){busy=value;RefreshUi();}
    async Task Import()=>await RunOperation(async(progress,cancel)=>{
        var disc=await Settings.PrepareGame(progress,cancel);Settings.SetImport(disc.Root);
        if(Settings.WantsOriginalAssetPaks()){var assets=await AssetExports.Ensure(disc,Settings.Game.Id,progress,cancel);Settings.RememberGamePak(assets);}
        Notify("Game files",disc.Verification);
    });
    async Task Launch() {
        if(busy||game.Running)return;
        busy=true;RefreshUi();
        try {
            if(Settings.ResolvedCoopMode=="host"&&!server.Running)await StartServer();
            var progress=BeginDiscImport();controller.Configure(Settings);
            await game.Launch(Root,Settings,controller,importProgress:progress,cancel:importCancellation!.Token,
                lobby:OperatingSystem.IsWindows()&&Settings.AutoLobby&&Settings.ResolvedCoopMode!="offline"?CreateLobbyOptions():null);
            Settings.Save();Notify("Outbreak","Game started.");
        }finally{EndDiscImport();busy=false;RefreshUi();}
    }
    async Task BrowseFile(string kind) {
        var options=new FilePickerOpenOptions{Title=kind=="iso"?"Choose your game source":"Choose "+kind,AllowMultiple=false};
        if(kind=="iso")options.FileTypeFilter=[new("Game source"){Patterns=Settings.UsesGamePak()?["*.pak"]:["*.iso"]}];
        var selected=await StorageProvider.OpenFilePickerAsync(options);
        if(selected.FirstOrDefault()?.TryGetLocalPath() is not {} path)return;
        if(kind=="iso")Settings.SetGameSource(path);else Settings.SetFile(kind,path);
        Changed();RefreshUi();
    }
    static void OpenPath(string path){if(!Uri.TryCreate(path,UriKind.Absolute,out var uri)||uri.IsFile){if(!File.Exists(path)&&!Directory.Exists(path))Directory.CreateDirectory(path);}Process.Start(new ProcessStartInfo(path){UseShellExecute=true});}
    async void OnClosing(object? sender,WindowClosingEventArgs e) {
        if(busy){e.Cancel=true;importCancellation?.Cancel();Notify("Stopping setup","Completed work is preserved. Close the launcher when setup stops.");return;}
        if(game.Running&&game.Process is {} process){e.Cancel=true;await PlatformRuntime.Stop(process);Close();return;}
        TrySave();
    }
}
