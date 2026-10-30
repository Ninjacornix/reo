using System.IO;
using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;
internal static class ControllerDiscoveryTests {
    [StructLayout(LayoutKind.Sequential)]
    struct XState {
        public uint Packet; public ushort Buttons; public byte LT, RT;
        public short LX, LY, RX, RY;
        public readonly Pad Pad => new(Buttons, LT, RT, LX, LY, RX, RY);
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetState(uint index, out XState state);

    internal static void Run(Action<bool, string> check) {
        check(RawInputPads.Supported(0x054c, 0x0ce6, 1, 5) && RawInputPads.Supported(0x054c, 0x0df2, 1, 4),
              "DualSense and Edge match numeric HID IDs regardless of USB/Bluetooth path syntax");
        check(!RawInputPads.Supported(0x045e, 0x0ce6, 1, 5) && !RawInputPads.Supported(0x054c, 0x05c4, 1, 5) &&
              !RawInputPads.Supported(0x054c, 0x0ce6, 12, 1), "Foreign devices and non-gamepad HID collections are excluded");
        const string btPath = @"\\?\HID#{00001124-0000-1000-8000-00805f9b34fb}_VID&0002054C_PID&0CE6#test";
        check(RawInputPads.Transport(btPath) == "Bluetooth", "Bluetooth path does not need USB VID_ and PID_ tokens");
        long now = 0;
        var device = new RawInputPads.Device(42, btPath, "Bluetooth");
        RawInputPads.Snapshot? snapshot = new(new() { 42 }, new() { device });
        using var controller = new Controller(_ => null, (_, _, _) => { }, () => snapshot, () => now);
        var settings = new Settings { InputDeviceId = "xbox:2" }; controller.Configure(settings); controller.Poll();
        string id = "ps:" + btPath;
        check(controller.AvailableDevices.Any(d => d.Id == id), "Connected DualSense is listed before its first input report");
        check(!controller.SelectedDevice.Available && controller.SelectedDevice.Id == "xbox:2",
              "Saved disconnected Xbox selection is preserved while DualSense is independently discovered");
        controller.Select(id); controller.Poll();
        check(controller.SelectedDevice.Available && controller.RawState == new Pad(), "Newly discovered idle controller starts neutral");
        now += 10000; controller.Poll();
        check(controller.SelectedDevice.Available, "Ten seconds without reports does not disconnect a physically present DualSense");

        var simple = new byte[] { 1, 255, 0, 128, 128, 0x21, 0x20, 0, 91, 182 };
        var padded = new byte[78]; simple.CopyTo(padded, 0);
        check(Controller.TryParse(simple, 0, out var expected) && Controller.TryParse(padded, 0, out var expanded) && expanded == expected &&
              expanded.Buttons == 0x1019 && expanded.LT == 91 && expanded.RT == 182,
              "Padded 78-byte basic Bluetooth packet uses the same controls as its 10-byte form");
        var usb = new byte[64]; usb[0] = 1; simple.AsSpan(1, 4).CopyTo(usb.AsSpan(1));
        usb[5] = 91; usb[6] = 182; usb[8] = 0x21; usb[9] = 0x20;
        var enhanced = new byte[78]; enhanced[0] = 0x31; usb.AsSpan(1).CopyTo(enhanced.AsSpan(2));
        string root = Path.Combine(Path.GetTempPath(), "reo-bt-input-" + Guid.NewGuid().ToString("N")); Directory.CreateDirectory(root);
        string? previous = Environment.GetEnvironmentVariable("REO_LAUNCHER_PAD_MAP");
        nint library = 0;
        try {
            string dll = Path.Combine(root, "XINPUT1_4.dll"); File.Copy(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"), dll);
            Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", controller.MapName); library = NativeLibrary.Load(dll);
            var get = Marshal.GetDelegateForFunctionPointer<GetState>(NativeLibrary.GetExport(library, "XInputGetState"));
            controller.SessionEnabled = true;
            foreach (var report in new[] { simple, padded, usb, enhanced }) {
                check(controller.AcceptReport(42, report), "Known physical device accepts its USB/basic/enhanced report");
                controller.Publish();
                check(get(0, out var state) == 0 && state.Pad == controller.State && state.Buttons == 0x1019 && state.LT == 91 && state.RT == 182,
                      "USB/basic/enhanced Bluetooth controls pass through the actual native XInput adapter");
            }
            check(!controller.AcceptReport(99, simple) && !controller.AcceptReport(42, new byte[11]), "Unknown device and truncated reports cannot change selected input");
            for (int length = 0; length < 78; length++) {
                var truncated = new byte[length]; if (length > 0) truncated[0] = 0x31;
                if (Controller.TryParse(truncated, 0, out _)) throw new IOException("Truncated enhanced Bluetooth packet accepted");
            }
            check(true, "All truncated enhanced Bluetooth lengths are rejected");
            snapshot = null; now += 10000; controller.Poll();
            check(controller.SelectedDevice.Available, "Transient Windows enumeration error does not remove the controller");
            snapshot = new(new() { 42 }, new()); now += 500; controller.Poll();
            check(controller.SelectedDevice.Available, "A present handle survives a transient HID metadata lookup failure");
            snapshot = new(new(), new()); now += 500; controller.Publish();
            check(!controller.SelectedDevice.Available && controller.State == new Pad() && get(0, out var unplugged) == 0 && unplugged.Pad == new Pad(),
                  "Physical removal releases all buttons, triggers and axes through native XInput");
            device = device with { Handle = 43 }; snapshot = new(new() { 43 }, new() { device }); now += 500; controller.Publish();
            check(controller.SelectedDevice.Available && controller.State == new Pad(), "Same selected controller reconnects with a new handle and no stale held input");
            check(controller.AcceptReport(43, padded), "Reconnected Bluetooth controller accepts its first basic report");
            controller.Publish(); check(get(0, out var resumed) == 0 && resumed.Buttons == 0x1019, "Bluetooth reconnect resumes the native adapter without restarting the game");
        } finally {
            if (library != 0) NativeLibrary.Free(library);
            Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", previous);
            Directory.Delete(root, true);
        }
    }
}
