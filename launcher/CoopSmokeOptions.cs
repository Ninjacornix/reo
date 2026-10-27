using System.IO;
using System.Net;
using System.Text.Json;

namespace Outbreak.Launcher;

// Explicit diagnostics only. Never saved into normal launcher preferences.
internal sealed record CoopSmokeOptions(string Folder, string Player, string Mode, string Address,
                                         string Room, int Seconds, bool Lobby, bool StartServer,
                                         bool AllowConcurrent) {
    internal string AccountHome => Path.Combine(Folder, "launcher-state");
    internal string Work => Path.Combine(Folder, "work");
    internal string Card => Path.Combine(Folder, "card0");

    internal static CoopSmokeOptions? Parse(string[] args) {
        bool explicitSession = args.Contains("--test-coop-session");
        if (!explicitSession && !args.Contains("--test-auto-network")) return null;
        string? Option(string key) {
            int at = Array.IndexOf(args, key);
            if (at < 0) return null;
            if (at + 1 >= args.Length || args[at + 1].StartsWith("--", StringComparison.Ordinal))
                throw new ArgumentException(key + " requires a value.");
            return args[at + 1];
        }
        string player = Option("--test-coop-player") ??
            "auto" + System.Security.Cryptography.RandomNumberGenerator.GetInt32(100000, 999999);
        if (!OnlineOptions.ValidUsername(player))
            throw new ArgumentException("--test-coop-player requires a valid disposable player name.");
        if (new[] { "--test-mod", "--test-cheats", "--test-builtin-cheats", "--test-pickup",
                    "--test-room-preview", "--test-enemies", "--test-enemy-combat", "--test-roster-probe" }
            .Any(args.Contains))
            throw new ArgumentException("Co-op session diagnostics cannot be combined with gameplay/mod test routes.");
        string mode = Option("--test-coop-mode") ?? (explicitSession ? "join" : "host");
        if (mode is not ("host" or "join"))
            throw new ArgumentException("--test-coop-mode must be host or join.");
        string address = Option("--test-coop-address") ?? "127.0.0.1";
        if (!OnlineOptions.TryHost(address, out address) || !IPAddress.IsLoopback(IPAddress.Parse(address)))
            throw new ArgumentException("Co-op diagnostics use a loopback server only.");
        bool lobby = args.Contains("--test-coop-lobby"), start = args.Contains("--test-coop-start-server");
        if (start && mode != "host")
            throw new ArgumentException("--test-coop-start-server requires host mode.");
        string? room = Option("--test-coop-room");
        if (lobby && mode == "join" && room == null)
            throw new ArgumentException("Join lobby diagnostics require --test-coop-room with the host's room title.");
        room ??= player;
        if (!OnlineOptions.ValidUsername(room))
            throw new ArgumentException("--test-coop-room requires a 4–10 character room title using player-name characters.");
        string secondsText = Option("--test-coop-seconds") ?? "240";
        if (!int.TryParse(secondsText, out int seconds) || seconds is < 15 or > 900)
            throw new ArgumentException("--test-coop-seconds must be 15–900.");
        string folder = Path.GetFullPath(Option("--test-coop-session") ??
            Path.Combine(Settings.Home, "test-coop", Guid.NewGuid().ToString("N")));
        return new(folder, player, mode, address, room, seconds, lobby, start, explicitSession);
    }

    internal void Prepare(Settings snapshot) {
        if (Directory.Exists(Folder) || File.Exists(Folder))
            throw new IOException("Use a new --test-coop-session folder; existing test evidence is preserved.");
        Directory.CreateDirectory(Folder);
        using (var claim = new FileStream(Path.Combine(Folder, "session-options.json"), FileMode.CreateNew,
                                         FileAccess.Write, FileShare.None))
            JsonSerializer.Serialize(claim, new { snapshot.SelectedGame, Player, Mode, Address, Room,
                Seconds, Lobby, StartServer, AllowConcurrent, AccountHome, Work, Card });
        Directory.CreateDirectory(Card);
        Directory.CreateDirectory(Work);
        snapshot.SelectCard(Card);
        snapshot.CoopMode = Mode;
        snapshot.HostServer = Mode == "host";
        snapshot.HostAddress = snapshot.CoopHost = Address;
        snapshot.AccountUsername = Player;
        snapshot.JoinHostName = Room;
        snapshot.JoinSignupPort = 0;
        snapshot.SignupPort = HostNetworking.SignupPort;
        snapshot.GamePort = HostNetworking.GamePort;
        snapshot.Fullscreen = false;
        snapshot.WindowSize = 0;
        snapshot.InternalResolution = 1;
        snapshot.Anisotropy = 1;
        snapshot.AntiAliasing = false;
        snapshot.AntiAliasingMode = "off";
        snapshot.AutoForward = false;
        snapshot.EnabledMods.Clear();
        snapshot.CheatsEnabled = false;
        snapshot.EnabledCheats.Clear();
        snapshot.InputDeviceId = "keyboard";
    }
}
