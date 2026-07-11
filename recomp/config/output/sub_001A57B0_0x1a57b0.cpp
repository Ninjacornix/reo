#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A57B0
// Address: 0x1a57b0 - 0x1a5850
void sub_001A57B0_0x1a57b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a57b0u;

    // 0x1a57b0: 0x90830000
    ctx->pc = 0x1a57b0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a57b4: 0x24020054
    ctx->pc = 0x1a57b4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 84));
    // 0x1a57b8: 0x1462000e
    ctx->pc = 0x1A57B8u;
    {
        const bool branch_taken_0x1a57b8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1A57BCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a57b8) {
            ctx->pc = 0x1A57F4u;
            goto label_1a57f4;
        }
    }
    ctx->pc = 0x1A57C0u;
    // 0x1a57c0: 0x90830001
    ctx->pc = 0x1a57c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1a57c4: 0x24020049
    ctx->pc = 0x1a57c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 73));
    // 0x1a57c8: 0x14620009
    ctx->pc = 0x1A57C8u;
    {
        const bool branch_taken_0x1a57c8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1a57c8) {
            ctx->pc = 0x1A57F0u;
            goto label_1a57f0;
        }
    }
    ctx->pc = 0x1A57D0u;
    // 0x1a57d0: 0x90830002
    ctx->pc = 0x1a57d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a57d4: 0x2402004d
    ctx->pc = 0x1a57d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 77));
    // 0x1a57d8: 0x14620005
    ctx->pc = 0x1A57D8u;
    {
        const bool branch_taken_0x1a57d8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1a57d8) {
            ctx->pc = 0x1A57F0u;
            goto label_1a57f0;
        }
    }
    ctx->pc = 0x1A57E0u;
    // 0x1a57e0: 0x90830003
    ctx->pc = 0x1a57e0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1a57e4: 0x24020032
    ctx->pc = 0x1a57e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 50));
    // 0x1a57e8: 0x10620004
    ctx->pc = 0x1A57E8u;
    {
        const bool branch_taken_0x1a57e8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1a57e8) {
            ctx->pc = 0x1A57FCu;
            goto label_1a57fc;
        }
    }
    ctx->pc = 0x1A57F0u;
label_1a57f0:
    // 0x1a57f0: 0x102d
    ctx->pc = 0x1a57f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a57f4:
    // 0x1a57f4: 0x10000014
    ctx->pc = 0x1A57F4u;
    {
        const bool branch_taken_0x1a57f4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a57f4) {
            ctx->pc = 0x1A5848u;
            goto label_1a5848;
        }
    }
    ctx->pc = 0x1A57FCu;
label_1a57fc:
    // 0x1a57fc: 0x90830004
    ctx->pc = 0x1a57fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a5800: 0x24020003
    ctx->pc = 0x1a5800u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a5804: 0x1062000b
    ctx->pc = 0x1A5804u;
    {
        const bool branch_taken_0x1a5804 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x1A5808u;
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
        if (branch_taken_0x1a5804) {
            ctx->pc = 0x1A5834u;
            goto label_1a5834;
        }
    }
    ctx->pc = 0x1A580Cu;
    // 0x1a580c: 0x24020004
    ctx->pc = 0x1a580cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a5810: 0x14620006
    ctx->pc = 0x1A5810u;
    {
        const bool branch_taken_0x1a5810 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1A5814u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a5810) {
            ctx->pc = 0x1A582Cu;
            goto label_1a582c;
        }
    }
    ctx->pc = 0x1A5818u;
    // 0x1a5818: 0x30a200ff
    ctx->pc = 0x1a5818u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 5), 255));
    // 0x1a581c: 0x2c410002
    ctx->pc = 0x1a581cu;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 2), 2));
    // 0x1a5820: 0x14200004
    ctx->pc = 0x1A5820u;
    {
        const bool branch_taken_0x1a5820 = (GPR_U32(ctx, 1) != GPR_U32(ctx, 0));
        if (branch_taken_0x1a5820) {
            ctx->pc = 0x1A5834u;
            goto label_1a5834;
        }
    }
    ctx->pc = 0x1A5828u;
    // 0x1a5828: 0x102d
    ctx->pc = 0x1a5828u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a582c:
    // 0x1a582c: 0x10000006
    ctx->pc = 0x1A582Cu;
    {
        const bool branch_taken_0x1a582c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a582c) {
            ctx->pc = 0x1A5848u;
            goto label_1a5848;
        }
    }
    ctx->pc = 0x1A5834u;
label_1a5834:
    // 0x1a5834: 0x94830006
    ctx->pc = 0x1a5834u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1a5838: 0x24020001
    ctx->pc = 0x1a5838u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a583c: 0x10620002
    ctx->pc = 0x1A583Cu;
    {
        const bool branch_taken_0x1a583c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1a583c) {
            ctx->pc = 0x1A5848u;
            goto label_1a5848;
        }
    }
    ctx->pc = 0x1A5844u;
    // 0x1a5844: 0x102d
    ctx->pc = 0x1a5844u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a5848:
    // 0x1a5848: 0x3e00008
    ctx->pc = 0x1A5848u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A57F0u: goto label_1a57f0;
            case 0x1A57F4u: goto label_1a57f4;
            case 0x1A57FCu: goto label_1a57fc;
            case 0x1A582Cu: goto label_1a582c;
            case 0x1A5834u: goto label_1a5834;
            case 0x1A5848u: goto label_1a5848;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5850u;
}
