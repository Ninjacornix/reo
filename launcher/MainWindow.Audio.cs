using System.Windows;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly AudioMixer audioMixer = new();
    readonly DispatcherTimer audioSaveTimer = new() { Interval = TimeSpan.FromMilliseconds(250) };

    void InitializeAudio() {
        var levels = AudioLevels.From(settings);
        MasterVolume.Value = levels.Master; MusicVolume.Value = levels.Music;
        SfxVolume.Value = levels.Sfx; VoiceVolume.Value = levels.Voice; UiVolume.Value = levels.Ui;
        UpdateAudioLabels();
        game.AudioMapName = audioMixer.MapName;
        audioMixer.Publish(settings);
        audioSaveTimer.Tick += (_, _) => { audioSaveTimer.Stop(); SaveSettings(this, new()); };
        Closing += (_, _) => {
            if (audioSaveTimer.IsEnabled) { audioSaveTimer.Stop(); SaveSettings(this, new()); }
        };
        Closed += (_, _) => { audioSaveTimer.Stop(); audioMixer.Dispose(); };
    }
    void UpdateAudioLabels() {
        MasterVolumeValue.Text = $"{MasterVolume.Value:0}%";
        MusicVolumeValue.Text = $"{MusicVolume.Value:0}%";
        SfxVolumeValue.Text = $"{SfxVolume.Value:0}%";
        VoiceVolumeValue.Text = $"{VoiceVolume.Value:0}%";
        UiVolumeValue.Text = $"{UiVolume.Value:0}%";
    }
    void UpdateAudioAvailability() {
        bool separateChannels = settings.Game.Id == "file1";
        foreach (var slider in new[] { MusicVolume, SfxVolume, VoiceVolume, UiVolume }) {
            slider.IsEnabled = separateChannels;
            slider.ToolTip = separateChannels ? null
                : "Separate music, effects, voice and UI volumes are available for File #1. Use Master for File #2.";
        }
    }
    void ReadAudioSettings() {
        settings.MasterVolume = (int)Math.Round(MasterVolume.Value);
        settings.MusicVolume = (int)Math.Round(MusicVolume.Value);
        settings.SfxVolume = (int)Math.Round(SfxVolume.Value);
        settings.VoiceVolume = (int)Math.Round(VoiceVolume.Value);
        settings.UiVolume = (int)Math.Round(UiVolume.Value);
    }
    void AudioChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
        if (!initialized) return;
        UpdateAudioLabels(); ReadAudioSettings(); audioMixer.Publish(settings);
        audioSaveTimer.Stop(); audioSaveTimer.Start();
    }
    void ResetAudio(object sender, RoutedEventArgs e) {
        MasterVolume.Value = 100;
        if (settings.Game.Id == "file1")
            MusicVolume.Value = SfxVolume.Value = VoiceVolume.Value = UiVolume.Value = 100;
    }
}
