namespace Outbreak.Launcher;

// "Start at the main menu" (REO_SKIP_INTRO in the game): the boot logo screens are skipped
// in the boot scene handler (reo_bootstrap.cpp) and the CAPCOM opening and title prompt are
// answered with Start (reo_hw_bridge.cpp). Nothing is sped up or hidden. Online sessions with the automatic sign-in
// also get REO_COOP_FAST_NETWORK (GameSession.cs): Network Game opens the server list
// directly, the connection and sign-in screens run behind a "connecting" screen.
public static class IntroSkip {
    public static IReadOnlyDictionary<string, string> Environment(string gameId, bool enabled) {
        if (!enabled) return new Dictionary<string, string>();
        return new Dictionary<string, string> { ["REO_SKIP_INTRO"] = "1" };
    }
}
