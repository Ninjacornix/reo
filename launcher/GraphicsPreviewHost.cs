using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;

namespace Outbreak.Launcher;

public sealed class GraphicsPreviewHost : HwndHost {
    internal GpuScenePreview Renderer { get; } = new();
    internal PreviewRotation Rotation { get; } = new();
    internal event EventHandler? RotationChanged;
    nint child, loadingBrush;
    internal bool HasPresentedFrame { get; set; }
    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)] static extern nint CreateWindowEx(int exStyle, string className,
        string? title, int style, int x, int y, int width, int height, nint parent, nint menu, nint instance, nint param);
    [DllImport("user32.dll")] static extern bool DestroyWindow(nint hwnd);
    [DllImport("user32.dll")] static extern nint SetCapture(nint hwnd);
    [DllImport("user32.dll")] static extern bool ReleaseCapture();
    [DllImport("user32.dll")] static extern bool GetClientRect(nint window, out NativeRect rect);
    [DllImport("user32.dll")] static extern nint LoadCursor(nint instance, nint name);
    [DllImport("user32.dll")] static extern nint SetCursor(nint cursor);
    [DllImport("user32.dll")] static extern nint BeginPaint(nint window, out PaintInfo paint);
    [DllImport("user32.dll")] static extern bool EndPaint(nint window, ref PaintInfo paint);
    [DllImport("user32.dll")] static extern int FillRect(nint dc, ref NativeRect rect, nint brush);
    [DllImport("gdi32.dll")] static extern nint CreateSolidBrush(uint color);
    [DllImport("gdi32.dll")] static extern bool DeleteObject(nint value);
    [StructLayout(LayoutKind.Sequential)] struct NativeRect { internal int Left, Top, Right, Bottom; }
    [StructLayout(LayoutKind.Sequential)] struct PaintInfo {
        internal nint Dc;
        internal int Erase;
        internal NativeRect Rect;
        internal int Restore, Update;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)] internal byte[] Reserved;
    }
    public GraphicsPreviewHost() {
        Focusable = true;
        IsVisibleChanged += (_, _) => { if (!IsVisible) { EndRotation(); HasPresentedFrame = false; } };
        Unloaded += (_, _) => EndRotation();
        PreviewKeyDown += (_, e) => {
            if (e.Key == Key.Home) { Rotation.Reset(); RotationChanged?.Invoke(this, EventArgs.Empty); e.Handled = true; }
        };
    }
    protected override HandleRef BuildWindowCore(HandleRef hwndParent) {
        var color = Palette.Background;
        loadingBrush = CreateSolidBrush((uint)(color.R | color.G << 8 | color.B << 16));
        // SS_NOTIFY makes the STATIC child return HTCLIENT. Without it Windows
        // treats the whole GPU surface as transparent to real mouse input.
        child = CreateWindowEx(0, "static", "Kevin GPU preview", unchecked((int)0x56000100), 0, 0, 1, 1, hwndParent.Handle, 0, 0, 0);
        if (child == 0) {
            int error = Marshal.GetLastWin32Error(); DeleteObject(loadingBrush); loadingBrush = 0;
            throw new System.ComponentModel.Win32Exception(error);
        }
        return new(this, child);
    }
    protected override void DestroyWindowCore(HandleRef hwnd) {
        EndRotation(); Renderer.Dispose(); DestroyWindow(hwnd.Handle); child = 0;
        if (loadingBrush != 0) DeleteObject(loadingBrush); loadingBrush = 0;
    }
    void PaintLoadingBackground(nint dc) {
        if (!HasPresentedFrame && dc != 0 && loadingBrush != 0 && GetClientRect(child, out var rect))
            FillRect(dc, ref rect, loadingBrush);
    }
    internal (int Width, int Height) PixelSize {
        get {
            if (child != 0 && GetClientRect(child, out var rect)) return (Math.Max(1, rect.Right - rect.Left), Math.Max(1, rect.Bottom - rect.Top));
            var dpi = VisualTreeHelper.GetDpi(this);
            return (Math.Max(1, (int)(ActualWidth * dpi.DpiScaleX)), Math.Max(1, (int)(ActualHeight * dpi.DpiScaleY)));
        }
    }
    void EndRotation() { if (!Rotation.Dragging) return; Rotation.End(); ReleaseCapture(); }
    protected override nint WndProc(nint hwnd, int message, nint wParam, nint lParam, ref bool handled) {
        long point = lParam.ToInt64(); var dpi = VisualTreeHelper.GetDpi(this);
        var location = new Point((short)(point & 65535) / dpi.DpiScaleX, (short)((point >> 16) & 65535) / dpi.DpiScaleY);
        switch (message) {
            case 0x000F: // Prevent STATIC's default white paint before the first GPU frame.
                var dc = BeginPaint(hwnd, out var paint);
                PaintLoadingBackground(dc); EndPaint(hwnd, ref paint);
                handled = true; return 0;
            case 0x0201: // WM_LBUTTONDOWN
                Focus(); Rotation.Begin(location); SetCapture(hwnd); handled = true; break;
            case 0x0200: // WM_MOUSEMOVE
                if (Rotation.Dragging) {
                    if ((wParam.ToInt64() & 1) == 0) EndRotation();
                    else if (Rotation.Move(location)) RotationChanged?.Invoke(this, EventArgs.Empty);
                    handled = true;
                }
                break;
            case 0x0202: EndRotation(); handled = true; break;
            case 0x020A: // WM_MOUSEWHEEL, including high-resolution wheel deltas
                if (Rotation.Scroll((short)((wParam.ToInt64() >> 16) & 65535)))
                    RotationChanged?.Invoke(this, EventArgs.Empty);
                handled = true; break;
            case 0x0215: Rotation.End(); break; // lost capture
            case 0x0020: // native child windows own their cursor
                if ((point & 65535) == 1) {
                    SetCursor(LoadCursor(0, Rotation.Dragging ? 32646 : 32649)); handled = true; return 1;
                }
                break;
            case 0x0014: PaintLoadingBackground(wParam); handled = true; return 1;
        }
        return handled ? 0 : base.WndProc(hwnd, message, wParam, lParam, ref handled);
    }
}
