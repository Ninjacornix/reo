using Avalonia;
using Avalonia.Animation.Easings;
using Avalonia.Controls;
using Avalonia.Data;
using Avalonia.Media;
using Avalonia.Threading;
using Avalonia.VisualTree;
using Avalonia.Platform.Storage;
using Avalonia.Controls.Primitives;

namespace Outbreak.Launcher.Desktop.Compatibility;

// Source adapters for the RC1 Windows view code. They keep the RC1 handlers readable line by
// line against launcher/MainWindow.*.cs while every control is an Avalonia control.
public enum Visibility { Visible, Hidden, Collapsed }
public sealed record Style(string Key);

public static class ViewProperties {
    static readonly System.Runtime.CompilerServices.ConditionalWeakTable<Control, object> hidden = new();
    extension(Control control) {
        // Hidden keeps its layout slot, draws nothing and takes no input, as in WPF.
        public Visibility Visibility {
            get => !control.IsVisible ? Visibility.Collapsed : hidden.TryGetValue(control, out _) ? Visibility.Hidden : Visibility.Visible;
            set {
                bool wasHidden = hidden.TryGetValue(control, out _);
                if (value == Visibility.Hidden && !wasHidden) {
                    hidden.Add(control, control.IsHitTestVisible);
                    control.IsHitTestVisible = false;
                    control.Opacity = 0;
                } else if (value != Visibility.Hidden && wasHidden) {
                    hidden.TryGetValue(control, out var hitTest);
                    hidden.Remove(control);
                    control.IsHitTestVisible = (bool)hitTest!;
                    control.ClearValue(Visual.OpacityProperty);
                }
                control.IsVisible = value != Visibility.Collapsed;
            }
        }
        public double ActualWidth => control.Bounds.Width;
        public double ActualHeight => control.Bounds.Height;
        public object? ToolTip { get => Avalonia.Controls.ToolTip.GetTip(control); set => Avalonia.Controls.ToolTip.SetTip(control, value); }
        public Style? Style {
            get => control.Classes.Count > 0 ? new(control.Classes[0]) : null;
            set {
                if (value == null) return;
                // WPF BasedOn chains become cumulative classes.
                if (value.Key == "ModOption") control.Classes.Add("CheatOption");
                if (value.Key == "GameFilePath") control.Classes.Add("CoopTextInput");
                if (value.Key == "CoopStatus") control.Classes.Add("Hint");
                control.Classes.Add(value.Key);
            }
        }
    }
    extension(ScrollViewer viewer) {
        public double VerticalOffset => viewer.Offset.Y;
        public double HorizontalOffset => viewer.Offset.X;
        public double ExtentHeight => viewer.Extent.Height;
        public void ScrollToVerticalOffset(double offset) => viewer.Offset = new(viewer.Offset.X, Math.Max(0, offset));
        public void ScrollToHorizontalOffset(double offset) => viewer.Offset = new(Math.Max(0, offset), viewer.Offset.Y);
    }
    static ScrollViewer? Scroller(TextBox box) => box.GetVisualDescendants().OfType<ScrollViewer>().FirstOrDefault();
    extension(TextBox box) {
        public double VerticalOffset => Scroller(box)?.Offset.Y ?? 0;
        public double HorizontalOffset => Scroller(box)?.Offset.X ?? 0;
        public double ExtentHeight => Scroller(box)?.Extent.Height ?? 0;
        public void ScrollToVerticalOffset(double offset) { if (Scroller(box) is { } viewer) viewer.Offset = new(viewer.Offset.X, Math.Max(0, offset)); }
        public void ScrollToHorizontalOffset(double offset) { if (Scroller(box) is { } viewer) viewer.Offset = new(Math.Max(0, offset), viewer.Offset.Y); }
    }
}

public static class VisualPalette {
    public static SolidColorBrush Brush(Rgba color, byte alpha = 255) {
        var mixed = Palette.WithAlpha(color, alpha);
        return new(Color.FromArgb(mixed.A, mixed.R, mixed.G, mixed.B));
    }
    public static Color ColorOf(Rgba color, byte alpha = 255) {
        var mixed = Palette.WithAlpha(color, alpha);
        return Avalonia.Media.Color.FromArgb(mixed.A, mixed.R, mixed.G, mixed.B);
    }
}

public static class SystemParameters {
    // RC1 consults Windows' client-area animation setting. Each desktop keeps its animations on.
    public static bool ClientAreaAnimation { get; internal set; } = true;
}

// WPF BeginAnimation semantics: an animation overrides the base (local) value, holds its final
// value after completion, and BeginAnimation(property, null) reverts to the base value.
public static class Motion {
    sealed class Track : IObservable<double>, IDisposable {
        IObserver<double>? observer;
        public double Value;
        public IDisposable? Binding;
        public IDisposable Subscribe(IObserver<double> value) { observer = value; value.OnNext(Value); return this; }
        public void Publish(double value) { Value = value; observer?.OnNext(value); }
        public void Dispose() => observer = null;
    }
    sealed class Run {
        public required AvaloniaObject Target;
        public required StyledProperty<double> Property;
        public required double From, To;
        public required TimeSpan Duration;
        public Easing? Easing;
        public Action? Completed;
        public required Track Track;
        public long Started;
        public bool Done;
    }
    static readonly Dictionary<(AvaloniaObject, AvaloniaProperty), Track> tracks = new();
    static readonly List<Run> runs = new();
    static DispatcherTimer? clock;

    public static void Animate(this AvaloniaObject target, StyledProperty<double> property, double? from, double to,
        TimeSpan duration, Easing? easing = null, Action? completed = null) {
        double start = from ?? target.GetValue(property);
        runs.RemoveAll(r => ReferenceEquals(r.Target, target) && r.Property == property);
        if (!tracks.TryGetValue((target, property), out var track)) {
            track = new Track { Value = start };
            tracks[(target, property)] = track;
            track.Binding = target.Bind(property, track, BindingPriority.Animation);
        }
        track.Publish(start);
        runs.Add(new Run { Target = target, Property = property, From = start, To = to, Duration = duration,
            Easing = easing, Completed = completed, Track = track, Started = System.Diagnostics.Stopwatch.GetTimestamp() });
        clock ??= CreateClock();
        clock.Start();
        Step();
    }
    public static void StopAnimation(this AvaloniaObject target, StyledProperty<double> property) {
        runs.RemoveAll(r => ReferenceEquals(r.Target, target) && r.Property == property);
        if (tracks.Remove((target, property), out var track)) track.Binding?.Dispose();
    }
    static DispatcherTimer CreateClock() {
        var timer = new DispatcherTimer(TimeSpan.FromMilliseconds(15), DispatcherPriority.Render, (_, _) => Step());
        return timer;
    }
    static void Step() {
        long now = System.Diagnostics.Stopwatch.GetTimestamp();
        foreach (var run in runs.ToArray()) {
            if (!runs.Contains(run)) continue;
            double progress = run.Duration <= TimeSpan.Zero ? 1 :
                Math.Clamp(System.Diagnostics.Stopwatch.GetElapsedTime(run.Started, now) / run.Duration, 0, 1);
            double eased = run.Easing?.Ease(progress) ?? progress;
            run.Track.Publish(run.From + (run.To - run.From) * eased);
            if (progress >= 1) {
                runs.Remove(run);
                run.Completed?.Invoke();
            }
        }
        if (runs.Count == 0) clock?.Stop();
    }
}

public enum MessageBoxButton { OK, YesNo }
public enum MessageBoxImage { None, Information, Warning }
public enum MessageBoxResult { None, OK, Yes, No }

public static class MessageBox {
    [System.Runtime.InteropServices.DllImport("user32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern int MessageBoxW(nint owner, string text, string caption, uint type);
    // Windows keeps RC1's system message box. Other desktops show the same text and choices.
    public static async Task<MessageBoxResult> Show(Window? owner, string text, string caption,
        MessageBoxButton buttons = MessageBoxButton.OK, MessageBoxImage image = MessageBoxImage.None,
        MessageBoxResult defaultResult = MessageBoxResult.None) {
        if (OperatingSystem.IsWindows()) {
            uint type = (buttons == MessageBoxButton.YesNo ? 4u : 0u) |
                        (image == MessageBoxImage.Warning ? 0x30u : image == MessageBoxImage.Information ? 0x40u : 0u) |
                        (buttons == MessageBoxButton.YesNo && defaultResult == MessageBoxResult.No ? 0x100u : 0u);
            nint handle = owner?.TryGetPlatformHandle()?.Handle ?? 0;
            int result = MessageBoxW(handle, text, caption, type);
            return result switch { 6 => MessageBoxResult.Yes, 7 => MessageBoxResult.No, 1 => MessageBoxResult.OK, _ => MessageBoxResult.None };
        }
        var choice = buttons == MessageBoxButton.YesNo ? (defaultResult == MessageBoxResult.No ? MessageBoxResult.No : MessageBoxResult.None) : MessageBoxResult.OK;
        var dialog = new Window { Title = caption, Width = 460, SizeToContent = SizeToContent.Height, CanResize = false,
            WindowStartupLocation = owner == null ? WindowStartupLocation.CenterScreen : WindowStartupLocation.CenterOwner,
            Background = VisualPalette.Brush(Palette.Background), Foreground = VisualPalette.Brush(Palette.Text), FontSize = 16,
            ShowInTaskbar = false };
        dialog.Bind(TemplatedControl.FontFamilyProperty, dialog.GetResourceObservable("GameDisplayFont"));
        var panel = new StackPanel { Margin = new Thickness(24) };
        panel.Children.Add(new TextBlock { Text = text, TextWrapping = TextWrapping.Wrap, LineHeight = 24 });
        var row = new StackPanel { Orientation = Orientation.Horizontal, HorizontalAlignment = HorizontalAlignment.Right, Margin = new Thickness(0, 22, 0, 0) };
        Button Add(string label, MessageBoxResult result) {
            var button = new Button { Content = label, MinWidth = 88, Margin = new Thickness(8, 0, 0, 0) };
            button.Click += (_, _) => { choice = result; dialog.Close(); };
            row.Children.Add(button);
            return button;
        }
        Button focus;
        if (buttons == MessageBoxButton.YesNo) {
            var yes = Add("Yes", MessageBoxResult.Yes);
            var no = Add("No", MessageBoxResult.No);
            focus = defaultResult == MessageBoxResult.No ? no : yes;
        } else focus = Add("OK", MessageBoxResult.OK);
        panel.Children.Add(row);
        dialog.Content = panel;
        dialog.Opened += (_, _) => focus.Focus();
        if (owner != null) await dialog.ShowDialog(owner); else {
            var closed = new TaskCompletionSource();
            dialog.Closed += (_, _) => closed.TrySetResult();
            dialog.Show();
            await closed.Task;
        }
        return choice;
    }
}

static class FilePickers {
    internal static List<Avalonia.Platform.Storage.FilePickerFileType> Types(string filter) {
        string[] parts = filter.Split('|');
        var types = new List<Avalonia.Platform.Storage.FilePickerFileType>();
        for (int i = 0; i + 1 < parts.Length; i += 2)
            types.Add(new(parts[i]) { Patterns = parts[i + 1].Split(';') });
        return types;
    }
    internal static async Task<Avalonia.Platform.Storage.IStorageFolder?> Folder(Window owner, string? path) =>
        string.IsNullOrEmpty(path) || !Directory.Exists(path) ? null : await owner.StorageProvider.TryGetFolderFromPathAsync(new Uri(Path.GetFullPath(path)));
}

public sealed class OpenFileDialog {
    public string Title { get; set; } = "Open";
    public string Filter { get; set; } = "";
    public bool Multiselect { get; set; }
    public bool CheckFileExists { get; set; }
    public string? InitialDirectory { get; set; }
    public string FileName => FileNames.FirstOrDefault() ?? "";
    public string[] FileNames { get; private set; } = [];
    public async Task<bool?> ShowDialog(Window owner) {
        var selected = await owner.StorageProvider.OpenFilePickerAsync(new() {
            Title = Title, AllowMultiple = Multiselect, FileTypeFilter = FilePickers.Types(Filter),
            SuggestedStartLocation = await FilePickers.Folder(owner, InitialDirectory) });
        FileNames = selected.Select(p => p.TryGetLocalPath()).Where(p => p != null && (!CheckFileExists || File.Exists(p))).Cast<string>().ToArray();
        return FileNames.Length > 0;
    }
}

public sealed class SaveFileDialog {
    public string Title { get; set; } = "Save";
    public string Filter { get; set; } = "";
    public string FileName { get; set; } = "";
    public async Task<bool?> ShowDialog(Window owner) {
        var types = FilePickers.Types(Filter);
        var file = await owner.StorageProvider.SaveFilePickerAsync(new() {
            Title = Title, SuggestedFileName = FileName, FileTypeChoices = types,
            DefaultExtension = types.FirstOrDefault()?.Patterns?.FirstOrDefault()?.TrimStart('*', '.') });
        if (file?.TryGetLocalPath() is not { } path) return false;
        FileName = path;
        return true;
    }
}

public sealed class OpenFolderDialog {
    public string Title { get; set; } = "Select folder";
    public string? InitialDirectory { get; set; }
    public bool Multiselect { get; set; }
    public string FolderName { get; private set; } = "";
    public async Task<bool?> ShowDialog(Window owner) {
        var folders = await owner.StorageProvider.OpenFolderPickerAsync(new() {
            Title = Title, AllowMultiple = Multiselect, SuggestedStartLocation = await FilePickers.Folder(owner, InitialDirectory) });
        if (folders.FirstOrDefault()?.TryGetLocalPath() is not { } path) return false;
        FolderName = path;
        return true;
    }
}

// RC1 status line: every assignment is reported, including one that repeats the current text.
public sealed class StatusText : TextBlock {
    protected override Type StyleKeyOverride => typeof(TextBlock);
    internal event Action<bool>? Assigned;
    public new string Text {
        get => base.Text ?? "";
        set {
            bool changed = !string.Equals(base.Text, value, StringComparison.Ordinal);
            base.Text = value;
            Assigned?.Invoke(changed);
        }
    }
}

// Platform wording. Windows keeps every RC1 string unchanged.
static class PlatformText {
    internal static string RecycleBin => OperatingSystem.IsWindows() ? "Recycle Bin" : "Trash";
    internal static string SystemName => OperatingSystem.IsWindows() ? "Windows" : OperatingSystem.IsMacOS() ? "macOS" : "Linux";
}

// WPF's TextBoxView keeps text two pixels from the left and right of the content host.
public sealed class TextInset : Avalonia.Data.Converters.IValueConverter {
    public static readonly TextInset Converter = new();
    public object Convert(object? value, Type targetType, object? parameter, System.Globalization.CultureInfo culture) =>
        value is Thickness padding ? new Thickness(padding.Left + 2, padding.Top, padding.Right + 2, padding.Bottom) : new Thickness(2, 0);
    public object ConvertBack(object? value, Type targetType, object? parameter, System.Globalization.CultureInfo culture) =>
        throw new NotSupportedException();
}

// WPF layout rounding rounds a TextBlock's measured size to the nearest device pixel; Avalonia
// rounds up. One pixel per text line drifts every list and form, so RC1 rounding is used here.
public class Rc1TextBlock : TextBlock {
    protected override Type StyleKeyOverride => typeof(TextBlock);
    protected override Size MeasureOverride(Size availableSize) {
        var size = base.MeasureOverride(availableSize);
        if (!UseLayoutRounding) return size;
        double scale = TopLevel.GetTopLevel(this)?.RenderScaling ?? 1;
        double Round(double value) => Math.Round(value * scale, MidpointRounding.AwayFromZero) / scale;
        // Wrapped text keeps its full width so arrange cannot break the last line again.
        return new Size(TextWrapping == TextWrapping.NoWrap ? Round(size.Width) : size.Width, Round(size.Height));
    }
    // With an explicit LineHeight, WPF centres each line's glyphs in the extra space; Avalonia adds
    // all of it above them. Draw the text at WPF's position.
    protected override void OnAttachedToVisualTree(VisualTreeAttachmentEventArgs e) {
        base.OnAttachedToVisualTree(e);
        if (OperatingSystem.IsWindows()) ApplyDisplayWidths();
    }
    protected override void OnPropertyChanged(AvaloniaPropertyChangedEventArgs change) {
        base.OnPropertyChanged(change);
        if (OperatingSystem.IsWindows() && (change.Property == TextProperty || change.Property == FontSizeProperty ||
            change.Property == FontFamilyProperty || change.Property == FontWeightProperty || change.Property == FontStyleProperty))
            ApplyDisplayWidths();
        if (change.Property == LineHeightProperty || change.Property == FontSizeProperty ||
            change.Property == FontFamilyProperty || change.Property == FontWeightProperty || change.Property == FontStyleProperty) {
            double extra = double.IsNaN(LineHeight) ? 0 : LineHeight - NaturalLineHeight();
            RenderTransform = extra > 0 ? new TranslateTransform(0, -extra / 2) : null;
        }
    }
    // RC1 sets TextFormattingMode.Display: GDI-compatible, hinted whole-pixel advances. Spread the
    // difference from Avalonia's shaped width over the characters so lines break where RC1's do.
    void ApplyDisplayWidths() {
        string text = Text ?? "";
        if (text.Length < 2 || text.Contains('\n')) { ClearValue(LetterSpacingProperty); return; }
        var face = new Typeface(FontFamily, FontStyle, FontWeight);
        double? gdi;
        try { gdi = GdiText.Width(face, FontSize, text, TopLevel.GetTopLevel(this)?.RenderScaling ?? 1); }
        catch (Exception error) when (error is System.Runtime.InteropServices.MarshalDirectiveException or DllNotFoundException or EntryPointNotFoundException) { gdi = null; }
        if (gdi == null) { ClearValue(LetterSpacingProperty); return; }
        using var layout = new Avalonia.Media.TextFormatting.TextLayout(text, face, FontSize, null);
        double spacing = (gdi.Value - layout.WidthIncludingTrailingWhitespace) / text.Length;
        if (Math.Abs(spacing) < .001) ClearValue(LetterSpacingProperty); else LetterSpacing = spacing;
    }
    static readonly Dictionary<(FontFamily, FontStyle, FontWeight, double), double> naturalHeights = new();
    double NaturalLineHeight() {
        var key = (FontFamily, FontStyle, FontWeight, FontSize);
        if (!naturalHeights.TryGetValue(key, out double height)) {
            using var layout = new Avalonia.Media.TextFormatting.TextLayout("X", new Typeface(FontFamily, FontStyle, FontWeight), FontSize, null);
            naturalHeights[key] = height = layout.Height;
        }
        return height;
    }
}
public class Rc1TextPresenter : Avalonia.Controls.Presenters.TextPresenter {
    protected override Type StyleKeyOverride => typeof(Avalonia.Controls.Presenters.TextPresenter);
    protected override Size MeasureOverride(Size availableSize) {
        var size = base.MeasureOverride(availableSize);
        double scale = TopLevel.GetTopLevel(this)?.RenderScaling ?? 1;
        return new Size(size.Width, Math.Round(size.Height * scale, MidpointRounding.AwayFromZero) / scale);
    }
}

// Windows GDI text extents (WPF Display formatting). Fonts not known to GDI return null.
static class GdiText {
    [System.Runtime.InteropServices.DllImport("gdi32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern nint CreateFontW(int height, int width, int escapement, int orientation, int weight, uint italic, uint underline,
        uint strike, uint charset, uint outPrecision, uint clipPrecision, uint quality, uint pitchAndFamily, string face);
    [System.Runtime.InteropServices.DllImport("gdi32.dll")] static extern nint CreateCompatibleDC(nint dc);
    [System.Runtime.InteropServices.DllImport("gdi32.dll")] static extern nint SelectObject(nint dc, nint item);
    [System.Runtime.InteropServices.DllImport("gdi32.dll")] static extern bool DeleteObject(nint item);
    [System.Runtime.InteropServices.DllImport("gdi32.dll")] static extern bool DeleteDC(nint dc);
    [System.Runtime.InteropServices.DllImport("gdi32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern bool GetTextExtentPoint32W(nint dc, string text, int length, out Extent size);
    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)] struct Extent { public int Width, Height; }
    [System.Runtime.InteropServices.DllImport("gdi32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern int GetTextFaceW(nint dc, int count, System.Text.StringBuilder face);
    [System.Runtime.InteropServices.DllImport("gdi32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern int AddFontResourceExW(string path, uint flags, nint reserved);
    static readonly Dictionary<(string, int, bool, int), nint> fonts = new();
    static nint dc;
    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    struct TextMetric { public int Height, Ascent, Descent, InternalLeading, ExternalLeading, AveCharWidth, MaxCharWidth, Weight, Overhang, DigitizedAspectX, DigitizedAspectY;
        public char FirstChar, LastChar, DefaultChar, BreakChar; public byte Italic, Underlined, StruckOut, PitchAndFamily, CharSet; }
    [System.Runtime.InteropServices.DllImport("gdi32.dll", CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    static extern bool GetTextMetricsW(nint dc, out TextMetric metric);
    // Diagnostic: GDI line metrics for a face at whole pixel sizes.
    internal static string Metrics(string face) {
        if (!OperatingSystem.IsWindows()) return "";
        var parts = new List<string>();
        foreach (int size in new[] { 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 142 }) {
            if (dc == 0) dc = CreateCompatibleDC(0);
            var font = CreateFontW(-size, 0, 0, 0, 400, 0, 0, 0, 1, 0, 0, 5, 0, face);
            var old = SelectObject(dc, font);
            if (GetTextMetricsW(dc, out var m)) parts.Add($"{size}:{m.Height}/{m.Ascent}/{m.Descent}");
            SelectObject(dc, old); DeleteObject(font);
        }
        return string.Join(' ', parts);
    }
    internal static void Register(string path) { if (OperatingSystem.IsWindows()) AddFontResourceExW(path, 0x10, 0); }
    internal static double? Width(Typeface typeface, double size, string text, double scale = 1) {
        if (!OperatingSystem.IsWindows()) return null;
        string name = typeface.FontFamily.FamilyNames.FirstOrDefault() ?? typeface.FontFamily.Name;
        if (name.Contains('#')) name = name[(name.LastIndexOf('#') + 1)..];
        // WPF Display formatting measures at device pixels.
        int pixels = (int)Math.Round(size * scale);
        if (pixels <= 0) return null;
        var key = (name, (int)typeface.Weight, typeface.Style != FontStyle.Normal, pixels);
        if (dc == 0) dc = CreateCompatibleDC(0);
        if (!fonts.TryGetValue(key, out var font)) {
            font = CreateFontW(-pixels, 0, 0, 0, (int)typeface.Weight, key.Item3 ? 1u : 0u, 0, 0, 1, 0, 0, 5, 0, name);
            SelectObject(dc, font);
            var actual = new System.Text.StringBuilder(64);
            GetTextFaceW(dc, actual.Capacity, actual);
            if (!string.Equals(actual.ToString(), name, StringComparison.OrdinalIgnoreCase)) { DeleteObject(font); font = 0; }
            fonts[key] = font;
        }
        if (font == 0) return null;
        SelectObject(dc, font);
        return GetTextExtentPoint32W(dc, text, text.Length, out var extent) ? extent.Width / scale : null;
    }
}
