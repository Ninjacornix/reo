#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DF50
// Address: 0x12df50 - 0x12e138
void sub_0012DF50_0x12df50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DF50_0x12df50");
#endif

    switch (ctx->pc) {
        case 0x12df9cu: goto label_12df9c;
        case 0x12dfc4u: goto label_12dfc4;
        case 0x12dff0u: goto label_12dff0;
        case 0x12e058u: goto label_12e058;
        case 0x12e0a4u: goto label_12e0a4;
        case 0x12e0b0u: goto label_12e0b0;
        case 0x12e0e8u: goto label_12e0e8;
        default: break;
    }

    ctx->pc = 0x12df50u;

    // 0x12df50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12df50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12df54: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12df54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12df58: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12df58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12df5c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12df5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df60: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12df60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12df64: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x12df64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df68: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12df68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12df6c: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x12df6cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df70: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x12df70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x12df74: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x12df74u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df78: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12df78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12df7c: 0x2328018  mult        $s0, $s1, $s2
    ctx->pc = 0x12df7cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x12df80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12df80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df84: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x12df84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df88: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x12df88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12df8c: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x12df8cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df90: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12df90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12df94: 0x60f809  jalr        $v1
    ctx->pc = 0x12DF94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12DF9Cu);
        ctx->pc = 0x12DF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DF94u;
            // 0x12df98: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12DF9Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DF9Cu: goto label_12df9c;
            case 0x12DFC4u: goto label_12dfc4;
            case 0x12DFD0u: goto label_12dfd0;
            case 0x12DFF0u: goto label_12dff0;
            case 0x12E038u: goto label_12e038;
            case 0x12E058u: goto label_12e058;
            case 0x12E090u: goto label_12e090;
            case 0x12E0A4u: goto label_12e0a4;
            case 0x12E0B0u: goto label_12e0b0;
            case 0x12E0D0u: goto label_12e0d0;
            case 0x12E0D4u: goto label_12e0d4;
            case 0x12E0E8u: goto label_12e0e8;
            case 0x12E0ECu: goto label_12e0ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12DF9Cu; }
            if (ctx->pc != 0x12DF9Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12DF9Cu;
label_12df9c:
    // 0x12df9c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x12df9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12dfa0: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x12dfa0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12dfa4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x12DFA4u;
    {
        const bool branch_taken_0x12dfa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12DFA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DFA4u;
            // 0x12dfa8: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dfa4) {
            ctx->pc = 0x12DFD0u;
            goto label_12dfd0;
        }
    }
    ctx->pc = 0x12DFACu;
    // 0x12dfac: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x12dfacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12dfb0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x12dfb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dfb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12dfb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dfb8: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12dfb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12dfbc: 0x40f809  jalr        $v0
    ctx->pc = 0x12DFBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12DFC4u);
        ctx->pc = 0x12DFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DFBCu;
            // 0x12dfc0: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12DFC4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DF9Cu: goto label_12df9c;
            case 0x12DFC4u: goto label_12dfc4;
            case 0x12DFD0u: goto label_12dfd0;
            case 0x12DFF0u: goto label_12dff0;
            case 0x12E038u: goto label_12e038;
            case 0x12E058u: goto label_12e058;
            case 0x12E090u: goto label_12e090;
            case 0x12E0A4u: goto label_12e0a4;
            case 0x12E0B0u: goto label_12e0b0;
            case 0x12E0D0u: goto label_12e0d0;
            case 0x12E0D4u: goto label_12e0d4;
            case 0x12E0E8u: goto label_12e0e8;
            case 0x12E0ECu: goto label_12e0ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12DFC4u; }
            if (ctx->pc != 0x12DFC4u) { return; }
        }
        }
    }
    ctx->pc = 0x12DFC4u;
label_12dfc4:
    // 0x12dfc4: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x12DFC4u;
    {
        const bool branch_taken_0x12dfc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12DFC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DFC4u;
            // 0x12dfc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dfc4) {
            ctx->pc = 0x12E0ECu;
            goto label_12e0ec;
        }
    }
    ctx->pc = 0x12DFCCu;
    // 0x12dfcc: 0x0  nop
    ctx->pc = 0x12dfccu;
    // NOP
label_12dfd0:
    // 0x12dfd0: 0x16220019  bne         $s1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x12DFD0u;
    {
        const bool branch_taken_0x12dfd0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x12DFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DFD0u;
            // 0x12dfd4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dfd0) {
            ctx->pc = 0x12E038u;
            goto label_12e038;
        }
    }
    ctx->pc = 0x12DFD8u;
    // 0x12dfd8: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x12dfd8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dfdc: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x12dfdcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dfe0: 0x1a40003b  blez        $s2, . + 4 + (0x3B << 2)
    ctx->pc = 0x12DFE0u;
    {
        const bool branch_taken_0x12dfe0 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x12DFE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DFE0u;
            // 0x12dfe4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dfe0) {
            ctx->pc = 0x12E0D0u;
            goto label_12e0d0;
        }
    }
    ctx->pc = 0x12DFE8u;
    // 0x12dfe8: 0x3c0900ff  lui         $t1, 0xFF
    ctx->pc = 0x12dfe8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)255 << 16));
    // 0x12dfec: 0x0  nop
    ctx->pc = 0x12dfecu;
    // NOP
label_12dff0:
    // 0x12dff0: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x12dff0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12dff4: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x12dff4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x12dff8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12dff8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x12dffc: 0x42a03  sra         $a1, $a0, 8
    ctx->pc = 0x12dffcu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 8));
    // 0x12e000: 0x41a00  sll         $v1, $a0, 8
    ctx->pc = 0x12e000u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x12e004: 0x41602  srl         $v0, $a0, 24
    ctx->pc = 0x12e004u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x12e008: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x12e008u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x12e00c: 0x691824  and         $v1, $v1, $t1
    ctx->pc = 0x12e00cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 9));
    // 0x12e010: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x12e010u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x12e014: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x12e014u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x12e018: 0x112202a  slt         $a0, $t0, $s2
    ctx->pc = 0x12e018u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12e01c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x12e01cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x12e020: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x12e020u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12e024: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x12e024u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x12e028: 0x1480fff1  bnez        $a0, . + 4 + (-0xF << 2)
    ctx->pc = 0x12E028u;
    {
        const bool branch_taken_0x12e028 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E028u;
            // 0x12e02c: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e028) {
            ctx->pc = 0x12DFF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12dff0;
        }
    }
    ctx->pc = 0x12E030u;
    // 0x12e030: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x12E030u;
    {
        const bool branch_taken_0x12e030 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E030u;
            // 0x12e034: 0x8e830000  lw          $v1, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e030) {
            ctx->pc = 0x12E0D4u;
            goto label_12e0d4;
        }
    }
    ctx->pc = 0x12E038u;
label_12e038:
    // 0x12e038: 0x16220015  bne         $s1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12E038u;
    {
        const bool branch_taken_0x12e038 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x12E03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E038u;
            // 0x12e03c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e038) {
            ctx->pc = 0x12E090u;
            goto label_12e090;
        }
    }
    ctx->pc = 0x12E040u;
    // 0x12e040: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x12e040u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e044: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x12e044u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e048: 0x1a400021  blez        $s2, . + 4 + (0x21 << 2)
    ctx->pc = 0x12E048u;
    {
        const bool branch_taken_0x12e048 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x12E04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E048u;
            // 0x12e04c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e048) {
            ctx->pc = 0x12E0D0u;
            goto label_12e0d0;
        }
    }
    ctx->pc = 0x12E050u;
    // 0x12e050: 0x2407ff00  addiu       $a3, $zero, -0x100
    ctx->pc = 0x12e050u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x12e054: 0x0  nop
    ctx->pc = 0x12e054u;
    // NOP
label_12e058:
    // 0x12e058: 0x94a20000  lhu         $v0, 0x0($a1)
    ctx->pc = 0x12e058u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12e05c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12e05cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x12e060: 0x90a30001  lbu         $v1, 0x1($a1)
    ctx->pc = 0x12e060u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x12e064: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x12e064u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x12e068: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x12e068u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x12e06c: 0x112202a  slt         $a0, $t0, $s2
    ctx->pc = 0x12e06cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12e070: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x12e070u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x12e074: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x12e074u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12e078: 0xa4c30000  sh          $v1, 0x0($a2)
    ctx->pc = 0x12e078u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x12e07c: 0x1480fff6  bnez        $a0, . + 4 + (-0xA << 2)
    ctx->pc = 0x12E07Cu;
    {
        const bool branch_taken_0x12e07c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E07Cu;
            // 0x12e080: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e07c) {
            ctx->pc = 0x12E058u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e058;
        }
    }
    ctx->pc = 0x12E084u;
    // 0x12e084: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x12E084u;
    {
        const bool branch_taken_0x12e084 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E084u;
            // 0x12e088: 0x8e830000  lw          $v1, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e084) {
            ctx->pc = 0x12E0D4u;
            goto label_12e0d4;
        }
    }
    ctx->pc = 0x12E08Cu;
    // 0x12e08c: 0x0  nop
    ctx->pc = 0x12e08cu;
    // NOP
label_12e090:
    // 0x12e090: 0x16220007  bne         $s1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12E090u;
    {
        const bool branch_taken_0x12e090 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x12E094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E090u;
            // 0x12e094: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e090) {
            ctx->pc = 0x12E0B0u;
            goto label_12e0b0;
        }
    }
    ctx->pc = 0x12E098u;
    // 0x12e098: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x12e098u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e09c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x12E09Cu;
    SET_GPR_U32(ctx, 31, 0x12E0A4u);
    ctx->pc = 0x12E0A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E09Cu;
            // 0x12e0a0: 0x3246ffff  andi        $a2, $s2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E0A4u; }
        if (ctx->pc != 0x12E0A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E0A4u; }
        if (ctx->pc != 0x12E0A4u) { return; }
    }
    ctx->pc = 0x12E0A4u;
label_12e0a4:
    // 0x12e0a4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x12E0A4u;
    {
        const bool branch_taken_0x12e0a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E0A4u;
            // 0x12e0a8: 0x8e830000  lw          $v1, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e0a4) {
            ctx->pc = 0x12E0D4u;
            goto label_12e0d4;
        }
    }
    ctx->pc = 0x12E0ACu;
    // 0x12e0ac: 0x0  nop
    ctx->pc = 0x12e0acu;
    // NOP
label_12e0b0:
    // 0x12e0b0: 0x0  nop
    ctx->pc = 0x12e0b0u;
    // NOP
    // 0x12e0b4: 0x0  nop
    ctx->pc = 0x12e0b4u;
    // NOP
    // 0x12e0b8: 0x0  nop
    ctx->pc = 0x12e0b8u;
    // NOP
    // 0x12e0bc: 0x0  nop
    ctx->pc = 0x12e0bcu;
    // NOP
    // 0x12e0c0: 0x0  nop
    ctx->pc = 0x12e0c0u;
    // NOP
    // 0x12e0c4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x12E0C4u;
    {
        const bool branch_taken_0x12e0c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12e0c4) {
            ctx->pc = 0x12E0B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e0b0;
        }
    }
    ctx->pc = 0x12E0CCu;
    // 0x12e0cc: 0x0  nop
    ctx->pc = 0x12e0ccu;
    // NOP
label_12e0d0:
    // 0x12e0d0: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x12e0d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
label_12e0d4:
    // 0x12e0d4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x12e0d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e0d8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12e0d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12e0dc: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12e0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12e0e0: 0x40f809  jalr        $v0
    ctx->pc = 0x12E0E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12E0E8u);
        ctx->pc = 0x12E0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E0E0u;
            // 0x12e0e4: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12E0E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DF9Cu: goto label_12df9c;
            case 0x12DFC4u: goto label_12dfc4;
            case 0x12DFD0u: goto label_12dfd0;
            case 0x12DFF0u: goto label_12dff0;
            case 0x12E038u: goto label_12e038;
            case 0x12E058u: goto label_12e058;
            case 0x12E090u: goto label_12e090;
            case 0x12E0A4u: goto label_12e0a4;
            case 0x12E0B0u: goto label_12e0b0;
            case 0x12E0D0u: goto label_12e0d0;
            case 0x12E0D4u: goto label_12e0d4;
            case 0x12E0E8u: goto label_12e0e8;
            case 0x12E0ECu: goto label_12e0ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12E0E8u; }
            if (ctx->pc != 0x12E0E8u) { return; }
        }
        }
    }
    ctx->pc = 0x12E0E8u;
label_12e0e8:
    // 0x12e0e8: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x12e0e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_12e0ec:
    // 0x12e0ec: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12e0ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12e0f0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12e0f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12e0f4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12e0f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12e0f8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12e0f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12e0fc: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x12e0fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12e100: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12e100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12e104: 0x3e00008  jr          $ra
    ctx->pc = 0x12E104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E104u;
            // 0x12e108: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DF9Cu: goto label_12df9c;
            case 0x12DFC4u: goto label_12dfc4;
            case 0x12DFD0u: goto label_12dfd0;
            case 0x12DFF0u: goto label_12dff0;
            case 0x12E038u: goto label_12e038;
            case 0x12E058u: goto label_12e058;
            case 0x12E090u: goto label_12e090;
            case 0x12E0A4u: goto label_12e0a4;
            case 0x12E0B0u: goto label_12e0b0;
            case 0x12E0D0u: goto label_12e0d0;
            case 0x12E0D4u: goto label_12e0d4;
            case 0x12E0E8u: goto label_12e0e8;
            case 0x12E0ECu: goto label_12e0ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E10Cu;
    // 0x12e10c: 0x0  nop
    ctx->pc = 0x12e10cu;
    // NOP
    // 0x12e110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e114: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x12e114u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x12e118: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12e118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12e11c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e11cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e120: 0x24849ee0  addiu       $a0, $a0, -0x6120
    ctx->pc = 0x12e120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942432));
    // 0x12e124: 0x240600c0  addiu       $a2, $zero, 0xC0
    ctx->pc = 0x12e124u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x12e128: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e128u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e12c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12E12Cu;
    ctx->pc = 0x12E130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E12Cu;
            // 0x12e130: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12E134u;
    // 0x12e134: 0x0  nop
    ctx->pc = 0x12e134u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
