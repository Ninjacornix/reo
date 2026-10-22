using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
public sealed record MovieDecoderChoice(bool Gpu, string GpuName, string Reason);

// GPU movies need a hardware MPEG-2 decoder on the GPU the game renders with; some GPUs
// (AMD RDNA 4, for example) have none, and the GPU route then stops at the first movie.
// reo-movie-check.exe repeats the game's own device choice and decoder test. Without a
// clear yes the original CPU decoder plays the movies.
public static class MovieDecoder {
    public static async Task<MovieDecoderChoice> Choose(CancellationToken cancel) {
        string check = Path.Combine(AppContext.BaseDirectory, "reo-movie-check.exe");
        if (!File.Exists(check))
            return new(false, "", "Movie decoder check is missing");
        try {
            using var process = new Process { StartInfo = new ProcessStartInfo(check) {
                UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true } };
            process.Start();
            using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancel);
            timeout.CancelAfter(TimeSpan.FromSeconds(10));
            string output;
            try {
                output = await process.StandardOutput.ReadToEndAsync(timeout.Token);
                await process.WaitForExitAsync(timeout.Token);
            } catch (OperationCanceledException) {
                try { process.Kill(); } catch (InvalidOperationException) { }
                cancel.ThrowIfCancellationRequested();
                return new(false, "", "Movie decoder check timed out");
            }
            using var result = JsonDocument.Parse(output.Trim());
            var root = result.RootElement;
            return new(root.GetProperty("gpuMovies").GetBoolean(),
                       root.GetProperty("gpu").GetString() ?? "",
                       root.GetProperty("reason").GetString() ?? "");
        } catch (Exception error) when (error is IOException or JsonException or KeyNotFoundException or
                                                 InvalidOperationException or
                                                 System.ComponentModel.Win32Exception) {
            return new(false, "", "Movie decoder check failed: " + error.Message);
        }
    }
}
