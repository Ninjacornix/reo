using System.IO;
using System.Net.Http;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

// Publisher covers are cached locally, separately from the GPL artwork in Assets.
static class GameArtwork {
    static readonly HttpClient Client = new() { Timeout = TimeSpan.FromSeconds(12) };
    static readonly string[] Sources = {
        "https://upload.wikimedia.org/wikipedia/en/a/ad/Re_outbreak_a.jpg",
        "https://upload.wikimedia.org/wikipedia/en/9/9c/Resident_Evil_Outbreak_File_2.jpg"
    };
    public static string Folder => Path.Combine(Settings.Home, "artwork");
    public static BitmapImage? Cached(int edition) {
        try {
            return Decode(File.ReadAllBytes(Path.Combine(Folder, $"file{edition}-cover.jpg")));
        } catch (Exception error)
            when (error is IOException or UnauthorizedAccessException or NotSupportedException or
                      ArgumentException or System.IO.FileFormatException) {
            return null;
        }
    }
    static BitmapImage Decode(byte[] bytes) {
        using var stream = new MemoryStream(bytes);
        var bitmap = new BitmapImage();
        bitmap.BeginInit();
        bitmap.CacheOption = BitmapCacheOption.OnLoad;
        bitmap.DecodePixelWidth = 1200;
        bitmap.StreamSource = stream;
        bitmap.EndInit();
        bitmap.Freeze();
        return bitmap;
    }
    public static async Task<BitmapImage?> FetchAsync(int edition) {
        var cached = Cached(edition);
        if (cached != null)
            return cached;
        string? temporary = null;
        try {
            using var request = new HttpRequestMessage(HttpMethod.Get, Sources[edition - 1]);
            request.Headers.UserAgent.ParseAdd(
                "OutbreakLauncher/0.1 (https://github.com/Ninjacornix/reo)");
            using var response =
                await Client.SendAsync(request, HttpCompletionOption.ResponseHeadersRead)
                    .ConfigureAwait(false);
            response.EnsureSuccessStatusCode();
            const int limit = 2 * 1024 * 1024;
            if (response.Content.Headers.ContentLength > limit)
                return null;
            using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(12));
            using var input =
                await response.Content.ReadAsStreamAsync(timeout.Token).ConfigureAwait(false);
            using var output = new MemoryStream();
            var buffer = new byte[16384];
            int count;
            while ((count = await input.ReadAsync(buffer, timeout.Token).ConfigureAwait(false)) !=
                   0) {
                if (output.Length + count > limit)
                    return null;
                output.Write(buffer, 0, count);
            }
            var bytes = output.ToArray();
            var bitmap = Decode(bytes);
            Directory.CreateDirectory(Folder);
            temporary = Path.Combine(Folder, Guid.NewGuid() + ".tmp");
            await File.WriteAllBytesAsync(temporary, bytes).ConfigureAwait(false);
            File.Move(temporary, Path.Combine(Folder, $"file{edition}-cover.jpg"), true);
            return bitmap;
        } catch (Exception error)
            when (error is HttpRequestException or IOException or UnauthorizedAccessException or
                      OperationCanceledException or NotSupportedException or ArgumentException or
                          System.IO.FileFormatException) {
            return null;
        } finally {
            if (temporary != null)
                try {
                    File.Delete(temporary);
                } catch (IOException) {
                } catch (UnauthorizedAccessException) {
                }
        }
    }
}
