using System.IO;
using System.IO.Compression;
using System.Net.Http;
using System.Security.Cryptography;

namespace Outbreak.Launcher;

// Optional, private converter. Never depends on a system FFmpeg installation or PATH.
internal static class BackgroundVideoTool {
    internal const string Version = "ffmpeg-9.0.2-essentials_build";
    internal const string Url = "https://www.gyan.dev/ffmpeg/builds/packages/" + Version + ".zip";
    internal const string ArchiveHash = "60f467265b1e312373dbcd92200c2618a74850f98d3d078e94296bb3fa2047ba";
    internal const string ExecutableHash = "3256173f3f8bffd7df12227c68adf68025edb1832273a9530688a7bb1ed8edec";
    const long ArchiveBytes = 114768076;
    static readonly SemaphoreSlim gate = new(1);
    static readonly HashSet<string> verified = new(StringComparer.OrdinalIgnoreCase);

    internal static string Folder(string home) => Path.Combine(home, "media-tools", Version);
    internal static async Task<string> Ensure(string home, CancellationToken cancel, IProgress<ImportProgress>? progress = null) {
        await gate.WaitAsync(cancel).ConfigureAwait(false);
        try {
            string folder = Folder(home), exe = Path.Combine(folder, "ffmpeg.exe");
            if (verified.Contains(exe) && File.Exists(exe)) return exe;
            if (File.Exists(exe) && await Hash(exe, cancel) == ExecutableHash) {
                verified.Add(exe);
                return exe;
            }
            Directory.CreateDirectory(Path.GetDirectoryName(folder)!);
            string zip = folder + ".download-" + Guid.NewGuid().ToString("N") + ".zip";
            try {
                using var deadline = CancellationTokenSource.CreateLinkedTokenSource(cancel);
                deadline.CancelAfter(TimeSpan.FromMinutes(8));
                cancel = deadline.Token; // Includes streamed content, not just HTTP headers.
                using var client = new HttpClient { Timeout = TimeSpan.FromMinutes(8) };
                client.DefaultRequestHeaders.UserAgent.ParseAdd("REO-Launcher/1.0");
                using var response = await client.GetAsync(Url, HttpCompletionOption.ResponseHeadersRead, cancel).ConfigureAwait(false);
                response.EnsureSuccessStatusCode();
                progress?.Report(new(0, ArchiveBytes, "Downloading background video converter", "Preparing background videos"));
                if (response.Content.Headers.ContentLength is long size && size != ArchiveBytes)
                    throw new IOException("Unexpected background converter download.");
                await using (var input = await response.Content.ReadAsStreamAsync(cancel))
                await using (var output = new FileStream(zip, FileMode.CreateNew, FileAccess.Write)) {
                    var buffer = new byte[65536];
                    long total = 0, reported = 0;
                    int count;
                    while ((count = await input.ReadAsync(buffer, cancel)) != 0) {
                        total += count;
                        if (total > ArchiveBytes) throw new IOException("Oversized background converter download.");
                        await output.WriteAsync(buffer.AsMemory(0, count), cancel);
                        if (total - reported >= 524288 || total == ArchiveBytes) {
                            progress?.Report(new(total, ArchiveBytes, $"Downloading background video converter · {total / (1024 * 1024)} / 109 MiB", "Preparing background videos"));
                            reported = total;
                        }
                    }
                    if (total != ArchiveBytes) throw new IOException("Incomplete background converter download.");
                }
                await Install(zip, home, cancel).ConfigureAwait(false);
                verified.Add(exe);
                return exe;
            } finally {
                if (File.Exists(zip)) File.Delete(zip);
            }
        } finally { gate.Release(); }
    }

    // Also used by the offline verification harness with the identical pinned archive.
    internal static async Task Install(string zip, string home, CancellationToken cancel) {
        if (new FileInfo(zip).Length != ArchiveBytes || await Hash(zip, cancel) != ArchiveHash)
            throw new IOException("Background converter verification failed.");
        string folder = Folder(home);
        Directory.CreateDirectory(folder);
        using var archive = ZipFile.OpenRead(zip);
        foreach (string name in new[] { "LICENSE", "README.txt", "ffmpeg.exe" }) {
            string relative = name.EndsWith(".exe") ? "bin/" + name : name;
            var entry = archive.GetEntry(Version + "/" + relative)
                ?? throw new IOException("Background converter archive is incomplete.");
            if (entry.Length > 120000000 || (entry.ExternalAttributes & 0x400) != 0 ||
                ((entry.ExternalAttributes >> 16) & 0xF000) == 0xA000)
                throw new IOException("Invalid background converter entry.");
            string destination = Path.Combine(folder, name), temp = destination + ".tmp-" + Guid.NewGuid().ToString("N");
            try {
                await using (var input = entry.Open())
                await using (var output = new FileStream(temp, FileMode.CreateNew, FileAccess.Write))
                    await input.CopyToAsync(output, cancel).ConfigureAwait(false);
                if (name == "ffmpeg.exe" && await Hash(temp, cancel) != ExecutableHash)
                    throw new IOException("Background converter executable verification failed.");
                File.Move(temp, destination, true);
            } finally { if (File.Exists(temp)) File.Delete(temp); }
        }
        await File.WriteAllTextAsync(Path.Combine(folder, "SOURCE.txt"),
            $"Downloaded from {Url}\nSHA-256: {ArchiveHash}\nBuild/source information: https://www.gyan.dev/ffmpeg/builds/\nFFmpeg source: https://github.com/FFmpeg/FFmpeg/commit/946fcce07b\n", cancel);
    }

    internal static async Task<string> Hash(string path, CancellationToken cancel) {
        await using var stream = File.OpenRead(path);
        return Convert.ToHexString(await SHA256.HashDataAsync(stream, cancel)).ToLowerInvariant();
    }
}
