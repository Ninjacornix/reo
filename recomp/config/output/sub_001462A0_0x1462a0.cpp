#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001462A0
// Address: 0x1462a0 - 0x146364
void sub_001462A0_0x1462a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001462A0_0x1462a0");
#endif

    switch (ctx->pc) {
        case 0x1462b8u: goto label_1462b8;
        case 0x1462c8u: goto label_1462c8;
        case 0x1462d4u: goto label_1462d4;
        case 0x1462dcu: goto label_1462dc;
        case 0x1462e8u: goto label_1462e8;
        case 0x1462f8u: goto label_1462f8;
        case 0x146304u: goto label_146304;
        case 0x14630cu: goto label_14630c;
        case 0x146318u: goto label_146318;
        case 0x14632cu: goto label_14632c;
        case 0x146338u: goto label_146338;
        default: break;
    }

    ctx->pc = 0x1462a0u;

    // 0x1462a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1462a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1462a4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1462a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1462a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1462a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1462ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1462acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1462b0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1462B0u;
    SET_GPR_U32(ctx, 31, 0x1462B8u);
    ctx->pc = 0x1462B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462B0u;
            // 0x1462b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462B8u; }
        if (ctx->pc != 0x1462B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462B8u; }
        if (ctx->pc != 0x1462B8u) { return; }
    }
    ctx->pc = 0x1462B8u;
label_1462b8:
    // 0x1462b8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1462B8u;
    {
        const bool branch_taken_0x1462b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1462BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1462B8u;
            // 0x1462bc: 0xae020858  sw          $v0, 0x858($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2136), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1462b8) {
            ctx->pc = 0x1462DCu;
            goto label_1462dc;
        }
    }
    ctx->pc = 0x1462C0u;
    // 0x1462c0: 0xc051496  jal         func_145258
    ctx->pc = 0x1462C0u;
    SET_GPR_U32(ctx, 31, 0x1462C8u);
    ctx->pc = 0x1462C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462C0u;
            // 0x1462c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462C8u; }
        if (ctx->pc != 0x1462C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462C8u; }
        if (ctx->pc != 0x1462C8u) { return; }
    }
    ctx->pc = 0x1462C8u;
label_1462c8:
    // 0x1462c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462cc: 0xc05148a  jal         func_145228
    ctx->pc = 0x1462CCu;
    SET_GPR_U32(ctx, 31, 0x1462D4u);
    ctx->pc = 0x1462D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462CCu;
            // 0x1462d0: 0x3c055000  lui         $a1, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20480 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462D4u; }
        if (ctx->pc != 0x1462D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462D4u; }
        if (ctx->pc != 0x1462D4u) { return; }
    }
    ctx->pc = 0x1462D4u;
label_1462d4:
    // 0x1462d4: 0xc051496  jal         func_145258
    ctx->pc = 0x1462D4u;
    SET_GPR_U32(ctx, 31, 0x1462DCu);
    ctx->pc = 0x1462D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462D4u;
            // 0x1462d8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462DCu; }
        if (ctx->pc != 0x1462DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462DCu; }
        if (ctx->pc != 0x1462DCu) { return; }
    }
    ctx->pc = 0x1462DCu;
label_1462dc:
    // 0x1462dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462e0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1462E0u;
    SET_GPR_U32(ctx, 31, 0x1462E8u);
    ctx->pc = 0x1462E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462E0u;
            // 0x1462e4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462E8u; }
        if (ctx->pc != 0x1462E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462E8u; }
        if (ctx->pc != 0x1462E8u) { return; }
    }
    ctx->pc = 0x1462E8u;
label_1462e8:
    // 0x1462e8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1462E8u;
    {
        const bool branch_taken_0x1462e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1462ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1462E8u;
            // 0x1462ec: 0xae02085c  sw          $v0, 0x85C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2140), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1462e8) {
            ctx->pc = 0x14630Cu;
            goto label_14630c;
        }
    }
    ctx->pc = 0x1462F0u;
    // 0x1462f0: 0xc051496  jal         func_145258
    ctx->pc = 0x1462F0u;
    SET_GPR_U32(ctx, 31, 0x1462F8u);
    ctx->pc = 0x1462F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462F0u;
            // 0x1462f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462F8u; }
        if (ctx->pc != 0x1462F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462F8u; }
        if (ctx->pc != 0x1462F8u) { return; }
    }
    ctx->pc = 0x1462F8u;
label_1462f8:
    // 0x1462f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462fc: 0xc05148a  jal         func_145228
    ctx->pc = 0x1462FCu;
    SET_GPR_U32(ctx, 31, 0x146304u);
    ctx->pc = 0x146300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462FCu;
            // 0x146300: 0x3c055800  lui         $a1, 0x5800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22528 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146304u; }
        if (ctx->pc != 0x146304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146304u; }
        if (ctx->pc != 0x146304u) { return; }
    }
    ctx->pc = 0x146304u;
label_146304:
    // 0x146304: 0xc051496  jal         func_145258
    ctx->pc = 0x146304u;
    SET_GPR_U32(ctx, 31, 0x14630Cu);
    ctx->pc = 0x146308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146304u;
            // 0x146308: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14630Cu; }
        if (ctx->pc != 0x14630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14630Cu; }
        if (ctx->pc != 0x14630Cu) { return; }
    }
    ctx->pc = 0x14630Cu;
label_14630c:
    // 0x14630c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14630cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146310: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146310u;
    SET_GPR_U32(ctx, 31, 0x146318u);
    ctx->pc = 0x146314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146310u;
            // 0x146314: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146318u; }
        if (ctx->pc != 0x146318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146318u; }
        if (ctx->pc != 0x146318u) { return; }
    }
    ctx->pc = 0x146318u;
label_146318:
    // 0x146318: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x146318u;
    {
        const bool branch_taken_0x146318 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14631Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146318u;
            // 0x14631c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146318) {
            ctx->pc = 0x14632Cu;
            goto label_14632c;
        }
    }
    ctx->pc = 0x146320u;
    // 0x146320: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146324: 0xc05221c  jal         func_148870
    ctx->pc = 0x146324u;
    SET_GPR_U32(ctx, 31, 0x14632Cu);
    ctx->pc = 0x146328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146324u;
            // 0x146328: 0x24a5df28  addiu       $a1, $a1, -0x20D8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958888));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14632Cu; }
        if (ctx->pc != 0x14632Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14632Cu; }
        if (ctx->pc != 0x14632Cu) { return; }
    }
    ctx->pc = 0x14632Cu;
label_14632c:
    // 0x14632c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14632cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146330: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146330u;
    SET_GPR_U32(ctx, 31, 0x146338u);
    ctx->pc = 0x146334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146330u;
            // 0x146334: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146338u; }
        if (ctx->pc != 0x146338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146338u; }
        if (ctx->pc != 0x146338u) { return; }
    }
    ctx->pc = 0x146338u;
label_146338:
    // 0x146338: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x146338u;
    {
        const bool branch_taken_0x146338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14633Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146338u;
            // 0x14633c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146338) {
            ctx->pc = 0x146358u;
            goto label_146358;
        }
    }
    ctx->pc = 0x146340u;
    // 0x146340: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146340u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146344: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x146344u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x146348: 0x24a5df50  addiu       $a1, $a1, -0x20B0
    ctx->pc = 0x146348u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958928));
    // 0x14634c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14634cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146350: 0x805221c  j           func_148870
    ctx->pc = 0x146350u;
    ctx->pc = 0x146354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146350u;
            // 0x146354: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x146358u;
label_146358:
    // 0x146358: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146358u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14635c: 0x3e00008  jr          $ra
    ctx->pc = 0x14635Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14635Cu;
            // 0x146360: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1462B8u: goto label_1462b8;
            case 0x1462C8u: goto label_1462c8;
            case 0x1462D4u: goto label_1462d4;
            case 0x1462DCu: goto label_1462dc;
            case 0x1462E8u: goto label_1462e8;
            case 0x1462F8u: goto label_1462f8;
            case 0x146304u: goto label_146304;
            case 0x14630Cu: goto label_14630c;
            case 0x146318u: goto label_146318;
            case 0x14632Cu: goto label_14632c;
            case 0x146338u: goto label_146338;
            case 0x146358u: goto label_146358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146364u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
