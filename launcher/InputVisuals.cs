using System.Globalization;
using System.Windows;
using System.Windows.Media;

namespace Outbreak.Launcher;
public sealed class StickPlot : FrameworkElement
{
    Pad raw = new(), output = new(); int zone; bool right;
    public void Update(Pad input, Pad mapped, int deadZone, bool rightStick) { raw = input; output = mapped; zone = deadZone; right = rightStick; InvalidateVisual(); }
    static void DrawText(DrawingContext dc, string text, Point center, double size, Brush brush)
    {
        var formatted = new FormattedText(text, CultureInfo.CurrentUICulture, FlowDirection.LeftToRight, new Typeface("Segoe UI"), size, brush, 1);
        dc.DrawText(formatted, new(center.X - formatted.Width / 2, center.Y - formatted.Height / 2));
    }
    protected override void OnRender(DrawingContext dc)
    {
        double radius = Math.Min(ActualWidth, ActualHeight - 22) / 2 - 8;
        if (radius < 1) return;
        var center = new Point(ActualWidth / 2, radius + 5);
        var line = new Pen(new SolidColorBrush(Color.FromRgb(66, 78, 79)), 1);
        dc.DrawEllipse(new SolidColorBrush(Color.FromRgb(22, 29, 31)), line, center, radius, radius);
        dc.DrawLine(line, new(center.X - radius, center.Y), new(center.X + radius, center.Y));
        dc.DrawLine(line, new(center.X, center.Y - radius), new(center.X, center.Y + radius));
        dc.DrawEllipse(new SolidColorBrush(Color.FromArgb(100, 146, 77, 77)), new Pen(new SolidColorBrush(Color.FromRgb(153, 90, 90)), 1), center, radius * zone / 100, radius * zone / 100);
        double rx = right ? raw.RX : raw.LX, ry = right ? raw.RY : raw.LY;
        double ox = right ? output.RX : output.LX, oy = right ? output.RY : output.LY;
        dc.DrawEllipse(null, new Pen(Brushes.Gray, 1.5), new(center.X + rx / 32768 * radius, center.Y - ry / 32768 * radius), 5, 5);
        dc.DrawEllipse(new SolidColorBrush(Color.FromRgb(172, 201, 184)), null, new(center.X + ox / 32768 * radius, center.Y - oy / 32768 * radius), 3, 3);
        DrawText(dc, right ? "Right stick" : "Left stick", new(center.X, radius * 2 + 14), 11, Brushes.Silver);
    }
}
