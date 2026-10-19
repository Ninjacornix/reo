using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow
{
    const string ReleasesUrl = "https://github.com/Ninjacornix/reo/releases";
    void RefreshReadyCheck()
    {
        void Row(TextBlock target, bool ready, string yes, string no)
        {
            target.Text = ready ? yes : no;
            target.Foreground = (Brush)FindResource(ready ? "Ink" : "Muted");
        }
        Row(ReadyBuild, File.Exists(settings.GetExe()), "Native game build found", "Choose a native game build in Game files");
        Row(ReadyFiles, File.Exists(settings.GetIso()) && File.Exists(settings.GetElf(root)),
            "Disc image and game files found", "Configure the disc image and ELF in Game files");
        string saves = GameSession.SaveFolder(root, settings.Game.Id);
        Row(ReadySaves, Directory.Exists(saves), "Save folder found", "Save folder will be created on launch");
        ReadySavePath.Text = saves;
        Row(ReadyInput, controller.SelectedDevice.Available, "Input: " + controller.SelectedDevice.Name,
            "Input device disconnected");
    }
    async Task DetectGraphicsCard()
    {
        try
        {
            var start = new ProcessStartInfo("powershell.exe")
            {
                UseShellExecute = false, CreateNoWindow = true,
                RedirectStandardOutput = true, RedirectStandardError = true
            };
            foreach (string arg in new[] { "-NoProfile", "-NonInteractive", "-Command",
                "@(Get-CimInstance Win32_VideoController -ErrorAction Stop | ForEach-Object { $_.Name }) | ConvertTo-Json -Compress" })
                start.ArgumentList.Add(arg);
            using var process = Process.Start(start) ?? throw new IOException("Cannot query graphics card.");
            var output = process.StandardOutput.ReadToEndAsync();
            var errors = process.StandardError.ReadToEndAsync();
            using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(8));
            try { await process.WaitForExitAsync(timeout.Token); }
            catch (OperationCanceledException) { if (!process.HasExited) process.Kill(); throw; }
            using var json = JsonDocument.Parse(await output);
            string[] names = json.RootElement.ValueKind == JsonValueKind.Array
                ? json.RootElement.EnumerateArray().Select(x => x.GetString() ?? "").Where(x => x.Length > 0).ToArray()
                : new[] { json.RootElement.GetString() ?? "" };
            if (process.ExitCode != 0 || !names.Any(x => x.Length > 0)) throw new IOException(await errors);
            ReadyGraphics.Text = "Graphics card: " + string.Join(", ", names);
        }
        catch (Exception error) when (error is IOException or JsonException or System.ComponentModel.Win32Exception or OperationCanceledException)
        {
            ReadyGraphics.Text = "Graphics card information unavailable";
        }
    }
    void CheckForUpdates(object sender, RoutedEventArgs e)
    {
        try
        {
            Process.Start(new ProcessStartInfo(ReleasesUrl) { UseShellExecute = true });
            Status.Text = "Opened GitHub Releases.";
        }
        catch (Exception error) when (error is System.ComponentModel.Win32Exception or InvalidOperationException)
        { Status.Text = "Could not open GitHub Releases: " + error.Message; }
    }
}
