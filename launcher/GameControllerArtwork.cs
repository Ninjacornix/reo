using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
#if !REO_CROSS_PLATFORM
using System.Windows.Media;
using System.Windows.Media.Imaging;
#endif

namespace Outbreak.Launcher;

// Extract only the controller from the owner's imported game. No game artwork ships with us.
internal static class GameControllerArtwork {
    internal const int Width = 172, Height = 116;
    internal const int OverlayWidth = 256, OverlayHeight = 174;
    internal const int MaxDecodedBytes = 4 * 1024 * 1024;
    const string OverlayHash = "7fc2dc3c017371fc06ef9184b3ae36733f85fac481c9f340b579a68110f6389b";
    const int CropX = 340, CropY = 390;
    sealed record Edition(int Index, int Size, string SourceHash, string PixelHash);
    static Edition? Profile(string game) => game switch {
        "file1" => new(557, 857152,
            "a06bc7b56a6768d80fac725daf30301393e0fd59f1498ebce20f0445fc50db26",
            "11cf3a1cf939f3406e452ac062b8b2ddd06ba2939345557e7b28deb912a6193a"),
        "file2" => new(585, 845376,
            "f334ef7e413254e50d9b415c687f392d6f3f71a42c859f221aff025daa45ce7e",
            "2f5a177c9165a8ad9d53f18a4ff1fee81af4d95269281a7a0c50b74dfdbf0da2"),
        _ => null
    };

#if !REO_CROSS_PLATFORM
    internal static BitmapSource? Load(string import, string game, string home) => LoadCore(import, game, home, false);
    internal static BitmapSource? LoadOverlay(string import, string game, string home) => LoadCore(import, game, home, true);

    static BitmapSource? LoadCore(string import, string game, string home, bool overlay) {
        var profile = Profile(game);
        if (profile == null || string.IsNullOrWhiteSpace(import)) return null;
        string archive = Path.Combine(import, "data", "NETBIO00.DAT");
        if (!File.Exists(archive)) return null;
        // Check the tiny, pinned source member even on cache hits. A cache cannot authorize
        // artwork for an absent, different or unsupported game import.
        using var stream = File.OpenRead(archive);
        var rom = BackgroundVideos.Entry(stream, new(0, stream.Length), 0);
        var texture = BackgroundVideos.Entry(stream, rom, profile.Index);
        if (texture.Length != profile.Size) throw new InvalidDataException("Unsupported controller texture size.");
        byte[] source = new byte[profile.Size];
        stream.Position = texture.Offset;
        stream.ReadExactly(source);
        if (!Matches(source, profile.SourceHash)) throw new InvalidDataException("Unsupported controller texture data.");

        string folder = Path.Combine(home, "controller-artwork");
        string cache = Path.Combine(folder, game + (overlay ? "-overlay-v1.png" : "-controller-v1.png"));
        string pixelHash = overlay ? OverlayHash : profile.PixelHash;
        int width = overlay ? OverlayWidth : Width, height = overlay ? OverlayHeight : Height;
        if (ReadCache(cache, pixelHash, width, height) is { } cached) return cached;
        byte[] decoded = DecompressOb(game == "file2" ? MomoMember(source, overlay ? 5 : 2) : source);
        byte[] pixels = DecodeCrop(decoded, game == "file1" ? (overlay ? 9 : 5) : 0, overlay);
        if (!Matches(pixels, pixelHash)) throw new InvalidDataException("Unsupported controller artwork pixels.");
        var image = Create(pixels, width, height);
        SaveCache(cache, folder, image);
        return image;
    }

    static bool Matches(byte[] bytes, string expected) =>
        Convert.ToHexString(SHA256.HashData(bytes)).Equals(expected, StringComparison.OrdinalIgnoreCase);

    static BitmapSource Create(byte[] pixels, int width, int height) {
        var image = BitmapSource.Create(width, height, 96, 96, PixelFormats.Bgra32, null, pixels, width * 4);
        image.Freeze();
        return image;
    }

    static BitmapSource? ReadCache(string path, string pixelHash, int width, int height) {
        try {
            using var stream = File.OpenRead(path);
            if (stream.Length > 1024 * 1024) return null;
            // Reject oversized IHDR dimensions before asking WPF to allocate a decoder.
            Span<byte> header = stackalloc byte[24];
            if (stream.Read(header) != header.Length ||
                !header[..8].SequenceEqual(new byte[] { 137, 80, 78, 71, 13, 10, 26, 10 }) ||
                !header[12..16].SequenceEqual("IHDR"u8) ||
                BinaryPrimitives.ReadUInt32BigEndian(header[16..20]) != width ||
                BinaryPrimitives.ReadUInt32BigEndian(header[20..24]) != height) return null;
            stream.Position = 0;
            var frame = BitmapDecoder.Create(stream, BitmapCreateOptions.PreservePixelFormat,
                BitmapCacheOption.OnLoad).Frames[0];
            if (frame.PixelWidth != width || frame.PixelHeight != height) return null;
            var converted = new FormatConvertedBitmap(frame, PixelFormats.Bgra32, null, 0);
            byte[] pixels = new byte[width * height * 4];
            converted.CopyPixels(pixels, width * 4, 0);
            return Matches(pixels, pixelHash) ? Create(pixels, width, height) : null;
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or
                                               NotSupportedException or ArgumentException or FileFormatException) {
            return null;
        }
    }

    static void SaveCache(string path, string folder, BitmapSource image) {
        string pending = path + "." + Guid.NewGuid().ToString("N") + ".tmp";
        try {
            Directory.CreateDirectory(folder);
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(image));
            using (var output = File.Create(pending)) encoder.Save(output);
            File.Move(pending, path, true);
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            // Caching is optional; the controller can still be shown on read-only storage.
        } finally {
            try { if (File.Exists(pending)) File.Delete(pending); }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException) { }
        }
    }

#else
    internal static byte[]? LoadPixels(string import, string game, bool overlay = false) {
        var profile = Profile(game);
        if (profile == null || string.IsNullOrWhiteSpace(import)) return null;
        string archive = Path.Combine(import, "data", "NETBIO00.DAT");
        if (!File.Exists(archive)) return null;
        using var stream = File.OpenRead(archive);
        var rom = BackgroundVideos.Entry(stream, new(0, stream.Length), 0);
        var texture = BackgroundVideos.Entry(stream, rom, profile.Index);
        if (texture.Length != profile.Size) throw new InvalidDataException("Unsupported controller texture size.");
        byte[] source = new byte[profile.Size];
        stream.Position = texture.Offset; stream.ReadExactly(source);
        if (!Matches(source, profile.SourceHash)) throw new InvalidDataException("Unsupported controller texture data.");
        byte[] decoded = DecompressOb(game == "file2" ? MomoMember(source, overlay ? 5 : 2) : source);
        byte[] pixels = DecodeCrop(decoded, game == "file1" ? (overlay ? 9 : 5) : 0, overlay);
        if (!Matches(pixels, overlay ? OverlayHash : profile.PixelHash)) throw new InvalidDataException("Unsupported controller pixels.");
        return pixels;
    }
    static bool Matches(byte[] bytes, string expected) =>
        Convert.ToHexString(SHA256.HashData(bytes)).Equals(expected, StringComparison.OrdinalIgnoreCase);
#endif

    internal static byte[] MomoMember(ReadOnlySpan<byte> source, int index) {
        if (source.Length < 8 || source.Length > MaxDecodedBytes || !source[..4].SequenceEqual("MOMO"u8))
            throw new InvalidDataException("Invalid controller texture container.");
        uint count = BinaryPrimitives.ReadUInt32LittleEndian(source[4..]);
        if (count is 0 or > 128 || index < 0 || index >= count || 8L + count * 8L > source.Length)
            throw new InvalidDataException("Invalid controller texture directory.");
        int entry = 8 + index * 8;
        uint offset = BinaryPrimitives.ReadUInt32LittleEndian(source[entry..]);
        uint length = BinaryPrimitives.ReadUInt32LittleEndian(source[(entry + 4)..]);
        if (offset < 8L + count * 8L || length == 0 || (long)offset + length > source.Length)
            throw new InvalidDataException("Controller texture member outside its container.");
        return source.Slice((int)offset, (int)length).ToArray();
    }

    // Outbreak's compressed tokens describe 16-bit words, read MSB-first from a control word.
    internal static byte[] DecompressOb(ReadOnlySpan<byte> source) {
        if (source.Length < 4 || source.Length > MaxDecodedBytes || (source.Length & 1) != 0)
            throw new InvalidDataException("Invalid compressed controller texture length.");
        byte[] output = new byte[MaxDecodedBytes];
        int position = 0, written = 0;
        while (position < source.Length) {
            ushort control = BinaryPrimitives.ReadUInt16LittleEndian(source[position..]);
            position += 2;
            if (position == source.Length) throw new InvalidDataException("Missing controller texture token.");
            for (int bit = 15; bit >= 0 && position < source.Length; bit--) {
                ushort word = BinaryPrimitives.ReadUInt16LittleEndian(source[position..]);
                position += 2;
                if ((control & (1 << bit)) == 0) {
                    if (written > output.Length - 2) throw new InvalidDataException("Controller texture exceeds decoding limit.");
                    BinaryPrimitives.WriteUInt16LittleEndian(output.AsSpan(written), word);
                    written += 2;
                    continue;
                }
                int count = word >> 11, offset = (word & 0x7ff) * 2;
                if (count == 0 && offset == 0) return output[..written];
                if (count == 0) {
                    if (position >= source.Length) throw new InvalidDataException("Missing controller texture run length.");
                    count = BinaryPrimitives.ReadUInt16LittleEndian(source[position..]);
                    position += 2;
                }
                int bytes = count * 2;
                if (offset > written || bytes > output.Length - written)
                    throw new InvalidDataException("Invalid controller texture back reference.");
                // Zero-fill runs and overlapping back references are both used by the game.
                if (offset == 0) Array.Clear(output, written, bytes);
                else for (int i = 0; i < bytes; i++) output[written + i] = output[written + i - offset];
                written += bytes;
            }
        }
        return output[..written];
    }

    // File #1 concatenates complete TIM2 files; File #2 stores one TIM2 per MOMO member.
    internal static byte[] DecodeCrop(ReadOnlySpan<byte> data, int imageIndex, bool overlay = false) {
        if (data.Length > MaxDecodedBytes || imageIndex < 0 || imageIndex > 127)
            throw new InvalidDataException("Invalid controller texture image index.");
        int file = 0, image = 0;
        while (file < data.Length) {
            if (data.Length - file < 16 || !data.Slice(file, 4).SequenceEqual("TIM2"u8))
                throw new InvalidDataException("Invalid controller TIM2 header.");
            int count = BinaryPrimitives.ReadUInt16LittleEndian(data[(file + 6)..]);
            if (count is 0 or > 128) throw new InvalidDataException("Invalid controller TIM2 image count.");
            int picture = file + (data[file + 5] == 0 ? 16 : 128);
            for (int n = 0; n < count; n++, image++) {
                if (picture > data.Length - 48) throw new InvalidDataException("Truncated controller TIM2 picture.");
                uint total = BinaryPrimitives.ReadUInt32LittleEndian(data[picture..]);
                uint clutSize = BinaryPrimitives.ReadUInt32LittleEndian(data[(picture + 4)..]);
                uint imageSize = BinaryPrimitives.ReadUInt32LittleEndian(data[(picture + 8)..]);
                int headerSize = BinaryPrimitives.ReadUInt16LittleEndian(data[(picture + 12)..]);
                if (headerSize < 48 || total < headerSize || (long)picture + total > data.Length ||
                    (long)headerSize + imageSize + clutSize > total)
                    throw new InvalidDataException("Invalid controller TIM2 picture extent.");
                if (image == imageIndex) {
                    int colors = BinaryPrimitives.ReadUInt16LittleEndian(data[(picture + 14)..]);
                    byte clutType = data[picture + 18], imageType = data[picture + 19];
                    int width = BinaryPrimitives.ReadUInt16LittleEndian(data[(picture + 20)..]);
                    int height = BinaryPrimitives.ReadUInt16LittleEndian(data[(picture + 22)..]);
                    int expectedType = overlay ? 4 : 5, expectedColors = overlay ? 16 : 256;
                    int expectedSize = overlay ? 256 : 512;
                    int minimumPixels = expectedSize * expectedSize / (overlay ? 2 : 1);
                    if (imageType != expectedType || (clutType & 0x3f) != 3 || colors != expectedColors ||
                        width != expectedSize || height != expectedSize || imageSize < minimumPixels || clutSize < colors * 4)
                        throw new InvalidDataException("Unsupported controller TIM2 pixel format.");
                    int pixels = picture + headerSize, palette = pixels + (int)imageSize;
                    int cropWidth = overlay ? OverlayWidth : Width, cropHeight = overlay ? OverlayHeight : Height;
                    int cropX = overlay ? 0 : CropX, cropY = overlay ? 0 : CropY;
                    byte[] result = new byte[cropWidth * cropHeight * 4];
                    for (int y = 0; y < cropHeight; y++) for (int x = 0; x < cropWidth; x++) {
                        int pixelIndex = (cropY + y) * width + cropX + x;
                        int color = overlay ? (data[pixels + pixelIndex / 2] >> ((pixelIndex & 1) * 4)) & 15
                                            : data[pixels + pixelIndex];
                        if (!overlay && (clutType & 0x80) == 0)
                            color = (color & ~24) | ((color & 8) << 1) | ((color & 16) >> 1);
                        int c = palette + color * 4, d = (y * cropWidth + x) * 4;
                        result[d] = data[c + 2]; result[d + 1] = data[c + 1]; result[d + 2] = data[c];
                        result[d + 3] = (byte)Math.Min(255, data[c + 3] * 2);
                    }
                    return result;
                }
                picture += (int)total;
            }
            file = picture;
        }
        throw new InvalidDataException("Missing controller TIM2 image.");
    }
}
