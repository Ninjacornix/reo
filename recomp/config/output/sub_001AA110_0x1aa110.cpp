#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA110
// Address: 0x1aa110 - 0x1aa1e0
void sub_001AA110_0x1aa110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA110_0x1aa110");
#endif

    switch (ctx->pc) {
        case 0x1aa128u: goto label_1aa128;
        case 0x1aa150u: goto label_1aa150;
        case 0x1aa1c4u: goto label_1aa1c4;
        case 0x1aa1ccu: goto label_1aa1cc;
        case 0x1aa1d4u: goto label_1aa1d4;
        default: break;
    }

    ctx->pc = 0x1aa110u;

    // 0x1aa110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aa110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aa114: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa118: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aa118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aa11c: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1aa11cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa120: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AA120u;
    {
        const bool branch_taken_0x1aa120 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AA124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA120u;
            // 0x1aa124: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aa120) {
            ctx->pc = 0x1AA144u;
            goto label_1aa144;
        }
    }
    ctx->pc = 0x1AA128u;
label_1aa128:
    // 0x1aa128: 0x0  nop
    ctx->pc = 0x1aa128u;
    // NOP
    // 0x1aa12c: 0x0  nop
    ctx->pc = 0x1aa12cu;
    // NOP
    // 0x1aa130: 0x0  nop
    ctx->pc = 0x1aa130u;
    // NOP
    // 0x1aa134: 0x0  nop
    ctx->pc = 0x1aa134u;
    // NOP
    // 0x1aa138: 0x0  nop
    ctx->pc = 0x1aa138u;
    // NOP
    // 0x1aa13c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA13Cu;
    {
        const bool branch_taken_0x1aa13c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa13c) {
            ctx->pc = 0x1AA128u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa128;
        }
    }
    ctx->pc = 0x1AA144u;
label_1aa144:
    // 0x1aa144: 0x8c234448  lw          $v1, 0x4448($at)
    ctx->pc = 0x1aa144u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17480)));
    // 0x1aa148: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AA148u;
    {
        const bool branch_taken_0x1aa148 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aa148) {
            ctx->pc = 0x1AA16Cu;
            goto label_1aa16c;
        }
    }
    ctx->pc = 0x1AA150u;
label_1aa150:
    // 0x1aa150: 0x0  nop
    ctx->pc = 0x1aa150u;
    // NOP
    // 0x1aa154: 0x0  nop
    ctx->pc = 0x1aa154u;
    // NOP
    // 0x1aa158: 0x0  nop
    ctx->pc = 0x1aa158u;
    // NOP
    // 0x1aa15c: 0x0  nop
    ctx->pc = 0x1aa15cu;
    // NOP
    // 0x1aa160: 0x0  nop
    ctx->pc = 0x1aa160u;
    // NOP
    // 0x1aa164: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AA164u;
    {
        const bool branch_taken_0x1aa164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aa164) {
            ctx->pc = 0x1AA150u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1aa150;
        }
    }
    ctx->pc = 0x1AA16Cu;
label_1aa16c:
    // 0x1aa16c: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x1aa16cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x1aa170: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa170u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa174: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1aa174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa178: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1aa178u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1aa17c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1aa17cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1aa180: 0x24a522c0  addiu       $a1, $a1, 0x22C0
    ctx->pc = 0x1aa180u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8896));
    // 0x1aa184: 0x2403053e  addiu       $v1, $zero, 0x53E
    ctx->pc = 0x1aa184u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1342));
    // 0x1aa188: 0x2484cfa0  addiu       $a0, $a0, -0x3060
    ctx->pc = 0x1aa188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954912));
    // 0x1aa18c: 0xac40001c  sw          $zero, 0x1C($v0)
    ctx->pc = 0x1aa18cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x1aa190: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa190u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa194: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1aa194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa198: 0xac45000c  sw          $a1, 0xC($v0)
    ctx->pc = 0x1aa198u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 5));
    // 0x1aa19c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa19cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa1a0: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1aa1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa1a4: 0xac400018  sw          $zero, 0x18($v0)
    ctx->pc = 0x1aa1a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x1aa1a8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa1a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa1ac: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1aa1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa1b0: 0xac430014  sw          $v1, 0x14($v0)
    ctx->pc = 0x1aa1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 3));
    // 0x1aa1b4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1aa1b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1aa1b8: 0x8c251698  lw          $a1, 0x1698($at)
    ctx->pc = 0x1aa1b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1aa1bc: 0xc06a758  jal         func_1A9D60
    ctx->pc = 0x1AA1BCu;
    SET_GPR_U32(ctx, 31, 0x1AA1C4u);
    ctx->pc = 0x1AA1C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA1BCu;
            // 0x1aa1c0: 0x24066000  addiu       $a2, $zero, 0x6000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9D60u;
    if (runtime->hasFunction(0x1A9D60u)) {
        auto targetFn = runtime->lookupFunction(0x1A9D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1C4u; }
        if (ctx->pc != 0x1AA1C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9D60_0x1a9d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1C4u; }
        if (ctx->pc != 0x1AA1C4u) { return; }
    }
    ctx->pc = 0x1AA1C4u;
label_1aa1c4:
    // 0x1aa1c4: 0xc06acf0  jal         func_1AB3C0
    ctx->pc = 0x1AA1C4u;
    SET_GPR_U32(ctx, 31, 0x1AA1CCu);
    ctx->pc = 0x1AB3C0u;
    if (runtime->hasFunction(0x1AB3C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1CCu; }
        if (ctx->pc != 0x1AA1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB3C0_0x1ab3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1CCu; }
        if (ctx->pc != 0x1AA1CCu) { return; }
    }
    ctx->pc = 0x1AA1CCu;
label_1aa1cc:
    // 0x1aa1cc: 0xc06acb4  jal         func_1AB2D0
    ctx->pc = 0x1AA1CCu;
    SET_GPR_U32(ctx, 31, 0x1AA1D4u);
    ctx->pc = 0x1AB2D0u;
    if (runtime->hasFunction(0x1AB2D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1D4u; }
        if (ctx->pc != 0x1AA1D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2D0_0x1ab2d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AA1D4u; }
        if (ctx->pc != 0x1AA1D4u) { return; }
    }
    ctx->pc = 0x1AA1D4u;
label_1aa1d4:
    // 0x1aa1d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aa1d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aa1d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA1D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AA1DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AA1D8u;
            // 0x1aa1dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AA128u: goto label_1aa128;
            case 0x1AA144u: goto label_1aa144;
            case 0x1AA150u: goto label_1aa150;
            case 0x1AA16Cu: goto label_1aa16c;
            case 0x1AA1C4u: goto label_1aa1c4;
            case 0x1AA1CCu: goto label_1aa1cc;
            case 0x1AA1D4u: goto label_1aa1d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AA1E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
