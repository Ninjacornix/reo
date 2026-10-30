using System.IO;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Models the original option records and pad handler, using the edition layouts
// verified against the owned BIN3 images. No running game or router is modified.
internal static class LobbyRoomSettingsTests {
    internal static void Run(Action<bool, string> check) {
        check(LobbySettings.ValidTitle("RaccoonCrew_123") && !LobbySettings.ValidTitle("RaccoonCrew_1234") &&
            !LobbySettings.ValidTitle("bad title") && !LobbySettings.ValidTitle(""),
            "Room titles honor the original fifteen-byte editor and supported keyboard reports");
        var settings = new Settings { AccountUsername = "Kevin", RoomName = "RaccoonCrew", RoomMaxPlayers = 3, RoomWaitMinutes = 30 };
        var restored = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
        check(restored.ResolvedRoomName == "RaccoonCrew" && restored.ResolvedRoomMaxPlayers == 3 && restored.ResolvedRoomWaitMinutes == 30,
            "Named room, player count and wait preferences persist together");
        settings.RoomName = ""; settings.RoomMaxPlayers = 99; settings.RoomWaitMinutes = 3;
        check(settings.ResolvedRoomName == "Kevin" && settings.ResolvedRoomMaxPlayers == 4 && settings.ResolvedRoomWaitMinutes == 5,
            "Blank room names use the player name and unsupported File #1 choices resolve safely");
        settings.SelectedGame = "file2";
        check(settings.ResolvedRoomWaitMinutes == 3, "File #2 retains its original extra three-minute choice");
        foreach (string game in new[] { "file1", "file2" }) {
            var advertised = new LanDiscovery.Game("Kevin", "127.0.0.1", Updates.DefaultVersion, true, GameId: game, RoomTitle: "RaccoonCrew_123");
            check(LanDiscovery.Decode(LanDiscovery.Encode(advertised)) == advertised,
                game + " discovery preserves the fifteen-character custom room title");
            check(LanDiscovery.Decode(LanDiscovery.Encode(advertised with { RoomTitle = "room-too-long-and-unsafe" })) == null,
                game + " discovery rejects unsupported room titles from the network");

            bool second = game == "file2";
            byte[] ram = new byte[0x2000000];
            uint overlay = second ? 0x58D000u : 0x570000u, root = second ? 0x6E2ED0u : 0x6D8DB0u;
            uint options = second ? 0x6B53E0u : 0x6A3DE0u;
            int cursorOffset = second ? 0x908 : 0x8DF;
            BitConverter.GetBytes(0x336F574Du).CopyTo(ram, overlay);
            BitConverter.GetBytes(4u).CopyTo(ram, overlay + 4);
            ram[root] = 3; ram[root + 0xE] = 3; ram[root + 0xF] = 2; ram[root + 0x10] = 1; ram[root + 0x41A] = 1;
            ram[root + (second ? 0x97Eu : 0x956u)] = 1;
            ram[options + 0x54] = 2;
            Encoding.ASCII.GetBytes("RaccoonCrew_123").CopyTo(ram, options + 0x12);
            byte[] Read(uint address, int count) => ram.AsSpan((int)address, count).ToArray();
            void Option(uint address, int[] choices, int current) {
                ram[address + 0x97] = (byte)choices.Length;
                ram[address + 0x98] = 1; ram[address + 0x99] = ram[address + 0x9A] = (byte)current;
                ram[address + 0x9B] = 0; ram[address + 0x9C] = (byte)(choices.Length - 1);
                for (int i = 0; i < choices.Length; i++) {
                    ram.AsSpan((int)address + 0xBD + i * 64, 64).Clear();
                    Encoding.ASCII.GetBytes(choices[i] + (address == options ? "" : " min"))
                        .CopyTo(ram, address + 0xBD + i * 64);
                }
            }
            int[] waits = LobbySettings.WaitTimes(game);
            Option(options, new[] { 2, 3, 4 }, 2);
            Option(options + 0x14A8, waits, second ? 1 : 0);
            var initial = LobbyAutomation.GuestMemory.ReadSnapshot(Read, game);
            check(initial.PlayersOption is { Index: 2, Minimum: 0, Maximum: 2, Editable: true } &&
                initial.PlayersOption.Values.SequenceEqual(new[] { 2, 3, 4 }) &&
                initial.WaitingOption!.Values[initial.WaitingOption.Index] == 5,
                game + " reads real option labels, normalized indices and bounds at its original memory addresses");

            foreach (int players in new[] { 2, 3, 4 }) foreach (int minutes in waits) {
                Option(options, new[] { 2, 3, 4 }, 2);
                Option(options + 0x14A8, waits, second ? 1 : 0);
                ram[root] = 3; ram[root + 0xF] = 2; ram[root + 0x10] = 1; ram[root + (uint)cursorOffset] = 0;
                bool finished = false;
                for (int stepCount = 0; stepCount < 50; stepCount++) {
                    var snapshot = LobbyAutomation.GuestMemory.ReadSnapshot(Read, game);
                    var step = LobbyAutomation.Plan(true, snapshot, new(), true, "RaccoonCrew_123", game, players, minutes);
                    if (step.Kind == LobbyAutomation.Act.Done) { finished = true; break; }
                    if (step.Kind != LobbyAutomation.Act.Button) break;
                    int cursor = ram[root + (uint)cursorOffset];
                    if (step.Value is "up" or "down")
                        ram[root + (uint)cursorOffset] = (byte)(cursor + (step.Value == "up" ? -1 : 1));
                    else if (step.Value is "left" or "right") {
                        uint address = options + (cursor == 3 ? 0x14A8u : 0u) + 0x9A;
                        ram[address] = (byte)(ram[address] + (step.Value == "left" ? -1 : 1));
                    } else if (step.Value == "cross" && cursor == 10) {
                        // Native finish is allowed only once both requested values are set.
                        if (new[] { 2, 3, 4 }[ram[options + 0x9A]] != players || waits[ram[options + 0x14A8 + 0x9A]] != minutes) break;
                        ram[root] = 4; ram[root + 0xF] = 6; ram[root + 0x10] = 2;
                    } else break;
                }
                check(finished, $"{game} original menu automation reaches the waiting room with {players} players and {minutes} minutes");
            }
            ram[root] = 3; ram[root + 0xF] = 2; ram[root + 0x10] = 1; ram[root + (uint)cursorOffset] = 10;
            Option(options, new[] { 2, 3, 4 }, 2); Option(options + 0x14A8, waits, second ? 1 : 0);
            ram[options + 0x9B] = 1;
            check(LobbyAutomation.Plan(true, LobbyAutomation.GuestMemory.ReadSnapshot(Read, game), new(), true,
                "RaccoonCrew_123", game, 2, 5).Kind == LobbyAutomation.Act.Refuse,
                game + " refuses a player count excluded by the live area's dependency bounds");
            ram[options + 0x9B] = 0; ram[options + 0x14A8 + 0x98] = 0;
            var fixedWait = LobbyAutomation.GuestMemory.ReadSnapshot(Read, game);
            check(LobbyAutomation.Plan(true, fixedWait, new(), true, "RaccoonCrew_123", game, 4, 10).Kind == LobbyAutomation.Act.Refuse &&
                LobbyAutomation.Plan(true, fixedWait, new(), true, "RaccoonCrew_123", game, 4, 5).Value == "cross",
                game + " changes no locked wait option, while accepting its already selected value");
            ram[options + 0x97] = 0;
            bool refused = false;
            try { LobbyAutomation.GuestMemory.ReadSnapshot(Read, game); } catch (InvalidDataException) { refused = true; }
            check(refused, game + " rejects incomplete original option records before issuing input");
        }
    }
}
