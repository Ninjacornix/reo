namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.Audio.cs. Windows publishes through RC1's shared-memory mixer;
// macOS and Linux publish the same values through the session's live-settings file.
public partial class MainWindow {
    readonly AudioMixer? audioMixer = OperatingSystem.IsWindows() ? new() : null;
    readonly SubtitleControl? subtitleControl = OperatingSystem.IsWindows() ? new() : null;
    // RC1 passes the mixer as sender so audio saves stay silent; this marks the same saves.
    readonly object audioSender = new();
    readonly DispatcherTimer audioSaveTimer = new() { Interval = TimeSpan.FromMilliseconds(250) };
    bool refreshingAudioOutputs;

    void InitializeAudio() {
        var levels = AudioLevels.From(settings);
        MasterVolume.Value = levels.Master; MusicVolume.Value = levels.Music;
        SfxVolume.Value = levels.Sfx; VoiceVolume.Value = levels.Voice; UiVolume.Value = levels.Ui;
        AudioSubtitles.IsChecked = settings.ShowSubtitles;
        UpdateAudioLabels();
        if (audioMixer != null) {
            game.AudioMapName = audioMixer.MapName;
            audioMixer.Publish(settings);
        }
        if (subtitleControl != null) {
            game.SubtitleMapName = subtitleControl.MapName;
            subtitleControl.Publish(settings.ShowSubtitles);
        }
        RefreshAudioOutputs();
        audioSaveTimer.Tick += (_, _) => { audioSaveTimer.Stop(); SaveSettings(audioSender, new()); };
        SizeChanged += (_, _) => UpdateAudioLayout();
        UpdateAudioLayout();
        Closing += (_, _) => {
            if (audioSaveTimer.IsEnabled) { audioSaveTimer.Stop(); SaveSettings(audioSender, new()); }
        };
        Closed += (_, _) => { audioSaveTimer.Stop(); audioMixer?.Dispose(); subtitleControl?.Dispose(); };
    }
    void PublishLiveSettings() {
        if (OperatingSystem.IsWindows() || !game.Running || game.Logs is not { } logs) return;
        try { PlatformRuntime.PublishLive(logs, settings); }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            System.Diagnostics.Debug.WriteLine(error.Message);
        }
    }
    void UpdateAudioLayout() {
        bool compact = (ActualHeight > 0 ? ActualHeight : Height) < 760;
        AudioMasterRow.Height = compact ? 42 : 56;
        foreach (var row in AudioChannels.Children.OfType<Grid>()) row.Height = compact ? 42 : 56;
        AudioSubtitlesRow.Height = compact ? 40 : 48;
        AudioFooterDivider.Margin = new Thickness(0, compact ? 4 : 8, 0, compact ? 8 : 14);
    }
    void UpdateAudioLabels() {
        MasterVolumeValue.Text = $"{MasterVolume.Value:0}%";
        MusicVolumeValue.Text = $"{MusicVolume.Value:0}%";
        SfxVolumeValue.Text = $"{SfxVolume.Value:0}%";
        VoiceVolumeValue.Text = $"{VoiceVolume.Value:0}%";
        UiVolumeValue.Text = $"{UiVolume.Value:0}%";
    }
    void UpdateAudioAvailability() {
        AudioEditionLabel.Text = settings.Game.Id == "file1" ? "OUTBREAK / FILE #1" : "OUTBREAK / FILE #2";
        AudioChannelNote.Text = "VOLUME BALANCE";
        AudioChannels.Opacity = 1;
        foreach (var slider in new[] { MusicVolume, SfxVolume, VoiceVolume, UiVolume }) {
            slider.IsEnabled = true;
            slider.ToolTip = null;
        }
    }
    void RefreshAudioOutputs() {
        refreshingAudioOutputs = true;
        try {
            AudioOutputPicker.ItemsSource = OperatingSystem.IsWindows()
                ? AudioOutputs.Choices(AudioOutputs.Enumerate(), settings.AudioOutputId ?? "", settings.AudioOutputName ?? "")
                : new[] { new AudioOutput("", "System default") };
            AudioOutputPicker.SelectedValue = OperatingSystem.IsWindows() ? settings.AudioOutputId ?? "" : "";
            UpdateAudioOutputHint();
        } finally { refreshingAudioOutputs = false; }
    }
    void UpdateAudioOutputHint() {
        bool unavailable = AudioOutputPicker.SelectedItem is AudioOutput { Available: false };
        AudioOutputHint.Text = unavailable ? $"Output unavailable. The game will use {PlatformText.SystemName} default." : "";
        AudioOutputHint.Visibility = unavailable ? Visibility.Visible : Visibility.Collapsed;
    }
    void AudioOutputOpened(object? sender, EventArgs e) => RefreshAudioOutputs();
    void AudioOutputChanged(object? sender, SelectionChangedEventArgs e) {
        if (!initialized || refreshingAudioOutputs || AudioOutputPicker.SelectedItem is not AudioOutput output) return;
        if (!OperatingSystem.IsWindows()) return;
        settings.AudioOutputId = output.Id;
        if (output.Available) settings.AudioOutputName = output.Name;
        UpdateAudioOutputHint();
        SaveSettings(audioSender, new());
    }
    void ReadAudioSettings() {
        settings.ShowSubtitles = AudioSubtitles.IsChecked == true;
        settings.MasterVolume = (int)Math.Round(MasterVolume.Value);
        settings.MusicVolume = (int)Math.Round(MusicVolume.Value);
        settings.SfxVolume = (int)Math.Round(SfxVolume.Value);
        settings.VoiceVolume = (int)Math.Round(VoiceVolume.Value);
        settings.UiVolume = (int)Math.Round(UiVolume.Value);
    }
    void SubtitlesChanged(object? sender, RoutedEventArgs e) {
        if (!initialized) return;
        settings.ShowSubtitles = AudioSubtitles.IsChecked == true;
        subtitleControl?.Publish(settings.ShowSubtitles);
        PublishLiveSettings();
        SaveSettings(audioSender, new());
    }
    void AudioChanged(object? sender, Avalonia.Controls.Primitives.RangeBaseValueChangedEventArgs e) {
        if (!initialized) return;
        UpdateAudioLabels(); ReadAudioSettings(); audioMixer?.Publish(settings); PublishLiveSettings();
        audioSaveTimer.Stop(); audioSaveTimer.Start();
    }
    void ResetAudio(object? sender, RoutedEventArgs e) {
        MasterVolume.Value = 100;
        MusicVolume.Value = SfxVolume.Value = VoiceVolume.Value = UiVolume.Value = 100;
    }
}
