using Avalonia;
using Avalonia.Layout;
using Path = System.IO.Path;
using Avalonia.Controls;
using Avalonia.Controls.Shapes;
using Avalonia.Controls.Primitives;
using Avalonia.Automation;
using Avalonia.Input;
using Avalonia.Interactivity;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Outbreak.Launcher.Desktop.Compatibility;
using BitmapSource = Avalonia.Media.Imaging.Bitmap;
using PointCollection = Avalonia.Points;
using System.Diagnostics;
using System.IO;

namespace Outbreak.Launcher.Desktop;
public partial class MainWindow {
    string cheatsGame = "";
    IReadOnlyList<CheatGroup> cheatGroups = Array.Empty<CheatGroup>();
    bool refreshingCheats;
    void ReloadCheats(object sender, RoutedEventArgs e) => RefreshCheats();
    void RefreshCheats() {
        cheatsGame = Settings.Game.Id;
        CheatGame.Text = Settings.Game.Id == "file1" ? "OUTBREAK / FILE #1" : "OUTBREAK / FILE #2";
        refreshingCheats = true;
        EnableCheats.IsChecked = Settings.CheatsEnabled;
        refreshingCheats = false;
        CheatList.Children.Clear();
        cheatGroups = Array.Empty<CheatGroup>();
        try {
            var groups = Cheats.Load(Settings.Game.Id);
            cheatGroups = groups;
            if (groups.Count == 0)
                CheatList.Children.Add(new TextBlock { Text = "No cheats imported.",
                                                       Margin = new Thickness(0, 18, 0, 0) });
            bool? builtinSection = null;
            int number = 0;
            foreach (var g in groups) {
                bool builtin = g.Builtin != null;
                if (builtinSection != builtin) {
                    CheatList.Children.Add(new TextBlock { Text = builtin ? "Built-in cheats" : "Imported cheats",
                        Foreground = VisualPalette.Brush(Palette.TextMuted), FontSize = 14,
                        Margin = new Thickness(0, builtinSection == null ? 0 : 14, 0, 5) });
                    builtinSection = builtin;
                }
                var content = new Grid();
                content.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(34) });
                content.ColumnDefinitions.Add(new ColumnDefinition());
                content.Children.Add(new TextBlock { Text = (++number).ToString("00"), FontSize = 14,
                    Foreground = VisualPalette.Brush(Palette.TextMuted), VerticalAlignment = VerticalAlignment.Center });
                var text = new StackPanel { VerticalAlignment = VerticalAlignment.Center };
                Grid.SetColumn(text, 1);
                content.Children.Add(text);
                text.Children.Add(new TextBlock { Text = g.Name, FontSize = 18, TextWrapping = TextWrapping.Wrap });
                var toggle =
                    new CheckBox { Content = content, IsEnabled = g.Supported,
                                   IsChecked = g.Supported && Settings.EnabledCheats.Contains(g.Id),
                                   Tag = g.Id, Style = (Compatibility.Style)FindResource("CheatOption") };
                AutomationProperties.SetName(toggle, g.Name);
                AutomationProperties.SetHelpText(toggle, g.Supported ? g.Description : g.Error);
                toggle.IsCheckedChanged += CheatToggled;

                string detail = g.Supported          ? g.Description
                                : g.Error.Length > 0 ? g.Error
                                                     : "No supported patch lines.";
                if (detail.Length > 0)
                    text.Children.Add(new TextBlock { Text = detail,
                                                     Style = (Compatibility.Style)FindResource("Hint"),
                                                     FontSize = 14, LineHeight = 20,
                                                     TextWrapping = TextWrapping.Wrap,
                                                     Margin = new Thickness(0, 3, 0, 0) });
                CheatList.Children.Add(toggle);
            }
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
        UpdateCheatLayout();
        UpdateCheatState();
    }
    void UpdateCheatLayout() {
        bool compact = (Bounds.Height > 0 ? Bounds.Height : Height) < 760;
        foreach (var option in CheatList.Children.OfType<CheckBox>()) {
            option.MinHeight = compact ? 54 : 64;
            option.Padding = new Thickness(12, compact ? 5 : 9, 12, compact ? 5 : 9);
        }
    }
    void UpdateCheatState() {
        bool locked = game.Running || busy;
        CheatControls.IsEnabled = !locked;
        CheatSessionNote.Visibility = locked ? Visibility.Visible : Visibility.Collapsed;
        CheatSessionNote.Text = "Stop the game to change cheats. Your selections are preserved.";
        int selected = cheatGroups.Count(g => g.Supported && Settings.EnabledCheats.Contains(g.Id));
        CheatSelectionState.Text = $"{selected} selected";
    }
    void CheatToggled(object sender, RoutedEventArgs e) {
        if (!initialized || refreshingCheats || game.Running || busy)
            return;
        var box = (CheckBox)sender;
        if (box.Tag is string id) {
            Settings.EnabledCheats.RemoveAll(x => x == id);
            if (box.IsChecked == true)
                Settings.EnabledCheats.Add(id);
        } else
            Settings.CheatsEnabled = box.IsChecked == true;
        try {
            Settings.Save();
            UpdateCheatState();
            RefreshGameUi();
        } catch (IOException error) {
            Status.Text = error.Message;
        }
    }
    async void ImportCheats(object sender, RoutedEventArgs e) {
        var dialog =
            new OpenFileDialog { Filter = "PCSX2 cheats (*.pnach)|*.pnach", Multiselect = true };
        if (await dialog.ShowDialog(this) != true)
            return;
        try {
            string folder = Cheats.Folder(Settings.Game.Id);
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
        string folder = Cheats.Folder(Settings.Game.Id);
        Directory.CreateDirectory(folder);
        Process.Start(new ProcessStartInfo(folder) { UseShellExecute = true });
    }
}
