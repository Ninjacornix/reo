using System.IO;
using System.Net;
using System.Net.Http;
using System.Security.Cryptography;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

internal static class GameArtworkDownloadTests {
    sealed class Handler(Func<HttpResponseMessage> response) : HttpMessageHandler {
        public int Requests;
        protected override Task<HttpResponseMessage> SendAsync(HttpRequestMessage request, CancellationToken token) {
            token.ThrowIfCancellationRequested();
            ++Requests;
            return Task.FromResult(response());
        }
    }
    internal static void Run(Action<bool, string> check) => Task.Run(async () => {
        string root = Path.Combine(Path.GetTempPath(), "reo-art-download-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            var image = BitmapSource.Create(1, 1, 96, 96, PixelFormats.Bgra32, null,
                                             new byte[] { 10, 80, 210, 255 }, 4);
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(image));
            using var buffer = new MemoryStream();
            encoder.Save(buffer);
            byte[] bytes = buffer.ToArray();
            var asset = new GameArtwork.Download("file1-cover.png", "https://example.invalid/cover.png",
                bytes.Length, Convert.ToHexString(SHA256.HashData(bytes)));
            using var http = new Handler(() => new(HttpStatusCode.OK) { Content = new ByteArrayContent(bytes) });
            using var client = new HttpClient(http);
            long progress = 0;
            await GameArtwork.DownloadAsset(client, root, asset, value => progress = value, default);
            string target = Path.Combine(root, asset.Name);
            check(progress == bytes.Length && File.ReadAllBytes(target).SequenceEqual(bytes) &&
                      GameArtwork.DownloadCurrent(root, asset),
                  "First-run artwork is verified and saved with byte progress");
            await GameArtwork.DownloadAsset(client, root, asset, null, default);
            check(http.Requests == 1, "Verified cached artwork makes no new network request");
            File.WriteAllText(target, "corrupt cache");
            await GameArtwork.DownloadAsset(client, root, asset, null, default);
            check(http.Requests == 2 && GameArtwork.DownloadCurrent(root, asset),
                  "Corrupt cached artwork is downloaded again and repaired");
            var changed = asset with { Sha256 = new string('0', 64) };
            try { await GameArtwork.DownloadAsset(client, root, changed, null, default); }
            catch (IOException) { }
            check(File.ReadAllBytes(target).SequenceEqual(bytes) &&
                      !Directory.GetFiles(root, "*.partial-*").Any(),
                  "Failed verification preserves existing art and removes partial downloads");
            string offline = Path.Combine(root, "offline");
            using var unavailable = new HttpClient(new Handler(() => throw new HttpRequestException("offline")));
            try { await GameArtwork.DownloadAsset(unavailable, offline, asset, null, default); }
            catch (HttpRequestException) { }
            check(!File.Exists(Path.Combine(offline, asset.Name)) &&
                      GameArtwork.LoadCaseArtwork(new[] { offline }, 1, GameArtwork.DefaultIdentity(1)) == null,
                  "Offline first launch leaves placeholders without admitting incomplete images");
            byte[] invalid = "not an image"u8.ToArray();
            var badImage = asset with { Name = "invalid.png", Bytes = invalid.Length,
                Sha256 = Convert.ToHexString(SHA256.HashData(invalid)) };
            using var invalidClient = new HttpClient(new Handler(() => new(HttpStatusCode.OK) {
                Content = new ByteArrayContent(invalid)
            }));
            try { await GameArtwork.DownloadAsset(invalidClient, root, badImage, null, default); }
            catch (IOException) { }
            check(!File.Exists(Path.Combine(root, badImage.Name)) && !Directory.GetFiles(root, "*.partial-*").Any(),
                  "Non-image responses never replace a case texture even with a matching transfer hash");
            using var cancellation = new CancellationTokenSource();
            cancellation.Cancel();
            string canceled = Path.Combine(root, "canceled");
            try { await GameArtwork.DownloadAsset(client, canceled, asset, null, cancellation.Token); }
            catch (OperationCanceledException) { }
            check(!File.Exists(Path.Combine(canceled, asset.Name)) &&
                      !Directory.GetFiles(canceled, "*.partial-*").Any(),
                  "Canceling artwork setup leaves no admitted or partial image");
        } finally {
            string full = Path.GetFullPath(root);
            string temp = Path.GetFullPath(Path.GetTempPath()).TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar;
            if (full.StartsWith(temp, StringComparison.OrdinalIgnoreCase) &&
                Path.GetFileName(full).StartsWith("reo-art-download-", StringComparison.Ordinal))
                Directory.Delete(full, true);
        }
    }).GetAwaiter().GetResult();
}
