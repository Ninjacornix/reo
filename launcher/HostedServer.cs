using System.Diagnostics;
using System.IO;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal sealed class HostedServer : IDisposable {
    readonly List<Process> processes = new();
    readonly List<Task> pumps = new();
    FileStream? lease;
    CancellationTokenSource? startup;
    public bool Running => processes.Count == 4 && processes.All(p => !p.HasExited);
    public string Address { get; private set; } = "";
    public string GameId { get; private set; } = "file1";
    internal static string StateFolder(string home, string game) =>
        Path.Combine(home, game == "file1" ? "hosted-server" : game == "file2" ? "hosted-server-file2"
            : throw new ArgumentException("Unknown game edition.", nameof(game)));
    internal static Dictionary<string, string> EditionEnvironment(string game, string host, int port) {
        string plugin = OnlineOptions.ServerPlugin(game);
        string bind = IPAddress.IsLoopback(IPAddress.Parse(host)) ? host : "0.0.0.0";
        return new() {
            ["OPENSNAP_BOOTSTRAP_HOST"] = bind,
            ["OPENSNAP_GAME_HOST"] = bind,
            ["OPENSNAP_CAPCOM_APP_HOST"] = bind,
            ["OPENSNAP_WEB_HOST"] = bind,
            ["OPENSNAP_BOOTSTRAP_GAMES"] = plugin,
            ["OPENSNAP_GAME_PLUGIN"] = plugin,
            ["OPENSNAP_WEB_GAME_PLUGIN"] = plugin,
            ["OPENSNAP_GAME_SERVER_MAP"] = JsonSerializer.Serialize(
                new Dictionary<string, object> { [plugin] = new { host, port } })
        };
    }
    public static string SuggestedAddress() =>
        NetworkInterface.GetAllNetworkInterfaces()
            .Where(n => n.OperationalStatus == OperationalStatus.Up &&
                        n.NetworkInterfaceType != NetworkInterfaceType.Loopback)
            .SelectMany(n => n.GetIPProperties().UnicastAddresses)
            .Select(a => a.Address)
            .FirstOrDefault(a => a.AddressFamily == AddressFamily.InterNetwork &&
                                 !IPAddress.IsLoopback(a) &&
                                 !a.ToString().StartsWith("169.254.", StringComparison.Ordinal))
            ?.ToString() ??
        "127.0.0.1";

    public async Task Start(string root, string address, CancellationToken cancel = default,
                            string? stateHome = null, int portOffset = 0,
                            string? componentRoot = null, IProgress<string>? progress = null,
                            IProgress<ImportProgress>? setupProgress = null, string game = "file1") {
        string plugin = OnlineOptions.ServerPlugin(game);
        if (Running) {
            if (GameId != game)
                throw new IOException("Stop the hosted game before switching editions.");
            return;
        }
        if (processes.Count > 0)
            Dispose();
        startup?.Dispose();
        startup = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        cancel = startup.Token;
        if (!OnlineOptions.TryHost(address, out string normalized))
            throw new IOException(
                "Choose the LAN, VPN or public IPv4 address your friends will use.");
        if (portOffset < 0 || portOffset > 55000)
            throw new ArgumentOutOfRangeException(nameof(portOffset));
        string data = StateFolder(stateHome ?? Settings.Home, game);
        Directory.CreateDirectory(data);
        try {
            lease = new FileStream(Path.Combine(data, "server.lock"), FileMode.OpenOrCreate,
                                   FileAccess.ReadWrite, FileShare.None);
            var ports = HostNetworking.Current;
            CheckPorts(portOffset);
            var (python, source) = await Locate(
                root, cancel, componentRoot, stateHome ?? Settings.Home, progress, setupProgress);
            progress?.Report("Starting server services...");
            setupProgress?.Report(new(0, 0, "Starting server services", "Starting server"));
            foreach (var args in new[] { new[] { "app", "capcom" },
                                         new[] { "web", "--web-plugin", plugin },
                                         new[] { "game" }, new[] { "bootstrap" } }) {
                cancel.ThrowIfCancellationRequested();
                var start = new ProcessStartInfo(python) {
                    UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = data,
                    RedirectStandardOutput = true, RedirectStandardError = true
                };
                start.ArgumentList.Add("-u");
                start.ArgumentList.Add(Path.Combine(source, "run.py"));
                foreach (string arg in args)
                    start.ArgumentList.Add(arg);
                foreach (string key in start.Environment.Keys
                             .Where(k => k.StartsWith("OPENSNAP_",
                                                      StringComparison.OrdinalIgnoreCase) ||
                                         k.StartsWith("PYTHON", StringComparison.OrdinalIgnoreCase))
                             .ToArray())
                    start.Environment.Remove(key);
                var env = start.Environment;
                Storage.ProcessEnvironment(start, stateHome);
                env["PYTHONPATH"] = source;
                if (Directory.Exists(Path.Combine(source, "vendor")))
                    env["PYTHONPATH"] += Path.PathSeparator + Path.Combine(source, "vendor");
                env["PYTHONNOUSERSITE"] = "1";
                env["PYTHONDONTWRITEBYTECODE"] = "1";
                env["OPENSNAP_LOG_LEVEL"] = "info";
                env["OPENSNAP_ENV_FILE"] = Path.Combine(data, "launcher-empty.env");
                env["OPENSNAP_ENV_DIST_FILE"] = Path.Combine(data, "launcher-empty.dist");
                env["OPENSNAP_DATA_DIR"] = data;
                env["OPENSNAP_STORAGE_BACKEND"] = "sqlite";
                env["OPENSNAP_SQLITE_PATH"] = Path.Combine(data, "opensnap.db");
                env["OPENSNAP_WEB_HTTPS_HOST"] = "";
                env["OPENSNAP_WEB_HTTPS_CERTFILE"] = "";
                env["OPENSNAP_WEB_HTTPS_KEYFILE"] = "";
                env["OPENSNAP_BOOTSTRAP_ADVERTISE_HOST"] = normalized;
                env["OPENSNAP_GAME_ADVERTISE_HOST"] = normalized;
                env["OPENSNAP_BOOTSTRAP_PORT"] = (9090 + portOffset).ToString();
                env["OPENSNAP_GAME_PORT"] = (ports.Game + portOffset).ToString();
                env["OPENSNAP_CAPCOM_APP_PORT"] = (10127 + portOffset).ToString();
                env["OPENSNAP_WEB_PORT"] = (ports.Signup + portOffset).ToString();
                foreach (var pair in EditionEnvironment(game, normalized, ports.Game + portOffset))
                    env[pair.Key] = pair.Value;
                var process =
                    Process.Start(start) ?? throw new IOException("Could not start the server.");
                processes.Add(process);
                string name = args[0];
                pumps.Add(GameSession.Pump(process.StandardOutput,
                                           new StreamWriter(Path.Combine(
                                               data, name + "-stdout.log")) { AutoFlush = true }));
                pumps.Add(GameSession.Pump(process.StandardError,
                                           new StreamWriter(Path.Combine(
                                               data, name + "-stderr.log")) { AutoFlush = true }));
            }
            var clock = Stopwatch.StartNew();
            while (clock.Elapsed < TimeSpan.FromSeconds(20)) {
                cancel.ThrowIfCancellationRequested();
                if (processes.Any(p => p.HasExited)) {
                    int stopped = processes.FindIndex(p => p.HasExited);
                    string name = new[] { "app", "web", "game", "bootstrap" }[stopped];
                    await Task.WhenAny(Task.WhenAll(pumps), Task.Delay(1000, cancel));
                    string tail = "";
                    try {
                        var lines = File.ReadAllLines(Path.Combine(data, name + "-stderr.log"))
                                        .Where(l => l.Trim().Length > 0)
                                        .TakeLast(3);
                        tail = string.Join(" | ", lines);
                    } catch (IOException) {
                    }
                    throw new IOException($"The {name} service stopped" +
                                          (tail.Length > 0 ? ": " + tail[..Math.Min(tail.Length, 600)]
                                                           : ". See the hosted-server logs."));
                }
                var ip = IPGlobalProperties.GetIPGlobalProperties();
                int[] tcp = ip.GetActiveTcpListeners().Select(e => e.Port).ToArray();
                int[] udp = ip.GetActiveUdpListeners().Select(e => e.Port).ToArray();
                if (tcp.Contains(ports.Signup + portOffset) && tcp.Contains(10127 + portOffset) &&
                    udp.Contains(9090 + portOffset) && udp.Contains(ports.Game + portOffset)) {
                    Address = normalized;
                    GameId = game;
                    return;
                }
                await Task.Delay(100, cancel);
            }
            throw new IOException(
                "The server did not become ready. Check its logs and port availability.");
        } catch {
            Dispose();
            throw;
        }
    }
    internal static void CheckPorts(int portOffset = 0) {
        var wanted = HostNetworking.Ports.Where(p => p.Number != LanDiscovery.Port)
                         .Select(p => (Port: p.Number + portOffset, p.Protocol))
                         .ToList();
        var ip = IPGlobalProperties.GetIPGlobalProperties();
        var busy = wanted.Where(w => w.Protocol == "TCP"
                                         ? ip.GetActiveTcpListeners().Any(e => e.Port == w.Port)
                                         : ip.GetActiveUdpListeners().Any(e => e.Port == w.Port))
                       .ToList();
        if (busy.Count == 0)
            return;
        var owners = HostNetworking.PortOwners(busy);
        string list = owners.Count > 0 ? string.Join("; ", owners)
                                       : string.Join(", ", busy.Select(b => $"{b.Port} {b.Protocol}"));
        bool fixedBusy = busy.Any(b => b.Port - portOffset is HostNetworking.LoginPort or
                                                              HostNetworking.AppPort);
        throw new IOException(
            "Ports already in use: " + list + ". " +
            (fixedBusy ? "Ports 9090 and 10127 are built into the game, so close that program first."
                       : "Close that program, or choose other ports under Ports."));
    }
    static async Task<(string, string)> Locate(string root, CancellationToken cancel,
                                               string? componentRoot, string home,
                                               IProgress<string>? progress,
                                               IProgress<ImportProgress>? setupProgress) {
        string payload = componentRoot ?? Path.Combine(root, "network-server");
        if (File.Exists(Path.Combine(payload, "server-manifest.json"))) {
            using var manifest = JsonDocument.Parse(
                await File.ReadAllTextAsync(Path.Combine(payload, "server-manifest.json"), cancel));
            string Resolve(string relative) {
                string file = Path.GetFullPath(Path.Combine(payload, relative));
                if (!file.StartsWith(Path.GetFullPath(payload) + Path.DirectorySeparatorChar,
                                     StringComparison.OrdinalIgnoreCase))
                    throw new IOException("Invalid server package path.");
                return file;
            }
            int format = manifest.RootElement.GetProperty("format").GetInt32();
            if (format is not(1 or 2))
                throw new IOException("Unsupported server package.");
            foreach (var item in manifest.RootElement.GetProperty("files").EnumerateArray()) {
                using var input = File.OpenRead(Resolve(item.GetProperty("path").GetString()!));
                string hash = Convert.ToHexString(await SHA256.HashDataAsync(input, cancel));
                if (!hash.Equals(item.GetProperty("sha256").GetString(),
                                 StringComparison.OrdinalIgnoreCase))
                    throw new IOException(
                        "Server package verification failed. Extract a complete release.");
            }
            string source = Resolve(manifest.RootElement.GetProperty("source").GetString()!);
            if (format == 2) {
                if (manifest.RootElement.GetProperty("runtime").GetString() != "external-python")
                    throw new IOException("Unsupported server Python configuration.");
                string? python = Environment.GetEnvironmentVariable("REO_SERVER_PYTHON");
                if (string.IsNullOrWhiteSpace(python))
                    python = Environment.GetEnvironmentVariable("REO_SERVER_PYTHON",
                                                                EnvironmentVariableTarget.User);
                if (string.IsNullOrWhiteSpace(python))
                    python = Path.Combine(home, "server-python", "Scripts", "python.exe");
                python = Path.GetFullPath(Environment.ExpandEnvironmentVariables(python));
                if (File.Exists(python)) {
                    try {
                        await CheckExternalPython(python, source, cancel);
                        return (python, source);
                    } catch (IOException) {
                        progress?.Report("Preparing a private server environment...");
                    }
                }
                string requirements =
                    Resolve(manifest.RootElement.GetProperty("requirements").GetString()!);
                return (await ServerPythonSetup.Ensure(home, source, requirements, progress, cancel,
                                                       setupProgress),
                        source);
            }
            return (Resolve(manifest.RootElement.GetProperty("python").GetString()!), source);
        }
        if (!AppLayout.Packaged(root)) {
            string source = Path.Combine(root, "build-ninja/coop-research/openSNAP");
            string python = Path.Combine(source, ".venv/Scripts/python.exe");
            if (File.Exists(python) && File.Exists(Path.Combine(source, "run.py")))
                return (python, source);
        }
        throw new IOException(
            "Hosting files are missing. Extract the complete release, including its network-server folder.");
    }
    internal static async Task CheckExternalPython(string python, string source,
                                                   CancellationToken cancel) {
        var start = new ProcessStartInfo(
            python) { UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = source,
                      RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string key in start.Environment.Keys
                     .Where(k => k.StartsWith("PYTHON", StringComparison.OrdinalIgnoreCase) ||
                                 k.StartsWith("OPENSNAP_", StringComparison.OrdinalIgnoreCase))
                     .ToArray())
            start.Environment.Remove(key);
        start.Environment["PYTHONPATH"] = source;
        start.Environment["PYTHONNOUSERSITE"] = "1";
        start.Environment["PYTHONDONTWRITEBYTECODE"] = "1";
        start.ArgumentList.Add("-B");
        start.ArgumentList.Add("-c");
        start.ArgumentList.Add(
            "import sys; assert sys.version_info[:2] == (3,12), 'Python 3.12 is required'; import sqlite3, ssl, flask, cryptography, dnslib; from opensnap_web.signup import SignupService");
        using var process =
            Process.Start(start) ?? throw new IOException("Could not check server Python.");
        var output = process.StandardOutput.ReadToEndAsync();
        var errors = process.StandardError.ReadToEndAsync();
        using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        timeout.CancelAfter(TimeSpan.FromSeconds(15));
        try {
            await process.WaitForExitAsync(timeout.Token);
        } catch (OperationCanceledException) {
            if (!process.HasExited)
                process.Kill(entireProcessTree: true);
            cancel.ThrowIfCancellationRequested();
            throw new IOException("Server Python check timed out. See network-server/README.md.");
        }
        await output;
        string details = (await errors).Trim();
        if (process.ExitCode != 0)
            throw new IOException(
                "Server Python dependencies are missing or incompatible. Install network-server/requirements.txt in the environment described in network-server/README.md.\n" +
                details[..Math.Min(details.Length, 1200)]);
    }
    public void Dispose() {
        startup?.Cancel();
        foreach (var process in processes.AsEnumerable().Reverse()) {
            try {
                if (!process.HasExited) {
                    process.Kill(entireProcessTree: true);
                    process.WaitForExit(2000);
                }
            } catch (InvalidOperationException) {
            } catch (System.ComponentModel.Win32Exception) when (process.HasExited) {
            } finally {
                process.Dispose();
            }
        }
        processes.Clear();
        try {
            Task.WaitAll(pumps.ToArray(), 2000);
        } catch (AggregateException) {
        }
        pumps.Clear();
        lease?.Dispose();
        lease = null;
        Address = "";
    }
}
