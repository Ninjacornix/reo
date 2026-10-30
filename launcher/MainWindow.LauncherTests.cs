using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestLauncherUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        Settings Stored() => Settings.Load(root);
        void Select(ComboBox picker, string value) {
            var item = picker.Items.Cast<ComboBoxItem>().Single(item => (string)item.Tag == value);
            var peer = new ComboBoxAutomationPeer(picker);
            var menu = (IExpandCollapseProvider)peer.GetPattern(PatternInterface.ExpandCollapse)!;
            menu.Expand(); UpdateLayout();
            var option = peer.GetChildren().Single(child => child.GetName() == (string)item.Content);
            ((ISelectionItemProvider)option.GetPattern(PatternInterface.SelectionItem)!).Select();
            menu.Collapse();
        }
        string Font() => ((FontFamily)Application.Current.Resources["GameDisplayFont"]).Source;
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed; UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Launcher UI diagnostics use isolated storage");
            timer.Stop();
            await Task.Delay(350);
            ((IInvokeProvider)new ButtonAutomationPeer(NavLauncher).GetPattern(PatternInterface.Invoke)!).Invoke();
            await Task.Delay(450);
            Capture("launcher-navigation");
            Check(currentPage == "Launcher" && PageLauncher.IsVisible && !PageGraphics.IsVisible &&
                System.Windows.Controls.Primitives.Selector.GetIsSelected(NavLauncher),
                $"The Launcher navigation button opens and selects its own settings page (page={currentPage}, visible={PageLauncher.IsVisible}, selected={System.Windows.Controls.Primitives.Selector.GetIsSelected(NavLauncher)})");
            var navigation = (Panel)NavLauncher.Parent;
            Check(navigation.Children.IndexOf(NavLauncher) + 1 == navigation.Children.IndexOf(NavLogs),
                "Launcher appears immediately above Log");
            Check(PageLauncher.IsAncestorOf(LauncherBackgroundMovies) && !PageGraphics.IsAncestorOf(LauncherBackgroundMovies),
                "The existing movie setting has moved from Graphics into Launcher");
            Check(LauncherLanguagePicker.Items.Count == 1 && (string)LauncherLanguagePicker.SelectedValue == "en",
                "The language menu offers English only");

            foreach (string font in new[] { "segoe-ui", "tahoma", "outbreak" }) {
                Select(LauncherFontPicker, font); await Task.Delay(150);
                string expected = font == "tahoma" ? "Tahoma" : font == "segoe-ui" ? "Segoe UI" :
                    ownedGameFont?.Source ?? "Segoe UI";
                Check(Font() == expected && Stored().ResolvedLauncherFont == font,
                    font + " applies immediately and survives settings reload");
                Check(DebugLog.FontFamily.Source == "Consolas", "Log output stays Consolas when choosing " + font);
            }
            Capture("launcher-outbreak");
            Select(LauncherFontPicker, "tahoma");
            // A game-font completion must respect the user's current selection.
            bool hasOwnedFontData = new[] { "file1", "file2" }.Any(id =>
                File.Exists(Path.Combine(settings.ImportFolder(id), "data", "NETBIO00.DAT")));
            ownedGameFont = null; gameFontLoaded = false; gameFontRequest = "";
            RefreshGameFont(); await Task.Delay(250);
            for (int i = 0; hasOwnedFontData && !gameFontLoaded && i < 150; i++) await Task.Delay(20);
            Check(Font() == "Tahoma" && (!hasOwnedFontData || gameFontLoaded),
                "An actual owned-font completion cannot overwrite the selected system font");
            object appliedFont = Application.Current.Resources["GameDisplayFont"];
            RefreshGameUi();
            Check(ReferenceEquals(appliedFont, Application.Current.Resources["GameDisplayFont"]),
                "Routine game-state refreshes retain the font resource without forcing text reflow");
            GamePicker.SelectedValue = settings.Game.Id == "file1" ? "file2" : "file1";
            await Task.Delay(200);
            Check(Font() == "Tahoma" && (string)LauncherFontPicker.SelectedValue == "tahoma",
                "Font choice is shared across both game editions");
            Capture("launcher-tahoma");
            bool originalMovies = LauncherBackgroundMovies.IsChecked == true;
            var toggle = (IToggleProvider)new CheckBoxAutomationPeer(LauncherBackgroundMovies).GetPattern(PatternInterface.Toggle)!;
            toggle.Toggle();
            Check(Stored().LauncherBackgroundMovies == !originalMovies,
                "The relocated movie switch persists through actual toggle automation");
            toggle.Toggle();
            Check(Stored().LauncherBackgroundMovies == originalMovies,
                "The movie switch restores its prior value");
            Check(Stored().LauncherLanguage == "en", "English persists with appearance preferences");
            Select(LauncherFontPicker, "outbreak");
            Width = MinWidth; Height = MinHeight; await Task.Delay(350); UpdateLayout();
            Check(PageLauncher.ActualWidth <= SettingsScroll.ViewportWidth + 1 &&
                LauncherLanguagePicker.TranslatePoint(new Point(LauncherLanguagePicker.ActualWidth,
                    LauncherLanguagePicker.ActualHeight), SettingsScroll).Y <= SettingsScroll.ViewportHeight + 1,
                "Launcher settings fit at the minimum supported window size");
            NavDeveloper.BringIntoView(); await Task.Delay(150); UpdateLayout();
            Check(NavigationScroll.ViewportHeight > 0 &&
                NavDeveloper.TranslatePoint(new Point(0, NavDeveloper.ActualHeight), NavigationScroll).Y <= NavigationScroll.ActualHeight + 1 &&
                NavigationScroll.TranslatePoint(new Point(0, NavigationScroll.ActualHeight), this).Y <
                    UpdateButton.TranslatePoint(new Point(), this).Y,
                "All navigation remains reachable at minimum height without overlapping Check for updates");
            Capture("launcher-compact");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks,
                scope = "Real WPF navigation, selection and toggle automation, persisted settings reload, shared font resources, and compact-window layout. No game launches."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            timer.Stop(); audioSaveTimer.Stop(); colorSaveTimer.Stop(); Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
        }
    }
}
