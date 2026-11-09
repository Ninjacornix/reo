#include "raylib.h"
#include <cstdio>
#include <chrono>
#include <thread>
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void*,void*,int,int,int,int,unsigned int);
extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();
int main(){
 const auto foreground=GetForegroundWindow();SetTraceLogLevel(LOG_WARNING);
 SetConfigFlags(FLAG_WINDOW_HIDDEN|FLAG_WINDOW_ALWAYS_RUN|FLAG_WINDOW_RESIZABLE);
 InitWindow(320,240,"Owned background capture probe");if(!IsWindowReady())return 2;
 if(!SetWindowPos(GetWindowHandle(),reinterpret_cast<void*>(1),0,0,0,0,0x53))return 3;
 SetTargetFPS(30);std::puts("ready");std::fflush(stdout);
 const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(10);unsigned frames{};
 while(std::chrono::steady_clock::now()<end&&!WindowShouldClose()){
  BeginDrawing();ClearBackground(MAGENTA);DrawRectangle(32,32,256,176,GREEN);EndDrawing();++frames;
 }
 const bool same=GetForegroundWindow()==foreground;CloseWindow();
 std::printf("{\"frames\":%u,\"foreground_unchanged\":%s,\"focus_requested\":false}\n",frames,same?"true":"false");return 0;
}
