#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181F58
// Address: 0x181f58 - 0x181f94
void sub_00181F58_0x181f58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181F58_0x181f58");
#endif

    switch (ctx->pc) {
        case 0x181f68u: goto label_181f68;
        case 0x181f84u: goto label_181f84;
        default: break;
    }

    ctx->pc = 0x181f58u;

    // 0x181f58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f5c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181f60: 0xc0604fc  jal         func_1813F0
    ctx->pc = 0x181F60u;
    SET_GPR_U32(ctx, 31, 0x181F68u);
    ctx->pc = 0x1813F0u;
    if (runtime->hasFunction(0x1813F0u)) {
        auto targetFn = runtime->lookupFunction(0x1813F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F68u; }
        if (ctx->pc != 0x181F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001813F0_0x1813f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F68u; }
        if (ctx->pc != 0x181F68u) { return; }
    }
    ctx->pc = 0x181F68u;
label_181f68:
    // 0x181f68: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181f68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f6c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181f70: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181f70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f74: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181F74u;
    {
        const bool branch_taken_0x181f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F74u;
            // 0x181f78: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181f74) {
            ctx->pc = 0x181F88u;
            goto label_181f88;
        }
    }
    ctx->pc = 0x181F7Cu;
    // 0x181f7c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181F7Cu;
    SET_GPR_U32(ctx, 31, 0x181F84u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F84u; }
        if (ctx->pc != 0x181F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F84u; }
        if (ctx->pc != 0x181F84u) { return; }
    }
    ctx->pc = 0x181F84u;
label_181f84:
    // 0x181f84: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f88:
    // 0x181f88: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f8c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F8Cu;
            // 0x181f90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181F68u: goto label_181f68;
            case 0x181F84u: goto label_181f84;
            case 0x181F88u: goto label_181f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
