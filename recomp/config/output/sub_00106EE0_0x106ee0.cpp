#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00106EE0
// Address: 0x106ee0 - 0x106f38
void sub_00106EE0_0x106ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x106ee0u;

    // 0x106ee0: 0x27bdffe0
    ctx->pc = 0x106ee0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106ee4: 0xffb00000
    ctx->pc = 0x106ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106ee8: 0x3c100021
    ctx->pc = 0x106ee8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x106eec: 0xffb10008
    ctx->pc = 0x106eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106ef0: 0x80882d
    ctx->pc = 0x106ef0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ef4: 0xffbf0010
    ctx->pc = 0x106ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106ef8: 0x261097f0
    ctx->pc = 0x106ef8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x106efc: 0xc041f4a
    ctx->pc = 0x106EFCu;
    SET_GPR_U32(ctx, 31, 0x106F04u);
    ctx->pc = 0x106F00u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x107D28u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F04u; }
    }
    if (ctx->pc != 0x106F04u) { return; }
    ctx->pc = 0x106F04u;
    // 0x106f04: 0x8e040000
    ctx->pc = 0x106f04u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f08: 0xc041c76
    ctx->pc = 0x106F08u;
    SET_GPR_U32(ctx, 31, 0x106F10u);
    ctx->pc = 0x106F0Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1071D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F10u; }
    }
    if (ctx->pc != 0x106F10u) { return; }
    ctx->pc = 0x106F10u;
    // 0x106f10: 0x8e040000
    ctx->pc = 0x106f10u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f14: 0xc041f6a
    ctx->pc = 0x106F14u;
    SET_GPR_U32(ctx, 31, 0x106F1Cu);
    ctx->pc = 0x106F18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x107DA8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F1Cu; }
    }
    if (ctx->pc != 0x106F1Cu) { return; }
    ctx->pc = 0x106F1Cu;
    // 0x106f1c: 0x220102d
    ctx->pc = 0x106f1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106f20: 0xdfb00000
    ctx->pc = 0x106f20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106f24: 0xdfb10008
    ctx->pc = 0x106f24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106f28: 0xdfbf0010
    ctx->pc = 0x106f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106f2c: 0x3e00008
    ctx->pc = 0x106F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106F30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x106F34u;
    // 0x106f34: 0x0
    ctx->pc = 0x106f34u;
    // NOP
}
