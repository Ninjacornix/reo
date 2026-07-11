#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001133F0
// Address: 0x1133f0 - 0x113488
void sub_001133F0_0x1133f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1133f0u;

    // 0x1133f0: 0x27bdffe0
    ctx->pc = 0x1133f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1133f4: 0xffb00000
    ctx->pc = 0x1133f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1133f8: 0xffbf0010
    ctx->pc = 0x1133f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1133fc: 0xc0449be
    ctx->pc = 0x1133FCu;
    SET_GPR_U32(ctx, 31, 0x113404u);
    ctx->pc = 0x1126F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113404u; }
    }
    if (ctx->pc != 0x113404u) { return; }
    ctx->pc = 0x113404u;
    // 0x113404: 0x40802d
    ctx->pc = 0x113404u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113408: 0x8e020008
    ctx->pc = 0x113408u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11340c: 0x14400010
    ctx->pc = 0x11340Cu;
    {
        const bool branch_taken_0x11340c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11340c) {
            ctx->pc = 0x113450u;
            goto label_113450;
        }
    }
    ctx->pc = 0x113414u;
    // 0x113414: 0xc0452ac
    ctx->pc = 0x113414u;
    SET_GPR_U32(ctx, 31, 0x11341Cu);
    ctx->pc = 0x114AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114AB0_0x114ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11341Cu; }
    }
    if (ctx->pc != 0x11341Cu) { return; }
    ctx->pc = 0x11341Cu;
    // 0x11341c: 0x86030000
    ctx->pc = 0x11341cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x113420: 0x24020001
    ctx->pc = 0x113420u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x113424: 0x14620014
    ctx->pc = 0x113424u;
    {
        const bool branch_taken_0x113424 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x113428u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x113424) {
            ctx->pc = 0x113478u;
            goto label_113478;
        }
    }
    ctx->pc = 0x11342Cu;
    // 0x11342c: 0x3c031200
    ctx->pc = 0x11342cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4608 << 16));
    // 0x113430: 0x34631000
    ctx->pc = 0x113430u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4096));
    // 0x113434: 0xdc620000
    ctx->pc = 0x113434u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113438: 0x2137a
    ctx->pc = 0x113438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 13);
    // 0x11343c: 0x30420001
    ctx->pc = 0x11343cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x113440: 0x2103c
    ctx->pc = 0x113440u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113444: 0x2103f
    ctx->pc = 0x113444u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113448: 0x1000000c
    ctx->pc = 0x113448u;
    {
        const bool branch_taken_0x113448 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11344Cu;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x113448) {
            ctx->pc = 0x11347Cu;
            goto label_11347c;
        }
    }
    ctx->pc = 0x113450u;
label_113450:
    // 0x113450: 0xc0452d0
    ctx->pc = 0x113450u;
    SET_GPR_U32(ctx, 31, 0x113458u);
    ctx->pc = 0x114B40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114B40_0x114b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113458u; }
    }
    if (ctx->pc != 0x113458u) { return; }
    ctx->pc = 0x113458u;
    // 0x113458: 0x2137b
    ctx->pc = 0x113458u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> 13);
    // 0x11345c: 0x86030000
    ctx->pc = 0x11345cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x113460: 0x30440001
    ctx->pc = 0x113460u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 2), 1));
    // 0x113464: 0x24020001
    ctx->pc = 0x113464u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x113468: 0x14620003
    ctx->pc = 0x113468u;
    {
        const bool branch_taken_0x113468 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x11346Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x113468) {
            ctx->pc = 0x113478u;
            goto label_113478;
        }
    }
    ctx->pc = 0x113470u;
    // 0x113470: 0x4103c
    ctx->pc = 0x113470u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x113474: 0x2103f
    ctx->pc = 0x113474u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
label_113478:
    // 0x113478: 0xdfb00000
    ctx->pc = 0x113478u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11347c:
    // 0x11347c: 0x3e00008
    ctx->pc = 0x11347Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113480u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113450u: goto label_113450;
            case 0x113478u: goto label_113478;
            case 0x11347Cu: goto label_11347c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113484u;
    // 0x113484: 0x0
    ctx->pc = 0x113484u;
    // NOP
}
