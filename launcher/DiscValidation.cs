using System.IO;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

internal static class DiscValidation {
    internal const string Required = "Required: Outbreak File #1, NTSC-U v2.00 (SLUS-20765).";
    internal record Verified(DiscEntry Elf, string Sha256, string Description);
    // Disc serial facts: PCSX2 bin/resources/GameIndex.yaml; these identify editions, not revisions.
    static readonly Dictionary<string, string> Titles =
        new() { ["SLUS-20765"] = "file1", ["SLES-51589"] = "file1", ["SLPM-65428"] = "file1",
                ["SLPM-74201"] = "file1", ["SLUS-20984"] = "file2", ["SLES-53319"] = "file2",
                ["SLPM-65692"] = "file2" };
    internal static Verified Check(DiscImage image, GameDefinition game, string expectedHash,
                                   CancellationToken cancel) {
        cancel.ThrowIfCancellationRequested();
        string required = game.Id == "file1"
                              ? Required
                              : "Required: the matching File #2 development executable.";
        InvalidDataException Reject(string message) => new(message + " " + required);
        var config = image.Entries.SingleOrDefault(
            e => !e.Directory && e.Name.Equals("SYSTEM.CNF", StringComparison.OrdinalIgnoreCase));
        if (config == null)
            throw Reject("This is not a bootable PS2 game ISO: SYSTEM.CNF is missing.");
        string text = image.ReadText(config, 16384).TrimStart('\uFEFF');
        var boots = Regex.Matches(
            text, @"(?im)^[ \t]*BOOT2[ \t]*=[ \t]*cdrom0?:[\\/]+([^ \t\r\n]+)[ \t]*\r?$",
            RegexOptions.None, TimeSpan.FromSeconds(1));
        if (boots.Count != 1)
            throw Reject("Invalid PS2 boot configuration: expected one BOOT2 entry in SYSTEM.CNF.");
        string path = boots[0].Groups[1].Value.Replace('\\', '/');
        if (path.EndsWith(";1", StringComparison.Ordinal))
            path = path[..^ 2];
        if (!Regex.IsMatch(path, @"^[A-Za-z0-9_.-]+(?:/[A-Za-z0-9_.-]+)*$", RegexOptions.None,
                           TimeSpan.FromSeconds(1)) ||
            path.Split('/').Any(p => p is "." or ".."))
            throw Reject("Invalid PS2 boot path in SYSTEM.CNF.");
        var elf = image.Entries.SingleOrDefault(
            e => !e.Directory && e.Name.Equals(path, StringComparison.OrdinalIgnoreCase));
        if (elf == null)
            throw Reject("The ISO is incomplete: its BOOT2 executable is missing.");
        var serialMatch = Regex.Match(Path.GetFileName(path).ToUpperInvariant(),
                                      @"^([A-Z]{4})_(\d{3})\.(\d{2})$");
        string serial = serialMatch.Success
                            ? serialMatch.Groups[1].Value + "-" + serialMatch.Groups[2].Value +
                                  serialMatch.Groups[3].Value
                            : "unknown serial";
        string region = serial[..Math.Min(serial.Length, 4)] switch {
            "SLUS" or "SCUS" => "NTSC-U (North America)",
            "SLES" or "SCES" => "PAL (Europe/Australia)",
            "SLPM" or "SLPS" or "SCPS" => "NTSC-J (Japan)",
            "SCAJ" or "SLKA" or "SCKA" => "NTSC-J (Asia)",
            _ => "unknown region"
        };
        Titles.TryGetValue(serial, out string? title);
        string detected = title == "file1"   ? "Outbreak File #1"
                          : title == "file2" ? "Outbreak File #2"
                                             : "PS2 disc";
        string identity = $"{detected}, {region}, {serial}";
        if (title == null)
            throw Reject("Unsupported game or edition detected: " + identity + ".");
        if (title != game.Id)
            throw Reject("Wrong game selected. Detected " + identity +
                         ". File #2 is not supported in this release.");
        if (!path.Equals(game.ElfName, StringComparison.OrdinalIgnoreCase))
            throw Reject("Unsupported region/edition. Detected " + identity + ".");
        string hash = image.Hash(elf, cancel);
        if (!hash.Equals(expectedHash, StringComparison.OrdinalIgnoreCase))
            throw Reject("Unsupported revision or modified/damaged executable. Detected " +
                         identity + "; its SHA-256 does not match the supported build.");
        // SYSTEM.CNF VER is boot metadata; only the executable hash establishes the supported revision.
        return new(elf, hash,
                   game.Id == "file1" ? "Verified: Outbreak File #1, NTSC-U v2.00 (SLUS-20765)."
                                      : "Verified: matching File #2 development executable.");
    }
}
