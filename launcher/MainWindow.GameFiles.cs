using System.IO;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string removalUiEdition = "";
    void RefreshGameFilesUi() {
        GameFilesEdition.Text = settings.Game.Id == "file2" ? "FILE #2" : "FILE #1";
        string executable = settings.GetExe();
        SelectedBuildPath.Text = executable;
        GameFilesBuildState.Text = File.Exists(executable) ? "Build available" : "No build selected";
        bool idle = !updating && !updateRestarting && !game.Running && !launching && !backingUp &&
                    importCancellation == null && !storageChanging;
        DiscFileActions.IsEnabled = BuildFileActions.IsEnabled = GameRemovalControls.IsEnabled = idle;
        DeveloperFiles.IsEnabled = idle;
        if (IsLoaded && PageSetup.IsVisible && removalUiEdition != settings.Game.Id) {
            removalUiEdition = settings.Game.Id;
            _ = EstimateRemoval();
        }
    }
}
