#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F388
// Address: 0x15f388 - 0x15f3ec
void sub_0015F388_0x15f388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F388_0x15f388");
#endif

    switch (ctx->pc) {
        case 0x15f39cu: goto label_15f39c;
        case 0x15f3c8u: goto label_15f3c8;
        case 0x15f3d4u: goto label_15f3d4;
        default: break;
    }

    ctx->pc = 0x15f388u;

    // 0x15f388: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f38c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f38cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f390: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15f390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15f394: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F394u;
    SET_GPR_U32(ctx, 31, 0x15F39Cu);
    ctx->pc = 0x15F398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F394u;
            // 0x15f398: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F39Cu; }
        if (ctx->pc != 0x15F39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F39Cu; }
        if (ctx->pc != 0x15F39Cu) { return; }
    }
    ctx->pc = 0x15F39Cu;
label_15f39c:
    // 0x15f39c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F39Cu;
    {
        const bool branch_taken_0x15f39c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F39Cu;
            // 0x15f3a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f39c) {
            ctx->pc = 0x15F3C0u;
            goto label_15f3c0;
        }
    }
    ctx->pc = 0x15F3A4u;
    // 0x15f3a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f3a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f3a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f3a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f3ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f3acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f3b0: 0x2484f1a0  addiu       $a0, $a0, -0xE60
    ctx->pc = 0x15f3b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963616));
    // 0x15f3b4: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F3B4u;
    ctx->pc = 0x15F3B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3B4u;
            // 0x15f3b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F3BCu;
    // 0x15f3bc: 0x0  nop
    ctx->pc = 0x15f3bcu;
    // NOP
label_15f3c0:
    // 0x15f3c0: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F3C0u;
    SET_GPR_U32(ctx, 31, 0x15F3C8u);
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3C8u; }
        if (ctx->pc != 0x15F3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3C8u; }
        if (ctx->pc != 0x15F3C8u) { return; }
    }
    ctx->pc = 0x15F3C8u;
label_15f3c8:
    // 0x15f3c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f3c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f3cc: 0xc058abe  jal         func_162AF8
    ctx->pc = 0x15F3CCu;
    SET_GPR_U32(ctx, 31, 0x15F3D4u);
    ctx->pc = 0x15F3D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3CCu;
            // 0x15f3d0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162AF8u;
    if (runtime->hasFunction(0x162AF8u)) {
        auto targetFn = runtime->lookupFunction(0x162AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3D4u; }
        if (ctx->pc != 0x15F3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162AF8_0x162af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3D4u; }
        if (ctx->pc != 0x15F3D4u) { return; }
    }
    ctx->pc = 0x15F3D4u;
label_15f3d4:
    // 0x15f3d4: 0xae000074  sw          $zero, 0x74($s0)
    ctx->pc = 0x15f3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 0));
    // 0x15f3d8: 0x8e04004c  lw          $a0, 0x4C($s0)
    ctx->pc = 0x15f3d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x15f3dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f3e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f3e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f3e4: 0x804f3de  j           func_13CF78
    ctx->pc = 0x15F3E4u;
    ctx->pc = 0x15F3E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3E4u;
            // 0x15f3e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CF78_0x13cf78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F3ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
