using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;

internal static class GameImageCache {
    public record Input(string Source, string Destination);
    public record Result(string Image, string Sha256);
    static string Hash(string file) {
        using var stream = File.OpenRead(file);
        if (stream.Length >= 1024 * 1024) {
            using var buffered = new BufferedStream(stream, 1024 * 1024);
            return Convert.ToHexString(SHA256.HashData(buffered)).ToLowerInvariant();
        }
        return Convert.ToHexString(SHA256.HashData(stream)).ToLowerInvariant();
    }
    public static Result Prepare(string home, IEnumerable<Input> files, CancellationToken cancel) {
        var inputs = files.Select(file => (File: file, Hash: Hash(file.Source)))
                         .OrderBy(file => file.File.Destination, StringComparer.OrdinalIgnoreCase)
                         .ToArray();
        if (inputs.Select(file => file.File.Destination)
                .Distinct(StringComparer.OrdinalIgnoreCase)
                .Count() != inputs.Length)
            throw new IOException("Duplicate game runtime files.");
        string identity =
            Convert
                .ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join(
                    "\n", inputs.Select(file => file.File.Destination + ":" + file.Hash)))))
                .ToLowerInvariant();
        string directory = LocalGameBuild.Inside(home, identity);
        Directory.CreateDirectory(directory);
        foreach (var input in inputs) {
            cancel.ThrowIfCancellationRequested();
            string target = LocalGameBuild.Inside(directory, input.File.Destination);
            if (File.Exists(target)) {
                if (Hash(target) != input.Hash)
                    throw new IOException("A cached game runtime file failed verification.");
                continue;
            }
            Directory.CreateDirectory(Path.GetDirectoryName(target)!);
            string temporary = target + "." + Guid.NewGuid().ToString("N") + ".tmp";
            try {
                File.Copy(input.File.Source, temporary, false);
                if (Hash(temporary) != input.Hash)
                    throw new IOException("The selected game build changed while copying.");
                try {
                    File.Move(temporary, target, false);
                } catch (IOException) when (File.Exists(target) && Hash(target) == input.Hash) {
                }
            } finally {
                if (File.Exists(temporary))
                    File.Delete(temporary);
            }
        }
        var image = inputs.Single(file => file.File.Destination == "reo_launcher_game.exe");
        return new(Path.Combine(directory, image.File.Destination), image.Hash);
    }
}
