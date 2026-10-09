#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A6D8
// Address: 0x17a6d8 - 0x17a728
void sub_0017A6D8_0x17a6d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A6D8_0x17a6d8");
#endif

    switch (ctx->pc) {
        case 0x17a6f8u: goto label_17a6f8;
        default: break;
    }

    ctx->pc = 0x17a6d8u;

    // 0x17a6d8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17a6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17a6dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x17a6dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a6e0: 0x2442f1f0  addiu       $v0, $v0, -0xE10
    ctx->pc = 0x17a6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963696));
    // 0x17a6e4: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x17a6e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17a6e8: 0x18a0000c  blez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A6E8u;
    {
        const bool branch_taken_0x17a6e8 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x17A6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A6E8u;
            // 0x17a6ec: 0x24420008  addiu       $v0, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a6e8) {
            ctx->pc = 0x17A71Cu;
            goto label_17a71c;
        }
    }
    ctx->pc = 0x17A6F0u;
    // 0x17a6f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x17a6f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a6f4: 0x0  nop
    ctx->pc = 0x17a6f4u;
    // NOP
label_17a6f8:
    // 0x17a6f8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x17a6f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17a6fc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x17a6fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a700: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17A700u;
    {
        const bool branch_taken_0x17a700 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A700u;
            // 0x17a704: 0x24840014  addiu       $a0, $a0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a700) {
            ctx->pc = 0x17A720u;
            goto label_17a720;
        }
    }
    ctx->pc = 0x17A708u;
    // 0x17a708: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x17a708u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x17a70c: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x17a70cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x17a710: 0x0  nop
    ctx->pc = 0x17a710u;
    // NOP
    // 0x17a714: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17A714u;
    {
        const bool branch_taken_0x17a714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17a714) {
            ctx->pc = 0x17A6F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17a6f8;
        }
    }
    ctx->pc = 0x17A71Cu;
label_17a71c:
    // 0x17a71c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17a71cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17a720:
    // 0x17a720: 0x3e00008  jr          $ra
    ctx->pc = 0x17A720u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A6F8u: goto label_17a6f8;
            case 0x17A71Cu: goto label_17a71c;
            case 0x17A720u: goto label_17a720;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A728u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
