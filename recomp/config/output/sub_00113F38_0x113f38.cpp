#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113F38
// Address: 0x113f38 - 0x113fb0
void sub_00113F38_0x113f38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113f38u;

    // 0x113f38: 0x27bdffe0
    ctx->pc = 0x113f38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x113f3c: 0xffb00000
    ctx->pc = 0x113f3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113f40: 0xffbf0010
    ctx->pc = 0x113f40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x113f44: 0xc047598
    ctx->pc = 0x113F44u;
    SET_GPR_U32(ctx, 31, 0x113F4Cu);
    ctx->pc = 0x113F48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113F4Cu; }
    }
    if (ctx->pc != 0x113F4Cu) { return; }
    ctx->pc = 0x113F4Cu;
    // 0x113f4c: 0x3c061000
    ctx->pc = 0x113f4cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x113f50: 0x3c071000
    ctx->pc = 0x113f50u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x113f54: 0x34c6f520
    ctx->pc = 0x113f54u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62752));
    // 0x113f58: 0x3c080001
    ctx->pc = 0x113f58u;
    SET_GPR_U32(ctx, 8, ((uint32_t)1 << 16));
    // 0x113f5c: 0x8cc30000
    ctx->pc = 0x113f5cu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x113f60: 0x34e7f590
    ctx->pc = 0x113f60u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 62864));
    // 0x113f64: 0x3c041000
    ctx->pc = 0x113f64u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113f68: 0x3c05fffe
    ctx->pc = 0x113f68u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65534 << 16));
    // 0x113f6c: 0x681825
    ctx->pc = 0x113f6cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x113f70: 0x3484b400
    ctx->pc = 0x113f70u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46080));
    // 0x113f74: 0xace30000
    ctx->pc = 0x113f74u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113f78: 0x34a5ffff
    ctx->pc = 0x113f78u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 65535));
    // 0x113f7c: 0xac900000
    ctx->pc = 0x113f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x113f80: 0x8cc30000
    ctx->pc = 0x113f80u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113f84: 0x651824
    ctx->pc = 0x113f84u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x113f88: 0xace30000
    ctx->pc = 0x113f88u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113f8c: 0x10400004
    ctx->pc = 0x113F8Cu;
    {
        const bool branch_taken_0x113f8c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x113F90u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x113f8c) {
            ctx->pc = 0x113FA0u;
            goto label_113fa0;
        }
    }
    ctx->pc = 0x113F94u;
    // 0x113f94: 0xdfb00000
    ctx->pc = 0x113f94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113f98: 0x80475ae
    ctx->pc = 0x113F98u;
    ctx->pc = 0x113F9Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x113FA0u;
label_113fa0:
    // 0x113fa0: 0xdfb00000
    ctx->pc = 0x113fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113fa4: 0x3e00008
    ctx->pc = 0x113FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113FA8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FA0u: goto label_113fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113FACu;
    // 0x113fac: 0x0
    ctx->pc = 0x113facu;
    // NOP
}
