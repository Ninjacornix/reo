#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA7F0
// Address: 0x1ba7f0 - 0x1ba83c
void sub_001BA7F0_0x1ba7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA7F0_0x1ba7f0");
#endif

    ctx->pc = 0x1ba7f0u;

    // 0x1ba7f0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba7f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba7f4: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1ba7f4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1ba7f8: 0x90236570  lbu         $v1, 0x6570($at)
    ctx->pc = 0x1ba7f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 25968)));
    // 0x1ba7fc: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1BA7FCu;
    {
        const bool branch_taken_0x1ba7fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7FCu;
            // 0x1ba800: 0x24c66570  addiu       $a2, $a2, 0x6570 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7fc) {
            ctx->pc = 0x1BA834u;
            goto label_1ba834;
        }
    }
    ctx->pc = 0x1BA804u;
    // 0x1ba804: 0x28a10009  slti        $at, $a1, 0x9
    ctx->pc = 0x1ba804u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1ba808: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1BA808u;
    {
        const bool branch_taken_0x1ba808 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA808u;
            // 0x1ba80c: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba808) {
            ctx->pc = 0x1BA834u;
            goto label_1ba834;
        }
    }
    ctx->pc = 0x1BA810u;
    // 0x1ba810: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1ba810u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1ba814: 0x24634da0  addiu       $v1, $v1, 0x4DA0
    ctx->pc = 0x1ba814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19872));
    // 0x1ba818: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba81c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1ba81cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ba820: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba824: 0xacc40010  sw          $a0, 0x10($a2)
    ctx->pc = 0x1ba824u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 4));
    // 0x1ba828: 0xa4c0000e  sh          $zero, 0xE($a2)
    ctx->pc = 0x1ba828u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba82c: 0xa4c3000c  sh          $v1, 0xC($a2)
    ctx->pc = 0x1ba82cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba830: 0xa0c30001  sb          $v1, 0x1($a2)
    ctx->pc = 0x1ba830u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 3));
label_1ba834:
    // 0x1ba834: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA834u: goto label_1ba834;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA83Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
