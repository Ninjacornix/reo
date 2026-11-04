using Outbreak.Launcher;
using System.Text.Json;

static class PlatformServicesTests {
    internal static async Task Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-media-lookup-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            check(BackgroundVideoTool.Cached(root) == null && !Directory.Exists(Path.Combine(root, "media-tools")),
                  "Converter availability probe does not download or create a cache");
            string cache = BackgroundVideoTool.Folder(root);
            Directory.CreateDirectory(cache);
            string exe = Path.Combine(cache, "ffmpeg.exe");
            File.WriteAllText(exe, "partial or tampered converter");
            check(BackgroundVideoTool.Cached(root) == null,
                  "An unverified cached Windows converter is never accepted");
            check(File.ReadAllText(exe) == "partial or tampered converter",
                  "An availability probe does not replace a corrupt cache or start a download");

            string tools = Path.Combine(root, "tools");
            Directory.CreateDirectory(tools);
            string bundled = Path.Combine(tools, OperatingSystem.IsWindows() ? "ffmpeg.exe" : "ffmpeg");
            File.WriteAllText(bundled, "package fixture; never executed");
            check(PlatformServices.BundledFfmpeg(root) == bundled,
                  "Bundled converter lookup uses the target OS executable name");
            string explicitTool = Path.Combine(root, "custom converter");
            File.WriteAllText(explicitTool, "metadata fixture; never executed");
            File.WriteAllText(Path.Combine(root, "platform-services.json"),
                              JsonSerializer.Serialize(new { ffmpeg = "custom converter" }));
            check(PlatformServices.BundledFfmpeg(root) == explicitTool,
                  "Explicit package converter metadata retains priority");
            File.Delete(explicitTool);
            check(PlatformServices.BundledFfmpeg(root) == bundled,
                  "Missing metadata target falls back to the platform's bundled converter");
            using var canceled = new CancellationTokenSource();
            canceled.Cancel();
            bool stopped = false;
            try { await PlatformServices.PrepareFfmpeg(canceled.Token); }
            catch (OperationCanceledException) { stopped = true; }
            check(stopped, "Closing a video cancels converter preparation before any lookup or download");
        } finally { Directory.Delete(root, true); }
    }
}
