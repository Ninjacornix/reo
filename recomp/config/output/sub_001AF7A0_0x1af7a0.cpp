#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001AF7A0
// Address: 0x1af7a0 - 0x1af850
void sub_001AF7A0_0x1af7a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1af7a0u;

    // 0x1af7a0: 0x27bdffc0
    ctx->pc = 0x1af7a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1af7a4: 0xffbf0030
    ctx->pc = 0x1af7a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1af7a8: 0x7fb20020
    ctx->pc = 0x1af7a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1af7ac: 0x7fb10010
    ctx->pc = 0x1af7acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1af7b0: 0x80902d
    ctx->pc = 0x1af7b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af7b4: 0x7fb00000
    ctx->pc = 0x1af7b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1af7b8: 0x882d
    ctx->pc = 0x1af7b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af7bc: 0x3c10002c
    ctx->pc = 0x1af7bcu;
    SET_GPR_U32(ctx, 16, ((uint32_t)44 << 16));
    // 0x1af7c0: 0x10000006
    ctx->pc = 0x1AF7C0u;
    {
        const bool branch_taken_0x1af7c0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF7C4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294938192));
        if (branch_taken_0x1af7c0) {
            ctx->pc = 0x1AF7DCu;
            goto label_1af7dc;
        }
    }
    ctx->pc = 0x1AF7C8u;
label_1af7c8:
    // 0x1af7c8: 0x8e020000
    ctx->pc = 0x1af7c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1af7cc: 0x10400007
    ctx->pc = 0x1AF7CCu;
    {
        const bool branch_taken_0x1af7cc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF7D0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x1af7cc) {
            ctx->pc = 0x1AF7ECu;
            goto label_1af7ec;
        }
    }
    ctx->pc = 0x1AF7D4u;
    // 0x1af7d4: 0x26310001
    ctx->pc = 0x1af7d4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 1));
    // 0x1af7d8: 0x26100008
    ctx->pc = 0x1af7d8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8));
label_1af7dc:
    // 0x1af7dc: 0x2a220008
    ctx->pc = 0x1af7dcu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 17), 8));
    // 0x1af7e0: 0x1440fff9
    ctx->pc = 0x1AF7E0u;
    {
        const bool branch_taken_0x1af7e0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1af7e0) {
            ctx->pc = 0x1AF7C8u;
            goto label_1af7c8;
        }
    }
    ctx->pc = 0x1AF7E8u;
    // 0x1af7e8: 0x24020008
    ctx->pc = 0x1af7e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8));
label_1af7ec:
    // 0x1af7ec: 0x16220008
    ctx->pc = 0x1AF7ECu;
    {
        const bool branch_taken_0x1af7ec = (GPR_U32(ctx, 17) != GPR_U32(ctx, 2));
        ctx->pc = 0x1AF7F0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1af7ec) {
            ctx->pc = 0x1AF810u;
            goto label_1af810;
        }
    }
    ctx->pc = 0x1AF7F4u;
label_1af7f4:
    // 0x1af7f4: 0x0
    ctx->pc = 0x1af7f4u;
    // NOP
    // 0x1af7f8: 0x0
    ctx->pc = 0x1af7f8u;
    // NOP
    // 0x1af7fc: 0x0
    ctx->pc = 0x1af7fcu;
    // NOP
    // 0x1af800: 0x0
    ctx->pc = 0x1af800u;
    // NOP
    // 0x1af804: 0x0
    ctx->pc = 0x1af804u;
    // NOP
    // 0x1af808: 0x1000fffa
    ctx->pc = 0x1AF808u;
    {
        const bool branch_taken_0x1af808 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1af808) {
            ctx->pc = 0x1AF7F4u;
            goto label_1af7f4;
        }
    }
    ctx->pc = 0x1AF810u;
label_1af810:
    // 0x1af810: 0xc063700
    ctx->pc = 0x1AF810u;
    SET_GPR_U32(ctx, 31, 0x1AF818u);
    ctx->pc = 0x18DC00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC00_0x18dc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF818u; }
    }
    if (ctx->pc != 0x1AF818u) { return; }
    ctx->pc = 0x1AF818u;
    // 0x1af818: 0x3c01002c
    ctx->pc = 0x1af818u;
    SET_GPR_U32(ctx, 1, ((uint32_t)44 << 16));
    // 0x1af81c: 0x8c238dd8
    ctx->pc = 0x1af81cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294938072)));
    // 0x1af820: 0x71082a
    ctx->pc = 0x1af820u;
    SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 17)));
    // 0x1af824: 0x10200002
    ctx->pc = 0x1AF824u;
    {
        const bool branch_taken_0x1af824 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF828u;
        SET_GPR_U32(ctx, 1, ((uint32_t)44 << 16));
        if (branch_taken_0x1af824) {
            ctx->pc = 0x1AF830u;
            goto label_1af830;
        }
    }
    ctx->pc = 0x1AF82Cu;
    // 0x1af82c: 0xac318dd8
    ctx->pc = 0x1af82cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938072), GPR_U32(ctx, 17));
label_1af830:
    // 0x1af830: 0xae120000
    ctx->pc = 0x1af830u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1af834: 0xdfbf0030
    ctx->pc = 0x1af834u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1af838: 0x7bb20020
    ctx->pc = 0x1af838u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1af83c: 0x7bb10010
    ctx->pc = 0x1af83cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1af840: 0x7bb00000
    ctx->pc = 0x1af840u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af844: 0x3e00008
    ctx->pc = 0x1AF844u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF848u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF7C8u: goto label_1af7c8;
            case 0x1AF7DCu: goto label_1af7dc;
            case 0x1AF7ECu: goto label_1af7ec;
            case 0x1AF7F4u: goto label_1af7f4;
            case 0x1AF810u: goto label_1af810;
            case 0x1AF830u: goto label_1af830;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF84Cu;
    // 0x1af84c: 0x0
    ctx->pc = 0x1af84cu;
    // NOP
}
