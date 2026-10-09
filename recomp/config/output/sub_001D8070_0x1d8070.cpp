#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8070
// Address: 0x1d8070 - 0x1d8180
void sub_001D8070_0x1d8070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8070_0x1d8070");
#endif

    switch (ctx->pc) {
        case 0x1d8098u: goto label_1d8098;
        case 0x1d80ccu: goto label_1d80cc;
        case 0x1d8104u: goto label_1d8104;
        case 0x1d810cu: goto label_1d810c;
        case 0x1d813cu: goto label_1d813c;
        case 0x1d8158u: goto label_1d8158;
        case 0x1d8160u: goto label_1d8160;
        default: break;
    }

    ctx->pc = 0x1d8070u;

    // 0x1d8070: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d8070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d8074: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d8074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d8078: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d8078u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d807c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d807cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d8080: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8080u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8084: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d8084u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8088: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d808c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d808cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8090: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8090u;
    SET_GPR_U32(ctx, 31, 0x1D8098u);
    ctx->pc = 0x1D8094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8090u;
            // 0x1d8094: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8098u; }
        if (ctx->pc != 0x1D8098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8098u; }
        if (ctx->pc != 0x1D8098u) { return; }
    }
    ctx->pc = 0x1D8098u;
label_1d8098:
    // 0x1d8098: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d8098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d809c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d809cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d80a0: 0x24420026  addiu       $v0, $v0, 0x26
    ctx->pc = 0x1d80a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 38));
    // 0x1d80a4: 0x2c411001  sltiu       $at, $v0, 0x1001
    ctx->pc = 0x1d80a4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4097) ? 1 : 0);
    // 0x1d80a8: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D80A8u;
    {
        const bool branch_taken_0x1d80a8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d80a8) {
            ctx->pc = 0x1D80B8u;
            goto label_1d80b8;
        }
    }
    ctx->pc = 0x1D80B0u;
    // 0x1d80b0: 0x24100fd9  addiu       $s0, $zero, 0xFD9
    ctx->pc = 0x1d80b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4057));
    // 0x1d80b4: 0x0  nop
    ctx->pc = 0x1d80b4u;
    // NOP
label_1d80b8:
    // 0x1d80b8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d80b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d80bc: 0x24846280  addiu       $a0, $a0, 0x6280
    ctx->pc = 0x1d80bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25216));
    // 0x1d80c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d80c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d80c4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D80C4u;
    SET_GPR_U32(ctx, 31, 0x1D80CCu);
    ctx->pc = 0x1D80C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D80C4u;
            // 0x1d80c8: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D80CCu; }
        if (ctx->pc != 0x1D80CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D80CCu; }
        if (ctx->pc != 0x1D80CCu) { return; }
    }
    ctx->pc = 0x1D80CCu;
label_1d80cc:
    // 0x1d80cc: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d80ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d80d0: 0x109c3c  dsll32      $s3, $s0, 16
    ctx->pc = 0x1d80d0u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d80d4: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d80d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d80d8: 0x139c3f  dsra32      $s3, $s3, 16
    ctx->pc = 0x1d80d8u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
    // 0x1d80dc: 0xa4520000  sh          $s2, 0x0($v0)
    ctx->pc = 0x1d80dcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1d80e0: 0x26660026  addiu       $a2, $s3, 0x26
    ctx->pc = 0x1d80e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 38));
    // 0x1d80e4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d80e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d80e8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d80e8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d80ec: 0xa4500002  sh          $s0, 0x2($v0)
    ctx->pc = 0x1d80ecu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 16));
    // 0x1d80f0: 0x24040013  addiu       $a0, $zero, 0x13
    ctx->pc = 0x1d80f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1d80f4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d80f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d80f8: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d80f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d80fc: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D80FCu;
    SET_GPR_U32(ctx, 31, 0x1D8104u);
    ctx->pc = 0x1D8100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D80FCu;
            // 0x1d8100: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8104u; }
        if (ctx->pc != 0x1D8104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8104u; }
        if (ctx->pc != 0x1D8104u) { return; }
    }
    ctx->pc = 0x1D8104u;
label_1d8104:
    // 0x1d8104: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1D8104u;
    SET_GPR_U32(ctx, 31, 0x1D810Cu);
    ctx->pc = 0x1D8108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8104u;
            // 0x1d8108: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D810Cu; }
        if (ctx->pc != 0x1D810Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D810Cu; }
        if (ctx->pc != 0x1D810Cu) { return; }
    }
    ctx->pc = 0x1D810Cu;
label_1d810c:
    // 0x1d810c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d810cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8110: 0x3c120034  lui         $s2, 0x34
    ctx->pc = 0x1d8110u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)52 << 16));
    // 0x1d8114: 0x8c226298  lw          $v0, 0x6298($at)
    ctx->pc = 0x1d8114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25240)));
    // 0x1d8118: 0x262082a  slt         $at, $s3, $v0
    ctx->pc = 0x1d8118u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d811c: 0x14200004  bnez        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D811Cu;
    {
        const bool branch_taken_0x1d811c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D8120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D811Cu;
            // 0x1d8120: 0x2652629c  addiu       $s2, $s2, 0x629C (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 25244));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d811c) {
            ctx->pc = 0x1D8130u;
            goto label_1d8130;
        }
    }
    ctx->pc = 0x1D8124u;
    // 0x1d8124: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x1d8124u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d8128: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D8128u;
    {
        const bool branch_taken_0x1d8128 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D812Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8128u;
            // 0x1d812c: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8128) {
            ctx->pc = 0x1D8140u;
            goto label_1d8140;
        }
    }
    ctx->pc = 0x1D8130u;
label_1d8130:
    // 0x1d8130: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1d8130u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1d8134: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1D8134u;
    SET_GPR_U32(ctx, 31, 0x1D813Cu);
    ctx->pc = 0x1D8138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8134u;
            // 0x1d8138: 0x248469b0  addiu       $a0, $a0, 0x69B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D813Cu; }
        if (ctx->pc != 0x1D813Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D813Cu; }
        if (ctx->pc != 0x1D813Cu) { return; }
    }
    ctx->pc = 0x1D813Cu;
label_1d813c:
    // 0x1d813c: 0x0  nop
    ctx->pc = 0x1d813cu;
    // NOP
label_1d8140:
    // 0x1d8140: 0x10343c  dsll32      $a2, $s0, 16
    ctx->pc = 0x1d8140u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d8144: 0x6343f  dsra32      $a2, $a2, 16
    ctx->pc = 0x1d8144u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x1d8148: 0x18c00003  blez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D8148u;
    {
        const bool branch_taken_0x1d8148 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D814Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8148u;
            // 0x1d814c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8148) {
            ctx->pc = 0x1D8158u;
            goto label_1d8158;
        }
    }
    ctx->pc = 0x1D8150u;
    // 0x1d8150: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D8150u;
    SET_GPR_U32(ctx, 31, 0x1D8158u);
    ctx->pc = 0x1D8154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8150u;
            // 0x1d8154: 0x26450004  addiu       $a1, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8158u; }
        if (ctx->pc != 0x1D8158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8158u; }
        if (ctx->pc != 0x1D8158u) { return; }
    }
    ctx->pc = 0x1D8158u;
label_1d8158:
    // 0x1d8158: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8158u;
    SET_GPR_U32(ctx, 31, 0x1D8160u);
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8160u; }
        if (ctx->pc != 0x1D8160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8160u; }
        if (ctx->pc != 0x1D8160u) { return; }
    }
    ctx->pc = 0x1D8160u;
label_1d8160:
    // 0x1d8160: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8160u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8164: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d8164u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8168: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8168u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d816c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d816cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8170: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8170u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8174: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8174u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8178: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8178u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D817Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8178u;
            // 0x1d817c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8098u: goto label_1d8098;
            case 0x1D80B8u: goto label_1d80b8;
            case 0x1D80CCu: goto label_1d80cc;
            case 0x1D8104u: goto label_1d8104;
            case 0x1D810Cu: goto label_1d810c;
            case 0x1D8130u: goto label_1d8130;
            case 0x1D813Cu: goto label_1d813c;
            case 0x1D8140u: goto label_1d8140;
            case 0x1D8158u: goto label_1d8158;
            case 0x1D8160u: goto label_1d8160;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8180u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
