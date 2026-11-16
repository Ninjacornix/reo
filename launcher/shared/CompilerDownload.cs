using System.Net;
using System.Net.Http.Headers;
using System.Security.Cryptography;
using System.Diagnostics;

namespace Outbreak.Launcher;

internal sealed record CompilerDownloadOptions(TimeSpan IdleTimeout, int Retries) {
    internal static CompilerDownloadOptions FromEnvironment() {
        int Read(string name, int fallback, int minimum, int maximum) {
            string? value = Environment.GetEnvironmentVariable(name);
            if (string.IsNullOrWhiteSpace(value))
                return fallback;
            if (!int.TryParse(value, out int number) || number < minimum || number > maximum)
                throw new IOException($"{name} must be between {minimum} and {maximum}.");
            return number;
        }
        return new(TimeSpan.FromSeconds(Read("REO_COMPILER_DOWNLOAD_IDLE_SECONDS", 120, 1, 3600)),
                   Read("REO_COMPILER_DOWNLOAD_RETRIES", 3, 0, 10));
    }
}

// The setup lock serializes access to the retained archive. Its pinned hash, not HTTP metadata,
// decides whether any downloaded, resumed or manually supplied bytes may be used.
internal static class CompilerDownload {
    static async Task Verify(string path, long bytes, string sha256, CancellationToken cancel) {
        await using var file = File.OpenRead(path);
        if (file.Length != bytes || !Convert.ToHexString(await SHA256.HashDataAsync(file, cancel))
                                         .Equals(sha256, StringComparison.OrdinalIgnoreCase))
            throw new InvalidDataException(
                "Compiler download failed size or SHA-256 verification.");
    }

    internal static async Task Run(HttpClient client, Uri url, string destination, long bytes,
                                   string sha256, CompilerDownloadOptions options,
                                   IProgress<ImportProgress>? progress, CancellationToken cancel,
                                   string? localArchive = null, TimeSpan? retryDelay = null) {
        cancel.ThrowIfCancellationRequested();
        if (!string.IsNullOrWhiteSpace(localArchive)) {
            // Open the source before truncating the cache; never allow selecting the cache itself.
            if (Path.GetFullPath(localArchive)
                    .Equals(Path.GetFullPath(destination), StringComparison.OrdinalIgnoreCase))
                throw new IOException(
                    "Choose a compiler archive outside the launcher's download cache.");
            await using var source = File.OpenRead(localArchive);
            if (source.Length != bytes)
                throw new IOException("The selected compiler archive has an unexpected size.");
            await using (var output = File.Create(destination))
                await source.CopyToAsync(output, cancel);
        } else {
            if (File.Exists(destination) && new FileInfo(destination).Length > bytes)
                File.Delete(destination);
            for (int attempt = 0;; attempt++) {
                long offset = File.Exists(destination) ? new FileInfo(destination).Length : 0;
                if (offset == bytes)
                    break;
                try {
                    await Transfer(client, url, destination, bytes, offset, options.IdleTimeout,
                                   progress, cancel);
                    break;
                } catch (Exception error)
                    when (!cancel.IsCancellationRequested &&
                          (error is OperationCanceledException or EndOfStreamException ||
                           error is HttpRequestException http &&
                               (http.StatusCode == null ||
                                http.StatusCode == HttpStatusCode.RequestTimeout ||
                                http.StatusCode == HttpStatusCode.TooManyRequests ||
                                (int)http.StatusCode >= 500))) {
                    if (attempt >= options.Retries)
                        throw new IOException(
                            "Compiler download stopped after retries. Downloaded data is kept; retry Import to resume. " +
                                "You can also download the required archive in a browser and set REO_COMPILER_ARCHIVE.",
                            error);
                    long received = File.Exists(destination) ? new FileInfo(destination).Length : 0;
                    progress?.Report(new(
                        received, bytes,
                        $"Connection interrupted; retrying ({attempt + 1}/{options.Retries}). Downloaded data is kept.",
                        "Downloading compiler"));
                    await Task.Delay(retryDelay ?? TimeSpan.FromSeconds(Math.Min(10, 1 << attempt)),
                                     cancel);
                }
            }
        }
        cancel.ThrowIfCancellationRequested();
        progress?.Report(new(0, 0, "Verifying compiler download", "Verifying compiler"));
        try {
            await Verify(destination, bytes, sha256, cancel);
        } catch (InvalidDataException) {
            File.Delete(destination);
            throw new IOException("Compiler download failed size or SHA-256 verification. " +
                                  "The invalid download was removed; retry Import.");
        }
        progress?.Report(new(bytes, bytes, "Download verified", "Downloading compiler"));
    }

    static async Task Transfer(HttpClient client, Uri url, string destination, long bytes,
                               long offset, TimeSpan idleTimeout,
                               IProgress<ImportProgress>? progress, CancellationToken cancel) {
        using var idle = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        using var request = new HttpRequestMessage(HttpMethod.Get, url);
        request.Headers.AcceptEncoding.Add(new StringWithQualityHeaderValue("identity"));
        if (offset > 0)
            request.Headers.Range = new RangeHeaderValue(offset, null);
        idle.CancelAfter(idleTimeout);
        using var response =
            await client.SendAsync(request, HttpCompletionOption.ResponseHeadersRead, idle.Token);
        // A server may not support ranges. Restart safely rather than append a whole archive.
        if (response.StatusCode == HttpStatusCode.OK) {
            offset = 0;
        } else if (response.StatusCode == HttpStatusCode.PartialContent) {
            var range = response.Content.Headers.ContentRange;
            if (range?.Unit != "bytes" || range.From != offset || range.To != bytes - 1 ||
                range.Length != bytes)
                throw new IOException("Invalid compiler download range response.");
        } else if (response.StatusCode == HttpStatusCode.RequestedRangeNotSatisfiable &&
                   offset > 0) {
            File.Delete(destination);
            throw new EndOfStreamException("Compiler server rejected resume; restarting download.");
        } else {
            response.EnsureSuccessStatusCode();
            throw new IOException("Unexpected compiler download response.");
        }
        if (response.Content.Headers.ContentLength is long length && length != bytes - offset)
            throw new IOException("Unexpected compiler download size.");
        idle.CancelAfter(idleTimeout);
        await using var input = await response.Content.ReadAsStreamAsync(idle.Token);
        await using var output =
            new FileStream(destination, offset == 0 ? FileMode.Create : FileMode.Append,
                           FileAccess.Write, FileShare.None, 65536, true);
        long received = offset, last = offset;
        progress?.Report(new(received, bytes,
                             offset > 0 ? "Resuming build tools download"
                                        : "Downloading build tools automatically",
                             "Downloading compiler"));
        var buffer = new byte[65536];
        var reported = Stopwatch.StartNew();
        while (true) {
            idle.CancelAfter(idleTimeout);
            int count;
            try {
                count = await input.ReadAsync(buffer, idle.Token);
            } catch (IOException error) {
                throw new HttpRequestException("Compiler connection interrupted.", error);
            }
            idle.CancelAfter(Timeout.InfiniteTimeSpan);
            if (count == 0)
                break;
            received += count;
            if (received > bytes)
                throw new IOException("Compiler download exceeds expected size.");
            await output.WriteAsync(buffer.AsMemory(0, count), cancel);
            if (received - last >= 524288 || reported.Elapsed >= TimeSpan.FromSeconds(1)) {
                progress?.Report(new(received, bytes, "Downloading build tools automatically",
                                     "Downloading compiler"));
                last = received;
                reported.Restart();
            }
        }
        if (received != bytes)
            throw new EndOfStreamException("Compiler download was interrupted.");
    }
}
