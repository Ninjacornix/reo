#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001AF5D0
// Address: 0x1af5d0 - 0x1af6a0
void sub_001AF5D0_0x1af5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1af5d0u;

    // 0x1af5d0: 0x482d
    ctx->pc = 0x1af5d0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af5d4: 0x402d
    ctx->pc = 0x1af5d4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1af5d8:
    // 0x1af5d8: 0x15000005
    ctx->pc = 0x1AF5D8u;
    {
        const bool branch_taken_0x1af5d8 = (GPR_U32(ctx, 8) != GPR_U32(ctx, 0));
        ctx->pc = 0x1AF5DCu;
        SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
        if (branch_taken_0x1af5d8) {
            ctx->pc = 0x1AF5F0u;
            goto label_1af5f0;
        }
    }
    ctx->pc = 0x1AF5E0u;
    // 0x1af5e0: 0x84890000
    ctx->pc = 0x1af5e0u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af5e4: 0x34088000
    ctx->pc = 0x1af5e4u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 0), 32768));
    // 0x1af5e8: 0x24840002
    ctx->pc = 0x1af5e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 2));
    // 0x1af5ec: 0x1281824
    ctx->pc = 0x1af5ecu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
label_1af5f0:
    // 0x1af5f0: 0x10600021
    ctx->pc = 0x1AF5F0u;
    {
        const bool branch_taken_0x1af5f0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x1af5f0) {
            ctx->pc = 0x1AF678u;
            goto label_1af678;
        }
    }
    ctx->pc = 0x1AF5F8u;
    // 0x1af5f8: 0x94830000
    ctx->pc = 0x1af5f8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af5fc: 0x33ac2
    ctx->pc = 0x1af5fcu;
    SET_GPR_U32(ctx, 7, SRL32(GPR_U32(ctx, 3), 11));
    // 0x1af600: 0x10e00003
    ctx->pc = 0x1AF600u;
    {
        const bool branch_taken_0x1af600 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF604u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x1af600) {
            ctx->pc = 0x1AF610u;
            goto label_1af610;
        }
    }
    ctx->pc = 0x1AF608u;
    // 0x1af608: 0x10000003
    ctx->pc = 0x1AF608u;
    {
        const bool branch_taken_0x1af608 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF60Cu;
        SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 2047));
        if (branch_taken_0x1af608) {
            ctx->pc = 0x1AF618u;
            goto label_1af618;
        }
    }
    ctx->pc = 0x1AF610u;
label_1af610:
    // 0x1af610: 0x94870000
    ctx->pc = 0x1af610u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af614: 0x24840002
    ctx->pc = 0x1af614u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 2));
label_1af618:
    // 0x1af618: 0x1460000c
    ctx->pc = 0x1AF618u;
    {
        const bool branch_taken_0x1af618 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1af618) {
            ctx->pc = 0x1AF64Cu;
            goto label_1af64c;
        }
    }
    ctx->pc = 0x1AF620u;
    // 0x1af620: 0x10e0001c
    ctx->pc = 0x1AF620u;
    {
        const bool branch_taken_0x1af620 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        if (branch_taken_0x1af620) {
            ctx->pc = 0x1AF694u;
            goto label_1af694;
        }
    }
    ctx->pc = 0x1AF628u;
label_1af628:
    // 0x1af628: 0xa4a00000
    ctx->pc = 0x1af628u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1af62c: 0x24e7ffff
    ctx->pc = 0x1af62cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1af630: 0x24a50002
    ctx->pc = 0x1af630u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
    // 0x1af634: 0x0
    ctx->pc = 0x1af634u;
    // NOP
    // 0x1af638: 0x0
    ctx->pc = 0x1af638u;
    // NOP
    // 0x1af63c: 0x14e0fffa
    ctx->pc = 0x1AF63Cu;
    {
        const bool branch_taken_0x1af63c = (GPR_U32(ctx, 7) != GPR_U32(ctx, 0));
        if (branch_taken_0x1af63c) {
            ctx->pc = 0x1AF628u;
            goto label_1af628;
        }
    }
    ctx->pc = 0x1AF644u;
    // 0x1af644: 0x10000011
    ctx->pc = 0x1AF644u;
    {
        const bool branch_taken_0x1af644 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF648u;
        SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
        if (branch_taken_0x1af644) {
            ctx->pc = 0x1AF68Cu;
            goto label_1af68c;
        }
    }
    ctx->pc = 0x1AF64Cu;
label_1af64c:
    // 0x1af64c: 0x31840
    ctx->pc = 0x1af64cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 1));
    // 0x1af650: 0xa33023
    ctx->pc = 0x1af650u;
    SET_GPR_U32(ctx, 6, SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_1af654:
    // 0x1af654: 0x94c30000
    ctx->pc = 0x1af654u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1af658: 0x24e7ffff
    ctx->pc = 0x1af658u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1af65c: 0xa4a30000
    ctx->pc = 0x1af65cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1af660: 0x24c60002
    ctx->pc = 0x1af660u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
    // 0x1af664: 0x24a50002
    ctx->pc = 0x1af664u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
    // 0x1af668: 0x14e0fffa
    ctx->pc = 0x1AF668u;
    {
        const bool branch_taken_0x1af668 = (GPR_U32(ctx, 7) != GPR_U32(ctx, 0));
        if (branch_taken_0x1af668) {
            ctx->pc = 0x1AF654u;
            goto label_1af654;
        }
    }
    ctx->pc = 0x1AF670u;
    // 0x1af670: 0x10000005
    ctx->pc = 0x1AF670u;
    {
        const bool branch_taken_0x1af670 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1af670) {
            ctx->pc = 0x1AF688u;
            goto label_1af688;
        }
    }
    ctx->pc = 0x1AF678u;
label_1af678:
    // 0x1af678: 0x94830000
    ctx->pc = 0x1af678u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af67c: 0xa4a30000
    ctx->pc = 0x1af67cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1af680: 0x24840002
    ctx->pc = 0x1af680u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 2));
    // 0x1af684: 0x24a50002
    ctx->pc = 0x1af684u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
label_1af688:
    // 0x1af688: 0x84043
    ctx->pc = 0x1af688u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
label_1af68c:
    // 0x1af68c: 0x1000ffd2
    ctx->pc = 0x1AF68Cu;
    {
        const bool branch_taken_0x1af68c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1af68c) {
            ctx->pc = 0x1AF5D8u;
            goto label_1af5d8;
        }
    }
    ctx->pc = 0x1AF694u;
label_1af694:
    // 0x1af694: 0x3e00008
    ctx->pc = 0x1AF694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF5D8u: goto label_1af5d8;
            case 0x1AF5F0u: goto label_1af5f0;
            case 0x1AF610u: goto label_1af610;
            case 0x1AF618u: goto label_1af618;
            case 0x1AF628u: goto label_1af628;
            case 0x1AF64Cu: goto label_1af64c;
            case 0x1AF654u: goto label_1af654;
            case 0x1AF678u: goto label_1af678;
            case 0x1AF688u: goto label_1af688;
            case 0x1AF68Cu: goto label_1af68c;
            case 0x1AF694u: goto label_1af694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF69Cu;
    // 0x1af69c: 0x0
    ctx->pc = 0x1af69cu;
    // NOP
}
