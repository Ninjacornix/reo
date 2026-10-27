using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class CoopSmokeOptionsTests {
    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-coop-smoke-options-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            check(CoopSmokeOptions.Parse(Array.Empty<string>()) == null,
                  "Normal launcher starts do not create co-op diagnostic state");
            string[] Args(string game) => new[] {
                "--test-coop-session", Path.Combine(root, game), "--test-coop-player", "fixture1",
                "--test-coop-mode", "join", "--test-coop-lobby", "--test-coop-room", "hosttest",
                "--test-coop-seconds", "300"
            };
            foreach (string game in new[] { "file1", "file2" }) {
                var options = CoopSmokeOptions.Parse(Args(game))!;
                var settings = new Settings { SelectedGame = game, MemoryCardFile1 = "user-card-1",
                    MemoryCardFile2 = "user-card-2", AccountUsername = "user1", CoopMode = "offline" };
                var snapshot = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
                options.Prepare(snapshot);
                check(options.AllowConcurrent && options.Seconds == 300 && options.Lobby && !options.StartServer,
                      game + " explicit co-op session has bounded multi-client options");
                check(snapshot.CardFolder(root) == options.Card && Directory.Exists(options.Card)
                      && Directory.Exists(options.Work) && snapshot.AccountUsername == "fixture1"
                      && snapshot.ResolvedCoopMode == "join" && snapshot.CoopHost == "127.0.0.1",
                      game + " co-op diagnostics use selected-edition private card and account");
                check(settings.MemoryCardFile1 == "user-card-1" && settings.MemoryCardFile2 == "user-card-2"
                      && settings.AccountUsername == "user1" && settings.CoopMode == "offline",
                      game + " preparing a diagnostic snapshot cannot modify normal settings");
                bool reused = false;
                try { options.Prepare(snapshot); } catch (IOException) { reused = true; }
                check(reused, game + " completed/active diagnostic folders cannot be overwritten");
            }
            foreach (var invalid in new[] {
                new[] { "--test-coop-address", "192.168.1.10" },
                new[] { "--test-coop-seconds", "901" },
                new[] { "--test-coop-seconds", "" },
                new[] { "--test-coop-mode", "offline" },
                new[] { "--test-coop-player", "bad name" },
                new[] { "--test-coop-mode", "join", "--test-coop-start-server" },
                new[] { "--test-coop-mode", "join", "--test-coop-lobby" },
                new[] { "--test-mod", "anything" }
            }) {
                bool rejected = false;
                try { CoopSmokeOptions.Parse(new[] { "--test-auto-network" }.Concat(invalid).ToArray()); }
                catch (ArgumentException) { rejected = true; }
                check(rejected, "Invalid or non-isolated co-op diagnostic options are rejected");
            }
        } finally { Directory.Delete(root, true); }
    }
}
