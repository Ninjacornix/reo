using Avalonia.Media.Imaging;
using System.Diagnostics;
using System.Globalization;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher.Desktop.Controls;

// The MediaElement subset RC1's BackgroundVideoPlayer uses: open, play, pause, seek, close,
// natural duration, opened/ended/failed. FFmpeg decodes in its own process; frames are paced
// here at the clip's frame rate and drawn like MediaElement with Stretch.
public sealed partial class VideoSurface : Control, IDisposable {
    public static readonly StyledProperty<Stretch> StretchProperty =
        AvaloniaProperty.Register<VideoSurface, Stretch>(nameof(Stretch), Stretch.UniformToFill);
    public Stretch Stretch { get => GetValue(StretchProperty); set => SetValue(StretchProperty, value); }
    public event EventHandler? MediaOpened, MediaEnded;
    public event EventHandler<string>? MediaFailed;
    public string? MediaPath { get; private set; }
    public bool HasVideo => opened && bitmap != null;
    public TimeSpan? NaturalDuration { get; private set; }
    WriteableBitmap? bitmap;
    CancellationTokenSource? decode;
    Process? process;
    bool opened, playing;
    int generation;
    readonly Stopwatch clock = new();
    TimeSpan start;
    double frameRate = 30;
    long shownFrames;
    TaskCompletionSource resume = new(TaskCreationOptions.RunContinuationsAsynchronously);

    public TimeSpan Position {
        get => start + TimeSpan.FromSeconds(shownFrames / frameRate);
        set {
            if (MediaPath == null) return;
            start = value < TimeSpan.Zero ? TimeSpan.Zero : value;
            shownFrames = 0;
            if (opened) Restart();
        }
    }
    public void Open(string path) {
        Close();
        MediaPath = path;
        start = TimeSpan.Zero;
        Restart();
    }
    public void Play() {
        if (MediaPath == null) return;
        playing = true;
        clock.Start();
        resume.TrySetResult();
    }
    public void Pause() {
        playing = false;
        clock.Stop();
        resume = new(TaskCreationOptions.RunContinuationsAsynchronously);
    }
    public void Close() {
        generation++;
        decode?.Cancel(); decode?.Dispose(); decode = null;
        Kill();
        MediaPath = null; NaturalDuration = null; opened = false; playing = false;
        clock.Reset(); shownFrames = 0;
        resume = new(TaskCreationOptions.RunContinuationsAsynchronously);
        var prior = bitmap; bitmap = null; prior?.Dispose();
        InvalidateVisual();
    }
    public void Dispose() => Close();
    void Kill() {
        try { if (process is { } child && !child.HasExited) child.Kill(true); }
        catch (Exception error) when (error is InvalidOperationException or System.ComponentModel.Win32Exception) { }
        process = null;
    }
    void Restart() {
        decode?.Cancel(); decode?.Dispose();
        Kill();
        var cancel = decode = new CancellationTokenSource();
        clock.Reset(); if (playing) clock.Start();
        _ = Decode(MediaPath!, start, ++generation, cancel.Token);
    }
    [GeneratedRegex(@"Duration: (\d+):(\d\d):(\d\d(?:\.\d+)?)")] private static partial Regex DurationPattern();
    [GeneratedRegex(@"Video: .*?, (\d{2,5})x(\d{2,5})")] private static partial Regex SizePattern();
    [GeneratedRegex(@"([\d.]+) fps")] private static partial Regex RatePattern();
    async Task Decode(string clip, TimeSpan offset, int run, CancellationToken token) {
        string? failure = null;
        bool ended = false;
        try {
            var info = new ProcessStartInfo(PlatformServices.Ffmpeg()) { UseShellExecute = false, CreateNoWindow = true,
                RedirectStandardOutput = true, RedirectStandardError = true };
            var arguments = new List<string> { "-hide_banner", "-loglevel", "info", "-nostdin" };
            if (offset > TimeSpan.Zero) arguments.AddRange(["-ss", offset.TotalSeconds.ToString("0.###", CultureInfo.InvariantCulture)]);
            arguments.AddRange(["-i", clip, "-an", "-sn", "-dn", "-pix_fmt", "bgra", "-f", "rawvideo", "pipe:1"]);
            foreach (string argument in arguments) info.ArgumentList.Add(argument);
            using var child = Process.Start(info) ?? throw new IOException("Could not start the background-video decoder.");
            process = child;
            var header = new TaskCompletionSource<(int Width, int Height)>(TaskCreationOptions.RunContinuationsAsynchronously);
            var errors = Task.Run(async () => {
                var log = new System.Text.StringBuilder();
                TimeSpan? duration = null;
                while (await child.StandardError.ReadLineAsync(token).ConfigureAwait(false) is { } line) {
                    if (log.Length < 4096) log.AppendLine(line);
                    if (DurationPattern().Match(line) is { Success: true } d)
                        duration = TimeSpan.FromHours(int.Parse(d.Groups[1].Value)) + TimeSpan.FromMinutes(int.Parse(d.Groups[2].Value)) +
                                   TimeSpan.FromSeconds(double.Parse(d.Groups[3].Value, CultureInfo.InvariantCulture));
                    if (line.Contains("Video:") && SizePattern().Match(line) is { Success: true } s) {
                        if (RatePattern().Match(line) is { Success: true } r &&
                            double.TryParse(r.Groups[1].Value, CultureInfo.InvariantCulture, out double fps) && fps > 1)
                            frameRate = fps;
                        Dispatcher.UIThread.Post(() => { if (run == generation) NaturalDuration = duration; });
                        header.TrySetResult((int.Parse(s.Groups[1].Value), int.Parse(s.Groups[2].Value)));
                    }
                }
                header.TrySetException(new IOException(log.ToString().Trim()));
                return log.ToString();
            }, token);
            var (width, height) = await header.Task.WaitAsync(token).ConfigureAwait(false);
            byte[] frame = new byte[width * height * 4];
            var output = child.StandardOutput.BaseStream;
            long index = 0;
            while (!token.IsCancellationRequested) {
                int count = 0;
                while (count < frame.Length) {
                    int read = await output.ReadAsync(frame.AsMemory(count), token).ConfigureAwait(false);
                    if (read == 0) break;
                    count += read;
                }
                if (count < frame.Length) { ended = index > 0; break; }
                // Pause holds the shown frame; the decoder blocks on its full pipe meanwhile.
                while (true) {
                    while (!playing && !token.IsCancellationRequested) await resume.Task.WaitAsync(token).ConfigureAwait(false);
                    double due = index / frameRate, now = clock.Elapsed.TotalSeconds;
                    if (due > now) await Task.Delay(TimeSpan.FromSeconds(Math.Min(due - now, .05)), token).ConfigureAwait(false);
                    else if (playing) break;
                }
                long shown = ++index;
                var copy = frame.ToArray();
                await Dispatcher.UIThread.InvokeAsync(() => Present(copy, width, height, shown, run), DispatcherPriority.Render);
            }
            if (!ended && !token.IsCancellationRequested) {
                await child.WaitForExitAsync(token).ConfigureAwait(false);
                failure = child.ExitCode != 0 || index == 0 ? (await errors.ConfigureAwait(false)).Trim() : null;
                if (failure is { Length: 0 }) failure = "The background clip has no playable video.";
            }
        } catch (OperationCanceledException) { return; }
        catch (Exception error) when (error is IOException or System.ComponentModel.Win32Exception or InvalidOperationException) {
            failure = error.Message;
        }
        await Dispatcher.UIThread.InvokeAsync(() => {
            if (run != generation) return;
            if (failure != null) MediaFailed?.Invoke(this, failure);
            else if (ended) MediaEnded?.Invoke(this, EventArgs.Empty);
        });
    }
    void Present(byte[] frame, int width, int height, long index, int run) {
        if (run != generation) return;
        if (bitmap == null || bitmap.PixelSize.Width != width || bitmap.PixelSize.Height != height) {
            bitmap?.Dispose();
            bitmap = new WriteableBitmap(new PixelSize(width, height), new Vector(96, 96),
                Avalonia.Platform.PixelFormat.Bgra8888, Avalonia.Platform.AlphaFormat.Opaque);
        }
        using (var pixels = bitmap.Lock())
            for (int y = 0; y < height; y++)
                System.Runtime.InteropServices.Marshal.Copy(frame, y * width * 4, pixels.Address + y * pixels.RowBytes, width * 4);
        shownFrames = index;
        InvalidateVisual();
        if (!opened) { opened = true; MediaOpened?.Invoke(this, EventArgs.Empty); }
    }
    public override void Render(DrawingContext context) {
        if (bitmap == null) return;
        var source = new Rect(bitmap.Size);
        var bounds = new Rect(Bounds.Size);
        var size = Stretch.CalculateSize(bounds.Size, source.Size);
        var destination = new Rect(bounds.Center.X - size.Width / 2, bounds.Center.Y - size.Height / 2, size.Width, size.Height);
        using (context.PushClip(bounds))
            context.DrawImage(bitmap, source, destination);
    }
}
