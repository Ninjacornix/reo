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
    async Task TestNavigationUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        var restricted = new[] { NavGraphics, NavAudio, NavController, NavSaves, NavCoop, NavMods, NavCheats, NavDeveloper };
        var unrestricted = new[] { NavPlay, NavLauncher, NavSetup, NavLogs };
        void Check(bool valid, string text) { if (!valid) throw new IOException(text); checks.Add(text); }
        void Invoke(Button button) => ((IInvokeProvider)new ButtonAutomationPeer(button).GetPattern(PatternInterface.Invoke)!).Invoke();
        void Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        string Install(string edition, bool pak = false) {
            settings.SelectedGame = edition;
            string folder = Path.Combine(output, edition + (pak ? "-pak" : "-iso"));
            Directory.CreateDirectory(Path.Combine(folder, "data"));
            string source = Path.Combine(folder, pak ? "game.pak" : "game.iso");
            File.WriteAllText(source, "Navigation fixture source");
            string exe = Path.Combine(folder, "game.exe");
            File.WriteAllText(exe, "Navigation fixture executable");
            File.WriteAllText(Path.Combine(folder, "data", settings.Game.ElfName), "Navigation fixture ELF");
            if (edition == "file2") settings.UseGamePakFile2 = pak; else settings.UseGamePakFile1 = pak;
            settings.SetGameSource(source); settings.SetFile("exe", exe); settings.SetImport(folder);
            var file = new FileInfo(source);
            File.WriteAllText(Path.Combine(folder, "import.json"), JsonSerializer.Serialize(new ImportManifest(
                pak ? 2 : 1, edition, file.FullName, file.Length, file.LastWriteTimeUtc.Ticks,
                DiscImport.ExpectedElf(edition), Array.Empty<ImportedFile>())));
            return exe;
        }
        try {
            Check(args.Contains("--data-home"), "Navigation diagnostics use an isolated data home");
            timer.Stop(); settings.LauncherBackgroundMovies = false;
            settings.Exe = settings.SecondExe = settings.Iso = settings.SecondIso = "";
            settings.ImportedFile1 = settings.ImportedFile2 = "";
            settings.UseGamePakFile1 = settings.UseGamePakFile2 = false;
            settings.SelectedGame = "file1"; ShowPage("Play"); RefreshGameUi();
            Check(currentPage == "Play" && restricted.All(b => !b.IsEnabled) && unrestricted.All(b => b.IsEnabled),
                "A fresh launch exposes only Play, Launcher, Game files and Log");
            foreach (var button in restricted) {
                bool rejected = false;
                try { Invoke(button); } catch (ElementNotEnabledException) { rejected = true; }
                Check(rejected && !button.Focus() && currentPage == "Play",
                    button.Name + " rejects activation and keyboard focus before installation");
            }
            await Task.Delay(350); Capture("fresh-launch");
            foreach (var button in unrestricted) {
                Invoke(button); await Task.Delay(100);
                Check(currentPage == (string)button.Tag, button.Name + " remains navigable without a game");
            }
            string first = Install("file1");
            settings.ImportedFile1 = ""; RefreshGameUi();
            Check(restricted.All(b => !b.IsEnabled), "An ISO and executable without a completed import do not unlock game sections");
            settings.ImportedFile1 = Path.GetDirectoryName(first)!; RefreshGameUi();
            Check(restricted.All(b => b.IsEnabled), "Completing File #1 installation enables every game section automatically");
            settings.SelectedGame = "file2"; RefreshGameUi();
            Invoke(NavAudio); await Task.Delay(350);
            Check(currentPage == "Audio" && restricted.All(b => b.IsEnabled),
                "An installed File #1 keeps sections available when selecting the uninstalled File #2");
            Capture("game-installed");
            File.Delete(first); RefreshGameUi();
            Check(restricted.All(b => !b.IsEnabled) && currentPage == "Play" && NavPlay.IsKeyboardFocused,
                "Removing the last installed build disables game sections and moves the active page and focus to Play");
            string second = Install("file2", pak: true);
            settings.SelectedGame = "file1"; RefreshGameUi();
            Check(restricted.All(b => b.IsEnabled), "A File #2 PAK installation alone unlocks sections even with File #1 selected");
            File.Delete(second); RefreshGameUi();
            Check(restricted.All(b => !b.IsEnabled) && unrestricted.All(b => b.IsEnabled),
                "Removing the only File #2 installation restores the fresh-launch navigation");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
            Close();
        }
    }
}
