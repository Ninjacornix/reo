#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8A50
// Address: 0x1c8a50 - 0x1c8a90
void sub_001C8A50_0x1c8a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8A50_0x1c8a50");
#endif

    switch (ctx->pc) {
        case 0x1c8a78u: goto label_1c8a78;
        default: break;
    }

    ctx->pc = 0x1c8a50u;

    // 0x1c8a50: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8A50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A50u;
            // 0x1c8a54: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8A78u: goto label_1c8a78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8A58u;
    // 0x1c8a58: 0x0  nop
    ctx->pc = 0x1c8a58u;
    // NOP
    // 0x1c8a5c: 0x0  nop
    ctx->pc = 0x1c8a5cu;
    // NOP
    // 0x1c8a60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8a60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8a64: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1c8a64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8a68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8a6c: 0xa3a5001f  sb          $a1, 0x1F($sp)
    ctx->pc = 0x1c8a6cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 5));
    // 0x1c8a70: 0xc072258  jal         func_1C8960
    ctx->pc = 0x1C8A70u;
    SET_GPR_U32(ctx, 31, 0x1C8A78u);
    ctx->pc = 0x1C8A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A70u;
            // 0x1c8a74: 0x27a5001f  addiu       $a1, $sp, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A78u; }
        if (ctx->pc != 0x1C8A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8960_0x1c8960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A78u; }
        if (ctx->pc != 0x1C8A78u) { return; }
    }
    ctx->pc = 0x1C8A78u;
label_1c8a78:
    // 0x1c8a78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8a78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A7Cu;
            // 0x1c8a80: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8A78u: goto label_1c8a78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8A84u;
    // 0x1c8a84: 0x0  nop
    ctx->pc = 0x1c8a84u;
    // NOP
    // 0x1c8a88: 0x0  nop
    ctx->pc = 0x1c8a88u;
    // NOP
    // 0x1c8a8c: 0x0  nop
    ctx->pc = 0x1c8a8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
