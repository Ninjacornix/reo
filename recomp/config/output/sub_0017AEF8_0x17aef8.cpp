#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017AEF8
// Address: 0x17aef8 - 0x17b010
void sub_0017AEF8_0x17aef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017AEF8_0x17aef8");
#endif

    switch (ctx->pc) {
        case 0x17af20u: goto label_17af20;
        case 0x17afccu: goto label_17afcc;
        case 0x17afe4u: goto label_17afe4;
        case 0x17aff8u: goto label_17aff8;
        default: break;
    }

    ctx->pc = 0x17aef8u;

    // 0x17aef8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17aef8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17aefc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17aefcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17af00: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17af00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17af04: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17af04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17af08: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17af08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17af0c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17af0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17af10: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17af10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17af14: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x17af14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x17af18: 0xc05eb1a  jal         func_17AC68
    ctx->pc = 0x17AF18u;
    SET_GPR_U32(ctx, 31, 0x17AF20u);
    ctx->pc = 0x17AF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AF18u;
            // 0x17af1c: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AF20u; }
        if (ctx->pc != 0x17AF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017AC68_0x17ac68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AF20u; }
        if (ctx->pc != 0x17AF20u) { return; }
    }
    ctx->pc = 0x17AF20u;
label_17af20:
    // 0x17af20: 0x26020004  addiu       $v0, $s0, 0x4
    ctx->pc = 0x17af20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17af24: 0x8e040048  lw          $a0, 0x48($s0)
    ctx->pc = 0x17af24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17af28: 0x8c4a0004  lw          $t2, 0x4($v0)
    ctx->pc = 0x17af28u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17af2c: 0x26080014  addiu       $t0, $s0, 0x14
    ctx->pc = 0x17af2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17af30: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x17af30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17af34: 0x26090024  addiu       $t1, $s0, 0x24
    ctx->pc = 0x17af34u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17af38: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x17af38u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17af3c: 0x417c2  srl         $v0, $a0, 31
    ctx->pc = 0x17af3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
    // 0x17af40: 0x1431818  mult        $v1, $t2, $v1
    ctx->pc = 0x17af40u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x17af44: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x17af44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x17af48: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x17af48u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x17af4c: 0x42043  sra         $a0, $a0, 1
    ctx->pc = 0x17af4cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 1));
    // 0x17af50: 0x8d250000  lw          $a1, 0x0($t1)
    ctx->pc = 0x17af50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x17af54: 0xa6880  sll         $t5, $t2, 2
    ctx->pc = 0x17af54u;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
    // 0x17af58: 0x8d0b0004  lw          $t3, 0x4($t0)
    ctx->pc = 0x17af58u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x17af5c: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17af5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17af60: 0x8e4c0008  lw          $t4, 0x8($s2)
    ctx->pc = 0x17af60u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17af64: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17af64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17af68: 0x8d280004  lw          $t0, 0x4($t1)
    ctx->pc = 0x17af68u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x17af6c: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17af6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17af70: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17af70u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17af74: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17af74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17af78: 0x8e090044  lw          $t1, 0x44($s0)
    ctx->pc = 0x17af78u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17af7c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17af7cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17af80: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x17af80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x17af84: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x17af84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x17af88: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x17af88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x17af8c: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x17af8cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x17af90: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17af90u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17af94: 0xafa50008  sw          $a1, 0x8($sp)
    ctx->pc = 0x17af94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 5));
    // 0x17af98: 0xafab0010  sw          $t3, 0x10($sp)
    ctx->pc = 0x17af98u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 11));
    // 0x17af9c: 0xafa80014  sw          $t0, 0x14($sp)
    ctx->pc = 0x17af9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 8));
    // 0x17afa0: 0xafb10020  sw          $s1, 0x20($sp)
    ctx->pc = 0x17afa0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 17));
    // 0x17afa4: 0xafa90024  sw          $t1, 0x24($sp)
    ctx->pc = 0x17afa4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 9));
    // 0x17afa8: 0xafa40028  sw          $a0, 0x28($sp)
    ctx->pc = 0x17afa8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 4));
    // 0x17afac: 0x15800004  bnez        $t4, . + 4 + (0x4 << 2)
    ctx->pc = 0x17AFACu;
    {
        const bool branch_taken_0x17afac = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x17AFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFACu;
            // 0x17afb0: 0xafaa000c  sw          $t2, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17afac) {
            ctx->pc = 0x17AFC0u;
            goto label_17afc0;
        }
    }
    ctx->pc = 0x17AFB4u;
    // 0x17afb4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17AFB4u;
    {
        const bool branch_taken_0x17afb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AFB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFB4u;
            // 0x17afb8: 0xafad002c  sw          $t5, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17afb4) {
            ctx->pc = 0x17AFC4u;
            goto label_17afc4;
        }
    }
    ctx->pc = 0x17AFBCu;
    // 0x17afbc: 0x0  nop
    ctx->pc = 0x17afbcu;
    // NOP
label_17afc0:
    // 0x17afc0: 0xafac002c  sw          $t4, 0x2C($sp)
    ctx->pc = 0x17afc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 12));
label_17afc4:
    // 0x17afc4: 0xc05f486  jal         func_17D218
    ctx->pc = 0x17AFC4u;
    SET_GPR_U32(ctx, 31, 0x17AFCCu);
    ctx->pc = 0x17D218u;
    if (runtime->hasFunction(0x17D218u)) {
        auto targetFn = runtime->lookupFunction(0x17D218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFCCu; }
        if (ctx->pc != 0x17AFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D218_0x17d218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFCCu; }
        if (ctx->pc != 0x17AFCCu) { return; }
    }
    ctx->pc = 0x17AFCCu;
label_17afcc:
    // 0x17afcc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17afccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17afd0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17AFD0u;
    {
        const bool branch_taken_0x17afd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17AFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFD0u;
            // 0x17afd4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17afd0) {
            ctx->pc = 0x17AFF0u;
            goto label_17aff0;
        }
    }
    ctx->pc = 0x17AFD8u;
    // 0x17afd8: 0x8e46003c  lw          $a2, 0x3C($s2)
    ctx->pc = 0x17afd8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x17afdc: 0xc0524ae  jal         func_1492B8
    ctx->pc = 0x17AFDCu;
    SET_GPR_U32(ctx, 31, 0x17AFE4u);
    ctx->pc = 0x17AFE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFDCu;
            // 0x17afe0: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492B8u;
    if (runtime->hasFunction(0x1492B8u)) {
        auto targetFn = runtime->lookupFunction(0x1492B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFE4u; }
        if (ctx->pc != 0x17AFE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492B8_0x1492b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFE4u; }
        if (ctx->pc != 0x17AFE4u) { return; }
    }
    ctx->pc = 0x17AFE4u;
label_17afe4:
    // 0x17afe4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x17AFE4u;
    {
        const bool branch_taken_0x17afe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFE4u;
            // 0x17afe8: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17afe4) {
            ctx->pc = 0x17AFFCu;
            goto label_17affc;
        }
    }
    ctx->pc = 0x17AFECu;
    // 0x17afec: 0x0  nop
    ctx->pc = 0x17afecu;
    // NOP
label_17aff0:
    // 0x17aff0: 0xc0524ac  jal         func_1492B0
    ctx->pc = 0x17AFF0u;
    SET_GPR_U32(ctx, 31, 0x17AFF8u);
    ctx->pc = 0x17AFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AFF0u;
            // 0x17aff4: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492B0u;
    if (runtime->hasFunction(0x1492B0u)) {
        auto targetFn = runtime->lookupFunction(0x1492B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFF8u; }
        if (ctx->pc != 0x17AFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492B0_0x1492b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AFF8u; }
        if (ctx->pc != 0x17AFF8u) { return; }
    }
    ctx->pc = 0x17AFF8u;
label_17aff8:
    // 0x17aff8: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17aff8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_17affc:
    // 0x17affc: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17affcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b000: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17b000u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b004: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x17b004u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17b008: 0x3e00008  jr          $ra
    ctx->pc = 0x17B008u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B008u;
            // 0x17b00c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17AF20u: goto label_17af20;
            case 0x17AFC0u: goto label_17afc0;
            case 0x17AFC4u: goto label_17afc4;
            case 0x17AFCCu: goto label_17afcc;
            case 0x17AFE4u: goto label_17afe4;
            case 0x17AFF0u: goto label_17aff0;
            case 0x17AFF8u: goto label_17aff8;
            case 0x17AFFCu: goto label_17affc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B010u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
