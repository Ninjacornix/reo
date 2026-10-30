using System.IO.MemoryMappedFiles;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class SubtitleControlTests {
    internal static void Run(Action<bool, string> check) {
        check(new Settings().ShowSubtitles && JsonSerializer.Deserialize<Settings>("{}")!.ShowSubtitles,
              "New and legacy settings show spoken subtitles by default");
        var restored = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(new Settings { ShowSubtitles = false }))!;
        check(!restored.ShowSubtitles, "The hidden-subtitles preference survives settings persistence");
        using var control = new SubtitleControl();
        using var consumer = MemoryMappedFile.OpenExisting(control.MapName, MemoryMappedFileRights.Read);
        using var view = consumer.CreateViewAccessor(0, SubtitleControl.Bytes, MemoryMappedFileAccess.Read);
        check(view.ReadUInt32(0) == SubtitleControl.Magic && view.ReadUInt32(4) == 1 &&
              (view.ReadUInt32(8) & 1u) == 0 && view.ReadUInt32(12) == 1,
              "Subtitle IPC starts with a complete versioned enabled snapshot");
        uint before = view.ReadUInt32(8);
        control.Publish(false);
        check(view.ReadUInt32(8) == before + 2 && (view.ReadUInt32(8) & 1u) == 0 && view.ReadUInt32(12) == 0,
              "Turning subtitles off publishes a complete disabled snapshot to the native mapping");
        control.Publish(true);
        check(view.ReadUInt32(12) == 1 && view.ReadUInt32(8) == before + 4,
              "Turning subtitles on restores the native mapping without changing the audio ABI");
    }
}
