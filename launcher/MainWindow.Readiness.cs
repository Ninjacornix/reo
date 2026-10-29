using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    const string ReleasesUrl = "https://github.com/Ninjacornix/reo/releases";
    const long SetupSpace = 10L * 1024 * 1024 * 1024;
    static bool VulkanInstalled() =>
        File.Exists(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.System),
                                 "vulkan-1.dll"));
    static long FreeSpace() {
        try {
            return new DriveInfo(Path.GetPathRoot(Settings.Home)!).AvailableFreeSpace;
        } catch (Exception error) when (error is IOException or ArgumentException or
                                            UnauthorizedAccessException) {
            return -1;
        }
    }
    static string Gigabytes(long bytes) => (bytes / (1024.0 * 1024 * 1024)).ToString("0.#") + " GB";
    enum Check { Done, Missing, Info }
    void SetCheck(string name, Check state, string text, string? action = null) {
        var mark = (TextBlock)FindName(name + "Mark");
        mark.Text = state switch { Check.Done => "\u2713", Check.Missing => "\u2717", _ => "\u2022" };
        mark.Foreground = (Brush)FindResource(state switch { Check.Done => "Good", Check.Missing => "Danger",
                                                             _ => "Muted" });
        System.Windows.Automation.AutomationProperties.SetName(
            mark, state switch { Check.Done => "Done", Check.Missing => "Needed", _ => "Information" });
        var label = (TextBlock)FindName(name + "Text");
        label.Text = text;
        label.Foreground = (Brush)FindResource(state == Check.Info ? "Muted" : "Ink");
        if (FindName(name + "Action") is Button button) {
            button.Content = action;
            button.Visibility = action == null ? Visibility.Collapsed : Visibility.Visible;
        }
    }
    string[] graphicsCards = Array.Empty<string>();
    void RefreshReadyCheck() {
        bool packaged = AppLayout.Packaged(root);
        bool kit = packaged ? LocalGameBuild.Available(root, settings.Game.Id) : File.Exists(settings.GetExe());
        bool built = File.Exists(settings.GetExe());
        bool vulkan = VulkanInstalled();
        long free = FreeSpace();
        bool roomy = built || free < 0 || free >= SetupSpace;
        string iso = settings.GetGameSource();
        bool discOk = discCheck is { Ok: true } && discCheck.Matches(iso, settings.Game.Id);
        string cards = graphicsCards.Length > 0 ? " (" + string.Join(", ", graphicsCards) + ")" : "";
        SetCheck("CheckDotnet", Check.Done, ".NET 8 Desktop Runtime");
        SetCheck("CheckVulkan", vulkan ? Check.Done : Check.Missing,
                 (vulkan ? "Vulkan graphics driver" : "Vulkan graphics driver not found") + cards,
                 vulkan ? null : "Get driver");
        SetCheck("CheckDisk", roomy ? Check.Done : Check.Missing,
                 free < 0 ? "Free disk space unknown"
                 : built ? Gigabytes(free) + " free disk space"
                         : Gigabytes(free) + " free (setup needs about 10 GB)",
                 roomy ? null : "Free up space");
        SetCheck("CheckDisc", discOk ? Check.Done : Check.Missing,
                 discOk ? "Game source verified"
                 : !File.Exists(iso) ? "Game source not chosen yet"
                 : discCheck != null && discCheck.Matches(iso, settings.Game.Id) ? "Game source not supported"
                                                               : "Checking game source...",
                 discOk ? null : settings.UsesGamePak() ? "Choose PAK" : "Choose ISO");
        RefreshNextStep(packaged, kit, built, vulkan, roomy);
    }
    static string DriverPage(IEnumerable<string> cards) {
        string all = string.Join(" ", cards);
        return all.Contains("NVIDIA", StringComparison.OrdinalIgnoreCase)
                   ? "https://www.nvidia.com/en-us/drivers/"
               : all.Contains("AMD", StringComparison.OrdinalIgnoreCase) ||
                       all.Contains("Radeon", StringComparison.OrdinalIgnoreCase)
                   ? "https://www.amd.com/en/support/download/drivers.html"
               : all.Contains("Intel", StringComparison.OrdinalIgnoreCase)
                   ? "https://www.intel.com/content/www/us/en/support/detect.html"
                   : "ms-settings:windowsupdate";
    }
    void ChecklistAction(object sender, RoutedEventArgs e) {
        void Open(string target) {
            try {
                Process.Start(new ProcessStartInfo(target) { UseShellExecute = true });
            } catch (System.ComponentModel.Win32Exception) {
                Status.Text = "Could not open " + target;
            }
        }
        switch ((string)((Button)sender).Tag) {
        case "CheckVulkan":
            Open(DriverPage(graphicsCards));
            break;
        case "CheckDisk":
            Open("ms-settings:storagesense");
            break;
        case "CheckDisc":
            ChooseIso();
            break;
        case "CheckInput":
            ShowPage("Controller");
            break;
        }
    }
    async void RecheckRequirements(object sender, RoutedEventArgs e) {
        await DetectGraphicsCard();
        RefreshGameUi();
    }
    enum NextAction { None, Releases, Setup, ChooseIso, Build, Driver }
    NextAction nextAction;
    string readinessStatus = "";
    void RefreshNextStep(bool packaged, bool kit, bool built, bool vulkan, bool roomy) {
        string iso = settings.GetGameSource();
        (string title, string detail, NextAction action) =
            !Playable(settings.Game.Id) ? ("", "", NextAction.None)
            : importCancellation != null
                ? ("Setting up the game", "Progress is shown below. This happens only once.", NextAction.None)
            : !kit && packaged
                ? ("This download is incomplete",
                   "Extract the complete release ZIP into a new folder, then open the launcher from there.",
                   NextAction.Releases)
            : !kit ? ("No game build found",
                      "Build reo_recomp in this checkout, or choose Use existing build in Game files.",
                      NextAction.Setup)
            : !vulkan ? ("Update your graphics driver",
                         "The game needs a Vulkan graphics driver. Install the latest driver from your graphics card maker.",
                         NextAction.Driver)
            : !File.Exists(iso)
                ? ("Choose your game source",
                   settings.UsesGamePak() ? "Select a complete game PAK exported by this launcher." : "Select your own game ISO. " + DiscValidation.RequiredFor(settings.Game.Id),
                   NextAction.ChooseIso)
            : discCheck == null || !discCheck.Matches(iso, settings.Game.Id)
                ? ("Checking your game source...", "This takes a few seconds.", NextAction.None)
            : !discCheck.Ok ? ("This game source can't be used", discCheck.Message, NextAction.ChooseIso)
            : !DiscImport.Ready(settings) || !built
                ? ("Build the game",
                   "One-time setup: imports your disc and compiles the game. It downloads build tools " +
                       "(about 173 MB) and can take a while." +
                       (roomy ? "" : " Free up disk space first: about 10 GB is needed."),
                   NextAction.Build)
                : ("", "", NextAction.None);
        nextAction = action;
        NextStep.Visibility = title.Length == 0 ? Visibility.Collapsed : Visibility.Visible;
        NextStepTitle.Text = title;
        NextStepDetail.Text = detail;
        NextStepButton.Visibility = action == NextAction.None ? Visibility.Collapsed : Visibility.Visible;
        NextStepButton.Content = action switch {
            NextAction.Releases => "Open downloads", NextAction.Setup => "Game files",
            NextAction.ChooseIso => discCheck?.Ok == false && discCheck.Matches(iso, settings.Game.Id)
                                        ? (settings.UsesGamePak() ? "Choose another PAK" : "Choose another ISO") : (settings.UsesGamePak() ? "Choose PAK" : "Choose ISO"),
            NextAction.Build => "Build game", _ => "Get driver"
        };
        NextStepButton.IsEnabled = !updating && !game.Running && !launching && !backingUp;
        // The footer reflects readiness instead of a bare "Ready" while setup is unfinished.
        string summary = !Playable(settings.Game.Id) ? "Not available yet"
                         : title.Length == 0 ? "Ready to play" : "Next step: " + title;
        if (Status.Text == "Ready" || Status.Text == readinessStatus)
            Status.Text = summary;
        readinessStatus = summary;
    }
    async void NextStepClicked(object sender, RoutedEventArgs e) {
        switch (nextAction) {
        case NextAction.Releases:
            Process.Start(new ProcessStartInfo(ReleasesUrl) { UseShellExecute = true });
            break;
        case NextAction.Setup:
            ShowPage("Setup");
            break;
        case NextAction.ChooseIso:
            ChooseIso();
            break;
        case NextAction.Build:
            await ImportSelectedDisc();
            break;
        case NextAction.Driver:
            ChecklistAction(CheckVulkanAction, e);
            break;
        }
    }
    async Task DetectGraphicsCard() {
        if (args.Contains("--public-preview"))
            return; // published screenshots do not show this PC's hardware
        try {
            var start = new ProcessStartInfo(
                "powershell.exe") { UseShellExecute = false, CreateNoWindow = true,
                                    RedirectStandardOutput = true, RedirectStandardError = true };
            foreach (string arg in new[] {
                         "-NoProfile", "-NonInteractive", "-Command",
                         "@(Get-CimInstance Win32_VideoController -ErrorAction Stop | " +
                             "ForEach-Object { $_.Name }) | ConvertTo-Json -Compress"
                     })
                start.ArgumentList.Add(arg);
            using var process =
                Process.Start(start) ?? throw new IOException("Cannot query graphics card.");
            var output = process.StandardOutput.ReadToEndAsync();
            var errors = process.StandardError.ReadToEndAsync();
            using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(8));
            try {
                await process.WaitForExitAsync(timeout.Token);
            } catch (OperationCanceledException) {
                if (!process.HasExited)
                    process.Kill();
                throw;
            }
            using var json = JsonDocument.Parse(await output);
            string[] names = json.RootElement.ValueKind == JsonValueKind.Array
                                 ? json.RootElement.EnumerateArray()
                                       .Select(x => x.GetString() ?? "")
                                       .Where(x => x.Length > 0)
                                       .ToArray()
                                 : new[] { json.RootElement.GetString() ?? "" };
            if (process.ExitCode != 0 || !names.Any(x => x.Length > 0))
                throw new IOException(await errors);
            graphicsCards = names.Where(x => x.Length > 0).ToArray();
            RefreshReadyCheck();
        } catch (Exception error)
            when (error is IOException or JsonException or System.ComponentModel.Win32Exception or
                      OperationCanceledException) {
            graphicsCards = Array.Empty<string>();
        }
    }
}
