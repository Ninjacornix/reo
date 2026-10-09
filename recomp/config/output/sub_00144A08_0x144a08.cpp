#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00144A08
// Address: 0x144a08 - 0x144eb0
void sub_00144A08_0x144a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00144A08_0x144a08");
#endif

    switch (ctx->pc) {
        case 0x144a84u: goto label_144a84;
        case 0x144aa0u: goto label_144aa0;
        case 0x144ae4u: goto label_144ae4;
        case 0x144ba0u: goto label_144ba0;
        case 0x144bccu: goto label_144bcc;
        case 0x144c3cu: goto label_144c3c;
        case 0x144c68u: goto label_144c68;
        case 0x144cc8u: goto label_144cc8;
        case 0x144cf4u: goto label_144cf4;
        case 0x144d24u: goto label_144d24;
        case 0x144d4cu: goto label_144d4c;
        case 0x144d54u: goto label_144d54;
        case 0x144d98u: goto label_144d98;
        default: break;
    }

    ctx->pc = 0x144a08u;

    // 0x144a08: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x144a08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x144a0c: 0x3c0b1000  lui         $t3, 0x1000
    ctx->pc = 0x144a0cu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)4096 << 16));
    // 0x144a10: 0xffb60090  sd          $s6, 0x90($sp)
    ctx->pc = 0x144a10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 22));
    // 0x144a14: 0x356b2010  ori         $t3, $t3, 0x2010
    ctx->pc = 0x144a14u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)8208);
    // 0x144a18: 0xffb50080  sd          $s5, 0x80($sp)
    ctx->pc = 0x144a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 21));
    // 0x144a1c: 0x3c02f8ff  lui         $v0, 0xF8FF
    ctx->pc = 0x144a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)63743 << 16));
    // 0x144a20: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x144a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x144a24: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x144a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x144a28: 0xffb10040  sd          $s1, 0x40($sp)
    ctx->pc = 0x144a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
    // 0x144a2c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x144a2cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a30: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x144a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x144a34: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x144a34u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a38: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x144a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x144a3c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x144a3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a40: 0xffbe00b0  sd          $fp, 0xB0($sp)
    ctx->pc = 0x144a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 30));
    // 0x144a44: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x144a44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a48: 0xffb700a0  sd          $s7, 0xA0($sp)
    ctx->pc = 0x144a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 23));
    // 0x144a4c: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x144a4cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a50: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x144a50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x144a54: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x144a54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144a58: 0xffb30060  sd          $s3, 0x60($sp)
    ctx->pc = 0x144a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
    // 0x144a5c: 0x8e040168  lw          $a0, 0x168($s0)
    ctx->pc = 0x144a5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
    // 0x144a60: 0x8d630000  lw          $v1, 0x0($t3)
    ctx->pc = 0x144a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x144a64: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x144a64u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x144a68: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x144a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x144a6c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x144a6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x144a70: 0xad630000  sw          $v1, 0x0($t3)
    ctx->pc = 0x144a70u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 3));
    // 0x144a74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144a74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a78: 0xafa70020  sw          $a3, 0x20($sp)
    ctx->pc = 0x144a78u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 7));
    // 0x144a7c: 0xc051552  jal         func_145548
    ctx->pc = 0x144A7Cu;
    SET_GPR_U32(ctx, 31, 0x144A84u);
    ctx->pc = 0x144A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144A7Cu;
            // 0x144a80: 0xafa90024  sw          $t1, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145548u;
    if (runtime->hasFunction(0x145548u)) {
        auto targetFn = runtime->lookupFunction(0x145548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144A84u; }
        if (ctx->pc != 0x144A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144A84u; }
        if (ctx->pc != 0x144A84u) { return; }
    }
    ctx->pc = 0x144A84u;
label_144a84:
    // 0x144a84: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x144a84u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a88: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x144A88u;
    {
        const bool branch_taken_0x144a88 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x144A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144A88u;
            // 0x144a8c: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144a88) {
            ctx->pc = 0x144AB0u;
            goto label_144ab0;
        }
    }
    ctx->pc = 0x144A90u;
    // 0x144a90: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x144a90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x144a94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144a94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a98: 0xc05221c  jal         func_148870
    ctx->pc = 0x144A98u;
    SET_GPR_U32(ctx, 31, 0x144AA0u);
    ctx->pc = 0x144A9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144A98u;
            // 0x144a9c: 0x24a5ded8  addiu       $a1, $a1, -0x2128 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958808));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AA0u; }
        if (ctx->pc != 0x144AA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AA0u; }
        if (ctx->pc != 0x144AA0u) { return; }
    }
    ctx->pc = 0x144AA0u;
label_144aa0:
    // 0x144aa0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x144aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144aa4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x144aa4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144aa8: 0x100000f5  b           . + 4 + (0xF5 << 2)
    ctx->pc = 0x144AA8u;
    {
        const bool branch_taken_0x144aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AA8u;
            // 0x144aac: 0xae030134  sw          $v1, 0x134($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144aa8) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144AB0u;
label_144ab0:
    // 0x144ab0: 0x3062000c  andi        $v0, $v1, 0xC
    ctx->pc = 0x144ab0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)12);
    // 0x144ab4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x144AB4u;
    {
        const bool branch_taken_0x144ab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AB4u;
            // 0x144ab8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ab4) {
            ctx->pc = 0x144AECu;
            goto label_144aec;
        }
    }
    ctx->pc = 0x144ABCu;
    // 0x144abc: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x144abcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144ac0: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x144AC0u;
    {
        const bool branch_taken_0x144ac0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x144AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AC0u;
            // 0x144ac4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ac0) {
            ctx->pc = 0x144ADCu;
            goto label_144adc;
        }
    }
    ctx->pc = 0x144AC8u;
    // 0x144ac8: 0x8e020194  lw          $v0, 0x194($s0)
    ctx->pc = 0x144ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x144acc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x144ACCu;
    {
        const bool branch_taken_0x144acc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144ACCu;
            // 0x144ad0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144acc) {
            ctx->pc = 0x144ADCu;
            goto label_144adc;
        }
    }
    ctx->pc = 0x144AD4u;
    // 0x144ad4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x144AD4u;
    {
        const bool branch_taken_0x144ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AD4u;
            // 0x144ad8: 0xaea20000  sw          $v0, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ad4) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144ADCu;
label_144adc:
    // 0x144adc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x144ADCu;
    SET_GPR_U32(ctx, 31, 0x144AE4u);
    ctx->pc = 0x144AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144ADCu;
            // 0x144ae0: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AE4u; }
        if (ctx->pc != 0x144AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AE4u; }
        if (ctx->pc != 0x144AE4u) { return; }
    }
    ctx->pc = 0x144AE4u;
label_144ae4:
    // 0x144ae4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x144AE4u;
    {
        const bool branch_taken_0x144ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AE4u;
            // 0x144ae8: 0xaea20000  sw          $v0, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ae4) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144AECu;
label_144aec:
    // 0x144aec: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x144aecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x144af0: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x144AF0u;
    {
        const bool branch_taken_0x144af0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x144af0) {
            ctx->pc = 0x144AF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144AF0u;
            // 0x144af4: 0x8e06018c  lw          $a2, 0x18C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144B1Cu;
            goto label_144b1c;
        }
    }
    ctx->pc = 0x144AF8u;
    // 0x144af8: 0x8e020198  lw          $v0, 0x198($s0)
    ctx->pc = 0x144af8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144afc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x144AFCu;
    {
        const bool branch_taken_0x144afc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144AFCu;
            // 0x144b00: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144afc) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144B04u;
    // 0x144b04: 0x8e02018c  lw          $v0, 0x18C($s0)
    ctx->pc = 0x144b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144b08: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x144b08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b0c: 0x38420003  xori        $v0, $v0, 0x3
    ctx->pc = 0x144b0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)3);
    // 0x144b10: 0x82180a  movz        $v1, $a0, $v0
    ctx->pc = 0x144b10u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x144b14: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x144b14u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
label_144b18:
    // 0x144b18: 0x8e06018c  lw          $a2, 0x18C($s0)
    ctx->pc = 0x144b18u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
label_144b1c:
    // 0x144b1c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x144b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x144b20: 0x14c20008  bne         $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x144B20u;
    {
        const bool branch_taken_0x144b20 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x144B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B20u;
            // 0x144b24: 0x8ea50000  lw          $a1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b20) {
            ctx->pc = 0x144B44u;
            goto label_144b44;
        }
    }
    ctx->pc = 0x144B28u;
    // 0x144b28: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x144b28u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144b2c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x144b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b30: 0x38a30001  xori        $v1, $a1, 0x1
    ctx->pc = 0x144b30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x144b34: 0x38a40002  xori        $a0, $a1, 0x2
    ctx->pc = 0x144b34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)2);
    // 0x144b38: 0x43980a  movz        $s3, $v0, $v1
    ctx->pc = 0x144b38u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 2));
    // 0x144b3c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x144B3Cu;
    {
        const bool branch_taken_0x144b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B3Cu;
            // 0x144b40: 0x2c940001  sltiu       $s4, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 20, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b3c) {
            ctx->pc = 0x144B58u;
            goto label_144b58;
        }
    }
    ctx->pc = 0x144B44u;
label_144b44:
    // 0x144b44: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x144b44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b48: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x144b48u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144b4c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x144b4cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144b50: 0x38a20002  xori        $v0, $a1, 0x2
    ctx->pc = 0x144b50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)2);
    // 0x144b54: 0x62980a  movz        $s3, $v1, $v0
    ctx->pc = 0x144b54u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
label_144b58:
    // 0x144b58: 0x38a20003  xori        $v0, $a1, 0x3
    ctx->pc = 0x144b58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)3);
    // 0x144b5c: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x144b5cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144b60: 0x16800003  bnez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x144B60u;
    {
        const bool branch_taken_0x144b60 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x144B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B60u;
            // 0x144b64: 0x2c5e0001  sltiu       $fp, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 30, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b60) {
            ctx->pc = 0x144B70u;
            goto label_144b70;
        }
    }
    ctx->pc = 0x144B68u;
    // 0x144b68: 0x38c20003  xori        $v0, $a2, 0x3
    ctx->pc = 0x144b68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)3);
    // 0x144b6c: 0x2c570001  sltiu       $s7, $v0, 0x1
    ctx->pc = 0x144b6cu;
    SET_GPR_U64(ctx, 23, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_144b70:
    // 0x144b70: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x144b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x144b74: 0x14c2000d  bne         $a2, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x144B74u;
    {
        const bool branch_taken_0x144b74 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x144B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B74u;
            // 0x144b78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b74) {
            ctx->pc = 0x144BACu;
            goto label_144bac;
        }
    }
    ctx->pc = 0x144B7Cu;
    // 0x144b7c: 0x8e020194  lw          $v0, 0x194($s0)
    ctx->pc = 0x144b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x144b80: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x144B80u;
    {
        const bool branch_taken_0x144b80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x144B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B80u;
            // 0x144b84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b80) {
            ctx->pc = 0x144BACu;
            goto label_144bac;
        }
    }
    ctx->pc = 0x144B88u;
    // 0x144b88: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x144b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144b8c: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x144b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x144b90: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x144B90u;
    {
        const bool branch_taken_0x144b90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144B90u;
            // 0x144b94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144b90) {
            ctx->pc = 0x144BA8u;
            goto label_144ba8;
        }
    }
    ctx->pc = 0x144B98u;
    // 0x144b98: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x144B98u;
    SET_GPR_U32(ctx, 31, 0x144BA0u);
    ctx->pc = 0x144B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144B98u;
            // 0x144b9c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BA0u; }
        if (ctx->pc != 0x144BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BA0u; }
        if (ctx->pc != 0x144BA0u) { return; }
    }
    ctx->pc = 0x144BA0u;
label_144ba0:
    // 0x144ba0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x144BA0u;
    {
        const bool branch_taken_0x144ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144BA0u;
            // 0x144ba4: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144ba0) {
            ctx->pc = 0x144BB0u;
            goto label_144bb0;
        }
    }
    ctx->pc = 0x144BA8u;
label_144ba8:
    // 0x144ba8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x144ba8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_144bac:
    // 0x144bac: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x144bacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_144bb0:
    // 0x144bb0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x144bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x144bb4: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x144bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144bb8: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x144bb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x144bbc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x144BBCu;
    {
        const bool branch_taken_0x144bbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144BBCu;
            // 0x144bc0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144bbc) {
            ctx->pc = 0x144BD4u;
            goto label_144bd4;
        }
    }
    ctx->pc = 0x144BC4u;
    // 0x144bc4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x144BC4u;
    SET_GPR_U32(ctx, 31, 0x144BCCu);
    ctx->pc = 0x144BC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144BC4u;
            // 0x144bc8: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BCCu; }
        if (ctx->pc != 0x144BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BCCu; }
        if (ctx->pc != 0x144BCCu) { return; }
    }
    ctx->pc = 0x144BCCu;
label_144bcc:
    // 0x144bcc: 0xae0201cc  sw          $v0, 0x1CC($s0)
    ctx->pc = 0x144bccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 460), GPR_U32(ctx, 2));
    // 0x144bd0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x144bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_144bd4:
    // 0x144bd4: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x144bd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x144bd8: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x144BD8u;
    {
        const bool branch_taken_0x144bd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x144bd8) {
            ctx->pc = 0x144BDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144BD8u;
            // 0x144bdc: 0x8e020860  lw          $v0, 0x860($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2144)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144BFCu;
            goto label_144bfc;
        }
    }
    ctx->pc = 0x144BE0u;
    // 0x144be0: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x144be0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x144be4: 0x50400021  beql        $v0, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x144BE4u;
    {
        const bool branch_taken_0x144be4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x144be4) {
            ctx->pc = 0x144BE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144BE4u;
            // 0x144be8: 0x8e030134  lw          $v1, 0x134($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144BECu;
    // 0x144bec: 0x8e020198  lw          $v0, 0x198($s0)
    ctx->pc = 0x144becu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144bf0: 0x5040001e  beql        $v0, $zero, . + 4 + (0x1E << 2)
    ctx->pc = 0x144BF0u;
    {
        const bool branch_taken_0x144bf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x144bf0) {
            ctx->pc = 0x144BF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144BF0u;
            // 0x144bf4: 0x8e030134  lw          $v1, 0x134($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144BF8u;
    // 0x144bf8: 0x8e020860  lw          $v0, 0x860($s0)
    ctx->pc = 0x144bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2144)));
label_144bfc:
    // 0x144bfc: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x144BFCu;
    {
        const bool branch_taken_0x144bfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144BFCu;
            // 0x144c00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144bfc) {
            ctx->pc = 0x144C44u;
            goto label_144c44;
        }
    }
    ctx->pc = 0x144C04u;
    // 0x144c04: 0x8e020180  lw          $v0, 0x180($s0)
    ctx->pc = 0x144c04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x144c08: 0x8e0b017c  lw          $t3, 0x17C($s0)
    ctx->pc = 0x144c08u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 380)));
    // 0x144c0c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x144c0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c10: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x144c10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x144c14: 0x8fa70024  lw          $a3, 0x24($sp)
    ctx->pc = 0x144c14u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144c18: 0xafbe0008  sw          $fp, 0x8($sp)
    ctx->pc = 0x144c18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x144c1c: 0x256bffff  addiu       $t3, $t3, -0x1
    ctx->pc = 0x144c1cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x144c20: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x144c20u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x144c24: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x144c24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c28: 0xafb70010  sw          $s7, 0x10($sp)
    ctx->pc = 0x144c28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x144c2c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x144c2cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c30: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x144c30u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c34: 0xc0513ce  jal         func_144F38
    ctx->pc = 0x144C34u;
    SET_GPR_U32(ctx, 31, 0x144C3Cu);
    ctx->pc = 0x144C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144C34u;
            // 0x144c38: 0x280502d  daddu       $t2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144F38u;
    if (runtime->hasFunction(0x144F38u)) {
        auto targetFn = runtime->lookupFunction(0x144F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C3Cu; }
        if (ctx->pc != 0x144C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144F38_0x144f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C3Cu; }
        if (ctx->pc != 0x144C3Cu) { return; }
    }
    ctx->pc = 0x144C3Cu;
label_144c3c:
    // 0x144c3c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x144C3Cu;
    {
        const bool branch_taken_0x144c3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144C3Cu;
            // 0x144c40: 0x8e030134  lw          $v1, 0x134($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144c3c) {
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144C44u;
label_144c44:
    // 0x144c44: 0x8e070170  lw          $a3, 0x170($s0)
    ctx->pc = 0x144c44u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 368)));
    // 0x144c48: 0x8e0b016c  lw          $t3, 0x16C($s0)
    ctx->pc = 0x144c48u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 364)));
    // 0x144c4c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x144c4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c50: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x144c50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x144c54: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x144c54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x144c58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c5c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x144c5cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c60: 0xc051436  jal         func_1450D8
    ctx->pc = 0x144C60u;
    SET_GPR_U32(ctx, 31, 0x144C68u);
    ctx->pc = 0x144C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144C60u;
            // 0x144c64: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1450D8u;
    if (runtime->hasFunction(0x1450D8u)) {
        auto targetFn = runtime->lookupFunction(0x1450D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C68u; }
        if (ctx->pc != 0x144C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001450D8_0x1450d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C68u; }
        if (ctx->pc != 0x144C68u) { return; }
    }
    ctx->pc = 0x144C68u;
label_144c68:
    // 0x144c68: 0x8e030134  lw          $v1, 0x134($s0)
    ctx->pc = 0x144c68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144c6c:
    // 0x144c6c: 0x14600084  bnez        $v1, . + 4 + (0x84 << 2)
    ctx->pc = 0x144C6Cu;
    {
        const bool branch_taken_0x144c6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x144C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144C6Cu;
            // 0x144c70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144c6c) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144C74u;
    // 0x144c74: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x144c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144c78: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x144c78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x144c7c: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x144C7Cu;
    {
        const bool branch_taken_0x144c7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x144c7c) {
            ctx->pc = 0x144CF8u;
            goto label_144cf8;
        }
    }
    ctx->pc = 0x144C84u;
    // 0x144c84: 0x8e020860  lw          $v0, 0x860($s0)
    ctx->pc = 0x144c84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2144)));
    // 0x144c88: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x144C88u;
    {
        const bool branch_taken_0x144c88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144C88u;
            // 0x144c8c: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144c88) {
            ctx->pc = 0x144CD0u;
            goto label_144cd0;
        }
    }
    ctx->pc = 0x144C90u;
    // 0x144c90: 0x8e020188  lw          $v0, 0x188($s0)
    ctx->pc = 0x144c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x144c94: 0x8e0b0184  lw          $t3, 0x184($s0)
    ctx->pc = 0x144c94u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 388)));
    // 0x144c98: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x144c98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c9c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x144c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x144ca0: 0x8fa70024  lw          $a3, 0x24($sp)
    ctx->pc = 0x144ca0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144ca4: 0xafb70010  sw          $s7, 0x10($sp)
    ctx->pc = 0x144ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x144ca8: 0x280502d  daddu       $t2, $s4, $zero
    ctx->pc = 0x144ca8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x144cacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x144cb0: 0x256bffff  addiu       $t3, $t3, -0x1
    ctx->pc = 0x144cb0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x144cb4: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x144cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x144cb8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144cb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cbc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x144cbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cc0: 0xc0513ce  jal         func_144F38
    ctx->pc = 0x144CC0u;
    SET_GPR_U32(ctx, 31, 0x144CC8u);
    ctx->pc = 0x144CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144CC0u;
            // 0x144cc4: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144F38u;
    if (runtime->hasFunction(0x144F38u)) {
        auto targetFn = runtime->lookupFunction(0x144F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CC8u; }
        if (ctx->pc != 0x144CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144F38_0x144f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CC8u; }
        if (ctx->pc != 0x144CC8u) { return; }
    }
    ctx->pc = 0x144CC8u;
label_144cc8:
    // 0x144cc8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x144CC8u;
    {
        const bool branch_taken_0x144cc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144CC8u;
            // 0x144ccc: 0x8e030134  lw          $v1, 0x134($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144cc8) {
            ctx->pc = 0x144CF8u;
            goto label_144cf8;
        }
    }
    ctx->pc = 0x144CD0u;
label_144cd0:
    // 0x144cd0: 0x8e070178  lw          $a3, 0x178($s0)
    ctx->pc = 0x144cd0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x144cd4: 0x8e0b0174  lw          $t3, 0x174($s0)
    ctx->pc = 0x144cd4u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 372)));
    // 0x144cd8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144cd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cdc: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x144cdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x144ce0: 0x26250008  addiu       $a1, $s1, 0x8
    ctx->pc = 0x144ce0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x144ce4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x144ce4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144ce8: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x144ce8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cec: 0xc051436  jal         func_1450D8
    ctx->pc = 0x144CECu;
    SET_GPR_U32(ctx, 31, 0x144CF4u);
    ctx->pc = 0x144CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144CECu;
            // 0x144cf0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1450D8u;
    if (runtime->hasFunction(0x1450D8u)) {
        auto targetFn = runtime->lookupFunction(0x1450D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CF4u; }
        if (ctx->pc != 0x144CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001450D8_0x1450d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CF4u; }
        if (ctx->pc != 0x144CF4u) { return; }
    }
    ctx->pc = 0x144CF4u;
label_144cf4:
    // 0x144cf4: 0x8e030134  lw          $v1, 0x134($s0)
    ctx->pc = 0x144cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144cf8:
    // 0x144cf8: 0x14600061  bnez        $v1, . + 4 + (0x61 << 2)
    ctx->pc = 0x144CF8u;
    {
        const bool branch_taken_0x144cf8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x144CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144CF8u;
            // 0x144cfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144cf8) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144D00u;
    // 0x144d00: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x144d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144d04: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x144d04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x144d08: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x144D08u;
    {
        const bool branch_taken_0x144d08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144D08u;
            // 0x144d0c: 0x30620003  andi        $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x144d08) {
            ctx->pc = 0x144D2Cu;
            goto label_144d2c;
        }
    }
    ctx->pc = 0x144D10u;
    // 0x144d10: 0x8e020198  lw          $v0, 0x198($s0)
    ctx->pc = 0x144d10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144d14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x144D14u;
    {
        const bool branch_taken_0x144d14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144D14u;
            // 0x144d18: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144d14) {
            ctx->pc = 0x144D28u;
            goto label_144d28;
        }
    }
    ctx->pc = 0x144D1Cu;
    // 0x144d1c: 0xc051636  jal         func_1458D8
    ctx->pc = 0x144D1Cu;
    SET_GPR_U32(ctx, 31, 0x144D24u);
    ctx->pc = 0x144D20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144D1Cu;
            // 0x144d20: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D24u; }
        if (ctx->pc != 0x144D24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D24u; }
        if (ctx->pc != 0x144D24u) { return; }
    }
    ctx->pc = 0x144D24u;
label_144d24:
    // 0x144d24: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x144d24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_144d28:
    // 0x144d28: 0x30620003  andi        $v0, $v1, 0x3
    ctx->pc = 0x144d28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
label_144d2c:
    // 0x144d2c: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x144D2Cu;
    {
        const bool branch_taken_0x144d2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144D2Cu;
            // 0x144d30: 0x24030140  addiu       $v1, $zero, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144d2c) {
            ctx->pc = 0x144DA0u;
            goto label_144da0;
        }
    }
    ctx->pc = 0x144D34u;
    // 0x144d34: 0x8e020828  lw          $v0, 0x828($s0)
    ctx->pc = 0x144d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x144d38: 0x24050300  addiu       $a1, $zero, 0x300
    ctx->pc = 0x144d38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
    // 0x144d3c: 0x432018  mult        $a0, $v0, $v1
    ctx->pc = 0x144d3cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x144d40: 0x901021  addu        $v0, $a0, $s0
    ctx->pc = 0x144d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x144d44: 0xc051c84  jal         func_147210
    ctx->pc = 0x144D44u;
    SET_GPR_U32(ctx, 31, 0x144D4Cu);
    ctx->pc = 0x144D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144D44u;
            // 0x144d48: 0x8c4405ac  lw          $a0, 0x5AC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1452)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147210u;
    if (runtime->hasFunction(0x147210u)) {
        auto targetFn = runtime->lookupFunction(0x147210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D4Cu; }
        if (ctx->pc != 0x144D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147210_0x147210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D4Cu; }
        if (ctx->pc != 0x144D4Cu) { return; }
    }
    ctx->pc = 0x144D4Cu;
label_144d4c:
    // 0x144d4c: 0xc051496  jal         func_145258
    ctx->pc = 0x144D4Cu;
    SET_GPR_U32(ctx, 31, 0x144D54u);
    ctx->pc = 0x144D50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144D4Cu;
            // 0x144d50: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D54u; }
        if (ctx->pc != 0x144D54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D54u; }
        if (ctx->pc != 0x144D54u) { return; }
    }
    ctx->pc = 0x144D54u;
label_144d54:
    // 0x144d54: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x144d54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144d58: 0x3c072000  lui         $a3, 0x2000
    ctx->pc = 0x144d58u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)8192 << 16));
    // 0x144d5c: 0x8e0601cc  lw          $a2, 0x1CC($s0)
    ctx->pc = 0x144d5cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 460)));
    // 0x144d60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144d60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144d64: 0x8e0301c8  lw          $v1, 0x1C8($s0)
    ctx->pc = 0x144d64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 456)));
    // 0x144d68: 0x30a50001  andi        $a1, $a1, 0x1
    ctx->pc = 0x144d68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
    // 0x144d6c: 0x8fa80020  lw          $t0, 0x20($sp)
    ctx->pc = 0x144d6cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x144d70: 0x52ec0  sll         $a1, $a1, 27
    ctx->pc = 0x144d70u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 27));
    // 0x144d74: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x144d74u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x144d78: 0x31e80  sll         $v1, $v1, 26
    ctx->pc = 0x144d78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 26));
    // 0x144d7c: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x144d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x144d80: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x144d80u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x144d84: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x144d84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x144d88: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x144d88u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x144d8c: 0x21640  sll         $v0, $v0, 25
    ctx->pc = 0x144d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 25));
    // 0x144d90: 0xc05148a  jal         func_145228
    ctx->pc = 0x144D90u;
    SET_GPR_U32(ctx, 31, 0x144D98u);
    ctx->pc = 0x144D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144D90u;
            // 0x144d94: 0xa22825  or          $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D98u; }
        if (ctx->pc != 0x144D98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D98u; }
        if (ctx->pc != 0x144D98u) { return; }
    }
    ctx->pc = 0x144D98u;
label_144d98:
    // 0x144d98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x144D98u;
    {
        const bool branch_taken_0x144d98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144D98u;
            // 0x144d9c: 0x8e020134  lw          $v0, 0x134($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144d98) {
            ctx->pc = 0x144DB8u;
            goto label_144db8;
        }
    }
    ctx->pc = 0x144DA0u;
label_144da0:
    // 0x144da0: 0x8e020828  lw          $v0, 0x828($s0)
    ctx->pc = 0x144da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x144da4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x144da4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144da8: 0x432818  mult        $a1, $v0, $v1
    ctx->pc = 0x144da8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x144dac: 0xb01021  addu        $v0, $a1, $s0
    ctx->pc = 0x144dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x144db0: 0xac4406e4  sw          $a0, 0x6E4($v0)
    ctx->pc = 0x144db0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1764), GPR_U32(ctx, 4));
    // 0x144db4: 0x8e020134  lw          $v0, 0x134($s0)
    ctx->pc = 0x144db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144db8:
    // 0x144db8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x144DB8u;
    {
        const bool branch_taken_0x144db8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x144DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144DB8u;
            // 0x144dbc: 0xae0001c8  sw          $zero, 0x1C8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 456), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144db8) {
            ctx->pc = 0x144DC8u;
            goto label_144dc8;
        }
    }
    ctx->pc = 0x144DC0u;
    // 0x144dc0: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x144DC0u;
    {
        const bool branch_taken_0x144dc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144DC0u;
            // 0x144dc4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144dc0) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144DC8u;
label_144dc8:
    // 0x144dc8: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x144dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144dcc: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x144dccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x144dd0: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x144DD0u;
    {
        const bool branch_taken_0x144dd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x144dd0) {
            ctx->pc = 0x144DD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144DD0u;
            // 0x144dd4: 0x8e020198  lw          $v0, 0x198($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144DF4u;
            goto label_144df4;
        }
    }
    ctx->pc = 0x144DD8u;
    // 0x144dd8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x144dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144ddc: 0xae0301c8  sw          $v1, 0x1C8($s0)
    ctx->pc = 0x144ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 456), GPR_U32(ctx, 3));
    // 0x144de0: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x144de0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144de4: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x144de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x144de8: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x144DE8u;
    {
        const bool branch_taken_0x144de8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x144de8) {
            ctx->pc = 0x144DECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144DE8u;
            // 0x144dec: 0x8e040168  lw          $a0, 0x168($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144E20u;
            goto label_144e20;
        }
    }
    ctx->pc = 0x144DF0u;
    // 0x144df0: 0x8e020198  lw          $v0, 0x198($s0)
    ctx->pc = 0x144df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
label_144df4:
    // 0x144df4: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x144DF4u;
    {
        const bool branch_taken_0x144df4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x144df4) {
            ctx->pc = 0x144DF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144DF4u;
            // 0x144df8: 0x8e040168  lw          $a0, 0x168($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144E20u;
            goto label_144e20;
        }
    }
    ctx->pc = 0x144DFCu;
    // 0x144dfc: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x144dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x144e00: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x144e00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x144e04: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x144e04u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x144e08: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x144e08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x144e0c: 0xae20001c  sw          $zero, 0x1C($s1)
    ctx->pc = 0x144e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
    // 0x144e10: 0xae200018  sw          $zero, 0x18($s1)
    ctx->pc = 0x144e10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 0));
    // 0x144e14: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x144e14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x144e18: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x144e18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x144e1c: 0x8e040168  lw          $a0, 0x168($s0)
    ctx->pc = 0x144e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
label_144e20:
    // 0x144e20: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x144e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x144e24: 0x14820016  bne         $a0, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x144E24u;
    {
        const bool branch_taken_0x144e24 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x144E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144E24u;
            // 0x144e28: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144e24) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144E2Cu;
    // 0x144e2c: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x144e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144e30: 0x30420009  andi        $v0, $v0, 0x9
    ctx->pc = 0x144e30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)9);
    // 0x144e34: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x144E34u;
    {
        const bool branch_taken_0x144e34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x144E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144E34u;
            // 0x144e38: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144e34) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144E3Cu;
    // 0x144e3c: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x144e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x144e40: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x144e40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x144e44: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x144e44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x144e48: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x144e48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x144e4c: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x144e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x144e50: 0x8e02018c  lw          $v0, 0x18C($s0)
    ctx->pc = 0x144e50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144e54: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x144E54u;
    {
        const bool branch_taken_0x144e54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x144E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144E54u;
            // 0x144e58: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144e54) {
            ctx->pc = 0x144E64u;
            goto label_144e64;
        }
    }
    ctx->pc = 0x144E5Cu;
    // 0x144e5c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x144E5Cu;
    {
        const bool branch_taken_0x144e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144E5Cu;
            // 0x144e60: 0xaea40000  sw          $a0, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144e5c) {
            ctx->pc = 0x144E7Cu;
            goto label_144e7c;
        }
    }
    ctx->pc = 0x144E64u;
label_144e64:
    // 0x144e64: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x144e64u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x144e68: 0x8e02018c  lw          $v0, 0x18C($s0)
    ctx->pc = 0x144e68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144e6c: 0x8fa80024  lw          $t0, 0x24($sp)
    ctx->pc = 0x144e6cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144e70: 0x38420002  xori        $v0, $v0, 0x2
    ctx->pc = 0x144e70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)2);
    // 0x144e74: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x144e74u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x144e78: 0xad020000  sw          $v0, 0x0($t0)
    ctx->pc = 0x144e78u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
label_144e7c:
    // 0x144e7c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x144e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_144e80:
    // 0x144e80: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x144e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x144e84: 0xdfbe00b0  ld          $fp, 0xB0($sp)
    ctx->pc = 0x144e84u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x144e88: 0xdfb700a0  ld          $s7, 0xA0($sp)
    ctx->pc = 0x144e88u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x144e8c: 0xdfb60090  ld          $s6, 0x90($sp)
    ctx->pc = 0x144e8cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x144e90: 0xdfb50080  ld          $s5, 0x80($sp)
    ctx->pc = 0x144e90u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x144e94: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x144e94u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x144e98: 0xdfb30060  ld          $s3, 0x60($sp)
    ctx->pc = 0x144e98u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x144e9c: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x144e9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x144ea0: 0xdfb10040  ld          $s1, 0x40($sp)
    ctx->pc = 0x144ea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x144ea4: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x144ea4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x144ea8: 0x3e00008  jr          $ra
    ctx->pc = 0x144EA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144EA8u;
            // 0x144eac: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144A84u: goto label_144a84;
            case 0x144AA0u: goto label_144aa0;
            case 0x144AB0u: goto label_144ab0;
            case 0x144ADCu: goto label_144adc;
            case 0x144AE4u: goto label_144ae4;
            case 0x144AECu: goto label_144aec;
            case 0x144B18u: goto label_144b18;
            case 0x144B1Cu: goto label_144b1c;
            case 0x144B44u: goto label_144b44;
            case 0x144B58u: goto label_144b58;
            case 0x144B70u: goto label_144b70;
            case 0x144BA0u: goto label_144ba0;
            case 0x144BA8u: goto label_144ba8;
            case 0x144BACu: goto label_144bac;
            case 0x144BB0u: goto label_144bb0;
            case 0x144BCCu: goto label_144bcc;
            case 0x144BD4u: goto label_144bd4;
            case 0x144BFCu: goto label_144bfc;
            case 0x144C3Cu: goto label_144c3c;
            case 0x144C44u: goto label_144c44;
            case 0x144C68u: goto label_144c68;
            case 0x144C6Cu: goto label_144c6c;
            case 0x144CC8u: goto label_144cc8;
            case 0x144CD0u: goto label_144cd0;
            case 0x144CF4u: goto label_144cf4;
            case 0x144CF8u: goto label_144cf8;
            case 0x144D24u: goto label_144d24;
            case 0x144D28u: goto label_144d28;
            case 0x144D2Cu: goto label_144d2c;
            case 0x144D4Cu: goto label_144d4c;
            case 0x144D54u: goto label_144d54;
            case 0x144D98u: goto label_144d98;
            case 0x144DA0u: goto label_144da0;
            case 0x144DB8u: goto label_144db8;
            case 0x144DC8u: goto label_144dc8;
            case 0x144DF4u: goto label_144df4;
            case 0x144E20u: goto label_144e20;
            case 0x144E64u: goto label_144e64;
            case 0x144E7Cu: goto label_144e7c;
            case 0x144E80u: goto label_144e80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144EB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
