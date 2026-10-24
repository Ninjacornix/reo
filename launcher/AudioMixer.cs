using System.IO.MemoryMappedFiles;

namespace Outbreak.Launcher;

internal readonly record struct AudioLevels(int Master, int Music, int Sfx, int Voice, int Ui) {
    internal static AudioLevels From(Settings settings) => new(
        Math.Clamp(settings.MasterVolume, 0, 100), Math.Clamp(settings.MusicVolume, 0, 100),
        Math.Clamp(settings.SfxVolume, 0, 100), Math.Clamp(settings.VoiceVolume, 0, 100),
        Math.Clamp(settings.UiVolume, 0, 100));
    internal string LaunchValue => $"{Master},{Music},{Sfx},{Voice},{Ui}";
}

// A separate input-only mapping keeps audio independent of pad focus, device
// selection and rumble output. The game retains the last complete update.
internal sealed class AudioMixer : IDisposable {
    internal const uint Magic = 0x52454f41;
    internal const int Bytes = 32;
    internal string MapName { get; } = "Local\\REO-Audio-" + Guid.NewGuid().ToString("N");
    readonly MemoryMappedFile map;
    readonly MemoryMappedViewAccessor view;
    int sequence;

    internal AudioMixer() {
        map = MemoryMappedFile.CreateNew(MapName, Bytes);
        view = map.CreateViewAccessor(0, Bytes);
        view.Write(0, Magic); view.Write(4, 1u);
        Publish(new Settings());
    }
    internal void Publish(Settings settings) {
        var levels = AudioLevels.From(settings);
        view.Write(8, ++sequence); // Odd while updating; publish all channels together.
        Thread.MemoryBarrier();
        view.Write(12, levels.Master); view.Write(16, levels.Music);
        view.Write(20, levels.Sfx); view.Write(24, levels.Voice); view.Write(28, levels.Ui);
        Thread.MemoryBarrier();
        view.Write(8, ++sequence);
    }
    public void Dispose() { view.Dispose(); map.Dispose(); }
}
