#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B80D0
// Address: 0x1b80d0 - 0x1b8170
void sub_001B80D0_0x1b80d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b80d0u;

label_1b80d0:
    // 0x1b80d0: 0x3c010032
    ctx->pc = 0x1b80d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1b80d4: 0x4363c
    ctx->pc = 0x1b80d4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 24));
    // 0x1b80d8: 0x902343f8
    ctx->pc = 0x1b80d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17400)));
    // 0x1b80dc: 0x6363f
    ctx->pc = 0x1b80dcu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 24));
    // 0x1b80e0: 0x10c30006
    ctx->pc = 0x1B80E0u;
    {
        const bool branch_taken_0x1b80e0 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 3));
        ctx->pc = 0x1B80E4u;
        SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
        if (branch_taken_0x1b80e0) {
            ctx->pc = 0x1B80FCu;
            goto label_1b80fc;
        }
    }
    ctx->pc = 0x1B80E8u;
    // 0x1b80e8: 0x802347f0
    ctx->pc = 0x1b80e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
    // 0x1b80ec: 0x10660003
    ctx->pc = 0x1B80ECu;
    {
        const bool branch_taken_0x1b80ec = (GPR_U32(ctx, 3) == GPR_U32(ctx, 6));
        if (branch_taken_0x1b80ec) {
            ctx->pc = 0x1B80FCu;
            goto label_1b80fc;
        }
    }
    ctx->pc = 0x1B80F4u;
    // 0x1b80f4: 0x3c010023
    ctx->pc = 0x1b80f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1b80f8: 0xa02447f0
    ctx->pc = 0x1b80f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18416), (uint8_t)GPR_U32(ctx, 4));
label_1b80fc:
    // 0x1b80fc: 0x5263c
    ctx->pc = 0x1b80fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) << (32 + 24));
    // 0x1b8100: 0x2403ffff
    ctx->pc = 0x1b8100u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b8104: 0x4263f
    ctx->pc = 0x1b8104u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1b8108: 0x10830009
    ctx->pc = 0x1B8108u;
    {
        const bool branch_taken_0x1b8108 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x1B810Cu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1b8108) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B8110u;
    // 0x1b8110: 0x902343f9
    ctx->pc = 0x1b8110u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17401)));
    // 0x1b8114: 0x10830006
    ctx->pc = 0x1B8114u;
    {
        const bool branch_taken_0x1b8114 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1b8114) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B811Cu;
    // 0x1b811c: 0x3c010023
    ctx->pc = 0x1b811cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1b8120: 0x802347f8
    ctx->pc = 0x1b8120u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
    // 0x1b8124: 0x10640002
    ctx->pc = 0x1B8124u;
    {
        const bool branch_taken_0x1b8124 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 4));
        ctx->pc = 0x1B8128u;
        SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
        if (branch_taken_0x1b8124) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B812Cu;
    // 0x1b812c: 0xa02547f8
    ctx->pc = 0x1b812cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18424), (uint8_t)GPR_U32(ctx, 5));
label_1b8130:
    // 0x1b8130: 0x3e00008
    ctx->pc = 0x1B8130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B80D0u: goto label_1b80d0;
            case 0x1B80FCu: goto label_1b80fc;
            case 0x1B8130u: goto label_1b8130;
            case 0x1B8164u: goto label_1b8164;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8138u;
    // 0x1b8138: 0x0
    ctx->pc = 0x1b8138u;
    // NOP
    // 0x1b813c: 0x0
    ctx->pc = 0x1b813cu;
    // NOP
    // 0x1b8140: 0x27bdfff0
    ctx->pc = 0x1b8140u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8144: 0x3c040058
    ctx->pc = 0x1b8144u;
    SET_GPR_U32(ctx, 4, ((uint32_t)88 << 16));
    // 0x1b8148: 0xffbf0000
    ctx->pc = 0x1b8148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b814c: 0x2484f1f0
    ctx->pc = 0x1b814cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294963696));
    // 0x1b8150: 0xc06dfd0
    ctx->pc = 0x1B8150u;
    SET_GPR_U32(ctx, 31, 0x1B8158u);
    ctx->pc = 0x1B8154u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1B7F40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8158u; }
    }
    if (ctx->pc != 0x1B8158u) { return; }
    ctx->pc = 0x1B8158u;
    // 0x1b8158: 0x24040001
    ctx->pc = 0x1b8158u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b815c: 0xc06e034
    ctx->pc = 0x1B815Cu;
    SET_GPR_U32(ctx, 31, 0x1B8164u);
    ctx->pc = 0x1B8160u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1B80D0u;
    goto label_1b80d0;
    ctx->pc = 0x1B8164u;
label_1b8164:
    // 0x1b8164: 0xdfbf0000
    ctx->pc = 0x1b8164u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8168: 0x3e00008
    ctx->pc = 0x1B8168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B816Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B80D0u: goto label_1b80d0;
            case 0x1B80FCu: goto label_1b80fc;
            case 0x1B8130u: goto label_1b8130;
            case 0x1B8164u: goto label_1b8164;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8170u;
}
