#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D678
// Address: 0x15d678 - 0x15d6b0
void sub_0015D678_0x15d678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D678_0x15d678");
#endif

    switch (ctx->pc) {
        case 0x15d68cu: goto label_15d68c;
        case 0x15d69cu: goto label_15d69c;
        default: break;
    }

    ctx->pc = 0x15d678u;

    // 0x15d678: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d678u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d67c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d67cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d680: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d684: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15D684u;
    SET_GPR_U32(ctx, 31, 0x15D68Cu);
    ctx->pc = 0x15D688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D684u;
            // 0x15d688: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D68Cu; }
        if (ctx->pc != 0x15D68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D68Cu; }
        if (ctx->pc != 0x15D68Cu) { return; }
    }
    ctx->pc = 0x15D68Cu;
label_15d68c:
    // 0x15d68c: 0x8c440030  lw          $a0, 0x30($v0)
    ctx->pc = 0x15d68cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x15d690: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x15d690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x15d694: 0x40f809  jalr        $v0
    ctx->pc = 0x15D694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15D69Cu);
        ctx->pc = 0x15D698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D694u;
            // 0x15d698: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15D69Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D68Cu: goto label_15d68c;
            case 0x15D69Cu: goto label_15d69c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15D69Cu; }
            if (ctx->pc != 0x15D69Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15D69Cu;
label_15d69c:
    // 0x15d69c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d69cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d6a0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d6a4: 0x3e00008  jr          $ra
    ctx->pc = 0x15D6A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D6A4u;
            // 0x15d6a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D68Cu: goto label_15d68c;
            case 0x15D69Cu: goto label_15d69c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D6ACu;
    // 0x15d6ac: 0x0  nop
    ctx->pc = 0x15d6acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
