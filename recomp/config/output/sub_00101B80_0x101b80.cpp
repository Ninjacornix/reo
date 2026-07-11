#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00101B80
// Address: 0x101b80 - 0x101c38
void sub_00101B80_0x101b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x101b80u;

    // 0x101b80: 0x27bdffc0
    ctx->pc = 0x101b80u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x101b84: 0x2404001e
    ctx->pc = 0x101b84u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 30));
    // 0x101b88: 0xffbf0030
    ctx->pc = 0x101b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x101b8c: 0xffb10020
    ctx->pc = 0x101b8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101b90: 0xc0403a2
    ctx->pc = 0x101B90u;
    SET_GPR_U32(ctx, 31, 0x101B98u);
    ctx->pc = 0x101B94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    ctx->pc = 0x100E88u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E88_0x100e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B98u; }
    }
    if (ctx->pc != 0x101B98u) { return; }
    ctx->pc = 0x101B98u;
    // 0x101b98: 0x14400003
    ctx->pc = 0x101B98u;
    {
        const bool branch_taken_0x101b98 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x101B9Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x101b98) {
            ctx->pc = 0x101BA8u;
            goto label_101ba8;
        }
    }
    ctx->pc = 0x101BA0u;
    // 0x101ba0: 0x10000020
    ctx->pc = 0x101BA0u;
    {
        const bool branch_taken_0x101ba0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101BA4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x101ba0) {
            ctx->pc = 0x101C24u;
            goto label_101c24;
        }
    }
    ctx->pc = 0x101BA8u;
label_101ba8:
    // 0x101ba8: 0x3c100020
    ctx->pc = 0x101ba8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x101bac: 0x24518b00
    ctx->pc = 0x101bacu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 4294937344));
    // 0x101bb0: 0x24030008
    ctx->pc = 0x101bb0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x101bb4: 0x3c040021
    ctx->pc = 0x101bb4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x101bb8: 0xae037958
    ctx->pc = 0x101bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 3));
    // 0x101bbc: 0x24849480
    ctx->pc = 0x101bbcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294939776));
    // 0x101bc0: 0xafa00000
    ctx->pc = 0x101bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x101bc4: 0x24050016
    ctx->pc = 0x101bc4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 22));
    // 0x101bc8: 0x302d
    ctx->pc = 0x101bc8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bcc: 0x382d
    ctx->pc = 0x101bccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd0: 0x402d
    ctx->pc = 0x101bd0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd4: 0x220482d
    ctx->pc = 0x101bd4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd8: 0x240a0004
    ctx->pc = 0x101bd8u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 4));
    // 0x101bdc: 0xc045e7a
    ctx->pc = 0x101BDCu;
    SET_GPR_U32(ctx, 31, 0x101BE4u);
    ctx->pc = 0x101BE0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BE4u; }
    }
    if (ctx->pc != 0x101BE4u) { return; }
    ctx->pc = 0x101BE4u;
    // 0x101be4: 0x4410007
    ctx->pc = 0x101BE4u;
    {
        const bool branch_taken_0x101be4 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x101BE8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x101be4) {
            ctx->pc = 0x101C04u;
            goto label_101c04;
        }
    }
    ctx->pc = 0x101BECu;
    // 0x101bec: 0x8c44792c
    ctx->pc = 0x101becu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101bf0: 0xc045190
    ctx->pc = 0x101BF0u;
    SET_GPR_U32(ctx, 31, 0x101BF8u);
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BF8u; }
    }
    if (ctx->pc != 0x101BF8u) { return; }
    ctx->pc = 0x101BF8u;
    // 0x101bf8: 0xae007958
    ctx->pc = 0x101bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101bfc: 0x10000009
    ctx->pc = 0x101BFCu;
    {
        const bool branch_taken_0x101bfc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101C00u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x101bfc) {
            ctx->pc = 0x101C24u;
            goto label_101c24;
        }
    }
    ctx->pc = 0x101C04u;
label_101c04:
    // 0x101c04: 0xae007958
    ctx->pc = 0x101c04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101c08: 0x3c030020
    ctx->pc = 0x101c08u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x101c0c: 0x3c022000
    ctx->pc = 0x101c0cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
    // 0x101c10: 0x2221025
    ctx->pc = 0x101c10u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x101c14: 0x8c64792c
    ctx->pc = 0x101c14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 31020)));
    // 0x101c18: 0xc045190
    ctx->pc = 0x101C18u;
    SET_GPR_U32(ctx, 31, 0x101C20u);
    ctx->pc = 0x101C1Cu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C20u; }
    }
    if (ctx->pc != 0x101C20u) { return; }
    ctx->pc = 0x101C20u;
    // 0x101c20: 0x200102d
    ctx->pc = 0x101c20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101c24:
    // 0x101c24: 0xdfbf0030
    ctx->pc = 0x101c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101c28: 0xdfb10020
    ctx->pc = 0x101c28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101c2c: 0xdfb00010
    ctx->pc = 0x101c2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101c30: 0x3e00008
    ctx->pc = 0x101C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101C34u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101BA8u: goto label_101ba8;
            case 0x101C04u: goto label_101c04;
            case 0x101C24u: goto label_101c24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101C38u;
}
