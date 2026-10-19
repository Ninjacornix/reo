using System.IO;
using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher;
static class SelfTest
{
    [StructLayout(LayoutKind.Sequential)] struct XState { public uint Packet; public ushort Buttons; public byte LT, RT; public short LX, LY, RX, RY; }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)] delegate uint GetState(uint index, out XState state);
    [DllImport("kernel32", CharSet = CharSet.Ansi)] static extern nint GetProcAddress(nint module, nint ordinal);
    public static object Probe(Controller controller)
    {
        controller.SessionEnabled = true; controller.Publish();
        Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", controller.MapName);
        nint library = NativeLibrary.Load(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"));
        var get = Marshal.GetDelegateForFunctionPointer<GetState>(GetProcAddress(library, 2));
        uint status = get(0, out var state);
        var result = new { status, packet = state.Packet, buttons = state.Buttons, leftTrigger = state.LT, rightTrigger = state.RT, leftX = state.LX, leftY = state.LY, rightX = state.RX, rightY = state.RY };
        NativeLibrary.Free(library);
        return result;
    }
    public static void Run()
    {
        int checks = 0;
        void Check(bool condition, string message) { if (!condition) throw new Exception(message); checks++; }
        var usb = new byte[64]; usb[0] = 1; Array.Fill(usb, (byte)128, 1, 4); usb[8] = 8;
        Check(Controller.TryParse(usb, 12, out var neutral) && neutral == new Pad(), "USB neutral report");
        usb[8] = 0xF1; usb[9] = 0xF3; usb[5] = 200; usb[6] = 240; usb[1] = 255; usb[2] = 0;
        Check(Controller.TryParse(usb, 12, out var held), "USB held report");
        Check(held.Buttons == 0xF3F9 && held.LT == 200 && held.RT == 240, "Face/dpad/system/shoulder mapping");
        Check(held.LX == 32767 && held.LY == 32767, "Analog extrema and Y orientation");
        var bt = new byte[78]; bt[0] = 0x31; usb.AsSpan(1).CopyTo(bt.AsSpan(2));
        Check(Controller.TryParse(bt, 12, out var bluetooth) && bluetooth == held, "Bluetooth enhanced parity");
        var simple = new byte[] { 1, 128, 128, 128, 128, 0x28, 0x20, 0, 42, 43 };
        Check(Controller.TryParse(simple, 12, out var basic) && basic.Buttons == 0x1010 && basic.LT == 42 && basic.RT == 43, "Bluetooth simple report");
        Check(!Controller.TryParse(new byte[3], 12, out _), "Truncated report rejected");
        usb[0] = 0x55; Check(!Controller.TryParse(usb, 12, out _), "Foreign report rejected");
        var inside = InputMapping.FilterStick(1500, 1500, 12);
        Check(inside == (0, 0), "Circular dead zone removes small diagonal drift");
        var beyond = InputMapping.FilterStick(4000, 4000, 12);
        Check(beyond.X > 0 && beyond.X == beyond.Y && beyond.X < 4000, "Circular boundary keeps direction and rescales");
        var maximum = InputMapping.FilterStick(32767, 0, 30);
        Check(maximum == (32767, 0), "Dead zone preserves full travel");
        var profile = new PadProfile(); profile.Buttons["Cross"] = 0x2000; profile.Buttons["Circle"] = 0;
        profile.Buttons["R2"] = InputMapping.LeftTrigger;
        var remapped = InputMapping.RemapPad(new(0x2000, 123, 0, 20000, 0), profile);
        Check(remapped.Buttons == 0x1000 && remapped.RT == 123, "Remap buttons and analog triggers without leaking old binding");
        profile.SwapSticks = true; profile.InvertRightY = true;
        var swapped = InputMapping.RemapPad(new(0, 0, 0, 0, 20000), profile);
        Check(swapped.LY == 0 && swapped.RY < 0, "Stick swap and right Y inversion");
        var keyboard = InputMapping.KeyboardDefaults(); keyboard["Cross"] = 'K';
        var keys = InputMapping.Keyboard(keyboard, k => k == 'K' || k == 'W');
        Check(keys.Buttons == 0x1001 && keys.LY == 32767, "Keyboard remap and movement");
        Check(InputMapping.Keyboard(keyboard, k => k == 'W' || k == 'S').LY == 0, "Opposite keyboard movement cancels");
        keyboard["Cross"] = 0;
        Check(InputMapping.Keyboard(keyboard, k => k == 'K').Buttons == 0, "Cleared key cannot produce stale action");
        Pad? simulatedXbox = new Pad(0x4000, 77, 89, 16384, -16384);
        using (var devices = new Controller(slot => slot == 2 ? simulatedXbox : null))
        {
            var config = new Settings { InputDeviceId = "xbox:2" };
            devices.Configure(config); devices.Poll();
            Check(devices.AvailableDevices.Count == 2 && devices.XboxCount == 1 && devices.SelectedDevice.Kind == "xbox", "Detect connected Xbox slot and keyboard without phantom slots");
            Check(devices.RawState == simulatedXbox && devices.State.Buttons == 0x4000 && devices.State.LT == 77, "Selected Xbox state reaches normalized game input");
            simulatedXbox = null; devices.Poll();
            Check(!devices.Connected && devices.State == new Pad(), "Selected Xbox disconnect releases controls without falling back");
            simulatedXbox = new Pad(0x1000); devices.Select("keyboard"); devices.Poll();
            Check(devices.State.Buttons != 0x1000 && devices.SelectedDevice.Kind == "keyboard", "Keyboard selection ignores unselected Xbox");
            config.Xbox.Buttons["Cross"] = 0x4000;
            string json = JsonSerializer.Serialize(config);
            var restored = JsonSerializer.Deserialize<Settings>(json)!;
            Check(restored.InputDeviceId == "keyboard" && restored.Xbox.Buttons["Cross"] == 0x4000, "Selection and independent layouts persist");
        }
        var games = new Settings { Exe = "first.exe", Iso = "first.iso", SecondExe = "second.exe", SecondIso = "second.iso", SelectedGame = "file2" };
        Check(games.GetExe() == "second.exe" && games.GetIso() == "second.iso" && games.GetElf("C:\\games").EndsWith("game_data_file2\\SLUS_209.84"), "Game selection uses independent executable, ISO and ELF");
        Check(GameSession.SaveFolder("C:\\games", "file1") != GameSession.SaveFolder("C:\\games", "file2"), "Games never share memory-card folders");
        games.SelectedGame = "file1";
        Check(games.GetExe() == "first.exe" && games.GetIso() == "first.iso", "Switching back preserves first game configuration");
        string logFixture = Path.GetTempFileName();
        try
        {
            File.WriteAllText(logFixture, string.Concat(Enumerable.Repeat("earlier diagnostic row\n", 1000)) + "last diagnostic row\n");
            string tail = LogTail.Read(logFixture, 512);
            Check(tail.Length <= 512 && tail.EndsWith("last diagnostic row\n"), "Debug log tail is bounded and includes latest complete row");
            File.WriteAllText(logFixture, new string('x', 4096));
            Check(LogTail.Read(logFixture, 512).Length == 512, "Long unbroken diagnostic line stays visible");
            using var writer = new FileStream(logFixture, FileMode.Open, FileAccess.Write, FileShare.ReadWrite);
            Check(LogTail.Read(logFixture, 512).Length == 512, "Tail can read while the game writer holds its file");
        }
        finally { File.Delete(logFixture); }
        string name = "Local\\REO-Test-" + Guid.NewGuid().ToString("N");
        using var map = MemoryMappedFile.CreateNew(name, 64); using var view = map.CreateViewAccessor();
        view.Write(0, Controller.Magic); view.Write(4, 2); view.Write(8, 1); view.Write(12, unchecked((uint)Environment.TickCount));
        view.Write(16, 123u); view.Write(20, held.Buttons); view.Write(22, held.LT); view.Write(23, held.RT); view.Write(24, held.LX); view.Write(26, held.LY);
        Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", name);
        nint library = NativeLibrary.Load(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"));
        nint function = GetProcAddress(library, 2);
        Check(function != 0 && function == NativeLibrary.GetExport(library, "XInputGetState"), "Game import ordinal2 matches named export");
        var get = Marshal.GetDelegateForFunctionPointer<GetState>(function);
        Check(get(0, out var result) == 0 && result.Packet == 123 && result.Buttons == held.Buttons && result.LX == held.LX && result.LY == held.LY, "C# shared memory -> native XInput ABI");
        view.Write(12, unchecked((uint)Environment.TickCount - 1000));
        Check(get(0, out var stale) == 0 && stale.Buttons == 0 && stale.LX == 0, "Stale producer releases held controls");
        view.Write(12, unchecked((uint)Environment.TickCount));
        Check(get(0, out var resumed) == 0 && resumed.Buttons == held.Buttons, "Reconnect resumes without game reinitialization");
        Directory.CreateDirectory(Path.Combine(AppContext.BaseDirectory, "test-results"));
        File.WriteAllText(Path.Combine(AppContext.BaseDirectory, "test-results", "self-test.json"), JsonSerializer.Serialize(new { passed = true, checks }));
        NativeLibrary.Free(library);
    }
}
