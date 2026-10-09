#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135078
// Address: 0x135078 - 0x135200
void sub_00135078_0x135078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135078_0x135078");
#endif

    switch (ctx->pc) {
        case 0x1350e8u: goto label_1350e8;
        case 0x135128u: goto label_135128;
        case 0x135150u: goto label_135150;
        case 0x135198u: goto label_135198;
        case 0x1351acu: goto label_1351ac;
        case 0x1351f0u: goto label_1351f0;
        default: break;
    }

    ctx->pc = 0x135078u;

label_135078:
    // 0x135078: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x135078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13507c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x13507cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x135080: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x135080u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135084: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x135084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x135088: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x135088u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13508c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x13508cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x135090: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x135090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x135094: 0x14710004  bne         $v1, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x135094u;
    {
        const bool branch_taken_0x135094 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 17));
        ctx->pc = 0x135098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135094u;
            // 0x135098: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135094) {
            ctx->pc = 0x1350A8u;
            goto label_1350a8;
        }
    }
    ctx->pc = 0x13509Cu;
    // 0x13509c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x13509cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1350a0: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x1350a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x1350a4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1350a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1350a8:
    // 0x1350a8: 0x5462002c  bnel        $v1, $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1350A8u;
    {
        const bool branch_taken_0x1350a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1350a8) {
            ctx->pc = 0x1350ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1350A8u;
            // 0x1350ac: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13515Cu;
            goto label_13515c;
        }
    }
    ctx->pc = 0x1350B0u;
    // 0x1350b0: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1350b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1350b4: 0x5451000e  bnel        $v0, $s1, . + 4 + (0xE << 2)
    ctx->pc = 0x1350B4u;
    {
        const bool branch_taken_0x1350b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x1350b4) {
            ctx->pc = 0x1350B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1350B4u;
            // 0x1350b8: 0x86030036  lh          $v1, 0x36($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 54)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1350F0u;
            goto label_1350f0;
        }
    }
    ctx->pc = 0x1350BCu;
    // 0x1350bc: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x1350bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1350c0: 0x26070028  addiu       $a3, $s0, 0x28
    ctx->pc = 0x1350c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x1350c4: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1350c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1350c8: 0x260a0034  addiu       $t2, $s0, 0x34
    ctx->pc = 0x1350c8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 52));
    // 0x1350cc: 0x8e060020  lw          $a2, 0x20($s0)
    ctx->pc = 0x1350ccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1350d0: 0x86080030  lh          $t0, 0x30($s0)
    ctx->pc = 0x1350d0u;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1350d4: 0x86090032  lh          $t1, 0x32($s0)
    ctx->pc = 0x1350d4u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 50)));
    // 0x1350d8: 0x860b0036  lh          $t3, 0x36($s0)
    ctx->pc = 0x1350d8u;
    SET_GPR_S32(ctx, 11, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 54)));
    // 0x1350dc: 0x86020038  lh          $v0, 0x38($s0)
    ctx->pc = 0x1350dcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1350e0: 0xc049db6  jal         func_1276D8
    ctx->pc = 0x1350E0u;
    SET_GPR_U32(ctx, 31, 0x1350E8u);
    ctx->pc = 0x1350E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1350E0u;
            // 0x1350e4: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1276D8u;
    if (runtime->hasFunction(0x1276D8u)) {
        auto targetFn = runtime->lookupFunction(0x1276D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1350E8u; }
        if (ctx->pc != 0x1350E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001276D8_0x1276d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1350E8u; }
        if (ctx->pc != 0x1350E8u) { return; }
    }
    ctx->pc = 0x1350E8u;
label_1350e8:
    // 0x1350e8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1350E8u;
    {
        const bool branch_taken_0x1350e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1350ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1350E8u;
            // 0x1350ec: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1350e8) {
            ctx->pc = 0x135150u;
            goto label_135150;
        }
    }
    ctx->pc = 0x1350F0u;
label_1350f0:
    // 0x1350f0: 0x260c0034  addiu       $t4, $s0, 0x34
    ctx->pc = 0x1350f0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 16), 52));
    // 0x1350f4: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x1350f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1350f8: 0x26070028  addiu       $a3, $s0, 0x28
    ctx->pc = 0x1350f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x1350fc: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1350fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x135100: 0x2609002c  addiu       $t1, $s0, 0x2C
    ctx->pc = 0x135100u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x135104: 0x8e060020  lw          $a2, 0x20($s0)
    ctx->pc = 0x135104u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x135108: 0x8e080024  lw          $t0, 0x24($s0)
    ctx->pc = 0x135108u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13510c: 0x860a0030  lh          $t2, 0x30($s0)
    ctx->pc = 0x13510cu;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x135110: 0x860b0032  lh          $t3, 0x32($s0)
    ctx->pc = 0x135110u;
    SET_GPR_S32(ctx, 11, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 50)));
    // 0x135114: 0x86020038  lh          $v0, 0x38($s0)
    ctx->pc = 0x135114u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x135118: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x135118u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x13511c: 0xafac0000  sw          $t4, 0x0($sp)
    ctx->pc = 0x13511cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 12));
    // 0x135120: 0xc049ff2  jal         func_127FC8
    ctx->pc = 0x135120u;
    SET_GPR_U32(ctx, 31, 0x135128u);
    ctx->pc = 0x135124u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135120u;
            // 0x135124: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x127FC8u;
    if (runtime->hasFunction(0x127FC8u)) {
        auto targetFn = runtime->lookupFunction(0x127FC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135128u; }
        if (ctx->pc != 0x135128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00127FC8_0x127fc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135128u; }
        if (ctx->pc != 0x135128u) { return; }
    }
    ctx->pc = 0x135128u;
label_135128:
    // 0x135128: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x135128u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x13512c: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x13512cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x135130: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x135130u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x135134: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x135134u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x135138: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x135138u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x13513c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13513cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x135140: 0x14510004  bne         $v0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x135140u;
    {
        const bool branch_taken_0x135140 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x135144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135140u;
            // 0x135144: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135140) {
            ctx->pc = 0x135154u;
            goto label_135154;
        }
    }
    ctx->pc = 0x135148u;
    // 0x135148: 0xc04d41a  jal         func_135068
    ctx->pc = 0x135148u;
    SET_GPR_U32(ctx, 31, 0x135150u);
    ctx->pc = 0x135068u;
    if (runtime->hasFunction(0x135068u)) {
        auto targetFn = runtime->lookupFunction(0x135068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135150u; }
        if (ctx->pc != 0x135150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135068_0x135068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135150u; }
        if (ctx->pc != 0x135150u) { return; }
    }
    ctx->pc = 0x135150u;
label_135150:
    // 0x135150: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x135150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_135154:
    // 0x135154: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x135154u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x135158: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x135158u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_13515c:
    // 0x13515c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x13515cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x135160: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x135160u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x135164: 0x3e00008  jr          $ra
    ctx->pc = 0x135164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135164u;
            // 0x135168: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135078u: goto label_135078;
            case 0x1350A8u: goto label_1350a8;
            case 0x1350E8u: goto label_1350e8;
            case 0x1350F0u: goto label_1350f0;
            case 0x135128u: goto label_135128;
            case 0x135150u: goto label_135150;
            case 0x135154u: goto label_135154;
            case 0x13515Cu: goto label_13515c;
            case 0x135198u: goto label_135198;
            case 0x1351ACu: goto label_1351ac;
            case 0x1351B0u: goto label_1351b0;
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13516Cu;
    // 0x13516c: 0x0  nop
    ctx->pc = 0x13516cu;
    // NOP
    // 0x135170: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135174: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x135174u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x135178: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x135178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13517c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13517cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135180: 0x2450b7b8  addiu       $s0, $v0, -0x4848
    ctx->pc = 0x135180u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948792));
    // 0x135184: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135188: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x135188u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13518c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13518cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135190: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x135190u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x135194: 0x0  nop
    ctx->pc = 0x135194u;
    // NOP
label_135198:
    // 0x135198: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x135198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13519c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13519Cu;
    {
        const bool branch_taken_0x13519c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13519c) {
            ctx->pc = 0x1351A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13519Cu;
            // 0x1351a0: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1351B0u;
            goto label_1351b0;
        }
    }
    ctx->pc = 0x1351A4u;
    // 0x1351a4: 0xc04d41e  jal         func_135078
    ctx->pc = 0x1351A4u;
    SET_GPR_U32(ctx, 31, 0x1351ACu);
    ctx->pc = 0x1351A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1351A4u;
            // 0x1351a8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135078u;
    goto label_135078;
    ctx->pc = 0x1351ACu;
label_1351ac:
    // 0x1351ac: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1351acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1351b0:
    // 0x1351b0: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1351B0u;
    {
        const bool branch_taken_0x1351b0 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1351B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351B0u;
            // 0x1351b4: 0x2610003c  addiu       $s0, $s0, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1351b0) {
            ctx->pc = 0x135198u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135198;
        }
    }
    ctx->pc = 0x1351B8u;
    // 0x1351b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1351b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1351bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1351bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1351c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1351c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1351c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1351c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1351c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1351C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1351CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351C8u;
            // 0x1351cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135078u: goto label_135078;
            case 0x1350A8u: goto label_1350a8;
            case 0x1350E8u: goto label_1350e8;
            case 0x1350F0u: goto label_1350f0;
            case 0x135128u: goto label_135128;
            case 0x135150u: goto label_135150;
            case 0x135154u: goto label_135154;
            case 0x13515Cu: goto label_13515c;
            case 0x135198u: goto label_135198;
            case 0x1351ACu: goto label_1351ac;
            case 0x1351B0u: goto label_1351b0;
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1351D0u;
    // 0x1351d0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1351d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1351d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1351d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1351d8: 0x8c43bb7c  lw          $v1, -0x4484($v0)
    ctx->pc = 0x1351d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949756)));
    // 0x1351dc: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1351DCu;
    {
        const bool branch_taken_0x1351dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1351E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351DCu;
            // 0x1351e0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1351dc) {
            ctx->pc = 0x1351F0u;
            goto label_1351f0;
        }
    }
    ctx->pc = 0x1351E4u;
    // 0x1351e4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1351e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1351e8: 0x60f809  jalr        $v1
    ctx->pc = 0x1351E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1351F0u);
        ctx->pc = 0x1351ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351E8u;
            // 0x1351ec: 0x8c44bb80  lw          $a0, -0x4480($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949760)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1351F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135078u: goto label_135078;
            case 0x1350A8u: goto label_1350a8;
            case 0x1350E8u: goto label_1350e8;
            case 0x1350F0u: goto label_1350f0;
            case 0x135128u: goto label_135128;
            case 0x135150u: goto label_135150;
            case 0x135154u: goto label_135154;
            case 0x13515Cu: goto label_13515c;
            case 0x135198u: goto label_135198;
            case 0x1351ACu: goto label_1351ac;
            case 0x1351B0u: goto label_1351b0;
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1351F0u; }
            if (ctx->pc != 0x1351F0u) { return; }
        }
        }
    }
    ctx->pc = 0x1351F0u;
label_1351f0:
    // 0x1351f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1351f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1351f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1351F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1351F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351F4u;
            // 0x1351f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135078u: goto label_135078;
            case 0x1350A8u: goto label_1350a8;
            case 0x1350E8u: goto label_1350e8;
            case 0x1350F0u: goto label_1350f0;
            case 0x135128u: goto label_135128;
            case 0x135150u: goto label_135150;
            case 0x135154u: goto label_135154;
            case 0x13515Cu: goto label_13515c;
            case 0x135198u: goto label_135198;
            case 0x1351ACu: goto label_1351ac;
            case 0x1351B0u: goto label_1351b0;
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1351FCu;
    // 0x1351fc: 0x0  nop
    ctx->pc = 0x1351fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
