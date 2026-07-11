#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011D9C8
// Address: 0x11d9c8 - 0x11da30
void sub_0011D9C8_0x11d9c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11d9c8u;

    // 0x11d9c8: 0x27bdffd0
    ctx->pc = 0x11d9c8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11d9cc: 0xffb00010
    ctx->pc = 0x11d9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11d9d0: 0xffbf0020
    ctx->pc = 0x11d9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11d9d4: 0xc0451b4
    ctx->pc = 0x11D9D4u;
    SET_GPR_U32(ctx, 31, 0x11D9DCu);
    ctx->pc = 0x11D9D8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1146D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D9DCu; }
    }
    if (ctx->pc != 0x11D9DCu) { return; }
    ctx->pc = 0x11D9DCu;
    // 0x11d9dc: 0x8fa30000
    ctx->pc = 0x11d9dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d9e0: 0x3c02ffff
    ctx->pc = 0x11d9e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x11d9e4: 0x34421fff
    ctx->pc = 0x11d9e4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8191));
    // 0x11d9e8: 0x27b00004
    ctx->pc = 0x11d9e8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 29), 4));
    // 0x11d9ec: 0x621824
    ctx->pc = 0x11d9ecu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11d9f0: 0x200202d
    ctx->pc = 0x11d9f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d9f4: 0x34632000
    ctx->pc = 0x11d9f4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8192));
    // 0x11d9f8: 0xc0451b0
    ctx->pc = 0x11D9F8u;
    SET_GPR_U32(ctx, 31, 0x11DA00u);
    ctx->pc = 0x11D9FCu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    ctx->pc = 0x1146C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001146C0_0x1146c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA00u; }
    }
    if (ctx->pc != 0x11DA00u) { return; }
    ctx->pc = 0x11DA00u;
    // 0x11da00: 0xc0451b4
    ctx->pc = 0x11DA00u;
    SET_GPR_U32(ctx, 31, 0x11DA08u);
    ctx->pc = 0x11DA04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1146D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA08u; }
    }
    if (ctx->pc != 0x11DA08u) { return; }
    ctx->pc = 0x11DA08u;
    // 0x11da08: 0xc0451b0
    ctx->pc = 0x11DA08u;
    SET_GPR_U32(ctx, 31, 0x11DA10u);
    ctx->pc = 0x11DA0Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1146C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001146C0_0x1146c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA10u; }
    }
    if (ctx->pc != 0x11DA10u) { return; }
    ctx->pc = 0x11DA10u;
    // 0x11da10: 0x8fa20004
    ctx->pc = 0x11da10u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x11da14: 0xdfbf0020
    ctx->pc = 0x11da14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11da18: 0x21342
    ctx->pc = 0x11da18u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 13));
    // 0x11da1c: 0xdfb00010
    ctx->pc = 0x11da1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11da20: 0x30420007
    ctx->pc = 0x11da20u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 7));
    // 0x11da24: 0x2c420001
    ctx->pc = 0x11da24u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 1));
    // 0x11da28: 0x3e00008
    ctx->pc = 0x11DA28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DA2Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11DA30u;
}
