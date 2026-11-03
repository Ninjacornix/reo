using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
// Developer page recordings. Each maps to an existing opt-in native diagnostic; all write into
// the session folder and stay off unless the player enables them.
public sealed class DeveloperOptions {
    public bool NetworkTrace { get; set; }
    public bool TransportLog { get; set; }
    public bool SnapTrace { get; set; }
    public bool FrameTiming { get; set; }
    public bool GameClock { get; set; }
    public bool CriServerTiming { get; set; }

    [System.Text.Json.Serialization.JsonIgnore]
    public bool Any => NetworkTrace || TransportLog || SnapTrace || FrameTiming || GameClock || CriServerTiming;

    // Network recordings apply only to online launches; the game clock observer is File #1 only.
    internal Dictionary<string, string> Environment(string logs, bool online, string game) {
        var values = new Dictionary<string, string>();
        if (online && NetworkTrace) values["REO_COOP_TRACE_FILE"] = Path.Combine(logs, Launcher.NetworkTrace.RawName);
        if (online && TransportLog) values["REO_NET_TRACE"] = "1";
        if (online && SnapTrace) values["REO_SNAP_TRACE"] = "1";
        if (FrameTiming) values["REO_FRAME_PACING_FILE"] = Path.Combine(logs, "frames.csv");
        if (GameClock && game == "file1") {
            values["REO_GAME_CLOCK_LOG"] = "1";
            values["REO_GAME_CLOCK_FROM_SECS"] = "0";
            values["REO_GAME_CLOCK_SECONDS"] = "600";
            values["REO_GAME_CLOCK_FILE"] = Path.Combine(logs, "clock.csv");
        }
        // Reports CRI middleware server dispatches and disc reads holding the CPU >= 20 ms
        // to the session's stderr.log.
        if (CriServerTiming && game == "file1") values["REO_CRI_SERVER_SLOW_MS"] = "20";
        return values;
    }
}

internal static class DeveloperOptionsTests {
    internal static void Run(Action<bool, string> check) {
        var legacy = JsonSerializer.Deserialize<Settings>("{}")!;
        check(legacy.Developer != null && !legacy.Developer.Any,
              "Older settings start with every developer recording off");
        var all = new DeveloperOptions { NetworkTrace = true, TransportLog = true, SnapTrace = true,
                                         FrameTiming = true, GameClock = true, CriServerTiming = true };
        var restored = JsonSerializer.Deserialize<Settings>(
            JsonSerializer.Serialize(new Settings { Developer = all }))!.Developer;
        check(restored.NetworkTrace && restored.TransportLog && restored.SnapTrace &&
              restored.FrameTiming && restored.GameClock && restored.CriServerTiming,
              "Developer recordings persist");
        string logs = Path.Combine("x", "session");
        var online = all.Environment(logs, true, "file1");
        check(online["REO_COOP_TRACE_FILE"] == Path.Combine(logs, NetworkTrace.RawName) &&
              online["REO_NET_TRACE"] == "1" && online["REO_SNAP_TRACE"] == "1" &&
              online["REO_FRAME_PACING_FILE"] == Path.Combine(logs, "frames.csv") &&
              online["REO_GAME_CLOCK_FILE"] == Path.Combine(logs, "clock.csv") &&
              online["REO_GAME_CLOCK_SECONDS"] == "600" && online["REO_CRI_SERVER_SLOW_MS"] == "20",
              "Developer recordings map to the native diagnostic switches inside the session folder");
        var offline = all.Environment(logs, false, "file2");
        check(offline.Keys.SequenceEqual(new[] { "REO_FRAME_PACING_FILE" }),
              "Offline launches skip network recordings and File #2 skips the File #1 clock and CRI observers");
        check(new DeveloperOptions().Environment(logs, true, "file1").Count == 0,
              "No developer switch is set unless enabled");
    }
}
