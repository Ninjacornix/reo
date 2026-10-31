using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestLogsUi(string output) {
        Directory.CreateDirectory(output);
        var checks = new List<string>();
        string session = Path.Combine(Settings.Home, "sessions", "zzz-log-ui-" + Guid.NewGuid().ToString("N"));
        void Check(bool value, string message) { if (!value) throw new IOException(message); checks.Add(message); }
        async Task Settle() { await Task.Delay(100); UpdateLayout(); }
        void ToggleFollow() => ((IToggleProvider)new CheckBoxAutomationPeer(FollowLog).GetPattern(PatternInterface.Toggle)!).Toggle();
        IEnumerable<T> Children<T>(DependencyObject parent) where T : DependencyObject {
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(parent); i++) {
                var child = VisualTreeHelper.GetChild(parent, i);
                if (child is T item) yield return item;
                foreach (var descendant in Children<T>(child)) yield return descendant;
            }
        }
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed;
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Log diagnostics use an isolated data home");
            timer.Stop(); ShowPage("Logs");
            manualLog = Path.Combine(output, "missing.log"); RefreshLog(); HideStatusToast(); await Task.Delay(350);
            Check(LogEmpty.IsVisible && DebugLog.Text.Length == 0 && LogFollowState.Text.Length == 0 &&
                NavLogs.IsEnabled && OpenLogFileButton.IsEnabled, "A fresh launcher has an actionable Log empty state");
            Capture("empty");
            Directory.CreateDirectory(session);
            string debug = Path.Combine(session, "stderr.log"), stdout = Path.Combine(session, "stdout.log");
            File.WriteAllText(debug, string.Join("\n", Enumerable.Range(0, 220).Select(i =>
                $"{i:0000} [FRAME] pc=0x00100000 " + new string('x', 240))) + "\n");
            File.WriteAllText(stdout, "Game output fixture\n");
            manualLog = null; RefreshLogSessions();
            LogSessionPicker.SelectedItem = LogSessionPicker.Items.Cast<LogSession>().Single(item => item.Directory == session);
            LogStreamPicker.SelectedIndex = 0; RefreshLog(); await Settle();
            Check(DebugLog.Text == File.ReadAllText(debug) && !LogEmpty.IsVisible && LogFollowState.Text == "FOLLOWING",
                "Session and stream selection show real debug text with the following state");
            Check(DebugLog.IsReadOnly && DebugLog.TextWrapping == TextWrapping.NoWrap && DebugLog.FontFamily.Source == "Consolas",
                "The log stays read-only and unwrapped in the fixed Consolas font");
            Check(LogStreamPicker.TranslatePoint(new Point(LogStreamPicker.ActualWidth, 0), PageLogs).X <= PageLogs.ActualWidth + .5 &&
                LogStreamPicker.ActualWidth <= System.Windows.Controls.Primitives.LayoutInformation.GetLayoutSlot(LogStreamPicker).Width + .5,
                "The complete Stream dropdown fits its column without clipping the right border");
            DebugLog.Select(0, 12);
            Check(DebugLog.SelectedText == DebugLog.Text[..12], "Log text remains selectable for copying");
            DebugLog.Select(0, 0);
            var horizontal = Children<ScrollBar>(DebugLog).Single(bar => bar.Orientation == Orientation.Horizontal);
            var vertical = Children<ScrollBar>(DebugLog).Single(bar => bar.Orientation == Orientation.Vertical);
            var hTrack = (Track)horizontal.Template.FindName("PART_Track", horizontal);
            var vTrack = (Track)vertical.Template.FindName("PART_Track", vertical);
            Check(horizontal.IsVisible && vertical.IsVisible && !hTrack.IsDirectionReversed && vTrack.IsDirectionReversed,
                "Horizontal and vertical tracks use the correct independent directions");
            ToggleFollow(); DebugLog.ScrollToHorizontalOffset(0); DebugLog.ScrollToVerticalOffset(0); await Settle();
            double thumbLeft = hTrack.Thumb.TranslatePoint(new Point(), horizontal).X;
            hTrack.Thumb.RaiseEvent(new DragDeltaEventArgs(48, 0) { RoutedEvent = Thumb.DragDeltaEvent }); await Settle();
            Check(DebugLog.HorizontalOffset > 0 && hTrack.Thumb.TranslatePoint(new Point(), horizontal).X > thumbLeft,
                "Dragging the actual horizontal thumb right reveals later columns and moves the thumb right");
            hTrack.Thumb.RaiseEvent(new DragDeltaEventArgs(-24, 0) { RoutedEvent = Thumb.DragDeltaEvent }); await Settle();
            double horizontalOffset = DebugLog.HorizontalOffset;
            Check(horizontalOffset > 0 && hTrack.Thumb.TranslatePoint(new Point(), horizontal).X > thumbLeft,
                "Dragging left reverses horizontal travel normally");
            vTrack.Thumb.RaiseEvent(new DragDeltaEventArgs(0, 24) { RoutedEvent = Thumb.DragDeltaEvent }); await Settle();
            double verticalOffset = DebugLog.VerticalOffset;
            Check(verticalOffset > 0, "Dragging the vertical thumb down still reveals later lines");
            File.AppendAllText(debug, "[APPEND] first live update\n"); RefreshLog(); await Settle();
            Check(Math.Abs(DebugLog.HorizontalOffset - horizontalOffset) < 1 && Math.Abs(DebugLog.VerticalOffset - verticalOffset) < 1 &&
                LogFollowState.Text == "PAUSED", "Paused live updates preserve both reading offsets");
            Capture("paused");
            ToggleFollow(); await Settle();
            Check(DebugLog.VerticalOffset > verticalOffset && Math.Abs(DebugLog.HorizontalOffset - horizontalOffset) < 1,
                "Enabling Follow immediately reaches the latest lines without shifting sideways");
            File.AppendAllText(debug, "[APPEND] second live update\n"); RefreshLog(); await Settle();
            Check(Math.Abs(DebugLog.HorizontalOffset - horizontalOffset) < 1 && LogFollowState.Text == "FOLLOWING",
                "Following an appended log keeps the chosen horizontal position");
            LogStreamPicker.SelectedIndex = 1; await Settle();
            Check(DebugLog.Text == "Game output fixture\n" && DebugLog.HorizontalOffset == 0,
                "Changing streams loads stdout and resets its horizontal position");
            LogStreamPicker.SelectedIndex = 0; LogStreamPicker.SelectedIndex = 1; await Settle();
            Check(DebugLog.Text == "Game output fixture\n", "A queued update from an earlier stream cannot overwrite the current stream");
            File.WriteAllText(stdout, ""); RefreshLog(); await Settle();
            Check(LogEmpty.IsVisible && LogEmptyDetail.Text == "Waiting for log entries.", "An existing empty log waits for its writer");
            File.WriteAllText(stdout, "Writer resumed\n"); RefreshLog(); await Settle();
            Check(!LogEmpty.IsVisible && DebugLog.Text == "Writer resumed\n", "New entries replace the empty state automatically");
            File.Delete(stdout); RefreshLog(); await Settle();
            Check(LogEmpty.IsVisible && DebugLog.Text.Length == 0, "A removed stream clears stale text and restores the empty state");
            LogStreamPicker.SelectedIndex = 0; await Settle();
            Width = MinWidth; Height = MinHeight; await Settle();
            Check(LogStreamPicker.TranslatePoint(new Point(LogStreamPicker.ActualWidth, 0), PageLogs).X <= PageLogs.ActualWidth + .5 &&
                LogStreamPicker.ActualWidth <= System.Windows.Controls.Primitives.LayoutInformation.GetLayoutSlot(LogStreamPicker).Width + .5,
                "The complete Stream dropdown also fits at minimum window size");
            Check(PageLogs.ActualWidth <= PageContent.ActualWidth + 1 && DebugLog.ActualHeight > 90 &&
                FollowLog.TranslatePoint(new Point(FollowLog.ActualWidth, 0), PageLogs).X <= PageLogs.ActualWidth + 1 &&
                OpenLogFileButton.IsVisible && LogSessionPicker.IsVisible && LogStreamPicker.IsVisible,
                "Session selectors, commands, Follow and the log viewport fit at minimum window size");
            Capture("compact");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = true, checks }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(
                new { passed = false, checks, error = error.ToString() }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally { Close(); }
    }
}
