using System.IO;
using System.IO.Compression;
using System.Numerics;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

internal sealed record PreviewTexture(int Width, int Height, byte[] Rgba);
internal sealed record PreviewMesh(Vector3[] Positions, Vector3[] Normals, Vector2[] TexCoords, int[] Indices, int TextureIndex);

internal sealed class GamePreviewScene {
    internal sealed record Bone(int Parent, Vector3 Translation, Quaternion Rotation, Vector3 Scale);
    internal sealed record Influence(int Bone, float Weight);
    internal sealed record Skin(Vector3[] BindPositions, Vector3[] BindNormals, Vector3[] Positions, Vector3[] Normals, Influence[][] Weights);
    internal IReadOnlyList<PreviewMesh> Meshes { get; private set; }
    internal IReadOnlyList<PreviewTexture> Textures { get; private set; }
    internal Vector3 Minimum { get; }
    internal Vector3 Maximum { get; }
    internal string Source { get; }
    internal bool HasOriginalAnimation => animation != null;
    internal bool HasHandgun => weapon != null;
    internal bool HasHandgunAnimation => weapon != null && animation?.HasHandgunStance == true;
    internal bool HasHandgunStance => HasHandgunAnimation;
    internal string AnimationDescription => HasHandgunAnimation ? "Original handgun idle (100/400)" : animation != null ? "Original relaxed idle (100)" : "Original animation unavailable";
    GamePreviewAnimation? animation;
    GamePreviewWeapon? weapon;
    readonly Bone[] bones;
    readonly Skin[] skins;
    readonly Matrix4x4[] inverseBind, posed, skinMatrices;
    readonly Vector3[] localScales;

    internal GamePreviewScene(List<PreviewMesh> meshes, List<PreviewTexture> textures, Bone[] bones, Skin[] skins, string source) {
        Meshes = meshes; Textures = textures; this.bones = bones; this.skins = skins; Source = source;
        posed = new Matrix4x4[bones.Length]; inverseBind = new Matrix4x4[bones.Length]; skinMatrices = new Matrix4x4[bones.Length];
        localScales = new Vector3[bones.Length];
        for (int i = 0; i < bones.Length; i++) {
            var bone = bones[i];
            posed[i] = Matrix4x4.CreateScale(bone.Scale) * Matrix4x4.CreateFromQuaternion(bone.Rotation) * Matrix4x4.CreateTranslation(bone.Translation);
            if (bone.Parent >= 0) posed[i] *= posed[bone.Parent];
            if (!Matrix4x4.Invert(posed[i], out inverseBind[i])) throw new InvalidDataException("Singular preview skeleton.");
        }
        Minimum = new(float.PositiveInfinity); Maximum = new(float.NegativeInfinity);
        foreach (var skin in skins) foreach (var p in skin.BindPositions) { Minimum = Vector3.Min(Minimum, p); Maximum = Vector3.Max(Maximum, p); }
        Animate(0);
    }

    internal void SetAnimation(GamePreviewAnimation? clip) { animation = clip; Animate(0); }

    internal void SetWeapon(GamePreviewWeapon? model) {
        if (model == null || weapon != null) return;
        weapon = model; int offset = Textures.Count;
        Textures = Textures.Concat(model.Textures).ToArray();
        Meshes = Meshes.Concat(model.Meshes.Select(m => m with { TextureIndex = m.TextureIndex + offset })).ToArray();
        Animate(0);
    }

    // Original animated hierarchy routine 0x193260 compensates the parent's
    // LOCAL scale before translation; inheriting it stretches every descendant.
    internal static Matrix4x4 AnimatedWorld(Vector3 scale, Quaternion rotation, Vector3 translation,
        Vector3 parentScale, Matrix4x4 parentWorld) =>
        Matrix4x4.CreateScale(scale) * Matrix4x4.CreateFromQuaternion(rotation) *
        Matrix4x4.CreateScale(Vector3.One / parentScale) * Matrix4x4.CreateTranslation(translation) * parentWorld;

    internal void Animate(double seconds) {
        for (int i = 0; i < bones.Length; i++) {
            var bone = bones[i]; var rotation = bone.Rotation; var translation = bone.Translation; var scale = bone.Scale;
            if (animation != null) {
                animation.Apply(i, seconds, ref translation, ref rotation, ref scale);
            }
            localScales[i] = scale;
            if (animation != null) posed[i] = AnimatedWorld(scale, rotation, translation,
                bone.Parent >= 0 ? localScales[bone.Parent] : Vector3.One,
                bone.Parent >= 0 ? posed[bone.Parent] : Matrix4x4.Identity);
            else {
                posed[i] = Matrix4x4.CreateScale(scale) * Matrix4x4.CreateFromQuaternion(rotation) * Matrix4x4.CreateTranslation(translation);
                if (bone.Parent >= 0) posed[i] *= posed[bone.Parent];
            }
            skinMatrices[i] = inverseBind[i] * posed[i];
        }
        foreach (var skin in skins) for (int i = 0; i < skin.Positions.Length; i++) {
            Vector3 position = default, normal = default;
            foreach (var influence in skin.Weights[i]) {
                position += Vector3.Transform(skin.BindPositions[i], skinMatrices[influence.Bone]) * influence.Weight;
                normal += Vector3.TransformNormal(skin.BindNormals[i], skinMatrices[influence.Bone]) * influence.Weight;
            }
            skin.Positions[i] = position;
            skin.Normals[i] = normal.LengthSquared() > 1e-8f ? Vector3.Normalize(normal) : Vector3.UnitY;
        }
        if (weapon != null) weapon.Update(posed[weapon.HandJoint]);
    }
}

// Decoder authored from the owned asset's bounded chunk structure and Fothsid's
// published format descriptions: https://github.com/Fothsid/libthanatos .
// No models, textures, clips, or generated game payloads are shipped in source.
internal static class GamePreviewAssets {
    internal const string KevinHash = "964daa4c3ce1cf724e62b0e9cda79a88a4761c4899d159d0090ae5ba539b4baf";
    const int MaxModel = 2 * 1024 * 1024;
    internal static GamePreviewScene? LoadShared(string firstImport, string secondImport, string home) {
        // Kevin's verified character payload is identical in both editions.
        // Either owned game can supply this one launcher scene.
        foreach (var (import, game) in new[] { (firstImport, "file1"), (secondImport, "file2") }) {
            try { if (Load(import, game, home) is { } scene) return scene; }
            catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or
                JsonException or ArgumentException or NotSupportedException or OverflowException) { }
        }
        return null;
    }
    readonly record struct Chunk(int Type, int Count, int Start, int Size) { internal int Data => Start + 12; internal int End => Start + Size; }
    static int I(byte[] b, int at) { if (at < 0 || at > b.Length - 4) throw new InvalidDataException("Incomplete preview asset."); return BitConverter.ToInt32(b, at); }
    static float F(byte[] b, int at) { float f = BitConverter.Int32BitsToSingle(I(b, at)); if (!float.IsFinite(f)) throw new InvalidDataException("Invalid preview coordinate."); return f; }
    static Vector3 V(byte[] b, int at) => new(F(b, at), F(b, at + 4), F(b, at + 8));
    static void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); }
    static Chunk Header(byte[] b, int at, int end) {
        int size = I(b, at + 8), count = I(b, at + 4);
        Require(size >= 12 && at >= 0 && at <= end - size && count is >= 0 and <= 100000, "Invalid preview model chunk.");
        return new(I(b, at), count, at, size);
    }
    static List<Chunk> Children(byte[] b, Chunk parent) {
        var result = new List<Chunk>(); int at = parent.Data;
        while (at < parent.End) { var child = Header(b, at, parent.End); result.Add(child); at = child.End; }
        Require(at == parent.End, "Incomplete preview model hierarchy."); return result;
    }
    static Chunk One(IEnumerable<Chunk> chunks, int type) => chunks.SingleOrDefault(c => c.Type == type) is { Size: > 0 } found
        ? found : throw new InvalidDataException("Missing preview model component.");

    internal static GamePreviewScene? Load(string import, string game, string home) {
        if (game is not ("file1" or "file2")) return null;
        if (File.Exists(import) && Path.GetExtension(import).Equals(".pak", StringComparison.OrdinalIgnoreCase)) return LoadPak(import, game);
        string exported = Path.Combine(home, "asset-exports", game);
        if (Directory.Exists(exported)) {
            // Only this game's standard export layout; never scan arbitrary disk trees.
            foreach (string folder in Directory.EnumerateDirectories(exported).Take(32).OrderByDescending(Directory.GetLastWriteTimeUtc)) {
                string pak = Path.Combine(folder, "single", "original-assets.pak");
                if (File.Exists(pak)) {
                    try { if (LoadPak(pak, game) is { } packed) return packed; }
                    catch (Exception error) when (error is IOException or InvalidDataException or JsonException) { }
                }
            }
        }
        string archive = Path.Combine(import, "data", "NETBIO00.DAT");
        if (!File.Exists(archive)) return null;
        using var file = File.OpenRead(archive);
        var rom = BackgroundVideos.Entry(file, new(0, file.Length), 0);
        var model = BackgroundVideos.Entry(file, rom, game == "file2" ? 508 : 491);
        Require(model.Length <= MaxModel, "Oversized preview model.");
        file.Position = model.Offset; var bytes = new byte[(int)model.Length]; file.ReadExactly(bytes);
        return Prepare(Decode(bytes, archive), archive, game);
    }

    internal static GamePreviewScene? LoadPak(string path, string game) {
        using var zip = ZipFile.OpenRead(path);
        Require(zip.Entries.Count <= 100000, "Too many preview asset members.");
        var index = zip.GetEntry("assets.json");
        if (index == null) return null;
        Require(index.Length <= 32 * 1024 * 1024, "Oversized preview asset index.");
        using var input = index.Open(); using var document = JsonDocument.Parse(input);
        var root = document.RootElement;
        Require(root.ValueKind == JsonValueKind.Object && root.TryGetProperty("game", out var edition) &&
            edition.ValueKind == JsonValueKind.String && edition.GetString() == game, "Preview PAK belongs to another game.");
        Require(root.TryGetProperty("entries", out var entries) && entries.ValueKind == JsonValueKind.Array &&
            entries.GetArrayLength() <= 100000, "Invalid preview asset index.");
        string wanted = "NETBIO00.DAT/0/" + (game == "file2" ? "508" : "491");
        foreach (var entry in entries.EnumerateArray()) {
            Require(entry.ValueKind == JsonValueKind.Object && entry.TryGetProperty("path", out var assetPath) &&
                assetPath.ValueKind == JsonValueKind.String, "Invalid preview asset path.");
            if (entry.GetProperty("path").GetString() != wanted) continue;
            Require(entry.TryGetProperty("file", out var assetFile) && assetFile.ValueKind == JsonValueKind.String, "Invalid preview asset member.");
            string member = assetFile.GetString() ?? "";
            Require(member.Length < 512 && !member.Contains('\\') && !member.StartsWith('/') && member.Split('/').All(p => p is not ("" or "." or "..")), "Unsafe preview asset member.");
            var resource = zip.GetEntry(member) ?? throw new InvalidDataException("Missing Kevin model in the asset PAK.");
            Require(resource.Length is > 0 and <= MaxModel, "Oversized preview model.");
            using var source = resource.Open(); var data = new byte[(int)resource.Length]; source.ReadExactly(data);
            return Prepare(Decode(data, path), path, game);
        }
        return null;
    }

    static GamePreviewScene Prepare(GamePreviewScene scene, string source, string game) {
        var idle = GamePreviewAnimation.ReadFromSource(source, game);
        Require(idle != null, "The original Kevin idle animation bank is missing from the asset pack or import.");
        scene.SetAnimation(idle);
        var weapon = GamePreviewWeapon.ReadFromSource(source, game);
        // Use the complete authored relaxed idle100 instead of the two-handed
        // upper400 stance. The pistol remains attached to its original hand.
        if (weapon != null) scene.SetWeapon(weapon);
        return scene;
    }

    internal static GamePreviewScene Decode(byte[] b, string source = "owned asset") {
        Require(b.Length is > 0 and <= MaxModel && Convert.ToHexString(SHA256.HashData(b)).Equals(KevinHash, StringComparison.OrdinalIgnoreCase), "Unsupported Kevin model revision.");
        var sections = new Dictionary<int, (int Offset, int Size, int Count)>();
        for (int at = 0; at <= 128 - 16; at += 16) {
            int type = I(b, at); if (type == 0) break;
            int offset = I(b, at + 4), size = I(b, at + 8), count = I(b, at + 12);
            Require(offset >= 128 && size >= 0 && offset <= b.Length - size && sections.TryAdd(type, (offset, size, count)), "Invalid preview NBD directory.");
        }
        var tex = sections[0x00584554]; var textures = new List<PreviewTexture>(); int cursor = tex.Offset;
        Require(tex.Count is > 0 and <= 8, "Invalid preview texture count.");
        for (int i = 0; i < tex.Count; i++) {
            int length = I(b, cursor); cursor += 4;
            Require(length > 0 && cursor <= tex.Offset + tex.Size - length, "Invalid preview texture span.");
            textures.Add(DecodeTexture(GameControllerArtwork.DecompressOb(b.AsSpan(cursor, length)))); cursor += length;
        }
        var ahi = sections[0x00494841]; var rig = Header(b, ahi.Offset, ahi.Offset + ahi.Size);
        Require(rig.Type == unchecked((int)0xc0000000), "Invalid preview skeleton.");
        var nodes = Children(b, rig).Where(c => c.Type != 0).ToArray();
        Require(nodes.Length is > 0 and <= 128, "Invalid preview joint count.");
        var bones = new GamePreviewScene.Bone[nodes.Length];
        for (int i = 0; i < nodes.Length; i++) {
            var node = nodes[i]; int at = node.Data, id = I(b, at), parent = I(b, at + 4);
            Require(node.Size == 268 && id == i && parent >= -1 && parent < i, "Invalid preview joint hierarchy.");
            var scale = V(b, at + 16); var rotation = new Quaternion(F(b, at + 32), F(b, at + 36), F(b, at + 40), F(b, at + 44));
            Require(rotation.LengthSquared() > .0001f && scale.X != 0 && scale.Y != 0 && scale.Z != 0, "Invalid preview bind transform.");
            if (node.Type == 0x40000003) { rotation = Quaternion.Conjugate(rotation); scale = Vector3.One / scale; }
            bones[i] = new(parent, V(b, at + 48), Quaternion.Normalize(rotation), scale);
        }
        var amo = sections[0x004f4d41]; var model = Children(b, Header(b, amo.Offset, amo.Offset + amo.Size));
        var materialNodes = Children(b, One(model, 9)); var textureNodes = Children(b, One(model, 10));
        var materialTextures = materialNodes.Select(c => {
            int refId = I(b, c.End - 4); Require(refId >= 0 && refId < textureNodes.Count, "Invalid preview material.");
            int texture = I(b, textureNodes[refId].Data); Require(texture >= 0 && texture < textures.Count, "Invalid preview texture reference."); return texture;
        }).ToArray();
        var result = new List<PreviewMesh>(); var skins = new List<GamePreviewScene.Skin>();
        foreach (var mesh in Children(b, One(model, 2))) {
            Require(mesh.Type == 4, "Invalid preview mesh."); var parts = Children(b, mesh);
            var p = One(parts, 0x70000); var n = One(parts, 0x80000); var uv = One(parts, 0xa0000);
            Require(p.Count is > 0 and <= 20000 && n.Count == p.Count && uv.Count == p.Count && p.Size == 12 + p.Count * 12 && n.Size == p.Size && uv.Size == 12 + p.Count * 8, "Invalid preview vertex attributes.");
            var positions = Enumerable.Range(0, p.Count).Select(i => V(b, p.Data + i * 12)).ToArray();
            var normals = Enumerable.Range(0, n.Count).Select(i => V(b, n.Data + i * 12)).ToArray();
            var coords = Enumerable.Range(0, uv.Count).Select(i => new Vector2(F(b, uv.Data + i * 8), F(b, uv.Data + i * 8 + 4))).ToArray();
            var palette = One(parts, 0x100000); var mapping = Enumerable.Range(0, palette.Count).Select(i => I(b, palette.Data + i * 4)).ToArray();
            Require(mapping.All(i => i >= 0 && i < bones.Length), "Invalid preview bone palette.");
            var weights = One(parts, 0xc0000); var influences = new GamePreviewScene.Influence[p.Count][]; cursor = weights.Data;
            for (int i = 0; i < p.Count; i++) {
                int count = I(b, cursor); cursor += 4; Require(count is > 0 and <= 4 && cursor <= weights.End - count * 8, "Invalid preview skin weights.");
                influences[i] = new GamePreviewScene.Influence[count]; float sum = 0;
                for (int j = 0; j < count; j++, cursor += 8) {
                    int bone = I(b, cursor); float weight = F(b, cursor + 4) / 100;
                    Require(bone >= 0 && bone < mapping.Length && weight >= 0 && weight <= 1, "Invalid preview influence.");
                    influences[i][j] = new(mapping[bone], weight); sum += weight;
                }
                Require(MathF.Abs(sum - 1) < .0001f, "Invalid preview weight sum.");
            }
            Require(cursor == weights.End, "Trailing preview skin weights.");
            var outputPositions = new Vector3[p.Count]; var outputNormals = new Vector3[p.Count];
            skins.Add(new(positions, normals, outputPositions, outputNormals, influences));
            var refs = One(parts, 0x50000); var references = Enumerable.Range(0, refs.Count).Select(i => I(b, refs.Data + i * 4)).ToArray();
            var groupMats = One(parts, 0x60000); int ordinal = 0; var triangles = new Dictionary<int, List<int>>();
            foreach (var stripList in Children(b, One(parts, 5))) {
                Require(stripList.Type is 0x30000 or 0x40000, "Unsupported preview primitive type."); cursor = stripList.Data;
                for (int g = 0; g < stripList.Count; g++, ordinal++) {
                    uint header = unchecked((uint)I(b, cursor)); cursor += 4; int count = (int)(header & 0x7fffffff);
                    Require(count is >= 3 and <= 20000 && cursor <= stripList.End - count * 4 && ordinal < groupMats.Count, "Invalid preview triangle strip.");
                    int mat = I(b, groupMats.Data + ordinal * 4); Require(mat >= 0 && mat < references.Length, "Invalid preview strip material.");
                    mat = references[mat]; Require(mat >= 0 && mat < materialTextures.Length, "Invalid preview material index.");
                    int texture = materialTextures[mat]; if (!triangles.TryGetValue(texture, out var indices)) triangles[texture] = indices = new();
                    for (int j = 2; j < count; j++) {
                        int a = I(b, cursor + (j - 2) * 4), d = I(b, cursor + (j - 1) * 4), c = I(b, cursor + j * 4);
                        Require(a >= 0 && a < p.Count && d >= 0 && d < p.Count && c >= 0 && c < p.Count, "Invalid preview triangle index.");
                        if (a == d || d == c || a == c) continue;
                        if (((j & 1) != 0) ^ ((header & 0x80000000) != 0)) (a, d) = (d, a);
                        indices.Add(a); indices.Add(d); indices.Add(c);
                    }
                    cursor += count * 4;
                }
                Require(cursor == stripList.End, "Trailing preview topology.");
            }
            Require(ordinal == groupMats.Count, "Incomplete preview material groups.");
            foreach (var item in triangles) result.Add(new(outputPositions, outputNormals, coords, item.Value.ToArray(), item.Key));
        }
        Require(result.Count > 0 && skins.Count == 4, "Incomplete Kevin preview model.");
        return new(result, textures, bones, skins.ToArray(), source);
    }

    static PreviewTexture DecodeTexture(byte[] b) {
        Require(b.Length >= 64 && b.AsSpan(0, 4).SequenceEqual("TIM2"u8), "Invalid preview TIM2 texture.");
        int at = b[5] == 0 ? 16 : 128;
        int total = I(b, at), clutBytes = I(b, at + 4), imageBytes = I(b, at + 8);
        int header = BitConverter.ToUInt16(b, at + 12), colors = BitConverter.ToUInt16(b, at + 14);
        int clutType = b[at + 18], type = b[at + 19], width = BitConverter.ToUInt16(b, at + 20), height = BitConverter.ToUInt16(b, at + 22);
        Require(width is > 0 and <= 1024 && height is > 0 and <= 1024 && header >= 48 && total >= header && at <= b.Length - total && imageBytes >= 0 && clutBytes >= 0 && (long)header + imageBytes + clutBytes <= total && type is 4 or 5 && (clutType & 63) == 3, "Unsupported preview texture encoding.");
        Require(colors == (type == 4 ? 16 : 256) && clutBytes >= colors * 4 && imageBytes >= width * height / (type == 4 ? 2 : 1), "Incomplete preview indexed texture.");
        int image = at + header, palette = image + imageBytes; var pixels = new byte[width * height * 4];
        for (int i = 0; i < width * height; i++) {
            int color = type == 4 ? (b[image + i / 2] >> ((i & 1) * 4)) & 15 : b[image + i];
            if (type == 5 && (clutType & 128) == 0) color = (color & ~24) | ((color & 8) << 1) | ((color & 16) >> 1);
            int c = palette + color * 4, d = i * 4;
            pixels[d] = b[c]; pixels[d + 1] = b[c + 1]; pixels[d + 2] = b[c + 2]; pixels[d + 3] = (byte)Math.Min(255, b[c + 3] * 2);
        }
        return new(width, height, pixels);
    }

    internal static (List<PreviewMesh> Meshes, List<PreviewTexture> Textures) DecodeHandgun(byte[] b) {
        // Admission and exact resource identity are checked by GamePreviewWeapon.
        int texOffset = I(b, 4), texSize = I(b, 8), texCount = I(b, 12);
        int amoOffset = I(b, 20), amoSize = I(b, 24), ahiOffset = I(b, 36), ahiSize = I(b, 40);
        Require(b.AsSpan(0, 4).SequenceEqual("TEX\0"u8) && b.AsSpan(16, 4).SequenceEqual("AMO\0"u8) &&
            b.AsSpan(32, 4).SequenceEqual("AHI\0"u8) && texOffset >= 64 && texSize >= 0 &&
            texOffset <= b.Length - texSize && texCount is > 0 and <= 64, "Invalid handgun model bank.");
        var rig = Children(b, Header(b, ahiOffset, ahiOffset + ahiSize));
        var rootList = rig[0]; Require(rootList.Type is 0 or unchecked((int)0x80000000), "Invalid handgun object roots.");
        int rootId = I(b, rootList.Data);
        var root = rig.Skip(1).Single(c => I(b, c.Data) == rootId);
        Require(I(b, root.Start + 80) == 0, "The first object model is not the standard handgun.");
        var model = Children(b, Header(b, amoOffset, amoOffset + amoSize));
        var materials = Children(b, One(model, 9)); var textureRefs = Children(b, One(model, 10));
        var materialTextures = materials.Select(c => {
            int reference = I(b, c.End - 4); Require(reference >= 0 && reference < textureRefs.Count, "Invalid handgun material.");
            int texture = I(b, textureRefs[reference].Data); Require(texture >= 0 && texture < texCount, "Invalid handgun texture."); return texture;
        }).ToArray();
        var meshes = Children(b, One(model, 2)); var parts = Children(b, meshes[0]);
        var p = One(parts, 0x70000); var n = One(parts, 0x80000); var uv = One(parts, 0xa0000);
        Require(p.Count is > 0 and <= 20000 && p.Size == 12 + p.Count * 12 && n.Count == p.Count &&
            n.Size == p.Size && uv.Count == p.Count && uv.Size == 12 + p.Count * 8, "Invalid handgun mesh attributes.");
        var positions = Enumerable.Range(0, p.Count).Select(i => V(b, p.Data + i * 12)).ToArray();
        var normals = Enumerable.Range(0, p.Count).Select(i => V(b, n.Data + i * 12)).ToArray();
        var coords = Enumerable.Range(0, p.Count).Select(i => new Vector2(F(b, uv.Data + i * 8), F(b, uv.Data + i * 8 + 4))).ToArray();
        var refs = One(parts, 0x50000); var references = Enumerable.Range(0, refs.Count).Select(i => I(b, refs.Data + i * 4)).ToArray();
        var groupMats = One(parts, 0x60000); int ordinal = 0; var triangles = new Dictionary<int, List<int>>();
        foreach (var list in Children(b, One(parts, 5))) {
            Require(list.Type is 0x30000 or 0x40000, "Unsupported handgun primitive type."); int cursor = list.Data;
            for (int group = 0; group < list.Count; group++, ordinal++) {
                uint header = unchecked((uint)I(b, cursor)); cursor += 4; int count = (int)(header & 0x7fffffff);
                Require(count is >= 3 and <= 20000 && cursor <= list.End - count * 4 && ordinal < groupMats.Count, "Invalid handgun triangle strip.");
                int material = I(b, groupMats.Data + ordinal * 4); Require(material >= 0 && material < references.Length, "Invalid handgun group material.");
                material = references[material]; Require(material >= 0 && material < materialTextures.Length, "Invalid handgun material index.");
                int texture = materialTextures[material]; if (!triangles.TryGetValue(texture, out var indices)) triangles[texture] = indices = new();
                for (int j = 2; j < count; j++) {
                    int a = I(b, cursor + (j - 2) * 4), d = I(b, cursor + (j - 1) * 4), c = I(b, cursor + j * 4);
                    Require(a >= 0 && a < p.Count && d >= 0 && d < p.Count && c >= 0 && c < p.Count, "Invalid handgun triangle index.");
                    if (a == d || d == c || a == c) continue;
                    if (((j & 1) != 0) ^ ((header & 0x80000000) != 0)) (a, d) = (d, a);
                    indices.Add(a); indices.Add(d); indices.Add(c);
                }
                cursor += count * 4;
            }
            Require(cursor == list.End, "Trailing handgun topology.");
        }
        Require(ordinal == groupMats.Count && triangles.Count > 0, "Incomplete handgun topology.");
        var textureMap = new Dictionary<int, int>(); var textures = new List<PreviewTexture>(); int at = texOffset;
        for (int i = 0; i < texCount; i++) {
            int length = I(b, at); at += 4; Require(length > 0 && at <= texOffset + texSize - length, "Invalid handgun texture span.");
            if (triangles.ContainsKey(i)) {
                textureMap[i] = textures.Count;
                textures.Add(DecodeTexture(GameControllerArtwork.DecompressOb(b.AsSpan(at, length))));
            }
            at += length;
        }
        var output = triangles.Select(pair => new PreviewMesh(positions, normals, coords, pair.Value.ToArray(), textureMap[pair.Key])).ToList();
        return (output, textures);
    }
}
