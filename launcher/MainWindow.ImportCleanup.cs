using System.IO;
using System.Windows;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async void CleanOldImports(object sender, RoutedEventArgs e) {
        if (game.Running || launching || updating || updateRestarting || backingUp || importCancellation != null) {
            Status.Text = "Close the game and wait for setup to finish before cleaning old imports."; return;
        }
        string gameId = settings.Game.Id;
        launching = true; RefreshGameUi();
        try {
            Status.Text = "Checking older game imports...";
            var items = await Task.Run(() => StaleImports.Find(settings, gameId));
            if (items.Count == 0) { Status.Text = "No old completed imports to clean. Selected imports are kept."; return; }
            string list = string.Join("\n", items.Select(i => Path.GetFileName(i.Source) + " — " + Gigabytes(i.Bytes) + "\n" + Path.GetFileName(i.Path)));
            if (MessageBox.Show(this, $"Delete {items.Count} old imports for {GameDefinition.Find(gameId).Name}?\n\n" + list +
                $"\n\nEstimated size: {Gigabytes(items.Sum(i => i.Bytes))}.\nSelected imports, source ISOs/PAKs, saves, exports and mods are kept. " +
                "Playing an older revision again needs its source ISO or PAK to import again.",
                "Clean up old imports", MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No) != MessageBoxResult.Yes) {
                Status.Text = "Old imports kept."; return;
            }
            Status.Text = "Removing reviewed old imports...";
            var failed = await Task.Run(() => StaleImports.Remove(items, settings, gameId));
            Status.Text = $"Removed {items.Count - failed.Count} old imports." +
                (failed.Count == 0 ? " Selected game files are kept." : " Some imports were kept because they changed, are protected or are in use.");
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) { Status.Text = error.Message; }
        finally { launching = false; RefreshGameUi(); }
    }
}
