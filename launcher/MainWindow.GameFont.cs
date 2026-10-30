using System.IO;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string gameFontRequest = "";
    async void RefreshGameFont() {
        string edition = settings.Game.Id, import = settings.ImportFolder(edition);
        string request = edition + "|" + import + "|" + Settings.Home;
        if (request == gameFontRequest) return;
        gameFontRequest = request;
        System.Windows.Application.Current.Resources["GameDisplayFont"] = new FontFamily("Segoe UI");
        if (!File.Exists(Path.Combine(import, "data", "NETBIO00.DAT"))) return;
        try {
            string path = await Task.Run(() => GameFont.Ensure(import, edition, Settings.Home));
            if (gameFontRequest != request) return;
            var font = GameFont.Load(path);
            if (new Typeface(font, System.Windows.FontStyles.Normal, System.Windows.FontWeights.Normal,
                System.Windows.FontStretches.Normal).TryGetGlyphTypeface(out var face) &&
                face.FamilyNames.Values.Contains(GameFont.FamilyName)) System.Windows.Application.Current.Resources["GameDisplayFont"] = font;
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                               ArgumentException or NotSupportedException or System.IO.FileFormatException) {
            // Font extraction is optional: setup and ordinary launcher text stay usable.
        }
    }
}
