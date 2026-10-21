using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Net.Http;
using System.Text.Json;
using System.Text;

namespace Outbreak.Launcher;

internal static class ServerPythonSetup {
    const string UvVersion = "0.13.3";
    const string UvUrl =
        "https://github.com/astral-sh/uv/releases/download/0.13.3/uv-x86_64-pc-windows-msvc.zip";
    const string ZipHash = "bb701bd35b586c45966654ea2703c9bd116a6a4fc0a8ca755bd644c2c41c5ebe";
    const string ExeHash = "9d2c061a89d51efe90beb970aa1928ae083e3bc8407463ffdb12c6ca916bfc10";
    internal static async Task<string> Ensure(string home, string source, string requirements,
                                              IProgress<string>? progress, CancellationToken cancel,
                                              IProgress<ImportProgress>? details = null) {
        string hash = Updates.Sha(requirements);
        string parent = Path.Combine(home, "server-python");
        Directory.CreateDirectory(parent);
        using var lease = await Lock(parent, progress, cancel);
        string environment = Path.Combine(parent, hash),
               python = Path.Combine(environment, "Scripts", "python.exe"),
               receipt = Path.Combine(environment, "ready.json");
        if (File.Exists(python) && File.Exists(receipt)) {
            using var record = JsonDocument.Parse(await File.ReadAllTextAsync(receipt, cancel));
            if (record.RootElement.GetProperty("requirementsSha256").GetString() == hash) {
                try {
                    await HostedServer.CheckExternalPython(python, source, cancel);
                    return python;
                } catch (IOException) { /* Repair an interrupted or modified environment below. */
                }
            }
        }
        string uv = await Tool(home, progress, cancel, details);
        if (!File.Exists(python)) {
            if (Directory.Exists(environment)) {
                // Preserve incomplete installs; never remove an environment or user data.
                Directory.Move(environment,
                               environment + ".incomplete-" + Guid.NewGuid().ToString("N"));
            }
            await Run(uv, home,
                      // An installed Python 3.12 is used when present; uv downloads one only otherwise.
                      new[] { "venv", "--no-project", "--python-preference", "system",
                              "--python", "3.12",
                              environment },
                      "Preparing Python for hosting (downloads Python 3.12 only if it is not installed)...", progress,
                      cancel, details);
        }
        await Run(uv, home,
                  new[] { "pip", "sync", "--python", python, "--only-binary", ":all:",
                          "--default-index", "https://pypi.org/simple", "--strict", requirements },
                  "Installing server dependencies...", progress, cancel, details);
        await HostedServer.CheckExternalPython(python, source, cancel);
        if (Updates.Sha(requirements) != hash)
            throw new IOException(
                "Server requirements changed during setup. Restart the launcher.");
        await File.WriteAllTextAsync(
            receipt + ".tmp",
            JsonSerializer.Serialize(
                new { format = 1, requirementsSha256 = hash, python, uvVersion = UvVersion }),
            cancel);
        File.Move(receipt + ".tmp", receipt, true);
        return python;
    }
    static async Task<FileStream> Lock(string folder, IProgress<string>? progress,
                                       CancellationToken cancel) {
        while (true) {
            cancel.ThrowIfCancellationRequested();
            try {
                return new FileStream(Path.Combine(folder, "setup.lock"), FileMode.OpenOrCreate,
                                      FileAccess.ReadWrite, FileShare.None);
            } catch (IOException error) when ((error.HResult & 0xffff) is 32 or 33) {
                progress?.Report("Waiting for another server setup to finish...");
                await Task.Delay(250, cancel);
            }
        }
    }
    static async Task<string> Tool(string home, IProgress<string>? progress,
                                   CancellationToken cancel, IProgress<ImportProgress>? details) {
        string folder = Path.Combine(home, "server-tools", "uv-" + UvVersion);
        Directory.CreateDirectory(folder);
        string executable = Path.Combine(folder, "uv.exe");
        if (File.Exists(executable) && Updates.Sha(executable) == ExeHash)
            return executable;
        string download = Path.Combine(folder, "download-" + Guid.NewGuid().ToString("N") + ".zip");
        string staged = executable + "." + Guid.NewGuid().ToString("N") + ".tmp";
        try {
            using var client = new HttpClient { Timeout = TimeSpan.FromMinutes(10) };
            client.DefaultRequestHeaders.UserAgent.ParseAdd("Outbreak-Launcher/" +
                                                            Updates.DefaultVersion);
            using var response =
                await client.GetAsync(UvUrl, HttpCompletionOption.ResponseHeadersRead, cancel);
            response.EnsureSuccessStatusCode();
            if (response.Content.Headers.ContentLength is long length && length != 15204998)
                throw new IOException("Unexpected server setup download size.");
            await using (var input = await response.Content.ReadAsStreamAsync(cancel)) await using (
                var output = new FileStream(download, FileMode.CreateNew, FileAccess.Write,
                                            FileShare.None, 65536, true)) {
                var buffer = new byte[65536];
                long received = 0, last = 0;
                int count;
                progress?.Report("Downloading server setup tool...");
                details?.Report(
                    new(0, 15204998, "Preparing hosting tools", "Downloading server tools"));
                while ((count = await input.ReadAsync(buffer, cancel)) != 0) {
                    received += count;
                    if (received > 15204998)
                        throw new IOException("Server setup download exceeds expected size.");
                    await output.WriteAsync(buffer.AsMemory(0, count), cancel);
                    if (received - last >= 524288) {
                        progress?.Report(
                            $"Downloading server setup tool... {received * 100 / 15204998}%");
                        details?.Report(new(received, 15204998, "Preparing hosting tools",
                                            "Downloading server tools"));
                        last = received;
                    }
                }
                if (received != 15204998)
                    throw new IOException("Server setup download was interrupted.");
            }
            details?.Report(
                new(15204998, 15204998, "Download complete", "Downloading server tools"));
            details?.Report(new(0, 0, "Verifying downloaded tools", "Preparing server tools"));
            if (Updates.Sha(download) != ZipHash)
                throw new IOException("Server setup download failed SHA-256 verification.");
            using (var zip = ZipFile.OpenRead(download)) {
                var entry = zip.GetEntry("uv.exe") ??
                            throw new IOException("Server setup tool is missing.");
                if (entry.Length > 100 * 1024 * 1024)
                    throw new IOException("Invalid server setup tool size.");
                entry.ExtractToFile(staged);
            }
            if (Updates.Sha(staged) != ExeHash)
                throw new IOException("Server setup executable failed SHA-256 verification.");
            File.Move(staged, executable, true);
            return executable;
        } finally {
            if (File.Exists(download))
                File.Delete(download);
            if (File.Exists(staged))
                File.Delete(staged);
        }
    }
    static async Task Run(string tool, string home, IEnumerable<string> arguments, string stage,
                          IProgress<string>? progress, CancellationToken cancel,
                          IProgress<ImportProgress>? details) {
        progress?.Report(stage);
        string phase = stage.StartsWith("Preparing Python", StringComparison.Ordinal)
                           ? "Preparing Python"
                           : "Installing server packages";
        details?.Report(new(0, 0, stage, phase));
        var start = new ProcessStartInfo(
            tool) { UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = home,
                    RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string key in start.Environment.Keys
                     .Where(key => key.StartsWith("UV_", StringComparison.OrdinalIgnoreCase) ||
                                   key.StartsWith("PIP_", StringComparison.OrdinalIgnoreCase) ||
                                   key.StartsWith("PYTHON", StringComparison.OrdinalIgnoreCase) ||
                                   key.Equals("VIRTUAL_ENV", StringComparison.OrdinalIgnoreCase))
                     .ToArray())
            start.Environment.Remove(key);
        start.Environment["UV_PYTHON_INSTALL_DIR"] = Path.Combine(home, "server-python-runtime");
        start.Environment["UV_CACHE_DIR"] = Path.Combine(home, "server-tools", "cache");
        start.Environment["UV_NO_PROGRESS"] = "1";
        start.Environment["NO_COLOR"] = "1";
        start.ArgumentList.Add("--no-config");
        foreach (string argument in arguments)
            start.ArgumentList.Add(argument);
        using var process =
            Process.Start(start) ?? throw new IOException("Could not start server setup.");
        async Task<string> Drain(StreamReader reader) {
            var text = new StringBuilder();
            while (await reader.ReadLineAsync() is {} line) {
                if (text.Length < 1024 * 1024)
                    text.AppendLine(line);
                if (!string.IsNullOrWhiteSpace(line))
                    details?.Report(new(0, 0, line[..Math.Min(line.Length, 180)], phase));
            }
            return text.ToString();
        }
        Task<string> output = Drain(process.StandardOutput), errors = Drain(process.StandardError);
        using var limit = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        limit.CancelAfter(TimeSpan.FromMinutes(10));
        try {
            await process.WaitForExitAsync(limit.Token);
        } catch (OperationCanceledException) {
            if (!process.HasExited)
                process.Kill(entireProcessTree: true);
            await process.WaitForExitAsync();
            cancel.ThrowIfCancellationRequested();
            throw new IOException(
                "Server setup timed out. Check your Internet connection and retry.");
        }
        string logText = (await output) + (await errors);
        await File.AppendAllTextAsync(Path.Combine(home, "server-python", "setup.log"),
                                      stage + "\n" + logText + "\n", cancel);
        if (process.ExitCode != 0)
            throw new IOException(
                "Server setup failed. See server-python/setup.log in the launcher data folder.\n" +
                logText[..Math.Min(logText.Length, 1200)]);
        details?.Report(new(1, 1, phase + " complete", phase));
    }
}
