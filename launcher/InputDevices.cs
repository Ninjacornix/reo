using System.Runtime.InteropServices;

namespace Outbreak.Launcher;
public sealed partial class Controller
{
    sealed record PhysicalPad(Pad Pad, long Seen, string Transport);
    readonly Dictionary<nint, string> deviceNames = new();
    readonly Dictionary<string, PhysicalPad> dualSense = new();
    readonly Dictionary<uint, Pad> xbox = new();
    readonly Func<uint, Pad?> readXbox;
    Settings config = new();
    long lastDiscovery = -1000;
    InputDevice lastSelected = new("keyboard", "Keyboard", "keyboard");
    public Pad RawState { get; private set; } = new();
    public int GameProcessId { get; set; }
    public int XboxCount => xbox.Count;
    public void Configure(Settings value) { config = value; }
    public IReadOnlyList<InputDevice> AvailableDevices => dualSense.Where(d => Environment.TickCount64 - d.Value.Seen < 2000)
        .Select((d, i) => new InputDevice("ps:" + d.Key, "DualSense" + (dualSense.Count > 1 ? " " + (i + 1) : "") + " (" + d.Value.Transport + ")", "playstation"))
        .Concat(xbox.Keys.Order().Select(slot => new InputDevice("xbox:" + slot, "Xbox / XInput controller " + (slot + 1), "xbox")))
        .Append(new InputDevice("keyboard", "Keyboard", "keyboard")).ToArray();
    public InputDevice SelectedDevice
    {
        get
        {
            var available = AvailableDevices;
            var found = config.InputDeviceId.Length == 0 ? available[0] : available.FirstOrDefault(d => d.Id == config.InputDeviceId);
            if (found != null) return lastSelected = found;
            return new(config.InputDeviceId, lastSelected.Id == config.InputDeviceId ? lastSelected.Name + " — disconnected" : "Saved device — disconnected", config.InputDeviceId.StartsWith("xbox:") ? "xbox" : "playstation", false);
        }
    }
    public PadProfile Profile => SelectedDevice.Kind == "xbox" ? config.Xbox : config.PlayStation;
    public void Select(string id) { config.InputDeviceId = id; RawState = State = new(); }
    public void Poll()
    {
        long now = Environment.TickCount64;
        if (now - lastDiscovery >= 500)
        {
            lastDiscovery = now;
            for (uint slot = 0; slot < 4; ++slot)
            {
                Pad? state = readXbox(slot);
                if (state == null) xbox.Remove(slot); else xbox[slot] = state;
            }
        }
        var device = SelectedDevice;
        if (!device.Available) { RawState = State = new(); return; }
        if (device.Kind == "keyboard")
        {
            GetWindowThreadProcessId(GetForegroundWindow(), out uint foreground);
            bool focused = foreground == Environment.ProcessId || (GameProcessId > 0 && foreground == GameProcessId);
            RawState = State = InputMapping.Keyboard(config.Keyboard, key => focused && (GetAsyncKeyState(key) & 0x8000) != 0);
            return;
        }
        if (device.Kind == "xbox")
        {
            uint slot = uint.Parse(device.Id.AsSpan(5));
            Pad? state = readXbox(slot);
            if (state == null) { xbox.Remove(slot); RawState = State = new(); return; }
            xbox[slot] = state; RawState = state;
        }
        else RawState = dualSense[device.Id[3..]].Pad;
        State = InputMapping.RemapPad(RawState, Profile);
    }
    [DllImport("user32")] static extern nint GetForegroundWindow();
    [DllImport("user32")] static extern uint GetWindowThreadProcessId(nint hwnd, out uint process);
    [DllImport("user32")] static extern short GetAsyncKeyState(int key);
}
