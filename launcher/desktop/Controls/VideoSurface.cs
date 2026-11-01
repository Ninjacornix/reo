using Avalonia.Controls;
using Avalonia.Threading;
using System.Diagnostics;

namespace Outbreak.Launcher.Desktop.Controls;

// FFmpeg is an independent media worker. No system codecs, shell commands or
// platform-specific video control alter the launcher's layout/compositing.
public sealed class VideoSurface:Image,IDisposable {
    CancellationTokenSource? cancellation;
    Process? process;
    int generation;
    string key="";
    public bool HasVideo=>Source!=null;
    public event Action? FrameReady;
    internal void Play(string[] clips) {
        string next=string.Join('|',clips);
        if(key==next&&cancellation!=null)return;
        Stop();key=next;
        if(clips.Length==0)return;
        var stop=cancellation=new();_ = Loop(clips,stop.Token,generation);
    }
    async Task Loop(string[] clips,CancellationToken token,int run) {
        try {
            while(!token.IsCancellationRequested)foreach(string clip in clips) {
                var start=new ProcessStartInfo(await BackgroundVideoTool.Ensure(Settings.Home,token).ConfigureAwait(false)){UseShellExecute=false,RedirectStandardOutput=true,RedirectStandardError=true};
                foreach(string arg in new[]{"-hide_banner","-loglevel","error","-re","-i",clip,"-an","-vf","fps=30,scale=512:448","-pix_fmt","bgra","-f","rawvideo","pipe:1"})start.ArgumentList.Add(arg);
                using var child=Process.Start(start)??throw new IOException("Could not start the background-video decoder.");process=child;
                var errors=child.StandardError.ReadToEndAsync(token);
                byte[] frame=new byte[512*448*4];
                while(!token.IsCancellationRequested) {
                    int count=0;
                    while(count<frame.Length) {
                        int read=await child.StandardOutput.BaseStream.ReadAsync(frame.AsMemory(count),token).ConfigureAwait(false);
                        if(read==0)break;count+=read;
                    }
                    if(count<frame.Length)break;
                    await Dispatcher.UIThread.InvokeAsync(()=>{
                        if(token.IsCancellationRequested)return;
                        var prior=Source;Source=ArtworkLoader.FromBgra(frame,512,448);Opacity=1;(prior as IDisposable)?.Dispose();FrameReady?.Invoke();
                    });
                }
                if(token.IsCancellationRequested){if(!child.HasExited)child.Kill(true);break;}
                await child.WaitForExitAsync(token).ConfigureAwait(false);
                string error=await errors.ConfigureAwait(false);if(child.ExitCode!=0)throw new IOException(error);
            }
        }catch(Exception e)when(e is IOException or OperationCanceledException or System.ComponentModel.Win32Exception){Debug.WriteLine(e.Message);}
        finally {if(run==generation)process=null;}
    }
    internal void Stop() {
        generation++;
        cancellation?.Cancel();cancellation?.Dispose();cancellation=null;key="";
        try{if(process is {} child&&!child.HasExited)child.Kill(true);}catch(InvalidOperationException){}catch(System.ComponentModel.Win32Exception){}
        var prior=Source;Source=null;Opacity=0;(prior as IDisposable)?.Dispose();
    }
    public void Dispose()=>Stop();
}
