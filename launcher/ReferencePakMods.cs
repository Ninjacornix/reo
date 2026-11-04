using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
// Importing an edited export under Mods compiles only changed native assets and
// translation fields. The original game data remains the validated base.
internal static class ReferencePakMods {
    static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true };
    static void Require(bool ok, string message) { if (!ok) throw new IOException(message); }
    static JsonDocument Read(ZipArchive zip, string name, long max = 32 * 1024 * 1024) {
        var entry = zip.GetEntry(name); Require(entry != null && entry.Length <= max, "Missing or oversized reference metadata: " + name);
        using var input = entry!.Open(); return JsonDocument.Parse(input);
    }
    static string Hash(Stream input, CancellationToken cancel) {
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256); byte[] buffer = new byte[1024 * 1024]; int n;
        while ((n = input.Read(buffer)) > 0) { cancel.ThrowIfCancellationRequested(); hash.AppendData(buffer, 0, n); }
        return Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
    }
    internal static bool ConvertIfReference(string source, string folder, CancellationToken cancel) {
        using var zip = ZipFile.OpenRead(source);
        bool assets = zip.GetEntry(AssetExports.ReferenceHeader) != null, stringsOnly = zip.GetEntry("string-reference.json") != null;
        if (!assets && !stringsOnly) return false;
        Require(zip.Entries.Count <= 100000, "Too many exported PAK members.");
        var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var entry in zip.Entries) { GamePaks.Safe(entry.FullName); Require(names.Add(entry.FullName), "Duplicate exported PAK member."); }
        using var header = Read(zip, assets ? AssetExports.ReferenceHeader : "string-reference.json", 65536);
        string game = header.RootElement.GetProperty("game").GetString() ?? "";
        string expected = DiscImport.ExpectedElf(game);
        Require(header.RootElement.GetProperty("elfSha256").GetString() == expected, "Exported PAK targets another executable revision.");
        var changes = new List<AssetReplacement>(); var payloads = new List<(ZipArchiveEntry Entry, string Name)>(); long total = 0;
        if (assets) {
            using var index = Read(zip, "assets.json", 64 * 1024 * 1024);
            Require(index.RootElement.GetProperty("format").GetInt32() == 1 && index.RootElement.GetProperty("verified").GetBoolean(), "Invalid asset reference index.");
            var entries = index.RootElement.GetProperty("entries"); Require(entries.GetArrayLength() <= 200000, "Too many asset references.");
            var paths = new HashSet<string>(StringComparer.Ordinal);
            foreach (var item in entries.EnumerateArray()) {
                cancel.ThrowIfCancellationRequested();
                string path = item.GetProperty("path").GetString() ?? "", file = item.GetProperty("file").GetString() ?? "";
                Require(Regex.IsMatch(path, @"\ANETBIO0[012]\.DAT(?:/[0-9]+){1,4}\z") && paths.Add(path), "Invalid or duplicate exported asset path.");
                GamePaks.Safe(file); var member = zip.GetEntry(file); Require(member != null, "Exported asset is missing: " + file);
                string original = item.GetProperty("sha256").GetString() ?? "";
                Require(Regex.IsMatch(original, @"\A[0-9a-fA-F]{64}\z"), "Invalid original asset hash.");
                using var input = member!.Open(); string hash = Hash(input, cancel);
                if (hash.Equals(original, StringComparison.OrdinalIgnoreCase)) continue;
                Require(!file.EndsWith("_h.bin", StringComparison.OrdinalIgnoreCase) && member.Length <= AssetPaks.MaxEntry, "Room name tables and oversized replacements are unsupported.");
                total += member.Length; Require(total <= AssetPaks.MaxExpanded && changes.Count < 4096, "Edited PAK exceeds mod limits.");
                string name = $"files/{changes.Count:D5}.bin";
                changes.Add(new() { Path = path, File = name, BaseSha256 = original }); payloads.Add((member, name));
            }
        }
        string prefix = assets ? ElfStringReferences.Prefix : "";
        var originals = new Dictionary<string, JsonElement>(); var edits = new Dictionary<uint, ExecutableStringReplacement>();
        void Add(JsonElement entry, string? text, string? bytesHex, bool usePadding = false) {
            if (text == null && bytesHex == null) return;
            if (text != null && text == entry.GetProperty("originalText").GetString() || bytesHex != null &&
                bytesHex.Equals(entry.GetProperty("originalBytesHex").GetString(), StringComparison.OrdinalIgnoreCase)) return;
            var value = new ExecutableStringReplacement { Address = entry.GetProperty("address").GetString() ?? "", UsePadding = usePadding,
                MaxBytes = entry.GetProperty(usePadding ? "paddingMaxBytes" : "maxBytes").GetInt32(),
                BaseSha256 = entry.GetProperty("originalSha256").GetString() ?? "", Text = text, BytesHex = bytesHex };
            ExecutableStrings.ValidateManifest(new() { value }); uint address = ExecutableStrings.Address(value.Address);
            if (edits.TryGetValue(address, out var previous)) Require(JsonSerializer.Serialize(previous, Json) == JsonSerializer.Serialize(value, Json), "Conflicting translations in exported PAK.");
            edits[address] = value;
        }
        foreach (string name in new[] { "strings.json", "ui-strings.json" }) {
            if (zip.GetEntry(prefix + name) == null) continue;
            using var reference = Read(zip, prefix + name);
            Require(reference.RootElement.GetProperty("game").GetString() == game && reference.RootElement.GetProperty("elfSha256").GetString() == expected, "Wrong string reference edition.");
            foreach (var entry in reference.RootElement.GetProperty("entries").EnumerateArray()) {
                cancel.ThrowIfCancellationRequested(); string id = entry.GetProperty("id").GetString() ?? "";
                if (originals.TryGetValue(id, out var previous)) Require(previous.GetProperty("address").GetString() == entry.GetProperty("address").GetString() &&
                    previous.GetProperty("originalSha256").GetString() == entry.GetProperty("originalSha256").GetString(), "Conflicting original string identities.");
                originals[id] = entry.Clone();
                string? text = entry.TryGetProperty("translation", out var t) && t.ValueKind != JsonValueKind.Null ? t.GetString() : null;
                string? hex = entry.TryGetProperty("translationBytesHex", out var h) && h.ValueKind != JsonValueKind.Null ? h.GetString() : null;
                Add(entry, text, hex, entry.TryGetProperty("usePadding", out var padding) && padding.GetBoolean());
            }
        }
        foreach (string name in new[] { "ui-strings.csv", "candidates.csv" }) {
            if (zip.GetEntry(prefix + name) == null) continue;
            var member = zip.GetEntry(prefix + name)!; Require(member.Length <= 32 * 1024 * 1024, "Oversized string CSV.");
            using var reader = new StreamReader(member.Open(), Encoding.UTF8, true); var rows = Csv(reader.ReadToEnd());
            Require(rows.Count > 0 && rows[0].Distinct().Count() == rows[0].Count, "Invalid CSV header.");
            var columns = rows[0].Select((value, index) => (value, index)).ToDictionary(p => p.value, p => p.index);
            Require(new[] { "id", "address", "maxBytes", "originalText", "translation" }.All(columns.ContainsKey), "Missing CSV columns.");
            foreach (var row in rows.Skip(1)) {
                Require(row.Count == columns.Count, "Invalid CSV row."); string text = row[columns["translation"]]; if (text.Length == 0) continue;
                Require(originals.TryGetValue(row[columns["id"]], out var entry), "Keep original JSON references alongside edited CSV.");
                Require(row[columns["address"]] == entry.GetProperty("address").GetString() && row[columns["originalText"]] == entry.GetProperty("originalText").GetString() &&
                    int.TryParse(row[columns["maxBytes"]], NumberStyles.None, CultureInfo.InvariantCulture, out int max) && max == entry.GetProperty("maxBytes").GetInt32(), "Edited CSV changed original string identity.");
                bool usePadding = false;
                if (columns.TryGetValue("usePadding", out int column) && row[column].Length > 0)
                    Require(bool.TryParse(row[column], out usePadding), "usePadding must be true or false.");
                Add(entry, text, null, usePadding);
            }
        }
        Require(changes.Count + edits.Count is > 0 and <= 4096, "No changed assets or translations found. Original exports are for local editing; change payloads or translation fields first.");
        string identity; using (var input = File.OpenRead(source)) identity = Hash(input, cancel);
        var manifest = new AssetPakManifest { Format = 1, Game = game, ElfSha256 = expected, Id = "edited." + game + "." + identity[..16],
            Name = "Edited " + GameDefinition.Find(game).Name, Version = "1", Replace = changes, Strings = edits.Values.ToList() };
        _ = AssetPaks.Parse(JsonSerializer.Serialize(manifest, Json));
        string temp = Path.Combine(Path.GetTempPath(), "reo-reference-mod-" + Guid.NewGuid().ToString("N") + ".pak");
        try {
            using (var file = new FileStream(temp, FileMode.CreateNew, FileAccess.Write))
            using (var output = new ZipArchive(file, ZipArchiveMode.Create)) {
                using (var writer = new StreamWriter(output.CreateEntry("pak.json").Open())) writer.Write(JsonSerializer.Serialize(manifest, Json));
                foreach (var payload in payloads) {
                    using var input = payload.Entry.Open(); using var target = output.CreateEntry(payload.Name, CompressionLevel.Fastest).Open();
                    byte[] buffer = new byte[1024 * 1024]; int n; while ((n = input.Read(buffer)) > 0) { cancel.ThrowIfCancellationRequested(); target.Write(buffer, 0, n); }
                }
            }
            AssetPaks.Import(temp, folder, cancel); return true;
        } finally { if (File.Exists(temp)) File.Delete(temp); }
    }
    internal static List<List<string>> Csv(string text) {
        var rows = new List<List<string>>(); var row = new List<string>(); var cell = new StringBuilder(); bool quoted = false;
        for (int at = 0; at < text.Length; at++) {
            char c = text[at];
            if (c == '"') {
                if (quoted && at + 1 < text.Length && text[at + 1] == '"') { cell.Append('"'); at++; } else quoted = !quoted;
            } else if (!quoted && (c == ',' || c == '\r' || c == '\n')) {
                row.Add(cell.ToString()); cell.Clear(); Require(row.Count <= 64, "Too many CSV columns.");
                if (c != ',') { rows.Add(row); row = new(); if (c == '\r' && at + 1 < text.Length && text[at + 1] == '\n') at++; }
            } else cell.Append(c);
            Require(rows.Count <= 200000, "Too many CSV rows.");
        }
        Require(!quoted, "Unterminated CSV quote."); if (cell.Length > 0 || row.Count > 0) { row.Add(cell.ToString()); rows.Add(row); } return rows;
    }
}
