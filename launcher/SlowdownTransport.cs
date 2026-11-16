using System.Diagnostics;
using System.IO.MemoryMappedFiles;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

[StructLayout(LayoutKind.Sequential)]
public readonly record struct SlowdownRecord(ulong Time, ulong Sequence, uint Kind, uint Flags,
                                             ulong A, ulong B, ulong C, ulong D, ulong E);
internal sealed record SlowdownSample(SlowdownRecord Record, uint ThreadId, int Ring);
public sealed record SlowdownPlan(string Session, string Map, int Pid, long Creation, string Image,
                                  string Sha256, string Game, bool Strict = false);
public sealed record SlowdownHandshake(uint Schema, string Session, int Pid, long Creation,
                                       string Image, string Sha256, string Build, long Frequency,
                                       uint Capabilities);

// Wire offsets are asserted in the native fixture as well as the cross-language test.
internal sealed unsafe class SlowdownTransport : IDisposable {
    internal const int Header = 4096, Rings = 8, Capacity = 1024, Stride = 65600;
    internal const int Size = Header + Rings * Stride;
    readonly MemoryMappedFile map;
    readonly MemoryMappedViewAccessor view;
    byte* pointer;
    internal SlowdownTransport(string name, string? session = null) {
        if (!OperatingSystem.IsWindows())
            throw new PlatformNotSupportedException("Live recording currently requires Windows.");
        map = session == null
                  ? MemoryMappedFile.OpenExisting(name, MemoryMappedFileRights.ReadWrite)
                  : MemoryMappedFile.CreateNew(name, Size, MemoryMappedFileAccess.ReadWrite);
        try {
            view = map.CreateViewAccessor(0, Size, MemoryMappedFileAccess.ReadWrite);
            view.SafeMemoryMappedViewHandle.AcquirePointer(ref pointer);
            if (session != null) {
                new Span<byte>(pointer, Size).Clear();
                Unsafe.WriteUnaligned(pointer, 1u);
                Encoding.ASCII.GetBytes(session).CopyTo(new Span<byte>(pointer + 32, 32));
            }
        } catch {
            map.Dispose();
            throw;
        }
    }
    ref long Long(int offset) => ref Unsafe.AsRef<long>(pointer + offset);
    internal uint Read32(int offset) =>
        unchecked((uint)Volatile.Read(ref Unsafe.AsRef<int>(pointer + offset)));
    internal long Read64(int offset) => Volatile.Read(ref Long(offset));
    internal string Text(int offset, int length) =>
        Encoding.UTF8.GetString(new ReadOnlySpan<byte>(pointer + offset, length)).TrimEnd('\0');
    internal SlowdownHandshake? Handshake(SlowdownPlan plan) {
        if (Read32(4) == 0)
            return null; // native release publishes every identity field
        if (Read32(0) != 1 || Text(32, 32) != plan.Session || Read32(8) != plan.Pid ||
            Read64(16) != plan.Creation ||
            !SlowdownIdentity.SameImage(Text(160, 1024), plan.Image) ||
            Read64(24) != Stopwatch.Frequency || string.IsNullOrWhiteSpace(Text(64, 96)))
            throw new IOException(
                "Native recorder handshake differs from the launched process or schema.");
        return new(1, plan.Session, plan.Pid, plan.Creation, plan.Image, plan.Sha256, Text(64, 96),
                   Read64(24), Read32(12));
    }
    internal List<SlowdownSample> Drain(out ulong dropped) {
        var records = new List<SlowdownSample>();
        dropped = 0;
        for (int ring = 0; ring < Rings; ring++) {
            int offset = Header + ring * Stride;
            long read = Read64(offset + 16), write = Read64(offset + 8);
            dropped += unchecked((ulong)Read64(offset + 24));
            if (read < 0 || write < read || write - read > Capacity)
                throw new IOException("Invalid native ring indices.");
            while (read < write) {
                var record = Unsafe.ReadUnaligned<SlowdownRecord>(pointer + offset + 64 +
                                                                  read % Capacity * 64);
                if (record.Sequence != (ulong)read || record.Kind is < 1 or > 4 ||
                    record.Time > (ulong)(Stopwatch.GetTimestamp() + Stopwatch.Frequency))
                    throw new IOException("Invalid committed native record.");
                records.Add(new(record, Read32(offset),
                                ring)); // copy before release: producer can now reuse this slot
                Volatile.Write(ref Long(offset + 16), ++read);
            }
        }
        records.Sort((a, b) => a.Record.Time != b.Record.Time
                                   ? a.Record.Time.CompareTo(b.Record.Time)
                                   : a.Record.Sequence.CompareTo(b.Record.Sequence));
        return records;
    }
    public void Dispose() {
        if (pointer != null) {
            view.SafeMemoryMappedViewHandle.ReleasePointer();
            pointer = null;
        }
        view.Dispose();
        map.Dispose();
    }
}

internal static class SlowdownIdentity {
    internal static bool SameImage(string a, string b) =>
        string.Equals(Path.GetFullPath(a), Path.GetFullPath(b), StringComparison.OrdinalIgnoreCase);
    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern bool QueryFullProcessImageName(IntPtr process, uint flags, StringBuilder name,
                                                 ref int length);
    [DllImport("advapi32.dll", SetLastError = true)]
    static extern bool
    OpenProcessToken(IntPtr process, uint access,
                     out Microsoft.Win32.SafeHandles.SafeAccessTokenHandle token);
    internal static Process Verify(SlowdownPlan plan) {
        if (!OperatingSystem.IsWindows())
            throw new PlatformNotSupportedException();
        var process = Process.GetProcessById(plan.Pid);
        try {
            int length = 32768;
            var image = new StringBuilder(length);
            if (process.StartTime.ToUniversalTime().ToFileTimeUtc() != plan.Creation ||
                !QueryFullProcessImageName(process.Handle, 0, image, ref length) ||
                !SameImage(image.ToString(), plan.Image))
                throw new IOException("The game process identity changed; refusing to attach.");
            if (!OpenProcessToken(process.Handle, 8, out var token))
                throw new IOException("Cannot verify game process owner.");
            using var ownedToken = token;
            using var owner = new WindowsIdentity(token.DangerousGetHandle());
            using var current = WindowsIdentity.GetCurrent();
            if (owner.User != current.User)
                throw new IOException("The game belongs to another user.");
            return process; // retained process handle cannot follow PID reuse
        } catch {
            process.Dispose();
            throw;
        }
    }
}

public sealed record SlowdownStatus(string State, string Detail, int Saved = 0,
                                    string? Latest = null);
public sealed class SlowdownSession : IDisposable {
    readonly string session = Guid.NewGuid().ToString("N");
    readonly string directory;
    readonly SlowdownTransport transport;
    readonly bool strict;
    Process? worker;
    volatile SlowdownStatus status = new("starting", "Waiting for the independent monitor.");
    public SlowdownStatus Status => status;
    internal void Failed(Exception error) => status = new("unavailable",
                                                          "Performance diagnostics error: " +
                                                              error.Message);
    internal SlowdownSession(string logs, ProcessStartInfo start, bool strict = false) {
        this.strict = strict;
        directory = Path.Combine(logs, "performance");
        Directory.CreateDirectory(directory);
        transport = new SlowdownTransport("Local\\REO-slowdown-" + session, session);
        start.Environment["REO_SLOWDOWN_MAP"] = "Local\\REO-slowdown-" + session;
        start.Environment["REO_SLOWDOWN_SESSION"] = session;
    }
    internal void Start(Process game, string image, string sha256, string gameId) {
        var plan = new SlowdownPlan(session, "Local\\REO-slowdown-" + session, game.Id,
                                    game.StartTime.ToUniversalTime().ToFileTimeUtc(),
                                    Path.GetFullPath(image), sha256, gameId, strict);
        SlowdownMonitor.AtomicJson(Path.Combine(directory, "plan.json"), plan);
        string host = Environment.ProcessPath ??
                      throw new IOException("Launcher executable identity unavailable.");
        var start = new ProcessStartInfo(host) { UseShellExecute = false, CreateNoWindow = true };
        if (Path.GetFileNameWithoutExtension(host).Equals("dotnet",
                                                          StringComparison.OrdinalIgnoreCase))
            start.ArgumentList.Add(System.Reflection.Assembly.GetEntryAssembly()!.Location);
        start.ArgumentList.Add("--slowdown-monitor");
        start.ArgumentList.Add(Path.Combine(directory, "plan.json"));
        worker = Process.Start(start) ??
                 throw new IOException("Could not start the performance monitor.");
        _ = Watch();
    }
    async Task Watch() {
        long started = Stopwatch.GetTimestamp();
        while (true) {
            try {
                string file = Path.Combine(directory, "status.json");
                if (File.Exists(file))
                    status = JsonSerializer.Deserialize<SlowdownStatus>(
                        await File.ReadAllTextAsync(file))!;
                if (worker!.HasExited) {
                    if (worker.ExitCode != 0)
                        status = status with { State = "unavailable",
                                               Detail = "Performance monitor stopped. " +
                                                        status.Detail };
                    worker.Dispose();
                    break;
                }
                if (Stopwatch.GetElapsedTime(started).TotalSeconds > 20 &&
                    status.State == "starting")
                    status = status with { State = "unavailable",
                                           Detail = "Monitor startup has not completed." };
            } catch (Exception error)
                when (error is IOException or UnauthorizedAccessException or JsonException) {
                status = status with { State = "unavailable",
                                       Detail = "Cannot read monitor status: " + error.Message };
            }
            await Task.Delay(500);
        }
    }
    public void MarkProblem() {
        if (status.State is not("recording" or "limited recording"))
            throw new IOException("The performance monitor is not ready.");
        // One bounded pending request. Repeated presses are coalesced by the monitor.
        using var file =
            new FileStream(Path.Combine(directory, "mark.request"), FileMode.OpenOrCreate,
                           FileAccess.Write, FileShare.ReadWrite | FileShare.Delete);
        file.SetLength(0);
    }
    public void Dispose() {
        transport.Dispose(); /* the monitor retains its own mapping and game handle */
    }
}
