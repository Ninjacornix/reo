#include "../../runtime/input/pad2_rumble.h"
#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    using namespace reo::pad2;
    unsigned checks=0;
    auto check=[&](bool value) {
        if(!value) throw std::runtime_error("libpad2 rumble check failed");
        ++checks;
    };
    // Captured command form: 1A6F90 sends one actuator-mask byte and two
    // packed data bytes through 189880/189420. Level 4 encodes 8F as 1F 01.
    std::vector<uint8_t> request{
        0,0,0,0, 0x0b,0x40,3,1, 40,0,0,0,
        1,0,0,0, 2,0,0,0, 0x1f,1,3
    };
    request.resize(0x1090);
    auto output=decodeOutput(0x8000131b,0,request,{});
    check(output.kind==OutputKind::Motors && output.motors==Motors{143*257,65535});
    for(unsigned large=0;large<256;++large) for(unsigned small=0;small<2;++small) {
        request[20]=uint8_t((large<<1)|small);request[21]=uint8_t(large>>7);
        auto result=decodeOutput(0x8000131b,0,request,{});
        check(result.kind==OutputKind::Motors && result.motors==Motors{uint16_t(large*257),uint16_t(small*65535)});
    }
    request[20]=request[21]=0;
    check(decodeOutput(0x8000131b,0,request,{60000,65535}).motors==Motors{});
    request[16]=1;request[20]=0;request[21]=1;
    check(decodeOutput(0x8000131b,0,request,{12345,65535}).motors==Motors{12345,0});
    request[20]=128;request[21]=2;
    check(decodeOutput(0x8000131b,0,request,{0,65535}).motors==Motors{128*257,65535});
    check(decodeOutput(0x8000131b,1,request,{}).kind==OutputKind::Unhandled);
    check(decodeOutput(0x8000131a,0,request,{}).kind==OutputKind::Unhandled);
    for(size_t size=0;size<22;++size)
        check(decodeOutput(0x8000131b,0,std::span(request).first(size),{}).kind==OutputKind::Unhandled);
    for(unsigned mask:{0u,3u,4u,255u}) {
        request[21]=uint8_t(mask);
        check(decodeOutput(0x8000131b,0,request,{}).kind==OutputKind::Unhandled);
    }
    request[21]=2;request[8]=0xff;request[9]=0xff;
    check(decodeOutput(0x8000131b,0,request,{}).kind==OutputKind::Unhandled);
    request[8]=40;request[9]=0;request[12]=2;
    check(decodeOutput(0x8000131b,0,request,{}).kind==OutputKind::Unhandled);
    const std::array<uint8_t,12> query{0,0,0,0,2,0x80,3,1,0,0,0,0};
    check(decodeOutput(0x8000131a,0,query,{}).kind==OutputKind::Profile);
    check(decodeOutput(0x8000131a,3,query,{}).kind==OutputKind::Unhandled);
    check(decodeOutput(0x8000131b,0,query,{}).kind==OutputKind::Unhandled);
    std::cout << "PASS " << checks << " libpad2 rumble checks: motor packing, partial/zero updates, profiles, socket isolation and invalid requests\n";
}
