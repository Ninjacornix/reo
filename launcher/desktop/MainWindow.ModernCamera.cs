namespace Outbreak.Launcher.Desktop;

// Controls > Modern camera: third-person camera options (launcher/ModernCamera.cs).
public partial class MainWindow {
    bool modernCameraUpdating;

    void InitializeModernCamera() {
        modernCameraUpdating = true;
        var o = settings.ModernCamera.Clamped();
        ModernCameraSwitch.IsChecked = o.Enabled;
        ModernCameraMouse.IsChecked = o.MouseLook;
        ModernCameraView.SelectedIndex = o.View == "first" ? 1 : 0;
        ModernCameraInvert.IsChecked = o.InvertY;
        ModernCameraCrosshair.IsChecked = o.Crosshair;
        ModernCameraMouseSensitivity.Value = o.MouseSensitivity;
        ModernCameraStickSpeed.Value = o.StickSpeed;
        ModernCameraDistance.Value = o.Distance;
        ModernCameraShoulder.Value = o.Shoulder;
        ModernCameraSide.SelectedIndex = o.ShoulderSide == "left" ? 1 : 0;
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
                     ModernCameraView, ModernCameraMouse, ModernCameraInvert, ModernCameraCrosshair, ModernCameraMouseSensitivity,
                     ModernCameraStickSpeed, ModernCameraDistance, ModernCameraShoulder, ModernCameraSide })
            control.IsEnabled = enabled;
        ModernCameraMouseSensitivity.IsEnabled = enabled && ModernCameraMouse.IsChecked == true;
        // Packaged launchers run the game from the local build cache; source layouts use Exe.
        string game = settings.Game.Id is "file2" ? "file2" : "file1";
        string built = LocalGameBuild.TargetPath(root, game);
        string exe = System.IO.File.Exists(built) ? built : game == "file2" ? settings.SecondExe : settings.Exe;
        bool supported = ModernCamera.Supported(exe);
        ModernCameraSupport.Text = supported ? ""
            : $"The installed {(game == "file2" ? "File #2" : "File #1")} build does not include the modern camera yet; the original camera is used.";
        ModernCameraSupport.IsVisible = !supported;
    }

    void SaveModernCamera() {
        settings.ModernCamera = new ModernCameraOptions {
            Enabled = ModernCameraSwitch.IsChecked == true,
            MouseLook = ModernCameraMouse.IsChecked == true,
            View = ModernCameraView.SelectedIndex == 1 ? "first" : "third",
            InvertY = ModernCameraInvert.IsChecked == true,
            Crosshair = ModernCameraCrosshair.IsChecked == true,
            MouseSensitivity = (int)Math.Round(ModernCameraMouseSensitivity.Value),
            StickSpeed = (int)Math.Round(ModernCameraStickSpeed.Value),
            Distance = (int)Math.Round(ModernCameraDistance.Value),
            Shoulder = (int)Math.Round(ModernCameraShoulder.Value),
            ShoulderSide = ModernCameraSide.SelectedIndex == 1 ? "left" : "right"
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

    void ModernCameraViewChanged(object? sender, SelectionChangedEventArgs e) {
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
