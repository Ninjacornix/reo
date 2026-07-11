#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00129F70
// Address: 0x129f70 - 0x12a020
void sub_00129F70_0x129f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x129f70u;

    // 0x129f70: 0x42080
    ctx->pc = 0x129f70u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
    // 0x129f74: 0x3c020021
    ctx->pc = 0x129f74u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x129f78: 0x441021
    ctx->pc = 0x129f78u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x129f7c: 0x8c42cd00
    ctx->pc = 0x129f7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4294954240)));
    // 0x129f80: 0x3e00008
    ctx->pc = 0x129F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129F84u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FC0u: goto label_129fc0;
            case 0x129FF8u: goto label_129ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129F88u;
    // 0x129f88: 0x3c020021
    ctx->pc = 0x129f88u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x129f8c: 0x3e00008
    ctx->pc = 0x129F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129F90u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294955264), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FC0u: goto label_129fc0;
            case 0x129FF8u: goto label_129ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129F94u;
    // 0x129f94: 0x0
    ctx->pc = 0x129f94u;
    // NOP
    // 0x129f98: 0x27bdfff0
    ctx->pc = 0x129f98u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129f9c: 0x24030002
    ctx->pc = 0x129f9cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x129fa0: 0xffbf0000
    ctx->pc = 0x129fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x129fa4: 0x80820001
    ctx->pc = 0x129fa4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x129fa8: 0x14430005
    ctx->pc = 0x129FA8u;
    {
        const bool branch_taken_0x129fa8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x129FACu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x129fa8) {
            ctx->pc = 0x129FC0u;
            goto label_129fc0;
        }
    }
    ctx->pc = 0x129FB0u;
    // 0x129fb0: 0x3c040024
    ctx->pc = 0x129fb0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x129fb4: 0x2484a288
    ctx->pc = 0x129fb4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943368));
    // 0x129fb8: 0x804a034
    ctx->pc = 0x129FB8u;
    ctx->pc = 0x129FBCu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1280D0u;
    sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    ctx->pc = 0x129FC0u;
label_129fc0:
    // 0x129fc0: 0xac85002c
    ctx->pc = 0x129fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
    // 0x129fc4: 0x3e00008
    ctx->pc = 0x129FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129FC8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FC0u: goto label_129fc0;
            case 0x129FF8u: goto label_129ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129FCCu;
    // 0x129fcc: 0x0
    ctx->pc = 0x129fccu;
    // NOP
    // 0x129fd0: 0x27bdfff0
    ctx->pc = 0x129fd0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129fd4: 0x102d
    ctx->pc = 0x129fd4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129fd8: 0x10800007
    ctx->pc = 0x129FD8u;
    {
        const bool branch_taken_0x129fd8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x129FDCu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x129fd8) {
            ctx->pc = 0x129FF8u;
            goto label_129ff8;
        }
    }
    ctx->pc = 0x129FE0u;
    // 0x129fe0: 0x8c830004
    ctx->pc = 0x129fe0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x129fe4: 0x10600004
    ctx->pc = 0x129FE4u;
    {
        const bool branch_taken_0x129fe4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x129FE8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x129fe4) {
            ctx->pc = 0x129FF8u;
            goto label_129ff8;
        }
    }
    ctx->pc = 0x129FECu;
    // 0x129fec: 0xdfbf0000
    ctx->pc = 0x129fecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129ff0: 0x804c3f8
    ctx->pc = 0x129FF0u;
    ctx->pc = 0x129FF4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x130FE0u;
    entry_130fe0_0x130fe8(rdram, ctx, runtime); return;
    ctx->pc = 0x129FF8u;
label_129ff8:
    // 0x129ff8: 0xdfbf0000
    ctx->pc = 0x129ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129ffc: 0x3e00008
    ctx->pc = 0x129FFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A000u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FC0u: goto label_129fc0;
            case 0x129FF8u: goto label_129ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A004u;
    // 0x12a004: 0x0
    ctx->pc = 0x12a004u;
    // NOP
    // 0x12a008: 0x27bdfff0
    ctx->pc = 0x12a008u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a00c: 0xffbf0000
    ctx->pc = 0x12a00cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a010: 0xdfbf0000
    ctx->pc = 0x12a010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a014: 0x804d7ee
    ctx->pc = 0x12A014u;
    ctx->pc = 0x12A018u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x135FB8u;
    sub_00135FB8_0x135fb8(rdram, ctx, runtime); return;
    ctx->pc = 0x12A01Cu;
    // 0x12a01c: 0x0
    ctx->pc = 0x12a01cu;
    // NOP
}
