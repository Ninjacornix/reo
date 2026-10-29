using System.Buffers.Binary;
using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

// Translation references only. Nothing here changes guest executable memory.
internal static class ElfStringReferences {
    internal const string Prefix = "executable-strings/";
    internal sealed record Profile(int Start, int End, int UiEnd);
    internal sealed record Segment(int FileOffset, uint Address, int Bytes);
    internal sealed record Entry(string Id, int FileOffset, string Address, string Group, string OriginalText,
        string? Translation, string Encoding, int MaxBytes, int TerminatorBytes, string OriginalBytesHex,
        string OriginalSha256, int OriginalsOffset, bool SourceTextRoundTrips, string[] ControlTokens,
        string[] FormatTokens, bool NeedsManualReview, List<string> LiteralAddressWordFileOffsets);
    internal sealed record Reference(Dictionary<string, byte[]> Files, List<Entry> Entries, int UiCount);
    static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true };
    static readonly Encoding Sjis = CreateEncoding();
    static Encoding CreateEncoding() {
        Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
        return Encoding.GetEncoding(932, EncoderFallback.ExceptionFallback, DecoderFallback.ExceptionFallback);
    }
    static void Require(bool valid, string message) { if (!valid) throw new IOException(message); }
    static string Hash(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
    static byte[] JsonBytes(object value) => Encoding.UTF8.GetBytes(JsonSerializer.Serialize(value, Json) + "\n");
    static uint U32(byte[] bytes, int at) => BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(at, 4));
    static ushort U16(byte[] bytes, int at) => BinaryPrimitives.ReadUInt16LittleEndian(bytes.AsSpan(at, 2));
    internal static Profile For(string game) => game switch {
        "file1" => new(0x150060, 0x159F80, 0x152E80),
        "file2" => new(0x1554D0, 0x169B80, 0x159DB0),
        _ => throw new IOException("Executable string references support File #1 and File #2.")
    };
    internal static Reference Read(string elf, string game, CancellationToken cancel = default) =>
        Extract(File.ReadAllBytes(elf), game, For(game), DiscImport.ExpectedElf(game), cancel);
    internal static Reference Extract(byte[] bytes, string game, Profile profile, string expected, CancellationToken cancel = default) {
        cancel.ThrowIfCancellationRequested();
        Require(Hash(bytes) == expected, "Executable string reference identity mismatch.");
        Require(bytes.Length >= 52 && bytes.AsSpan(0, 7).SequenceEqual(new byte[] { 0x7f, 69, 76, 70, 1, 1, 1 }) &&
            U16(bytes, 16) == 2 && U16(bytes, 18) == 8 && U16(bytes, 40) == 52 && U16(bytes, 42) == 32,
            "String references need a little-endian MIPS ELF32 executable.");
        uint table = U32(bytes, 28); int count = U16(bytes, 44);
        Require(count is > 0 and <= 256 && table >= 52 && table + (ulong)count * 32 <= (ulong)bytes.Length, "Invalid ELF program table.");
        var segments = new List<Segment>();
        for (int i = 0; i < count; i++) {
            int at = (int)table + i * 32;
            uint offset = U32(bytes, at + 4), address = U32(bytes, at + 8), size = U32(bytes, at + 16), memory = U32(bytes, at + 20);
            if (U32(bytes, at) != 1 || size == 0) continue;
            Require(size <= memory && offset + (ulong)size <= (ulong)bytes.Length && address + (ulong)memory <= 0x100000000UL,
                "Invalid file-backed ELF segment.");
            Require(!segments.Any(s => offset < (long)s.FileOffset + s.Bytes && s.FileOffset < offset + (long)size), "Ambiguous ELF file ranges.");
            segments.Add(new((int)offset, address, (int)size));
        }
        int start = profile.Start, end = profile.End;
        Require(start > 0 && start < end && end <= bytes.Length && bytes[start - 1] == 0 && profile.UiEnd > start && profile.UiEnd <= end,
            "Invalid executable string range.");
        var containing = segments.Where(s => s.FileOffset <= start && end <= (long)s.FileOffset + s.Bytes).ToList();
        Require(containing.Count == 1, "String range is not within one file-backed ELF segment.");
        var segment = containing[0]; var entries = new List<Entry>(); using var originals = new MemoryStream();
        for (int position = start; position < end;) {
            cancel.ThrowIfCancellationRequested();
            int stop = Array.IndexOf(bytes, (byte)0, position, end - position); if (stop < 0) break;
            var raw = bytes.AsSpan(position, stop - position).ToArray(); string text;
            try { text = Sjis.GetString(raw); } catch (DecoderFallbackException) { text = ""; }
            if (text.Length >= 2 && text.All(Printable) && Regex.IsMatch(text, "[A-Za-z]{2}|[^\\x00-\\x7f]{2}")) {
                uint address = segment.Address + (uint)(position - segment.FileOffset);
                entries.Add(new($"elf-{address:X8}", position, $"0x{address:X8}", position < profile.UiEnd ? "ui-region-candidate" : "other-candidate",
                    text, null, "cp932", raw.Length, 1, Convert.ToHexString(raw).ToLowerInvariant(), Hash(raw), (int)originals.Length,
                    Sjis.GetBytes(text).AsSpan().SequenceEqual(raw), Tokens(text, @"<[^>\r\n]+>"),
                    Tokens(text, @"%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%]"), true, new()));
                originals.Write(raw); originals.WriteByte(0);
            }
            position = stop + 1;
        }
        Require(entries.Count > 0, "No executable string candidates found.");
        var addresses = entries.ToDictionary(e => uint.Parse(e.Address[2..], NumberStyles.HexNumber, CultureInfo.InvariantCulture));
        foreach (var source in segments) {
            int limit = (source.FileOffset + source.Bytes) & ~3;
            for (int at = (source.FileOffset + 3) & ~3; at < limit; at += 4) {
                if ((at & 0xffff) == 0) cancel.ThrowIfCancellationRequested();
                if (addresses.TryGetValue(U32(bytes, at), out var entry)) entry.LiteralAddressWordFileOffsets.Add($"0x{at:X8}");
            }
        }
        var ui = entries.Where(e => e.Group == "ui-region-candidate").ToList();
        var files = new Dictionary<string, byte[]> {
            ["strings.json"] = JsonBytes(new { format = 1, game, elfSha256 = expected, entries }),
            ["ui-strings.json"] = JsonBytes(new { format = 1, game, elfSha256 = expected, entries = ui }),
            ["ui-strings.csv"] = Csv(ui), ["candidates.csv"] = Csv(entries), ["originals.bin"] = originals.ToArray(),
            ["README.txt"] = Encoding.UTF8.GetBytes(
                "Executable string editing reference for " + game + ".\n" +
                "Start with ui-strings.csv or ui-strings.json; enter translations separately.\n" +
                "Candidates need manual review. UI grouping is a location heuristic. The broader catalogue includes SDK diagnostics and resource names.\n" +
                "Addresses come from ELF PT_LOAD mapping. Literal address words are static pointer candidates, not verified call sites.\n" +
                "maxBytes counts original CP932/Shift-JIS-family bytes, excluding the NUL terminator; adjacent padding is not available.\n" +
                "Preserve original bytes, spaces, line breaks, formatting tags and printf arguments. Glyph/font mapping also needs verification.\n" +
                "originals.bin contains the indexed NUL-terminated original candidates. Keep original game text private.\n" +
                "This export does not implement runtime executable-string overrides. Editing these references does not change game text.\n")
        };
        files["string-reference.json"] = JsonBytes(new {
            format = 1, kind = "executable-string-reference", game, elf = GameDefinition.Find(game).ElfName, elfSha256 = expected,
            runtimePatchSupported = false, candidateCount = entries.Count, uiRegionCandidateCount = ui.Count,
            uiRegionCandidatesWithAddressWords = ui.Count(e => e.LiteralAddressWordFileOffsets.Count > 0), encoding = "cp932",
            range = new { fileStart = start, fileEndExclusive = end, uiFileEndExclusive = profile.UiEnd,
                addressStart = $"0x{segment.Address + (uint)(start - segment.FileOffset):X8}" },
            limitations = new[] { "Static byte extraction only; not a complete semantic UI catalogue.", "No pointer/call-site, glyph coverage or in-game translation verification." },
            files = files.ToDictionary(p => p.Key, p => new { bytes = p.Value.Length, sha256 = Hash(p.Value) })
        });
        return new(files, entries, ui.Count);
    }
    static bool Printable(char c) => c is ' ' or '\r' or '\n' or '\t' || char.GetUnicodeCategory(c) is not
        (UnicodeCategory.Control or UnicodeCategory.Format or UnicodeCategory.Surrogate or UnicodeCategory.PrivateUse or UnicodeCategory.OtherNotAssigned or
         UnicodeCategory.LineSeparator or UnicodeCategory.ParagraphSeparator or UnicodeCategory.SpaceSeparator);
    static string[] Tokens(string text, string pattern) => Regex.Matches(text, pattern).Select(m => m.Value).ToArray();
    static byte[] Csv(IEnumerable<Entry> entries) {
        static string Cell(string text) => "\"" + text.Replace("\"", "\"\"") + "\"";
        var result = new StringBuilder("id,address,fileOffset,maxBytes,encoding,literalAddressWordFileOffsets,originalText,translation\r\n");
        foreach (var entry in entries) result.Append(string.Join(",", new[] { entry.Id, entry.Address, $"0x{entry.FileOffset:X8}",
            entry.MaxBytes.ToString(CultureInfo.InvariantCulture), entry.Encoding, string.Join(";", entry.LiteralAddressWordFileOffsets), entry.OriginalText, "" }.Select(Cell))).Append("\r\n");
        return Encoding.UTF8.GetPreamble().Concat(Encoding.UTF8.GetBytes(result.ToString())).ToArray();
    }
    internal static void Write(ZipArchive zip, string elf, string game, CancellationToken cancel = default) {
        foreach (var (name, bytes) in Read(elf, game, cancel).Files) {
            cancel.ThrowIfCancellationRequested(); using var output = zip.CreateEntry(Prefix + name, CompressionLevel.Fastest).Open(); output.Write(bytes);
        }
    }
    internal static void Verify(ZipArchive zip, string elf, string game, CancellationToken cancel = default) {
        foreach (var (name, bytes) in Read(elf, game, cancel).Files) {
            cancel.ThrowIfCancellationRequested(); var member = zip.GetEntry(Prefix + name);
            Require(member != null && member.Length == bytes.Length, "Missing or incomplete executable string reference: " + name);
            using var input = member!.Open(); using var buffer = new MemoryStream(); input.CopyTo(buffer);
            Require(buffer.ToArray().AsSpan().SequenceEqual(bytes), "Executable string reference differs from its source: " + name);
        }
    }
}
