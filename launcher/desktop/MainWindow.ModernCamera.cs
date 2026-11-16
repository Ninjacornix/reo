namespace Outbreak.Launcher.Desktop;

// Controls > Modern camera: third-person camera options (launcher/ModernCamera.cs).
public partial class MainWindow {
    bool modernCameraUpdating;

    void InitializeModernCamera() {
        modernCameraUpdating = true;
        var o = settings.ModernCamera.Clamped();
        ModernCameraSwitch.IsChecked = o.Enabled;
        ModernCameraMouse.IsChecked = o.MouseLook;
        ModernCameraInvert.IsChecked = o.InvertY;
        ModernCameraMouseSensitivity.Value = o.MouseSensitivity;
        ModernCameraStickSpeed.Value = o.StickSpeed;
        ModernCameraDistance.Value = o.Distance;
        ModernCameraShoulder.Value = o.Shoulder;
        modernCameraUpdating = false;
        UpdateModernCameraLabels();
    }

    void UpdateModernCameraLabels() {
        ModernCameraMouseLabel.Text = $"Mouse sensitivity: {(int)ModernCameraMouseSensitivity.Value}%";
        ModernCameraStickLabel.Text = $"Stick look speed: {(int)ModernCameraStickSpeed.Value}%";
        ModernCameraDistanceLabel.Text = $"Distance: {(int)ModernCameraDistance.Value}";
        ModernCameraShoulderLabel.Text = $"Shoulder offset: {(int)ModernCameraShoulder.Value}";
        bool enabled = ModernCameraSwitch.IsChecked == true;
        foreach (var control in new Avalonia.Controls.Control[] {
                     ModernCameraMouse, ModernCameraInvert, ModernCameraMouseSensitivity,
                     ModernCameraStickSpeed, ModernCameraDistance, ModernCameraShoulder })
            control.IsEnabled = enabled;
        ModernCameraMouseSensitivity.IsEnabled = enabled && ModernCameraMouse.IsChecked == true;
        string exe = settings.Exe;
        ModernCameraSupport.Text = ModernCamera.Supported(exe)
            ? "The installed File #1 build supports the modern camera."
            : "The installed File #1 build does not include the native camera yet; the original camera is used until the game is rebuilt with it.";
    }

    void SaveModernCamera() {
        settings.ModernCamera = new ModernCameraOptions {
            Enabled = ModernCameraSwitch.IsChecked == true,
            MouseLook = ModernCameraMouse.IsChecked == true,
            InvertY = ModernCameraInvert.IsChecked == true,
            MouseSensitivity = (int)Math.Round(ModernCameraMouseSensitivity.Value),
            StickSpeed = (int)Math.Round(ModernCameraStickSpeed.Value),
            Distance = (int)Math.Round(ModernCameraDistance.Value),
            Shoulder = (int)Math.Round(ModernCameraShoulder.Value)
        }.Clamped();
        SaveInputPreferences();
    }

    void ModernCameraChanged(object? sender, RoutedEventArgs e) {
        if (!initialized || modernCameraUpdating) return;
        UpdateModernCameraLabels();
        SaveModernCamera();
    }

    void ModernCameraSliderChanged(object? sender, Avalonia.Controls.Primitives.RangeBaseValueChangedEventArgs e) {
        if (!initialized || modernCameraUpdating) return;
        UpdateModernCameraLabels();
        SaveModernCamera();
    }

    void ResetModernCamera(object? sender, RoutedEventArgs e) {
        bool enabled = settings.ModernCamera.Enabled;
        settings.ModernCamera = new ModernCameraOptions { Enabled = enabled };
        InitializeModernCamera();
        SaveInputPreferences();
    }

    void ShowModernCamera(object? sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        InputBindingsPanel.Visibility = Visibility.Collapsed;
        InputLayoutPanel.Visibility = Visibility.Collapsed;
        ModernCameraPanel.Visibility = Visibility.Visible;
        ModernCameraTab.BorderBrush = VisualPalette.Brush(Palette.Accent);
        BindingsTab.BorderBrush = VisualPalette.Brush(Palette.Text, Palette.Divider);
        LayoutTab.BorderBrush = VisualPalette.Brush(Palette.Text, Palette.Divider);
        UpdateModernCameraLabels();
    }
}
