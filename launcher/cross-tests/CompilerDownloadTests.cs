using System.Net;
using System.Net.Http.Headers;
using System.Security.Cryptography;
using Outbreak.Launcher;

static class CompilerDownloadTests {
    sealed class Handler(
        Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> send)
        : HttpMessageHandler {
        protected override Task<HttpResponseMessage>
        SendAsync(HttpRequestMessage request, CancellationToken cancel) => send(request, cancel);
    }
    sealed class Progress(Action<ImportProgress> report) : IProgress<ImportProgress> {
        public void Report(ImportProgress value) => report(value);
    }
    sealed class Chunks(byte[] data, int chunk, TimeSpan delay, bool fail = false,
                        Action? atEnd = null)
        : MemoryStream
    (data) {
        public override async ValueTask<int> ReadAsync(Memory<byte> buffer,
                                                       CancellationToken cancel = default) {
            await Task.Delay(delay, cancel);
            if (Position == Length) {
                atEnd?.Invoke();
                cancel.ThrowIfCancellationRequested();
                if (fail)
                    throw new IOException("Synthetic broken connection");
            }
            return await base.ReadAsync(buffer[..Math.Min(chunk, buffer.Length)], cancel);
        }
    }
    internal static async Task Run(Action<bool, string> check) {
        string home =
            Path.Combine(Path.GetTempPath(), "reo-download-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(home);
        byte[] data = Enumerable.Range(0, 32).Select(i => (byte)i).ToArray();
        string hash = Convert.ToHexString(SHA256.HashData(data));
        string target = Path.Combine(home, "compiler.part");
        var options = new CompilerDownloadOptions(TimeSpan.FromSeconds(1), 1);
        HttpResponseMessage Response(byte[] body, long? from = null) {
            var result = new HttpResponseMessage(from == null ? HttpStatusCode.OK
                                                              : HttpStatusCode.PartialContent) {
                Content = new ByteArrayContent(body)
            };
            if (from != null)
                result.Content.Headers.ContentRange =
                    new ContentRangeHeaderValue(from.Value, data.Length - 1, data.Length);
            return result;
        }
        async Task Download(
            Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> send,
            CompilerDownloadOptions? settings = null, CancellationToken cancel = default,
            string? archive = null, IProgress<ImportProgress>? progress = null) {
            using var client =
                new HttpClient(new Handler(send)) { Timeout = Timeout.InfiniteTimeSpan };
            await CompilerDownload.Run(client, new Uri("https://compiler.invalid/tools.zip"),
                                       target, data.Length, hash, settings ?? options, progress,
                                       cancel, archive, TimeSpan.Zero);
        }
        async Task Fails(Func<Task> action, string message) {
            bool failed = false;
            try {
                await action();
            } catch (Exception error) when (error is IOException or HttpRequestException) {
                failed = true;
            }
            check(failed, message);
        }
        Task<HttpResponseMessage> Never(HttpRequestMessage r, CancellationToken c) =>
            throw new Exception("Unexpected network request");
        try {
            int requests = 0;
            await Download((r, c) => {
                requests++;
                if (requests == 1) {
                    var result = Response(data);
                    result.Content =
                        new StreamContent(new Chunks(data[..8], 8, TimeSpan.Zero, fail: true));
                    result.Content.Headers.ContentLength = data.Length;
                    return Task.FromResult(result);
                }
                check(r.Headers.Range?.Ranges.Single().From == 8,
                      "Interrupted transfer resumes at saved byte");
                return Task.FromResult(Response(data[8..], 8));
            });
            check(requests == 2 && File.ReadAllBytes(target).SequenceEqual(data),
                  "Retry produces exact archive");
            await Download(Never);
            check(File.Exists(target),
                  "Complete retained archive is verified without downloading again");

            File.WriteAllBytes(target, data[..8]);
            await Download((r, c) => Task.FromResult(Response(data)));
            check(File.ReadAllBytes(target).SequenceEqual(data),
                  "Server ignoring Range restarts without appending");

            File.WriteAllBytes(target, data[..8]);
            requests = 0;
            await Download((r, c) => Task.FromResult(
                               ++requests == 1 ? new HttpResponseMessage(
                                                     HttpStatusCode.RequestedRangeNotSatisfiable)
                                               : Response(data)));
            check(requests == 2 && File.ReadAllBytes(target).SequenceEqual(data),
                  "Rejected resume restarts safely");

            File.WriteAllBytes(target, data[..8]);
            await Fails(() => Download((r, c) => Task.FromResult(Response(data[9..], 9))),
                        "Wrong Content-Range is rejected");
            check(new FileInfo(target).Length == 8,
                  "Invalid range does not alter partial download");

            File.Delete(target);
            requests = 0;
            await Download((r, c) => Task.FromResult(
                               ++requests == 1
                                   ? new HttpResponseMessage(HttpStatusCode.ServiceUnavailable)
                                   : Response(data)));
            check(requests == 2, "Transient HTTP failure is retried");
            File.Delete(target);
            requests = 0;
            await Fails(() => Download((r, c) => {
                            requests++;
                            return Task.FromResult(
                                new HttpResponseMessage(HttpStatusCode.NotFound));
                        }),
                        "Permanent HTTP errors surface");
            check(requests == 1, "Permanent HTTP errors are not retried");

            // Every chunk arrives within the idle limit, although the total exceeds it.
            await Download((r, c) => {
                var result = Response(data);
                result.Content =
                    new StreamContent(new Chunks(data, 4, TimeSpan.FromMilliseconds(75)));
                return Task.FromResult(result);
            }, new(TimeSpan.FromMilliseconds(400), 0));
            check(File.ReadAllBytes(target).SequenceEqual(data),
                  "Slow progressing download outlives idle timeout");

            File.Delete(target);
            requests = 0;
            await Fails(
                () => Download(async (r, c) => {
                    requests++;
                    await Task.Delay(Timeout.Infinite, c);
                    return Response(data);
                }, new(TimeSpan.FromMilliseconds(80), 1)), "Stalled response headers time out");
            check(requests == 2, "Header timeouts respect retry limit");

            File.WriteAllBytes(target, data[..8]);
            requests = 0;
            await Fails(() => Download((r, c) => {
                            requests++;
                            var result = Response(data[8..], 8);
                            result.Content = new StreamContent(
                                new Chunks(data[8..], 4, TimeSpan.FromSeconds(10)));
                            result.Content.Headers.ContentRange =
                                new ContentRangeHeaderValue(8, 31, 32);
                            return Task.FromResult(result);
                        }, new(TimeSpan.FromMilliseconds(80), 1)), "Stalled body times out");
            check(requests == 2 && new FileInfo(target).Length == 8,
                  "Exhausted retries retain partial bytes");
            await Download((r, c) => {
                check(r.Headers.Range?.Ranges.Single().From == 8,
                      "Later Import resumes retained partial");
                return Task.FromResult(Response(data[8..], 8));
            });

            File.Delete(target);
            using (var cancellation = new CancellationTokenSource()) {
                requests = 0;
                bool cancelled = false;
                try {
                    await Download((r, c) => {
                        requests++;
                        var result = Response(data);
                        result.Content = new StreamContent(
                            new Chunks(data[..8], 8, TimeSpan.Zero, atEnd: cancellation.Cancel));
                        result.Content.Headers.ContentLength = data.Length;
                        return Task.FromResult(result);
                    }, cancel: cancellation.Token);
                } catch (OperationCanceledException) {
                    cancelled = true;
                }
                check(cancelled && requests == 1 && new FileInfo(target).Length == 8,
                      "User cancellation preserves bytes and never retries");
            }

            File.WriteAllBytes(target, new byte[data.Length]);
            await Fails(() => Download(Never),
                        "Corrupt complete cached archive fails hash verification");
            check(!File.Exists(target), "Corrupt archive is discarded");
            await Fails(() => Download((r, c) => Task.FromResult(Response(new byte[data.Length]))),
                        "Corrupt fresh download is rejected");
            check(!File.Exists(target), "Corrupt fresh download is discarded");

            string local = Path.Combine(home, "manual.zip");
            File.WriteAllBytes(local, data);
            await Download(Never, archive: local);
            check(File.ReadAllBytes(target).SequenceEqual(data),
                  "Manual archive works without network");
            File.WriteAllBytes(local, new byte[data.Length]);
            await Fails(() => Download(Never, archive: local),
                        "Manual archive requires pinned hash");
            check(!File.Exists(target) && File.Exists(local),
                  "Invalid manual archive never deletes user's source");

            File.WriteAllBytes(target, new byte[data.Length + 1]);
            await Download((r, c) => {
                check(r.Headers.Range == null, "Oversized cached file is restarted");
                return Task.FromResult(Response(data));
            });
            foreach (string name in new[] { "REO_COMPILER_DOWNLOAD_IDLE_SECONDS",
                                            "REO_COMPILER_DOWNLOAD_RETRIES" }) {
                string? prior = Environment.GetEnvironmentVariable(name);
                try {
                    Environment.SetEnvironmentVariable(name, "invalid");
                    bool rejected = false;
                    try {
                        CompilerDownloadOptions.FromEnvironment();
                    } catch (IOException) {
                        rejected = true;
                    }
                    check(rejected, "Invalid " + name + " is explained");
                    Environment.SetEnvironmentVariable(name,
                                                       name.EndsWith("SECONDS") ? "600" : "0");
                    var selected = CompilerDownloadOptions.FromEnvironment();
                    check(name.EndsWith("SECONDS") ? selected.IdleTimeout.TotalSeconds == 600
                                                   : selected.Retries == 0,
                          "Custom " + name + " is honored");
                } finally {
                    Environment.SetEnvironmentVariable(name, prior);
                }
            }
        } finally {
            Directory.Delete(home, true);
        }
    }
}
