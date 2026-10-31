using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

// Platform-neutral catalogue code is shared directly with the Windows launcher.
internal static class DiscImport {
    internal static string ExpectedElf(string game) => game switch {
        "file1" => "SLUS_207.65", "file2" => "SLUS_209.84",
        _ => throw new ArgumentException("Unknown game")
    };
}

internal static class Program {
    static int Main(string[] args) {
        try {
            if (args.Length == 1 && args[0] == "--self-test") {
                int checks = 0;
                GlobalWeaponMotionsTests.Run((ok, message) => {
                    checks++; if (!ok) throw new IOException(message);
                });
                Console.WriteLine($"PASS shared motion checks={checks}"); return 0;
            }
            if (args.Length != 3 || args[0] != "catalogue")
                throw new ArgumentException("Usage: AssetHelper catalogue DISC_DIRECTORY OUTPUT_DIRECTORY");
            string disc = Path.GetFullPath(args[1]), output = Path.GetFullPath(args[2]);
            using (var elf = File.OpenRead(Path.Combine(disc, "SLUS_207.65"))) {
                if (Convert.ToHexString(SHA256.HashData(elf)).ToLowerInvariant() !=
                    "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46")
                    throw new IOException("Unsupported File #1 executable");
            }
            Directory.CreateDirectory(output);
            Console.WriteLine(JsonSerializer.Serialize(new {
                catalogue = GlobalItemCatalogue.Prepare(disc, output, "file1")
            }));
            return 0;
        } catch (Exception error) {
            Console.Error.WriteLine(error.Message); return 1;
        }
    }
}
