#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001DB0B8
// Address: 0x1db0b8 - 0x1db16c
void sub_001DB0B8_0x1db0b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1db0b8u;

    // 0x1db0b8: 0x27bdffe0
    ctx->pc = 0x1db0b8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db0bc: 0xffbe0010
    ctx->pc = 0x1db0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db0c0: 0xffbf0018
    ctx->pc = 0x1db0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1db0c4: 0x3a0f02d
    ctx->pc = 0x1db0c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0c8: 0xafc40000
    ctx->pc = 0x1db0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db0cc: 0xafc50004
    ctx->pc = 0x1db0ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1db0d0: 0x8fc30000
    ctx->pc = 0x1db0d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db0d4: 0x27c5000c
    ctx->pc = 0x1db0d4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 30), 12));
    // 0x1db0d8: 0x97c20004
    ctx->pc = 0x1db0d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db0dc: 0x24420014
    ctx->pc = 0x1db0dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 20));
    // 0x1db0e0: 0x3042ffff
    ctx->pc = 0x1db0e0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x1db0e4: 0x8c640520
    ctx->pc = 0x1db0e4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 1312)));
    // 0x1db0e8: 0x40302d
    ctx->pc = 0x1db0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0ec: 0x24070001
    ctx->pc = 0x1db0ecu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1db0f0: 0x24080001
    ctx->pc = 0x1db0f0u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1db0f4: 0xc07c80a
    ctx->pc = 0x1DB0F4u;
    SET_GPR_U32(ctx, 31, 0x1DB0FCu);
    ctx->pc = 0x1F2028u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB0FCu; }
    }
    if (ctx->pc != 0x1DB0FCu) { return; }
    ctx->pc = 0x1DB0FCu;
    // 0x1db0fc: 0xafc20008
    ctx->pc = 0x1db0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1db100: 0x8fc20008
    ctx->pc = 0x1db100u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1db104: 0x10400004
    ctx->pc = 0x1DB104u;
    {
        const bool branch_taken_0x1db104 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1db104) {
            ctx->pc = 0x1DB118u;
            goto label_1db118;
        }
    }
    ctx->pc = 0x1DB10Cu;
    // 0x1db10c: 0x8fc2000c
    ctx->pc = 0x1db10cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db110: 0x10000010
    ctx->pc = 0x1DB110u;
    {
        const bool branch_taken_0x1db110 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1db110) {
            ctx->pc = 0x1DB154u;
            goto label_1db154;
        }
    }
    ctx->pc = 0x1DB118u;
label_1db118:
    // 0x1db118: 0x8fc4000c
    ctx->pc = 0x1db118u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db11c: 0x24050010
    ctx->pc = 0x1db11cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1db120: 0xc07cc3c
    ctx->pc = 0x1DB120u;
    SET_GPR_U32(ctx, 31, 0x1DB128u);
    ctx->pc = 0x1F30F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB128u; }
    }
    if (ctx->pc != 0x1DB128u) { return; }
    ctx->pc = 0x1DB128u;
    // 0x1db128: 0x14400009
    ctx->pc = 0x1DB128u;
    {
        const bool branch_taken_0x1db128 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1db128) {
            ctx->pc = 0x1DB150u;
            goto label_1db150;
        }
    }
    ctx->pc = 0x1DB130u;
    // 0x1db130: 0x8fc20000
    ctx->pc = 0x1db130u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db134: 0x8c440520
    ctx->pc = 0x1db134u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1db138: 0x8fc5000c
    ctx->pc = 0x1db138u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db13c: 0xc07ca04
    ctx->pc = 0x1DB13Cu;
    SET_GPR_U32(ctx, 31, 0x1DB144u);
    ctx->pc = 0x1F2810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB144u; }
    }
    if (ctx->pc != 0x1DB144u) { return; }
    ctx->pc = 0x1DB144u;
    // 0x1db144: 0x102d
    ctx->pc = 0x1db144u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db148: 0x10000002
    ctx->pc = 0x1DB148u;
    {
        const bool branch_taken_0x1db148 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1db148) {
            ctx->pc = 0x1DB154u;
            goto label_1db154;
        }
    }
    ctx->pc = 0x1DB150u;
label_1db150:
    // 0x1db150: 0x8fc2000c
    ctx->pc = 0x1db150u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1db154:
    // 0x1db154: 0x3c0e82d
    ctx->pc = 0x1db154u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db158: 0xdfbe0010
    ctx->pc = 0x1db158u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db15c: 0xdfbf0018
    ctx->pc = 0x1db15cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db160: 0x27bd0020
    ctx->pc = 0x1db160u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db164: 0x3e00008
    ctx->pc = 0x1DB164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB118u: goto label_1db118;
            case 0x1DB150u: goto label_1db150;
            case 0x1DB154u: goto label_1db154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB16Cu;
}
