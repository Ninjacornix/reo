using System.IO;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Offline checks for co-op mode settings, LAN discovery packets and hosted-server settings;
// no game or network is used.
static class CoopAutomationTests {
    public static void Run(Action<bool, string> check) {
        // Settings saved by older launchers keep their meaning.
        check(new Settings { HostServer = true }.ResolvedCoopMode == "host" &&
                  new Settings { CoopHost = "10.0.0.2" }.ResolvedCoopMode == "join" &&
                  new Settings().ResolvedCoopMode == "offline" &&
                  new Settings { CoopMode = "offline", CoopHost = "10.0.0.2" }.ResolvedCoopMode == "offline",
              "Co-op mode migration changed");
        var joining = new Settings { CoopMode = "join", CoopHost = "10.0.0.2", AccountUsername = "reo01" };
        check(OnlineOptions.Configured(joining) &&
                  !OnlineOptions.Configured(new Settings { CoopMode = "offline", CoopHost = "10.0.0.2",
                                                           AccountUsername = "reo01" }) &&
                  OnlineOptions.Error(new Settings { CoopMode = "offline", CoopHost = "x" }) == null,
              "Play alone must not use or validate network settings");

        // Discovery replies are untrusted input.
        var game = new LanDiscovery.Game("Kevin_1", "192.168.1.20", Updates.DefaultVersion, true, 20500);
        check(LanDiscovery.Decode(LanDiscovery.Encode(game)) == game, "Discovery reply round trip failed");
        check(HostNetworking.PortError(10128, 9091) == null && HostNetworking.PortError(9090, 9091) != null &&
                  HostNetworking.PortError(10128, 80) != null && HostNetworking.PortError(20000, 20001) == null,
              "Port validation changed");
        var hostSettings = new Settings { CoopMode = "host", CoopHost = "192.168.1.20", SignupPort = 20500 };
        var joinSettings = new Settings { CoopMode = "join", CoopHost = "192.168.1.20", JoinSignupPort = 20500 };
        check(SignupEndpoints.For(hostSettings, null)!.ToString() ==
                  "http://127.0.0.1:20500/reweb/signup/create_id.html" &&
                  SignupEndpoints.For(joinSettings, null)!.Port == 20500 &&
                  SignupEndpoints.For(new Settings { CoopMode = "join", CoopHost = "192.168.1.20" }, null) == null,
              "Sign-up must use the host's configured port");
        foreach (string bad in new[] {
                     "REO-LAN!1{\"name\":\"x\",\"address\":\"192.168.1.20\",\"version\":\"1\",\"room\":true,\"signup\":10128}",
                     "REO-LAN!1{\"name\":\"Kevin\",\"address\":\"192.168.1.20\",\"version\":\"1\",\"room\":true,\"signup\":80}",
                     "REO-LAN!1{\"name\":\"Kevin\",\"address\":\"999.1.1.1\",\"version\":\"1\",\"room\":true}",
                     "REO-LAN!1{\"name\":\"Kevin\",\"address\":\"192.168.1.20\",\"version\":\"1\"}",
                     "REO-LAN!2{\"name\":\"Kevin\",\"address\":\"192.168.1.20\",\"version\":\"1\",\"room\":true}",
                     "REO-LAN!1[1,[2,[3]]]", "REO-LAN!1" + new string(' ', 600) })
            check(LanDiscovery.Decode(Encoding.ASCII.GetBytes(bad)) == null,
                  "Invalid discovery reply accepted: " + bad[..Math.Min(bad.Length, 40)]);

        // A busy hosting port is reported with the program that holds it.
        using (var busy = new System.Net.Sockets.TcpListener(System.Net.IPAddress.Loopback,
                                                             HostNetworking.SignupPort + 33000)) {
            busy.Start();
            string message = "";
            try {
                HostedServer.CheckPorts(33000);
            } catch (IOException error) {
                message = error.Message;
            }
            string self = System.Diagnostics.Process.GetCurrentProcess().ProcessName;
            check(message.Contains($"{HostNetworking.SignupPort + 33000} TCP is used by {self}") &&
                      message.Contains("choose other ports"),
                  "Port conflict message does not name the program: " + message);
        }

        // Real UDP round trip through the responder on this PC.
        using (new LanDiscovery.Responder(() => game)) {
            var answer = Task.Run(() => LanDiscovery.Ask("127.0.0.1", TimeSpan.FromSeconds(2),
                                                         CancellationToken.None))
                             .GetAwaiter().GetResult();
            check(answer == game, "A hosting launcher did not answer a direct discovery query");
        }

        // File #2 uses a different query so old File #1 launchers cannot see its rooms.
        var secondGame = game with { GameId = "file2" };
        check(LanDiscovery.Decode(LanDiscovery.Encode(secondGame)) == secondGame,
              "File #2 discovery preserves its edition identity");
        check(LanDiscovery.Decode(Encoding.ASCII.GetBytes(
            "REO-LAN!1{\"name\":\"Kevin\",\"address\":\"127.0.0.1\",\"version\":\"1\",\"room\":true,\"signup\":10128,\"game\":\"file2\"}")) == null,
              "Legacy replies cannot advertise File #2 to File #1 clients");
        var secondSession = RandomizerSession.Create(secondGame.Name, new(), "file2");
        using (new LanDiscovery.Responder(() => secondGame, () => secondSession)) {
            var matching = Task.Run(() => LanDiscovery.Ask("127.0.0.1", TimeSpan.FromMilliseconds(250),
                CancellationToken.None, "file2")).GetAwaiter().GetResult();
            var mismatched = Task.Run(() => LanDiscovery.Ask("127.0.0.1", TimeSpan.FromMilliseconds(150),
                CancellationToken.None, "file1")).GetAwaiter().GetResult();
            check(matching == secondGame && mismatched == null,
                  "File #2 host answers only File #2 discovery requests");
            using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(3));
            var guest = new Settings { SelectedGame = "file2", CoopMode = "join", CoopHost = "127.0.0.1",
                                       JoinHostName = secondGame.Name };
            var session = RandomizerSession.Resolve(guest, new(), timeout.Token).GetAwaiter().GetResult();
            check(session.Bytes.SequenceEqual(secondSession) && session.Mods.Count == 0,
                  "File #2 guest can join an unmodded host through the launcher responder");
        }
        using (new LanDiscovery.Responder(() => game)) {
            var mismatched = Task.Run(() => LanDiscovery.Ask("127.0.0.1", TimeSpan.FromMilliseconds(150),
                CancellationToken.None, "file2")).GetAwaiter().GetResult();
            check(mismatched == null, "File #1 host cannot be joined through File #2 discovery");
        }
        foreach (var edition in new[] { ("file1", "outbreak"), ("file2", "outbreak2") }) {
            var env = HostedServer.EditionEnvironment(edition.Item1, "127.0.0.1", 20001);
            using var map = JsonDocument.Parse(env["OPENSNAP_GAME_SERVER_MAP"]);
            var endpoint = map.RootElement.GetProperty(edition.Item2);
            check(env["OPENSNAP_BOOTSTRAP_GAMES"] == edition.Item2 &&
                  env["OPENSNAP_GAME_PLUGIN"] == edition.Item2 && env["OPENSNAP_WEB_GAME_PLUGIN"] == edition.Item2 &&
                  endpoint.GetProperty("host").GetString() == "127.0.0.1" &&
                  endpoint.GetProperty("port").GetInt32() == 20001 && map.RootElement.EnumerateObject().Count() == 1,
                  edition.Item1 + " selects only its matching bootstrap, game and web server plugin");
        }
        check(HostedServer.StateFolder("test", "file1") != HostedServer.StateFolder("test", "file2"),
              "Hosted editions use separate server databases and leases");
        foreach (string host in new[] { "127.0.0.1", "127.8.9.10", "192.168.1.20" }) {
            var env = HostedServer.EditionEnvironment("file2", host, 9091);
            string expected = host.StartsWith("127.", StringComparison.Ordinal) ? host : "0.0.0.0";
            check(new[] { "OPENSNAP_BOOTSTRAP_HOST", "OPENSNAP_GAME_HOST", "OPENSNAP_CAPCOM_APP_HOST",
                          "OPENSNAP_WEB_HOST" }.All(key => env[key] == expected),
                  "Loopback hosting binds all four services locally; LAN hosting remains reachable");
        }
    }
}
