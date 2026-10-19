using System.Text.Json;
using System.IO;
using System.Text;

namespace Outbreak.Launcher;

static class OnlineOptionsTests {
    public static void Run(Action<bool, string> check) {
        foreach (string username in new[] { "reo1", "reo01", "Reo_01", "1234", "abcdefghij" })
            check(OnlineOptions.ValidUsername(username),
                  "Compatible openSNAP username: " + username);
        foreach (string username in new[] { "", "abc", "abcdefghijk", "_reo1", "reo1_", "re__o",
                                            "re o1", "réo1", "reo1\n" })
            check(!OnlineOptions.ValidUsername(username),
                  "Unsupported username rejected: " + username);
        check(!OnlineOptions.ValidUsername(null), "Missing username rejected");
        check(OnlineOptions.TryHost("127.0.0.1", out var loopback) && loopback == "127.0.0.1",
              "Numeric loopback supported");
        check(OnlineOptions.TryHost(" 192.168.001.002 ", out var normalized) &&
                  normalized == "192.168.1.2",
              "IPv4 endpoint normalized before native launch");
        foreach (string host in new[] { "", "localhost", "127.1", "0x7f000001", "::1",
                                        "127.0.0.1:9090", "256.0.0.1", "1.2.-3.4", "0.0.0.0",
                                        "255.255.255.255", "224.0.0.1" })
            check(!OnlineOptions.TryHost(host, out _), "Invalid server endpoint rejected: " + host);
        var offline = new Settings { CoopHost = "bad", AccountUsername = "bad" };
        check(
            OnlineOptions.Error(offline) != null &&
                OnlineOptions.LaunchEnvironment(offline).Count == 0,
            "Offline launch ignores unfinished online settings and exports no network environment");
        var online = new Settings { CoopHost = "127.000.000.001", AccountUsername = "reo01" };
        var env = OnlineOptions.LaunchEnvironment(online);
        check(env.Count == 4 && env["REO_COOP_HOST"] == "127.0.0.1" &&
                  env["REO_COOP_PLATFORM_AUTH"] == "native" && env["REO_COOP_USERNAME"] == "reo01",
              "Online launch selects genuine native platform authentication and configured " +
                  "account/server");
        check(!env.Keys.Any(k => k.Contains("PASSWORD", StringComparison.OrdinalIgnoreCase)) &&
                  !env.ContainsKey("REO_TEST_ROUTE"),
              "Online options export neither a password nor diagnostic automation");
        var persisted = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(online))!;
        check(persisted.CoopHost == online.CoopHost && persisted.AccountUsername == "reo01",
              "Online configuration persists with settings");
        online.CoopHost = "not-a-server";
        check(OnlineOptions.LaunchEnvironment(online).Count == 0,
              "Incomplete network settings leave normal Play available offline");
        online.SelectedGame = "file2";
        check(OnlineOptions.Error(online)?.Contains("File #1", StringComparison.Ordinal) == true,
              "File #2 remains unsupported online");
        CheckMemoryCardPreparation(check);
    }

    static void CheckMemoryCardPreparation(Action<bool, string> check) {
        string fixture =
            Path.Combine(Path.GetTempPath(), "reo-online-card-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(fixture);
        try {
            var online = new Settings { CoopHost = "127.0.0.1", AccountUsername = "reo01" };
            string absent = Path.Combine(fixture, "offline-absent");
            check(OnlineOptions.PrepareMemoryCard(new Settings(), absent, null) == "offline" &&
                      !Directory.Exists(absent),
                  "Offline preparation does not create a missing card or lease");
            string card = Path.Combine(fixture, "fresh");
            using (var lease = MemoryCards.Acquire(card)) {
                File.WriteAllText(Path.Combine(card, "existing-save"), "preserve save");
                bool locked = false;
                try {
                    using var competing = MemoryCards.Acquire(card);
                } catch (IOException) {
                    locked = true;
                }
                check(locked,
                      "Online profile preparation retains the selected card's exclusive lease");
                check(OnlineOptions.PrepareMemoryCard(online, card, lease) ==
                          "created-host-profile-marker",
                      "Online card gets a new native provider marker");
                var marker = Path.Combine(card, "BWNETCNF", "BWNETDCNF");
                check(File.ReadAllBytes(marker).SequenceEqual(
                          Encoding.UTF8.GetBytes(OnlineOptions.HostProfileMarker)),
                      "Native profile marker contains only exact original project text");
                check(File.ReadAllText(Path.Combine(card, "existing-save")) == "preserve save",
                      "Online preparation leaves existing saves unchanged");
                File.WriteAllText(marker, "user configuration");
                check(OnlineOptions.PrepareMemoryCard(online, card, lease) ==
                              "existing-profile-directory" &&
                          File.ReadAllText(marker) == "user configuration",
                      "Existing network configuration is never overwritten");
                check(OnlineOptions.PrepareMemoryCard(new Settings(), card, null) == "offline" &&
                          File.ReadAllText(marker) == "user configuration",
                      "Offline preparation leaves an existing profile unchanged");
            }
            string emptyProfile = Path.Combine(fixture, "existing-empty");
            using (var lease = MemoryCards.Acquire(emptyProfile)) {
                Directory.CreateDirectory(Path.Combine(emptyProfile, "BWNETCNF"));
                bool refused = false;
                try {
                    OnlineOptions.PrepareMemoryCard(online, emptyProfile, lease);
                } catch (IOException error) {
                    refused = error.Message.Contains("empty BWNETCNF", StringComparison.Ordinal);
                }
                check(refused && Directory.Exists(Path.Combine(emptyProfile, "BWNETCNF")) &&
                          !Directory
                               .EnumerateFileSystemEntries(Path.Combine(emptyProfile, "BWNETCNF"))
                               .Any(),
                      "An existing empty profile directory is preserved and reported as unusable");
            }
            string collision = Path.Combine(fixture, "file-collision");
            using (var lease = MemoryCards.Acquire(collision)) {
                string existing = Path.Combine(collision, "BWNETCNF");
                File.WriteAllText(existing, "user file");
                bool refused = false;
                try {
                    OnlineOptions.PrepareMemoryCard(online, collision, lease);
                } catch (IOException) {
                    refused = true;
                }
                check(refused && File.ReadAllText(existing) == "user file",
                      "A conflicting user file is preserved and reports an explicit preparation " +
                          "error");
            }
            string unleased = Path.Combine(fixture, "unleased");
            Directory.CreateDirectory(unleased);
            bool noLeaseRefused = false;
            try {
                OnlineOptions.PrepareMemoryCard(online, unleased, null);
            } catch (IOException) {
                noLeaseRefused = true;
            }
            check(noLeaseRefused && !Directory.Exists(Path.Combine(unleased, "BWNETCNF")),
                  "Online profile cannot mutate a card without its lease");
            using (var wrongLease = MemoryCards.Acquire(Path.Combine(fixture, "another-card"))) {
                bool wrongRefused = false;
                try {
                    OnlineOptions.PrepareMemoryCard(online, unleased, wrongLease);
                } catch (IOException) {
                    wrongRefused = true;
                }
                check(wrongRefused && !Directory.Exists(Path.Combine(unleased, "BWNETCNF")),
                      "An unrelated card lease cannot authorize online preparation");
            }
            string createdEmpty = Path.Combine(fixture, "created-empty-profile");
            Directory.CreateDirectory(createdEmpty);
            OnlineOptions.RemoveEmptyCreatedProfileDirectory(createdEmpty);
            check(!Directory.Exists(createdEmpty),
                  "Failed marker creation can remove only its own empty profile directory");
            string populated = Path.Combine(fixture, "created-profile-now-populated");
            Directory.CreateDirectory(populated);
            File.WriteAllText(Path.Combine(populated, "user-file"), "preserve");
            OnlineOptions.RemoveEmptyCreatedProfileDirectory(populated);
            check(File.ReadAllText(Path.Combine(populated, "user-file")) == "preserve",
                  "Failure cleanup never recursively removes new or existing profile contents");
        } finally {
            Directory.Delete(fixture, true);
        }
    }
}
