using System.IO;
using System.Net;
using System.Net.Http;
using System.Text;

namespace Outbreak.Launcher;
internal static class AutomaticAccountTests {
    sealed class Reply(string html, HttpStatusCode status = HttpStatusCode.OK)
        : HttpMessageHandler {
        public string? Form;
        protected override async Task<HttpResponseMessage> SendAsync(HttpRequestMessage request,
                                                                     CancellationToken cancel) {
            Form = await request.Content!.ReadAsStringAsync(cancel);
            return new HttpResponseMessage(status) { Content = new StringContent(html) };
        }
    }
    public static async Task Run(Action<bool, string> check) {
        var endpoint = new Uri("http://127.0.0.1/reweb/signup/create_id.html");
        using (var handler = new Reply("<!--AM-USA-COMP-SIGNUP--><!--INPUT-IDS-->test01<!--INPUT-IDE-->")) using (
            var client = new HttpClient(handler)) {
            await AutomaticAccount.Register(client, endpoint, "test01", "testpassword01", default);
            check(handler.Form == "username=test01&password=testpassword01",
                  "Account provisioning uses the real server signup fields");
        }
        foreach (string html in new[] {
                     "<!--AM-USA-COMP-SIGNUP--><!--INPUT-IDS-->other01<!--INPUT-IDE-->",
                     "<h1>success</h1>", "Password mismatch for existing user."
                 }) {
            using var handler = new Reply(html);
            using var client = new HttpClient(handler);
            bool failed = false;
            try {
                await AutomaticAccount.Register(client, endpoint, "test01", "testpassword01",
                                                default);
            } catch (IOException error) {
                failed = true;
                check(!error.Message.Contains("testpassword01"),
                      "Account errors never include credentials");
                if (html.StartsWith("Password mismatch"))
                    check(error is AccountNameTakenException,
                          "A taken username is refused rather than claimed");
            }
            check(failed,
                  "An HTTP 200 error or wrong-account response cannot admit automatic login");
        }
        byte[] input = AutomaticAccount.CredentialInput(7, "abc123def456ghi");
        check(input.Length == 28 && BitConverter.ToUInt32(input, 0) == 0x52454F41 &&
                  BitConverter.ToUInt32(input, 4) == 7 && BitConverter.ToUInt32(input, 8) == 15 &&
                  Encoding.ASCII.GetString(input, 12, 15) == "abc123def456ghi" && input[27] == 0,
              "Native editor input preserves generation and the bounded original password format");
        bool refused = false;
        try {
            AutomaticAccount.CredentialInput(0, "abc123def456ghi");
        } catch (IOException) {
            refused = true;
        }
        check(refused, "Native input refuses an invalid account generation");
        string home =
            Path.Combine(Path.GetTempPath(), "reo-account-" + Guid.NewGuid().ToString("N"));
        try {
            string first = AccountCredentials.Get(home, "127.0.0.1", "test01");
            check(first.Length == 15 && first.All(char.IsAsciiLetterOrDigit),
                  "Automatic passwords fit the original game editor");
            check(
                AccountCredentials.Get(home, "127.0.0.1", "test01") == first,
                "Lost signup responses and later launches reuse the same protected account credential");
            check(AccountCredentials.Get(home, "127.0.0.2", "test01") != first,
                  "Credentials are scoped to the configured server and username");
            check(!Directory.GetFiles(Path.Combine(home, "accounts"))
                       .Any(file => Encoding.UTF8.GetString(File.ReadAllBytes(file))
                                        .Contains(first, StringComparison.Ordinal)),
                  "Saved account files do not contain the plaintext password");
        } finally {
            if (Directory.Exists(home))
                Directory.Delete(home, true);
        }
    }
}
