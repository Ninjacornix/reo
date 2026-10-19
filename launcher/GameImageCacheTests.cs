using System.IO;

namespace Outbreak.Launcher;

internal static class GameImageCacheTests {
    public static void Run(Action<bool, string> check) {
        string root =
            Path.Combine(Path.GetTempPath(), "reo-image-cache-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            string source = Path.Combine(root, "source.exe"),
                   library = Path.Combine(root, "runtime.dll");
            File.WriteAllText(source, "synthetic executable");
            File.WriteAllText(library, "runtime v1");
            var files = new[] { new GameImageCache.Input(source, "reo_launcher_game.exe"),
                                new GameImageCache.Input(library, "runtime.dll") };
            string home = Path.Combine(root, "cache");
            var first = GameImageCache.Prepare(home, files, default);
            var stamp = File.GetLastWriteTimeUtc(first.Image);
            using (File.Open(first.Image, FileMode.Open, FileAccess.Read, FileShare.Read)) {
                var again = GameImageCache.Prepare(home, files, default);
                check(first == again && File.GetLastWriteTimeUtc(first.Image) == stamp,
                      "A running immutable game image is reused without replacing it");
                File.WriteAllText(library, "runtime v2");
                var changed = GameImageCache.Prepare(home, files, default);
                check(
                    changed.Image != first.Image &&
                        File.ReadAllText(Path.Combine(Path.GetDirectoryName(first.Image)!,
                                                      "runtime.dll")) == "runtime v1",
                    "Changed runtime libraries get a separate cache and preserve the running build");
            }
            var current = GameImageCache.Prepare(home, files, default);
            File.WriteAllText(current.Image, "damaged");
            bool refused = false;
            try {
                GameImageCache.Prepare(home, files, default);
            } catch (IOException) {
                refused = true;
            }
            check(refused,
                  "A corrupted cached executable is refused rather than silently replaced");
            refused = false;
            try {
                GameImageCache.Prepare(home, [new(source, "../outside.exe")], default);
            } catch (IOException) {
                refused = true;
            }
            check(refused && !File.Exists(Path.Combine(home, "outside.exe")),
                  "Game cache files cannot escape their owned directory");
        } finally {
            string resolved = Path.GetFullPath(root),
                   temporary = Path.GetFullPath(Path.GetTempPath());
            if (!resolved.StartsWith(temporary, StringComparison.OrdinalIgnoreCase))
                throw new IOException("Unexpected test cleanup path");
            Directory.Delete(resolved, true);
        }
    }
}
