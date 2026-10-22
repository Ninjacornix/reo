using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Net.NetworkInformation;
using System.Net.Sockets;

namespace Outbreak.Launcher;

// Helpers that make hosting reachable for friends: which address to share, which ports must be
// open, optional router port forwarding (UPnP) and an optional Windows Firewall rule.
internal static class HostNetworking {
    // The game itself connects to login 9090 and app server 10127, so those are fixed. The login
    // server tells games which game-server port to use, and sign-up is only used by launchers
    // (joining launchers learn it through discovery), so both can be changed by the host.
    // Sign-up avoids port 80, which many providers block for home users.
    internal const int SignupPort = 10128, GamePort = 9091, LoginPort = 9090, AppPort = 10127;
    internal sealed record PortChoice(int Signup, int Game);
    internal static PortChoice Current { get; set; } = new(SignupPort, GamePort);
    internal sealed record ServerPort(int Number, string Protocol, string Use);
    internal static ServerPort[] Ports => new ServerPort[] {
        new(Current.Signup, "TCP", "player sign-up"), new(AppPort, "TCP", "game app server (fixed)"),
        new(LoginPort, "UDP", "login (fixed)"), new(Current.Game, "UDP", "game server"),
        new(LanDiscovery.Port, "UDP", "finding your game and sharing randomizer settings") };
    internal static string? PortError(int signup, int game) {
        int[] reserved = { LoginPort, AppPort, LanDiscovery.Port };
        if (signup is < 1024 or > 65535 || game is < 1024 or > 65535)
            return "Ports must be numbers from 1024 to 65535.";
        if (reserved.Contains(signup) || reserved.Contains(game))
            return $"Ports {LoginPort}, {AppPort} and {LanDiscovery.Port} are already used by the game.";
        return null;
    }

    // Which programs listen on the given ports, from netstat (no administrator rights needed).
    internal static List<string> PortOwners(IEnumerable<(int Port, string Protocol)> wanted) {
        var result = new List<string>();
        try {
            var start = new ProcessStartInfo("netstat", "-ano") {
                UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true };
            using var process = Process.Start(start)!;
            string output = process.StandardOutput.ReadToEnd();
            process.WaitForExit(5000);
            var targets = wanted.ToList();
            foreach (string line in output.Split('\n')) {
                string[] parts = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length < 4 || parts[0] is not("TCP" or "UDP") ||
                    (parts[0] == "TCP" && (parts.Length < 5 || parts[3] != "LISTENING")))
                    continue;
                int colon = parts[1].LastIndexOf(':');
                if (colon < 0 || !int.TryParse(parts[1][(colon + 1)..], out int port) ||
                    !int.TryParse(parts[^1].Trim(), out int pid) || !targets.Contains((port, parts[0])))
                    continue;
                string name;
                try {
                    using var owner = Process.GetProcessById(pid);
                    name = owner.ProcessName;
                } catch (ArgumentException) {
                    name = "another program";
                }
                string entry = $"{port} {parts[0]} is used by {name} (process {pid})";
                if (!result.Contains(entry))
                    result.Add(entry);
            }
        } catch (Exception error) when (error is Win32Exception or InvalidOperationException) {
        }
        return result;
    }
    internal static string PortList =>
        string.Join("\n", Ports.Select(p => $"{p.Number} {p.Protocol} — {p.Use}"));

    internal enum AddressKind { Home, Vpn, Public }
    internal sealed record LocalAddress(string Address, string Adapter, AddressKind Kind) {
        public string Label => Kind switch {
            AddressKind.Home => $"{Address} (home network: {Adapter})",
            AddressKind.Vpn => $"{Address} (VPN: {Adapter})",
            _ => $"{Address} (internet: {Adapter})"
        };
    }

    internal static AddressKind Classify(IPAddress address, string adapter = "") {
        byte[] b = address.GetAddressBytes();
        if (b[0] == 10 || (b[0] == 172 && b[1] >= 16 && b[1] <= 31) || (b[0] == 192 && b[1] == 168))
            return AddressKind.Home;
        // 100.64/10 is used by Tailscale and by carrier-grade NAT; 25/8 by Hamachi.
        if ((b[0] == 100 && b[1] >= 64 && b[1] <= 127) || b[0] == 25 ||
            adapter.Contains("Tailscale", StringComparison.OrdinalIgnoreCase) ||
            adapter.Contains("ZeroTier", StringComparison.OrdinalIgnoreCase) ||
            adapter.Contains("Hamachi", StringComparison.OrdinalIgnoreCase) ||
            adapter.Contains("Radmin", StringComparison.OrdinalIgnoreCase))
            return AddressKind.Vpn;
        return AddressKind.Public;
    }

    internal static bool IsPublic(IPAddress address) {
        byte[] b = address.GetAddressBytes();
        return address.AddressFamily == AddressFamily.InterNetwork && !IPAddress.IsLoopback(address) &&
               Classify(address) == AddressKind.Public && b[0] != 0 && b[0] < 224 &&
               !(b[0] == 169 && b[1] == 254);
    }

    // Host-only adapters of virtual machines/WSL/Docker are unreachable for friends.
    internal static bool IsVirtualAdapter(string text) =>
        new[] { "vEthernet", "Hyper-V", "WSL", "VirtualBox", "VMware", "Docker", "Host-Only" }
            .Any(t => text.Contains(t, StringComparison.OrdinalIgnoreCase));
    static bool IsVirtual(NetworkInterface adapter) =>
        IsVirtualAdapter(adapter.Name + " " + adapter.Description);

    // Every usable IPv4 address of this PC, home network first.
    internal static List<LocalAddress> LocalAddresses() {
        var result = new List<LocalAddress>();
        foreach (var adapter in NetworkInterface.GetAllNetworkInterfaces()) {
            if (adapter.OperationalStatus != OperationalStatus.Up ||
                adapter.NetworkInterfaceType == NetworkInterfaceType.Loopback || IsVirtual(adapter))
                continue;
            foreach (var unicast in adapter.GetIPProperties().UnicastAddresses) {
                var address = unicast.Address;
                if (address.AddressFamily != AddressFamily.InterNetwork || IPAddress.IsLoopback(address) ||
                    address.ToString().StartsWith("169.254.", StringComparison.Ordinal))
                    continue;
                result.Add(new(address.ToString(), adapter.Name, Classify(address, adapter.Description + " " + adapter.Name)));
            }
        }
        return result.OrderBy(a => a.Kind).ThenBy(a => a.Adapter).ToList();
    }

    // Only on request: asks api.ipify.org (no account, no data sent) which address the internet sees.
    internal static async Task<string> PublicAddress(CancellationToken cancel) {
        using var client = new HttpClient { Timeout = TimeSpan.FromSeconds(8) };
        string text = (await client.GetStringAsync("https://api.ipify.org", cancel)).Trim();
        if (!IPAddress.TryParse(text, out var address) || address.AddressFamily != AddressFamily.InterNetwork)
            throw new IOException("The address service returned an unexpected answer.");
        return address.ToString();
    }

    // ---- Router port forwarding through Windows' built-in UPnP client (HNetCfg.NATUPnP). ----
    internal sealed record UpnpResult(bool Opened, string Message, string? RouterAddress);
    static readonly string MappingDescription = "RE Outbreak Recomp " + Guid.NewGuid().ToString("N");

    static T OnMta<T>(Func<T> work, TimeSpan limit) {
        T value = default!;
        Exception? failure = null;
        var thread = new Thread(() => {
            try { value = work(); } catch (Exception error) { failure = error; }
        }) { IsBackground = true };
        thread.SetApartmentState(ApartmentState.MTA);
        thread.Start();
        if (!thread.Join(limit))
            throw new TimeoutException("The router did not answer.");
        if (failure != null)
            throw failure;
        return value;
    }

    static dynamic? Mappings() {
        var type = Type.GetTypeFromProgID("HNetCfg.NATUPnP");
        if (type == null)
            return null;
        dynamic nat = Activator.CreateInstance(type)!;
        return nat.StaticPortMappingCollection;
    }

    internal static Task<UpnpResult> OpenPorts(string lanAddress) => Task.Run(() => {
        try {
            return OnMta(() => {
                dynamic? maps = Mappings();
                if (maps == null)
                    return new UpnpResult(false,
                        "Your router did not offer automatic port forwarding (UPnP is off or unsupported). " +
                        "Forward the ports in your router settings instead.", null);
                string? router = null;
                foreach (var port in Ports) {
                    foreach (dynamic existing in maps)
                        if ((int)existing.ExternalPort == port.Number &&
                            string.Equals((string)existing.Protocol, port.Protocol,
                                          StringComparison.OrdinalIgnoreCase))
                            throw new IOException($"Router port {port.Number} {port.Protocol} already has a mapping.");
                    dynamic mapping = maps.Add(port.Number, port.Protocol, port.Number, lanAddress, true,
                                               MappingDescription);
                    try { router ??= (string)mapping.ExternalIPAddress; } catch { }
                }
                return new UpnpResult(true, "Router ports opened automatically.", router);
            }, TimeSpan.FromSeconds(20));
        } catch (Exception error) {
            return new UpnpResult(false,
                "Automatic port forwarding failed (" + error.Message.TrimEnd('.') + "). " +
                "Forward the ports in your router settings instead.", null);
        }
    });

    internal static Task ClosePorts() => Task.Run(() => {
        try {
            OnMta(() => {
                dynamic? maps = Mappings();
                if (maps != null) {
                    var owned = new List<(int Port, string Protocol)>();
                    foreach (dynamic mapping in maps)
                        if (string.Equals((string)mapping.Description, MappingDescription,
                                          StringComparison.Ordinal))
                            owned.Add(((int)mapping.ExternalPort, (string)mapping.Protocol));
                    foreach (var mapping in owned)
                        try { maps.Remove(mapping.Port, mapping.Protocol); } catch { }
                }
                return true;
            }, TimeSpan.FromSeconds(10));
        } catch {
        }
    });

    // A router that reports a non-public WAN address is itself behind another NAT (often the ISP's
    // carrier-grade NAT): forwarding on this router cannot make the server reachable from the internet.
    internal static bool BehindAnotherNat(string? routerAddress) =>
        routerAddress != null && IPAddress.TryParse(routerAddress, out var a) && !IsPublic(a);

    // ---- Windows Firewall ----
    const string RuleTcp = "RE Outbreak Recomp server (TCP)";
    const string RuleUdp = "RE Outbreak Recomp server (UDP)";

    // Present only when the rules cover the currently configured ports.
    internal static bool FirewallRulesPresent() =>
        RuleExists(RuleTcp, Ports.Where(p => p.Protocol == "TCP").Select(p => p.Number)) &&
        RuleExists(RuleUdp, Ports.Where(p => p.Protocol == "UDP").Select(p => p.Number));

    static bool RuleExists(string name, IEnumerable<int> ports) {
        try {
            var start = new ProcessStartInfo("netsh", $"advfirewall firewall show rule name=\"{name}\"") {
                UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true,
                RedirectStandardError = true };
            using var process = Process.Start(start)!;
            string output = process.StandardOutput.ReadToEnd();
            process.WaitForExit(5000);
            // Port numbers are not localized, unlike the field labels around them.
            return process.ExitCode == 0 &&
                   ports.All(port => System.Text.RegularExpressions.Regex.IsMatch(
                                 output, $@"(?<![0-9]){port}(?![0-9])"));
        } catch {
            return false;
        }
    }

    // Adds inbound allow rules for exactly the server ports. Windows asks for administrator approval.
    internal static Task<bool> AddFirewallRules() => Task.Run(() => {
        string tcp = string.Join(",", Ports.Where(p => p.Protocol == "TCP").Select(p => p.Number));
        string udp = string.Join(",", Ports.Where(p => p.Protocol == "UDP").Select(p => p.Number));
        string script =
            $"netsh advfirewall firewall delete rule name=\"{RuleTcp}\" >nul 2>&1 & " +
            $"netsh advfirewall firewall delete rule name=\"{RuleUdp}\" >nul 2>&1 & " +
            $"netsh advfirewall firewall add rule name=\"{RuleTcp}\" dir=in action=allow protocol=TCP localport={tcp} && " +
            $"netsh advfirewall firewall add rule name=\"{RuleUdp}\" dir=in action=allow protocol=UDP localport={udp}";
        var start = new ProcessStartInfo("cmd.exe", "/c " + script) {
            UseShellExecute = true, Verb = "runas", WindowStyle = ProcessWindowStyle.Hidden };
        try {
            using var process = Process.Start(start)!;
            process.WaitForExit(30000);
        } catch (Win32Exception error) when (error.NativeErrorCode == 1223) {
            return false; // the user declined the administrator prompt
        }
        return FirewallRulesPresent();
    });
}
