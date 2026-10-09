#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167920
// Address: 0x167920 - 0x167ad0
void sub_00167920_0x167920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167920_0x167920");
#endif

    switch (ctx->pc) {
        case 0x167980u: goto label_167980;
        case 0x167994u: goto label_167994;
        case 0x1679ccu: goto label_1679cc;
        default: break;
    }

    ctx->pc = 0x167920u;

    // 0x167920: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167920u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167924: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x167924u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x167928: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167928u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16792c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16792cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x167930: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167930u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167934: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167938: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16793c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16793cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167940: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167944: 0x24871140  addiu       $a3, $a0, 0x1140
    ctx->pc = 0x167944u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x167948: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16794c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x16794cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167950: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x167950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x167954: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x167954u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x167958: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x167958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x16795c: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x16795cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x167960: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x167960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x167964: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x167964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x167968: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x167968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x16796c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16796Cu;
    {
        const bool branch_taken_0x16796c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16796Cu;
            // 0x167970: 0xc0a82d  daddu       $s5, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16796c) {
            ctx->pc = 0x167988u;
            goto label_167988;
        }
    }
    ctx->pc = 0x167974u;
    // 0x167974: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167974u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167978: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167978u;
    SET_GPR_U32(ctx, 31, 0x167980u);
    ctx->pc = 0x16797Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167978u;
            // 0x16797c: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167980u; }
        if (ctx->pc != 0x167980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167980u; }
        if (ctx->pc != 0x167980u) { return; }
    }
    ctx->pc = 0x167980u;
label_167980:
    // 0x167980: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x167980u;
    {
        const bool branch_taken_0x167980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167980u;
            // 0x167984: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167980) {
            ctx->pc = 0x167AA4u;
            goto label_167aa4;
        }
    }
    ctx->pc = 0x167988u;
label_167988:
    // 0x167988: 0x24f00010  addiu       $s0, $a3, 0x10
    ctx->pc = 0x167988u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x16798c: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x16798Cu;
    SET_GPR_U32(ctx, 31, 0x167994u);
    ctx->pc = 0x167990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16798Cu;
            // 0x167990: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167994u; }
        if (ctx->pc != 0x167994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167994u; }
        if (ctx->pc != 0x167994u) { return; }
    }
    ctx->pc = 0x167994u;
label_167994:
    // 0x167994: 0x8e140008  lw          $s4, 0x8($s0)
    ctx->pc = 0x167994u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x167998: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x167998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16799c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16799cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1679a0: 0x8e13002c  lw          $s3, 0x2C($s0)
    ctx->pc = 0x1679a0u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1679a4: 0x8e110028  lw          $s1, 0x28($s0)
    ctx->pc = 0x1679a4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1679a8: 0x8e16000c  lw          $s6, 0xC($s0)
    ctx->pc = 0x1679a8u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1679ac: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x1679acu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1679b0: 0x8e170014  lw          $s7, 0x14($s0)
    ctx->pc = 0x1679b0u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1679b4: 0x8e1e0018  lw          $fp, 0x18($s0)
    ctx->pc = 0x1679b4u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1679b8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1679b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1679bc: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1679bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1679c0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x1679c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x1679c4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1679C4u;
    SET_GPR_U32(ctx, 31, 0x1679CCu);
    ctx->pc = 0x1679C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1679C4u;
            // 0x1679c8: 0x8e100024  lw          $s0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1679CCu; }
        if (ctx->pc != 0x1679CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1679CCu; }
        if (ctx->pc != 0x1679CCu) { return; }
    }
    ctx->pc = 0x1679CCu;
label_1679cc:
    // 0x1679cc: 0x271102a  slt         $v0, $s3, $s1
    ctx->pc = 0x1679ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1679d0: 0xaeb40000  sw          $s4, 0x0($s5)
    ctx->pc = 0x1679d0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 20));
    // 0x1679d4: 0xaeb20008  sw          $s2, 0x8($s5)
    ctx->pc = 0x1679d4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 18));
    // 0x1679d8: 0xaeb60004  sw          $s6, 0x4($s5)
    ctx->pc = 0x1679d8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 22));
    // 0x1679dc: 0xaeb10024  sw          $s1, 0x24($s5)
    ctx->pc = 0x1679dcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 17));
    // 0x1679e0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1679E0u;
    {
        const bool branch_taken_0x1679e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1679E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1679E0u;
            // 0x1679e4: 0xaeb30028  sw          $s3, 0x28($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 40), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1679e0) {
            ctx->pc = 0x167A00u;
            goto label_167a00;
        }
    }
    ctx->pc = 0x1679E8u;
    // 0x1679e8: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x1679e8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
    // 0x1679ec: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x1679ecu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x1679f0: 0xaea00014  sw          $zero, 0x14($s5)
    ctx->pc = 0x1679f0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 0));
    // 0x1679f4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1679F4u;
    {
        const bool branch_taken_0x1679f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1679F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1679F4u;
            // 0x1679f8: 0xaea00018  sw          $zero, 0x18($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1679f4) {
            ctx->pc = 0x167A48u;
            goto label_167a48;
        }
    }
    ctx->pc = 0x1679FCu;
    // 0x1679fc: 0x0  nop
    ctx->pc = 0x1679fcu;
    // NOP
label_167a00:
    // 0x167a00: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x167a00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167a04: 0x203102a  slt         $v0, $s0, $v1
    ctx->pc = 0x167a04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x167a08: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x167A08u;
    {
        const bool branch_taken_0x167a08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x167a08) {
            ctx->pc = 0x167A0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167A08u;
            // 0x167a0c: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167A58u;
            goto label_167a58;
        }
    }
    ctx->pc = 0x167A10u;
    // 0x167a10: 0x701023  subu        $v0, $v1, $s0
    ctx->pc = 0x167a10u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x167a14: 0x2ac30009  slti        $v1, $s6, 0x9
    ctx->pc = 0x167a14u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x167a18: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x167a18u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167a1c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A1Cu;
    {
        const bool branch_taken_0x167a1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A1Cu;
            // 0x167a20: 0x2f01021  addu        $v0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a1c) {
            ctx->pc = 0x167A2Cu;
            goto label_167a2c;
        }
    }
    ctx->pc = 0x167A24u;
    // 0x167a24: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a28: 0x2e21021  addu        $v0, $s7, $v0
    ctx->pc = 0x167a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
label_167a2c:
    // 0x167a2c: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167a30: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A30u;
    {
        const bool branch_taken_0x167a30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A30u;
            // 0x167a34: 0x3d01021  addu        $v0, $fp, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a30) {
            ctx->pc = 0x167A40u;
            goto label_167a40;
        }
    }
    ctx->pc = 0x167A38u;
    // 0x167a38: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a3c: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x167a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167a40:
    // 0x167a40: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x167a40u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x167a44: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x167a44u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
label_167a48:
    // 0x167a48: 0xaea00010  sw          $zero, 0x10($s5)
    ctx->pc = 0x167a48u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 0));
    // 0x167a4c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x167A4Cu;
    {
        const bool branch_taken_0x167a4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A4Cu;
            // 0x167a50: 0xaea0001c  sw          $zero, 0x1C($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a4c) {
            ctx->pc = 0x167A9Cu;
            goto label_167a9c;
        }
    }
    ctx->pc = 0x167A54u;
    // 0x167a54: 0x0  nop
    ctx->pc = 0x167a54u;
    // NOP
label_167a58:
    // 0x167a58: 0x701023  subu        $v0, $v1, $s0
    ctx->pc = 0x167a58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x167a5c: 0x2ac30009  slti        $v1, $s6, 0x9
    ctx->pc = 0x167a5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x167a60: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x167a60u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167a64: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A64u;
    {
        const bool branch_taken_0x167a64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A64u;
            // 0x167a68: 0x2f01021  addu        $v0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a64) {
            ctx->pc = 0x167A74u;
            goto label_167a74;
        }
    }
    ctx->pc = 0x167A6Cu;
    // 0x167a6c: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a70: 0x2e21021  addu        $v0, $s7, $v0
    ctx->pc = 0x167a70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
label_167a74:
    // 0x167a74: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167a74u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167a78: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167A78u;
    {
        const bool branch_taken_0x167a78 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167A78u;
            // 0x167a7c: 0x3d01021  addu        $v0, $fp, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167a78) {
            ctx->pc = 0x167A88u;
            goto label_167a88;
        }
    }
    ctx->pc = 0x167A80u;
    // 0x167a80: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x167a80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x167a84: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x167a84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167a88:
    // 0x167a88: 0xaebe0020  sw          $fp, 0x20($s5)
    ctx->pc = 0x167a88u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 30));
    // 0x167a8c: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x167a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x167a90: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x167a90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167a94: 0xaeb7001c  sw          $s7, 0x1C($s5)
    ctx->pc = 0x167a94u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 23));
    // 0x167a98: 0xaea20010  sw          $v0, 0x10($s5)
    ctx->pc = 0x167a98u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 2));
label_167a9c:
    // 0x167a9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167a9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167aa0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167aa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167aa4:
    // 0x167aa4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167aa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167aa8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167aa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167aac: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x167aacu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167ab0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x167ab0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167ab4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x167ab4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x167ab8: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x167ab8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x167abc: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x167abcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x167ac0: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x167ac0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x167ac4: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x167ac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x167ac8: 0x3e00008  jr          $ra
    ctx->pc = 0x167AC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167AC8u;
            // 0x167acc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167980u: goto label_167980;
            case 0x167988u: goto label_167988;
            case 0x167994u: goto label_167994;
            case 0x1679CCu: goto label_1679cc;
            case 0x167A00u: goto label_167a00;
            case 0x167A2Cu: goto label_167a2c;
            case 0x167A40u: goto label_167a40;
            case 0x167A48u: goto label_167a48;
            case 0x167A58u: goto label_167a58;
            case 0x167A74u: goto label_167a74;
            case 0x167A88u: goto label_167a88;
            case 0x167A9Cu: goto label_167a9c;
            case 0x167AA4u: goto label_167aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167AD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
