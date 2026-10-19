using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed partial class Settings {
    public static string Home =>
        Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
                     "OutbreakRecomp", "launcher");
    public string Exe { get; set; } = "";
    public string Iso { get; set; } = "";
    public int WindowSize { get; set; }
    public bool Fullscreen { get; set; }
    public string AspectRatio { get; set; } = "4:3";
    public string ScreenFit { get; set; } = "fit";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedAspect => AspectRatio == "16:9" ? "16:9" : "4:3";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedFit => ScreenFit is "stretch" or "center" or "fill" ? ScreenFit : "fit";
    public bool LinearFilter { get; set; } = true;
    public bool AsyncVif { get; set; } = true;
    public bool HostServer { get; set; }
    public string HostAddress { get; set; } = "";
    public bool AutoForward { get; set; }
    public string CoopHost { get; set; } = "";
    public string AccountUsername { get; set; } = "";
    public bool TextureLinear { get; set; }
    public int Anisotropy { get; set; } = 1;
    public int ResolvedAnisotropy => Anisotropy is 2 or 4 or 8 or 16 ? Anisotropy : 1;
    public bool AntiAliasing { get; set; } = true;
    public string? AntiAliasingMode { get; set; }
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedAntiAliasing => !AntiAliasing || AntiAliasingMode == "off" ? "off"
                                          : AntiAliasingMode == "smaa"               ? "smaa"
                                                                                     : "fxaa";
    public int Brightness { get; set; } = 100;
    public double Gamma { get; set; } = 1.0;
    public bool DualSense { get; set; } = true;
    public int DeadZone { get; set; } = 12;
    public string InputDeviceId { get; set; } = "";
    public PadProfile PlayStation { get; set; } = new();
    public PadProfile Xbox { get; set; } = new();
    public Dictionary<string, int> Keyboard { get; set; } = InputMapping.KeyboardDefaults();
    public static Settings Load(string root) {
        Settings settings;
        try {
            settings = JsonSerializer.Deserialize<Settings>(
                           File.ReadAllText(Path.Combine(Home, "settings.json"))) ??
                       new();
        } catch (Exception error) when (error is IOException or JsonException) {
            settings = new();
        }
        if (AppLayout.Packaged(root) || settings.Exe.Length == 0)
            settings.Exe = AppLayout.Native(root, "file1");
        if (AppLayout.Packaged(root) || settings.SecondExe.Length == 0)
            settings.SecondExe = AppLayout.Native(root, "file2");
        if (settings.Iso.Length == 0 && !AppLayout.Packaged(root))
            settings.Iso = Path.Combine(root, "iso", "Resident Evil - Outbreak (v2.00).iso");
        settings.WindowSize = Math.Clamp(settings.WindowSize, 0, DisplayOptions.Sizes.Length - 1);
        settings.Brightness = Math.Clamp(settings.Brightness, 50, 150);
        settings.Gamma =
            double.IsFinite(settings.Gamma) ? Math.Clamp(settings.Gamma, 0.5, 2.0) : 1.0;
        settings.DeadZone = Math.Clamp(settings.DeadZone, 0, 30);
        if (!settings.DualSense && settings.InputDeviceId.Length == 0)
            settings.InputDeviceId = "keyboard";
        settings.EnabledCheats ??= new();
        settings.CoopHost ??= "";
        settings.AccountUsername ??= "";
        settings.PlayStation ??= new();
        settings.Xbox ??= new();
        settings.Keyboard ??= InputMapping.KeyboardDefaults();
        settings.PlayStation.DeadZone = Math.Clamp(settings.PlayStation.DeadZone, 0, 30);
        settings.Xbox.DeadZone = Math.Clamp(settings.Xbox.DeadZone, 0, 30);
        settings.PlayStation.Buttons ??= InputMapping.PadDefaults();
        settings.Xbox.Buttons ??= InputMapping.PadDefaults();
        return settings;
    }
    public void Save() {
        Directory.CreateDirectory(Home);
        string target = Path.Combine(Home, "settings.json");
        File.WriteAllText(
            target + ".tmp",
            JsonSerializer.Serialize(this, new JsonSerializerOptions { WriteIndented = true }));
        File.Move(target + ".tmp", target, true);
    }
}
