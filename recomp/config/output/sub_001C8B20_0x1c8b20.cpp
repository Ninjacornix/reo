#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8B20
// Address: 0x1c8b20 - 0x1c8b50
void sub_001C8B20_0x1c8b20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8B20_0x1c8b20");
#endif

    switch (ctx->pc) {
        case 0x1c8b34u: goto label_1c8b34;
        default: break;
    }

    ctx->pc = 0x1c8b20u;

    // 0x1c8b20: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8b20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8b24: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1c8b24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8b28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8b28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8b2c: 0xc072274  jal         func_1C89D0
    ctx->pc = 0x1C8B2Cu;
    SET_GPR_U32(ctx, 31, 0x1C8B34u);
    ctx->pc = 0x1C8B30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B2Cu;
            // 0x1c8b30: 0x27a5001e  addiu       $a1, $sp, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C89D0u;
    if (runtime->hasFunction(0x1C89D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C89D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B34u; }
        if (ctx->pc != 0x1C8B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C89D0_0x1c89d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B34u; }
        if (ctx->pc != 0x1C8B34u) { return; }
    }
    ctx->pc = 0x1C8B34u;
label_1c8b34:
    // 0x1c8b34: 0x97a2001e  lhu         $v0, 0x1E($sp)
    ctx->pc = 0x1c8b34u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 30)));
    // 0x1c8b38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8b38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B3Cu;
            // 0x1c8b40: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8B34u: goto label_1c8b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8B44u;
    // 0x1c8b44: 0x0  nop
    ctx->pc = 0x1c8b44u;
    // NOP
    // 0x1c8b48: 0x0  nop
    ctx->pc = 0x1c8b48u;
    // NOP
    // 0x1c8b4c: 0x0  nop
    ctx->pc = 0x1c8b4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
