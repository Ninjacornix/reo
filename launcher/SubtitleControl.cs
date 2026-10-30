using System.IO.MemoryMappedFiles;

namespace Outbreak.Launcher;

// Kept separate from the audio IPC so older audio consumers retain their exact ABI.
internal sealed class SubtitleControl : IDisposable {
    internal const uint Magic = 0x53554254;
    internal const int Bytes = 16;
    internal string MapName { get; } = "Local\\REO-Subtitles-" + Guid.NewGuid().ToString("N");
    readonly MemoryMappedFile map;
    readonly MemoryMappedViewAccessor view;
    int sequence;

    internal SubtitleControl() {
        map = MemoryMappedFile.CreateNew(MapName, Bytes);
        view = map.CreateViewAccessor(0, Bytes);
        view.Write(0, Magic);
        view.Write(4, 1u);
        Publish(true);
    }
    internal void Publish(bool enabled) {
        view.Write(8, ++sequence);
        Thread.MemoryBarrier();
        view.Write(12, enabled ? 1u : 0u);
        Thread.MemoryBarrier();
        view.Write(8, ++sequence);
    }
    public void Dispose() { view.Dispose(); map.Dispose(); }
}
