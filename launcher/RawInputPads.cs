using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

// Presence comes from Windows, independently of whether a controller is sending
// reports. RID_DEVICE_INFO_HID supplies numeric IDs over USB and Bluetooth.
internal static class RawInputPads {
    internal sealed record Device(nint Handle, string Path, string Transport);
    internal sealed record Snapshot(HashSet<nint> Handles, List<Device> Pads);
    internal static bool Supported(uint vendor, uint product, ushort page, ushort usage) =>
        vendor == 0x054c && (product is 0x0ce6 or 0x0df2) && page == 1 && (usage is 4 or 5);

    internal static string Transport(string path) =>
        path.Contains("BTH", StringComparison.OrdinalIgnoreCase) ||
        path.Contains("{00001124-", StringComparison.OrdinalIgnoreCase) ||
        path.Contains("VID&", StringComparison.OrdinalIgnoreCase) ? "Bluetooth" : "Unknown";

    internal static Device? Read(nint handle) {
        if (handle == 0) return null;
        // RID_DEVICE_INFO is 32 bytes, including its largest union member.
        nint info = Marshal.AllocHGlobal(32);
        try {
            Marshal.WriteInt32(info, 32); uint bytes = 32;
            if (GetRawInputDeviceInfo(handle, 0x2000000b, info, ref bytes) == uint.MaxValue || bytes < 24 ||
                Marshal.ReadInt32(info, 4) != 2 ||
                !Supported(unchecked((uint)Marshal.ReadInt32(info, 8)), unchecked((uint)Marshal.ReadInt32(info, 12)),
                           unchecked((ushort)Marshal.ReadInt16(info, 20)), unchecked((ushort)Marshal.ReadInt16(info, 22)))) return null;
        } finally { Marshal.FreeHGlobal(info); }
        uint length = 0;
        if (GetRawInputDeviceInfo(handle, 0x20000007, 0, ref length) == uint.MaxValue || length is 0 or > 8192) return null;
        nint name = Marshal.AllocHGlobal(checked((int)(length + 1) * 2));
        try {
            Marshal.WriteInt16(name, checked((int)length * 2), 0);
            if (GetRawInputDeviceInfo(handle, 0x20000007, name, ref length) == uint.MaxValue) return null;
            string path = Marshal.PtrToStringUni(name) ?? "";
            return path.Length == 0 ? null : new(handle, path, Transport(path));
        } finally { Marshal.FreeHGlobal(name); }
    }

    internal static Snapshot? Enumerate() {
        uint stride = (uint)Marshal.SizeOf<DeviceList>();
        // A plug/unplug can grow the list between the size query and the read.
        for (int attempt = 0; attempt < 3; attempt++) {
            uint count = 0;
            if (GetRawInputDeviceList(0, ref count, stride) == uint.MaxValue || count > 4096) return null;
            if (count == 0) return new(new(), new());
            uint capacity = count;
            nint memory = Marshal.AllocHGlobal(checked((int)(capacity * stride)));
            try {
                uint read = GetRawInputDeviceList(memory, ref count, stride);
                if (read == uint.MaxValue) {
                    if (Marshal.GetLastWin32Error() == 122) continue;
                    return null;
                }
                if (read > capacity) return null;
                var handles = new HashSet<nint>(); var pads = new List<Device>();
                for (int i = 0; i < read; i++) {
                    var entry = Marshal.PtrToStructure<DeviceList>(memory + checked(i * (int)stride));
                    handles.Add(entry.Handle);
                    if (entry.Type == 2 && Read(entry.Handle) is { } pad) pads.Add(pad);
                }
                return new(handles, pads);
            } finally { Marshal.FreeHGlobal(memory); }
        }
        // Failed enumeration is not evidence that every controller disconnected.
        return null;
    }
    [StructLayout(LayoutKind.Sequential)]
    struct DeviceList { public nint Handle; public uint Type; }
    [DllImport("user32", SetLastError = true)]
    static extern uint GetRawInputDeviceList(nint list, ref uint count, uint size);
    [DllImport("user32", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern uint GetRawInputDeviceInfo(nint device, uint command, nint data, ref uint size);
}
