using System.IO.MemoryMappedFiles;
using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal readonly record struct PadRumble(ushort Left = 0, ushort Right = 0);

// Native game output occupies bytes 32..47; controller input keeps its existing ABI.
internal sealed class ControllerRumble : IDisposable {
    internal const uint Magic = 0x52454f52;
    internal const uint Timeout = 750;
    uint? activeXbox;
    PadRumble? sent;
    readonly Action<uint, ushort, ushort> xboxWriter;
    readonly object gate = new();
    readonly Timer watchdog;
    long updated;
    bool disposed;

    internal ControllerRumble(Action<uint, ushort, ushort> xboxWriter) {
        this.xboxWriter = xboxWriter;
        watchdog = new(_ => CheckTimeout(Environment.TickCount64), null, 100, 100);
    }

    internal static PadRumble Read(MemoryMappedViewAccessor view, bool enabled, uint now,
                                   int sessionStartSequence = 0) {
        if (!enabled || view.ReadUInt32(32) != Magic) return new();
        for (int attempt = 0; attempt < 8; ++attempt) {
            int first = view.ReadInt32(36);
            if ((first & 1) != 0) continue;
            Thread.MemoryBarrier();
            uint tick = view.ReadUInt32(40);
            var value = new PadRumble(view.ReadUInt16(44), view.ReadUInt16(46));
            Thread.MemoryBarrier();
            if (first != view.ReadInt32(36)) continue;
            return first != sessionStartSequence && unchecked(now - tick) <= Timeout
                       ? value : new();
        }
        return new();
    }

    internal void Update(InputDevice device, PadRumble value) {
        lock (gate) {
            if (disposed) return;
            updated = Environment.TickCount64;
            uint? next = device.Available && device.Kind == "xbox" &&
                         device.Id.StartsWith("xbox:") && uint.TryParse(device.Id.AsSpan(5), out uint slot) && slot < 4
                             ? slot : null;
            if (activeXbox != next) {
                if (activeXbox is { } previous) xboxWriter(previous, 0, 0);
                activeXbox = next; sent = null;
            }
            if (activeXbox is { } selected && sent != value) {
                xboxWriter(selected, value.Left, value.Right);
                sent = value;
            }
        }
    }

    internal void CheckTimeout(long now) {
        lock (gate) {
            if (!disposed && now - updated > Timeout && activeXbox is { } slot &&
                sent is { } motors && motors != new PadRumble()) {
                xboxWriter(slot, 0, 0); sent = new PadRumble();
            }
        }
    }

    public void Dispose() {
        lock (gate) {
            if (disposed) return;
            disposed = true;
            if (activeXbox is { } selected) xboxWriter(selected, 0, 0);
            activeXbox = null; sent = null;
        }
        watchdog.Dispose();
    }

    internal static async Task Trace(Process process, Controller controller, string logs) {
        try {
            using var stream = new StreamWriter(Path.Combine(logs, "controller-rumble.jsonl")) { AutoFlush = true };
            Controller.RumbleObservation? previous = null;
            DualSenseLight.Output? previousOutput = null;
            long exitedAt = 0;
            while (controller.GameProcessId == process.Id) {
                var requested = controller.RumbleOutput;
                var output = controller.LastDualSenseOutput;
                if (requested != previous || output != previousOutput) {
                    await stream.WriteLineAsync(JsonSerializer.Serialize(new {
                        utc = DateTime.UtcNow, requested, dualSense = output
                    })).ConfigureAwait(false);
                    previous = requested; previousOutput = output;
                }
                if (process.HasExited) {
                    if (exitedAt == 0) exitedAt = Environment.TickCount64;
                    if (Environment.TickCount64 - exitedAt >= 1000) break;
                }
                await Task.Delay(20).ConfigureAwait(false);
            }
        } catch (Exception error) when (error is IOException or InvalidOperationException or System.ComponentModel.Win32Exception) {
            Debug.WriteLine("Controller rumble trace: " + error.Message);
        }
    }
}
