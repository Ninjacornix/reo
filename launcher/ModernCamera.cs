using System.Globalization;
using System.IO;

namespace Outbreak.Launcher;

// Third-person "modern camera" for File #1 and File #2, built on the native room camera swap
// (docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md). Works with a controller
// (right stick looks, left stick walks relative to the camera) and with keyboard
// and mouse (mouse looks, WASD walks relative to the camera, right button aims,
// left button is cross, wheel zooms, C frees the cursor). L3 (Z) switches
// between third and first person; aiming shows a crosshair and picks the game's
// aim height from where the camera looks.
public sealed class ModernCameraOptions {
    public bool Enabled { get; set; }
    public bool MouseLook { get; set; } = true;
    // "third" or "first"; L3 (Z on keyboard) switches during play.
    public string View { get; set; } = "third";
    // Percent of the default sensitivities (mouse 0.06 degrees per count, stick 4/3 degrees per frame).
    public int MouseSensitivity { get; set; } = 100;
    public int StickSpeed { get; set; } = 100;
    public bool InvertY { get; set; }
    // Over-the-shoulder framing: distance behind the shoulder and sideways offset.
    public int Distance { get; set; } = 170;
    public int Shoulder { get; set; } = 45;

    public ModernCameraOptions Clamped() => new() {
        Enabled = Enabled,
        MouseLook = MouseLook,
        View = View == "first" ? "first" : "third",
        MouseSensitivity = Math.Clamp(MouseSensitivity, 10, 400),
        StickSpeed = Math.Clamp(StickSpeed, 10, 400),
        InvertY = InvertY,
        Distance = Math.Clamp(Distance, 60, 600),
        Shoulder = Math.Clamp(Shoulder, -120, 120)
    };
}

public static class ModernCamera {
    // Present in a game executable built with the native room camera and its TPS mod.
    public const string BuildMarker = "REO_CAMERA_MOD";

    // Game process environment. Empty when the camera is off.
    public static IReadOnlyDictionary<string, string> Environment(ModernCameraOptions options) {
        var o = options.Clamped();
        if (!o.Enabled) return new Dictionary<string, string>();
        string F(double value) => value.ToString("0.###", CultureInfo.InvariantCulture);
        double mouse = 0.06 * o.MouseSensitivity / 100.0, stick = o.StickSpeed / 100.0;
        return new Dictionary<string, string> {
            ["REO_NATIVE_ROOM_CAMERA"] = "1",
            ["REO_CAMERA_MOD"] = "tps",
            ["REO_CAMERA_MOUSE"] = o.MouseLook ? "1" : "0",
            ["REO_CAMERA_VIEW"] = o.View,
            ["REO_CAMERA_TPS"] = $"distance={o.Distance},side={o.Shoulder},mouse_sens={F(mouse)}," +
                                 $"yaw_speed={F(4 * stick)},pitch_speed={F(3 * stick)},invert_y={(o.InvertY ? 1 : 0)}"
        };
    }

    static readonly Dictionary<string, (long Length, DateTime Written, bool Supported)> supportCache = new();

    // Whether the executable contains the camera build marker. Cached per file version.
    public static bool Supported(string exe) {
        try {
            var info = new FileInfo(exe);
            if (!info.Exists) return false;
            lock (supportCache)
                if (supportCache.TryGetValue(info.FullName, out var cached) &&
                    cached.Length == info.Length && cached.Written == info.LastWriteTimeUtc)
                    return cached.Supported;
            bool found = GameSession.HasMarker(info.FullName, BuildMarker);
            lock (supportCache) supportCache[info.FullName] = (info.Length, info.LastWriteTimeUtc, found);
            return found;
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            return false;
        }
    }
}
