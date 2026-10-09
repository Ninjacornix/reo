#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173570
// Address: 0x173570 - 0x1735b0
void sub_00173570_0x173570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173570_0x173570");
#endif

    switch (ctx->pc) {
        case 0x173580u: goto label_173580;
        default: break;
    }

    ctx->pc = 0x173570u;

    // 0x173570: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173570u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173574: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x173574u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173578: 0x2446f18c  addiu       $a2, $v0, -0xE74
    ctx->pc = 0x173578u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17357c: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x17357cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
label_173580:
    // 0x173580: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x173580u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x173584: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x173584u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173588: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x173588u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17358c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17358Cu;
    {
        const bool branch_taken_0x17358c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x173590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17358Cu;
            // 0x173590: 0x28a40008  slti        $a0, $a1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17358c) {
            ctx->pc = 0x1735A8u;
            goto label_1735a8;
        }
    }
    ctx->pc = 0x173594u;
    // 0x173594: 0x0  nop
    ctx->pc = 0x173594u;
    // NOP
    // 0x173598: 0x0  nop
    ctx->pc = 0x173598u;
    // NOP
    // 0x17359c: 0x5480fff8  bnel        $a0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17359Cu;
    {
        const bool branch_taken_0x17359c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x17359c) {
            ctx->pc = 0x1735A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17359Cu;
            // 0x1735a0: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173580u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173580;
        }
    }
    ctx->pc = 0x1735A4u;
    // 0x1735a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1735a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1735a8:
    // 0x1735a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1735A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173580u: goto label_173580;
            case 0x1735A8u: goto label_1735a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1735B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
