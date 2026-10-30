using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

// Personal artwork overrides artwork cached by the automatic first-run download.
static partial class GameArtwork {
    internal record Identity(string Serial, string Region);
    internal record CaseArtwork(BitmapSource Front, BitmapSource? Back, BitmapSource? Spine);
    sealed record WrapLayout(int[] Front, int[] Back, int[] Spine);
    public static string Folder => Path.Combine(Settings.Home, "artwork");
    public static string DownloadFolder => Path.Combine(Folder, "downloaded");
    internal static Identity DefaultIdentity(int edition) =>
        new(edition == 2 ? "SLUS-20984" : "SLUS-20765", "ntsc-u");
    internal static Identity FromBootConfig(int edition, string config) {
        var boots = Regex.Matches(config.TrimStart('\uFEFF'),
            @"(?im)^[ \t]*BOOT2[ \t]*=[ \t]*cdrom0?:[\\/]+(?:[A-Z0-9_.-]+[\\/])*(?<prefix>[A-Z]{4})_(?<first>\d{3})\.(?<last>\d{2})(?:;1)?[ \t]*\r?$",
            RegexOptions.None, TimeSpan.FromSeconds(1));
        if (boots.Count != 1)
            return DefaultIdentity(edition);
        var boot = boots[0];
        if (boot.Value.Replace('\\', '/').Split('/').Any(part => part is "." or ".."))
            return DefaultIdentity(edition);
        string prefix = boot.Groups["prefix"].Value.ToUpperInvariant();
        string serial = prefix + "-" + boot.Groups["first"].Value + boot.Groups["last"].Value;
        if (DiscValidation.GameForSerial(serial) != "file" + edition)
            return DefaultIdentity(edition);
        return new(serial, prefix switch {
            "SLES" or "SCES" => "pal",
            "SLPM" or "SLPS" or "SCPS" => "ntsc-j",
            _ => "ntsc-u"
        });
    }
    internal static Identity DiscIdentity(int edition, string iso) {
        try {
            using var disc = new DiscImage(iso);
            var config = disc.Entries.SingleOrDefault(e => !e.Directory &&
                e.Name.Equals("SYSTEM.CNF", StringComparison.OrdinalIgnoreCase));
            return config == null ? DefaultIdentity(edition)
                                  : FromBootConfig(edition, disc.ReadText(config, 16384));
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                              ArgumentException or RegexMatchTimeoutException) {
            return DefaultIdentity(edition);
        }
    }
    static IEnumerable<string> CandidateStems(int edition, Identity identity) =>
        new[] { identity.Serial, $"file{edition}-{identity.Region}", $"file{edition}",
                $"file{edition}-ntsc-u" }
            .Distinct(StringComparer.OrdinalIgnoreCase);
    internal static IEnumerable<string> CandidateNames(int edition, Identity identity) =>
        CandidateStems(edition, identity)
            .SelectMany(stem => new[] { stem + "-cover.jpg", stem + "-cover.png" });
    internal static BitmapImage? LoadCover(string folder, int edition, Identity identity) {
        return LoadCover(new[] { folder }, edition, identity);
    }
    internal static BitmapImage? LoadCover(IEnumerable<string> folders, int edition, Identity identity) {
        var locations = folders.ToArray();
        foreach (string candidate in CandidateNames(edition, identity)) {
            foreach (string folder in locations) {
                var image = LoadImage(Path.Combine(folder, candidate));
                if (image != null)
                    return image;
            }
        }
        return null;
    }
    internal static CaseArtwork? LoadCaseArtwork(IEnumerable<string> folders, int edition, Identity identity) {
        var locations = folders.ToArray();
        foreach (string stem in CandidateStems(edition, identity)) {
            foreach (string folder in locations) {
                foreach (string extension in new[] { ".jpg", ".png" }) {
                    string wrap = Path.Combine(folder, stem + "-wrap" + extension);
                    if (LoadWrap(wrap) is { } artwork)
                        return artwork;
                }
                var front = LoadImage(Path.Combine(folder, stem + "-cover.jpg")) ??
                            LoadImage(Path.Combine(folder, stem + "-cover.png"));
                if (front == null)
                    continue;
                BitmapSource? Part(string name) => locations.SelectMany(location => new[] {
                    Path.Combine(location, stem + "-" + name + ".jpg"),
                    Path.Combine(location, stem + "-" + name + ".png")
                }).Select(path => LoadImage(path, name == "spine" ? 0 : 1200)).FirstOrDefault(image => image != null);
                return new(front, Part("back"), Part("spine"));
            }
        }
        return null;
    }
    static CaseArtwork? LoadWrap(string path) {
        var image = LoadImage(path, 0);
        if (image == null || image.PixelWidth <= image.PixelHeight)
            return null;
        try {
            string metadata = Path.ChangeExtension(path, ".json");
            WrapLayout? layout;
            if (File.Exists(metadata)) {
                layout = JsonSerializer.Deserialize<WrapLayout>(File.ReadAllText(metadata),
                    new JsonSerializerOptions { PropertyNameCaseInsensitive = true });
            } else {
                int spine = (int)Math.Round(image.PixelWidth * 14.0 / 284);
                int back = (image.PixelWidth - spine) / 2, height = image.PixelHeight;
                layout = new(new[] { back + spine, 0, image.PixelWidth - back - spine, height },
                    new[] { 0, 0, back, height }, new[] { back, 0, spine, height });
            }
            bool Valid(int[]? rectangle) => rectangle is { Length: 4 } &&
                rectangle[0] >= 0 && rectangle[1] >= 0 && rectangle[2] > 0 && rectangle[3] > 0 &&
                (long)rectangle[0] + rectangle[2] <= image.PixelWidth &&
                (long)rectangle[1] + rectangle[3] <= image.PixelHeight;
            if (layout == null || !Valid(layout.Front) || !Valid(layout.Back) || !Valid(layout.Spine))
                return null;
            BitmapSource Crop(int[] rectangle) {
                var crop = new CroppedBitmap(image,
                    new Int32Rect(rectangle[0], rectangle[1], rectangle[2], rectangle[3]));
                crop.Freeze();
                return crop;
            }
            return new(Crop(layout.Front), Crop(layout.Back), Crop(layout.Spine));
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                              JsonException or ArgumentException) {
            return null;
        }
    }
    static BitmapImage? LoadImage(string path, int decodeWidth = 1200) {
        try {
            using var stream = File.OpenRead(path);
            var bitmap = new BitmapImage();
            bitmap.BeginInit();
            bitmap.CacheOption = BitmapCacheOption.OnLoad;
            bitmap.DecodePixelWidth = decodeWidth;
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
    public static Task<CaseArtwork?> FetchAsync(int edition, string iso) =>
        Task.Run(() => LoadCaseArtwork(new[] { Folder, DownloadFolder }, edition, DiscIdentity(edition, iso)));
    public static string CacheKey(IEnumerable<string> paths) => string.Join('|', paths.Select(path => {
        try {
            if (Directory.Exists(path))
                return path + ":" + Directory.GetLastWriteTimeUtc(path).Ticks;
            var file = new FileInfo(path);
            return path + ":" + (file.Exists ? $"{file.Length}:{file.LastWriteTimeUtc.Ticks}" : "missing");
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or ArgumentException) {
            return path + ":unavailable";
        }
    }));
}
