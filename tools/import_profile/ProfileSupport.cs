namespace Outbreak.Launcher;

// This diagnostic links production import/build code but redirects storage into a fresh sandbox.
public sealed partial class Settings {
    public static string Home { get; internal set; } = "";
    public string Exe { get; set; } = "";
    public string Iso { get; set; } = "";
}
internal static class Updates {
    public const string DefaultVersion = "1.0.10-profile";
}
internal static class CompilerSetup {
    public static Task Ensure(CancellationToken cancel) => throw new NotSupportedException(
        "This profiler uses the pinned portable kit, never MSVC provisioning.");
}
public static partial class LocalGameBuild {
    internal static void ProfileExpand(string root, IProgress<ImportProgress> progress,
                                       CancellationToken cancel) => ExpandPayload(root, progress,
                                                                                  cancel);
    internal static object ProfileKit(string root, CancellationToken cancel) {
        var kit = ReadKit(KitFolder(root), DiscImport.FirstElfSha256, cancel);
        foreach (var file in kit.Files) {
            cancel.ThrowIfCancellationRequested();
            if (Sha(Inside(KitFolder(root), file.Path)) != file.Sha256)
                throw new IOException("Invalid kit file: " + file.Path);
        }
        return new { files = kit.Files.Length, folder = KitFolder(root) };
    }
}
