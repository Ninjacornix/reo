using Microsoft.Win32;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string cheatsGame = "";
    void ReloadCheats(object sender, RoutedEventArgs e) => RefreshCheats();
    void RefreshCheats() {
        cheatsGame = settings.Game.Id;
        CheatGame.Text = settings.Game.Name;
        CheatControls.IsEnabled = settings.Game.Id == "file1" && !game.Running && !launching;
        EnableCheats.IsChecked = settings.CheatsEnabled;
        CheatList.Children.Clear();
        if (settings.Game.Id == "file2") {
            Status.Text =
                "Cheats are not available for File #2 yet.";
            return;
        }
        try {
            var groups = Cheats.Load(settings.Game.Id);
            if (groups.Count == 0)
                CheatList.Children.Add(new TextBlock { Text = "No cheats imported.",
                                                       Margin = new Thickness(0, 18, 0, 0) });
            foreach (var g in groups) {
                var row = new StackPanel { Margin = new Thickness(0, 10, 0, 10) };
                var toggle =
                    new CheckBox { Content = g.Name, IsEnabled = g.Supported,
                                   IsChecked = g.Supported && settings.EnabledCheats.Contains(g.Id),
                                   Tag = g.Id };
                toggle.Click += CheatToggled;
                row.Children.Add(toggle);
                string detail = g.Supported          ? ""
                                : g.Error.Length > 0 ? g.Error
                                                     : "No supported patch lines.";
                if (detail.Length > 0)
                    row.Children.Add(new TextBlock { Text = detail,
                                                     Style = (Style)FindResource("Hint"),
                                                     TextWrapping = TextWrapping.Wrap,
                                                     Margin = new Thickness(25, 5, 0, 0) });
                CheatList.Children.Add(row);
            }
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
    }
    void CheatToggled(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching)
            return;
        var box = (CheckBox)sender;
        if (box.Tag is string id) {
            settings.EnabledCheats.RemoveAll(x => x == id);
            if (box.IsChecked == true)
                settings.EnabledCheats.Add(id);
        } else
            settings.CheatsEnabled = box.IsChecked == true;
        try {
            settings.Save();
            Status.Text = "Cheats saved. Apply on next launch.";
        } catch (IOException error) {
            Status.Text = error.Message;
        }
    }
    void ImportCheats(object sender, RoutedEventArgs e) {
        var dialog =
            new OpenFileDialog { Filter = "PCSX2 cheats (*.pnach)|*.pnach", Multiselect = true };
        if (dialog.ShowDialog(this) != true)
            return;
        try {
            string folder = Cheats.Folder(settings.Game.Id);
            Directory.CreateDirectory(folder);
            foreach (string file in dialog.FileNames) {
                if (new FileInfo(file).Length > 1024 * 1024)
                    throw new IOException("Cheat file exceeds 1 MB.");
                string text = File.ReadAllText(file);
                Cheats.Parse(text, Path.GetFileName(file));
                string target = Path.Combine(folder, Path.GetFileName(file));
                if (File.Exists(target) &&
                    !string.Equals(file, target, StringComparison.OrdinalIgnoreCase))
                    throw new IOException(
                        "A cheat file with that name already exists. Rename it before importing.");
                if (!string.Equals(file, target, StringComparison.OrdinalIgnoreCase))
                    File.WriteAllText(target, text);
            }
            RefreshCheats();
            Status.Text = "Imported. Select the cheats to enable.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
    }
    void OpenCheatFolder(object sender, RoutedEventArgs e) {
        string folder = Cheats.Folder(settings.Game.Id);
        Directory.CreateDirectory(folder);
        Process.Start(new ProcessStartInfo(folder) { UseShellExecute = true });
    }
}
