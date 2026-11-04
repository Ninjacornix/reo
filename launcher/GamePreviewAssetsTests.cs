using System.IO;
using System.IO.Compression;
using System.Numerics;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class GamePreviewAssetsTests {
    internal static void Run(Action<bool, string> check) {
        string temp = Path.Combine(Path.GetTempPath(), "reo-preview-assets-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        bool Refuses(Action operation) { try { operation(); return false; } catch (InvalidDataException) { return true; } }
        try {
            check(GamePreviewAssets.Load(temp, "unknown", temp) == null && GamePreviewAssets.Load(temp, "file1", temp) == null,
                "Live preview leaves missing imports and unsupported games unavailable");
            check(GamePreviewAssets.LoadShared(temp, temp, temp) == null,
                "The shared preview leaves missing assets unavailable without generating a character");
            check(Refuses(() => GamePreviewAssets.Decode(new byte[128])), "Live preview rejects unrecognized model payloads");
            string Pack(string game, string? member) {
                string path = Path.Combine(temp, Guid.NewGuid().ToString("N") + ".pak");
                using var zip = ZipFile.Open(path, ZipArchiveMode.Create);
                if (member != null) {
                    using var writer = new StreamWriter(zip.CreateEntry("assets.json").Open());
                    writer.Write(JsonSerializer.Serialize(new { game, entries = new[] { new { path = "NETBIO00.DAT/0/491", file = member } } }));
                }
                return path;
            }
            check(GamePreviewAssets.LoadPak(Pack("file1", null), "file1") == null,
                "Live preview ignores packs without an original asset index");
            check(Refuses(() => GamePreviewAssets.LoadPak(Pack("file2", "model.nbd"), "file1")),
                "Live preview refuses packs belonging to another game");
            check(GamePreviewAssets.LoadShared(Pack("file2", "model.nbd"), temp, temp) == null,
                "An invalid first-edition pack does not escape the shared asset fallback");
            check(Refuses(() => GamePreviewAssets.LoadPak(Pack("file1", "../model.nbd"), "file1")),
                "Live preview refuses unsafe model member names before reading them");
            check(Refuses(() => GamePreviewAssets.LoadPak(Pack("file1", "missing.nbd"), "file1")),
                "Live preview reports incomplete indexed model packs");
        } finally { Directory.Delete(temp, true); }
    }

    // Explicitly invoked by owned-data diagnostics; no owned assets are distributed.
    internal static void CheckOwned(GamePreviewScene scene, Action<bool, string> check) {
        check(scene.Meshes.Count >= 5 && scene.Meshes.Take(5).Sum(m => m.Indices.Length / 3) == 3910 &&
              scene.Textures.Count >= 2 && scene.Textures.Take(2).All(t => t.Width == 256 && t.Height == 256 && t.Rgba.Length == 256 * 256 * 4),
            "Owned Kevin pack decodes all four model parts and both original textures");
        check(scene.Meshes.All(m => m.Indices.Length % 3 == 0 && m.Indices.All(i => i >= 0 && i < m.Positions.Length) &&
              m.TexCoords.Length == m.Positions.Length && m.Normals.Length == m.Positions.Length && m.TextureIndex >= 0 && m.TextureIndex < scene.Textures.Count),
            "Owned preview geometry keeps valid material, attribute and triangle references");
        double settled = scene.HasHandgunAnimation ? 1 : 0;
        scene.Animate(settled); var first = scene.Meshes.SelectMany(m => m.Positions).ToArray();
        scene.Animate(settled + 1); var later = scene.Meshes.SelectMany(m => m.Positions).ToArray();
        check(first.Zip(later).Count(p => Vector3.Distance(p.First, p.Second) > .0001f) > 3000 &&
              later.All(p => float.IsFinite(p.X) && float.IsFinite(p.Y) && float.IsFinite(p.Z)),
            "Owned preview idle changes skinned vertices and produces finite positions");
        scene.Animate(settled); var returned = scene.Meshes.SelectMany(m => m.Positions).ToArray();
        check(first.SequenceEqual(returned), "Preview animation evaluates from bind data without accumulating pose drift");
        check(scene.Minimum.Y == 0 && scene.Maximum.Y is > 170 and < 175 &&
              scene.Meshes.SelectMany(m => m.Positions).All(p => p.Y > -1 && p.Y < 180),
            "Preview skinning retains grounded feet and the original character scale");
        if (scene.HasOriginalAnimation) {
            bool grounded = true, finite = true;
            for (int frame = 0; frame <= 120; frame++) {
                scene.Animate(settled + frame / 30.0);
                var points = scene.Meshes.SelectMany(m => m.Positions);
                float floor = points.Min(p => p.Y);
                grounded &= floor > -1 && floor < 1;
                finite &= points.All(p => float.IsFinite(p.X + p.Y + p.Z));
            }
            check(grounded && finite, "Original idle keeps the skinned boots within one centimeter of the floor throughout its full loop");
            check(first.SequenceEqual(scene.Meshes.SelectMany(m => m.Positions)),
                "Original idle returns the settled skinned model to its starting pose after 120 frames");
            scene.Animate(settled);
        }
    }
}
