#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CD18
// Address: 0x17cd18 - 0x17ce0c
void sub_0017CD18_0x17cd18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CD18_0x17cd18");
#endif

    switch (ctx->pc) {
        case 0x17cd88u: goto label_17cd88;
        case 0x17cdf0u: goto label_17cdf0;
        default: break;
    }

    ctx->pc = 0x17cd18u;

    // 0x17cd18: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x17cd18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x17cd1c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17cd1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17cd20: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17cd20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd24: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17cd24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17cd28: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17cd28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17cd2c: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17cd2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17cd30: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17cd30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd34: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17cd34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17cd38: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17cd38u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd3c: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x17cd3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x17cd40: 0x26020014  addiu       $v0, $s0, 0x14
    ctx->pc = 0x17cd40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17cd44: 0xafa60020  sw          $a2, 0x20($sp)
    ctx->pc = 0x17cd44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
    // 0x17cd48: 0x26030024  addiu       $v1, $s0, 0x24
    ctx->pc = 0x17cd48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17cd4c: 0x8c690004  lw          $t1, 0x4($v1)
    ctx->pc = 0x17cd4cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x17cd50: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x17cd50u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17cd54: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x17cd54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17cd58: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x17cd58u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17cd5c: 0x8e270000  lw          $a3, 0x0($s1)
    ctx->pc = 0x17cd5cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17cd60: 0x8e030044  lw          $v1, 0x44($s0)
    ctx->pc = 0x17cd60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17cd64: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17cd64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17cd68: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x17cd68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x17cd6c: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17cd6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17cd70: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x17cd70u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x17cd74: 0xafa90014  sw          $t1, 0x14($sp)
    ctx->pc = 0x17cd74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 9));
    // 0x17cd78: 0xafa30024  sw          $v1, 0x24($sp)
    ctx->pc = 0x17cd78u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x17cd7c: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x17cd7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x17cd80: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17CD80u;
    SET_GPR_U32(ctx, 31, 0x17CD88u);
    ctx->pc = 0x17CD84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD80u;
            // 0x17cd84: 0xafa80010  sw          $t0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CD88u; }
        if (ctx->pc != 0x17CD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CD88u; }
        if (ctx->pc != 0x17CD88u) { return; }
    }
    ctx->pc = 0x17CD88u;
label_17cd88:
    // 0x17cd88: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17cd88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cd8c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17cd8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd90: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17cd90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd94: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17cd94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd98: 0x27a70020  addiu       $a3, $sp, 0x20
    ctx->pc = 0x17cd98u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17cd9c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17CD9Cu;
    {
        const bool branch_taken_0x17cd9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17CDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD9Cu;
            // 0x17cda0: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cd9c) {
            ctx->pc = 0x17CDB8u;
            goto label_17cdb8;
        }
    }
    ctx->pc = 0x17CDA4u;
    // 0x17cda4: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17cda4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17cda8: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17cda8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17cdac: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17cdacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17cdb0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17CDB0u;
    {
        const bool branch_taken_0x17cdb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDB0u;
            // 0x17cdb4: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cdb0) {
            ctx->pc = 0x17CDBCu;
            goto label_17cdbc;
        }
    }
    ctx->pc = 0x17CDB8u;
label_17cdb8:
    // 0x17cdb8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17cdb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_17cdbc:
    // 0x17cdbc: 0xafa20028  sw          $v0, 0x28($sp)
    ctx->pc = 0x17cdbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x17cdc0: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17cdc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17cdc4: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x17CDC4u;
    {
        const bool branch_taken_0x17cdc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17cdc4) {
            ctx->pc = 0x17CDC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDC4u;
            // 0x17cdc8: 0xafa2002c  sw          $v0, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CDDCu;
            goto label_17cddc;
        }
    }
    ctx->pc = 0x17CDCCu;
    // 0x17cdcc: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x17cdccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17cdd0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x17cdd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x17cdd4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17cdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17cdd8: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x17cdd8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
label_17cddc:
    // 0x17cddc: 0x16690002  bne         $s3, $t1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17CDDCu;
    {
        const bool branch_taken_0x17cddc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 9));
        ctx->pc = 0x17CDE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDDCu;
            // 0x17cde0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cddc) {
            ctx->pc = 0x17CDE8u;
            goto label_17cde8;
        }
    }
    ctx->pc = 0x17CDE4u;
    // 0x17cde4: 0x8e48003c  lw          $t0, 0x3C($s2)
    ctx->pc = 0x17cde4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
label_17cde8:
    // 0x17cde8: 0xc05f384  jal         func_17CE10
    ctx->pc = 0x17CDE8u;
    SET_GPR_U32(ctx, 31, 0x17CDF0u);
    ctx->pc = 0x17CE10u;
    if (runtime->hasFunction(0x17CE10u)) {
        auto targetFn = runtime->lookupFunction(0x17CE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CDF0u; }
        if (ctx->pc != 0x17CDF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE10_0x17ce10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CDF0u; }
        if (ctx->pc != 0x17CDF0u) { return; }
    }
    ctx->pc = 0x17CDF0u;
label_17cdf0:
    // 0x17cdf0: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17cdf0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17cdf4: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17cdf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17cdf8: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17cdf8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17cdfc: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17cdfcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17ce00: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x17ce00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17ce04: 0x3e00008  jr          $ra
    ctx->pc = 0x17CE04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE04u;
            // 0x17ce08: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CD88u: goto label_17cd88;
            case 0x17CDB8u: goto label_17cdb8;
            case 0x17CDBCu: goto label_17cdbc;
            case 0x17CDDCu: goto label_17cddc;
            case 0x17CDE8u: goto label_17cde8;
            case 0x17CDF0u: goto label_17cdf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CE0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
