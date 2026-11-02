using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
public static partial class Updates {
    static (Version Number, string[] Prerelease) ReleaseIdentity(string tag) {
        var match = Regex.Match(tag,
            @"\A[vV]?(?<number>\d+\.\d+(?:\.\d+){0,2})(?:-(?<pre>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?\z");
        if (!match.Success)
            throw new IOException("Invalid release tag: " + tag);
        return (ParseVersion(match.Groups["number"].Value),
                match.Groups["pre"].Success ? match.Groups["pre"].Value.Split('.') : []);
    }
    public static Version ReleaseVersion(string tag) => ReleaseIdentity(tag).Number;

    // Numeric package versions remain unchanged. Tags distinguish RCs sharing that version.
    public static int CompareReleaseTags(string first, string second) {
        var a = ReleaseIdentity(first);
        var b = ReleaseIdentity(second);
        int number = a.Number.CompareTo(b.Number);
        if (number != 0) return number;
        if (a.Prerelease.Length == 0 || b.Prerelease.Length == 0)
            return (a.Prerelease.Length == 0 ? 1 : 0).CompareTo(b.Prerelease.Length == 0 ? 1 : 0);
        static int Digits(string x, string y) {
            x = x.TrimStart('0'); y = y.TrimStart('0');
            int length = x.Length.CompareTo(y.Length);
            return length != 0 ? length : string.CompareOrdinal(x, y);
        }
        for (int i = 0; i < Math.Min(a.Prerelease.Length, b.Prerelease.Length); i++) {
            string x = a.Prerelease[i], y = b.Prerelease[i];
            bool nx = x.All(char.IsAsciiDigit), ny = y.All(char.IsAsciiDigit);
            int compared;
            if (nx && ny) compared = Digits(x, y);
            else if (nx != ny) compared = nx ? -1 : 1;
            // This project's historical tags use rc1, rc2, ... rather than rc.1.
            else if (Regex.IsMatch(x, @"\Arc\d+\z") && Regex.IsMatch(y, @"\Arc\d+\z"))
                compared = Digits(x[2..], y[2..]);
            else compared = string.CompareOrdinal(x, y);
            if (compared != 0) return compared;
        }
        return a.Prerelease.Length.CompareTo(b.Prerelease.Length);
    }

    public static string InstalledReleaseTag(string root) {
        var version = InstalledVersion(root);
        if (AppLayout.Packaged(root)) {
            using var document = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "distribution.json")));
            if (document.RootElement.TryGetProperty("releaseTag", out var value) &&
                !string.IsNullOrEmpty(value.GetString())) {
                string tag = value.GetString()!;
                if (ReleaseVersion(tag) != version)
                    throw new IOException("The installed release tag does not match its numeric version.");
                return tag;
            }
        }
        return version.ToString();
    }
}
