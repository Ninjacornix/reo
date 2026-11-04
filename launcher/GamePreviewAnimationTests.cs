using System.Numerics;
using System.IO;
using System.IO.Compression;

namespace Outbreak.Launcher;

internal static class GamePreviewAnimationTests {
    internal static void Run(Action<bool, string> check) {
        // Original PL00_pc_000 bone19 rotationY, native evaluator 0x18E710 /
        // 0x18F260 at frame8.5: packed value542.65625, then PI/8192 radians.
        byte[] nativeKeys = new short[] { 570, 0, -2, -4, 548, 34, 3, 3 }
            .SelectMany(BitConverter.GetBytes).ToArray();
        var nativeCurve = new GamePreviewAnimation.Track(16, new[] {
            GamePreviewAnimation.DecodeKey(nativeKeys, 0, true, 16),
            GamePreviewAnimation.DecodeKey(nativeKeys, 8, true, 16) });
        check(Math.Abs(nativeCurve.Evaluate(8.5f) - .20810606548151686) < .0000001,
            "Original packed key tangents match the native asymmetric Hermite sample");
        var parentScale = new Vector3(2, 3, 4);
        var parentWorld = Matrix4x4.CreateScale(parentScale) * Matrix4x4.CreateTranslation(10, 20, 30);
        var child = GamePreviewScene.AnimatedWorld(new(1.1f, 1.2f, 1.3f), Quaternion.Identity,
            new(1, 2, 3), parentScale, parentWorld);
        check(Vector3.Distance(child.Translation, new(12, 26, 42)) < .00001f &&
            Math.Abs(Vector3.TransformNormal(Vector3.UnitX, child).Length() - 1.1f) < .00001f &&
            Math.Abs(Vector3.TransformNormal(Vector3.UnitY, child).Length() - 1.2f) < .00001f &&
            Math.Abs(Vector3.TransformNormal(Vector3.UnitZ, child).Length() - 1.3f) < .00001f,
            "Native animated hierarchy compensates inherited scale without removing parent-scaled translation");
        check(GamePreviewAnimation.ReadFromSource("missing-preview-animation.pak", "file1") == null &&
              GamePreviewAnimation.ReadFromSource("missing-preview-animation.pak", "unknown") == null,
            "Original idle leaves unavailable animation sources absent");
        bool refuses = false;
        try { GamePreviewAnimation.Decode(new byte[64], "file1"); } catch (System.IO.InvalidDataException) { refuses = true; }
        check(refuses, "Original idle rejects unrecognized animation bank bytes");
        bool RefusesIndex(string entries) {
            string path = Path.Combine(Path.GetTempPath(), "reo-animation-index-" + Guid.NewGuid().ToString("N") + ".pak");
            try {
                using (var zip = ZipFile.Open(path, ZipArchiveMode.Create)) {
                    using var writer = new StreamWriter(zip.CreateEntry("assets.json").Open());
                    writer.Write("{\"game\":\"file1\",\"entries\":" + entries + "}");
                }
                try { GamePreviewAnimation.ReadFromSource(path, "file1"); return false; }
                catch (InvalidDataException) { return true; }
            } finally { File.Delete(path); }
        }
        check(RefusesIndex("[null]"), "Original idle refuses malformed asset-index entry types without escaping its load error path");
        check(RefusesIndex("[" + string.Join(',', Enumerable.Repeat("null", 100001)) + "]"),
            "Original idle bounds the asset index before visiting its entries");
        var linear = new GamePreviewAnimation.Track(8, new[] {
            new GamePreviewAnimation.Key(1, 0, 2, 2), new GamePreviewAnimation.Key(5, 2, 2, 2) });
        check(linear.Evaluate(-1) == 1 && linear.Evaluate(0) == 1 && linear.Evaluate(1) == 3 &&
              linear.Evaluate(2) == 5 && linear.Evaluate(3) == 5,
            "Original idle Hermite sampling honors endpoint values and slopes in frame units");
        var eased = new GamePreviewAnimation.Track(64, new[] {
            new GamePreviewAnimation.Key(0, 0, 0, 0), new GamePreviewAnimation.Key(8, 4, 0, 0) });
        check(Math.Abs(eased.Evaluate(1) - 1.25f) < .000001f && Math.Abs(eased.Evaluate(2) - 4) < .000001f,
            "Original idle retains authored ease curves rather than replacing them with linear interpolation");
    }

    internal static void CheckOwned(GamePreviewAnimation animation, Action<bool, string> check) {
        check(animation.IsExtractedOriginal && animation.Duration == 4 && animation.TrackCount == 69 && animation.BoneCount == 20,
            "Owned Kevin idle decodes the original 120-frame paired lower and upper tracks");
        (Vector3 Translation, Quaternion Rotation, Vector3 Scale) Pose(int bone, double time) {
            var translation = bone == 2 ? new Vector3(0, 110, 0) : Vector3.Zero;
            var rotation = Quaternion.Identity; var scale = Vector3.One;
            animation.Apply(bone, time, ref translation, ref rotation, ref scale); return (translation, rotation, scale);
        }
        check(Pose(2, 0).Translation.Y == 105.5f && Pose(10, 0).Scale == Vector3.One,
            "Owned idle decodes four-bit linear values without raising the feet or stretching unit scale");
        var start = Enumerable.Range(0, 36).Select(i => Pose(i, 0)).ToArray();
        var nextLoop = Enumerable.Range(0, 36).Select(i => Pose(i, animation.Duration)).ToArray();
        check(start.SequenceEqual(nextLoop), "Original idle returns to its first authored pose at the next loop");
        check(Enumerable.Range(0, 36).Any(i => Pose(i, 0) != Pose(i, 1)),
            "Original idle evaluates changing authored joint transforms");
        bool finite = true;
        for (int frame = 0; frame <= 120; frame++) for (int bone = 0; bone < 36; bone++) {
            var pose = Pose(bone, frame / 30.0);
            finite &= float.IsFinite(pose.Translation.X + pose.Translation.Y + pose.Translation.Z) &&
                float.IsFinite(pose.Rotation.X + pose.Rotation.Y + pose.Rotation.Z + pose.Rotation.W) &&
                float.IsFinite(pose.Scale.X + pose.Scale.Y + pose.Scale.Z);
        }
        check(finite, "All owned idle joint transforms remain finite across the complete loop");
    }

    internal static void CheckHandgunTree(GamePreviewAnimation animation, Action<bool, string> check) {
        check(animation.HasHandgunStance && animation.IsExtractedOriginal && animation.TrackCount == 84 && animation.BoneCount == 28,
            "Handgun animation tree combines the original lower idle, upper ready and both finger channels");
        (Vector3 Translation, Quaternion Rotation, Vector3 Scale) Pose(int bone, double time) {
            var translation = bone == 2 ? new Vector3(0, 110, 0) : Vector3.Zero;
            var rotation = Quaternion.Identity; var scale = Vector3.One;
            animation.Apply(bone, time, ref translation, ref rotation, ref scale); return (translation, rotation, scale);
        }
        check(Pose(13, 0) != Pose(13, 1) && Pose(13, 1) == Pose(13, 3),
            "Original handgun upper transition advances once and holds its final pose");
        check(Pose(34, 0) != Pose(34, 1) && Pose(34, 1) == Pose(34, 3) && Pose(29, 0) == Pose(29, 1),
            "Original handgun finger tree closes the carrying hand while preserving the other hand channel");
        check(Pose(2, 1) != Pose(2, 2), "Lower-body idle continues while the handgun upper pose is held");
        check(new[] { 10, 11, 12, 20, 21 }.All(i => Pose(i, 1) == Pose(i, 2)),
            "The original full upper400 tree remains intact without substituted torso or head animation");
        check(Enumerable.Range(0, 36).All(i => Pose(i, 1) == Pose(i, 5)),
            "Settled handgun animation retains the original four-second lower-body preview loop without restarting the upper transition");
    }
}
