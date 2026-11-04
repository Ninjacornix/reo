namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.Window.cs.
public partial class MainWindow {
    Rect restoreBounds;
    Size frameExtra;
    void InitializeWindowLayout() {
        // The working area excludes the taskbar / Dock and menu bar, in logical units.
        var screen = Screens.ScreenFromWindow(this) ?? Screens.Primary;
        var work = screen == null ? new Rect(0, 0, 1920, 1080) : screen.WorkingArea.ToRect(screen.Scaling);
        double availableWidth = Math.Max(1, work.Width - 24);
        double availableHeight = Math.Max(1, work.Height - 24);
        MinWidth = Math.Min(980, availableWidth);
        MinHeight = Math.Min(690, availableHeight);
        Width = Math.Clamp(double.IsFinite(settings.LauncherWidth) && settings.LauncherWidth > 0
            ? settings.LauncherWidth : 1320, MinWidth, availableWidth);
        Height = Math.Clamp(double.IsFinite(settings.LauncherHeight) && settings.LauncherHeight > 0
            ? settings.LauncherHeight : 920, MinHeight, availableHeight);
        bool remember = !staticCapture && !args.Any(arg => arg.StartsWith("--test-") || arg.StartsWith("--probe-") ||
            arg is "--screenshot" or "--public-preview" or "--smoke-launch");
        if (OperatingSystem.IsWindows())
            Opened += (_, _) => Win32Properties.AddWndProcHookCallback(this, SizeMoveHook);
        // WPF Width/Height/MinWidth/MinHeight include the window frame and title bar; Avalonia's
        // are the client area. Once the frame is known, size the client so the outer window matches.
        double outerWidth = Width, outerHeight = Height, outerMinWidth = MinWidth, outerMinHeight = MinHeight;
        Opened += (_, _) => {
            if (FrameSize is not { } frame || frame.Width <= 0) return;
            frameExtra = new Size(Math.Max(0, frame.Width - ClientSize.Width), Math.Max(0, frame.Height - ClientSize.Height));
            MinWidth = Math.Max(1, outerMinWidth - frameExtra.Width);
            MinHeight = Math.Max(1, outerMinHeight - frameExtra.Height);
            if (WindowState == WindowState.Normal) {
                Width = Math.Max(MinWidth, outerWidth - frameExtra.Width);
                Height = Math.Max(MinHeight, outerHeight - frameExtra.Height);
                // Keep CenterScreen centred on the outer window.
                Position = new PixelPoint(Position.X + (int)(frameExtra.Width * RenderScaling / 2),
                                          Position.Y + (int)(frameExtra.Height * RenderScaling / 2));
            }
        };
        bool maximized = settings.LauncherMaximized;
        if (remember && maximized)
            WindowState = WindowState.Maximized;
        restoreBounds = new Rect(0, 0, Width, Height);
        PropertyChanged += (_, e) => {
            if (e.Property == WindowStateProperty) {
                // Launching a game minimizes the launcher; keep the user's previous choice.
                if (WindowState != WindowState.Minimized)
                    maximized = WindowState == WindowState.Maximized;
                OnWindowStateChanged();
            } else if (e.Property == ClientSizeProperty && WindowState == WindowState.Normal) {
                restoreBounds = new Rect(0, 0, ClientSize.Width + frameExtra.Width, ClientSize.Height + frameExtra.Height);
            }
        };
        Rect bounds = default;
        Closing += (_, _) => bounds = restoreBounds;
        Closed += (_, _) => {
            if (!remember)
                return;
            if (bounds.Width <= 0 || bounds.Height <= 0)
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
    event Action? WindowStateChanged;
    void OnWindowStateChanged() => WindowStateChanged?.Invoke();
    const uint WM_ENTERSIZEMOVE = 0x0231, WM_EXITSIZEMOVE = 0x0232;
    // While the window is dragged or resized, hold the background movie and the case animations.
    // Every movie frame otherwise redraws the whole Play pane, and the render thread falls behind
    // the compositor moving the window.
    nint SizeMoveHook(nint hwnd, uint message, nint wParam, nint lParam, ref bool handled) {
        if (message is WM_ENTERSIZEMOVE or WM_EXITSIZEMOVE) {
            bool moving = message == WM_ENTERSIZEMOVE;
            backgroundPlayer?.Hold(moving);
            GameDisc1.Hold(moving);
            GameDisc2.Hold(moving);
            GameCase1.Hold(moving);
            GameCase2.Hold(moving);
        }
        return 0;
    }
}
