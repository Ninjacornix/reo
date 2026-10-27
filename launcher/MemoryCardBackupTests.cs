using System.IO;
using System.IO.Compression;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class MemoryCardBackupTests {
    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-save-backup-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            var settings = new Settings();
            var selected = new Dictionary<string, string>();
            foreach (string game in new[] { "file1", "file2" }) {
                settings.SelectedGame = game;
                var card = MemoryCards.Create(game, root);
                settings.MemoryCards.Add(card);
                settings.SelectCard(card.Folder);
                string title = game == "file1" ? "BASLUS-20765" : "BASLUS-20984";
                string save = Path.Combine(card.Folder, title, "data");
                Directory.CreateDirectory(Path.GetDirectoryName(save)!);
                Directory.CreateDirectory(Path.Combine(card.Folder, ".reo-meta"));
                byte[] content = Enumerable.Range(0, 257).Select(n => (byte)n).ToArray();
                File.WriteAllBytes(save, content);
                File.WriteAllText(Path.Combine(card.Folder, ".reo-meta", "fixture"), game);
                string archive = Path.Combine(root, game + ".zip");
                MemoryCards.Backup(settings.CardFolder(root), archive);
                byte[] original = File.ReadAllBytes(archive);
                string restored = Path.Combine(root, game + "-restored");
                ZipFile.ExtractToDirectory(archive, restored);
                check(File.ReadAllBytes(Path.Combine(restored, title, "data")).SequenceEqual(content)
                      && File.ReadAllText(Path.Combine(restored, ".reo-meta", "fixture")) == game,
                      game + " backup/extract preserves save bytes and runtime metadata");
                bool locked = false;
                using (MemoryCards.Acquire(card.Folder)) {
                    try { MemoryCards.Backup(card.Folder, archive); }
                    catch (IOException) { locked = true; }
                }
                check(locked && File.ReadAllBytes(archive).SequenceEqual(original),
                      game + " active cards cannot be backed up and previous backups remain intact");
                bool inside = false;
                try { MemoryCards.Backup(card.Folder, Path.Combine(card.Folder, "backup.zip")); }
                catch (IOException) { inside = true; }
                check(inside && !File.Exists(Path.Combine(card.Folder, "backup.zip")),
                      game + " backup cannot include its own archive");
                bool failed = false;
                using (new FileStream(save, FileMode.Open, FileAccess.Read, FileShare.None)) {
                    try { MemoryCards.Backup(card.Folder, archive); }
                    catch (IOException) { failed = true; }
                }
                check(failed && File.ReadAllBytes(archive).SequenceEqual(original)
                      && !Directory.EnumerateFiles(root, "*.tmp").Any(),
                      game + " failed backup cleans staging and preserves the prior archive");
                settings.SelectCard(restored);
                selected[game] = restored;
            }
            settings = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
            foreach (var pair in selected) {
                settings.SelectedGame = pair.Key;
                check(settings.CardFolder(root) == pair.Value,
                      pair.Key + " restored folder selection persists independently");
            }
        } finally { Directory.Delete(root, true); }
    }
}
