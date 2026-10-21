using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Finds games hosted by other launchers on the same network. A joining launcher broadcasts a fixed
// query; hosting launchers answer with their player name and the address their server advertises.
// The same query sent directly to a host's address tells a joiner whether the host's room exists.
// No central service is involved, and nothing is sent unless the player hosts or searches.
public static class LanDiscovery {
    public const int Port = 10129;
    const int MaxPacket = 512;
    static readonly byte[] Query = Encoding.ASCII.GetBytes("REO-LAN?1");
    static readonly byte[] ReplyPrefix = Encoding.ASCII.GetBytes("REO-LAN!1");

    public sealed record Game(string Name, string Address, string Version, bool RoomReady,
                              int Signup = HostNetworking.SignupPort);

    internal static byte[] Encode(Game game) {
        byte[] body = JsonSerializer.SerializeToUtf8Bytes(
            new { name = game.Name, address = game.Address, version = game.Version,
                  room = game.RoomReady, signup = game.Signup });
        return ReplyPrefix.Concat(body).ToArray();
    }

    // Untrusted network input: bounded size, exact prefix, validated fields.
    internal static Game? Decode(ReadOnlySpan<byte> packet) {
        if (packet.Length > MaxPacket || !packet.StartsWith(ReplyPrefix))
            return null;
        try {
            using var json = JsonDocument.Parse(packet[ReplyPrefix.Length..].ToArray(),
                                                new JsonDocumentOptions { MaxDepth = 2 });
            var root = json.RootElement;
            string name = root.GetProperty("name").GetString() ?? "";
            string version = root.GetProperty("version").GetString() ?? "";
            int signup = root.GetProperty("signup").GetInt32();
            if (!OnlineOptions.TryHost(root.GetProperty("address").GetString(), out string address) ||
                !OnlineOptions.ValidUsername(name) || version.Length > 20 ||
                version.Any(c => c is < ' ' or > '~') || signup is < 1024 or > 65535)
                return null;
            return new(name, address, version, root.GetProperty("room").GetBoolean(), signup);
        } catch (Exception error) when (error is JsonException or InvalidOperationException or
                                            KeyNotFoundException or ArgumentException or
                                            FormatException) {
            return null;
        }
    }

    // Answers queries while this launcher hosts. Failing to bind only disables discovery.
    public sealed class Responder : IDisposable {
        readonly UdpClient socket;
        readonly CancellationTokenSource stop = new();
        readonly Func<Game> describe;
        public Responder(Func<Game> describe) {
            this.describe = describe;
            socket = new UdpClient(new IPEndPoint(IPAddress.Any, Port));
            _ = Serve();
        }
        async Task Serve() {
            long windowStart = Environment.TickCount64;
            int answered = 0;
            while (!stop.IsCancellationRequested) {
                UdpReceiveResult request;
                try {
                    request = await socket.ReceiveAsync(stop.Token).ConfigureAwait(false);
                } catch (Exception error) when (error is OperationCanceledException or
                                                    ObjectDisposedException or SocketException) {
                    if (stop.IsCancellationRequested)
                        return;
                    continue;
                }
                if (!request.Buffer.AsSpan().SequenceEqual(Query))
                    continue;
                // Bound the work a flood of queries can cause.
                long now = Environment.TickCount64;
                if (now - windowStart > 1000) {
                    windowStart = now;
                    answered = 0;
                }
                if (++answered > 20)
                    continue;
                try {
                    byte[] reply = Encode(describe());
                    await socket.SendAsync(reply, request.RemoteEndPoint, stop.Token).ConfigureAwait(false);
                } catch (Exception error) when (error is OperationCanceledException or
                                                    ObjectDisposedException or SocketException) {
                }
            }
        }
        public void Dispose() {
            stop.Cancel();
            socket.Dispose();
        }
    }

    static IEnumerable<IPAddress> BroadcastAddresses() {
        yield return IPAddress.Broadcast;
        foreach (var adapter in NetworkInterface.GetAllNetworkInterfaces()) {
            if (adapter.OperationalStatus != OperationalStatus.Up ||
                adapter.NetworkInterfaceType == NetworkInterfaceType.Loopback)
                continue;
            foreach (var unicast in adapter.GetIPProperties().UnicastAddresses) {
                if (unicast.Address.AddressFamily != AddressFamily.InterNetwork ||
                    unicast.IPv4Mask == null)
                    continue;
                byte[] address = unicast.Address.GetAddressBytes(),
                       mask = unicast.IPv4Mask.GetAddressBytes();
                for (int i = 0; i < 4; ++i)
                    address[i] = (byte)(address[i] | ~mask[i]);
                yield return new IPAddress(address);
            }
        }
    }

    // Broadcast search of the local network.
    public static Task<List<Game>> Search(TimeSpan wait, CancellationToken cancel) =>
        Collect(BroadcastAddresses().Distinct().ToArray(), wait, cancel);

    // Direct question to one host, including hosts reached over a VPN or the internet.
    public static async Task<Game?> Ask(string address, TimeSpan wait, CancellationToken cancel) {
        if (!OnlineOptions.TryHost(address, out string host))
            return null;
        return (await Collect(new[] { IPAddress.Parse(host) }, wait, cancel).ConfigureAwait(false))
            .FirstOrDefault();
    }

    static async Task<List<Game>> Collect(IPAddress[] targets, TimeSpan wait,
                                          CancellationToken cancel) {
        var found = new Dictionary<string, Game>();
        using var socket = new UdpClient(new IPEndPoint(IPAddress.Any, 0)) { EnableBroadcast = true };
        foreach (var target in targets) {
            try {
                await socket.SendAsync(Query, new IPEndPoint(target, Port), cancel).ConfigureAwait(false);
            } catch (SocketException) {
            }
        }
        using var limit = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        limit.CancelAfter(wait);
        while (found.Count < 32) {
            UdpReceiveResult reply;
            try {
                reply = await socket.ReceiveAsync(limit.Token).ConfigureAwait(false);
            } catch (OperationCanceledException) {
                break;
            } catch (SocketException) {
                // ICMP port unreachable from a host that is not hosting; keep listening.
                continue;
            }
            if (Decode(reply.Buffer) is { } game)
                found[game.Address] = game;
        }
        cancel.ThrowIfCancellationRequested();
        return found.Values.OrderBy(g => g.Name, StringComparer.OrdinalIgnoreCase).ToList();
    }
}
