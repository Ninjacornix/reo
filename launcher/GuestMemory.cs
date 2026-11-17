using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

// Read-only access to the running game's EE RAM (located through the ELF signature), used by
// the controller health light. No guest writes.
internal sealed class GuestMemory : IDisposable {
    const uint RamSize = 0x2000000, Root = 0x6D8DB0;
    readonly nint handle;
    readonly long baseAddress;

    GuestMemory(nint handle, long baseAddress) {
        this.handle = handle;
        this.baseAddress = baseAddress;
    }

    public static GuestMemory Open(Process process, string elfPath) {
        nint handle = OpenProcess(0x1010, false, process.Id); // QUERY_LIMITED | VM_READ
        if (handle == 0)
            throw new IOException("Cannot read the game's lobby state.");
        try {
            byte[] image = File.ReadAllBytes(elfPath);
            uint phoff = BitConverter.ToUInt32(image, 0x1C);
            int phnum = BitConverter.ToUInt16(image, 0x2C);
            (uint Address, byte[] Bytes)? segment = null;
            for (int i = 0; i < phnum && segment == null; ++i) {
                int at = checked((int)phoff + i * 32);
                uint kind = BitConverter.ToUInt32(image, at), offset = BitConverter.ToUInt32(image, at + 4),
                     address = BitConverter.ToUInt32(image, at + 8), size = BitConverter.ToUInt32(image, at + 16);
                if (kind == 1 && size >= 64)
                    segment = (address, image.AsSpan(checked((int)offset), 64).ToArray());
            }
            if (segment == null)
                throw new IOException("The game executable has no loaded segment.");
            var candidates = new HashSet<long>();
            long cursor = 0;
            var info = new MemoryInfo();
            var probe = new byte[64];
            while (cursor < 0x7FFFFFFFFFFF &&
                   VirtualQueryEx(handle, (nint)cursor, out info, Marshal.SizeOf<MemoryInfo>()) != 0) {
                long regionBase = info.BaseAddress, size = (long)info.RegionSize;
                if (info.State == 0x1000 && size >= RamSize && (info.Protect & 0x101) == 0)
                    foreach (long slack in new long[] { 0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x1000 })
                        if (ReadHost(handle, regionBase + slack + segment.Value.Address, probe) &&
                            probe.AsSpan().SequenceEqual(segment.Value.Bytes))
                            candidates.Add(regionBase + slack);
                long next = regionBase + size;
                if (next <= cursor)
                    break;
                cursor = next;
            }
            if (candidates.Count != 1)
                throw new IOException("The game's memory is not ready.");
            return new(handle, candidates.Single());
        } catch {
            CloseHandle(handle);
            throw;
        }
    }

    static bool ReadHost(nint handle, long address, byte[] buffer) =>
        ReadProcessMemory(handle, (nint)address, buffer, buffer.Length, out nint read) &&
        read == buffer.Length;

    byte[] Bytes(uint address, int size) {
        if (size < 0 || address + (ulong)size > RamSize)
            throw new InvalidDataException("Read outside game memory.");
        var buffer = new byte[size];
        if (!ReadHost(handle, baseAddress + address, buffer))
            throw new IOException("The game's memory is no longer readable.");
        return buffer;
    }
    uint Word(uint address) => BitConverter.ToUInt32(Bytes(address, 4));
    byte Byte(uint address) => Bytes(address, 1)[0];

    internal ControllerHealth.Sample ReadHealth() {
        int phase = Byte(0x4badd0), slot = Byte(0x4baded);
        if (phase != 2 || slot >= 4)
            return new(phase, slot, false, 0, 0);
        byte[] actor = Bytes(0x4a5c30u + (uint)slot * 0x10e0u, 0x548);
        if (Byte(0x4badd0) != phase || Byte(0x4baded) != slot)
            return new(0, 0, false, 0, 0);
        return new(phase, slot, actor[0] != 0, BitConverter.ToInt16(actor, 0x544),
                   BitConverter.ToInt16(actor, 0x546));
    }

    public void Dispose() => CloseHandle(handle);

    [StructLayout(LayoutKind.Sequential)]
    struct MemoryInfo {
        public long BaseAddress, AllocationBase;
        public uint AllocationProtect;
        public ushort PartitionId;
        public nuint RegionSize;
        public uint State, Protect, Type;
    }
    [DllImport("kernel32", SetLastError = true)]
    static extern nint OpenProcess(uint access, bool inherit, int id);
    [DllImport("kernel32")]
    static extern bool CloseHandle(nint handle);
    [DllImport("kernel32")]
    static extern nint VirtualQueryEx(nint process, nint address, out MemoryInfo info, int length);
    [DllImport("kernel32")]
    static extern bool ReadProcessMemory(nint process, nint address, byte[] buffer, int size,
                                         out nint read);
}
