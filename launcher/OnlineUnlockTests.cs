using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class OnlineUnlockTests {
    internal static async Task Run(Action<bool, string> check) {
        string root = Path.Combine(Path.GetTempPath(), "reo-online-unlocks-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        bool Rejected(Action action) {
            try { action(); return false; }
            catch (IOException error) { return error.Message.Contains("Unlock everything") && error.Message.Contains("Play alone"); }
        }
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                var choices = Cheats.Builtins(game);
                int unlock = choices.FindIndex(g => g.Builtin == "unlock");
                foreach (string mode in new[] { "host", "join" }) {
                    for (int mask = 0; mask < 1 << choices.Count; mask++) {
                        var settings = new Settings { SelectedGame = game, CoopMode = mode, CheatsEnabled = true,
                            EnabledCheats = choices.Where((_, index) => (mask & (1 << index)) != 0).Select(g => g.Id).ToList() };
                        string before = JsonSerializer.Serialize(settings.EnabledCheats);
                        bool allowed = (mask & ~(1 << unlock)) == 0;
                        check(Rejected(() => Cheats.VerifyOnlineSelection(settings)) == !allowed,
                            $"{game} {mode} session selection policy, mask {mask}");
                        if (!allowed) {
                            check(Rejected(() => Cheats.Export(settings, root)), $"{game} {mode} rejects mixed/gameplay cheats, mask {mask}");
                        } else {
                            string manifest = Cheats.Export(settings, root);
                            check(mask == 0 ? manifest == "" : File.ReadAllLines(manifest).SequenceEqual(new[] { "REO-CHEATS-2", "builtin unlock" }),
                                $"{game} {mode} exports exactly the requested progression unlock");
                        }
                        check(JsonSerializer.Serialize(settings.EnabledCheats) == before, "Co-op validation preserves the saved selection");
                    }
                }
                var enabled = new Settings { SelectedGame = game, CoopMode = "host", AccountUsername = "host29", CheatsEnabled = true,
                    EnabledCheats = new() { $"builtin.{game}.unlock" } };
                var hosted = await RandomizerSession.Resolve(enabled, new(), default);
                check(RandomizerSession.Parse(hosted.Bytes, game).Host == "host29" && hosted.Mods.Count == 0,
                    game + " progression unlock does not prevent an unmodded host session");
                using var server = new UdpClient(new IPEndPoint(IPAddress.Loopback, 0));
                using var deadline = new CancellationTokenSource(TimeSpan.FromSeconds(5));
                var serve = Task.Run(async () => {
                    var query = await server.ReceiveAsync(deadline.Token);
                    await server.SendAsync(RandomizerSession.Reply(query.Buffer, hosted.Bytes)!, query.RemoteEndPoint, deadline.Token);
                });
                enabled.CoopMode = "join"; enabled.CoopHost = "127.0.0.1";
                var joined = await RandomizerSession.Resolve(enabled, new(), deadline.Token, ((IPEndPoint)server.Client.LocalEndPoint!).Port);
                await serve;
                check(joined.Bytes.SequenceEqual(hosted.Bytes) && joined.Mods.Count == 0,
                    game + " unlock-only guest resolves the host over real UDP without adding shared effects");
                enabled.EnabledCheats.Add($"builtin.{game}.health");
                bool blocked = false;
                try { await RandomizerSession.Resolve(enabled, new(), deadline.Token, ((IPEndPoint)server.Client.LocalEndPoint!).Port); }
                catch (IOException error) { blocked = error.Message.Contains("Play alone"); }
                check(blocked, game + " guest gameplay cheats are rejected before asking the host");
                enabled.CoopMode = "host";
                blocked = false;
                try { await RandomizerSession.Resolve(enabled, new(), default); }
                catch (IOException error) { blocked = error.Message.Contains("Play alone"); }
                check(blocked, game + " host gameplay cheats remain unavailable");
                enabled.CheatsEnabled = false;
                check(Cheats.Export(enabled, root) == "", game + " disabled master switch exports nothing online");
                Cheats.VerifyOnlineSelection(enabled);
                check(true, game + " disabled master switch ignores stored gameplay selections");
                enabled.CheatsEnabled = true;
                enabled.EnabledCheats = new() { $"builtin.{(game == "file1" ? "file2" : "file1")}.health" };
                Cheats.VerifyOnlineSelection(enabled);
                check(Cheats.Export(enabled, root) == "", game + " other-edition selections do not block or leak into co-op");
                string folder = Cheats.Folder(game); Directory.CreateDirectory(folder);
                string file = Path.Combine(folder, "online-unlock-test-" + Guid.NewGuid().ToString("N") + ".pnach");
                try {
                    File.WriteAllText(file, "[Unlock everything]\npatch=1,EE,004A5C40,word,00000001\n");
                    string id = Cheats.Parse(File.ReadAllText(file), game == "file2" ? "file2/" + Path.GetFileName(file) : Path.GetFileName(file)).Single().Id;
                    enabled.EnabledCheats = new() { $"builtin.{game}.unlock", id };
                    check(Rejected(() => Cheats.VerifyOnlineSelection(enabled)) && Rejected(() => Cheats.Export(enabled, root)),
                        game + " an imported data patch named Unlock everything cannot bypass the online rule");
                    enabled.EnabledCheats = new() { $"builtin.{game}.unlock" };
                    var effect = new ModManifest { Effects = new() { "health" } };
                    check(Rejected(() => Cheats.Export(enabled, root, new() { effect })), game + " mixed mod effects cannot piggyback on online unlocks");
                    var patch = new ModManifest { Patches = new() { new ModPatch { Address = "004A5C40", Size = 4, Value = "00000001" } } };
                    check(Rejected(() => Cheats.Export(enabled, root, new() { patch })), game + " mod data writes cannot piggyback on online unlocks");
                } finally { File.Delete(file); }
            }
        } finally { Directory.Delete(root, true); }
    }
}
