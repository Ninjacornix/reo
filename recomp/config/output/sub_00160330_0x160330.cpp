#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160330
// Address: 0x160330 - 0x160384
void sub_00160330_0x160330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160330_0x160330");
#endif

    switch (ctx->pc) {
        case 0x160344u: goto label_160344;
        case 0x16035cu: goto label_16035c;
        case 0x160370u: goto label_160370;
        default: break;
    }

    ctx->pc = 0x160330u;

    // 0x160330: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x160330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x160334: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x160334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x160338: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x160338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16033c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16033Cu;
    SET_GPR_U32(ctx, 31, 0x160344u);
    ctx->pc = 0x160340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16033Cu;
            // 0x160340: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160344u; }
        if (ctx->pc != 0x160344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160344u; }
        if (ctx->pc != 0x160344u) { return; }
    }
    ctx->pc = 0x160344u;
label_160344:
    // 0x160344: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x160344u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160348: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x160348u;
    {
        const bool branch_taken_0x160348 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16034Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160348u;
            // 0x16034c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160348) {
            ctx->pc = 0x160368u;
            goto label_160368;
        }
    }
    ctx->pc = 0x160350u;
    // 0x160350: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160350u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160354: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160354u;
    SET_GPR_U32(ctx, 31, 0x16035Cu);
    ctx->pc = 0x160358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160354u;
            // 0x160358: 0x2484f628  addiu       $a0, $a0, -0x9D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16035Cu; }
        if (ctx->pc != 0x16035Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16035Cu; }
        if (ctx->pc != 0x16035Cu) { return; }
    }
    ctx->pc = 0x16035Cu;
label_16035c:
    // 0x16035c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16035Cu;
    {
        const bool branch_taken_0x16035c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16035Cu;
            // 0x160360: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16035c) {
            ctx->pc = 0x160374u;
            goto label_160374;
        }
    }
    ctx->pc = 0x160364u;
    // 0x160364: 0x0  nop
    ctx->pc = 0x160364u;
    // NOP
label_160368:
    // 0x160368: 0xc057fa2  jal         func_15FE88
    ctx->pc = 0x160368u;
    SET_GPR_U32(ctx, 31, 0x160370u);
    ctx->pc = 0x15FE88u;
    if (runtime->hasFunction(0x15FE88u)) {
        auto targetFn = runtime->lookupFunction(0x15FE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160370u; }
        if (ctx->pc != 0x160370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FE88_0x15fe88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160370u; }
        if (ctx->pc != 0x160370u) { return; }
    }
    ctx->pc = 0x160370u;
label_160370:
    // 0x160370: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x160370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_160374:
    // 0x160374: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x160374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x160378: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x160378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16037c: 0x3e00008  jr          $ra
    ctx->pc = 0x16037Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16037Cu;
            // 0x160380: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160344u: goto label_160344;
            case 0x16035Cu: goto label_16035c;
            case 0x160368u: goto label_160368;
            case 0x160370u: goto label_160370;
            case 0x160374u: goto label_160374;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160384u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
