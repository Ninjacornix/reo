using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed class GameSession
{
    public Process? Process { get; private set; }
    public string? Logs { get; private set; }
    public bool Running => Process is { HasExited: false };
    public static string SaveFolder(string root, string game = "file1") => Path.Combine(root, "build-ninja", GameDefinition.Find(game).PlayFolder, "saves");

    public async Task Launch(string root, Settings settings, Controller controller)
    {
        if (Running) throw new InvalidOperationException("The launcher already has a game session running.");
        string sourceExe = settings.GetExe(), iso = settings.GetIso(), elf = settings.GetElf(root);
        var selectedGame = settings.Game;
        if (!File.Exists(sourceExe)) throw new FileNotFoundException("Choose the selected game's native executable in Game files.");
        if (!File.Exists(iso)) throw new FileNotFoundException("Choose the selected game's ISO in Game files.");
        if (!File.Exists(elf)) throw new FileNotFoundException("Choose the selected game's extracted ELF in Game files.");
        string discRoot = await MountDisc(iso);
        string discElf = Path.Combine(discRoot, selectedGame.ElfName);
        if (!File.Exists(discElf)) throw new FileNotFoundException("The selected disc does not contain this game's ELF.");
        using (var chosen = File.OpenRead(elf))
        using (var onDisc = File.OpenRead(discElf))
            if (!SHA256.HashData(chosen).SequenceEqual(SHA256.HashData(onDisc))) throw new IOException("The selected ELF does not match this disc image.");
        string proxy = Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll");
        if (!File.Exists(proxy)) throw new FileNotFoundException("Build the launcher's input adapter first (launcher/build.ps1).");
        string hash;
        string cached = Path.Combine(Settings.Home, "game-cache");
        Directory.CreateDirectory(cached);
        // Only launcher-owned copies are replaced. Never place the adapter next
        // to Claude's executable, load a changing in-place build, or alter sources.
        string image = Path.Combine(cached, "reo_launcher_game.exe");
        hash = await Task.Run(() => {
            using var source = new FileStream(sourceExe, FileMode.Open, FileAccess.Read, FileShare.ReadWrite | FileShare.Delete);
            using var copy = new FileStream(image + ".tmp", FileMode.Create, FileAccess.Write);
            source.CopyTo(copy); copy.Flush(); source.Position = 0;
            return Convert.ToHexString(SHA256.HashData(source)).ToLowerInvariant();
        });
        using (var check = File.OpenRead(image + ".tmp"))
            if (Convert.ToHexString(SHA256.HashData(check)).ToLowerInvariant() != hash) throw new IOException("Executable copy failed verification.");
        File.Move(image + ".tmp", image, true);
        string shaderSource = Path.Combine(Path.GetDirectoryName(Path.GetFullPath(sourceExe))!, "reo-gpu-present");
        string shaderTarget = Path.Combine(cached, "reo-gpu-present");
        Directory.CreateDirectory(shaderTarget);
        foreach (string file in new[] { "present_opaque.vert.spv", "present_native.frag.spv" })
        {
            string input = Path.Combine(shaderSource, file);
            if (!File.Exists(input)) throw new FileNotFoundException("The selected build is missing its reo-gpu-present shaders: " + file);
            File.Copy(input, Path.Combine(shaderTarget, file), true);
        }
        string vulkanLoader = Path.Combine(Path.GetDirectoryName(Path.GetFullPath(sourceExe))!, "vulkan-1.dll");
        if (File.Exists(vulkanLoader)) File.Copy(vulkanLoader, Path.Combine(cached, "vulkan-1.dll"), true);
        string cachedProxy = Path.Combine(cached, "XINPUT1_4.dll");
        File.Copy(proxy, cachedProxy, true);
        Logs = Path.Combine(Settings.Home, "sessions", DateTime.Now.ToString("yyyyMMdd-HHmmss-fff"));
        Directory.CreateDirectory(Logs); Directory.CreateDirectory(SaveFolder(root, selectedGame.Id));
        var start = new ProcessStartInfo(image) { UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = Path.Combine(root, "build-ninja", selectedGame.PlayFolder), RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string arg in new[] { "--game", selectedGame.Id, "--elf", discElf, "--data", discRoot }) start.ArgumentList.Add(arg);
        foreach (var key in start.Environment.Keys.Where(k => k.StartsWith("REO_", StringComparison.OrdinalIgnoreCase)).ToArray()) start.Environment.Remove(key);
        void Set(string key, string value) => start.Environment[key] = value;
        Set("REO_ISO", Path.GetFullPath(iso)); Set("REO_NATURAL", "1"); Set("REO_TURBO", "1"); // existing normal-speed scheduling mode, no time warp
        Set("REO_GS_BACKEND", "parallel"); Set("REO_GS_THREAD", "1"); Set("REO_GS_GPU_PRESENT", "1");
        Set("REO_GS_DISPATCH_PACE", "2"); Set("REO_GS_SPRITE_DEPTH_PARALLEL", "1");
        Set("REO_VIF1_ASYNC", settings.AsyncVif ? "1" : "0"); Set("REO_VIF1_GPU_RESIDENT", "0");
        Set("REO_DISPLAY_FILTER", settings.LinearFilter ? "linear" : "nearest");
        // GPU movie request uses presence semantics in some paths: leave unset
        // for CPU, never set the misleading string "0".
        if (settings.GpuMovies) Set("REO_GPU_MOVIE", "1");
        controller.Select(controller.SelectedDevice.Id); // pin the chosen source across hotplug events
        controller.SessionEnabled = true; controller.Publish();
        Set("REO_LAUNCHER_PAD_MAP", controller.MapName);
        var stdout = new StreamWriter(Path.Combine(Logs, "stdout.log")) { AutoFlush = true };
        var stderr = new StreamWriter(Path.Combine(Logs, "stderr.log")) { AutoFlush = true };
        Process = new Process { StartInfo = start };
        try { if (!Process.Start()) throw new IOException("Windows could not start the game."); }
        catch { stdout.Dispose(); stderr.Dispose(); throw; }
        controller.GameProcessId = Process.Id;
        _ = Pump(Process.StandardOutput, stdout); _ = Pump(Process.StandardError, stderr);
        await File.WriteAllTextAsync(Path.Combine(Logs, "launch.json"), JsonSerializer.Serialize(new { pid = Process.Id, game = selectedGame.Id, source = sourceExe, image, sha256 = hash, iso, discRoot, inputDevice = controller.SelectedDevice.Name, gpuMovies = settings.GpuMovies, directIso = true }, new JsonSerializerOptions { WriteIndented = true }));
        _ = ApplyWindow(Process, settings);
        _ = RecordExit(Process, Logs);
    }
    static async Task<string> MountDisc(string iso)
    {
        var start = new ProcessStartInfo("powershell.exe") { UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string arg in new[] { "-NoProfile", "-ExecutionPolicy", "Bypass", "-File", Path.Combine(AppContext.BaseDirectory, "MountDisc.ps1"), "-Iso", Path.GetFullPath(iso) }) start.ArgumentList.Add(arg);
        using var mount = Process.Start(start) ?? throw new IOException("Cannot open the disc image.");
        Task<string> output = mount.StandardOutput.ReadToEndAsync(), error = mount.StandardError.ReadToEndAsync();
        await mount.WaitForExitAsync();
        if (mount.ExitCode != 0) throw new IOException("Cannot mount the disc: " + await error);
        using var record = JsonDocument.Parse(await output);
        return record.RootElement.GetProperty("root").GetString()!;
    }
    static async Task RecordExit(Process process, string logs)
    {
        await process.WaitForExitAsync();
        await File.WriteAllTextAsync(Path.Combine(logs, "exit.json"), JsonSerializer.Serialize(new { pid = process.Id, exitCode = process.ExitCode, utc = DateTime.UtcNow }));
    }
    static async Task Pump(StreamReader input, StreamWriter output)
    {
        using (output) { string? line; while ((line = await input.ReadLineAsync()) != null) await output.WriteLineAsync(line); }
    }
    static async Task ApplyWindow(Process process, Settings settings)
    {
        for (int i = 0; i < 100 && !process.HasExited; ++i)
        {
            await Task.Delay(100); process.Refresh(); nint hwnd = process.MainWindowHandle;
            if (hwnd == 0) continue;
            if (settings.Fullscreen)
            {
                long style = GetWindowLongPtr(hwnd, -16).ToInt64() & ~0x00CF0000L;
                SetWindowLongPtr(hwnd, -16, new nint(style));
                var info = new MonitorInfo { Size = Marshal.SizeOf<MonitorInfo>() };
                if (GetMonitorInfo(MonitorFromWindow(hwnd, 2), ref info))
                    SetWindowPos(hwnd, 0, info.Monitor.Left, info.Monitor.Top, info.Monitor.Right - info.Monitor.Left, info.Monitor.Bottom - info.Monitor.Top, 0x24);
            }
            else
            {
                int width = new[] { 1024, 1280, 1600 }[settings.WindowSize];
                var rect = new Rect { Right = width, Bottom = width * 3 / 4 };
                AdjustWindowRect(ref rect, (uint)GetWindowLongPtr(hwnd, -16).ToInt64(), false);
                SetWindowPos(hwnd, 0, 80, 60, rect.Right - rect.Left, rect.Bottom - rect.Top, 0x24);
            }
            break;
        }
    }
    [StructLayout(LayoutKind.Sequential)] struct Rect { public int Left, Top, Right, Bottom; }
    [StructLayout(LayoutKind.Sequential)] struct MonitorInfo { public int Size; public Rect Monitor, Work; public uint Flags; }
    [DllImport("user32")] static extern nint GetWindowLongPtrW(nint hwnd, int index);
    static nint GetWindowLongPtr(nint hwnd, int index) => GetWindowLongPtrW(hwnd, index);
    [DllImport("user32", EntryPoint = "SetWindowLongPtrW")] static extern nint SetWindowLongPtr(nint hwnd, int index, nint value);
    [DllImport("user32")] static extern bool SetWindowPos(nint hwnd, nint after, int x, int y, int width, int height, uint flags);
    [DllImport("user32")] static extern bool AdjustWindowRect(ref Rect rect, uint style, bool menu);
    [DllImport("user32")] static extern nint MonitorFromWindow(nint hwnd, uint flags);
    [DllImport("user32", CharSet = CharSet.Unicode)] static extern bool GetMonitorInfo(nint monitor, ref MonitorInfo info);
}
