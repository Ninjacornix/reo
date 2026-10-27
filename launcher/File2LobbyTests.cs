using System.IO;
using System.Text;

namespace Outbreak.Launcher;

// Checks edition isolation and refusal gates; native gameplay is validated separately.
static class File2LobbyTests {
    public static void Run(Action<bool, string> check) {
        CheckJoiningTitle(check);
        var segments = new Dictionary<uint, byte[]> {
            [0x58D000] = new byte[] { 0x4D, 0x57, 0x6F, 0x33, 4, 0, 0, 0 },
            [0x6E2ED0] = new byte[0xA00], [0x6E293E] = new byte[6],
            [0x6B53F2] = new byte[16], [0x6DEAA0] = new byte[0x15C],
            [0x64C160] = new byte[4], [0x64C148] = new byte[1],
            [0x6B547A] = new byte[1], [0x8AA5D8] = new byte[1],
            [0x6E9490] = new byte[1], [0x6E9491] = new byte[1],
            [0x6A9848] = new byte[1], [0x6A9849] = new byte[1]
        };
        byte[] root = segments[0x6E2ED0];
        root[0] = 3; root[0xE] = 1; root[0x41A] = 1;
        segments[0x6E293E][0] = 1; segments[0x6E293E][4] = 1;
        segments[0x6DEAA0][0xE] = 1;
        byte[] Read(uint address, int size) {
            if (!segments.TryGetValue(address, out var data) || data.Length != size)
                throw new InvalidOperationException($"Unexpected File #2 read: {address:X8}/{size:X}");
            return data.ToArray();
        }
        var snapshot = LobbyAutomation.GuestMemory.ReadSnapshot(Read, "file2");
        check(snapshot.Rooms.Count == 1 && snapshot.Rooms[0].Kind == 1 && snapshot.ServerCount == 0 &&
                  snapshot.ServerRows.Count == 0 && snapshot.ServerControllerSub == 0,
              "File #2 reader must isolate its memory and read server count without a synthetic File #1 mode table");
        check(LobbyAutomation.Plan(true, snapshot, new(), true, "", "file2").Value == "cross",
              "File #2 verified room list must allow vacancy selection");
        var server = snapshot with { MainMode = 7, OuterStep = 37, OuterSub = 7,
            ServerController = 3, ServerControllerSub = -1, ServerWidget = 2, ServerWidgetSub = 0, ServerCount = 1,
            ServerRows = new[] { new LobbyAutomation.ServerRow(1, 0) } };
        check(LobbyAutomation.Plan(true, server, new(), true, "", "file2").Kind == LobbyAutomation.Act.Wait,
              "File #2 must not use File #1 server-selection inputs even with matching stale fields");
        check(LobbyAutomation.Plan(true, server with { ServerControllerSub = 0 }, new(), true, "", "file2").Value ==
                  "cross", "File #2 sole server must accept Confirm only at verified idle gates");
        check(LobbyAutomation.Plan(true, server with { ServerControllerSub = 0, ServerCount = 2 }, new(), true, "", "file2").Kind ==
                  LobbyAutomation.Act.Wait, "File #2 multiple servers require manual selection");
        check(LobbyAutomation.Plan(true, server with { ServerControllerSub = 0, ServerWidgetSub = 1 }, new(), true, "", "file2").Kind ==
                  LobbyAutomation.Act.Wait, "File #2 server transitions must not receive automatic input");
        check(LobbyAutomation.Plan(true, snapshot with { Chat = true }, new(), true, "", "file2").Kind ==
                  LobbyAutomation.Act.Wait, "File #2 modal state must prevent automatic input");
        check(LobbyAutomation.Plan(true, snapshot, new(), true, "", "unknown").Kind == LobbyAutomation.Act.Refuse,
              "Unknown games must not use a lobby layout");
        var difficulty = snapshot with { State = 1, Menu = 1, Phase = 2, AreaCount = 0, Cursor = 9 };
        check(LobbyAutomation.Plan(true, difficulty, new(), true, "", "file2").Value == "left",
              "File #2 difficulty selection must precede the scenario area list");
        var editor = snapshot with { State = 3, Menu = 3, Phase = 3, Nested = 2,
            KeyboardInitialized = true, KeyboardDelay = 0, KeyboardComplete = 0, Title = "" };
        var context = new LobbyAutomation.Context();
        check(LobbyAutomation.Plan(true, editor, context, true, "cooptest", "file2").Kind == LobbyAutomation.Act.Wait &&
                  LobbyAutomation.Plan(true, editor, context, true, "cooptest", "file2").Kind == LobbyAutomation.Act.Text,
              "File #2 title editor must become ready after stable observations without sampling one-frame warmup");
        check(LobbyAutomation.Plan(true, editor with { KeyboardComplete = 1 }, context, true, "cooptest", "file2").Kind ==
                  LobbyAutomation.Act.Wait &&
                  LobbyAutomation.Plan(true, editor, context, true, "cooptest", "file2").Kind == LobbyAutomation.Act.Wait,
              "File #2 title readiness must reset after completion changes");
        segments[0x6E293E][4] = 129;
        bool rejected = false;
        try { LobbyAutomation.GuestMemory.ReadSnapshot(Read, "file2"); }
        catch (InvalidDataException) { rejected = true; }
        check(rejected, "File #2 oversized room lists must be rejected before memory reads");
        segments[0x6E293E][4] = 1;
        segments[0x58D000][4] = 3;
        rejected = false;
        try { LobbyAutomation.GuestMemory.ReadSnapshot(Read, "file2"); }
        catch (InvalidDataException) { rejected = true; }
        check(rejected, "File #2 must reject an inactive lobby overlay");
    }
    static void CheckJoiningTitle(Action<bool, string> check) {
        foreach (string game in new[] { "file1", "file2" }) {
            bool second = game == "file2";
            byte[] ram = new byte[0x2000000];
            uint overlay = second ? 0x58D000u : 0x570000u;
            BitConverter.GetBytes(0x336F574Du).CopyTo(ram, overlay);
            BitConverter.GetBytes(4u).CopyTo(ram, overlay + 4);
            uint root = second ? 0x6E2ED0u : 0x6D8DB0u;
            ram[root] = 3; ram[root + 0xE] = 1; ram[root + 0x41A] = 1;
            uint counts = second ? 0x6E293Eu : 0x6D881Eu;
            ram[counts + 4] = 1;
            uint room = second ? 0x6DEAA0u : 0x6CD4A0u;
            ram[room + 0xE] = 3;
            byte[] Read(uint address, int size) => ram.AsSpan((int)address, size).ToArray();
            Encoding.ASCII.GetBytes("file2h09").CopyTo(ram, room + 0x18);
            var snapshot = LobbyAutomation.GuestMemory.ReadSnapshot(Read, game, "file2h09");
            check(snapshot.Title == "" && snapshot.Rooms.Single().ContainsTitle,
                  game + " join must find configured host title when local creation buffer is empty");
            check(!LobbyAutomation.GuestMemory.ReadSnapshot(Read, game, "different").Rooms.Single().ContainsTitle,
                  game + " join must reject a different room title");
            ram[room + 0x18 + 8] = (byte)'x';
            check(!LobbyAutomation.GuestMemory.ReadSnapshot(Read, game, "file2h09").Rooms.Single().ContainsTitle,
                  game + " join must reject a room title that only shares the host prefix");
        }
    }

}
