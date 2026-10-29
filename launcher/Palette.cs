using System.Windows.Markup;
using System.Windows.Media;

namespace Outbreak.Launcher;

// The launcher's only colours: two soft blacks, two warm ivories and two burnt oranges. Soft
// black covers most of the window, ivory carries text, orange marks focus, selection and the
// main action. UI code uses the roles below. In-between shades are these colours at partial
// opacity, never new colours: hover = Text 14%, divider = Text 12%, control outline = Text 40%,
// selection = Accent 25%. SelfTest rejects anything else. Two exceptions: CalibrationPreview's
// grey ramp must stay neutral to calibrate brightness, and 3D shadows are black at partial
// opacity (soft black is the window colour, so it cannot darken anything).
public static class Palette {
    // The colours themselves. Physical things (the PS2 cases, lamp light) use these directly.
    public static readonly Color SoftBlack = Rgb(0x141210), SoftBlackRaised = Rgb(0x24211E),
        WarmIvory = Rgb(0xF3ECDF), WarmIvoryMuted = Rgb(0xB3A898),
        BurntOrange = Rgb(0xDB6A22), BurntOrangeDeep = Rgb(0x9A4008);
    public static readonly IReadOnlyList<Color> All = new[] {
        SoftBlack, SoftBlackRaised, WarmIvory, WarmIvoryMuted, BurntOrange, BurntOrangeDeep };

    // Roles.
    public static Color Background => SoftBlack;        // window, sidebar, fields
    public static Color Surface => SoftBlackRaised;     // buttons, dropdowns, cards
    public static Color Text => WarmIvory;
    public static Color TextMuted => WarmIvoryMuted;    // hints, labels
    public static Color Accent => BurntOrange;          // focus, selection, toggles
    public static Color AccentDeep => BurntOrangeDeep;  // filled buttons under ivory text
    public static Color Danger => BurntOrange;          // error text

    public const byte Hover = 36, Divider = 31, Outline = 102, Selection = 64;
    public static Color ControlLine => WithAlpha(Text, Outline);

    // Partial opacity multiplies, so a translucent role stays translucent when faded further.
    public static Color WithAlpha(Color color, byte alpha) =>
        Color.FromArgb((byte)(color.A * alpha / 255), color.R, color.G, color.B);
    // A light of this colour at the given intensity (3D lighting only).
    public static Color Scale(Color color, double intensity) {
        intensity = Math.Clamp(intensity, 0, 1);
        return Color.FromRgb((byte)(color.R * intensity), (byte)(color.G * intensity), (byte)(color.B * intensity));
    }
    public static SolidColorBrush Brush(Color color, byte alpha = 255) {
        var brush = new SolidColorBrush(WithAlpha(color, alpha));
        brush.Freeze();
        return brush;
    }
    public static bool Contains(Color color) => All.Any(c => c.R == color.R && c.G == color.G && c.B == color.B);
    public static Color Over(Color foreground, Color background) {
        double a = foreground.A / 255.0;
        byte Mix(byte f, byte b) => (byte)Math.Round(b + (f - b) * a);
        return Color.FromRgb(Mix(foreground.R, background.R), Mix(foreground.G, background.G), Mix(foreground.B, background.B));
    }
    // WCAG contrast of a (possibly translucent) foreground composited over an opaque background.
    public static double Contrast(Color foreground, Color background) {
        static double Channel(double c) { c /= 255; return c <= 0.03928 ? c / 12.92 : Math.Pow((c + 0.055) / 1.055, 2.4); }
        static double Luminance(Color c) => 0.2126 * Channel(c.R) + 0.7152 * Channel(c.G) + 0.0722 * Channel(c.B);
        double front = Luminance(Over(foreground, background)), back = Luminance(background);
        return (Math.Max(front, back) + 0.05) / (Math.Min(front, back) + 0.05);
    }
    static Color Rgb(int value) => Color.FromRgb((byte)(value >> 16), (byte)(value >> 8), (byte)value);
}

// XAML access: {local:Palette Accent} or {local:Palette Text, Alpha=36}. Produces a Color for
// Color properties and a frozen brush everywhere else.
[MarkupExtensionReturnType(typeof(object))]
public sealed class PaletteExtension : MarkupExtension {
    public PaletteExtension() { }
    public PaletteExtension(string name) => Name = name;
    [ConstructorArgument("name")] public string Name { get; set; } = "";
    public byte Alpha { get; set; } = 255;
    public override object ProvideValue(IServiceProvider services) {
        object? value = typeof(Palette).GetProperty(Name)?.GetValue(null) ?? typeof(Palette).GetField(Name)?.GetValue(null);
        if (value is not Color baseColor)
            throw new ArgumentException("Unknown palette colour: " + Name);
        var color = Palette.WithAlpha(baseColor, Alpha);
        var target = services.GetService(typeof(IProvideValueTarget)) as IProvideValueTarget;
        bool wantsColor = target?.TargetProperty switch {
            System.Windows.DependencyProperty p => p.PropertyType == typeof(Color),
            System.Reflection.PropertyInfo p => p.PropertyType == typeof(Color),
            _ => false
        };
        return wantsColor ? color : Palette.Brush(color);
    }
}
