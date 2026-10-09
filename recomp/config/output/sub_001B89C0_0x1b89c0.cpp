#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B89C0
// Address: 0x1b89c0 - 0x1b8a08
void sub_001B89C0_0x1b89c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B89C0_0x1b89c0");
#endif

    switch (ctx->pc) {
        case 0x1b89e0u: goto label_1b89e0;
        case 0x1b89fcu: goto label_1b89fc;
        default: break;
    }

    ctx->pc = 0x1b89c0u;

    // 0x1b89c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b89c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b89c4: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1b89c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b89c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b89c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b89cc: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B89CCu;
    {
        const bool branch_taken_0x1b89cc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B89D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89CCu;
            // 0x1b89d0: 0xc0502d  daddu       $t2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b89cc) {
            ctx->pc = 0x1B89E8u;
            goto label_1b89e8;
        }
    }
    ctx->pc = 0x1B89D4u;
    // 0x1b89d4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b89d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b89d8: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B89D8u;
    SET_GPR_U32(ctx, 31, 0x1B89E0u);
    ctx->pc = 0x1B89DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89D8u;
            // 0x1b89dc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89E0u; }
        if (ctx->pc != 0x1B89E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89E0u; }
        if (ctx->pc != 0x1B89E0u) { return; }
    }
    ctx->pc = 0x1B89E0u;
label_1b89e0:
    // 0x1b89e0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B89E0u;
    {
        const bool branch_taken_0x1b89e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B89E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89E0u;
            // 0x1b89e4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b89e0) {
            ctx->pc = 0x1B8A00u;
            goto label_1b8a00;
        }
    }
    ctx->pc = 0x1B89E8u;
label_1b89e8:
    // 0x1b89e8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b89e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b89ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b89ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b89f0: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b89f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b89f4: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B89F4u;
    SET_GPR_U32(ctx, 31, 0x1B89FCu);
    ctx->pc = 0x1B89F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89F4u;
            // 0x1b89f8: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89FCu; }
        if (ctx->pc != 0x1B89FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89FCu; }
        if (ctx->pc != 0x1B89FCu) { return; }
    }
    ctx->pc = 0x1B89FCu;
label_1b89fc:
    // 0x1b89fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b89fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b8a00:
    // 0x1b8a00: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8A00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A00u;
            // 0x1b8a04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B89E0u: goto label_1b89e0;
            case 0x1B89E8u: goto label_1b89e8;
            case 0x1B89FCu: goto label_1b89fc;
            case 0x1B8A00u: goto label_1b8a00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8A08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
