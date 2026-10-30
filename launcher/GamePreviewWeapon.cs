using System.IO;
using System.IO.Compression;
using System.Numerics;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

// A rigid attachment from the owner's original handgun geometry. The original
// object bank is read once; only this model and its used textures are retained.
internal sealed class GamePreviewWeapon {
    internal int HandJoint => 32;
    internal string Source { get; }
    internal IReadOnlyList<PreviewMesh> Meshes { get; }
    internal IReadOnlyList<PreviewTexture> Textures { get; }
    internal Vector3 Grip => new(6.5f, 0, 1.5f);
    readonly Vector3[] localPositions, localNormals, positions, normals;
    readonly Matrix4x4 gripTransform = Matrix4x4.CreateTranslation(-7, 0, 2) *
        Matrix4x4.CreateRotationZ(MathF.PI) * Matrix4x4.CreateTranslation(6.5f, 0, 1.5f);
    const int MaxBank = 2 * 1024 * 1024;

    GamePreviewWeapon(byte[] bank, string source) {
        var decoded = GamePreviewAssets.DecodeHandgun(bank); Source = source; Textures = decoded.Textures;
        localPositions = decoded.Meshes[0].Positions; localNormals = decoded.Meshes[0].Normals;
        positions = new Vector3[localPositions.Length]; normals = new Vector3[localNormals.Length];
        Meshes = decoded.Meshes.Select(m => m with { Positions = positions, Normals = normals }).ToArray();
    }
    internal void Update(Matrix4x4 hand) {
        var transform = gripTransform * hand;
        for (int i = 0; i < positions.Length; i++) {
            positions[i] = Vector3.Transform(localPositions[i], transform);
            var normal = Vector3.TransformNormal(localNormals[i], transform);
            normals[i] = normal.LengthSquared() > 1e-8f ? Vector3.Normalize(normal) : Vector3.UnitY;
        }
    }
    static void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); }
    internal static GamePreviewWeapon Decode(byte[] data, string game, string source = "owned object bank") {
        string expected = game switch {
            "file1" => "1fad1efced5d19d926765c76df53f56f0587e426e5ef4b04a79e8c0f00bcde99",
            "file2" => "c3a7c9a042486f1ee6304569c52715c3b115d5b2d0bcc70deabbb3437cb0be33", _ => ""
        };
        Require(data.Length is > 0 and <= MaxBank && expected.Length != 0 &&
            Convert.ToHexString(SHA256.HashData(data)).Equals(expected, StringComparison.OrdinalIgnoreCase), "Unsupported preview handgun bank.");
        return new(data, source);
    }
    internal static GamePreviewWeapon? ReadFromSource(string source, string game) {
        if (game is not ("file1" or "file2") || !File.Exists(source)) return null;
        int index = game == "file2" ? 1391 : 1093; byte[]? data = null;
        if (Path.GetExtension(source).Equals(".pak", StringComparison.OrdinalIgnoreCase)) {
            using var zip = ZipFile.OpenRead(source);
            Require(zip.Entries.Count <= 100000, "Too many preview weapon pack members.");
            var indexEntry = zip.GetEntry("assets.json"); if (indexEntry == null) return null;
            Require(indexEntry.Length <= 32 * 1024 * 1024, "Oversized preview weapon index.");
            using var input = indexEntry.Open(); using var document = JsonDocument.Parse(input);
            var root = document.RootElement;
            Require(root.ValueKind == JsonValueKind.Object && root.TryGetProperty("game", out var edition) &&
                edition.ValueKind == JsonValueKind.String && edition.GetString() == game &&
                root.TryGetProperty("entries", out var entries) && entries.ValueKind == JsonValueKind.Array &&
                entries.GetArrayLength() <= 100000, "Invalid preview weapon pack identity.");
            foreach (var entry in root.GetProperty("entries").EnumerateArray()) {
                Require(entry.ValueKind == JsonValueKind.Object, "Invalid preview weapon index entry.");
                if (!entry.TryGetProperty("path", out var path) || path.ValueKind != JsonValueKind.String ||
                    path.GetString() != "NETBIO00.DAT/1/" + index) continue;
                Require(entry.TryGetProperty("file", out var member) && member.ValueKind == JsonValueKind.String, "Missing preview handgun member.");
                string name = member.GetString() ?? "";
                Require(name.Length < 512 && !name.Contains('\\') && !name.StartsWith('/') &&
                    name.Split('/').All(p => p is not ("" or "." or "..")), "Unsafe preview handgun member.");
                var resource = zip.GetEntry(name) ?? throw new InvalidDataException("Missing original handgun model.");
                Require(resource.Length is > 0 and <= MaxBank, "Oversized preview handgun bank.");
                using var payload = resource.Open(); data = new byte[(int)resource.Length]; payload.ReadExactly(data); break;
            }
        } else if (Path.GetFileName(source).Equals("NETBIO00.DAT", StringComparison.OrdinalIgnoreCase)) {
            using var archive = File.OpenRead(source);
            var room = BackgroundVideos.Entry(archive, new(0, archive.Length), 1);
            var resource = BackgroundVideos.Entry(archive, room, index);
            Require(resource.Length is > 0 and <= MaxBank, "Oversized preview handgun bank.");
            archive.Position = resource.Offset; data = new byte[(int)resource.Length]; archive.ReadExactly(data);
        }
        return data == null ? null : Decode(data, game, source);
    }
}
