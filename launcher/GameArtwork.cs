using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

// Personal artwork overrides artwork cached by the automatic first-run download.
static partial class GameArtwork {
    internal record Identity(string Serial, string Region);
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
        } catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or
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
