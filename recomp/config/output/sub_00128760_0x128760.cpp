#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128760
// Address: 0x128760 - 0x1287a4
void sub_00128760_0x128760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128760_0x128760");
#endif

    switch (ctx->pc) {
        case 0x128798u: goto label_128798;
        default: break;
    }

    ctx->pc = 0x128760u;

    // 0x128760: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x128760u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128764: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x128764u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128768: 0xe0602d  daddu       $t4, $a3, $zero
    ctx->pc = 0x128768u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12876c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x12876cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128770: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x128774: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x128774u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128778: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128778u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12877c: 0x180482d  daddu       $t1, $t4, $zero
    ctx->pc = 0x12877cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128780: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128780u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128784: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x128784u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128788: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x128788u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12878c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12878cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x128790: 0xc04a218  jal         func_128860
    ctx->pc = 0x128790u;
    SET_GPR_U32(ctx, 31, 0x128798u);
    ctx->pc = 0x128794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128790u;
            // 0x128794: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128798u; }
        if (ctx->pc != 0x128798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128798u; }
        if (ctx->pc != 0x128798u) { return; }
    }
    ctx->pc = 0x128798u;
label_128798:
    // 0x128798: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x128798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12879c: 0x3e00008  jr          $ra
    ctx->pc = 0x12879Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1287A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12879Cu;
            // 0x1287a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128798u: goto label_128798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1287A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
