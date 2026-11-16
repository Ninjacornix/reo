using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices;
using HwndSource = Outbreak.Launcher.NativeWindowMessages;

namespace Outbreak.Launcher;

public sealed partial class Controller : IDisposable {
    public const uint Magic = 0x52454F50;
    public readonly string MapName = "Local\\REO-Pad-" + Guid.NewGuid().ToString("N");
    readonly MemoryMappedFile map;
    readonly MemoryMappedViewAccessor view;
    HwndSource? source;
    int sequence;
    uint packet;
    Pad lastPublished = new();
    string lastPublishedDevice = "";
    readonly DualSenseLight light = new();
    readonly ControllerRumble rumble;
    volatile bool sessionEnabled;
    int rumbleSessionStart;
    internal sealed record RumbleObservation(bool Enabled, string Device, bool Available,
                                             PadRumble Requested);
    RumbleObservation rumbleObservation = new(false, "", false, new());
    internal RumbleObservation RumbleOutput => Volatile.Read(ref rumbleObservation);
    internal DualSenseLight.Output? LastDualSenseOutput => light.LastOutput;
    int healthLight = 0x0040ff;
    internal void SetHealthLight(PadLight color) =>
        Interlocked.Exchange(ref healthLight, (color.R << 16) | (color.G << 8) | color.B);
    public Pad State { get; private set; } = new();
    public bool Connected => SelectedDevice.Available;
    public bool SessionEnabled {
        get => sessionEnabled;
        set {
            if (value && !sessionEnabled)
                Interlocked.Exchange(ref rumbleSessionStart, view.ReadInt32(36));
            sessionEnabled = value;
        }
    }
    public int DeadZone { get; set; } = 12;
    public uint Reports { get; private set; }
    public string Transport { get; private set; } = "USB";

    public Controller(Func<uint, Pad?>? xboxReader = null,
                      Action<uint, ushort, ushort>? xboxRumble = null)
        : this(xboxReader, xboxRumble, RawInputPads.Enumerate, () => Environment.TickCount64) { }
    internal Controller(Func<uint, Pad?>? xboxReader, Action<uint, ushort, ushort>? xboxRumble,
                        Func<RawInputPads.Snapshot?> discoverPads, Func<long> inputClock) {
        this.discoverPads = discoverPads;
        this.inputClock = inputClock;
        if (!OperatingSystem.IsWindows()) {
            xboxReader ??= NativeControllers.Read;
            xboxRumble ??= NativeControllers.Rumble;
            discoverPads = () => null;
            this.discoverPads = discoverPads;
        }
        var native = xboxReader == null ? new XboxInput() : null;
        readXbox = xboxReader ?? native!.Read;
        rumble = new(xboxRumble ?? (native == null ? (_, _, _) => { } : native.Rumble));
        if (!OperatingSystem.IsWindows()) {
            string folder = Path.Combine(Settings.Home, "input"); Directory.CreateDirectory(folder);
            MapName = Path.Combine(folder, Guid.NewGuid().ToString("N")+".map");
            var file = new FileStream(MapName, FileMode.CreateNew, FileAccess.ReadWrite, FileShare.ReadWrite, 4096, FileOptions.DeleteOnClose);
            file.SetLength(64);
            map = MemoryMappedFile.CreateFromFile(file,null,64,MemoryMappedFileAccess.ReadWrite,HandleInheritability.None,false);
        } else
        map = MemoryMappedFile.CreateNew(MapName, 64);
        view = map.CreateViewAccessor();
        view.Write(0, Magic);
        view.Write(32, ControllerRumble.Magic);
    }
    public void Attach(nint hwnd) {
        if (!OperatingSystem.IsWindows()) return;
        source = HwndSource.FromHwnd(hwnd);
        source.AddHook(Hook);
        var devices =
            new[] { new RawDevice { Page = 1, Usage = 5, Flags = 0x2100, Window = hwnd },
                    new RawDevice { Page = 1, Usage = 4, Flags = 0x2100, Window = hwnd } };
        if (!RegisterRawInputDevices(devices, 2, (uint)Marshal.SizeOf<RawDevice>()))
            throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error());
        RefreshDualSense();
    }
    void RemoveDualSense(nint handle) {
        if (deviceNames.Remove(handle, out string? removed)) dualSense.Remove(removed);
    }
    void AddDualSense(RawInputPads.Device device) {
        if (deviceNames.TryGetValue(device.Handle, out string? previous) && previous != device.Path)
            RemoveDualSense(device.Handle);
        deviceNames[device.Handle] = device.Path;
        if (!dualSense.ContainsKey(device.Path))
            dualSense[device.Path] = new(new Pad(), device.Transport, device.Model);
    }
    void RefreshDualSense() {
        if (discoverPads() is not { } snapshot) return;
        foreach (var handle in deviceNames.Keys.Where(h => !snapshot.Handles.Contains(h)).ToArray()) RemoveDualSense(handle);
        foreach (var device in snapshot.Pads) AddDualSense(device);
    }
    bool IsSupported(nint device) {
        if (deviceNames.ContainsKey(device)) return true;
        if (RawInputPads.Read(device) is not { } found) return false;
        AddDualSense(found); return true;
    }
    nint Hook(nint hwnd, int message, nint wp, nint lp, ref bool handled) {
        if (message == 0xFE) {
            if (wp == 2) RemoveDualSense(lp);
            else if (wp == 1) { lastDiscovery = -1000; RefreshDualSense(); }
        }
        if (message != 0xFF)
            return 0;
        uint size = 0;
        uint header = (uint)(8 + IntPtr.Size * 2);
        GetRawInputData(lp, 0x10000003, 0, ref size, header);
        if (size < header + 8 || size > 65536)
            return 0;
        nint data = Marshal.AllocHGlobal((int)size);
        try {
            if (GetRawInputData(lp, 0x10000003, data, ref size, header) != size ||
                Marshal.ReadInt32(data) != 2)
                return 0;
            if (!IsSupported(Marshal.ReadIntPtr(data, 8)))
                return 0;
            int width = Marshal.ReadInt32(data, (int)header),
                count = Marshal.ReadInt32(data, (int)header + 4);
            if (width < 10 || count < 1 || (long)width * count > size - header - 8)
                return 0;
            var bytes = new byte[width];
            Marshal.Copy(data + (int)header + 8 + (count - 1) * width, bytes, 0, width);
            AcceptReport(Marshal.ReadIntPtr(data, 8), bytes);
        } finally {
            Marshal.FreeHGlobal(data);
        }
        return 0;
    }
    internal bool AcceptReport(nint device, byte[] bytes) {
        if (!deviceNames.TryGetValue(device, out string? path) ||
            !dualSense.TryGetValue(path, out var known) ||
            !TryParse(bytes, known.Model, 0, out Pad pad))
            return false;
        Reports++;
        // USB input is always report 0x01 at exactly 64 bytes; any other accepted report is Bluetooth.
        Transport = bytes[0] == 1 && bytes.Length == 64 ? "USB" : "Bluetooth";
        dualSense[path] = known with { Pad = pad, Transport = Transport };
        return true;
    }
    // Input report layouts documented by SDL's PS4 and PS5 HID drivers. Light output uses
    // a separate shared handle; no pairing, exclusive handle or virtual driver.
    public static bool TryParse(byte[] data, PadModel model, int deadZone, out Pad pad) {
        pad = new();
        if (data.Length < 10)
            return false;
        // Left stick offset, and whether buttons come before the triggers (compact layout).
        var (offset, compact) = (model, data[0]) switch {
            // Windows may pad the basic Bluetooth report to 78 bytes. Its controls
            // still use the compact layout, not the enhanced report's offsets.
            (PadModel.DualSense, 1) when data.Length is 10 or 78 => (1, true),
            (PadModel.DualSense, 1) when data.Length == 64 => (1, false),
            (PadModel.DualSense, 0x31) when data.Length == 78 => (2, false),
            // DualShock 4 is compact on USB and Bluetooth. Bluetooth reports 0x11-0x19 add two
            // header bytes, and bit 7 of the first one marks that controller data is present.
            (PadModel.DualShock4, 1) => (1, true),
            (PadModel.DualShock4, >= 0x11 and <= 0x19)
                when data.Length >= 78 && (data[1] & 0x80) != 0 => (3, true),
            _ => (-1, false)
        };
        if (offset < 0)
            return false;
        int buttons = offset + (compact ? 4 : 7);
        byte a = data[buttons], b = data[buttons + 1];
        ushort bits = 0;
        int hat = a & 15;
        if (hat is 0 or 1 or 7)
            bits |= 1;
        if (hat is 3 or 4 or 5)
            bits |= 2;
        if (hat is 5 or 6 or 7)
            bits |= 4;
        if (hat is 1 or 2 or 3)
            bits |= 8;
        if ((a & 0x20) != 0)
            bits |= 0x1000; // Cross -> XInput A
        if ((a & 0x40) != 0)
            bits |= 0x2000; // Circle -> B
        if ((a & 0x10) != 0)
            bits |= 0x4000; // Square -> X
        if ((a & 0x80) != 0)
            bits |= 0x8000; // Triangle -> Y
        if ((b & 1) != 0)
            bits |= 0x100;
        if ((b & 2) != 0)
            bits |= 0x200;
        if ((b & 0x10) != 0)
            bits |= 0x20; // Create -> Back
        if ((b & 0x20) != 0)
            bits |= 0x10; // Options -> Start
        if ((b & 0x40) != 0)
            bits |= 0x40;
        if ((b & 0x80) != 0)
            bits |= 0x80;
        short Axis(byte value, bool invert) {
            int v = value >= 128 ? (value - 128) * 32767 / 127 : (value - 128) * 256;
            int threshold = Math.Clamp(deadZone, 0, 30) * 32767 / 100;
            int magnitude = Math.Abs(v);
            v = magnitude <= threshold
                    ? 0
                    : Math.Sign(v) * (magnitude - threshold) * 32767 / (32767 - threshold);
            return (short)Math.Clamp(invert ? -v : v, -32768, 32767);
        }
        int triggers = offset + (compact ? 7 : 4);
        pad = new(bits, data[triggers], data[triggers + 1], Axis(data[offset], false),
                  Axis(data[offset + 1], true), Axis(data[offset + 2], false),
                  Axis(data[offset + 3], true));
        return true;
    }
    readonly object injection = new();
    ushort injectedButtons;
    long injectedUntil;
    // Automatic lobby steering: ordinary pad buttons added to the player's own input for a moment.
    public void Inject(ushort buttons, int milliseconds) {
        lock (injection) {
            injectedButtons = buttons;
            injectedUntil = Environment.TickCount64 + milliseconds;
        }
    }
    public void Publish() {
        Poll();
        var pad = State;
        lock (injection)
            if (Environment.TickCount64 < injectedUntil)
                pad = pad with { Buttons = (ushort)(pad.Buttons | injectedButtons) };
        string selected = SelectedDevice.Id;
        if (pad != lastPublished || selected != lastPublishedDevice) {
            ++packet;
            lastPublished = pad;
            lastPublishedDevice = selected;
        }
        view.Write(4, ++sequence);
        Thread.MemoryBarrier(); // odd = writing
        view.Write(8, SessionEnabled ? 1u : 0u);
        view.Write(12, unchecked((uint)Environment.TickCount));
        view.Write(16, packet);
        view.Write(20, pad.Buttons);
        view.Write(22, pad.LT);
        view.Write(23, pad.RT);
        view.Write(24, pad.LX);
        view.Write(26, pad.LY);
        view.Write(28, pad.RX);
        view.Write(30, pad.RY);
        Thread.MemoryBarrier();
        view.Write(4, ++sequence);
        var device = SelectedDevice;
        var motors = ControllerRumble.Read(view, SessionEnabled && config.RumbleEnabled,
                                          unchecked((uint)Environment.TickCount),
                                          Volatile.Read(ref rumbleSessionStart));
        rumble.Update(device, motors);
        Volatile.Write(ref rumbleObservation, new(SessionEnabled, device.Name, device.Available, motors));
        int rgb = SessionEnabled ? Volatile.Read(ref healthLight) : 0x0040ff;
        // DualSenseLight writes DualSense output reports only; a DualShock 4 stays input-only.
        bool playstation =
            device.Available && device.Kind == "playstation" &&
            dualSense[device.Id[3..]] is { Model: PadModel.DualSense, Transport: not "Unknown" };
        light.Update(playstation ? device.Id[3..] : null,
                     playstation && dualSense[device.Id[3..]].Transport == "Bluetooth",
                     new((byte)(rgb >> 16), (byte)(rgb >> 8), (byte)rgb), motors);
    }
    public void Dispose() {
        rumble.Dispose();
        light.Dispose();
        source?.RemoveHook(Hook);
        view.Dispose();
        map.Dispose();
    }
    [StructLayout(LayoutKind.Sequential)]
    struct RawDevice {
        public ushort Page, Usage;
        public uint Flags;
        public nint Window;
    }
    [DllImport("user32", SetLastError = true)]
    static extern bool RegisterRawInputDevices(RawDevice[] devices, uint count, uint size);
    [DllImport("user32")]
    static extern uint GetRawInputData(nint input, uint command, nint data, ref uint size,
                                       uint headerSize);
}
