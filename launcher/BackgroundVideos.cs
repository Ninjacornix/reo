using System.Buffers.Binary;
using System.Diagnostics;
using System.IO;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class BackgroundVideos {
    // Version 2 replaces the initial veryfast/CRF 23 encode with medium/CRF 20.
    internal const int CacheFormat = 2;
    internal record Clip(int Index, string SourceSha256);
    internal record Profile(int Count, Clip[] Clips);
    internal record Range(long Offset, long Length);
    internal record CachedClip(string File, long Bytes, string Sha256, string SourceSha256);
    internal record Manifest(int Format, string Game, string ElfSha256, CachedClip[] Clips);
    static readonly SemaphoreSlim converter = new(1);
    internal static Profile For(string game) => game switch {
        "file1" => new(422, new[] {
            new Clip(412, "8f3d870f720b590c963c98bd318ef83b743d1fa88288bc4ac57269f9cafaed47"),
            new Clip(413, "aa6ed7c77501568962042f54a784bc27aa42b119a48354db91c28faa332f1bf5") }),
        // File #2's adxsnd_usa.afs has no usable filename table. These are the
        // PS2demo01/02 streams from the supported NTSC-U v1.05 revision.
        "file2" => new(1853, new[] {
            new Clip(1833, "16dfdd83bac8dbdd918a35a805c0612673f6208fb7d1d2ea1bbe13435fb68bd0"),
            new Clip(1834, "77672971aa5446114dc68df825d80a7b1afbe9f77ed0e23dc7786181c88d9c95") }),
        _ => throw new InvalidDataException("Unsupported background video edition.")
    };
    internal static string Folder(string import) => Path.Combine(import, "background-videos-v1");

    internal static async Task<string[]> Prepare(string import, string game, string home, CancellationToken cancel,
                                                  IProgress<ImportProgress>? progress = null) {
        // Only derive assets from an import verified for this exact game revision.
        var imported = JsonSerializer.Deserialize<ImportManifest>(
            await File.ReadAllTextAsync(Path.Combine(import, "import.json"), cancel));
        if (imported is not { Version: 1 } || imported.Game != game || imported.ElfSha256 != DiscImport.ExpectedElf(game))
            return Array.Empty<string>();
        string folder = Folder(import);
        var cached = await ReadCache(folder, game, cancel).ConfigureAwait(false);
        if (cached.Length != 0) return cached;
        await converter.WaitAsync(cancel).ConfigureAwait(false);
        try {
            cached = await ReadCache(folder, game, cancel).ConfigureAwait(false);
            if (cached.Length != 0) return cached;
            await using var archive = File.OpenRead(Path.Combine(import, "data", "NETBIO01.DAT"));
            // Validate the container before initiating an optional tool download.
            var sound = Entry(archive, new(0, archive.Length), 0);
            foreach (var clip in For(game).Clips) _ = Entry(archive, sound, clip.Index, For(game).Count);
            string tool = await BackgroundVideoTool.Ensure(home, cancel, progress).ConfigureAwait(false);
            return await ConvertArchive(archive, new(0, archive.Length), game, folder, tool, cancel, progress).ConfigureAwait(false);
        } finally { converter.Release(); }
    }

    internal static async Task<string[]> ReadCache(string folder, string game, CancellationToken cancel) {
        try {
            var manifest = JsonSerializer.Deserialize<Manifest>(await File.ReadAllTextAsync(Path.Combine(folder, "videos.json"), cancel));
            var profile = For(game);
            if (manifest == null || manifest.Format != CacheFormat || manifest.Game != game || manifest.ElfSha256 != DiscImport.ExpectedElf(game) ||
                manifest.Clips == null || manifest.Clips.Length != profile.Clips.Length) return Array.Empty<string>();
            var paths = new List<string>();
            for (int i = 0; i < manifest.Clips.Length; i++) {
                var clip = manifest.Clips[i];
                if (clip == null || clip.File != $"demo-{i + 1}.mp4" || clip.SourceSha256 != profile.Clips[i].SourceSha256 || clip.Bytes < 32)
                    return Array.Empty<string>();
                string path = Path.Combine(folder, clip.File);
                if (new FileInfo(path).Length != clip.Bytes || await BackgroundVideoTool.Hash(path, cancel) != clip.Sha256)
                    return Array.Empty<string>();
                paths.Add(path);
            }
            return paths.ToArray();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or JsonException) {
            return Array.Empty<string>();
        }
    }

    // Bounds are relative to each nested AFS, never to the containing file alone.
    internal static Range Entry(Stream input, Range archive, int index, int? expectedCount = null) {
        if (!input.CanSeek || archive.Offset < 0 || archive.Length < 8 || archive.Offset > input.Length - archive.Length)
            throw new InvalidDataException("Invalid AFS extent.");
        Span<byte> bytes = stackalloc byte[8];
        input.Position = archive.Offset;
        input.ReadExactly(bytes);
        uint count = BinaryPrimitives.ReadUInt32LittleEndian(bytes[4..]);
        long tableEnd = 8L + count * 8L;
        if (!bytes[..4].SequenceEqual("AFS\0"u8) || count is 0 or > 10000 || tableEnd > archive.Length ||
            index < 0 || index >= count || (expectedCount != null && count != expectedCount))
            throw new InvalidDataException("Unexpected AFS video table.");
        input.Position = archive.Offset + 8L + index * 8L;
        input.ReadExactly(bytes);
        long offset = BinaryPrimitives.ReadUInt32LittleEndian(bytes), length = BinaryPrimitives.ReadUInt32LittleEndian(bytes[4..]);
        if (offset < tableEnd || length == 0 || offset > archive.Length - length)
            throw new InvalidDataException("AFS video lies outside its archive.");
        return new(archive.Offset + offset, length);
    }

    // Stream/extent overload lets verification exercise the exact parser against an
    // owned ISO without copying several GB of unrelated game data.
    internal static async Task<string[]> ConvertArchive(Stream archive, Range extent, string game, string folder,
                                                         string tool, CancellationToken cancel, IProgress<ImportProgress>? progress = null) {
        var profile = For(game);
        var sound = Entry(archive, extent, 0);
        Directory.CreateDirectory(folder);
        string staging = Path.Combine(folder, ".prepare-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(staging);
        var clips = new List<CachedClip>();
        try {
            for (int i = 0; i < profile.Clips.Length; i++) {
                cancel.ThrowIfCancellationRequested();
                var clip = profile.Clips[i];
                progress?.Report(new(i, profile.Clips.Length, $"Preparing background video {i + 1} of {profile.Clips.Length} · one-time setup", "Preparing background videos"));
                var range = Entry(archive, sound, clip.Index, profile.Count);
                if (range.Length > 64 * 1024 * 1024) throw new InvalidDataException("Oversized demonstration video.");
                string source = Path.Combine(staging, "demo.sfd"), name = $"demo-{i + 1}.mp4", output = Path.Combine(staging, name);
                archive.Position = range.Offset;
                using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
                await using (var destination = new FileStream(source, FileMode.Create, FileAccess.Write)) {
                    var buffer = new byte[65536];
                    long left = range.Length;
                    while (left > 0) {
                        int count = await archive.ReadAsync(buffer.AsMemory(0, (int)Math.Min(left, buffer.Length)), cancel);
                        if (count == 0) throw new EndOfStreamException();
                        hash.AppendData(buffer, 0, count);
                        await destination.WriteAsync(buffer.AsMemory(0, count), cancel);
                        left -= count;
                    }
                }
                if (Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant() != clip.SourceSha256)
                    throw new InvalidDataException("The demonstration video does not match this disc revision.");
                await Transcode(tool, source, output, cancel).ConfigureAwait(false);
                clips.Add(new(name, new FileInfo(output).Length, await BackgroundVideoTool.Hash(output, cancel), clip.SourceSha256));
            }
            cancel.ThrowIfCancellationRequested();
            foreach (var clip in clips) File.Move(Path.Combine(staging, clip.File), Path.Combine(folder, clip.File), true);
            string manifest = Path.Combine(staging, "videos.json");
            await File.WriteAllTextAsync(manifest, JsonSerializer.Serialize(new Manifest(CacheFormat, game, DiscImport.ExpectedElf(game), clips.ToArray())), cancel);
            File.Move(manifest, Path.Combine(folder, "videos.json"), true);
            return clips.Select(c => Path.Combine(folder, c.File)).ToArray();
        } finally {
            // Only this invocation's randomly named staging directory, inside its own cache.
            if (Directory.Exists(staging) && Path.GetDirectoryName(Path.GetFullPath(staging)) == Path.GetFullPath(folder))
                Directory.Delete(staging, true);
        }
    }

    internal static async Task Transcode(string tool, string source, string output, CancellationToken cancel) {
        cancel.ThrowIfCancellationRequested();
        var start = new ProcessStartInfo(tool) { UseShellExecute = false, CreateNoWindow = true,
            RedirectStandardError = true, RedirectStandardOutput = true };
        foreach (string arg in new[] { "-hide_banner", "-loglevel", "error", "-nostdin", "-y", "-threads", "2",
            "-i", source, "-map", "0:v:0", "-an", "-sn", "-dn", "-map_metadata", "-1", "-c:v", "libx264",
            "-preset", "medium", "-crf", "20", "-pix_fmt", "yuv420p", "-threads", "2", "-movflags", "+faststart", output })
            start.ArgumentList.Add(arg);
        using var process = Process.Start(start) ?? throw new IOException("Could not start background converter.");
        try { process.PriorityClass = ProcessPriorityClass.BelowNormal; }
        catch (Exception error) when (error is InvalidOperationException or System.ComponentModel.Win32Exception) { }
        using var cancellation = cancel.Register(() => {
            try { if (!process.HasExited) process.Kill(entireProcessTree: true); }
            catch (Exception error) when (error is InvalidOperationException or System.ComponentModel.Win32Exception) { }
        });
        var stderr = process.StandardError.ReadToEndAsync();
        var stdout = process.StandardOutput.ReadToEndAsync();
        try {
            await process.WaitForExitAsync(cancel).ConfigureAwait(false);
            cancel.ThrowIfCancellationRequested();
            await Task.WhenAll(stderr, stdout).ConfigureAwait(false);
            if (process.ExitCode != 0 || !File.Exists(output) || new FileInfo(output).Length < 32)
                throw new IOException("Could not convert demonstration video: " + (await stderr)[..Math.Min((await stderr).Length, 600)]);
        } finally {
            if (!process.HasExited) {
                process.Kill(entireProcessTree: true);
                await process.WaitForExitAsync().ConfigureAwait(false);
            }
        }
    }
}
