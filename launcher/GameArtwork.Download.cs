using System.IO;
using System.Net.Http;
using System.Security.Cryptography;

namespace Outbreak.Launcher;

static partial class GameArtwork {
    internal record Download(string Name, string Url, long Bytes, string Sha256);
    internal record DownloadProgress(double Percent, string Detail);
    internal static readonly Download[] Downloads = {
        new("file1-ntsc-u-wrap.jpg", "https://psxdatacenter.com/psx2/images2/hires/SLUS-20765/SLUS-20765-F-ALL.jpg",
            1788204, "2826dd99c6b4e85367bda7c600c0db18f80e7199f4807af8b8eb306d43fc4395"),
        new("file2-ntsc-u-cover.jpg", "https://images.launchbox-app.com/r2_926a0694-7890-456a-a9f0-cf4b84571e2c.jpg",
            513506, "9204d96c00599e409b3bd86b2a15c23d1b7eb1946bf207fb3f48e71235fc6934"),
        new("file2-ntsc-u-back.jpg", "https://images.launchbox-app.com/5e85cd55-a093-4159-a297-c45ad2ca7671.jpg",
            320374, "5ce93996367c2246336b18a08f42c3adcd573bdb5bbbd0ee8ad58d10517fbea1"),
        new("file2-ntsc-u-spine.jpg", "https://images.launchbox-app.com/8c4509ac-8d5e-4d4c-a226-0a4355806ac8.jpg",
            31504, "5d8fd502d0b2033cb3ef7ba2d6dad4fcf60be49886b0e893ba97ec27c3c875ad")
    };
    internal const string DownloadLayout = "{\"front\":[1712,0,1494,2136],\"back\":[0,0,1534,2136],\"spine\":[1534,0,178,2136]}";
    internal static bool DownloadCurrent(string folder, Download asset) {
        try {
            string path = Path.Combine(folder, asset.Name);
            if (new FileInfo(path).Length != asset.Bytes)
                return false;
            using var file = File.OpenRead(path);
            return Convert.ToHexString(SHA256.HashData(file)).Equals(asset.Sha256, StringComparison.OrdinalIgnoreCase);
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return false;
        }
    }
    public static bool DownloadsCurrent() {
        try {
            return Downloads.All(asset => DownloadCurrent(DownloadFolder, asset)) &&
                   File.ReadAllText(Path.Combine(DownloadFolder, "file1-ntsc-u-wrap.json")) == DownloadLayout;
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return false;
        }
    }
    internal static async Task DownloadAsset(HttpClient client, string folder, Download asset,
                                            Action<long>? progress, CancellationToken cancel) {
        if (DownloadCurrent(folder, asset)) {
            progress?.Invoke(asset.Bytes);
            return;
        }
        Directory.CreateDirectory(folder);
        string target = Path.Combine(folder, asset.Name);
        string temporary = target + ".partial-" + Guid.NewGuid().ToString("N");
        try {
            using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
            timeout.CancelAfter(TimeSpan.FromSeconds(15));
            using var response = await client.GetAsync(asset.Url, HttpCompletionOption.ResponseHeadersRead, timeout.Token).ConfigureAwait(false);
            response.EnsureSuccessStatusCode();
            if (response.Content.Headers.ContentLength is { } length && length != asset.Bytes)
                throw new IOException("Cover artwork size does not match the expected image.");
            using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
            await using (var input = await response.Content.ReadAsStreamAsync(timeout.Token).ConfigureAwait(false))
            await using (var output = new FileStream(temporary, FileMode.CreateNew, FileAccess.Write,
                             FileShare.None, 65536, FileOptions.Asynchronous)) {
                byte[] buffer = new byte[65536];
                long received = 0;
                int count;
                while ((count = await input.ReadAsync(buffer, timeout.Token).ConfigureAwait(false)) != 0) {
                    received += count;
                    if (received > asset.Bytes)
                        throw new IOException("Cover artwork exceeds the expected image size.");
                    hash.AppendData(buffer, 0, count);
                    await output.WriteAsync(buffer.AsMemory(0, count), timeout.Token).ConfigureAwait(false);
                    progress?.Invoke(received);
                }
                if (received != asset.Bytes || !Convert.ToHexString(hash.GetHashAndReset())
                        .Equals(asset.Sha256, StringComparison.OrdinalIgnoreCase))
                    throw new IOException("Cover artwork did not pass verification.");
            }
            if (LoadImage(temporary, 0) == null)
                throw new IOException("Downloaded cover artwork could not be opened.");
            File.Move(temporary, target, true);
        } finally {
            try { File.Delete(temporary); }
            catch (IOException) { }
            catch (UnauthorizedAccessException) { }
        }
    }
    public static async Task DownloadMissing(HttpClient client, IProgress<DownloadProgress>? progress,
                                             CancellationToken cancel) {
        Directory.CreateDirectory(DownloadFolder);
        // This is authored crop metadata, not an image shipped with the launcher.
        string layout = Path.Combine(DownloadFolder, "file1-ntsc-u-wrap.json");
        string pending = layout + ".partial-" + Guid.NewGuid().ToString("N");
        try {
            await File.WriteAllTextAsync(pending, DownloadLayout, cancel).ConfigureAwait(false);
            File.Move(pending, layout, true);
        } finally {
            if (File.Exists(pending)) File.Delete(pending);
        }
        long total = Downloads.Sum(asset => asset.Bytes), completed = 0;
        foreach (var asset in Downloads) {
            cancel.ThrowIfCancellationRequested();
            long prior = completed;
            try {
                await DownloadAsset(client, DownloadFolder, asset,
                    bytes => progress?.Report(new((prior + bytes) * 100.0 / total,
                        asset.Name.StartsWith("file1") ? "Outbreak: File #1" : "Outbreak: File #2")), cancel).ConfigureAwait(false);
            } catch (Exception error) when (error is HttpRequestException or IOException or
                                                  UnauthorizedAccessException ||
                                                  error is OperationCanceledException && !cancel.IsCancellationRequested) {
                // Artwork is optional. Keep other successful files and try the rest.
            }
            completed += asset.Bytes;
            progress?.Report(new(completed * 100.0 / total, "Preparing cover artwork"));
        }
    }
}
