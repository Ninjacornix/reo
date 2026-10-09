#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0B70
// Address: 0x1d0b70 - 0x1d0c7c
void sub_001D0B70_0x1d0b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0B70_0x1d0b70");
#endif

    switch (ctx->pc) {
        case 0x1d0b8cu: goto label_1d0b8c;
        case 0x1d0b98u: goto label_1d0b98;
        case 0x1d0ba4u: goto label_1d0ba4;
        case 0x1d0bb0u: goto label_1d0bb0;
        case 0x1d0bbcu: goto label_1d0bbc;
        case 0x1d0bc8u: goto label_1d0bc8;
        case 0x1d0bd4u: goto label_1d0bd4;
        case 0x1d0be0u: goto label_1d0be0;
        case 0x1d0becu: goto label_1d0bec;
        case 0x1d0c00u: goto label_1d0c00;
        case 0x1d0c38u: goto label_1d0c38;
        case 0x1d0c50u: goto label_1d0c50;
        case 0x1d0c68u: goto label_1d0c68;
        default: break;
    }

    ctx->pc = 0x1d0b70u;

    // 0x1d0b70: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1d0b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1d0b74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d0b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d0b78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0b78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0b7c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d0b7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0b80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0b84: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0B84u;
    SET_GPR_U32(ctx, 31, 0x1D0B8Cu);
    ctx->pc = 0x1D0B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B84u;
            // 0x1d0b88: 0x24042a00  addiu       $a0, $zero, 0x2A00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B8Cu; }
        if (ctx->pc != 0x1D0B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B8Cu; }
        if (ctx->pc != 0x1D0B8Cu) { return; }
    }
    ctx->pc = 0x1D0B8Cu;
label_1d0b8c:
    // 0x1d0b8c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0b8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d0b90: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0B90u;
    SET_GPR_U32(ctx, 31, 0x1D0B98u);
    ctx->pc = 0x1D0B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B90u;
            // 0x1d0b94: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B98u; }
        if (ctx->pc != 0x1D0B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B98u; }
        if (ctx->pc != 0x1D0B98u) { return; }
    }
    ctx->pc = 0x1D0B98u;
label_1d0b98:
    // 0x1d0b98: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d0b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0b9c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0B9Cu;
    SET_GPR_U32(ctx, 31, 0x1D0BA4u);
    ctx->pc = 0x1D0BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B9Cu;
            // 0x1d0ba0: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BA4u; }
        if (ctx->pc != 0x1D0BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BA4u; }
        if (ctx->pc != 0x1D0BA4u) { return; }
    }
    ctx->pc = 0x1D0BA4u;
label_1d0ba4:
    // 0x1d0ba4: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d0ba8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BA8u;
    SET_GPR_U32(ctx, 31, 0x1D0BB0u);
    ctx->pc = 0x1D0BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BA8u;
            // 0x1d0bac: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BB0u; }
        if (ctx->pc != 0x1D0BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BB0u; }
        if (ctx->pc != 0x1D0BB0u) { return; }
    }
    ctx->pc = 0x1D0BB0u;
label_1d0bb0:
    // 0x1d0bb0: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d0bb4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BB4u;
    SET_GPR_U32(ctx, 31, 0x1D0BBCu);
    ctx->pc = 0x1D0BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BB4u;
            // 0x1d0bb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BBCu; }
        if (ctx->pc != 0x1D0BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BBCu; }
        if (ctx->pc != 0x1D0BBCu) { return; }
    }
    ctx->pc = 0x1D0BBCu;
label_1d0bbc:
    // 0x1d0bbc: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d0bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0bc0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BC0u;
    SET_GPR_U32(ctx, 31, 0x1D0BC8u);
    ctx->pc = 0x1D0BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BC0u;
            // 0x1d0bc4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BC8u; }
        if (ctx->pc != 0x1D0BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BC8u; }
        if (ctx->pc != 0x1D0BC8u) { return; }
    }
    ctx->pc = 0x1D0BC8u;
label_1d0bc8:
    // 0x1d0bc8: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d0bc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0bcc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BCCu;
    SET_GPR_U32(ctx, 31, 0x1D0BD4u);
    ctx->pc = 0x1D0BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BCCu;
            // 0x1d0bd0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BD4u; }
        if (ctx->pc != 0x1D0BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BD4u; }
        if (ctx->pc != 0x1D0BD4u) { return; }
    }
    ctx->pc = 0x1D0BD4u;
label_1d0bd4:
    // 0x1d0bd4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d0bd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0bd8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BD8u;
    SET_GPR_U32(ctx, 31, 0x1D0BE0u);
    ctx->pc = 0x1D0BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BD8u;
            // 0x1d0bdc: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BE0u; }
        if (ctx->pc != 0x1D0BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BE0u; }
        if (ctx->pc != 0x1D0BE0u) { return; }
    }
    ctx->pc = 0x1D0BE0u;
label_1d0be0:
    // 0x1d0be0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0be0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0be4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BE4u;
    SET_GPR_U32(ctx, 31, 0x1D0BECu);
    ctx->pc = 0x1D0BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BE4u;
            // 0x1d0be8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BECu; }
        if (ctx->pc != 0x1D0BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BECu; }
        if (ctx->pc != 0x1D0BECu) { return; }
    }
    ctx->pc = 0x1D0BECu;
label_1d0bec:
    // 0x1d0bec: 0x3c10003d  lui         $s0, 0x3D
    ctx->pc = 0x1d0becu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)61 << 16));
    // 0x1d0bf0: 0x24040240  addiu       $a0, $zero, 0x240
    ctx->pc = 0x1d0bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 576));
    // 0x1d0bf4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1d0bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d0bf8: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0BF8u;
    SET_GPR_U32(ctx, 31, 0x1D0C00u);
    ctx->pc = 0x1D0BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BF8u;
            // 0x1d0bfc: 0x26109230  addiu       $s0, $s0, -0x6DD0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294939184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C00u; }
        if (ctx->pc != 0x1D0C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C00u; }
        if (ctx->pc != 0x1D0C00u) { return; }
    }
    ctx->pc = 0x1D0C00u;
label_1d0c00:
    // 0x1d0c00: 0x3c01003d  lui         $at, 0x3D
    ctx->pc = 0x1d0c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)61 << 16));
    // 0x1d0c04: 0xac229a38  sw          $v0, -0x65C8($at)
    ctx->pc = 0x1d0c04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941240), GPR_U32(ctx, 2));
    // 0x1d0c08: 0x3c01003d  lui         $at, 0x3D
    ctx->pc = 0x1d0c08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)61 << 16));
    // 0x1d0c0c: 0xac209a48  sw          $zero, -0x65B8($at)
    ctx->pc = 0x1d0c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941256), GPR_U32(ctx, 0));
    // 0x1d0c10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0c10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0c14: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0c14u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0c18: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D0C18u;
    {
        const bool branch_taken_0x1d0c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C18u;
            // 0x1d0c1c: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0c18) {
            ctx->pc = 0x1D0C40u;
            goto label_1d0c40;
        }
    }
    ctx->pc = 0x1D0C20u;
    // 0x1d0c20: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0c20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0c24: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0c24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c28: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x1d0c28u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0c2c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0c2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0c30: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0C30u;
    SET_GPR_U32(ctx, 31, 0x1D0C38u);
    ctx->pc = 0x1D0C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C30u;
            // 0x1d0c34: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C38u; }
        if (ctx->pc != 0x1D0C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C38u; }
        if (ctx->pc != 0x1D0C38u) { return; }
    }
    ctx->pc = 0x1D0C38u;
label_1d0c38:
    // 0x1d0c38: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D0C38u;
    {
        const bool branch_taken_0x1d0c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C38u;
            // 0x1d0c3c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0c38) {
            ctx->pc = 0x1D0C6Cu;
            goto label_1d0c6c;
        }
    }
    ctx->pc = 0x1D0C40u;
label_1d0c40:
    // 0x1d0c40: 0x322600ff  andi        $a2, $s1, 0xFF
    ctx->pc = 0x1d0c40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0c44: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d0c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d0c48: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0C48u;
    SET_GPR_U32(ctx, 31, 0x1D0C50u);
    ctx->pc = 0x1D0C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C48u;
            // 0x1d0c4c: 0x24a56248  addiu       $a1, $a1, 0x6248 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C50u; }
        if (ctx->pc != 0x1D0C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C50u; }
        if (ctx->pc != 0x1D0C50u) { return; }
    }
    ctx->pc = 0x1D0C50u;
label_1d0c50:
    // 0x1d0c50: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d0c50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d0c54: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d0c54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c58: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d0c58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d0c5c: 0x24062a00  addiu       $a2, $zero, 0x2A00
    ctx->pc = 0x1d0c5cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
    // 0x1d0c60: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D0C60u;
    SET_GPR_U32(ctx, 31, 0x1D0C68u);
    ctx->pc = 0x1D0C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C60u;
            // 0x1d0c64: 0x34470003  ori         $a3, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C68u; }
        if (ctx->pc != 0x1D0C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C68u; }
        if (ctx->pc != 0x1D0C68u) { return; }
    }
    ctx->pc = 0x1D0C68u;
label_1d0c68:
    // 0x1d0c68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d0c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1d0c6c:
    // 0x1d0c6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0c6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0c70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0c70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0c74: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C74u;
            // 0x1d0c78: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0C7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
