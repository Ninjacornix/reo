using System.IO;
using System.IO.Compression;
using System.Numerics;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

// Reads Kevin's original paired lower/upper idle tracks from the owner's player
// animation bank. The channel/container schema is corroborated by 2Tie's public
// Outbreak/Monster Hunter animation importer. No clip data ships with the launcher.
internal sealed class GamePreviewAnimation {
    internal readonly record struct Key(float Value, float Frame, float OutTangent, float InTangent);
    internal sealed record Track(int Axis, Key[] Keys) {
        internal float Evaluate(float frame) {
            if (frame <= Keys[0].Frame) return Keys[0].Value;
            for (int i = 1; i < Keys.Length; i++) {
                var right = Keys[i]; if (frame > right.Frame) continue;
                var left = Keys[i - 1]; float span = right.Frame - left.Frame;
                if (span <= 0) return right.Value;
                float t = (frame - left.Frame) / span, t2 = t * t, t3 = t2 * t;
                return (2 * t3 - 3 * t2 + 1) * left.Value + (t3 - 2 * t2 + t) * span * left.OutTangent +
                    (-2 * t3 + 3 * t2) * right.Value + (t3 - t2) * span * right.InTangent;
            }
            return Keys[^1].Value;
        }
    }
    const int MaxBytes = 3 * 1024 * 1024;
    internal const int Frames = 120;
    internal const float FramesPerSecond = 30;
    internal double Duration => Frames / FramesPerSecond;
    internal bool IsExtractedOriginal => true;
    internal bool HasHandgunStance => lowerIdle != null;
    internal string Source { get; }
    internal int TrackCount => tracks.Sum(t => t.Length) + (lowerIdle?.tracks.Take(10).Sum(t => t.Length) ?? 0);
    internal int BoneCount => tracks.Count(t => t.Length != 0) + (lowerIdle?.tracks.Take(10).Count(t => t.Length != 0) ?? 0);
    readonly Track[][] tracks;
    readonly GamePreviewAnimation? lowerIdle;
    GamePreviewAnimation(Track[][] tracks, string source, GamePreviewAnimation? lowerIdle = null) {
        this.tracks = tracks; Source = source; this.lowerIdle = lowerIdle;
    }
    static void Require(bool okay, string message) { if (!okay) throw new InvalidDataException(message); }
    static int I(byte[] b, int at) {
        Require(at >= 0 && at <= b.Length - 4, "Truncated original idle animation.");
        return BitConverter.ToInt32(b, at);
    }
    static float F(byte[] b, int at) {
        float value = BitConverter.Int32BitsToSingle(I(b, at));
        Require(float.IsFinite(value), "Nonfinite original animation key."); return value;
    }
    internal static Key DecodeKey(byte[] bytes, int position, bool packed, int axis) {
        Require(position >= 0 && position <= bytes.Length - (packed ? 8 : 16), "Truncated original animation key.");
        float Read(int n) => packed ? BitConverter.ToInt16(bytes, position + n * 2) : F(bytes, position + n * 4);
        float unit = !packed ? 1 : axis is 8 or 16 or 32 ? MathF.PI / 8192 : 1f / 16;
        // Native 0x18E710 stores incoming before outgoing, not the reverse.
        return new(Read(0) * unit, Read(1), Read(3) * unit, Read(2) * unit);
    }

    internal static GamePreviewAnimation? ReadFromSource(string source, string game) {
        var bytes = ReadBank(source, game, game == "file2" ? 873 : 1047);
        return bytes == null ? null : Decode(bytes, game, source);
    }

    internal static GamePreviewAnimation? ReadHandgunFromSource(string source, string game, GamePreviewAnimation idle) {
        var bytes = ReadBank(source, game, game == "file2" ? 867 : 958);
        return bytes == null ? null : DecodeHandgun(bytes, game, idle, source);
    }

    static byte[]? ReadBank(string source, string game, int index) {
        if (game is not ("file1" or "file2") || !File.Exists(source)) return null;
        byte[]? bytes = null;
        if (Path.GetExtension(source).Equals(".pak", StringComparison.OrdinalIgnoreCase)) {
            using var zip = ZipFile.OpenRead(source);
            Require(zip.Entries.Count <= 100000, "Too many animation pack members.");
            var header = zip.GetEntry("assets.json"); if (header == null) return null;
            Require(header.Length <= 32 * 1024 * 1024, "Oversized animation asset index.");
            using var input = header.Open(); using var document = JsonDocument.Parse(input);
            var root = document.RootElement;
            Require(root.ValueKind == JsonValueKind.Object && root.TryGetProperty("game", out var edition) &&
                edition.ValueKind == JsonValueKind.String && edition.GetString() == game &&
                root.TryGetProperty("entries", out var entries) && entries.ValueKind == JsonValueKind.Array &&
                entries.GetArrayLength() <= 100000,
                "Invalid animation pack identity.");
            foreach (var entry in root.GetProperty("entries").EnumerateArray()) {
                Require(entry.ValueKind == JsonValueKind.Object, "Invalid animation asset index entry.");
                if (!entry.TryGetProperty("path", out var path) || path.ValueKind != JsonValueKind.String ||
                    path.GetString() != "NETBIO00.DAT/0/" + index) continue;
                Require(entry.TryGetProperty("file", out var member) && member.ValueKind == JsonValueKind.String, "Missing animation member.");
                string name = member.GetString() ?? "";
                Require(name.Length < 512 && !name.Contains('\\') && !name.StartsWith('/') &&
                    name.Split('/').All(p => p is not ("" or "." or "..")), "Unsafe animation member.");
                var resource = zip.GetEntry(name) ?? throw new InvalidDataException("Missing original animation bank.");
                Require(resource.Length is > 0 and <= MaxBytes, "Oversized original animation bank.");
                using var clip = resource.Open(); bytes = new byte[(int)resource.Length]; clip.ReadExactly(bytes); break;
            }
        } else if (Path.GetFileName(source).Equals("NETBIO00.DAT", StringComparison.OrdinalIgnoreCase)) {
            using var file = File.OpenRead(source);
            var rom = BackgroundVideos.Entry(file, new(0, file.Length), 0);
            var resource = BackgroundVideos.Entry(file, rom, index);
            Require(resource.Length is > 0 and <= MaxBytes, "Oversized original animation bank.");
            file.Position = resource.Offset; bytes = new byte[(int)resource.Length]; file.ReadExactly(bytes);
        }
        return bytes;
    }

    internal static GamePreviewAnimation Decode(byte[] b, string game, string source = "owned animation bank") {
        string expected = game switch {
            "file1" => "04b63daf655738204ac61acbb28cff3e952f0ac1c322ffe49ebd2ccbc4181855",
            "file2" => "301097f92da1e0dca8612f349d6d72203762e6881784729d9fcb93893dd89116",
            _ => ""
        };
        Require(b.Length is > 0 and <= MaxBytes && expected.Length != 0 &&
            Convert.ToHexString(SHA256.HashData(b)).Equals(expected, StringComparison.OrdinalIgnoreCase),
            "Unsupported original Kevin animation bank.");
        Require(I(b, 0) == 0 && I(b, 4) == 5 && I(b, 16) == 200, "Invalid original player animation table.");
        int pointers = I(b, 20);
        Require(pointers >= 168 && pointers <= b.Length - 200 * 4, "Invalid original animation pointer table.");
        var decoded = Enumerable.Range(0, 36).Select(_ => Array.Empty<Track>()).ToArray();
        // The bank stores the 120-frame idle as a lower-body (0..9) and an
        // upper-body (10..21) entry. The two entries have matching key time ranges.
        foreach (int slot in new[] { 0, 1 }) {
            ParseChannel(b, I(b, pointers + slot * 4), slot == 0 ? 0 : 10, slot == 0 ? 10 : 12, Frames, decoded);
        }
        return new(decoded, source);
    }

    internal static GamePreviewAnimation DecodeHandgun(byte[] b, string game, GamePreviewAnimation idle, string source = "owned handgun motion bank") {
        string expected = game switch {
            "file1" => "0fcc915bfb353ca8d0a3e3fbac96fe23bc4609deaf45d1029b1d5d8d933036e8",
            "file2" => "cb9a9457b3277fb1a2f3b7fb67638c36d9507439dba122e951f281bfaff56286", _ => ""
        };
        Require(b.Length is > 0 and <= MaxBytes && expected.Length != 0 &&
            Convert.ToHexString(SHA256.HashData(b)).Equals(expected, StringComparison.OrdinalIgnoreCase), "Unsupported original handgun motion bank.");
        Require(I(b, 0) == 0 && I(b, 4) == 5 && I(b, 40) == 500, "Invalid original handgun motion table.");
        int pointers = I(b, 44); Require(pointers >= 328 && pointers <= b.Length - 500 * 4, "Invalid handgun motion pointer table.");
        Require(I(b, pointers) == -1 && I(b, pointers + 8) == -1, "Unexpected handgun motion channel layout.");
        var decoded = Enumerable.Range(0, 36).Select(_ => Array.Empty<Track>()).ToArray();
        // Native logical 400 supplies upper-body and both hand trees. Its lower
        // channel is absent, so the original lower-body idle 100 keeps running.
        ParseChannel(b, I(b, pointers + 4), 10, 12, 10, decoded);
        ParseChannel(b, I(b, pointers + 12), 28, 4, 10, decoded);
        ParseChannel(b, I(b, pointers + 16), 32, 4, 10, decoded);
        return new(decoded, source, idle);
    }

    static void ParseChannel(byte[] b, int at, int first, int boneCount, int frames, Track[][] decoded) {
            int count = I(b, at + 4), size = I(b, at + 8);
            Require(I(b, at) == unchecked((int)0x80000002) && count == boneCount &&
                size >= 20 && at >= 0 && at <= b.Length - size, "Invalid original idle container.");
            int end = at + size; Require(I(b, at + 12) == 0 && F(b, at + 16) == 0, "Unsupported original idle loop metadata.");
            at += 20;
            for (int bone = 0; bone < count; bone++) {
                int mask = I(b, at), children = I(b, at + 4), boneSize = I(b, at + 8);
                Require((mask & unchecked((int)0xfffffe00)) == unchecked((int)0x80000000) && children is >= 0 and <= 9 &&
                    boneSize >= 12 && at <= end - boneSize, "Invalid original idle bone tracks.");
                int boneEnd = at + boneSize; at += 12; var channels = new List<Track>(); var axes = new HashSet<int>();
                for (int c = 0; c < children; c++) {
                    int flags = I(b, at), keys = I(b, at + 4), keySize = I(b, at + 8), axis = flags & 0x1ff;
                    Require(axis is 1 or 2 or 4 or 8 or 16 or 32 or 64 or 128 or 256 && axes.Add(axis) &&
                        keys is > 0 and <= 1024 && keySize >= 12 && at <= boneEnd - keySize, "Invalid original idle channel.");
                    bool packed = (flags & unchecked((int)0xffff0000)) == unchecked((int)0x80120000);
                    bool floating = (flags & unchecked((int)0xffff0000)) == unchecked((int)0x80220000);
                    Require((packed || floating) && keySize == 12 + keys * (packed ? 8 : 16), "Unsupported original idle key encoding.");
                    var values = new Key[keys];
                    // Linear/scale shorts use four fraction bits: the unit-scale
                    // keys are 16, and the idle's 1688 hip-Y value becomes 105.5.
                    // This retains the authored grounded feet instead of /15 drift.
                    for (int k = 0; k < keys; k++) {
                        int p = at + 12 + k * (packed ? 8 : 16);
                        values[k] = DecodeKey(b, p, packed, axis);
                        Require(values[k].Frame >= 0 && values[k].Frame <= frames &&
                            (k == 0 || values[k].Frame > values[k - 1].Frame), "Unordered original idle keys.");
                    }
                    Require(values[0].Frame == 0 && values[^1].Frame == frames, "Incomplete original idle time range.");
                    channels.Add(new(axis, values)); at += keySize;
                }
                Require(at == boneEnd, "Trailing original idle bone data."); decoded[first + bone] = channels.ToArray();
            }
            Require(at == end, "Trailing original idle clip data.");
    }

    internal void Apply(int joint, double seconds, ref Vector3 translation, ref Quaternion rotation, ref Vector3 scale) {
        // Original healthy-idle handler 0x6747F0 requests lower100 then full
        // upper400; no substitute torso/head curves or preview pose offsets.
        if (lowerIdle != null && joint < 10) {
            lowerIdle.Apply(joint, seconds, ref translation, ref rotation, ref scale); return;
        }
        if ((uint)joint >= tracks.Length || tracks[joint].Length == 0) return;
        double elapsed = (double.IsFinite(seconds) ? Math.Max(0, seconds) : 0) * FramesPerSecond;
        // The ready transition plays once. Holding its last authored upper/hand
        // pose avoids repeatedly jerking back to frame zero every ten frames.
        float frame = (float)(lowerIdle != null ? Math.Min(10, elapsed) : elapsed % Frames);
        Vector3 euler = default; bool rotates = false;
        foreach (var track in tracks[joint]) {
            float value = track.Evaluate(frame);
            switch (track.Axis) {
                case 1: scale.X = value; break;
                case 2: scale.Y = value; break;
                case 4: scale.Z = value; break;
                case 8: euler.X = value; rotates = true; break;
                case 16: euler.Y = value; rotates = true; break;
                case 32: euler.Z = value; rotates = true; break;
                case 64: translation.X = value; break;
                case 128: translation.Y = value; break;
                case 256: translation.Z = value; break;
            }
        }
        if (rotates) rotation = Quaternion.CreateFromRotationMatrix(Matrix4x4.CreateRotationX(euler.X) *
            Matrix4x4.CreateRotationY(euler.Y) * Matrix4x4.CreateRotationZ(euler.Z));
    }
}
