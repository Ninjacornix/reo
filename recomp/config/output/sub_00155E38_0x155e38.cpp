#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155E38
// Address: 0x155e38 - 0x155e60
void sub_00155E38_0x155e38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155E38_0x155e38");
#endif

    ctx->pc = 0x155e38u;

    // 0x155e38: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155e38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155e3c: 0xac444c58  sw          $a0, 0x4C58($v0)
    ctx->pc = 0x155e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 19544), GPR_U32(ctx, 4));
    // 0x155e40: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x155E40u;
    {
        const bool branch_taken_0x155e40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x155E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155E40u;
            // 0x155e44: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155e40) {
            ctx->pc = 0x155E54u;
            goto label_155e54;
        }
    }
    ctx->pc = 0x155E48u;
    // 0x155e48: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x155e48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x155e4c: 0x38630002  xori        $v1, $v1, 0x2
    ctx->pc = 0x155e4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x155e50: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x155e50u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_155e54:
    // 0x155e54: 0x3e00008  jr          $ra
    ctx->pc = 0x155E54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155E54u: goto label_155e54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155E5Cu;
    // 0x155e5c: 0x0  nop
    ctx->pc = 0x155e5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
