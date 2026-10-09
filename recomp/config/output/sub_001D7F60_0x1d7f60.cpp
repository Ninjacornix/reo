#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7F60
// Address: 0x1d7f60 - 0x1d8070
void sub_001D7F60_0x1d7f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7F60_0x1d7f60");
#endif

    switch (ctx->pc) {
        case 0x1d7f88u: goto label_1d7f88;
        case 0x1d7fbcu: goto label_1d7fbc;
        case 0x1d7ff4u: goto label_1d7ff4;
        case 0x1d7ffcu: goto label_1d7ffc;
        case 0x1d802cu: goto label_1d802c;
        case 0x1d8048u: goto label_1d8048;
        case 0x1d8050u: goto label_1d8050;
        default: break;
    }

    ctx->pc = 0x1d7f60u;

    // 0x1d7f60: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d7f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d7f64: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d7f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d7f68: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d7f68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d7f6c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d7f6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d7f70: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d7f70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d7f74: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d7f74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7f78: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7f78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7f7c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d7f7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7f80: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7F80u;
    SET_GPR_U32(ctx, 31, 0x1D7F88u);
    ctx->pc = 0x1D7F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7F80u;
            // 0x1d7f84: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F88u; }
        if (ctx->pc != 0x1D7F88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F88u; }
        if (ctx->pc != 0x1D7F88u) { return; }
    }
    ctx->pc = 0x1D7F88u;
label_1d7f88:
    // 0x1d7f88: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d7f88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d7f8c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7f8cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7f90: 0x24420026  addiu       $v0, $v0, 0x26
    ctx->pc = 0x1d7f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 38));
    // 0x1d7f94: 0x2c411001  sltiu       $at, $v0, 0x1001
    ctx->pc = 0x1d7f94u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4097) ? 1 : 0);
    // 0x1d7f98: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7F98u;
    {
        const bool branch_taken_0x1d7f98 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d7f98) {
            ctx->pc = 0x1D7FA8u;
            goto label_1d7fa8;
        }
    }
    ctx->pc = 0x1D7FA0u;
    // 0x1d7fa0: 0x24100fd9  addiu       $s0, $zero, 0xFD9
    ctx->pc = 0x1d7fa0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4057));
    // 0x1d7fa4: 0x0  nop
    ctx->pc = 0x1d7fa4u;
    // NOP
label_1d7fa8:
    // 0x1d7fa8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d7fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d7fac: 0x24846280  addiu       $a0, $a0, 0x6280
    ctx->pc = 0x1d7facu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25216));
    // 0x1d7fb0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d7fb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7fb4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D7FB4u;
    SET_GPR_U32(ctx, 31, 0x1D7FBCu);
    ctx->pc = 0x1D7FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7FB4u;
            // 0x1d7fb8: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FBCu; }
        if (ctx->pc != 0x1D7FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FBCu; }
        if (ctx->pc != 0x1D7FBCu) { return; }
    }
    ctx->pc = 0x1D7FBCu;
label_1d7fbc:
    // 0x1d7fbc: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d7fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d7fc0: 0x109c3c  dsll32      $s3, $s0, 16
    ctx->pc = 0x1d7fc0u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d7fc4: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d7fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d7fc8: 0x139c3f  dsra32      $s3, $s3, 16
    ctx->pc = 0x1d7fc8u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
    // 0x1d7fcc: 0xa4520000  sh          $s2, 0x0($v0)
    ctx->pc = 0x1d7fccu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1d7fd0: 0x26660026  addiu       $a2, $s3, 0x26
    ctx->pc = 0x1d7fd0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 38));
    // 0x1d7fd4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7fd8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7fd8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7fdc: 0xa4500002  sh          $s0, 0x2($v0)
    ctx->pc = 0x1d7fdcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 16));
    // 0x1d7fe0: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d7fe0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d7fe4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7fe8: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7fe8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7fec: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7FECu;
    SET_GPR_U32(ctx, 31, 0x1D7FF4u);
    ctx->pc = 0x1D7FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7FECu;
            // 0x1d7ff0: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FF4u; }
        if (ctx->pc != 0x1D7FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FF4u; }
        if (ctx->pc != 0x1D7FF4u) { return; }
    }
    ctx->pc = 0x1D7FF4u;
label_1d7ff4:
    // 0x1d7ff4: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1D7FF4u;
    SET_GPR_U32(ctx, 31, 0x1D7FFCu);
    ctx->pc = 0x1D7FF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7FF4u;
            // 0x1d7ff8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FFCu; }
        if (ctx->pc != 0x1D7FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7FFCu; }
        if (ctx->pc != 0x1D7FFCu) { return; }
    }
    ctx->pc = 0x1D7FFCu;
label_1d7ffc:
    // 0x1d7ffc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7ffcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8000: 0x3c120034  lui         $s2, 0x34
    ctx->pc = 0x1d8000u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)52 << 16));
    // 0x1d8004: 0x8c226298  lw          $v0, 0x6298($at)
    ctx->pc = 0x1d8004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25240)));
    // 0x1d8008: 0x262082a  slt         $at, $s3, $v0
    ctx->pc = 0x1d8008u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d800c: 0x14200004  bnez        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D800Cu;
    {
        const bool branch_taken_0x1d800c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D8010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D800Cu;
            // 0x1d8010: 0x2652629c  addiu       $s2, $s2, 0x629C (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 25244));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d800c) {
            ctx->pc = 0x1D8020u;
            goto label_1d8020;
        }
    }
    ctx->pc = 0x1D8014u;
    // 0x1d8014: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x1d8014u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d8018: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D8018u;
    {
        const bool branch_taken_0x1d8018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D801Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8018u;
            // 0x1d801c: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8018) {
            ctx->pc = 0x1D8030u;
            goto label_1d8030;
        }
    }
    ctx->pc = 0x1D8020u;
label_1d8020:
    // 0x1d8020: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1d8020u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1d8024: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1D8024u;
    SET_GPR_U32(ctx, 31, 0x1D802Cu);
    ctx->pc = 0x1D8028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8024u;
            // 0x1d8028: 0x248469b0  addiu       $a0, $a0, 0x69B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D802Cu; }
        if (ctx->pc != 0x1D802Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D802Cu; }
        if (ctx->pc != 0x1D802Cu) { return; }
    }
    ctx->pc = 0x1D802Cu;
label_1d802c:
    // 0x1d802c: 0x0  nop
    ctx->pc = 0x1d802cu;
    // NOP
label_1d8030:
    // 0x1d8030: 0x10343c  dsll32      $a2, $s0, 16
    ctx->pc = 0x1d8030u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d8034: 0x6343f  dsra32      $a2, $a2, 16
    ctx->pc = 0x1d8034u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x1d8038: 0x18c00003  blez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D8038u;
    {
        const bool branch_taken_0x1d8038 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D803Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8038u;
            // 0x1d803c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8038) {
            ctx->pc = 0x1D8048u;
            goto label_1d8048;
        }
    }
    ctx->pc = 0x1D8040u;
    // 0x1d8040: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D8040u;
    SET_GPR_U32(ctx, 31, 0x1D8048u);
    ctx->pc = 0x1D8044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8040u;
            // 0x1d8044: 0x26450004  addiu       $a1, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8048u; }
        if (ctx->pc != 0x1D8048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8048u; }
        if (ctx->pc != 0x1D8048u) { return; }
    }
    ctx->pc = 0x1D8048u;
label_1d8048:
    // 0x1d8048: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8048u;
    SET_GPR_U32(ctx, 31, 0x1D8050u);
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8050u; }
        if (ctx->pc != 0x1D8050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8050u; }
        if (ctx->pc != 0x1D8050u) { return; }
    }
    ctx->pc = 0x1D8050u;
label_1d8050:
    // 0x1d8050: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8050u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8054: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d8054u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8058: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8058u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d805c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d805cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8060: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8060u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8064: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8064u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8068: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D806Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8068u;
            // 0x1d806c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7F88u: goto label_1d7f88;
            case 0x1D7FA8u: goto label_1d7fa8;
            case 0x1D7FBCu: goto label_1d7fbc;
            case 0x1D7FF4u: goto label_1d7ff4;
            case 0x1D7FFCu: goto label_1d7ffc;
            case 0x1D8020u: goto label_1d8020;
            case 0x1D802Cu: goto label_1d802c;
            case 0x1D8030u: goto label_1d8030;
            case 0x1D8048u: goto label_1d8048;
            case 0x1D8050u: goto label_1d8050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8070u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
