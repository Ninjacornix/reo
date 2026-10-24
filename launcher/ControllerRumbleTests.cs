using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices;
using System.Buffers.Binary;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class ControllerRumbleTests {
    [StructLayout(LayoutKind.Sequential)]
    struct Vibration {
        public ushort Left, Right;
    }
    [StructLayout(LayoutKind.Sequential)]
    struct Capabilities {
        public byte Type, SubType;
        public ushort Flags, Buttons;
        public byte LT, RT;
        public short LX, LY, RX, RY;
        public ushort Left, Right;
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint SetState(uint index, ref Vibration vibration);
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint SetNull(uint index, nint vibration);
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetCapabilities(uint index, uint flags, out Capabilities caps);
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetNullCapabilities(uint index, uint flags, nint caps);

    internal static void Run(Action<bool, string> check) {
        check(JsonSerializer.Deserialize<Settings>("{}")!.RumbleEnabled &&
              !JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                  new Settings { RumbleEnabled = false }))!.RumbleEnabled,
              "Rumble defaults on for existing settings and an off preference survives reload");
        var hardware = new List<PadRumble>();
        var config = new Settings { InputDeviceId = "xbox:2" };
        using (var controller = new Controller(slot => slot == 2 ? new Pad(0x1000) : null,
                                               (_, left, right) => hardware.Add(new(left, right)))) {
            controller.Configure(config);
            controller.SessionEnabled = true;
            using var gameMap = MemoryMappedFile.OpenExisting(controller.MapName);
            using var gameOutput = gameMap.CreateViewAccessor();
            gameOutput.Write(36, 2);
            gameOutput.Write(40, unchecked((uint)Environment.TickCount));
            gameOutput.Write(44, (ushort)24000); gameOutput.Write(46, (ushort)36000);
            controller.Publish();
            check(hardware[^1] == new PadRumble(24000, 36000),
                  "Enabled controller receives the current game's effect");
            config.RumbleEnabled = false;
            controller.Publish();
            check(hardware[^1] == new PadRumble() && controller.State.Buttons == 0x1000,
                  "Disabling rumble stops active motors immediately while input still works");
            config.RumbleEnabled = true;
            gameOutput.Write(36, 4); gameOutput.Write(40, unchecked((uint)Environment.TickCount));
            controller.Publish();
            check(hardware[^1] == new PadRumble(24000, 36000),
                  "Re-enabling rumble uses a fresh game effect without restarting");
        }
        using var map = MemoryMappedFile.CreateNew(null, 64);
        using var view = map.CreateViewAccessor();
        view.Write(32, ControllerRumble.Magic);
        view.Write(36, 2); view.Write(40, 1000u); view.Write(44, (ushort)1234); view.Write(46, (ushort)5678);
        var expected = new PadRumble(1234, 5678);
        check(ControllerRumble.Read(view, true, 1000) == expected,
              "Fresh native motor request keeps independent left and right magnitudes");
        check(ControllerRumble.Read(view, false, 1000) == new PadRumble() &&
              ControllerRumble.Read(view, true, 1751) == new PadRumble(),
              "Disabled sessions and missing game heartbeats stop vibration");
        check(ControllerRumble.Read(view, true, 1750) == expected,
              "Rumble freshness includes the exact timeout boundary");
        view.Write(40, uint.MaxValue - 9);
        check(ControllerRumble.Read(view, true, 10) == expected,
              "Native tick wrap does not interrupt a current effect");
        view.Write(40, 1000u);
        check(ControllerRumble.Read(view, true, 1000, 2) == new PadRumble(),
              "A newly started game cannot inherit the previous game's effect");
        view.Write(36, 4);
        check(ControllerRumble.Read(view, true, 1000, 2) == expected,
              "New game heartbeat releases the previous-session sequence guard");
        view.Write(36, 5);
        check(ControllerRumble.Read(view, true, 1000) == new PadRumble(),
              "In-progress native output writes are never sent to hardware");
        view.Write(36, 6); view.Write(32, 0u);
        check(ControllerRumble.Read(view, true, 1000) == new PadRumble(),
              "Legacy input-only mappings have no rumble output");

        var sent = new List<(uint Slot, ushort Left, ushort Right)>();
        using (var router = new ControllerRumble((slot, left, right) => sent.Add((slot, left, right)))) {
            router.Update(new("xbox:2", "third pad", "xbox"), expected);
            check(sent.SequenceEqual(new[] { (2u, (ushort)1234, (ushort)5678) }),
                  "Logical pad zero routes rumble to the selected physical Xbox slot");
            router.Update(new("xbox:2", "third pad", "xbox"), expected);
            check(sent.Count == 1, "Unchanged Xbox output does not flood the driver");
            router.Update(new("xbox:1", "second pad", "xbox"), expected);
            check(sent.TakeLast(2).SequenceEqual(new[] { (2u, (ushort)0, (ushort)0), (1u, (ushort)1234, (ushort)5678) }),
                  "Switching Xbox slots first stops the old controller");
            router.Update(new("xbox:1", "disconnected", "xbox", false), expected);
            check(sent[^1] == (1u, 0, 0), "Disconnect releases the previously selected motors");
            int count = sent.Count;
            router.Update(new("ps:test", "DualSense", "playstation"), expected);
            router.Update(new("keyboard", "Keyboard", "keyboard"), expected);
            check(sent.Count == count, "DualSense and keyboard never rumble an unrelated Xbox pad");
            router.Update(new("xbox:3", "fourth pad", "xbox"), expected);
            router.CheckTimeout(Environment.TickCount64 + ControllerRumble.Timeout + 1);
            check(sent[^1] == (3u, 0, 0), "Xbox watchdog stops hardware even when launcher publishing stalls");
            router.Update(new("xbox:3", "fourth pad", "xbox"), expected);
        }
        check(sent[^1] == (3u, 0, 0), "Controller disposal stops the selected Xbox motors");

        var target = new DualSenseLight.Target("test", false, PadLight.Green, expected, 1000);
        check(DualSenseLight.Current(target, 1750)?.Rumble == expected &&
              DualSenseLight.Current(target, 1751) is { Rumble: var stoppedMotors, Color: var color } &&
              stoppedMotors == new PadRumble() && color == PadLight.Green,
              "DualSense worker independently stops stale UI output while retaining the health colour");

        var usb = DualSenseLight.Report(false, new(17, 34, 51), rumble: new PadRumble(65535, 32768));
        var bytes = new byte[48]; bytes[0] = 2; bytes[1] = 3; bytes[2] = 4;
        bytes[3] = 64; bytes[4] = 127; bytes[45] = 17; bytes[46] = 34; bytes[47] = 51;
        check(usb.SequenceEqual(bytes),
              "DualSense USB combines both motors and health colour without trigger or audio-setting writes");
        var stopped = DualSenseLight.Report(false, PadLight.Red, rumble: new PadRumble());
        check(stopped[1] == 3 && stopped[3] == 0 && stopped[4] == 0 && stopped[45] == 255,
              "DualSense stop explicitly clears motors while preserving the health light");
        var bt = DualSenseLight.Report(true, new(17, 34, 51), rumble: new PadRumble(65535, 32768));
        check(bt.Length == 78 && bt[2] == 3 && bt[3] == 4 && bt[4] == 64 && bt[5] == 127 &&
              bt[46] == 17 && bt[47] == 34 && bt[48] == 51 &&
              BinaryPrimitives.ReadUInt32LittleEndian(bt.AsSpan(74)) == 0x72a25cd6u,
              "DualSense Bluetooth motor/colour report matches an independent CRC fixture");
    }

    internal static void RunNative(Action<bool, string> check, nint library, MemoryMappedViewAccessor view) {
        view.Write(32, ControllerRumble.Magic);
        var set = Marshal.GetDelegateForFunctionPointer<SetState>(NativeLibrary.GetExport(library, "XInputSetState"));
        var setNull = Marshal.GetDelegateForFunctionPointer<SetNull>(NativeLibrary.GetExport(library, "XInputSetState"));
        var caps = Marshal.GetDelegateForFunctionPointer<GetCapabilities>(NativeLibrary.GetExport(library, "XInputGetCapabilities"));
        var nullCaps = Marshal.GetDelegateForFunctionPointer<GetNullCapabilities>(NativeLibrary.GetExport(library, "XInputGetCapabilities"));
        var vibration = new Vibration { Left = 0x9a00, Right = 0x3400 };
        var input = new byte[32]; view.ReadArray(0, input, 0, input.Length);
        check(set(0, ref vibration) == 0 &&
              ControllerRumble.Read(view, true, unchecked((uint)Environment.TickCount)) == new PadRumble(0x9a00, 0x3400),
              "Native XInputSetState publishes the C# rumble ABI with a current heartbeat");
        var after = new byte[32]; view.ReadArray(0, after, 0, after.Length);
        check(input.SequenceEqual(after), "Native rumble output leaves controller input bytes unchanged");
        check(caps(0, 0, out var info) == 0 && info.Flags == 1 && info.Left == 65535 && info.Right == 65535,
              "Native controller capabilities advertise both force-feedback motors");
        check(setNull(0, 0) == 160 && nullCaps(0, 0, 0) == 160,
              "Native vibration and capabilities reject null pointers");
        int sequence = view.ReadInt32(36);
        check(set(1, ref vibration) == 1167 && view.ReadInt32(36) == sequence,
              "A private logical-pad request never reaches another physical controller");
        view.Write(8, 0u);
        check(set(0, ref vibration) == 0 &&
              ControllerRumble.Read(view, true, unchecked((uint)Environment.TickCount)) == new PadRumble(),
              "Disabled private input writes a motor stop without physical fallback");
        view.Write(8, 1u); view.Write(12, unchecked((uint)Environment.TickCount - 1000));
        check(set(0, ref vibration) == 0 &&
              ControllerRumble.Read(view, true, unchecked((uint)Environment.TickCount)) == new PadRumble(),
              "Stalled launcher input cannot retain active rumble");
        view.Write(12, unchecked((uint)Environment.TickCount));
        check(set(0, ref vibration) == 0 &&
              ControllerRumble.Read(view, true, unchecked((uint)Environment.TickCount)) == new PadRumble(0x9a00, 0x3400),
              "Native game heartbeat resumes rumble after a temporary input stall");
    }
}
