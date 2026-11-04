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
        check(RawInputPads.Model(0x054c, 0x0ce6, 1, 5) == PadModel.DualSense &&
                  RawInputPads.Model(0x054c, 0x0df2, 1, 4) == PadModel.DualSense,
              "DualSense and Edge match numeric HID IDs regardless of USB/Bluetooth path syntax");
        check(RawInputPads.Model(0x054c, 0x05c4, 1, 5) == PadModel.DualShock4 &&
                  RawInputPads.Model(0x054c, 0x09cc, 1, 4) == PadModel.DualShock4,
              "Both DualShock 4 revisions match their numeric HID IDs");
        check(RawInputPads.Model(0x045e, 0x0ce6, 1, 5) == null &&
                  RawInputPads.Model(0x054c, 0x0268, 1, 4) == null &&
                  RawInputPads.Model(0x054c, 0x0ce6, 12, 1) == null,
              "Foreign devices and non-gamepad HID collections are excluded");
        const string btPath = @"\\?\HID#{00001124-0000-1000-8000-00805f9b34fb}_VID&0002054C_PID&0CE6#test";
        check(RawInputPads.Transport(btPath) == "Bluetooth", "Bluetooth path does not need USB VID_ and PID_ tokens");
        long now = 0;
        var device = new RawInputPads.Device(42, btPath, "Bluetooth", PadModel.DualSense);
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
        check(Controller.TryParse(simple, PadModel.DualSense, 0, out var expected) &&
                  Controller.TryParse(padded, PadModel.DualSense, 0, out var expanded) &&
                  expanded == expected && expanded.Buttons == 0x1019 && expanded.LT == 91 &&
                  expanded.RT == 182,
              "Padded 78-byte basic Bluetooth packet uses the same controls as its 10-byte form");
        // The same 64-byte USB report 0x01 has DualSense triggers where DualShock 4 has buttons.
        var ds4Usb = new byte[64];
        simple.CopyTo(ds4Usb, 0);
        var ds4Bt = new byte[78];
        ds4Bt[0] = 0x11;
        ds4Bt[1] = 0xc0;
        simple.AsSpan(1).CopyTo(ds4Bt.AsSpan(3));
        var ds4Padded = new byte[547];
        ds4Bt.CopyTo(ds4Padded, 0);
        check(new[] { simple, ds4Usb, ds4Bt, ds4Padded }.All(
                  r => Controller.TryParse(r, PadModel.DualShock4, 0, out var pad) &&
                       pad == expected),
              "DualShock 4 USB, basic and padded Bluetooth reports use its compact layout");
        var noControls = (byte[])ds4Bt.Clone();
        noControls[1] = 0x40;
        check(!Controller.TryParse(noControls, PadModel.DualShock4, 0, out _),
              "DualShock 4 Bluetooth reports without controller data are ignored");
        var ds4 = new RawInputPads.Device(44, @"\\?\HID#VID_054C&PID_09CC&MI_03#test", "Unknown",
                                          PadModel.DualShock4);
        using (var pads = new Controller(
                   _ => null, (_, _, _) => {}, () => new(new() { 44 }, new() { ds4 }), () => 0)) {
            pads.Configure(new Settings());
            pads.Poll();
            check(pads.AcceptReport(44, ds4Usb) && pads.SelectedDevice.Name == "DualShock 4 (USB)",
                  "DualShock 4 is listed by name with its USB transport");
            pads.SessionEnabled = true;
            pads.Publish();
            Thread.Sleep(100);
            check(pads.RawState == expected && pads.LastDualSenseOutput == null,
                  "DualShock 4 controls are published without DualSense light or rumble writes");
            check(pads.AcceptReport(44, ds4Padded) &&
                      pads.SelectedDevice.Name == "DualShock 4 (Bluetooth)",
                  "Padded 547-byte Bluetooth report is not mistaken for USB");
        }
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
                if (Controller.TryParse(truncated, PadModel.DualSense, 0, out _))
                    throw new IOException("Truncated enhanced Bluetooth packet accepted");
                if (length > 0)
                    truncated[0] = 0x11;
                if (length > 1)
                    truncated[1] = 0xc0;
                if (Controller.TryParse(truncated, PadModel.DualShock4, 0, out _))
                    throw new IOException("Truncated DualShock 4 Bluetooth packet accepted");
            }
            check(true, "All truncated enhanced and DualShock 4 Bluetooth lengths are rejected");
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
