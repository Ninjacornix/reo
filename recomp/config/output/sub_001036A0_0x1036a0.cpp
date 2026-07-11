#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001036A0
// Address: 0x1036a0 - 0x103750
void sub_001036A0_0x1036a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1036a0u;

    // 0x1036a0: 0x27bdffd0
    ctx->pc = 0x1036a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1036a4: 0xffb10010
    ctx->pc = 0x1036a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1036a8: 0xffbf0020
    ctx->pc = 0x1036a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1036ac: 0x80882d
    ctx->pc = 0x1036acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1036b0: 0xc047598
    ctx->pc = 0x1036B0u;
    SET_GPR_U32(ctx, 31, 0x1036B8u);
    ctx->pc = 0x1036B4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1036B8u; }
    }
    if (ctx->pc != 0x1036B8u) { return; }
    ctx->pc = 0x1036B8u;
    // 0x1036b8: 0x40382d
    ctx->pc = 0x1036b8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1036bc: 0x3c040001
    ctx->pc = 0x1036bcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1036c0: 0x3c021000
    ctx->pc = 0x1036c0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1036c4: 0x3442f520
    ctx->pc = 0x1036c4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 62752));
    // 0x1036c8: 0x8c460000
    ctx->pc = 0x1036c8u;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1036cc: 0xc41824
    ctx->pc = 0x1036ccu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1036d0: 0x14600005
    ctx->pc = 0x1036D0u;
    {
        const bool branch_taken_0x1036d0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1036D4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1036d0) {
            ctx->pc = 0x1036E8u;
            goto label_1036e8;
        }
    }
    ctx->pc = 0x1036D8u;
    // 0x1036d8: 0xc41825
    ctx->pc = 0x1036d8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1036dc: 0x3442f590
    ctx->pc = 0x1036dcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 62864));
    // 0x1036e0: 0xac430000
    ctx->pc = 0x1036e0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1036e4: 0x3c021000
    ctx->pc = 0x1036e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_1036e8:
    // 0x1036e8: 0x3c04ffff
    ctx->pc = 0x1036e8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
    // 0x1036ec: 0x3442e000
    ctx->pc = 0x1036ecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57344));
    // 0x1036f0: 0x3484feff
    ctx->pc = 0x1036f0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 65279));
    // 0x1036f4: 0x8c450000
    ctx->pc = 0x1036f4u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1036f8: 0x3c031000
    ctx->pc = 0x1036f8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1036fc: 0x8e300000
    ctx->pc = 0x1036fcu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x103700: 0x3463f590
    ctx->pc = 0x103700u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 62864));
    // 0x103704: 0x2042024
    ctx->pc = 0x103704u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x103708: 0xae240000
    ctx->pc = 0x103708u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
    // 0x10370c: 0xac660000
    ctx->pc = 0x10370cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x103710: 0x10e00004
    ctx->pc = 0x103710u;
    {
        const bool branch_taken_0x103710 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        ctx->pc = 0x103714u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x103710) {
            ctx->pc = 0x103724u;
            goto label_103724;
        }
    }
    ctx->pc = 0x103718u;
    // 0x103718: 0xc0475ae
    ctx->pc = 0x103718u;
    SET_GPR_U32(ctx, 31, 0x103720u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103720u; }
    }
    if (ctx->pc != 0x103720u) { return; }
    ctx->pc = 0x103720u;
    // 0x103720: 0x200102d
    ctx->pc = 0x103720u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_103724:
    // 0x103724: 0xdfbf0020
    ctx->pc = 0x103724u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x103728: 0xdfb10010
    ctx->pc = 0x103728u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10372c: 0xdfb00000
    ctx->pc = 0x10372cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103730: 0x3e00008
    ctx->pc = 0x103730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103734u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1036E8u: goto label_1036e8;
            case 0x103724u: goto label_103724;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103738u;
    // 0x103738: 0x8c820000
    ctx->pc = 0x103738u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10373c: 0xac850000
    ctx->pc = 0x10373cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x103740: 0x21202
    ctx->pc = 0x103740u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x103744: 0x3e00008
    ctx->pc = 0x103744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103748u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1036E8u: goto label_1036e8;
            case 0x103724u: goto label_103724;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10374Cu;
    // 0x10374c: 0x0
    ctx->pc = 0x10374cu;
    // NOP
}
