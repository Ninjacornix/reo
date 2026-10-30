using System.IO;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Outbreak.Launcher;
public partial class MainWindow {
    BitmapSource? controllerArtwork;
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
            var artwork = await Task.Run(() => GameControllerArtwork.Load(import, edition, Settings.Home));
            if (controllerArtworkRequest != request || !IsLoaded) return;
            controllerArtwork = artwork;
        } catch (Exception error) when (error is IOException or InvalidDataException or UnauthorizedAccessException or ArgumentException or NotSupportedException) {
            if (controllerArtworkRequest != request) return;
            controllerArtwork = null;
        }
        if (controllerArtworkRequest == request) BuildBindingRows();
    }
    Button CreateMapBinding(string id, string label) {
        var content = new StackPanel();
        content.Children.Add(new TextBlock { Text = label, FontSize = 14,
            VerticalAlignment = VerticalAlignment.Center,
            Foreground = Palette.Brush(Palette.TextMuted) });
        var value = new TextBlock { Text = captureTarget == id ? "Waiting..." : InputMapping.SourceName(CurrentBindings.GetValueOrDefault(id), controller.SelectedDevice.Kind),
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
        RenderOptions.SetBitmapScalingMode(diagramImage, BitmapScalingMode.HighQuality);
        ControllerDiagram.Children.Add(diagramImage);
        foreach (var action in InputMapping.Actions) {
            var leader = new Polyline { Stroke = Palette.Brush(Palette.TextMuted, 120), StrokeThickness = 1,
                IsHitTestVisible = false, UseLayoutRounding = false };
            ControllerDiagram.Children.Add(leader); bindingLeaders[action.Id] = leader;
            ControllerDiagram.Children.Add(CreateMapBinding(action.Id, action.Label));
        }
        LayoutControllerDiagram();
        return true;
    }
    void ControllerDiagramSizeChanged(object sender, SizeChangedEventArgs e) => LayoutControllerDiagram();
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
                ? new PointCollection { start, new(imageLeft - 8, start.Y), new(end.X, end.Y + 18), end }
                : new PointCollection { start, end };
        }
    }
    void ClearBinding(string action) {
        CurrentBindings[action] = 0; CancelCapture(this, new()); SaveInputPreferences(); BuildBindingRows();
        if (bindingButtons.TryGetValue(action, out var binding)) binding.Focus();
    }
    void ClearCapturedBinding(object sender, RoutedEventArgs e) { if (captureTarget.Length != 0) ClearBinding(captureTarget); }
}
