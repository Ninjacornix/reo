#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A9400
// Address: 0x1a9400 - 0x1a9480
void sub_001A9400_0x1a9400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a9400u;

    // 0x1a9400: 0x27bdfff0
    ctx->pc = 0x1a9400u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9404: 0x18800005
    ctx->pc = 0x1A9404u;
    {
        const bool branch_taken_0x1a9404 = (GPR_S32(ctx, 4) <= 0);
        ctx->pc = 0x1A9408u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x1a9404) {
            ctx->pc = 0x1A941Cu;
            goto label_1a941c;
        }
    }
    ctx->pc = 0x1A940Cu;
    // 0x1a940c: 0x8ca50000
    ctx->pc = 0x1a940cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a9410: 0x3c04002b
    ctx->pc = 0x1a9410u;
    SET_GPR_U32(ctx, 4, ((uint32_t)43 << 16));
    // 0x1a9414: 0xc042bf0
    ctx->pc = 0x1A9414u;
    SET_GPR_U32(ctx, 31, 0x1A941Cu);
    ctx->pc = 0x1A9418u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 14096));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A941Cu; }
    }
    if (ctx->pc != 0x1A941Cu) { return; }
    ctx->pc = 0x1A941Cu;
label_1a941c:
    // 0x1a941c: 0xc06a474
    ctx->pc = 0x1A941Cu;
    SET_GPR_U32(ctx, 31, 0x1A9424u);
    ctx->pc = 0x1A91D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A91D0_0x1a91d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9424u; }
    }
    if (ctx->pc != 0x1A9424u) { return; }
    ctx->pc = 0x1A9424u;
label_1a9424:
    // 0x1a9424: 0xc06ea80
    ctx->pc = 0x1A9424u;
    SET_GPR_U32(ctx, 31, 0x1A942Cu);
    ctx->pc = 0x1BAA00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAA00_0x1baa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A942Cu; }
    }
    if (ctx->pc != 0x1A942Cu) { return; }
    ctx->pc = 0x1A942Cu;
    // 0x1a942c: 0xc0759c8
    ctx->pc = 0x1A942Cu;
    SET_GPR_U32(ctx, 31, 0x1A9434u);
    ctx->pc = 0x1D6720u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6720_0x1d6720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9434u; }
    }
    if (ctx->pc != 0x1A9434u) { return; }
    ctx->pc = 0x1A9434u;
    // 0x1a9434: 0x2102b
    ctx->pc = 0x1a9434u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1a9438: 0x38420001
    ctx->pc = 0x1a9438u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 1));
    // 0x1a943c: 0x1440fff9
    ctx->pc = 0x1A943Cu;
    {
        const bool branch_taken_0x1a943c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1A9440u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1a943c) {
            ctx->pc = 0x1A9424u;
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A9444u;
    // 0x1a9444: 0x942244c0
    ctx->pc = 0x1a9444u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17600)));
    // 0x1a9448: 0x3042001f
    ctx->pc = 0x1a9448u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 31));
    // 0x1a944c: 0x1440fff5
    ctx->pc = 0x1A944Cu;
    {
        const bool branch_taken_0x1a944c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1a944c) {
            ctx->pc = 0x1A9424u;
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A9454u;
    // 0x1a9454: 0x3c010034
    ctx->pc = 0x1a9454u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1a9458: 0x8c23d158
    ctx->pc = 0x1a9458u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1a945c: 0x3c010034
    ctx->pc = 0x1a945cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1a9460: 0x8c640000
    ctx->pc = 0x1a9460u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a9464: 0x8022cc48
    ctx->pc = 0x1a9464u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1a9468: 0x38420001
    ctx->pc = 0x1a9468u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 1));
    // 0x1a946c: 0xc0759d8
    ctx->pc = 0x1A946Cu;
    SET_GPR_U32(ctx, 31, 0x1A9474u);
    ctx->pc = 0x1A9470u;
    SET_GPR_U32(ctx, 5, SLTU32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1D6760u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6760_0x1d6760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9474u; }
    }
    if (ctx->pc != 0x1A9474u) { return; }
    ctx->pc = 0x1A9474u;
    // 0x1a9474: 0x1000ffeb
    ctx->pc = 0x1A9474u;
    {
        const bool branch_taken_0x1a9474 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a9474) {
            ctx->pc = 0x1A9424u;
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A947Cu;
    // 0x1a947c: 0x0
    ctx->pc = 0x1a947cu;
    // NOP
}
