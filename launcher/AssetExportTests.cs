using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
static class AssetExportTests {
    sealed class InlineProgress(Action<ImportProgress> callback) : IProgress<ImportProgress> {
        public void Report(ImportProgress value) => callback(value);
    }
    public static void Run(Action<bool, string> check) {
        var settings = new Settings();
        check(!settings.WantsOriginalAssetPaks("file1") && !settings.WantsOriginalAssetPaks("file2"), "Original exports default off for both games");
        settings.SetOriginalAssetExport(true);
        check(settings.WantsOriginalAssetPaks("file1") && !settings.WantsOriginalAssetPaks("file2"), "File #1 original export preference is independent");
        settings.SelectedGame = "file2"; settings.SetOriginalAssetExport(true);
        settings.SelectedGame = "file1"; settings.SetOriginalAssetExport(false);
        check(!settings.WantsOriginalAssetPaks("file1") && settings.WantsOriginalAssetPaks("file2"), "Switching games preserves original export preferences");
        string root = Path.Combine(Path.GetTempPath(), "reo-original-export-tests-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            byte[] Afs(params (string Name, byte[] Bytes)[] entries) {
                using var stream = new MemoryStream(); using var writer = new BinaryWriter(stream);
                writer.Write("AFS\0"u8); writer.Write(entries.Length); stream.SetLength(2048); stream.Position = 2048;
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
            string imported = Path.Combine(root, "import"), data = Path.Combine(imported, "data"), home = Path.Combine(root, "home");
            Directory.CreateDirectory(data);
            byte[] nested = Afs(("face.tm2", "TIM2 texture"u8.ToArray()), ("model.nbd", "TEX\0bundle"u8.ToArray()),
                ("SOUN", new byte[] { 0x80, 0, 0, 0 }), ("SOUN", "duplicate sound"u8.ToArray()),
                ("../../escape.bin", "unsafe name"u8.ToArray()), ("", Array.Empty<byte>()));
            var originals = new Dictionary<string, byte[]> {
                ["NETBIO00.DAT"] = Afs(("room.afs", nested), ("r001_h.bin", "protected original table"u8.ToArray())),
                ["NETBIO01.DAT"] = Afs(("sound.adx", "audio data"u8.ToArray())),
                ["NETBIO02.DAT"] = Afs(("movie.sfd", "movie data"u8.ToArray()))
            };
            foreach (var item in originals) File.WriteAllBytes(Path.Combine(data, item.Key), item.Value);
            var index = AssetPaks.Index(data, "file1");
            OriginalAssetExport Export(string destination, IProgress<ImportProgress>? progress = null, CancellationToken token = default) =>
                AssetExports.Export(data, "file1", DiscImport.FirstElfSha256, progress, token, destination, index);
            var first = Export(home);
            check(!first.Reused && first.Entries == index.Entries.Count(e => !e.IsArchive), "All native leaves exported");
            check(Directory.GetFiles(first.Root, "*.pak").Length == 1, "All original assets are in one pack");
            string pak = Path.Combine(first.Root, "original-assets.pak");
            using (var zip = ZipFile.OpenRead(pak)) {
                using var reader = new StreamReader(zip.GetEntry("assets.json")!.Open());
                using var manifest = JsonDocument.Parse(reader.ReadToEnd());
                var entries = manifest.RootElement.GetProperty("entries").EnumerateArray().ToList();
                check(zip.GetEntry(AssetExports.ReferenceHeader) != null && manifest.RootElement.GetProperty("verified").GetBoolean(), "Original reference header and verified editing index included");
                check(entries.Count == first.Entries && zip.Entries.Count == entries.Count + 2, "Pack and index counts agree");
                check(entries.Select(e => e.GetProperty("path").GetString()).Distinct().Count() == entries.Count &&
                    entries.Select(e => e.GetProperty("file").GetString()).Distinct().Count() == entries.Count, "Duplicate and missing AFS names retain unique indexed paths");
                check(entries.All(e => !e.GetProperty("file").GetString()!.Split('/').Any(p => p is "." or "..")), "Unsafe original names cannot escape ZIP paths");
                bool equal = true;
                foreach (var entry in entries) {
                    string address = entry.GetProperty("path").GetString()!;
                    long offset = entry.GetProperty("sourceOffset").GetInt64(), length = entry.GetProperty("bytes").GetInt64();
                    using var input = zip.GetEntry(entry.GetProperty("file").GetString()!)!.Open(); using var output = new MemoryStream(); input.CopyTo(output);
                    byte[] bytes = output.ToArray();
                    equal &= bytes.AsSpan().SequenceEqual(originals[address.Split('/')[0]].AsSpan((int)offset, (int)length)) &&
                        Convert.ToHexString(SHA256.HashData(bytes)).Equals(entry.GetProperty("sha256").GetString(), StringComparison.OrdinalIgnoreCase);
                }
                check(equal, "Every exported byte and SHA-256 matches its original range");
            }
            check(originals.All(p => File.ReadAllBytes(Path.Combine(data, p.Key)).AsSpan().SequenceEqual(p.Value)), "Original archives unchanged by export");
            var stamp = File.GetLastWriteTimeUtc(pak); var reused = Export(home);
            check(reused.Reused && reused.Root == first.Root && File.GetLastWriteTimeUtc(pak) == stamp, "Completed export reused without rewriting the pack");
            try { AssetPaks.Import(pak, Path.Combine(root, "mods")); check(false, "Original references cannot be installed as replacement mods"); }
            catch (IOException e) { check(e.Message.Contains("local editing"), "Original references cannot be installed as replacement mods"); }
            byte[] changed = File.ReadAllBytes(pak); changed[0] ^= 1; File.WriteAllBytes(pak, changed);
            File.SetLastWriteTimeUtc(pak, stamp.AddSeconds(2));
            var replacement = Export(home);
            check(!replacement.Reused && replacement.Root != first.Root && File.ReadAllBytes(pak).AsSpan().SequenceEqual(changed), "Edited old exports preserved while a fresh verified copy is created");
            check(Export(home).Root == replacement.Root && Export(home).Reused, "New export version becomes the reusable current version");
            string pointer = Path.Combine(Path.GetDirectoryName(replacement.Root)!, "single.json");
            File.WriteAllText(pointer, "{\"format\":1,\"folder\":\"../../outside\"}");
            var recovered = Export(home);
            check(Path.GetDirectoryName(recovered.Root) == Path.GetDirectoryName(first.Root), "Export pointer cannot redirect writes outside managed storage");
            string cancelledHome = Path.Combine(root, "cancelled");
            using var cancel = new CancellationTokenSource();
            try {
                Export(cancelledHome, new InlineProgress(p => { if (p.Stage == "Verifying original asset packs") cancel.Cancel(); }), cancel.Token);
                check(false, "Cancellation removes unpublished partial export");
            } catch (OperationCanceledException) {
                check(!Directory.EnumerateFiles(cancelledHome, "*.pak", SearchOption.AllDirectories).Any() &&
                    !Directory.EnumerateDirectories(cancelledHome, ".export-*", SearchOption.AllDirectories).Any(), "Cancellation removes unpublished partial export");
            }
            check(File.Exists(Path.Combine(recovered.Root, "original-assets.pak")), "Cancellation preserves completed exports");
            try { Export(data); check(false, "Export destination cannot be inside imported data"); }
            catch (IOException) { check(!Directory.Exists(Path.Combine(data, "asset-exports")), "Export destination cannot be inside imported data"); }
            File.WriteAllText(Path.Combine(data, "SLUS_207.65"), "not a supported executable");
            try {
                AssetExports.Ensure(new(imported, "", 0, 0, true), "file1", home: Path.Combine(root, "wrong-elf")).GetAwaiter().GetResult();
                check(false, "Export validates the imported executable");
            } catch (IOException) { check(!Directory.Exists(Path.Combine(root, "wrong-elf")), "Export validates the imported executable"); }
            using var cancelledIndex = new CancellationTokenSource(); cancelledIndex.Cancel();
            try { AssetPaks.Index(data, "file1", cancel: cancelledIndex.Token); check(false, "Archive indexing honours cancellation"); }
            catch (OperationCanceledException) { check(true, "Archive indexing honours cancellation"); }
            string longHome = Path.Combine(root, "Čakovec 測試", new string('a', 70), new string('b', 70), new string('c', 70));
            var unicode = Export(longHome);
            check(unicode.Root.Length > 300 && File.Exists(Path.Combine(unicode.Root, "original-assets.pak")) && Export(longHome).Reused,
                "Unicode and long export paths work and reuse correctly");
            var secondIndex = AssetPaks.Index(data, "file2");
            var second = AssetExports.Export(data, "file2", DiscImport.SecondElfSha256, null, default, home, secondIndex);
            check(second.Entries == secondIndex.Entries.Count(e => !e.IsArchive) && !second.Root.Equals(first.Root), "File #2 exports independently into its own combined pack");
        } finally {
            string full = Path.GetFullPath(root), temp = Path.TrimEndingDirectorySeparator(Path.GetFullPath(Path.GetTempPath()));
            if (Path.GetDirectoryName(full) == temp && Path.GetFileName(full).StartsWith("reo-original-export-tests-", StringComparison.Ordinal)) Directory.Delete(full, true);
        }
    }
}
