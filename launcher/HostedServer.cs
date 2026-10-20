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
                            string? componentRoot = null) {
        if (Running)
            return;
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
        string data = Path.Combine(stateHome ?? Settings.Home, "hosted-server");
        Directory.CreateDirectory(data);
        try {
            lease = new FileStream(Path.Combine(data, "server.lock"), FileMode.OpenOrCreate,
                                   FileAccess.ReadWrite, FileShare.None);
            CheckPorts(portOffset);
            var (python, source) = await Locate(root, cancel, componentRoot);
            foreach (var args in new[] { new[] { "app", "capcom" },
                                         new[] { "web", "--web-plugin", "outbreak" },
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
                env["PYTHONPATH"] = source + Path.PathSeparator + Path.Combine(source, "vendor");
                env["PYTHONNOUSERSITE"] = "1";
                env["PYTHONDONTWRITEBYTECODE"] = "1";
                env["OPENSNAP_LOG_LEVEL"] = "info";
                env["OPENSNAP_ENV_FILE"] = Path.Combine(data, "launcher-empty.env");
                env["OPENSNAP_ENV_DIST_FILE"] = Path.Combine(data, "launcher-empty.dist");
                env["OPENSNAP_DATA_DIR"] = data;
                env["OPENSNAP_STORAGE_BACKEND"] = "sqlite";
                env["OPENSNAP_SQLITE_PATH"] = Path.Combine(data, "opensnap.db");
                env["OPENSNAP_BOOTSTRAP_HOST"] = "0.0.0.0";
                env["OPENSNAP_GAME_HOST"] = "0.0.0.0";
                env["OPENSNAP_CAPCOM_APP_HOST"] = "0.0.0.0";
                env["OPENSNAP_WEB_HOST"] = "0.0.0.0";
                env["OPENSNAP_WEB_HTTPS_HOST"] = "";
                env["OPENSNAP_WEB_HTTPS_CERTFILE"] = "";
                env["OPENSNAP_WEB_HTTPS_KEYFILE"] = "";
                env["OPENSNAP_BOOTSTRAP_ADVERTISE_HOST"] = normalized;
                env["OPENSNAP_GAME_ADVERTISE_HOST"] = normalized;
                env["OPENSNAP_BOOTSTRAP_PORT"] = (9090 + portOffset).ToString();
                env["OPENSNAP_GAME_PORT"] = (9091 + portOffset).ToString();
                env["OPENSNAP_CAPCOM_APP_PORT"] = (10127 + portOffset).ToString();
                env["OPENSNAP_WEB_PORT"] = (80 + portOffset).ToString();
                env["OPENSNAP_BOOTSTRAP_GAMES"] = "outbreak";
                env["OPENSNAP_GAME_PLUGIN"] = "outbreak";
                env["OPENSNAP_WEB_GAME_PLUGIN"] = "outbreak";
                env["OPENSNAP_GAME_SERVER_MAP"] = JsonSerializer.Serialize(
                    new { outbreak = new { host = normalized, port = 9091 + portOffset } });
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
                if (processes.Any(p => p.HasExited))
                    throw new IOException("A server service stopped. See the hosted-server logs.");
                var ip = IPGlobalProperties.GetIPGlobalProperties();
                int[] tcp = ip.GetActiveTcpListeners().Select(e => e.Port).ToArray();
                int[] udp = ip.GetActiveUdpListeners().Select(e => e.Port).ToArray();
                if (tcp.Contains(80 + portOffset) && tcp.Contains(10127 + portOffset) &&
                    udp.Contains(9090 + portOffset) && udp.Contains(9091 + portOffset)) {
                    Address = normalized;
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
        var ip = IPGlobalProperties.GetIPGlobalProperties();
        if (ip.GetActiveTcpListeners().Any(e => e.Port == 80 + portOffset ||
                                                e.Port == 10127 + portOffset) ||
            ip.GetActiveUdpListeners().Any(e => e.Port == 9090 + portOffset ||
                                                e.Port == 9091 + portOffset))
            throw new IOException(
                "Server ports are already in use. Stop the other server, or join it with Host server off.");
    }
    static async Task<(string, string)> Locate(string root, CancellationToken cancel,
                                               string? componentRoot) {
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
            if (manifest.RootElement.GetProperty("format").GetInt32() != 1)
                throw new IOException("Unsupported server package.");
            foreach (var item in manifest.RootElement.GetProperty("files").EnumerateArray()) {
                using var input = File.OpenRead(Resolve(item.GetProperty("path").GetString()!));
                string hash = Convert.ToHexString(await SHA256.HashDataAsync(input, cancel));
                if (!hash.Equals(item.GetProperty("sha256").GetString(),
                                 StringComparison.OrdinalIgnoreCase))
                    throw new IOException(
                        "Server package verification failed. Extract a complete release.");
            }
            return (Resolve(manifest.RootElement.GetProperty("python").GetString()!),
                    Resolve(manifest.RootElement.GetProperty("source").GetString()!));
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
