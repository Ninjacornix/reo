using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

public record InputDevice(string Id, string Name, string Kind, bool Available = true) {
    public override string ToString() => Name;
}
public sealed class PadProfile {
    public int DeadZone { get; set; } = 12;
    public bool SwapSticks { get; set; }
    public bool InvertRightY { get; set; }
    public Dictionary<string, int> Buttons { get; set; } = InputMapping.PadDefaults();
}
public static partial class InputMapping {
    public const int LeftTrigger = 0x10000, RightTrigger = 0x20000;
    public static readonly(string Id, string Label, int Code)[] Actions = {
        ("Up", "D-pad up", 1),        ("Down", "D-pad down", 2),
        ("Left", "D-pad left", 4),    ("Right", "D-pad right", 8),
        ("Cross", "Cross", 0x1000),   ("Circle", "Circle", 0x2000),
        ("Square", "Square", 0x4000), ("Triangle", "Triangle", 0x8000),
        ("L1", "L1", 0x100),          ("R1", "R1", 0x200),
        ("L2", "L2", LeftTrigger),    ("R2", "R2", RightTrigger),
        ("Start", "Start", 0x10),     ("Select", "Select", 0x20),
        ("L3", "L3", 0x40),           ("R3", "R3", 0x80)
    };
    public static readonly(string Id, string Label)[] Camera = {
        ("CameraUp", "Right stick up"), ("CameraDown", "Right stick down"),
        ("CameraLeft", "Right stick left"), ("CameraRight", "Right stick right")
    };
    public static Dictionary<string, int> PadDefaults() => Actions.ToDictionary(a => a.Id,
                                                                                a => a.Code);
    public static Dictionary<string, int> KeyboardDefaults() =>
        new() { ["Up"] = 'W',      ["Down"] = 'S',      ["Left"] = 'A',      ["Right"] = 'D',
                ["Cross"] = 32,    ["Circle"] = 'E',    ["Square"] = 'Q',    ["Triangle"] = 'R',
                ["L1"] = '1',      ["R1"] = '2',        ["L2"] = '3',        ["R2"] = '4',
                ["Start"] = 13,    ["Select"] = 8,      ["L3"] = 'Z',        ["R3"] = 'X',
                ["CameraUp"] = 38, ["CameraDown"] = 40, ["CameraLeft"] = 37, ["CameraRight"] = 39 };
    // One keyboard key belongs to one action. In particular, assigning arrows to
    // the D-pad must release the old right-stick/voice-command binding.
    public static string[] BindKeyboard(Dictionary<string,int> bindings,string action,int key) {
        if (!Actions.Any(a => a.Id == action) && !Camera.Any(a => a.Id == action))
            throw new ArgumentException("Unknown keyboard action.", nameof(action));
        if (key < 0 || key > 255) throw new ArgumentOutOfRangeException(nameof(key));
        var conflicts = key == 0 ? Array.Empty<string>() : bindings
            .Where(pair => pair.Key != action && pair.Value == key).Select(pair => pair.Key).ToArray();
        foreach (string conflict in conflicts) bindings[conflict] = 0;
        bindings[action] = key;
        return conflicts;
    }
    public static HashSet<int> Pressed(Pad pad) {
        var result = Actions.Where(a => a.Code < LeftTrigger && (pad.Buttons & a.Code) != 0)
                         .Select(a => a.Code)
                         .ToHashSet();
        if (pad.LT > 30)
            result.Add(LeftTrigger);
        if (pad.RT > 30)
            result.Add(RightTrigger);
        return result;
    }
    public static bool ActionPressed(Pad mapped, string action) => action switch {
        "CameraUp" => mapped.RY > 0,
        "CameraDown" => mapped.RY < 0,
        "CameraLeft" => mapped.RX < 0,
        "CameraRight" => mapped.RX > 0,
        "L2" => mapped.LT > 30,
        "R2" => mapped.RT > 30,
        _ => Actions.Any(a => a.Id == action && a.Code < LeftTrigger &&
                             (mapped.Buttons & a.Code) != 0)
    };
    public static (short X, short Y) FilterStick(short x, short y, int percent) {
        double magnitude = Math.Sqrt((double)x * x + (double)y * y);
        double threshold = Math.Clamp(percent, 0, 30) * 32767.0 / 100;
        if (magnitude <= threshold || magnitude == 0)
            return (0, 0);
        // Circular dead zone, continuous rescaling, preserves direction.
        double output = (Math.Min(magnitude, 32767) - threshold) / (32767 - threshold) * 32767;
        return ((short)Math.Clamp(Math.Round(x / magnitude * output), -32768, 32767),
                (short)Math.Clamp(Math.Round(y / magnitude * output), -32768, 32767));
    }
    static byte SourceAmount(Pad raw, int code) => code switch {
        0 => 0, LeftTrigger => raw.LT, RightTrigger => raw.RT,
        _ => (raw.Buttons & code) != 0 ? (byte)255 : (byte)0
    };
    public static Pad RemapPad(Pad raw, PadProfile profile) {
        ushort buttons = 0;
        byte lt = 0, rt = 0;
        foreach (var target in Actions) {
            if (!profile.Buttons.TryGetValue(target.Id, out int source))
                continue;
            byte amount = SourceAmount(raw, source);
            if (target.Code == LeftTrigger)
                lt = amount;
            else if (target.Code == RightTrigger)
                rt = amount;
            else if (amount > 30)
                buttons |= (ushort)target.Code;
        }
        var left = FilterStick(raw.LX, raw.LY, profile.DeadZone);
        var right = FilterStick(raw.RX, raw.RY, profile.DeadZone);
        if (profile.SwapSticks)
            (left, right) = (right, left);
        if (profile.InvertRightY)
            right.Y = (short)Math.Clamp(-(int)right.Y, -32768, 32767);
        return new(buttons, lt, rt, left.X, left.Y, right.X, right.Y);
    }
    public static Pad Keyboard(Dictionary<string, int> bindings, Func<int, bool> down) {
        ushort buttons = 0;
        byte lt = 0, rt = 0;
        bool Held(string action) =>
            bindings.TryGetValue(action, out int key) && key > 0 && key < 256 &&
            !(key == 13 && (down(17) || down(162) || down(163))) && down(key);
        foreach (var target in Actions) {
            if (!Held(target.Id))
                continue;
            if (target.Code == LeftTrigger)
                lt = 255;
            else if (target.Code == RightTrigger)
                rt = 255;
            else
                buttons |= (ushort)target.Code;
        }
        foreach (ushort pair in new ushort[] { 3, 12 })
            if ((buttons & pair) == pair)
                buttons &= (ushort)~pair;
        short Axis(bool positive, bool negative) => positive == negative ? (short)0
                                                    : positive           ? (short)32767
                                                                         : (short)-32768;
        // D-pad keys are digital PS2 input (tank controls). Mirroring them onto
        // the left stick makes the game select camera-relative analog movement.
        return new(buttons, lt, rt, 0, 0,
                   Axis(Held("CameraRight"), Held("CameraLeft")),
                   Axis(Held("CameraUp"), Held("CameraDown")));
    }
}

// Always load the actual system library: the launcher's directory also contains
// its game-side adapter and must never be used to enumerate physical devices.
public sealed class XboxInput {
    [StructLayout(LayoutKind.Sequential)]
    struct State {
        public uint Packet;
        public ushort Buttons;
        public byte LT, RT;
        public short LX, LY, RX, RY;
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetState(uint slot, out State state);
    [StructLayout(LayoutKind.Sequential)]
    struct Vibration {
        public ushort Left, Right;
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint SetState(uint slot, ref Vibration state);
    readonly GetState get;
    readonly SetState set;
    public XboxInput() {
        nint module = NativeLibrary.Load(
            System.IO.Path.Combine(Environment.SystemDirectory, "xinput1_4.dll"));
        get = Marshal.GetDelegateForFunctionPointer<GetState>(
            NativeLibrary.GetExport(module, "XInputGetState"));
        set = Marshal.GetDelegateForFunctionPointer<SetState>(
            NativeLibrary.GetExport(module, "XInputSetState"));
    }
    public Pad? Read(uint slot) => get(slot, out var state) == 0
                                       ? new Pad(state.Buttons, state.LT, state.RT, state.LX,
                                                 state.LY, state.RX, state.RY)
                                       : null;
    public void Rumble(uint slot, ushort left, ushort right) {
        var value = new Vibration { Left = left, Right = right };
        set(slot, ref value);
    }
}

public sealed class FullscreenChord {
    bool reserved;
    public bool SuppressEnter(bool enter, bool control) {
        if (!enter)
            reserved = false;
        else if (control)
            reserved = true;
        return reserved;
    }
}
