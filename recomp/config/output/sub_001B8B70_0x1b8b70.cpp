#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8B70
// Address: 0x1b8b70 - 0x1b8bb0
void sub_001B8B70_0x1b8b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8B70_0x1b8b70");
#endif

    switch (ctx->pc) {
        case 0x1b8ba4u: goto label_1b8ba4;
        default: break;
    }

    ctx->pc = 0x1b8b70u;

    // 0x1b8b70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8b74: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8b74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8b78: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8b7c: 0x90830002  lbu         $v1, 0x2($a0)
    ctx->pc = 0x1b8b7cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b8b80: 0x14680008  bne         $v1, $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8B80u;
    {
        const bool branch_taken_0x1b8b80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 8));
        ctx->pc = 0x1B8B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8B80u;
            // 0x1b8b84: 0xc0502d  daddu       $t2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8b80) {
            ctx->pc = 0x1B8BA4u;
            goto label_1b8ba4;
        }
    }
    ctx->pc = 0x1B8B88u;
    // 0x1b8b88: 0x90830003  lbu         $v1, 0x3($a0)
    ctx->pc = 0x1b8b88u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b8b8c: 0x24870038  addiu       $a3, $a0, 0x38
    ctx->pc = 0x1b8b8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x1b8b90: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1b8b90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1b8b94: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8b94u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8b98: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1b8b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1b8b9c: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8B9Cu;
    SET_GPR_U32(ctx, 31, 0x1B8BA4u);
    ctx->pc = 0x1B8BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8B9Cu;
            // 0x1b8ba0: 0x433023  subu        $a2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8BA4u; }
        if (ctx->pc != 0x1B8BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8BA4u; }
        if (ctx->pc != 0x1B8BA4u) { return; }
    }
    ctx->pc = 0x1B8BA4u;
label_1b8ba4:
    // 0x1b8ba4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8ba4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8ba8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8BA8u;
            // 0x1b8bac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8BA4u: goto label_1b8ba4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8BB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
