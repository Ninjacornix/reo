#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119948
// Address: 0x119948 - 0x119b28
void sub_00119948_0x119948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119948_0x119948");
#endif

    switch (ctx->pc) {
        case 0x119990u: goto label_119990;
        case 0x11999cu: goto label_11999c;
        case 0x1199b4u: goto label_1199b4;
        case 0x1199d0u: goto label_1199d0;
        case 0x1199f0u: goto label_1199f0;
        case 0x119a14u: goto label_119a14;
        case 0x119a40u: goto label_119a40;
        case 0x119a6cu: goto label_119a6c;
        case 0x119aa0u: goto label_119aa0;
        case 0x119ab0u: goto label_119ab0;
        case 0x119ab8u: goto label_119ab8;
        case 0x119accu: goto label_119acc;
        case 0x119adcu: goto label_119adc;
        case 0x119aecu: goto label_119aec;
        case 0x119af4u: goto label_119af4;
        default: break;
    }

    ctx->pc = 0x119948u;

    // 0x119948: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x119948u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x11994c: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11994cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x119950: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x119950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x119954: 0x100b82d  daddu       $s7, $t0, $zero
    ctx->pc = 0x119954u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119958: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x119958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11995c: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x11995cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119960: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x119960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x119964: 0x120a02d  daddu       $s4, $t1, $zero
    ctx->pc = 0x119964u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119968: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x119968u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11996c: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x11996cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119970: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x119970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x119974: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x119974u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119978: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x119978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11997c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11997cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x119980: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x119980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x119984: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x119984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x119988: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x119988u;
    SET_GPR_U32(ctx, 31, 0x119990u);
    ctx->pc = 0x11998Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119988u;
            // 0x11998c: 0x26d1ca40  addiu       $s1, $s6, -0x35C0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119990u; }
        if (ctx->pc != 0x119990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119990u; }
        if (ctx->pc != 0x119990u) { return; }
    }
    ctx->pc = 0x119990u;
label_119990:
    // 0x119990: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x119990u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119994: 0xc04619c  jal         func_118670
    ctx->pc = 0x119994u;
    SET_GPR_U32(ctx, 31, 0x11999Cu);
    ctx->pc = 0x119998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119994u;
            // 0x119998: 0x2404001a  addiu       $a0, $zero, 0x1A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11999Cu; }
        if (ctx->pc != 0x11999Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11999Cu; }
        if (ctx->pc != 0x11999Cu) { return; }
    }
    ctx->pc = 0x11999Cu;
label_11999c:
    // 0x11999c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11999cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1199a0: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x1199a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x1199a4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1199A4u;
    {
        const bool branch_taken_0x1199a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1199a4) {
            ctx->pc = 0x1199B4u;
            goto label_1199b4;
        }
    }
    ctx->pc = 0x1199ACu;
    // 0x1199ac: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x1199ACu;
    SET_GPR_U32(ctx, 31, 0x1199B4u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199B4u; }
        if (ctx->pc != 0x1199B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199B4u; }
        if (ctx->pc != 0x1199B4u) { return; }
    }
    ctx->pc = 0x1199B4u;
label_1199b4:
    // 0x1199b4: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1199B4u;
    {
        const bool branch_taken_0x1199b4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x1199b4) {
            ctx->pc = 0x1199C8u;
            goto label_1199c8;
        }
    }
    ctx->pc = 0x1199BCu;
    // 0x1199bc: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x1199bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1199c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1199C0u;
    {
        const bool branch_taken_0x1199c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1199C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1199C0u;
            // 0x1199c4: 0x2e620401  sltiu       $v0, $s3, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1199c0) {
            ctx->pc = 0x1199D8u;
            goto label_1199d8;
        }
    }
    ctx->pc = 0x1199C8u;
label_1199c8:
    // 0x1199c8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x1199C8u;
    SET_GPR_U32(ctx, 31, 0x1199D0u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199D0u; }
        if (ctx->pc != 0x1199D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199D0u; }
        if (ctx->pc != 0x1199D0u) { return; }
    }
    ctx->pc = 0x1199D0u;
label_1199d0:
    // 0x1199d0: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1199D0u;
    {
        const bool branch_taken_0x1199d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1199D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1199D0u;
            // 0x1199d4: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1199d0) {
            ctx->pc = 0x119AF8u;
            goto label_119af8;
        }
    }
    ctx->pc = 0x1199D8u;
label_1199d8:
    // 0x1199d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1199D8u;
    {
        const bool branch_taken_0x1199d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1199DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1199D8u;
            // 0x1199dc: 0x2e820401  sltiu       $v0, $s4, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1199d8) {
            ctx->pc = 0x1199E8u;
            goto label_1199e8;
        }
    }
    ctx->pc = 0x1199E0u;
    // 0x1199e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1199E0u;
    {
        const bool branch_taken_0x1199e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1199e0) {
            ctx->pc = 0x1199F8u;
            goto label_1199f8;
        }
    }
    ctx->pc = 0x1199E8u;
label_1199e8:
    // 0x1199e8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x1199E8u;
    SET_GPR_U32(ctx, 31, 0x1199F0u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199F0u; }
        if (ctx->pc != 0x1199F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1199F0u; }
        if (ctx->pc != 0x1199F0u) { return; }
    }
    ctx->pc = 0x1199F0u;
label_1199f0:
    // 0x1199f0: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1199F0u;
    {
        const bool branch_taken_0x1199f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1199F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1199F0u;
            // 0x1199f4: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1199f0) {
            ctx->pc = 0x119AF8u;
            goto label_119af8;
        }
    }
    ctx->pc = 0x1199F8u;
label_1199f8:
    // 0x1199f8: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1199F8u;
    {
        const bool branch_taken_0x1199f8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1199FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1199F8u;
            // 0x1199fc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1199f8) {
            ctx->pc = 0x119A08u;
            goto label_119a08;
        }
    }
    ctx->pc = 0x119A00u;
    // 0x119a00: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x119A00u;
    {
        const bool branch_taken_0x119a00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119A00u;
            // 0x119a04: 0xae20041c  sw          $zero, 0x41C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 1052), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119a00) {
            ctx->pc = 0x119A14u;
            goto label_119a14;
        }
    }
    ctx->pc = 0x119A08u;
label_119a08:
    // 0x119a08: 0x26240014  addiu       $a0, $s1, 0x14
    ctx->pc = 0x119a08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x119a0c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x119A0Cu;
    SET_GPR_U32(ctx, 31, 0x119A14u);
    ctx->pc = 0x119A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119A0Cu;
            // 0x119a10: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A14u; }
        if (ctx->pc != 0x119A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A14u; }
        if (ctx->pc != 0x119A14u) { return; }
    }
    ctx->pc = 0x119A14u;
label_119a14:
    // 0x119a14: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x119a14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x119a18: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x119a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x119a1c: 0xae350010  sw          $s5, 0x10($s1)
    ctx->pc = 0x119a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 21));
    // 0x119a20: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x119a20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x119a24: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x119a24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x119a28: 0x26d0ca40  addiu       $s0, $s6, -0x35C0
    ctx->pc = 0x119a28u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x119a2c: 0xae33041c  sw          $s3, 0x41C($s1)
    ctx->pc = 0x119a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 1052), GPR_U32(ctx, 19));
    // 0x119a30: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x119a30u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x119a34: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x119a34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x119a38: 0xc045188  jal         func_114620
    ctx->pc = 0x119A38u;
    SET_GPR_U32(ctx, 31, 0x119A40u);
    ctx->pc = 0x119A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119A38u;
            // 0x119a3c: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A40u; }
        if (ctx->pc != 0x119A40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A40u; }
        if (ctx->pc != 0x119A40u) { return; }
    }
    ctx->pc = 0x119A40u;
label_119a40:
    // 0x119a40: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x119a40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119a44: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x119a44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119a48: 0x27a20030  addiu       $v0, $sp, 0x30
    ctx->pc = 0x119a48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x119a4c: 0xae340418  sw          $s4, 0x418($s1)
    ctx->pc = 0x119a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 1048), GPR_U32(ctx, 20));
    // 0x119a50: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x119a50u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x119a54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x119a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119a58: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x119a58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x119a5c: 0x24050420  addiu       $a1, $zero, 0x420
    ctx->pc = 0x119a5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1056));
    // 0x119a60: 0xae370414  sw          $s7, 0x414($s1)
    ctx->pc = 0x119a60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 1044), GPR_U32(ctx, 23));
    // 0x119a64: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x119A64u;
    SET_GPR_U32(ctx, 31, 0x119A6Cu);
    ctx->pc = 0x119A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119A64u;
            // 0x119a68: 0xae320000  sw          $s2, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A6Cu; }
        if (ctx->pc != 0x119A6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119A6Cu; }
        if (ctx->pc != 0x119A6Cu) { return; }
    }
    ctx->pc = 0x119A6Cu;
label_119a6c:
    // 0x119a6c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x119a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x119a70: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x119a70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x119a74: 0x2451d680  addiu       $s1, $v0, -0x2980
    ctx->pc = 0x119a74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956672));
    // 0x119a78: 0x2484e140  addiu       $a0, $a0, -0x1EC0
    ctx->pc = 0x119a78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959424));
    // 0x119a7c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x119a7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119a80: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x119a80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x119a84: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x119a84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x119a88: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x119a88u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119a8c: 0x24080420  addiu       $t0, $zero, 0x420
    ctx->pc = 0x119a8cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1056));
    // 0x119a90: 0x220482d  daddu       $t1, $s1, $zero
    ctx->pc = 0x119a90u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119a94: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x119a94u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119a98: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x119A98u;
    SET_GPR_U32(ctx, 31, 0x119AA0u);
    ctx->pc = 0x119A9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119A98u;
            // 0x119a9c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AA0u; }
        if (ctx->pc != 0x119AA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AA0u; }
        if (ctx->pc != 0x119AA0u) { return; }
    }
    ctx->pc = 0x119AA0u;
label_119aa0:
    // 0x119aa0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x119AA0u;
    {
        const bool branch_taken_0x119aa0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x119AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119AA0u;
            // 0x119aa4: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119aa0) {
            ctx->pc = 0x119AC0u;
            goto label_119ac0;
        }
    }
    ctx->pc = 0x119AA8u;
    // 0x119aa8: 0xc04518c  jal         func_114630
    ctx->pc = 0x119AA8u;
    SET_GPR_U32(ctx, 31, 0x119AB0u);
    ctx->pc = 0x119AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119AA8u;
            // 0x119aac: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AB0u; }
        if (ctx->pc != 0x119AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AB0u; }
        if (ctx->pc != 0x119AB0u) { return; }
    }
    ctx->pc = 0x119AB0u;
label_119ab0:
    // 0x119ab0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119AB0u;
    SET_GPR_U32(ctx, 31, 0x119AB8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AB8u; }
        if (ctx->pc != 0x119AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AB8u; }
        if (ctx->pc != 0x119AB8u) { return; }
    }
    ctx->pc = 0x119AB8u;
label_119ab8:
    // 0x119ab8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x119AB8u;
    {
        const bool branch_taken_0x119ab8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119AB8u;
            // 0x119abc: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119ab8) {
            ctx->pc = 0x119AF8u;
            goto label_119af8;
        }
    }
    ctx->pc = 0x119AC0u;
label_119ac0:
    // 0x119ac0: 0x2221025  or          $v0, $s1, $v0
    ctx->pc = 0x119ac0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x119ac4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119AC4u;
    SET_GPR_U32(ctx, 31, 0x119ACCu);
    ctx->pc = 0x119AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119AC4u;
            // 0x119ac8: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119ACCu; }
        if (ctx->pc != 0x119ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119ACCu; }
        if (ctx->pc != 0x119ACCu) { return; }
    }
    ctx->pc = 0x119ACCu;
label_119acc:
    // 0x119acc: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x119ACCu;
    {
        const bool branch_taken_0x119acc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x119acc) {
            ctx->pc = 0x119AE4u;
            goto label_119ae4;
        }
    }
    ctx->pc = 0x119AD4u;
    // 0x119ad4: 0xc04518c  jal         func_114630
    ctx->pc = 0x119AD4u;
    SET_GPR_U32(ctx, 31, 0x119ADCu);
    ctx->pc = 0x119AD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119AD4u;
            // 0x119ad8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119ADCu; }
        if (ctx->pc != 0x119ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119ADCu; }
        if (ctx->pc != 0x119ADCu) { return; }
    }
    ctx->pc = 0x119ADCu;
label_119adc:
    // 0x119adc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x119ADCu;
    {
        const bool branch_taken_0x119adc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119ADCu;
            // 0x119ae0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119adc) {
            ctx->pc = 0x119AF8u;
            goto label_119af8;
        }
    }
    ctx->pc = 0x119AE4u;
label_119ae4:
    // 0x119ae4: 0xc045198  jal         func_114660
    ctx->pc = 0x119AE4u;
    SET_GPR_U32(ctx, 31, 0x119AECu);
    ctx->pc = 0x119AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119AE4u;
            // 0x119ae8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AECu; }
        if (ctx->pc != 0x119AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AECu; }
        if (ctx->pc != 0x119AECu) { return; }
    }
    ctx->pc = 0x119AECu;
label_119aec:
    // 0x119aec: 0xc04518c  jal         func_114630
    ctx->pc = 0x119AECu;
    SET_GPR_U32(ctx, 31, 0x119AF4u);
    ctx->pc = 0x119AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119AECu;
            // 0x119af0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AF4u; }
        if (ctx->pc != 0x119AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119AF4u; }
        if (ctx->pc != 0x119AF4u) { return; }
    }
    ctx->pc = 0x119AF4u;
label_119af4:
    // 0x119af4: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x119af4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_119af8:
    // 0x119af8: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x119af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x119afc: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x119afcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x119b00: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x119b00u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x119b04: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x119b04u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x119b08: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x119b08u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x119b0c: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x119b0cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x119b10: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x119b10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x119b14: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x119b14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x119b18: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x119b18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x119b1c: 0x3e00008  jr          $ra
    ctx->pc = 0x119B1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119B1Cu;
            // 0x119b20: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119990u: goto label_119990;
            case 0x11999Cu: goto label_11999c;
            case 0x1199B4u: goto label_1199b4;
            case 0x1199C8u: goto label_1199c8;
            case 0x1199D0u: goto label_1199d0;
            case 0x1199D8u: goto label_1199d8;
            case 0x1199E8u: goto label_1199e8;
            case 0x1199F0u: goto label_1199f0;
            case 0x1199F8u: goto label_1199f8;
            case 0x119A08u: goto label_119a08;
            case 0x119A14u: goto label_119a14;
            case 0x119A40u: goto label_119a40;
            case 0x119A6Cu: goto label_119a6c;
            case 0x119AA0u: goto label_119aa0;
            case 0x119AB0u: goto label_119ab0;
            case 0x119AB8u: goto label_119ab8;
            case 0x119AC0u: goto label_119ac0;
            case 0x119ACCu: goto label_119acc;
            case 0x119ADCu: goto label_119adc;
            case 0x119AE4u: goto label_119ae4;
            case 0x119AECu: goto label_119aec;
            case 0x119AF4u: goto label_119af4;
            case 0x119AF8u: goto label_119af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119B24u;
    // 0x119b24: 0x0  nop
    ctx->pc = 0x119b24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
