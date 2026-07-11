#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113ED0
// Address: 0x113ed0 - 0x113f38
void sub_00113ED0_0x113ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113ed0u;

    // 0x113ed0: 0x10800006
    ctx->pc = 0x113ED0u;
    {
        const bool branch_taken_0x113ed0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x113ED4u;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113ed0) {
            ctx->pc = 0x113EECu;
            goto label_113eec;
        }
    }
    ctx->pc = 0x113ED8u;
    // 0x113ed8: 0x24020001
    ctx->pc = 0x113ed8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x113edc: 0x1082000f
    ctx->pc = 0x113EDCu;
    {
        const bool branch_taken_0x113edc = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x113EE0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113edc) {
            ctx->pc = 0x113F1Cu;
            goto label_113f1c;
        }
    }
    ctx->pc = 0x113EE4u;
    // 0x113ee4: 0x10000012
    ctx->pc = 0x113EE4u;
    {
        const bool branch_taken_0x113ee4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x113ee4) {
            ctx->pc = 0x113F30u;
            goto label_113f30;
        }
    }
    ctx->pc = 0x113EECu;
label_113eec:
    // 0x113eec: 0x3c031000
    ctx->pc = 0x113eecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113ef0: 0x34632010
    ctx->pc = 0x113ef0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x113ef4: 0x0
    ctx->pc = 0x113ef4u;
    // NOP
label_113ef8:
    // 0x113ef8: 0x8c620000
    ctx->pc = 0x113ef8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113efc: 0x0
    ctx->pc = 0x113efcu;
    // NOP
    // 0x113f00: 0x0
    ctx->pc = 0x113f00u;
    // NOP
    // 0x113f04: 0x0
    ctx->pc = 0x113f04u;
    // NOP
    // 0x113f08: 0x0
    ctx->pc = 0x113f08u;
    // NOP
    // 0x113f0c: 0x440fffa
    ctx->pc = 0x113F0Cu;
    {
        const bool branch_taken_0x113f0c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x113f0c) {
            ctx->pc = 0x113EF8u;
            goto label_113ef8;
        }
    }
    ctx->pc = 0x113F14u;
    // 0x113f14: 0x10000005
    ctx->pc = 0x113F14u;
    {
        const bool branch_taken_0x113f14 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113F18u;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113f14) {
            ctx->pc = 0x113F2Cu;
            goto label_113f2c;
        }
    }
    ctx->pc = 0x113F1Cu;
label_113f1c:
    // 0x113f1c: 0x3c021000
    ctx->pc = 0x113f1cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113f20: 0x34422010
    ctx->pc = 0x113f20u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x113f24: 0x8c430000
    ctx->pc = 0x113f24u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113f28: 0x31fc2
    ctx->pc = 0x113f28u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 31));
label_113f2c:
    // 0x113f2c: 0x60102d
    ctx->pc = 0x113f2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_113f30:
    // 0x113f30: 0x3e00008
    ctx->pc = 0x113F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113EECu: goto label_113eec;
            case 0x113EF8u: goto label_113ef8;
            case 0x113F1Cu: goto label_113f1c;
            case 0x113F2Cu: goto label_113f2c;
            case 0x113F30u: goto label_113f30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113F38u;
}
