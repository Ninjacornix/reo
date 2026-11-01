using System.Globalization;

namespace Outbreak.Launcher.Desktop.Controls;

// Port of RC1 InputVisuals.cs StickPlot.
public sealed class StickPlot : Control {
    Pad output = new();
    int zone;
    bool right;
    public void Update(Pad mapped, int deadZone, bool rightStick) {
        if (output == mapped && zone == deadZone && right == rightStick)
            return;
        output = mapped;
        zone = deadZone;
        right = rightStick;
        InvalidateVisual();
    }
    internal Point Position => new((right ? output.RX : output.LX) / 32768.0,
        -(right ? output.RY : output.LY) / 32768.0);
    static void DrawText(DrawingContext dc, string text, Point center, double size, IBrush brush) {
        var formatted =
            new FormattedText(text, CultureInfo.CurrentUICulture, FlowDirection.LeftToRight,
                              new Typeface(OperatingSystem.IsWindows() ? "Segoe UI" : "Segoe UI, Helvetica Neue, DejaVu Sans"), size, brush);
        dc.DrawText(formatted,
                    new(center.X - formatted.Width / 2, center.Y - formatted.Height / 2));
    }
    public override void Render(DrawingContext dc) {
        double radius = Math.Min(Bounds.Width, Bounds.Height - 22) / 2 - 8;
        if (radius < 1)
            return;
        var center = new Point(Bounds.Width / 2, radius + 5);
        var line = new Pen(VisualPalette.Brush(Palette.Text, Palette.Outline), 1);
        dc.DrawEllipse(VisualPalette.Brush(Palette.Background), line, center, radius,
                       radius);
        dc.DrawLine(line, new(center.X - radius, center.Y), new(center.X + radius, center.Y));
        dc.DrawLine(line, new(center.X, center.Y - radius), new(center.X, center.Y + radius));
        dc.DrawEllipse(VisualPalette.Brush(Palette.Accent, 100),
                       new Pen(VisualPalette.Brush(Palette.Accent), 1), center,
                       radius * zone / 100, radius * zone / 100);
        var position = Position;
        dc.DrawEllipse(VisualPalette.Brush(Palette.Text), null,
                       new(center.X + position.X * radius, center.Y + position.Y * radius), 3, 3);
        DrawText(dc, right ? "Right stick" : "Left stick", new(center.X, radius * 2 + 14), 11,
                 VisualPalette.Brush(Palette.TextMuted));
    }
}
