using System.Text.Json;

namespace Outbreak.Launcher;

internal static class AudioOutputTests {
    internal static void Run(Action<bool, string> check) {
        var legacy = JsonSerializer.Deserialize<Settings>("{}")!;
        check(legacy.AudioOutputId == "", "Older settings follow the Windows default audio output");
        var devices = new[] { new AudioOutput("headphones-id", "Headphones (USB)"),
            new AudioOutput("speakers-id", "Speakers (Čakovec 音声)"), new AudioOutput("headphones-id", "duplicate") };
        var choices = AudioOutputs.Choices(devices, "speakers-id", devices[1].Name);
        check(choices[0].Id == "" && choices.Count == 3 && choices.All(d => d.Available),
              "Output choices include Windows default and unique connected endpoints");
        var missing = AudioOutputs.Choices(Array.Empty<AudioOutput>(), "saved-id", "USB headset");
        check(missing.Count == 2 && missing[1].Id == "saved-id" && !missing[1].Available,
              "A disconnected saved output remains identifiable without discarding its preference");
        var settings = new Settings { AudioOutputId = "opaque-endpoint-id", AudioOutputName = devices[1].Name };
        var restored = JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(settings))!;
        check(restored.AudioOutputId == settings.AudioOutputId && restored.AudioOutputName == settings.AudioOutputName,
              "Opaque endpoint IDs and Unicode friendly names survive settings persistence");
    }
}
