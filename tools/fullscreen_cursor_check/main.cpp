#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <stdexcept>

void ps2InstallModalRender(void*,void(*)());

namespace {
LRESULT CALLBACK windowProc(HWND window,UINT message,WPARAM w,LPARAM l) {
    return DefWindowProcW(window,message,w,l);
}
void pump() {
    const auto until=GetTickCount64()+120;
    do {
        MSG message;
        while(PeekMessageW(&message,nullptr,0,0,PM_REMOVE)) {
            TranslateMessage(&message);DispatchMessageW(&message);
        }
        Sleep(5);
    } while(GetTickCount64()<until);
}
bool cursorVisible() {
    CURSORINFO cursor{sizeof(CURSORINFO)};
    if(!GetCursorInfo(&cursor)) throw std::runtime_error("Cannot inspect desktop cursor");
    return (cursor.flags&CURSOR_SHOWING) && cursor.hCursor;
}
void activate(HWND window) {
    const auto own=GetCurrentThreadId();
    const auto foreground=GetWindowThreadProcessId(GetForegroundWindow(),nullptr);
    const bool attached=foreground!=own && AttachThreadInput(own,foreground,TRUE);
    SetForegroundWindow(window);SetActiveWindow(window);SetFocus(window);
    if(attached) AttachThreadInput(own,foreground,FALSE);
    pump();
    if(GetForegroundWindow()!=window) throw std::runtime_error("Cannot focus owned test window");
}
void atClient(HWND window) {
    POINT point{120,120};ClientToScreen(window,&point);SetCursorPos(point.x,point.y);
    SendMessageW(window,WM_SETCURSOR,reinterpret_cast<WPARAM>(window),MAKELPARAM(HTCLIENT,WM_MOUSEMOVE));
    pump();
}
struct RestoreDesktop {
    HWND foreground=GetForegroundWindow();
    POINT cursor{};
    RestoreDesktop() {GetCursorPos(&cursor);}
    ~RestoreDesktop() {
        SetCursor(LoadCursorW(nullptr,MAKEINTRESOURCEW(32512)));
        if(IsWindow(foreground)) SetForegroundWindow(foreground);
        SetCursorPos(cursor.x,cursor.y);
    }
};
}
int main() {
    RestoreDesktop restore;
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    WNDCLASSW type{};type.lpfnWndProc=windowProc;type.hInstance=GetModuleHandleW(nullptr);
    type.lpszClassName=L"REO-Fullscreen-Cursor-Check";type.hCursor=LoadCursorW(nullptr,MAKEINTRESOURCEW(32512));
    if(!RegisterClassW(&type)) return 2;
    HWND game=CreateWindowW(type.lpszClassName,L"Outbreak cursor check",WS_OVERLAPPEDWINDOW,
                            120,100,680,480,nullptr,nullptr,type.hInstance,nullptr);
    HWND other=CreateWindowW(type.lpszClassName,L"Cursor focus check",WS_OVERLAPPEDWINDOW,
                             160,120,580,440,nullptr,nullptr,type.hInstance,nullptr);
    unsigned checks=0;
    auto check=[&](bool result,const char* label) {
        if(!result) throw std::runtime_error(label);
        ++checks;std::cout << "PASS " << label << '\n';
    };
    int result=0;
    try {
        ps2InstallModalRender(game,+[]{});
        ShowWindow(game,SW_SHOW);activate(game);atClient(game);
        check(cursorVisible(),"windowed cursor visible");
        MONITORINFO monitor{sizeof(MONITORINFO)};
        if(!GetMonitorInfoW(MonitorFromWindow(game,MONITOR_DEFAULTTONEAREST),&monitor))
            throw std::runtime_error("Cannot inspect monitor");
        // Same style/placement changes used by the launcher's Fullscreen option.
        SetWindowLongPtrW(game,GWL_STYLE,GetWindowLongPtrW(game,GWL_STYLE)&~WS_OVERLAPPEDWINDOW);
        SetWindowPos(game,HWND_TOP,monitor.rcMonitor.left,monitor.rcMonitor.top,
                     monitor.rcMonitor.right-monitor.rcMonitor.left,monitor.rcMonitor.bottom-monitor.rcMonitor.top,
                     SWP_FRAMECHANGED);
        pump();atClient(game);
        if(cursorVisible()) {
            RECT bounds{};GetWindowRect(game,&bounds);POINT pos{};GetCursorPos(&pos);
            std::cerr << "diagnostic foreground=" << GetForegroundWindow() << " game=" << game
                      << " cursor=" << GetCursor() << " rect=" << bounds.left << ',' << bounds.top << ','
                      << bounds.right << ',' << bounds.bottom << " monitor=" << monitor.rcMonitor.left << ','
                      << monitor.rcMonitor.top << ',' << monitor.rcMonitor.right << ',' << monitor.rcMonitor.bottom
                      << " pointer=" << pos.x << ',' << pos.y << " style=" << GetWindowLongPtrW(game,GWL_STYLE) << '\n';
        }
        check(!cursorVisible(),"launcher-style fullscreen hides cursor");
        atClient(game);check(!cursorVisible(),"mouse movement keeps fullscreen cursor hidden");
        ShowWindow(other,SW_SHOW);activate(other);atClient(other);
        check(cursorVisible(),"switching windows restores desktop cursor");
        activate(game);atClient(game);
        check(!cursorVisible(),"returning to fullscreen hides cursor");
        // Exercise the existing Ctrl+Enter window procedure without entering any game buttons.
        BYTE keys[256]{};GetKeyboardState(keys);BYTE pressed[256]{};CopyMemory(pressed,keys,sizeof(keys));
        pressed[VK_CONTROL]=pressed[VK_LCONTROL]=0x80;SetKeyboardState(pressed);
        SendMessageW(game,WM_KEYDOWN,VK_RETURN,0);SetKeyboardState(keys);
        SendMessageW(game,WM_KEYUP,VK_RETURN,0);pump();atClient(game);
        check(cursorVisible(),"Ctrl+Enter windowed mode restores cursor");
        SetKeyboardState(pressed);SendMessageW(game,WM_KEYDOWN,VK_RETURN,0);SetKeyboardState(keys);
        SendMessageW(game,WM_KEYUP,VK_RETURN,0);pump();atClient(game);
        check(!cursorVisible(),"Ctrl+Enter fullscreen hides cursor");
        DestroyWindow(game);game=nullptr;pump();activate(other);atClient(other);
        check(cursorVisible(),"closing fullscreen restores cursor");
    } catch(const std::exception& error) {
        std::cerr << "FAIL " << error.what() << '\n';result=1;
    }
    if(game) DestroyWindow(game);
    if(other) DestroyWindow(other);
    std::cout << "Cursor checks: " << checks << '\n';
    return result;
}
