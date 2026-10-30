using System.IO;
using System.Text;

namespace Outbreak.Launcher;

internal static class CheatCompatibilityTests {
    internal static void Run(Action<bool, string> check) {
        string folder = Path.Combine(Path.GetTempPath(), "reo-cheat-capabilities-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(folder);
        string image = Path.Combine(folder, "fixture.exe");
        bool Rejected(string game, string token, string name) {
            try { GameSession.VerifyCheatCompatibility(image, game, new[] { "REO-CHEATS-2", "builtin " + token }); }
            catch (IOException error) { return error.Message.Contains(name) && error.Message.Contains("Rebuild or update"); }
            return false;
        }
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                var builtins = Cheats.Builtins(game);
                var points = builtins.Single(g => g.Builtin == "points");
                var escape = builtins.Single(g => g.Builtin == "escape");
                check(points.Id == "builtin." + game + ".points" && escape.Id == "builtin." + game + ".escape" &&
                      points.Writes.Count == 0 && escape.Writes.Count == 0 && points.Supported && escape.Supported,
                      game + " exposes points and escape cheats under separate stable built-in identities");
                var settings = new Settings { SelectedGame = game, CoopMode = "offline", CheatsEnabled = true,
                    EnabledCheats = new() { points.Id, escape.Id } };
                string manifest = Cheats.Export(settings, folder);
                check(File.ReadAllLines(manifest).SequenceEqual(new[] { "REO-CHEATS-2", "builtin points", "builtin escape" }),
                      game + " exports only the selected native points/escape operations using manifest v2");
                settings.SelectedGame = game == "file1" ? "file2" : "file1";
                check(Cheats.Export(settings, folder) == "", game + " points/escape choices do not leak to the other game");
                settings.SelectedGame = game;
                settings.CoopMode = "host";
                bool blockedOnline = false;
                try { Cheats.Export(settings, folder); } catch (IOException) { blockedOnline = true; }
                check(blockedOnline, game + " points/escape cheats retain the offline-only restriction");
            }
            File.WriteAllText(image, "old-game\n[CHEATS-FILE2-1] health infection ammo data", Encoding.ASCII);
            foreach (string game in new[] { "file1", "file2" }) {
                check(Rejected(game, "points", "Max results points") && Rejected(game, "escape", "Infinite escape time"),
                      game + " older binaries cannot silently ignore either new built-in");
                GameSession.VerifyCheatCompatibility(image, game, new[] { "builtin health", "builtin ammo" });
            }
            File.AppendAllText(image, "\n[CHEATS-POINTS-1] maximum results points", Encoding.ASCII);
            foreach (string game in new[] { "file1", "file2" }) {
                GameSession.VerifyCheatCompatibility(image, game, new[] { "builtin points" });
                check(Rejected(game, "escape", "Infinite escape time"),
                      game + " points support alone does not advertise escape support");
            }
            File.AppendAllText(image, "\n[CHEATS-ESCAPE-1] active countdown frozen", Encoding.ASCII);
            foreach (string game in new[] { "file1", "file2" }) {
                GameSession.VerifyCheatCompatibility(image, game, new[] { "builtin points", "builtin escape" });
                check(true, game + " accepts both new built-ins when the native binary advertises both capabilities");
            }
            string marker = "[CHEATS-POINTS-1] maximum results points";
            File.WriteAllText(image, new string('x', 1024 * 1024 + marker.Length - 3) + marker, Encoding.ASCII);
            GameSession.VerifyCheatCompatibility(image, "file1", new[] { "builtin points" });
            check(true, "Cheat capability detection survives a marker split across binary read chunks");
        } finally {
            string absolute = Path.GetFullPath(folder);
            if (absolute.StartsWith(Path.GetFullPath(Path.GetTempPath()), StringComparison.OrdinalIgnoreCase) &&
                Path.GetFileName(absolute).StartsWith("reo-cheat-capabilities-", StringComparison.Ordinal))
                Directory.Delete(absolute, true);
        }
    }
}
