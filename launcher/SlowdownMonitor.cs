using System.Diagnostics;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text.Json;

namespace Outbreak.Launcher;

// Runs before any UI/storage initialization. All capture work belongs to this
// process, so minimizing or blocking the launcher's event loop cannot stop it.
public static class SlowdownMonitor {
    static readonly JsonSerializerOptions Json = new() { WriteIndented = true };
    public static void AtomicJson<T>(string file, T value) {
        string temporary = file + ".tmp";
        File.WriteAllText(temporary, JsonSerializer.Serialize(value, Json));
        File.Move(temporary, file, true);
    }
    public static async Task<int> Run(string planFile) {
        string directory = Path.GetDirectoryName(Path.GetFullPath(planFile))!;
        int saved = 0;
        string? latest = null;
        SlowdownIncident? pending = null;
        string? pendingDirectory = null;
        SlowdownHandshake? handshake = null;
        void Status(string state, string detail) =>
            AtomicJson(Path.Combine(directory, "status.json"),
                       new SlowdownStatus(state, detail, saved, latest));
        try {
            if (!OperatingSystem.IsWindows())
                throw new IOException("Live monitoring currently requires Windows.");
            if (Path.GetFileName(planFile) != "plan.json" || new FileInfo(planFile).Length > 16384)
                throw new IOException("Invalid monitor plan.");
            var plan = JsonSerializer.Deserialize<SlowdownPlan>(File.ReadAllText(planFile)) ??
                       throw new IOException("Missing monitor plan.");
            if (!Guid.TryParseExact(plan.Session, "N", out _) ||
                plan.Map != "Local\\REO-slowdown-" + plan.Session ||
                plan.Game is not("file1" or "file2"))
                throw new IOException("Invalid session identity.");
            using var process = SlowdownIdentity.Verify(plan);
            // Keep the exact executable immutable while observing it, including
            // the launcher's private copy. No process-name attachment or PID retry.
            using var executable =
                new FileStream(plan.Image, FileMode.Open, FileAccess.Read, FileShare.Read);
            if (!Convert.ToHexString(SHA256.HashData(executable))
                     .Equals(plan.Sha256, StringComparison.OrdinalIgnoreCase))
                throw new IOException("The launched executable hash changed.");
            using var transport = new SlowdownTransport(plan.Map);
            using var lease =
                new FileStream(Path.Combine(directory, "monitor.lock"), FileMode.OpenOrCreate,
                               FileAccess.ReadWrite, FileShare.Read);
            var records = new Queue<SlowdownEvidence>();
            var health = new Queue<SlowdownHealth>();
            var detector =
                new SlowdownDetector(Stopwatch.Frequency, plan.Game == "file1", plan.Strict);
            using var trace = plan.Strict ? new SlowdownTrace(directory, plan) : null;
            trace?.Flush(null, 0);
            long number = 0, lossEpoch = 0, lastHealth = 0, lastStatus = 0, lastPartial = 0;
            ulong dropped = 0;
            uint capabilities = 0;
            bool ended = false, budgetExhausted = false;
            int maximumReports = plan.Strict ? 100 : 20;
            void PreservePartial() {
                if (pending != null)
                    AtomicJson(Path.Combine(pendingDirectory!, "incident.partial.json"), pending);
            }
            void Begin(string reason, long time) {
                if (pending != null)
                    return; // coalesce symptoms/manual marks in the same incident
                if (saved >= maximumReports ||
                    Directory
                            .EnumerateFiles(directory, "incident*.json",
                                            SearchOption.AllDirectories)
                            .Sum(f => new FileInfo(f).Length) >= 128L * 1024 * 1024) {
                    budgetExhausted = true;
                    return;
                }
                string id = DateTime.UtcNow.ToString("yyyyMMdd-HHmmss-fff") + "-" +
                            Guid.NewGuid().ToString("N")[..8];
                pendingDirectory = Path.Combine(directory, id);
                Directory.CreateDirectory(pendingDirectory);
                pending = new(id, plan, handshake, reason, time, false, dropped, capabilities,
                              records.ToList(), health.ToList());
                PreservePartial(); // history survives monitor failure during follow-up
            }
            void Finish(bool complete) {
                if (pending == null)
                    return;
                pending = pending with { Complete = complete, Handshake = handshake,
                                         Dropped = dropped, Capabilities = capabilities };
                string file = Path.Combine(pendingDirectory!,
                                           complete ? "incident.json" : "incident.partial.json");
                AtomicJson(file, pending);
                SlowdownAnalyzer.Write(pendingDirectory!);
                // A saved notification requires both evidence and generated report.
                if (complete)
                    File.Delete(Path.Combine(pendingDirectory!, "incident.partial.json"));
                latest = pendingDirectory;
                saved++;
                pending = null;
                pendingDirectory = null;
            }
            while (true) {
                long time = Stopwatch.GetTimestamp();
                if (handshake == null)
                    handshake = transport.Handshake(plan);
                if (handshake != null) {
                    capabilities = transport.Read32(12);
                    handshake = handshake with { Capabilities = capabilities };
                    var batch = transport.Drain(out ulong lost);
                    if (lost != dropped || (capabilities & 0x80000000) != 0) {
                        detector.Lost();
                        lossEpoch++;
                    }
                    dropped = lost;
                    foreach (var sample in batch) {
                        var record = sample.Record;
                        var evidence = new SlowdownEvidence(++number, record, lossEpoch,
                                                            sample.ThreadId, sample.Ring);
                        trace?.Append(evidence);
                        records.Enqueue(evidence);
                        while (records.Count > 16000 ||
                               records.Count > 0 && time - (long)records.Peek().Record.Time >
                                                        30 * Stopwatch.Frequency)
                            records.Dequeue();
                        if (pending != null && pending.Records.Count < 25000)
                            pending.Records.Add(evidence);
                        else if (pending != null)
                            pending = pending with {
                                Error =
                                    "Incident record limit reached; follow-up evidence is truncated."
                            };
                        string? symptom = detector.Observe(record);
                        if (symptom != null)
                            Begin(symptom, (long)record.Time);
                    }
                }
                if (time - lastHealth >= Stopwatch.Frequency / 2) {
                    lastHealth = time;
                    try {
                        process.Refresh();
                        var observation =
                            new SlowdownHealth(time, process.TotalProcessorTime.TotalMilliseconds,
                                               process.WorkingSet64, process.Threads.Count, null);
                        health.Enqueue(observation);
                        trace?.Append(observation);
                        if (pending != null && pending.Health.Count < 1000)
                            pending.Health.Add(observation);
                    } catch (
                        InvalidOperationException) { /* process may have exited between checks */
                    }
                    while (health.Count > 0 && time - health.Peek().Time > 30 * Stopwatch.Frequency)
                        health.Dequeue();
                }
                string request = Path.Combine(directory, "mark.request");
                if (File.Exists(request)) {
                    File.Delete(request);
                    Begin("manual", time);
                }
                string? silence = detector.Silence(time);
                if (silence != null)
                    Begin(silence, time);
                if (pending != null && time - lastPartial > Stopwatch.Frequency) {
                    PreservePartial();
                    lastPartial = time;
                }
                if (pending != null && time - pending.TriggerTime >= 5 * Stopwatch.Frequency)
                    Finish(true);
                if (time - lastStatus >= Stopwatch.Frequency / 2) {
                    lastStatus = time;
                    bool coverageLimited = dropped != 0 || (capabilities & 0x80000000) != 0;
                    string state = handshake != null && (capabilities & 6) == 6 &&
                                           !budgetExhausted && !coverageLimited &&
                                           trace?.Capped != true
                                       ? "recording"
                                       : "limited recording";
                    string detail =
                        budgetExhausted
                            ? "Session report limit reached. Start a new session to save further incidents."
                        : handshake == null
                            ? "Process health only; native recorder handshake has not arrived. Rebuild the game for clock and frame evidence."
                        : (capabilities & 6) == 0
                            ? "Native transport and process health; waiting for clock/frame instrumentation."
                        : (capabilities & 4) == 0
                            ? "Verified clock and process health; waiting for frame instrumentation."
                        : (capabilities & 2) == 0
                            ? plan.Game == "file2"
                                  ? "Frame timing and process health; File #2 original clock is not verified."
                                  : "Frame timing and process health; original-clock hook is unavailable."
                            : "Verified original clock, frame phases and process health. Reports stay on this computer.";
                    if (coverageLimited)
                        detail += " Telemetry loss detected; coverage is limited.";
                    if (plan.Strict)
                        detail +=
                            trace!.Capped
                                ? " Continuous trace limit reached; incident detection continues."
                                : " Sensitive detection and continuous evidence are enabled.";
                    trace?.Flush(handshake, dropped);
                    Status(state, detail);
                }
                // Always drain once more after exit: native worker teardown may have
                // committed records between this iteration's drain and exit check.
                if (ended)
                    break;
                ended = process.HasExited;
                if (!ended)
                    await Task.Delay(100);
            }
            if (process.ExitCode != 0 && pending == null)
                Begin("process-exit-" + process.ExitCode, Stopwatch.GetTimestamp());
            Finish(false);
            trace?.Flush(handshake, dropped, complete: true);
            if (trace != null)
                SlowdownTrace.Analyze(directory);
            Status("stopped", "Game exited; available evidence was preserved.");
            return 0;
        } catch (Exception error) {
            // Diagnostics never signal, suspend, kill or wait on the game.
            try {
                if (pending != null && pendingDirectory != null) {
                    AtomicJson(Path.Combine(pendingDirectory, "incident.partial.json"),
                               pending with { Error = error.Message });
                    SlowdownAnalyzer.Write(pendingDirectory);
                }
                Status("unavailable", "Performance diagnostics error: " + error.Message);
            } catch { /* disk/access failure cannot be repaired by claiming success */
            }
            return 1;
        }
    }
    public static string? LatestReport(string sessions) =>
        Directory.Exists(sessions)
            ? Directory.EnumerateFiles(sessions, "report.md", SearchOption.AllDirectories)
                  .Concat(Directory.EnumerateFiles(sessions, "continuous-metadata.json",
                                                   SearchOption.AllDirectories))
                  .OrderByDescending(File.GetLastWriteTimeUtc)
                  .Select(Path.GetDirectoryName)
                  .FirstOrDefault()
            : null;
    public static void Export(string bundle, string destination) {
        // Only the evidence/report allowlist, never account data, game RAM, saves,
        // logs, executable, or launch.json. Completed evidence stays immutable.
        string[] allowed = ["incident.json", "incident.partial.json", "findings.json", "report.md"];
        string full = Path.GetFullPath(destination);
        if (Path.GetFullPath(bundle).Equals(Path.GetDirectoryName(full),
                                            StringComparison.OrdinalIgnoreCase))
            throw new IOException("Choose an export destination outside the report folder.");
        string temporary = full + "." + Guid.NewGuid().ToString("N") + ".tmp";
        try {
            using (var archive = ZipFile.Open(temporary, ZipArchiveMode.Create)) {
                foreach (string name in allowed) {
                    string file = Path.Combine(bundle, name);
                    if (File.Exists(file))
                        archive.CreateEntryFromFile(file, name);
                }
                string evidence = Path.Combine(bundle, "incident.json");
                if (!File.Exists(evidence))
                    evidence = Path.Combine(bundle, "incident.partial.json");
                var incident =
                    File.Exists(evidence)
                        ? JsonSerializer.Deserialize<SlowdownIncident>(File.ReadAllText(evidence))
                        : null;
                bool sessionOnly = incident == null &&
                                   File.Exists(Path.Combine(bundle, "continuous-metadata.json"));
                if (incident == null && !sessionOnly)
                    throw new IOException("No performance evidence was found in this folder.");
                if (incident?.Process.Strict == true || sessionOnly) {
                    string session = sessionOnly ? Path.GetFullPath(bundle)
                                                 : Path.GetDirectoryName(Path.GetFullPath(bundle))!;
                    foreach (string name in new[] { "continuous.csv", "continuous-health.csv",
                                                    "continuous-metadata.json",
                                                    "continuous-analysis.json",
                                                    "continuous-report.txt" }) {
                        string file = Path.Combine(session, name);
                        if (!File.Exists(file))
                            continue;
                        using var input = new FileStream(file, FileMode.Open, FileAccess.Read,
                                                         FileShare.ReadWrite | FileShare.Delete);
                        long remaining = input.Length;
                        if (remaining > 128L * 1024 * 1024)
                            throw new IOException("Continuous trace exceeds the export limit.");
                        using var output = archive.CreateEntry("session/" + name).Open();
                        byte[] buffer = new byte[65536];
                        while (remaining > 0) {
                            int read =
                                input.Read(buffer, 0, (int)Math.Min(buffer.Length, remaining));
                            if (read == 0)
                                throw new IOException("Continuous trace changed during export.");
                            output.Write(buffer, 0, read);
                            remaining -= read;
                        }
                    }
                }
            }
            File.Move(temporary, full, true);
        } finally {
            if (File.Exists(temporary))
                File.Delete(temporary);
        }
    }
}
