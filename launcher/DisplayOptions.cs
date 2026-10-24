namespace Outbreak.Launcher;

public record OutputSize(int Width, int Height) {
    public string Name => (Width, Height) switch {
        (512, 448) => "Native (512 × 448)",
        (1280, 720) => "HD (1280 × 720)",
        (1920, 1080) => "FHD (1920 × 1080)",
        (2560, 1440) => "QHD / 2K (2560 × 1440)",
        (3840, 2160) => "4K (3840 × 2160)",
        _ => $"{Width} × {Height}"
    };
    public override string ToString() => Name;
}

public static class DisplayOptions {
    // Preserve every index used by existing settings files. Menu ordering is
    // separate so adding Native does not change an existing output preference.
    public static readonly OutputSize[] Sizes = { new(1024, 768), new(1280, 960),  new(1600, 1200),
                                                  new(1280, 720), new(1920, 1080), new(2560, 1440),
                                                  new(3840, 2160), new(512, 448) };
    public static readonly OutputSize[] MenuSizes = {
        Sizes[7], Sizes[3], Sizes[4], Sizes[5], Sizes[6], Sizes[0], Sizes[1], Sizes[2]
    };
    public static readonly int[] InternalScales = { 1, 2, 4 };
    public static readonly string[] Fits = { "fit", "center", "stretch", "fill" };
    public static string FitName(string fit) => fit switch { "center" => "Centered",
                                                             "stretch" => "Stretched",
                                                             "fill" => "Fill",
                                                             _ => "Fit" };
    public static OutputSize Size(int index) => Sizes[Math.Clamp(index, 0, Sizes.Length - 1)];
}
