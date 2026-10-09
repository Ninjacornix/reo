#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012EBF0
// Address: 0x12ebf0 - 0x12edb0
void sub_0012EBF0_0x12ebf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012EBF0_0x12ebf0");
#endif

    switch (ctx->pc) {
        case 0x12ec58u: goto label_12ec58;
        case 0x12ec88u: goto label_12ec88;
        case 0x12eca4u: goto label_12eca4;
        case 0x12ed00u: goto label_12ed00;
        case 0x12ed08u: goto label_12ed08;
        case 0x12ed3cu: goto label_12ed3c;
        case 0x12ed68u: goto label_12ed68;
        default: break;
    }

    ctx->pc = 0x12ebf0u;

    // 0x12ebf0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x12ebf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x12ebf4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12ebf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12ebf8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12ebf8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ebfc: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12ebfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12ec00: 0x26080090  addiu       $t0, $s0, 0x90
    ctx->pc = 0x12ec00u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
    // 0x12ec04: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12ec04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12ec08: 0x260900d0  addiu       $t1, $s0, 0xD0
    ctx->pc = 0x12ec08u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 208));
    // 0x12ec0c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12ec0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12ec10: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x12ec10u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ec14: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12ec14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x12ec18: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x12ec18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x12ec1c: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x12ec1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x12ec20: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x12ec20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x12ec24: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x12ec24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x12ec28: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x12ec28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x12ec2c: 0xafa80000  sw          $t0, 0x0($sp)
    ctx->pc = 0x12ec2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
    // 0x12ec30: 0x8e020030  lw          $v0, 0x30($s0)
    ctx->pc = 0x12ec30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x12ec34: 0x8e03003c  lw          $v1, 0x3C($s0)
    ctx->pc = 0x12ec34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12ec38: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12ec38u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x12ec3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12ec3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ec40: 0x628823  subu        $s1, $v1, $v0
    ctx->pc = 0x12ec40u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12ec44: 0xafa90004  sw          $t1, 0x4($sp)
    ctx->pc = 0x12ec44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 9));
    // 0x12ec48: 0xd1102a  slt         $v0, $a2, $s1
    ctx->pc = 0x12ec48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x12ec4c: 0xc2880b  movn        $s1, $a2, $v0
    ctx->pc = 0x12ec4cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 6));
    // 0x12ec50: 0xc04b966  jal         func_12E598
    ctx->pc = 0x12EC50u;
    SET_GPR_U32(ctx, 31, 0x12EC58u);
    ctx->pc = 0x12EC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC50u;
            // 0x12ec54: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E598u;
    if (runtime->hasFunction(0x12E598u)) {
        auto targetFn = runtime->lookupFunction(0x12E598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EC58u; }
        if (ctx->pc != 0x12EC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E598_0x12e598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EC58u; }
        if (ctx->pc != 0x12EC58u) { return; }
    }
    ctx->pc = 0x12EC58u;
label_12ec58:
    // 0x12ec58: 0x5040004a  beql        $v0, $zero, . + 4 + (0x4A << 2)
    ctx->pc = 0x12EC58u;
    {
        const bool branch_taken_0x12ec58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ec58) {
            ctx->pc = 0x12EC5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC58u;
            // 0x12ec5c: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12ED84u;
            goto label_12ed84;
        }
    }
    ctx->pc = 0x12EC60u;
    // 0x12ec60: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12ec60u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x12ec64: 0x226102a  slt         $v0, $s1, $a2
    ctx->pc = 0x12ec64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x12ec68: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x12EC68u;
    {
        const bool branch_taken_0x12ec68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EC6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC68u;
            // 0x12ec6c: 0x8e030058  lw          $v1, 0x58($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ec68) {
            ctx->pc = 0x12ECC8u;
            goto label_12ecc8;
        }
    }
    ctx->pc = 0x12EC70u;
    // 0x12ec70: 0x18600015  blez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x12EC70u;
    {
        const bool branch_taken_0x12ec70 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12EC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC70u;
            // 0x12ec74: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ec70) {
            ctx->pc = 0x12ECC8u;
            goto label_12ecc8;
        }
    }
    ctx->pc = 0x12EC78u;
    // 0x12ec78: 0x11a040  sll         $s4, $s1, 1
    ctx->pc = 0x12ec78u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x12ec7c: 0x3a0902d  daddu       $s2, $sp, $zero
    ctx->pc = 0x12ec7cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ec80: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12ec80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12ec84: 0x0  nop
    ctx->pc = 0x12ec84u;
    // NOP
label_12ec88:
    // 0x12ec88: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x12ec88u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x12ec8c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12EC8Cu;
    {
        const bool branch_taken_0x12ec8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC8Cu;
            // 0x12ec90: 0x2822021  addu        $a0, $s4, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ec8c) {
            ctx->pc = 0x12ECACu;
            goto label_12ecac;
        }
    }
    ctx->pc = 0x12EC94u;
    // 0x12ec94: 0xd13023  subu        $a2, $a2, $s1
    ctx->pc = 0x12ec94u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x12ec98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12ec98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ec9c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12EC9Cu;
    SET_GPR_U32(ctx, 31, 0x12ECA4u);
    ctx->pc = 0x12ECA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EC9Cu;
            // 0x12eca0: 0x63040  sll         $a2, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ECA4u; }
        if (ctx->pc != 0x12ECA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ECA4u; }
        if (ctx->pc != 0x12ECA4u) { return; }
    }
    ctx->pc = 0x12ECA4u;
label_12eca4:
    // 0x12eca4: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12eca4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x12eca8: 0x8e030058  lw          $v1, 0x58($s0)
    ctx->pc = 0x12eca8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
label_12ecac:
    // 0x12ecac: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12ecacu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12ecb0: 0x263102a  slt         $v0, $s3, $v1
    ctx->pc = 0x12ecb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12ecb4: 0x5440fff4  bnel        $v0, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x12ECB4u;
    {
        const bool branch_taken_0x12ecb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ecb4) {
            ctx->pc = 0x12ECB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12ECB4u;
            // 0x12ecb8: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EC88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ec88;
        }
    }
    ctx->pc = 0x12ECBCu;
    // 0x12ecbc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12ECBCu;
    {
        const bool branch_taken_0x12ecbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12ECC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ECBCu;
            // 0x12ecc0: 0x8e020030  lw          $v0, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ecbc) {
            ctx->pc = 0x12ECCCu;
            goto label_12eccc;
        }
    }
    ctx->pc = 0x12ECC4u;
    // 0x12ecc4: 0x0  nop
    ctx->pc = 0x12ecc4u;
    // NOP
label_12ecc8:
    // 0x12ecc8: 0x8e020030  lw          $v0, 0x30($s0)
    ctx->pc = 0x12ecc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
label_12eccc:
    // 0x12eccc: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x12ecccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ecd0: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x12ecd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x12ecd4: 0x18600029  blez        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x12ECD4u;
    {
        const bool branch_taken_0x12ecd4 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12ECD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ECD4u;
            // 0x12ecd8: 0xae020030  sw          $v0, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ecd4) {
            ctx->pc = 0x12ED7Cu;
            goto label_12ed7c;
        }
    }
    ctx->pc = 0x12ECDCu;
    // 0x12ecdc: 0x27be0012  addiu       $fp, $sp, 0x12
    ctx->pc = 0x12ecdcu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), 18));
    // 0x12ece0: 0x2617000c  addiu       $s7, $s0, 0xC
    ctx->pc = 0x12ece0u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x12ece4: 0x26160008  addiu       $s6, $s0, 0x8
    ctx->pc = 0x12ece4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x12ece8: 0x26140298  addiu       $s4, $s0, 0x298
    ctx->pc = 0x12ece8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 664));
    // 0x12ecec: 0x26130290  addiu       $s3, $s0, 0x290
    ctx->pc = 0x12ececu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 656));
    // 0x12ecf0: 0x26110080  addiu       $s1, $s0, 0x80
    ctx->pc = 0x12ecf0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x12ecf4: 0x24120080  addiu       $s2, $zero, 0x80
    ctx->pc = 0x12ecf4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x12ecf8: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x12ecf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ecfc: 0x0  nop
    ctx->pc = 0x12ecfcu;
    // NOP
label_12ed00:
    // 0x12ed00: 0xc04b9c2  jal         func_12E708
    ctx->pc = 0x12ED00u;
    SET_GPR_U32(ctx, 31, 0x12ED08u);
    ctx->pc = 0x12ED04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ED00u;
            // 0x12ed04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E708u;
    if (runtime->hasFunction(0x12E708u)) {
        auto targetFn = runtime->lookupFunction(0x12E708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED08u; }
        if (ctx->pc != 0x12ED08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E708_0x12e708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED08u; }
        if (ctx->pc != 0x12ED08u) { return; }
    }
    ctx->pc = 0x12ED08u;
label_12ed08:
    // 0x12ed08: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12ed08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ed0c: 0x27a20010  addiu       $v0, $sp, 0x10
    ctx->pc = 0x12ed0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12ed10: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x12ed10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ed14: 0xdc670080  ld          $a3, 0x80($v1)
    ctx->pc = 0x12ed14u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 128)));
    // 0x12ed18: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12ed18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ed1c: 0x9462007c  lhu         $v0, 0x7C($v1)
    ctx->pc = 0x12ed1cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 124)));
    // 0x12ed20: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x12ed20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x12ed24: 0x8c640088  lw          $a0, 0x88($v1)
    ctx->pc = 0x12ed24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 136)));
    // 0x12ed28: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x12ed28u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12ed2c: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x12ed2cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x12ed30: 0xfe870000  sd          $a3, 0x0($s4)
    ctx->pc = 0x12ed30u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 7));
    // 0x12ed34: 0xc04b87c  jal         func_12E1F0
    ctx->pc = 0x12ED34u;
    SET_GPR_U32(ctx, 31, 0x12ED3Cu);
    ctx->pc = 0x12ED38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ED34u;
            // 0x12ed38: 0x26940008  addiu       $s4, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E1F0u;
    if (runtime->hasFunction(0x12E1F0u)) {
        auto targetFn = runtime->lookupFunction(0x12E1F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED3Cu; }
        if (ctx->pc != 0x12ED3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E1F0_0x12e1f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED3Cu; }
        if (ctx->pc != 0x12ED3Cu) { return; }
    }
    ctx->pc = 0x12ED3Cu;
label_12ed3c:
    // 0x12ed3c: 0x2d22021  addu        $a0, $s6, $s2
    ctx->pc = 0x12ed3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x12ed40: 0x97a20010  lhu         $v0, 0x10($sp)
    ctx->pc = 0x12ed40u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ed44: 0x2f23021  addu        $a2, $s7, $s2
    ctx->pc = 0x12ed44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 18)));
    // 0x12ed48: 0x97a30012  lhu         $v1, 0x12($sp)
    ctx->pc = 0x12ed48u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 18)));
    // 0x12ed4c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x12ed4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ed50: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x12ed50u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12ed54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12ed54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ed58: 0xa4c30000  sh          $v1, 0x0($a2)
    ctx->pc = 0x12ed58u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x12ed5c: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x12ed5cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x12ed60: 0xc04ba5a  jal         func_12E968
    ctx->pc = 0x12ED60u;
    SET_GPR_U32(ctx, 31, 0x12ED68u);
    ctx->pc = 0x12ED64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ED60u;
            // 0x12ed64: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E968u;
    if (runtime->hasFunction(0x12E968u)) {
        auto targetFn = runtime->lookupFunction(0x12E968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED68u; }
        if (ctx->pc != 0x12ED68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E968_0x12e968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ED68u; }
        if (ctx->pc != 0x12ED68u) { return; }
    }
    ctx->pc = 0x12ED68u;
label_12ed68:
    // 0x12ed68: 0x8e020058  lw          $v0, 0x58($s0)
    ctx->pc = 0x12ed68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
    // 0x12ed6c: 0x2a2102a  slt         $v0, $s5, $v0
    ctx->pc = 0x12ed6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12ed70: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x12ED70u;
    {
        const bool branch_taken_0x12ed70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12ED74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ED70u;
            // 0x12ed74: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ed70) {
            ctx->pc = 0x12ED00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ed00;
        }
    }
    ctx->pc = 0x12ED78u;
    // 0x12ed78: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12ed78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
label_12ed7c:
    // 0x12ed7c: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x12ed7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ed80: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12ed80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_12ed84:
    // 0x12ed84: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12ed84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ed88: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12ed88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ed8c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12ed8cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12ed90: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x12ed90u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12ed94: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x12ed94u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12ed98: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x12ed98u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12ed9c: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x12ed9cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12eda0: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x12eda0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12eda4: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x12eda4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x12eda8: 0x3e00008  jr          $ra
    ctx->pc = 0x12EDA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12EDACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EDA8u;
            // 0x12edac: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EC58u: goto label_12ec58;
            case 0x12EC88u: goto label_12ec88;
            case 0x12ECA4u: goto label_12eca4;
            case 0x12ECACu: goto label_12ecac;
            case 0x12ECC8u: goto label_12ecc8;
            case 0x12ECCCu: goto label_12eccc;
            case 0x12ED00u: goto label_12ed00;
            case 0x12ED08u: goto label_12ed08;
            case 0x12ED3Cu: goto label_12ed3c;
            case 0x12ED68u: goto label_12ed68;
            case 0x12ED7Cu: goto label_12ed7c;
            case 0x12ED84u: goto label_12ed84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12EDB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
