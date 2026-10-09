#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA080
// Address: 0x1da080 - 0x1da1fc
void sub_001DA080_0x1da080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA080_0x1da080");
#endif

    switch (ctx->pc) {
        case 0x1da128u: goto label_1da128;
        case 0x1da13cu: goto label_1da13c;
        case 0x1da180u: goto label_1da180;
        case 0x1da1b4u: goto label_1da1b4;
        default: break;
    }

    ctx->pc = 0x1da080u;

    // 0x1da080: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1da080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1da084: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1da084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1da088: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1da088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1da08c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1da08cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1da090: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1da090u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da094: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1da094u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1da098: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1da098u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da09c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1da09cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1da0a0: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1DA0A0u;
    {
        const bool branch_taken_0x1da0a0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1DA0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0A0u;
            // 0x1da0a4: 0xa7a0005e  sh          $zero, 0x5E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 94), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0a0) {
            ctx->pc = 0x1DA0B8u;
            goto label_1da0b8;
        }
    }
    ctx->pc = 0x1DA0A8u;
    // 0x1da0a8: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1da0a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1da0ac: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DA0ACu;
    {
        const bool branch_taken_0x1da0ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da0ac) {
            ctx->pc = 0x1DA0D0u;
            goto label_1da0d0;
        }
    }
    ctx->pc = 0x1DA0B4u;
    // 0x1da0b4: 0x0  nop
    ctx->pc = 0x1da0b4u;
    // NOP
label_1da0b8:
    // 0x1da0b8: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1da0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1da0bc: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da0bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da0c0: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da0c4: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1DA0C4u;
    {
        const bool branch_taken_0x1da0c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA0C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0C4u;
            // 0x1da0c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0c4) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA0CCu;
    // 0x1da0cc: 0x0  nop
    ctx->pc = 0x1da0ccu;
    // NOP
label_1da0d0:
    // 0x1da0d0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da0d4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1da0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1da0d8: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da0dc: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1da0dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1da0e0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1da0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da0e4: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA0E4u;
    {
        const bool branch_taken_0x1da0e4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0E4u;
            // 0x1da0e8: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0e4) {
            ctx->pc = 0x1DA100u;
            goto label_1da100;
        }
    }
    ctx->pc = 0x1DA0ECu;
    // 0x1da0ec: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da0ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da0f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da0f4: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1DA0F4u;
    {
        const bool branch_taken_0x1da0f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA0F4u;
            // 0x1da0f8: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da0f4) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA0FCu;
    // 0x1da0fc: 0x0  nop
    ctx->pc = 0x1da0fcu;
    // NOP
label_1da100:
    // 0x1da100: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1da100u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da104: 0x220182d  daddu       $v1, $s1, $zero
    ctx->pc = 0x1da104u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da108: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x1da108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1da10c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1da10cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da110: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1da110u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1da114: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da114u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da118: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1da118u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1da11c: 0x10200020  beqz        $at, . + 4 + (0x20 << 2)
    ctx->pc = 0x1DA11Cu;
    {
        const bool branch_taken_0x1da11c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA11Cu;
            // 0x1da120: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da11c) {
            ctx->pc = 0x1DA1A0u;
            goto label_1da1a0;
        }
    }
    ctx->pc = 0x1DA124u;
    // 0x1da124: 0x0  nop
    ctx->pc = 0x1da124u;
    // NOP
label_1da128:
    // 0x1da128: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1da128u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da12c: 0x27a5005e  addiu       $a1, $sp, 0x5E
    ctx->pc = 0x1da12cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 94));
    // 0x1da130: 0x27a6005c  addiu       $a2, $sp, 0x5C
    ctx->pc = 0x1da130u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    // 0x1da134: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1DA134u;
    SET_GPR_U32(ctx, 31, 0x1DA13Cu);
    ctx->pc = 0x1DA138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA134u;
            // 0x1da138: 0x27a7005a  addiu       $a3, $sp, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 90));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA13Cu; }
        if (ctx->pc != 0x1DA13Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA13Cu; }
        if (ctx->pc != 0x1DA13Cu) { return; }
    }
    ctx->pc = 0x1DA13Cu;
label_1da13c:
    // 0x1da13c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1da13cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da140: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da140u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da144: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA144u;
    {
        const bool branch_taken_0x1da144 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA144u;
            // 0x1da148: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da144) {
            ctx->pc = 0x1DA160u;
            goto label_1da160;
        }
    }
    ctx->pc = 0x1DA14Cu;
    // 0x1da14c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da14cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da150: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da154: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1DA154u;
    {
        const bool branch_taken_0x1da154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA154u;
            // 0x1da158: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da154) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA15Cu;
    // 0x1da15c: 0x0  nop
    ctx->pc = 0x1da15cu;
    // NOP
label_1da160:
    // 0x1da160: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1da160u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1da164: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1da164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1da168: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA168u;
    {
        const bool branch_taken_0x1da168 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1DA16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA168u;
            // 0x1da16c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da168) {
            ctx->pc = 0x1DA178u;
            goto label_1da178;
        }
    }
    ctx->pc = 0x1DA170u;
    // 0x1da170: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1DA170u;
    {
        const bool branch_taken_0x1da170 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1da170) {
            ctx->pc = 0x1DA1A0u;
            goto label_1da1a0;
        }
    }
    ctx->pc = 0x1DA178u;
label_1da178:
    // 0x1da178: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1DA178u;
    SET_GPR_U32(ctx, 31, 0x1DA180u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA180u; }
        if (ctx->pc != 0x1DA180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA180u; }
        if (ctx->pc != 0x1DA180u) { return; }
    }
    ctx->pc = 0x1DA180u;
label_1da180:
    // 0x1da180: 0x220182d  daddu       $v1, $s1, $zero
    ctx->pc = 0x1da180u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da184: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x1da184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1da188: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1da188u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da18c: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1da18cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1da190: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da190u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da194: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1da194u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1da198: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1DA198u;
    {
        const bool branch_taken_0x1da198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1DA19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA198u;
            // 0x1da19c: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da198) {
            ctx->pc = 0x1DA128u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1da128;
        }
    }
    ctx->pc = 0x1DA1A0u;
label_1da1a0:
    // 0x1da1a0: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1da1a0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1da1a4: 0x12343c  dsll32      $a2, $s2, 16
    ctx->pc = 0x1da1a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 18) << (32 + 16));
    // 0x1da1a8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1da1a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da1ac: 0xc075f70  jal         func_1D7DC0
    ctx->pc = 0x1DA1ACu;
    SET_GPR_U32(ctx, 31, 0x1DA1B4u);
    ctx->pc = 0x1DA1B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1ACu;
            // 0x1da1b0: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7DC0u;
    if (runtime->hasFunction(0x1D7DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA1B4u; }
        if (ctx->pc != 0x1DA1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7DC0_0x1d7dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA1B4u; }
        if (ctx->pc != 0x1DA1B4u) { return; }
    }
    ctx->pc = 0x1DA1B4u;
label_1da1b4:
    // 0x1da1b4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1da1b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1da1b8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1da1b8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1da1bc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA1BCu;
    {
        const bool branch_taken_0x1da1bc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA1C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1BCu;
            // 0x1da1c0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da1bc) {
            ctx->pc = 0x1DA1D8u;
            goto label_1da1d8;
        }
    }
    ctx->pc = 0x1DA1C4u;
    // 0x1da1c4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da1c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da1c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da1cc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA1CCu;
    {
        const bool branch_taken_0x1da1cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1CCu;
            // 0x1da1d0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da1cc) {
            ctx->pc = 0x1DA1E0u;
            goto label_1da1e0;
        }
    }
    ctx->pc = 0x1DA1D4u;
    // 0x1da1d4: 0x0  nop
    ctx->pc = 0x1da1d4u;
    // NOP
label_1da1d8:
    // 0x1da1d8: 0x12103c  dsll32      $v0, $s2, 0
    ctx->pc = 0x1da1d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1da1dc: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1da1dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
label_1da1e0:
    // 0x1da1e0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1da1e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1da1e4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1da1e4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1da1e8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1da1e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da1ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da1ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da1f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da1f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da1f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA1F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA1F4u;
            // 0x1da1f8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA0B8u: goto label_1da0b8;
            case 0x1DA0D0u: goto label_1da0d0;
            case 0x1DA100u: goto label_1da100;
            case 0x1DA128u: goto label_1da128;
            case 0x1DA13Cu: goto label_1da13c;
            case 0x1DA160u: goto label_1da160;
            case 0x1DA178u: goto label_1da178;
            case 0x1DA180u: goto label_1da180;
            case 0x1DA1A0u: goto label_1da1a0;
            case 0x1DA1B4u: goto label_1da1b4;
            case 0x1DA1D8u: goto label_1da1d8;
            case 0x1DA1E0u: goto label_1da1e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA1FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
