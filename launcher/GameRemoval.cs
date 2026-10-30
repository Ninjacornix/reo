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
            targets.Add(new(Path.Combine(home, "memory-cards", "default", game), "save games"));
            string card = Path.GetFullPath(settings.CardFolder(root));
            // Only cards the launcher manages; a folder the player picked elsewhere is theirs.
            if (card.StartsWith(Path.GetFullPath(Path.Combine(home, "memory-cards")) +
                                    Path.DirectorySeparatorChar,
                                StringComparison.OrdinalIgnoreCase))
                targets.Add(new(card, "selected memory card"));
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
