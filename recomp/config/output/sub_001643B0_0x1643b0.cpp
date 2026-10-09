#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001643B0
// Address: 0x1643b0 - 0x164408
void sub_001643B0_0x1643b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001643B0_0x1643b0");
#endif

    switch (ctx->pc) {
        case 0x1643c4u: goto label_1643c4;
        case 0x1643d0u: goto label_1643d0;
        case 0x1643d8u: goto label_1643d8;
        case 0x1643e4u: goto label_1643e4;
        case 0x1643ecu: goto label_1643ec;
        default: break;
    }

    ctx->pc = 0x1643b0u;

    // 0x1643b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1643b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1643b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1643b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1643b8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1643b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1643bc: 0xc057e9e  jal         func_15FA78
    ctx->pc = 0x1643BCu;
    SET_GPR_U32(ctx, 31, 0x1643C4u);
    ctx->pc = 0x1643C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1643BCu;
            // 0x1643c0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FA78u;
    if (runtime->hasFunction(0x15FA78u)) {
        auto targetFn = runtime->lookupFunction(0x15FA78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643C4u; }
        if (ctx->pc != 0x1643C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA78_0x15fa78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643C4u; }
        if (ctx->pc != 0x1643C4u) { return; }
    }
    ctx->pc = 0x1643C4u;
label_1643c4:
    // 0x1643c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1643c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1643c8: 0xc0590ca  jal         func_164328
    ctx->pc = 0x1643C8u;
    SET_GPR_U32(ctx, 31, 0x1643D0u);
    ctx->pc = 0x1643CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1643C8u;
            // 0x1643cc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164328u;
    if (runtime->hasFunction(0x164328u)) {
        auto targetFn = runtime->lookupFunction(0x164328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643D0u; }
        if (ctx->pc != 0x1643D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164328_0x164328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643D0u; }
        if (ctx->pc != 0x1643D0u) { return; }
    }
    ctx->pc = 0x1643D0u;
label_1643d0:
    // 0x1643d0: 0xc058dfa  jal         func_1637E8
    ctx->pc = 0x1643D0u;
    SET_GPR_U32(ctx, 31, 0x1643D8u);
    ctx->pc = 0x1637E8u;
    if (runtime->hasFunction(0x1637E8u)) {
        auto targetFn = runtime->lookupFunction(0x1637E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643D8u; }
        if (ctx->pc != 0x1643D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001637E8_0x1637e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643D8u; }
        if (ctx->pc != 0x1643D8u) { return; }
    }
    ctx->pc = 0x1643D8u;
label_1643d8:
    // 0x1643d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1643d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1643dc: 0xc0590ca  jal         func_164328
    ctx->pc = 0x1643DCu;
    SET_GPR_U32(ctx, 31, 0x1643E4u);
    ctx->pc = 0x1643E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1643DCu;
            // 0x1643e0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164328u;
    if (runtime->hasFunction(0x164328u)) {
        auto targetFn = runtime->lookupFunction(0x164328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643E4u; }
        if (ctx->pc != 0x1643E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164328_0x164328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643E4u; }
        if (ctx->pc != 0x1643E4u) { return; }
    }
    ctx->pc = 0x1643E4u;
label_1643e4:
    // 0x1643e4: 0xc057ea4  jal         func_15FA90
    ctx->pc = 0x1643E4u;
    SET_GPR_U32(ctx, 31, 0x1643ECu);
    ctx->pc = 0x15FA90u;
    if (runtime->hasFunction(0x15FA90u)) {
        auto targetFn = runtime->lookupFunction(0x15FA90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643ECu; }
        if (ctx->pc != 0x1643ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA90_0x15fa90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1643ECu; }
        if (ctx->pc != 0x1643ECu) { return; }
    }
    ctx->pc = 0x1643ECu;
label_1643ec:
    // 0x1643ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1643ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1643f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1643f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1643f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1643f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1643f8: 0x8058e16  j           func_163858
    ctx->pc = 0x1643F8u;
    ctx->pc = 0x1643FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1643F8u;
            // 0x1643fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163858u;
    if (runtime->hasFunction(0x163858u)) {
        auto targetFn = runtime->lookupFunction(0x163858u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163858_0x163858(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164400u;
    // 0x164400: 0x3e00008  jr          $ra
    ctx->pc = 0x164400u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164400u;
            // 0x164404: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1643C4u: goto label_1643c4;
            case 0x1643D0u: goto label_1643d0;
            case 0x1643D8u: goto label_1643d8;
            case 0x1643E4u: goto label_1643e4;
            case 0x1643ECu: goto label_1643ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164408u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
