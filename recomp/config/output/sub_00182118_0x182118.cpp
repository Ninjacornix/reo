#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182118
// Address: 0x182118 - 0x182154
void sub_00182118_0x182118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182118_0x182118");
#endif

    switch (ctx->pc) {
        case 0x182128u: goto label_182128;
        case 0x182144u: goto label_182144;
        default: break;
    }

    ctx->pc = 0x182118u;

    // 0x182118: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18211c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18211cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182120: 0xc06043c  jal         func_1810F0
    ctx->pc = 0x182120u;
    SET_GPR_U32(ctx, 31, 0x182128u);
    ctx->pc = 0x1810F0u;
    if (runtime->hasFunction(0x1810F0u)) {
        auto targetFn = runtime->lookupFunction(0x1810F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182128u; }
        if (ctx->pc != 0x182128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001810F0_0x1810f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182128u; }
        if (ctx->pc != 0x182128u) { return; }
    }
    ctx->pc = 0x182128u;
label_182128:
    // 0x182128: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182128u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18212c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18212cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182130: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182130u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182134: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182134u;
    {
        const bool branch_taken_0x182134 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182134u;
            // 0x182138: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182134) {
            ctx->pc = 0x182148u;
            goto label_182148;
        }
    }
    ctx->pc = 0x18213Cu;
    // 0x18213c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18213Cu;
    SET_GPR_U32(ctx, 31, 0x182144u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182144u; }
        if (ctx->pc != 0x182144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182144u; }
        if (ctx->pc != 0x182144u) { return; }
    }
    ctx->pc = 0x182144u;
label_182144:
    // 0x182144: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182148:
    // 0x182148: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18214c: 0x3e00008  jr          $ra
    ctx->pc = 0x18214Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18214Cu;
            // 0x182150: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182128u: goto label_182128;
            case 0x182144u: goto label_182144;
            case 0x182148u: goto label_182148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182154u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
