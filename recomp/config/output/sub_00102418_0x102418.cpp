#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102418
// Address: 0x102418 - 0x102448
void sub_00102418_0x102418(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102418_0x102418");
#endif

    ctx->pc = 0x102418u;

    // 0x102418: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x102418u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x10241c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10241cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102420: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102420u;
    {
        const bool branch_taken_0x102420 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x102420) {
            ctx->pc = 0x102430u;
            goto label_102430;
        }
    }
    ctx->pc = 0x102428u;
    // 0x102428: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x102428u;
    {
        const bool branch_taken_0x102428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10242Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102428u;
            // 0x10242c: 0x34630400  ori         $v1, $v1, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1024);
        ctx->in_delay_slot = false;
        if (branch_taken_0x102428) {
            ctx->pc = 0x10243Cu;
            goto label_10243c;
        }
    }
    ctx->pc = 0x102430u;
label_102430:
    // 0x102430: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x102430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x102434: 0x3442fbff  ori         $v0, $v0, 0xFBFF
    ctx->pc = 0x102434u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64511);
    // 0x102438: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x102438u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_10243c:
    // 0x10243c: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x10243cu;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x102440: 0x3e00008  jr          $ra
    ctx->pc = 0x102440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
