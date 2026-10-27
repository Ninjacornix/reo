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
        byte[] config = Encoding.ASCII.GetBytes("BOOT2 = cdrom0:\\SLUS_207.65;1\r\nVER = 1.00\r\nVMODE = NTSC\r\n");
        config.CopyTo(image, 25 * 2048);
        DirectoryAt(20, Record(new byte[] { 0 }, 20, 2048, true),
                    Record(new byte[] { 1 }, 20, 2048, true),
                    Record("SLUS_207.65;1"u8.ToArray(), 21, elf.Length, false),
                    Record("HELLO.BIN;1"u8.ToArray(), 22, asset.Length, false),
                    Record("BIN"u8.ToArray(), 23, 2048, true),
                    Record("SYSTEM.CNF;1"u8.ToArray(), 25, config.Length, false));
        DirectoryAt(23, Record(new byte[] { 0 }, 23, 2048, true),
                    Record(new byte[] { 1 }, 20, 2048, true),
                    Record("ASSET.BIN;1"u8.ToArray(), 24, asset.Length, false));
        File.WriteAllBytes(iso, image);
        // clang-format on
        string expected = Convert.ToHexString(SHA256.HashData(elf)).ToLowerInvariant();
        using (var disc = new DiscImage(iso))
            check(disc.Entries.Count == 5 && disc.Entries.Any(e => e.Name == "BIN/ASSET.BIN"),
                  "Read nested ISO files without mounting");
        string cache = Path.Combine(home, "cache");
        var imported = DiscImport.Ensure(iso, GameDefinition.First, expected, home: cache)
                           .GetAwaiter()
                           .GetResult();
        check(!imported.Reused && imported.Files == 4 &&
                  File.ReadAllBytes(imported.Elf).SequenceEqual(elf),
              "Import writes original ELF and files");
        check(
            imported.Verification.Contains("NTSC-U v2.00"),
            "Executable hash establishes supported revision independently of SYSTEM.CNF VER=1.00");
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
        string wrongCache = Path.Combine(home, "wrong-revision");
        try {
            DiscImport.Ensure(iso, GameDefinition.First, new string('0', 64), home: wrongCache)
                .GetAwaiter()
                .GetResult();
        } catch (InvalidDataException error) {
            wrong = error.Message.Contains("Unsupported revision") &&
                    error.Message.Contains("NTSC-U v2.00") && !Directory.Exists(wrongCache);
        }
        check(wrong, "Unsupported game revision refused before extraction");
        byte[] original = image.ToArray();
        void RejectDisc(string label, string serial, string? boot, string expectedMessage, bool decoy = false) {
            image = original.ToArray();
            Array.Clear(image, 20 * 2048, 2048);
            var rows = new List<byte[]> { Record(Encoding.ASCII.GetBytes(serial + ";1"), 21,
                                                 elf.Length, false) };
            if (boot != null) {
                byte[] cnf = Encoding.ASCII.GetBytes(boot);
                Array.Clear(image, 25 * 2048, 2048);
                cnf.CopyTo(image, 25 * 2048);
                rows.Add(Record(Encoding.ASCII.GetBytes("SYSTEM.CNF;1"), 25, cnf.Length, false));
            }
            if (decoy)
                rows.Add(Record(Encoding.ASCII.GetBytes("SLUS_207.65;1"), 21, elf.Length, false));
            DirectoryAt(20, rows.ToArray());
            // Deliberately misleading filename: identification must come from the disc contents.
            string variant = Path.Combine(home, label + " USA v2.00.iso");
            string rejectedCache = Path.Combine(home, "refused-" + label);
            File.WriteAllBytes(variant, image);
            string error = "";
            try {
                DiscImport.Ensure(variant, GameDefinition.First, expected, home: rejectedCache)
                    .GetAwaiter()
                    .GetResult();
            } catch (InvalidDataException rejected) {
                error = rejected.Message;
            }
            check(error.Contains(expectedMessage, StringComparison.OrdinalIgnoreCase) &&
                      error.Contains("NTSC-U v2.00") && !Directory.Exists(rejectedCache),
                  label + ": clear diagnosis before creating import files");
        }
        RejectDisc("PAL", "SLES_515.89", "BOOT2 = cdrom0:\\SLES_515.89;1\r\n",
                   "PAL (Europe/Australia)");
        RejectDisc("Japan", "SLPM_654.28", "BOOT2 = cdrom0:\\SLPM_654.28;1\r\n", "NTSC-J (Japan)");
        RejectDisc("Wrong-title", "SLUS_209.84", "BOOT2 = cdrom0:\\SLUS_209.84;1\r\n", "File #2");
        string secondIso = Path.Combine(home, "Wrong-title USA v2.00.iso");
        var secondDisc = DiscImport.Ensure(secondIso, GameDefinition.Second, expected,
                                          home: Path.Combine(home, "second-title"))
            .GetAwaiter().GetResult();
        check(File.Exists(secondDisc.Elf) && Path.GetFileName(secondDisc.Elf) == "SLUS_209.84" &&
                  secondDisc.Verification.Contains("File #2, NTSC-U v1.05"),
              "File #2 import uses its own serial and verification description");
        check(DiscImport.ExpectedElf(new Settings { SelectedGame = "file2" }, home) ==
                  DiscImport.SecondElfSha256 && DiscImport.SecondElfSha256 != DiscImport.FirstElfSha256,
              "File #2 has a pinned hash without needing a local reference ELF");
        bool secondRevisionRejected = false;
        try {
            using var secondImage = new DiscImage(secondIso);
            _ = DiscValidation.Check(secondImage, GameDefinition.Second, DiscImport.SecondElfSha256,
                                     CancellationToken.None);
        } catch (InvalidDataException error) {
            secondRevisionRejected = error.Message.Contains("Unsupported revision") &&
                                     error.Message.Contains("NTSC-U v1.05");
        }
        check(secondRevisionRejected, "Synthetic File #2 ELF cannot pass the real revision hash");
        RejectDisc("Unknown-title", "SLUS_123.45", "BOOT2 = cdrom0:\\SLUS_123.45;1\r\n",
                   "Unsupported game");
        RejectDisc("Decoy-USA-ELF", "SLES_515.89", "BOOT2 = cdrom0:\\SLES_515.89;1\r\n", "PAL",
                   true);
        RejectDisc("Missing-config", "SLUS_207.65", null, "SYSTEM.CNF");
        RejectDisc("Not-PS2", "SLUS_207.65", "BOOT = cdrom:\\SLUS_207.65;1\r\n", "BOOT2");
        RejectDisc("Missing-boot", "SLUS_207.65", "BOOT2 = cdrom0:\\MISSING.ELF;1\r\n",
                   "BOOT2 executable is missing");
        RejectDisc("Unsafe-boot", "SLUS_207.65", "BOOT2 = cdrom0:\\..\\SLUS_207.65;1\r\n",
                   "boot path");
        RejectDisc("Duplicate-boot", "SLUS_207.65",
                   "BOOT2 = cdrom0:\\SLUS_207.65;1\r\nBOOT2 = cdrom0:\\SLUS_207.65;1\r\n",
                   "one BOOT2");
        image = original;
        using (var cancel = new CancellationTokenSource()) {
            bool canceled = false;
            string canceledHome = Path.Combine(home, "cancel");
            try {
                DiscImport
                    .Ensure(iso, GameDefinition.First, expected, new InlineProgress(value => {
                                if (value.Stage == "Importing")
                                    cancel.Cancel();
                            }),
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
