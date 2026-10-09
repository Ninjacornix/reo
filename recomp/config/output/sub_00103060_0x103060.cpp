#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103060
// Address: 0x103060 - 0x103088
void sub_00103060_0x103060(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103060_0x103060");
#endif

    ctx->pc = 0x103060u;

    // 0x103060: 0x2c82000a  sltiu       $v0, $a0, 0xA
    ctx->pc = 0x103060u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x103064: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x103064u;
    {
        const bool branch_taken_0x103064 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x103068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103064u;
            // 0x103068: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103064) {
            ctx->pc = 0x103080u;
            goto label_103080;
        }
    }
    ctx->pc = 0x10306Cu;
    // 0x10306c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x10306cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x103070: 0x244294c8  addiu       $v0, $v0, -0x6B38
    ctx->pc = 0x103070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939848));
    // 0x103074: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x103074u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x103078: 0x3e00008  jr          $ra
    ctx->pc = 0x103078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10307Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103078u;
            // 0x10307c: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103080u: goto label_103080;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103080u;
label_103080:
    // 0x103080: 0x3e00008  jr          $ra
    ctx->pc = 0x103080u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103080u;
            // 0x103084: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103080u: goto label_103080;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103088u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
