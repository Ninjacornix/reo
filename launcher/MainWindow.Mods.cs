using Microsoft.Win32;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string modsGame = "";
    List<InstalledAssetPak> installedAssetPaks = new();
    void RefreshAssetPakSummary() {
        int count = installedAssetPaks.Count(p => p.Manifest?.Game == settings.Game.Id && settings.EnabledAssetPaks.Contains(p.Manifest.Id));
        PlayAssetSummary.Text = count == 0 ? "None" : count + (count == 1 ? " asset pack" : " asset packs") + " · Solo play";
    }
    void UpdateRandomizerSeed() {
        ModSeed.Text = game.RandomizerSeedSummary ?? "";
        ModSeed.Visibility = game.RandomizerSeedSummary == null ? Visibility.Collapsed : Visibility.Visible;
    }
    void ReloadMods(object sender, RoutedEventArgs e) => RefreshMods();
    void RefreshMods() {
        modsGame = settings.Game.Id;
        UpdateRandomizerSeed();
        ModControls.IsEnabled = !game.Running && !launching;
        ModList.Children.Clear();
        try {
            if (!game.Running && !launching && Mods.ConsolidateRandomizers(settings)) settings.Save();
            var installed = Mods.Load(game: settings.Game.Id);
            var shown = new HashSet<string>();
            foreach (var mod in installed) {
                var m = mod.Manifest;
                string? id = m?.Id;
                bool enabled = id != null && settings.ActiveMods.Contains(id);
                var row = new StackPanel { Margin = new Thickness(0, 10, 0, 10) };
                var toggle = new CheckBox {
                    Content = m == null ? Path.GetFileName(mod.File) : $"{m.Name} · {m.Version}",
                    IsChecked = enabled, IsEnabled = settings.Game.Id == "file1" && m != null && (mod.Error.Length == 0 || enabled), Tag = id
                };
                toggle.Click += ModToggled;
                row.Children.Add(toggle);
                row.Children.Add(new TextBlock {
                    Text = mod.Error.Length > 0 ? mod.Error : m!.Description,
                    Style = (Style)FindResource("Hint"), TextWrapping = TextWrapping.Wrap,
                    Margin = new Thickness(25, 5, 0, 0)
                });
                ModList.Children.Add(row);
                if (id != null) shown.Add(id);
            }
            foreach (string id in settings.ActiveMods.Where(x => !shown.Contains(x)).Distinct()) {
                var toggle = new CheckBox {
                    Content = id + " — missing or invalid; untick to disable", IsChecked = true,
                    Tag = id, Margin = new Thickness(0, 10, 0, 10)
                };
                toggle.Click += ModToggled;
                ModList.Children.Add(toggle);
            }
            var assetPaks = AssetPaks.Load();
            installedAssetPaks = assetPaks;
            RefreshAssetPakSummary();
            foreach (var pak in assetPaks) {
                var manifest = pak.Manifest;
                if (manifest != null && manifest.Game != settings.Game.Id) continue;
                string? id = manifest?.Id;
                bool enabled = id != null && settings.EnabledAssetPaks.Contains(id);
                var row = new StackPanel { Margin = new Thickness(0, 10, 0, 10) };
                var toggle = new CheckBox {
                    Content = manifest == null ? Path.GetFileName(pak.File) : $"{manifest.Name} · {manifest.Version} · {manifest.Replace.Count} assets · {manifest.Strings.Count} strings",
                    IsChecked = enabled, IsEnabled = manifest != null && (pak.Error.Length == 0 || enabled), Tag = id
                };
                toggle.Checked += AssetPakToggled;
                toggle.Unchecked += AssetPakToggled;
                row.Children.Add(toggle);
                row.Children.Add(new TextBlock { Text = pak.Error.Length > 0 ? pak.Error : manifest!.Description,
                    Style = (Style)FindResource("Hint"), TextWrapping = TextWrapping.Wrap, Margin = new Thickness(25, 5, 0, 0) });
                ModList.Children.Add(row);
            }
            foreach (string id in settings.EnabledAssetPaks.Where(id => !assetPaks.Any(p => p.Manifest?.Id == id)).Distinct()) {
                var toggle = new CheckBox { Content = id + " — missing or invalid asset pack; untick to disable",
                    IsChecked = true, Tag = id, Margin = new Thickness(0, 10, 0, 10) };
                toggle.Checked += AssetPakToggled; toggle.Unchecked += AssetPakToggled;
                ModList.Children.Add(toggle);
            }
            if (ModList.Children.Count == 0)
                ModList.Children.Add(new TextBlock { Text = "No mods installed. Import a .pak asset pack or mod JSON file to start.",
                    TextWrapping = TextWrapping.Wrap, Margin = new Thickness(0, 16, 0, 16) });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
    }
    void AssetPakToggled(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching || ((CheckBox)sender).Tag is not string id) return;
        settings.EnabledAssetPaks.RemoveAll(value => value == id);
        if (((CheckBox)sender).IsChecked == true) settings.EnabledAssetPaks.Add(id);
        try { settings.Save(); Status.Text = "Asset packs saved. Changes apply on next solo launch."; }
        catch (IOException error) { Status.Text = error.Message; }
        RefreshMods();
    }
    void ModToggled(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching) return;
        var box = (CheckBox)sender;
        if (box.Tag is not string id) return;
        settings.ActiveMods.RemoveAll(x => x == id);
        if (box.IsChecked == true) settings.ActiveMods.Add(id);
        try {
            settings.Save();
            Status.Text = "Mods saved. Changes apply on next launch.";
        } catch (IOException error) { Status.Text = error.Message; }
        RefreshMods();
    }
    async void ImportMod(object sender, RoutedEventArgs e) {
        if (game.Running || launching || updating || updateRestarting || backingUp || importCancellation != null) return;
        var dialog = new OpenFileDialog { Filter = "Outbreak mods (*.pak;*.json)|*.pak;*.json|Asset packs (*.pak)|*.pak|JSON mods (*.json)|*.json" };
        if (dialog.ShowDialog(this) != true) return;
        string source = dialog.FileName;
        launching = true;
        try {
            var progress = BeginDiscImport(); RefreshGameUi();
            progress.Report(new(0, 0, "Reading edited assets and translations", "Importing mod"));
            var cancel = importCancellation!.Token;
            await Task.Run(() => {
                if (Path.GetExtension(source).Equals(".pak", StringComparison.OrdinalIgnoreCase)) AssetPaks.Import(source, cancel: cancel);
                else Mods.Import(source, game: settings.Game.Id);
            }, cancel);
            Status.Text = "Mod imported. Tick it to enable.";
        } catch (OperationCanceledException) { Status.Text = "Mod import canceled. Previous mods are kept.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        } finally { launching = false; EndDiscImport(); RefreshGameUi(); }
        RefreshMods();
    }
    void OpenModFolder(object sender, RoutedEventArgs e) {
        try {
            Directory.CreateDirectory(Mods.FolderFor(settings.Game.Id));
            Directory.CreateDirectory(AssetPaks.Folder);
            Process.Start(new ProcessStartInfo(Path.GetDirectoryName(AssetPaks.Folder)!) { UseShellExecute = true });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or System.ComponentModel.Win32Exception) {
            Status.Text = error.Message;
        }
    }
}
