#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B910
// Address: 0x13b910 - 0x13baa0
void sub_0013B910_0x13b910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B910_0x13b910");
#endif

    switch (ctx->pc) {
        case 0x13b974u: goto label_13b974;
        case 0x13b988u: goto label_13b988;
        case 0x13b9c0u: goto label_13b9c0;
        case 0x13ba04u: goto label_13ba04;
        case 0x13ba1cu: goto label_13ba1c;
        case 0x13ba3cu: goto label_13ba3c;
        case 0x13ba44u: goto label_13ba44;
        case 0x13ba5cu: goto label_13ba5c;
        default: break;
    }

    ctx->pc = 0x13b910u;

    // 0x13b910: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13b910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13b914: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13b914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13b918: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13b918u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b91c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13b91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13b920: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13b920u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b924: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13b924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13b928: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x13b928u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b92c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b930: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13b930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13b934: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13b934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13b938: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B938u;
    {
        const bool branch_taken_0x13b938 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B938u;
            // 0x13b93c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b938) {
            ctx->pc = 0x13B950u;
            goto label_13b950;
        }
    }
    ctx->pc = 0x13B940u;
    // 0x13b940: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b940u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b944: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x13B944u;
    {
        const bool branch_taken_0x13b944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B944u;
            // 0x13b948: 0x24a5d0b0  addiu       $a1, $a1, -0x2F50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b944) {
            ctx->pc = 0x13B96Cu;
            goto label_13b96c;
        }
    }
    ctx->pc = 0x13B94Cu;
    // 0x13b94c: 0x0  nop
    ctx->pc = 0x13b94cu;
    // NOP
label_13b950:
    // 0x13b950: 0x6410003  bgez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x13B950u;
    {
        const bool branch_taken_0x13b950 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x13B954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B950u;
            // 0x13b954: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b950) {
            ctx->pc = 0x13B960u;
            goto label_13b960;
        }
    }
    ctx->pc = 0x13B958u;
    // 0x13b958: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13B958u;
    {
        const bool branch_taken_0x13b958 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B95Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B958u;
            // 0x13b95c: 0x24a5d0c8  addiu       $a1, $a1, -0x2F38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955208));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b958) {
            ctx->pc = 0x13B96Cu;
            goto label_13b96c;
        }
    }
    ctx->pc = 0x13B960u;
label_13b960:
    // 0x13b960: 0x16600007  bnez        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x13B960u;
    {
        const bool branch_taken_0x13b960 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B960u;
            // 0x13b964: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b960) {
            ctx->pc = 0x13B980u;
            goto label_13b980;
        }
    }
    ctx->pc = 0x13B968u;
    // 0x13b968: 0x24a5d0e8  addiu       $a1, $a1, -0x2F18
    ctx->pc = 0x13b968u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955240));
label_13b96c:
    // 0x13b96c: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B96Cu;
    SET_GPR_U32(ctx, 31, 0x13B974u);
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B974u; }
        if (ctx->pc != 0x13B974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B974u; }
        if (ctx->pc != 0x13B974u) { return; }
    }
    ctx->pc = 0x13B974u;
label_13b974:
    // 0x13b974: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x13B974u;
    {
        const bool branch_taken_0x13b974 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B974u;
            // 0x13b978: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b974) {
            ctx->pc = 0x13BA7Cu;
            goto label_13ba7c;
        }
    }
    ctx->pc = 0x13B97Cu;
    // 0x13b97c: 0x0  nop
    ctx->pc = 0x13b97cu;
    // NOP
label_13b980:
    // 0x13b980: 0xc04ebfe  jal         func_13AFF8
    ctx->pc = 0x13B980u;
    SET_GPR_U32(ctx, 31, 0x13B988u);
    ctx->pc = 0x13B984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B980u;
            // 0x13b984: 0x24140001  addiu       $s4, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFF8u;
    if (runtime->hasFunction(0x13AFF8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B988u; }
        if (ctx->pc != 0x13B988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFF8_0x13aff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B988u; }
        if (ctx->pc != 0x13B988u) { return; }
    }
    ctx->pc = 0x13B988u;
label_13b988:
    // 0x13b988: 0x54540003  bnel        $v0, $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x13B988u;
    {
        const bool branch_taken_0x13b988 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0x13b988) {
            ctx->pc = 0x13B98Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B988u;
            // 0x13b98c: 0x82230002  lb          $v1, 0x2($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B998u;
            goto label_13b998;
        }
    }
    ctx->pc = 0x13B990u;
    // 0x13b990: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x13B990u;
    {
        const bool branch_taken_0x13b990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B990u;
            // 0x13b994: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b990) {
            ctx->pc = 0x13BA7Cu;
            goto label_13ba7c;
        }
    }
    ctx->pc = 0x13B998u;
label_13b998:
    // 0x13b998: 0x24150002  addiu       $s5, $zero, 0x2
    ctx->pc = 0x13b998u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13b99c: 0x10750037  beq         $v1, $s5, . + 4 + (0x37 << 2)
    ctx->pc = 0x13B99Cu;
    {
        const bool branch_taken_0x13b99c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 21));
        ctx->pc = 0x13B9A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B99Cu;
            // 0x13b9a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b99c) {
            ctx->pc = 0x13BA7Cu;
            goto label_13ba7c;
        }
    }
    ctx->pc = 0x13B9A4u;
    // 0x13b9a4: 0x16400004  bnez        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13B9A4u;
    {
        const bool branch_taken_0x13b9a4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x13b9a4) {
            ctx->pc = 0x13B9B8u;
            goto label_13b9b8;
        }
    }
    ctx->pc = 0x13B9ACu;
    // 0x13b9ac: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x13B9ACu;
    {
        const bool branch_taken_0x13b9ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B9ACu;
            // 0x13b9b0: 0xa2340002  sb          $s4, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b9ac) {
            ctx->pc = 0x13BA7Cu;
            goto label_13ba7c;
        }
    }
    ctx->pc = 0x13B9B4u;
    // 0x13b9b4: 0x0  nop
    ctx->pc = 0x13b9b4u;
    // NOP
label_13b9b8:
    // 0x13b9b8: 0xc04dcd0  jal         func_137340
    ctx->pc = 0x13B9B8u;
    SET_GPR_U32(ctx, 31, 0x13B9C0u);
    ctx->pc = 0x137340u;
    if (runtime->hasFunction(0x137340u)) {
        auto targetFn = runtime->lookupFunction(0x137340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B9C0u; }
        if (ctx->pc != 0x13B9C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137340_0x137340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B9C0u; }
        if (ctx->pc != 0x13B9C0u) { return; }
    }
    ctx->pc = 0x13B9C0u;
label_13b9c0:
    // 0x13b9c0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x13b9c0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b9c4: 0x1060002d  beqz        $v1, . + 4 + (0x2D << 2)
    ctx->pc = 0x13B9C4u;
    {
        const bool branch_taken_0x13b9c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B9C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B9C4u;
            // 0x13b9c8: 0xae23002c  sw          $v1, 0x2C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b9c4) {
            ctx->pc = 0x13BA7Cu;
            goto label_13ba7c;
        }
    }
    ctx->pc = 0x13B9CCu;
    // 0x13b9cc: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x13b9ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x13b9d0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x13b9d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b9d4: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x13b9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x13b9d8: 0x1282c0  sll         $s0, $s2, 11
    ctx->pc = 0x13b9d8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 18), 11));
    // 0x13b9dc: 0xde270008  ld          $a3, 0x8($s1)
    ctx->pc = 0x13b9dcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x13b9e0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13b9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13b9e4: 0xae330020  sw          $s3, 0x20($s1)
    ctx->pc = 0x13b9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 19));
    // 0x13b9e8: 0x242182a  slt         $v1, $s2, $v0
    ctx->pc = 0x13b9e8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13b9ec: 0xf0302b  sltu        $a2, $a3, $s0
    ctx->pc = 0x13b9ecu;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x13b9f0: 0x43280a  movz        $a1, $v0, $v1
    ctx->pc = 0x13b9f0u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x13b9f4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b9f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b9f8: 0xae250024  sw          $a1, 0x24($s1)
    ctx->pc = 0x13b9f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 5));
    // 0x13b9fc: 0xc04ec2c  jal         func_13B0B0
    ctx->pc = 0x13B9FCu;
    SET_GPR_U32(ctx, 31, 0x13BA04u);
    ctx->pc = 0x13BA00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B9FCu;
            // 0x13ba00: 0xe6800b  movn        $s0, $a3, $a2 (Delay Slot)
        if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B0B0u;
    if (runtime->hasFunction(0x13B0B0u)) {
        auto targetFn = runtime->lookupFunction(0x13B0B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA04u; }
        if (ctx->pc != 0x13BA04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B0B0_0x13b0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA04u; }
        if (ctx->pc != 0x13BA04u) { return; }
    }
    ctx->pc = 0x13BA04u;
label_13ba04:
    // 0x13ba04: 0x8e24002c  lw          $a0, 0x2C($s1)
    ctx->pc = 0x13ba04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x13ba08: 0x8e250018  lw          $a1, 0x18($s1)
    ctx->pc = 0x13ba08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x13ba0c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x13ba0cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ba10: 0x8e26001c  lw          $a2, 0x1C($s1)
    ctx->pc = 0x13ba10u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x13ba14: 0xc04dd56  jal         func_137558
    ctx->pc = 0x13BA14u;
    SET_GPR_U32(ctx, 31, 0x13BA1Cu);
    ctx->pc = 0x13BA18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA14u;
            // 0x13ba18: 0x260402d  daddu       $t0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137558u;
    if (runtime->hasFunction(0x137558u)) {
        auto targetFn = runtime->lookupFunction(0x137558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA1Cu; }
        if (ctx->pc != 0x13BA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137558_0x137558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA1Cu; }
        if (ctx->pc != 0x13BA1Cu) { return; }
    }
    ctx->pc = 0x13BA1Cu;
label_13ba1c:
    // 0x13ba1c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x13BA1Cu;
    {
        const bool branch_taken_0x13ba1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA1Cu;
            // 0x13ba20: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ba1c) {
            ctx->pc = 0x13BA80u;
            goto label_13ba80;
        }
    }
    ctx->pc = 0x13BA24u;
    // 0x13ba24: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ba24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ba28: 0x8c50dea0  lw          $s0, -0x2160($v0)
    ctx->pc = 0x13ba28u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958752)));
    // 0x13ba2c: 0x56140010  bnel        $s0, $s4, . + 4 + (0x10 << 2)
    ctx->pc = 0x13BA2Cu;
    {
        const bool branch_taken_0x13ba2c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 20));
        if (branch_taken_0x13ba2c) {
            ctx->pc = 0x13BA30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA2Cu;
            // 0x13ba30: 0xa2350002  sb          $s5, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BA70u;
            goto label_13ba70;
        }
    }
    ctx->pc = 0x13BA34u;
    // 0x13ba34: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x13BA34u;
    SET_GPR_U32(ctx, 31, 0x13BA3Cu);
    ctx->pc = 0x137E90u;
    if (runtime->hasFunction(0x137E90u)) {
        auto targetFn = runtime->lookupFunction(0x137E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA3Cu; }
        if (ctx->pc != 0x13BA3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137E90_0x137e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA3Cu; }
        if (ctx->pc != 0x13BA3Cu) { return; }
    }
    ctx->pc = 0x13BA3Cu;
label_13ba3c:
    // 0x13ba3c: 0xc04df60  jal         func_137D80
    ctx->pc = 0x13BA3Cu;
    SET_GPR_U32(ctx, 31, 0x13BA44u);
    ctx->pc = 0x137D80u;
    if (runtime->hasFunction(0x137D80u)) {
        auto targetFn = runtime->lookupFunction(0x137D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA44u; }
        if (ctx->pc != 0x13BA44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA44u; }
        if (ctx->pc != 0x13BA44u) { return; }
    }
    ctx->pc = 0x13BA44u;
label_13ba44:
    // 0x13ba44: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x13ba44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x13ba48: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x13ba48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ba4c: 0x8e24002c  lw          $a0, 0x2C($s1)
    ctx->pc = 0x13ba4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x13ba50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13ba50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13ba54: 0xc04dcf2  jal         func_1373C8
    ctx->pc = 0x13BA54u;
    SET_GPR_U32(ctx, 31, 0x13BA5Cu);
    ctx->pc = 0x13BA58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA54u;
            // 0x13ba58: 0xae22001c  sw          $v0, 0x1C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1373C8u;
    if (runtime->hasFunction(0x1373C8u)) {
        auto targetFn = runtime->lookupFunction(0x1373C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA5Cu; }
        if (ctx->pc != 0x13BA5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001373C8_0x1373c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BA5Cu; }
        if (ctx->pc != 0x13BA5Cu) { return; }
    }
    ctx->pc = 0x13BA5Cu;
label_13ba5c:
    // 0x13ba5c: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x13ba5cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x13ba60: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x13ba60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ba64: 0xa2300002  sb          $s0, 0x2($s1)
    ctx->pc = 0x13ba64u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 16));
    // 0x13ba68: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x13BA68u;
    {
        const bool branch_taken_0x13ba68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA68u;
            // 0x13ba6c: 0xae220028  sw          $v0, 0x28($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ba68) {
            ctx->pc = 0x13BA78u;
            goto label_13ba78;
        }
    }
    ctx->pc = 0x13BA70u;
label_13ba70:
    // 0x13ba70: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x13ba70u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x13ba74: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x13ba74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
label_13ba78:
    // 0x13ba78: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x13ba78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
label_13ba7c:
    // 0x13ba7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ba7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13ba80:
    // 0x13ba80: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ba80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ba84: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ba84u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ba88: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ba88u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ba8c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13ba8cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ba90: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13ba90u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13ba94: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13ba94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13ba98: 0x3e00008  jr          $ra
    ctx->pc = 0x13BA98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BA98u;
            // 0x13ba9c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B950u: goto label_13b950;
            case 0x13B960u: goto label_13b960;
            case 0x13B96Cu: goto label_13b96c;
            case 0x13B974u: goto label_13b974;
            case 0x13B980u: goto label_13b980;
            case 0x13B988u: goto label_13b988;
            case 0x13B998u: goto label_13b998;
            case 0x13B9B8u: goto label_13b9b8;
            case 0x13B9C0u: goto label_13b9c0;
            case 0x13BA04u: goto label_13ba04;
            case 0x13BA1Cu: goto label_13ba1c;
            case 0x13BA3Cu: goto label_13ba3c;
            case 0x13BA44u: goto label_13ba44;
            case 0x13BA5Cu: goto label_13ba5c;
            case 0x13BA70u: goto label_13ba70;
            case 0x13BA78u: goto label_13ba78;
            case 0x13BA7Cu: goto label_13ba7c;
            case 0x13BA80u: goto label_13ba80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BAA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
