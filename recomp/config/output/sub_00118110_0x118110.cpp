#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00118110
// Address: 0x118110 - 0x118170
void sub_00118110_0x118110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x118110u;

    // 0x118110: 0x27bdffc0
    ctx->pc = 0x118110u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x118114: 0x2403ffff
    ctx->pc = 0x118114u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x118118: 0xffb00020
    ctx->pc = 0x118118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x11811c: 0x3c100021
    ctx->pc = 0x11811cu;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x118120: 0xffbf0030
    ctx->pc = 0x118120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x118124: 0x8e029de8
    ctx->pc = 0x118124u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
    // 0x118128: 0x1443000d
    ctx->pc = 0x118128u;
    {
        const bool branch_taken_0x118128 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x11812Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x118128) {
            ctx->pc = 0x118160u;
            goto label_118160;
        }
    }
    ctx->pc = 0x118130u;
    // 0x118130: 0x24020001
    ctx->pc = 0x118130u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x118134: 0xafa00014
    ctx->pc = 0x118134u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x118138: 0xafa20004
    ctx->pc = 0x118138u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x11813c: 0x3a0202d
    ctx->pc = 0x11813cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118140: 0xc045188
    ctx->pc = 0x118140u;
    SET_GPR_U32(ctx, 31, 0x118148u);
    ctx->pc = 0x118144u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118148u; }
    }
    if (ctx->pc != 0x118148u) { return; }
    ctx->pc = 0x118148u;
    // 0x118148: 0xae029de8
    ctx->pc = 0x118148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942184), GPR_U32(ctx, 2));
    // 0x11814c: 0xc045188
    ctx->pc = 0x11814Cu;
    SET_GPR_U32(ctx, 31, 0x118154u);
    ctx->pc = 0x118150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118154u; }
    }
    if (ctx->pc != 0x118154u) { return; }
    ctx->pc = 0x118154u;
    // 0x118154: 0x3c030021
    ctx->pc = 0x118154u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x118158: 0xac629dec
    ctx->pc = 0x118158u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942188), GPR_U32(ctx, 2));
    // 0x11815c: 0xdfbf0030
    ctx->pc = 0x11815cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_118160:
    // 0x118160: 0xdfb00020
    ctx->pc = 0x118160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118164: 0x3e00008
    ctx->pc = 0x118164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118168u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118160u: goto label_118160;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11816Cu;
    // 0x11816c: 0x0
    ctx->pc = 0x11816cu;
    // NOP
}
