using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class ControllerHealth {
    internal readonly record struct Sample(int Phase, int Slot, bool Active, int Health, int Maximum);

    internal static PadLight Color(Sample sample) {
        if (sample.Phase != 2 || sample.Slot is < 0 or >= 4 || !sample.Active ||
            sample.Maximum is <= 0 or >= 32767 || sample.Health < 0 || sample.Health > sample.Maximum)
            return PadLight.Blue;
        if (sample.Health * 4 < sample.Maximum) return PadLight.Red;
        if (sample.Health * 2 <= sample.Maximum) return PadLight.Yellow;
        return PadLight.Green;
    }

    // Bounded reads on a background worker at 4 Hz. No guest writes or game-thread hooks.
    internal static async Task Run(Process process, string elf, Controller controller, string logs) {
        LobbyAutomation.GuestMemory? memory = null;
        Sample? previous = null;
        try {
            using var trace = new StreamWriter(Path.Combine(logs, "controller-health.jsonl")) { AutoFlush = true };
            while (!process.HasExited) {
                Sample? sample = null;
                try {
                    memory ??= LobbyAutomation.GuestMemory.Open(process, elf);
                    sample = memory.ReadHealth();
                } catch (IOException) {
                    memory?.Dispose(); memory = null;
                }
                var color = sample is { } value ? Color(value) : PadLight.Blue;
                if (controller.GameProcessId != process.Id) break;
                controller.SetHealthLight(color);
                if (sample != previous) {
                    await trace.WriteLineAsync(JsonSerializer.Serialize(new {
                        utc = DateTime.UtcNow, sample, color, readOnly = true }));
                    previous = sample;
                }
                await Task.Delay(memory == null ? 2000 : 250).ConfigureAwait(false);
            }
        } catch (Exception error) when (error is IOException or InvalidOperationException or System.ComponentModel.Win32Exception) {
            Debug.WriteLine("Controller health light: " + error.Message);
        } finally {
            memory?.Dispose();
            if (controller.GameProcessId == process.Id)
                controller.SetHealthLight(PadLight.Blue);
        }
    }
}
