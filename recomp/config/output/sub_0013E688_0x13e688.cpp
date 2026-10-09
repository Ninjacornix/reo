#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E688
// Address: 0x13e688 - 0x13e6bc
void sub_0013E688_0x13e688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E688_0x13e688");
#endif

    ctx->pc = 0x13e688u;

    // 0x13e688: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x13e688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x13e68c: 0x10450009  beq         $v0, $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E68Cu;
    {
        const bool branch_taken_0x13e68c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13E690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E68Cu;
            // 0x13e690: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e68c) {
            ctx->pc = 0x13E6B4u;
            goto label_13e6b4;
        }
    }
    ctx->pc = 0x13E694u;
    // 0x13e694: 0x8c431468  lw          $v1, 0x1468($v0)
    ctx->pc = 0x13e694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5224)));
    // 0x13e698: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13E698u;
    {
        const bool branch_taken_0x13e698 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E698u;
            // 0x13e69c: 0x51600  sll         $v0, $a1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e698) {
            ctx->pc = 0x13E6ACu;
            goto label_13e6ac;
        }
    }
    ctx->pc = 0x13E6A0u;
    // 0x13e6a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13e6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e6a4: 0x10a20003  beq         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13E6A4u;
    {
        const bool branch_taken_0x13e6a4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6A4u;
            // 0x13e6a8: 0x51600  sll         $v0, $a1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e6a4) {
            ctx->pc = 0x13E6B4u;
            goto label_13e6b4;
        }
    }
    ctx->pc = 0x13E6ACu;
label_13e6ac:
    // 0x13e6ac: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13e6acu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13e6b0: 0xac820048  sw          $v0, 0x48($a0)
    ctx->pc = 0x13e6b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 2));
label_13e6b4:
    // 0x13e6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x13E6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E6BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
