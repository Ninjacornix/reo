#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00103088
// Address: 0x103088 - 0x103168
void sub_00103088_0x103088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x103088u;

    // 0x103088: 0x27bdffb0
    ctx->pc = 0x103088u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x10308c: 0x3c021000
    ctx->pc = 0x10308cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x103090: 0xffb10030
    ctx->pc = 0x103090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x103094: 0x3442e000
    ctx->pc = 0x103094u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57344));
    // 0x103098: 0xffb00020
    ctx->pc = 0x103098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x10309c: 0x3c060023
    ctx->pc = 0x10309cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)35 << 16));
    // 0x1030a0: 0xffbf0040
    ctx->pc = 0x1030a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1030a4: 0x3c030021
    ctx->pc = 0x1030a4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x1030a8: 0x80802d
    ctx->pc = 0x1030a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1030ac: 0x246394c8
    ctx->pc = 0x1030acu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294939848));
    // 0x1030b0: 0x8c450000
    ctx->pc = 0x1030b0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1030b4: 0x24c67710
    ctx->pc = 0x1030b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 30480));
    // 0x1030b8: 0x24040009
    ctx->pc = 0x1030b8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 9));
    // 0x1030bc: 0x30b10001
    ctx->pc = 0x1030bcu;
    SET_GPR_U32(ctx, 17, AND32(GPR_U32(ctx, 5), 1));
label_1030c0:
    // 0x1030c0: 0x8cc20000
    ctx->pc = 0x1030c0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1030c4: 0x50400009
    ctx->pc = 0x1030C4u;
    {
        const bool branch_taken_0x1030c4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1030c4) {
            ctx->pc = 0x1030C8u;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4));
            ctx->pc = 0x1030ECu;
            goto label_1030ec;
        }
    }
    ctx->pc = 0x1030CCu;
    // 0x1030cc: 0x8c620000
    ctx->pc = 0x1030ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1030d0: 0xac400080
    ctx->pc = 0x1030d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 0));
    // 0x1030d4: 0xac400000
    ctx->pc = 0x1030d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1030d8: 0xac400030
    ctx->pc = 0x1030d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 0));
    // 0x1030dc: 0xac400010
    ctx->pc = 0x1030dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x1030e0: 0xac400050
    ctx->pc = 0x1030e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 80), GPR_U32(ctx, 0));
    // 0x1030e4: 0xac400040
    ctx->pc = 0x1030e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 64), GPR_U32(ctx, 0));
    // 0x1030e8: 0x24630004
    ctx->pc = 0x1030e8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4));
label_1030ec:
    // 0x1030ec: 0x2484ffff
    ctx->pc = 0x1030ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1030f0: 0x481fff3
    ctx->pc = 0x1030F0u;
    {
        const bool branch_taken_0x1030f0 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x1030F4u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4));
        if (branch_taken_0x1030f0) {
            ctx->pc = 0x1030C0u;
            goto label_1030c0;
        }
    }
    ctx->pc = 0x1030F8u;
    // 0x1030f8: 0x3c031000
    ctx->pc = 0x1030f8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1030fc: 0x3402ff1f
    ctx->pc = 0x1030fcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 65311));
    // 0x103100: 0x3463e010
    ctx->pc = 0x103100u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57360));
    // 0x103104: 0x3c06ff1f
    ctx->pc = 0x103104u;
    SET_GPR_U32(ctx, 6, ((uint32_t)65311 << 16));
    // 0x103108: 0xac620000
    ctx->pc = 0x103108u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x10310c: 0x3a0202d
    ctx->pc = 0x10310cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103110: 0x24050014
    ctx->pc = 0x103110u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 20));
    // 0x103114: 0x8c620000
    ctx->pc = 0x103114u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x103118: 0x461024
    ctx->pc = 0x103118u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x10311c: 0xc040c0a
    ctx->pc = 0x10311Cu;
    SET_GPR_U32(ctx, 31, 0x103124u);
    ctx->pc = 0x103120u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x103028u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103028_0x103028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103124u; }
    }
    if (ctx->pc != 0x103124u) { return; }
    ctx->pc = 0x103124u;
    // 0x103124: 0xc040c5a
    ctx->pc = 0x103124u;
    SET_GPR_U32(ctx, 31, 0x10312Cu);
    ctx->pc = 0x103128u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x103168u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103168_0x103168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10312Cu; }
    }
    if (ctx->pc != 0x10312Cu) { return; }
    ctx->pc = 0x10312Cu;
    // 0x10312c: 0x24030001
    ctx->pc = 0x10312cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x103130: 0x16030007
    ctx->pc = 0x103130u;
    {
        const bool branch_taken_0x103130 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 3));
        ctx->pc = 0x103134u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x103130) {
            ctx->pc = 0x103150u;
            goto label_103150;
        }
    }
    ctx->pc = 0x103138u;
    // 0x103138: 0x3c031000
    ctx->pc = 0x103138u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x10313c: 0x3463e000
    ctx->pc = 0x10313cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57344));
    // 0x103140: 0x8c620000
    ctx->pc = 0x103140u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103144: 0x34420001
    ctx->pc = 0x103144u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 1));
    // 0x103148: 0xac620000
    ctx->pc = 0x103148u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x10314c: 0x220102d
    ctx->pc = 0x10314cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_103150:
    // 0x103150: 0xdfbf0040
    ctx->pc = 0x103150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x103154: 0xdfb10030
    ctx->pc = 0x103154u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x103158: 0xdfb00020
    ctx->pc = 0x103158u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10315c: 0x3e00008
    ctx->pc = 0x10315Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103160u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1030C0u: goto label_1030c0;
            case 0x1030ECu: goto label_1030ec;
            case 0x103150u: goto label_103150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103164u;
    // 0x103164: 0x0
    ctx->pc = 0x103164u;
    // NOP
}
