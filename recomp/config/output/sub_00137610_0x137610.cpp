#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137610
// Address: 0x137610 - 0x137640
void sub_00137610_0x137610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137610_0x137610");
#endif

    switch (ctx->pc) {
        case 0x137618u: goto label_137618;
        default: break;
    }

    ctx->pc = 0x137610u;

    // 0x137610: 0x24023fff  addiu       $v0, $zero, 0x3FFF
    ctx->pc = 0x137610u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16383));
    // 0x137614: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x137614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_137618:
    // 0x137618: 0x0  nop
    ctx->pc = 0x137618u;
    // NOP
    // 0x13761c: 0x0  nop
    ctx->pc = 0x13761cu;
    // NOP
    // 0x137620: 0x0  nop
    ctx->pc = 0x137620u;
    // NOP
    // 0x137624: 0x0  nop
    ctx->pc = 0x137624u;
    // NOP
    // 0x137628: 0x0  nop
    ctx->pc = 0x137628u;
    // NOP
    // 0x13762c: 0x443fffa  bgezl       $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13762Cu;
    {
        const bool branch_taken_0x13762c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x13762c) {
            ctx->pc = 0x137630u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13762Cu;
            // 0x137630: 0x2442ffe0  addiu       $v0, $v0, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_137618;
        }
    }
    ctx->pc = 0x137634u;
    // 0x137634: 0x3e00008  jr          $ra
    ctx->pc = 0x137634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137618u: goto label_137618;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13763Cu;
    // 0x13763c: 0x0  nop
    ctx->pc = 0x13763cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
