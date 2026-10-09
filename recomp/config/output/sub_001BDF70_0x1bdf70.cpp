#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDF70
// Address: 0x1bdf70 - 0x1be190
void sub_001BDF70_0x1bdf70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDF70_0x1bdf70");
#endif

    switch (ctx->pc) {
        case 0x1bdfd4u: goto label_1bdfd4;
        case 0x1bdfe4u: goto label_1bdfe4;
        case 0x1bdfecu: goto label_1bdfec;
        case 0x1bdff8u: goto label_1bdff8;
        case 0x1be010u: goto label_1be010;
        case 0x1be020u: goto label_1be020;
        case 0x1be068u: goto label_1be068;
        case 0x1be080u: goto label_1be080;
        case 0x1be128u: goto label_1be128;
        case 0x1be130u: goto label_1be130;
        case 0x1be164u: goto label_1be164;
        default: break;
    }

    ctx->pc = 0x1bdf70u;

    // 0x1bdf70: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x1bdf70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1bdf74: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bdf74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bdf78: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1bdf78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1bdf7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bdf7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bdf80: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bdf80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bdf84: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bdf84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bdf88: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1bdf88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdf8c: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1bdf8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bdf90: 0x10830063  beq         $a0, $v1, . + 4 + (0x63 << 2)
    ctx->pc = 0x1BDF90u;
    {
        const bool branch_taken_0x1bdf90 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BDF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF90u;
            // 0x1bdf94: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdf90) {
            ctx->pc = 0x1BE120u;
            goto label_1be120;
        }
    }
    ctx->pc = 0x1BDF98u;
    // 0x1bdf98: 0x10830029  beq         $a0, $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x1BDF98u;
    {
        const bool branch_taken_0x1bdf98 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bdf98) {
            ctx->pc = 0x1BE040u;
            goto label_1be040;
        }
    }
    ctx->pc = 0x1BDFA0u;
    // 0x1bdfa0: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BDFA0u;
    {
        const bool branch_taken_0x1bdfa0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bdfa0) {
            ctx->pc = 0x1BDFB0u;
            goto label_1bdfb0;
        }
    }
    ctx->pc = 0x1BDFA8u;
    // 0x1bdfa8: 0x10000074  b           . + 4 + (0x74 << 2)
    ctx->pc = 0x1BDFA8u;
    {
        const bool branch_taken_0x1bdfa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDFACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDFA8u;
            // 0x1bdfac: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdfa8) {
            ctx->pc = 0x1BE17Cu;
            goto label_1be17c;
        }
    }
    ctx->pc = 0x1BDFB0u;
label_1bdfb0:
    // 0x1bdfb0: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x1bdfb0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1bdfb4: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1bdfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1bdfb8: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1bdfb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1bdfbc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1bdfbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1bdfc0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bdfc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bdfc4: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1bdfc4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdfc8: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1bdfc8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bdfcc: 0xc06f904  jal         func_1BE410
    ctx->pc = 0x1BDFCCu;
    SET_GPR_U32(ctx, 31, 0x1BDFD4u);
    ctx->pc = 0x1BDFD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDFCCu;
            // 0x1bdfd0: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE410u;
    if (runtime->hasFunction(0x1BE410u)) {
        auto targetFn = runtime->lookupFunction(0x1BE410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFD4u; }
        if (ctx->pc != 0x1BDFD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE410_0x1be410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFD4u; }
        if (ctx->pc != 0x1BDFD4u) { return; }
    }
    ctx->pc = 0x1BDFD4u;
label_1bdfd4:
    // 0x1bdfd4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1bdfd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bdfd8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1bdfd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bdfdc: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BDFDCu;
    SET_GPR_U32(ctx, 31, 0x1BDFE4u);
    ctx->pc = 0x1BDFE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDFDCu;
            // 0x1bdfe0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFE4u; }
        if (ctx->pc != 0x1BDFE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFE4u; }
        if (ctx->pc != 0x1BDFE4u) { return; }
    }
    ctx->pc = 0x1BDFE4u;
label_1bdfe4:
    // 0x1bdfe4: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BDFE4u;
    {
        const bool branch_taken_0x1bdfe4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BDFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDFE4u;
            // 0x1bdfe8: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdfe4) {
            ctx->pc = 0x1BE000u;
            goto label_1be000;
        }
    }
    ctx->pc = 0x1BDFECu;
label_1bdfec:
    // 0x1bdfec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bdfecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdff0: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDFF0u;
    SET_GPR_U32(ctx, 31, 0x1BDFF8u);
    ctx->pc = 0x1BDFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDFF0u;
            // 0x1bdff4: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFF8u; }
        if (ctx->pc != 0x1BDFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDFF8u; }
        if (ctx->pc != 0x1BDFF8u) { return; }
    }
    ctx->pc = 0x1BDFF8u;
label_1bdff8:
    // 0x1bdff8: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1BDFF8u;
    {
        const bool branch_taken_0x1bdff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bdff8) {
            ctx->pc = 0x1BE178u;
            goto label_1be178;
        }
    }
    ctx->pc = 0x1BE000u;
label_1be000:
    // 0x1be000: 0xae260028  sw          $a2, 0x28($s1)
    ctx->pc = 0x1be000u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 6));
    // 0x1be004: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1be004u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1be008: 0xc06f914  jal         func_1BE450
    ctx->pc = 0x1BE008u;
    SET_GPR_U32(ctx, 31, 0x1BE010u);
    ctx->pc = 0x1BE00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE008u;
            // 0x1be00c: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE450u;
    if (runtime->hasFunction(0x1BE450u)) {
        auto targetFn = runtime->lookupFunction(0x1BE450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE010u; }
        if (ctx->pc != 0x1BE010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE450_0x1be450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE010u; }
        if (ctx->pc != 0x1BE010u) { return; }
    }
    ctx->pc = 0x1BE010u;
label_1be010:
    // 0x1be010: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1be010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1be014: 0x24050602  addiu       $a1, $zero, 0x602
    ctx->pc = 0x1be014u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1538));
    // 0x1be018: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BE018u;
    SET_GPR_U32(ctx, 31, 0x1BE020u);
    ctx->pc = 0x1BE01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE018u;
            // 0x1be01c: 0x240601b6  addiu       $a2, $zero, 0x1B6 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 438));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE020u; }
        if (ctx->pc != 0x1BE020u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE020u; }
        if (ctx->pc != 0x1BE020u) { return; }
    }
    ctx->pc = 0x1BE020u;
label_1be020:
    // 0x1be020: 0x440fff2  bltz        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1BE020u;
    {
        const bool branch_taken_0x1be020 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BE024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE020u;
            // 0x1be024: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be020) {
            ctx->pc = 0x1BDFECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdfec;
        }
    }
    ctx->pc = 0x1BE028u;
    // 0x1be028: 0xae26002c  sw          $a2, 0x2C($s1)
    ctx->pc = 0x1be028u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 6));
    // 0x1be02c: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1be02cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1be030: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1be030u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1be034: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1be034u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1be038: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1BE038u;
    {
        const bool branch_taken_0x1be038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE038u;
            // 0x1be03c: 0xae200030  sw          $zero, 0x30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be038) {
            ctx->pc = 0x1BE178u;
            goto label_1be178;
        }
    }
    ctx->pc = 0x1BE040u;
label_1be040:
    // 0x1be040: 0x8e270024  lw          $a3, 0x24($s1)
    ctx->pc = 0x1be040u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1be044: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1be044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1be048: 0x8e240028  lw          $a0, 0x28($s1)
    ctx->pc = 0x1be048u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x1be04c: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1be04cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1be050: 0x8e260014  lw          $a2, 0x14($s1)
    ctx->pc = 0x1be050u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1be054: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x1be054u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1be058: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1be058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1be05c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1be05cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1be060: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1BE060u;
    SET_GPR_U32(ctx, 31, 0x1BE068u);
    ctx->pc = 0x1BE064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE060u;
            // 0x1be064: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE068u; }
        if (ctx->pc != 0x1BE068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE068u; }
        if (ctx->pc != 0x1BE068u) { return; }
    }
    ctx->pc = 0x1BE068u;
label_1be068:
    // 0x1be068: 0x440ffe0  bltz        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x1BE068u;
    {
        const bool branch_taken_0x1be068 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BE06Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE068u;
            // 0x1be06c: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be068) {
            ctx->pc = 0x1BDFECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdfec;
        }
    }
    ctx->pc = 0x1BE070u;
    // 0x1be070: 0x8e24002c  lw          $a0, 0x2C($s1)
    ctx->pc = 0x1be070u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x1be074: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1be074u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1be078: 0xc0464c4  jal         func_119310
    ctx->pc = 0x1BE078u;
    SET_GPR_U32(ctx, 31, 0x1BE080u);
    ctx->pc = 0x1BE07Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE078u;
            // 0x1be07c: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119310u;
    if (runtime->hasFunction(0x119310u)) {
        auto targetFn = runtime->lookupFunction(0x119310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE080u; }
        if (ctx->pc != 0x1BE080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119310_0x119310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE080u; }
        if (ctx->pc != 0x1BE080u) { return; }
    }
    ctx->pc = 0x1BE080u;
label_1be080:
    // 0x1be080: 0x440ffda  bltz        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x1BE080u;
    {
        const bool branch_taken_0x1be080 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BE084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE080u;
            // 0x1be084: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be080) {
            ctx->pc = 0x1BDFECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdfec;
        }
    }
    ctx->pc = 0x1BE088u;
    // 0x1be088: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x1be088u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x1be08c: 0x3c0342c8  lui         $v1, 0x42C8
    ctx->pc = 0x1be08cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17096 << 16));
    // 0x1be090: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1be090u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1be094: 0x921821  addu        $v1, $a0, $s2
    ctx->pc = 0x1be094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1be098: 0xae230030  sw          $v1, 0x30($s1)
    ctx->pc = 0x1be098u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 3));
    // 0x1be09c: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x1be09cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1be0a0: 0x721821  addu        $v1, $v1, $s2
    ctx->pc = 0x1be0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1be0a4: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x1be0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
    // 0x1be0a8: 0xc6210034  lwc1        $f1, 0x34($s1)
    ctx->pc = 0x1be0a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1be0ac: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x1be0acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1be0b0: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1be0b0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1be0b4: 0x31a40  sll         $v1, $v1, 9
    ctx->pc = 0x1be0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 9));
    // 0x1be0b8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1be0b8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1be0bc: 0x0  nop
    ctx->pc = 0x1be0bcu;
    // NOP
    // 0x1be0c0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1be0c0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1be0c4: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1be0c4u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1be0c8: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1be0c8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1be0cc: 0xe6200038  swc1        $f0, 0x38($s1)
    ctx->pc = 0x1be0ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 56), bits); }
    // 0x1be0d0: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1be0d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1be0d4: 0x8e230030  lw          $v1, 0x30($s1)
    ctx->pc = 0x1be0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x1be0d8: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x1be0d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1be0dc: 0x14600026  bnez        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x1BE0DCu;
    {
        const bool branch_taken_0x1be0dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1be0dc) {
            ctx->pc = 0x1BE178u;
            goto label_1be178;
        }
    }
    ctx->pc = 0x1BE0E4u;
    // 0x1be0e4: 0xae040008  sw          $a0, 0x8($s0)
    ctx->pc = 0x1be0e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 4));
    // 0x1be0e8: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1be0e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1be0ec: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x1be0ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1be0f0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1be0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1be0f4: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1be0f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1be0f8: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x1be0f8u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1be0fc: 0x0  nop
    ctx->pc = 0x1be0fcu;
    // NOP
    // 0x1be100: 0x0  nop
    ctx->pc = 0x1be100u;
    // NOP
    // 0x1be104: 0x1812  mflo        $v1
    ctx->pc = 0x1be104u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1be108: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1be108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1be10c: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x1be10cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
    // 0x1be110: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1be110u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1be114: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1be114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1be118: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1BE118u;
    {
        const bool branch_taken_0x1be118 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE11Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE118u;
            // 0x1be11c: 0xae230004  sw          $v1, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be118) {
            ctx->pc = 0x1BE178u;
            goto label_1be178;
        }
    }
    ctx->pc = 0x1BE120u;
label_1be120:
    // 0x1be120: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BE120u;
    SET_GPR_U32(ctx, 31, 0x1BE128u);
    ctx->pc = 0x1BE124u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE120u;
            // 0x1be124: 0x8e240028  lw          $a0, 0x28($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE128u; }
        if (ctx->pc != 0x1BE128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE128u; }
        if (ctx->pc != 0x1BE128u) { return; }
    }
    ctx->pc = 0x1BE128u;
label_1be128:
    // 0x1be128: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BE128u;
    SET_GPR_U32(ctx, 31, 0x1BE130u);
    ctx->pc = 0x1BE12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE128u;
            // 0x1be12c: 0x8e24002c  lw          $a0, 0x2C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE130u; }
        if (ctx->pc != 0x1BE130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE130u; }
        if (ctx->pc != 0x1BE130u) { return; }
    }
    ctx->pc = 0x1BE130u;
label_1be130:
    // 0x1be130: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x1be130u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x1be134: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x1be134u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x1be138: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1be138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1be13c: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x1be13cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1be140: 0xae240024  sw          $a0, 0x24($s1)
    ctx->pc = 0x1be140u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 4));
    // 0x1be144: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x1be144u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1be148: 0x83082a  slt         $at, $a0, $v1
    ctx->pc = 0x1be148u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1be14c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE14Cu;
    {
        const bool branch_taken_0x1be14c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be14c) {
            ctx->pc = 0x1BE15Cu;
            goto label_1be15c;
        }
    }
    ctx->pc = 0x1BE154u;
    // 0x1be154: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BE154u;
    {
        const bool branch_taken_0x1be154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE154u;
            // 0x1be158: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be154) {
            ctx->pc = 0x1BE178u;
            goto label_1be178;
        }
    }
    ctx->pc = 0x1BE15Cu;
label_1be15c:
    // 0x1be15c: 0xc06f900  jal         func_1BE400
    ctx->pc = 0x1BE15Cu;
    SET_GPR_U32(ctx, 31, 0x1BE164u);
    ctx->pc = 0x1BE400u;
    if (runtime->hasFunction(0x1BE400u)) {
        auto targetFn = runtime->lookupFunction(0x1BE400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE164u; }
        if (ctx->pc != 0x1BE164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE400_0x1be400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE164u; }
        if (ctx->pc != 0x1BE164u) { return; }
    }
    ctx->pc = 0x1BE164u;
label_1be164:
    // 0x1be164: 0x440ffa1  bltz        $v0, . + 4 + (-0x5F << 2)
    ctx->pc = 0x1BE164u;
    {
        const bool branch_taken_0x1be164 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BE168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE164u;
            // 0x1be168: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be164) {
            ctx->pc = 0x1BDFECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdfec;
        }
    }
    ctx->pc = 0x1BE16Cu;
    // 0x1be16c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1be16cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1be170: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1be170u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1be174: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1be174u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1be178:
    // 0x1be178: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1be178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1be17c:
    // 0x1be17c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1be17cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1be180: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1be180u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be184: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be184u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be188: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE188u;
            // 0x1be18c: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDFB0u: goto label_1bdfb0;
            case 0x1BDFD4u: goto label_1bdfd4;
            case 0x1BDFE4u: goto label_1bdfe4;
            case 0x1BDFECu: goto label_1bdfec;
            case 0x1BDFF8u: goto label_1bdff8;
            case 0x1BE000u: goto label_1be000;
            case 0x1BE010u: goto label_1be010;
            case 0x1BE020u: goto label_1be020;
            case 0x1BE040u: goto label_1be040;
            case 0x1BE068u: goto label_1be068;
            case 0x1BE080u: goto label_1be080;
            case 0x1BE120u: goto label_1be120;
            case 0x1BE128u: goto label_1be128;
            case 0x1BE130u: goto label_1be130;
            case 0x1BE15Cu: goto label_1be15c;
            case 0x1BE164u: goto label_1be164;
            case 0x1BE178u: goto label_1be178;
            case 0x1BE17Cu: goto label_1be17c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE190u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
