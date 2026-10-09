#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017BD98
// Address: 0x17bd98 - 0x17be84
void sub_0017BD98_0x17bd98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017BD98_0x17bd98");
#endif

    switch (ctx->pc) {
        case 0x17be08u: goto label_17be08;
        case 0x17be68u: goto label_17be68;
        default: break;
    }

    ctx->pc = 0x17bd98u;

    // 0x17bd98: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x17bd98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x17bd9c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17bd9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17bda0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17bda0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bda4: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17bda4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17bda8: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17bda8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17bdac: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17bdacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17bdb0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17bdb0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bdb4: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17bdb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17bdb8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17bdb8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bdbc: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x17bdbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x17bdc0: 0x26020014  addiu       $v0, $s0, 0x14
    ctx->pc = 0x17bdc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17bdc4: 0xafa60020  sw          $a2, 0x20($sp)
    ctx->pc = 0x17bdc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
    // 0x17bdc8: 0x26030024  addiu       $v1, $s0, 0x24
    ctx->pc = 0x17bdc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17bdcc: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x17bdccu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17bdd0: 0x8c690004  lw          $t1, 0x4($v1)
    ctx->pc = 0x17bdd0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x17bdd4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x17bdd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17bdd8: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x17bdd8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17bddc: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17bddcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17bde0: 0x8e030044  lw          $v1, 0x44($s0)
    ctx->pc = 0x17bde0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17bde4: 0x8e270000  lw          $a3, 0x0($s1)
    ctx->pc = 0x17bde4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17bde8: 0xafa30024  sw          $v1, 0x24($sp)
    ctx->pc = 0x17bde8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x17bdec: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x17bdecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x17bdf0: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17bdf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17bdf4: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x17bdf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x17bdf8: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x17bdf8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x17bdfc: 0xafa80010  sw          $t0, 0x10($sp)
    ctx->pc = 0x17bdfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x17be00: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17BE00u;
    SET_GPR_U32(ctx, 31, 0x17BE08u);
    ctx->pc = 0x17BE04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE00u;
            // 0x17be04: 0xafa90014  sw          $t1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BE08u; }
        if (ctx->pc != 0x17BE08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BE08u; }
        if (ctx->pc != 0x17BE08u) { return; }
    }
    ctx->pc = 0x17BE08u;
label_17be08:
    // 0x17be08: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17be08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17be0c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17BE0Cu;
    {
        const bool branch_taken_0x17be0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17BE10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE0Cu;
            // 0x17be10: 0x8e020048  lw          $v0, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17be0c) {
            ctx->pc = 0x17BE20u;
            goto label_17be20;
        }
    }
    ctx->pc = 0x17BE14u;
    // 0x17be14: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17be14u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17be18: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17be18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17be1c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17be1cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_17be20:
    // 0x17be20: 0xafa20028  sw          $v0, 0x28($sp)
    ctx->pc = 0x17be20u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x17be24: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17be24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17be28: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x17BE28u;
    {
        const bool branch_taken_0x17be28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17be28) {
            ctx->pc = 0x17BE2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE28u;
            // 0x17be2c: 0x8e220004  lw          $v0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17BE30u;
            goto label_17be30;
        }
    }
    ctx->pc = 0x17BE30u;
label_17be30:
    // 0x17be30: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x17be30u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x17be34: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x17be34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x17be38: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x17BE38u;
    {
        const bool branch_taken_0x17be38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17be38) {
            ctx->pc = 0x17BE3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE38u;
            // 0x17be3c: 0x8e220008  lw          $v0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17BE40u;
            goto label_17be40;
        }
    }
    ctx->pc = 0x17BE40u;
label_17be40:
    // 0x17be40: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x17be40u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x17be44: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17be44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17be48: 0x16620002  bne         $s3, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17BE48u;
    {
        const bool branch_taken_0x17be48 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        ctx->pc = 0x17BE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE48u;
            // 0x17be4c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17be48) {
            ctx->pc = 0x17BE54u;
            goto label_17be54;
        }
    }
    ctx->pc = 0x17BE50u;
    // 0x17be50: 0x8e48003c  lw          $t0, 0x3C($s2)
    ctx->pc = 0x17be50u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
label_17be54:
    // 0x17be54: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17be54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17be58: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17be58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17be5c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17be5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17be60: 0xc05efa2  jal         func_17BE88
    ctx->pc = 0x17BE60u;
    SET_GPR_U32(ctx, 31, 0x17BE68u);
    ctx->pc = 0x17BE64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE60u;
            // 0x17be64: 0x27a70020  addiu       $a3, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BE88u;
    if (runtime->hasFunction(0x17BE88u)) {
        auto targetFn = runtime->lookupFunction(0x17BE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BE68u; }
        if (ctx->pc != 0x17BE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BE88_0x17be88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BE68u; }
        if (ctx->pc != 0x17BE68u) { return; }
    }
    ctx->pc = 0x17BE68u;
label_17be68:
    // 0x17be68: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17be68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17be6c: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17be6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17be70: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17be70u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17be74: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17be74u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17be78: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x17be78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17be7c: 0x3e00008  jr          $ra
    ctx->pc = 0x17BE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17BE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BE7Cu;
            // 0x17be80: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17BE08u: goto label_17be08;
            case 0x17BE20u: goto label_17be20;
            case 0x17BE30u: goto label_17be30;
            case 0x17BE40u: goto label_17be40;
            case 0x17BE54u: goto label_17be54;
            case 0x17BE68u: goto label_17be68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17BE84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
