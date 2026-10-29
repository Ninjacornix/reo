using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

public sealed class AssetPakManifest {
    public int Format { get; set; }
    public string Id { get; set; } = "";
    public string Name { get; set; } = "";
    public string Version { get; set; } = "";
    public string Description { get; set; } = "";
    public string Game { get; set; } = "";
    public string ElfSha256 { get; set; } = "";
    public List<AssetReplacement> Replace { get; set; } = new();
}
public sealed class AssetReplacement {
    public string Path { get; set; } = "";
    public string File { get; set; } = "";
    public string? BaseSha256 { get; set; }
}
public sealed record InstalledAssetPak(string File, AssetPakManifest? Manifest, string Error);
public sealed record AssetIndexEntry(string Path, string Name, long Offset, long Size, bool IsArchive);
public sealed record AssetArchive(string File, long Size, long LastWriteUtcTicks);
public sealed record AssetIndex(int Format, string Game, string ElfSha256,
                                List<AssetArchive> Archives, List<AssetIndexEntry> Entries);
public sealed record PreparedAsset(string Path, string File, long Size, string BaseSha256, string Sha256, string Pack);

public static class AssetPaks {
    sealed record CachedPayload(long Size, string Sha256);
    public const string Capability = "[ASSET-PAKS-1]";
    public const long MaxEntry = 256L * 1024 * 1024;
    public const long MaxExpanded = 2L * 1024 * 1024 * 1024;
    const int MaxManifest = 1024 * 1024;
    public static string Folder => Path.Combine(Settings.Home, "mods", "assets");
    static readonly JsonSerializerOptions Json = new() {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow
    };
    static void Require(bool condition, string message) { if (!condition) throw new IOException(message); }
    static bool HashValid(string? hash) => hash != null && Regex.IsMatch(hash, @"\A[0-9a-fA-F]{64}\z");
    static string Expected(string game) => game switch {
        "file1" => DiscImport.FirstElfSha256, "file2" => DiscImport.SecondElfSha256,
        _ => throw new IOException("Asset pack game must be file1 or file2.")
    };
    static string SafePath(string? path, bool directory = false) {
        Require(!string.IsNullOrEmpty(path) && path.Length <= 240 && !path.Contains('\\') &&
            !path.Contains(':') && !path.StartsWith('/') && !path.Any(char.IsControl), "Unsafe asset package path.");
        string value = directory ? path!.TrimEnd('/') : path!;
        Require(value.Split('/').All(p => p.Length > 0 && p is not ("." or "..") &&
            !p.EndsWith(' ') && !p.EndsWith('.') && p.IndexOfAny(new[] { '<', '>', '"', '|', '?', '*' }) < 0 &&
            !Regex.IsMatch(p, @"\A(?:CON|PRN|AUX|NUL|COM[1-9\u00b9\u00b2\u00b3]|LPT[1-9\u00b9\u00b2\u00b3])(?:\.|\z)", RegexOptions.IgnoreCase | RegexOptions.CultureInvariant)),
            "Unsafe asset package path.");
        return value;
    }
    public static AssetPakManifest Parse(string text) {
        Require(Encoding.UTF8.GetByteCount(text) <= MaxManifest, "pak.json exceeds 1 MiB.");
        AssetPakManifest manifest;
        try {
            using var document = JsonDocument.Parse(text);
            void Unique(JsonElement e) {
                if (e.ValueKind == JsonValueKind.Object) {
                    var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                    foreach (var p in e.EnumerateObject()) { Require(names.Add(p.Name), "Duplicate JSON property in pak.json."); Unique(p.Value); }
                } else if (e.ValueKind == JsonValueKind.Array) foreach (var item in e.EnumerateArray()) Unique(item);
            }
            Unique(document.RootElement);
            manifest = JsonSerializer.Deserialize<AssetPakManifest>(text, Json) ?? throw new IOException("Empty pak.json.");
        } catch (JsonException e) { throw new IOException("Invalid pak.json: " + e.Message, e); }
        Require(manifest.Format == 1, "Unsupported asset pack format; expected 1.");
        Require(manifest.Id != null && Regex.IsMatch(manifest.Id, @"\A[a-z0-9][a-z0-9.-]{0,79}\z"), "Invalid asset pack ID.");
        Require(!string.IsNullOrWhiteSpace(manifest.Name) && manifest.Name.Length <= 120 &&
            !string.IsNullOrWhiteSpace(manifest.Version) && manifest.Version.Length <= 40 &&
            manifest.Description != null && manifest.Description.Length <= 4000, "Asset pack needs a name and version.");
        Require(string.Equals(manifest.ElfSha256, Expected(manifest.Game), StringComparison.OrdinalIgnoreCase),
            "Asset pack targets an unsupported executable revision.");
        Require(manifest.Replace != null && manifest.Replace.Count is > 0 and <= 4096, "Asset pack needs 1–4096 replacements.");
        var targets = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var replacement in manifest.Replace!) {
            Require(replacement != null, "Null asset replacement.");
            SafePath(replacement!.Path); SafePath(replacement.File);
            Require(targets.Add(replacement.Path), "Duplicate replacement path in asset pack.");
            Require(replacement.BaseSha256 == null || HashValid(replacement.BaseSha256), "Invalid baseSha256.");
        }
        return manifest;
    }
    // This wrapper never calls ExtractToDirectory; only declared payloads are copied
    // into numeric cache filenames after the whole ZIP directory is validated.
    sealed class Package : IDisposable {
        readonly ZipArchive? zip;
        readonly string? loose;
        readonly Dictionary<string, ZipArchiveEntry> entries = new(StringComparer.OrdinalIgnoreCase);
        public AssetPakManifest Manifest { get; }
        public Package(string file) {
            try {
                if (Directory.Exists(file)) {
                    loose = Path.GetFullPath(file);
                    RejectLink(loose);
                    using var stream = Open("pak.json"); Manifest = Parse(ReadManifest(stream));
                } else {
                    Require(new FileInfo(file).Length <= MaxExpanded, "Asset pack exceeds 2 GiB.");
                    zip = ZipFile.OpenRead(file);
                    Require(zip.Entries.Count <= 10000, "Asset pack has too many ZIP entries.");
                    long expanded = 0;
                    foreach (var entry in zip.Entries) {
                        bool directory = entry.FullName.EndsWith('/');
                        SafePath(entry.FullName, directory);
                        Require(entries.TryAdd(entry.FullName, entry), "Duplicate ZIP entry in asset pack.");
                        int kind = (entry.ExternalAttributes >> 16) & 0xf000;
                        Require(kind is 0 or 0x8000 or 0x4000 && (entry.ExternalAttributes & 0x400) == 0,
                            "Links and special files are unsupported in asset packs.");
                        Require(entry.Length <= (entry.FullName == "pak.json" ? MaxManifest : MaxEntry), "Asset ZIP entry exceeds size limit.");
                        expanded = checked(expanded + entry.Length);
                        Require(expanded <= MaxExpanded, "Expanded asset pack exceeds 2 GiB.");
                    }
                    Require(entries.ContainsKey("pak.json") && entries["pak.json"].FullName == "pak.json", "Asset pack needs root pak.json.");
                    using var stream = Open("pak.json"); Manifest = Parse(ReadManifest(stream));
                }
                long total = 0;
                foreach (var replacement in Manifest.Replace) {
                    Require(replacement.File != "pak.json", "pak.json cannot be a replacement payload.");
                    using var stream = Open(replacement.File);
                    Require(stream.Length <= MaxEntry, "Replacement exceeds 256 MiB.");
                    total = checked(total + stream.Length); Require(total <= MaxExpanded, "Asset pack payloads exceed 2 GiB.");
                }
            } catch { zip?.Dispose(); throw; }
        }
        static string ReadManifest(Stream stream) {
            Require(stream.Length <= MaxManifest, "pak.json exceeds 1 MiB.");
            using var reader = new StreamReader(stream, Encoding.UTF8, true, 4096, true); return reader.ReadToEnd();
        }
        static void RejectLink(string path) => Require((File.GetAttributes(path) & FileAttributes.ReparsePoint) == 0,
            "Asset pack folders and files cannot contain links.");
        public Stream Open(string name) {
            SafePath(name);
            if (zip != null) {
                Require(entries.TryGetValue(name, out var entry) && entry.FullName == name && !name.EndsWith('/'),
                    "Asset payload is missing or its filename case differs: " + name);
                // ZipArchiveEntry streams do not expose Length. Keep it alongside the
                // stream using a bounded wrapper, including limits on actual bytes.
                return new BoundedStream(entry!.Open(), entry.Length);
            }
            string path = loose!;
            foreach (string part in name.Split('/')) { path = Path.Combine(path, part); RejectLink(path); }
            return new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read);
        }
        public void Dispose() => zip?.Dispose();
    }
    sealed class BoundedStream(Stream inner, long length) : Stream {
        long position;
        public override bool CanRead => true;
        public override bool CanSeek => false;
        public override bool CanWrite => false;
        public override long Length => length;
        public override long Position { get => position; set => throw new NotSupportedException(); }
        public override int Read(byte[] buffer, int offset, int count) {
            int read = inner.Read(buffer, offset, (int)Math.Min(count, Math.Max(0, length - position + 1)));
            position += read; Require(position <= length, "ZIP payload exceeds its declared size.");
            if (read == 0) Require(position == length, "Truncated ZIP payload."); return read;
        }
        public override void Flush() { }
        public override long Seek(long offset, SeekOrigin origin) => throw new NotSupportedException();
        public override void SetLength(long value) => throw new NotSupportedException();
        public override void Write(byte[] buffer, int offset, int count) => throw new NotSupportedException();
        protected override void Dispose(bool disposing) { if (disposing) inner.Dispose(); base.Dispose(disposing); }
    }
    public static List<InstalledAssetPak> Load(string? folder = null) {
        folder ??= Folder; var result = new List<InstalledAssetPak>();
        if (!Directory.Exists(folder)) return result;
        foreach (var path in Directory.EnumerateFiles(folder, "*.pak").Concat(Directory.EnumerateDirectories(folder).Where(d => File.Exists(Path.Combine(d, "pak.json")))).Order()) {
            try { using var package = new Package(path); result.Add(new(path, package.Manifest, "")); }
            catch (Exception e) when (e is IOException or UnauthorizedAccessException or InvalidDataException or OverflowException) { result.Add(new(path, null, e.Message)); }
        }
        var duplicates = result.Where(p => p.Manifest != null).GroupBy(p => p.Manifest!.Id).Where(g => g.Count() > 1).Select(g => g.Key).ToHashSet();
        return result.Select(p => p.Manifest != null && duplicates.Contains(p.Manifest.Id) ? p with { Error = "Duplicate asset pack ID." } : p).ToList();
    }
    public static void Import(string source, string? folder = null) {
        folder ??= Folder;
        using var package = new Package(source);
        Require(!Directory.Exists(source), "For loose packs, place the folder inside the asset mods folder.");
        Require(!Load(folder).Any(p => p.Manifest?.Id == package.Manifest.Id), "This asset pack ID is already installed.");
        Directory.CreateDirectory(folder);
        using var input = File.OpenRead(source);
        using var output = new FileStream(Path.Combine(folder, package.Manifest.Id + ".pak"), FileMode.CreateNew, FileAccess.Write);
        input.CopyTo(output);
    }
    public static List<InstalledAssetPak> Selected(Settings settings, string? folder = null) {
        var enabled = settings.EnabledAssetPaks.Distinct().ToList();
        if (enabled.Count == 0) return new();
        var installed = Load(folder); var selected = new List<InstalledAssetPak>();
        foreach (var id in enabled) {
            var matches = installed.Where(p => p.Manifest?.Id == id).ToList();
            Require(matches.Count == 1 && matches[0].Error.Length == 0, "Enabled asset pack is missing, invalid or duplicated: " + id);
            // Each game's enabled packs remain saved while switching games.
            if (matches[0].Manifest!.Game == settings.Game.Id) selected.Add(matches[0]);
        }
        Require(selected.Count == 0 || settings.ResolvedCoopMode == "offline", "Asset packs currently support solo play only. Disable them before hosting or joining co-op.");
        return selected;
    }
    public static AssetIndex Index(string data, string game, string? indexFile = null) {
        _ = Expected(game);
        var archives = new List<AssetArchive>(); var entries = new List<AssetIndexEntry>();
        foreach (string name in game == "file1" ? new[] { "NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT" } : new[] { "NETBIO00.DAT", "NETBIO01.DAT" }) {
            string source = Path.Combine(data, name); var info = new FileInfo(source);
            Require(info.Exists && info.Length < 0x100000000L, "Missing or oversized original asset archive: " + name);
            archives.Add(new(name, info.Length, info.LastWriteTimeUtc.Ticks));
            using var stream = File.OpenRead(source); using var reader = new BinaryReader(stream);
            void Walk(long offset, long length, string path, string label, int depth) {
                Require(offset >= 0 && length >= 0 && offset <= stream.Length && length <= stream.Length - offset, "Invalid asset archive extent.");
                stream.Position = offset;
                bool isArchive = length >= 4 && reader.ReadUInt32() == 0x00534641;
                if (depth > 0) entries.Add(new(path, label, offset, length, isArchive));
                Require(entries.Count <= 200000, "Asset index exceeds entry limit.");
                if (!isArchive) return;
                Require(depth < 4 && length >= 16, "Invalid AFS nesting or header.");
                uint count = reader.ReadUInt32(); Require(count is > 0 and <= 100000 && 16L + count * 8L <= length, "Invalid AFS count.");
                var table = new (uint Offset, uint Size)[count];
                for (int i = 0; i < count; i++) {
                    table[i] = (reader.ReadUInt32(), reader.ReadUInt32());
                    Require(table[i].Offset >= 16L + count * 8L && table[i].Offset % 2048 == 0 &&
                        (long)table[i].Offset + table[i].Size <= length, "AFS entry exceeds its archive or is unaligned.");
                }
                uint namesOffset = reader.ReadUInt32(), namesSize = reader.ReadUInt32();
                Require((long)namesOffset + namesSize <= length && namesSize <= count * 48L + 2048, "Invalid AFS name table.");
                stream.Position = offset + namesOffset; var names = reader.ReadBytes((int)namesSize);
                for (int i = 0; i < count; i++) {
                    string childName = names.Length >= (i + 1) * 48 ? Encoding.ASCII.GetString(names, i * 48, 32).Split('\0')[0] : "";
                    Walk(offset + table[i].Offset, table[i].Size, path + "/" + i, childName, depth + 1);
                }
            }
            Walk(0, info.Length, name, name, 0);
        }
        var result = new AssetIndex(1, game, Expected(game), archives, entries);
        if (indexFile != null) {
            string temp = indexFile + "." + Guid.NewGuid().ToString("N") + ".tmp";
            File.WriteAllText(temp, JsonSerializer.Serialize(result, Json)); File.Move(temp, indexFile, true);
        }
        return result;
    }
    public static AssetIndexEntry Resolve(AssetIndex index, string target) {
        var parts = SafePath(target).Split('/');
        Require(parts.Length is >= 2 and <= 5, "Asset path must address a leaf entry.");
        string prefix = parts[0].ToUpperInvariant();
        Require(index.Archives.Any(a => a.File == prefix), "Unknown asset archive: " + parts[0]);
        AssetIndexEntry? resolved = null;
        foreach (string part in parts.Skip(1)) {
            var numeric = part.StartsWith('#') ? part[1..] : part;
            var candidates = index.Entries.Where(e => e.Path.StartsWith(prefix + "/", StringComparison.Ordinal) && e.Path.Count(c => c == '/') == prefix.Count(c => c == '/') + 1);
            if (uint.TryParse(numeric, out uint number)) candidates = candidates.Where(e => e.Path == prefix + "/" + number);
            else candidates = candidates.Where(e => e.Name.Equals(part, StringComparison.OrdinalIgnoreCase));
            var matches = candidates.ToList(); Require(matches.Count == 1, "Asset path is missing or ambiguous; use numeric indices: " + target);
            resolved = matches[0]; prefix = resolved.Path;
        }
        Require(resolved != null && !resolved.IsArchive && !resolved.Name.EndsWith("_h.bin", StringComparison.OrdinalIgnoreCase),
            "Only leaf assets can be replaced; whole AFS archives and room name tables are unsupported.");
        Require(resolved!.Size <= MaxEntry, "Original asset exceeds 256 MiB.");
        return resolved;
    }
    static string HashRange(string file, long offset, long size) {
        using var stream = File.OpenRead(file); stream.Position = offset;
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
        byte[] buffer = new byte[1024 * 1024];
        while (size > 0) { int n = stream.Read(buffer, 0, (int)Math.Min(buffer.Length, size)); Require(n > 0, "Truncated original asset."); hash.AppendData(buffer, 0, n); size -= n; }
        return Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
    }
    static void ValidateVirtualSizes(AssetIndex index, List<PreparedAsset> prepared, string data) {
        var replacements = prepared.ToDictionary(p => p.Path, p => p.Size, StringComparer.Ordinal);
        var children = index.Entries.GroupBy(e => e.Path[..e.Path.LastIndexOf('/')]).ToDictionary(g => g.Key, g => g.ToList());
        var changed = new HashSet<string>(StringComparer.Ordinal);
        foreach (var replacement in prepared) {
            string path = replacement.Path;
            while (path.Contains('/')) { path = path[..path.LastIndexOf('/')]; changed.Add(path); }
        }
        foreach (var archive in index.Archives) {
            if (!changed.Contains(archive.File)) continue;
            using var source = File.OpenRead(Path.Combine(data, archive.File)); using var reader = new BinaryReader(source);
            long Size(string path, long offset, long originalSize) {
                if (replacements.TryGetValue(path, out long replacement)) return replacement;
                if (!changed.Contains(path)) return originalSize;
                var entries = children[path];
                long size = entries.Min(e => e.Offset) - offset;
                foreach (var entry in entries) size = checked(((size + 2047) & ~2047L) + Size(entry.Path, entry.Offset, entry.Size));
                source.Position = offset + 12 + entries.Count * 8L;
                uint namesSize = reader.ReadUInt32();
                if (namesSize != 0) size = checked(((size + 2047) & ~2047L) + namesSize);
                Require(size < 0x100000000L, "Asset packs make " + path + " exceed the 4 GiB archive limit.");
                return size;
            }
            _ = Size(archive.File, 0, archive.Size);
        }
    }
    public static string Prepare(List<InstalledAssetPak> packs, string data, string game, string session, string? cache = null,
                                  CancellationToken cancel = default) {
        if (packs.Count == 0) return "";
        data = Path.TrimEndingDirectorySeparator(Path.GetFullPath(data));
        session = Path.GetFullPath(session);
        cache = Path.GetFullPath(cache ?? Path.Combine(Settings.Home, "asset-cache"));
        var index = Index(data, game, Path.Combine(Path.GetDirectoryName(data)!, "assets.json"));
        string elf = Path.Combine(data, game == "file1" ? "SLUS_207.65" : "SLUS_209.84");
        Require(HashRange(elf, 0, new FileInfo(elf).Length) == Expected(game), "Asset pack executable identity mismatch.");
        var prepared = new List<PreparedAsset>(); var owners = new Dictionary<string, string>();
        foreach (var installed in packs.OrderBy(p => p.Manifest!.Id, StringComparer.Ordinal)) {
            cancel.ThrowIfCancellationRequested();
            using var package = new Package(installed.File); var manifest = package.Manifest;
            Require(manifest.Id == installed.Manifest!.Id && manifest.Game == game, "Asset pack changed or targets a different game.");
            string packHash = Directory.Exists(installed.File) ? "loose" : HashRange(installed.File, 0, new FileInfo(installed.File).Length);
            string folder = Path.Combine(cache, packHash); Directory.CreateDirectory(folder);
            foreach (var replacement in manifest.Replace) {
                cancel.ThrowIfCancellationRequested();
                var entry = Resolve(index, replacement.Path);
                Require(!owners.TryGetValue(entry.Path, out var owner), $"Asset pack {manifest.Name} conflicts with {owner} at {entry.Path}.");
                owners.Add(entry.Path, manifest.Name);
                string original = HashRange(Path.Combine(data, entry.Path.Split('/')[0]), entry.Offset, entry.Size);
                Require(replacement.BaseSha256 == null || original.Equals(replacement.BaseSha256, StringComparison.OrdinalIgnoreCase),
                    "Original asset hash differs for " + entry.Path + "; the pack targets another disc revision.");
                string cacheRecord = Path.Combine(folder, Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(replacement.File))).ToLowerInvariant() + ".json");
                if (packHash != "loose" && File.Exists(cacheRecord)) {
                    Require(new FileInfo(cacheRecord).Length <= 1024, "Invalid asset cache record.");
                    CachedPayload? cached;
                    try { cached = JsonSerializer.Deserialize<CachedPayload>(File.ReadAllText(cacheRecord), Json); }
                    catch (JsonException e) { throw new IOException("Invalid asset cache record.", e); }
                    Require(cached != null && cached.Size >= 0 && cached.Size <= MaxEntry && HashValid(cached.Sha256), "Invalid asset cache record.");
                    string cachedFile = Path.Combine(folder, cached!.Sha256.ToLowerInvariant() + ".bin");
                    Require(File.Exists(cachedFile) && new FileInfo(cachedFile).Length == cached.Size && HashRange(cachedFile, 0, cached.Size) == cached.Sha256,
                        "Asset cache is corrupt; remove its folder and retry.");
                    prepared.Add(new(entry.Path, Path.GetFullPath(cachedFile), cached.Size, original, cached.Sha256, manifest.Id));
                    continue;
                }
                using var source = package.Open(replacement.File);
                string temp = Path.Combine(folder, Guid.NewGuid().ToString("N") + ".tmp");
                string newHash; long length = 0;
                try {
                    using (var output = new FileStream(temp, FileMode.CreateNew, FileAccess.Write)) {
                        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256); byte[] buffer = new byte[1024 * 1024]; int n;
                        while ((n = source.Read(buffer, 0, buffer.Length)) > 0) {
                            cancel.ThrowIfCancellationRequested(); length += n; Require(length <= MaxEntry, "Replacement exceeds 256 MiB.");
                            output.Write(buffer, 0, n); hash.AppendData(buffer, 0, n);
                        }
                        newHash = Convert.ToHexString(hash.GetHashAndReset()).ToLowerInvariant();
                    }
                    string target = Path.Combine(folder, newHash + ".bin");
                    if (File.Exists(target)) Require(HashRange(target, 0, new FileInfo(target).Length) == newHash, "Asset cache is corrupt; remove its folder and retry.");
                    else File.Move(temp, target);
                    prepared.Add(new(entry.Path, Path.GetFullPath(target), length, original, newHash, manifest.Id));
                    if (packHash != "loose") {
                        string recordTemp = cacheRecord + "." + Guid.NewGuid().ToString("N") + ".tmp";
                        File.WriteAllText(recordTemp, JsonSerializer.Serialize(new CachedPayload(length, newHash), Json));
                        File.Move(recordTemp, cacheRecord, true);
                    }
                } finally { if (File.Exists(temp)) File.Delete(temp); }
            }
        }
        Require(prepared.Count <= 4096, "Selected packs exceed 4096 replacements.");
        ValidateVirtualSizes(index, prepared, data);
        long planBytes = 48;
        foreach (var asset in prepared) {
            int pathBytes = Encoding.UTF8.GetByteCount(asset.Path), fileBytes = Encoding.UTF8.GetByteCount(asset.File);
            Require(pathBytes <= 256 && fileBytes <= 32768, "Asset path exceeds native plan limits.");
            planBytes += 80L + pathBytes + fileBytes;
        }
        Require(planBytes <= 16 * 1024 * 1024, "Asset overlay plan exceeds 16 MiB; use a shorter cache directory.");
        Directory.CreateDirectory(session);
        string binary = Path.Combine(session, "asset-overlay.bin");
        using (var stream = new FileStream(binary, FileMode.CreateNew, FileAccess.Write))
        using (var writer = new BinaryWriter(stream, Encoding.UTF8)) {
            void Text(string value) { byte[] bytes = Encoding.UTF8.GetBytes(value); writer.Write((uint)bytes.Length); writer.Write(bytes); }
            writer.Write(Encoding.ASCII.GetBytes("REOPAK1\0")); writer.Write(game == "file1" ? 1u : 2u);
            writer.Write(Convert.FromHexString(Expected(game))); writer.Write((uint)prepared.Count);
            foreach (var asset in prepared.OrderBy(a => a.Path, StringComparer.Ordinal)) {
                Text(asset.Path); Text(asset.File); writer.Write((ulong)asset.Size);
                writer.Write(Convert.FromHexString(asset.BaseSha256)); writer.Write(Convert.FromHexString(asset.Sha256));
            }
        }
        File.WriteAllText(Path.Combine(session, "asset-overlay.json"), JsonSerializer.Serialize(new { format = 1, game, elfSha256 = Expected(game), binary, replace = prepared }, Json));
        return binary;
    }
}

public sealed partial class Settings {
    public List<string> EnabledAssetPaks { get; set; } = new();
}
