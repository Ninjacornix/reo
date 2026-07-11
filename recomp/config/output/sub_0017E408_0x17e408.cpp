#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017E408
// Address: 0x17e408 - 0x17e4c8
void sub_0017E408_0x17e408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17e408u;

    // 0x17e408: 0x3c020024
    ctx->pc = 0x17e408u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
    // 0x17e40c: 0x3e00008
    ctx->pc = 0x17E40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E410u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 5320));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E414u;
    // 0x17e414: 0x0
    ctx->pc = 0x17e414u;
    // NOP
    // 0x17e418: 0x3c020023
    ctx->pc = 0x17e418u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17e41c: 0x2442f978
    ctx->pc = 0x17e41cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294965624));
    // 0x17e420: 0x8c430000
    ctx->pc = 0x17e420u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17e424: 0x18600002
    ctx->pc = 0x17E424u;
    {
        const bool branch_taken_0x17e424 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x17E428u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x17e424) {
            ctx->pc = 0x17E430u;
            goto label_17e430;
        }
    }
    ctx->pc = 0x17E42Cu;
    // 0x17e42c: 0xac440000
    ctx->pc = 0x17e42cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
label_17e430:
    // 0x17e430: 0x3e00008
    ctx->pc = 0x17E430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E438u;
    // 0x17e438: 0x27bdffd0
    ctx->pc = 0x17e438u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17e43c: 0x3c050024
    ctx->pc = 0x17e43cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x17e440: 0xffb10018
    ctx->pc = 0x17e440u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17e444: 0xc0882d
    ctx->pc = 0x17e444u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e448: 0x24a51500
    ctx->pc = 0x17e448u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 5376));
    // 0x17e44c: 0x24060008
    ctx->pc = 0x17e44cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8));
    // 0x17e450: 0xffb00010
    ctx->pc = 0x17e450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e454: 0xffbf0020
    ctx->pc = 0x17e454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17e458: 0xc042d7e
    ctx->pc = 0x17E458u;
    SET_GPR_U32(ctx, 31, 0x17E460u);
    ctx->pc = 0x17E45Cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10B5F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E460u; }
    }
    if (ctx->pc != 0x17E460u) { return; }
    ctx->pc = 0x17E460u;
    // 0x17e460: 0x3c050024
    ctx->pc = 0x17e460u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x17e464: 0x3a0202d
    ctx->pc = 0x17e464u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e468: 0x24060005
    ctx->pc = 0x17e468u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 5));
    // 0x17e46c: 0xc042a0c
    ctx->pc = 0x17E46Cu;
    SET_GPR_U32(ctx, 31, 0x17E474u);
    ctx->pc = 0x17E470u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 5392));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E474u; }
    }
    if (ctx->pc != 0x17E474u) { return; }
    ctx->pc = 0x17E474u;
    // 0x17e474: 0x200202d
    ctx->pc = 0x17e474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e478: 0x3a0282d
    ctx->pc = 0x17e478u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e47c: 0xc042aee
    ctx->pc = 0x17E47Cu;
    SET_GPR_U32(ctx, 31, 0x17E484u);
    ctx->pc = 0x17E480u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 16));
    ctx->pc = 0x10ABB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E484u; }
    }
    if (ctx->pc != 0x17E484u) { return; }
    ctx->pc = 0x17E484u;
    // 0x17e484: 0x3c050024
    ctx->pc = 0x17e484u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x17e488: 0x24060002
    ctx->pc = 0x17e488u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    // 0x17e48c: 0x200202d
    ctx->pc = 0x17e48cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e490: 0xc042d7e
    ctx->pc = 0x17E490u;
    SET_GPR_U32(ctx, 31, 0x17E498u);
    ctx->pc = 0x17E494u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 5400));
    ctx->pc = 0x10B5F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E498u; }
    }
    if (ctx->pc != 0x17E498u) { return; }
    ctx->pc = 0x17E498u;
    // 0x17e498: 0x200202d
    ctx->pc = 0x17e498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e49c: 0xc05f932
    ctx->pc = 0x17E49Cu;
    SET_GPR_U32(ctx, 31, 0x17E4A4u);
    ctx->pc = 0x17E4A0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x17E4C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E4C8_0x17e4c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4A4u; }
    }
    if (ctx->pc != 0x17E4A4u) { return; }
    ctx->pc = 0x17E4A4u;
    // 0x17e4a4: 0x3c050024
    ctx->pc = 0x17e4a4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x17e4a8: 0x200202d
    ctx->pc = 0x17e4a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e4ac: 0xc042aee
    ctx->pc = 0x17E4ACu;
    SET_GPR_U32(ctx, 31, 0x17E4B4u);
    ctx->pc = 0x17E4B0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 5408));
    ctx->pc = 0x10ABB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4B4u; }
    }
    if (ctx->pc != 0x17E4B4u) { return; }
    ctx->pc = 0x17E4B4u;
    // 0x17e4b4: 0xdfb00010
    ctx->pc = 0x17e4b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e4b8: 0xdfb10018
    ctx->pc = 0x17e4b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e4bc: 0xdfbf0020
    ctx->pc = 0x17e4bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e4c0: 0x3e00008
    ctx->pc = 0x17E4C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E4C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E4C8u;
}
