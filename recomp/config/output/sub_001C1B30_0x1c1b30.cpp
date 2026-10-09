#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1B30
// Address: 0x1c1b30 - 0x1c1b60
void sub_001C1B30_0x1c1b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1B30_0x1c1b30");
#endif

    ctx->pc = 0x1c1b30u;

    // 0x1c1b30: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c1b30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1b34: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x1c1b34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1c1b38: 0x90a30003  lbu         $v1, 0x3($a1)
    ctx->pc = 0x1c1b38u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x1c1b3c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c1b3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c1b40: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1c1b40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1c1b44: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1B44u;
    {
        const bool branch_taken_0x1c1b44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C1B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B44u;
            // 0x1c1b48: 0xa0a30003  sb          $v1, 0x3($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 3), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1b44) {
            ctx->pc = 0x1C1B58u;
            goto label_1c1b58;
        }
    }
    ctx->pc = 0x1C1B4Cu;
    // 0x1c1b4c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1c1b4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1b50: 0x8070674  j           func_1C19D0
    ctx->pc = 0x1C1B50u;
    ctx->pc = 0x1C1B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B50u;
            // 0x1c1b54: 0xa0a00003  sb          $zero, 0x3($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C19D0u;
    if (runtime->hasFunction(0x1C19D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C19D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C19D0_0x1c19d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C1B58u;
label_1c1b58:
    // 0x1c1b58: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1B58u: goto label_1c1b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
