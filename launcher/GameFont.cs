using System.IO;
using System.Security.Cryptography;
using System.Windows.Media;

namespace Outbreak.Launcher;

// Decode the owned game's normal 20-dot Gothic font; no game font ships with us.
internal static class GameFont {
    internal const string FamilyName = "Outbreak Dialogue UI";
    internal static byte[] ReadAtlas(string import, string game) {
        var (index, expected) = game switch {
            "file1" => (553, "f0bbf9de1d7a2a96617ca96b7051f8f0de11691c9ab996383c05e28efec5e2d1"),
            "file2" => (581, "1afb94d38e1bb5b7506479a48e7484f8d6d8b10f24fccf6f090d2fd0f3011df8"),
            _ => throw new InvalidDataException("Unsupported font edition.")
        };
        using var stream = File.OpenRead(Path.Combine(import, "data", "NETBIO00.DAT"));
        var rom = BackgroundVideos.Entry(stream, new(0, stream.Length), 0);
        var font = BackgroundVideos.Entry(stream, rom, index);
        if (font.Length != 780800) throw new InvalidDataException("Unexpected game font size.");
        byte[] bytes = new byte[(int)font.Length];
        stream.Position = font.Offset; stream.ReadExactly(bytes);
        if (!Convert.ToHexString(SHA256.HashData(bytes)).Equals(expected, StringComparison.OrdinalIgnoreCase))
            throw new InvalidDataException("Unsupported game font data.");
        return bytes;
    }
    internal static int GlyphIndex(char ascii) {
        if (ascii < 32 || ascii > 126) throw new ArgumentOutOfRangeException(nameof(ascii));
        System.Text.Encoding.RegisterProvider(System.Text.CodePagesEncodingProvider.Instance);
        // The table is in Shift-JIS double-byte order, with the 0x7f trail omitted.
        char full = ascii switch { ' ' => '\u3000', '\'' => '\u2019', '"' => '\u201d',
            _ => (char)(ascii + 0xfee0) };
        byte[] code = System.Text.Encoding.GetEncoding(932, System.Text.EncoderFallback.ExceptionFallback,
            System.Text.DecoderFallback.ExceptionFallback).GetBytes(new[] { full });
        if (code.Length != 2) throw new InvalidDataException("Missing double-byte font character.");
        int lead = code[0] < 0xa0 ? code[0] - 0x81 : code[0] - 0xc1;
        int index = lead * 188 + code[1] - 0x40 - (code[1] > 0x7f ? 1 : 0);
        if (index < 0 || index >= 7808) throw new InvalidDataException("Font character outside table.");
        return index;
    }
    internal static byte[,,] Decode(byte[] data) {
        if (data.Length != 780800) throw new InvalidDataException("Invalid 20-dot game font length.");
        var result = new byte[95, 20, 20];
        for (int code = 32; code <= 126; code++) {
            int offset = GlyphIndex((char)code) * 100;
            for (int y = 0; y < 20; y++) for (int x = 0; x < 20; x++)
                result[code - 32, x, y] = (byte)((data[offset + y * 5 + x / 4] >> (6 - 2 * (x % 4))) & 3);
        }
        return result;
    }
    internal static string Ensure(string import, string game, string home) {
        byte[] font = BitmapTypeface.Build(Decode(ReadAtlas(import, game)), FamilyName);
        string folder = Path.Combine(home, "game-fonts"), path = Path.Combine(folder, "dialogue-gothic-v2.ttf");
        Directory.CreateDirectory(folder);
        if (!File.Exists(path) || new FileInfo(path).Length != font.Length ||
            !File.ReadAllBytes(path).AsSpan().SequenceEqual(font)) {
            string pending = path + "." + Guid.NewGuid().ToString("N") + ".tmp";
            try { File.WriteAllBytes(pending, font); File.Move(pending, path, true); }
            finally { if (File.Exists(pending)) File.Delete(pending); }
        }
        return path;
    }
    internal static FontFamily Load(string path) => new(new Uri(Path.GetDirectoryName(path)! +
        Path.DirectorySeparatorChar), "./" + Path.GetFileName(path) + "#" + FamilyName);
}
