#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138580
// Address: 0x138580 - 0x1385d8
void sub_00138580_0x138580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138580_0x138580");
#endif

    switch (ctx->pc) {
        case 0x138594u: goto label_138594;
        case 0x13859cu: goto label_13859c;
        case 0x1385b8u: goto label_1385b8;
        case 0x1385c0u: goto label_1385c0;
        default: break;
    }

    ctx->pc = 0x138580u;

    // 0x138580: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138588: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x138588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13858c: 0xc04e0bc  jal         func_1382F0
    ctx->pc = 0x13858Cu;
    SET_GPR_U32(ctx, 31, 0x138594u);
    ctx->pc = 0x138590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13858Cu;
            // 0x138590: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382F0u;
    if (runtime->hasFunction(0x1382F0u)) {
        auto targetFn = runtime->lookupFunction(0x1382F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138594u; }
        if (ctx->pc != 0x138594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001382F0_0x1382f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138594u; }
        if (ctx->pc != 0x138594u) { return; }
    }
    ctx->pc = 0x138594u;
label_138594:
    // 0x138594: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x138594u;
    SET_GPR_U32(ctx, 31, 0x13859Cu);
    ctx->pc = 0x138598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138594u;
            // 0x138598: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13859Cu; }
        if (ctx->pc != 0x13859Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13859Cu; }
        if (ctx->pc != 0x13859Cu) { return; }
    }
    ctx->pc = 0x13859Cu;
label_13859c:
    // 0x13859c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13859cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1385a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1385a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1385a4: 0x2484c780  addiu       $a0, $a0, -0x3880
    ctx->pc = 0x1385a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952832));
    // 0x1385a8: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1385A8u;
    {
        const bool branch_taken_0x1385a8 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1385ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1385A8u;
            // 0x1385ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1385a8) {
            ctx->pc = 0x1385B8u;
            goto label_1385b8;
        }
    }
    ctx->pc = 0x1385B0u;
    // 0x1385b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1385B0u;
    SET_GPR_U32(ctx, 31, 0x1385B8u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385B8u; }
        if (ctx->pc != 0x1385B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385B8u; }
        if (ctx->pc != 0x1385B8u) { return; }
    }
    ctx->pc = 0x1385B8u;
label_1385b8:
    // 0x1385b8: 0xc04e0ca  jal         func_138328
    ctx->pc = 0x1385B8u;
    SET_GPR_U32(ctx, 31, 0x1385C0u);
    ctx->pc = 0x138328u;
    if (runtime->hasFunction(0x138328u)) {
        auto targetFn = runtime->lookupFunction(0x138328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385C0u; }
        if (ctx->pc != 0x1385C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138328_0x138328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385C0u; }
        if (ctx->pc != 0x1385C0u) { return; }
    }
    ctx->pc = 0x1385C0u;
label_1385c0:
    // 0x1385c0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1385c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1385c4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1385c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1385c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1385c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1385cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1385CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1385D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1385CCu;
            // 0x1385d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138594u: goto label_138594;
            case 0x13859Cu: goto label_13859c;
            case 0x1385B8u: goto label_1385b8;
            case 0x1385C0u: goto label_1385c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1385D4u;
    // 0x1385d4: 0x0  nop
    ctx->pc = 0x1385d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
