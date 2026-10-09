#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001287A8
// Address: 0x1287a8 - 0x1287dc
void sub_001287A8_0x1287a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001287A8_0x1287a8");
#endif

    switch (ctx->pc) {
        case 0x1287d0u: goto label_1287d0;
        default: break;
    }

    ctx->pc = 0x1287a8u;

    // 0x1287a8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1287a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1287acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1287b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1287b4: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1287b4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287b8: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x1287b8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287bc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1287bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287c0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1287c0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1287c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1287c8: 0xc04a218  jal         func_128860
    ctx->pc = 0x1287C8u;
    SET_GPR_U32(ctx, 31, 0x1287D0u);
    ctx->pc = 0x1287CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1287C8u;
            // 0x1287cc: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1287D0u; }
        if (ctx->pc != 0x1287D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1287D0u; }
        if (ctx->pc != 0x1287D0u) { return; }
    }
    ctx->pc = 0x1287D0u;
label_1287d0:
    // 0x1287d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1287d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1287d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1287D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1287D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1287D4u;
            // 0x1287d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1287D0u: goto label_1287d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1287DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
