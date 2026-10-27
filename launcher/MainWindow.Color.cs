using System.IO;
using System.Windows;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly DispatcherTimer colorSaveTimer = new() { Interval = TimeSpan.FromMilliseconds(250) };
    ColorPreviewEffect? colorEffect;
    static string PreviewPath => Path.Combine(Settings.Home, "room-preview.png");
    void InitializeColorPreview() {
        colorEffect = new();
        RoomPreview.Effect = colorEffect;
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
        bool room = false;
        if (File.Exists(PreviewPath)) {
            try {
                LoadPreview(PreviewPath);
                room = true;
            } catch (Exception error)
                when (error is IOException or NotSupportedException or FileFormatException) {
            }
        }
        if (!room) {
            // No capture from the player's own game: show the drawn calibration chart.
            RoomPreview.Source = CalibrationPreview.Create();
            PreviewEmpty.Visibility = Visibility.Collapsed;
        }
        UpdateColorPreview();
    }
    void LoadPreview(string path) {
        using var stream = File.OpenRead(path);
        var bitmap = new BitmapImage();
        bitmap.BeginInit();
        bitmap.CacheOption = BitmapCacheOption.OnLoad;
        bitmap.DecodePixelWidth = 900;
        bitmap.StreamSource = stream;
        bitmap.EndInit();
        bitmap.Freeze();
        RoomPreview.Source = bitmap;
        PreviewEmpty.Visibility = Visibility.Collapsed;
    }
    void UpdateColorPreview() {
        if (colorEffect == null)
            return;
        int brightness = (int)Math.Round(Brightness.Value);
        double gamma = Math.Round(Gamma.Value, 2);
        colorEffect.Gain = brightness / 100.0;
        colorEffect.Gamma = gamma;
        BrightnessValue.Text = $"{brightness}%";
        GammaValue.Text = gamma.ToString("F2");
    }
    void ColorChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
        if (!initialized)
            return;
        UpdateColorPreview();
        colorSaveTimer.Stop();
        colorSaveTimer.Start();
    }
    void ResetColor(object sender, RoutedEventArgs e) {
        Brightness.Value = 100;
        Gamma.Value = 1;
    }
}
