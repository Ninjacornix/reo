using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestGameFilesUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        var ownedDirectories = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        async Task Wait(Func<bool> condition) {
            for (int i = 0; i < 400 && !condition(); i++) await Task.Delay(25);
            Check(condition(), "The selected file state settles without starting setup"); UpdateLayout();
        }
        void Toggle(CheckBox box) => ((IToggleProvider)new CheckBoxAutomationPeer(box).GetPattern(PatternInterface.Toggle)!).Toggle();
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed; UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Game-files diagnostics require an isolated data home");
            timer.Stop(); settings.CoopMode = "offline";
            settings.ImportedFile1 = settings.ImportedFile2 = "";
            GamePicker.SelectedValue = "file1";
            string firstIso = Path.Combine(output, "selected disc with spaces.iso");
            string firstExe = Path.Combine(output, "completed build with spaces", "reo_recomp.exe");
            Directory.CreateDirectory(Path.GetDirectoryName(firstExe)!);
            File.WriteAllBytes(firstIso, new byte[64]); File.WriteAllBytes(firstExe, new byte[] { 1, 2, 3 });
            settings.SetFile("iso", firstIso); settings.SetFile("exe", firstExe);
            discCheck = null; RefreshGameUi(); ShowPage("Setup");
            await Wait(() => !checkingDisc && discCheck?.Matches(firstIso, "file1") == true);
            await Task.Delay(400); UpdateLayout();
            Check(GameFilesEdition.Text == "FILE #1" && IsoPath.Text == firstIso && SelectedBuildPath.Text == firstExe &&
                ExePath.Text == firstExe && StoragePath.Text == Settings.Home && GameFilesBuildState.Text == "Build available",
                "The disc, build and shared storage panels show their actual selected paths and file availability");
            Check(IsoPath.IsReadOnly && SelectedBuildPath.IsReadOnly && StoragePath.IsReadOnly &&
                new TextBoxAutomationPeer(IsoPath).GetPattern(PatternInterface.Value) is IValueProvider { IsReadOnly: true },
                "Paths remain selectable and accessible without becoming editable settings fields");
            Check(discCheck!.Ok == false && DiscValidationStatus.IsVisible && !ImportDiscButton.IsEnabled,
                "A real invalid ISO check shows its error and keeps import disabled in the new layout");
            Check(ChooseIsoButton.IsEnabled && ExistingBuildButton.IsEnabled && ChooseStorageButton.IsEnabled &&
                OpenStorageButton.IsEnabled && SupportedDiscHint.Text.Contains("20765"),
                "Disc selection, existing-build import and storage actions remain available for the selected edition");
            SettingsScroll.ScrollToTop(); Capture("game-files-invalid-disc");

            var isoInfo = new FileInfo(firstIso);
            discCheck = new("file1", firstIso, isoInfo.Length, isoInfo.LastWriteTimeUtc.Ticks, true, "Verified disc fixture");
            RefreshImportUi();
            Check(ImportDiscButton.IsEnabled == settings.FilesPresent(root),
                "A verified-disc state uses the existing import eligibility rules rather than a decorative enabled button");
            string fixture = Path.Combine(Settings.Home, "local-games", "file1", "game-files-ui-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(fixture); File.WriteAllBytes(Path.Combine(fixture, "fixture.bin"), new byte[128]); ownedDirectories.Add(fixture);
            string toolsFixture = Path.Combine(Settings.Home, "toolchains", "game-files-ui-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(toolsFixture); File.WriteAllBytes(Path.Combine(toolsFixture, "fixture.bin"), new byte[64]); ownedDirectories.Add(toolsFixture);
            await EstimateRemoval();
            Check(RemoveGameButton.IsEnabled && RemoveSize.Text.Contains("Frees about"),
                "Removal measures real fixture files and retains its confirmation action");
            Toggle(RemoveSaves); Toggle(RemoveTools); await Wait(() => RemoveSize.Text != "Measuring...");
            Check(RemoveSaves.IsChecked == true && RemoveTools.IsChecked == true &&
                GameRemoval.Targets(root, settings, "file1", true, true).Any(t => t.Path == Path.Combine(Settings.Home, "toolchains")) &&
                File.Exists(Path.Combine(fixture, "fixture.bin")),
                "Removal switches update their existing targets without deleting or moving any files");
            Toggle(RemoveSaves); Toggle(RemoveTools); await Wait(() => RemoveSize.Text != "Measuring...");
            SettingsScroll.ScrollToTop(); Capture("game-files");

            SetLaunching(true); RefreshGameUi();
            Check(!ChooseIsoButton.IsEnabled && !ImportDiscButton.IsEnabled && !ExistingBuildButton.IsEnabled &&
                !ChooseStorageButton.IsEnabled && !RemoveGameButton.IsEnabled && !RemoveSaves.IsEnabled && !DeveloperFiles.IsEnabled,
                "Launch preparation locks imports, storage moves, developer paths and removal together");
            SetLaunching(false); RefreshGameUi();
            Check(ChooseIsoButton.IsEnabled && ExistingBuildButton.IsEnabled && GameRemovalControls.IsEnabled,
                "The file actions recover after launch preparation ends");
            var progress = BeginDiscImport(); RefreshGameUi();
            progress.Report(new(50, 100, "Isolated progress fixture", "Importing disc"));
            await Task.Delay(100);
            Check(ImportActivity.IsVisible && SetupStage.Text == "Importing disc" && DiscProgress.Value == 50 &&
                !DiscFileActions.IsEnabled && !GameRemovalControls.IsEnabled,
                "The existing setup progress display stays connected while file actions are locked");
            EndDiscImport(); RefreshGameUi();
            Check(!ImportActivity.IsVisible && DiscFileActions.IsEnabled, "Completing setup restores the file actions and clears progress");

            string sharedStorage = StoragePath.Text;
            GamePicker.SelectedValue = "file2";
            string secondIso = Path.Combine(output, "second disc with spaces.iso");
            settings.SetFile("iso", secondIso); settings.SetFile("exe", Path.Combine(output, "missing-file2-build.exe"));
            discCheck = null; RefreshGameUi(); await EstimateRemoval();
            Check(GameFilesEdition.Text == "FILE #2" && IsoPath.Text == secondIso && SelectedBuildPath.Text == settings.GetExe() &&
                GameFilesBuildState.Text == "No build selected" && SupportedDiscHint.Text.Contains("20984") && StoragePath.Text == sharedStorage,
                "File #2 gets its own disc, build and required revision while retaining the shared storage folder");
            SettingsScroll.ScrollToTop(); Capture("game-files-file2");
            GamePicker.SelectedValue = "file1"; RefreshGameUi();
            Check(IsoPath.Text == firstIso && SelectedBuildPath.Text == firstExe && GameFilesEdition.Text == "FILE #1",
                "Switching back preserves File #1's selected disc and build");
            DeveloperFiles.Visibility = Visibility.Visible;
            ((IExpandCollapseProvider)new ExpanderAutomationPeer(DeveloperFiles).GetPattern(PatternInterface.ExpandCollapse)!).Expand();
            await Task.Delay(100);
            Check(ExePath.IsVisible && ElfPath.IsVisible && BrowseExeButton.IsEnabled && BrowseElfButton.IsEnabled,
                "Developer files retain the native executable and ELF browsing actions in the shared dropdown style");
            DeveloperFiles.IsExpanded = false;
            Width = MinWidth; Height = MinHeight; await Task.Delay(200); UpdateLayout();
            Check(PageSetup.ActualWidth <= SettingsScroll.ViewportWidth + 1 && IsoPath.ActualWidth >= 290 && StoragePath.ActualWidth >= 250 &&
                StoragePath.TranslatePoint(new Point(StoragePath.ActualWidth, 0), PageSetup).X <= PageSetup.ActualWidth + 1,
                "Disc/build and storage/removal columns fit horizontally at minimum window size");
            RemoveGameButton.BringIntoView(); await Task.Delay(100);
            var removePosition = RemoveGameButton.TranslatePoint(new Point(), SettingsScroll);
            Check(removePosition.Y >= 0 && removePosition.Y + RemoveGameButton.ActualHeight <= SettingsScroll.ViewportHeight + 1,
                "Maintenance actions remain reachable by scrolling in a compact window");
            Capture("game-files-compact");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks,
                scope = "Real controls, invalid ISO validation, file-path binding, removal estimates and progress presentation with isolated fixtures. No disc imports, game builds, storage moves or game removals were performed."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            if (importCancellation != null) EndDiscImport();
            SetLaunching(false); timer.Stop(); audioSaveTimer.Stop(); colorSaveTimer.Stop();
            Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
            foreach (string folder in ownedDirectories) {
                File.Delete(Path.Combine(folder, "fixture.bin")); Directory.Delete(folder, false);
            }
        }
    }
}
