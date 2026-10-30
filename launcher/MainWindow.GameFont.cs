using System.IO;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string gameFontRequest = "";
    bool gameFontLoaded;
    FontFamily? ownedGameFont;
    async void RefreshGameFont() {
        // This is the launcher's shared typeface. Keep the first validated owned
        // font across edition changes; swapping to Segoe UI and back reflows every
        // control, description and button while the next font loads.
        ApplyLauncherFont();
        if (gameFontLoaded) return;
        string edition = new[] { settings.Game.Id, "file1", "file2" }.Distinct()
            .FirstOrDefault(id => File.Exists(Path.Combine(settings.ImportFolder(id), "data", "NETBIO00.DAT")))
            ?? settings.Game.Id;
        string import = settings.ImportFolder(edition);
        string request = edition + "|" + import + "|" + Settings.Home;
        if (request == gameFontRequest) return;
        gameFontRequest = request;
        if (!File.Exists(Path.Combine(import, "data", "NETBIO00.DAT"))) return;
        try {
            string path = await Task.Run(() => GameFont.Ensure(import, edition, Settings.Home));
            if (gameFontRequest != request) return;
            var font = GameFont.Load(path);
            if (new Typeface(font, System.Windows.FontStyles.Normal, System.Windows.FontWeights.Normal,
                System.Windows.FontStretches.Normal).TryGetGlyphTypeface(out var face) &&
                face.FamilyNames.Values.Contains(GameFont.FamilyName)) {
                ownedGameFont = font;
                gameFontLoaded = true;
                ApplyLauncherFont();
            }
        } catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or
                                               ArgumentException or NotSupportedException or System.IO.FileFormatException) {
            // Font extraction is optional: setup and ordinary launcher text stay usable.
        }
    }
}
