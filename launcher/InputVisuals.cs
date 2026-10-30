using System.Globalization;
using System.Windows;
using System.Windows.Media;

namespace Outbreak.Launcher;
public static class InputFeedback {
    public static readonly DependencyProperty IsActiveProperty = DependencyProperty.RegisterAttached(
        "IsActive", typeof(bool), typeof(InputFeedback), new PropertyMetadata(false));
    public static bool GetIsActive(DependencyObject target) => (bool)target.GetValue(IsActiveProperty);
    public static void SetIsActive(DependencyObject target, bool value) =>
        target.SetValue(IsActiveProperty, value);
}

public sealed class StickPlot : FrameworkElement {
    Pad raw = new(), output = new();
    int zone;
    bool right;
    public void Update(Pad input, Pad mapped, int deadZone, bool rightStick) {
        if (raw == input && output == mapped && zone == deadZone && right == rightStick)
            return;
        raw = input;
        output = mapped;
        zone = deadZone;
        right = rightStick;
        InvalidateVisual();
    }
    static void DrawText(DrawingContext dc, string text, Point center, double size, Brush brush) {
        var formatted =
            new FormattedText(text, CultureInfo.CurrentUICulture, FlowDirection.LeftToRight,
                              new Typeface("Segoe UI"), size, brush, 1);
        dc.DrawText(formatted,
                    new(center.X - formatted.Width / 2, center.Y - formatted.Height / 2));
    }
    protected override void OnRender(DrawingContext dc) {
        double radius = Math.Min(ActualWidth, ActualHeight - 22) / 2 - 8;
        if (radius < 1)
            return;
        var center = new Point(ActualWidth / 2, radius + 5);
        var line = new Pen(Palette.Brush(Palette.Text, Palette.Outline), 1);
        dc.DrawEllipse(Palette.Brush(Palette.Background), line, center, radius,
                       radius);
        dc.DrawLine(line, new(center.X - radius, center.Y), new(center.X + radius, center.Y));
        dc.DrawLine(line, new(center.X, center.Y - radius), new(center.X, center.Y + radius));
        dc.DrawEllipse(Palette.Brush(Palette.Accent, 100),
                       new Pen(Palette.Brush(Palette.Accent), 1), center,
                       radius * zone / 100, radius * zone / 100);
        double rx = right ? raw.RX : raw.LX, ry = right ? raw.RY : raw.LY;
        double ox = right ? output.RX : output.LX, oy = right ? output.RY : output.LY;
        dc.DrawEllipse(null, new Pen(Palette.Brush(Palette.TextMuted), 1.5),
                       new(center.X + rx / 32768 * radius, center.Y - ry / 32768 * radius), 5, 5);
        dc.DrawEllipse(Palette.Brush(Palette.Text), null,
                       new(center.X + ox / 32768 * radius, center.Y - oy / 32768 * radius), 3, 3);
        DrawText(dc, right ? "Right stick" : "Left stick", new(center.X, radius * 2 + 14), 11,
                 Palette.Brush(Palette.TextMuted));
    }
}
