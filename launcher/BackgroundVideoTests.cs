using System.Buffers.Binary;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class BackgroundVideoTests {
    internal static async Task Run(Action<bool, string> check) {
        using var bytes = new MemoryStream(new byte[512]);
        void Header(int at, uint count, uint offset, uint length) {
            bytes.Position = at;
            bytes.Write("AFS\0"u8);
            foreach (uint value in new[] { count, offset, length }) {
                var word = new byte[4];
                BinaryPrimitives.WriteUInt32LittleEndian(word, value);
                bytes.Write(word);
            }
        }
        Header(32, 1, 64, 32);
        check(BackgroundVideos.Entry(bytes, new(32, 128), 0) == new BackgroundVideos.Range(96, 32),
              "Nested AFS offsets stay relative to their own archive");
        bool Rejected(Action action) {
            try { action(); return false; } catch (InvalidDataException) { return true; }
        }
        Header(32, 1, 120, 32);
        check(Rejected(() => BackgroundVideos.Entry(bytes, new(32, 128), 0)),
              "Movie extents cannot spill into the enclosing file");
        Header(32, 1, 8, 32);
        check(Rejected(() => BackgroundVideos.Entry(bytes, new(32, 128), 0)),
              "An AFS movie cannot overlap its table");
        Header(32, 1, 64, 32);
        check(Rejected(() => BackgroundVideos.Entry(bytes, new(32, 128), -1)) &&
              Rejected(() => BackgroundVideos.Entry(bytes, new(32, 128), 1)) &&
              Rejected(() => BackgroundVideos.Entry(bytes, new(32, 128), 0, 1853)),
              "Invalid movie indices and other archive revisions are rejected");

        string root = Path.Combine(Path.GetTempPath(), "reo-background-test-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            var clips = new List<BackgroundVideos.CachedClip>();
            for (int i = 0; i < 2; i++) {
                string name = $"demo-{i + 1}.mp4", path = Path.Combine(root, name);
                await File.WriteAllBytesAsync(path, Enumerable.Repeat((byte)i, 128).ToArray());
                clips.Add(new(name, 128, await BackgroundVideoTool.Hash(path, default), BackgroundVideos.For("file1").Clips[i].SourceSha256));
            }
            var manifest = new BackgroundVideos.Manifest(BackgroundVideos.CacheFormat, "file1", DiscImport.FirstElfSha256, clips.ToArray());
            async Task Write(BackgroundVideos.Manifest value) => await File.WriteAllTextAsync(Path.Combine(root, "videos.json"), JsonSerializer.Serialize(value));
            await Write(manifest);
            check((await BackgroundVideos.ReadCache(root, "file1", default)).Length == 2 &&
                  (await BackgroundVideos.ReadCache(root, "file2", default)).Length == 0,
                  "A verified playlist is reusable only by its own edition");
            await Write(manifest with { Format = 1 });
            check((await BackgroundVideos.ReadCache(root, "file1", default)).Length == 0,
                  "Earlier fast encodes are regenerated with the current quality settings");
            await Write(manifest with { Clips = new[] { clips[0] with { File = "../outside.mp4" }, clips[1] } });
            check((await BackgroundVideos.ReadCache(root, "file1", default)).Length == 0,
                  "Cache metadata cannot point outside its movie directory");
            await Write(manifest);
            await File.WriteAllBytesAsync(Path.Combine(root, "demo-1.mp4"), new byte[128]);
            // Clip 1 originally contains zeroes; change a byte without changing length.
            using (var file = File.OpenWrite(Path.Combine(root, "demo-1.mp4"))) file.WriteByte(42);
            check((await BackgroundVideos.ReadCache(root, "file1", default)).Length == 0,
                  "Same-length corrupted movies do not pass cache verification");
            using var cancellation = new CancellationTokenSource();
            cancellation.Cancel();
            bool canceled = false;
            try { await BackgroundVideos.Transcode("must-not-start.exe", "unused", "unused", cancellation.Token); }
            catch (OperationCanceledException) { canceled = true; }
            check(canceled, "Cancellation prevents spawning a background converter");
        } finally { Directory.Delete(root, true); }
    }

    internal static async Task VerifyOwnedDiscs(string first, string second, string zip, string output) {
        output = Path.GetFullPath(output);
        Directory.CreateDirectory(output);
        string home = Path.Combine(output, "ui-data");
        if (zip != "-") await BackgroundVideoTool.Install(zip, home, default);
        string tool = await BackgroundVideoTool.Ensure(home, default);
        var settings = new Settings { Iso = Path.GetFullPath(first), SecondIso = Path.GetFullPath(second) };
        var results = new List<object>();
        foreach (var (game, iso) in new[] { ("file1", first), ("file2", second) }) {
            using var image = new DiscImage(iso);
            var verified = DiscValidation.Check(image, GameDefinition.Find(game), DiscImport.ExpectedElf(game), default);
            var entry = image.Entries.Single(e => e.Name.Equals("NETBIO01.DAT", StringComparison.OrdinalIgnoreCase));
            string import = Path.Combine(home, "imports", game, "movie-test-fixture"), folder = BackgroundVideos.Folder(import);
            await using var input = File.OpenRead(iso);
            var paths = await BackgroundVideos.ConvertArchive(input, new(entry.Offset, entry.Length), game, folder, tool, default);
            var source = new FileInfo(iso);
            // Minimal UI test fixture only; not a playable disc import.
            await File.WriteAllTextAsync(Path.Combine(import, "import.json"), JsonSerializer.Serialize(
                new ImportManifest(1, game, source.FullName, source.Length, source.LastWriteTimeUtc.Ticks, verified.Sha256, Array.Empty<ImportedFile>())));
            var reused = await BackgroundVideos.Prepare(import, game, home, default);
            if (!paths.SequenceEqual(reused) || (await BackgroundVideos.ReadCache(folder, game == "file1" ? "file2" : "file1", default)).Length != 0)
                throw new IOException("Owned-disc video cache verification failed.");
            settings.SelectedGame = game;
            settings.SetImport(import);
            results.Add(new { game, verified.Sha256, cacheReused = true, paths });
        }
        settings.SelectedGame = "file1";
        await File.WriteAllTextAsync(Path.Combine(home, "settings.json"), JsonSerializer.Serialize(settings));
        await File.WriteAllTextAsync(Path.Combine(output, "conversion-result.json"), JsonSerializer.Serialize(new { passed = true, results }, new JsonSerializerOptions { WriteIndented = true }));
    }
}
