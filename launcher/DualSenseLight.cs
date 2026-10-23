using Microsoft.Win32.SafeHandles;
using System.Buffers.Binary;
using System.IO;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal readonly record struct PadLight(byte R, byte G, byte B) {
    public static readonly PadLight Blue = new(0, 64, 255), Green = new(0, 255, 32),
                                    Yellow = new(255, 190, 0), Red = new(255, 0, 0);
}

// Shared HID output handle only; input remains on the existing Raw Input path.
// Report fields follow SDL's documented DualSense effects layout:
// https://github.com/libsdl-org/SDL/blob/SDL2/src/joystick/hidapi/SDL_hidapi_ps5.c
internal sealed class DualSenseLight : IDisposable {
    internal sealed record Target(string Path, bool Bluetooth, PadLight Color);
    readonly object gate = new();
    readonly CancellationTokenSource stop = new();
    Target? target;
    readonly Task worker;
    internal string? LastError { get; private set; }
    internal PadLight? LastSent { get; private set; }

    public DualSenseLight() => worker = Task.Run(Run);

    public void Update(string? path, bool bluetooth, PadLight color) {
        lock (gate)
            target = path == null ? null : new(path, bluetooth, color);
    }

    internal static byte[] Report(bool bluetooth, PadLight color, bool reset = false) {
        var data = new byte[bluetooth ? 78 : 48];
        int offset = bluetooth ? 2 : 1;
        data[0] = bluetooth ? (byte)0x31 : (byte)0x02;
        if (bluetooth) data[1] = 0x02;
        data[offset + 1] = reset ? (byte)0x08 : (byte)0x04;
        if (!reset) {
            data[offset + 44] = color.R;
            data[offset + 45] = color.G;
            data[offset + 46] = color.B;
        }
        if (bluetooth) {
            uint crc = 0xffffffff;
            void Add(byte value) {
                crc ^= value;
                for (int bit = 0; bit < 8; ++bit)
                    crc = (crc >> 1) ^ ((crc & 1) != 0 ? 0xedb88320u : 0);
            }
            Add(0xa2); // Bluetooth HID output transaction, included in the checksum.
            for (int i = 0; i < 74; ++i) Add(data[i]);
            BinaryPrimitives.WriteUInt32LittleEndian(data.AsSpan(74), ~crc);
        }
        return data;
    }

    static async Task Write(FileStream stream, byte[] report, CancellationToken cancel) {
        using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
        timeout.CancelAfter(500);
        await stream.WriteAsync(report, timeout.Token).ConfigureAwait(false);
    }

    async Task Run() {
        FileStream? stream = null;
        Target? opened = null, sent = null;
        long lastWrite = 0, retryAfter = 0;
        try {
            while (!stop.IsCancellationRequested) {
                Target? next;
                lock (gate) next = target;
                try {
                    if (opened != null && (opened.Path != next?.Path || opened.Bluetooth != next?.Bluetooth)) {
                        if (stream != null && opened != null)
                            await Write(stream, Report(opened.Bluetooth, PadLight.Blue), stop.Token);
                        stream?.Dispose(); stream = null; opened = sent = null;
                        retryAfter = 0;
                    }
                    long now = Environment.TickCount64;
                    if (next != null && now >= retryAfter &&
                        (next != sent || now - lastWrite >= 5000)) {
                        if (stream == null) {
                            var handle = CreateFile(next.Path, 0x40000000, 3, 0, 3, 0x40000000, 0);
                            if (handle.IsInvalid) {
                                int error = Marshal.GetLastWin32Error();
                                handle.Dispose();
                                throw new IOException("Cannot open DualSense light: " + error);
                            }
                            try { stream = new FileStream(handle, FileAccess.Write, 1, true); }
                            catch { handle.Dispose(); throw; }
                            opened = next;
                            // Release the connection animation before claiming LED colour.
                            await Write(stream, Report(next.Bluetooth, next.Color, reset: true), stop.Token);
                        }
                        await Write(stream, Report(next.Bluetooth, next.Color), stop.Token);
                        LastSent = next.Color; LastError = null;
                        sent = next; lastWrite = now;
                    }
                } catch (Exception error) when (error is IOException or UnauthorizedAccessException or OperationCanceledException) {
                    LastError = error.Message;
                    stream?.Dispose(); stream = null; opened = sent = null;
                    retryAfter = Environment.TickCount64 + 2000;
                }
                await Task.Delay(100, stop.Token).ConfigureAwait(false);
            }
        } catch (OperationCanceledException) {
        } finally {
            if (stream != null) {
                try { await Write(stream, Report(opened!.Bluetooth, PadLight.Blue), CancellationToken.None); }
                catch (Exception error) when (error is IOException or UnauthorizedAccessException or OperationCanceledException) { }
                stream.Dispose();
            }
        }
    }

    public void Dispose() => stop.Cancel();

    [DllImport("kernel32", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern SafeFileHandle CreateFile(string path, uint access, uint share, nint security,
                                           uint creation, uint flags, nint template);
}
