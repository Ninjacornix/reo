using System.IO;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Offline checks for co-op mode settings, LAN discovery packets and the lobby planner. The planner
// cases mirror tools/coop_playtest/test_lobby_driver.py; no game or network is used.
static class CoopAutomationTests {
    static LobbyAutomation.Snapshot Base() =>
        new(State: 2, Sub: 0, Menu: 1, Phase: 0, Nested: 0, Cursor: 0, SettingsCursor: 0,
            JoinCursor: 0, CharacterIndex: 0, CharacterCount: 8, AreaCursor: 0, AreaPage: 0,
            RoomCursor: 0, RoomPage: 0, MemberCount: 1, Host: 1, Chat: false, AreaCount: 1,
            RoomCount: 0, Title: "", MaxPlayersIndex: 0, OuterStep: 37, OuterSub: 7, MainMode: 1,
            ServerController: 3, ServerWidget: 2, ServerWidgetSub: 0, ServerCount: 2,
            ServerRows: new[] { new LobbyAutomation.ServerRow(0, 0), new LobbyAutomation.ServerRow(1, 1) },
            KeyboardInitialized: true, KeyboardDelay: 0, KeyboardComplete: 0,
            Rooms: Array.Empty<LobbyAutomation.Room>());

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
        var reloaded = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(new Settings()))!;
        check(reloaded.AutoLobby, "Automatic waiting room must default on");

        // Discovery replies are untrusted input.
        var game = new LanDiscovery.Game("Kevin_1", "192.168.1.20", Updates.DefaultVersion, true, 20500);
        check(LanDiscovery.Decode(LanDiscovery.Encode(game)) == game, "Discovery reply round trip failed");
        check(HostNetworking.PortError(10128, 9091) == null && HostNetworking.PortError(9090, 9091) != null &&
                  HostNetworking.PortError(10128, 80) != null && HostNetworking.PortError(20000, 20001) == null,
              "Port validation changed");
        var hostSettings = new Settings { CoopMode = "host", CoopHost = "192.168.1.20", SignupPort = 20500 };
        var joinSettings = new Settings { CoopMode = "join", CoopHost = "192.168.1.20", JoinSignupPort = 20500 };
        check(MainWindow.SignupEndpoint(hostSettings, null)!.ToString() ==
                  "http://127.0.0.1:20500/reweb/signup/create_id.html" &&
                  MainWindow.SignupEndpoint(joinSettings, null)!.Port == 20500 &&
                  MainWindow.SignupEndpoint(new Settings { CoopMode = "join", CoopHost = "192.168.1.20" }, null) == null,
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

        // USB keyboard reports: Shift settles in its own report; Enter closes the text.
        var reports = LobbyAutomation.KeyboardQueue.Reports("aB_1", true);
        check(reports.Count == 2 + 4 + 4 + 2 + 2 && reports[0][2] == 4 && reports[2][0] == 2 &&
                  reports[2][2] == 0 && reports[3][2] == 5 && reports[5].All(b => b == 0) &&
                  reports[^2][2] == 40,
              "Keyboard report encoding changed");
        string queue = Path.Combine(Path.GetTempPath(), "reo-kb-" + Guid.NewGuid().ToString("N"));
        try {
            LobbyAutomation.CreateKeyboardQueue(queue);
            check(!LobbyAutomation.KeyboardQueue.TryQueue(queue, "abc", true),
                  "Keyboard text queued before the game acknowledged the queue");
            File.WriteAllText(queue + ".ack", "0");
            check(LobbyAutomation.KeyboardQueue.TryQueue(queue, "abc", true) &&
                      !LobbyAutomation.KeyboardQueue.TryQueue(queue, "abc", true),
                  "Pending keyboard reports were overwritten");
        } finally {
            File.Delete(queue);
            File.Delete(queue + ".ack");
        }

        LobbyAutomation.Step Plan(LobbyAutomation.Snapshot s, bool host = true,
                                  LobbyAutomation.Context? context = null, bool ready = true,
                                  string title = "Kevin") =>
            LobbyAutomation.Plan(host, s, context ?? new(), ready, title);
        bool Is(LobbyAutomation.Step step, LobbyAutomation.Act kind, string? value = null) =>
            step.Kind == kind && (value == null || step.Value == value);
        var A = LobbyAutomation.Act.Button;

        var server = Base() with { MainMode = 7, State = 6 };
        check(Is(Plan(server), A, "right") && Is(Plan(server with { Cursor = 1 }), A, "cross") &&
                  Is(Plan(server with { ServerRows = new[] { new LobbyAutomation.ServerRow(1, 0),
                                                             new LobbyAutomation.ServerRow(0, 1) },
                                        Cursor = 1 }), A, "left") &&
                  Is(Plan(server with { ServerWidgetSub = 1 }), LobbyAutomation.Act.Wait),
              "Server select must use the original server map");
        check(Is(Plan(Base() with { MainMode = 7, ServerRows = new[] { new LobbyAutomation.ServerRow(1, 0),
                                                                     new LobbyAutomation.ServerRow(1, 1) } }),
                  LobbyAutomation.Act.Refuse),
              "Ambiguous server map accepted");
        var outside = new LobbyAutomation.Context();
        check(Is(Plan(Base() with { State = 14 }, context: outside), LobbyAutomation.Act.Wait) &&
                  Is(Plan(Base() with { Chat = true }), LobbyAutomation.Act.Wait),
              "Post-login transition must wait");
        outside.OutsideCount = 149;
        check(Is(Plan(Base() with { State = 6 }, context: outside), LobbyAutomation.Act.Refuse),
              "Lasting disconnect state must stop steering");

        var editor = Base() with { State = 3, Menu = 3, Phase = 3, Nested = 2 };
        var warm = new LobbyAutomation.Context { TitleWarmupObserved = true };
        check(Is(Plan(editor), LobbyAutomation.Act.Wait) &&
                  Is(Plan(editor, context: warm), LobbyAutomation.Act.Text, "Kevin") &&
                  Is(Plan(editor with { KeyboardDelay = 1 }, context: warm), LobbyAutomation.Act.Wait) &&
                  Is(Plan(editor with { Title = "existing" }, context: warm), LobbyAutomation.Act.Refuse),
              "Room title must wait for the original editor");
        var settingsMenu = Base() with { State = 3, Menu = 3, Phase = 2, Nested = 1, Title = "Kevin" };
        check(Is(Plan(settingsMenu with { SettingsCursor = 2 }), A, "right") &&
                  Is(Plan(settingsMenu with { SettingsCursor = 10, MaxPlayersIndex = 2 }), A, "cross"),
              "Room settings steering changed");

        var join = Base() with { State = 3, Menu = 2, Phase = 1, Nested = 1, Host = 0 };
        check(Is(Plan(join, host: false), A, "down") &&
                  Is(Plan(join with { JoinCursor = 1 }, host: false), A, "cross") &&
                  Is(Plan(join with { CharacterIndex = 8 }, host: false), LobbyAutomation.Act.Refuse),
              "Guest room entry steering changed");
        var area = Base() with { Menu = 5 };
        check(Is(Plan(area, host: false, ready: false), LobbyAutomation.Act.Wait) &&
                  Is(Plan(area, host: false), A, "cross"),
              "Guests must wait for the host's room before entering the area");
        var list = Base() with { State = 3, Menu = 1, Host = 0,
                                 Rooms = new[] { new LobbyAutomation.Room(0, 1, false),
                                                 new LobbyAutomation.Room(1, 3, true) } };
        var focus = new LobbyAutomation.Context();
        var onRoom = list with { RoomCursor = 1 };
        check(Is(Plan(onRoom, host: false, context: focus), A, "left") &&
                  Is(Plan(onRoom, host: false, context: focus), A, "cross"),
              "Guests press Left once before choosing the host's room");
        check(Is(Plan(list, host: false), A, "down") && Is(Plan(list), A, "cross") &&
                  Is(Plan(list with { Rooms = new[] { new LobbyAutomation.Room(0, 3, true),
                                                      new LobbyAutomation.Room(1, 3, true) } },
                          host: false), LobbyAutomation.Act.Refuse) &&
                  Is(Plan(list with { Rooms = new[] { new LobbyAutomation.Room(0, 3, false) } },
                          host: false), LobbyAutomation.Act.Wait) &&
                  Is(Plan(list with { Rooms = new[] { new LobbyAutomation.Room(0, 3, false) } },
                          host: false, title: "", context: new() { RoomFocusMoved = true }), A, "cross"),
              "Room selection must only enter the host's room");
        check(Is(Plan(Base() with { State = 4, Phase = 6, Nested = 2 }), LobbyAutomation.Act.Done) &&
                  Is(Plan(Base() with { State = 4, Phase = 6, Nested = 2, Host = 0 }, host: false),
                     LobbyAutomation.Act.Done),
              "Waiting room must end steering without pressing Start");
    }
}
