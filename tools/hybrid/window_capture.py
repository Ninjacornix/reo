"""Capture an owned game window with PrintWindow(PW_RENDERFULLCONTENT).

Works when other windows cover the game, unlike desktop capture. Read-only:
never changes window z-order, focus or the game process.
"""
import ctypes
import ctypes.wintypes as wt
from PIL import Image

user = ctypes.WinDLL('user32', use_last_error=True)
gdi = ctypes.WinDLL('gdi32', use_last_error=True)
PW_CLIENTONLY, PW_RENDERFULLCONTENT = 1, 2


class BITMAPINFOHEADER(ctypes.Structure):
    _fields_ = [('biSize', wt.DWORD), ('biWidth', wt.LONG), ('biHeight', wt.LONG), ('biPlanes', wt.WORD),
                ('biBitCount', wt.WORD), ('biCompression', wt.DWORD), ('biSizeImage', wt.DWORD),
                ('biXPelsPerMeter', wt.LONG), ('biYPelsPerMeter', wt.LONG), ('biClrUsed', wt.DWORD),
                ('biClrImportant', wt.DWORD)]


def _window(pid):
    found = []
    cb = ctypes.WINFUNCTYPE(ctypes.c_int, wt.HWND, wt.LPARAM)

    def visit(hwnd, _):
        owner = wt.DWORD()
        user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
        rect = wt.RECT()
        if owner.value == pid and user.IsWindowVisible(hwnd) and user.GetClientRect(hwnd, ctypes.byref(rect)):
            area = (rect.right - rect.left) * (rect.bottom - rect.top)
            if area > 0:
                found.append((area, hwnd, rect.right - rect.left, rect.bottom - rect.top))
        return 1
    user.EnumWindows(cb(visit), 0)
    if not found:
        raise ValueError('Owned window not visible')
    return max(found)[1:]


def capture(identity, path):
    hwnd, width, height = _window(identity['pid'])
    window_dc = user.GetDC(hwnd)
    memory_dc = gdi.CreateCompatibleDC(window_dc)
    bitmap = gdi.CreateCompatibleBitmap(window_dc, width, height)
    old = gdi.SelectObject(memory_dc, bitmap)
    try:
        if not user.PrintWindow(hwnd, memory_dc, PW_CLIENTONLY | PW_RENDERFULLCONTENT):
            raise ctypes.WinError(ctypes.get_last_error())
        header = BITMAPINFOHEADER(ctypes.sizeof(BITMAPINFOHEADER), width, -height, 1, 32, 0, 0, 0, 0, 0, 0)
        buffer = ctypes.create_string_buffer(width * height * 4)
        if not gdi.GetDIBits(memory_dc, bitmap, 0, height, buffer, ctypes.byref(header), 0):
            raise ctypes.WinError(ctypes.get_last_error())
        Image.frombuffer('RGBA', (width, height), buffer, 'raw', 'BGRA', 0, 1).convert('RGB').save(path)
        return {'path': str(path), 'width': width, 'height': height, 'method': 'PrintWindow'}
    finally:
        gdi.SelectObject(memory_dc, old)
        gdi.DeleteObject(bitmap)
        gdi.DeleteDC(memory_dc)
        user.ReleaseDC(hwnd, window_dc)
