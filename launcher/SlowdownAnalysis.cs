using System.Text.Json;

namespace Outbreak.Launcher;

public sealed record SlowdownEvidence(long Id, SlowdownRecord Record, long LossEpoch = 0,
                                      uint ThreadId = 0, int Ring = 0);
public sealed record SlowdownHealth(long Time, double CpuMilliseconds, long WorkingSet, int Threads,
                                    bool? Responding);
public sealed record SlowdownFinding(string Classification, string Summary, long[] Evidence,
                                     string[] Sources);
public sealed record SlowdownIncident(string Id, SlowdownPlan Process, SlowdownHandshake? Handshake,
                                      string Trigger, long TriggerTime, bool Complete,
                                      ulong Dropped, uint Capabilities,
                                      List<SlowdownEvidence> Records, List<SlowdownHealth> Health,
                                      string? Error = null, uint Schema = 1);
public sealed record SlowdownReport(string Verdict, bool Partial, List<SlowdownFinding> Findings,
                                    string[] Unknowns);

internal sealed record SlowdownPolicy(double ClockWindow, double ClockRatio, double FrameWork,
                                      double PresentationGap, double Silence) {
    internal static SlowdownPolicy For(bool strict) =>
        strict ? new(1, .90, .040, .040, 2) : new(2, .75, .150, .250, 5);
    internal static double LateUpdateSeconds(SlowdownRecord clock) =>
        Math.Max(.025, (byte)(clock.C >> 16) / 60.0 * 1.5);
}

// Same clock interpretation as tools/analyze_game_clock.py. A callback is not an
// original update. Loss, resets, pause/room/mode epochs break continuity.
internal sealed class SlowdownDetector {
    readonly long frequency;
    readonly bool requireClock;
    readonly bool strict;
    readonly SlowdownPolicy policy;
    SlowdownRecord? first, previous, lastUpdate;
    ulong lastFrame, lastClock, lastPresented;
    long lastSymptom, lastWarmupEnd;
    bool warmup, latched, lastFrameVisible;
    internal SlowdownDetector(long frequency, bool requireClock, bool strict = false) {
        this.frequency = frequency;
        this.requireClock = requireClock;
        this.strict = strict;
        policy = SlowdownPolicy.For(strict);
    }
    internal static bool Eligible(SlowdownRecord r) => r.Kind == 1 && (byte)(r.C >> 24) == 2 &&
                                                       (byte)(r.C >> 32) == 0 &&
                                                       (byte)(r.C >> 40) == 0 &&
                                                       (ushort)r.C == (byte)(r.C >> 48) &&
                                                       (byte)(r.C >> 16) is 1 or 2;
    internal static bool Continuous(SlowdownRecord before, SlowdownRecord after) {
        const ulong epoch =
            0xffff000000ffffff; // scenario/cache-room, room/step; phase handled by Eligible
        if (!Eligible(before) || !Eligible(after) || (before.C & epoch) != (after.C & epoch) ||
            (byte)before.D != (byte)after.D || after.Time <= before.Time)
            return false;
        return after.A == before.A && after.B == before.B ||
               after.A == before.A + (byte)(after.C >> 16) && after.B == before.B + 1;
    }
    internal void Lost() {
        first = previous = lastUpdate = null;
        lastClock = lastFrame = lastPresented = 0;
        lastFrameVisible = false;
    }
    string? Symptom(string reason, long time) {
        bool trigger = !latched || time - lastSymptom > 10 * frequency;
        latched = true;
        lastSymptom = time;
        return trigger ? reason : null;
    }
    internal string? Observe(SlowdownRecord record) {
        long time = checked((long)record.Time);
        if (record.Kind == 3) {
            warmup = record.A != 0;
            if (!warmup)
                lastWarmupEnd = time;
            Lost();
            return null;
        }
        if (record.Kind == 4) {
            Lost();
            return null;
        }
        if (record.Kind == 1) {
            lastClock = record.Time;
            string? late = null;
            if (previous is not {} before || !Continuous(before, record)) {
                first = lastUpdate = record;
            } else if (record.A != before.A || record.B != before.B) {
                if (strict && !warmup && lastUpdate is {} update &&
                    (record.Time - update.Time) / (double)frequency >
                        SlowdownPolicy.LateUpdateSeconds(record))
                    late = Symptom("original-update-hitch", time);
                lastUpdate = record;
            }
            previous = record;
            if (!Eligible(record) || warmup) {
                first = lastUpdate = null;
                return null;
            }
            first ??= record;
            var start = first.Value;
            double seconds = (record.Time - start.Time) / (double)frequency;
            if (seconds >= policy.ClockWindow) {
                double ratio = (record.A - start.A) / 60.0 / seconds;
                first = record;
                if (ratio < policy.ClockRatio)
                    return late ?? Symptom("original-clock-slowdown", time);
            }
            return late;
        }
        if (record.Kind == 2) {
            ulong previousFrame = lastPresented;
            lastFrame = record.Time;
            if (record.Flags == 3) {
                lastFrameVisible = true;
                lastPresented = record.Time;
            } else if ((record.Flags & 1) != 0) {
                lastFrameVisible = false;
                lastPresented = 0; // minimize / detached epoch
            }
            bool gameplay = strict || !requireClock || previous is {}
            clock && Eligible(clock) && record.Time >= clock.Time &&
                record.Time - clock.Time < (ulong)(2 * frequency);
            // Only visible presentations can trigger a presentation hitch. Minimized
            // windows and intentionally retired scanouts do not satisfy Flags == 3.
            if (warmup || time - lastWarmupEnd < frequency || !gameplay || record.Flags != 3)
                return null;
            if (record.A >= (ulong)(frequency * policy.FrameWork))
                return Symptom("frame-work-hitch", time);
            if (previousFrame != 0 && record.Time > previousFrame &&
                record.Time - previousFrame >= (ulong)(frequency * policy.PresentationGap))
                return Symptom("presentation-gap", time);
        }
        return null;
    }
    internal string? Silence(long time) {
        // Absence of hooks cannot distinguish loading, pause, blocked workers,
        // or missing instrumentation. Report a stream gap, never a proven hang.
        if (!warmup && previous is {} clock && Eligible(clock) && lastClock != 0 &&
            time - (long)lastClock > policy.Silence * frequency)
            return Symptom("gameplay-observation-gap", time);
        if ((strict || !requireClock) && !warmup && lastFrameVisible && lastFrame != 0 &&
            time - (long)lastFrame > policy.Silence * frequency)
            return Symptom("presentation-observation-gap", time);
        return null;
    }
}

public static class SlowdownAnalyzer {
    public static SlowdownReport Analyze(SlowdownIncident incident) {
        var policy = SlowdownPolicy.For(incident.Process.Strict);
        var findings = new List<SlowdownFinding>();
        findings.Add(new(
            "measured symptom",
            incident.Trigger == "manual"
                ? "The player marked a problem; automatic thresholds need not have been crossed."
                : "Incident trigger: " + incident.Trigger +
                      ". This describes an observation, not a root cause.",
            incident.Records
                .Where(x => Math.Abs((long)x.Record.Time - incident.TriggerTime) <
                            (incident.Handshake?.Frequency ?? 1) * 3)
                .Select(x => x.Id)
                .ToArray(),
            []));
        long frequency = incident.Handshake?.Frequency ?? 0;
        if (frequency > 0) {
            var clocks = incident.Records.Where(x => x.Record.Kind is 1 or 4).ToList();
            SlowdownEvidence? start = null, previous = null, lastUpdate = null;
            int lateUpdates = 0;
            foreach (var point in clocks) {
                if (!SlowdownDetector.Eligible(point.Record)) {
                    start = previous = lastUpdate = null;
                    continue;
                }
                if (previous == null || previous.LossEpoch != point.LossEpoch ||
                    !SlowdownDetector.Continuous(previous.Record, point.Record))
                    start = lastUpdate = point;
                else if (point.Record.A != previous.Record.A ||
                         point.Record.B != previous.Record.B) {
                    if (incident.Process.Strict && lastUpdate is {} update && lateUpdates < 20) {
                        double gap = (point.Record.Time - update.Record.Time) / (double)frequency;
                        if (gap > SlowdownPolicy.LateUpdateSeconds(point.Record)) {
                            findings.Add(new(
                                "measured symptom",
                                $"One original update interval occupied {gap * 1000:F1} ms; expected quantum is {(byte)(point.Record.C >> 16) / 60.0 * 1000:F1} ms. This can be hidden by an average FPS reading.",
                                [update.Id, point.Id],
                                ["recomp/overrides/reo_game_clock_observer.h"]));
                            lateUpdates++;
                        }
                    }
                    lastUpdate = point;
                }
                start ??= point;
                var a = start.Record;
                var b = point.Record;
                double wall = (b.Time - a.Time) / (double)frequency;
                if (wall >= policy.ClockWindow) {
                    if ((b.A - a.A) / 60.0 / wall < policy.ClockRatio)
                        findings.Add(new(
                            "measured symptom",
                            $"Original clock advanced {(b.A-a.A)/60.0:F3} game seconds in {wall:F3} host seconds; duplicate actor callbacks do not count as updates.",
                            [start.Id, point.Id], [
                                "recomp/overrides/reo_game_clock_observer.h",
                                "tools/analyze_game_clock.py"
                            ]));
                    start = point;
                }
                previous = point;
            }
            foreach (var point in incident.Records
                         .Where(x => x.Record.Kind == 2 &&
                                     x.Record.A >= (ulong)(frequency * policy.FrameWork))
                         .OrderByDescending(x => x.Record.A)
                         .Take(5)) {
                var r = point.Record;
                string phase =
                    (r.Flags & 1) == 0         ? "capture (scanout boundary was not reached)"
                    : r.B >= r.C && r.B >= r.D ? "capture preparation / GS flush / scanout"
                    : r.C >= r.D ? "presentation call (may include CPU, driver, and waits)"
                                 : "capture tail";
                findings.Add(new(
                    "measured bottleneck",
                    $"Frame capture occupied {r.A*1000.0/frequency:F1} ms; largest measured phase: {phase}. Phase completion flags={r.Flags}. This is host wall time, not GPU execution time.",
                    [point.Id], [
                        "tools/parallel_gs_backend/parallel_backend.cpp: capture",
                        "runtime/gs/frame_pacing.h"
                    ]));
            }
        }
        if (incident.Dropped != 0 || (incident.Capabilities & 0x80000000) != 0)
            findings.Add(new(
                "evidence limitation",
                $"Telemetry loss: {incident.Dropped} full-ring drops; producer overflow={(incident.Capabilities & 0x80000000) != 0}. Clock continuity is not established across loss.",
                [], []));
        if (incident.Error != null)
            findings.Add(new("evidence limitation", incident.Error, [], []));
        return new(
            "Root cause unknown; no controlled fix/retest has confirmed a cause.",
            !incident.Complete, findings, [
                "No automatic stack suspension or game-memory dump was performed.",
                "A missing clock hook can mean loading, pause, a blocked worker, or missing coverage.",
                "Frame phases include CPU and driver waits; GPU timestamps, VU work attribution, and input replay are unavailable.",
                "A candidate fix needs an independently recorded retest of the same game, room, settings and interaction; this bundle is not a deterministic replay."
            ]);
    }
    public static void Write(string bundle) {
        string file = Path.Combine(bundle, "incident.json");
        if (!File.Exists(file))
            file = Path.Combine(bundle, "incident.partial.json");
        if (new FileInfo(file).Length > 32 * 1024 * 1024)
            throw new IOException("Incident exceeds the analyzer's input limit.");
        var incident = JsonSerializer.Deserialize<SlowdownIncident>(File.ReadAllText(file)) ??
                       throw new IOException("Missing incident.");
        if (incident.Schema != 1 || incident.Handshake is {} handshake &&
                                        (handshake.Schema != 1 || handshake.Frequency <= 0))
            throw new IOException("Unsupported incident schema or clock frequency.");
        if (incident.Records.Count > 25000 || incident.Health.Count > 1000)
            throw new IOException("Incident exceeds the analyzer's record limit.");
        var report = Analyze(incident);
        SlowdownMonitor.AtomicJson(Path.Combine(bundle, "findings.json"), report);
        string text =
            "# Performance incident " + incident.Id + "\n\n" + report.Verdict + "\n\n" +
            (report.Partial
                 ? "Partial bundle: the monitor or game ended before follow-up completed.\n\n"
                 : "") +
            string.Join("\n\n", report.Findings.Select(
                                    f => "- **" + f.Classification + "**: " + f.Summary +
                                         "\n  Evidence IDs: " + string.Join(", ", f.Evidence) +
                                         ". Sources: " + string.Join(", ", f.Sources))) +
            "\n\n## Unknowns and retest\n\n" +
            string.Join("\n", report.Unknowns.Select(x => "- " + x)) +
            "\n\nEvidence IDs refer to Records[].Id in incident.json (or incident.partial.json). Raw clock fields and phase values use schema 1 in docs/LIVE_SLOWDOWN_CHECKER.md.\n";
        File.WriteAllText(Path.Combine(bundle, "report.md"), text);
    }
}
