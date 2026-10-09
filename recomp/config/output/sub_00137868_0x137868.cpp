#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137868
// Address: 0x137868 - 0x1378d0
void sub_00137868_0x137868(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137868_0x137868");
#endif

    switch (ctx->pc) {
        case 0x13787cu: goto label_13787c;
        case 0x137894u: goto label_137894;
        case 0x1378b8u: goto label_1378b8;
        default: break;
    }

    ctx->pc = 0x137868u;

    // 0x137868: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137868u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13786c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13786cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137870: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137874: 0xc0505c0  jal         func_141700
    ctx->pc = 0x137874u;
    SET_GPR_U32(ctx, 31, 0x13787Cu);
    ctx->pc = 0x137878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137874u;
            // 0x137878: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13787Cu; }
        if (ctx->pc != 0x13787Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13787Cu; }
        if (ctx->pc != 0x13787Cu) { return; }
    }
    ctx->pc = 0x13787Cu;
label_13787c:
    // 0x13787c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13787cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x137880: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137880u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137884: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x137884u;
    {
        const bool branch_taken_0x137884 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x137888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137884u;
            // 0x137888: 0x2484c4e8  addiu       $a0, $a0, -0x3B18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137884) {
            ctx->pc = 0x1378A0u;
            goto label_1378a0;
        }
    }
    ctx->pc = 0x13788Cu;
    // 0x13788c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13788Cu;
    SET_GPR_U32(ctx, 31, 0x137894u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137894u; }
        if (ctx->pc != 0x137894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137894u; }
        if (ctx->pc != 0x137894u) { return; }
    }
    ctx->pc = 0x137894u;
label_137894:
    // 0x137894: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x137894u;
    {
        const bool branch_taken_0x137894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137894u;
            // 0x137898: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137894) {
            ctx->pc = 0x1378C4u;
            goto label_1378c4;
        }
    }
    ctx->pc = 0x13789Cu;
    // 0x13789c: 0x0  nop
    ctx->pc = 0x13789cu;
    // NOP
label_1378a0:
    // 0x1378a0: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1378a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1378a4: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1378A4u;
    {
        const bool branch_taken_0x1378a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1378a4) {
            ctx->pc = 0x1378A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1378A4u;
            // 0x1378a8: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1378C0u;
            goto label_1378c0;
        }
    }
    ctx->pc = 0x1378ACu;
    // 0x1378ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1378acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1378b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1378B0u;
    SET_GPR_U32(ctx, 31, 0x1378B8u);
    ctx->pc = 0x1378B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1378B0u;
            // 0x1378b4: 0x2484c508  addiu       $a0, $a0, -0x3AF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1378B8u; }
        if (ctx->pc != 0x1378B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1378B8u; }
        if (ctx->pc != 0x1378B8u) { return; }
    }
    ctx->pc = 0x1378B8u;
label_1378b8:
    // 0x1378b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1378B8u;
    {
        const bool branch_taken_0x1378b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1378BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1378B8u;
            // 0x1378bc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1378b8) {
            ctx->pc = 0x1378C4u;
            goto label_1378c4;
        }
    }
    ctx->pc = 0x1378C0u;
label_1378c0:
    // 0x1378c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1378c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1378c4:
    // 0x1378c4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1378c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1378c8: 0x80505de  j           func_141778
    ctx->pc = 0x1378C8u;
    ctx->pc = 0x1378CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1378C8u;
            // 0x1378cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141778_0x141778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1378D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
