#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5A20
// Address: 0x1c5a20 - 0x1c5ba4
void sub_001C5A20_0x1c5a20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5A20_0x1c5a20");
#endif

    switch (ctx->pc) {
        case 0x1c5a5cu: goto label_1c5a5c;
        case 0x1c5a74u: goto label_1c5a74;
        case 0x1c5ac0u: goto label_1c5ac0;
        case 0x1c5accu: goto label_1c5acc;
        case 0x1c5adcu: goto label_1c5adc;
        case 0x1c5ae8u: goto label_1c5ae8;
        case 0x1c5af4u: goto label_1c5af4;
        case 0x1c5b00u: goto label_1c5b00;
        case 0x1c5b14u: goto label_1c5b14;
        case 0x1c5b58u: goto label_1c5b58;
        case 0x1c5b68u: goto label_1c5b68;
        default: break;
    }

    ctx->pc = 0x1c5a20u;

    // 0x1c5a20: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1c5a20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1c5a24: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1c5a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1c5a28: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1c5a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1c5a2c: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1c5a2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1c5a30: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c5a30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c5a34: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5a34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c5a38: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c5a38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5a3c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1c5a3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5a40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5A40u;
    {
        const bool branch_taken_0x1c5a40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A40u;
            // 0x1c5a44: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a40) {
            ctx->pc = 0x1C5A50u;
            goto label_1c5a50;
        }
    }
    ctx->pc = 0x1C5A48u;
    // 0x1c5a48: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5A48u;
    {
        const bool branch_taken_0x1c5a48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A48u;
            // 0x1c5a4c: 0x24900018  addiu       $s0, $a0, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a48) {
            ctx->pc = 0x1C5A54u;
            goto label_1c5a54;
        }
    }
    ctx->pc = 0x1C5A50u;
label_1c5a50:
    // 0x1c5a50: 0x24900008  addiu       $s0, $a0, 0x8
    ctx->pc = 0x1c5a50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
label_1c5a54:
    // 0x1c5a54: 0xc071664  jal         func_1C5990
    ctx->pc = 0x1C5A54u;
    SET_GPR_U32(ctx, 31, 0x1C5A5Cu);
    ctx->pc = 0x1C5A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A54u;
            // 0x1c5a58: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5990u;
    if (runtime->hasFunction(0x1C5990u)) {
        auto targetFn = runtime->lookupFunction(0x1C5990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5A5Cu; }
        if (ctx->pc != 0x1C5A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5990_0x1c5990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5A5Cu; }
        if (ctx->pc != 0x1C5A5Cu) { return; }
    }
    ctx->pc = 0x1C5A5Cu;
label_1c5a5c:
    // 0x1c5a5c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5A5Cu;
    {
        const bool branch_taken_0x1c5a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A5Cu;
            // 0x1c5a60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a5c) {
            ctx->pc = 0x1C5A6Cu;
            goto label_1c5a6c;
        }
    }
    ctx->pc = 0x1C5A64u;
    // 0x1c5a64: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1C5A64u;
    {
        const bool branch_taken_0x1c5a64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A64u;
            // 0x1c5a68: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a64) {
            ctx->pc = 0x1C5B88u;
            goto label_1c5b88;
        }
    }
    ctx->pc = 0x1C5A6Cu;
label_1c5a6c:
    // 0x1c5a6c: 0xc071674  jal         func_1C59D0
    ctx->pc = 0x1C5A6Cu;
    SET_GPR_U32(ctx, 31, 0x1C5A74u);
    ctx->pc = 0x1C59D0u;
    if (runtime->hasFunction(0x1C59D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C59D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5A74u; }
        if (ctx->pc != 0x1C5A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C59D0_0x1c59d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5A74u; }
        if (ctx->pc != 0x1C5A74u) { return; }
    }
    ctx->pc = 0x1C5A74u;
label_1c5a74:
    // 0x1c5a74: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1c5a74u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5a78: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5A78u;
    {
        const bool branch_taken_0x1c5a78 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5a78) {
            ctx->pc = 0x1C5A88u;
            goto label_1c5a88;
        }
    }
    ctx->pc = 0x1C5A80u;
    // 0x1c5a80: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1C5A80u;
    {
        const bool branch_taken_0x1c5a80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A80u;
            // 0x1c5a84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a80) {
            ctx->pc = 0x1C5B88u;
            goto label_1c5b88;
        }
    }
    ctx->pc = 0x1C5A88u;
label_1c5a88:
    // 0x1c5a88: 0x92020008  lbu         $v0, 0x8($s0)
    ctx->pc = 0x1c5a88u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c5a8c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5A8Cu;
    {
        const bool branch_taken_0x1c5a8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5a8c) {
            ctx->pc = 0x1C5AA0u;
            goto label_1c5aa0;
        }
    }
    ctx->pc = 0x1C5A94u;
    // 0x1c5a94: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c5a94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c5a98: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C5A98u;
    {
        const bool branch_taken_0x1c5a98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5A98u;
            // 0x1c5a9c: 0xae110000  sw          $s1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5a98) {
            ctx->pc = 0x1C5AB0u;
            goto label_1c5ab0;
        }
    }
    ctx->pc = 0x1C5AA0u;
label_1c5aa0:
    // 0x1c5aa0: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c5aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c5aa4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1c5aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1c5aa8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c5aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c5aac: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x1c5aacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
label_1c5ab0:
    // 0x1c5ab0: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1c5ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1c5ab4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5ab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5ab8: 0xc0722c8  jal         func_1C8B20
    ctx->pc = 0x1C5AB8u;
    SET_GPR_U32(ctx, 31, 0x1C5AC0u);
    ctx->pc = 0x1C5ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AB8u;
            // 0x1c5abc: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8B20u;
    if (runtime->hasFunction(0x1C8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1C8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AC0u; }
        if (ctx->pc != 0x1C5AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8B20_0x1c8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AC0u; }
        if (ctx->pc != 0x1C5AC0u) { return; }
    }
    ctx->pc = 0x1C5AC0u;
label_1c5ac0:
    // 0x1c5ac0: 0xa7a20050  sh          $v0, 0x50($sp)
    ctx->pc = 0x1c5ac0u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 80), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c5ac4: 0xc0722a4  jal         func_1C8A90
    ctx->pc = 0x1C5AC4u;
    SET_GPR_U32(ctx, 31, 0x1C5ACCu);
    ctx->pc = 0x1C5AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AC4u;
            // 0x1c5ac8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A90u;
    if (runtime->hasFunction(0x1C8A90u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5ACCu; }
        if (ctx->pc != 0x1C5ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8A90_0x1c8a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5ACCu; }
        if (ctx->pc != 0x1C5ACCu) { return; }
    }
    ctx->pc = 0x1C5ACCu;
label_1c5acc:
    // 0x1c5acc: 0xa3a20052  sb          $v0, 0x52($sp)
    ctx->pc = 0x1c5accu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 82), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c5ad0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5ad0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5ad4: 0xc0722a4  jal         func_1C8A90
    ctx->pc = 0x1C5AD4u;
    SET_GPR_U32(ctx, 31, 0x1C5ADCu);
    ctx->pc = 0x1C5AD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AD4u;
            // 0x1c5ad8: 0x27b30053  addiu       $s3, $sp, 0x53 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 83));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A90u;
    if (runtime->hasFunction(0x1C8A90u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5ADCu; }
        if (ctx->pc != 0x1C5ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8A90_0x1c8a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5ADCu; }
        if (ctx->pc != 0x1C5ADCu) { return; }
    }
    ctx->pc = 0x1C5ADCu;
label_1c5adc:
    // 0x1c5adc: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1c5adcu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c5ae0: 0xc0722b0  jal         func_1C8AC0
    ctx->pc = 0x1C5AE0u;
    SET_GPR_U32(ctx, 31, 0x1C5AE8u);
    ctx->pc = 0x1C5AE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AE0u;
            // 0x1c5ae4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8AC0u;
    if (runtime->hasFunction(0x1C8AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C8AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AE8u; }
        if (ctx->pc != 0x1C5AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8AC0_0x1c8ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AE8u; }
        if (ctx->pc != 0x1C5AE8u) { return; }
    }
    ctx->pc = 0x1C5AE8u;
label_1c5ae8:
    // 0x1c5ae8: 0xafa20054  sw          $v0, 0x54($sp)
    ctx->pc = 0x1c5ae8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 2));
    // 0x1c5aec: 0xc0722c8  jal         func_1C8B20
    ctx->pc = 0x1C5AECu;
    SET_GPR_U32(ctx, 31, 0x1C5AF4u);
    ctx->pc = 0x1C5AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AECu;
            // 0x1c5af0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8B20u;
    if (runtime->hasFunction(0x1C8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1C8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AF4u; }
        if (ctx->pc != 0x1C5AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8B20_0x1c8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5AF4u; }
        if (ctx->pc != 0x1C5AF4u) { return; }
    }
    ctx->pc = 0x1C5AF4u;
label_1c5af4:
    // 0x1c5af4: 0xa7a20058  sh          $v0, 0x58($sp)
    ctx->pc = 0x1c5af4u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 88), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c5af8: 0xc0722a4  jal         func_1C8A90
    ctx->pc = 0x1C5AF8u;
    SET_GPR_U32(ctx, 31, 0x1C5B00u);
    ctx->pc = 0x1C5AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5AF8u;
            // 0x1c5afc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A90u;
    if (runtime->hasFunction(0x1C8A90u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B00u; }
        if (ctx->pc != 0x1C5B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8A90_0x1c8a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B00u; }
        if (ctx->pc != 0x1C5B00u) { return; }
    }
    ctx->pc = 0x1C5B00u;
label_1c5b00:
    // 0x1c5b00: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c5b00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c5b04: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5b04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5b08: 0x3442007f  ori         $v0, $v0, 0x7F
    ctx->pc = 0x1c5b08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)127);
    // 0x1c5b0c: 0xc0722a4  jal         func_1C8A90
    ctx->pc = 0x1C5B0Cu;
    SET_GPR_U32(ctx, 31, 0x1C5B14u);
    ctx->pc = 0x1C5B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5B0Cu;
            // 0x1c5b10: 0xa3a2005a  sb          $v0, 0x5A($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 90), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A90u;
    if (runtime->hasFunction(0x1C8A90u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B14u; }
        if (ctx->pc != 0x1C5B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8A90_0x1c8a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B14u; }
        if (ctx->pc != 0x1C5B14u) { return; }
    }
    ctx->pc = 0x1C5B14u;
label_1c5b14:
    // 0x1c5b14: 0xa3a2005b  sb          $v0, 0x5B($sp)
    ctx->pc = 0x1c5b14u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 91), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c5b18: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x1c5b18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1c5b1c: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5B1Cu;
    {
        const bool branch_taken_0x1c5b1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1C5B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5B1Cu;
            // 0x1c5b20: 0x30440003  andi        $a0, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5b1c) {
            ctx->pc = 0x1C5B30u;
            goto label_1c5b30;
        }
    }
    ctx->pc = 0x1C5B24u;
    // 0x1c5b24: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5B24u;
    {
        const bool branch_taken_0x1c5b24 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5b24) {
            ctx->pc = 0x1C5B30u;
            goto label_1c5b30;
        }
    }
    ctx->pc = 0x1C5B2Cu;
    // 0x1c5b2c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x1c5b2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
label_1c5b30:
    // 0x1c5b30: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C5B30u;
    {
        const bool branch_taken_0x1c5b30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5b30) {
            ctx->pc = 0x1C5B48u;
            goto label_1c5b48;
        }
    }
    ctx->pc = 0x1C5B38u;
    // 0x1c5b38: 0x92630000  lbu         $v1, 0x0($s3)
    ctx->pc = 0x1c5b38u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1c5b3c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c5b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c5b40: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1c5b40u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1c5b44: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1c5b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1c5b48:
    // 0x1c5b48: 0x2446fff4  addiu       $a2, $v0, -0xC
    ctx->pc = 0x1c5b48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967284));
    // 0x1c5b4c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5b4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5b50: 0xc072274  jal         func_1C89D0
    ctx->pc = 0x1C5B50u;
    SET_GPR_U32(ctx, 31, 0x1C5B58u);
    ctx->pc = 0x1C5B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5B50u;
            // 0x1c5b54: 0x27a5005c  addiu       $a1, $sp, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C89D0u;
    if (runtime->hasFunction(0x1C89D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C89D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B58u; }
        if (ctx->pc != 0x1C5B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C89D0_0x1c89d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B58u; }
        if (ctx->pc != 0x1C5B58u) { return; }
    }
    ctx->pc = 0x1C5B58u;
label_1c5b58:
    // 0x1c5b58: 0x9206000a  lbu         $a2, 0xA($s0)
    ctx->pc = 0x1c5b58u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c5b5c: 0x26240008  addiu       $a0, $s1, 0x8
    ctx->pc = 0x1c5b5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x1c5b60: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5B60u;
    SET_GPR_U32(ctx, 31, 0x1C5B68u);
    ctx->pc = 0x1C5B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5B60u;
            // 0x1c5b64: 0x27a50054  addiu       $a1, $sp, 0x54 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 84));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B68u; }
        if (ctx->pc != 0x1C5B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5B68u; }
        if (ctx->pc != 0x1C5B68u) { return; }
    }
    ctx->pc = 0x1C5B68u;
label_1c5b68:
    // 0x1c5b68: 0x9223000f  lbu         $v1, 0xF($s1)
    ctx->pc = 0x1c5b68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 15)));
    // 0x1c5b6c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c5b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c5b70: 0x34630020  ori         $v1, $v1, 0x20
    ctx->pc = 0x1c5b70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32);
    // 0x1c5b74: 0xa223000f  sb          $v1, 0xF($s1)
    ctx->pc = 0x1c5b74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 15), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c5b78: 0x92030008  lbu         $v1, 0x8($s0)
    ctx->pc = 0x1c5b78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c5b7c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c5b7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c5b80: 0xa2030008  sb          $v1, 0x8($s0)
    ctx->pc = 0x1c5b80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c5b84: 0xa202000b  sb          $v0, 0xB($s0)
    ctx->pc = 0x1c5b84u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 2));
label_1c5b88:
    // 0x1c5b88: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1c5b88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c5b8c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c5b8cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c5b90: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c5b90u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c5b94: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c5b94u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5b98: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5b98u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5b9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5B9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5B9Cu;
            // 0x1c5ba0: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5A50u: goto label_1c5a50;
            case 0x1C5A54u: goto label_1c5a54;
            case 0x1C5A5Cu: goto label_1c5a5c;
            case 0x1C5A6Cu: goto label_1c5a6c;
            case 0x1C5A74u: goto label_1c5a74;
            case 0x1C5A88u: goto label_1c5a88;
            case 0x1C5AA0u: goto label_1c5aa0;
            case 0x1C5AB0u: goto label_1c5ab0;
            case 0x1C5AC0u: goto label_1c5ac0;
            case 0x1C5ACCu: goto label_1c5acc;
            case 0x1C5ADCu: goto label_1c5adc;
            case 0x1C5AE8u: goto label_1c5ae8;
            case 0x1C5AF4u: goto label_1c5af4;
            case 0x1C5B00u: goto label_1c5b00;
            case 0x1C5B14u: goto label_1c5b14;
            case 0x1C5B30u: goto label_1c5b30;
            case 0x1C5B48u: goto label_1c5b48;
            case 0x1C5B58u: goto label_1c5b58;
            case 0x1C5B68u: goto label_1c5b68;
            case 0x1C5B88u: goto label_1c5b88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5BA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
