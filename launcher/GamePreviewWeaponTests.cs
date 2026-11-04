using System.IO;
using System.Numerics;

namespace Outbreak.Launcher;

internal static class GamePreviewWeaponTests {
    internal static void Run(Action<bool, string> check) {
        check(GamePreviewWeapon.ReadFromSource("missing-preview-weapon.pak", "file1") == null &&
              GamePreviewWeapon.ReadFromSource("missing-preview-weapon.pak", "unknown") == null,
            "Preview handgun leaves unavailable weapon sources absent");
        bool refuses = false;
        try { GamePreviewWeapon.Decode(new byte[128], "file1"); } catch (InvalidDataException) { refuses = true; }
        check(refuses, "Preview handgun refuses unrecognized object model banks");
    }

    internal static void CheckOwned(GamePreviewWeapon weapon, Action<bool, string> check) {
        check(weapon.Meshes.Count == 2 && weapon.Meshes[0].Positions.Length == 467 &&
              weapon.Meshes.Sum(m => m.Indices.Length / 3) == 259 && weapon.Textures.Count == 2,
            "Owned handgun retains the original pistol geometry and its two used materials");
        weapon.Update(Matrix4x4.Identity); var mesh = weapon.Meshes[0]; var initial = mesh.Positions.ToArray();
        var transform = Matrix4x4.CreateFromYawPitchRoll(.8f, .5f, -.3f) * Matrix4x4.CreateTranslation(25, 90, 20);
        weapon.Update(transform); var attached = mesh.Positions.ToArray();
        check(initial.Zip(attached).All(p => Vector3.Distance(Vector3.Transform(p.First, transform), p.Second) < .0001f),
            "Handgun geometry follows the complete animated hand rotation and translation");
        check(Math.Abs(Vector3.Distance(initial[0], initial[100]) - Vector3.Distance(attached[0], attached[100])) < .0001f &&
              mesh.Normals.All(n => float.IsFinite(n.X + n.Y + n.Z) && Math.Abs(n.LengthSquared() - 1) < .001f),
            "Handgun attachment preserves rigid dimensions and finite unit normals");
        weapon.Update(Matrix4x4.Identity);
        check(initial.SequenceEqual(mesh.Positions), "Handgun attachment evaluates from authored geometry without accumulated drift");
    }
}
