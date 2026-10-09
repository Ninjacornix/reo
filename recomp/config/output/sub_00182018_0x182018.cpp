#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182018
// Address: 0x182018 - 0x182054
void sub_00182018_0x182018(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182018_0x182018");
#endif

    switch (ctx->pc) {
        case 0x182028u: goto label_182028;
        case 0x182044u: goto label_182044;
        default: break;
    }

    ctx->pc = 0x182018u;

    // 0x182018: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18201c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18201cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182020: 0xc060594  jal         func_181650
    ctx->pc = 0x182020u;
    SET_GPR_U32(ctx, 31, 0x182028u);
    ctx->pc = 0x181650u;
    if (runtime->hasFunction(0x181650u)) {
        auto targetFn = runtime->lookupFunction(0x181650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182028u; }
        if (ctx->pc != 0x182028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181650_0x181650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182028u; }
        if (ctx->pc != 0x182028u) { return; }
    }
    ctx->pc = 0x182028u;
label_182028:
    // 0x182028: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182028u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18202c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18202cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182030: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182034: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182034u;
    {
        const bool branch_taken_0x182034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182034u;
            // 0x182038: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182034) {
            ctx->pc = 0x182048u;
            goto label_182048;
        }
    }
    ctx->pc = 0x18203Cu;
    // 0x18203c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18203Cu;
    SET_GPR_U32(ctx, 31, 0x182044u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182044u; }
        if (ctx->pc != 0x182044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182044u; }
        if (ctx->pc != 0x182044u) { return; }
    }
    ctx->pc = 0x182044u;
label_182044:
    // 0x182044: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182048:
    // 0x182048: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18204c: 0x3e00008  jr          $ra
    ctx->pc = 0x18204Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18204Cu;
            // 0x182050: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182028u: goto label_182028;
            case 0x182044u: goto label_182044;
            case 0x182048u: goto label_182048;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182054u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
