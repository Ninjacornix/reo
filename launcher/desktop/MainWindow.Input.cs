using Avalonia.Automation;
using Avalonia.Controls.Shapes;
using Avalonia.Media.Imaging;
using Path = System.IO.Path;

namespace Outbreak.Launcher.Desktop;

// Ports of RC1 MainWindow.Input.cs and MainWindow.ControllerMap.cs.
public partial class MainWindow {
    bool inputUiUpdating, captureArmed;
    string deviceFingerprint = "", displayedDevice = "", captureTarget = "";
    readonly Dictionary<string, Button> bindingButtons = new();
    readonly HashSet<Key> heldKeys = new();
    Dictionary<string, int> CurrentBindings => controller.SelectedDevice.Kind == "keyboard"
                                                   ? settings.Keyboard
                                                   : controller.Profile.Buttons;
    void InitializeInput() {
        // Capture before recording the held key, so a newly pressed key is not
        // mistaken for a repeat if routed-handler ordering changes.
        AddHandler(KeyDownEvent, (_, e) => {
            CaptureKey(this, e);
            // macOS and Linux forward play through the launcher's key table.
            ForwardKey(e, true);
        }, RoutingStrategies.Tunnel, handledEventsToo: true);
        AddHandler(KeyUpEvent, (_, e) => ForwardKey(e, false), RoutingStrategies.Tunnel, handledEventsToo: true);
        Deactivated += (_, _) => { heldKeys.Clear(); NativeControllers.ClearKeys(); };
        inputUiUpdating = true;
        RumbleSwitch.IsChecked = settings.RumbleEnabled;
        inputUiUpdating = false;
        controller.Poll();
        UpdateInputUi();
        ShowBindings(this, new());
    }
    void ForwardKey(KeyEventArgs e, bool down) {
        if (down) heldKeys.Add(e.Key); else heldKeys.Remove(e.Key);
        if (OperatingSystem.IsWindows()) return;
        int code = VirtualKey(e.Key);
        if (code != 0) NativeControllers.SetKey(code, down);
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
    void InputDeviceChanged(object? sender, SelectionChangedEventArgs e) {
        if (!initialized || inputUiUpdating ||
            InputDevicePicker.SelectedItem is not InputDevice device || !device.Available)
            return;
        controller.Select(device.Id);
        SaveInputPreferences();
        controller.Poll();
        UpdateInputUi();
    }
    void DeadZoneChanged(object? sender, Avalonia.Controls.Primitives.RangeBaseValueChangedEventArgs e) {
        if (!initialized || inputUiUpdating)
            return;
        controller.Profile.DeadZone = (int)e.NewValue;
        SaveInputPreferences();
    }
    void SaveInputOptions(object? sender, RoutedEventArgs e) {
        if (!initialized || inputUiUpdating)
            return;
        controller.Profile.SwapSticks = SwapSticks.IsChecked == true;
        controller.Profile.InvertRightY = InvertRightY.IsChecked == true;
        SaveInputPreferences();
    }
    void RumbleChanged(object? sender, RoutedEventArgs e) {
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
    void ShowInputLayout(object? sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        InputLayoutPanel.Visibility = Visibility.Visible;
        InputBindingsPanel.Visibility = Visibility.Collapsed;
        LayoutTab.BorderBrush = VisualPalette.Brush(Palette.Accent);
        BindingsTab.BorderBrush = VisualPalette.Brush(Palette.Text, Palette.Divider);
    }
    void ShowBindings(object? sender, RoutedEventArgs e) {
        InputLayoutPanel.Visibility = Visibility.Collapsed;
        InputBindingsPanel.Visibility = Visibility.Visible;
        BuildBindingRows();
        RefreshControllerArtwork();
        BindingsTab.BorderBrush = VisualPalette.Brush(Palette.Accent);
        LayoutTab.BorderBrush = VisualPalette.Brush(Palette.Text, Palette.Divider);
    }
    void BuildBindingRows() {
        BindingRows.Children.Clear();
        bindingButtons.Clear();
        bool diagram = BuildControllerMap();
        KeyboardStickBindings.Children.Clear();
        bool keyboard = controller.SelectedDevice.Kind == "keyboard";
        KeyboardStickBindingsPanel.Visibility = keyboard ? Visibility.Visible : Visibility.Collapsed;
        if (keyboard) foreach (var action in InputMapping.Camera) {
            var binding = CreateMapBinding(action.Id, action.Label);
            binding.Margin = new Thickness(0, 4, 14, 4);
            KeyboardStickBindings.Children.Add(binding);
        }
        if (diagram) { UpdateBindingFeedback(); return; }
        var rows = InputMapping.Actions.Select(a => (a.Id, a.Label)).ToList();
        foreach (var action in rows) {
            var row = new Grid { Margin = new Thickness(0, 4, 14, 4) };
            row.ColumnDefinitions.Add(new());
            row.ColumnDefinitions.Add(new() { Width = new GridLength(115) });
            row.ColumnDefinitions.Add(new() { Width = new GridLength(48) });
            row.Children.Add(new Rc1TextBlock { Text = action.Label,
                                             VerticalAlignment = VerticalAlignment.Center });
            var binding = new Button { Content = InputMapping.SourceName(
                                           CurrentBindings.GetValueOrDefault(action.Id),
                                           controller.SelectedDevice.Kind),
                                       Tag = action.Id, Padding = new Thickness(12, 7, 12, 7) };
            AutomationProperties.SetName(binding, action.Label + " binding");
            AutomationProperties.SetHelpText(binding, "Activate to remap this PS2 control.");
            binding.Click += StartBinding;
            bindingButtons[action.Id] = binding;
            Grid.SetColumn(binding, 1);
            row.Children.Add(binding);
            var clear =
                new Button { Content = "Clear", Tag = action.Id, Margin = new Thickness(7, 0, 0, 0),
                             Padding = new Thickness(6), FontSize = 11 };
            AutomationProperties.SetName(clear, "Clear " + action.Label + " binding");
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
            if (button.Classes.Contains("input-active") != active)
                button.Classes.Set("input-active", active);
        }
    }
    void StartBinding(object? sender, RoutedEventArgs e) {
        if (!controller.SelectedDevice.Available) {
            Status.Text = "Connect the selected input device first.";
            return;
        }
        captureTarget = (string)((Button)sender!).Tag!;
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
    void CaptureKey(object? sender, KeyEventArgs e) {
        bool repeat = heldKeys.Contains(e.Key);
        if (captureTarget.Length == 0 || controller.SelectedDevice.Kind != "keyboard" || repeat)
            return;
        int key = VirtualKey(e.Key);
        if (key <= 0 || key > 255)
            return;
        e.Handled = true;
        FinishBinding(key);
    }
    // Windows virtual-key codes, as stored by RC1 keyboard bindings.
    internal static int VirtualKey(Key key) {
        if (key is >= Key.A and <= Key.Z) return 'A' + (key - Key.A);
        if (key is >= Key.D0 and <= Key.D9) return '0' + (key - Key.D0);
        if (key is >= Key.NumPad0 and <= Key.NumPad9) return 0x60 + (key - Key.NumPad0);
        if (key is >= Key.F1 and <= Key.F24) return 0x70 + (key - Key.F1);
        return key switch {
            Key.Back => 8, Key.Tab => 9, Key.Enter => 13, Key.Pause => 19, Key.CapsLock => 20, Key.Escape => 27,
            Key.Space => 32, Key.PageUp => 33, Key.PageDown => 34, Key.End => 35, Key.Home => 36,
            Key.Left => 37, Key.Up => 38, Key.Right => 39, Key.Down => 40, Key.Insert => 45, Key.Delete => 46,
            Key.LeftShift => 160, Key.RightShift => 161, Key.LeftCtrl => 162, Key.RightCtrl => 163,
            Key.LeftAlt => 164, Key.RightAlt => 165,
            Key.Multiply => 106, Key.Add => 107, Key.Subtract => 109, Key.Decimal => 110, Key.Divide => 111,
            Key.OemSemicolon => 186, Key.OemPlus => 187, Key.OemComma => 188, Key.OemMinus => 189,
            Key.OemPeriod => 190, Key.OemQuestion => 191, Key.OemTilde => 192, Key.OemOpenBrackets => 219,
            Key.OemPipe => 220, Key.OemCloseBrackets => 221, Key.OemQuotes => 222, _ => 0
        };
    }
    void FinishBinding(int source) {
        string target = captureTarget;
        string[] cleared = controller.SelectedDevice.Kind == "keyboard"
            ? InputMapping.BindKeyboard(CurrentBindings, target, source) : Array.Empty<string>();
        if (controller.SelectedDevice.Kind != "keyboard") CurrentBindings[target] = source;
        CancelCapture(this, new());
        SaveInputPreferences();
        if (cleared.Length > 0) Status.Text = "Cleared previous keyboard binding: " + string.Join(", ",
            cleared.Select(id => InputMapping.Actions.FirstOrDefault(a => a.Id == id).Label ?? InputMapping.Camera.FirstOrDefault(a => a.Id == id).Label ?? id));
        if (bindingButtons.TryGetValue(target, out var binding)) binding.Focus();
    }
    void CancelCapture(object? sender, RoutedEventArgs e) {
        bool active = captureTarget.Length != 0;
        captureTarget = "";
        CaptureHint.Text = "";
        CapturePanel.Visibility = Visibility.Collapsed;
        if (active)
            BuildBindingRows();
    }
    void ResetBindings(object? sender, RoutedEventArgs e) {
        CancelCapture(sender, e);
        if (controller.SelectedDevice.Kind == "keyboard")
            settings.Keyboard = InputMapping.KeyboardDefaults();
        else
            controller.Profile.Buttons = InputMapping.PadDefaults();
        SaveInputPreferences();
        BuildBindingRows();
    }

    // ---- Controller map (RC1 MainWindow.ControllerMap.cs) ----
    IImage? controllerArtwork;
    string controllerArtworkRequest = "";
    readonly Dictionary<string, TextBlock> bindingValues = new();
    readonly Dictionary<string, Polyline> bindingLeaders = new();
    Image? diagramImage;
    // Centers of the visible button faces in the 172 x 116 crop, in pixel-edge
    // coordinates (pixel 0's center is .5). Both editions use the same geometry.
    // In particular L1/R1 are the lower grey shoulder faces, not the dark case below.
    static readonly Dictionary<string, Point> ControllerAnchors = new() {
        ["L2"] = new(36.5/172,7.5/116), ["L1"] = new(35.5/172,18.0/116),
        ["R2"] = new(129.0/172,7.5/116), ["R1"] = new(131.0/172,18.0/116),
        ["Up"] = new(34.0/172,49.5/116), ["Down"] = new(34.0/172,67.5/116),
        ["Left"] = new(24.5/172,58.0/116), ["Right"] = new(43.5/172,58.0/116),
        ["Triangle"] = new(131.0/172,45.0/116), ["Circle"] = new(146.0/172,59.0/116),
        ["Cross"] = new(131.5/172,72.0/116), ["Square"] = new(118.5/172,59.0/116),
        ["Select"] = new(68.0/172,58.5/116), ["Start"] = new(98.0/172,58.5/116),
        ["L3"] = new(60.5/172,86.5/116), ["R3"] = new(106.0/172,86.5/116)
    };
    async void RefreshControllerArtwork() {
        if (PageController.Visibility != Visibility.Visible) return;
        string edition = settings.Game.Id, import = settings.ImportFolder(edition);
        string request = edition + "|" + import + "|" + Settings.Home;
        if (request == controllerArtworkRequest) return;
        controllerArtworkRequest = request;
        try {
            var pixels = await Task.Run(() => GameControllerArtwork.LoadPixels(import, edition));
            if (controllerArtworkRequest != request || !IsLoaded) return;
            controllerArtwork = pixels == null ? null
                : ArtworkLoader.FromBgra(pixels, GameControllerArtwork.Width, GameControllerArtwork.Height);
        } catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or ArgumentException or NotSupportedException) {
            if (controllerArtworkRequest != request) return;
            controllerArtwork = null;
        }
        if (controllerArtworkRequest == request) BuildBindingRows();
    }
    Button CreateMapBinding(string id, string label) {
        var content = new StackPanel();
        content.Children.Add(new Rc1TextBlock { Text = label, FontSize = 14,
            VerticalAlignment = VerticalAlignment.Center,
            Foreground = VisualPalette.Brush(Palette.TextMuted) });
        var value = new Rc1TextBlock { Text = captureTarget == id ? "Waiting..." : InputMapping.SourceName(CurrentBindings.GetValueOrDefault(id), controller.SelectedDevice.Kind),
            FontSize = 16, VerticalAlignment = VerticalAlignment.Center,
            TextTrimming = TextTrimming.CharacterEllipsis, Margin = new Thickness(0, 2, 0, 0) };
        content.Children.Add(value); bindingValues[id] = value;
        var button = new Button { Tag = id, Content = content, Style = (Style)FindResource("ControllerBindingButton"),
            ToolTip = label + ": " + value.Text, Padding = new Thickness(8, 4, 8, 4),
            HorizontalContentAlignment = HorizontalAlignment.Left, MinHeight = 48 };
        AutomationProperties.SetName(button, label + " binding");
        AutomationProperties.SetHelpText(button, "Current input: " + value.Text + ". Activate to remap, or open the context menu to clear this binding.");
        button.Click += StartBinding;
        var menu = new ContextMenu();
        var clear = new MenuItem { Header = "Clear binding" };
        clear.Click += (_, _) => ClearBinding(id);
        menu.Items.Add(clear); button.ContextMenu = menu;
        bindingButtons[id] = button;
        return button;
    }
    bool BuildControllerMap() {
        bindingValues.Clear(); bindingLeaders.Clear();
        ControllerDiagram.Children.Clear();
        bool ready = controllerArtwork != null;
        ControllerDiagram.Visibility = ready ? Visibility.Visible : Visibility.Collapsed;
        ControllerArtworkHint.Visibility = ready ? Visibility.Collapsed : Visibility.Visible;
        BindingRows.Visibility = ready ? Visibility.Collapsed : Visibility.Visible;
        if (!ready) return false;
        // Preserve the same fractional geometry for the sprite and its line endpoints.
        diagramImage = new Image { Source = controllerArtwork, Stretch = Stretch.Fill, IsHitTestVisible = false, UseLayoutRounding = false };
        RenderOptions.SetBitmapInterpolationMode(diagramImage, BitmapInterpolationMode.HighQuality);
        ControllerDiagram.Children.Add(diagramImage);
        foreach (var action in InputMapping.Actions) {
            var leader = new Polyline { Stroke = VisualPalette.Brush(Palette.TextMuted, 120), StrokeThickness = 1,
                IsHitTestVisible = false, UseLayoutRounding = false };
            ControllerDiagram.Children.Add(leader); bindingLeaders[action.Id] = leader;
            ControllerDiagram.Children.Add(CreateMapBinding(action.Id, action.Label));
        }
        LayoutControllerDiagram();
        return true;
    }
    void ControllerDiagramSizeChanged(object? sender, SizeChangedEventArgs e) => LayoutControllerDiagram();
    void LayoutControllerDiagram() {
        if (controllerArtwork == null || diagramImage == null || ControllerDiagram.ActualWidth < 100) return;
        const double boxHeight = 48, sideWidth = 148, rowWidth = 140, gap = 12;
        double width = ControllerDiagram.ActualWidth, imageWidth = Math.Min(440, width - 328);
        if (imageWidth < 120) return;
        double imageHeight = imageWidth * 116 / 172, imageLeft = (width - imageWidth) / 2, top = 80;
        double bottom = Math.Max(top + imageHeight, 310) + 28;
        double height = bottom + boxHeight;
        if (Math.Abs(ControllerDiagram.Height - height) > 1) ControllerDiagram.Height = height;
        diagramImage.Width = imageWidth; diagramImage.Height = imageHeight;
        Canvas.SetLeft(diagramImage, imageLeft); Canvas.SetTop(diagramImage, top);
        var positions = new Dictionary<string, Point>();
        string[] left = { "Up", "Left", "Right", "Down" }, right = { "Triangle", "Square", "Circle", "Cross" };
        for (int i = 0; i < left.Length; i++) {
            positions[left[i]] = new(0, 100 + i * 54);
            positions[right[i]] = new(width - sideWidth, 100 + i * 54);
        }
        string[] upper = { "L1", "L2", "R2", "R1" }, lower = { "Select", "L3", "R3", "Start" };
        double rowLeft = (width - (rowWidth * 4 + gap * 3)) / 2;
        for (int i = 0; i < upper.Length; i++) {
            positions[upper[i]] = new(rowLeft + i * (rowWidth + gap), 0);
            positions[lower[i]] = new(rowLeft + i * (rowWidth + gap), bottom);
        }
        foreach (var action in InputMapping.Actions) {
            if (!bindingButtons.TryGetValue(action.Id, out var button)) continue;
            var anchor = ControllerAnchors[action.Id];
            var end = new Point(imageLeft + anchor.X * imageWidth, top + anchor.Y * imageHeight);
            bool onLeft = left.Contains(action.Id), onRight = right.Contains(action.Id);
            double boxWidth = onLeft || onRight ? sideWidth : rowWidth;
            var location = positions[action.Id];
            button.Width = boxWidth; button.Height = boxHeight;
            Canvas.SetLeft(button, location.X); Canvas.SetTop(button, location.Y);
            var start = onLeft ? new Point(location.X + boxWidth, location.Y + boxHeight / 2) :
                onRight ? new Point(location.X, location.Y + boxHeight / 2) :
                new Point(location.X + boxWidth / 2, location.Y + (upper.Contains(action.Id) ? boxHeight : 0));
            // Approach the inner D-pad button from below, keeping its line off the left target.
            bindingLeaders[action.Id].Points = action.Id == "Right"
                ? new Points { start, new(imageLeft - 8, start.Y), new(end.X, end.Y + 18), end }
                : new Points { start, end };
        }
    }
    void ClearBinding(string action) {
        CurrentBindings[action] = 0; CancelCapture(this, new()); SaveInputPreferences(); BuildBindingRows();
        if (bindingButtons.TryGetValue(action, out var binding)) binding.Focus();
    }
    void ClearCapturedBinding(object? sender, RoutedEventArgs e) { if (captureTarget.Length != 0) ClearBinding(captureTarget); }
}
