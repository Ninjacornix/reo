using System.IO;

namespace Outbreak.Launcher;
public static class AppLayout {
    public static bool Packaged(string root) => File.Exists(Path.Combine(root,
                                                                         "distribution.json"));
    public static string FindRoot(string start) {
        for (var folder = new DirectoryInfo(start); folder != null; folder = folder.Parent)
            if (Packaged(folder.FullName) ||
                (Directory.Exists(Path.Combine(folder.FullName, "recomp")) &&
                 File.Exists(Path.Combine(folder.FullName, "CMakeLists.txt"))))
                return Path.TrimEndingDirectorySeparator(folder.FullName);
        throw new DirectoryNotFoundException("The launcher installation is incomplete. Extract " +
                                             "the complete release archive to a folder.");
    }
    public static string Native(string root, string game) =>
        Packaged(root) ? LocalGameBuild.TargetPath(root, game)
                       : Path.Combine(root, "build-ninja", "recomp",
                                      game == "file2" ? "reo_recomp_file2.exe" : "reo_recomp.exe");
    public static string Work(string root, string game) => Path.Combine(Settings.Home, "play", game);
}
public sealed partial class Settings {
    public string ImportedFile1 { get; set; } = "";
    public string ImportedFile2 { get; set; } = "";
    public string ImportFolder(string? game = null) => (game ?? Game.Id) == "file2" ? ImportedFile2
                                                                                    : ImportedFile1;
    public void SetImport(string folder) {
        if (Game.Id == "file2")
            ImportedFile2 = folder;
        else
            ImportedFile1 = folder;
    }
}
