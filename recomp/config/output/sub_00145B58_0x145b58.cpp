#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00145B58
// Address: 0x145b58 - 0x145bd8
void sub_00145B58_0x145b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x145b58u;

    // 0x145b58: 0x27bdffd0
    ctx->pc = 0x145b58u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x145b5c: 0xffb00000
    ctx->pc = 0x145b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145b60: 0x80802d
    ctx->pc = 0x145b60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b64: 0xffbf0020
    ctx->pc = 0x145b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x145b68: 0xc051496
    ctx->pc = 0x145B68u;
    SET_GPR_U32(ctx, 31, 0x145B70u);
    ctx->pc = 0x145B6Cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B70u; }
    }
    if (ctx->pc != 0x145B70u) { return; }
    ctx->pc = 0x145B70u;
    // 0x145b70: 0x3c021000
    ctx->pc = 0x145b70u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145b74: 0x34422020
    ctx->pc = 0x145b74u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8224));
    // 0x145b78: 0x8c430000
    ctx->pc = 0x145b78u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145b7c: 0x30630007
    ctx->pc = 0x145b7cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 7));
    // 0x145b80: 0x31823
    ctx->pc = 0x145b80u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x145b84: 0x30650007
    ctx->pc = 0x145b84u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 3), 7));
    // 0x145b88: 0x10a00007
    ctx->pc = 0x145B88u;
    {
        const bool branch_taken_0x145b88 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x145B8Cu;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x145b88) {
            ctx->pc = 0x145BA8u;
            goto label_145ba8;
        }
    }
    ctx->pc = 0x145B90u;
    // 0x145b90: 0xc051636
    ctx->pc = 0x145B90u;
    SET_GPR_U32(ctx, 31, 0x145B98u);
    ctx->pc = 0x145B94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1458D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B98u; }
    }
    if (ctx->pc != 0x145B98u) { return; }
    ctx->pc = 0x145B98u;
    // 0x145b98: 0x10000003
    ctx->pc = 0x145B98u;
    {
        const bool branch_taken_0x145b98 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145B9Cu;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x145b98) {
            ctx->pc = 0x145BA8u;
            goto label_145ba8;
        }
    }
    ctx->pc = 0x145BA0u;
label_145ba0:
    // 0x145ba0: 0xc051636
    ctx->pc = 0x145BA0u;
    SET_GPR_U32(ctx, 31, 0x145BA8u);
    ctx->pc = 0x145BA4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x1458D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BA8u; }
    }
    if (ctx->pc != 0x145BA8u) { return; }
    ctx->pc = 0x145BA8u;
label_145ba8:
    // 0x145ba8: 0x200202d
    ctx->pc = 0x145ba8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145bac: 0xc0515ee
    ctx->pc = 0x145BACu;
    SET_GPR_U32(ctx, 31, 0x145BB4u);
    ctx->pc = 0x145BB0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 24));
    ctx->pc = 0x1457B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001457B8_0x1457b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BB4u; }
    }
    if (ctx->pc != 0x145BB4u) { return; }
    ctx->pc = 0x145BB4u;
    // 0x145bb4: 0x10510004
    ctx->pc = 0x145BB4u;
    {
        const bool branch_taken_0x145bb4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 17));
        ctx->pc = 0x145BB8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x145bb4) {
            ctx->pc = 0x145BC8u;
            goto label_145bc8;
        }
    }
    ctx->pc = 0x145BBCu;
    // 0x145bbc: 0x8e0210a0
    ctx->pc = 0x145bbcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145bc0: 0x1040fff7
    ctx->pc = 0x145BC0u;
    {
        const bool branch_taken_0x145bc0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x145BC4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145bc0) {
            ctx->pc = 0x145BA0u;
            goto label_145ba0;
        }
    }
    ctx->pc = 0x145BC8u;
label_145bc8:
    // 0x145bc8: 0xdfb10010
    ctx->pc = 0x145bc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145bcc: 0xdfb00000
    ctx->pc = 0x145bccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145bd0: 0x3e00008
    ctx->pc = 0x145BD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145BD4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145BA0u: goto label_145ba0;
            case 0x145BA8u: goto label_145ba8;
            case 0x145BC8u: goto label_145bc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145BD8u;
}
