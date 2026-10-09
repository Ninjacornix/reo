#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146460
// Address: 0x146460 - 0x1464f0
void sub_00146460_0x146460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146460_0x146460");
#endif

    switch (ctx->pc) {
        case 0x146478u: goto label_146478;
        case 0x146484u: goto label_146484;
        case 0x146490u: goto label_146490;
        case 0x14649cu: goto label_14649c;
        case 0x1464a8u: goto label_1464a8;
        case 0x1464b4u: goto label_1464b4;
        case 0x1464c0u: goto label_1464c0;
        case 0x1464ccu: goto label_1464cc;
        case 0x1464d8u: goto label_1464d8;
        default: break;
    }

    ctx->pc = 0x146460u;

    // 0x146460: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x146460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x146464: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x146464u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146468: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14646c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x14646cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x146470: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146470u;
    SET_GPR_U32(ctx, 31, 0x146478u);
    ctx->pc = 0x146474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146470u;
            // 0x146474: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146478u; }
        if (ctx->pc != 0x146478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146478u; }
        if (ctx->pc != 0x146478u) { return; }
    }
    ctx->pc = 0x146478u;
label_146478:
    // 0x146478: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146478u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14647c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14647Cu;
    SET_GPR_U32(ctx, 31, 0x146484u);
    ctx->pc = 0x146480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14647Cu;
            // 0x146480: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146484u; }
        if (ctx->pc != 0x146484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146484u; }
        if (ctx->pc != 0x146484u) { return; }
    }
    ctx->pc = 0x146484u;
label_146484:
    // 0x146484: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146484u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146488: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146488u;
    SET_GPR_U32(ctx, 31, 0x146490u);
    ctx->pc = 0x14648Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146488u;
            // 0x14648c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146490u; }
        if (ctx->pc != 0x146490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146490u; }
        if (ctx->pc != 0x146490u) { return; }
    }
    ctx->pc = 0x146490u;
label_146490:
    // 0x146490: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146490u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146494: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146494u;
    SET_GPR_U32(ctx, 31, 0x14649Cu);
    ctx->pc = 0x146498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146494u;
            // 0x146498: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14649Cu; }
        if (ctx->pc != 0x14649Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14649Cu; }
        if (ctx->pc != 0x14649Cu) { return; }
    }
    ctx->pc = 0x14649Cu;
label_14649c:
    // 0x14649c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14649cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464a0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464A0u;
    SET_GPR_U32(ctx, 31, 0x1464A8u);
    ctx->pc = 0x1464A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464A0u;
            // 0x1464a4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464A8u; }
        if (ctx->pc != 0x1464A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464A8u; }
        if (ctx->pc != 0x1464A8u) { return; }
    }
    ctx->pc = 0x1464A8u;
label_1464a8:
    // 0x1464a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464ac: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464ACu;
    SET_GPR_U32(ctx, 31, 0x1464B4u);
    ctx->pc = 0x1464B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464ACu;
            // 0x1464b0: 0x24050014  addiu       $a1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464B4u; }
        if (ctx->pc != 0x1464B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464B4u; }
        if (ctx->pc != 0x1464B4u) { return; }
    }
    ctx->pc = 0x1464B4u;
label_1464b4:
    // 0x1464b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464b8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464B8u;
    SET_GPR_U32(ctx, 31, 0x1464C0u);
    ctx->pc = 0x1464BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464B8u;
            // 0x1464bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464C0u; }
        if (ctx->pc != 0x1464C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464C0u; }
        if (ctx->pc != 0x1464C0u) { return; }
    }
    ctx->pc = 0x1464C0u;
label_1464c0:
    // 0x1464c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464c4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464C4u;
    SET_GPR_U32(ctx, 31, 0x1464CCu);
    ctx->pc = 0x1464C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464C4u;
            // 0x1464c8: 0x24050016  addiu       $a1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464CCu; }
        if (ctx->pc != 0x1464CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464CCu; }
        if (ctx->pc != 0x1464CCu) { return; }
    }
    ctx->pc = 0x1464CCu;
label_1464cc:
    // 0x1464cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464d0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464D0u;
    SET_GPR_U32(ctx, 31, 0x1464D8u);
    ctx->pc = 0x1464D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464D0u;
            // 0x1464d4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464D8u; }
        if (ctx->pc != 0x1464D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464D8u; }
        if (ctx->pc != 0x1464D8u) { return; }
    }
    ctx->pc = 0x1464D8u;
label_1464d8:
    // 0x1464d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1464dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1464e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1464e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1464e4: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x1464e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1464e8: 0x805167a  j           func_1459E8
    ctx->pc = 0x1464E8u;
    ctx->pc = 0x1464ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464E8u;
            // 0x1464ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001459E8_0x1459e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1464F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
