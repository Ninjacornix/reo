using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool refreshingOriginalAssetOptions;
    readonly Dictionary<string, string> originalAssetFolders = new();
    void RefreshOriginalAssetExportUi() {
        refreshingOriginalAssetOptions = true;
        try {
            ExportOriginalAssets.IsChecked = settings.WantsOriginalAssetPaks();
            bool idle = !game.Running && !launching && !updating && !updateRestarting && !backingUp && importCancellation == null;
            OriginalAssetOptions.IsEnabled = idle;
            CleanOldImportsButton.IsEnabled = idle;
            ExportOriginalAssets.IsEnabled = idle && !settings.UsesGamePak();
            ExportOriginalAssetsNow.IsEnabled = idle && DiscImport.Ready(settings);
            OpenOriginalAssetExports.IsEnabled = Directory.Exists(AssetExports.GameFolder(settings.Game.Id));
        } finally { refreshingOriginalAssetOptions = false; }
    }
    void OriginalAssetOptionChanged(object sender, RoutedEventArgs e) {
        if (!initialized || refreshingOriginalAssetOptions || game.Running || launching || importCancellation != null) return;
        try {
            settings.SetOriginalAssetExport(ExportOriginalAssets.IsChecked == true);
            settings.Save();
            Status.Text = settings.WantsOriginalAssetPaks() ? "Original assets will be exported during setup." : "Original asset export is optional. Use Export now after importing.";
        } catch (IOException error) { Status.Text = error.Message; }
    }
    async void ExportOriginalAssetsClicked(object sender, RoutedEventArgs e) {
        if (updating || updateRestarting || game.Running || launching || backingUp || importCancellation != null || !DiscImport.Ready(settings)) return;
        SetLaunching(true);
        try {
            var progress = BeginDiscImport(); RefreshGameUi();
            string imported = settings.ImportFolder();
            var disc = new ImportedDisc(imported, Path.Combine(imported, "data", settings.Game.ElfName), 0, 0, true);
            var result = await AssetExports.Ensure(disc, settings.Game.Id, progress, importCancellation!.Token);
            settings.RememberGamePak(result); settings.Save();
            originalAssetFolders[settings.Game.Id] = result.Root;
            Status.Text = $"{result.Entries:N0} original assets {(result.Reused ? "already exported" : "exported")}. Use Open exports folder.";
        } catch (OperationCanceledException) { Status.Text = "Asset export canceled. Game files and completed exports are kept."; }
        catch (Exception error) { Status.Text = "Original asset export failed: " + error.Message; }
        finally { SetLaunching(false); EndDiscImport(); RefreshGameUi(); }
    }
    void OpenOriginalAssetExportsClicked(object sender, RoutedEventArgs e) {
        string folder = originalAssetFolders.GetValueOrDefault(settings.Game.Id) ?? AssetExports.GameFolder(settings.Game.Id);
        if (!Directory.Exists(folder)) return;
        try { Process.Start(new ProcessStartInfo(folder) { UseShellExecute = true }); }
        catch (Exception error) when (error is IOException or System.ComponentModel.Win32Exception) { Status.Text = error.Message; }
    }
}
