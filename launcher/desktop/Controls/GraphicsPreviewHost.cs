using Avalonia.Media.Imaging;

namespace Outbreak.Launcher.Desktop.Controls;

// Port of RC1 PreviewRotation.cs. Direct manipulation only: releasing the pointer preserves the
// angle. There is no velocity, coast, idle turn or return animation.
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

// RC1 GraphicsPreviewHost input and surface. RC1 presents Kevin from a native GPU child window;
// this surface presents the same renderer's frames inside the common view.
public sealed class GraphicsPreviewHost : Control {
    internal PreviewRotation Rotation { get; } = new();
    internal event EventHandler? RotationChanged;
    internal bool HasPresentedFrame { get; set; }
    WriteableBitmap? frame;
    public GraphicsPreviewHost() {
        Focusable = true;
        Cursor = new Cursor(StandardCursorType.Hand);
        PropertyChanged += (_, e) => {
            if (e.Property == IsVisibleProperty && !IsVisible) { EndRotation(); HasPresentedFrame = false; }
        };
        DetachedFromVisualTree += (_, _) => EndRotation();
        AddHandler(KeyDownEvent, (_, e) => {
            if (e.Key == Key.Home) { Rotation.Reset(); RotationChanged?.Invoke(this, EventArgs.Empty); e.Handled = true; }
        }, RoutingStrategies.Tunnel);
    }
    internal (int Width, int Height) PixelSize {
        get {
            double scale = TopLevel.GetTopLevel(this)?.RenderScaling ?? 1;
            return (Math.Max(1, (int)(Bounds.Width * scale)), Math.Max(1, (int)(Bounds.Height * scale)));
        }
    }
    internal void Present(PreviewFrame value) {
        if (frame == null || frame.PixelSize.Width != value.Width || frame.PixelSize.Height != value.Height) {
            frame?.Dispose();
            frame = new WriteableBitmap(new PixelSize(value.Width, value.Height), new Vector(96, 96),
                Avalonia.Platform.PixelFormat.Bgra8888, Avalonia.Platform.AlphaFormat.Unpremul);
        }
        using (var pixels = frame.Lock())
            for (int y = 0; y < value.Height; y++)
                System.Runtime.InteropServices.Marshal.Copy(value.Bgra, y * value.Width * 4, pixels.Address + y * pixels.RowBytes, value.Width * 4);
        HasPresentedFrame = true;
        InvalidateVisual();
    }
    public override void Render(DrawingContext context) {
        var bounds = new Rect(Bounds.Size);
        context.FillRectangle(VisualPalette.Brush(Palette.Background), bounds);
        if (frame != null && HasPresentedFrame)
            context.DrawImage(frame, new Rect(frame.Size), bounds);
    }
    void EndRotation() { if (!Rotation.Dragging) return; Rotation.End(); Cursor = new Cursor(StandardCursorType.Hand); }
    protected override void OnPointerPressed(PointerPressedEventArgs e) {
        base.OnPointerPressed(e);
        if (!e.GetCurrentPoint(this).Properties.IsLeftButtonPressed) return;
        Focus(); Rotation.Begin(e.GetPosition(this)); e.Pointer.Capture(this);
        Cursor = new Cursor(StandardCursorType.SizeAll); e.Handled = true;
    }
    protected override void OnPointerMoved(PointerEventArgs e) {
        base.OnPointerMoved(e);
        if (!Rotation.Dragging) return;
        if (!e.GetCurrentPoint(this).Properties.IsLeftButtonPressed) EndRotation();
        else if (Rotation.Move(e.GetPosition(this))) RotationChanged?.Invoke(this, EventArgs.Empty);
        e.Handled = true;
    }
    protected override void OnPointerReleased(PointerReleasedEventArgs e) {
        base.OnPointerReleased(e);
        EndRotation(); e.Pointer.Capture(null); e.Handled = true;
    }
    protected override void OnPointerCaptureLost(PointerCaptureLostEventArgs e) {
        base.OnPointerCaptureLost(e);
        Rotation.End(); Cursor = new Cursor(StandardCursorType.Hand);
    }
    protected override void OnPointerWheelChanged(PointerWheelEventArgs e) {
        base.OnPointerWheelChanged(e);
        // WM_MOUSEWHEEL reports 120 per notch, including high-resolution partial deltas.
        if (Rotation.Scroll((int)Math.Round(e.Delta.Y * 120))) RotationChanged?.Invoke(this, EventArgs.Empty);
        e.Handled = true;
    }
}
