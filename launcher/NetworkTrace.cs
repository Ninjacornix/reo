using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;
// Optional co-op packet timing. The native transport (REO_COOP_TRACE_FILE) writes every socket
// payload in hex, including the login exchange; after the game exits only each packet's header
// bytes are kept so the log can be shared. Timestamps are the game's steady clock, which on
// Windows is QueryPerformanceCounter; the anchor maps them to UTC to align with the server log.
internal static partial class NetworkTrace {
    internal const string RawName = "coop-trace.raw.jsonl";
    internal const string SharedName = "coop-trace.jsonl";
    internal const int HeaderBytes = 16;

    internal static string Start(string logs) {
        long ticks = Stopwatch.GetTimestamp();
        var steadyUs = (long)((Int128)ticks * 1_000_000 / Stopwatch.Frequency);
        File.WriteAllText(Path.Combine(logs, "coop-trace-clock.json"),
                          JsonSerializer.Serialize(new { utc = DateTime.UtcNow, steadyUs }));
        return Path.Combine(logs, RawName);
    }

    // Rewrites the raw trace with payloads cut to their header; removes the raw file.
    internal static void Finish(string logs) {
        var raw = Path.Combine(logs, RawName);
        if (!File.Exists(raw)) return;
        try {
            using (var reader = new StreamReader(raw))
            using (var writer = new StreamWriter(Path.Combine(logs, SharedName))) {
                for (string? line; (line = reader.ReadLine()) != null;)
                    writer.WriteLine(Strip(line));
            }
            File.Delete(raw);
        } catch (IOException) {
            // Leave the raw file in place; it is never shared automatically.
        }
    }

    internal static string Strip(string line) =>
        Hex().Replace(line, m => "\"hex\":\"" + m.Groups[1].Value[..Math.Min(m.Groups[1].Length, HeaderBytes * 2)] + "\"");

    [GeneratedRegex("\"hex\":\"([0-9a-fA-F]*)\"")]
    private static partial Regex Hex();
}

internal static class NetworkTraceTests {
    internal static void Run(Action<bool, string> check) {
        string payload = new string('a', 400);
        string line = "{\"t_us\":5,\"direction\":\"send\",\"bytes\":200,\"hex\":\"" + payload + "\"}";
        check(NetworkTrace.Strip(line) ==
              "{\"t_us\":5,\"direction\":\"send\",\"bytes\":200,\"hex\":\"" + new string('a', 32) + "\"}",
              "Network trace keeps only packet headers and the original byte count");
        check(NetworkTrace.Strip("{\"event\":\"rpc\",\"op\":1}") == "{\"event\":\"rpc\",\"op\":1}",
              "Network trace leaves non-packet events unchanged");
        string logs = Path.Combine(Path.GetTempPath(), "reo-trace-test-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(logs);
        try {
            string rawPath = NetworkTrace.Start(logs);
            File.WriteAllText(rawPath, line + "\n");
            NetworkTrace.Finish(logs);
            check(!File.Exists(rawPath) &&
                  File.ReadAllText(Path.Combine(logs, NetworkTrace.SharedName)).Trim() == NetworkTrace.Strip(line) &&
                  File.Exists(Path.Combine(logs, "coop-trace-clock.json")),
                  "Finished network trace replaces the full-payload file with the shareable one");
        } finally {
            Directory.Delete(logs, true);
        }
    }
}
