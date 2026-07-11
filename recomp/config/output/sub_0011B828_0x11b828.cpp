#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011B828
// Address: 0x11b828 - 0x11b8b0
void sub_0011B828_0x11b828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11b828u;

    // 0x11b828: 0x27bdffd0
    ctx->pc = 0x11b828u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11b82c: 0xffb10010
    ctx->pc = 0x11b82cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11b830: 0xffbf0020
    ctx->pc = 0x11b830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11b834: 0x3c110026
    ctx->pc = 0x11b834u;
    SET_GPR_U32(ctx, 17, ((uint32_t)38 << 16));
    // 0x11b838: 0x1000000a
    ctx->pc = 0x11B838u;
    {
        const bool branch_taken_0x11b838 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11B83Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        if (branch_taken_0x11b838) {
            ctx->pc = 0x11B864u;
            goto label_11b864;
        }
    }
    ctx->pc = 0x11B840u;
label_11b840:
    // 0x11b840: 0x3c020010
    ctx->pc = 0x11b840u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x11b844: 0x2403ffff
    ctx->pc = 0x11b844u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_11b848:
    // 0x11b848: 0x2442ffff
    ctx->pc = 0x11b848u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x11b84c: 0x0
    ctx->pc = 0x11b84cu;
    // NOP
    // 0x11b850: 0x0
    ctx->pc = 0x11b850u;
    // NOP
    // 0x11b854: 0x0
    ctx->pc = 0x11b854u;
    // NOP
    // 0x11b858: 0x0
    ctx->pc = 0x11b858u;
    // NOP
    // 0x11b85c: 0x1443fffa
    ctx->pc = 0x11B85Cu;
    {
        const bool branch_taken_0x11b85c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x11b85c) {
            ctx->pc = 0x11B848u;
            goto label_11b848;
        }
    }
    ctx->pc = 0x11B864u;
label_11b864:
    // 0x11b864: 0x2630e240
    ctx->pc = 0x11b864u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 4294959680));
    // 0x11b868: 0x3c058000
    ctx->pc = 0x11b868u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x11b86c: 0x200202d
    ctx->pc = 0x11b86cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b870: 0x34a50003
    ctx->pc = 0x11b870u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 3));
    // 0x11b874: 0xc045e06
    ctx->pc = 0x11B874u;
    SET_GPR_U32(ctx, 31, 0x11B87Cu);
    ctx->pc = 0x11B878u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B87Cu; }
    }
    if (ctx->pc != 0x11B87Cu) { return; }
    ctx->pc = 0x11B87Cu;
    // 0x11b87c: 0x4430003
    ctx->pc = 0x11B87Cu;
    {
        const bool branch_taken_0x11b87c = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x11b87c) {
            ctx->pc = 0x11B880u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
            ctx->pc = 0x11B88Cu;
            goto label_11b88c;
        }
    }
    ctx->pc = 0x11B884u;
    // 0x11b884: 0x10000005
    ctx->pc = 0x11B884u;
    {
        const bool branch_taken_0x11b884 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11B888u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x11b884) {
            ctx->pc = 0x11B89Cu;
            goto label_11b89c;
        }
    }
    ctx->pc = 0x11B88Cu;
label_11b88c:
    // 0x11b88c: 0x1040ffec
    ctx->pc = 0x11B88Cu;
    {
        const bool branch_taken_0x11b88c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11B890u;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x11b88c) {
            ctx->pc = 0x11B840u;
            goto label_11b840;
        }
    }
    ctx->pc = 0x11B894u;
    // 0x11b894: 0xac409df8
    ctx->pc = 0x11b894u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942200), GPR_U32(ctx, 0));
    // 0x11b898: 0x102d
    ctx->pc = 0x11b898u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11b89c:
    // 0x11b89c: 0xdfbf0020
    ctx->pc = 0x11b89cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11b8a0: 0xdfb10010
    ctx->pc = 0x11b8a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11b8a4: 0xdfb00000
    ctx->pc = 0x11b8a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11b8a8: 0x3e00008
    ctx->pc = 0x11B8A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B8ACu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B840u: goto label_11b840;
            case 0x11B848u: goto label_11b848;
            case 0x11B864u: goto label_11b864;
            case 0x11B88Cu: goto label_11b88c;
            case 0x11B89Cu: goto label_11b89c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B8B0u;
}
