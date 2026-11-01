using Avalonia;
using Avalonia.Controls;
using Avalonia.Platform.Storage;
using Avalonia.Media;
using System.Diagnostics;
using System.Text.Json;
using Outbreak.Launcher.Desktop.Compatibility;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    MemoryCardOption? cardToDelete;
    void RefreshCards() {
        if(!initialized)return;
        var selected=Settings.CardFolder(Root);
        CardSelection.ItemsSource=Settings.CardOptions(Root);
        CardSelection.SelectedItem=Settings.CardOptions(Root).FirstOrDefault(c=>Path.GetFullPath(c.Folder)==selected);
        RefreshCardDetails();
    }
    void RefreshCardDetails() {
        CardPath.Text=Settings.CardFolder(Root);SelectedCardName.Text=(CardSelection.SelectedItem as MemoryCardOption)?.Name??"Current memory card";
        try {int count=Directory.Exists(CardPath.Text)?Directory.EnumerateFiles(CardPath.Text,"*",SearchOption.AllDirectories).Count(p=>!Path.GetRelativePath(CardPath.Text,p).Split(Path.DirectorySeparatorChar).Any(part=>part.StartsWith(".reo-",StringComparison.Ordinal))):0;SaveCount.Text=count==0?"Empty card":$"{count} {(count==1?"file":"files")} stored";}
        catch(IOException){SaveCount.Text="Card files are unavailable.";}
        CardControls.IsEnabled=!busy&&!game.Running;CardBusyHint.IsVisible=busy||game.Running;
        DeleteCardButton.IsEnabled=CardSelection.SelectedItem is MemoryCardOption card&&Path.GetFullPath(card.Folder)!=Path.GetFullPath(Settings.DefaultCardFolder(Root));
    }
    void CreateCard() {
        if(busy||game.Running)throw new IOException("Stop the game before creating a card.");
        var card=MemoryCards.Create(NewCardName.Text??"");Settings.MemoryCards.Add(card);Settings.SelectCard(card.Folder);Settings.Save();NewCardName.Text="";RefreshCards();
    }
    async Task BrowseCard() {
        if(game.Running||busy)throw new IOException("Stop the game before switching cards.");
        var folders=await StorageProvider.OpenFolderPickerAsync(new(){Title="Choose memory-card folder",AllowMultiple=false});
        if(folders.FirstOrDefault()?.TryGetLocalPath() is {} path) {
            var card=new MemoryCardOption(Path.GetFileName(path),path);Settings.MemoryCards.Add(card);Settings.SelectCard(path);Settings.Save();RefreshCards();
        }
    }
    async Task BackupCard() {
        var file=await StorageProvider.SaveFilePickerAsync(new(){Title="Back up memory card",SuggestedFileName="Outbreak-card-"+DateTime.Now.ToString("yyyyMMdd-HHmmss")+".zip",FileTypeChoices=[new("ZIP archive"){Patterns=["*.zip"]}]});
        if(file?.TryGetLocalPath() is {} path)await RunOperation((_,_)=>Task.Run(()=>MemoryCards.Backup(Settings.CardFolder(Root),path)));
    }
    void AskDeleteCard() {
        if(CardSelection.SelectedItem is not MemoryCardOption card||!DeleteCardButton.IsEnabled)return;
        cardToDelete=card;bool recycle=MemoryCards.CanRecycle(card.Folder);
        DeleteCardQuestion.Text=recycle?$"Move “{card.Name}” and its save data to the {(OperatingSystem.IsWindows()?"Recycle Bin":"Trash")}?":$"Remove “{card.Name}” from the launcher? Its folder and save data will be kept.";
        ConfirmDeleteCardButton.Content=recycle?(OperatingSystem.IsWindows()?"Move to Recycle Bin":"Move to Trash"):"Remove card";
        DeleteCardPanel.IsVisible=true;CancelDeleteCardButton.Focus();
    }
    void DeleteCard() {
        if(cardToDelete==null||busy||game.Running)return;
        MemoryCards.DeleteProfile(Settings,Root,cardToDelete);cardToDelete=null;DeleteCardPanel.IsVisible=false;RefreshCards();
    }
    void StopHostedServer() {
        lan?.Dispose();lan=null;server.Dispose();if(OperatingSystem.IsWindows())_ = HostNetworking.ClosePorts();
    }
    void RefreshOnline() {
        bool host=Settings.ResolvedCoopMode=="host",join=Settings.ResolvedCoopMode=="join";
        CoopControls.IsEnabled=!busy&&!game.Running;
        CoopUnavailable.IsVisible=false;
        OnlinePanel.IsVisible=host||join;OfflinePanel.IsVisible=!host&&!join;
        HostOptions.IsVisible=host;JoinOptions.IsVisible=join;RoomSettings.IsVisible=host;
        RoomSettings.IsEnabled=Settings.AutoLobby;
        if(RoomName.Parent is Grid room)foreach(var placeholder in room.Children.OfType<TextBlock>())placeholder.IsVisible=string.IsNullOrEmpty(RoomName.Text);
        CopyServerButton.IsEnabled=server.Running;
        if(!OperatingSystem.IsWindows())FirewallButton.Content="Open network settings";
        string? error=OnlineOptions.Error(Settings);
        CoopValidation.Text=error??"";CoopValidation.IsVisible=error!=null;
        HostStatus.Text=server.Running?"Your game is open for friends":"";
        HostDetail.Text=server.Running?"Share this address: "+server.Address:"";
        StartServerButton.Content=server.Running?"Stop server":"Start server";
        if(HostAddressPicker.ItemCount==0) {
            var addresses=HostNetworking.LocalAddresses();HostAddressPicker.ItemsSource=addresses;
            HostAddressPicker.SelectedItem=addresses.FirstOrDefault(a=>a.Address==Settings.HostAddress)??addresses.FirstOrDefault();
        }
    }
    LobbyAutomation.Options CreateLobbyOptions()=>new(Settings.ResolvedCoopMode=="host",Settings.ResolvedRoomName,Settings.CoopHost,
        ready=>roomReady=ready,Settings.Game.Id,Settings.ResolvedRoomMaxPlayers,Settings.ResolvedRoomWaitMinutes);
    bool roomReady;
    async Task StartServer() {
        if(server.Running){if(game.Running)throw new IOException("Stop your game before stopping its server.");lan?.Dispose();lan=null;server.Dispose();if(OperatingSystem.IsWindows())await HostNetworking.ClosePorts();RefreshOnline();return;}
        string address=Settings.HostAddress.Length>0?Settings.HostAddress:HostedServer.SuggestedAddress();Settings.CoopHost=address;
        HostNetworking.Current=new(Settings.SignupPort,Settings.GamePort);
        await server.Start(Root,address,lifetime.Token,progress:new Progress<string>(text=>Notify("Hosting",text)),game:Settings.Game.Id);
        if(OperatingSystem.IsWindows()&&Settings.AutoForward){var forwarding=await HostNetworking.OpenPorts(address);Notify("Router ports",forwarding.Message);}
        lan?.Dispose();lan=new(()=>new LanDiscovery.Game(Settings.AccountUsername,address,"1.0.20-rc1",roomReady,Settings.SignupPort,Settings.Game.Id,Settings.ResolvedRoomName),()=>game.HostRandomizerConfiguration);
        Settings.Save();RefreshOnline();Notify("Hosting",address);
    }
    async Task FindHosts() {
        var games=await LanDiscovery.Search(TimeSpan.FromSeconds(2),lifetime.Token,Settings.Game.Id);
        // The existing RC1 host list is rebuilt with the same labels/actions.
        if(this.FindControl<StackPanel>("FoundGames") is {} list) {
            list.Children.Clear();
            foreach(var host in games){var button=new Button{Content=host.Name+" / "+host.Address};button.Click+=(_,_)=>{Settings.CoopHost=host.Address;Settings.JoinSignupPort=host.Signup;CoopHost.Text=host.Address;Changed();};list.Children.Add(button);}
        }
        Notify("LAN games",games.Count==0?"No hosts found.":games.Count+" host(s) found.");
    }
    record LogSession(string Name,string Directory);
    string? manualLog;
    void RefreshLogs() {
        string root=Path.Combine(Settings.Home,"sessions");
        var folders=Directory.Exists(root)?Directory.GetDirectories(root).OrderDescending().ToArray():[];
        string? previous=(LogSessionPicker.SelectedItem as LogSession)?.Directory;
        var sessions=folders.Take(40).Select(folder=>new LogSession(Path.GetFileName(folder),folder)).ToArray();
        LogSessionPicker.ItemsSource=sessions;LogSessionPicker.SelectedItem=sessions.FirstOrDefault(s=>s.Directory==(game.Logs??previous))??sessions.FirstOrDefault();
        if(LogStreamPicker.ItemsSource==null)LogStreamPicker.Items.Clear();
        LogStreamPicker.ItemsSource=new[]{"Game debug","Game output"};LogStreamPicker.SelectedIndex=0;LoadLog();
    }
    void LoadLog() {
        string? path=manualLog??(LogSessionPicker.SelectedItem is LogSession session?Path.Combine(session.Directory,LogStreamPicker.SelectedIndex==1?"stdout.log":"stderr.log"):null);
        bool available=path!=null&&File.Exists(path);LogEmpty.IsVisible=!available;
        LogInfo.Text=path??"";LogFollowState.Text=FollowLog.IsChecked==true?"Following":"Paused";
        OpenLogFolderButton.IsEnabled=available;
        if(!available){DebugLog.Text="";return;}
        var file=new FileInfo(path!);using var stream=file.Open(FileMode.Open,FileAccess.Read,FileShare.ReadWrite|FileShare.Delete);
        stream.Position=Math.Max(0,stream.Length-128*1024);using var reader=new StreamReader(stream);string text=reader.ReadToEnd();
        if(DebugLog.Text!=text){DebugLog.Text=text;if(FollowLog.IsChecked==true)DebugLog.CaretIndex=text.Length;}
    }
    async Task BrowseLog() {
        var files=await StorageProvider.OpenFilePickerAsync(new(){Title="Open log",AllowMultiple=false});
        if(files.FirstOrDefault()?.TryGetLocalPath() is {} path){manualLog=path;LoadLog();}
    }
    async Task CheckUpdates() {
        UpdateState.Text="Checking for updates…";
        try {
            using var client=Updates.Client();string json=await client.GetStringAsync(Updates.LatestApi,lifetime.Token);
            using var doc=JsonDocument.Parse(json);string tag=doc.RootElement.GetProperty("tag_name").GetString()??"";
            var assets=doc.RootElement.GetProperty("assets").EnumerateArray();
            string platform=OperatingSystem.IsWindows()?"Windows":OperatingSystem.IsMacOS()?"macOS":"Linux";
            bool compatible=assets.Any(a=>(a.GetProperty("name").GetString()??"").Contains(platform,StringComparison.OrdinalIgnoreCase));
            UpdateState.Text=compatible?$"Available release: {tag}":$"No {platform} package is published for {tag}.";
        }catch(HttpRequestException e){UpdateState.Text="Update check failed: "+e.Message;}
    }
    async Task ExportAssets()=>await RunOperation(async(progress,cancel)=>{
        var disc=await Settings.PrepareGame(progress,cancel);Settings.SetImport(disc.Root);
        var export=await AssetExports.Ensure(disc,Settings.Game.Id,progress,cancel);Settings.RememberGamePak(export);
    });
    async Task CleanImports() {
        var candidates=await Task.Run(()=>StaleImports.Find(Settings,Settings.Game.Id));
        if(candidates.Count==0){Notify("Imports","No old imports to remove.");return;}
        if(await Confirm("Clean old imports?",$"Remove {candidates.Count} verified stale imports? The current import and original ISO are kept."))
            await RunOperation((_,_)=>Task.Run(()=>StaleImports.Remove(candidates,Settings,Settings.Game.Id)));
    }
    async Task ChangeStorage() {
        if(busy||game.Running)throw new IOException("Stop the game before changing storage.");
        var folders=await StorageProvider.OpenFolderPickerAsync(new(){Title="Choose launcher data folder",AllowMultiple=false});
        if(folders.FirstOrDefault()?.TryGetLocalPath() is not {} path)return;
        string current=Settings.Home;
        if(!await Confirm("Move launcher data?","Copy saves, settings and managed data to "+path+"? The previous folder is preserved."))return;
        await RunOperation(async(_,cancel)=>{await Storage.Select(Root,current,path,null,cancel);});
        StoragePath.Text=Settings.Home;
    }
    async Task RemoveSelectedGame() {
        if(busy||game.Running)throw new IOException("Stop the game before removing it.");
        var targets=GameRemoval.Targets(Root,Settings,Settings.Game.Id,RemoveSaves.IsChecked==true,RemoveTools.IsChecked==true);
        if(!await Confirm("Remove game?",string.Join("\n",targets.Select(t=>t.What+": "+t.Path))))return;
        await RunOperation((_,_)=>Task.Run(()=>{var failures=GameRemoval.Remove(targets);if(failures.Count>0)throw new IOException(string.Join("\n",failures));}));
    }
    async Task<bool> Confirm(string title,string message) {
        var dialog=new Window{Title=title,Width=520,Height=250,WindowStartupLocation=WindowStartupLocation.CenterOwner,CanResize=false,Background=new SolidColorBrush(Color.Parse("#141210")),FontFamily=FontFamily};
        var panel=new StackPanel{Margin=new Thickness(24),Spacing=20};panel.Children.Add(new TextBlock{Text=message,TextWrapping=TextWrapping.Wrap});
        var buttons=new StackPanel{Orientation=Orientation.Horizontal,Spacing=12};var cancel=new Button{Content="Cancel"};var proceed=new Button{Content="Continue"};
        cancel.Click+=(_,_)=>dialog.Close(false);proceed.Click+=(_,_)=>dialog.Close(true);buttons.Children.Add(cancel);buttons.Children.Add(proceed);panel.Children.Add(buttons);dialog.Content=panel;
        return await dialog.ShowDialog<bool>(this);
    }
}
