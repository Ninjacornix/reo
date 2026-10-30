using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool inputUiUpdating, captureArmed;
    string deviceFingerprint = "", displayedDevice = "", captureTarget = "";
    Dictionary<string, int> CurrentBindings => controller.SelectedDevice.Kind == "keyboard"
                                                   ? settings.Keyboard
                                                   : controller.Profile.Buttons;
    void InitializeInput() {
        PreviewKeyDown += CaptureKey;
        inputUiUpdating = true;
        RumbleSwitch.IsChecked = settings.RumbleEnabled;
        inputUiUpdating = false;
        controller.Poll();
        UpdateInputUi();
        ShowBindings(this, new());
    }
    void UpdateInputUi() {
        var device = controller.SelectedDevice;
        var devices = controller.AvailableDevices.ToList();
        if (!device.Available)
            devices.Add(device);
        string fingerprint = string.Join('|', devices.Select(d => d.Id + ":" + d.Name)) + ":" + device.Id;
        if (fingerprint != deviceFingerprint) {
            deviceFingerprint = fingerprint;
            inputUiUpdating = true;
            InputDevicePicker.ItemsSource = devices;
            InputDevicePicker.SelectedItem = devices.FirstOrDefault(d => d.Id == device.Id);
            inputUiUpdating = false;
        }
        if (displayedDevice != device.Id) {
            displayedDevice = device.Id;
            CancelCapture(this, new());
            inputUiUpdating = true;
            DeadZone.Value = controller.Profile.DeadZone;
            SwapSticks.IsChecked = controller.Profile.SwapSticks;
            InvertRightY.IsChecked = controller.Profile.InvertRightY;
            inputUiUpdating = false;
            BuildBindingRows();
        }
        bool keyboard = device.Kind == "keyboard";
        LayoutTab.IsEnabled = !keyboard;
        if (keyboard && InputLayoutPanel.Visibility == Visibility.Visible)
            ShowBindings(this, new());
        StickSettings.Visibility = keyboard ? Visibility.Collapsed : Visibility.Visible;
        ControllerDetail.Text = "Reconnect this device, or select another.";
        ControllerDetail.Visibility = device.Available ? Visibility.Collapsed : Visibility.Visible;
        PadBadge.Content = device.Available ? device.Name : "Input device disconnected";
        DeadZoneLabel.Text = $"Dead zone: {controller.Profile.DeadZone}%";
        LeftPlot.Update(controller.RawState, controller.State, controller.Profile.DeadZone, false);
        RightPlot.Update(controller.RawState, controller.State, controller.Profile.DeadZone, true);
        if (captureTarget.Length != 0 && !keyboard) {
            var pressed = InputMapping.Pressed(controller.RawState);
            if (pressed.Count == 0)
                captureArmed = true;
            else if (captureArmed)
                FinishBinding(pressed.Order().First());
        }
    }
    void InputDeviceChanged(object sender, SelectionChangedEventArgs e) {
        if (!initialized || inputUiUpdating ||
            InputDevicePicker.SelectedItem is not InputDevice device || !device.Available)
            return;
        controller.Select(device.Id);
        SaveInputPreferences();
        controller.Poll();
        UpdateInputUi();
    }
    void DeadZoneChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
        if (!initialized || inputUiUpdating)
            return;
        controller.Profile.DeadZone = (int)e.NewValue;
        SaveInputPreferences();
    }
    void SaveInputOptions(object sender, RoutedEventArgs e) {
        if (!initialized || inputUiUpdating)
            return;
        controller.Profile.SwapSticks = SwapSticks.IsChecked == true;
        controller.Profile.InvertRightY = InvertRightY.IsChecked == true;
        SaveInputPreferences();
    }
    void RumbleChanged(object sender, RoutedEventArgs e) {
        if (!initialized || inputUiUpdating)
            return;
        settings.RumbleEnabled = RumbleSwitch.IsChecked == true;
        controller.Publish();
        SaveInputPreferences();
    }
    void SaveInputPreferences() {
        try {
            settings.Save();
            Status.Text = "Input settings saved";
        } catch (System.IO.IOException error) {
            Status.Text = "Could not save input settings: " + error.Message;
        }
        SessionSummary.Text = "GPU rendering / " + controller.SelectedDevice.Name;
    }
    void ShowInputLayout(object sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        InputLayoutPanel.Visibility = Visibility.Visible;
        InputBindingsPanel.Visibility = Visibility.Collapsed;
        LayoutTab.BorderBrush = new SolidColorBrush(Color.FromRgb(161, 75, 77));
        BindingsTab.BorderBrush = new SolidColorBrush(Color.FromRgb(52, 61, 62));
    }
    void ShowBindings(object sender, RoutedEventArgs e) {
        InputLayoutPanel.Visibility = Visibility.Collapsed;
        InputBindingsPanel.Visibility = Visibility.Visible;
        BuildBindingRows();
        BindingsTab.BorderBrush = new SolidColorBrush(Color.FromRgb(161, 75, 77));
        LayoutTab.BorderBrush = new SolidColorBrush(Color.FromRgb(52, 61, 62));
    }
    void BuildBindingRows() {
        BindingRows.Children.Clear();
        var rows = InputMapping.Actions.Select(a => (a.Id, a.Label)).ToList();
        if (controller.SelectedDevice.Kind == "keyboard")
            rows.AddRange(InputMapping.Camera);
        foreach (var action in rows) {
            var row = new Grid { Margin = new Thickness(0, 4, 14, 4) };
            row.ColumnDefinitions.Add(new());
            row.ColumnDefinitions.Add(new() { Width = new GridLength(115) });
            row.ColumnDefinitions.Add(new() { Width = new GridLength(48) });
            row.Children.Add(new TextBlock { Text = action.Label,
                                             VerticalAlignment = VerticalAlignment.Center });
            var binding = new Button { Content = InputMapping.SourceName(
                                           CurrentBindings.GetValueOrDefault(action.Id),
                                           controller.SelectedDevice.Kind),
                                       Tag = action.Id, Padding = new Thickness(12, 7, 12, 7) };
            binding.Click += StartBinding;
            Grid.SetColumn(binding, 1);
            row.Children.Add(binding);
            var clear =
                new Button { Content = "Clear", Tag = action.Id, Margin = new Thickness(7, 0, 0, 0),
                             Padding = new Thickness(6), FontSize = 11 };
            clear.Click += (_, _) => {
                CurrentBindings[action.Id] = 0;
                CancelCapture(this, new());
                SaveInputPreferences();
                BuildBindingRows();
            };
            Grid.SetColumn(clear, 2);
            row.Children.Add(clear);
            BindingRows.Children.Add(row);
        }
    }
    void StartBinding(object sender, RoutedEventArgs e) {
        if (!controller.SelectedDevice.Available) {
            Status.Text = "Connect the selected input device first.";
            return;
        }
        captureTarget = (string)((Button)sender).Tag;
        captureArmed = InputMapping.Pressed(controller.RawState).Count == 0;
        string target = InputMapping.Actions.FirstOrDefault(a => a.Id == captureTarget).Label ??
                        InputMapping.Camera.First(a => a.Id == captureTarget).Label;
        CaptureHint.Text =
            controller.SelectedDevice.Kind == "keyboard"
                ? $"{target}: press a key."
                : $"{target}: release held controls, then press a button or trigger.";
        CapturePanel.Visibility = Visibility.Visible;
        ((Button)sender).Content = "Waiting…";
    }
    void CaptureKey(object sender, KeyEventArgs e) {
        if (captureTarget.Length == 0 || controller.SelectedDevice.Kind != "keyboard" || e.IsRepeat)
            return;
        int key = KeyInterop.VirtualKeyFromKey(e.Key == Key.System ? e.SystemKey : e.Key);
        if (key <= 0 || key > 255)
            return;
        e.Handled = true;
        FinishBinding(key);
    }
    void FinishBinding(int source) {
        CurrentBindings[captureTarget] = source;
        CancelCapture(this, new());
        SaveInputPreferences();
        BuildBindingRows();
    }
    void CancelCapture(object sender, RoutedEventArgs e) {
        bool active = captureTarget.Length != 0;
        captureTarget = "";
        CaptureHint.Text = "";
        CapturePanel.Visibility = Visibility.Collapsed;
        if (active)
            BuildBindingRows();
    }
    void ResetBindings(object sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        if (controller.SelectedDevice.Kind == "keyboard")
            settings.Keyboard = InputMapping.KeyboardDefaults();
        else
            controller.Profile.Buttons = InputMapping.PadDefaults();
        SaveInputPreferences();
        BuildBindingRows();
    }
}
