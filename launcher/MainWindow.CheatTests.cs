using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestCheatsUi(string output) {
        Directory.CreateDirectory(output);
        string settingsPath = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(settingsPath) ? File.ReadAllBytes(settingsPath) : null;
        string fixture = Path.Combine(Cheats.Folder("file1"), "ui-check-" + Guid.NewGuid().ToString("N") + ".pnach");
        var checks = new List<string>();
        void Check(bool ok, string message) { if (!ok) throw new IOException(message); checks.Add(message); }
        void Toggle(CheckBox box) => ((IToggleProvider)new CheckBoxAutomationPeer(box).GetPattern(PatternInterface.Toggle)!).Toggle();
        void Space(CheckBox box) {
            foreach (var routedEvent in new[] { Keyboard.PreviewKeyDownEvent, Keyboard.PreviewKeyUpEvent })
                InputManager.Current.ProcessInput(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(box), Environment.TickCount, Key.Space) { RoutedEvent = routedEvent });
        }
        CheckBox[] Options() => CheatList.Children.OfType<CheckBox>().ToArray();
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!;
        void Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var stream = File.Create(Path.Combine(output, name + ".png")); encoder.Save(stream);
        }
        try {
            timer.Stop();
            settings.EnabledCheats.Clear(); settings.CheatsEnabled = false;
            GamePicker.SelectedValue = "file1"; ShowPage("Cheats");
            await Task.Delay(400);
            HideStatusToast();
            await Task.Delay(350);
            if (args.Contains("--test-owned-game-font"))
                Check(((FontFamily)Application.Current.Resources["GameDisplayFont"]).Source.Contains(GameFont.FamilyName),
                      "The page uses the verified owned game dialogue font");
            Check(Options().Length == 6 && CheatGame.Text.EndsWith("#1"), "File #1 displays its six built-in cheats with the correct edition");
            Check(Options().All(c => AutomationProperties.GetName(c).Length > 0 && AutomationProperties.GetHelpText(c).Length > 0),
                  "Cheat names and explanations are available to assistive technology");
            Check(AutomationProperties.GetHelpText(Options()[3]).Contains("Saving"), "Unlock everything explains that saving can retain the unlocks");
            Toggle(EnableCheats);
            Check(settings.CheatsEnabled && Stored().CheatsEnabled, "The master switch persists through native UI automation");
            var health = Options()[0]; var ammo = Options()[2];
            Toggle(health); Toggle(ammo);
            Check(Stored().EnabledCheats.Contains("builtin.file1.health") && Stored().EnabledCheats.Contains("builtin.file1.ammo") &&
                  CheatSelectionState.Text == "2 selected", "Individual cheat choices persist and update the visible selection count");
            var points = Options().Single(c => (string)c.Tag == "builtin.file1.points");
            var escape = Options().Single(c => (string)c.Tag == "builtin.file1.escape");
            Toggle(points); Toggle(escape);
            Check(Stored().EnabledCheats.Contains("builtin.file1.points") && Stored().EnabledCheats.Contains("builtin.file1.escape") &&
                  CheatSelectionState.Text == "4 selected", "File #1 points and escape options persist through the native checkboxes");
            string manifestFolder = Path.Combine(output, "manifests");
            Directory.CreateDirectory(manifestFolder);
            var manifest = File.ReadAllLines(Cheats.Export(settings, manifestFolder));
            Check(manifest.Contains("builtin points") && manifest.Contains("builtin escape") && !manifest.Contains("builtin unlock"),
                  "File #1 exports the selected points and escape operations without enabling unlock everything");
            Toggle(points); Toggle(escape);
            Check(StatusToast.Visibility == Visibility.Collapsed, "Routine cheat selections stay quiet without obscuring the options");
            health.Focus(); await Task.Delay(100);
            Check(health.IsKeyboardFocused && ((Border)health.Template.FindName("Row", health)).BorderBrush == FindResource("Ink"),
                  "Keyboard focus visibly outlines the entire cheat row");
            Capture("keyboard-focus");
            Space(health);
            Check(health.IsChecked == false && !Stored().EnabledCheats.Contains("builtin.file1.health"), "Space toggles the focused cheat and saves the change");
            Space(health);
            Toggle(EnableCheats);
            Check(!Stored().CheatsEnabled && Stored().EnabledCheats.Count == 2 && health.IsChecked == true && ammo.IsChecked == true &&
                  CheatSelectionState.Text == "2 selected", "Disabling cheats preserves selections and their count while the master switch shows the inactive state");
            NavCheats.Focus(); Capture("disabled-master");
            Toggle(EnableCheats); NavCheats.Focus(); Capture("file1-selected");
            SetLaunching(true); UpdateCheatState();
            bool blocked = false;
            try { Toggle(health); } catch (ElementNotEnabledException) { blocked = true; }
            Check(blocked && !EnableCheats.IsEnabled && CheatSessionNote.IsVisible && health.IsChecked == true,
                  "Launching locks all cheat editing, preserves choices and shows the reason");
            Capture("locked-during-launch");
            SetLaunching(false); UpdateCheatState();
            Check(health.IsEnabled && EnableCheats.IsEnabled && !CheatSessionNote.IsVisible, "Cheat editing returns when launching finishes");
            string? previousMode = settings.CoopMode;
            foreach (string mode in new[] { "host", "join" }) {
                settings.CoopMode = mode; UpdateCheatState();
                Check(CheatSessionNote.IsVisible && CheatSessionNote.Text.Contains("Unlock everything") &&
                      CheatSessionNote.Text.Contains("Play alone") && EnableCheats.IsEnabled,
                      mode + " explains online progression unlocks without locking selection edits");
            }
            settings.CoopMode = previousMode; UpdateCheatState();
            Width = MinWidth; Height = MinHeight; await Task.Delay(300); UpdateLayout();
            SettingsScroll.ScrollToTop(); await Task.Delay(100); Capture("compact-file1-top");
            SettingsScroll.ScrollToEnd(); await Task.Delay(100);
            Capture("compact-file1");
            var importPosition = CheatFileActions.TranslatePoint(new Point(), SettingsScroll);
            Check(PageCheats.ActualWidth <= SettingsScroll.ViewportWidth + 1 && importPosition.Y >= 0 &&
                  importPosition.Y + CheatFileActions.ActualHeight <= SettingsScroll.ViewportHeight + 1,
                  "All six built-ins remain readable and native vertical scrolling reaches import controls at minimum window size without horizontal overflow");
            GamePicker.SelectedValue = "file2"; await Task.Delay(200);
            Check(Options().Length == 6 && Options().All(c => ((string)c.Tag).StartsWith("builtin.file2.")) && CheatGame.Text.EndsWith("#2"),
                  "Switching games shows only File #2 built-ins and updates the edition");
            Toggle(Options()[0]);
            Check(Stored().EnabledCheats.Contains("builtin.file2.health") && Stored().EnabledCheats.Contains("builtin.file1.ammo"),
                  "File #2 selections preserve the saved File #1 choices");
            Toggle(Options().Single(c => (string)c.Tag == "builtin.file2.points"));
            Toggle(Options().Single(c => (string)c.Tag == "builtin.file2.escape"));
            Check(Stored().EnabledCheats.Contains("builtin.file2.points") && Stored().EnabledCheats.Contains("builtin.file2.escape") &&
                  Stored().EnabledCheats.Contains("builtin.file1.ammo"), "File #2 points and escape choices preserve the independent File #1 selection");
            var secondManifest = File.ReadAllLines(Cheats.Export(settings, manifestFolder));
            Check(secondManifest.SequenceEqual(new[] { "REO-CHEATS-2", "builtin health", "builtin points", "builtin escape" }),
                  "File #2 exports only its selected health, points and escape operations");
            SettingsScroll.ScrollToEnd(); await Task.Delay(100);
            Capture("compact-file2");
            GamePicker.SelectedValue = "file1"; Width = 1320; Height = 920;
            Directory.CreateDirectory(Path.GetDirectoryName(fixture)!);
            await File.WriteAllTextAsync(fixture, "[Extra item test]\ndescription=An imported cheat description stays with its option.\npatch=1,EE,00400000,word,00000001\n[Unsupported pointer test]\npatch=1,EE,E0000000,extended,00000001\n");
            RefreshCheats(); await Task.Delay(200);
            var imported = Options().Where(c => !((string)c.Tag).StartsWith("builtin.")).ToArray();
            Check(imported.Length == 2 && imported[0].IsEnabled && !imported[1].IsEnabled &&
                  AutomationProperties.GetHelpText(imported[1]).Contains("Line"), "Imported groups stay separate and unsupported codes remain disabled with a reason");
            Toggle(imported[0]);
            Check(Stored().EnabledCheats.Contains((string)imported[0].Tag), "Imported cheat choices still persist through the redesigned controls");
            SettingsScroll.ScrollToEnd(); await Task.Delay(100); Capture("imported-cheats");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            SetLaunching(false);
            if (File.Exists(fixture)) File.Delete(fixture);
            if (saved == null) File.Delete(settingsPath); else File.WriteAllBytes(settingsPath, saved);
            Close();
        }
    }
}
