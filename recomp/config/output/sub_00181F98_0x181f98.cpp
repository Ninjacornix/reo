#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181F98
// Address: 0x181f98 - 0x181fd4
void sub_00181F98_0x181f98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181F98_0x181f98");
#endif

    switch (ctx->pc) {
        case 0x181fa8u: goto label_181fa8;
        case 0x181fc4u: goto label_181fc4;
        default: break;
    }

    ctx->pc = 0x181f98u;

    // 0x181f98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181f98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181f9c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181fa0: 0xc06052a  jal         func_1814A8
    ctx->pc = 0x181FA0u;
    SET_GPR_U32(ctx, 31, 0x181FA8u);
    ctx->pc = 0x1814A8u;
    if (runtime->hasFunction(0x1814A8u)) {
        auto targetFn = runtime->lookupFunction(0x1814A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FA8u; }
        if (ctx->pc != 0x181FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001814A8_0x1814a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FA8u; }
        if (ctx->pc != 0x181FA8u) { return; }
    }
    ctx->pc = 0x181FA8u;
label_181fa8:
    // 0x181fa8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181fa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181facu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181fb0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181fb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fb4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181FB4u;
    {
        const bool branch_taken_0x181fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FB4u;
            // 0x181fb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181fb4) {
            ctx->pc = 0x181FC8u;
            goto label_181fc8;
        }
    }
    ctx->pc = 0x181FBCu;
    // 0x181fbc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181FBCu;
    SET_GPR_U32(ctx, 31, 0x181FC4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FC4u; }
        if (ctx->pc != 0x181FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FC4u; }
        if (ctx->pc != 0x181FC4u) { return; }
    }
    ctx->pc = 0x181FC4u;
label_181fc4:
    // 0x181fc4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181fc8:
    // 0x181fc8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181fcc: 0x3e00008  jr          $ra
    ctx->pc = 0x181FCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FCCu;
            // 0x181fd0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181FA8u: goto label_181fa8;
            case 0x181FC4u: goto label_181fc4;
            case 0x181FC8u: goto label_181fc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181FD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
