using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Net.Http;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;

// Credentials belong to this Windows user, not the settings file or game logs.
internal static class AccountCredentials {
    [StructLayout(LayoutKind.Sequential)]
    struct Blob {
        public int Length;
        public nint Data;
    }
    [DllImport("crypt32", SetLastError = true, CharSet = CharSet.Unicode)]
    static extern bool CryptProtectData(ref Blob input, string description, ref Blob entropy,
                                        nint reserved, nint prompt, uint flags, out Blob output);
    [DllImport("crypt32", SetLastError = true)]
    static extern bool CryptUnprotectData(ref Blob input, nint description, ref Blob entropy,
                                          nint reserved, nint prompt, uint flags, out Blob output);
    [DllImport("kernel32")]
    static extern nint LocalFree(nint value);

    static byte[] Protect(byte[] input, byte[] entropy, bool decrypt) {
        var a = new Blob { Length = input.Length, Data = Marshal.AllocHGlobal(input.Length) };
        var b = new Blob { Length = entropy.Length, Data = Marshal.AllocHGlobal(entropy.Length) };
        Blob result = default;
        try {
            Marshal.Copy(input, 0, a.Data, input.Length);
            Marshal.Copy(entropy, 0, b.Data, entropy.Length);
            bool ok = decrypt ? CryptUnprotectData(ref a, 0, ref b, 0, 0, 1, out result)
                              : CryptProtectData(ref a, "RE: Outbreak account", ref b, 0, 0, 1,
                                                 out result);
            if (!ok)
                throw new Win32Exception(
                    Marshal.GetLastWin32Error(),
                    "Could not access this Windows user's saved network credentials.");
            var bytes = new byte[result.Length];
            Marshal.Copy(result.Data, bytes, 0, bytes.Length);
            return bytes;
        } finally {
            for (int i = 0; i < a.Length; i++)
                Marshal.WriteByte(a.Data, i, 0);
            Marshal.FreeHGlobal(a.Data);
            Marshal.FreeHGlobal(b.Data);
            if (result.Data != 0) {
                for (int i = 0; i < result.Length; i++)
                    Marshal.WriteByte(result.Data, i, 0);
                LocalFree(result.Data);
            }
        }
    }

    public static string Get(string home, string host, string username) {
#if REO_CROSS_PLATFORM
        if (!OperatingSystem.IsWindows()) return PlatformCredentials.Get(host, username);
#endif
        byte[] identity = SHA256.HashData(Encoding.UTF8.GetBytes(host + "\n" + username));
        string directory = Path.Combine(home, "accounts");
        Directory.CreateDirectory(directory);
        string path = Path.Combine(directory, Convert.ToHexString(identity) + ".credential");
        // Persist before making the request: a lost response must not strand a new account.
        if (!File.Exists(path)) {
            const string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
            string generated =
                new(Enumerable.Range(0, 15)
                        .Select(
                            _ => alphabet[RandomNumberGenerator.GetInt32(alphabet.Length)])
                        .ToArray());
            byte[] clear = Encoding.ASCII.GetBytes(generated);
            byte[] encrypted;
            try {
                encrypted = Protect(clear, identity, false);
            } finally {
                CryptographicOperations.ZeroMemory(clear);
            }
            string temporary = path + "." + Guid.NewGuid().ToString("N") + ".tmp";
            try {
                File.WriteAllBytes(temporary, encrypted);
                try {
                    File.Move(temporary, path, false);
                } catch (IOException) when (File.Exists(path)) {
                }
            } finally {
                if (File.Exists(temporary))
                    File.Delete(temporary);
            }
        }
        byte[] password = Protect(File.ReadAllBytes(path), identity, true);
        try {
            string text = Encoding.ASCII.GetString(password);
            if (text.Length != 15 || text.Any(c => !char.IsAsciiLetterOrDigit(c)))
                throw new IOException("Saved network credentials are invalid.");
            return text;
        } finally {
            CryptographicOperations.ZeroMemory(password);
        }
    }
}

internal sealed class AutomaticAccount : IDisposable {
    internal static async Task<string> Provision(string home, string host, string username,
                                                 CancellationToken cancel, Uri? endpoint = null) {
        string credential = AccountCredentials.Get(home, host, username);
        using var handler = new SocketsHttpHandler { AllowAutoRedirect = false, UseProxy = false,
                                                     ConnectTimeout = TimeSpan.FromSeconds(5) };
        using var client = new HttpClient(handler) { Timeout = TimeSpan.FromSeconds(20) };
        if (endpoint != null) {
            await Register(client, endpoint, username, credential, cancel);
            return credential;
        }
        try {
            await Register(client, SignupEndpoint(host, HostNetworking.SignupPort), username,
                           credential, cancel);
        } catch (HttpRequestException error)
            when (error.HttpRequestError == HttpRequestError.ConnectionError) {
            // Servers hosted by launchers before 1.0.12, and standalone openSNAP servers, use 80.
            await Register(client, SignupEndpoint(host, 80), username, credential, cancel);
        }
        return credential;
    }
    internal static Uri SignupEndpoint(string host, int port) =>
        new($"http://{host}:{port}/reweb/signup/create_id.html");
    readonly string host, username, directory, status, input;
    readonly CancellationTokenSource stop = new();
    readonly Action<string> report;
    readonly Uri? endpoint;
    readonly object gate = new();
    Task? setup, delivery;
    int attempt;
    bool disposed;
    string? password;
    public AutomaticAccount(string home, Settings settings, Action<string> report,
                            Uri? registrationEndpoint = null) {
        OnlineOptions.TryHost(settings.CoopHost, out host);
        username = settings.AccountUsername;
        endpoint = registrationEndpoint;
        this.report = report;
        directory = Path.Combine(home, "network-sessions", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        status = Path.Combine(directory, "status");
        input = status + ".credential";
        Home = home;
    }
    string Home { get; }
    public void
    Bind(ProcessStartInfo start) => start.Environment["REO_COOP_ACCOUNT_STATUS"] = status;
    void Publish(string value) {
        File.WriteAllText(status + ".tmp", value, Encoding.ASCII);
        File.Move(status + ".tmp", status, true);
    }
    public void Observe(string line) {
        lock (gate) {
            if (disposed)
                return;
            const string request = "[COOP-AUTO] account-request ",
                         ready = "[COOP-AUTO] password-ready ";
            if (line.StartsWith(request, StringComparison.Ordinal) &&
                int.TryParse(line[request.Length..], out int next) && next > attempt &&
                next <= 1000) {
                var previousSetup = setup;
                var previousDelivery = delivery;
                attempt = next;
                delivery = null;
                setup = Task.Run(async () => {
                    try {
                        if (previousSetup != null)
                            await previousSetup;
                        if (previousDelivery != null)
                            await previousDelivery;
                        if (!stop.IsCancellationRequested)
                            await Prepare(next);
                    } catch (OperationCanceledException) when (stop.IsCancellationRequested) {
                    } catch {
                        Failure(
                            next,
                            "Could not prepare private network input. Restart the game to retry.");
                    }
                });
            }
            if (line.StartsWith(ready, StringComparison.Ordinal) &&
                int.TryParse(line[ready.Length..], out int current) && current == attempt &&
                delivery == null)
                delivery = Task.Run(() => Deliver(current));
        }
    }
    async Task Prepare(int current) {
        try {
            report("Preparing network account...");
            password = await Provision(Home, host, username, stop.Token, endpoint);
            Publish("ready " + current);
            report("Network account ready. Connecting in the game...");
        } catch (OperationCanceledException) when (stop.IsCancellationRequested) {
        } catch (Exception error) {
            Failure(
                current,
                error is AccountNameTakenException
                    ? error.Message
                    : "Could not prepare the network account. Check the server and try Network again.");
        }
    }
    internal static async Task Register(HttpClient client, Uri endpoint, string username,
                                        string password, CancellationToken cancel) {
        using var form = new FormUrlEncodedContent(
            new Dictionary<string, string> { ["username"] = username, ["password"] = password });
        using var response = await client.PostAsync(endpoint, form, cancel);
        response.EnsureSuccessStatusCode();
        if (response.Content.Headers.ContentLength > 65536)
            throw new IOException("The account response is too large.");
        using var body = await response.Content.ReadAsStreamAsync(cancel);
        using var text = new StreamReader(body, Encoding.UTF8);
        char[] buffer = new char[65537];
        int length = 0;
        while (length < buffer.Length) {
            int read = await text.ReadAsync(buffer.AsMemory(length), cancel);
            if (read == 0)
                break;
            length += read;
        }
        if (length > 65536)
            throw new IOException("The account response is too large.");
        string html = new(buffer, 0, length);
        string marker = "<!--INPUT-IDS-->" + username + "<!--INPUT-IDE-->";
        if (!html.Contains("<!--AM-USA-COMP-SIGNUP-->", StringComparison.Ordinal) ||
            !html.Contains(marker, StringComparison.Ordinal)) {
            if (html.Contains("Password mismatch for existing user.", StringComparison.Ordinal))
                throw new AccountNameTakenException(
                    "That username is already in use on this server. Choose another username.");
            throw new IOException("The server did not confirm account registration.");
        }
    }
    async Task Deliver(int current) {
        try {
            if (setup == null)
                throw new IOException("Account preparation was not requested.");
            await setup;
            if (password == null || !File.Exists(status) ||
                File.ReadAllText(status) != "ready " + current)
                return;
            File.Delete(status + ".applied");
            byte[] bytes = CredentialInput((uint)current, password);
            try {
                File.WriteAllBytes(input + ".tmp", bytes);
                File.Move(input + ".tmp", input, true);
                Publish("input " + current);
            } finally {
                CryptographicOperations.ZeroMemory(bytes);
            }
            var timer = Stopwatch.StartNew();
            while (timer.Elapsed < TimeSpan.FromSeconds(20)) {
                stop.Token.ThrowIfCancellationRequested();
                if (File.Exists(status + ".applied") &&
                    File.ReadAllText(status + ".applied").Trim() == current.ToString()) {
                    password = null;
                    Publish("typed " + current);
                    report("Credentials entered. Waiting for the game's server login.");
                    return;
                }
                await Task.Delay(25, stop.Token);
            }
            throw new IOException("The game did not accept native credential input.");
        } catch (OperationCanceledException) when (stop.IsCancellationRequested) {
        } catch {
            Failure(current,
                    "Automatic login could not complete. Return to the network menu to retry.");
        } finally {
            TryDelete(input);
            TryDelete(input + ".tmp");
        }
    }
    internal static byte[] CredentialInput(uint attempt, string password) {
        if (attempt == 0 || password.Length != 15 ||
            password.Any(c => !char.IsAsciiLetterOrDigit(c)))
            throw new IOException("Invalid native credential input.");
        byte[] bytes = new byte[28];
        BitConverter.GetBytes(0x52454F41u).CopyTo(bytes, 0);
        BitConverter.GetBytes(attempt).CopyTo(bytes, 4);
        BitConverter.GetBytes(15u).CopyTo(bytes, 8);
        Encoding.ASCII.GetBytes(password).CopyTo(bytes, 12);
        return bytes;
    }
    void Failure(int current, string message) {
        if (stop.IsCancellationRequested)
            return;
        try {
            Publish("error " + current);
        } catch (IOException) {
        } catch (UnauthorizedAccessException) {
        }
        report(message);
    }
    static void TryDelete(string file) {
        try {
            File.Delete(file);
        } catch (IOException) {
        } catch (UnauthorizedAccessException) {
        }
    }
    public void Dispose() {
        lock (gate) {
            if (disposed)
                return;
            disposed = true;
            stop.Cancel();
            _ = Cleanup();
        }
    }
    async Task Cleanup() {
        try {
            if (setup != null)
                await setup;
            if (delivery != null)
                await delivery;
        } finally {
            password = null;
            foreach (string file in new[] { input, input + ".tmp", status, status + ".tmp",
                                            status + ".applied", status + ".applied.tmp" })
                TryDelete(file);
            try {
                Directory.Delete(directory, false);
            } catch (IOException) {
            }
            stop.Dispose();
        }
    }
}
internal sealed class AccountNameTakenException(string message) : IOException
(message);
