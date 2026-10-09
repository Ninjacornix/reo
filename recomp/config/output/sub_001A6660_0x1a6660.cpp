#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6660
// Address: 0x1a6660 - 0x1a66a0
void sub_001A6660_0x1a6660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6660_0x1a6660");
#endif

    switch (ctx->pc) {
        case 0x1a6670u: goto label_1a6670;
        case 0x1a668cu: goto label_1a668c;
        default: break;
    }

    ctx->pc = 0x1a6660u;

    // 0x1a6660: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a6660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a6664: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a6664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a6668: 0xc06224e  jal         func_188938
    ctx->pc = 0x1A6668u;
    SET_GPR_U32(ctx, 31, 0x1A6670u);
    ctx->pc = 0x188938u;
    if (runtime->hasFunction(0x188938u)) {
        auto targetFn = runtime->lookupFunction(0x188938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6670u; }
        if (ctx->pc != 0x1A6670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188938_0x188938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6670u; }
        if (ctx->pc != 0x1A6670u) { return; }
    }
    ctx->pc = 0x1A6670u;
label_1a6670:
    // 0x1a6670: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a6670u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6674: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A6674u;
    {
        const bool branch_taken_0x1a6674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A6678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6674u;
            // 0x1a6678: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6674) {
            ctx->pc = 0x1A6684u;
            goto label_1a6684;
        }
    }
    ctx->pc = 0x1A667Cu;
    // 0x1a667c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A667Cu;
    {
        const bool branch_taken_0x1a667c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A667Cu;
            // 0x1a6680: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a667c) {
            ctx->pc = 0x1A6694u;
            goto label_1a6694;
        }
    }
    ctx->pc = 0x1A6684u;
label_1a6684:
    // 0x1a6684: 0xc0600b4  jal         func_1802D0
    ctx->pc = 0x1A6684u;
    SET_GPR_U32(ctx, 31, 0x1A668Cu);
    ctx->pc = 0x1802D0u;
    if (runtime->hasFunction(0x1802D0u)) {
        auto targetFn = runtime->lookupFunction(0x1802D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A668Cu; }
        if (ctx->pc != 0x1A668Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001802D0_0x1802d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A668Cu; }
        if (ctx->pc != 0x1A668Cu) { return; }
    }
    ctx->pc = 0x1A668Cu;
label_1a668c:
    // 0x1a668c: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1a668cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1a6690: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1a6690u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1a6694:
    // 0x1a6694: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a6694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a6698: 0x3e00008  jr          $ra
    ctx->pc = 0x1A6698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A669Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6698u;
            // 0x1a669c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A6670u: goto label_1a6670;
            case 0x1A6684u: goto label_1a6684;
            case 0x1A668Cu: goto label_1a668c;
            case 0x1A6694u: goto label_1a6694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A66A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
