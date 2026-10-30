using System.IO;
using System.Windows;
using System.Windows.Interop;

namespace Outbreak.Launcher;

public partial class MainWindow {
    void InitializeWindowLayout() {
        // WorkArea uses WPF's logical units and excludes the taskbar.
        var work = SystemParameters.WorkArea;
        double availableWidth = Math.Max(1, work.Width - 24);
        double availableHeight = Math.Max(1, work.Height - 24);
        MinWidth = Math.Min(980, availableWidth);
        MinHeight = Math.Min(690, availableHeight);
        Width = Math.Clamp(double.IsFinite(settings.LauncherWidth) && settings.LauncherWidth > 0
            ? settings.LauncherWidth : 1320, MinWidth, availableWidth);
        Height = Math.Clamp(double.IsFinite(settings.LauncherHeight) && settings.LauncherHeight > 0
            ? settings.LauncherHeight : 920, MinHeight, availableHeight);
        bool remember = !args.Any(arg => arg.StartsWith("--test-") || arg.StartsWith("--probe-") ||
            arg is "--screenshot" or "--public-preview" or "--smoke-launch");
        SourceInitialized += (_, _) => HwndSource.FromHwnd(new WindowInteropHelper(this).Handle)?.AddHook(SizeMoveHook);
        bool maximized = settings.LauncherMaximized;
        if (remember && maximized)
            WindowState = WindowState.Maximized;
        StateChanged += (_, _) => {
            // Launching a game minimizes the launcher; keep the user's previous choice.
            if (WindowState != WindowState.Minimized)
                maximized = WindowState == WindowState.Maximized;
        };
        Rect bounds = Rect.Empty;
        Closing += (_, _) => bounds = RestoreBounds;
        Closed += (_, _) => {
            if (!remember)
                return;
            if (bounds.IsEmpty || bounds.Width <= 0 || bounds.Height <= 0)
                return;
            settings.LauncherWidth = bounds.Width;
            settings.LauncherHeight = bounds.Height;
            settings.LauncherMaximized = maximized;
            try {
                settings.Save();
            } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
                System.Diagnostics.Debug.WriteLine("Window size could not be saved: " + error.Message);
            }
        };
    }
    const int WM_ENTERSIZEMOVE = 0x0231, WM_EXITSIZEMOVE = 0x0232;
    // While the window is dragged or resized, hold the background movie and the case animations.
    // Every movie frame otherwise redraws the whole Play pane, and the render thread falls behind
    // the compositor moving the window.
    IntPtr SizeMoveHook(IntPtr hwnd, int message, IntPtr wParam, IntPtr lParam, ref bool handled) {
        if (message is WM_ENTERSIZEMOVE or WM_EXITSIZEMOVE) {
            bool moving = message == WM_ENTERSIZEMOVE;
            backgroundPlayer?.Hold(moving);
            GameCase1.Hold(moving);
            GameCase2.Hold(moving);
        }
        return IntPtr.Zero;
    }
}
