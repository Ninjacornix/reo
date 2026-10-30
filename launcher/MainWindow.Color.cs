using System.Windows;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly DispatcherTimer colorSaveTimer = new() { Interval = TimeSpan.FromMilliseconds(250) };
    void InitializeColorPreview() {
        colorSaveTimer.Tick += (_, _) => {
            colorSaveTimer.Stop();
            SaveSettings(this, new());
        };
        Closed += (_, _) => colorSaveTimer.Stop();
        Closing += (_, _) => {
            if (colorSaveTimer.IsEnabled) {
                colorSaveTimer.Stop();
                SaveSettings(this, new());
            }
        };
        UpdateColorPreview();
    }
    void UpdateColorPreview() {
        int brightness = (int)Math.Round(Brightness.Value);
        double gamma = Math.Round(Gamma.Value, 2);
        BrightnessValue.Text = $"{brightness}%";
        GammaValue.Text = gamma.ToString("F2");
    }
    void ColorChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
        if (!initialized)
            return;
        UpdateColorPreview();
        InvalidateGraphicsPreview();
        colorSaveTimer.Stop();
        colorSaveTimer.Start();
    }
    void ResetColor(object sender, RoutedEventArgs e) {
        Brightness.Value = 100;
        Gamma.Value = 1;
    }
}
