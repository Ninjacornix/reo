#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128828
// Address: 0x128828 - 0x128860
void sub_00128828_0x128828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128828_0x128828");
#endif

    switch (ctx->pc) {
        case 0x128854u: goto label_128854;
        default: break;
    }

    ctx->pc = 0x128828u;

    // 0x128828: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x128828u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12882c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12882cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128830: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x128834: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x128834u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128838: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128838u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12883c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x12883cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128840: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x128840u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128844: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x128844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128848: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x128848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12884c: 0xc04a218  jal         func_128860
    ctx->pc = 0x12884Cu;
    SET_GPR_U32(ctx, 31, 0x128854u);
    ctx->pc = 0x128850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12884Cu;
            // 0x128850: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128854u; }
        if (ctx->pc != 0x128854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128854u; }
        if (ctx->pc != 0x128854u) { return; }
    }
    ctx->pc = 0x128854u;
label_128854:
    // 0x128854: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x128854u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128858: 0x3e00008  jr          $ra
    ctx->pc = 0x128858u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12885Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128858u;
            // 0x12885c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128854u: goto label_128854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128860u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
