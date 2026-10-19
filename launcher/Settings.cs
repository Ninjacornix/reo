using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed partial class Settings
{
    public static string Home => Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "OutbreakRecomp", "launcher");
    public string Exe { get; set; } = "";
    public string Iso { get; set; } = "";
    public int WindowSize { get; set; }
    public bool Fullscreen { get; set; }
    public bool LinearFilter { get; set; } = true;
    public bool AsyncVif { get; set; } = true;
    public bool GpuMovies { get; set; }
    public bool DualSense { get; set; } = true;
    public int DeadZone { get; set; } = 12;
    public string InputDeviceId { get; set; } = "";
    public PadProfile PlayStation { get; set; } = new();
    public PadProfile Xbox { get; set; } = new();
    public Dictionary<string, int> Keyboard { get; set; } = InputMapping.KeyboardDefaults();
    public static Settings Load(string root)
    {
        Settings settings;
        try { settings = JsonSerializer.Deserialize<Settings>(File.ReadAllText(Path.Combine(Home, "settings.json"))) ?? new(); }
        catch (Exception error) when (error is IOException or JsonException) { settings = new(); }
        if (settings.Exe.Length == 0) settings.Exe = Path.Combine(root, "build-ninja", "recomp", "reo_recomp.exe");
        if (settings.Iso.Length == 0) settings.Iso = Path.Combine(root, "iso", "Resident Evil - Outbreak (v2.00).iso");
        settings.WindowSize = Math.Clamp(settings.WindowSize, 0, 2);
        settings.DeadZone = Math.Clamp(settings.DeadZone, 0, 30);
        if (!settings.DualSense && settings.InputDeviceId.Length == 0) settings.InputDeviceId = "keyboard";
        settings.PlayStation ??= new(); settings.Xbox ??= new(); settings.Keyboard ??= InputMapping.KeyboardDefaults();
        settings.PlayStation.DeadZone = Math.Clamp(settings.PlayStation.DeadZone, 0, 30);
        settings.Xbox.DeadZone = Math.Clamp(settings.Xbox.DeadZone, 0, 30);
        settings.PlayStation.Buttons ??= InputMapping.PadDefaults(); settings.Xbox.Buttons ??= InputMapping.PadDefaults();
        return settings;
    }
    public void Save()
    {
        Directory.CreateDirectory(Home);
        string target = Path.Combine(Home, "settings.json");
        File.WriteAllText(target + ".tmp", JsonSerializer.Serialize(this, new JsonSerializerOptions { WriteIndented = true }));
        File.Move(target + ".tmp", target, true);
    }
}
