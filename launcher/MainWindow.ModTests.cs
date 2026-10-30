using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestModsUi(string output) {
        Directory.CreateDirectory(output);
        string settingsPath = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(settingsPath) ? File.ReadAllBytes(settingsPath) : null;
        string id = "fixture.randomizer-" + Guid.NewGuid().ToString("N");
        var ownedFiles = new List<string>(); var checks = new List<string>();
        void Check(bool ok, string message) { if (!ok) throw new IOException(message); checks.Add(message); }
        async Task Wait(Func<bool> condition) {
            for (int i = 0; i < 150 && !condition(); i++) await Task.Delay(20);
            Check(condition(), "The mod action completes and refreshes the visible library");
        }
        void Invoke(Button button) => ((IInvokeProvider)new ButtonAutomationPeer(button).GetPattern(PatternInterface.Invoke)!).Invoke();
        void Toggle(CheckBox box) => ((IToggleProvider)new CheckBoxAutomationPeer(box).GetPattern(PatternInterface.Toggle)!).Toggle();
        void Expand(Expander expander) => ((IExpandCollapseProvider)new ExpanderAutomationPeer(expander).GetPattern(PatternInterface.ExpandCollapse)!).Expand();
        void Collapse(Expander expander) => ((IExpandCollapseProvider)new ExpanderAutomationPeer(expander).GetPattern(PatternInterface.ExpandCollapse)!).Collapse();
        void Seed(ModRow row, string text) => ((IValueProvider)new TextBoxAutomationPeer(row.SeedInput!).GetPattern(PatternInterface.Value)!).SetValue(text);
        ModRow Randomizer() => modRows.Single(r => r.Mod.Manifest?.Id == id);
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!;
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed;
            UpdateLayout(); var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32); bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Mod diagnostics require an isolated data home");
            timer.Stop(); settings.CoopMode = "offline"; settings.ActiveMods.Clear();
            settings.ModConfigurations = new();
            foreach (string edition in new[] { "file1", "file2" }) {
                string sample = edition == "file1" ? "randomizer.json" : "randomizer-file2.json";
                var mod = Mods.Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "examples", "mods", sample)));
                mod.Id = id;
                string path = Path.Combine(Mods.FolderFor(edition), id + ".json"); Directory.CreateDirectory(Path.GetDirectoryName(path)!);
                File.WriteAllText(path, JsonSerializer.Serialize(mod, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase })); ownedFiles.Add(path);
            }
            string originalPackage = File.ReadAllText(ownedFiles[0]);
            GamePicker.SelectedValue = "file1"; ShowPage("Mods"); await Task.Delay(500);
            if (args.Contains("--test-owned-game-font"))
                Check(((FontFamily)Application.Current.Resources["GameDisplayFont"]).Source.Contains(GameFont.FamilyName), "Mods uses the owned game display font");
            var row = Randomizer();
            Check(ModGame.Text == "FILE #1" && !ModSelectionState.Text.Contains("Next launch"),
                "The mod header shows only the selected file and the enabled count");
            Check(row.Options != null && !row.Options.IsExpanded && row.SeedMode!.SelectedIndex == 0,
                  "Randomizer starts with collapsed Options and automatic seeds");
            Toggle(row.Toggle);
            Check(Stored().ActiveMods.Contains(id) && ModSelectionState.Text.StartsWith("1 enabled"), "Native mod toggle persists selection and updates its count");
            Expand(row.Options!); await Task.Delay(100);
            Check(row.Options!.IsExpanded && !row.CustomSeedRow!.IsVisible, "Native dropdown expansion reveals seed mode and keeps custom input hidden in automatic mode");
            var optionsHeader = (ToggleButton)row.Options.Template.FindName("OptionsToggle", row.Options);
            optionsHeader.Focus();
            void SpaceOptions() {
                foreach (var routedEvent in new[] { Keyboard.KeyDownEvent, Keyboard.KeyUpEvent })
                    optionsHeader.RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this), Environment.TickCount, Key.Space) { RoutedEvent = routedEvent });
            }
            Check(optionsHeader.IsKeyboardFocused && ((Border)optionsHeader.Template.FindName("HeaderRow", optionsHeader)).BorderBrush == FindResource("Ink"),
                  "Options dropdown has a visible native keyboard focus outline");
            SpaceOptions();
            Check(!row.Options.IsExpanded, "Space collapses the focused options dropdown");
            SpaceOptions();
            Check(row.Options.IsExpanded, "Space reopens the focused options dropdown");
            Capture("automatic-seed");
            row.SeedMode!.SelectedIndex = 1;
            Check(row.CustomSeedRow!.IsVisible && row.SeedInput!.IsEnabled && Stored().ConfigurationFor(id).UseCustomSeed,
                  "Choosing Custom seed reveals an enabled input and saves the mode");
            Seed(row, "356353");
            Check(Stored().ConfigurationFor(id).Seed == 356353 && row.Summary!.Text.Contains("356353"),
                  "Native seed input persists its value and updates the collapsed summary");
            var launch = new RandomizerSeeds().ForLaunch(Mods.Selected(settings), "offline",
                () => throw new InvalidOperationException("Custom input was ignored"), settings.ActiveModConfigurations);
            Check(launch.Single().ItemRandomizer!.Seed == 356353 && launch.Single().EnemyRandomizer!.Seed == 356353,
                  "The saved UI configuration supplies the actual launch seed to both items and enemies");
            var host = RandomizerSession.Parse(RandomizerSession.Create("reo01", launch));
            Check(host.Items!.Seed == 356353 && host.Enemies!.Seed == 356353, "Host publication carries the configured seed unchanged");
            Check(File.ReadAllText(ownedFiles[0]) == originalPackage, "Seed configuration leaves the installed package and weighted pool unchanged");
            NavMods.Focus(); Capture("custom-seed-file1");
            Collapse(row.Options!); await Task.Delay(100); Capture("collapsed-options");
            Check(!row.Options!.IsExpanded && row.Summary!.Text.Contains("356353"), "Collapsed options retain the visible custom seed summary");
            Expand(row.Options!);
            Seed(row, "4294967295"); Check(Stored().ConfigurationFor(id).Seed == uint.MaxValue, "Custom seed accepts the full unsigned 32-bit maximum");
            Seed(row, "4294967296");
            Check(row.SeedError!.IsVisible && Stored().ConfigurationFor(id).Seed == uint.MaxValue && ModConfigurationProblem() != null,
                  "An overflowing draft is explained inline, preserves the saved seed and blocks launch");
            LaunchGame(this, new RoutedEventArgs()); await Task.Delay(100);
            Check(!launching && !game.Running && currentPage == "Mods", "An invalid enabled seed cannot start a game");
            Capture("invalid-seed");
            Seed(row, ""); Check(row.SeedError!.IsVisible && ModConfigurationProblem() != null, "An empty custom seed remains an explicit validation error");
            row.SeedMode.SelectedIndex = 0;
            Check(!row.SeedError!.IsVisible && !row.CustomSeedRow!.IsVisible && ModConfigurationProblem() == null && Stored().ConfigurationFor(id).Seed == uint.MaxValue,
                  "Automatic mode clears draft errors while remembering the custom value");
            row.SeedMode.SelectedIndex = 1; Seed(row, "356353");
            Check(!row.SeedError!.IsVisible && ModConfigurationProblem() == null, "Correcting the custom seed restores launch readiness");
            Toggle(row.Toggle); Toggle(row.Toggle);
            Check(ReferenceEquals(row, Randomizer()) && row.Options!.IsExpanded && row.SeedInput!.Text == "356353",
                  "Toggling the mod preserves the open dropdown and edited seed");
            RefreshMods(); row = Randomizer();
            Check(row.Options!.IsExpanded && row.SeedMode!.SelectedIndex == 1 && row.SeedInput!.Text == "356353", "Reloading mods restores options without discarding saved configuration");
            GamePicker.SelectedValue = "file2"; await Task.Delay(350); row = Randomizer();
            Check(row.SeedMode!.SelectedIndex == 0 && row.Toggle.IsChecked == false && ModGame.Text.EndsWith("#2"),
                  "File #2 has independent enabled and seed preferences for the same mod ID");
            Toggle(row.Toggle); Expand(row.Options!); row.SeedMode.SelectedIndex = 1; Seed(row, "42");
            Check(Stored().ConfigurationFor(id).Seed == 42, "File #2 custom seed saves independently");
            Capture("custom-seed-file2");
            GamePicker.SelectedValue = "file1"; await Task.Delay(350); row = Randomizer();
            Check(row.SeedInput!.Text == "356353" && row.SeedMode!.SelectedIndex == 1 && row.Toggle.IsChecked == true,
                  "Switching back restores File #1's custom seed and selection");
            Width = MinWidth; Height = MinHeight; await Task.Delay(250); SettingsScroll.ScrollToEnd(); await Task.Delay(100);
            var inputPosition = row.SeedInput.TranslatePoint(new Point(), SettingsScroll);
            var importPosition = ImportModButton.TranslatePoint(new Point(), SettingsScroll);
            Check(PageMods.ActualWidth <= SettingsScroll.ViewportWidth + 1 && inputPosition.X >= 0 &&
                  inputPosition.X + row.SeedInput.ActualWidth <= SettingsScroll.ViewportWidth + 1 && importPosition.Y >= 0 &&
                  importPosition.Y + ImportModButton.ActualHeight <= SettingsScroll.ViewportHeight + 1,
                  "Expanded options fit horizontally at minimum size and import actions remain reachable by scrolling");
            StatusToast.Visibility = Visibility.Collapsed; Capture("compact-options");
            SetLaunching(true); UpdateModState(); bool blocked = false;
            try { Seed(row, "100"); } catch (ElementNotEnabledException) { blocked = true; }
            Check(blocked && !row.Toggle.IsEnabled && ModSessionNote.IsVisible && settings.ConfigurationFor(id).Seed == 356353,
                  "Launching locks configuration and mod toggles without losing saved values");
            SetLaunching(false); settings.CoopMode = "join"; UpdateModState();
            Check(ModSessionNote.Text.Contains("host's") && row.SeedInput.IsEnabled, "Join mode explains host authority while allowing local preferences to be saved");
            var joined = new RandomizerSeeds().ForLaunch(RandomizerSession.ModsFor(host), "join", configurations: settings.ActiveModConfigurations);
            Check(joined.Single().ItemRandomizer!.Seed == 356353 && Mods.Selected(settings).Count == 0,
                  "Joining uses the host snapshot instead of selecting local packages");
            settings.CoopMode = "offline"; UpdateModState();
            Invoke(row.Delete); await Wait(() => row.DeleteConfirmation?.IsVisible == true);
            Check(File.ReadAllText(ownedFiles[0]) == originalPackage && settings.ActiveMods.Contains(id),
                "Delete opens a confirmation without changing the package or enabled state");
            Capture("delete-confirmation");
            Invoke(row.CancelDelete!); await Wait(() => row.DeleteConfirmation?.IsVisible == false);
            Check(settings.ConfigurationFor(id).Seed == 356353 && File.Exists(ownedFiles[0]),
                "Cancel preserves the original package and custom seed");
            SetLaunching(true); UpdateModState(); DeleteMod(row);
            Check(!row.Delete.IsEnabled && File.Exists(ownedFiles[0]), "Mod deletion is disabled and refused during game launch");
            SetLaunching(false); UpdateModState();
            var oldRow = row;
            Invoke(row.Delete); await Wait(() => row.DeleteConfirmation?.IsVisible == true);
            GamePicker.SelectedValue = "file2"; DeleteMod(oldRow);
            Check(File.Exists(ownedFiles[0]) && File.Exists(ownedFiles[1]),
                "A stale confirmation cannot delete a package after switching editions");
            GamePicker.SelectedValue = "file1"; row = Randomizer();
            bool saveBlocked = false;
            using (new FileStream(settingsPath, FileMode.Open, FileAccess.Read, FileShare.Read)) {
                try { Mods.Delete(settings, row.Mod); }
                catch (Exception error) when (error is IOException or UnauthorizedAccessException) { saveBlocked = true; }
            }
            Check(saveBlocked && settings.ActiveMods.Contains(id) && settings.ConfigurationFor(id).Seed == 356353 &&
                File.ReadAllText(ownedFiles[0]) == originalPackage,
                "A settings-save failure preserves the enabled package and its seed before recycling anything");
            bool wrongEdition = false;
            try { Mods.Delete(settings, Mods.Load(game: "file2").Single(m => m.Manifest?.Id == id)); }
            catch (IOException) { wrongEdition = true; }
            Check(wrongEdition && File.Exists(ownedFiles[1]), "Deletion rejects a package belonging to the other game's folder");
            Invoke(row.Delete); await Wait(() => row.DeleteConfirmation?.IsVisible == true);
            Invoke(row.ConfirmDelete!); await Wait(() => !File.Exists(ownedFiles[0]));
            var afterDelete = Stored();
            Check(!afterDelete.ActiveMods.Contains(id) && !afterDelete.ActiveModConfigurations.ContainsKey(id) &&
                afterDelete.File2EnabledMods.Contains(id) && afterDelete.ModConfigurations["file2"][id].Seed == 42 &&
                File.Exists(ownedFiles[1]) && !modRows.Any(r => r.Mod.Manifest?.Id == id),
                "Deleting an enabled mod recycles its package and clears only this edition's selection and seed");
            GamePicker.SelectedValue = "file2"; row = Randomizer();
            Check(row.Toggle.IsChecked == true && row.SeedInput!.Text == "42" && ModGame.Text == "FILE #2",
                "The other edition retains its installed package, enabled state and independent seed");
            Invoke(row.Delete); await Wait(() => row.DeleteConfirmation?.IsVisible == true);
            Invoke(row.ConfirmDelete!); await Wait(() => !File.Exists(ownedFiles[1]));
            Check(!Stored().File2EnabledMods.Contains(id) && !Stored().ActiveModConfigurations.ContainsKey(id),
                "File #2 deletion also clears its own persisted selection and configuration");
            GamePicker.SelectedValue = "file1";
            File.WriteAllText(ownedFiles[0], originalPackage);
            string duplicate = Path.Combine(Mods.FolderFor("file1"), id + ".duplicate.json");
            File.WriteAllText(duplicate, originalPackage); ownedFiles.Add(duplicate);
            settings.ActiveMods.Add(id); settings.SetConfiguration(id, new() { UseCustomSeed = true, Seed = 123 }); settings.Save(); RefreshMods();
            var duplicateRow = modRows.Single(r => r.Mod.File == duplicate);
            Invoke(duplicateRow.Delete); await Wait(() => duplicateRow.DeleteConfirmation?.IsVisible == true);
            Invoke(duplicateRow.ConfirmDelete!); await Wait(() => !File.Exists(duplicate));
            Check(File.Exists(ownedFiles[0]) && Stored().ActiveMods.Contains(id) && Stored().ConfigurationFor(id).Seed == 123 &&
                Mods.Selected(settings).Single().Id == id,
                "Deleting one duplicate package preserves the remaining enabled mod and its configuration");
            settings.CoopMode = "offline"; settings.ActiveMods.Add("fixture.missing"); RefreshMods();
            var missing = modRows.Single(r => r.Missing); Toggle(missing.Toggle);
            Check(!settings.ActiveMods.Contains("fixture.missing") && !missing.Toggle.IsEnabled,
                  "A missing enabled package can be disabled but cannot be re-enabled accidentally");
            settings.ActiveMods.Add("fixture.missing"); settings.SetConfiguration("fixture.missing", new() { Seed = 99 }); settings.Save(); RefreshMods();
            missing = modRows.Single(r => r.Missing);
            Invoke(missing.Delete); await Wait(() => missing.DeleteConfirmation?.IsVisible == true);
            Invoke(missing.ConfirmDelete!); await Wait(() => !modRows.Any(r => r.Missing));
            Check(!Stored().ActiveMods.Contains("fixture.missing") && !Stored().ActiveModConfigurations.ContainsKey("fixture.missing"),
                "Removing a missing entry clears its stale enabled state and configuration");
            string invalid = Path.Combine(Mods.FolderFor("file1"), "ui-invalid-" + Guid.NewGuid().ToString("N") + ".json");
            File.WriteAllText(invalid, "{ invalid JSON }"); ownedFiles.Add(invalid); RefreshMods();
            Check(modRows.Any(r => r.Mod.Manifest == null && !r.Toggle.IsEnabled && r.Mod.Error.Length > 0 && r.Options == null),
                  "Invalid packages keep a visible reason and never expose configuration or enable controls");
            var invalidRow = modRows.Single(r => r.Mod.File == invalid);
            Invoke(invalidRow.Delete); await Wait(() => invalidRow.DeleteConfirmation?.IsVisible == true);
            Invoke(invalidRow.ConfirmDelete!); await Wait(() => !File.Exists(invalid));
            Check(!modRows.Any(r => r.Mod.File == invalid), "Invalid JSON packages can be deleted through the same confirmed action");
            foreach (string path in ownedFiles) File.Delete(path);
            settings.ActiveMods.Clear(); RefreshMods();
            Check(modRows.Count == 0 && ModList.Children.OfType<TextBlock>().Any(t => t.Text.StartsWith("No mods installed")) && ImportModButton.IsEnabled,
                  "Empty mod library retains import and recovery controls");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            SetLaunching(false); settings.CoopMode = "offline";
            foreach (string path in ownedFiles) if (File.Exists(path)) File.Delete(path);
            if (saved == null) File.Delete(settingsPath); else File.WriteAllBytes(settingsPath, saved);
            Close();
        }
    }
}
