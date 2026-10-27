using System.IO;
using System.Text.Json;
using System.Text.Json.Nodes;

namespace Outbreak.Launcher;

internal static class StorageTests {
    sealed class ProgressAction(Action<StorageProgress> action) : IProgress<StorageProgress> {
        public void Report(StorageProgress value) => action(value);
    }

    internal static void Run(Action<bool, string> check) => RunAsync(check).GetAwaiter().GetResult();
    static async Task RunAsync(Action<bool, string> check) {
        string sandbox = Path.Combine(Path.GetTempPath(), "reo storage é " + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(sandbox);
        try {
            string root = Path.Combine(sandbox, "launcher"), source = Path.Combine(root, "data"), destination = Path.Combine(root, "custom data");
            Directory.CreateDirectory(source);
            check(Storage.Resolve(root) == source, "Fresh launch defaults to data beside the launcher");
            check(Storage.Resolve(root, destination) == destination, "Explicit data folder overrides the default");
            string settings = JsonSerializer.Serialize(new {
                ImportedFile1 = Path.Combine(source, "imports", "file1", "cached"),
                ImportedFile2 = Path.Combine(source, "imports", "file2", "cached"),
                Exe = Path.Combine(source, "local-games", "file1", "ready", "reo_recomp.exe"),
                MemoryCards = new[] { new { Name = "My card", Folder = Path.Combine(source, "memory-cards", "my card") } },
                Iso = Path.Combine(sandbox, "external.iso"), AccountUsername = "player1"
            });
            File.WriteAllText(Path.Combine(source, "settings.json"), settings);
            string import = Path.Combine(source, "imports", "file1", "cached"); Directory.CreateDirectory(import);
            File.WriteAllText(Path.Combine(import, "import.json"), JsonSerializer.Serialize(new { Source = Path.Combine(source, "disc.iso"), SourceLength = 123, ElfSha256 = "hash" }));
            string card = Path.Combine(source, "memory-cards", "my card"); Directory.CreateDirectory(card);
            byte[] save = { 1, 4, 6, 9, 12 }; File.WriteAllBytes(Path.Combine(card, "save.bin"), save);
            Directory.CreateDirectory(Path.Combine(source, "empty card"));
            File.WriteAllText(Path.Combine(source, ".storage.lock"), "not user data");
            File.WriteAllText(Path.Combine(source, "card.reo-lock"), "not user data");
            string signed = Path.Combine(source, "build-kits", "kit"); Directory.CreateDirectory(signed);
            File.WriteAllText(Path.Combine(signed, "build-kit.json"), "{\"path\":\"leave signed input unchanged\"}");
            await Storage.Select(root, source, destination, null, default);
            check(Storage.Resolve(root) == destination, "New storage locator publishes after verified data copy");
            check(JsonNode.Parse(File.ReadAllText(Path.Combine(root, Storage.LocatorName)))!["folder"]!.GetValue<string>() == "custom data",
                  "Storage inside installation uses a portable relative locator");
            var moved = JsonNode.Parse(File.ReadAllText(Path.Combine(destination, "settings.json")))!;
            check(moved["ImportedFile1"]!.GetValue<string>() == Path.Combine(destination, "imports", "file1", "cached") &&
                  moved["ImportedFile2"]!.GetValue<string>() == Path.Combine(destination, "imports", "file2", "cached"),
                  "Both editions' imported disc paths follow the data folder");
            check(moved["Exe"]!.GetValue<string>().StartsWith(destination) &&
                  moved["MemoryCards"]![0]!["Folder"]!.GetValue<string>().StartsWith(destination),
                  "Built games and nested memory-card selections follow storage relocation");
            check(moved["Iso"]!.GetValue<string>() == Path.Combine(sandbox, "external.iso") && moved["AccountUsername"]!.GetValue<string>() == "player1",
                  "External files and unrelated preferences retain their values");
            check(JsonNode.Parse(File.ReadAllText(Path.Combine(destination, "imports", "file1", "cached", "import.json")))!["Source"]!.GetValue<string>() == Path.Combine(destination, "disc.iso"),
                  "Mutable import manifests follow an ISO stored inside the data folder");
            check(File.ReadAllBytes(Path.Combine(destination, "memory-cards", "my card", "save.bin")).SequenceEqual(save),
                  "Save bytes survive relocation exactly");
            check(File.ReadAllText(Path.Combine(source, "settings.json")) == settings && File.ReadAllBytes(Path.Combine(card, "save.bin")).SequenceEqual(save),
                  "Original settings and saves remain available as a backup");
            check(Directory.Exists(Path.Combine(destination, "empty card")) && !File.Exists(Path.Combine(destination, ".storage.lock")) &&
                  !File.Exists(Path.Combine(destination, "card.reo-lock")), "Empty folders are retained while live lease files are not copied");
            check(File.ReadAllText(Path.Combine(signed, "build-kit.json")) == File.ReadAllText(Path.Combine(destination, "build-kits", "kit", "build-kit.json")),
                  "Signed build-kit inputs are never rewritten during migration");
            check(!Directory.GetDirectories(root, ".reo-storage-*").Any(), "Successful migration leaves no staging directory");
            string oldLocator = File.ReadAllText(Path.Combine(root, Storage.LocatorName));
            string missing = Path.Combine(root, "missing-drive", "data");
            await Storage.WriteJson(Path.Combine(root, Storage.LocatorName), new { Format = 1, Folder = missing }, default);
            bool missingRefused = false;
            try { Storage.Resolve(root); } catch (IOException) { missingRefused = true; }
            check(missingRefused && !Directory.Exists(missing), "A missing selected drive never creates a replacement profile");
            File.WriteAllText(Path.Combine(root, Storage.LocatorName), oldLocator);
            string occupied = Path.Combine(root, "occupied"); Directory.CreateDirectory(occupied);
            File.WriteAllText(Path.Combine(occupied, "keep.txt"), "keep");
            bool refused = false;
            try { await Storage.Select(root, source, occupied, null, default); } catch (IOException) { refused = true; }
            check(refused && File.ReadAllText(Path.Combine(occupied, "keep.txt")) == "keep" &&
                  File.ReadAllText(Path.Combine(root, Storage.LocatorName)) == oldLocator,
                  "Destination conflicts preserve existing files and the active storage selection");
            foreach (string invalid in new[] { source, root, Path.Combine(source, "nested") }) {
                refused = false;
                try { await Storage.CopyData(source, invalid, root, null, default); } catch (IOException) { refused = true; }
                check(refused, "Migration refuses overlapping source/destination: " + invalid);
            }
            string cancelSource = Path.Combine(root, "cancel-source"), cancelTarget = Path.Combine(root, "cancel-target");
            Directory.CreateDirectory(cancelSource); File.WriteAllBytes(Path.Combine(cancelSource, "large.bin"), new byte[2 * 1024 * 1024]);
            using var cancelled = new CancellationTokenSource();
            bool stopped = false;
            try { await Storage.Select(root, cancelSource, cancelTarget, new ProgressAction(_ => cancelled.Cancel()), cancelled.Token); }
            catch (OperationCanceledException) { stopped = true; }
            check(stopped && !Directory.Exists(cancelTarget) && !Directory.GetDirectories(root, ".reo-storage-*").Any() &&
                  File.ReadAllText(Path.Combine(root, Storage.LocatorName)) == oldLocator,
                  "Cancelling a copy removes staging and retains the old active folder");
            using (var locked = new FileStream(Path.Combine(cancelSource, "large.bin"), FileMode.Open, FileAccess.Write, FileShare.None)) {
                refused = false;
                try { await Storage.Select(root, cancelSource, cancelTarget, null, default); } catch (IOException) { refused = true; }
                check(refused && !Directory.Exists(cancelTarget) && File.ReadAllText(Path.Combine(root, Storage.LocatorName)) == oldLocator,
                      "A busy file aborts migration without switching storage");
            }
            check(Storage.NeedsLegacyImport(Path.Combine(root, "new-profile"), source) && !Storage.NeedsLegacyImport(destination, source),
                  "Existing AppData-style settings are imported once, never over an established profile");
            check(Storage.ProtectedUpdatePath(root, "storage.json") && Storage.ProtectedUpdatePath(root, "custom data/settings.json") &&
                  Storage.ProtectedUpdatePath(root, "data/settings.json") &&
                  !Storage.ProtectedUpdatePath(root, "Outbreak.Launcher.exe"), "Updates distinguish user storage from launcher package files");

            string portable = Path.Combine(sandbox, "portable"), relocated = Path.Combine(sandbox, "relocated");
            string oldHome = Path.Combine(portable, "data"), newHome = Path.Combine(relocated, "data");
            Directory.CreateDirectory(oldHome);
            await Storage.WriteJson(Path.Combine(oldHome, Storage.MarkerName), new { home = oldHome, installation = portable }, default);
            await Storage.WriteJson(Path.Combine(oldHome, "settings.json"), new { Exe = Path.Combine(oldHome, "local-games", "game.exe"),
                Iso = Path.Combine(portable, "iso", "disc.iso"), External = oldHome + "-other\\file" }, default);
            if (!Storage.Within(portable, sandbox) || !Storage.Within(relocated, sandbox)) throw new IOException("Fixture path escaped test sandbox");
            Directory.Move(portable, relocated);
            await Storage.Rebase(newHome, relocated, default);
            var rebased = JsonNode.Parse(File.ReadAllText(Path.Combine(newHome, "settings.json")))!;
            check(rebased["exe"]!.GetValue<string>() == Path.Combine(newHome, "local-games", "game.exe") &&
                  rebased["iso"]!.GetValue<string>() == Path.Combine(relocated, "iso", "disc.iso"),
                  "Moving the whole portable installation repairs both storage and installation paths");
            check(rebased["external"]!.GetValue<string>() == newHome + "-other\\file", "Similarly named folders follow the installation without being mistaken for the data folder");
            string unrelated = Path.Combine(sandbox, "portable-other", "file");
            check(Storage.RebasePath(unrelated, oldHome, newHome, portable, relocated) == unrelated,
                  "Path rebasing leaves similarly named external installations alone");
            string stableSettings = File.ReadAllText(Path.Combine(newHome, "settings.json"));
            await Storage.Rebase(newHome, relocated, default);
            check(File.ReadAllText(Path.Combine(newHome, "settings.json")) == stableSettings,
                  "Repeated startup rebasing is stable");
        } finally {
            if (!Storage.Within(sandbox, Path.GetTempPath())) throw new IOException("Fixture cleanup escaped temporary storage");
            Directory.Delete(sandbox, true);
        }
    }
}
