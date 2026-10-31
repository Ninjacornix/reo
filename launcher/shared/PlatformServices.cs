using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class PlatformServices {
    internal sealed record Runner(string Executable,string Source,string[] Prefix);
    internal static Runner Server(string root) {
        string metadata=Path.Combine(AppContext.BaseDirectory,"platform-services.json");
        if(File.Exists(metadata)) {
            using var doc=JsonDocument.Parse(File.ReadAllText(metadata));
            var server=doc.RootElement.GetProperty("server");
            string Resolve(string key)=>Path.GetFullPath(Path.Combine(AppContext.BaseDirectory,server.GetProperty(key).GetString()!));
            return new(Resolve("executable"),Resolve("source"),["--server-worker"]);
        }
        string source=Path.Combine(root,"build-macos","opensnap-source"),python=Path.Combine(root,"build-macos","launcher-env","bin","python");
        if(File.Exists(python)&&File.Exists(Path.Combine(source,"run.py")))return new(python,source,["-u",Path.Combine(root,"network","server","worker.py"),"--server-worker"]);
        throw new IOException("The bundled server runtime is missing. Build the shared launcher package, including its server tools.");
    }
    internal static string Ffmpeg() {
        string metadata=Path.Combine(AppContext.BaseDirectory,"platform-services.json");
        if(File.Exists(metadata)) {
            using var doc=JsonDocument.Parse(File.ReadAllText(metadata));
            if(doc.RootElement.TryGetProperty("ffmpeg",out var ffmpeg)) {
                string file=Path.GetFullPath(Path.Combine(AppContext.BaseDirectory,ffmpeg.GetString()!));
                if(File.Exists(file))return file;
            }
        }
        foreach(string candidate in new[]{Path.Combine(AppContext.BaseDirectory,"tools","ffmpeg"),"/opt/homebrew/bin/ffmpeg","/usr/local/bin/ffmpeg","/usr/bin/ffmpeg"})if(File.Exists(candidate))return candidate;
        throw new IOException("Background videos need the bundled FFmpeg tool. Rebuild the launcher package or install FFmpeg.");
    }
    [DllImport("Reo.Platform",EntryPoint="reo_trash_path")]static extern int TrashMac([MarshalAs(UnmanagedType.LPUTF8Str)]string path);
    internal static void Trash(string path) {
        if(OperatingSystem.IsMacOS()) {
            if(TrashMac(path)==0)throw new IOException("macOS could not move the memory card to the Trash.");
            return;
        }
        var start=new ProcessStartInfo("gio"){UseShellExecute=false,RedirectStandardError=true};start.ArgumentList.Add("trash");start.ArgumentList.Add("--");start.ArgumentList.Add(path);
        using var process=Process.Start(start)??throw new IOException("Could not open the system Trash service.");
        string error=process.StandardError.ReadToEnd();process.WaitForExit();if(process.ExitCode!=0)throw new IOException("Could not move the card to the Trash: "+error);
    }
}
