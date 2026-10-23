using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Outbreak.Launcher;

// A host publishes one immutable, data-only configuration for its running game.
// Joining players use this snapshot instead of their locally enabled randomizers.
internal static class RandomizerSession {
    internal const int Protocol = 3, MaxPacket = 32768;
    internal const string Capability = "[MOD-SESSION-3] scenario-plan";
    internal static readonly byte[] QueryPrefix = Encoding.ASCII.GetBytes("REO-MODS?3");
    internal static readonly byte[] ReplyPrefix = Encoding.ASCII.GetBytes("REO-MODS!3");
    static readonly JsonSerializerOptions Json = new() {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        MaxDepth = 12
    };
    internal sealed class Configuration {
        public int Protocol { get; set; }
        public string Session { get; set; } = "";
        public string Elf { get; set; } = "";
        public string Host { get; set; } = "";
        public WeaponShuffle? Weapons { get; set; }
        public ItemRandomizer? Items { get; set; }
        public EnemyRandomizer? Enemies { get; set; }
    }
    internal sealed record Resolution(byte[] Bytes, List<ModManifest> Mods);
    internal static async Task<Resolution> Resolve(Settings settings, List<ModManifest> selected,
                                                  CancellationToken cancel, int port=LanDiscovery.Port) {
        if (settings.CheatsEnabled && settings.EnabledCheats.Count != 0)
            throw new IOException("Disable local cheats before joining or hosting a shared randomizer session.");
        if (settings.ResolvedCoopMode == "host")
            return new(Create(settings.AccountUsername, selected), selected);
        if (settings.ResolvedCoopMode != "join") throw new IOException("A shared session requires host or join mode.");
        var bytes = await Fetch(settings.CoopHost, cancel, port);
        var shared = Parse(bytes);
        if (settings.JoinHostName.Length > 0 && settings.JoinHostName != shared.Host)
            throw new IOException("The host changed. Refresh the game list before joining.");
        return new(bytes, ModsFor(shared));
    }
    internal static byte[] Create(string host, List<ModManifest> mods) {
        if (!OnlineOptions.ValidUsername(host) || mods.Any(m => m.Effects.Count != 0 || m.Patches.Count != 0))
            throw new IOException("Co-op supports host-controlled randomizers only; disable other gameplay mods.");
        if (mods.Count(m => m.WeaponShuffle != null || m.ItemRandomizer != null) > 1 ||
            mods.Count(m => m.EnemyRandomizer != null) > 1)
            throw new IOException("Enable at most one item and one enemy randomizer.");
        var config = new Configuration { Protocol=Protocol, Elf=DiscImport.FirstElfSha256,
            Session = Guid.NewGuid().ToString("N"), Host = host,
            Weapons = mods.SingleOrDefault(m => m.WeaponShuffle != null)?.WeaponShuffle,
            Items = mods.SingleOrDefault(m => m.ItemRandomizer != null)?.ItemRandomizer,
            Enemies = mods.SingleOrDefault(m => m.EnemyRandomizer != null)?.EnemyRandomizer };
        byte[] bytes = JsonSerializer.SerializeToUtf8Bytes(config, Json);
        _ = Parse(bytes);
        return bytes;
    }
    internal static Configuration Parse(byte[] bytes) {
        if (bytes.Length > MaxPacket - 64) throw new IOException("Host randomizer configuration is too large.");
        try {
            var config = JsonSerializer.Deserialize<Configuration>(bytes, Json)
                ?? throw new IOException("Host configuration is empty.");
            if (config.Protocol != Protocol || config.Elf != DiscImport.FirstElfSha256 ||
                config.Session == null || config.Session.Length != 32 || !Guid.TryParseExact(config.Session, "N", out _) ||
                !OnlineOptions.ValidUsername(config.Host))
                throw new IOException("Host randomizer session is incompatible. Update both launchers and game builds.");
            _ = ModsFor(config); // Reuse strict manifest validation for all numeric data.
            return config;
        } catch (JsonException e) { throw new IOException("Invalid host randomizer configuration.", e); }
    }
    internal static List<ModManifest> ModsFor(Configuration config) {
        if (config.Weapons == null && config.Items == null && config.Enemies == null) return new();
        var manifest = new ModManifest { Format=1, Id="session.host-randomizers", Name="Host randomizers",
            Version="3", ElfSha256=config.Elf, WeaponShuffle=config.Weapons,
            ItemRandomizer=config.Items, EnemyRandomizer=config.Enemies };
        return new() { Mods.Parse(JsonSerializer.Serialize(manifest, Json)) };
    }
    internal static byte[]? Reply(byte[] query, byte[]? configuration) {
        if (query.Length != QueryPrefix.Length + 16 || !query.AsSpan().StartsWith(QueryPrefix)) return null;
        // Empty body explicitly means that the host has not launched yet.
        return ReplyPrefix.Concat(query.Skip(QueryPrefix.Length)).Concat(configuration ?? Array.Empty<byte>()).ToArray();
    }
    internal static byte[] Decode(byte[] packet, byte[] nonce) {
        if (packet.Length > MaxPacket || packet.Length < ReplyPrefix.Length + 16 ||
            !packet.AsSpan().StartsWith(ReplyPrefix) ||
            !packet.AsSpan(ReplyPrefix.Length,16).SequenceEqual(nonce))
            throw new IOException("Unexpected randomizer session response.");
        var body = packet[(ReplyPrefix.Length+16)..];
        if (body.Length == 0) throw new IOException("The host needs to press Play before you join.");
        _ = Parse(body);
        return body;
    }
    internal static async Task<byte[]> Fetch(string host, CancellationToken cancel, int port=LanDiscovery.Port) {
        if (!OnlineOptions.TryHost(host, out string address)) throw new IOException("Invalid host address.");
        using var socket = new UdpClient(AddressFamily.InterNetwork);
        socket.Connect(new IPEndPoint(IPAddress.Parse(address), port));
        byte[] nonce=RandomNumberGenerator.GetBytes(16), query=QueryPrefix.Concat(nonce).ToArray();
        for (int attempt=0; attempt<3; ++attempt) {
            await socket.SendAsync(query, cancel).ConfigureAwait(false);
            using var wait=CancellationTokenSource.CreateLinkedTokenSource(cancel);
            wait.CancelAfter(TimeSpan.FromSeconds(2));
            try {
                var response=await socket.ReceiveAsync(wait.Token).ConfigureAwait(false);
                return Decode(response.Buffer, nonce);
            } catch (OperationCanceledException) when (!cancel.IsCancellationRequested) { }
              catch (SocketException) { }
        }
        cancel.ThrowIfCancellationRequested();
        throw new IOException("Could not read the host's randomizer settings. Keep the host launcher open and allow UDP port 10129, then retry.");
    }
    internal static string Digest(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
}
