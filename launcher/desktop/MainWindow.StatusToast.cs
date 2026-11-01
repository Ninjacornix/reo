using Avalonia.Animation.Easings;
using System.Diagnostics;

namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.StatusToast.cs. StatusText lives in Compatibility.
public partial class MainWindow {
    readonly DispatcherTimer statusToastTimer = new();
    long statusAssignedAt;
    bool statusToastShown;

    void InitializeStatusToast() {
        statusToastTimer.Tick += (_, _) => HideStatusToast();
        Status.Assigned += StatusAssigned;
        StatusToast.PointerEntered += (_, _) => statusToastTimer.Stop();
        StatusToast.PointerExited += (_, _) => { if (statusToastShown) statusToastTimer.Start(); };
    }
    void StatusAssigned(bool changed) {
        long now = Stopwatch.GetTimestamp();
        // Some states (co-op network status, graphics preparation) are re-assigned every UI
        // tick. Those repeats must not bring the card back after it has timed out; a repeat
        // after a pause is a new event and does.
        bool repeatAfterPause = Stopwatch.GetElapsedTime(statusAssignedAt, now) > TimeSpan.FromSeconds(1);
        statusAssignedAt = now;
        if (QuietStatus(Status.Text)) { HideStatusToast(); return; }
        if (changed || (!statusToastShown && repeatAfterPause)) ShowStatusToast();
    }
    void ShowStatusToast() {
        // Longer messages stay a little longer: 4 s plus about 50 ms per character, up to 10 s.
        statusToastTimer.Interval = TimeSpan.FromSeconds(Math.Clamp(4 + Status.Text.Length * 0.05, 4, 10));
        statusToastTimer.Stop();
        if (!StatusToast.IsPointerOver) statusToastTimer.Start();
        // "Saved · Changes apply on the next launch" becomes a title and a detail line.
        string text = Status.Text;
        int split = text.IndexOf(" · ", StringComparison.Ordinal);
        StatusToastTitle.Text = split > 0 ? text[..split] : text;
        StatusToastDetail.Text = split > 0 ? text[(split + 3)..] : "";
        StatusToastDetail.Visibility = split > 0 ? Visibility.Visible : Visibility.Collapsed;
        if (statusToastShown) return;
        statusToastShown = true;
        StatusToast.Visibility = Visibility.Visible;
        if (!IsLoaded || !SystemParameters.ClientAreaAnimation) {
            StatusToast.StopAnimation(OpacityProperty);
            StatusToast.Opacity = 1;
            return;
        }
        StatusToast.Animate(OpacityProperty, null, 1, TimeSpan.FromMilliseconds(160));
        StatusToastOffset.Animate(TranslateTransform.YProperty, -10, 0, TimeSpan.FromMilliseconds(220), new CubicEaseOut());
    }
    void HideStatusToast() {
        statusToastTimer.Stop();
        if (!statusToastShown) return;
        statusToastShown = false;
        if (!IsLoaded || !SystemParameters.ClientAreaAnimation) {
            StatusToast.StopAnimation(OpacityProperty);
            StatusToast.Opacity = 0;
            StatusToast.Visibility = Visibility.Collapsed;
            return;
        }
        StatusToast.Animate(OpacityProperty, null, 0, TimeSpan.FromMilliseconds(300), completed: () => {
            if (!statusToastShown) StatusToast.Visibility = Visibility.Collapsed;
        });
    }
    void DismissStatusToast(object? sender, PointerReleasedEventArgs e) {
        if (e.InitialPressMouseButton != MouseButton.Left) return;
        HideStatusToast();
        e.Handled = true;
    }
}
