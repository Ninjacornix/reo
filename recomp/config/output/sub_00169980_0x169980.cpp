#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169980
// Address: 0x169980 - 0x1699b8
void sub_00169980_0x169980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169980_0x169980");
#endif

    ctx->pc = 0x169980u;

    // 0x169980: 0x24840078  addiu       $a0, $a0, 0x78
    ctx->pc = 0x169980u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 120));
    // 0x169984: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x169984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x169988: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x169988u;
    {
        const bool branch_taken_0x169988 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16998Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169988u;
            // 0x16998c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169988) {
            ctx->pc = 0x1699B0u;
            goto label_1699b0;
        }
    }
    ctx->pc = 0x169990u;
    // 0x169990: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x169990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x169994: 0x8c840008  lw          $a0, 0x8($a0)
    ctx->pc = 0x169994u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x169998: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x169998u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x16999c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16999cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1699a0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1699a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1699a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1699a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1699a8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1699a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1699ac: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1699acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_1699b0:
    // 0x1699b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1699B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1699B0u: goto label_1699b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1699B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
