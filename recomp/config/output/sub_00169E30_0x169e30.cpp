#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169E30
// Address: 0x169e30 - 0x169e50
void sub_00169E30_0x169e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169E30_0x169e30");
#endif

    ctx->pc = 0x169e30u;

    // 0x169e30: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x169e30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x169e34: 0xac44ef80  sw          $a0, -0x1080($v0)
    ctx->pc = 0x169e34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963072), GPR_U32(ctx, 4));
    // 0x169e38: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x169E38u;
    {
        const bool branch_taken_0x169e38 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x169E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169E38u;
            // 0x169e3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169e38) {
            ctx->pc = 0x169E48u;
            goto label_169e48;
        }
    }
    ctx->pc = 0x169E40u;
    // 0x169e40: 0x8c830048  lw          $v1, 0x48($a0)
    ctx->pc = 0x169e40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x169e44: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x169e44u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_169e48:
    // 0x169e48: 0x3e00008  jr          $ra
    ctx->pc = 0x169E48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169E48u: goto label_169e48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169E50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
