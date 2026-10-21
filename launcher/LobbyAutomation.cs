using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Optional "take me to the waiting room" steering after the game has signed in. It is a port of
// tools/coop_playtest/lobby_driver.py for one player: it reads the original lobby state from the
// game's EE RAM through a read-only handle and answers each known idle menu gate with an ordinary
// pad press (or USB-keyboard text for the room title). Unknown states only wait. Any button the
// player presses ends the automation, so the original menus always remain usable by hand.
public sealed class LobbyAutomation : IDisposable {
    public sealed record Options(bool Host, string Title, string HostAddress,
                                 Action<bool>? HostRoomReady = null);

    // Bits of the launcher pad map (XInput order, as in Controller).
    internal static readonly IReadOnlyDictionary<string, ushort> Buttons =
        new Dictionary<string, ushort> { ["up"] = 1, ["down"] = 2, ["left"] = 4, ["right"] = 8,
                                         ["start"] = 0x10, ["cross"] = 0x1000,
                                         ["circle"] = 0x2000 };

    internal sealed record Room(int Index, int Kind, bool ContainsTitle);
    internal sealed record ServerRow(int Mode, int Backend);
    internal sealed record Snapshot(
        int State, int Sub, int Menu, int Phase, int Nested, int Cursor, int SettingsCursor,
        int JoinCursor, int CharacterIndex, int CharacterCount, int AreaCursor, int AreaPage,
        int RoomCursor, int RoomPage, int MemberCount, int Host, bool Chat, int AreaCount,
        int RoomCount, string Title, int MaxPlayersIndex, int OuterStep, int OuterSub,
        int MainMode, int ServerController, int ServerWidget, int ServerWidgetSub, uint ServerCount,
        IReadOnlyList<ServerRow> ServerRows, bool KeyboardInitialized, int KeyboardDelay,
        int KeyboardComplete, IReadOnlyList<Room> Rooms);
    internal sealed class Context {
        public int OutsideCount;
        public bool TitleQueued, TitleWarmupObserved, RoomFocusMoved;
    }
    internal enum Act { Wait, Button, Text, Done, Refuse }
    internal readonly record struct Step(Act Kind, string? Value, string Reason);

    internal static bool WaitingRoom(Snapshot s, bool host) =>
        s.State == 4 && s.Sub == 0 && s.Phase == 6 && s.Nested == 2 && !s.Chat &&
        (s.Host != 0) == host;

    // One action for verified idle gates only; mirrors lobby_driver.plan with goal waiting-room.
    internal static Step Plan(bool host, Snapshot s, Context context, bool hostRoomReady,
                              string title) {
        if (s.OuterStep == 37 && s.OuterSub == 7 && s.MainMode == 7 && s.ServerController == 3 &&
            s.ServerWidget == 2 && s.ServerWidgetSub == 0) {
            var rows = s.ServerRows;
            if (s.ServerCount != rows.Count || rows.Count == 0 || s.Cursor >= rows.Count)
                return new(Act.Refuse, null, "invalid-original-server-selection-map");
            var targets = Enumerable.Range(0, rows.Count).Where(i => rows[i].Mode == 1).ToList();
            if (targets.Count != 1)
                return new(Act.Refuse, null, "free-mode-server-map-is-missing-or-ambiguous");
            int target = targets[0];
            return new(Act.Button, s.Cursor == target ? "cross" : s.Cursor < target ? "right" : "left",
                       "select-original-free-mode-server");
        }
        // Root state can be stale in Server Select; only trust it in the lobby mode.
        if (s.MainMode != 1)
            return new(Act.Wait, null, "await-original-lobby-mode");
        if (s.Chat)
            return new(Act.Wait, null, "original-chat-or-modal-active");
        if (s.State is 6 or 14) {
            // Right after login this transient state appears before Server Select settles.
            if (++context.OutsideCount < 150)
                return new(Act.Wait, null, "await-post-login-transition");
            return new(Act.Refuse, null, "disconnect-or-post-start-ui-is-outside-this-driver");
        }
        if (WaitingRoom(s, host))
            return new(Act.Done, null, "original-waiting-room-reached");
        if (s.State == 2 && s.Sub == 0 && s.Menu == 1 && s.Phase == 0)
            return new(Act.Button, s.Cursor == 0 ? "cross" : "left", "select-original-room-list");
        if (s.State == 2 && s.Sub == 0 && s.Menu == 5 && s.Phase == 0 && s.AreaCount != 0) {
            if (!host && !hostRoomReady)
                return new(Act.Wait, null, "hold-area-entry-until-host-room-is-created");
            int index = s.AreaCursor + s.AreaPage;
            return new(Act.Button, index != 0 ? "up" : "cross", "enter-original-first-area");
        }
        if (s.State == 3 && s.Sub == 0 && s.Menu == 1 && s.Phase == 0) {
            List<int> matches;
            if (host)
                matches = s.Rooms.Where(r => r.Kind == 1).Select(r => r.Index).ToList();
            else {
                var rooms = s.Rooms.Where(r => r.Kind == 3).ToList();
                if (title.Length != 0)
                    rooms = rooms.Where(r => r.ContainsTitle).ToList();
                matches = rooms.Select(r => r.Index).ToList();
                if (matches.Count > 1)
                    return new(Act.Refuse, null, "several-rooms-match-choose-yours");
            }
            if (matches.Count == 0)
                return new(Act.Wait, null, "waiting-for-original-vacancy-or-owned-room-record");
            int target = matches[0], current = s.RoomCursor + s.RoomPage;
            if (current == target && !host && !context.RoomFocusMoved) {
                // Observed on a live guest: the room list can keep focus off the room column
                // until Left is pressed; Left is a no-op when focus is already there.
                context.RoomFocusMoved = true;
                return new(Act.Button, "left", "focus-original-room-column");
            }
            return new(Act.Button, current > target ? "up" : current < target ? "down" : "cross",
                       "select-original-room-record");
        }
        if (s.State == 3 && s.Sub == 0 && s.Menu == 3 && host) {
            if (s.Phase == 3 && s.Nested == 2 && !context.TitleQueued) {
                if (!context.TitleWarmupObserved || !s.KeyboardInitialized ||
                    s.KeyboardDelay != 0 || s.KeyboardComplete != 0)
                    return new(Act.Wait, null, "await-original-title-editor-input-readiness");
                if (s.Title.Length != 0)
                    return new(Act.Refuse, null, "title-input-is-not-empty-will-not-overwrite");
                return new(Act.Text, title, "enter-owned-room-title-through-usb-keyboard");
            }
            if (s.Phase == 2 && s.Nested == 1) {
                int cursor = s.SettingsCursor;
                if (s.Title != title) {
                    if (context.TitleQueued)
                        return new(Act.Refuse, null, "original-title-returned-with-unexpected-content");
                    if (s.Title.Length != 0)
                        return new(Act.Refuse, null, "existing-room-title-needs-manual-clear");
                    return new(Act.Button, cursor != 0 ? "up" : "cross", "open-original-title-editor");
                }
                if (s.MaxPlayersIndex != 2) {
                    if (cursor != 2)
                        return new(Act.Button, cursor > 2 ? "up" : "down",
                                   "select-original-no-players-option");
                    return new(Act.Button, s.MaxPlayersIndex < 2 ? "right" : "left",
                               "select-option-index2-four-players");
                }
                return new(Act.Button, cursor < 10 ? "down" : cursor > 10 ? "up" : "cross",
                           "select-original-finish");
            }
        }
        if (s.State == 3 && s.Sub == 0 && s.Menu == 2 && s.Phase == 1 && s.Nested == 1 && !host) {
            // The original roster skips occupied characters; accept the game's current choice.
            if (s.CharacterCount is <= 0 or > 32 || s.CharacterIndex >= s.CharacterCount)
                return new(Act.Refuse, null, "invalid-original-character-selection");
            if (s.JoinCursor == 0)
                return new(Act.Button, "down", "select-original-room-entry");
            if (s.JoinCursor == 1)
                return new(Act.Button, "cross", "confirm-original-room-entry");
        }
        if (s.State == 4 && s.Sub == 0 && s.Phase == 4)
            return new(Act.Button, "cross", "confirm-original-pre-waiting-ready-stage");
        return new(Act.Wait, null, "await-known-idle-lobby-gate");
    }

    const double PressGap = 0.35, StableFor = 0.12, BusyRetry = 0.3;
    const int PressLimit = 100;
    static readonly TimeSpan Limit = TimeSpan.FromMinutes(20);
    readonly Process process;
    readonly string elf, keyboardFile;
    readonly Action<ushort, int> press;
    readonly Func<bool> playerPressed;
    readonly Options options;
    readonly Action<string> report;
    readonly CancellationTokenSource stop = new();
    bool hostRoomReady;

    public LobbyAutomation(Process process, string elf, Controller controller, string keyboardFile,
                           Options options, Action<string> report)
        : this(process, elf, controller.Inject, () => controller.State.Buttons != 0, keyboardFile,
               options, report) {}
    internal LobbyAutomation(Process process, string elf, Action<ushort, int> press,
                             Func<bool> playerPressed, string keyboardFile, Options options,
                             Action<string> report) {
        this.process = process;
        this.elf = elf;
        this.press = press;
        this.playerPressed = playerPressed;
        this.keyboardFile = keyboardFile;
        this.options = options;
        this.report = report;
    }

    public static void CreateKeyboardQueue(string path) =>
        File.WriteAllBytes(path, KeyboardQueue.Header(0, 0));

    public Task Run() => Task.Run(async () => {
        GuestMemory? memory = null;
        try {
            await Drive(() => memory ??= GuestMemory.Open(process, elf));
        } catch (OperationCanceledException) {
        } catch (Exception error) {
            report("Automatic room setup stopped (" + error.Message.TrimEnd('.') +
                   "). Continue in the game menus.");
        } finally {
            memory?.Dispose();
        }
    });

    async Task Drive(Func<GuestMemory> memory) {
        var clock = Stopwatch.StartNew();
        var context = new Context();
        string? stableKey = null;
        double stableSince = 0, nextAction = 0, lastAsk = -10;
        double? areaGateSince = null;
        int presses = 0;
        bool steering = false;
        Task<LanDiscovery.Game?>? asking = null;
        while (!stop.IsCancellationRequested && !process.HasExited && clock.Elapsed < Limit) {
            await Task.Delay(100, stop.Token);
            double now = clock.Elapsed.TotalSeconds;
            Snapshot snapshot;
            try {
                snapshot = memory().Read();
            } catch (InvalidDataException) {
                continue; // title screen, sign-in or game loading: not in the lobby overlay yet
            } catch (IOException) when (!steering) {
                continue; // the game's memory is not mapped yet
            }
            // The player is in control as soon as they press anything.
            if (steering && playerPressed()) {
                report("Automatic room setup stopped because you pressed a button. Continue in the game menus.");
                return;
            }
            if (!options.Host && !hostRoomReady) {
                if (asking is { IsCompleted: true }) {
                    if (asking.Status == TaskStatus.RanToCompletion && asking.Result?.RoomReady == true)
                        hostRoomReady = true;
                    asking = null;
                }
                if (asking == null && now - lastAsk >= 2) {
                    lastAsk = now;
                    asking = LanDiscovery.Ask(options.HostAddress, TimeSpan.FromSeconds(1.5), stop.Token);
                }
            }
            if (snapshot.State == 3 && snapshot.Menu == 3 && snapshot.Phase == 3 &&
                snapshot.Nested == 2 && snapshot.KeyboardInitialized && snapshot.KeyboardDelay > 0)
                context.TitleWarmupObserved = true;
            string key = JsonSerializer.Serialize(snapshot);
            if (key != stableKey) {
                stableKey = key;
                stableSince = now;
            }
            var step = Plan(options.Host, snapshot, context, hostRoomReady, options.Title);
            if (step.Reason == "hold-area-entry-until-host-room-is-created") {
                areaGateSince ??= now;
                // Hosts that cannot be asked (older launcher, blocked port) still get a room: wait
                // a minute for it, then look for it.
                if (now - areaGateSince.Value > 60)
                    hostRoomReady = true;
                report("Waiting for the host to open a room...");
            }
            switch (step.Kind) {
            case Act.Done:
                options.HostRoomReady?.Invoke(true);
                report(options.Host
                           ? "You're in the waiting room. Choose START SCENARIO when everyone has joined."
                           : "You're in the host's waiting room. The host starts the scenario.");
                return;
            case Act.Refuse:
                report(step.Reason == "several-rooms-match-choose-yours"
                           ? "Several rooms are open. Choose the host's room in the game."
                           : "Automatic room setup stopped (" + step.Reason + "). Continue in the game menus.");
                return;
            case Act.Wait:
                continue;
            }
            if (now < nextAction || now - stableSince < StableFor)
                continue;
            if (presses >= PressLimit) {
                report("Automatic room setup gave up. Continue in the game menus.");
                return;
            }
            if (!steering) {
                steering = true;
                report(options.Host ? "Opening a room for your friends..." : "Joining the host's room...");
            }
            if (step.Kind == Act.Button) {
                press(Buttons[step.Value!], 180);
                ++presses;
            } else {
                if (!KeyboardQueue.TryQueue(keyboardFile, step.Value!, enter: true)) {
                    nextAction = now + BusyRetry;
                    continue;
                }
                context.TitleQueued = true;
            }
            nextAction = now + PressGap;
        }
    }

    public void Dispose() => stop.Cancel();

    // Private USB keyboard queue read by the native REO_COOP_KEYBOARD_FILE service; same format as
    // tools/coop_playtest/coop_playtest.py queue_keyboard.
    internal static class KeyboardQueue {
        const uint Magic = 0x52454F4B;
        internal static byte[] Header(uint sequence, int count) {
            var header = new byte[12];
            BitConverter.TryWriteBytes(header.AsSpan(0), Magic);
            BitConverter.TryWriteBytes(header.AsSpan(4), sequence);
            BitConverter.TryWriteBytes(header.AsSpan(8), (uint)count);
            return header;
        }
        // US-layout USB boot-keyboard reports. The original driver drops a key that changes
        // together with Shift, so Shift settles in its own report first.
        internal static List<byte[]> Reports(string text, bool enter) {
            var reports = new List<byte[]>();
            foreach (char c in text) {
                (byte modifier, byte code) = c switch {
                    >= 'a' and <= 'z' => ((byte)0, (byte)(4 + c - 'a')),
                    >= 'A' and <= 'Z' => ((byte)2, (byte)(4 + c - 'A')),
                    >= '1' and <= '9' => ((byte)0, (byte)(30 + c - '1')),
                    '0' => ((byte)0, (byte)39),
                    '_' => ((byte)2, (byte)45),
                    _ => throw new ArgumentException("Room titles use letters, numbers and _.")
                };
                if (modifier != 0)
                    reports.Add(new byte[] { modifier, 0, 0, 0, 0, 0, 0, 0 });
                reports.Add(new byte[] { modifier, 0, code, 0, 0, 0, 0, 0 });
                reports.Add(new byte[] { modifier, 0, 0, 0, 0, 0, 0, 0 });
                if (modifier != 0)
                    reports.Add(new byte[8]);
            }
            if (enter) {
                reports.Add(new byte[] { 0, 0, 40, 0, 0, 0, 0, 0 });
                reports.Add(new byte[8]);
            }
            return reports;
        }
        // False while the game has not acknowledged the previous reports; never overwrites them.
        internal static bool TryQueue(string path, string text, bool enter) {
            byte[] old = File.ReadAllBytes(path);
            if (old.Length < 12 || BitConverter.ToUInt32(old, 0) != Magic)
                throw new IOException("The keyboard queue is damaged.");
            uint previous = BitConverter.ToUInt32(old, 4);
            if (!uint.TryParse(ReadAck(path + ".ack"), out uint acknowledged) ||
                acknowledged != previous)
                return false;
            var reports = Reports(text, enter);
            using var payload = new MemoryStream();
            payload.Write(Header(previous + 1, reports.Count));
            foreach (var report in reports)
                payload.Write(report);
            string temporary = path + ".tmp-" + Guid.NewGuid().ToString("N");
            File.WriteAllBytes(temporary, payload.ToArray());
            File.Move(temporary, path, true);
            return true;
        }
        static string ReadAck(string path) {
            try {
                return File.ReadAllText(path, Encoding.ASCII).Trim();
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
                return "";
            }
        }
    }

    // Read-only view of the game's 32 MiB EE RAM. The guest RAM block is identified by the first
    // loaded ELF segment appearing at exactly one candidate base, as in lobby_driver.GuestRam.
    internal sealed class GuestMemory : IDisposable {
        const uint RamSize = 0x2000000, Root = 0x6D8DB0;
        readonly nint handle;
        readonly long baseAddress;

        GuestMemory(nint handle, long baseAddress) {
            this.handle = handle;
            this.baseAddress = baseAddress;
        }

        public static GuestMemory Open(Process process, string elfPath) {
            nint handle = OpenProcess(0x1010, false, process.Id); // QUERY_LIMITED | VM_READ
            if (handle == 0)
                throw new IOException("Cannot read the game's lobby state.");
            try {
                byte[] image = File.ReadAllBytes(elfPath);
                uint phoff = BitConverter.ToUInt32(image, 0x1C);
                int phnum = BitConverter.ToUInt16(image, 0x2C);
                (uint Address, byte[] Bytes)? segment = null;
                for (int i = 0; i < phnum && segment == null; ++i) {
                    int at = checked((int)phoff + i * 32);
                    uint kind = BitConverter.ToUInt32(image, at), offset = BitConverter.ToUInt32(image, at + 4),
                         address = BitConverter.ToUInt32(image, at + 8), size = BitConverter.ToUInt32(image, at + 16);
                    if (kind == 1 && size >= 64)
                        segment = (address, image.AsSpan(checked((int)offset), 64).ToArray());
                }
                if (segment == null)
                    throw new IOException("The game executable has no loaded segment.");
                var candidates = new HashSet<long>();
                long cursor = 0;
                var info = new MemoryInfo();
                var probe = new byte[64];
                while (cursor < 0x7FFFFFFFFFFF &&
                       VirtualQueryEx(handle, (nint)cursor, out info, Marshal.SizeOf<MemoryInfo>()) != 0) {
                    long regionBase = info.BaseAddress, size = (long)info.RegionSize;
                    if (info.State == 0x1000 && size >= RamSize && (info.Protect & 0x101) == 0)
                        foreach (long slack in new long[] { 0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x1000 })
                            if (ReadHost(handle, regionBase + slack + segment.Value.Address, probe) &&
                                probe.AsSpan().SequenceEqual(segment.Value.Bytes))
                                candidates.Add(regionBase + slack);
                    long next = regionBase + size;
                    if (next <= cursor)
                        break;
                    cursor = next;
                }
                if (candidates.Count != 1)
                    throw new IOException("The game's memory is not ready.");
                return new(handle, candidates.Single());
            } catch {
                CloseHandle(handle);
                throw;
            }
        }

        static bool ReadHost(nint handle, long address, byte[] buffer) =>
            ReadProcessMemory(handle, (nint)address, buffer, buffer.Length, out nint read) &&
            read == buffer.Length;

        byte[] Bytes(uint address, int size) {
            if (size < 0 || address + (ulong)size > RamSize)
                throw new InvalidDataException("Read outside game memory.");
            var buffer = new byte[size];
            if (!ReadHost(handle, baseAddress + address, buffer))
                throw new IOException("The game's memory is no longer readable.");
            return buffer;
        }
        uint Word(uint address) => BitConverter.ToUInt32(Bytes(address, 4));
        byte Byte(uint address) => Bytes(address, 1)[0];

        public Snapshot Read() {
            // Throws InvalidDataException outside the BIN3 lobby overlay.
            byte[] overlay = Bytes(0x570000, 8);
            if (BitConverter.ToUInt32(overlay, 0) != 0x336F574D || BitConverter.ToUInt32(overlay, 4) != 4)
                throw new InvalidDataException("The lobby is not active.");
            byte[] raw = Bytes(Root, 0x980);
            byte[] counts = Bytes(0x6D881E, 6);
            int areaCount = BitConverter.ToUInt16(counts, 0), roomCount = BitConverter.ToUInt16(counts, 4);
            if (areaCount > 128 || roomCount > 128)
                throw new InvalidDataException("Lobby list counts exceed the verified bounds.");
            byte[] title = Bytes(0x6A3DF2, 16);
            int titleLength = Array.IndexOf(title, (byte)0);
            string titleText = Encoding.ASCII.GetString(title, 0, titleLength < 0 ? 16 : titleLength);
            byte[] rooms = raw[0] == 3 && raw[0xE] == 1 ? Bytes(0x6CD4A0, roomCount * 0x15C)
                                                         : Array.Empty<byte>();
            uint serverCount = Word(0x699560);
            byte[] serverBytes = Bytes(0x6994E0, (int)Math.Min(serverCount, 32) * 2);
            uint keyboardWork = Word(0x6436D0);
            bool keyboardValid = keyboardWork > 0 && keyboardWork < RamSize - 0x40;
            byte[] keyboard = keyboardValid ? Bytes(keyboardWork, 0x40) : new byte[0x40];
            var roomList = new List<Room>();
            for (int i = 0; i < rooms.Length / 0x15C; ++i) {
                var row = rooms.AsSpan(i * 0x15C, 0x15C);
                roomList.Add(new(i, row[0xE], titleText.Length != 0 &&
                                               row.IndexOf(Encoding.ASCII.GetBytes(titleText)) >= 0));
            }
            var servers = new List<ServerRow>();
            for (int i = 0; i + 1 < serverBytes.Length; i += 2)
                servers.Add(new(serverBytes[i], serverBytes[i + 1]));
            return new(raw[0], raw[1], raw[0xE], raw[0xF], raw[0x10], raw[0x8DE], raw[0x8DF],
                       raw[0x8E0], BitConverter.ToUInt16(raw, 4), BitConverter.ToUInt16(raw, 0xA),
                       raw[0x446], raw[0x447], raw[0x444], raw[0x445],
                       BitConverter.ToUInt16(raw, 0x452), raw[0x956],
                       raw[0x13] != 0 || raw[0x14] != 0 || raw[0x54F] != 0, areaCount, roomCount,
                       titleText, Byte(0x6A3E7A), Byte(0x6DF150), Byte(0x6DF151), raw[0x41A],
                       Byte(0x6995A0), raw[0x8D8], raw[0x8D9], serverCount, servers,
                       keyboardValid && keyboard[0x28] == 1, Byte(0x6436C8), keyboard[0x36],
                       roomList);
        }

        public void Dispose() => CloseHandle(handle);

        [StructLayout(LayoutKind.Sequential)]
        struct MemoryInfo {
            public long BaseAddress, AllocationBase;
            public uint AllocationProtect;
            public ushort PartitionId;
            public nuint RegionSize;
            public uint State, Protect, Type;
        }
        [DllImport("kernel32", SetLastError = true)]
        static extern nint OpenProcess(uint access, bool inherit, int id);
        [DllImport("kernel32")]
        static extern bool CloseHandle(nint handle);
        [DllImport("kernel32")]
        static extern nint VirtualQueryEx(nint process, nint address, out MemoryInfo info, int length);
        [DllImport("kernel32")]
        static extern bool ReadProcessMemory(nint process, nint address, byte[] buffer, int size,
                                             out nint read);
    }
}
