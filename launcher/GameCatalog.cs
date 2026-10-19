using System.IO;

namespace Outbreak.Launcher;
public record GameDefinition(string Id, string Name, string ElfName, string DataFolder,
                             string PlayFolder) {
    public static readonly GameDefinition First =
        new("file1", "Outbreak: File #1", "SLUS_207.65", "game_data", "play");
    public static readonly GameDefinition Second =
        new("file2", "Outbreak: File #2", "SLUS_209.84", "game_data_file2", "play-file2");
    public static GameDefinition Find(string id) => id == "file2" ? Second : First;
}
public sealed partial class Settings {
    public string SelectedGame { get; set; } = "file1";
    public string Elf { get; set; } = "";
    public string SecondExe { get; set; } = "";
    public string SecondIso { get; set; } = "";
    public string SecondElf { get; set; } = "";
    [System.Text.Json.Serialization.JsonIgnore]
    public GameDefinition Game => GameDefinition.Find(SelectedGame);
    public string GetExe(string? gameId = null) => (gameId ?? Game.Id) == "file2" ? SecondExe : Exe;
    public string GetIso(string? gameId = null) => (gameId ?? Game.Id) == "file2" ? SecondIso : Iso;
    public string GetElf(string root, string? gameId = null) {
        var definition = GameDefinition.Find(gameId ?? Game.Id);
        if (DiscImport.Ready(this, definition.Id))
            return Path.Combine(ImportFolder(definition.Id), "data", definition.ElfName);
        string explicitPath = definition.Id == "file2" ? SecondElf : Elf;
        return explicitPath.Length != 0
                   ? explicitPath
                   : Path.Combine(root, definition.DataFolder, definition.ElfName);
    }
    public void SetFile(string kind, string value) {
        bool second = Game.Id == "file2";
        if (kind == "exe") {
            if (second)
                SecondExe = value;
            else
                Exe = value;
        } else if (kind == "iso") {
            if (second)
                SecondIso = value;
            else
                Iso = value;
        } else {
            if (second)
                SecondElf = value;
            else
                Elf = value;
        }
    }
    public bool FilesPresent(string root, string? gameId = null) =>
        (AppLayout.Packaged(root) ? LocalGameBuild.Available(root) : File.Exists(GetExe(gameId))) &&
        File.Exists(GetIso(gameId));
}
