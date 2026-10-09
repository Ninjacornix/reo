#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D03A0
// Address: 0x1d03a0 - 0x1d0420
void sub_001D03A0_0x1d03a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D03A0_0x1d03a0");
#endif

    switch (ctx->pc) {
        case 0x1d03b4u: goto label_1d03b4;
        case 0x1d03c0u: goto label_1d03c0;
        case 0x1d03ccu: goto label_1d03cc;
        case 0x1d03d8u: goto label_1d03d8;
        case 0x1d03e4u: goto label_1d03e4;
        case 0x1d03f0u: goto label_1d03f0;
        case 0x1d03fcu: goto label_1d03fc;
        case 0x1d0408u: goto label_1d0408;
        default: break;
    }

    ctx->pc = 0x1d03a0u;

    // 0x1d03a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d03a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d03a4: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d03a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d03a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d03a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d03ac: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03ACu;
    SET_GPR_U32(ctx, 31, 0x1D03B4u);
    ctx->pc = 0x1D03B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03ACu;
            // 0x1d03b0: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03B4u; }
        if (ctx->pc != 0x1D03B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03B4u; }
        if (ctx->pc != 0x1D03B4u) { return; }
    }
    ctx->pc = 0x1D03B4u;
label_1d03b4:
    // 0x1d03b4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d03b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d03b8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03B8u;
    SET_GPR_U32(ctx, 31, 0x1D03C0u);
    ctx->pc = 0x1D03BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03B8u;
            // 0x1d03bc: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03C0u; }
        if (ctx->pc != 0x1D03C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03C0u; }
        if (ctx->pc != 0x1D03C0u) { return; }
    }
    ctx->pc = 0x1D03C0u;
label_1d03c0:
    // 0x1d03c0: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d03c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d03c4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03C4u;
    SET_GPR_U32(ctx, 31, 0x1D03CCu);
    ctx->pc = 0x1D03C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03C4u;
            // 0x1d03c8: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03CCu; }
        if (ctx->pc != 0x1D03CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03CCu; }
        if (ctx->pc != 0x1D03CCu) { return; }
    }
    ctx->pc = 0x1D03CCu;
label_1d03cc:
    // 0x1d03cc: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d03ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d03d0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03D0u;
    SET_GPR_U32(ctx, 31, 0x1D03D8u);
    ctx->pc = 0x1D03D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03D0u;
            // 0x1d03d4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03D8u; }
        if (ctx->pc != 0x1D03D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03D8u; }
        if (ctx->pc != 0x1D03D8u) { return; }
    }
    ctx->pc = 0x1D03D8u;
label_1d03d8:
    // 0x1d03d8: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d03d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d03dc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03DCu;
    SET_GPR_U32(ctx, 31, 0x1D03E4u);
    ctx->pc = 0x1D03E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03DCu;
            // 0x1d03e0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03E4u; }
        if (ctx->pc != 0x1D03E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03E4u; }
        if (ctx->pc != 0x1D03E4u) { return; }
    }
    ctx->pc = 0x1D03E4u;
label_1d03e4:
    // 0x1d03e4: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d03e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d03e8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03E8u;
    SET_GPR_U32(ctx, 31, 0x1D03F0u);
    ctx->pc = 0x1D03ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03E8u;
            // 0x1d03ec: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03F0u; }
        if (ctx->pc != 0x1D03F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03F0u; }
        if (ctx->pc != 0x1D03F0u) { return; }
    }
    ctx->pc = 0x1D03F0u;
label_1d03f0:
    // 0x1d03f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d03f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d03f4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D03F4u;
    SET_GPR_U32(ctx, 31, 0x1D03FCu);
    ctx->pc = 0x1D03F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D03F4u;
            // 0x1d03f8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03FCu; }
        if (ctx->pc != 0x1D03FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D03FCu; }
        if (ctx->pc != 0x1D03FCu) { return; }
    }
    ctx->pc = 0x1D03FCu;
label_1d03fc:
    // 0x1d03fc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d03fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0400: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0400u;
    SET_GPR_U32(ctx, 31, 0x1D0408u);
    ctx->pc = 0x1D0404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0400u;
            // 0x1d0404: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0408u; }
        if (ctx->pc != 0x1D0408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0408u; }
        if (ctx->pc != 0x1D0408u) { return; }
    }
    ctx->pc = 0x1D0408u;
label_1d0408:
    // 0x1d0408: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d0408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d040c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D040Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D040Cu;
            // 0x1d0410: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D03B4u: goto label_1d03b4;
            case 0x1D03C0u: goto label_1d03c0;
            case 0x1D03CCu: goto label_1d03cc;
            case 0x1D03D8u: goto label_1d03d8;
            case 0x1D03E4u: goto label_1d03e4;
            case 0x1D03F0u: goto label_1d03f0;
            case 0x1D03FCu: goto label_1d03fc;
            case 0x1D0408u: goto label_1d0408;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0414u;
    // 0x1d0414: 0x0  nop
    ctx->pc = 0x1d0414u;
    // NOP
    // 0x1d0418: 0x0  nop
    ctx->pc = 0x1d0418u;
    // NOP
    // 0x1d041c: 0x0  nop
    ctx->pc = 0x1d041cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
