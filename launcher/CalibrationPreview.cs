using System.Globalization;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

// Brightness/gamma reference drawn by the launcher, shown until a room capture from
// the player's own game exists. No game artwork is shipped; the colour preview effect
// applies the sliders to this image exactly as it does to a room capture.
internal static class CalibrationPreview {
    internal const int Width = 960, Height = 320;
    // Grey levels of the near-black and near-white patches (0-255).
    internal static readonly byte[] Shadows = { 4, 8, 12, 16, 24, 32 };
    internal static readonly byte[] Highlights = { 251, 247, 243, 239, 231, 223 };

    internal static BitmapSource Create() {
        var visual = new DrawingVisual();
        using (var dc = visual.RenderOpen()) {
            void Box(double x, double y, double w, double h, byte level) =>
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(level, level, level)), null,
                                 new Rect(x, y, w, h));
            void Text(string text, double x, double y, double size, byte level, bool center = false) {
                var formatted = new FormattedText(text, CultureInfo.CurrentUICulture, FlowDirection.LeftToRight,
                                                  new Typeface("Segoe UI"), size,
                                                  new SolidColorBrush(Color.FromRgb(level, level, level)), 1.0);
                dc.DrawText(formatted, new Point(center ? x - formatted.Width / 2 : x, y));
            }
            Box(0, 0, Width, Height, 0);
            // Full ramp: 16 even steps from black to white.
            const double rampX = 40, rampWidth = Width - 80, step = rampWidth / 16;
            // A frame shows where the ramp starts; its first step is pure black.
            dc.DrawRectangle(null, new Pen(new SolidColorBrush(Color.FromRgb(96, 96, 96)), 1),
                             new Rect(rampX - 3.5, 24.5, rampWidth + 7, 67));
            for (int i = 0; i < 16; ++i)
                Box(rampX + i * step, 28, Math.Ceiling(step), 60, (byte)(i * 255 / 15));
            // Near-black patches on black and near-white patches on white.
            const double panelWidth = 420, top = 116, panelHeight = 136;
            Box(rampX, top, panelWidth, panelHeight, 0);
            Box(Width - rampX - panelWidth, top, panelWidth, panelHeight, 255);
            for (int i = 0; i < Shadows.Length; ++i) {
                Box(rampX + 24 + i * 64, top + 24, 48, 48, Shadows[i]);
                Box(Width - rampX - panelWidth + 24 + i * 64, top + 24, 48, 48, Highlights[i]);
            }
            Text("Shadows: the darkest squares should be just visible", rampX + 24, top + 90, 15, 150);
            Text("Highlights: the brightest squares should be just visible",
                 Width - rampX - panelWidth + 24, top + 90, 15, 90);
            Text("Each step of the bar above should look different", Width / 2.0, 272, 15, 150, center: true);
        }
        var bitmap = new RenderTargetBitmap(Width, Height, 96, 96, PixelFormats.Pbgra32);
        bitmap.Render(visual);
        bitmap.Freeze();
        return bitmap;
    }
}
