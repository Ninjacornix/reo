using System.IO;
using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal static class ControllerInputTests {
    [StructLayout(LayoutKind.Sequential)]
    struct State {
        public uint Packet;
        public ushort Buttons;
        public byte LT, RT;
        public short LX, LY, RX, RY;
        public readonly Pad Pad => new(Buttons, LT, RT, LX, LY, RX, RY);
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetState(uint index, out State state);

    internal static void Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-input-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        string? previous = Environment.GetEnvironmentVariable("REO_LAUNCHER_PAD_MAP");
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                Pad? physical = new(0x2000, 91, 182, 16384, -8192, -12000, 20000);
                var settings = new Settings { SelectedGame = game, InputDeviceId = "xbox:2" };
                settings.Xbox.Buttons["Cross"] = 0x2000;
                settings.Xbox.Buttons["Circle"] = 0;
                settings.Xbox.SwapSticks = true;
                settings.Xbox.InvertRightY = true;
                using var controller = new Controller(slot => slot == 2 ? physical : null);
                controller.Configure(settings);
                controller.SessionEnabled = true;
                controller.Publish();
                string dll = Path.Combine(root, game + ".dll");
                File.Copy(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"), dll);
                Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", controller.MapName);
                nint library = NativeLibrary.Load(dll);
                try {
                    var get = Marshal.GetDelegateForFunctionPointer<GetState>(NativeLibrary.GetExport(library, "XInputGetState"));
                    check(get(0, out var initial) == 0 && initial.Pad == controller.State
                          && initial.Buttons == 0x1000 && initial.LT == 91 && initial.RT == 182
                          && initial.LX < 0 && initial.LY > 0 && initial.RX > 0 && initial.RY > 0,
                          game + " selected pad remapping, triggers, dead zone and stick options reach native XInput");
                    check(get(1, out var other) == 1167 && other.Pad == new Pad(),
                          game + " unselected physical ports are hidden from the game");
                    controller.SessionEnabled = false;
                    controller.Publish();
                    check(get(0, out var disabled) == 0 && disabled.Pad == new Pad(),
                          game + " disabled input remains neutral without native keyboard or physical fallback");
                    controller.SessionEnabled = true;
                    controller.Publish();
                    check(get(0, out var resumed) == 0 && resumed.Buttons == 0x1000,
                          game + " session resumes without reconnecting the logical pad");
                    physical = null;
                    controller.Publish();
                    check(get(0, out var unplugged) == 0 && unplugged.Pad == new Pad(),
                          game + " unplug releases every button, trigger and stick");
                    physical = new(0x2000);
                    // Discovery intentionally runs every 500 ms; no game restart is needed.
                    Thread.Sleep(510);
                    controller.Publish();
                    check(get(0, out var reconnected) == 0 && reconnected.Buttons == 0x1000,
                          game + " selected physical controller reconnects through the same native adapter");
                    settings.Xbox.SwapSticks = false;
                    settings.Xbox.InvertRightY = false;
                    controller.Configure(settings);
                    foreach (ushort direction in new ushort[] { 1, 2, 4, 8, 5, 9, 6, 10 }) {
                        physical = new(direction);
                        controller.Publish();
                        check(get(0, out var digital) == 0 && digital.Buttons == direction &&
                              digital.LX == 0 && digital.LY == 0 && digital.RX == 0 && digital.RY == 0,
                              game + " D-pad direction " + direction + " keeps both sticks neutral");
                    }
                    physical = new(0, 0, 0, 20000, -20000);
                    controller.Publish();
                    check(get(0, out var analog) == 0 && analog.Buttons == 0 &&
                          analog.LX > 0 && analog.LY < 0,
                          game + " analog movement remains independent from digital directions");
                    physical = new(4, 0, 0, 20000, -20000);
                    controller.Publish();
                    check(get(0, out var mixed) == 0 && mixed.Buttons == 4 &&
                          mixed.LX == analog.LX && mixed.LY == analog.LY,
                          game + " simultaneous D-pad and stick preserve both inputs");
                    using var map = MemoryMappedFile.OpenExisting(controller.MapName);
                    using var view = map.CreateViewAccessor();
                    view.Write(0, 0u);
                    check(get(0, out var invalid) == 0 && invalid.Pad == new Pad(),
                          game + " invalid private feed cannot select a different controller");
                } finally { NativeLibrary.Free(library); }
            }
        } finally {
            Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", previous);
            Directory.Delete(root, true);
        }
    }
}
