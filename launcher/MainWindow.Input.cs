using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool inputUiUpdating, captureArmed;
    string deviceFingerprint = "", displayedDevice = "", captureTarget = "";
    readonly Dictionary<string, Button> bindingButtons = new();
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
        string fingerprint = string.Join('|', devices.Select(d => d.Id)) + ":" + device.Id;
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
        RefreshControllerArtwork();
        LayoutTab.IsEnabled = !keyboard;
        if (keyboard && InputLayoutPanel.Visibility == Visibility.Visible)
            ShowBindings(this, new());
        StickSettings.Visibility = keyboard ? Visibility.Collapsed : Visibility.Visible;
        ControllerDetail.Text = "Reconnect this device, or select another.";
        ControllerDetail.Visibility = device.Available ? Visibility.Collapsed : Visibility.Visible;
        DeadZoneLabel.Text = $"Dead zone: {controller.Profile.DeadZone}%";
        LeftPlot.Update(controller.State, controller.Profile.DeadZone, false);
        RightPlot.Update(controller.State, controller.Profile.DeadZone, true);
        UpdateBindingFeedback();
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
        } catch (Exception error) when (error is System.IO.IOException or UnauthorizedAccessException) {
            Status.Text = "Could not save input settings: " + error.Message;
        }
        SessionSummary.Text = "GPU rendering / " + controller.SelectedDevice.Name;
    }
    void ShowInputLayout(object sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        InputLayoutPanel.Visibility = Visibility.Visible;
        InputBindingsPanel.Visibility = Visibility.Collapsed;
        LayoutTab.BorderBrush = Palette.Brush(Palette.Accent);
        BindingsTab.BorderBrush = Palette.Brush(Palette.Text, Palette.Divider);
    }
    void ShowBindings(object sender, RoutedEventArgs e) {
        InputLayoutPanel.Visibility = Visibility.Collapsed;
        InputBindingsPanel.Visibility = Visibility.Visible;
        BuildBindingRows();
        RefreshControllerArtwork();
        BindingsTab.BorderBrush = Palette.Brush(Palette.Accent);
        LayoutTab.BorderBrush = Palette.Brush(Palette.Text, Palette.Divider);
    }
    void BuildBindingRows() {
        BindingRows.Children.Clear();
        bindingButtons.Clear();
        if (BuildControllerMap()) { UpdateBindingFeedback(); return; }
        var rows = InputMapping.Actions.Select(a => (a.Id, a.Label)).ToList();
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
            System.Windows.Automation.AutomationProperties.SetName(binding, action.Label + " binding");
            System.Windows.Automation.AutomationProperties.SetHelpText(binding, "Activate to remap this PS2 control.");
            binding.Click += StartBinding;
            bindingButtons[action.Id] = binding;
            Grid.SetColumn(binding, 1);
            row.Children.Add(binding);
            var clear =
                new Button { Content = "Clear", Tag = action.Id, Margin = new Thickness(7, 0, 0, 0),
                             Padding = new Thickness(6), FontSize = 11 };
            System.Windows.Automation.AutomationProperties.SetName(clear, "Clear " + action.Label + " binding");
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
        UpdateBindingFeedback();
    }
    void UpdateBindingFeedback() {
        foreach (var (action, button) in bindingButtons) {
            bool active = controller.SelectedDevice.Available && captureTarget.Length == 0 &&
                          InputMapping.ActionPressed(controller.State, action);
            if (InputFeedback.GetIsActive(button) != active)
                InputFeedback.SetIsActive(button, active);
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
        foreach (var (action, button) in bindingButtons) {
            string text = captureTarget == action ? "Waiting..." : InputMapping.SourceName(CurrentBindings.GetValueOrDefault(action), controller.SelectedDevice.Kind);
            if (bindingValues.TryGetValue(action, out var value)) value.Text = text;
            else button.Content = text;
        }
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
        string target = captureTarget;
        CurrentBindings[target] = source;
        CancelCapture(this, new());
        SaveInputPreferences();
        if (bindingButtons.TryGetValue(target, out var binding)) binding.Focus();
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
