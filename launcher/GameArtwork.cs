using System.IO;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

// User-local artwork is optional. Publisher artwork is never downloaded or bundled.
static class GameArtwork {
    public static string Folder => Path.Combine(Settings.Home, "artwork");
    public static BitmapImage? Cached(int edition) {
        try {
            using var stream = File.OpenRead(Path.Combine(Folder, $"file{edition}-cover.jpg"));
            var bitmap = new BitmapImage();
            bitmap.BeginInit();
            bitmap.CacheOption = BitmapCacheOption.OnLoad;
            bitmap.DecodePixelWidth = 1200;
            bitmap.StreamSource = stream;
            bitmap.EndInit();
            bitmap.Freeze();
            return bitmap;
        } catch (Exception error)
            when (error is IOException or UnauthorizedAccessException or NotSupportedException or
                      ArgumentException or System.IO.FileFormatException) {
            return null;
        }
    }
    public static Task<BitmapImage?> FetchAsync(int edition) => Task.FromResult(Cached(edition));
}
