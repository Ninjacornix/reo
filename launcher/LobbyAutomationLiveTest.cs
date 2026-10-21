using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

// Developer check: runs the launcher's lobby automation against a running two-to-four player
// session of tools/coop_playtest (after its drive-login). Input goes through the harness's
// per-player input.json and keyboard queue instead of the launcher controller. Player 1 hosts.
internal static class LobbyAutomationLiveTest {
    public static async Task Run(string sessionFolder, string hostName, string receipt) {
        using var session = JsonDocument.Parse(File.ReadAllText(Path.Combine(sessionFolder, "session.json")));
        using var run = JsonDocument.Parse(File.ReadAllText(Path.Combine(sessionFolder, "run.json")));
        string elf = session.RootElement.GetProperty("elf").GetString()!;
        var pids = run.RootElement.GetProperty("players").EnumerateArray()
                       .ToDictionary(p => p.GetProperty("number").GetInt32(), p => p.GetProperty("pid").GetInt32());
        bool hostReady = false;
        using var responder = new LanDiscovery.Responder(
            () => new(hostName, "127.0.0.1", Updates.DefaultVersion, hostReady));
        var clock = Stopwatch.StartNew();
        var results = new List<object>();
        var tasks = new List<Task>();
        foreach (var player in session.RootElement.GetProperty("players").EnumerateArray()) {
            int number = player.GetProperty("number").GetInt32();
            string input = player.GetProperty("inputFile").GetString()!;
            var process = Process.GetProcessById(pids[number]);
            var messages = new List<string>();
            void Press(ushort buttons, int milliseconds) {
                string name = LobbyAutomation.Buttons.Single(b => b.Value == buttons).Key;
                string temporary = input + ".tmp-" + Guid.NewGuid().ToString("N");
                File.WriteAllText(temporary, JsonSerializer.Serialize(new {
                    buttons = new[] { name },
                    expiresUnix = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds() / 1000.0 + milliseconds / 1000.0
                }));
                File.Move(temporary, input, true);
            }
            var automation = new LobbyAutomation(
                process, elf, Press, () => false, player.GetProperty("keyboardFile").GetString()!,
                new(number == 1, hostName, "127.0.0.1", number == 1 ? ready => hostReady = ready : null),
                text => {
                    lock (messages)
                        messages.Add($"{clock.Elapsed.TotalSeconds:0.0}s {text}");
                });
            tasks.Add(automation.Run().ContinueWith(_ => {
                lock (results)
                    results.Add(new { number, finishedSeconds = clock.Elapsed.TotalSeconds, messages });
            }));
        }
        await Task.WhenAll(tasks);
        await File.WriteAllTextAsync(receipt, JsonSerializer.Serialize(
            new { hostName, players = results, hostRoomReady = hostReady,
                  note = "UI waiting-room state observed by the launcher automation; not gameplay proof" },
            new JsonSerializerOptions { WriteIndented = true }));
    }
}
