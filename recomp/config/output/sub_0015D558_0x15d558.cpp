#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D558
// Address: 0x15d558 - 0x15d5a0
void sub_0015D558_0x15d558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D558_0x15d558");
#endif

    switch (ctx->pc) {
        case 0x15d57cu: goto label_15d57c;
        default: break;
    }

    ctx->pc = 0x15d558u;

    // 0x15d558: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d55c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d560: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15d560u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d564: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d568: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15d568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d56c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15d56cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15d570: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15d570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15d574: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15D574u;
    SET_GPR_U32(ctx, 31, 0x15D57Cu);
    ctx->pc = 0x15D578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D574u;
            // 0x15d578: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D57Cu; }
        if (ctx->pc != 0x15D57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D57Cu; }
        if (ctx->pc != 0x15D57Cu) { return; }
    }
    ctx->pc = 0x15D57Cu;
label_15d57c:
    // 0x15d57c: 0xac500030  sw          $s0, 0x30($v0)
    ctx->pc = 0x15d57cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 16));
    // 0x15d580: 0xac510028  sw          $s1, 0x28($v0)
    ctx->pc = 0x15d580u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 17));
    // 0x15d584: 0xac52002c  sw          $s2, 0x2C($v0)
    ctx->pc = 0x15d584u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 44), GPR_U32(ctx, 18));
    // 0x15d588: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d588u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d58c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d58cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d590: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15d590u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d594: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15d594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15d598: 0x3e00008  jr          $ra
    ctx->pc = 0x15D598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D598u;
            // 0x15d59c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D57Cu: goto label_15d57c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D5A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
