#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9360
// Address: 0x1b9360 - 0x1b93a8
void sub_001B9360_0x1b9360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9360_0x1b9360");
#endif

    switch (ctx->pc) {
        case 0x1b937cu: goto label_1b937c;
        case 0x1b939cu: goto label_1b939c;
        default: break;
    }

    ctx->pc = 0x1b9360u;

    // 0x1b9360: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b9360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b9364: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1b9364u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9368: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B9368u;
    {
        const bool branch_taken_0x1b9368 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B936Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9368u;
            // 0x1b936c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9368) {
            ctx->pc = 0x1B9384u;
            goto label_1b9384;
        }
    }
    ctx->pc = 0x1B9370u;
    // 0x1b9370: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9374: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B9374u;
    SET_GPR_U32(ctx, 31, 0x1B937Cu);
    ctx->pc = 0x1B9378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9374u;
            // 0x1b9378: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B937Cu; }
        if (ctx->pc != 0x1B937Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B937Cu; }
        if (ctx->pc != 0x1B937Cu) { return; }
    }
    ctx->pc = 0x1B937Cu;
label_1b937c:
    // 0x1b937c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B937Cu;
    {
        const bool branch_taken_0x1b937c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B937Cu;
            // 0x1b9380: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b937c) {
            ctx->pc = 0x1B93A0u;
            goto label_1b93a0;
        }
    }
    ctx->pc = 0x1B9384u;
label_1b9384:
    // 0x1b9384: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9388: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9388u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b938c: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x1b938cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9390: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9390u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9394: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9394u;
    SET_GPR_U32(ctx, 31, 0x1B939Cu);
    ctx->pc = 0x1B9398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9394u;
            // 0x1b9398: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B939Cu; }
        if (ctx->pc != 0x1B939Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B939Cu; }
        if (ctx->pc != 0x1B939Cu) { return; }
    }
    ctx->pc = 0x1B939Cu;
label_1b939c:
    // 0x1b939c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b939cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b93a0:
    // 0x1b93a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B93A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B93A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B93A0u;
            // 0x1b93a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B93A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
