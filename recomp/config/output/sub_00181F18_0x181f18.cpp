#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181F18
// Address: 0x181f18 - 0x181f54
void sub_00181F18_0x181f18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181F18_0x181f18");
#endif

    switch (ctx->pc) {
        case 0x181f28u: goto label_181f28;
        case 0x181f44u: goto label_181f44;
        default: break;
    }

    ctx->pc = 0x181f18u;

    // 0x181f18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181f20: 0xc0604c4  jal         func_181310
    ctx->pc = 0x181F20u;
    SET_GPR_U32(ctx, 31, 0x181F28u);
    ctx->pc = 0x181310u;
    if (runtime->hasFunction(0x181310u)) {
        auto targetFn = runtime->lookupFunction(0x181310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F28u; }
        if (ctx->pc != 0x181F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181310_0x181310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F28u; }
        if (ctx->pc != 0x181F28u) { return; }
    }
    ctx->pc = 0x181F28u;
label_181f28:
    // 0x181f28: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181f28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f2c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181f30: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181f30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181f34: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181F34u;
    {
        const bool branch_taken_0x181f34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F34u;
            // 0x181f38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181f34) {
            ctx->pc = 0x181F48u;
            goto label_181f48;
        }
    }
    ctx->pc = 0x181F3Cu;
    // 0x181f3c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181F3Cu;
    SET_GPR_U32(ctx, 31, 0x181F44u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F44u; }
        if (ctx->pc != 0x181F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F44u; }
        if (ctx->pc != 0x181F44u) { return; }
    }
    ctx->pc = 0x181F44u;
label_181f44:
    // 0x181f44: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f48:
    // 0x181f48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f4c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F4Cu;
            // 0x181f50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181F28u: goto label_181f28;
            case 0x181F44u: goto label_181f44;
            case 0x181F48u: goto label_181f48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
