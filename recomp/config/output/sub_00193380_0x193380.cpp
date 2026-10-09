#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193380
// Address: 0x193380 - 0x1934c0
void sub_00193380_0x193380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193380_0x193380");
#endif

    switch (ctx->pc) {
        case 0x1933bcu: goto label_1933bc;
        case 0x1933ccu: goto label_1933cc;
        case 0x193410u: goto label_193410;
        case 0x193428u: goto label_193428;
        case 0x193448u: goto label_193448;
        case 0x193468u: goto label_193468;
        case 0x19348cu: goto label_19348c;
        case 0x19349cu: goto label_19349c;
        default: break;
    }

    ctx->pc = 0x193380u;

    // 0x193380: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x193380u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193384: 0x8064ce4  j           func_193390
    ctx->pc = 0x193384u;
    ctx->pc = 0x193388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193384u;
            // 0x193388: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193390u;
    goto label_193390;
    ctx->pc = 0x19338Cu;
    // 0x19338c: 0x0  nop
    ctx->pc = 0x19338cu;
    // NOP
label_193390:
    // 0x193390: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x193390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x193394: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x193394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x193398: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x193398u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19339c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19339cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1933a0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1933a0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1933a4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1933a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1933a8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1933a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1933ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1933acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1933b0: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1933b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1933b4: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x1933B4u;
    SET_GPR_U32(ctx, 31, 0x1933BCu);
    ctx->pc = 0x1933B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1933B4u;
            // 0x1933b8: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1933BCu; }
        if (ctx->pc != 0x1933BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1933BCu; }
        if (ctx->pc != 0x1933BCu) { return; }
    }
    ctx->pc = 0x1933BCu;
label_1933bc:
    // 0x1933bc: 0x84520002  lh          $s2, 0x2($v0)
    ctx->pc = 0x1933bcu;
    SET_GPR_S32(ctx, 18, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1933c0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1933c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1933c4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1933C4u;
    {
        const bool branch_taken_0x1933c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1933C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1933C4u;
            // 0x1933c8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1933c4) {
            ctx->pc = 0x193414u;
            goto label_193414;
        }
    }
    ctx->pc = 0x1933CCu;
label_1933cc:
    // 0x1933cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1933ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1933d0: 0x702021  addu        $a0, $v1, $s0
    ctx->pc = 0x1933d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1933d4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1933d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1933d8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1933d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1933dc: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1933dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1933e0: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x1933e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1933e4: 0xa47200c2  sh          $s2, 0xC2($v1)
    ctx->pc = 0x1933e4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 194), (uint16_t)GPR_U32(ctx, 18));
    // 0x1933e8: 0x24640040  addiu       $a0, $v1, 0x40
    ctx->pc = 0x1933e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
    // 0x1933ec: 0xa4620180  sh          $v0, 0x180($v1)
    ctx->pc = 0x1933ecu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 384), (uint16_t)GPR_U32(ctx, 2));
    // 0x1933f0: 0xa4620182  sh          $v0, 0x182($v1)
    ctx->pc = 0x1933f0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 386), (uint16_t)GPR_U32(ctx, 2));
    // 0x1933f4: 0xac6000cc  sw          $zero, 0xCC($v1)
    ctx->pc = 0x1933f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 204), GPR_U32(ctx, 0));
    // 0x1933f8: 0xac6000d0  sw          $zero, 0xD0($v1)
    ctx->pc = 0x1933f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 208), GPR_U32(ctx, 0));
    // 0x1933fc: 0xac6000d4  sw          $zero, 0xD4($v1)
    ctx->pc = 0x1933fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 0));
    // 0x193400: 0xac6000d8  sw          $zero, 0xD8($v1)
    ctx->pc = 0x193400u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 0));
    // 0x193404: 0xac600178  sw          $zero, 0x178($v1)
    ctx->pc = 0x193404u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 376), GPR_U32(ctx, 0));
    // 0x193408: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x193408u;
    SET_GPR_U32(ctx, 31, 0x193410u);
    ctx->pc = 0x19340Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193408u;
            // 0x19340c: 0xac60017c  sw          $zero, 0x17C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 380), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193410u; }
        if (ctx->pc != 0x193410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193410u; }
        if (ctx->pc != 0x193410u) { return; }
    }
    ctx->pc = 0x193410u;
label_193410:
    // 0x193410: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x193410u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_193414:
    // 0x193414: 0x212102a  slt         $v0, $s0, $s2
    ctx->pc = 0x193414u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x193418: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x193418u;
    {
        const bool branch_taken_0x193418 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19341Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193418u;
            // 0x19341c: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193418) {
            ctx->pc = 0x1933CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1933cc;
        }
    }
    ctx->pc = 0x193420u;
    // 0x193420: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x193420u;
    {
        const bool branch_taken_0x193420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193420u;
            // 0x193424: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193420) {
            ctx->pc = 0x19344Cu;
            goto label_19344c;
        }
    }
    ctx->pc = 0x193428u;
label_193428:
    // 0x193428: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x193428u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19342c: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x19342cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x193430: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x193430u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193434: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x193434u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x193438: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x193438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x19343c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x19343cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x193440: 0xc064ef4  jal         func_193BD0
    ctx->pc = 0x193440u;
    SET_GPR_U32(ctx, 31, 0x193448u);
    ctx->pc = 0x193444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193440u;
            // 0x193444: 0x2822021  addu        $a0, $s4, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193BD0u;
    if (runtime->hasFunction(0x193BD0u)) {
        auto targetFn = runtime->lookupFunction(0x193BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193448u; }
        if (ctx->pc != 0x193448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193BD0_0x193bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193448u; }
        if (ctx->pc != 0x193448u) { return; }
    }
    ctx->pc = 0x193448u;
label_193448:
    // 0x193448: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x193448u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_19344c:
    // 0x19344c: 0x212102a  slt         $v0, $s0, $s2
    ctx->pc = 0x19344cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x193450: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x193450u;
    {
        const bool branch_taken_0x193450 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x193454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193450u;
            // 0x193454: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193450) {
            ctx->pc = 0x193428u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_193428;
        }
    }
    ctx->pc = 0x193458u;
    // 0x193458: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x193458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19345c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x19345cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193460: 0xc064d30  jal         func_1934C0
    ctx->pc = 0x193460u;
    SET_GPR_U32(ctx, 31, 0x193468u);
    ctx->pc = 0x193464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193460u;
            // 0x193464: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1934C0u;
    if (runtime->hasFunction(0x1934C0u)) {
        auto targetFn = runtime->lookupFunction(0x1934C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193468u; }
        if (ctx->pc != 0x193468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001934C0_0x1934c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193468u; }
        if (ctx->pc != 0x193468u) { return; }
    }
    ctx->pc = 0x193468u;
label_193468:
    // 0x193468: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19346c: 0x12620009  beq         $s3, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x19346Cu;
    {
        const bool branch_taken_0x19346c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x193470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19346Cu;
            // 0x193470: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19346c) {
            ctx->pc = 0x193494u;
            goto label_193494;
        }
    }
    ctx->pc = 0x193474u;
    // 0x193474: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x193474u;
    {
        const bool branch_taken_0x193474 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x193478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193474u;
            // 0x193478: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193474) {
            ctx->pc = 0x193484u;
            goto label_193484;
        }
    }
    ctx->pc = 0x19347Cu;
    // 0x19347c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19347Cu;
    {
        const bool branch_taken_0x19347c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19347Cu;
            // 0x193480: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19347c) {
            ctx->pc = 0x1934A0u;
            goto label_1934a0;
        }
    }
    ctx->pc = 0x193484u;
label_193484:
    // 0x193484: 0xc064ddc  jal         func_193770
    ctx->pc = 0x193484u;
    SET_GPR_U32(ctx, 31, 0x19348Cu);
    ctx->pc = 0x193770u;
    if (runtime->hasFunction(0x193770u)) {
        auto targetFn = runtime->lookupFunction(0x193770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19348Cu; }
        if (ctx->pc != 0x19348Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193770_0x193770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19348Cu; }
        if (ctx->pc != 0x19348Cu) { return; }
    }
    ctx->pc = 0x19348Cu;
label_19348c:
    // 0x19348c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x19348Cu;
    {
        const bool branch_taken_0x19348c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19348c) {
            ctx->pc = 0x19349Cu;
            goto label_19349c;
        }
    }
    ctx->pc = 0x193494u;
label_193494:
    // 0x193494: 0xc064e20  jal         func_193880
    ctx->pc = 0x193494u;
    SET_GPR_U32(ctx, 31, 0x19349Cu);
    ctx->pc = 0x193880u;
    if (runtime->hasFunction(0x193880u)) {
        auto targetFn = runtime->lookupFunction(0x193880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19349Cu; }
        if (ctx->pc != 0x19349Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193880_0x193880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19349Cu; }
        if (ctx->pc != 0x19349Cu) { return; }
    }
    ctx->pc = 0x19349Cu;
label_19349c:
    // 0x19349c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x19349cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1934a0:
    // 0x1934a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1934a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1934a4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1934a4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1934a8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1934a8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1934ac: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1934acu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1934b0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1934b0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1934b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1934b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1934b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1934B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1934BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1934B8u;
            // 0x1934bc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193390u: goto label_193390;
            case 0x1933BCu: goto label_1933bc;
            case 0x1933CCu: goto label_1933cc;
            case 0x193410u: goto label_193410;
            case 0x193414u: goto label_193414;
            case 0x193428u: goto label_193428;
            case 0x193448u: goto label_193448;
            case 0x19344Cu: goto label_19344c;
            case 0x193468u: goto label_193468;
            case 0x193484u: goto label_193484;
            case 0x19348Cu: goto label_19348c;
            case 0x193494u: goto label_193494;
            case 0x19349Cu: goto label_19349c;
            case 0x1934A0u: goto label_1934a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1934C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
