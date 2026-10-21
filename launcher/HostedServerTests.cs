using System.Diagnostics;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Net.Sockets;
using System.Text.Json;

namespace Outbreak.Launcher;
internal static class HostedServerTests {
    public static async Task Run(string root, string component, string receipt) {
        string home =
            Path.Combine(Path.GetTempPath(), "reo-host-check-" + Guid.NewGuid().ToString("N"));
        int checks = 0;
        void Check(bool ok, string why) {
            if (!ok)
                throw new IOException(why);
            checks++;
        }
        using var server = new HostedServer();
        using var limit = new CancellationTokenSource(TimeSpan.FromMinutes(3));
        try {
            // Alternate ports and a temporary database leave existing user services untouched.
            using (var occupied = new TcpListener(IPAddress.Loopback, 42128)) {
                occupied.Start();
                bool refused = false;
                try {
                    HostedServer.CheckPorts(32000);
                } catch (IOException) {
                    refused = true;
                }
                Check(refused, "An existing service was not rejected");
            }
            await server.Start(root, "127.0.0.1", limit.Token, home, 32000, component);
            Check(server.Running && server.Address == "127.0.0.1",
                  "The four owned services did not start");
            var settings = new Settings { CoopHost = "127.0.0.1", AccountUsername = "autocheck1" };
            var endpoint = new Uri("http://127.0.0.1:42128/reweb/signup/create_id.html");
            string launcherCredential = await AutomaticAccount.Provision(
                home, "127.0.0.1", settings.AccountUsername, limit.Token, endpoint);
            Check(
                launcherCredential ==
                    AccountCredentials.Get(home, "127.0.0.1", settings.AccountUsername),
                "Launcher provisioning did not persist the registered account before game launch");
            using (var account = new AutomaticAccount(home, settings,
                                                      _ => {}, endpoint)) {
                var start = new ProcessStartInfo();
                account.Bind(start);
                string status = start.Environment["REO_COOP_ACCOUNT_STATUS"]!;
                string credentialFile = status + ".credential";
                Check(!File.Exists(status),
                      "Game session status was published before entering Network");
                account.Observe("[COOP-AUTO] account-request 1");
                async Task WaitFor(Func<bool> predicate) {
                    while (!predicate()) {
                        limit.Token.ThrowIfCancellationRequested();
                        await Task.Delay(25, limit.Token);
                    }
                }
                await WaitFor(() => File.Exists(status) && File.ReadAllText(status) == "ready 1");
                string password =
                    AccountCredentials.Get(home, "127.0.0.1", settings.AccountUsername);
                using var client = new HttpClient(new SocketsHttpHandler { UseProxy = false });
                await AutomaticAccount.Register(client, endpoint, settings.AccountUsername,
                                                password, limit.Token);
                Check(true, "Account was not accepted on a subsequent real server login");
                bool collision = false;
                try {
                    await AutomaticAccount.Register(client, endpoint, settings.AccountUsername,
                                                    "anotherpassword", limit.Token);
                } catch (AccountNameTakenException) {
                    collision = true;
                }
                Check(collision, "An existing account accepted the wrong credential");
                account.Observe("[COOP-AUTO] password-ready 1");
                await WaitFor(() => File.ReadAllText(status) == "input 1");
                Check(File.ReadAllBytes(credentialFile)
                          .SequenceEqual(AutomaticAccount.CredentialInput(1, password)),
                      "Native credential handoff does not match the registered account");
                File.Delete(credentialFile);
                File.WriteAllText(status + ".applied", "1");
                await WaitFor(() => File.ReadAllText(status) == "typed 1");
                Check(!File.Exists(credentialFile), "Applied credential input was retained");
                account.Observe("[COOP-AUTO] account-request 2");
                await WaitFor(() => File.ReadAllText(status) == "ready 2");
                Check(AccountCredentials.Get(home, "127.0.0.1", settings.AccountUsername) ==
                          password,
                      "Returning to Network changed the account password");
            }
            server.Dispose();
            Check(!server.Running, "Owned services did not stop");
            await Task.Delay(500);
            HostedServer.CheckPorts(32000);
            Check(true, "Owned ports were not released");
            bool installedAutomatically =
                Directory.Exists(Path.Combine(home, "server-python-runtime"));
            if (installedAutomatically) {
                string marker = Directory
                                    .GetFiles(Path.Combine(home, "server-python"), "ready.json",
                                              SearchOption.AllDirectories)
                                    .Single();
                string before = await File.ReadAllTextAsync(marker);
                await server.Start(root, "127.0.0.1", limit.Token, home, 32000, component);
                Check(server.Running, "Cached automatic server setup did not restart");
                Check(await File.ReadAllTextAsync(marker) == before,
                      "A cached startup unexpectedly repeated installation");
                server.Dispose();
            }
            await File.WriteAllTextAsync(receipt, JsonSerializer.Serialize(new {
                passed = true, checks,
                externalPython = !File.Exists(Path.Combine(component, "python", "python.exe")),
                installedAutomatically, serverServices = 4, automaticRegistration = true,
                credentialReuse = true, collisionRefused = true, nativeCredentialHandshake = true,
                game = false
            }));
        } finally {
            server.Dispose();
            // Background input cleanup may still be releasing its private files.
            for (int i = 0; i < 20; ++i) {
                try {
                    if (Directory.Exists(home))
                        RemoveOwnedTree(home, home);
                    break;
                } catch (Exception error)
                    when (error is IOException or UnauthorizedAccessException) {
                    await Task.Delay(50);
                }
            }
        }
    }
    static void RemoveOwnedTree(string folder, string root) {
        string canonical = Path.GetFullPath(root), temp = Path.GetFullPath(Path.GetTempPath());
        if (!canonical.StartsWith(temp, StringComparison.OrdinalIgnoreCase) ||
            !Path.GetFileName(canonical).StartsWith("reo-host-check-", StringComparison.Ordinal) ||
            !(Path.GetFullPath(folder) == canonical ||
              Path.GetFullPath(folder).StartsWith(canonical + Path.DirectorySeparatorChar,
                                                  StringComparison.OrdinalIgnoreCase)))
            throw new IOException("Refusing cleanup outside the owned server test directory.");
        foreach (string entry in Directory.EnumerateFileSystemEntries(folder)) {
            var attributes = File.GetAttributes(entry);
            bool directory = (attributes & FileAttributes.Directory) != 0;
            if (directory && (attributes & FileAttributes.ReparsePoint) == 0)
                RemoveOwnedTree(entry, root);
            else {
                File.SetAttributes(entry, attributes & ~FileAttributes.ReadOnly);
                if (directory)
                    Directory.Delete(entry);
                else
                    File.Delete(entry);
            }
        }
        File.SetAttributes(folder, File.GetAttributes(folder) & ~FileAttributes.ReadOnly);
        Directory.Delete(folder);
    }
}
