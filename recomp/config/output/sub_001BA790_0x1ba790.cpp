#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA790
// Address: 0x1ba790 - 0x1ba7e4
void sub_001BA790_0x1ba790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA790_0x1ba790");
#endif

    ctx->pc = 0x1ba790u;

    // 0x1ba790: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ba790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ba794: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1ba794u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1ba798: 0x902343ef  lbu         $v1, 0x43EF($at)
    ctx->pc = 0x1ba798u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17391)));
    // 0x1ba79c: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1BA79Cu;
    {
        const bool branch_taken_0x1ba79c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA79Cu;
            // 0x1ba7a0: 0x24c66570  addiu       $a2, $a2, 0x6570 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba79c) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7A4u;
    // 0x1ba7a4: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x1ba7a4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1ba7a8: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1BA7A8u;
    {
        const bool branch_taken_0x1ba7a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7A8u;
            // 0x1ba7ac: 0x28a10009  slti        $at, $a1, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7a8) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7B0u;
    // 0x1ba7b0: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1BA7B0u;
    {
        const bool branch_taken_0x1ba7b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7B0u;
            // 0x1ba7b4: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7b0) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7B8u;
    // 0x1ba7b8: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1ba7b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1ba7bc: 0x24634da0  addiu       $v1, $v1, 0x4DA0
    ctx->pc = 0x1ba7bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19872));
    // 0x1ba7c0: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba7c4: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1ba7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ba7c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba7cc: 0xacc40010  sw          $a0, 0x10($a2)
    ctx->pc = 0x1ba7ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 4));
    // 0x1ba7d0: 0xa4c0000e  sh          $zero, 0xE($a2)
    ctx->pc = 0x1ba7d0u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba7d4: 0xa4c3000c  sh          $v1, 0xC($a2)
    ctx->pc = 0x1ba7d4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba7d8: 0xa0c30001  sb          $v1, 0x1($a2)
    ctx->pc = 0x1ba7d8u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 3));
label_1ba7dc:
    // 0x1ba7dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA7DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA7DCu: goto label_1ba7dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA7E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
