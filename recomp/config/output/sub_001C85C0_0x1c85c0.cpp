#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C85C0
// Address: 0x1c85c0 - 0x1c8620
void sub_001C85C0_0x1c85c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C85C0_0x1c85c0");
#endif

    switch (ctx->pc) {
        case 0x1c85e0u: goto label_1c85e0;
        case 0x1c85f4u: goto label_1c85f4;
        default: break;
    }

    ctx->pc = 0x1c85c0u;

    // 0x1c85c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c85c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c85c4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c85c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c85c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c85c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c85cc: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c85ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c85d0: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C85D0u;
    {
        const bool branch_taken_0x1c85d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C85D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C85D0u;
            // 0x1c85d4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c85d0) {
            ctx->pc = 0x1C8608u;
            goto label_1c8608;
        }
    }
    ctx->pc = 0x1C85D8u;
    // 0x1c85d8: 0xc0719ec  jal         func_1C67B0
    ctx->pc = 0x1C85D8u;
    SET_GPR_U32(ctx, 31, 0x1C85E0u);
    ctx->pc = 0x1C67B0u;
    if (runtime->hasFunction(0x1C67B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C67B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85E0u; }
        if (ctx->pc != 0x1C85E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C67B0_0x1c67b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85E0u; }
        if (ctx->pc != 0x1C85E0u) { return; }
    }
    ctx->pc = 0x1C85E0u;
label_1c85e0:
    // 0x1c85e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c85e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c85e4: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C85E4u;
    {
        const bool branch_taken_0x1c85e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C85E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C85E4u;
            // 0x1c85e8: 0x240402bc  addiu       $a0, $zero, 0x2BC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 700));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c85e4) {
            ctx->pc = 0x1C8604u;
            goto label_1c8604;
        }
    }
    ctx->pc = 0x1C85ECu;
    // 0x1c85ec: 0xc071b24  jal         func_1C6C90
    ctx->pc = 0x1C85ECu;
    SET_GPR_U32(ctx, 31, 0x1C85F4u);
    ctx->pc = 0x1C6C90u;
    if (runtime->hasFunction(0x1C6C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C6C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85F4u; }
        if (ctx->pc != 0x1C85F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6C90_0x1c6c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C85F4u; }
        if (ctx->pc != 0x1C85F4u) { return; }
    }
    ctx->pc = 0x1C85F4u;
label_1c85f4:
    // 0x1c85f4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C85F4u;
    {
        const bool branch_taken_0x1c85f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c85f4) {
            ctx->pc = 0x1C8604u;
            goto label_1c8604;
        }
    }
    ctx->pc = 0x1C85FCu;
    // 0x1c85fc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C85FCu;
    {
        const bool branch_taken_0x1c85fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C85FCu;
            // 0x1c8600: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c85fc) {
            ctx->pc = 0x1C8608u;
            goto label_1c8608;
        }
    }
    ctx->pc = 0x1C8604u;
label_1c8604:
    // 0x1c8604: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c8604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1c8608:
    // 0x1c8608: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c860c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C860Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C860Cu;
            // 0x1c8610: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C85E0u: goto label_1c85e0;
            case 0x1C85F4u: goto label_1c85f4;
            case 0x1C8604u: goto label_1c8604;
            case 0x1C8608u: goto label_1c8608;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8614u;
    // 0x1c8614: 0x0  nop
    ctx->pc = 0x1c8614u;
    // NOP
    // 0x1c8618: 0x0  nop
    ctx->pc = 0x1c8618u;
    // NOP
    // 0x1c861c: 0x0  nop
    ctx->pc = 0x1c861cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
