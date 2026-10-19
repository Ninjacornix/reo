namespace Outbreak.Launcher;

public record OutputSize(int Width, int Height) {
    public string Name => $"{Width} x {Height}";
    public override string ToString() => Name;
}

public static class DisplayOptions {
    // Preserve the first three indices used by existing settings files.
    public static readonly OutputSize[] Sizes = { new(1024, 768), new(1280, 960),  new(1600, 1200),
                                                  new(1280, 720), new(1920, 1080), new(2560, 1440),
                                                  new(3840, 2160) };
    public static readonly string[] Fits = { "fit", "center", "stretch", "fill" };
    public static string FitName(string fit) => fit switch { "center" => "Centered",
                                                             "stretch" => "Stretched",
                                                             "fill" => "Fill",
                                                             _ => "Fit" };
    public static OutputSize Size(int index) => Sizes[Math.Clamp(index, 0, Sizes.Length - 1)];
}
