namespace Outbreak.Launcher;

public sealed partial class Settings {
    public string RoomName { get; set; } = "";
    public int RoomMaxPlayers { get; set; } = 4;
    public int RoomWaitMinutes { get; set; } = 5;
    public string JoinRoomName { get; set; } = "";
    [System.Text.Json.Serialization.JsonIgnore]
    public string ResolvedRoomName => string.IsNullOrWhiteSpace(RoomName) ? AccountUsername : RoomName.Trim();
    [System.Text.Json.Serialization.JsonIgnore]
    public int ResolvedRoomMaxPlayers => Math.Clamp(RoomMaxPlayers, 2, 4);
    [System.Text.Json.Serialization.JsonIgnore]
    public int ResolvedRoomWaitMinutes => LobbySettings.WaitTimes(Game.Id).Contains(RoomWaitMinutes) ? RoomWaitMinutes : 5;
}

internal static class LobbySettings {
    internal const int MaximumTitleLength = 15;
    internal static int[] WaitTimes(string game) => game == "file2" ? new[] { 3, 5, 10, 15, 30 } : new[] { 5, 10, 15, 30 };
    internal static bool ValidTitle(string title) => title.Length is > 0 and <= MaximumTitleLength &&
        title == title.Trim() && title.All(c => char.IsAsciiLetterOrDigit(c) || c == '_');
}
