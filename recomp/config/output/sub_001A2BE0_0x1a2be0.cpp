#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2BE0
// Address: 0x1a2be0 - 0x1a2c10
void sub_001A2BE0_0x1a2be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2BE0_0x1a2be0");
#endif

    switch (ctx->pc) {
        case 0x1a2bf4u: goto label_1a2bf4;
        default: break;
    }

    ctx->pc = 0x1a2be0u;

    // 0x1a2be0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2be4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a2be4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2be8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2be8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a2bec: 0xc068b04  jal         func_1A2C10
    ctx->pc = 0x1A2BECu;
    SET_GPR_U32(ctx, 31, 0x1A2BF4u);
    ctx->pc = 0x1A2BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2BECu;
            // 0x1a2bf0: 0xac20ffd8  sw          $zero, -0x28($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967256), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2C10u;
    if (runtime->hasFunction(0x1A2C10u)) {
        auto targetFn = runtime->lookupFunction(0x1A2C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BF4u; }
        if (ctx->pc != 0x1A2BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2C10_0x1a2c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BF4u; }
        if (ctx->pc != 0x1A2BF4u) { return; }
    }
    ctx->pc = 0x1A2BF4u;
label_1a2bf4:
    // 0x1a2bf4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a2bf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2bf8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2bfc: 0x8c22ffd8  lw          $v0, -0x28($at)
    ctx->pc = 0x1a2bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967256)));
    // 0x1a2c00: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C00u;
            // 0x1a2c04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2BF4u: goto label_1a2bf4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2C08u;
    // 0x1a2c08: 0x0  nop
    ctx->pc = 0x1a2c08u;
    // NOP
    // 0x1a2c0c: 0x0  nop
    ctx->pc = 0x1a2c0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
