using Avalonia.Controls.Primitives;

namespace Outbreak.Launcher.Desktop;

// WPF view services RC1 handlers use: FindName, FindResource and the few events WPF wires in XAML
// that Avalonia exposes only as routed events.
public partial class MainWindow {
    new object FindName(string name) => this.FindNameScope()?.Find(name) ?? throw new KeyNotFoundException(name);
    static readonly HashSet<string> StyleKeys = new(StringComparer.Ordinal) {
        "Hint", "ModOption", "CheatOption", "ModOptionsDropdown", "ControllerBindingButton", "Section",
        "CoopGameChoice", "CoopStatus", "CoopTextInput", "GameFilePath", "PrimaryButton", "LaunchLabel", "LaunchValue",
        "ToggleSwitch", "GraphicsChoice", "AudioSlider", "NavButton", "ModeChoice", "GameChoice", "DiscChoice",
        "CaseNumber", "CaseBlurb" };
    object FindResource(string name) =>
        StyleKeys.Contains(name) ? new Style(name)
        : this.TryFindResource(name, ActualThemeVariant, out var value) && value != null ? value
        : throw new KeyNotFoundException(name);
    double ActualWidth => Bounds.Width;
    double ActualHeight => Bounds.Height;
    TranslateTransform StatusToastOffset => (TranslateTransform)StatusToast.RenderTransform!;
    void InitializeViewEvents() {
        GameCasePicker.AddHandler(RequestBringIntoViewEvent, KeepPlayViewport, handledEventsToo: true);
    }
}
