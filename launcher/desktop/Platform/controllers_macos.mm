#import <AppKit/AppKit.h>
#import <GameController/GameController.h>
#import <CoreHaptics/CoreHaptics.h>
#include <cstdint>
#include <cmath>
#include <algorithm>

struct ReoPad {uint16_t buttons;uint8_t lt,rt;int16_t lx,ly,rx,ry;};
extern "C" int reo_trash_path(const char* path) {
    @autoreleasepool {
        if(!path)return 0;
        NSURL* url=[NSURL fileURLWithPath:[NSString stringWithUTF8String:path]];
        return [[NSFileManager defaultManager]trashItemAtURL:url resultingItemURL:nil error:nil]?1:0;
    }
}
extern "C" int reo_controller_read(int index,ReoPad* result) {
    if(!result||![NSThread isMainThread]||index<0)return 0;
    NSArray<GCController*>* devices=GCController.controllers;
    if(index>=devices.count)return 0;
    GCExtendedGamepad* p=devices[index].extendedGamepad;
    if(!p)return 0;
    *result={};
    auto bit=[&](GCControllerButtonInput* button,uint16_t mask){if(button.pressed)result->buttons|=mask;};
    bit(p.dpad.up,1);bit(p.dpad.down,2);bit(p.dpad.left,4);bit(p.dpad.right,8);
    bit(p.buttonMenu,0x10);bit(p.buttonOptions,0x20);bit(p.leftThumbstickButton,0x40);bit(p.rightThumbstickButton,0x80);
    bit(p.leftShoulder,0x100);bit(p.rightShoulder,0x200);
    bit(p.buttonA,0x1000);bit(p.buttonB,0x2000);bit(p.buttonX,0x4000);bit(p.buttonY,0x8000);
    result->lt=uint8_t(std::lround(p.leftTrigger.value*255));result->rt=uint8_t(std::lround(p.rightTrigger.value*255));
    auto axis=[](float v){return int16_t(std::lround(v*(v<0?32768:32767)));};
    result->lx=axis(p.leftThumbstick.xAxis.value);result->ly=axis(p.leftThumbstick.yAxis.value);
    result->rx=axis(p.rightThumbstick.xAxis.value);result->ry=axis(p.rightThumbstick.yAxis.value);
    return 1;
}
extern "C" void reo_controller_rumble(int index,uint16_t left,uint16_t right) {
    if(![NSThread isMainThread]||index<0||index>=GCController.controllers.count)return;
    static NSMutableDictionary<NSNumber*,CHHapticEngine*>* engines=[NSMutableDictionary new];
    NSNumber* key=@(index);
    CHHapticEngine* engine=engines[key];
    if(!engine){engine=[GCController.controllers[index].haptics createEngineWithLocality:GCHapticsLocalityDefault];if(engine)engines[key]=engine;}
    if(!engine||(!left&&!right)||![engine startAndReturnError:nil])return;
    float intensity=std::max(left,right)/65535.f;
    CHHapticEventParameter* level=[[CHHapticEventParameter alloc]initWithParameterID:CHHapticEventParameterIDHapticIntensity value:intensity];
    CHHapticEvent* event=[[CHHapticEvent alloc]initWithEventType:CHHapticEventTypeHapticContinuous parameters:@[level] relativeTime:0 duration:.2];
    CHHapticPattern* pattern=[[CHHapticPattern alloc]initWithEvents:@[event] parameters:@[] error:nil];
    [[engine createPlayerWithPattern:pattern error:nil]startAtTime:CHHapticTimeImmediate error:nil];
}
