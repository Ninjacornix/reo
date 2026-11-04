using System.IO;
using System.Text;

namespace Outbreak.Launcher;

internal static class CheatCompatibilityTests {
    internal static void Run(Action<bool, string> check) {
        ExamineMessageTests(check);
        string folder = Path.Combine(Path.GetTempPath(), "reo-cheat-capabilities-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(folder);
        string image = Path.Combine(folder, "fixture.exe");
        bool Rejected(string game, string token, string name, bool online = false) {
            try { GameSession.VerifyCheatCompatibility(image, game, new[] { "REO-CHEATS-2", "builtin " + token }, online); }
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
            foreach (string game in new[] { "file1", "file2" }) {
                string progression = game == "file1" ? "[CHEATS-UNLOCK-1] progression" : "[CHEATS-UNLOCK-FILE2-1] progression";
                File.WriteAllText(image, "[CHEATS-FILE2-1] health infection ammo data\n" + progression, Encoding.ASCII);
                GameSession.VerifyCheatCompatibility(image, game, new[] { "builtin unlock" });
                GameSession.VerifyCheatCompatibility(image, game, new[] { "REO-CHEATS-2" }, online: true);
                check(true, game + " a guest without unlocks does not require the host's online-unlock capability");
                check(Rejected(game, "unlock", "Online Unlock everything", online: true),
                      game + " offline-only unlock binaries are rejected for online unlocks with a rebuild instruction");
                File.AppendAllText(image, "\n" + GameSession.OnlineUnlockCapability, Encoding.ASCII);
                GameSession.VerifyCheatCompatibility(image, game, new[] { "builtin unlock" }, online: true);
                check(true, game + " accepts online unlocks when the native room-progression banks are supported");
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
    static void ExamineMessageTests(Action<bool, string> check) {
        void Reject(Action action, string label) {
            try { action(); } catch (IOException) { check(true, label); return; }
            check(false, label);
        }
        var culture = System.Globalization.CultureInfo.CurrentCulture;
        string folder = Path.Combine(Path.GetTempPath(), "reo-examine-capabilities-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(folder);
        try {
            string image = Path.Combine(folder, "fixture.exe");
            foreach (string game in new[] { "file1", "file2" }) {
                var mod = new ModManifest { Format = 1, Id = "fixture.examine", Name = "Examine timing", Version = "1",
                    ElfSha256 = DiscImport.ExpectedElf(game), ExamineMessages = new() };
                var selected = new List<ModManifest> { mod };
                File.WriteAllText(image, "old-game [MOD-EXAMINE-TIME-1]", Encoding.ASCII);
                check(!GameSession.SupportsExamineMessages(image), game + " requires the complete examine capability marker");
                bool rejectedOld = false;
                try { GameSession.ExamineMessageEnvironment(selected, GameSession.SupportsExamineMessages(image)); }
                catch (IOException error) {
                    rejectedOld = error.Message.Contains("Examine message timing") && error.Message.Contains("Rebuild or update");
                }
                check(rejectedOld, game + " selected timing mod rejects older binaries with rebuild/update guidance");
                check(GameSession.ExamineMessageEnvironment(Array.Empty<ModManifest>(), false).Count == 0,
                    game + " disabled examine timing needs no native capability or environment variable");
                check(GameSession.ExamineMessageEnvironment(new[] { new ModManifest() }, false).Count == 0,
                    game + " unrelated mods do not require examine timing support");
                string marker = GameSession.ExamineMessagesCapability;
                File.WriteAllText(image, new string('x', 1024 * 1024 + marker.Length - 3) + marker, Encoding.ASCII);
                check(GameSession.SupportsExamineMessages(image), game + " exact examine capability is detected across binary read boundaries");
                System.Globalization.CultureInfo.CurrentCulture = System.Globalization.CultureInfo.GetCultureInfo("hr-HR");
                foreach (var (multiplier, expected) in new[] {
                    (1d, "1000"), (10d, "10000"), (2.5d, "2500"), (2.3456789d, "2346"),
                    (8.001d, "8001"), (1.0000000000000002d, "1001"), (9.9999999d, "10000") }) {
                    mod.ExamineMessages!.DurationMultiplier = multiplier;
                    var environment = GameSession.ExamineMessageEnvironment(selected, GameSession.SupportsExamineMessages(image));
                    check(environment.Count == 1 && environment["REO_MOD_EXAMINE_TIME_SCALE"] == expected,
                        game + " selected multiplier becomes upward-rounded invariant integer permille " + expected);
                }
                foreach (double invalid in new[] { double.NaN, double.PositiveInfinity, double.NegativeInfinity, 0.999d, 10.001d }) {
                    mod.ExamineMessages!.DurationMultiplier = invalid;
                    Reject(() => GameSession.ExamineMessageEnvironment(selected, true), game + " programmatic invalid timing cannot reach native environment");
                }
                mod.ExamineMessages!.DurationMultiplier = 2;
                Reject(() => GameSession.ExamineMessageEnvironment(new[] { mod, mod }, true),
                    game + " environment derivation defensively rejects multiple timing mods");
            }
        } finally {
            System.Globalization.CultureInfo.CurrentCulture = culture;
            string absolute = Path.GetFullPath(folder);
            if (absolute.StartsWith(Path.GetFullPath(Path.GetTempPath()), StringComparison.OrdinalIgnoreCase) &&
                Path.GetFileName(absolute).StartsWith("reo-examine-capabilities-", StringComparison.Ordinal))
                Directory.Delete(absolute, true);
        }
    }
}
