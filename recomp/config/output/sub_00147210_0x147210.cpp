#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00147210
// Address: 0x147210 - 0x147298
void sub_00147210_0x147210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x147210u;

    // 0x147210: 0x27bdffd0
    ctx->pc = 0x147210u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x147214: 0xffb10010
    ctx->pc = 0x147214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x147218: 0xffb00000
    ctx->pc = 0x147218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14721c: 0xa0882d
    ctx->pc = 0x14721cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147220: 0xffbf0020
    ctx->pc = 0x147220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x147224: 0xc047598
    ctx->pc = 0x147224u;
    SET_GPR_U32(ctx, 31, 0x14722Cu);
    ctx->pc = 0x147228u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14722Cu; }
    }
    if (ctx->pc != 0x14722Cu) { return; }
    ctx->pc = 0x14722Cu;
    // 0x14722c: 0x3c030fff
    ctx->pc = 0x14722cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x147230: 0x3c051000
    ctx->pc = 0x147230u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x147234: 0x3463ffff
    ctx->pc = 0x147234u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x147238: 0x3c068000
    ctx->pc = 0x147238u;
    SET_GPR_U32(ctx, 6, ((uint32_t)32768 << 16));
    // 0x14723c: 0x2038024
    ctx->pc = 0x14723cu;
    SET_GPR_U32(ctx, 16, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x147240: 0x34a5b010
    ctx->pc = 0x147240u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 45072));
    // 0x147244: 0x2068025
    ctx->pc = 0x147244u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x147248: 0x3c041000
    ctx->pc = 0x147248u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x14724c: 0xacb00000
    ctx->pc = 0x14724cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 16));
    // 0x147250: 0x3484b020
    ctx->pc = 0x147250u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45088));
    // 0x147254: 0x118903
    ctx->pc = 0x147254u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 4));
    // 0x147258: 0x3c031000
    ctx->pc = 0x147258u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x14725c: 0xac910000
    ctx->pc = 0x14725cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x147260: 0x3463b000
    ctx->pc = 0x147260u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 45056));
    // 0x147264: 0x24040100
    ctx->pc = 0x147264u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 256));
    // 0x147268: 0xac640000
    ctx->pc = 0x147268u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x14726c: 0x10400005
    ctx->pc = 0x14726Cu;
    {
        const bool branch_taken_0x14726c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147270u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x14726c) {
            ctx->pc = 0x147284u;
            goto label_147284;
        }
    }
    ctx->pc = 0x147274u;
    // 0x147274: 0xdfb10010
    ctx->pc = 0x147274u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147278: 0xdfb00000
    ctx->pc = 0x147278u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14727c: 0x80475ae
    ctx->pc = 0x14727Cu;
    ctx->pc = 0x147280u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x147284u;
label_147284:
    // 0x147284: 0xdfb10010
    ctx->pc = 0x147284u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147288: 0xdfb00000
    ctx->pc = 0x147288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14728c: 0x3e00008
    ctx->pc = 0x14728Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147290u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147284u: goto label_147284;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147294u;
    // 0x147294: 0x0
    ctx->pc = 0x147294u;
    // NOP
}
