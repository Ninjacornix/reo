using System.IO;
using System.IO.MemoryMappedFiles;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;

public partial class MainWindow {
    async Task TestAudioUi(string output) {
        Directory.CreateDirectory(output);
        string settingsPath = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(settingsPath) ? File.ReadAllBytes(settingsPath) : null;
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        void Set(Slider slider, int level) => ((IRangeValueProvider)new SliderAutomationPeer(slider)
            .GetPattern(PatternInterface.RangeValue)!).SetValue(level);
        void Reset() => ((IInvokeProvider)new ButtonAutomationPeer(ResetAudioButton)
            .GetPattern(PatternInterface.Invoke)!).Invoke();
        void ToggleSubtitles() => ((IToggleProvider)new CheckBoxAutomationPeer(AudioSubtitles)
            .GetPattern(PatternInterface.Toggle)!).Toggle();
        void Key(Slider slider, System.Windows.Input.Key key) {
            slider.Focus();
            slider.RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this),
                Environment.TickCount, key) { RoutedEvent = Keyboard.KeyDownEvent });
        }
        void Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            if (AudioOutputPicker.IsDropDownOpen && AudioOutputPicker.Template.FindName("PART_Popup", AudioOutputPicker) is Popup { Child: FrameworkElement menu }) {
                var visual = new DrawingVisual();
                using (var drawing = visual.RenderOpen()) {
                    drawing.DrawImage(bitmap, new Rect(0, 0, ActualWidth, ActualHeight));
                    var position = AudioOutputPicker.TranslatePoint(new Point(0, AudioOutputPicker.ActualHeight), this);
                    var brush = new VisualBrush(menu) { ViewboxUnits = BrushMappingMode.Absolute,
                        Viewbox = new Rect(0, 0, menu.ActualWidth, menu.ActualHeight), Stretch = Stretch.Fill };
                    drawing.DrawRectangle(brush, null, new Rect(position.X, position.Y, menu.ActualWidth, menu.ActualHeight));
                }
                var combined = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
                combined.Render(visual);
                bitmap = combined;
            }
            var encoder = new PngBitmapEncoder();
            encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png"));
            encoder.Save(file);
        }
        try {
            timer.Stop();
            ShowPage("Audio");
            GamePicker.SelectedValue = "file1";
            await Task.Delay(500);
            var outputs = (IReadOnlyList<AudioOutput>)AudioOutputPicker.ItemsSource;
            await File.WriteAllTextAsync(Path.Combine(output, "audio-outputs.json"), JsonSerializer.Serialize(outputs));
            Check(outputs[0].Id == "" && AudioOutputPicker.IsEnabled,
                  "The output dropdown includes Windows default and can be used for either game");
            if (outputs.FirstOrDefault(d => d.Available && d.Id.Length != 0) is { } endpoint) {
                AudioOutputPicker.SelectedValue = endpoint.Id;
                await Task.Delay(100);
                var storedOutput = JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!;
                Check(storedOutput.AudioOutputId == endpoint.Id && storedOutput.AudioOutputName == endpoint.Name,
                      "Selecting a connected output persists its real Windows endpoint ID and friendly name");
                Capture("selected-output");
            }
            AudioOutputPicker.SelectedValue = "";
            AudioOutputPicker.IsDropDownOpen = true;
            await Task.Delay(200);
            Check(AudioOutputPicker.IsDropDownOpen && AudioOutputPicker.Items.Count == outputs.Count,
                  "Opening the native output dropdown refreshes and displays the current endpoints");
            Capture("output-devices");
            AudioOutputPicker.IsDropDownOpen = false;
            using var subtitleConsumer = MemoryMappedFile.OpenExisting(subtitleControl.MapName, MemoryMappedFileRights.Read);
            using var subtitleView = subtitleConsumer.CreateViewAccessor(0, SubtitleControl.Bytes, MemoryMappedFileAccess.Read);
            Check(AudioSubtitles.IsEnabled && AudioSubtitles.IsChecked == settings.ShowSubtitles &&
                  subtitleView.ReadUInt32(12) == (settings.ShowSubtitles ? 1u : 0u),
                  "Subtitles initializes from the saved preference and publishes it before game launch");
            if (AudioSubtitles.IsChecked != true) ToggleSubtitles();
            ToggleSubtitles();
            Check(!settings.ShowSubtitles && subtitleView.ReadUInt32(12) == 0 &&
                  !JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!.ShowSubtitles,
                  "The native Subtitles switch immediately publishes and persists the disabled preference");
            Capture("subtitles-off");
            ToggleSubtitles();
            Check(settings.ShowSubtitles && subtitleView.ReadUInt32(12) == 1,
                  "The native Subtitles switch restores captions immediately");
            Check(MasterVolume.IsEnabled && MusicVolume.IsEnabled && SfxVolume.IsEnabled &&
                  VoiceVolume.IsEnabled && UiVolume.IsEnabled,
                  "File #1 exposes all five real mixer controls");
            // Output/subtitle actions above intentionally report saved settings.
            // Clear that toast before testing silent mixer-only adjustments.
            HideStatusToast(); await Task.Delay(350);
            Set(MasterVolume, 68); Set(MusicVolume, 42); Set(SfxVolume, 84); Set(VoiceVolume, 100); Set(UiVolume, 58);
            await Task.Delay(400);
            Check(AudioLevels.From(settings) == new AudioLevels(68, 42, 84, 100, 58) &&
                  MasterVolumeValue.Text == "68%" && MusicVolumeValue.Text == "42%",
                  "Accessible sliders update the displayed values and real settings");
            using var consumer = MemoryMappedFile.OpenExisting(audioMixer.MapName, MemoryMappedFileRights.Read);
            using var view = consumer.CreateViewAccessor(0, AudioMixer.Bytes, MemoryMappedFileAccess.Read);
            Check(new[] { 68, 42, 84, 100, 58 }.Select((value, index) => view.ReadInt32(12 + index * 4) == value).All(value => value),
                  "The redesigned controls publish the correct levels to the native audio mapping");
            var persisted = JsonSerializer.Deserialize<Settings>(File.ReadAllText(settingsPath))!;
            Check(AudioLevels.From(persisted) == new AudioLevels(68, 42, 84, 100, 58),
                  "Debounced volume changes are saved to disk");
            Check(StatusToast.Visibility == Visibility.Collapsed,
                  "Routine audio adjustment saves without a toast obscuring the page");
            Capture("file1-balanced");
            Key(MasterVolume, System.Windows.Input.Key.Right);
            Check(MasterVolume.Value == 69 && MasterVolume.IsKeyboardFocusWithin &&
                  ((Border)MasterVolume.Template.FindName("AudioSliderFocus", MasterVolume)).Visibility == Visibility.Visible,
                  "Native arrow keys adjust the Master slider and show keyboard focus");
            Capture("keyboard-focus");
            Set(MasterVolume, 0);
            await Task.Delay(100);
            Check(MasterVolumeValue.Text == "0%" && view.ReadInt32(12) == 0 && MusicVolume.Value == 42 && SfxVolume.Value == 84,
                  "Master mute publishes zero while preserving the individual channel balance");
            Capture("muted");
            Reset();
            await Task.Delay(400);
            Check(AudioLevels.From(settings) == new AudioLevels(100, 100, 100, 100, 100),
                  "File #1 reset restores all five channels");
            Set(MusicVolume, 17);
            GamePicker.SelectedValue = "file2";
            await Task.Delay(350);
            Check(MasterVolume.IsEnabled && MusicVolume.IsEnabled && SfxVolume.IsEnabled &&
                  VoiceVolume.IsEnabled && UiVolume.IsEnabled && AudioChannels.Opacity == 1 &&
                  AudioChannelNote.Text == "VOLUME BALANCE",
                  "File #2 exposes all five volume controls at full opacity");
            Check(AudioSubtitles.IsEnabled, "Subtitles remains independent of File #2 audio channel levels");
            ToggleSubtitles();
            Check(!settings.ShowSubtitles && subtitleView.ReadUInt32(12) == 0,
                  "File #2 can publish the hidden-subtitles preference through the same native control");
            Set(MusicVolume, 0); Set(SfxVolume, 23); Set(VoiceVolume, 37); Set(UiVolume, 61);
            await Task.Delay(400);
            Check(settings.MusicVolume == 0 && settings.SfxVolume == 23 && settings.VoiceVolume == 37 && settings.UiVolume == 61 &&
                  view.ReadInt32(16) == 0 && view.ReadInt32(20) == 23 && view.ReadInt32(24) == 37 && view.ReadInt32(28) == 61,
                  "File #2 native slider automation publishes independent channel levels immediately through real IPC");
            Set(MasterVolume, 40);
            Reset();
            await Task.Delay(400);
            Check(AudioLevels.From(settings) == new AudioLevels(100,100,100,100,100) && !settings.ShowSubtitles,
                  "File #2 reset restores all five channels while preserving the subtitle preference");
            ToggleSubtitles();
            NavAudio.Focus();
            Capture("file2-channels");
            Width = MinWidth; Height = MinHeight;
            await Task.Delay(300);
            SettingsScroll.ScrollToEnd();
            await Task.Delay(200);
            var resetPosition = ResetAudioButton.TranslatePoint(new Point(), SettingsScroll);
            var subtitlePosition = AudioSubtitles.TranslatePoint(new Point(), SettingsScroll);
            Check(PageAudio.ActualWidth <= SettingsScroll.ViewportWidth + 1 && SettingsScroll.ScrollableHeight <= 1 && resetPosition.Y >= 0 &&
                  resetPosition.Y + ResetAudioButton.ActualHeight <= SettingsScroll.ViewportHeight + 1 &&
                  subtitlePosition.Y >= 0 && subtitlePosition.Y + AudioSubtitles.ActualHeight <= SettingsScroll.ViewportHeight + 1 && GamePicker.IsVisible,
                  "All audio controls, Subtitles and Reset fit at minimum window size without scrolling above the fixed DVD footer");
            Capture("compact-file2");
            GamePicker.SelectedValue = "file1";
            SettingsScroll.ScrollToTop();
            await Task.Delay(300);
            Check(MusicVolume.IsEnabled && MusicVolume.Value == 100 && AudioChannels.Opacity == 1,
                  "Both games retain the same saved audio balance and enabled channel controls");
            Capture("compact-file1");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            audioSaveTimer.Stop();
            if (saved == null) File.Delete(settingsPath); else File.WriteAllBytes(settingsPath, saved);
            Close();
        }
    }
}
