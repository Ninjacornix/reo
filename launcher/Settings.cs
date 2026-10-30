using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed partial class Settings {
    public static string Home => Storage.Home;
    public string Exe { get; set; } = "";
    public string Iso { get; set; } = "";
    public int WindowSize { get; set; }
    public double LauncherWidth { get; set; } = 1320;
    public double LauncherHeight { get; set; } = 920;
    public bool LauncherMaximized { get; set; }
    public bool LauncherBackgroundMovies { get; set; } = true;
    public string LauncherFont { get; set; } = "outbreak";
    public string LauncherLanguage { get; set; } = "en";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedLauncherFont => LauncherFont is "segoe-ui" or "tahoma" ? LauncherFont : "outbreak";
    public bool Fullscreen { get; set; }
    public bool PerformanceOverlay { get; set; }
    public string AspectRatio { get; set; } = "4:3";
    // Widen the game camera to the selected ratio instead of stretching the 4:3 view.
    public bool WidescreenCamera { get; set; }
    public string ScreenFit { get; set; } = "fit";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedAspect => Array.IndexOf(DisplayOptions.Aspects, AspectRatio) >= 0 ? AspectRatio : "4:3";
    [System.Text.Json.Serialization.JsonIgnore]
    public bool ResolvedWidescreen => WidescreenCamera && ResolvedAspect != "4:3";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedFit => ScreenFit is "stretch" or "center" or "fill" ? ScreenFit : "fit";
    public bool LinearFilter { get; set; } = true;
    public bool AsyncVif { get; set; } = true;
    // Used only when the movie decoder check finds a compatible GPU.
    public bool GpuMovies { get; set; } = true;
    public bool HostServer { get; set; }
    public string HostAddress { get; set; } = "";
    public bool AutoForward { get; set; }
    public string CoopHost { get; set; } = "";
    public string AccountUsername { get; set; } = "";
    // "offline", "host" or "join"; null in settings saved by older launchers.
    public string? CoopMode { get; set; }
    public bool AutoLobby { get; set; } = true;
    DeveloperOptions developer = new();
    public DeveloperOptions Developer { get => developer; set => developer = value ?? new(); }
    public string JoinHostName { get; set; } = "";
    // Hosting ports the host may change; JoinSignupPort is learned from the host (0 = default).
    public int SignupPort { get; set; } = HostNetworking.SignupPort;
    public int GamePort { get; set; } = HostNetworking.GamePort;
    public int JoinSignupPort { get; set; }
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedCoopMode => CoopMode is "offline" or "host" or "join" ? CoopMode
                                      : HostServer                             ? "host"
                                      : !string.IsNullOrWhiteSpace(CoopHost)   ? "join"
                                                                               : "offline";
    public bool TextureLinear { get; set; }
    public int InternalResolution { get; set; } = 1;
    [System.Text.Json.Serialization.JsonIgnore]
    public int ResolvedInternalResolution => InternalResolution is 2 or 4 ? InternalResolution : 1;
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
    public bool RumbleEnabled { get; set; } = true;
    public int MasterVolume { get; set; } = 100;
    public bool ShowSubtitles { get; set; } = true;
    public string AudioOutputId { get; set; } = "";
    public string AudioOutputName { get; set; } = "";
    public int MusicVolume { get; set; } = 100;
    public int SfxVolume { get; set; } = 100;
    public int VoiceVolume { get; set; } = 100;
    public int UiVolume { get; set; } = 100;
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
        settings.MasterVolume = Math.Clamp(settings.MasterVolume, 0, 100);
        settings.MusicVolume = Math.Clamp(settings.MusicVolume, 0, 100);
        settings.SfxVolume = Math.Clamp(settings.SfxVolume, 0, 100);
        settings.VoiceVolume = Math.Clamp(settings.VoiceVolume, 0, 100);
        settings.UiVolume = Math.Clamp(settings.UiVolume, 0, 100);
        settings.Gamma =
            double.IsFinite(settings.Gamma) ? Math.Clamp(settings.Gamma, 0.5, 2.0) : 1.0;
        settings.DeadZone = Math.Clamp(settings.DeadZone, 0, 30);
        if (!settings.DualSense && settings.InputDeviceId.Length == 0)
            settings.InputDeviceId = "keyboard";
        settings.EnabledCheats ??= new();
        settings.EnabledMods ??= new();
        settings.CoopHost ??= "";
        settings.AccountUsername ??= "";
        settings.RoomName ??= "";
        settings.JoinRoomName ??= "";
        settings.RoomMaxPlayers = Math.Clamp(settings.RoomMaxPlayers, 2, 4);
        if (!new[] { 3, 5, 10, 15, 30 }.Contains(settings.RoomWaitMinutes)) settings.RoomWaitMinutes = 5;
        settings.JoinHostName ??= "";
        if (HostNetworking.PortError(settings.SignupPort, settings.GamePort) != null) {
            settings.SignupPort = HostNetworking.SignupPort;
            settings.GamePort = HostNetworking.GamePort;
        }
        if (settings.JoinSignupPort is < 0 or > 65535)
            settings.JoinSignupPort = 0;
        settings.HostAddress ??= "";
        settings.PlayStation ??= new();
        settings.Xbox ??= new();
        settings.Keyboard ??= InputMapping.KeyboardDefaults();
        settings.PlayStation.DeadZone = Math.Clamp(settings.PlayStation.DeadZone, 0, 30);
        settings.Xbox.DeadZone = Math.Clamp(settings.Xbox.DeadZone, 0, 30);
        settings.PlayStation.Buttons ??= InputMapping.PadDefaults();
        settings.Xbox.Buttons ??= InputMapping.PadDefaults();
        settings.UpgradeMemoryCards(root);
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
