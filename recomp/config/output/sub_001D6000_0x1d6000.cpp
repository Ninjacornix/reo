#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6000
// Address: 0x1d6000 - 0x1d604c
void sub_001D6000_0x1d6000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6000_0x1d6000");
#endif

    switch (ctx->pc) {
        case 0x1d6028u: goto label_1d6028;
        default: break;
    }

    ctx->pc = 0x1d6000u;

    // 0x1d6000: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d6000u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d6004: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d6004u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d6008: 0x24442980  addiu       $a0, $v0, 0x2980
    ctx->pc = 0x1d6008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 10624));
    // 0x1d600c: 0x90820006  lbu         $v0, 0x6($a0)
    ctx->pc = 0x1d600cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1d6010: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6010u;
    {
        const bool branch_taken_0x1d6010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6010u;
            // 0x1d6014: 0x8c6328d8  lw          $v1, 0x28D8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10456)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6010) {
            ctx->pc = 0x1D6020u;
            goto label_1d6020;
        }
    }
    ctx->pc = 0x1D6018u;
    // 0x1d6018: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D601Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6018u;
            // 0x1d601c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6020u;
label_1d6020:
    // 0x1d6020: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1d6020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d6024: 0x0  nop
    ctx->pc = 0x1d6024u;
    // NOP
label_1d6028:
    // 0x1d6028: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1d6028u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d602c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1d602cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1d6030: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d6030u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d6034: 0xa0620000  sb          $v0, 0x0($v1)
    ctx->pc = 0x1d6034u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d6038: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d6038u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d603c: 0x4a1fffa  bgez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D603Cu;
    {
        const bool branch_taken_0x1d603c = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1d603c) {
            ctx->pc = 0x1D6028u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d6028;
        }
    }
    ctx->pc = 0x1D6044u;
    // 0x1d6044: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6044u;
            // 0x1d6048: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D604Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
