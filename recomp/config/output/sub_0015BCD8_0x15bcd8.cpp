#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BCD8
// Address: 0x15bcd8 - 0x15bdc0
void sub_0015BCD8_0x15bcd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BCD8_0x15bcd8");
#endif

    switch (ctx->pc) {
        case 0x15bd14u: goto label_15bd14;
        case 0x15bd1cu: goto label_15bd1c;
        default: break;
    }

    ctx->pc = 0x15bcd8u;

    // 0x15bcd8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x15bcd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15bcdc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15bcdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15bce0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15bce0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bce4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15bce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15bce8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15bce8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bcec: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x15bcecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x15bcf0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x15bcf0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bcf4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15bcf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15bcf8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15bcf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bcfc: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x15bcfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x15bd00: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x15bd00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15bd04: 0x27a70008  addiu       $a3, $sp, 0x8
    ctx->pc = 0x15bd04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x15bd08: 0x27a8000c  addiu       $t0, $sp, 0xC
    ctx->pc = 0x15bd08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x15bd0c: 0xc056f22  jal         func_15BC88
    ctx->pc = 0x15BD0Cu;
    SET_GPR_U32(ctx, 31, 0x15BD14u);
    ctx->pc = 0x15BD10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BD0Cu;
            // 0x15bd10: 0x8e120010  lw          $s2, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BC88u;
    if (runtime->hasFunction(0x15BC88u)) {
        auto targetFn = runtime->lookupFunction(0x15BC88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BD14u; }
        if (ctx->pc != 0x15BD14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BC88_0x15bc88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BD14u; }
        if (ctx->pc != 0x15BD14u) { return; }
    }
    ctx->pc = 0x15BD14u;
label_15bd14:
    // 0x15bd14: 0xc056f70  jal         func_15BDC0
    ctx->pc = 0x15BD14u;
    SET_GPR_U32(ctx, 31, 0x15BD1Cu);
    ctx->pc = 0x15BD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BD14u;
            // 0x15bd18: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BDC0u;
    if (runtime->hasFunction(0x15BDC0u)) {
        auto targetFn = runtime->lookupFunction(0x15BDC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BD1Cu; }
        if (ctx->pc != 0x15BD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BDC0_0x15bdc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BD1Cu; }
        if (ctx->pc != 0x15BD1Cu) { return; }
    }
    ctx->pc = 0x15BD1Cu;
label_15bd1c:
    // 0x15bd1c: 0x24090002  addiu       $t1, $zero, 0x2
    ctx->pc = 0x15bd1cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15bd20: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15bd20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15bd24: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x15bd24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15bd28: 0x24a7000f  addiu       $a3, $a1, 0xF
    ctx->pc = 0x15bd28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x15bd2c: 0x28a30000  slti        $v1, $a1, 0x0
    ctx->pc = 0x15bd2cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bd30: 0xa44018  mult        $t0, $a1, $a0
    ctx->pc = 0x15bd30u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x15bd34: 0xe3280b  movn        $a1, $a3, $v1
    ctx->pc = 0x15bd34u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x15bd38: 0x2486000f  addiu       $a2, $a0, 0xF
    ctx->pc = 0x15bd38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x15bd3c: 0x28830000  slti        $v1, $a0, 0x0
    ctx->pc = 0x15bd3cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bd40: 0xc3200b  movn        $a0, $a2, $v1
    ctx->pc = 0x15bd40u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 6));
    // 0x15bd44: 0x52903  sra         $a1, $a1, 4
    ctx->pc = 0x15bd44u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 4));
    // 0x15bd48: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x15bd48u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x15bd4c: 0xa43818  mult        $a3, $a1, $a0
    ctx->pc = 0x15bd4cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x15bd50: 0x818c0  sll         $v1, $t0, 3
    ctx->pc = 0x15bd50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x15bd54: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x15bd54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x15bd58: 0x337c2  srl         $a2, $v1, 31
    ctx->pc = 0x15bd58u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x15bd5c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x15bd5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x15bd60: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x15bd60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bd64: 0x72040  sll         $a0, $a3, 1
    ctx->pc = 0x15bd64u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x15bd68: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x15bd68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x15bd6c: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x15bd6cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x15bd70: 0x52a80  sll         $a1, $a1, 10
    ctx->pc = 0x15bd70u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 10));
    // 0x15bd74: 0x3c010008  lui         $at, 0x8
    ctx->pc = 0x15bd74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)8 << 16));
    // 0x15bd78: 0x34216910  ori         $at, $at, 0x6910
    ctx->pc = 0x15bd78u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)26896);
    // 0x15bd7c: 0x231821  addu        $v1, $at, $v1
    ctx->pc = 0x15bd7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x15bd80: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x15bd80u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x15bd84: 0x24a50040  addiu       $a1, $a1, 0x40
    ctx->pc = 0x15bd84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
    // 0x15bd88: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x15bd88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x15bd8c: 0x2451818  mult        $v1, $s2, $a1
    ctx->pc = 0x15bd8cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x15bd90: 0x10490002  beq         $v0, $t1, . + 4 + (0x2 << 2)
    ctx->pc = 0x15BD90u;
    {
        const bool branch_taken_0x15bd90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 9));
        ctx->pc = 0x15BD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BD90u;
            // 0x15bd94: 0x24840040  addiu       $a0, $a0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bd90) {
            ctx->pc = 0x15BD9Cu;
            goto label_15bd9c;
        }
    }
    ctx->pc = 0x15BD98u;
    // 0x15bd98: 0x2441818  mult        $v1, $s2, $a0
    ctx->pc = 0x15bd98u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
label_15bd9c:
    // 0x15bd9c: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x15bd9cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x15bda0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15bda0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15bda4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15bda4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15bda8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15bda8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15bdac: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x15bdacu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15bdb0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x15bdb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15bdb4: 0x3e00008  jr          $ra
    ctx->pc = 0x15BDB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDB4u;
            // 0x15bdb8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BD14u: goto label_15bd14;
            case 0x15BD1Cu: goto label_15bd1c;
            case 0x15BD9Cu: goto label_15bd9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BDBCu;
    // 0x15bdbc: 0x0  nop
    ctx->pc = 0x15bdbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
