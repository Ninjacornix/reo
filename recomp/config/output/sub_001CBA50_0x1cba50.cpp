#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBA50
// Address: 0x1cba50 - 0x1cbb54
void sub_001CBA50_0x1cba50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBA50_0x1cba50");
#endif

    switch (ctx->pc) {
        case 0x1cbaa0u: goto label_1cbaa0;
        case 0x1cbac0u: goto label_1cbac0;
        case 0x1cbae0u: goto label_1cbae0;
        case 0x1cbb24u: goto label_1cbb24;
        case 0x1cbb3cu: goto label_1cbb3c;
        default: break;
    }

    ctx->pc = 0x1cba50u;

    // 0x1cba50: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1cba50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1cba54: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba58: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1cba58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1cba5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cba5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cba60: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cba60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cba64: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cba64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cba68: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cba68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cba6c: 0x27b20048  addiu       $s2, $sp, 0x48
    ctx->pc = 0x1cba6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1cba70: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cba70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cba74: 0x27b10044  addiu       $s1, $sp, 0x44
    ctx->pc = 0x1cba74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x1cba78: 0xac20d9f8  sw          $zero, -0x2608($at)
    ctx->pc = 0x1cba78u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957560), GPR_U32(ctx, 0));
    // 0x1cba7c: 0x27b00054  addiu       $s0, $sp, 0x54
    ctx->pc = 0x1cba7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 84));
    // 0x1cba80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba84: 0xac20da00  sw          $zero, -0x2600($at)
    ctx->pc = 0x1cba84u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 0));
    // 0x1cba88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cba88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cba8c: 0xac20da08  sw          $zero, -0x25F8($at)
    ctx->pc = 0x1cba8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957576), GPR_U32(ctx, 0));
    // 0x1cba90: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cba90u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cba94: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cba94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cba98: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBA98u;
    SET_GPR_U32(ctx, 31, 0x1CBAA0u);
    ctx->pc = 0x1CBA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA98u;
            // 0x1cba9c: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAA0u; }
        if (ctx->pc != 0x1CBAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAA0u; }
        if (ctx->pc != 0x1CBAA0u) { return; }
    }
    ctx->pc = 0x1CBAA0u;
label_1cbaa0:
    // 0x1cbaa0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbaa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbaa4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cbaa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cbaa8: 0xac226008  sw          $v0, 0x6008($at)
    ctx->pc = 0x1cbaa8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24584), GPR_U32(ctx, 2));
    // 0x1cbaac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cbaacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cbab0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cbab0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cbab4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cbab4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cbab8: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBAB8u;
    SET_GPR_U32(ctx, 31, 0x1CBAC0u);
    ctx->pc = 0x1CBABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBAB8u;
            // 0x1cbabc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAC0u; }
        if (ctx->pc != 0x1CBAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAC0u; }
        if (ctx->pc != 0x1CBAC0u) { return; }
    }
    ctx->pc = 0x1CBAC0u;
label_1cbac0:
    // 0x1cbac0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbac0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbac4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1cbac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1cbac8: 0xac226000  sw          $v0, 0x6000($at)
    ctx->pc = 0x1cbac8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24576), GPR_U32(ctx, 2));
    // 0x1cbacc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cbaccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cbad0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1cbad0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1cbad4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1cbad4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1cbad8: 0xc045188  jal         func_114620
    ctx->pc = 0x1CBAD8u;
    SET_GPR_U32(ctx, 31, 0x1CBAE0u);
    ctx->pc = 0x1CBADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBAD8u;
            // 0x1cbadc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAE0u; }
        if (ctx->pc != 0x1CBAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBAE0u; }
        if (ctx->pc != 0x1CBAE0u) { return; }
    }
    ctx->pc = 0x1CBAE0u;
label_1cbae0:
    // 0x1cbae0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbae0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbae4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1cbae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1cbae8: 0xac225fe8  sw          $v0, 0x5FE8($at)
    ctx->pc = 0x1cbae8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24552), GPR_U32(ctx, 2));
    // 0x1cbaec: 0x24022000  addiu       $v0, $zero, 0x2000
    ctx->pc = 0x1cbaecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1cbaf0: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x1cbaf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x1cbaf4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1cbaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1cbaf8: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x1cbaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x1cbafc: 0xafa20070  sw          $v0, 0x70($sp)
    ctx->pc = 0x1cbafcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 2));
    // 0x1cbb00: 0x3c02001d  lui         $v0, 0x1D
    ctx->pc = 0x1cbb00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)29 << 16));
    // 0x1cbb04: 0x2442b9a0  addiu       $v0, $v0, -0x4660
    ctx->pc = 0x1cbb04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949280));
    // 0x1cbb08: 0xafa20064  sw          $v0, 0x64($sp)
    ctx->pc = 0x1cbb08u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 2));
    // 0x1cbb0c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cbb0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cbb10: 0x2442da10  addiu       $v0, $v0, -0x25F0
    ctx->pc = 0x1cbb10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957584));
    // 0x1cbb14: 0xafa20068  sw          $v0, 0x68($sp)
    ctx->pc = 0x1cbb14u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 2));
    // 0x1cbb18: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cbb18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cbb1c: 0xc045108  jal         func_114420
    ctx->pc = 0x1CBB1Cu;
    SET_GPR_U32(ctx, 31, 0x1CBB24u);
    ctx->pc = 0x1CBB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB1Cu;
            // 0x1cbb20: 0xafa20074  sw          $v0, 0x74($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB24u; }
        if (ctx->pc != 0x1CBB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB24u; }
        if (ctx->pc != 0x1CBB24u) { return; }
    }
    ctx->pc = 0x1CBB24u;
label_1cbb24:
    // 0x1cbb24: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbb24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbb28: 0xac225ff8  sw          $v0, 0x5FF8($at)
    ctx->pc = 0x1cbb28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24568), GPR_U32(ctx, 2));
    // 0x1cbb2c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbb2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbb30: 0x8c245ff8  lw          $a0, 0x5FF8($at)
    ctx->pc = 0x1cbb30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24568)));
    // 0x1cbb34: 0xc045110  jal         func_114440
    ctx->pc = 0x1CBB34u;
    SET_GPR_U32(ctx, 31, 0x1CBB3Cu);
    ctx->pc = 0x1CBB38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB34u;
            // 0x1cbb38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB3Cu; }
        if (ctx->pc != 0x1CBB3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBB3Cu; }
        if (ctx->pc != 0x1CBB3Cu) { return; }
    }
    ctx->pc = 0x1CBB3Cu;
label_1cbb3c:
    // 0x1cbb3c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1cbb3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cbb40: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cbb40u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cbb44: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cbb44u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cbb48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbb48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbb4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBB4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB4Cu;
            // 0x1cbb50: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBAA0u: goto label_1cbaa0;
            case 0x1CBAC0u: goto label_1cbac0;
            case 0x1CBAE0u: goto label_1cbae0;
            case 0x1CBB24u: goto label_1cbb24;
            case 0x1CBB3Cu: goto label_1cbb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBB54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
