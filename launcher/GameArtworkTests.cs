using System.IO;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

internal static class GameArtworkTests {
    internal static void Run(Action<bool, string> check) {
        foreach (var (edition, serial, region) in new[] {
            (1, "SLUS_207.65", "ntsc-u"), (1, "SLES_515.89", "pal"),
            (1, "SLPM_654.28", "ntsc-j"), (1, "SLPM_742.01", "ntsc-j"),
            (2, "SLUS_209.84", "ntsc-u"), (2, "SLES_533.19", "pal"),
            (2, "SLPM_656.92", "ntsc-j") }) {
            var found = GameArtwork.FromBootConfig(edition,
                $"\uFEFFBOOT2 = cdrom0:\\{serial};1\r\nVER = 1.00\r\n");
            check(found.Region == region && found.Serial == serial.Replace('_', '-').Replace(".", ""),
                  "Cover selection identifies " + serial + " from boot metadata");
        }
        check(GameArtwork.FromBootConfig(1, "BOOT2 = cdrom0:\\SLUS_209.84;1") ==
                  GameArtwork.DefaultIdentity(1) &&
              GameArtwork.FromBootConfig(2, "BOOT2 = cdrom0:\\..\\SLES_533.19;1") ==
                  GameArtwork.DefaultIdentity(2),
              "Wrong-game and unsafe boot metadata cannot select another game's artwork");
        check(GameArtwork.DiscIdentity(2, "") == GameArtwork.DefaultIdentity(2),
              "Missing ISO defaults artwork to the game's NTSC-U edition");

        string root = Path.Combine(Path.GetTempPath(), "reo-artwork-" + Guid.NewGuid().ToString("N"));
        string personal = Path.Combine(root, "personal"), bundled = Path.Combine(root, "bundled");
        Directory.CreateDirectory(personal);
        Directory.CreateDirectory(bundled);
        try {
            string invalidDisc = Path.Combine(root, "invalid.iso");
            File.WriteAllText(invalidDisc, "not a disc image");
            check(GameArtwork.DiscIdentity(2, invalidDisc) == GameArtwork.DefaultIdentity(2),
                  "An invalid ISO safely falls back to the edition's default artwork");
            void Write(string folder, string name, byte red, byte green, byte blue) {
                var pixels = new byte[] { blue, green, red, 255 };
                var bitmap = BitmapSource.Create(1, 1, 96, 96, PixelFormats.Bgra32, null, pixels, 4);
                var encoder = new PngBitmapEncoder();
                encoder.Frames.Add(BitmapFrame.Create(bitmap));
                using var output = File.Create(Path.Combine(folder, name));
                encoder.Save(output);
            }
            bool IsColor(BitmapSource? image, byte red, byte green, byte blue) {
                if (image == null) return false;
                var converted = new FormatConvertedBitmap(image, PixelFormats.Bgra32, null, 0);
                var pixel = new byte[4];
                converted.CopyPixels(new System.Windows.Int32Rect(0, 0, 1, 1), pixel, 4, 0);
                return pixel.SequenceEqual(new byte[] { blue, green, red, 255 });
            }
            var pal = new GameArtwork.Identity("SLES-51589", "pal");
            var locations = new[] { personal, bundled };
            check(GameArtwork.LoadDiscArtwork(locations, 1, pal) == null,
                  "Missing disc label uses the procedural DVD fallback");
            Write(bundled, "file1-ntsc-u-disc.png", 255, 0, 0);
            check(IsColor(GameArtwork.LoadDiscArtwork(locations, 1, pal), 255, 0, 0),
                  "A missing regional disc label falls back to the downloaded NTSC-U label");
            Write(personal, "file1-disc.png", 0, 255, 0);
            Write(bundled, "SLES-51589-disc.png", 0, 0, 255);
            check(IsColor(GameArtwork.LoadDiscArtwork(locations, 1, pal), 0, 255, 0),
                  "Personal generic disc labels override cached labels");
            Write(personal, "SLES-51589-disc.png", 255, 255, 0);
            check(IsColor(GameArtwork.LoadDiscArtwork(locations, 1, pal), 255, 255, 0),
                  "Exact serial disc labels take priority within the personal folder");
            File.WriteAllText(Path.Combine(personal, "SLES-51589-disc.png"), "invalid");
            check(IsColor(GameArtwork.LoadDiscArtwork(locations, 1, pal), 0, 255, 0) &&
                      GameArtwork.LoadDiscArtwork(locations, 2, GameArtwork.DefaultIdentity(2)) == null,
                  "Corrupt disc labels fall back safely without using another game's label");
            Write(personal, "file1-cover.png", 0, 0, 255);
            Write(bundled, "file1-pal-cover.png", 255, 0, 0);
            Write(bundled, "file1-ntsc-u-cover.png", 255, 255, 255);
            check(IsColor(GameArtwork.LoadCover(locations, 1, pal), 255, 0, 0),
                  "Matching packaged regional art wins over generic fallback artwork");
            Write(personal, "file1-pal-cover.png", 0, 255, 0);
            check(IsColor(GameArtwork.LoadCover(locations, 1, pal), 0, 255, 0),
                  "Personal artwork overrides the same packaged regional cover");
            Write(bundled, "SLES-51589-cover.png", 255, 255, 0);
            check(IsColor(GameArtwork.LoadCover(locations, 1, pal), 255, 255, 0),
                  "Exact installed-disc serial wins over broader regional artwork");
            File.WriteAllText(Path.Combine(bundled, "SLES-51589-cover.png"), "invalid image");
            check(IsColor(GameArtwork.LoadCover(locations, 1, pal), 0, 255, 0),
                  "A corrupt exact cover falls back to valid regional artwork");
            check(IsColor(GameArtwork.LoadCover(locations, 1, GameArtwork.DefaultIdentity(1)), 255, 255, 255),
                  "Without an installed ISO the NTSC-U cover is selected");
            check(GameArtwork.LoadCover(locations, 2, GameArtwork.DefaultIdentity(2)) == null,
                  "Missing artwork leaves the title-only case available");
            Write(bundled, "file1-pal-back.png", 0, 0, 255);
            Write(bundled, "file1-pal-spine.png", 255, 255, 0);
            var panels = GameArtwork.LoadCaseArtwork(locations, 1, pal);
            check(IsColor(panels?.Front, 0, 255, 0) && IsColor(panels?.Back, 0, 0, 255) &&
                      IsColor(panels?.Spine, 255, 255, 0),
                  "Separate regional front, back and spine images reach the matching case faces");
            var spread = new byte[284 * 190 * 4];
            for (int y = 0; y < 190; ++y)
                for (int x = 0; x < 284; ++x) {
                    int offset = (y * 284 + x) * 4;
                    spread[offset + (x < 135 ? 0 : x < 149 ? 1 : 2)] = 255;
                    spread[offset + 3] = 255;
                }
            var spreadBitmap = BitmapSource.Create(284, 190, 96, 96, PixelFormats.Bgra32,
                                                   null, spread, 284 * 4);
            var spreadEncoder = new PngBitmapEncoder();
            spreadEncoder.Frames.Add(BitmapFrame.Create(spreadBitmap));
            using (var output = File.Create(Path.Combine(bundled, "file2-ntsc-u-wrap.png")))
                spreadEncoder.Save(output);
            var wrapped = GameArtwork.LoadCaseArtwork(locations, 2, GameArtwork.DefaultIdentity(2));
            check(IsColor(wrapped?.Front, 255, 0, 0) && IsColor(wrapped?.Back, 0, 0, 255) &&
                      IsColor(wrapped?.Spine, 0, 255, 0) && wrapped?.Spine?.PixelWidth == 14,
                  "Full DVD cover spread maps back, spine and front without stretching the whole sheet");
            string layout = Path.Combine(bundled, "file2-ntsc-u-wrap.json");
            File.WriteAllText(layout,
                "{\"front\":[0,0,135,190],\"back\":[149,0,135,190],\"spine\":[135,0,14,190]}");
            var custom = GameArtwork.LoadCaseArtwork(locations, 2, GameArtwork.DefaultIdentity(2));
            check(IsColor(custom?.Front, 0, 0, 255) && IsColor(custom?.Back, 255, 0, 0),
                  "Full-cover crop metadata controls which original image region reaches each face");
            File.WriteAllText(layout,
                "{\"front\":[0,0,99999,190],\"back\":[149,0,135,190],\"spine\":[135,0,14,190]}");
            check(GameArtwork.LoadCaseArtwork(locations, 2, GameArtwork.DefaultIdentity(2)) == null,
                  "Out-of-bounds full-cover crop metadata is rejected without breaking the launcher");
        } finally {
            string full = Path.GetFullPath(root);
            if (full.StartsWith(Path.GetFullPath(Path.GetTempPath()), StringComparison.OrdinalIgnoreCase) &&
                Path.GetFileName(full).StartsWith("reo-artwork-", StringComparison.Ordinal))
                Directory.Delete(full, true);
        }
    }
}
