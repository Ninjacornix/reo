using System.Diagnostics;
using System.Globalization;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

// Sensitive mode keeps the committed stream, including observations that never
// triggered an incident. All IO stays in the independent monitor process.
internal sealed class SlowdownTrace : IDisposable {
    readonly string directory;
    readonly SlowdownPlan plan;
    readonly long limit;
    readonly StreamWriter records, health;
    long bytes, count, healthCount;
    bool capped;
    internal bool Capped => capped;
    internal SlowdownTrace(string directory, SlowdownPlan plan, long limit = 128L * 1024 * 1024) {
        this.directory = directory;
        this.plan = plan;
        this.limit = limit;
        StreamWriter Open(string name) =>
            new(new FileStream(Path.Combine(directory, name), FileMode.CreateNew, FileAccess.Write,
                               FileShare.Read, 65536),
                new UTF8Encoding(false)) { NewLine = "\n" };
        records = Open("continuous.csv");
        try {
            health = Open("continuous-health.csv");
        } catch {
            records.Dispose();
            throw;
        }
        Write(records, "id,loss_epoch,thread,ring,time,sequence,kind,flags,a,b,c,d,e");
        Write(health, "time,cpu_ms,working_set,threads");
    }
    bool Write(StreamWriter writer, string line) {
        if (capped || bytes + line.Length + 1 > limit) {
            capped = true;
            return false;
        }
        writer.WriteLine(line);
        bytes += line.Length + 1;
        return true;
    }
    internal void Append(SlowdownEvidence evidence) {
        var r = evidence.Record;
        if (Write(
                records,
                FormattableString.Invariant(
                    $"{evidence.Id},{evidence.LossEpoch},{evidence.ThreadId},{evidence.Ring},{r.Time},{r.Sequence},{r.Kind},{r.Flags},{r.A},{r.B},{r.C},{r.D},{r.E}")))
            count++;
    }
    internal void Append(SlowdownHealth observation) {
        if (Write(
                health,
                FormattableString.Invariant(
                    $"{observation.Time},{observation.CpuMilliseconds:R},{observation.WorkingSet},{observation.Threads}")))
            healthCount++;
    }
    internal void Flush(SlowdownHandshake? handshake, ulong dropped, bool complete = false) {
        records.Flush();
        health.Flush();
        SlowdownMonitor.AtomicJson(Path.Combine(directory, "continuous-metadata.json"), new {
            Schema = 1, Plan = plan, Handshake = handshake, Frequency = Stopwatch.Frequency,
            Policy = SlowdownPolicy.For(plan.Strict), Records = count, Health = healthCount,
            Bytes = bytes, Limit = limit, Capped = capped, Dropped = dropped, Complete = complete
        });
    }
    public void Dispose() {
        records.Dispose();
        health.Dispose();
    }

    // A crash may leave an incomplete final row. Keep every complete preceding
    // record; never fill missing bytes or treat a truncated row as evidence.
    internal static IEnumerable<SlowdownEvidence> Read(string file) {
        bool partialTail;
        using (var input =
                   new FileStream(file, FileMode.Open, FileAccess.Read, FileShare.ReadWrite)) {
            partialTail = false;
            if (input.Length != 0) {
                input.Seek(-1, SeekOrigin.End);
                partialTail = input.ReadByte() != '\n';
            }
        }
        using var stream = new StreamReader(
            new FileStream(file, FileMode.Open, FileAccess.Read, FileShare.ReadWrite));
        if (stream.ReadLine() != "id,loss_epoch,thread,ring,time,sequence,kind,flags,a,b,c,d,e")
            throw new IOException("Unsupported continuous trace header.");
        while (stream.ReadLine() is {} line) {
            if (stream.EndOfStream && partialTail)
                yield break;
            string[] parts = line.Split(',');
            if (parts.Length != 13 || line.Length > 512)
                throw new IOException("Invalid continuous trace row.");
            var values = parts.Select(p => ulong.Parse(p, CultureInfo.InvariantCulture)).ToArray();
            yield return new(
                checked((long)values[0]),
                new(values[4], values[5], checked((uint)values[6]), checked((uint)values[7]),
                    values[8], values[9], values[10], values[11], values[12]),
                checked((long)values[1]), checked((uint)values[2]), checked((int)values[3]));
        }
    }
    public static void Analyze(string directory) {
        using var metadata = JsonDocument.Parse(
            File.ReadAllText(Path.Combine(directory, "continuous-metadata.json")));
        var root = metadata.RootElement;
        if (root.GetProperty("Schema").GetInt32() != 1)
            throw new IOException("Unsupported continuous trace schema.");
        long frequency = root.GetProperty("Frequency").GetInt64();
        if (frequency <= 0)
            throw new IOException("Invalid continuous trace frequency.");
        bool strict = root.GetProperty("Plan").GetProperty("Strict").GetBoolean();
        var policy = SlowdownPolicy.For(strict);
        var detector = new SlowdownDetector(
            frequency, root.GetProperty("Plan").GetProperty("Game").GetString() == "file1", strict);
        long count = 0, frames = 0, frameHitches = 0, loss = -1;
        double maximumFrameMs = 0;
        var triggers = new List<object>();
        foreach (var evidence in Read(Path.Combine(directory, "continuous.csv"))) {
            count++;
            if (evidence.LossEpoch != loss) {
                detector.Lost();
                loss = evidence.LossEpoch;
            }
            var record = evidence.Record;
            if (record.Kind == 2) {
                frames++;
                maximumFrameMs = Math.Max(maximumFrameMs, record.A * 1000.0 / frequency);
                if (record.Flags == 3 && record.A >= frequency * policy.FrameWork)
                    frameHitches++;
            }
            if ((detector.Observe(record) ?? detector.Silence((long)record.Time)) is {} reason &&
                triggers.Count < 1000)
                triggers.Add(new { evidence.Id, record.Time, Reason = reason });
        }
        SlowdownMonitor.AtomicJson(Path.Combine(directory, "continuous-analysis.json"), new {
            Verdict = "Measured timing observations; root cause unknown.", Records = count,
            Frames = frames, FrameWorkHitches = frameHitches, MaximumFrameWorkMs = maximumFrameMs,
            Triggers = triggers, Complete = root.GetProperty("Complete").GetBoolean(),
            Capped = root.GetProperty("Capped").GetBoolean(),
            Dropped = root.GetProperty("Dropped").GetUInt64()
        });
        File.WriteAllText(
            Path.Combine(directory, "continuous-report.txt"),
            FormattableString.Invariant(
                $"Continuous performance evidence\n\nRoot cause unknown.\nRecords: {count}\nFrame scopes: {frames}\nVisible frame-work hitches: {frameHitches}\nMaximum frame work: {maximumFrameMs:F3} ms\nComplete acquisition: {root.GetProperty("Complete").GetBoolean()}\nTrace capped: {root.GetProperty("Capped").GetBoolean()}\nDropped telemetry: {root.GetProperty("Dropped").GetUInt64()}\n\nSee continuous-analysis.json for trigger evidence IDs and continuous.csv for every preserved observation. These are host timing observations, not GPU display timestamps.\n"));
    }
}
