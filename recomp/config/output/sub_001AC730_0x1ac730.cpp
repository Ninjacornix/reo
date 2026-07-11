#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001AC730
// Address: 0x1ac730 - 0x1ac7f0
void sub_001AC730_0x1ac730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1ac730u;

    // 0x1ac730: 0x27bdffd0
    ctx->pc = 0x1ac730u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ac734: 0x3c028000
    ctx->pc = 0x1ac734u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x1ac738: 0xffbf0020
    ctx->pc = 0x1ac738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ac73c: 0x7fb10010
    ctx->pc = 0x1ac73cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ac740: 0x7fb00000
    ctx->pc = 0x1ac740u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ac744: 0x80882d
    ctx->pc = 0x1ac744u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac748: 0xa0802d
    ctx->pc = 0x1ac748u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac74c: 0x3444000c
    ctx->pc = 0x1ac74cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 12));
    // 0x1ac750: 0xc06a030
    ctx->pc = 0x1AC750u;
    SET_GPR_U32(ctx, 31, 0x1AC758u);
    ctx->pc = 0x1AC754u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1A80C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC758u; }
    }
    if (ctx->pc != 0x1AC758u) { return; }
    ctx->pc = 0x1AC758u;
    // 0x1ac758: 0x220202d
    ctx->pc = 0x1ac758u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac75c: 0xc06b3ec
    ctx->pc = 0x1AC75Cu;
    SET_GPR_U32(ctx, 31, 0x1AC764u);
    ctx->pc = 0x1AC760u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1ACFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACFB0_0x1acfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC764u; }
    }
    if (ctx->pc != 0x1AC764u) { return; }
    ctx->pc = 0x1AC764u;
    // 0x1ac764: 0x4410003
    ctx->pc = 0x1AC764u;
    {
        const bool branch_taken_0x1ac764 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x1AC768u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ac764) {
            ctx->pc = 0x1AC774u;
            goto label_1ac774;
        }
    }
    ctx->pc = 0x1AC76Cu;
    // 0x1ac76c: 0x1000001a
    ctx->pc = 0x1AC76Cu;
    {
        const bool branch_taken_0x1ac76c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AC770u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x1ac76c) {
            ctx->pc = 0x1AC7D8u;
            goto label_1ac7d8;
        }
    }
    ctx->pc = 0x1AC774u;
label_1ac774:
    // 0x1ac774: 0xc06ade4
    ctx->pc = 0x1AC774u;
    SET_GPR_U32(ctx, 31, 0x1AC77Cu);
    ctx->pc = 0x1AB790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC77Cu; }
    }
    if (ctx->pc != 0x1AC77Cu) { return; }
    ctx->pc = 0x1AC77Cu;
    // 0x1ac77c: 0x10000004
    ctx->pc = 0x1AC77Cu;
    {
        const bool branch_taken_0x1ac77c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AC780u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1ac77c) {
            ctx->pc = 0x1AC790u;
            goto label_1ac790;
        }
    }
    ctx->pc = 0x1AC784u;
label_1ac784:
    // 0x1ac784: 0xc044cfc
    ctx->pc = 0x1AC784u;
    SET_GPR_U32(ctx, 31, 0x1AC78Cu);
    ctx->pc = 0x1AC788u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC78Cu; }
    }
    if (ctx->pc != 0x1AC78Cu) { return; }
    ctx->pc = 0x1AC78Cu;
    // 0x1ac78c: 0x24040001
    ctx->pc = 0x1ac78cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_1ac790:
    // 0x1ac790: 0xc069fd4
    ctx->pc = 0x1AC790u;
    SET_GPR_U32(ctx, 31, 0x1AC798u);
    ctx->pc = 0x1A7F50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7F50_0x1a7f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC798u; }
    }
    if (ctx->pc != 0x1AC798u) { return; }
    ctx->pc = 0x1AC798u;
    // 0x1ac798: 0x1c40fffa
    ctx->pc = 0x1AC798u;
    {
        const bool branch_taken_0x1ac798 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1ac798) {
            ctx->pc = 0x1AC784u;
            goto label_1ac784;
        }
    }
    ctx->pc = 0x1AC7A0u;
    // 0x1ac7a0: 0x10000004
    ctx->pc = 0x1AC7A0u;
    {
        const bool branch_taken_0x1ac7a0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AC7A4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
        if (branch_taken_0x1ac7a0) {
            ctx->pc = 0x1AC7B4u;
            goto label_1ac7b4;
        }
    }
    ctx->pc = 0x1AC7A8u;
label_1ac7a8:
    // 0x1ac7a8: 0xc044cfc
    ctx->pc = 0x1AC7A8u;
    SET_GPR_U32(ctx, 31, 0x1AC7B0u);
    ctx->pc = 0x1AC7ACu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7B0u; }
    }
    if (ctx->pc != 0x1AC7B0u) { return; }
    ctx->pc = 0x1AC7B0u;
    // 0x1ac7b0: 0x3c028000
    ctx->pc = 0x1ac7b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
label_1ac7b4:
    // 0x1ac7b4: 0x24050001
    ctx->pc = 0x1ac7b4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac7b8: 0xc06a030
    ctx->pc = 0x1AC7B8u;
    SET_GPR_U32(ctx, 31, 0x1AC7C0u);
    ctx->pc = 0x1AC7BCu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 12));
    ctx->pc = 0x1A80C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7C0u; }
    }
    if (ctx->pc != 0x1AC7C0u) { return; }
    ctx->pc = 0x1AC7C0u;
    // 0x1ac7c0: 0x1c40fff9
    ctx->pc = 0x1AC7C0u;
    {
        const bool branch_taken_0x1ac7c0 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1ac7c0) {
            ctx->pc = 0x1AC7A8u;
            goto label_1ac7a8;
        }
    }
    ctx->pc = 0x1AC7C8u;
    // 0x1ac7c8: 0xc06adfc
    ctx->pc = 0x1AC7C8u;
    SET_GPR_U32(ctx, 31, 0x1AC7D0u);
    ctx->pc = 0x1AB7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7D0u; }
    }
    if (ctx->pc != 0x1AC7D0u) { return; }
    ctx->pc = 0x1AC7D0u;
    // 0x1ac7d0: 0x200102d
    ctx->pc = 0x1ac7d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac7d4: 0xdfbf0020
    ctx->pc = 0x1ac7d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ac7d8:
    // 0x1ac7d8: 0x7bb10010
    ctx->pc = 0x1ac7d8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ac7dc: 0x7bb00000
    ctx->pc = 0x1ac7dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac7e0: 0x3e00008
    ctx->pc = 0x1AC7E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC7E4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC774u: goto label_1ac774;
            case 0x1AC784u: goto label_1ac784;
            case 0x1AC790u: goto label_1ac790;
            case 0x1AC7A8u: goto label_1ac7a8;
            case 0x1AC7B4u: goto label_1ac7b4;
            case 0x1AC7D8u: goto label_1ac7d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC7E8u;
    // 0x1ac7e8: 0x0
    ctx->pc = 0x1ac7e8u;
    // NOP
    // 0x1ac7ec: 0x0
    ctx->pc = 0x1ac7ecu;
    // NOP
}
