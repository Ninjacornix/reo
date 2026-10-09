#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5D70
// Address: 0x1c5d70 - 0x1c5da0
void sub_001C5D70_0x1c5d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5D70_0x1c5d70");
#endif

    switch (ctx->pc) {
        case 0x1c5d8cu: goto label_1c5d8c;
        default: break;
    }

    ctx->pc = 0x1c5d70u;

    // 0x1c5d70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c5d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c5d74: 0x28a10002  slti        $at, $a1, 0x2
    ctx->pc = 0x1c5d74u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1c5d78: 0x14200004  bnez        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5D78u;
    {
        const bool branch_taken_0x1c5d78 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D78u;
            // 0x1c5d7c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5d78) {
            ctx->pc = 0x1C5D8Cu;
            goto label_1c5d8c;
        }
    }
    ctx->pc = 0x1C5D80u;
    // 0x1c5d80: 0x24a6ffff  addiu       $a2, $a1, -0x1
    ctx->pc = 0x1c5d80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1c5d84: 0xc071768  jal         func_1C5DA0
    ctx->pc = 0x1C5D84u;
    SET_GPR_U32(ctx, 31, 0x1C5D8Cu);
    ctx->pc = 0x1C5D88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D84u;
            // 0x1c5d88: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5DA0u;
    if (runtime->hasFunction(0x1C5DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1C5DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5D8Cu; }
        if (ctx->pc != 0x1C5D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5DA0_0x1c5da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5D8Cu; }
        if (ctx->pc != 0x1C5D8Cu) { return; }
    }
    ctx->pc = 0x1C5D8Cu;
label_1c5d8c:
    // 0x1c5d8c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c5d8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5d90: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5D90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5D90u;
            // 0x1c5d94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5D8Cu: goto label_1c5d8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5D98u;
    // 0x1c5d98: 0x0  nop
    ctx->pc = 0x1c5d98u;
    // NOP
    // 0x1c5d9c: 0x0  nop
    ctx->pc = 0x1c5d9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
