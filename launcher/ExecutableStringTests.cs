using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
internal static class ExecutableStringTests {
    public static void Run(Action<bool, string> check) {
        void Reject(Action action, string message) { try { action(); check(false, message); } catch (IOException) { check(true, message); } }
        foreach (string game in new[] { "file1", "file2" }) {
            uint address = game == "file1" ? 0x250f30u : 0x255c50u;
            ElfStringReferences.Entry Entry(uint addr, string text, string[] controls, string[] formats) {
                byte[] raw = Encoding.ASCII.GetBytes(text);
                return new("test", 0, $"0x{addr:X8}", "ui-region-candidate", text, null, "cp932", raw.Length, 1,
                    Convert.ToHexString(raw).ToLowerInvariant(), Convert.ToHexString(SHA256.HashData(raw)).ToLowerInvariant(), 0, true, controls, formats, true, new());
            }
            var original = Entry(address, "SINGLE PLAY", Array.Empty<string>(), Array.Empty<string>());
            var tagged = Entry(address + 32, "<p1>Use %s?", new[] { "<p1>" }, new[] { "%s" });
            var reference = new ElfStringReferences.Reference(new(), new() { original, tagged }, 2);
            ExecutableStringReplacement Value(string? text = "PAK CHECK", uint? at = null) => new() {
                Address = $"0x{at ?? address:X8}", MaxBytes = original.MaxBytes, BaseSha256 = original.OriginalSha256, Text = text };
            AssetPakManifest Pack(params ExecutableStringReplacement[] values) => new() {
                Format = 1, Id = "test.strings", Name = "String fixture", Version = "1", Game = game, ElfSha256 = DiscImport.ExpectedElf(game), Strings = values.ToList() };
            var manifest = Pack(Value());
            string Json(AssetPakManifest value) => JsonSerializer.Serialize(value, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase });
            check(AssetPaks.Parse(Json(manifest)).Replace.Count == 0, game + " supports string-only PAK manifests");
            var patches = ExecutableStrings.Build(new[] { manifest }, reference);
            check(patches.Count == 1 && Encoding.ASCII.GetString(patches[0].Replacement) == "PAK CHECK" && patches[0].Original.Length == 11,
                game + " creates bounded executable string replacements");
            check(ExecutableStrings.Build(new[] { Pack(Value("SINGLE PLAY")) }, reference).Count == 0, game + " ignores unchanged string values");
            check(ExecutableStrings.Build(new[] { Pack(Value("")) }, reference).Single().Replacement.Length == 0, game + " permits explicitly clearing a string within its slot");
            Reject(() => ExecutableStrings.Build(new[] { Pack(Value("TOO LONG FOR SLOT")) }, reference), game + " rejects oversized encoded translations");
            Reject(() => ExecutableStrings.Build(new[] { Pack(Value("bad\0text")) }, reference), game + " rejects embedded NULs");
            Reject(() => ExecutableStrings.Build(new[] { Pack(Value("\u00e1")) }, reference), game + " rejects characters missing from CP932 without a byte mapping");
            Reject(() => ExecutableStrings.Build(new[] { Pack(Value(at: address - 1)) }, reference), game + " rejects addresses outside known string boundaries");
            var badHash = Value(); badHash.BaseSha256 = new string('0', 64);
            Reject(() => ExecutableStrings.Build(new[] { Pack(badHash) }, reference), game + " rejects a changed original string identity");
            var badBudget = Value(); badBudget.MaxBytes++;
            Reject(() => ExecutableStrings.Build(new[] { Pack(badBudget) }, reference), game + " rejects borrowing adjacent padding");
            Reject(() => ExecutableStrings.Build(new[] { manifest, manifest }, reference), game + " rejects conflicts across enabled PAKs");
            Reject(() => AssetPaks.Parse(Json(Pack(Value(), Value()))), game + " rejects duplicate string targets inside a PAK");
            var hex = Value(null); hex.BytesHex = "50414b";
            check(ExecutableStrings.Build(new[] { Pack(hex) }, reference).Single().Replacement.SequenceEqual("PAK"u8.ToArray()), game + " supports explicit encoded translation bytes");
            hex.Text = "also text";
            Reject(() => AssetPaks.Parse(Json(Pack(hex))), game + " rejects ambiguous text and bytesHex fields");
            var tag = new ExecutableStringReplacement { Address = tagged.Address, MaxBytes = tagged.MaxBytes, BaseSha256 = tagged.OriginalSha256, Text = "<p1>Get %s!" };
            check(ExecutableStrings.Build(new[] { Pack(tag) }, reference).Count == 1, game + " accepts translated text with preserved control and format tokens");
            tag.Text = "<p1>Get %n!";
            Reject(() => ExecutableStrings.Build(new[] { Pack(tag) }, reference), game + " rejects changed printf argument types");
            tag.Text = "Get %s!";
            Reject(() => ExecutableStrings.Build(new[] { Pack(tag) }, reference), game + " rejects removed formatting controls");
            using var cancel = new CancellationTokenSource(); cancel.Cancel();
            try { ExecutableStrings.Build(new[] { manifest }, reference, cancel.Token); check(false, game + " string preparation honors cancellation"); }
            catch (OperationCanceledException) { check(true, game + " string preparation honors cancellation"); }
        }
        var rows = ReferencePakMods.Csv("id,translation\r\na,\"line 1\r\nline 2, \"\"quoted\"\"\"\r\n");
        check(rows.Count == 2 && rows[1][1] == "line 1\r\nline 2, \"quoted\"", "Edited reference CSV preserves embedded line breaks, commas and quotes");
        Reject(() => ReferencePakMods.Csv("id,translation\na,\"unterminated"), "Edited reference CSV rejects an unfinished quoted field");
    }
}
