using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;
static class DiscImportTests {
    sealed class InlineProgress(Action<ImportProgress> report) : IProgress<ImportProgress> {
        public void Report(ImportProgress value) => report(value);
    }
    public static void Run(Action<bool, string> check) {
        string home =
            Path.Combine(Path.GetTempPath(), "reo-disc-test-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(home);
        string iso = Path.Combine(home, "Owned test disc.iso");
        byte[] image = new byte[40 * 2048];
        void Dual(byte[] bytes, int at, uint value) {
            BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(at), value);
            BinaryPrimitives.WriteUInt32BigEndian(bytes.AsSpan(at + 4), value);
        }
        byte[] Record(byte[] name, int lba, int size, bool directory) {
            var row = new byte[(33 + name.Length + 1) & ~1];
            row[0] = (byte)row.Length;
            row[25] = directory ? (byte)2 : (byte)0;
            row[32] = (byte)name.Length;
            Dual(row, 2, (uint)lba);
            Dual(row, 10, (uint)size);
            name.CopyTo(row, 33);
            return row;
        }
        void DirectoryAt(int lba, params byte[][] rows) {
            int at = lba * 2048;
            foreach (var row in rows) {
                row.CopyTo(image, at);
                at += row.Length;
            }
        }
        // LLVM 21 does not parse C# UTF-8 literal suffixes.
        // clang-format off
        int pvd = 16 * 2048;
        image[pvd] = 1;
        "CD001"u8.CopyTo(image.AsSpan(pvd + 1));
        image[pvd + 6] = 1;
        Dual(image, pvd + 80, 40);
        BinaryPrimitives.WriteUInt16LittleEndian(image.AsSpan(pvd + 128), 2048);
        BinaryPrimitives.WriteUInt16BigEndian(image.AsSpan(pvd + 130), 2048);
        Record(new byte[] { 0 }, 20, 2048, true).CopyTo(image, pvd + 156);
        byte[] elf = "test executable bytes"u8.ToArray(),
               asset = "saved disc payload"u8.ToArray();
        elf.CopyTo(image, 21 * 2048);
        asset.CopyTo(image, 22 * 2048);
        asset.CopyTo(image, 24 * 2048);
        DirectoryAt(20, Record(new byte[] { 0 }, 20, 2048, true),
                    Record(new byte[] { 1 }, 20, 2048, true),
                    Record("SLUS_207.65;1"u8.ToArray(), 21, elf.Length, false),
                    Record("HELLO.BIN;1"u8.ToArray(), 22, asset.Length, false),
                    Record("BIN"u8.ToArray(), 23, 2048, true));
        DirectoryAt(23, Record(new byte[] { 0 }, 23, 2048, true),
                    Record(new byte[] { 1 }, 20, 2048, true),
                    Record("ASSET.BIN;1"u8.ToArray(), 24, asset.Length, false));
        File.WriteAllBytes(iso, image);
        // clang-format on
        string expected = Convert.ToHexString(SHA256.HashData(elf)).ToLowerInvariant();
        using (var disc = new DiscImage(iso))
            check(disc.Entries.Count == 4 && disc.Entries.Any(e => e.Name == "BIN/ASSET.BIN"),
                  "Read nested ISO files without mounting");
        string cache = Path.Combine(home, "cache");
        var imported = DiscImport.Ensure(iso, GameDefinition.First, expected, home: cache)
                           .GetAwaiter()
                           .GetResult();
        check(!imported.Reused && imported.Files == 3 &&
                  File.ReadAllBytes(imported.Elf).SequenceEqual(elf),
              "Import writes original ELF and files");
        check(File.ReadAllBytes(Path.Combine(imported.Root, "data", "BIN", "ASSET.BIN"))
                  .SequenceEqual(asset),
              "Nested file bytes preserved");
        var reused = DiscImport.Ensure(iso, GameDefinition.First, expected, home: cache)
                         .GetAwaiter()
                         .GetResult();
        check(reused.Reused && reused.Root == imported.Root,
              "Second launch reuses completed import");
        File.Delete(Path.Combine(imported.Root, "data", "HELLO.BIN"));
        var repaired = DiscImport.Ensure(iso, GameDefinition.First, expected, home: cache)
                           .GetAwaiter()
                           .GetResult();
        check(!repaired.Reused && File.Exists(Path.Combine(repaired.Root, "data", "HELLO.BIN")),
              "Missing imported file is repaired before launch");
        byte[] changed = elf.ToArray();
        changed[0] ^= 1;
        File.WriteAllBytes(repaired.Elf, changed);
        repaired = DiscImport.Ensure(iso, GameDefinition.First, expected, home: cache)
                       .GetAwaiter()
                       .GetResult();
        check(!repaired.Reused && File.ReadAllBytes(repaired.Elf).SequenceEqual(elf),
              "Changed cached executable cannot bypass version check");
        bool wrong = false;
        try {
            DiscImport.Ensure(iso, GameDefinition.First, new string('0', 64), home: cache)
                .GetAwaiter()
                .GetResult();
        } catch (InvalidDataException) {
            wrong = true;
        }
        check(wrong, "Unsupported game revision refused before extraction");
        using (var cancel = new CancellationTokenSource()) {
            bool canceled = false;
            string canceledHome = Path.Combine(home, "cancel");
            try {
                DiscImport
                    .Ensure(iso, GameDefinition.First, expected,
                            new InlineProgress(
                                _ => cancel.Cancel()),
                            cancel.Token, canceledHome)
                    .GetAwaiter()
                    .GetResult();
            } catch (OperationCanceledException) {
                canceled = true;
            }
            check(canceled &&
                      !Directory
                           .EnumerateFiles(canceledHome, "import.json", SearchOption.AllDirectories)
                           .Any() &&
                      !Directory
                           .EnumerateDirectories(canceledHome, "*.import-*",
                                                 SearchOption.AllDirectories)
                           .Any(),
                  "Canceled import leaves no completed or partial installation");
        }
        string bad = Path.Combine(home, "invalid.iso");
        File.WriteAllBytes(bad, new byte[80]);
        bool invalid = false;
        try {
            using var disc = new DiscImage(bad);
        } catch (InvalidDataException) {
            invalid = true;
        }
        check(invalid, "Truncated ISO rejected");
        // clang-format off
        DirectoryAt(20, Record("../ESCAPE;1"u8.ToArray(), 21, elf.Length, false));
        // clang-format on
        File.WriteAllBytes(bad, image);
        invalid = false;
        try {
            using var disc = new DiscImage(bad);
        } catch (InvalidDataException) {
            invalid = true;
        }
        check(invalid, "Unsafe ISO filenames rejected before file creation");
        File.WriteAllText(Path.Combine(home, "distribution.json"), "{}");
        Directory.CreateDirectory(Path.Combine(home, "child"));
        check(AppLayout.FindRoot(Path.Combine(home, "child")) == home &&
                  AppLayout.Work(home, "file1")
                      .StartsWith(Settings.Home, StringComparison.OrdinalIgnoreCase),
              "Packaged launcher runs outside source tree and writes in user data");
    }
}
