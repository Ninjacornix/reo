using Microsoft.Win32;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string modsGame = "";
    void ReloadMods(object sender, RoutedEventArgs e) => RefreshMods();
    void RefreshMods() {
        modsGame = settings.Game.Id;
        ModControls.IsEnabled = settings.Game.Id == "file1" && !game.Running && !launching;
        ModList.Children.Clear();
        ModHelp.Text = settings.Game.Id == "file1"
            ? "Import a mod, then tick it to enable for solo or hosting. Joining uses the host's randomizer settings automatically. Changes apply on the next launch; effects and data patches are solo only."
            : "Mods will be available for File #2 when its native build is supported.";
        try {
            if (!game.Running && !launching && Mods.ConsolidateRandomizers(settings)) settings.Save();
            var installed = Mods.Load();
            var shown = new HashSet<string>();
            foreach (var mod in installed) {
                var m = mod.Manifest;
                string? id = m?.Id;
                bool enabled = id != null && settings.EnabledMods.Contains(id);
                var row = new StackPanel { Margin = new Thickness(0, 10, 0, 10) };
                var toggle = new CheckBox {
                    Content = m == null ? Path.GetFileName(mod.File) : $"{m.Name} · {m.Version}",
                    IsChecked = enabled, IsEnabled = m != null && (mod.Error.Length == 0 || enabled), Tag = id
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
            foreach (string id in settings.EnabledMods.Where(x => !shown.Contains(x)).Distinct()) {
                var toggle = new CheckBox {
                    Content = id + " — missing or invalid; untick to disable", IsChecked = true,
                    Tag = id, Margin = new Thickness(0, 10, 0, 10)
                };
                toggle.Click += ModToggled;
                ModList.Children.Add(toggle);
            }
            if (ModList.Children.Count == 0)
                ModList.Children.Add(new TextBlock { Text = "No mods installed. Import a mod JSON file to start.",
                    TextWrapping = TextWrapping.Wrap, Margin = new Thickness(0, 16, 0, 16) });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            ModHelp.Text = error.Message;
        }
    }
    void ModToggled(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching) return;
        var box = (CheckBox)sender;
        if (box.Tag is not string id) return;
        settings.EnabledMods.RemoveAll(x => x == id);
        if (box.IsChecked == true) settings.EnabledMods.Add(id);
        try {
            settings.Save();
            Status.Text = "Mods saved. Changes apply on next launch.";
        } catch (IOException error) { Status.Text = error.Message; }
        RefreshMods();
    }
    void ImportMod(object sender, RoutedEventArgs e) {
        if (game.Running || launching) return;
        var dialog = new OpenFileDialog { Filter = "Outbreak mod (*.json)|*.json" };
        if (dialog.ShowDialog(this) != true) return;
        try {
            Mods.Import(dialog.FileName);
            Status.Text = "Mod imported. Tick it to enable.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
        RefreshMods();
    }
    void OpenModFolder(object sender, RoutedEventArgs e) {
        try {
            Directory.CreateDirectory(Mods.Folder);
            Process.Start(new ProcessStartInfo(Mods.Folder) { UseShellExecute = true });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or System.ComponentModel.Win32Exception) {
            Status.Text = error.Message;
        }
    }
}
