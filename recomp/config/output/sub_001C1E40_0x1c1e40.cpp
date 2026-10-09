#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1E40
// Address: 0x1c1e40 - 0x1c1e78
void sub_001C1E40_0x1c1e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1E40_0x1c1e40");
#endif

    ctx->pc = 0x1c1e40u;

    // 0x1c1e40: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1E40u;
    {
        const bool branch_taken_0x1c1e40 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1C1E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E40u;
            // 0x1c1e44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1e40) {
            ctx->pc = 0x1C1E58u;
            goto label_1c1e58;
        }
    }
    ctx->pc = 0x1C1E48u;
    // 0x1c1e48: 0x2882005a  slti        $v0, $a0, 0x5A
    ctx->pc = 0x1c1e48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)90) ? 1 : 0);
    // 0x1c1e4c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1E4Cu;
    {
        const bool branch_taken_0x1c1e4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E4Cu;
            // 0x1c1e50: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1e4c) {
            ctx->pc = 0x1C1E60u;
            goto label_1c1e60;
        }
    }
    ctx->pc = 0x1C1E54u;
    // 0x1c1e54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c1e54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c1e58:
    // 0x1c1e58: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1E58u;
    {
        const bool branch_taken_0x1c1e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1e58) {
            ctx->pc = 0x1C1E70u;
            goto label_1c1e70;
        }
    }
    ctx->pc = 0x1C1E60u;
label_1c1e60:
    // 0x1c1e60: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1e60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1e64: 0x24425d20  addiu       $v0, $v0, 0x5D20
    ctx->pc = 0x1c1e64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23840));
    // 0x1c1e68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1e68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1e6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c1e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1c1e70:
    // 0x1c1e70: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1E70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1E78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
