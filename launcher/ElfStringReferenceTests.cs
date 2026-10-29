using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
internal static class ElfStringReferenceTests {
    public static void Run(Action<bool, string> check) {
        check(ElfStringReferences.For("file1").Start != ElfStringReferences.For("file2").Start &&
            ElfStringReferences.For("file2").UiEnd > ElfStringReferences.For("file2").Start,
            "Executable references use distinct verified regions for both editions");
        foreach (string game in new[] { "file1", "file2" }) {
            byte[] data = new byte[512];
            void U16(int at, ushort value) => BinaryPrimitives.WriteUInt16LittleEndian(data.AsSpan(at), value);
            void U32(int at, uint value) => BinaryPrimitives.WriteUInt32LittleEndian(data.AsSpan(at), value);
            new byte[] { 0x7f, 69, 76, 70, 1, 1, 1 }.CopyTo(data, 0);
            U16(16, 2); U16(18, 8); U32(20, 1); U32(28, 52); U16(40, 52); U16(42, 32); U16(44, 1);
            U32(52, 1); U32(56, 128); U32(60, 0x100000); U32(68, 384); U32(72, 384); U32(128, 0x100020);
            var payload = Encoding.ASCII.GetBytes("  EQUIP\0<p1>Use %s?\n\0").Concat(new byte[] { 0x82, 0x61, 0x82, 0x51, 0x82, 0x65, 0 })
                .Concat(Encoding.ASCII.GetBytes("  EQUIP\0\u0001junk\0UNTERMINATED")).ToArray();
            payload.CopyTo(data, 160);
            string Hash(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
            var profile = new ElfStringReferences.Profile(160, 160 + payload.Length, 160 + payload.Length);
            var result = ElfStringReferences.Extract(data, game, profile, Hash(data)); var entries = result.Entries;
            check(entries.Count == 4 && result.UiCount == 4, game + " excludes binary/truncated runs without losing duplicate strings");
            check(entries[0].Address == "0x00100020" && entries[0].LiteralAddressWordFileOffsets.SequenceEqual(new[] { "0x00000080" }),
                game + " string addresses and pointer words follow ELF mapping");
            check(entries[0].OriginalText == "  EQUIP" && entries[0].MaxBytes == 7 && entries[0].TerminatorBytes == 1,
                game + " string byte budget preserves leading spaces and excludes the NUL");
            check(entries[1].ControlTokens.SequenceEqual(new[] { "<p1>" }) && entries[1].FormatTokens.SequenceEqual(new[] { "%s" }) && entries[1].OriginalText.EndsWith('\n'),
                game + " string references preserve controls, printf tokens and line breaks");
            check(entries[2].MaxBytes == 6 && entries[2].OriginalText.Length == 3 && entries.All(e => e.SourceTextRoundTrips),
                game + " CP932 budget counts bytes instead of Unicode characters");
            check(entries[0].Id != entries[3].Id && entries[0].OriginalText == entries[3].OriginalText,
                game + " identical string values keep independent addresses");
            check(entries.All(e => data.AsSpan(e.FileOffset, e.MaxBytes).SequenceEqual(Convert.FromHexString(e.OriginalBytesHex)) &&
                result.Files["originals.bin"].AsSpan(e.OriginalsOffset, e.MaxBytes + 1).SequenceEqual(data.AsSpan(e.FileOffset, e.MaxBytes + 1))),
                game + " every original byte and terminator matches the source");
            using (var header = JsonDocument.Parse(result.Files["string-reference.json"])) {
                var h = header.RootElement;
                check(h.GetProperty("game").GetString() == game && h.GetProperty("runtimePatchSupported").GetBoolean() &&
                    h.GetProperty("files").EnumerateObject().All(p => p.Value.GetProperty("sha256").GetString() == Hash(result.Files[p.Name])),
                    game + " reference header identifies the edition and hashes all editing files");
            }
            using (var index = JsonDocument.Parse(result.Files["strings.json"]))
                check(index.RootElement.GetProperty("entries")[0].GetProperty("translation").ValueKind == JsonValueKind.Null &&
                    result.Files["ui-strings.csv"].AsSpan(0, 3).SequenceEqual(new byte[] { 0xef, 0xbb, 0xbf }),
                    game + " JSON leaves translations separate and CSV declares UTF-8");
            using var canceled = new CancellationTokenSource(); canceled.Cancel();
            try { ElfStringReferences.Extract(data, game, profile, Hash(data), canceled.Token); check(false, game + " string extraction honors cancellation"); }
            catch (OperationCanceledException) { check(true, game + " string extraction honors cancellation"); }
            try { ElfStringReferences.Extract(data, game, profile, new string('0', 64)); check(false, game + " string extraction rejects a wrong executable hash"); }
            catch (IOException) { check(true, game + " string extraction rejects a wrong executable hash"); }
            try { ElfStringReferences.Extract(data, game, profile with { Start = 161 }, Hash(data)); check(false, game + " string extraction rejects a range beginning inside a string"); }
            catch (IOException) { check(true, game + " string extraction rejects a range beginning inside a string"); }
            U32(68, 5000);
            try { ElfStringReferences.Extract(data, game, profile, Hash(data)); check(false, game + " string extraction rejects an invalid segment extent"); }
            catch (IOException) { check(true, game + " string extraction rejects an invalid segment extent"); }
        }
    }
}
