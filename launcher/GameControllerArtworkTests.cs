using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

internal static class GameControllerArtworkTests {
    static byte[] Words(params ushort[] words) {
        byte[] bytes = new byte[words.Length * 2];
        for (int i = 0; i < words.Length; i++) BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(i * 2), words[i]);
        return bytes;
    }
    static void Reject(Action action, Action<bool, string> check, string name) {
        bool rejected = false;
        try { action(); } catch (InvalidDataException) { rejected = true; }
        check(rejected, name);
    }
    static byte[] Texture(bool aligned, bool overlay = false, bool linearClut = false) {
        int head = aligned ? 128 : 16, size = overlay ? 256 : 512;
        int pixels = size * size / (overlay ? 2 : 1), colors = overlay ? 16 : 256;
        byte[] result = new byte[head + 48 + pixels + colors * 4];
        "TIM2"u8.CopyTo(result); result[4] = 4; result[5] = aligned ? (byte)1 : (byte)0;
        BinaryPrimitives.WriteUInt16LittleEndian(result.AsSpan(6), 1);
        BinaryPrimitives.WriteUInt32LittleEndian(result.AsSpan(head), (uint)(result.Length - head));
        BinaryPrimitives.WriteUInt32LittleEndian(result.AsSpan(head + 4), (uint)(colors * 4));
        BinaryPrimitives.WriteUInt32LittleEndian(result.AsSpan(head + 8), (uint)pixels);
        BinaryPrimitives.WriteUInt16LittleEndian(result.AsSpan(head + 12), 48);
        BinaryPrimitives.WriteUInt16LittleEndian(result.AsSpan(head + 14), (ushort)colors);
        result[head + 18] = linearClut ? (byte)0x83 : (byte)3;
        result[head + 19] = overlay ? (byte)4 : (byte)5;
        BinaryPrimitives.WriteUInt16LittleEndian(result.AsSpan(head + 20), (ushort)size);
        BinaryPrimitives.WriteUInt16LittleEndian(result.AsSpan(head + 22), (ushort)size);
        for (int y = 0; y < size; y++) for (int x = 0; x < size; x++) {
            int color = (x + y) % colors, p = y * size + x;
            if (overlay) result[head + 48 + p / 2] |= (byte)(color << ((p & 1) * 4));
            else result[head + 48 + p] = (byte)color;
        }
        for (int i = 0; i < colors; i++) {
            int p = head + 48 + pixels + i * 4;
            result[p] = (byte)i; result[p + 1] = (byte)(255 - i);
            result[p + 2] = (byte)(i ^ 0xa5); result[p + 3] = (byte)(i % 129);
        }
        return result;
    }
    static bool ExpectedPixels(byte[] actual, bool overlay, bool linearClut) {
        int width = overlay ? 256 : 172, height = overlay ? 174 : 116;
        if (actual.Length != width * height * 4) return false;
        for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) {
            int index = (x + y + (overlay ? 0 : 340 + 390)) % (overlay ? 16 : 256);
            if (!overlay && !linearClut) index = (index & ~24) | ((index & 8) << 1) | ((index & 16) >> 1);
            int p = (y * width + x) * 4;
            if (actual[p] != (byte)(index ^ 0xa5) || actual[p + 1] != 255 - index || actual[p + 2] != index ||
                actual[p + 3] != Math.Min(255, (index % 129) * 2)) return false;
        }
        return true;
    }

    internal static void Run(Action<bool, string> check) {
        check(GameControllerArtwork.DecompressOb(Words(0, 0x1234, 0xabcd)).SequenceEqual(Words(0x1234, 0xabcd)),
            "Controller OB decoder reads little-endian literals MSB-first");
        check(GameControllerArtwork.DecompressOb(Words(0x4000, 0x5678, (3 << 11) | 1)).SequenceEqual(
            Words(0x5678, 0x5678, 0x5678, 0x5678)), "Controller OB decoder supports overlapping word back references");
        check(GameControllerArtwork.DecompressOb(Words(0x8000, 3 << 11)).SequenceEqual(new byte[6]),
            "Controller OB decoder supports zero-filled runs");
        check(GameControllerArtwork.DecompressOb(Words(0x4000, 0x1234, 1, 35)).Length == 72,
            "Controller OB decoder supports extended run counts");
        check(GameControllerArtwork.DecompressOb(Words(0x4000, 0x1234, 0, 0xffff)).SequenceEqual(Words(0x1234)),
            "Controller OB decoder stops at its sentinel");
        foreach (byte[] invalid in new[] { Array.Empty<byte>(), new byte[3], Words(0), Words(0x8000, 1),
            Words(0x8000, (1 << 11) | 1), new byte[GameControllerArtwork.MaxDecodedBytes + 2] })
            Reject(() => GameControllerArtwork.DecompressOb(invalid), check,
                "Controller OB decoder rejects malformed or oversized compressed data");
        // Three groups of fifteen extended runs exceed the fixed four-megabyte ceiling.
        var bomb = new List<ushort>();
        for (int i = 0; i < 3; i++) {
            bomb.Add(0x7fff); bomb.Add(1);
            for (int run = 0; run < 15; run++) { bomb.Add(1); bomb.Add(65535); }
        }
        Reject(() => GameControllerArtwork.DecompressOb(Words(bomb.ToArray())), check,
            "Controller OB decoder bounds expanded data before allocation or copying");

        byte[] momo = new byte[28]; "MOMO"u8.CopyTo(momo);
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(4), 2);
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(8), 24);
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(12), 2);
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(16), 26);
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(20), 2);
        momo[26] = 0x42; momo[27] = 0x17;
        check(GameControllerArtwork.MomoMember(momo, 1).SequenceEqual(new byte[] { 0x42, 0x17 }),
            "Controller MOMO decoder selects the requested member");
        Reject(() => GameControllerArtwork.MomoMember(momo, 2), check, "Controller MOMO decoder bounds member indices");
        Reject(() => GameControllerArtwork.MomoMember(momo[..23], 1), check, "Controller MOMO decoder rejects truncated tables");
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(16), uint.MaxValue);
        Reject(() => GameControllerArtwork.MomoMember(momo, 1), check, "Controller MOMO decoder rejects overflowing extents");
        BinaryPrimitives.WriteUInt32LittleEndian(momo.AsSpan(16), 8);
        Reject(() => GameControllerArtwork.MomoMember(momo, 1), check, "Controller MOMO members cannot overlap their directory");

        foreach (bool aligned in new[] { false, true }) foreach (bool linear in new[] { false, true }) {
            check(ExpectedPixels(GameControllerArtwork.DecodeCrop(Texture(aligned, false, linear), 0), false, linear),
                "Controller TIM2 crop preserves BGRA, palette order, alpha and native coordinates");
            check(ExpectedPixels(GameControllerArtwork.DecodeCrop(Texture(aligned, true, linear), 0, true), true, linear),
                "Controller overlay decodes low-nibble-first IDX4 without an IDX8 palette swap");
        }
        byte[] first = Texture(false), second = Texture(true, false, true);
        check(GameControllerArtwork.DecodeCrop(first.Concat(second).ToArray(), 1).SequenceEqual(
            GameControllerArtwork.DecodeCrop(second, 0)), "Controller decoder traverses concatenated TIM2 files");
        byte[] multi = first.Concat(second[128..]).ToArray();
        BinaryPrimitives.WriteUInt16LittleEndian(multi.AsSpan(6), 2);
        check(GameControllerArtwork.DecodeCrop(multi, 1).SequenceEqual(GameControllerArtwork.DecodeCrop(second, 0)),
            "Controller decoder traverses multiple pictures in one TIM2 file");
        Reject(() => GameControllerArtwork.DecodeCrop(first, 1), check, "Controller decoder rejects missing images");
        Reject(() => GameControllerArtwork.DecodeCrop(first, -1), check, "Controller decoder rejects negative image indices");
        Reject(() => GameControllerArtwork.DecodeCrop(first[..^1], 0), check, "Controller decoder rejects truncated palettes");
        Reject(() => GameControllerArtwork.DecodeCrop(new byte[16], 0), check, "Controller decoder checks the TIM2 signature");
        foreach (int offset in new[] { 16, 20, 24, 28, 30, 34, 35, 36, 38 }) {
            byte[] invalid = (byte[])first.Clone();
            invalid[offset] = 0xff; invalid[offset + 1] = 0xff;
            Reject(() => GameControllerArtwork.DecodeCrop(invalid, 0), check,
                "Controller decoder rejects unsupported picture extents, dimensions and palette formats");
        }
        check(GameControllerArtwork.Load("", "file1", "") == null &&
            GameControllerArtwork.Load("missing-import", "file2", "") == null &&
            GameControllerArtwork.Load("missing-import", "unsupported", "") == null &&
            GameControllerArtwork.LoadOverlay("", "file1", "") == null,
            "Controller artwork requires a supported owned import");
    }

    static string PixelHash(BitmapSource image) {
        byte[] pixels = new byte[image.PixelWidth * image.PixelHeight * 4];
        image.CopyPixels(pixels, image.PixelWidth * 4, 0);
        return Convert.ToHexString(SHA256.HashData(pixels)).ToLowerInvariant();
    }

    // Opt-in integration checks. All resulting copyrighted pixels stay in the supplied private home.
    internal static void VerifyOwned(string file1Import, string file2Import, string home, Action<bool, string> check) {
        foreach (var (game, import, hash) in new[] {
            ("file1", file1Import, "11cf3a1cf939f3406e452ac062b8b2ddd06ba2939345557e7b28deb912a6193a"),
            ("file2", file2Import, "2f5a177c9165a8ad9d53f18a4ff1fee81af4d95269281a7a0c50b74dfdbf0da2") }) {
            foreach (bool overlay in new[] { false, true }) {
                string expected = overlay ? "7fc2dc3c017371fc06ef9184b3ae36733f85fac481c9f340b579a68110f6389b" : hash;
                BitmapSource? Load() => overlay ? GameControllerArtwork.LoadOverlay(import, game, home)
                                               : GameControllerArtwork.Load(import, game, home);
                var image = Load();
                check(image != null && image.IsFrozen && image.Format == PixelFormats.Bgra32 &&
                    image.PixelWidth == (overlay ? 256 : 172) && image.PixelHeight == (overlay ? 174 : 116) &&
                    PixelHash(image) == expected, game + (overlay ? " overlay" : " controller") + " owned pixel SHA256 " + expected);
                string cache = Path.Combine(home, "controller-artwork", game + (overlay ? "-overlay-v1.png" : "-controller-v1.png"));
                DateTime timestamp = File.GetLastWriteTimeUtc(cache);
                check(Load() is { } cached && PixelHash(cached) == expected && File.GetLastWriteTimeUtc(cache) == timestamp,
                    game + " controller artwork reuses verified PNG cache");
                File.WriteAllBytes(cache, new byte[] { 137, 80, 78 });
                check(Load() is { } repaired && PixelHash(repaired) == expected && new FileInfo(cache).Length > 24,
                    game + " controller artwork repairs a corrupt cache from owned source");
                var empty = BitmapSource.Create(overlay ? 256 : 172, overlay ? 174 : 116, 96, 96,
                    PixelFormats.Bgra32, null, new byte[(overlay ? 256 * 174 : 172 * 116) * 4], (overlay ? 256 : 172) * 4);
                var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(empty));
                using (var output = File.Create(cache)) encoder.Save(output);
                check(Load() is { } replaced && PixelHash(replaced) == expected,
                    game + " controller artwork rejects valid PNGs with incorrect pixel hashes");
            }
        }
        Reject(() => GameControllerArtwork.Load(file1Import, "file2", home), check,
            "Controller cache cannot authorize artwork for the wrong owned edition");
    }
}
