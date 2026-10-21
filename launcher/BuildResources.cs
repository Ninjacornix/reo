using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal static class BuildResources {
    internal const int MaximumWorkers = 32;
    [StructLayout(LayoutKind.Sequential)]
    struct MemoryStatus {
        public uint Length, Load;
        public ulong TotalPhysical, AvailablePhysical, TotalPageFile, AvailablePageFile,
            TotalVirtual, AvailableVirtual, AvailableExtendedVirtual;
    }
    [DllImport("kernel32.dll", SetLastError = true)]
    [return:MarshalAs(UnmanagedType.Bool)]
    static extern bool GlobalMemoryStatusEx(ref MemoryStatus status);
    internal static int WorkerCount() {
        var memory = new MemoryStatus { Length = (uint)Marshal.SizeOf<MemoryStatus>() };
        if (!GlobalMemoryStatusEx(ref memory))
            return Math.Clamp(Environment.ProcessorCount / 2, 1, 2);
        return Select(Environment.ProcessorCount,
                      Math.Min(memory.AvailablePhysical, memory.AvailablePageFile));
    }
    internal static int Select(int processors, ulong availableBytes) {
        const ulong gib = 1024UL * 1024 * 1024;
        // Upper bound only: the worker re-reads free memory for every compiler it starts and
        // reserves 0.5 GiB per ordinary unit (they measured 60-150 MB) and 4 GiB for huge ones.
        int memoryLimit =
            (int)Math.Min((ulong)MaximumWorkers,
                          (availableBytes > gib ? availableBytes - gib : 0) / (gib / 2));
        return Math.Max(1, Math.Min(Math.Clamp(processors - 1, 1, MaximumWorkers), memoryLimit));
    }
}
