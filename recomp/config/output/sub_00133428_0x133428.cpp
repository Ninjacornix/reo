#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00133428
// Address: 0x133428 - 0x133490
void sub_00133428_0x133428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x133428u;

    // 0x133428: 0x27bdfff0
    ctx->pc = 0x133428u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13342c: 0xffbf0000
    ctx->pc = 0x13342cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133430: 0xdfbf0000
    ctx->pc = 0x133430u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133434: 0x8049bf6
    ctx->pc = 0x133434u;
    ctx->pc = 0x133438u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x126FD8u;
    entry_126fd8_0x127158(rdram, ctx, runtime); return;
    ctx->pc = 0x13343Cu;
    // 0x13343c: 0x0
    ctx->pc = 0x13343cu;
    // NOP
    // 0x133440: 0x27bdfff0
    ctx->pc = 0x133440u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133444: 0x14800006
    ctx->pc = 0x133444u;
    {
        const bool branch_taken_0x133444 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x133448u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x133444) {
            ctx->pc = 0x133460u;
            goto label_133460;
        }
    }
    ctx->pc = 0x13344Cu;
    // 0x13344c: 0x3c040024
    ctx->pc = 0x13344cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x133450: 0xdfbf0000
    ctx->pc = 0x133450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133454: 0x2484b548
    ctx->pc = 0x133454u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294948168));
    // 0x133458: 0x804a034
    ctx->pc = 0x133458u;
    ctx->pc = 0x13345Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1280D0u;
    sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    ctx->pc = 0x133460u;
label_133460:
    // 0x133460: 0x8c840004
    ctx->pc = 0x133460u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x133464: 0xdfbf0000
    ctx->pc = 0x133464u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133468: 0x804b5be
    ctx->pc = 0x133468u;
    ctx->pc = 0x13346Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12D6F8u;
    entry_12d6f8_0x12d710(rdram, ctx, runtime); return;
    ctx->pc = 0x133470u;
    // 0x133470: 0x27bdfff0
    ctx->pc = 0x133470u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133474: 0xffbf0000
    ctx->pc = 0x133474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133478: 0xdfbf0000
    ctx->pc = 0x133478u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13347c: 0x804b5c4
    ctx->pc = 0x13347Cu;
    ctx->pc = 0x133480u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12D710u;
    entry_12d710_0x12d728(rdram, ctx, runtime); return;
    ctx->pc = 0x133484u;
    // 0x133484: 0x0
    ctx->pc = 0x133484u;
    // NOP
    // 0x133488: 0x3e00008
    ctx->pc = 0x133488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13348Cu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133460u: goto label_133460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133490u;
}
