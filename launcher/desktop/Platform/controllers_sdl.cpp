#include <SDL2/SDL.h>
#include <cstdint>
#include <array>
#include <algorithm>
struct ReoPad {uint16_t buttons;uint8_t lt,rt;int16_t lx,ly,rx,ry;};
namespace {
std::array<SDL_GameController*,4> pads{};
void refresh() {
    static bool ready=[](){SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");return SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER)==0;}();
    if(!ready)return;
    SDL_GameControllerUpdate();
    for(auto& pad:pads)if(pad&&!SDL_GameControllerGetAttached(pad)){SDL_GameControllerClose(pad);pad=nullptr;}
    for(int i=0;i<SDL_NumJoysticks();++i) {
        if(!SDL_IsGameController(i))continue;
        SDL_JoystickID id=SDL_JoystickGetDeviceInstanceID(i);
        bool found=false;
        for(auto* pad:pads)if(pad&&SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(pad))==id)found=true;
        if(!found)for(auto& pad:pads)if(!pad){pad=SDL_GameControllerOpen(i);break;}
    }
}
}
extern "C" int reo_controller_read(int index,ReoPad* result) {
    refresh();if(!result||index<0||index>=int(pads.size())||!pads[index])return 0;
    auto* pad=pads[index];*result={};
    const SDL_GameControllerButton source[]={SDL_CONTROLLER_BUTTON_DPAD_UP,SDL_CONTROLLER_BUTTON_DPAD_DOWN,SDL_CONTROLLER_BUTTON_DPAD_LEFT,SDL_CONTROLLER_BUTTON_DPAD_RIGHT,SDL_CONTROLLER_BUTTON_START,SDL_CONTROLLER_BUTTON_BACK,SDL_CONTROLLER_BUTTON_LEFTSTICK,SDL_CONTROLLER_BUTTON_RIGHTSTICK,SDL_CONTROLLER_BUTTON_LEFTSHOULDER,SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,SDL_CONTROLLER_BUTTON_A,SDL_CONTROLLER_BUTTON_B,SDL_CONTROLLER_BUTTON_X,SDL_CONTROLLER_BUTTON_Y};
    const uint16_t bits[]={1,2,4,8,0x10,0x20,0x40,0x80,0x100,0x200,0x1000,0x2000,0x4000,0x8000};
    for(unsigned i=0;i<14;++i)if(SDL_GameControllerGetButton(pad,source[i]))result->buttons|=bits[i];
    result->lt=uint8_t(std::max(0,int(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERLEFT)))*255/32767);
    result->rt=uint8_t(std::max(0,int(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERRIGHT)))*255/32767);
    auto inverted=[](int16_t value){return int16_t(std::clamp(-int(value),-32768,32767));};
    result->lx=SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_LEFTX);result->ly=inverted(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_LEFTY));
    result->rx=SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_RIGHTX);result->ry=inverted(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_RIGHTY));return 1;
}
extern "C" void reo_controller_rumble(int index,uint16_t left,uint16_t right) {
    if(index>=0&&index<int(pads.size())&&pads[index])SDL_GameControllerRumble(pads[index],left,right,200);
}
