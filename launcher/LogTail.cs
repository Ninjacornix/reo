using System.IO;
using System.Text;

namespace Outbreak.Launcher;
public static class LogTail
{
    // Read-only bounded tail: never lock a running game's writer, never load an
    // entire multi-megabyte diagnostic log into the WPF dispatcher.
    public static string Read(string path, int maximumBytes = 128 * 1024)
    {
        if (maximumBytes < 4 || maximumBytes > 1024 * 1024) throw new ArgumentOutOfRangeException(nameof(maximumBytes));
        using var stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite | FileShare.Delete);
        long start = Math.Max(0, stream.Length - maximumBytes);
        stream.Position = start;
        var bytes = new byte[Math.Min(maximumBytes, stream.Length - start)];
        int count = 0, got;
        while (count < bytes.Length && (got = stream.Read(bytes, count, bytes.Length - count)) > 0) count += got;
        int first = 0;
        if (start > 0)
        {
            while (first < count && bytes[first] != 10) ++first;
            if (first < count) ++first; else first = 0;
        }
        return Encoding.UTF8.GetString(bytes, first, count - first);
    }
}
