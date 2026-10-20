using System.Buffers.Binary;
using System.IO;
using System.Text;

namespace Outbreak.Launcher;
public sealed record DiscEntry(string Name, long Offset, long Length, bool Directory);
public sealed class DiscImage : IDisposable {
    const int Sector = 2048;
    readonly FileStream image;
    readonly List<DiscEntry> entries = new();
    public IReadOnlyList<DiscEntry> Entries => entries;
    public DiscImage(string filename) {
        image = new(filename, FileMode.Open, FileAccess.Read, FileShare.Read, 1024 * 1024,
                    FileOptions.SequentialScan);
        try {
            ReadIndex();
        } catch {
            image.Dispose();
            throw;
        }
    }
    byte[] Read(long offset, int length) {
        if (offset < 0 || length < 0 || offset > image.Length - length)
            throw new InvalidDataException("The ISO contains an invalid file extent.");
        var bytes = new byte[length];
        image.Position = offset;
        image.ReadExactly(bytes);
        return bytes;
    }
    static uint U32(ReadOnlySpan<byte> data) => BinaryPrimitives.ReadUInt32LittleEndian(data);
    static uint Dual32(ReadOnlySpan<byte> data) {
        uint value = U32(data);
        if (value != BinaryPrimitives.ReadUInt32BigEndian(data[4..]))
            throw new InvalidDataException("The ISO contains an invalid directory record.");
        return value;
    }
    static string Filename(ReadOnlySpan<byte> bytes) {
        if (bytes.Length == 0 || bytes.IndexOfAnyInRange((byte)0, (byte)31) >= 0 ||
            bytes.IndexOfAnyInRange((byte)127, (byte)255) >= 0)
            throw new InvalidDataException("The ISO contains an unsupported filename.");
        string name = Encoding.ASCII.GetString(bytes);
        int version = name.IndexOf(';');
        if (version >= 0) {
            if (!int.TryParse(name[(version + 1)..], out int number) || number != 1)
                throw new InvalidDataException("The ISO has unsupported file versions.");
            name = name[..version];
        }
        if (name.Length == 0 || name.Length > 120 || name is "." or ".." || name.EndsWith('.') ||
            name.EndsWith(' ') || name.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0 ||
            name.Contains('/') || name.Contains('\\'))
            throw new InvalidDataException("The ISO contains an unsafe filename.");
        string stem = name.Split('.') [0].ToUpperInvariant();
        if (stem is "CON" or "PRN" or "AUX" or "NUL" ||
            (stem.Length == 4 && (stem.StartsWith("COM") || stem.StartsWith("LPT")) &&
             stem[3] is >= '1' and <= '9'))
            throw new InvalidDataException("The ISO contains an unsupported device filename.");
        return name;
    }
    void ReadIndex() {
        byte[]? primary = null;
        for (int sector = 16; sector < 48; ++sector) {
            var descriptor = Read((long)sector * Sector, Sector);
            // LLVM 21 does not parse C# UTF-8 literal suffixes.
            // clang-format off
            if (!descriptor.AsSpan(1, 5).SequenceEqual("CD001"u8) || descriptor[6] != 1)
                throw new InvalidDataException(
                    "Select a valid PS2 ISO image (ISO 9660, 2048-byte sectors).");
            // clang-format on
            if (descriptor[0] == 1) {
                primary = descriptor;
                break;
            }
            if (descriptor[0] == 255)
                break;
        }
        if (primary == null ||
            BinaryPrimitives.ReadUInt16LittleEndian(primary.AsSpan(128)) != Sector ||
            BinaryPrimitives.ReadUInt16BigEndian(primary.AsSpan(130)) != Sector)
            throw new InvalidDataException("The ISO's filesystem is not supported.");
        uint volume = Dual32(primary.AsSpan(80));
        if ((long)volume * Sector > image.Length)
            throw new InvalidDataException("The ISO image is truncated.");
        var queue = new Queue<(string Name, uint Lba, uint Size, int Depth)>();
        queue.Enqueue(("", Dual32(primary.AsSpan(158)), Dual32(primary.AsSpan(166)), 0));
        var visited = new HashSet<uint>();
        var paths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        while (queue.TryDequeue(out var directory)) {
            if (directory.Depth > 32 || !visited.Add(directory.Lba) ||
                directory.Size > 16 * 1024 * 1024)
                throw new InvalidDataException("The ISO directory structure is invalid.");
            var bytes = Read((long)directory.Lba * Sector, checked((int)directory.Size));
            for (int at = 0; at < bytes.Length;) {
                int length = bytes[at];
                if (length == 0) {
                    at = ((at / Sector) + 1) * Sector;
                    continue;
                }
                if (length < 34 || at + length > bytes.Length || at % Sector + length > Sector)
                    throw new InvalidDataException("The ISO directory is truncated.");
                var row = bytes.AsSpan(at, length);
                at += length;
                int nameLength = row[32];
                if (nameLength == 0 || 33 + nameLength > row.Length)
                    throw new InvalidDataException("The ISO filename record is invalid.");
                if (nameLength == 1 && row[33] <= 1)
                    continue;
                if ((row[25] & 0x80) != 0 || row[26] != 0 || row[27] != 0 || row[1] != 0)
                    throw new InvalidDataException(
                        "Multi-extent or interleaved ISOs are not supported.");
                string name = Filename(row.Slice(33, nameLength));
                string path = directory.Name.Length == 0 ? name : directory.Name + "/" + name;
                if (!paths.Add(path) || paths.Count > 100000)
                    throw new InvalidDataException("The ISO contains conflicting file paths.");
                uint lba = Dual32(row[2..]), size = Dual32(row[10..]);
                long offset = (long)lba * Sector;
                if (offset > image.Length - size)
                    throw new InvalidDataException("The ISO file data is truncated.");
                bool isDirectory = (row[25] & 2) != 0;
                entries.Add(new(path, offset, size, isDirectory));
                if (isDirectory)
                    queue.Enqueue((path, lba, size, directory.Depth + 1));
            }
        }
    }
    public void Copy(DiscEntry entry, Stream destination, CancellationToken cancel,
                     Action<int>? progress = null,
                     System.Security.Cryptography.IncrementalHash? hash = null) {
        image.Position = entry.Offset;
        long remaining = entry.Length;
        var buffer = new byte[1024 * 1024];
        while (remaining > 0) {
            cancel.ThrowIfCancellationRequested();
            int length = (int)Math.Min(buffer.Length, remaining);
            image.ReadExactly(buffer.AsSpan(0, length));
            destination.Write(buffer, 0, length);
            hash?.AppendData(buffer, 0, length);
            remaining -= length;
            progress?.Invoke(length);
        }
    }
    public string ReadText(DiscEntry entry, int maximumBytes) {
        if (entry.Directory || entry.Length > maximumBytes)
            throw new InvalidDataException("The ISO boot configuration is invalid or oversized.");
        return Encoding.UTF8.GetString(Read(entry.Offset, checked((int)entry.Length)));
    }
    public string Hash(DiscEntry entry, CancellationToken cancel = default) {
        using var hash = System.Security.Cryptography.IncrementalHash.CreateHash(
            System.Security.Cryptography.HashAlgorithmName.SHA256);
        Copy(entry, Stream.Null, cancel, hash: hash);
        return Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
    }
    public void Dispose() => image.Dispose();
}
