using System.Windows;

namespace Outbreak.Launcher;

// Direct manipulation only: releasing the pointer preserves the angle. There
// is no velocity, coast, idle turn or return animation.
internal sealed class PreviewRotation {
    internal float Yaw { get; private set; }
    internal float Pitch => 0;
    internal float Zoom { get; private set; } = 1;
    internal bool Dragging { get; private set; }
    Point origin;
    float startYaw;
    internal void Begin(Point point) { origin = point; startYaw = Yaw; Dragging = true; }
    internal bool Move(Point point) {
        if (!Dragging) return false;
        var delta = point - origin;
        float next = (float)((startYaw + delta.X * .6) % 360);
        if (next == Yaw) return false;
        Yaw = next; return true;
    }
    internal void End() => Dragging = false;
    internal bool Scroll(int delta) {
        float next = (float)Math.Clamp(Zoom * Math.Pow(1.12, delta / 120.0), .65, 2.5);
        if (next == Zoom) return false;
        Zoom = next; return true;
    }
    internal void Reset() { End(); Yaw = 0; Zoom = 1; }
}
