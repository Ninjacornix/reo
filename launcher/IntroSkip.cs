namespace Outbreak.Launcher;

// "Start at the main menu": the boot logos run fast while the screen is black and audio
// muted, and the title prompt is confirmed automatically (REO_SKIP_INTRO in the game,
// runtime/gs/performance.h and recomp/overrides/reo_hw_bridge.cpp). REO_TURBO returns to
// normal speed once the original front-menu pointer exists (File #1 0x5D4898, File #2
// 0x5B7D00, network/native/game_addresses.h).
public static class IntroSkip {
    public static IReadOnlyDictionary<string, string> Environment(string gameId, bool enabled) {
        if (!enabled) return new Dictionary<string, string>();
        string frontMenu = gameId == "file2" ? "0x5B7D00" : "0x5D4898";
        return new Dictionary<string, string> {
            ["REO_SKIP_INTRO"] = "1",
            ["REO_TURBO"] = "16",
            ["REO_TURBO_UNTIL"] = frontMenu
        };
    }
}
