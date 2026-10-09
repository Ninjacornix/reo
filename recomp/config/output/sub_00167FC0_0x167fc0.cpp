#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167FC0
// Address: 0x167fc0 - 0x1681e8
void sub_00167FC0_0x167fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167FC0_0x167fc0");
#endif

    switch (ctx->pc) {
        case 0x167ff4u: goto label_167ff4;
        case 0x168068u: goto label_168068;
        case 0x1680d0u: goto label_1680d0;
        case 0x1680e4u: goto label_1680e4;
        case 0x16810cu: goto label_16810c;
        case 0x168134u: goto label_168134;
        case 0x168140u: goto label_168140;
        case 0x168180u: goto label_168180;
        case 0x1681b4u: goto label_1681b4;
        default: break;
    }

    ctx->pc = 0x167fc0u;

    // 0x167fc0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x167fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167fc4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167fc8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x167fc8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167fcc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167fd0: 0x26500cc0  addiu       $s0, $s2, 0xCC0
    ctx->pc = 0x167fd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 3264));
    // 0x167fd4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167fd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167fd8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167fdc: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167fe0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x167fe0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167fe4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x167fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x167fe8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x167fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x167fec: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167FECu;
    SET_GPR_U32(ctx, 31, 0x167FF4u);
    ctx->pc = 0x167FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167FECu;
            // 0x167ff0: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167FF4u; }
        if (ctx->pc != 0x167FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167FF4u; }
        if (ctx->pc != 0x167FF4u) { return; }
    }
    ctx->pc = 0x167FF4u;
label_167ff4:
    // 0x167ff4: 0x8e0301b4  lw          $v1, 0x1B4($s0)
    ctx->pc = 0x167ff4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x167ff8: 0x8e0201b0  lw          $v0, 0x1B0($s0)
    ctx->pc = 0x167ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 432)));
    // 0x167ffc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x167ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168000: 0x1c400005  bgtz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x168000u;
    {
        const bool branch_taken_0x168000 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x168004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168000u;
            // 0x168004: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168000) {
            ctx->pc = 0x168018u;
            goto label_168018;
        }
    }
    ctx->pc = 0x168008u;
    // 0x168008: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x168008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16800c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x16800cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168010: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x168010u;
    {
        const bool branch_taken_0x168010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168010u;
            // 0x168014: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168010) {
            ctx->pc = 0x168060u;
            goto label_168060;
        }
    }
    ctx->pc = 0x168018u;
label_168018:
    // 0x168018: 0x8e0201a8  lw          $v0, 0x1A8($s0)
    ctx->pc = 0x168018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 424)));
    // 0x16801c: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x16801cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x168020: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x168020u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x168024: 0x8e0301b4  lw          $v1, 0x1B4($s0)
    ctx->pc = 0x168024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x168028: 0x28650000  slti        $a1, $v1, 0x0
    ctx->pc = 0x168028u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16802c: 0x2466001f  addiu       $a2, $v1, 0x1F
    ctx->pc = 0x16802cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 31));
    // 0x168030: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x168030u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168034: 0xc5100b  movn        $v0, $a2, $a1
    ctx->pc = 0x168034u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x168038: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x168038u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x16803c: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x16803cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x168040: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x168040u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x168044: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x168044u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x168048: 0x721821  addu        $v1, $v1, $s2
    ctx->pc = 0x168048u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x16804c: 0x8c650e78  lw          $a1, 0xE78($v1)
    ctx->pc = 0x16804cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 3704)));
    // 0x168050: 0xae650000  sw          $a1, 0x0($s3)
    ctx->pc = 0x168050u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 5));
    // 0x168054: 0x8e0201b4  lw          $v0, 0x1B4($s0)
    ctx->pc = 0x168054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x168058: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x168058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16805c: 0xae0201b4  sw          $v0, 0x1B4($s0)
    ctx->pc = 0x16805cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 436), GPR_U32(ctx, 2));
label_168060:
    // 0x168060: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x168060u;
    SET_GPR_U32(ctx, 31, 0x168068u);
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168068u; }
        if (ctx->pc != 0x168068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168068u; }
        if (ctx->pc != 0x168068u) { return; }
    }
    ctx->pc = 0x168068u;
label_168068:
    // 0x168068: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x168068u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16806c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16806cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168070: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x168070u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168074: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x168074u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168078: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x168078u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16807c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16807cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x168080: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x168080u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x168084: 0x3e00008  jr          $ra
    ctx->pc = 0x168084u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168084u;
            // 0x168088: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167FF4u: goto label_167ff4;
            case 0x168018u: goto label_168018;
            case 0x168060u: goto label_168060;
            case 0x168068u: goto label_168068;
            case 0x1680D0u: goto label_1680d0;
            case 0x1680E4u: goto label_1680e4;
            case 0x1680F0u: goto label_1680f0;
            case 0x16810Cu: goto label_16810c;
            case 0x168134u: goto label_168134;
            case 0x168140u: goto label_168140;
            case 0x168180u: goto label_168180;
            case 0x168194u: goto label_168194;
            case 0x1681B4u: goto label_1681b4;
            case 0x1681B8u: goto label_1681b8;
            case 0x1681BCu: goto label_1681bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16808Cu;
    // 0x16808c: 0x0  nop
    ctx->pc = 0x16808cu;
    // NOP
    // 0x168090: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x168090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x168094: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x168094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x168098: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x168098u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16809c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16809cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1680a0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1680a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1680a4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1680a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1680a8: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1680a8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1680ac: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x1680acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x1680b0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1680b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1680b4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1680b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1680b8: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x1680b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x1680bc: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x1680bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x1680c0: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x1680c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x1680c4: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x1680c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1680c8: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1680C8u;
    SET_GPR_U32(ctx, 31, 0x1680D0u);
    ctx->pc = 0x1680CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1680C8u;
            // 0x1680cc: 0xe0b82d  daddu       $s7, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1680D0u; }
        if (ctx->pc != 0x1680D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1680D0u; }
        if (ctx->pc != 0x1680D0u) { return; }
    }
    ctx->pc = 0x1680D0u;
label_1680d0:
    // 0x1680d0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1680D0u;
    {
        const bool branch_taken_0x1680d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1680D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1680D0u;
            // 0x1680d4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1680d0) {
            ctx->pc = 0x1680F0u;
            goto label_1680f0;
        }
    }
    ctx->pc = 0x1680D8u;
    // 0x1680d8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1680d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1680dc: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1680DCu;
    SET_GPR_U32(ctx, 31, 0x1680E4u);
    ctx->pc = 0x1680E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1680DCu;
            // 0x1680e0: 0x34a50162  ori         $a1, $a1, 0x162 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)354);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1680E4u; }
        if (ctx->pc != 0x1680E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1680E4u; }
        if (ctx->pc != 0x1680E4u) { return; }
    }
    ctx->pc = 0x1680E4u;
label_1680e4:
    // 0x1680e4: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1680E4u;
    {
        const bool branch_taken_0x1680e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1680E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1680E4u;
            // 0x1680e8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1680e4) {
            ctx->pc = 0x1681BCu;
            goto label_1681bc;
        }
    }
    ctx->pc = 0x1680ECu;
    // 0x1680ec: 0x0  nop
    ctx->pc = 0x1680ecu;
    // NOP
label_1680f0:
    // 0x1680f0: 0x8e160dc8  lw          $s6, 0xDC8($s0)
    ctx->pc = 0x1680f0u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3528)));
    // 0x1680f4: 0x26110cc0  addiu       $s1, $s0, 0xCC0
    ctx->pc = 0x1680f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x1680f8: 0xaee00000  sw          $zero, 0x0($s7)
    ctx->pc = 0x1680f8u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 0));
    // 0x1680fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1680fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168100: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x168100u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168104: 0xc05d884  jal         func_176210
    ctx->pc = 0x168104u;
    SET_GPR_U32(ctx, 31, 0x16810Cu);
    ctx->pc = 0x168108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168104u;
            // 0x168108: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176210u;
    if (runtime->hasFunction(0x176210u)) {
        auto targetFn = runtime->lookupFunction(0x176210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16810Cu; }
        if (ctx->pc != 0x16810Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176210_0x176210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16810Cu; }
        if (ctx->pc != 0x16810Cu) { return; }
    }
    ctx->pc = 0x16810Cu;
label_16810c:
    // 0x16810c: 0x8e230120  lw          $v1, 0x120($s1)
    ctx->pc = 0x16810cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x168110: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x168110u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168114: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x168114u;
    {
        const bool branch_taken_0x168114 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x168118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168114u;
            // 0x168118: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168114) {
            ctx->pc = 0x1681B8u;
            goto label_1681b8;
        }
    }
    ctx->pc = 0x16811Cu;
    // 0x16811c: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x16811cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x168120: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x168120u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x168124: 0x10830024  beq         $a0, $v1, . + 4 + (0x24 << 2)
    ctx->pc = 0x168124u;
    {
        const bool branch_taken_0x168124 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x168128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168124u;
            // 0x168128: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168124) {
            ctx->pc = 0x1681B8u;
            goto label_1681b8;
        }
    }
    ctx->pc = 0x16812Cu;
    // 0x16812c: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x16812Cu;
    SET_GPR_U32(ctx, 31, 0x168134u);
    ctx->pc = 0x168130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16812Cu;
            // 0x168130: 0x26150cc8  addiu       $s5, $s0, 0xCC8 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 16), 3272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168134u; }
        if (ctx->pc != 0x168134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168134u; }
        if (ctx->pc != 0x168134u) { return; }
    }
    ctx->pc = 0x168134u;
label_168134:
    // 0x168134: 0x8e300124  lw          $s0, 0x124($s1)
    ctx->pc = 0x168134u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 292)));
    // 0x168138: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x168138u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16813c: 0x0  nop
    ctx->pc = 0x16813cu;
    // NOP
label_168140:
    // 0x168140: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x168140u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x168144: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x168144u;
    {
        const bool branch_taken_0x168144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168144u;
            // 0x168148: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168144) {
            ctx->pc = 0x168194u;
            goto label_168194;
        }
    }
    ctx->pc = 0x16814Cu;
    // 0x16814c: 0x2604001f  addiu       $a0, $s0, 0x1F
    ctx->pc = 0x16814cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 31));
    // 0x168150: 0x2a030000  slti        $v1, $s0, 0x0
    ctx->pc = 0x168150u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x168154: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x168154u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168158: 0x8e850000  lw          $a1, 0x0($s4)
    ctx->pc = 0x168158u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x16815c: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x16815cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x168160: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x168160u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168164: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x168164u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x168168: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x168168u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x16816c: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x16816cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x168170: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x168170u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x168174: 0x551021  addu        $v0, $v0, $s5
    ctx->pc = 0x168174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x168178: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x168178u;
    SET_GPR_U32(ctx, 31, 0x168180u);
    ctx->pc = 0x16817Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168178u;
            // 0x16817c: 0x8c440120  lw          $a0, 0x120($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 288)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168180u; }
        if (ctx->pc != 0x168180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168180u; }
        if (ctx->pc != 0x168180u) { return; }
    }
    ctx->pc = 0x168180u;
label_168180:
    // 0x168180: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x168180u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168184: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x168184u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x168188: 0x52102a  slt         $v0, $v0, $s2
    ctx->pc = 0x168188u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x16818c: 0x5440ffec  bnel        $v0, $zero, . + 4 + (-0x14 << 2)
    ctx->pc = 0x16818Cu;
    {
        const bool branch_taken_0x16818c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16818c) {
            ctx->pc = 0x168190u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16818Cu;
            // 0x168190: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168140u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_168140;
        }
    }
    ctx->pc = 0x168194u;
label_168194:
    // 0x168194: 0xaef00000  sw          $s0, 0x0($s7)
    ctx->pc = 0x168194u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 16));
    // 0x168198: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x168198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16819c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x16819cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1681a0: 0x521023  subu        $v0, $v0, $s2
    ctx->pc = 0x1681a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1681a4: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1681a4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1681a8: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x1681a8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1681ac: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1681ACu;
    SET_GPR_U32(ctx, 31, 0x1681B4u);
    ctx->pc = 0x1681B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1681ACu;
            // 0x1681b0: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1681B4u; }
        if (ctx->pc != 0x1681B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1681B4u; }
        if (ctx->pc != 0x1681B4u) { return; }
    }
    ctx->pc = 0x1681B4u;
label_1681b4:
    // 0x1681b4: 0x3c0102d  daddu       $v0, $fp, $zero
    ctx->pc = 0x1681b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_1681b8:
    // 0x1681b8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1681b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1681bc:
    // 0x1681bc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1681bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1681c0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1681c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1681c4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1681c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1681c8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1681c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1681cc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1681ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1681d0: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x1681d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1681d4: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x1681d4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1681d8: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x1681d8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1681dc: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x1681dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1681e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1681E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1681E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1681E0u;
            // 0x1681e4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167FF4u: goto label_167ff4;
            case 0x168018u: goto label_168018;
            case 0x168060u: goto label_168060;
            case 0x168068u: goto label_168068;
            case 0x1680D0u: goto label_1680d0;
            case 0x1680E4u: goto label_1680e4;
            case 0x1680F0u: goto label_1680f0;
            case 0x16810Cu: goto label_16810c;
            case 0x168134u: goto label_168134;
            case 0x168140u: goto label_168140;
            case 0x168180u: goto label_168180;
            case 0x168194u: goto label_168194;
            case 0x1681B4u: goto label_1681b4;
            case 0x1681B8u: goto label_1681b8;
            case 0x1681BCu: goto label_1681bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1681E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
