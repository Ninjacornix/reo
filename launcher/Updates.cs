using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Net;
using System.Net.Http;
using System.Security.Cryptography;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
public record ReleaseAsset(string Name, Uri Url, long Size, string? Digest);
public record LauncherRelease(string Tag, Version Version, ReleaseAsset Package,
                              ReleaseAsset? Checksum);
public record UpdateProgress(string Stage, double Percent);
public record PackageFile(string Path, long Bytes, string Sha256);
public record UpdatePlan(string Work, string Source, string Target, string Version, int ParentPid,
                         long ParentStarted);
public static partial class Updates {
    public const string Repository = "https://github.com/Ninjacornix/reo";
    public const string LatestApi = "https://api.github.com/repos/Ninjacornix/reo/releases/latest";
    public const string DefaultVersion = "1.0.7";
    public static readonly JsonSerializerOptions Json =
        new() { PropertyNameCaseInsensitive = true, WriteIndented = true };
    public static string Home => Path.Combine(Settings.Home, "updates");
    const long MaxZip = 1024L * 1024 * 1024, MaxExpanded = 3L * 1024 * 1024 * 1024;
    const int MaxPackageEntries = 25000;
    [DllImport("kernel32.dll", CharSet = CharSet.Unicode)]
    static extern uint GetLongPathNameW(string path, StringBuilder result, uint capacity);
    public static string CanonicalDirectory(string path) {
        string absolute = Path.GetFullPath(path);
        var result = new StringBuilder(32768);
        uint count = GetLongPathNameW(absolute, result, (uint)result.Capacity);
        if (count == 0 || count >= result.Capacity)
            throw new IOException("Could not resolve update directory.");
        return result.ToString().TrimEnd(Path.DirectorySeparatorChar);
    }
    public static Version ParseVersion(string value) {
        string v = value.TrimStart('v', 'V');
        if (!Regex.IsMatch(v, @"^\d+\.\d+(\.\d+)?(\.\d+)?$") ||
            !Version.TryParse(v, out var version))
            throw new IOException("Release tag must be a stable numeric version, such as v0.2.0.");
        return new(version.Major, version.Minor, Math.Max(0, version.Build),
                   Math.Max(0, version.Revision));
    }
    public static Version InstalledVersion(string root) {
        if (AppLayout.Packaged(root)) {
            using var doc =
                JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "distribution.json")));
            if (doc.RootElement.TryGetProperty("version", out var value))
                return ParseVersion(value.GetString() ?? "");
        }
        return ParseVersion(DefaultVersion);
    }
    public static HttpClient Client() {
        var client = new HttpClient { Timeout = Timeout.InfiniteTimeSpan };
        client.DefaultRequestHeaders.UserAgent.ParseAdd("RE-Outbreak-Launcher/" + DefaultVersion);
        client.DefaultRequestHeaders.Accept.ParseAdd("application/vnd.github+json");
        client.DefaultRequestHeaders.Add("X-GitHub-Api-Version", "2022-11-28");
        return client;
    }
    static bool
    DownloadUrl(Uri uri) => uri.Scheme == "https" && uri.IsDefaultPort
                            && uri.UserInfo.Length == 0 &&
                            uri.Host.Equals("github.com", StringComparison.OrdinalIgnoreCase) &&
                            uri.AbsolutePath.StartsWith("/Ninjacornix/reo/releases/download/",
                                                        StringComparison.OrdinalIgnoreCase);
    static bool Hash(string? hash) => hash != null && Regex.IsMatch(hash, @"\A[0-9a-fA-F]{64}\z");
    public static LauncherRelease? ParseRelease(string json, Version installed,
                                                bool includePrereleases = false) {
        using var doc = JsonDocument.Parse(json);
        var r = doc.RootElement;
        if (r.GetProperty("draft").GetBoolean() ||
            (!includePrereleases && r.GetProperty("prerelease").GetBoolean()))
            return null;
        string tag = r.GetProperty("tag_name").GetString() ?? "";
        var version = ParseVersion(tag);
        if (version <= installed)
            return null;
        var assets = new List<ReleaseAsset>();
        foreach (var a in r.GetProperty("assets").EnumerateArray()) {
            if (a.TryGetProperty("state", out var state) && state.GetString() != "uploaded")
                continue;
            if (!Uri.TryCreate(a.GetProperty("browser_download_url").GetString(), UriKind.Absolute,
                               out var url) ||
                !DownloadUrl(url))
                continue;
            string name = a.GetProperty("name").GetString() ?? "";
            assets.Add(new(name, url, a.GetProperty("size").GetInt64(),
                           a.TryGetProperty("digest", out var digest) ? digest.GetString() : null));
        }
        var packages =
            assets
                .Where(a => a.Name.StartsWith("RE-Outbreak-", StringComparison.OrdinalIgnoreCase) &&
                            a.Name.EndsWith(".zip", StringComparison.OrdinalIgnoreCase) &&
                            (a.Name.Contains("Windows-x64", StringComparison.OrdinalIgnoreCase) ||
                             a.Name.Contains("win-x64", StringComparison.OrdinalIgnoreCase)))
                .ToList();
        var package =
            packages.FirstOrDefault(a => a.Name.Equals($"RE-Outbreak-{tag}-Windows-x64.zip",
                                                       StringComparison.OrdinalIgnoreCase));
        if (package == null && packages.Count == 1)
            package = packages[0];
        if (package == null)
            throw new IOException(packages.Count == 0
                                      ? "The latest release has no Windows x64 package yet."
                                      : "The latest release has multiple Windows packages; name " +
                                            "its updater asset RE-Outbreak-<tag>-Windows-x64.zip.");
        if (package.Size <= 0 || package.Size > MaxZip)
            throw new IOException("Release package size is invalid.");
        var checksum = assets.FirstOrDefault(
            a => a.Name.Equals(package.Name + ".sha256", StringComparison.OrdinalIgnoreCase));
        if (!(package.Digest?.StartsWith("sha256:", StringComparison.OrdinalIgnoreCase) == true &&
              Hash(package.Digest[7..])) &&
            checksum == null)
            throw new IOException("This release has no SHA-256 digest or checksum asset. It " +
                                  "cannot be installed automatically.");
        return new(tag, version, package, checksum);
    }
    public static bool PrereleaseChannel(string root) {
        if (!AppLayout.Packaged(root))
            return true;
        using var document =
            JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "distribution.json")));
        return document.RootElement.TryGetProperty("prerelease", out var value) &&
               value.ValueKind == JsonValueKind.True;
    }
    public static async Task<LauncherRelease?> Check(HttpClient client, Version installed,
                                                     CancellationToken cancel,
                                                     bool includePrereleases = false) {
        using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        timeout.CancelAfter(TimeSpan.FromSeconds(20));
        string endpoint = includePrereleases
                              ? "https://api.github.com/repos/Ninjacornix/reo/releases?per_page=100"
                              : LatestApi;
        using var response = await client.GetAsync(endpoint, timeout.Token).ConfigureAwait(false);
        if (response.StatusCode == HttpStatusCode.NotFound)
            return null;
        if (response.StatusCode == HttpStatusCode.Forbidden || (int)response.StatusCode == 429)
            throw new IOException("GitHub's request limit was reached. Try again later.");
        response.EnsureSuccessStatusCode();
        string json = await response.Content.ReadAsStringAsync(timeout.Token).ConfigureAwait(false);
        if (!includePrereleases)
            return ParseRelease(json, installed);
        using var releases = JsonDocument.Parse(json);
        LauncherRelease? newest = null;
        foreach (var release in releases.RootElement.EnumerateArray()) {
            // Source-only releases are not installable launcher updates.
            if (!release.GetProperty("assets").EnumerateArray().Any(a => {
                    string name = a.GetProperty("name").GetString() ?? "";
                    return name.StartsWith("RE-Outbreak-", StringComparison.OrdinalIgnoreCase) &&
                           name.EndsWith(".zip", StringComparison.OrdinalIgnoreCase) &&
                           (name.Contains("Windows-x64", StringComparison.OrdinalIgnoreCase) ||
                            name.Contains("win-x64", StringComparison.OrdinalIgnoreCase));
                }))
                continue;
            var candidate = ParseRelease(release.GetRawText(), installed, true);
            if (candidate != null && (newest == null || candidate.Version > newest.Version))
                newest = candidate;
        }
        return newest;
    }
    public static string Sha(string file) {
        using var stream = File.OpenRead(file);
        return Convert.ToHexString(SHA256.HashData(stream)).ToLowerInvariant();
    }
}
