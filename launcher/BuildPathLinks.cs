using System.ComponentModel;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;

namespace Outbreak.Launcher;

// ReparsePoint also describes cloud placeholders and file-data filters. Only
// name-surrogate tags redirect a path to another file or directory on Windows.
internal static class BuildPathLinks {
    const uint NameSurrogate = 0x20000000;
    internal static bool RedirectingTag(uint tag) => (tag & NameSurrogate) != 0;

    [StructLayout(LayoutKind.Sequential)]
    struct AttributeTag { public uint Attributes, Tag; }

    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern SafeFileHandle CreateFileW(string name, uint access, uint share,
        nint security, uint creation, uint flags, nint template);

    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool GetFileInformationByHandleEx(SafeFileHandle handle, int infoClass,
        out AttributeTag info, uint size);

    internal static bool Redirects(string path, FileAttributes attributes) {
        if ((attributes & FileAttributes.ReparsePoint) == 0) return false;
        if (!OperatingSystem.IsWindows())
            return new FileInfo(path).LinkTarget != null;
        // Inspect the point itself, including directories, rather than following it.
        // Extended paths work even without the machine-wide long-path setting.
        string full = Path.GetFullPath(path);
        if (!full.StartsWith(@"\\?\", StringComparison.Ordinal))
            full = full.StartsWith(@"\\", StringComparison.Ordinal)
                ? @"\\?\UNC\" + full[2..] : @"\\?\" + full;
        using var handle = CreateFileW(full, 0, 7, 0, 3, 0x02200000, 0);
        if (handle.IsInvalid)
            throw Failure(path);
        // FileAttributeTagInfo = 9; FILE_FLAG_OPEN_REPARSE_POINT | BACKUP_SEMANTICS.
        if (!GetFileInformationByHandleEx(handle, 9, out var info, 8))
            throw Failure(path);
        return RedirectingTag(info.Tag);
    }

    static IOException Failure(string path) => new(
        "Could not inspect build-kit path: " + path,
        new Win32Exception(Marshal.GetLastWin32Error()));
}
