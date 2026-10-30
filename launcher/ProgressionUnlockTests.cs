using System.IO;
using System.Text;

namespace Outbreak.Launcher;

internal static class ProgressionUnlockTests {
    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-progression-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            string image = Path.Combine(root, "synthetic-native.bin");
            File.WriteAllText(image, "[CHEATS-FILE2-1] health infection ammo data\n[CHEATS-UNLOCK-1] progression");
            check(GameSession.SupportsProgressionUnlocks(image, "file1") &&
                  !GameSession.SupportsProgressionUnlocks(image, "file2"),
                  "Old File #2 cheat support and the File #1 unlock marker cannot enable File #2 unlocks");
            // A marker can straddle the streaming capability reader's buffer boundary.
            const string file2Marker = "[CHEATS-UNLOCK-FILE2-1] progression";
            using (var stream = File.Create(image)) {
                stream.SetLength(1024 * 1024 + Encoding.ASCII.GetByteCount(file2Marker) - 8);
                stream.Position = stream.Length;
                stream.Write(Encoding.ASCII.GetBytes(file2Marker));
            }
            check(GameSession.SupportsProgressionUnlocks(image, "file2") &&
                  !GameSession.SupportsProgressionUnlocks(image, "file1") &&
                  !GameSession.SupportsProgressionUnlocks(image, "unknown"),
                  "File #2 requires its own unlock marker, including across a read boundary");

            var settings = new Settings { SelectedGame = "file2", CoopMode = "offline",
                CheatsEnabled = true, EnabledCheats = new() { "builtin.file2.unlock" } };
            string exported = Cheats.Export(settings, root);
            check(File.ReadAllLines(exported).SequenceEqual(new[] { "REO-CHEATS-2", "builtin unlock" }),
                  "File #2 unlocks export without enabling health, infection or ammunition cheats");
            foreach (string mode in new[] { "host", "join" }) {
                settings.CoopMode = mode;
                bool blocked = false;
                try { Cheats.Export(settings, root); }
                catch (IOException error) { blocked = error.Message.Contains("Play alone"); }
                check(blocked, "File #2 unlock-only selection is unavailable in co-op " + mode);
            }
        } finally { Directory.Delete(root, true); }
    }
}
