#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142038
// Address: 0x142038 - 0x142078
void sub_00142038_0x142038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142038_0x142038");
#endif

    ctx->pc = 0x142038u;

    // 0x142038: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142038u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14203c: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x14203cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x142040: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x142044: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x142044u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142048: 0x8050788  j           func_141E20
    ctx->pc = 0x142048u;
    ctx->pc = 0x14204Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142048u;
            // 0x14204c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E20u;
    if (runtime->hasFunction(0x141E20u)) {
        auto targetFn = runtime->lookupFunction(0x141E20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141E20_0x141e20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x142050u;
    // 0x142050: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x142050u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x142054: 0x2c840007  sltiu       $a0, $a0, 0x7
    ctx->pc = 0x142054u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x142058: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x142058u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x14205c: 0x2421a5f8  addiu       $at, $at, -0x5A08
    ctx->pc = 0x14205cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294944248));
    // 0x142060: 0x231821  addu        $v1, $at, $v1
    ctx->pc = 0x142060u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x142064: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x142064u;
    {
        const bool branch_taken_0x142064 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x142068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142064u;
            // 0x142068: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142064) {
            ctx->pc = 0x142070u;
            goto label_142070;
        }
    }
    ctx->pc = 0x14206Cu;
    // 0x14206c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x14206cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_142070:
    // 0x142070: 0x3e00008  jr          $ra
    ctx->pc = 0x142070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142070u: goto label_142070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
