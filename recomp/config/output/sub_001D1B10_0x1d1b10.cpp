#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1B10
// Address: 0x1d1b10 - 0x1d1fc0
void sub_001D1B10_0x1d1b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1B10_0x1d1b10");
#endif

    switch (ctx->pc) {
        case 0x1d1b48u: goto label_1d1b48;
        case 0x1d1b64u: goto label_1d1b64;
        case 0x1d1b78u: goto label_1d1b78;
        case 0x1d1b80u: goto label_1d1b80;
        case 0x1d1bc0u: goto label_1d1bc0;
        case 0x1d1bd8u: goto label_1d1bd8;
        case 0x1d1c04u: goto label_1d1c04;
        case 0x1d1c78u: goto label_1d1c78;
        case 0x1d1c90u: goto label_1d1c90;
        case 0x1d1ca8u: goto label_1d1ca8;
        case 0x1d1d08u: goto label_1d1d08;
        case 0x1d1d20u: goto label_1d1d20;
        case 0x1d1d44u: goto label_1d1d44;
        case 0x1d1d5cu: goto label_1d1d5c;
        case 0x1d1d70u: goto label_1d1d70;
        case 0x1d1d94u: goto label_1d1d94;
        case 0x1d1dacu: goto label_1d1dac;
        case 0x1d1dc0u: goto label_1d1dc0;
        case 0x1d1de0u: goto label_1d1de0;
        case 0x1d1e2cu: goto label_1d1e2c;
        case 0x1d1e40u: goto label_1d1e40;
        case 0x1d1e60u: goto label_1d1e60;
        case 0x1d1eb4u: goto label_1d1eb4;
        case 0x1d1ed0u: goto label_1d1ed0;
        case 0x1d1f00u: goto label_1d1f00;
        case 0x1d1f24u: goto label_1d1f24;
        case 0x1d1facu: goto label_1d1fac;
        default: break;
    }

    ctx->pc = 0x1d1b10u;

    // 0x1d1b10: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x1d1b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x1d1b14: 0x3086ffff  andi        $a2, $a0, 0xFFFF
    ctx->pc = 0x1d1b14u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d1b18: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d1b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d1b1c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1b20: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d1b20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d1b24: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1b24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1b28: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d1b28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d1b2c: 0x24a563b0  addiu       $a1, $a1, 0x63B0
    ctx->pc = 0x1d1b2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25520));
    // 0x1d1b30: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d1b30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1b34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1b34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1b38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1b38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1b3c: 0x8c33440c  lw          $s3, 0x440C($at)
    ctx->pc = 0x1d1b3cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1b40: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1B40u;
    SET_GPR_U32(ctx, 31, 0x1D1B48u);
    ctx->pc = 0x1D1B44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1B40u;
            // 0x1d1b44: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B48u; }
        if (ctx->pc != 0x1D1B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B48u; }
        if (ctx->pc != 0x1D1B48u) { return; }
    }
    ctx->pc = 0x1D1B48u;
label_1d1b48:
    // 0x1d1b48: 0x27b10060  addiu       $s1, $sp, 0x60
    ctx->pc = 0x1d1b48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d1b4c: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1d1b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1d1b50: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d1b50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b54: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1b54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b58: 0x34460001  ori         $a2, $v0, 0x1
    ctx->pc = 0x1d1b58u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x1d1b5c: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1B5Cu;
    SET_GPR_U32(ctx, 31, 0x1D1B64u);
    ctx->pc = 0x1D1B60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1B5Cu;
            // 0x1d1b60: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B64u; }
        if (ctx->pc != 0x1D1B64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B64u; }
        if (ctx->pc != 0x1D1B64u) { return; }
    }
    ctx->pc = 0x1D1B64u;
label_1d1b64:
    // 0x1d1b64: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1d1b64u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b68: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1d1b68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b6c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d1b6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b70: 0xc074674  jal         func_1D19D0
    ctx->pc = 0x1D1B70u;
    SET_GPR_U32(ctx, 31, 0x1D1B78u);
    ctx->pc = 0x1D1B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1B70u;
            // 0x1d1b74: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D19D0u;
    if (runtime->hasFunction(0x1D19D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D19D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B78u; }
        if (ctx->pc != 0x1D1B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D19D0_0x1d19d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1B78u; }
        if (ctx->pc != 0x1D1B78u) { return; }
    }
    ctx->pc = 0x1D1B78u;
label_1d1b78:
    // 0x1d1b78: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1d1b78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1b7c: 0x122100  sll         $a0, $s2, 4
    ctx->pc = 0x1d1b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
label_1d1b80:
    // 0x1d1b80: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1d1b80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1d1b84: 0x922823  subu        $a1, $a0, $s2
    ctx->pc = 0x1d1b84u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1d1b88: 0x24635c30  addiu       $v1, $v1, 0x5C30
    ctx->pc = 0x1d1b88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23600));
    // 0x1d1b8c: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1d1b8cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d1b90: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1d1b90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1d1b94: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x1d1b94u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1d1b98: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1d1b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d1b9c: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1d1b9cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d1ba0: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1D1BA0u;
    {
        const bool branch_taken_0x1d1ba0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1ba0) {
            ctx->pc = 0x1D1C04u;
            goto label_1d1c04;
        }
    }
    ctx->pc = 0x1D1BA8u;
    // 0x1d1ba8: 0x90860b98  lbu         $a2, 0xB98($a0)
    ctx->pc = 0x1d1ba8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2968)));
    // 0x1d1bac: 0x24900b98  addiu       $s0, $a0, 0xB98
    ctx->pc = 0x1d1bacu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 2968));
    // 0x1d1bb0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1bb0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1bb4: 0x24a563e0  addiu       $a1, $a1, 0x63E0
    ctx->pc = 0x1d1bb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25568));
    // 0x1d1bb8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1BB8u;
    SET_GPR_U32(ctx, 31, 0x1D1BC0u);
    ctx->pc = 0x1D1BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1BB8u;
            // 0x1d1bbc: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1BC0u; }
        if (ctx->pc != 0x1D1BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1BC0u; }
        if (ctx->pc != 0x1D1BC0u) { return; }
    }
    ctx->pc = 0x1D1BC0u;
label_1d1bc0:
    // 0x1d1bc0: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1d1bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1d1bc4: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x1d1bc4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1bc8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1bcc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d1bccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1bd0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1BD0u;
    SET_GPR_U32(ctx, 31, 0x1D1BD8u);
    ctx->pc = 0x1D1BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1BD0u;
            // 0x1d1bd4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1BD8u; }
        if (ctx->pc != 0x1D1BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1BD8u; }
        if (ctx->pc != 0x1D1BD8u) { return; }
    }
    ctx->pc = 0x1D1BD8u;
label_1d1bd8:
    // 0x1d1bd8: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x1d1bd8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d1bdc: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1d1bdcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1be0: 0x24031f44  addiu       $v1, $zero, 0x1F44
    ctx->pc = 0x1d1be0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
    // 0x1d1be4: 0x3c02004d  lui         $v0, 0x4D
    ctx->pc = 0x1d1be4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)77 << 16));
    // 0x1d1be8: 0x24427000  addiu       $v0, $v0, 0x7000
    ctx->pc = 0x1d1be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28672));
    // 0x1d1bec: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1d1becu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1bf0: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1d1bf0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1bf4: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1d1bf4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1bf8: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x1d1bf8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d1bfc: 0xc074650  jal         func_1D1940
    ctx->pc = 0x1D1BFCu;
    SET_GPR_U32(ctx, 31, 0x1D1C04u);
    ctx->pc = 0x1D1C00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1BFCu;
            // 0x1d1c00: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1940u;
    if (runtime->hasFunction(0x1D1940u)) {
        auto targetFn = runtime->lookupFunction(0x1D1940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C04u; }
        if (ctx->pc != 0x1D1C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1940_0x1d1940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C04u; }
        if (ctx->pc != 0x1D1C04u) { return; }
    }
    ctx->pc = 0x1D1C04u;
label_1d1c04:
    // 0x1d1c04: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d1c04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d1c08: 0x2a430008  slti        $v1, $s2, 0x8
    ctx->pc = 0x1d1c08u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1d1c0c: 0x1460ffdc  bnez        $v1, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1D1C0Cu;
    {
        const bool branch_taken_0x1d1c0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D1C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C0Cu;
            // 0x1d1c10: 0x122100  sll         $a0, $s2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1c0c) {
            ctx->pc = 0x1D1B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d1b80;
        }
    }
    ctx->pc = 0x1D1C14u;
    // 0x1d1c14: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d1c14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d1c18: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d1c18u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1c1c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1c1cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1c20: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1c20u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1c24: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1c24u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1c28: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1c28u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1c2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C2Cu;
            // 0x1d1c30: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1C34u;
    // 0x1d1c34: 0x0  nop
    ctx->pc = 0x1d1c34u;
    // NOP
    // 0x1d1c38: 0x0  nop
    ctx->pc = 0x1d1c38u;
    // NOP
    // 0x1d1c3c: 0x0  nop
    ctx->pc = 0x1d1c3cu;
    // NOP
    // 0x1d1c40: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1C40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1C48u;
    // 0x1d1c48: 0x0  nop
    ctx->pc = 0x1d1c48u;
    // NOP
    // 0x1d1c4c: 0x0  nop
    ctx->pc = 0x1d1c4cu;
    // NOP
    // 0x1d1c50: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d1c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d1c54: 0x308600ff  andi        $a2, $a0, 0xFF
    ctx->pc = 0x1d1c54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d1c58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d1c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d1c5c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1c5cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1c60: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1c60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1c64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1c64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1c68: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d1c68u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1c6c: 0x24a56410  addiu       $a1, $a1, 0x6410
    ctx->pc = 0x1d1c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25616));
    // 0x1d1c70: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1C70u;
    SET_GPR_U32(ctx, 31, 0x1D1C78u);
    ctx->pc = 0x1D1C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C70u;
            // 0x1d1c74: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C78u; }
        if (ctx->pc != 0x1D1C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C78u; }
        if (ctx->pc != 0x1D1C78u) { return; }
    }
    ctx->pc = 0x1D1C78u;
label_1d1c78:
    // 0x1d1c78: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1d1c78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1d1c7c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1c80: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1c80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c84: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d1c84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c88: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1C88u;
    SET_GPR_U32(ctx, 31, 0x1D1C90u);
    ctx->pc = 0x1D1C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C88u;
            // 0x1d1c8c: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C90u; }
        if (ctx->pc != 0x1D1C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C90u; }
        if (ctx->pc != 0x1D1C90u) { return; }
    }
    ctx->pc = 0x1D1C90u;
label_1d1c90:
    // 0x1d1c90: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1c90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1c94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1c94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c98: 0x24a53750  addiu       $a1, $a1, 0x3750
    ctx->pc = 0x1d1c98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14160));
    // 0x1d1c9c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1c9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ca0: 0xc074650  jal         func_1D1940
    ctx->pc = 0x1D1CA0u;
    SET_GPR_U32(ctx, 31, 0x1D1CA8u);
    ctx->pc = 0x1D1CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1CA0u;
            // 0x1d1ca4: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1940u;
    if (runtime->hasFunction(0x1D1940u)) {
        auto targetFn = runtime->lookupFunction(0x1D1940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1CA8u; }
        if (ctx->pc != 0x1D1CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1940_0x1d1940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1CA8u; }
        if (ctx->pc != 0x1D1CA8u) { return; }
    }
    ctx->pc = 0x1D1CA8u;
label_1d1ca8:
    // 0x1d1ca8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d1ca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1cac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1cacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1cb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1CB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1CB0u;
            // 0x1d1cb4: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1CB8u;
    // 0x1d1cb8: 0x0  nop
    ctx->pc = 0x1d1cb8u;
    // NOP
    // 0x1d1cbc: 0x0  nop
    ctx->pc = 0x1d1cbcu;
    // NOP
    // 0x1d1cc0: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x1d1cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x1d1cc4: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d1cc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d1cc8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d1cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d1ccc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d1cccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d1cd0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d1cd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1cd4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d1cd4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1cd8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1cd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1cdc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d1cdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ce0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1ce0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1ce4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1ce8: 0xa020ae0f  sb          $zero, -0x51F1($at)
    ctx->pc = 0x1d1ce8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946319), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d1cec: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1cecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1cf0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1cf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1cf4: 0x24a56430  addiu       $a1, $a1, 0x6430
    ctx->pc = 0x1d1cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25648));
    // 0x1d1cf8: 0x8c31440c  lw          $s1, 0x440C($at)
    ctx->pc = 0x1d1cf8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1cfc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1cfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d00: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1D00u;
    SET_GPR_U32(ctx, 31, 0x1D1D08u);
    ctx->pc = 0x1D1D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D00u;
            // 0x1d1d04: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D08u; }
        if (ctx->pc != 0x1D1D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D08u; }
        if (ctx->pc != 0x1D1D08u) { return; }
    }
    ctx->pc = 0x1D1D08u;
label_1d1d08:
    // 0x1d1d08: 0x27b00050  addiu       $s0, $sp, 0x50
    ctx->pc = 0x1d1d08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1d0c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1d10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d14: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1d14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1d18: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1D18u;
    SET_GPR_U32(ctx, 31, 0x1D1D20u);
    ctx->pc = 0x1D1D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D18u;
            // 0x1d1d1c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D20u; }
        if (ctx->pc != 0x1D1D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D20u; }
        if (ctx->pc != 0x1D1D20u) { return; }
    }
    ctx->pc = 0x1D1D20u;
label_1d1d20:
    // 0x1d1d20: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1D20u;
    {
        const bool branch_taken_0x1d1d20 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d1d20) {
            ctx->pc = 0x1D1D44u;
            goto label_1d1d44;
        }
    }
    ctx->pc = 0x1D1D28u;
    // 0x1d1d28: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1d28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1d2c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1d2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1d30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d34: 0x24a5c810  addiu       $a1, $a1, -0x37F0
    ctx->pc = 0x1d1d34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294952976));
    // 0x1d1d38: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1d38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1d3c: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1D3Cu;
    SET_GPR_U32(ctx, 31, 0x1D1D44u);
    ctx->pc = 0x1D1D40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D3Cu;
            // 0x1d1d40: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D44u; }
        if (ctx->pc != 0x1D1D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D44u; }
        if (ctx->pc != 0x1D1D44u) { return; }
    }
    ctx->pc = 0x1D1D44u;
label_1d1d44:
    // 0x1d1d44: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1d44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1d48: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1d48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1d4c: 0x24a56460  addiu       $a1, $a1, 0x6460
    ctx->pc = 0x1d1d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25696));
    // 0x1d1d50: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1d50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d54: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1D54u;
    SET_GPR_U32(ctx, 31, 0x1D1D5Cu);
    ctx->pc = 0x1D1D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D54u;
            // 0x1d1d58: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D5Cu; }
        if (ctx->pc != 0x1D1D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D5Cu; }
        if (ctx->pc != 0x1D1D5Cu) { return; }
    }
    ctx->pc = 0x1D1D5Cu;
label_1d1d5c:
    // 0x1d1d5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1d5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d60: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1d60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d64: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1d64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1d68: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1D68u;
    SET_GPR_U32(ctx, 31, 0x1D1D70u);
    ctx->pc = 0x1D1D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D68u;
            // 0x1d1d6c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D70u; }
        if (ctx->pc != 0x1D1D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D70u; }
        if (ctx->pc != 0x1D1D70u) { return; }
    }
    ctx->pc = 0x1D1D70u;
label_1d1d70:
    // 0x1d1d70: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1D70u;
    {
        const bool branch_taken_0x1d1d70 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d1d70) {
            ctx->pc = 0x1D1D94u;
            goto label_1d1d94;
        }
    }
    ctx->pc = 0x1D1D78u;
    // 0x1d1d78: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1d78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1d7c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1d7cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d80: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1d80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d84: 0x24a5bb80  addiu       $a1, $a1, -0x4480
    ctx->pc = 0x1d1d84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294949760));
    // 0x1d1d88: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1d88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1d8c: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1D8Cu;
    SET_GPR_U32(ctx, 31, 0x1D1D94u);
    ctx->pc = 0x1D1D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D8Cu;
            // 0x1d1d90: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D94u; }
        if (ctx->pc != 0x1D1D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D94u; }
        if (ctx->pc != 0x1D1D94u) { return; }
    }
    ctx->pc = 0x1D1D94u;
label_1d1d94:
    // 0x1d1d94: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1d94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1d98: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1d98u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d9c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1d1d9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1da0: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1da0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1da4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1DA4u;
    SET_GPR_U32(ctx, 31, 0x1D1DACu);
    ctx->pc = 0x1D1DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DA4u;
            // 0x1d1da8: 0x24a56490  addiu       $a1, $a1, 0x6490 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DACu; }
        if (ctx->pc != 0x1D1DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DACu; }
        if (ctx->pc != 0x1D1DACu) { return; }
    }
    ctx->pc = 0x1D1DACu;
label_1d1dac:
    // 0x1d1dac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1dacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1db0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1db0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1db4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1db4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1db8: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1DB8u;
    SET_GPR_U32(ctx, 31, 0x1D1DC0u);
    ctx->pc = 0x1D1DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DB8u;
            // 0x1d1dbc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DC0u; }
        if (ctx->pc != 0x1D1DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DC0u; }
        if (ctx->pc != 0x1D1DC0u) { return; }
    }
    ctx->pc = 0x1D1DC0u;
label_1d1dc0:
    // 0x1d1dc0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1dc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1dc4: 0x18c00006  blez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D1DC4u;
    {
        const bool branch_taken_0x1d1dc4 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D1DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DC4u;
            // 0x1d1dc8: 0x3c05004f  lui         $a1, 0x4F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)79 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1dc4) {
            ctx->pc = 0x1D1DE0u;
            goto label_1d1de0;
        }
    }
    ctx->pc = 0x1D1DCCu;
    // 0x1d1dcc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1dccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1dd0: 0x24a58970  addiu       $a1, $a1, -0x7690
    ctx->pc = 0x1d1dd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294936944));
    // 0x1d1dd4: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1dd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1dd8: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1DD8u;
    SET_GPR_U32(ctx, 31, 0x1D1DE0u);
    ctx->pc = 0x1D1DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DD8u;
            // 0x1d1ddc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DE0u; }
        if (ctx->pc != 0x1D1DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DE0u; }
        if (ctx->pc != 0x1D1DE0u) { return; }
    }
    ctx->pc = 0x1D1DE0u;
label_1d1de0:
    // 0x1d1de0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d1de0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1de4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1de4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1de8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1de8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1dec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1decu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1df0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1df0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1df4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DF4u;
            // 0x1d1df8: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1DFCu;
    // 0x1d1dfc: 0x0  nop
    ctx->pc = 0x1d1dfcu;
    // NOP
    // 0x1d1e00: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d1e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d1e04: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1d1e04u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d1e08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d1e0c: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1d1e0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1e10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1e14: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1e14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1e18: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d1e18u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1e1c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1e1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1e20: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1e20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1e24: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1E24u;
    SET_GPR_U32(ctx, 31, 0x1D1E2Cu);
    ctx->pc = 0x1D1E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E24u;
            // 0x1d1e28: 0x24a564c0  addiu       $a1, $a1, 0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25792));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E2Cu; }
        if (ctx->pc != 0x1D1E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E2Cu; }
        if (ctx->pc != 0x1D1E2Cu) { return; }
    }
    ctx->pc = 0x1D1E2Cu;
label_1d1e2c:
    // 0x1d1e2c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1e30: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1e30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e34: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1e34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1e38: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1E38u;
    SET_GPR_U32(ctx, 31, 0x1D1E40u);
    ctx->pc = 0x1D1E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E38u;
            // 0x1d1e3c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E40u; }
        if (ctx->pc != 0x1D1E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E40u; }
        if (ctx->pc != 0x1D1E40u) { return; }
    }
    ctx->pc = 0x1D1E40u;
label_1d1e40:
    // 0x1d1e40: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1e40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e44: 0x18c00006  blez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D1E44u;
    {
        const bool branch_taken_0x1d1e44 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D1E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E44u;
            // 0x1d1e48: 0x3c05004c  lui         $a1, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1e44) {
            ctx->pc = 0x1D1E60u;
            goto label_1d1e60;
        }
    }
    ctx->pc = 0x1D1E4Cu;
    // 0x1d1e4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e50: 0x24a5aef0  addiu       $a1, $a1, -0x5110
    ctx->pc = 0x1d1e50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946544));
    // 0x1d1e54: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1e54u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1e58: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1E58u;
    SET_GPR_U32(ctx, 31, 0x1D1E60u);
    ctx->pc = 0x1D1E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E58u;
            // 0x1d1e5c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E60u; }
        if (ctx->pc != 0x1D1E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E60u; }
        if (ctx->pc != 0x1D1E60u) { return; }
    }
    ctx->pc = 0x1D1E60u;
label_1d1e60:
    // 0x1d1e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d1e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1e64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1e64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1e68: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E68u;
            // 0x1d1e6c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1E70u;
    // 0x1d1e70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d1e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d1e74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d1e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d1e78: 0x94820bb4  lhu         $v0, 0xBB4($a0)
    ctx->pc = 0x1d1e78u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2996)));
    // 0x1d1e7c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1D1E7Cu;
    {
        const bool branch_taken_0x1d1e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1e7c) {
            ctx->pc = 0x1D1ED8u;
            goto label_1d1ed8;
        }
    }
    ctx->pc = 0x1D1E84u;
    // 0x1d1e84: 0x9083054d  lbu         $v1, 0x54D($a0)
    ctx->pc = 0x1d1e84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1357)));
    // 0x1d1e88: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1d1e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1d1e8c: 0x34468000  ori         $a2, $v0, 0x8000
    ctx->pc = 0x1d1e8cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1d1e90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d1e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1e94: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D1E94u;
    {
        const bool branch_taken_0x1d1e94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d1e94) {
            ctx->pc = 0x1D1EBCu;
            goto label_1d1ebc;
        }
    }
    ctx->pc = 0x1D1E9Cu;
    // 0x1d1e9c: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1e9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1ea0: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1ea0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1ea4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ea8: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1d1ea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1eac: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EACu;
    SET_GPR_U32(ctx, 31, 0x1D1EB4u);
    ctx->pc = 0x1D1EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EACu;
            // 0x1d1eb0: 0x24451100  addiu       $a1, $v0, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1EB4u; }
        if (ctx->pc != 0x1D1EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1EB4u; }
        if (ctx->pc != 0x1D1EB4u) { return; }
    }
    ctx->pc = 0x1D1EB4u;
label_1d1eb4:
    // 0x1d1eb4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D1EB4u;
    {
        const bool branch_taken_0x1d1eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EB4u;
            // 0x1d1eb8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1eb4) {
            ctx->pc = 0x1D1F28u;
            goto label_1d1f28;
        }
    }
    ctx->pc = 0x1D1EBCu;
label_1d1ebc:
    // 0x1d1ebc: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1ebcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1ec0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ec4: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x1d1ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ec8: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EC8u;
    SET_GPR_U32(ctx, 31, 0x1D1ED0u);
    ctx->pc = 0x1D1ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EC8u;
            // 0x1d1ecc: 0x24451000  addiu       $a1, $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ED0u; }
        if (ctx->pc != 0x1D1ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ED0u; }
        if (ctx->pc != 0x1D1ED0u) { return; }
    }
    ctx->pc = 0x1D1ED0u;
label_1d1ed0:
    // 0x1d1ed0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D1ED0u;
    {
        const bool branch_taken_0x1d1ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1ed0) {
            ctx->pc = 0x1D1F24u;
            goto label_1d1f24;
        }
    }
    ctx->pc = 0x1D1ED8u;
label_1d1ed8:
    // 0x1d1ed8: 0x9083054d  lbu         $v1, 0x54D($a0)
    ctx->pc = 0x1d1ed8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1357)));
    // 0x1d1edc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d1edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1ee0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D1EE0u;
    {
        const bool branch_taken_0x1d1ee0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D1EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EE0u;
            // 0x1d1ee4: 0x30c200ff  andi        $v0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1ee0) {
            ctx->pc = 0x1D1F08u;
            goto label_1d1f08;
        }
    }
    ctx->pc = 0x1D1EE8u;
    // 0x1d1ee8: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1ee8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1eec: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1eecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1ef0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ef4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1d1ef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ef8: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EF8u;
    SET_GPR_U32(ctx, 31, 0x1D1F00u);
    ctx->pc = 0x1D1EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EF8u;
            // 0x1d1efc: 0x24451100  addiu       $a1, $v0, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F00u; }
        if (ctx->pc != 0x1D1F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F00u; }
        if (ctx->pc != 0x1D1F00u) { return; }
    }
    ctx->pc = 0x1D1F00u;
label_1d1f00:
    // 0x1d1f00: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1F00u;
    {
        const bool branch_taken_0x1d1f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1f00) {
            ctx->pc = 0x1D1F24u;
            goto label_1d1f24;
        }
    }
    ctx->pc = 0x1D1F08u;
label_1d1f08:
    // 0x1d1f08: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1f08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1f0c: 0x22c00  sll         $a1, $v0, 16
    ctx->pc = 0x1d1f0cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d1f10: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1f10u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1f14: 0xa32025  or          $a0, $a1, $v1
    ctx->pc = 0x1d1f14u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1d1f18: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1f18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1f1c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D1F24u);
    ctx->pc = 0x1D1F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1F1Cu;
            // 0x1d1f20: 0x24451000  addiu       $a1, $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F24u; }
        if (ctx->pc != 0x1D1F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F24u; }
        if (ctx->pc != 0x1D1F24u) { return; }
    }
    ctx->pc = 0x1D1F24u;
label_1d1f24:
    // 0x1d1f24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d1f24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1d1f28:
    // 0x1d1f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1F28u;
            // 0x1d1f2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1F30u;
    // 0x1d1f30: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1F38u;
    // 0x1d1f38: 0x0  nop
    ctx->pc = 0x1d1f38u;
    // NOP
    // 0x1d1f3c: 0x0  nop
    ctx->pc = 0x1d1f3cu;
    // NOP
    // 0x1d1f40: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1F40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1F48u;
    // 0x1d1f48: 0x0  nop
    ctx->pc = 0x1d1f48u;
    // NOP
    // 0x1d1f4c: 0x0  nop
    ctx->pc = 0x1d1f4cu;
    // NOP
    // 0x1d1f50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d1f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d1f54: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1f54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1f58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d1f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d1f5c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d1f5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d1f60: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D1F60u;
    {
        const bool branch_taken_0x1d1f60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d1f60) {
            ctx->pc = 0x1D1FACu;
            goto label_1d1fac;
        }
    }
    ctx->pc = 0x1D1F68u;
    // 0x1d1f68: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d1f68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d1f6c: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f70: 0x902697b8  lbu         $a2, -0x6848($at)
    ctx->pc = 0x1d1f70u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d1f74: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1d1f74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d1f78: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1f78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1f7c: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1d1f7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1d1f80: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1d1f80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1d1f84: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1d1f84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d1f88: 0x432025  or          $a0, $v0, $v1
    ctx->pc = 0x1d1f88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1d1f8c: 0x38c20001  xori        $v0, $a2, 0x1
    ctx->pc = 0x1d1f8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)1);
    // 0x1d1f90: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f94: 0xa02297b8  sb          $v0, -0x6848($at)
    ctx->pc = 0x1d1f94u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294940600), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d1f98: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d1f98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d1f9c: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1d1f9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d1fa0: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1d1fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1d1fa4: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1FA4u;
    SET_GPR_U32(ctx, 31, 0x1D1FACu);
    ctx->pc = 0x1D1FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1FA4u;
            // 0x1d1fa8: 0x24451800  addiu       $a1, $v0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FACu; }
        if (ctx->pc != 0x1D1FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FACu; }
        if (ctx->pc != 0x1D1FACu) { return; }
    }
    ctx->pc = 0x1D1FACu;
label_1d1fac:
    // 0x1d1fac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d1facu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1fb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1FB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1FB0u;
            // 0x1d1fb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1B48u: goto label_1d1b48;
            case 0x1D1B64u: goto label_1d1b64;
            case 0x1D1B78u: goto label_1d1b78;
            case 0x1D1B80u: goto label_1d1b80;
            case 0x1D1BC0u: goto label_1d1bc0;
            case 0x1D1BD8u: goto label_1d1bd8;
            case 0x1D1C04u: goto label_1d1c04;
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            case 0x1D1FACu: goto label_1d1fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1FB8u;
    // 0x1d1fb8: 0x0  nop
    ctx->pc = 0x1d1fb8u;
    // NOP
    // 0x1d1fbc: 0x0  nop
    ctx->pc = 0x1d1fbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
