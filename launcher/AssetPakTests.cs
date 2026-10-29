using System.IO;
using System.IO.Compression;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
static class AssetPakTests {
    public static void Run(Action<bool, string> check) {
        void Reject(Action action, string label) {
            try { action(); } catch (Exception e) when (e is IOException or InvalidDataException) { check(true, label); return; }
            check(false, label);
        }
        string Manifest(string game = "file1", string target = "NETBIO00.DAT/0/0", string payload = "files/edit.bin") => JsonSerializer.Serialize(new {
            format = 1, id = "test.assets", name = "Asset fixture", version = "1", game,
            elfSha256 = game == "file1" ? DiscImport.FirstElfSha256 : DiscImport.SecondElfSha256,
            replace = new[] { new { path = target, file = payload } }
        });
        check(AssetPaks.Parse(Manifest()).Game == "file1", "File #1 asset manifest");
        check(AssetPaks.Parse(Manifest("file2")).Game == "file2", "File #2 asset manifest");
        foreach (string path in new[] { "../escape", "/absolute", "C:/absolute", "files\\escape", "files//empty", "files/./dot",
            "files/.. /escape", "files/name.", "files/name ", "files/NUL.bin" })
            Reject(() => AssetPaks.Parse(Manifest(payload: path)), "Unsafe asset payload path rejected: " + path);
        Reject(() => AssetPaks.Parse(Manifest().Replace("\"format\":1", "\"format\":1,\"format\":1")), "Duplicate manifest property rejected");
        Reject(() => AssetPaks.Parse(Manifest().Replace("\"format\":1", "\"format\":2")), "Unknown asset pack version rejected");
        Reject(() => AssetPaks.Parse(Manifest().Replace(DiscImport.FirstElfSha256, DiscImport.SecondElfSha256)), "Wrong asset ELF revision rejected");
        string folder = Path.Combine(Path.GetTempPath(), "reo-asset-tests-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(folder);
        try {
            byte[] Afs(params (string Name, byte[] Bytes)[] entries) {
                using var stream = new MemoryStream(); using var writer = new BinaryWriter(stream);
                writer.Write(Encoding.ASCII.GetBytes("AFS\0")); writer.Write(entries.Length);
                stream.SetLength(2048); stream.Position = 2048;
                var offsets = new List<uint>();
                foreach (var entry in entries) {
                    offsets.Add((uint)stream.Position); writer.Write(entry.Bytes);
                    stream.Position = (stream.Position + 2047) & ~2047L; stream.SetLength(stream.Position);
                }
                uint names = (uint)stream.Position;
                foreach (var entry in entries) {
                    writer.Write(Encoding.ASCII.GetBytes(entry.Name).Concat(new byte[32]).Take(32).ToArray());
                    writer.Write(new byte[12]); writer.Write(entry.Bytes.Length);
                }
                stream.Position = 8;
                for (int i = 0; i < entries.Length; i++) { writer.Write(offsets[i]); writer.Write(entries[i].Bytes.Length); }
                writer.Write(names); writer.Write(entries.Length * 48); return stream.ToArray();
            }
            string data = Path.Combine(folder, "data"); Directory.CreateDirectory(data);
            byte[] nested = Afs(("SOUN", new byte[] { 1, 2, 3 }), ("SOUN", new byte[] { 4, 5 }));
            byte[] archive = Afs(("room.afs", nested), ("room_h.bin", new byte[] { 9 }));
            foreach (string name in new[] { "NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT" }) File.WriteAllBytes(Path.Combine(data, name), archive);
            var index = AssetPaks.Index(data, "file1");
            check(AssetPaks.Resolve(index, "NETBIO00.DAT/0/1").Size == 2, "Numeric asset address survives duplicate names");
            check(AssetPaks.Resolve(index, "NETBIO00.DAT/room.afs/#1").Path == "NETBIO00.DAT/0/1", "Mixed name/index address resolves");
            Reject(() => AssetPaks.Resolve(index, "NETBIO00.DAT/room.afs/SOUN"), "Ambiguous asset name rejected");
            Reject(() => AssetPaks.Resolve(index, "NETBIO00.DAT/0"), "Whole nested archive replacement rejected");
            Reject(() => AssetPaks.Resolve(index, "NETBIO00.DAT/1"), "Room name table replacement rejected");
            Reject(() => AssetPaks.Resolve(index, "DUMMY.DAT/0"), "Dummy padding replacement rejected");
            Reject(() => AssetPaks.Resolve(index, "NETBIO00.DAT/0/99"), "Missing asset entry rejected");
            string packages = Path.Combine(folder, "packages"); Directory.CreateDirectory(packages);
            void Pack(string name, params (string Name, string Contents)[] entries) {
                using var zip = ZipFile.Open(Path.Combine(packages, name), ZipArchiveMode.Create);
                foreach (var entry in entries) { using var writer = new StreamWriter(zip.CreateEntry(entry.Name).Open()); writer.Write(entry.Contents); }
            }
            Pack("valid.pak", ("pak.json", Manifest()), ("files/edit.bin", "edited"));
            var installed = AssetPaks.Load(packages);
            check(installed.Single().Error == "" && installed.Single().Manifest!.Replace.Count == 1, "Valid ZIP asset pack loads");
            var settings = new Settings { SelectedGame = "file1", CoopMode = "offline", EnabledAssetPaks = new() { "test.assets" } };
            check(AssetPaks.Selected(settings, packages).Count == 1, "Solo pack selection");
            settings.CoopMode = "host";
            Reject(() => AssetPaks.Selected(settings, packages), "Host refuses enabled asset packs");
            settings.CoopMode = "join";
            Reject(() => AssetPaks.Selected(settings, packages), "Join refuses enabled asset packs");
            settings.SelectedGame = "file2";
            settings.CoopMode = "offline";
            settings.EnabledMods.Add("file1.saved.preference");
            check(AssetPaks.Selected(settings, packages).Count == 0 && Mods.Selected(settings).Count == 0 && settings.EnabledMods.Count == 1,
                "Other-edition preferences remain saved without affecting File #2 launch");
            Pack("bad.pak", ("pak.json", Manifest()), ("files/edit.bin", "edited"), ("../escape", "bad"));
            check(AssetPaks.Load(packages).Single(p => p.File.EndsWith("bad.pak")).Manifest == null, "ZIP traversal rejected");
            Pack("duplicates.pak", ("pak.json", Manifest()), ("files/edit.bin", "a"), ("files/edit.bin", "b"));
            check(AssetPaks.Load(packages).Single(p => p.File.EndsWith("duplicates.pak")).Manifest == null, "ZIP duplicate entry rejected");
            Pack("missing.pak", ("pak.json", Manifest()));
            check(AssetPaks.Load(packages).Single(p => p.File.EndsWith("missing.pak")).Manifest == null, "Missing payload rejected");
            string loose = Path.Combine(packages, "loose"); Directory.CreateDirectory(Path.Combine(loose, "files"));
            File.WriteAllText(Path.Combine(loose, "pak.json"), Manifest()); File.WriteAllText(Path.Combine(loose, "files/edit.bin"), "edited");
            check(AssetPaks.Load(packages).Where(p => p.Manifest != null).All(p => p.Error.Contains("Duplicate")), "Loose pack loads and duplicate package IDs block selection");
            byte[] bad = (byte[])archive.Clone(); BitConverter.GetBytes(uint.MaxValue).CopyTo(bad, 8);
            File.WriteAllBytes(Path.Combine(data, "NETBIO00.DAT"), bad);
            Reject(() => AssetPaks.Index(data, "file1"), "Malformed AFS entry extent rejected");
        } finally { Directory.Delete(folder, true); }
    }
}
