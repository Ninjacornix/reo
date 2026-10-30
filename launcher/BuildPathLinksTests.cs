using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;

namespace Outbreak.Launcher;

internal static class BuildPathLinksTests {
    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern SafeFileHandle CreateFileW(string path, uint access, uint share,
        nint security, uint creation, uint flags, nint template);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool DeviceIoControl(SafeFileHandle handle, uint operation,
        byte[] input, int length, nint output, int outputLength, out int returned, nint overlapped);

    internal static void Run(Action<bool, string> check) {
        check(BuildPathLinks.RedirectingTag(0xa000000c) &&
              BuildPathLinks.RedirectingTag(0xa0000003) &&
              BuildPathLinks.RedirectingTag(0x20000042),
              "Symbolic links, junctions and unknown name-surrogate tags redirect paths");
        check(!BuildPathLinks.RedirectingTag(0x9000001a) &&
              !BuildPathLinks.RedirectingTag(0x80000017) &&
              !BuildPathLinks.RedirectingTag(0x42),
              "Cloud, WOF and independent data tags are not symbolic links");
        string root = Path.Combine(Path.GetTempPath(), "reo-link-check-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        string data = Path.Combine(root, "data-point");
        string junction = Path.Combine(root, "junction");
        string outside = Path.Combine(root, "outside");
        Directory.CreateDirectory(outside);
        File.WriteAllText(Path.Combine(outside, "keep.txt"), "untouched");
        uint installedTag = 0x42;
        try {
            check(LocalGameBuild.Inside(root, "ordinary/new/file.bin") ==
                  Path.Combine(root, "ordinary", "new", "file.bin"),
                  "Ordinary missing paths remain valid");
            // Real non-Microsoft data reparse point; no cloud service or filter driver
            // is required to inspect its metadata. It must not be opened as file data.
            Directory.CreateDirectory(data);
            SetDataPoint(data, true);
            check((File.GetAttributes(data) & FileAttributes.ReparsePoint) != 0,
                  "Regression fixture is a real Windows reparse point");
            bool oldRejected = false;
            try { OldInside(root, "data-point/new.bin"); }
            catch (IOException error) { oldRejected = error.Message.Contains("symbolic links"); }
            check(oldRejected, "RC0 guard reproduces the false symbolic-link rejection on a data point");
            check(LocalGameBuild.Inside(root, "data-point/new.bin") == Path.Combine(data, "new.bin"),
                  "RC1 accepts a non-redirecting reparse point");
            SetDataPoint(data, false);
            string deep = Path.Combine(root, string.Join(Path.DirectorySeparatorChar,
                Enumerable.Repeat(new string('d', 45), 6)), "data-point");
            Directory.CreateDirectory(deep);
            SetDataPoint(deep, true);
            try {
                string extended = @"\\?\" + deep;
                check(deep.Length > 300 &&
                      !BuildPathLinks.Redirects(deep, File.GetAttributes(deep)) &&
                      !BuildPathLinks.Redirects(extended, File.GetAttributes(extended)),
                      "Real data points beyond MAX_PATH accept ordinary and extended path arguments");
            } finally { SetDataPoint(deep, false); }
            installedTag = 0x20000042;
            SetDataPoint(data, true, installedTag);
            bool unknownRedirectRejected = false;
            try { LocalGameBuild.Inside(root, "data-point/new.bin"); }
            catch (IOException error) { unknownRedirectRejected = error.Message.Contains(data); }
            check(unknownRedirectRejected, "Unknown real namespace-redirecting reparse tags remain blocked");
            SetDataPoint(data, false, installedTag);
            bool inspectionFailed = false;
            try { BuildPathLinks.Redirects(Path.Combine(root, "missing"), FileAttributes.ReparsePoint); }
            catch (IOException error) { inspectionFailed = error.Message.Contains("missing") && error.InnerException != null; }
            check(inspectionFailed, "An unreadable reparse tag fails closed with the path and Windows error");

            using var command = Process.Start(new ProcessStartInfo("cmd.exe") {
                ArgumentList = { "/d", "/c", "mklink", "/J", junction, outside },
                UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true,
                RedirectStandardError = true
            })!;
            command.WaitForExit();
            check(command.ExitCode == 0, "Real junction fixture created");
            bool rejected = false;
            try { LocalGameBuild.Inside(root, "junction/keep.txt"); }
            catch (IOException error) {
                rejected = error.Message.Contains(junction) && error.Message.Contains("Game files");
            }
            check(rejected, "RC1 still rejects real junction traversal and identifies the path and recovery");
            Directory.Delete(junction);
            check(File.ReadAllText(Path.Combine(outside, "keep.txt")) == "untouched",
                  "Rejected traversal leaves target data unchanged");
        } finally {
            if (Directory.Exists(junction)) Directory.Delete(junction);
            if (Directory.Exists(data) && (File.GetAttributes(data) & FileAttributes.ReparsePoint) != 0)
                SetDataPoint(data, false, installedTag);
            Directory.Delete(root, true);
        }
    }

    static void SetDataPoint(string path, bool create, uint tag = 0x42) {
        // Non-Microsoft GUID-form tag, optionally with the name-surrogate bit set.
        var buffer = new byte[24];
        BitConverter.GetBytes(tag).CopyTo(buffer, 0);
        new Guid("b06ae63a-c6ea-41dd-8239-78ea4f90238c").ToByteArray().CopyTo(buffer, 8);
        using var handle = CreateFileW(@"\\?\" + path, 0x40000000, 7, 0, 3, 0x02200000, 0);
        if (handle.IsInvalid || !DeviceIoControl(handle, create ? 0x000900a4u : 0x000900acu,
            buffer, buffer.Length, 0, 0, out _, 0))
            throw new IOException("Reparse fixture operation failed: " + Marshal.GetLastWin32Error());
    }

    // Exact rejection predicate and ancestor walk used by RC0, retained to prove
    // this fixture fails before the fix rather than merely mirroring new code.
    static void OldInside(string root, string relative) {
        for (FileSystemInfo? path = new FileInfo(Path.Combine(root, relative)); path != null;
             path = path is FileInfo f ? f.Directory : ((DirectoryInfo)path).Parent) {
            if (path.Exists && (path.Attributes & FileAttributes.ReparsePoint) != 0)
                throw new IOException("Build-kit paths must not traverse symbolic links.");
            if (path.FullName.Equals(root, StringComparison.OrdinalIgnoreCase)) break;
        }
    }
}
