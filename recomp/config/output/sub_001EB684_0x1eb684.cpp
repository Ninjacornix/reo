#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001EB684
// Address: 0x1eb684 - 0x1eb764
void sub_001EB684_0x1eb684(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1eb684u;

    // 0x1eb684: 0x27bdffe0
    ctx->pc = 0x1eb684u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1eb688: 0xffbe0010
    ctx->pc = 0x1eb688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1eb68c: 0x3a0f02d
    ctx->pc = 0x1eb68cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb690: 0xafc40000
    ctx->pc = 0x1eb690u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb694: 0x8fc30000
    ctx->pc = 0x1eb694u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb698: 0x3c026745
    ctx->pc = 0x1eb698u;
    SET_GPR_U32(ctx, 2, ((uint32_t)26437 << 16));
    // 0x1eb69c: 0x34422301
    ctx->pc = 0x1eb69cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8961));
    // 0x1eb6a0: 0xac620000
    ctx->pc = 0x1eb6a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb6a4: 0x8fc30000
    ctx->pc = 0x1eb6a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6a8: 0x3c02efcd
    ctx->pc = 0x1eb6a8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)61389 << 16));
    // 0x1eb6ac: 0x3442ab89
    ctx->pc = 0x1eb6acu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 43913));
    // 0x1eb6b0: 0xac620004
    ctx->pc = 0x1eb6b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1eb6b4: 0x8fc30000
    ctx->pc = 0x1eb6b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6b8: 0x3c0298ba
    ctx->pc = 0x1eb6b8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)39098 << 16));
    // 0x1eb6bc: 0x3442dcfe
    ctx->pc = 0x1eb6bcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 56574));
    // 0x1eb6c0: 0xac620008
    ctx->pc = 0x1eb6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1eb6c4: 0x8fc30000
    ctx->pc = 0x1eb6c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6c8: 0x3c021032
    ctx->pc = 0x1eb6c8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4146 << 16));
    // 0x1eb6cc: 0x34425476
    ctx->pc = 0x1eb6ccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 21622));
    // 0x1eb6d0: 0xac62000c
    ctx->pc = 0x1eb6d0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
    // 0x1eb6d4: 0x8fc30000
    ctx->pc = 0x1eb6d4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6d8: 0x3c02c3d2
    ctx->pc = 0x1eb6d8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)50130 << 16));
    // 0x1eb6dc: 0x3442e1f0
    ctx->pc = 0x1eb6dcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57840));
    // 0x1eb6e0: 0xac620010
    ctx->pc = 0x1eb6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1eb6e4: 0x8fc20000
    ctx->pc = 0x1eb6e4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6e8: 0xac400014
    ctx->pc = 0x1eb6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x1eb6ec: 0x8fc20000
    ctx->pc = 0x1eb6ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6f0: 0xac400018
    ctx->pc = 0x1eb6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x1eb6f4: 0x8fc20000
    ctx->pc = 0x1eb6f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6f8: 0xac40001c
    ctx->pc = 0x1eb6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x1eb6fc: 0x8fc20000
    ctx->pc = 0x1eb6fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb700: 0xac400020
    ctx->pc = 0x1eb700u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 0));
    // 0x1eb704: 0xafc00004
    ctx->pc = 0x1eb704u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1eb708:
    // 0x1eb708: 0x8fc20004
    ctx->pc = 0x1eb708u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb70c: 0x28420050
    ctx->pc = 0x1eb70cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 80));
    // 0x1eb710: 0x14400003
    ctx->pc = 0x1EB710u;
    {
        const bool branch_taken_0x1eb710 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1eb710) {
            ctx->pc = 0x1EB720u;
            goto label_1eb720;
        }
    }
    ctx->pc = 0x1EB718u;
    // 0x1eb718: 0x1000000d
    ctx->pc = 0x1EB718u;
    {
        const bool branch_taken_0x1eb718 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1eb718) {
            ctx->pc = 0x1EB750u;
            goto label_1eb750;
        }
    }
    ctx->pc = 0x1EB720u;
label_1eb720:
    // 0x1eb720: 0x8fc40000
    ctx->pc = 0x1eb720u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb724: 0x8fc20004
    ctx->pc = 0x1eb724u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb728: 0x21080
    ctx->pc = 0x1eb728u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eb72c: 0x24430020
    ctx->pc = 0x1eb72cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 2), 32));
    // 0x1eb730: 0x24820004
    ctx->pc = 0x1eb730u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eb734: 0x431021
    ctx->pc = 0x1eb734u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1eb738: 0xac400000
    ctx->pc = 0x1eb738u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1eb73c: 0x8fc20004
    ctx->pc = 0x1eb73cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb740: 0x24420001
    ctx->pc = 0x1eb740u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb744: 0xafc20004
    ctx->pc = 0x1eb744u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1eb748: 0x1000ffef
    ctx->pc = 0x1EB748u;
    {
        const bool branch_taken_0x1eb748 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1eb748) {
            ctx->pc = 0x1EB708u;
            goto label_1eb708;
        }
    }
    ctx->pc = 0x1EB750u;
label_1eb750:
    // 0x1eb750: 0x3c0e82d
    ctx->pc = 0x1eb750u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb754: 0xdfbe0010
    ctx->pc = 0x1eb754u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1eb758: 0x27bd0020
    ctx->pc = 0x1eb758u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1eb75c: 0x3e00008
    ctx->pc = 0x1EB75Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB708u: goto label_1eb708;
            case 0x1EB720u: goto label_1eb720;
            case 0x1EB750u: goto label_1eb750;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB764u;
}
