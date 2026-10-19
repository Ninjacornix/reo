#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

bool ps2VifKickVuProfileActive() noexcept;

namespace {
unsigned failures = 0;
void check(bool value, const char* name) {
    failures += !value;
    std::printf("%s %s\n", value ? "PASS" : "FAIL", name);
}
void entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    rt->Store32(ram, ctx, 0x1000E000, 1);
    // Upload two actual pairs. E takes effect after its following pair;
    // that delay pair executes IADDIU vi1,vi0,5 before stopping at PC16.
    const uint32_t packet[] = {0x4A020000u, 0x8000033Cu, 0x400002FFu, 0x10010005u,
                               0x000002FFu, 0x14000000u, 0,           0};
    std::memcpy(ram + 0x20000, packet, sizeof(packet));
    rt->Store32(ram, ctx, 0x10009010, 0x20000);
    rt->Store32(ram, ctx, 0x10009020, 2);
    check(!ps2VifKickVuProfileActive(), "aggregate scope absent before the DMA write");
    rt->Store32(ram, ctx, 0x10009000, 0x100);
    check(!ps2VifKickVuProfileActive(), "aggregate scope restored after the DMA write");
    check(rt->vu1().state().vi[1] == 5, "real MPG/MSCAL executes the E delay pair");
    check(rt->vu1().state().pc == 16 && rt->vu1().state().ebit,
          "VU ends at the original delay-pair boundary");
    check(std::memcmp(rt->memory().getVU1Code(), packet + 1, 16) == 0,
          "uploaded microcode preserved");
    check((rt->Load32(ram, ctx, 0x1000E010) & 2u) != 0, "actual VIF DMA completion published");
    check(std::memcmp(ram + 0x20000, packet, sizeof(packet)) == 0, "DMA input preserved");
    ctx->pc = 0;
    rt->requestStop();
}
} // namespace
int main(int argc, char** argv) {
    _putenv_s("REO_HEADLESS", "1");
    const bool disabled = argc > 1 && std::strcmp(argv[1], "--disabled") == 0;
    _putenv_s("REO_VIF_KICK_TIMING_AT", disabled ? "" : "0");
    _putenv_s("REO_VIF_KICK_TIMING_MIN_US", "0");
    _putenv_s("REO_VIF_KICK_TIMING_LIMIT", "4");
    PS2Runtime rt;
    if (!rt.initialize("VIF VU aggregate profile"))
        return 2;
    rt.registerFunction(0x10000, entry);
    rt.cpu().pc = 0x10000;
    rt.run();
    std::printf("VIF VU aggregate: %s failures=%u\n", failures ? "FAIL" : "PASS", failures);
    return failures ? 1 : 0;
}
