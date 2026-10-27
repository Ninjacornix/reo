using System.Diagnostics;
using System.IO;
using System.Net.Http;
using System.Text.Json;

namespace Outbreak.Launcher;
public static partial class Updates {
    static async Task<string> ExpectedHash(HttpClient client, LauncherRelease release,
                                           CancellationToken cancel) {
        if (release.Package.Digest?.StartsWith("sha256:", StringComparison.OrdinalIgnoreCase) ==
                true &&
            Hash(release.Package.Digest[7..]))
            return release.Package.Digest[7..].ToLowerInvariant();
        var checksum = release.Checksum ?? throw new IOException("Release checksum missing.");
        if (checksum.Size <= 0 || checksum.Size > 4096)
            throw new IOException("Invalid checksum asset size.");
        using var response =
            await client.GetAsync(checksum.Url, HttpCompletionOption.ResponseHeadersRead, cancel)
                .ConfigureAwait(false);
        response.EnsureSuccessStatusCode();
        using var stream = await response.Content.ReadAsStreamAsync(cancel).ConfigureAwait(false);
        var bytes = new byte[4097];
        int size = 0, count;
        while (size < bytes.Length &&
               (count =
                    await stream.ReadAsync(bytes.AsMemory(size), cancel).ConfigureAwait(false)) > 0)
            size += count;
        string text = System.Text.Encoding.UTF8.GetString(bytes, 0, size).Trim();
        var parts = text.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries);
        if (size > 4096 || parts.Length != 2 || !Hash(parts[0]) ||
            parts[1].TrimStart('*') != release.Package.Name)
            throw new IOException("Release checksum file does not match its package.");
        return parts[0].ToLowerInvariant();
    }
    public static async Task<string> Download(HttpClient client, LauncherRelease release,
                                              string work, IProgress<UpdateProgress>? progress,
                                              CancellationToken cancel) {
        if (!DownloadUrl(release.Package.Url) ||
            (release.Checksum != null && !DownloadUrl(release.Checksum.Url)))
            throw new IOException(
                "Update downloads must come from this project's GitHub releases.");
        Directory.CreateDirectory(work);
        string zip = Path.Combine(work, "download.zip");
        string expected = await ExpectedHash(client, release, cancel).ConfigureAwait(false);
        using var response =
            await client
                .GetAsync(release.Package.Url, HttpCompletionOption.ResponseHeadersRead, cancel)
                .ConfigureAwait(false);
        response.EnsureSuccessStatusCode();
        if (response.Content.Headers.ContentLength is long length && length != release.Package.Size)
            throw new IOException("Release download size changed.");
        var input = await response.Content.ReadAsStreamAsync(cancel).ConfigureAwait(false);
        var output =
            new FileStream(zip, FileMode.CreateNew, FileAccess.Write, FileShare.None, 65536, true);
        await using (input.ConfigureAwait(false)) await using (output.ConfigureAwait(false)) {
            var bytes = new byte[65536];
            long received = 0;
            int count;
            long lastReport = Stopwatch.GetTimestamp();
            while ((count = await input.ReadAsync(bytes, cancel).ConfigureAwait(false)) != 0) {
                received += count;
                if (received > release.Package.Size)
                    throw new IOException("Release download exceeds its advertised size.");
                await output.WriteAsync(bytes.AsMemory(0, count), cancel).ConfigureAwait(false);
                if (Stopwatch.GetElapsedTime(lastReport).TotalMilliseconds >= 150 ||
                    received == release.Package.Size) {
                    progress?.Report(new("Downloading", received * 100.0 / release.Package.Size));
                    lastReport = Stopwatch.GetTimestamp();
                }
            }
            if (received != release.Package.Size)
                throw new IOException("The update download was interrupted.");
        }
        progress?.Report(new("Verifying", 100));
        if (!Sha(zip).Equals(expected, StringComparison.OrdinalIgnoreCase))
            throw new IOException("The update download failed SHA-256 verification.");
        return zip;
    }
    public static void CheckWritable(string target) {
        if (!AppLayout.Packaged(target))
            throw new IOException(
                "Automatic installation is available in packaged releases, not source checkouts.");
        string probe = SafePath(target, ".reo-write-" + Guid.NewGuid().ToString("N"));
        using (var file = new FileStream(probe, FileMode.CreateNew, FileAccess.Write,
                                         FileShare.None)) file.WriteByte(0);
        File.Delete(probe);
    }
    public static async Task<UpdatePlan> Prepare(HttpClient client, LauncherRelease release,
                                                 string target, IProgress<UpdateProgress>? progress,
                                                 CancellationToken cancel) {
        CheckWritable(target);
        string work = Path.Combine(Home, Guid.NewGuid().ToString("N"));
        string zip = await Download(client, release, work, progress, cancel).ConfigureAwait(false);
        string stage = Path.Combine(work, "new");
        await Task
            .Run(
                () => {
                    progress?.Report(new("Unpacking", 100));
                    Extract(zip, stage, cancel);
                    Validate(stage, release.Version, cancel);
                },
                cancel)
            .ConfigureAwait(false);
        using var parent = Process.GetCurrentProcess();
        return new(work, stage, Path.GetFullPath(target), release.Tag, parent.Id,
                   parent.StartTime.ToUniversalTime().Ticks);
    }
    public static bool InstallationBusy(string target) {
        string path = Path.Combine(target, ".reo-update.lock");
        if (!File.Exists(path))
            return false;
        try {
            using var file =
                new FileStream(path, FileMode.Open, FileAccess.ReadWrite, FileShare.None);
            return false;
        } catch (IOException) {
            return true;
        }
    }
    public static async Task StartWorker(UpdatePlan plan, CancellationToken cancel) {
        string helper = Path.Combine(plan.Work, "helper");
        await Task
            .Run(
                () => {
                    Directory.CreateDirectory(helper);
                    foreach (var file in Inventory(plan.Target)
                                 .Where(f => !f.Path.StartsWith(
                                            "games/", StringComparison.OrdinalIgnoreCase))) {
                        cancel.ThrowIfCancellationRequested();
                        string source = SafePath(plan.Target, file.Path),
                               target = SafePath(helper, file.Path);
                        Directory.CreateDirectory(Path.GetDirectoryName(target)!);
                        File.Copy(source, target);
                    }
                    File.Copy(Path.Combine(plan.Target, "package-manifest.json"),
                              Path.Combine(helper, "package-manifest.json"));
                },
                cancel)
            .ConfigureAwait(false);
        string planFile = Path.Combine(plan.Work, "plan.json");
        File.WriteAllText(planFile, JsonSerializer.Serialize(plan, Json));
        var start = new ProcessStartInfo(Path.Combine(helper, "Outbreak.Launcher.exe")) {
            UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = helper
        };
        start.ArgumentList.Add("--apply-update");
        Storage.ProcessEnvironment(start);
        start.ArgumentList.Add(planFile);
        using var process =
            Process.Start(start) ?? throw new IOException("Could not start the update installer.");
        for (int i = 0; i < 600; i++) {
            cancel.ThrowIfCancellationRequested();
            if (File.Exists(Path.Combine(plan.Work, "ready.json")))
                return;
            if (process.HasExited)
                throw new IOException("The update installer could not start. See " + plan.Work);
            await Task.Delay(100, cancel).ConfigureAwait(false);
        }
        throw new IOException(
            "The update installer did not become ready. The launcher has been kept open.");
    }
}
