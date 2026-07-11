#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0019F6C0
// Address: 0x19f6c0 - 0x19f750
void sub_0019F6C0_0x19f6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x19f6c0u;

    // 0x19f6c0: 0x27bdfff0
    ctx->pc = 0x19f6c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f6c4: 0xffbf0000
    ctx->pc = 0x19f6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f6c8: 0xc06eaf0
    ctx->pc = 0x19F6C8u;
    SET_GPR_U32(ctx, 31, 0x19F6D0u);
    ctx->pc = 0x1BABC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BABC0_0x1babc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D0u; }
    }
    if (ctx->pc != 0x19F6D0u) { return; }
    ctx->pc = 0x19F6D0u;
    // 0x19f6d0: 0xc063594
    ctx->pc = 0x19F6D0u;
    SET_GPR_U32(ctx, 31, 0x19F6D8u);
    ctx->pc = 0x18D650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D8u; }
    }
    if (ctx->pc != 0x19F6D8u) { return; }
    ctx->pc = 0x19F6D8u;
    // 0x19f6d8: 0xc06a42c
    ctx->pc = 0x19F6D8u;
    SET_GPR_U32(ctx, 31, 0x19F6E0u);
    ctx->pc = 0x1A90B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A90B0_0x1a90b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6E0u; }
    }
    if (ctx->pc != 0x19F6E0u) { return; }
    ctx->pc = 0x19F6E0u;
    // 0x19f6e0: 0x24020083
    ctx->pc = 0x19f6e0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 131));
    // 0x19f6e4: 0x3c011000
    ctx->pc = 0x19f6e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x19f6e8: 0xac220010
    ctx->pc = 0x19f6e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 16), GPR_U32(ctx, 2)); // MMIO: 0x10000010
    // 0x19f6ec: 0x3c011000
    ctx->pc = 0x19f6ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x19f6f0: 0xac200000
    ctx->pc = 0x19f6f0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x19f6f4: 0x3c01002a
    ctx->pc = 0x19f6f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f6f8: 0xac20fa0c
    ctx->pc = 0x19f6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 0));
    // 0x19f6fc: 0x3c01002a
    ctx->pc = 0x19f6fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f700: 0x8c22fec8
    ctx->pc = 0x19f700u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966984)));
    // 0x19f704: 0x24420001
    ctx->pc = 0x19f704u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x19f708: 0x3c01002a
    ctx->pc = 0x19f708u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f70c: 0xc06351c
    ctx->pc = 0x19F70Cu;
    SET_GPR_U32(ctx, 31, 0x19F714u);
    ctx->pc = 0x19F710u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966984), GPR_U32(ctx, 2));
    ctx->pc = 0x18D470u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D470_0x18d470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F714u; }
    }
    if (ctx->pc != 0x19F714u) { return; }
    ctx->pc = 0x19F714u;
    // 0x19f714: 0xc063750
    ctx->pc = 0x19F714u;
    SET_GPR_U32(ctx, 31, 0x19F71Cu);
    ctx->pc = 0x18DD40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DD40_0x18dd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F71Cu; }
    }
    if (ctx->pc != 0x19F71Cu) { return; }
    ctx->pc = 0x19F71Cu;
    // 0x19f71c: 0xc068248
    ctx->pc = 0x19F71Cu;
    SET_GPR_U32(ctx, 31, 0x19F724u);
    ctx->pc = 0x1A0920u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0920_0x1a0920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F724u; }
    }
    if (ctx->pc != 0x19F724u) { return; }
    ctx->pc = 0x19F724u;
    // 0x19f724: 0x3c01002a
    ctx->pc = 0x19f724u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f728: 0x2402ffff
    ctx->pc = 0x19f728u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x19f72c: 0xac20fda0
    ctx->pc = 0x19f72cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966688), GPR_U32(ctx, 0));
    // 0x19f730: 0x3c01002a
    ctx->pc = 0x19f730u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f734: 0xc06ead8
    ctx->pc = 0x19F734u;
    SET_GPR_U32(ctx, 31, 0x19F73Cu);
    ctx->pc = 0x19F738u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966684), GPR_U32(ctx, 2));
    ctx->pc = 0x1BAB60u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAB60_0x1bab60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F73Cu; }
    }
    if (ctx->pc != 0x19F73Cu) { return; }
    ctx->pc = 0x19F73Cu;
    // 0x19f73c: 0xdfbf0000
    ctx->pc = 0x19f73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f740: 0x24020001
    ctx->pc = 0x19f740u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f744: 0x3e00008
    ctx->pc = 0x19F744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F748u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x19F74Cu;
    // 0x19f74c: 0x0
    ctx->pc = 0x19f74cu;
    // NOP
}
