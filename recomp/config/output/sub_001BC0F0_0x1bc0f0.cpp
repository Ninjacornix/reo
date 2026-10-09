#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC0F0
// Address: 0x1bc0f0 - 0x1bc1d0
void sub_001BC0F0_0x1bc0f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC0F0_0x1bc0f0");
#endif

    switch (ctx->pc) {
        case 0x1bc118u: goto label_1bc118;
        case 0x1bc120u: goto label_1bc120;
        case 0x1bc12cu: goto label_1bc12c;
        case 0x1bc138u: goto label_1bc138;
        case 0x1bc144u: goto label_1bc144;
        case 0x1bc14cu: goto label_1bc14c;
        case 0x1bc168u: goto label_1bc168;
        case 0x1bc1bcu: goto label_1bc1bc;
        default: break;
    }

    ctx->pc = 0x1bc0f0u;

    // 0x1bc0f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bc0f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bc0f4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc0f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc0f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bc0f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bc0fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bc0fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bc100: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1bc100u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1bc104: 0x3c100031  lui         $s0, 0x31
    ctx->pc = 0x1bc104u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49 << 16));
    // 0x1bc108: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BC108u;
    {
        const bool branch_taken_0x1bc108 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BC10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC108u;
            // 0x1bc10c: 0x261065e0  addiu       $s0, $s0, 0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 26080));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc108) {
            ctx->pc = 0x1BC118u;
            goto label_1bc118;
        }
    }
    ctx->pc = 0x1BC110u;
    // 0x1bc110: 0xc06f13c  jal         func_1BC4F0
    ctx->pc = 0x1BC110u;
    SET_GPR_U32(ctx, 31, 0x1BC118u);
    ctx->pc = 0x1BC4F0u;
    if (runtime->hasFunction(0x1BC4F0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC4F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC118u; }
        if (ctx->pc != 0x1BC118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC4F0_0x1bc4f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC118u; }
        if (ctx->pc != 0x1BC118u) { return; }
    }
    ctx->pc = 0x1BC118u;
label_1bc118:
    // 0x1bc118: 0xc06bddc  jal         func_1AF770
    ctx->pc = 0x1BC118u;
    SET_GPR_U32(ctx, 31, 0x1BC120u);
    ctx->pc = 0x1AF770u;
    if (runtime->hasFunction(0x1AF770u)) {
        auto targetFn = runtime->lookupFunction(0x1AF770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC120u; }
        if (ctx->pc != 0x1BC120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC120u; }
        if (ctx->pc != 0x1BC120u) { return; }
    }
    ctx->pc = 0x1BC120u;
label_1bc120:
    // 0x1bc120: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x1bc120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1bc124: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC124u;
    SET_GPR_U32(ctx, 31, 0x1BC12Cu);
    ctx->pc = 0x1BC128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC124u;
            // 0x1bc128: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC12Cu; }
        if (ctx->pc != 0x1BC12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC12Cu; }
        if (ctx->pc != 0x1BC12Cu) { return; }
    }
    ctx->pc = 0x1BC12Cu;
label_1bc12c:
    // 0x1bc12c: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1bc12cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1bc130: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC130u;
    SET_GPR_U32(ctx, 31, 0x1BC138u);
    ctx->pc = 0x1BC134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC130u;
            // 0x1bc134: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC138u; }
        if (ctx->pc != 0x1BC138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC138u; }
        if (ctx->pc != 0x1BC138u) { return; }
    }
    ctx->pc = 0x1BC138u;
label_1bc138:
    // 0x1bc138: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1bc138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1bc13c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC13Cu;
    SET_GPR_U32(ctx, 31, 0x1BC144u);
    ctx->pc = 0x1BC140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC13Cu;
            // 0x1bc140: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC144u; }
        if (ctx->pc != 0x1BC144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC144u; }
        if (ctx->pc != 0x1BC144u) { return; }
    }
    ctx->pc = 0x1BC144u;
label_1bc144:
    // 0x1bc144: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1BC144u;
    SET_GPR_U32(ctx, 31, 0x1BC14Cu);
    ctx->pc = 0x1BC148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC144u;
            // 0x1bc148: 0x24040058  addiu       $a0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC14Cu; }
        if (ctx->pc != 0x1BC14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC14Cu; }
        if (ctx->pc != 0x1BC14Cu) { return; }
    }
    ctx->pc = 0x1BC14Cu;
label_1bc14c:
    // 0x1bc14c: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1BC14Cu;
    {
        const bool branch_taken_0x1bc14c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bc14c) {
            ctx->pc = 0x1BC1BCu;
            goto label_1bc1bc;
        }
    }
    ctx->pc = 0x1BC154u;
    // 0x1bc154: 0x86030004  lh          $v1, 0x4($s0)
    ctx->pc = 0x1bc154u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bc158: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1BC158u;
    {
        const bool branch_taken_0x1bc158 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC15Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC158u;
            // 0x1bc15c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc158) {
            ctx->pc = 0x1BC1BCu;
            goto label_1bc1bc;
        }
    }
    ctx->pc = 0x1BC160u;
    // 0x1bc160: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BC160u;
    SET_GPR_U32(ctx, 31, 0x1BC168u);
    ctx->pc = 0x1BC164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC160u;
            // 0x1bc164: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC168u; }
        if (ctx->pc != 0x1BC168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC168u; }
        if (ctx->pc != 0x1BC168u) { return; }
    }
    ctx->pc = 0x1BC168u;
label_1bc168:
    // 0x1bc168: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bc168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc16c: 0x27a50022  addiu       $a1, $sp, 0x22
    ctx->pc = 0x1bc16cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 34));
    // 0x1bc170: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1bc170u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1bc174: 0x84420004  lh          $v0, 0x4($v0)
    ctx->pc = 0x1bc174u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1bc178: 0xa7a20020  sh          $v0, 0x20($sp)
    ctx->pc = 0x1bc178u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 32), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc17c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bc17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc180: 0x84420006  lh          $v0, 0x6($v0)
    ctx->pc = 0x1bc180u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x1bc184: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x1bc184u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc188: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bc188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc18c: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x1bc18cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bc190: 0x84630008  lh          $v1, 0x8($v1)
    ctx->pc = 0x1bc190u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1bc194: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bc194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bc198: 0xa7a20024  sh          $v0, 0x24($sp)
    ctx->pc = 0x1bc198u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc19c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bc19cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc1a0: 0x84a20000  lh          $v0, 0x0($a1)
    ctx->pc = 0x1bc1a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1bc1a4: 0x8463000a  lh          $v1, 0xA($v1)
    ctx->pc = 0x1bc1a4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x1bc1a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bc1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bc1ac: 0xa7a20026  sh          $v0, 0x26($sp)
    ctx->pc = 0x1bc1acu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc1b0: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1bc1b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1bc1b4: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BC1B4u;
    SET_GPR_U32(ctx, 31, 0x1BC1BCu);
    ctx->pc = 0x1BC1B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC1B4u;
            // 0x1bc1b8: 0xafa20028  sw          $v0, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC1BCu; }
        if (ctx->pc != 0x1BC1BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC1BCu; }
        if (ctx->pc != 0x1BC1BCu) { return; }
    }
    ctx->pc = 0x1BC1BCu;
label_1bc1bc:
    // 0x1bc1bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bc1bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bc1c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bc1c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC1C4u;
            // 0x1bc1c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC118u: goto label_1bc118;
            case 0x1BC120u: goto label_1bc120;
            case 0x1BC12Cu: goto label_1bc12c;
            case 0x1BC138u: goto label_1bc138;
            case 0x1BC144u: goto label_1bc144;
            case 0x1BC14Cu: goto label_1bc14c;
            case 0x1BC168u: goto label_1bc168;
            case 0x1BC1BCu: goto label_1bc1bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC1CCu;
    // 0x1bc1cc: 0x0  nop
    ctx->pc = 0x1bc1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
