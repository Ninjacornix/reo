#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4A80
// Address: 0x1b4a80 - 0x1b4ab0
void sub_001B4A80_0x1b4a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4A80_0x1b4a80");
#endif

    switch (ctx->pc) {
        case 0x1b4a90u: goto label_1b4a90;
        default: break;
    }

    ctx->pc = 0x1b4a80u;

    // 0x1b4a80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b4a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b4a84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b4a84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b4a88: 0xc067238  jal         func_19C8E0
    ctx->pc = 0x1B4A88u;
    SET_GPR_U32(ctx, 31, 0x1B4A90u);
    ctx->pc = 0x1B4A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4A88u;
            // 0x1b4a8c: 0x24042000  addiu       $a0, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19C8E0u;
    if (runtime->hasFunction(0x19C8E0u)) {
        auto targetFn = runtime->lookupFunction(0x19C8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4A90u; }
        if (ctx->pc != 0x1B4A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019C8E0_0x19c8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4A90u; }
        if (ctx->pc != 0x1B4A90u) { return; }
    }
    ctx->pc = 0x1B4A90u;
label_1b4a90:
    // 0x1b4a90: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4a94: 0xa4224414  sh          $v0, 0x4414($at)
    ctx->pc = 0x1b4a94u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17428), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b4a98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b4a98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4a9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4A9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4A9Cu;
            // 0x1b4aa0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4A90u: goto label_1b4a90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4AA4u;
    // 0x1b4aa4: 0x0  nop
    ctx->pc = 0x1b4aa4u;
    // NOP
    // 0x1b4aa8: 0x0  nop
    ctx->pc = 0x1b4aa8u;
    // NOP
    // 0x1b4aac: 0x0  nop
    ctx->pc = 0x1b4aacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
