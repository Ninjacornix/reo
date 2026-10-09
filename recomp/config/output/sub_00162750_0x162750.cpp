#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162750
// Address: 0x162750 - 0x1627f0
void sub_00162750_0x162750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162750_0x162750");
#endif

    switch (ctx->pc) {
        case 0x162764u: goto label_162764;
        case 0x162790u: goto label_162790;
        case 0x1627bcu: goto label_1627bc;
        default: break;
    }

    ctx->pc = 0x162750u;

    // 0x162750: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162754: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162758: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16275c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16275Cu;
    SET_GPR_U32(ctx, 31, 0x162764u);
    ctx->pc = 0x162760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16275Cu;
            // 0x162760: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162764u; }
        if (ctx->pc != 0x162764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162764u; }
        if (ctx->pc != 0x162764u) { return; }
    }
    ctx->pc = 0x162764u;
label_162764:
    // 0x162764: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162764u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162768: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x162768u;
    {
        const bool branch_taken_0x162768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16276Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162768u;
            // 0x16276c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162768) {
            ctx->pc = 0x162788u;
            goto label_162788;
        }
    }
    ctx->pc = 0x162770u;
    // 0x162770: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162770u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162774: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162774u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162778: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162778u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16277c: 0x24840260  addiu       $a0, $a0, 0x260
    ctx->pc = 0x16277cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 608));
    // 0x162780: 0x8058dd4  j           func_163750
    ctx->pc = 0x162780u;
    ctx->pc = 0x162784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162780u;
            // 0x162784: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162788u;
label_162788:
    // 0x162788: 0xc058998  jal         func_162660
    ctx->pc = 0x162788u;
    SET_GPR_U32(ctx, 31, 0x162790u);
    ctx->pc = 0x162660u;
    if (runtime->hasFunction(0x162660u)) {
        auto targetFn = runtime->lookupFunction(0x162660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162790u; }
        if (ctx->pc != 0x162790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162660_0x162660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162790u; }
        if (ctx->pc != 0x162790u) { return; }
    }
    ctx->pc = 0x162790u;
label_162790:
    // 0x162790: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162790u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162794: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162798: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162798u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16279c: 0x80589ea  j           func_1627A8
    ctx->pc = 0x16279Cu;
    ctx->pc = 0x1627A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16279Cu;
            // 0x1627a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1627A8u;
    goto label_1627a8;
    ctx->pc = 0x1627A4u;
    // 0x1627a4: 0x0  nop
    ctx->pc = 0x1627a4u;
    // NOP
label_1627a8:
    // 0x1627a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1627a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1627ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1627acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1627b0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1627b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1627b4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1627B4u;
    SET_GPR_U32(ctx, 31, 0x1627BCu);
    ctx->pc = 0x1627B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627B4u;
            // 0x1627b8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1627BCu; }
        if (ctx->pc != 0x1627BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1627BCu; }
        if (ctx->pc != 0x1627BCu) { return; }
    }
    ctx->pc = 0x1627BCu;
label_1627bc:
    // 0x1627bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1627bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1627c0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1627C0u;
    {
        const bool branch_taken_0x1627c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1627C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1627C0u;
            // 0x1627c4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1627c0) {
            ctx->pc = 0x1627E0u;
            goto label_1627e0;
        }
    }
    ctx->pc = 0x1627C8u;
    // 0x1627c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1627c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1627cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1627ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1627d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1627d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1627d4: 0x24840290  addiu       $a0, $a0, 0x290
    ctx->pc = 0x1627d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 656));
    // 0x1627d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1627D8u;
    ctx->pc = 0x1627DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627D8u;
            // 0x1627dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1627E0u;
label_1627e0:
    // 0x1627e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1627e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1627e4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1627e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1627e8: 0x8058abe  j           func_162AF8
    ctx->pc = 0x1627E8u;
    ctx->pc = 0x1627ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1627E8u;
            // 0x1627ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162AF8u;
    if (runtime->hasFunction(0x162AF8u)) {
        auto targetFn = runtime->lookupFunction(0x162AF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162AF8_0x162af8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1627F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
