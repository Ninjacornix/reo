#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD700
// Address: 0x1ad700 - 0x1ad748
void sub_001AD700_0x1ad700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD700_0x1ad700");
#endif

    ctx->pc = 0x1ad700u;

    // 0x1ad700: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1ad700u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ad704: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ad704u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ad708: 0x24423934  addiu       $v0, $v0, 0x3934
    ctx->pc = 0x1ad708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14644));
    // 0x1ad70c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ad70cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ad710: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1ad710u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ad714: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD714u;
    {
        const bool branch_taken_0x1ad714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD714u;
            // 0x1ad718: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad714) {
            ctx->pc = 0x1AD724u;
            goto label_1ad724;
        }
    }
    ctx->pc = 0x1AD71Cu;
    // 0x1ad71c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AD71Cu;
    {
        const bool branch_taken_0x1ad71c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD71Cu;
            // 0x1ad720: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad71c) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD724u;
label_1ad724:
    // 0x1ad724: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1ad724u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1ad728: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ad728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ad72c: 0x906300e4  lbu         $v1, 0xE4($v1)
    ctx->pc = 0x1ad72cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 228)));
    // 0x1ad730: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD730u;
    {
        const bool branch_taken_0x1ad730 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AD734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD730u;
            // 0x1ad734: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad730) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD738u;
    // 0x1ad738: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1AD738u;
    {
        const bool branch_taken_0x1ad738 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD73Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD738u;
            // 0x1ad73c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad738) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD740u;
label_1ad740:
    // 0x1ad740: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD724u: goto label_1ad724;
            case 0x1AD740u: goto label_1ad740;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
