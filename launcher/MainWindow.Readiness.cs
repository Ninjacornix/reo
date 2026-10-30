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
    string[] graphicsCards = Array.Empty<string>();
    void RefreshReadyCheck() {
        bool packaged = AppLayout.Packaged(root);
        bool kit = packaged ? LocalGameBuild.Available(root, settings.Game.Id) : File.Exists(settings.GetExe());
        bool built = File.Exists(settings.GetExe());
        bool vulkan = VulkanInstalled();
        long free = FreeSpace();
        bool roomy = built || free < 0 || free >= SetupSpace;
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
    void OpenExternal(string target) {
        try {
            Process.Start(new ProcessStartInfo(target) { UseShellExecute = true });
        } catch (System.ComponentModel.Win32Exception) {
            Status.Text = "Could not open " + target;
        }
    }
    enum NextAction { None, Releases, Setup, ChooseIso, Build, Driver }
    NextAction nextAction;
    string readinessStatus = "";
    readonly Dictionary<string, DiscCheck> readinessDiscChecks = new();
    (string title, string detail, NextAction action) NextStepFor(string edition, bool packaged, bool kit, bool built, bool vulkan, bool roomy) {
        string iso = settings.GetIso(edition);
        var known = discCheck?.Matches(iso, edition) == true ? discCheck : readinessDiscChecks.GetValueOrDefault(edition);
        if (known?.Matches(iso, edition) != true) known = null;
        return
            !Playable(edition) ? ("", "", NextAction.None)
            : importCancellation != null
                ? ("Setting up the game", "Progress is shown below. This happens only once.", NextAction.None)
            : !kit && packaged
                ? ("This download is incomplete",
                   "Extract the complete release ZIP into a new folder, then open the launcher from there.",
                   NextAction.Releases)
            : !kit ? ("No game build found",
                      "Build reo_recomp in this checkout, or choose Use existing build in Game files.",
                      NextAction.Setup)
            : !built && packaged && LocalGameBuild.DataFolderProblem(Settings.Home) is { } tooDeep
                ? ("Choose a shorter folder", tooDeep, NextAction.Setup)
            : !vulkan ? ("Update your graphics driver",
                         "The game needs a Vulkan graphics driver. Install the latest driver from your graphics card maker.",
                         NextAction.Driver)
            : !File.Exists(iso)
                ? ("Choose your game disc",
                   "Select your own game ISO. " + DiscValidation.RequiredFor(edition),
                   NextAction.ChooseIso)
            : DiscImport.Ready(settings, edition) && built ? ("", "", NextAction.None)
            : known == null
                ? ("Checking your disc...", "This takes a few seconds.", NextAction.None)
            : !known.Ok ? ("This disc can't be used", known.Message, NextAction.ChooseIso)
            : !DiscImport.Ready(settings, edition) || !built
                ? ("Build the game",
                   "One-time setup: imports your disc and compiles the game. It downloads build tools " +
                       "(about 173 MB) and can take a while." +
                       (roomy ? "" : " Free up disk space first: about 10 GB is needed."),
                   NextAction.Build)
                : ("", "", NextAction.None);
    }
    static string NextStepActionLabel(NextAction action, bool invalidDisc) => action switch {
        NextAction.Releases => "Open downloads", NextAction.Setup => "Game files",
        NextAction.ChooseIso => invalidDisc ? "Choose another ISO" : "Choose ISO",
        NextAction.Build => "Build game", _ => "Get driver"
    };
    void RefreshNextStep(bool packaged, bool kit, bool built, bool vulkan, bool roomy) {
        if (discCheck != null) readinessDiscChecks[discCheck.Game] = discCheck;
        var (title, detail, action) = NextStepFor(settings.Game.Id, packaged, kit, built, vulkan, roomy);
        nextAction = action;
        NextStep.Visibility = title.Length == 0 ? Visibility.Collapsed : Visibility.Visible;
        NextStepTitle.Text = title;
        NextStepDetail.Text = detail;
        NextStepButton.Visibility = action == NextAction.None ? Visibility.Collapsed : Visibility.Visible;
        NextStepButton.Content = NextStepActionLabel(action, discCheck?.Ok == false && discCheck.Matches(settings.GetIso(), settings.Game.Id));
        NextStepButton.IsEnabled = !updating && !game.Running && !launching && !backingUp;
        // The inactive edition's hidden notice measures the same header slot.
        // Ready/setup switches therefore never insert/remove space above cases.
        string other = settings.Game.Id == "file1" ? "file2" : "file1";
        bool otherBuilt = File.Exists(settings.GetExe(other));
        bool otherKit = packaged ? LocalGameBuild.Available(root, other) : otherBuilt;
        long otherFree = FreeSpace();
        var otherState = NextStepFor(other, packaged, otherKit, otherBuilt, vulkan,
            otherBuilt || otherFree < 0 || otherFree >= SetupSpace);
        NextStepMeasure.Visibility = otherState.title.Length == 0 ? Visibility.Collapsed : Visibility.Hidden;
        NextStepMeasureTitle.Text = otherState.title;
        NextStepMeasureDetail.Text = otherState.detail;
        NextStepMeasureButton.Visibility = otherState.action == NextAction.None ? Visibility.Collapsed : Visibility.Visible;
        NextStepMeasureButton.Content = NextStepActionLabel(otherState.action,
            readinessDiscChecks.GetValueOrDefault(other) is { Ok: false } otherCheck && otherCheck.Matches(settings.GetIso(other), other));
        // The footer reflects readiness instead of a bare "Ready" while setup is unfinished.
        string summary = !Playable(settings.Game.Id) ? "Not available yet"
                         : title.Length == 0 ? "Ready to play" : "Next step: " + title;
        if (Status.Text == "Ready" || Status.Text == readinessStatus)
            Status.Text = summary;
        readinessStatus = summary;
        UpdateStatusLine();
    }
    // Nothing needs saying for "ready", and a pending next step already has its own panel.
    // Messages and progress still appear as a status toast.
    static bool QuietStatus(string text) =>
        text is "" or "Ready" or "Ready to play" || text.StartsWith("Next step: ", StringComparison.Ordinal);
    void UpdateStatusLine() {
        if (QuietStatus(Status.Text)) HideStatusToast();
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
            OpenExternal(DriverPage(graphicsCards));
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
