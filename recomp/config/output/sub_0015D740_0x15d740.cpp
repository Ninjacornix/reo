#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D740
// Address: 0x15d740 - 0x15d7a0
void sub_0015D740_0x15d740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D740_0x15d740");
#endif

    switch (ctx->pc) {
        case 0x15d760u: goto label_15d760;
        case 0x15d774u: goto label_15d774;
        default: break;
    }

    ctx->pc = 0x15d740u;

    // 0x15d740: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d744: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d748: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15d748u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d74c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15d74cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15d750: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d754: 0x263001e8  addiu       $s0, $s1, 0x1E8
    ctx->pc = 0x15d754u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 488));
    // 0x15d758: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15d758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15d75c: 0x2412001f  addiu       $s2, $zero, 0x1F
    ctx->pc = 0x15d75cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
label_15d760:
    // 0x15d760: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x15d760u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15d764: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15D764u;
    {
        const bool branch_taken_0x15d764 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d764) {
            ctx->pc = 0x15D768u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D764u;
            // 0x15d768: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D77Cu;
            goto label_15d77c;
        }
    }
    ctx->pc = 0x15D76Cu;
    // 0x15d76c: 0xc0575ac  jal         func_15D6B0
    ctx->pc = 0x15D76Cu;
    SET_GPR_U32(ctx, 31, 0x15D774u);
    ctx->pc = 0x15D770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D76Cu;
            // 0x15d770: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D6B0u;
    if (runtime->hasFunction(0x15D6B0u)) {
        auto targetFn = runtime->lookupFunction(0x15D6B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D774u; }
        if (ctx->pc != 0x15D774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D6B0_0x15d6b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D774u; }
        if (ctx->pc != 0x15D774u) { return; }
    }
    ctx->pc = 0x15D774u;
label_15d774:
    // 0x15d774: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x15d774u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x15d778: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x15d778u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
label_15d77c:
    // 0x15d77c: 0x641fff8  bgez        $s2, . + 4 + (-0x8 << 2)
    ctx->pc = 0x15D77Cu;
    {
        const bool branch_taken_0x15d77c = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x15D780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D77Cu;
            // 0x15d780: 0x2610fffc  addiu       $s0, $s0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d77c) {
            ctx->pc = 0x15D760u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15d760;
        }
    }
    ctx->pc = 0x15D784u;
    // 0x15d784: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d784u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d788: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d788u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d78c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15d78cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d790: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15d790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15d794: 0x3e00008  jr          $ra
    ctx->pc = 0x15D794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D794u;
            // 0x15d798: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D760u: goto label_15d760;
            case 0x15D774u: goto label_15d774;
            case 0x15D77Cu: goto label_15d77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D79Cu;
    // 0x15d79c: 0x0  nop
    ctx->pc = 0x15d79cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
