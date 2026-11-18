using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text.Json;
using Outbreak.Launcher;

internal static class SlowdownTests {
    static SlowdownRecord Clock(ulong time, ulong units, ulong counter, ulong state = 0) =>
        new(time, counter, 1, 0, units, counter,
            state == 0 ? 1ul | (2ul << 16) | (2ul << 24) | (1ul << 48) : state, 0, 0);
    internal static async Task Run(Action<bool, string> check) {
        check(Marshal.SizeOf<SlowdownRecord>() == 64, "Native and managed wire record sizes match");
        check(!JsonSerializer.Deserialize<DeveloperOptions>("{}")!.RecordSlowdowns,
              "Slowdown recording is off for older settings");
        check(JsonSerializer
                  .Deserialize<DeveloperOptions>(JsonSerializer.Serialize(
                      new DeveloperOptions { RecordSlowdowns = true }))!.RecordSlowdowns,
              "Slowdown opt-in survives settings roundtrip");
        check(new DeveloperOptions { RecordSlowdowns = true }
                      .Environment("session", true, "file1")
                      .Count == 0,
              "Slowdown setting changes no game speed, rendering, VU or bounded CSV switches");
        var detector = new SlowdownDetector(1000, true);
        bool triggered = false;
        for (ulong update = 0; update < 100; ++update) {
            for (ulong actor = 0; actor < 4; ++actor)
                triggered |=
                    detector.Observe(Clock(1000 + update * 34 + actor, update * 2, update)) != null;
        }
        check(!triggered, "Four actor callbacks per update do not change the measured clock speed");
        detector = new(1000, true);
        string? symptom = null;
        for (ulong update = 0; update < 40; ++update)
            symptom ??= detector.Observe(Clock(1000 + update * 100, update * 2, update));
        check(symptom == "original-clock-slowdown",
              "Slow original clock triggers without counting callbacks");
        detector = new(1000, true);
        triggered = false;
        for (ulong update = 0; update < 100; ++update) {
            var sample = Clock(1000 + update * 100, update * 2, update);
            triggered |= detector.Observe(sample with { C = sample.C | (1ul << 32) }) != null;
        }
        check(!triggered && detector.Silence(50000) == null,
              "Paused clock does not trigger slowdown or stream silence");
        var before = Clock(1000, 2, 1);
        var after = Clock(2000, 4, 2);
        check(SlowdownDetector.Continuous(before, after),
              "Verified clock quantum and counter pair continues an epoch");
        check(!SlowdownDetector.Continuous(before, after with { A = 6 }),
              "Skipped/reset clocks break continuity");
        check(!SlowdownDetector.Continuous(before, after with { C = after.C ^ (1ul << 56) }),
              "Scenario changes break continuity");
        check(!SlowdownDetector.Continuous(before, after with { D = 1 }),
              "Cache variant changes break continuity");
        check(!SlowdownDetector.Continuous(before, after with { Time = 999 }),
              "Nonmonotonic host time breaks continuity");
        detector = new(1000, true);
        detector.Observe(before);
        detector.Lost();
        check(detector.Silence(8000) == null, "Loss removes unsupported clock silence claims");
        detector = new(1000, true);
        detector.Observe(before);
        check(
            detector.Silence(8000) == "gameplay-observation-gap" && detector.Silence(9000) == null,
            "Missing hooks produce one observation-gap incident, not a proven hang or notification storm");
        detector = new(1000, false);
        detector.Observe(new(2000, 0, 2, 3, 10, 3, 4, 3, 1));
        check(
            detector.Silence(8000) == "presentation-observation-gap",
            "File #2 missing frame stream is preserved as an observation gap, not a proved game stall");
        detector = new(1000, false);
        detector.Observe(new(2000, 0, 2, 1, 10, 3, 0, 0, 1));
        check(detector.Silence(8000) == null,
              "Suspended visible presentation is not treated as a missing visible stream");
        detector = new(1000, false);
        check(detector.Observe(new(2000, 0, 2, 1, 1000, 0, 0, 0, 0)) == null,
              "Invisible/retired frames do not trigger presentation incidents");
        check(detector.Observe(new(3000, 0, 2, 3, 180, 10, 160, 10, 1)) == "frame-work-hitch",
              "Visible long frame work triggers a hitch");
        detector = new(1000, false);
        detector.Observe(new(1000, 0, 3, 0, 1, 0, 0, 0, 0));
        check(detector.Observe(new(3000, 0, 2, 3, 180, 10, 160, 10, 1)) == null,
              "Shader warmup suppresses gameplay hitch detection");
        detector = new(1000, true, true);
        triggered = false;
        for (ulong update = 0; update < 100; update++)
            for (ulong actor = 0; actor < 4; actor++)
                triggered |=
                    detector.Observe(Clock(1000 + update * 34 + actor, update * 2, update)) != null;
        check(!triggered,
              "Sensitive detection deduplicates actors and accepts steady original speed");
        detector = new(1000, true, true);
        detector.Observe(Clock(1000, 0, 0));
        detector.Observe(Clock(1033, 0, 0));
        detector.Observe(Clock(1060, 0, 0));
        check(
            detector.Observe(Clock(1070, 2, 1)) == "original-update-hitch",
            "One 70ms original update triggers even with duplicate callbacks inside the interval");
        detector = new(1000, true, true);
        symptom = null;
        for (ulong update = 0; update < 35; update++)
            symptom ??= detector.Observe(Clock(1000 + update * 40, update * 2, update));
        check(symptom == "original-clock-slowdown",
              "Sensitive detection catches a 17% speed drop over one second");
        detector = new(1000, true, true);
        check(detector.Observe(new(2000, 0, 2, 3, 45, 10, 30, 5, 1)) == "frame-work-hitch",
              "One 45ms frame triggers without actor-clock coverage during a cutscene");
        detector = new(1000, true, true);
        detector.Observe(new(2000, 0, 2, 3, 10, 3, 4, 3, 1));
        detector.Observe(new(2016, 1, 2, 0, 1, 0, 0, 0, 2));
        check(detector.Observe(new(2050, 2, 2, 3, 10, 3, 4, 3, 3)) == "presentation-gap",
              "Sensitive detection checks visible cadence across retired scanouts");
        detector = new(1000, true, true);
        detector.Observe(new(2000, 0, 2, 3, 10, 3, 4, 3, 1));
        detector.Observe(new(2016, 1, 2, 0, 1, 0, 0, 0, 2));
        check(detector.Silence(5000) == "presentation-observation-gap",
              "A retired scanout does not hide a subsequent stopped visible stream");
        detector = new(1000, true, true);
        detector.Observe(new(2000, 0, 2, 3, 10, 3, 4, 3, 1));
        detector.Observe(new(2016, 1, 2, 1, 10, 3, 0, 0, 1));
        check(detector.Observe(new(5000, 2, 2, 3, 10, 3, 4, 3, 3)) == null,
              "Sensitive presentation gaps do not span a minimized epoch");
        check(JsonSerializer
                  .Deserialize<DeveloperOptions>(JsonSerializer.Serialize(
                      new DeveloperOptions { StrictSlowdowns = true }))!.StrictSlowdowns,
              "Sensitive mode persists in developer settings");
        if (!OperatingSystem.IsWindows())
            return;
        string? nativeGame = Environment.GetEnvironmentVariable("REO_SLOWDOWN_NATIVE");
        if (nativeGame != null) {
            string token = Guid.NewGuid().ToString("N"), mapName = "Local\\REO-slowdown-" + token;
            using var map = new SlowdownTransport(mapName, token);
            var help = new ProcessStartInfo(
                nativeGame) { UseShellExecute = false, CreateNoWindow = true,
                              RedirectStandardOutput = true, RedirectStandardError = true };
            help.ArgumentList.Add("--help");
            help.Environment["REO_SLOWDOWN_MAP"] = mapName;
            help.Environment["REO_SLOWDOWN_SESSION"] = token;
            using var process = Process.Start(help)!;
            var plan = new SlowdownPlan(
                token, mapName, process.Id, process.StartTime.ToUniversalTime().ToFileTimeUtc(),
                Path.GetFullPath(nativeGame), Updates.Sha(nativeGame), "file1");
            await process.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(10));
            check(
                process.ExitCode == 0 &&
                    map.Handshake(plan)?.Build.StartsWith("reo-slowdown-v1") == true,
                "Rebuilt native executable publishes its real recorder identity before --help exits; no game session was played");
        }
        string? fixture = Environment.GetEnvironmentVariable("REO_SLOWDOWN_FIXTURE");
        if (fixture == null)
            throw new IOException(
                "Set REO_SLOWDOWN_FIXTURE to the freshly built tools/slowdown_check/fixture.cpp executable.");
        string home =
            Path.Combine(Path.GetTempPath(), "reo-slowdown-tests-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(home);
        try {
            // Validate overflow, immutable unread slots, producer limits, and rejection
            // of stale sessions/PID creation identities using a real native process.
            string session = Guid.NewGuid().ToString("N"), name = "Local\\REO-slowdown-" + session;
            using (var map = new SlowdownTransport(name, session)) {
                var start = new ProcessStartInfo(fixture) { UseShellExecute = false,
                                                            CreateNoWindow = true };
                start.Environment["REO_SLOWDOWN_MAP"] = name;
                start.Environment["REO_SLOWDOWN_SESSION"] = session;
                start.ArgumentList.Add("--overflow");
                using var native = Process.Start(start)!;
                var plan = new SlowdownPlan(
                    session, name, native.Id, native.StartTime.ToUniversalTime().ToFileTimeUtc(),
                    Path.GetFullPath(fixture), Updates.Sha(fixture), "file1");
                await native.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(10));
                check(native.ExitCode == 0,
                      "Native producer completes while full rings have no consumer");
                check(map.Handshake(plan) != null,
                      "Native QPC/process/image handshake matches managed process identity");
                bool rejected = false;
                try {
                    map.Handshake(plan with { Creation = plan.Creation + 1 });
                } catch (IOException) {
                    rejected = true;
                }
                check(rejected, "Native handshake rejects PID reuse/creation mismatch");
                rejected = false;
                try {
                    map.Handshake(plan with { Session = Guid.NewGuid().ToString("N") });
                } catch (IOException) {
                    rejected = true;
                }
                check(rejected, "Native handshake rejects stale random sessions");
                var batch = map.Drain(out ulong dropped).Select(s => s.Record).ToList();
                check(batch.Count == 8192 && dropped == 80,
                      "Every full SPSC ring drops ten records without overwriting unread slots");
                check(batch.GroupBy(r => r.A).All(
                          g => g.Select(r => r.B).SequenceEqual(
                              Enumerable.Range(0, 1024).Select(i => (ulong)i))),
                      "Unread native payloads remain intact across full rings");
                check((map.Read32(12) & 0x80000000) != 0, "Producer limit loss is explicit");
                check(map.Drain(out _).Count == 0,
                      "Consumer advances only after copying committed records");
            }
            session = Guid.NewGuid().ToString("N");
            name = "Local\\REO-slowdown-" + session;
            using (var map = new SlowdownTransport(name, session)) {
                var start = new ProcessStartInfo(fixture) { UseShellExecute = false,
                                                            CreateNoWindow = true };
                start.Environment["REO_SLOWDOWN_MAP"] = name;
                start.Environment["REO_SLOWDOWN_SESSION"] = session;
                start.ArgumentList.Add("--flood");
                using var native = Process.Start(start)!;
                var received = new List<SlowdownRecord>();
                ulong lost = 0;
                do {
                    received.AddRange(map.Drain(out lost).Select(s => s.Record));
                    await Task.Delay(1);
                } while (!native.HasExited);
                received.AddRange(map.Drain(out lost).Select(s => s.Record));
                check(
                    received.Count > 0 && received.Count + (long)lost == 200000,
                    "Concurrent cross-process acquire/release accounts for every committed or dropped record");
                check(
                    received.All(r => r.B == (r.A ^ 0x12345678) && r.C == r.A + 7 &&
                                      r.D == r.A * 3 && r.E == r.A * 5),
                    "Concurrent cross-process consumer sees complete payloads without torn records");
            }
            // Full worker lifecycle through the same self-hosting launcher mode.
            var launch =
                new ProcessStartInfo(fixture) { UseShellExecute = false, CreateNoWindow = true };
            using var recording = new SlowdownSession(home, launch, strict: true);
            using var game = Process.Start(launch)!;
            recording.Start(game, fixture, Updates.Sha(fixture), "file1");
            var actual = new SlowdownPlan("unused", "unused", game.Id,
                                          game.StartTime.ToUniversalTime().ToFileTimeUtc(), fixture,
                                          Updates.Sha(fixture), "file1");
            using (var owned = SlowdownIdentity.Verify(actual))
                check(owned.Id == game.Id, "Owned process identity is validated before monitoring");
            bool refused = false;
            try {
                using var wrong =
                    SlowdownIdentity.Verify(actual with { Creation = actual.Creation + 1 });
            } catch (IOException) {
                refused = true;
            }
            check(refused, "External monitor rejects a reused PID identity before attaching");
            var deadline = Stopwatch.StartNew();
            while (recording.Status.State == "starting" && deadline.Elapsed.TotalSeconds < 8)
                await Task.Delay(100);
            check(recording.Status.State is "recording" or "limited recording",
                  "Independent monitor starts without constructing launcher UI");
            recording.MarkProblem();
            await game.WaitForExitAsync().WaitAsync(TimeSpan.FromSeconds(15));
            while (recording.Status.State != "stopped" && deadline.Elapsed.TotalSeconds < 15)
                await Task.Delay(100);
            check(recording.Status.State == "stopped" && recording.Status.Saved >= 1,
                  "Monitor preserves history/followup, reports exit and counts only saved reports");
            string report =
                recording.Status.Latest ?? throw new IOException("Fixture did not save a report");
            check(File.Exists(Path.Combine(report, "report.md")) &&
                      File.Exists(Path.Combine(report, "findings.json")),
                  "Offline human and structured reports are generated");
            var incident = JsonSerializer.Deserialize<SlowdownIncident>(File.ReadAllText(
                Path.Combine(report, File.Exists(Path.Combine(report, "incident.json"))
                                         ? "incident.json"
                                         : "incident.partial.json")))!;
            check(incident.Records.Count > 20 && incident.Health.Count > 3,
                  "Incident contains native records and independent process health");
            string traceDirectory = Path.Combine(home, "performance");
            var continuous =
                SlowdownTrace.Read(Path.Combine(traceDirectory, "continuous.csv")).ToList();
            check(incident.Process.Strict && continuous.Count > 20 &&
                      File.Exists(Path.Combine(traceDirectory, "continuous-analysis.json")),
                  "Sensitive mode saves and analyzes observations even outside incident triggers");
            using (var meta = JsonDocument.Parse(
                       File.ReadAllText(Path.Combine(traceDirectory, "continuous-metadata.json"))))
                check(meta.RootElement.GetProperty("Complete").GetBoolean() &&
                          meta.RootElement.GetProperty("Records").GetInt64() == continuous.Count,
                      "Final trace receipt matches committed records and process exit");
            check(SlowdownAnalyzer.Analyze(incident).Verdict.Contains("unknown"),
                  "Evidence is not promoted to a confirmed root cause");
            string exported = Path.Combine(home, "report.zip");
            SlowdownMonitor.Export(report, exported);
            using var zip = System.IO.Compression.ZipFile.OpenRead(exported);
            check(zip.Entries.Count >= 3 &&
                      zip.Entries.All(e => e.Name is
                                           "report.md" or "findings.json" or "incident.json" or
                                           "incident.partial.json" or "continuous.csv" or
                                           "continuous-health.csv" or "continuous-metadata.json" or
                                           "continuous-analysis.json" or "continuous-report.txt"),
                  "Export contains only performance evidence and reports");
            check(zip.Entries.Any(e => e.FullName == "session/continuous.csv"),
                  "Sensitive exports include continuous evidence");
            string wholeSession = Path.Combine(home, "whole-session.zip");
            SlowdownMonitor.Export(traceDirectory, wholeSession);
            using (var sessionZip = System.IO.Compression.ZipFile.OpenRead(wholeSession))
                check(sessionZip.Entries.Count >= 4 &&
                          sessionZip.Entries.All(e => e.FullName.StartsWith("session/")),
                      "A continuous session exports without requiring an incident report");
            string cappedDirectory = Path.Combine(home, "trace-limit");
            Directory.CreateDirectory(cappedDirectory);
            using (var capped = new SlowdownTrace(cappedDirectory, incident.Process, limit: 300)) {
                for (int n = 0; n < 100; n++)
                    capped.Append(new SlowdownEvidence(
                        n, Clock((ulong)(1000 + n * 34), (ulong)(n * 2), (ulong)n)));
                capped.Flush(incident.Handshake, 0);
                check(capped.Capped &&
                          new FileInfo(Path.Combine(cappedDirectory, "continuous.csv")).Length <
                              300,
                      "Continuous trace obeys its byte budget without overwriting history");
            }
            int completeRows =
                SlowdownTrace.Read(Path.Combine(cappedDirectory, "continuous.csv")).Count();
            File.AppendAllText(Path.Combine(cappedDirectory, "continuous.csv"),
                               "incomplete,last,row");
            check(SlowdownTrace.Read(Path.Combine(cappedDirectory, "continuous.csv")).Count() ==
                      completeRows,
                  "Interrupted final CSV row preserves preceding complete observations");
            AtomicPartialCheck(report, incident, check);
            string limitedHome = Path.Combine(home, "limited");
            Directory.CreateDirectory(limitedHome);
            var older =
                new ProcessStartInfo(fixture) { UseShellExecute = false, CreateNoWindow = true };
            older.ArgumentList.Add("--no-recorder");
            using var limited = new SlowdownSession(limitedHome, older);
            using var oldGame = Process.Start(older)!;
            limited.Start(oldGame, fixture, Updates.Sha(fixture), "file2");
            var wait = Stopwatch.StartNew();
            while (limited.Status.State == "starting" && wait.Elapsed.TotalSeconds < 5)
                await Task.Delay(50);
            check(
                limited.Status.State == "limited recording" &&
                    limited.Status.Detail.Contains("health only"),
                "Old native builds are honestly limited rather than claiming the saved setting proves recording");
            limited.MarkProblem();
            await oldGame.WaitForExitAsync();
            while (limited.Status.State != "stopped" && wait.Elapsed.TotalSeconds < 8)
                await Task.Delay(50);
            check(limited.Status.Saved == 1 && limited.Status.Latest != null,
                  "Manual health-only incident survives game exit during followup");
            var partial = JsonSerializer.Deserialize<SlowdownIncident>(
                File.ReadAllText(Path.Combine(limited.Status.Latest!, "incident.partial.json")))!;
            check(
                !partial.Complete && partial.Handshake == null && partial.Records.Count == 0 &&
                    partial.Health.Count > 0,
                "Partial unsupported-native report exposes missing capabilities and preserves process health");
        } finally {
            Directory.Delete(home, true);
        }
    }
    static void AtomicPartialCheck(string report, SlowdownIncident incident,
                                   Action<bool, string> check) {
        File.Delete(Path.Combine(report, "incident.json"));
        SlowdownMonitor.AtomicJson(Path.Combine(report, "incident.partial.json"),
                                   incident with { Complete = false });
        SlowdownAnalyzer.Write(report);
        check(JsonSerializer
                  .Deserialize<SlowdownReport>(
                      File.ReadAllText(Path.Combine(report, "findings.json")))!.Partial,
              "Offline analyzer handles interrupted partial bundles");
    }
}
