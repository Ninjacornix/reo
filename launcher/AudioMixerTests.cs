using System.IO.MemoryMappedFiles;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class AudioMixerTests {
    internal static void Run(Action<bool, string> check) {
        var legacy = JsonSerializer.Deserialize<Settings>("{}")!;
        check(AudioLevels.From(legacy) == new AudioLevels(100, 100, 100, 100, 100),
              "Older settings keep the original full audio level");
        var settings = new Settings { MasterVolume = 37, MusicVolume = 0, SfxVolume = 82,
                                      VoiceVolume = 65, UiVolume = 13, Fullscreen = true };
        var restored = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
        check(AudioLevels.From(restored) == new AudioLevels(37, 0, 82, 65, 13) && restored.Fullscreen,
              "All five independent audio values persist, including mute");
        check(AudioLevels.From(settings).LaunchValue == "37,0,82,65,13",
              "Startup audio levels use the native channel order");
        var invalid = new Settings { MasterVolume = -1, MusicVolume = 101, SfxVolume = int.MaxValue,
                                     VoiceVolume = int.MinValue, UiVolume = 50 };
        check(AudioLevels.From(invalid) == new AudioLevels(0, 100, 100, 0, 50),
              "Audio settings cannot amplify above full scale or use negative gains");
        using var mixer = new AudioMixer();
        using var consumer = MemoryMappedFile.OpenExisting(mixer.MapName, MemoryMappedFileRights.Read);
        using var view = consumer.CreateViewAccessor(0, AudioMixer.Bytes, MemoryMappedFileAccess.Read);
        check(view.ReadUInt32(0) == AudioMixer.Magic && view.ReadUInt32(4) == 1 &&
              view.ReadUInt32(8) % 2 == 0,
              "Audio shared memory advertises a complete versioned snapshot");
        check(Enumerable.Range(0, 5).All(i => view.ReadInt32(12 + i * 4) == 100),
              "Native consumers see full volume before the first user update");
        uint before = view.ReadUInt32(8);
        mixer.Publish(settings);
        check(view.ReadUInt32(8) == before + 2 && view.ReadUInt32(8) % 2 == 0 &&
              new[] { 37, 0, 82, 65, 13 }.Select((value, index) =>
                  view.ReadInt32(12 + index * 4) == value).All(value => value),
              "Live audio changes reach the native mapping with no channel crossover");
        mixer.Publish(invalid);
        check(new[] { 0, 100, 100, 0, 50 }.Select((value, index) =>
                  view.ReadInt32(12 + index * 4) == value).All(value => value),
              "Live publication validates channel limits as well as startup values");
    }
}
