using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media.Animation;
using System.Windows.Threading;

namespace Outbreak.Launcher;

// The status line. Every assignment is reported, including one that repeats the current text,
// so a repeated message (a second save, for example) can be shown again.
public sealed class StatusText : TextBlock {
    internal event Action<bool>? Assigned;
    public new string Text {
        get => base.Text;
        set {
            bool changed = !string.Equals(base.Text, value, StringComparison.Ordinal);
            base.Text = value;
            Assigned?.Invoke(changed);
        }
    }
}

public partial class MainWindow {
    readonly DispatcherTimer statusToastTimer = new();
    long statusAssignedAt;
    bool statusToastShown;

    void InitializeStatusToast() {
        statusToastTimer.Tick += (_, _) => HideStatusToast();
        Status.Assigned += StatusAssigned;
        StatusToast.MouseEnter += (_, _) => statusToastTimer.Stop();
        StatusToast.MouseLeave += (_, _) => { if (statusToastShown) statusToastTimer.Start(); };
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
        if (!StatusToast.IsMouseOver) statusToastTimer.Start();
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
            StatusToast.BeginAnimation(OpacityProperty, null);
            StatusToast.Opacity = 1;
            return;
        }
        var ease = new CubicEase { EasingMode = EasingMode.EaseOut };
        StatusToast.BeginAnimation(OpacityProperty, new DoubleAnimation(1, TimeSpan.FromMilliseconds(160)));
        StatusToastOffset.BeginAnimation(System.Windows.Media.TranslateTransform.YProperty,
            new DoubleAnimation(-10, 0, TimeSpan.FromMilliseconds(220)) { EasingFunction = ease });
    }
    void HideStatusToast() {
        statusToastTimer.Stop();
        if (!statusToastShown) return;
        statusToastShown = false;
        if (!IsLoaded || !SystemParameters.ClientAreaAnimation) {
            StatusToast.BeginAnimation(OpacityProperty, null);
            StatusToast.Opacity = 0;
            StatusToast.Visibility = Visibility.Collapsed;
            return;
        }
        var fade = new DoubleAnimation(0, TimeSpan.FromMilliseconds(300));
        fade.Completed += (_, _) => {
            if (!statusToastShown) StatusToast.Visibility = Visibility.Collapsed;
        };
        StatusToast.BeginAnimation(OpacityProperty, fade);
    }
    void DismissStatusToast(object sender, MouseButtonEventArgs e) {
        HideStatusToast();
        e.Handled = true;
    }
}
