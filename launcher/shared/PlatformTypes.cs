using System.Runtime.CompilerServices;

[assembly: InternalsVisibleTo("Outbreak.Launcher")]
[assembly: InternalsVisibleTo("Reo.Launcher.CrossTests")]

namespace Outbreak.Launcher;

public readonly record struct Rgba(byte A, byte R, byte G, byte B) {
    public static Rgba FromArgb(byte a, byte r, byte g, byte b) => new(a,r,g,b);
    public static Rgba FromRgb(byte r, byte g, byte b) => new(255,r,g,b);
}
