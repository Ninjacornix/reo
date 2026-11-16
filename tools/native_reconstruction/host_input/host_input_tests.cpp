#include "runtime/input/input.h"
#include <windows.h>
#include <xinput.h>
#include <array>
#include <iostream>
#include <stdexcept>

namespace {
std::array<bool,2> connected{};std::array<XINPUT_STATE,2> physical{};
std::array<bool,256> keys{};unsigned checks{};
HWND active_window=reinterpret_cast<HWND>(0x1234);bool minimized{};DWORD window_process=17;
void check(bool value){++checks;if(!value)throw std::runtime_error("native input host test failed");}
}
DWORD XInputGetState(DWORD port,XINPUT_STATE* out){
    if(port>=connected.size()||!connected[port])return 1167;
    *out=physical[port];return ERROR_SUCCESS;
}
SHORT GetAsyncKeyState(int key){return key>=0&&key<int(keys.size())&&keys[std::size_t(key)]?SHORT(-32768):0;}
bool IsWindow(HWND window){return window==reinterpret_cast<HWND>(0x1234);}
DWORD GetWindowThreadProcessId(HWND,DWORD* process){*process=window_process;return 3;}
DWORD GetCurrentProcessId(){return 17;}
HWND GetForegroundWindow(){return active_window;}
bool IsIconic(HWND){return minimized;}
int main()try{
    reo::Input input;check(!input.poll_native(true));check(input.init());
    keys['W']=true;auto state=input.poll_native(true);check(bool(state));
    check(state->focused&&!state->ports[0].physical_connected&&state->ports[0].keyboard_available&&
          !(state->ports[0].pad.buttons&reo::PS2_UP)&&state->ports[0].pad.left_y==0);
    check(!state->ports[1].physical_connected&&!state->ports[1].keyboard_available&&state->ports[1].pad.buttons==0xffff);
    auto unfocused=input.poll_native(false);check(bool(unfocused)&&!unfocused->focused&&unfocused->ports[0].keyboard_available&&
        unfocused->ports[0].pad.buttons==0xffff&&unfocused->ports[0].pad.left_y==128);
    connected[0]=true;connected[1]=true;physical[0].Gamepad.wButtons=XINPUT_GAMEPAD_A;
    physical[0].Gamepad.sThumbLX=32767;physical[1].Gamepad.wButtons=XINPUT_GAMEPAD_B;
    state=input.poll_native(true);check(state&&state->ports[0].physical_connected&&state->ports[1].physical_connected);
    check(!(state->ports[0].pad.buttons&reo::PS2_CROSS)&&(state->ports[0].pad.buttons&reo::PS2_UP)&&state->ports[0].pad.left_x==255);
    check(!(state->ports[1].pad.buttons&reo::PS2_CIRCLE));
    unfocused=input.poll_native(false);check(unfocused&&unfocused->ports[0].physical_connected&&unfocused->ports[1].physical_connected&&
        unfocused->ports[0].pad.buttons==0xffff&&unfocused->ports[1].pad.buttons==0xffff);
    connected[0]=false;connected[1]=false;state=input.poll_native(true);
    check(state&&!state->ports[0].physical_connected&&!state->ports[1].physical_connected&&
        !(state->ports[0].pad.buttons&reo::PS2_UP)&&state->ports[1].pad.buttons==0xffff);
    connected[1]=true;physical[1].Gamepad.wButtons=XINPUT_GAMEPAD_Y;state=input.poll_native(true);
    check(state&&state->ports[1].physical_connected&&!(state->ports[1].pad.buttons&reo::PS2_TRIANGLE));
    check(!input.poll_native_window(nullptr)&&!input.poll_native_window(reinterpret_cast<HWND>(0x9999)));
    window_process=18;check(!input.poll_native_window(reinterpret_cast<HWND>(0x1234)));window_process=17;
    state=input.poll_native_window(reinterpret_cast<HWND>(0x1234));check(state&&state->focused);
    active_window=nullptr;state=input.poll_native_window(reinterpret_cast<HWND>(0x1234));check(state&&!state->focused&&state->ports[0].pad.buttons==0xffff);
    active_window=reinterpret_cast<HWND>(0x1234);minimized=true;state=input.poll_native_window(active_window);check(state&&!state->focused);
    input.shutdown();check(!input.poll_native(true));
    std::cout<<"{\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
