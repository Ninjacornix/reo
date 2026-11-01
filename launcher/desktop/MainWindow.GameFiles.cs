using Avalonia.Controls;
namespace Outbreak.Launcher.Desktop;
public partial class MainWindow {
    readonly Dictionary<string,(long Length,long Ticks,string Result)> discChecks=[];
    string checkingSource="";
    void RefreshGameFiles() {
        string executable=Settings.GetExe(),source=Settings.GetGameSource();bool idle=!busy&&!game.Running;
        GameFilesEdition.Text=Settings.Game.Id=="file2"?"FILE #2":"FILE #1";
        SelectedBuildPath.Text=executable;GameFilesBuildState.Text=File.Exists(executable)?"Build available":"No build selected";
        DiscFileActions.IsEnabled=BuildFileActions.IsEnabled=GameRemovalControls.IsEnabled=DeveloperFiles.IsEnabled=idle;
        OriginalAssetOptions.IsEnabled=idle;UseGamePakSwitch.IsEnabled=idle;
        SupportedDiscHint.Text=Settings.UsesGamePak()?"Choose a complete game PAK exported by this launcher. The first launch prepares a local game-data cache; the ISO is not needed. Older asset-only PAKs need to be re-exported.":DiscValidation.RequiredFor(Settings.Game.Id)+" PAL, Japanese and other revisions are unsupported.";
        ExistingBuildHint.Text="Choose a compatible native game build for this OS. Keep its libraries and shaders together. Your selected ISO or game PAK is still required.";
        bool imported=DiscImport.Ready(Settings);
        ImportState.Text=imported?"Game data imported.":File.Exists(source)?"Import prepares verified game files in the local data folder.":Settings.UsesGamePak()?"Choose PAK to start setup.":"Choose ISO to start setup. "+DiscValidation.RequiredFor(Settings.Game.Id);
        ImportDiscButton.Content=File.Exists(executable)?"Import game data":"Import and build";
        if(File.Exists(source)) {
            var file=new FileInfo(source);string key=Settings.Game.Id+"|"+file.FullName;
            if(discChecks.TryGetValue(key,out var check)&&check.Length==file.Length&&check.Ticks==file.LastWriteTimeUtc.Ticks)DiscValidationStatus.Text=check.Result;
            else {DiscValidationStatus.Text="Checking game source...";if(checkingSource!=key)_ = CheckSource(key,file,Settings.Game);}
        }else DiscValidationStatus.Text="";
    }
    async Task CheckSource(string key,FileInfo file,GameDefinition edition) {
        checkingSource=key;long length=file.Length,ticks=file.LastWriteTimeUtc.Ticks;string result;
        try {
            result=await Task.Run(()=>{if(file.Extension.Equals(".pak",StringComparison.OrdinalIgnoreCase)){GamePaks.Check(file.FullName,edition.Id);return "Verified game PAK: "+edition.Name;}using var disc=new DiscImage(file.FullName);return DiscValidation.Check(disc,edition,DiscImport.ExpectedElf(edition.Id),lifetime.Token).Description;},lifetime.Token);
            result="✓ "+result;
        }catch(Exception error)when(error is IOException or UnauthorizedAccessException or System.Text.Json.JsonException){result="✗ "+error.Message;}
        catch(OperationCanceledException){return;}
        finally{if(checkingSource==key)checkingSource="";}
        if(closed)return;discChecks[key]=(length,ticks,result);RefreshGameFiles();
    }
}
