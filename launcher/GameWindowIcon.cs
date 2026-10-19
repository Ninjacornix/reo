using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal static class GameWindowIcon {
    [DllImport("user32", CharSet = CharSet.Unicode)]
    static extern nint LoadImageW(nint instance, string name, uint type, int width, int height,
                                  uint flags);
    [DllImport("user32")]
    static extern nint SendMessageTimeoutW(nint window, uint message, nuint wParam, nint lParam,
                                           uint flags, uint timeout, out nuint result);
    [DllImport("user32")]
    static extern bool DestroyIcon(nint icon);

    public static async Task Apply(Process process, nint window) {
        string file = Path.Combine(AppContext.BaseDirectory, "Assets", "app-icon.ico");
        if (!File.Exists(file))
            return;
        nint large = LoadImageW(0, file, 1, 32, 32, 0x10);
        nint small = LoadImageW(0, file, 1, 16, 16, 0x10);
        try {
            bool largeSet = large == 0, smallSet = small == 0;
            for (int attempt = 0; attempt < 80 && !process.HasExited; ++attempt) {
                if (!largeSet)
                    largeSet = SendMessageTimeoutW(window, 0x80, 1, large, 2, 100, out _) != 0;
                if (!smallSet)
                    smallSet = SendMessageTimeoutW(window, 0x80, 0, small, 2, 100, out _) != 0;
                if (largeSet && smallSet)
                    break;
                await Task.Delay(100);
            }
            await process.WaitForExitAsync();
        } catch (InvalidOperationException) {
        } finally {
            if (large != 0)
                DestroyIcon(large);
            if (small != 0)
                DestroyIcon(small);
        }
    }
}
