using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Threading;
using System.Diagnostics;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    FontFamily? ownedFont;
    readonly Dictionary<string,IImage> backdrops=[];
    readonly GameScenePreviewRenderer previewRenderer=new();
    GamePreviewScene? previewScene;
    readonly Stopwatch previewClock=Stopwatch.StartNew();
    bool previewBusy;
    long nextPreview;
    float previewYaw,previewPitch,previewZoom=1;
    readonly Dictionary<string,string[]> videos=[];
    CancellationTokenSource? mediaPreparation;
    string preparingMedia="";
    async Task InitializeAssets() {
        try {
            await Storage.Initialize(Root,false,null,lifetime.Token);
            string import=Settings.ImportFolder("file1");
            if(!Directory.Exists(Path.Combine(import,"data")))import=Settings.ImportFolder("file2");
            if(Directory.Exists(Path.Combine(import,"data"))) {
                string edition=import==Settings.ImportFolder("file1")?"file1":"file2";
                string path=await Task.Run(()=>GameFont.Ensure(import,edition,Settings.Home),lifetime.Token);
                ownedFont=OwnedFontCollection.Load(path);
                ApplyFont();
                byte[]? pixels=await Task.Run(()=>GameControllerArtwork.LoadPixels(import,edition),lifetime.Token);
                if(pixels!=null)controllerArtwork=ArtworkLoader.FromBgra(pixels,GameControllerArtwork.Width,GameControllerArtwork.Height);
                BuildBindings();
                previewScene=await Task.Run(()=>GamePreviewAssets.LoadShared(Settings.ImportFolder("file1"),Settings.ImportFolder("file2"),Settings.Home),lifetime.Token);
                if(previewScene!=null){PreviewEmpty.IsVisible=false;GraphicsGpuView.IsVisible=true;GraphicsPreviewState.Text="Live preview";}
            }
        }catch(Exception e)when(e is IOException or ArgumentException or NotSupportedException){Notify("Optional artwork",e.Message);}
        try {
            ArtworkActivity.IsVisible=true;
            using var client=new HttpClient();client.DefaultRequestHeaders.UserAgent.ParseAdd("OutbreakLauncher/1.0 (https://github.com/Ninjacornix/reo)");
            await GameArtwork.DownloadMissing(client,new Progress<GameArtwork.DownloadProgress>(p=>{ArtworkDownloadProgress.Value=p.Percent;ArtworkDownloadDetail.Text=p.Detail;}),lifetime.Token);
        }catch(Exception e)when(e is IOException or HttpRequestException or OperationCanceledException){Debug.WriteLine(e.Message);}
        finally {ArtworkActivity.IsVisible=false;}
        if(closed)return;
        for(int edition=1;edition<=2;edition++) {
            var art=ArtworkLoader.LoadCase(edition,Settings.GetIso("file"+edition));
            var view=this.FindControl<GameCaseView>("GameCase"+edition)!;
            view.Cover=art?.Front;view.BackCover=art?.Back;view.SpineCover=art?.Spine;
            var disc=this.FindControl<GameDiscView>("GameDisc"+edition)!;
            disc.Artwork=ArtworkLoader.LoadDisc(edition,Settings.GetIso("file"+edition));disc.InvalidateVisual();
            if(art!=null)backdrops["file"+edition]=ArtworkLoader.Backdrop(art.Front);
        }
        RefreshBackdrop();RefreshUi();
        _ = PrepareMovies();
    }
    void ApplyFont() {
        FontFamily family=Settings.ResolvedLauncherFont switch{"segoe-ui"=>new("Segoe UI"),"tahoma"=>new("Tahoma"),_=>ownedFont??new("Segoe UI")};
        Resources["GameDisplayFont"]=family;FontFamily=family;
        LauncherFontHint.IsVisible=Settings.ResolvedLauncherFont=="outbreak"&&ownedFont==null;
    }
    void RefreshBackdrop() {
        bool show=currentPage=="Play"&&backdrops.ContainsKey(Settings.Game.Id);
        if(backdrops.TryGetValue(Settings.Game.Id,out var source))Backdrop.Source=source;
        bool active=Settings.LauncherBackgroundMovies&&currentPage=="Play"&&!busy&&!game.Running&&WindowState!=WindowState.Minimized;
        if(active&&videos.TryGetValue(Settings.Game.Id,out var clips))BackgroundMovieA.Play(clips);
        else BackgroundMovieA.Stop();
        if(!active){mediaPreparation?.Cancel();preparingMedia="";}
        bool video=active&&BackgroundMovieA.HasVideo;
        BackgroundScene.IsVisible=currentPage=="Play";ArtworkLayer.IsVisible=show||video;
        ImageBackdropLayer.IsVisible=show&&!video;VideoBackgroundShade.IsVisible=VideoVignette.IsVisible=video;ImageBackgroundShade.IsVisible=!video;
        if(active&&Initialization?.IsCompleted==true&&!videos.ContainsKey(Settings.Game.Id))_ = PrepareMovies();
    }
    async Task PrepareMovies() {
        string edition=Settings.Game.Id,import=Settings.ImportFolder();
        if(!Settings.LauncherBackgroundMovies||busy||game.Running||preparingMedia==edition||videos.ContainsKey(edition)||!File.Exists(Path.Combine(import,"data","NETBIO01.DAT")))return;
        mediaPreparation?.Cancel();var stop=mediaPreparation=CancellationTokenSource.CreateLinkedTokenSource(lifetime.Token);preparingMedia=edition;
        try {
            string folder=BackgroundVideos.Folder(import);
            string[] clips=await BackgroundVideos.ReadCache(folder,edition,stop.Token);
            if(clips.Length==0) {
                string ffmpeg=await BackgroundVideoTool.Ensure(Settings.Home,stop.Token);
                clips=await Task.Run(async()=>{
                    using var archive=File.OpenRead(Path.Combine(import,"data","NETBIO01.DAT"));
                    return await BackgroundVideos.ConvertArchive(archive,new(0,archive.Length),edition,folder,ffmpeg,stop.Token);
                },stop.Token);
            }
            if(!stop.IsCancellationRequested){videos[edition]=clips;RefreshBackdrop();}
        }catch(Exception e)when(e is IOException or OperationCanceledException or System.ComponentModel.Win32Exception){Debug.WriteLine(e.Message);}
        finally{if(mediaPreparation==stop){preparingMedia="";mediaPreparation=null;}stop.Dispose();}
    }
    async void RenderPreview() {
        if(previewBusy||previewScene==null||currentPage!="Graphics"||game.Running||!IsVisible||Stopwatch.GetTimestamp()<nextPreview)return;
        int width=Math.Clamp((int)GraphicsPreviewStage.Bounds.Width,32,1200),height=Math.Clamp((int)GraphicsPreviewStage.Bounds.Height,32,1000);
        if(width<=32||height<=32)return;
        previewBusy=true;
        try {
            var size=DisplayOptions.Size(Settings.WindowSize);
            var options=new PreviewRenderOptions(Settings.ResolvedInternalResolution,Settings.TextureLinear,Settings.ResolvedAnisotropy,Settings.ResolvedAntiAliasing,Settings.ResolvedAspect,Settings.ResolvedWidescreen,Settings.ResolvedFit,Settings.LinearFilter,Settings.Brightness,Settings.Gamma,size.Width,size.Height);
            double seconds=previewClock.Elapsed.TotalSeconds;var scene=previewScene;
            var frame=await Task.Run(()=>previewRenderer.Render(scene,options,seconds,width,height,previewYaw,previewPitch,previewZoom),lifetime.Token);
            if(!closed){var prior=GraphicsGpuView.Source;GraphicsGpuView.Source=ArtworkLoader.FromBgra(frame.Bgra,frame.Width,frame.Height);(prior as IDisposable)?.Dispose();}
        }catch(Exception e)when(e is IOException or InvalidDataException or OperationCanceledException){GraphicsPreviewState.Text=e.Message;}
        finally {previewBusy=false;nextPreview=Stopwatch.GetTimestamp()+Stopwatch.Frequency/30;}
    }
}
