using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal record AudioOutput(string Id, string Name, bool Available = true) {
    public override string ToString() => Name;
}

internal static class AudioOutputs {
    public static IReadOnlyList<AudioOutput> Choices(IEnumerable<AudioOutput> devices, string selected, string name) {
        var result = new List<AudioOutput> { new("", "Windows default") };
        result.AddRange(devices.Where(d => d.Id.Length != 0).DistinctBy(d => d.Id, StringComparer.Ordinal)
            .OrderBy(d => d.Name, StringComparer.CurrentCultureIgnoreCase).ThenBy(d => d.Id));
        if (selected.Length != 0 && result.All(d => d.Id != selected))
            result.Add(new(selected, (name.Length == 0 ? "Saved output" : name) + " (unavailable)", false));
        return result;
    }
    public static IReadOnlyList<AudioOutput> Enumerate() {
        var result = new List<AudioOutput>();
        IMMDeviceEnumerator? enumerator = null;
        IMMDeviceCollection? collection = null;
        try {
            enumerator = (IMMDeviceEnumerator)new MMDeviceEnumerator();
            Marshal.ThrowExceptionForHR(enumerator.EnumAudioEndpoints(0, 1, out collection)); // active render endpoints only
            Marshal.ThrowExceptionForHR(collection.GetCount(out uint count));
            for (uint i = 0; i < count; i++) {
                IMMDevice? device = null;
                IPropertyStore? properties = null;
                try {
                    Marshal.ThrowExceptionForHR(collection.Item(i, out device));
                    Marshal.ThrowExceptionForHR(device.GetId(out string id));
                    Marshal.ThrowExceptionForHR(device.OpenPropertyStore(0, out properties));
                    var key = new PropertyKey { Format = new("a45c254e-df1c-4efd-8020-67d146a850e0"), Id = 14 };
                    Marshal.ThrowExceptionForHR(properties.GetValue(ref key, out var value));
                    try {
                        string name = value.Type == 31 ? Marshal.PtrToStringUni(value.Pointer) ?? "Audio output" : "Audio output";
                        result.Add(new(id, name));
                    } finally { PropVariantClear(ref value); }
                } catch (COMException) { /* A device can disappear during enumeration. */ }
                finally { Release(properties); Release(device); }
            }
        } catch (COMException) { /* Windows default remains usable when enumeration is unavailable. */ }
        finally { Release(collection); Release(enumerator); }
        return result;
    }
    static void Release(object? value) { if (value != null && Marshal.IsComObject(value)) Marshal.FinalReleaseComObject(value); }
    [DllImport("ole32.dll")] static extern int PropVariantClear(ref PropVariant value);
    [StructLayout(LayoutKind.Sequential)] struct PropertyKey { public Guid Format; public uint Id; }
    [StructLayout(LayoutKind.Explicit, Size = 24)] struct PropVariant {
        [FieldOffset(0)] public ushort Type;
        [FieldOffset(8)] public nint Pointer;
    }
    [ComImport, Guid("bcde0395-e52f-467c-8e3d-c4579291692e")] class MMDeviceEnumerator { }
    [ComImport, Guid("a95664d2-9614-4f35-a746-de8db63617e6"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface IMMDeviceEnumerator {
        [PreserveSig] int EnumAudioEndpoints(int flow, uint state, out IMMDeviceCollection devices);
    }
    [ComImport, Guid("0bd7a1be-7a1a-44db-8397-cc5392387b5e"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface IMMDeviceCollection {
        [PreserveSig] int GetCount(out uint count);
        [PreserveSig] int Item(uint index, out IMMDevice device);
    }
    [ComImport, Guid("d666063f-1587-4e43-81f1-b948e807363f"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface IMMDevice {
        [PreserveSig] int Activate(ref Guid id, uint context, nint parameters, [MarshalAs(UnmanagedType.IUnknown)] out object value);
        [PreserveSig] int OpenPropertyStore(uint access, out IPropertyStore properties);
        [PreserveSig] int GetId([MarshalAs(UnmanagedType.LPWStr)] out string id);
        [PreserveSig] int GetState(out uint state);
    }
    [ComImport, Guid("886d8eeb-8cf2-4446-8d02-cdba1dbdcf99"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface IPropertyStore {
        [PreserveSig] int GetCount(out uint count);
        [PreserveSig] int GetAt(uint index, out PropertyKey key);
        [PreserveSig] int GetValue(ref PropertyKey key, out PropVariant value);
    }
}
