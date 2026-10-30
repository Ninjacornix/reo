using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestDeveloperUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        string session = Path.Combine(Settings.Home, "sessions", "zz-developer-ui-" + Guid.NewGuid().ToString("N"));
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        async Task Wait(Func<bool> condition) {
            for (int i = 0; i < 150 && !condition(); i++) await Task.Delay(20);
            if (!condition()) throw new IOException("Developer UI did not settle.");
            UpdateLayout();
        }
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(path))!;
        void Toggle(CheckBox box) => ((IToggleProvider)new CheckBoxAutomationPeer(box).GetPattern(PatternInterface.Toggle)!).Toggle();
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed; UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this); var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Developer diagnostics require an isolated data home");
            timer.Stop(); settings.CoopMode = "offline"; GamePicker.SelectedValue = "file1";
            initialized = false; settings.Developer = new(); InitializeDeveloper(); initialized = true;
            ShowPage("Developer"); RefreshDeveloperUi(); await Task.Delay(450);
            var switches = new[] { DevNetworkTrace, DevTransportLog, DevSnapTrace, DevFrameTiming, DevGameClock };
            Check(switches.All(box => box.IsVisible && box.IsEnabled && box.IsChecked != true),
                "The redesigned Network and Timing groups expose all five existing recording switches");
            Capture("developer-default");
            HideStatusToast(); await Task.Delay(350);
            foreach (var box in switches) Toggle(box);
            var stored = Stored().Developer;
            Check(stored.NetworkTrace && stored.TransportLog && stored.SnapTrace && stored.FrameTiming && stored.GameClock,
                "Every styled switch persists its actual developer option through native toggle automation");
            Check(StatusToast.Visibility == Visibility.Collapsed, "Routine developer changes save quietly");
            var native = stored.Environment(session, true, "file1");
            Check(native.ContainsKey("REO_COOP_TRACE_FILE") && native["REO_NET_TRACE"] == "1" && native["REO_SNAP_TRACE"] == "1" &&
                native["REO_FRAME_PACING_FILE"] == Path.Combine(session, "frames.csv") &&
                native["REO_GAME_CLOCK_FILE"] == Path.Combine(session, "clock.csv"),
                "The saved switches still supply the existing native recording flags and session paths");
            Capture("developer-enabled");
            GamePicker.SelectedValue = "file2"; RefreshDeveloperUi();
            bool blocked = false;
            try { Toggle(DevGameClock); } catch (ElementNotEnabledException) { blocked = true; }
            Check(blocked && DevGameClock.IsChecked == true && Stored().Developer.GameClock &&
                !Stored().Developer.Environment(session, true, "file2").ContainsKey("REO_GAME_CLOCK_FILE"),
                "File #2 disables its unsupported clock control while retaining the File #1 preference");
            GamePicker.SelectedValue = "file1"; RefreshDeveloperUi();
            Check(DevGameClock.IsEnabled && DevGameClock.IsChecked == true,
                "Returning to File #1 restores the retained clock option");
            SetLaunching(true); RefreshDeveloperUi();
            Check(DeveloperSessionNote.IsVisible, "An active session shows only the relevant next-session notice");
            SetLaunching(false); RefreshDeveloperUi();
            Check(!DeveloperSessionNote.IsVisible, "Idle developer settings omit the session notice");

            Directory.CreateDirectory(session);
            string debugText = "000000.000 [INFO] Developer log fixture\n000000.016 [FRAME] ticks=12345678 pc=0x00100000\n";
            File.WriteAllText(Path.Combine(session, "stderr.log"), debugText);
            File.WriteAllText(Path.Combine(session, "stdout.log"), "Standard output fixture\n");
            ((IInvokeProvider)new ButtonAutomationPeer(DeveloperViewLogsButton).GetPattern(PatternInterface.Invoke)!).Invoke();
            await Wait(() => currentPage == "Logs");
            LogSessionPicker.SelectedItem = LogSessionPicker.Items.Cast<LogSession>().Single(item => item.Directory == session);
            LogStreamPicker.SelectedIndex = 0; manualLog = null; lastLogPath = ""; RefreshLog(); await Task.Delay(350);
            Check(DebugLog.Text == debugText && DebugLog.IsReadOnly && DebugLog.TextWrapping == TextWrapping.NoWrap &&
                DebugLog.FontFamily.Source == "Consolas",
                "View logs opens real session text in the fixed Consolas font without changing read-only log behavior");
            Check(new Typeface(DebugLog.FontFamily, FontStyles.Normal, FontWeights.Normal, FontStretches.Normal)
                .TryGetGlyphTypeface(out var face) &&
                face.AdvanceWidths[face.CharacterToGlyphMap['i']] == face.AdvanceWidths[face.CharacterToGlyphMap['W']],
                "The selected log typeface has equal-width character metrics for readable columns");
            Capture("log-consolas");
            LogStreamPicker.SelectedIndex = 1; RefreshLog();
            Check(DebugLog.Text == "Standard output fixture\n" && DebugLog.FontFamily.Source == "Consolas",
                "Switching log streams preserves the normal log font");
            GamePicker.SelectedValue = "file2";
            Check(DebugLog.FontFamily.Source == "Consolas", "Edition changes preserve the log font independently of game artwork fonts");
            ShowPage("Developer"); await Task.Delay(400);
            Width = MinWidth; Height = MinHeight; await Task.Delay(200); UpdateLayout();
            Check(PageDeveloper.ActualWidth <= SettingsScroll.ViewportWidth + 1 && switches.All(box => {
                var point = box.TranslatePoint(new Point(box.ActualWidth, box.ActualHeight), SettingsScroll);
                return point.X <= SettingsScroll.ViewportWidth + 1 && point.Y <= SettingsScroll.ViewportHeight + 1;
            }) && OpenSessionFoldersButton.IsEnabled,
                "Both recording groups and the session-folder action fit at minimum window size");
            Capture("developer-compact");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks,
                scope = "Native toggle and button automation, persisted developer flags, real fixture log reading and glyph metrics. No game launches or native recordings were started."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            SetLaunching(false); timer.Stop(); audioSaveTimer.Stop(); colorSaveTimer.Stop(); Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
            if (Directory.Exists(session)) {
                File.Delete(Path.Combine(session, "stderr.log")); File.Delete(Path.Combine(session, "stdout.log"));
                Directory.Delete(session, false);
            }
        }
    }
}
