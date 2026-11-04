using System.IO;

namespace Outbreak.Launcher;

// "Remove game": deletes what the launcher created for a game in its storage folder. The player's
// ISO, the launcher folder and settings stay; saves and shared build tools only on request.
internal static class GameRemoval {
    public sealed record Target(string Path, string What);

    public static List<Target> Targets(string root, Settings settings, string game, bool saves,
                                       bool tools, string? home = null) {
        home ??= Settings.Home;
        var targets = new List<Target> {
            new(Path.Combine(home, "local-games", game), "built game and compile cache"),
            new(Path.Combine(home, "imports", game), "imported disc data"),
            new(Path.Combine(home, "play", game), "game working folder"),
            new(Path.Combine(home, "game-cache"), "prepared game image"),
            new(Path.Combine(home, "build-kits"), "unpacked build files"),
        };
        if (saves) {
            // Cards can contain saves for both games, including upgraded legacy
            // defaults. Keep the card and shared metadata; remove only this title.
            string managed = Path.GetFullPath(Path.Combine(home, "memory-cards"));
            string prefix = game == "file2" ? "BASLUS-20984" : "BASLUS-20765";
            void AddTitleSaves(string folder) {
                folder = Path.GetFullPath(folder);
                if (!folder.StartsWith(managed + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) ||
                    !Directory.Exists(folder)) return;
                for (var entry = new DirectoryInfo(folder); entry != null; entry = entry.Parent) {
                    if (entry.Attributes.HasFlag(FileAttributes.ReparsePoint)) return;
                    if (entry.FullName.Equals(managed, StringComparison.OrdinalIgnoreCase)) break;
                }
                targets.AddRange(Directory.EnumerateDirectories(folder)
                    .Where(path => Path.GetFileName(path).StartsWith(prefix, StringComparison.OrdinalIgnoreCase))
                    .Select(path => new Target(path, "this game's save data")));
            }
            AddTitleSaves(Path.Combine(managed, "default", game, "data"));
            AddTitleSaves(Path.Combine(managed, "default", "data"));
            AddTitleSaves(settings.CardFolder(root));
        }
        if (tools)
            foreach (string name in new[] { "toolchains", "server-python", "server-python-runtime",
                                            "server-tools", "media-tools" })
                targets.Add(new(Path.Combine(home, name), "build and hosting tools"));
        return targets.Where(t => Directory.Exists(t.Path))
                   .GroupBy(t => Path.GetFullPath(t.Path), StringComparer.OrdinalIgnoreCase)
                   .Select(g => g.First())
                   .ToList();
    }

    public static long Size(IEnumerable<Target> targets) =>
        targets.Sum(t => {
            try {
                return new DirectoryInfo(t.Path).EnumerateFiles("*", SearchOption.AllDirectories)
                    .Sum(f => f.Length);
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
                return 0L;
            }
        });

    // Returns folders that could not be removed (for example, files in use).
    public static List<string> Remove(IEnumerable<Target> targets) {
        var failed = new List<string>();
        foreach (var target in targets) {
            try {
                if ((File.GetAttributes(target.Path) & FileAttributes.ReparsePoint) != 0)
                    Directory.Delete(target.Path); // never follow a link out of launcher storage
                else
                    Directory.Delete(target.Path, true);
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
                failed.Add(target.Path);
            }
        }
        return failed;
    }
}
