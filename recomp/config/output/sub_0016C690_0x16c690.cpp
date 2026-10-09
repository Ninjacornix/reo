#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C690
// Address: 0x16c690 - 0x16c6b4
void sub_0016C690_0x16c690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C690_0x16c690");
#endif

    ctx->pc = 0x16c690u;

    // 0x16c690: 0x24840da4  addiu       $a0, $a0, 0xDA4
    ctx->pc = 0x16c690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3492));
    // 0x16c694: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x16c694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x16c698: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x16c698u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x16c69c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16c69cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16c6a0: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x16C6A0u;
    {
        const bool branch_taken_0x16c6a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16C6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6A0u;
            // 0x16c6a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c6a0) {
            ctx->pc = 0x16C6ACu;
            goto label_16c6ac;
        }
    }
    ctx->pc = 0x16C6A8u;
    // 0x16c6a8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x16c6a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_16c6ac:
    // 0x16c6ac: 0x3e00008  jr          $ra
    ctx->pc = 0x16C6ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C6ACu: goto label_16c6ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C6B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
