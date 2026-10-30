using System.Globalization;
using System.IO;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
public sealed class ExecutableStringReplacement {
    public string Address { get; set; } = "";
    public int MaxBytes { get; set; }
    public bool UsePadding { get; set; }
    public string BaseSha256 { get; set; } = "";
    public string? Text { get; set; }
    public string? BytesHex { get; set; }
}
internal static class ExecutableStrings {
    internal const string Capability = "[EXECUTABLE-STRINGS-1]";
    internal const string PaddingCapability = "[EXECUTABLE-STRINGS-2]";
    internal const string PlanName = "executable-strings.bin";
    internal sealed record Patch(uint Address, byte[] Original, byte[] Replacement, string Pack, int Capacity);
    internal static string RequiredCapability(string plan) {
        using var input = File.OpenRead(plan); Span<byte> magic = stackalloc byte[8];
        input.ReadExactly(magic); return magic.SequenceEqual("REOSTR2\0"u8) ? PaddingCapability : Capability;
    }
    static void Require(bool value, string message) { if (!value) throw new IOException(message); }
    internal static uint Address(string value) {
        Require(value != null && Regex.IsMatch(value, @"\A(?:0x)?[0-9a-fA-F]{1,8}\z"), "Invalid executable string address.");
        return uint.Parse(value!.StartsWith("0x") ? value[2..] : value, NumberStyles.HexNumber, CultureInfo.InvariantCulture);
    }
    internal static void ValidateManifest(List<ExecutableStringReplacement> strings) {
        Require(strings != null && strings.Count <= 4096, "Too many executable string replacements.");
        var seen = new HashSet<uint>();
        foreach (var value in strings!) {
            Require(value != null, "Null executable string replacement.");
            Require(seen.Add(Address(value!.Address)), "Duplicate executable string address.");
            Require(value.MaxBytes is > 0 and <= 65535 && value.BaseSha256 != null && Regex.IsMatch(value.BaseSha256, @"\A[0-9a-fA-F]{64}\z"), "Invalid original string identity or byte budget.");
            Require((value.Text == null) != (value.BytesHex == null), "A string replacement needs either text or bytesHex.");
            Require(value.Text == null || (value.Text.Length <= 65535 && !value.Text.Contains('\0')), "Invalid executable string text.");
            Require(value.BytesHex == null || Regex.IsMatch(value.BytesHex, @"\A(?:[0-9a-fA-F]{2})*\z") && value.BytesHex.Length <= value.MaxBytes * 2,
                "Invalid encoded string bytes.");
        }
    }
    static string[] Tokens(string value, string pattern) => Regex.Matches(value, pattern).Select(m => m.Value).ToArray();
    internal static List<Patch> Build(IEnumerable<AssetPakManifest> packs, ElfStringReferences.Reference reference, CancellationToken cancel = default) {
        Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
        var encoding = Encoding.GetEncoding(932, EncoderFallback.ExceptionFallback, DecoderFallback.ExceptionFallback);
        var entries = reference.Entries.ToDictionary(e => Address(e.Address)); var owners = new Dictionary<uint, string>();
        var result = new List<Patch>(); long total = 0;
        foreach (var pack in packs) {
            ValidateManifest(pack.Strings);
            foreach (var value in pack.Strings) {
                cancel.ThrowIfCancellationRequested(); uint address = Address(value.Address);
                Require(entries.TryGetValue(address, out var original), "String target is outside the verified executable catalogue: " + value.Address);
                Require((value.UsePadding ? value.MaxBytes >= original!.MaxBytes && value.MaxBytes <= original.PaddingMaxBytes
                                          : original!.MaxBytes == value.MaxBytes) && original.OriginalSha256.Equals(value.BaseSha256, StringComparison.OrdinalIgnoreCase),
                        "Original executable string identity or verified padding budget differs: " + value.Address);
                Require(!owners.TryGetValue(address, out var owner), $"Pack {pack.Name} conflicts with {owner} at string {value.Address}."); owners.Add(address, pack.Name);
                byte[] bytes;
                try { bytes = value.Text != null ? encoding.GetBytes(value.Text) : Convert.FromHexString(value.BytesHex!); }
                catch (EncoderFallbackException e) { throw new IOException("Translation cannot be encoded as CP932; use verified font byte mappings via bytesHex.", e); }
                Require(bytes.Length <= value.MaxBytes && !bytes.Contains((byte)0), "Translation exceeds its original encoded byte budget or contains NUL: " + value.Address);
                string decoded;
                try { decoded = encoding.GetString(bytes); } catch (DecoderFallbackException e) { throw new IOException("Invalid CP932 translation byte sequence.", e); }
                Require(original.ControlTokens.SequenceEqual(Tokens(decoded, @"<[^>\r\n]+>")) && original.FormatTokens.SequenceEqual(Tokens(decoded,
                    @"%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%]")), "Translation must preserve formatting tags and printf arguments: " + value.Address);
                var raw = Convert.FromHexString(original.OriginalBytesHex);
                if (raw.AsSpan().SequenceEqual(bytes)) continue;
                total += value.MaxBytes + bytes.Length; Require(total <= 1024 * 1024 && result.Count < 4096, "Executable string plan exceeds limits.");
                result.Add(new(address, raw, bytes, pack.Id, value.MaxBytes));
            }
        }
        return result;
    }
    internal static void Prepare(List<AssetPakManifest> packs, string elf, string game, string session, CancellationToken cancel) {
        if (!packs.Any(p => p.Strings.Count > 0)) return;
        var patches = Build(packs, ElfStringReferences.Read(elf, game, cancel), cancel);
        if (patches.Count == 0) return;
        Directory.CreateDirectory(session);
        bool padded = patches.Any(p => p.Capacity > p.Original.Length);
        using (var output = new BinaryWriter(File.Create(Path.Combine(session, PlanName)))) {
            output.Write(Encoding.ASCII.GetBytes(padded ? "REOSTR2\0" : "REOSTR1\0")); output.Write(game == "file1" ? 1u : 2u);
            output.Write(Convert.FromHexString(DiscImport.ExpectedElf(game))); output.Write((uint)patches.Count);
            foreach (var patch in patches.OrderBy(p => p.Address)) {
                output.Write(patch.Address); output.Write((uint)patch.Original.Length);
                if (padded) output.Write((uint)patch.Capacity);
                output.Write((uint)patch.Replacement.Length);
                output.Write(patch.Original); output.Write((byte)0); output.Write(patch.Replacement);
            }
        }
        File.WriteAllText(Path.Combine(session, "executable-strings.json"), JsonSerializer.Serialize(new { format = 1, game,
            replace = patches.Select(p => new { address = $"0x{p.Address:X8}", originalBytes = p.Original.Length, maxBytes = p.Capacity,
                usePadding = p.Capacity > p.Original.Length, bytesHex = Convert.ToHexString(p.Replacement).ToLowerInvariant(), pack = p.Pack }) },
            new JsonSerializerOptions { WriteIndented = true }));
    }
}
