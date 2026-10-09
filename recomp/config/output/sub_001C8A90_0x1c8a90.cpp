#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8A90
// Address: 0x1c8a90 - 0x1c8ac0
void sub_001C8A90_0x1c8a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8A90_0x1c8a90");
#endif

    switch (ctx->pc) {
        case 0x1c8aa4u: goto label_1c8aa4;
        default: break;
    }

    ctx->pc = 0x1c8a90u;

    // 0x1c8a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8a94: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1c8a94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8a98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8a9c: 0xc072274  jal         func_1C89D0
    ctx->pc = 0x1C8A9Cu;
    SET_GPR_U32(ctx, 31, 0x1C8AA4u);
    ctx->pc = 0x1C8AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A9Cu;
            // 0x1c8aa0: 0x27a5001f  addiu       $a1, $sp, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C89D0u;
    if (runtime->hasFunction(0x1C89D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C89D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8AA4u; }
        if (ctx->pc != 0x1C8AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C89D0_0x1c89d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8AA4u; }
        if (ctx->pc != 0x1C8AA4u) { return; }
    }
    ctx->pc = 0x1C8AA4u;
label_1c8aa4:
    // 0x1c8aa4: 0x93a2001f  lbu         $v0, 0x1F($sp)
    ctx->pc = 0x1c8aa4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 31)));
    // 0x1c8aa8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8aa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8aac: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8AACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8AACu;
            // 0x1c8ab0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8AA4u: goto label_1c8aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8AB4u;
    // 0x1c8ab4: 0x0  nop
    ctx->pc = 0x1c8ab4u;
    // NOP
    // 0x1c8ab8: 0x0  nop
    ctx->pc = 0x1c8ab8u;
    // NOP
    // 0x1c8abc: 0x0  nop
    ctx->pc = 0x1c8abcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
