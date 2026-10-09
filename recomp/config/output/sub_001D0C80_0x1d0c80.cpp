#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0C80
// Address: 0x1d0c80 - 0x1d102c
void sub_001D0C80_0x1d0c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0C80_0x1d0c80");
#endif

    switch (ctx->pc) {
        case 0x1d0cc4u: goto label_1d0cc4;
        case 0x1d0cd0u: goto label_1d0cd0;
        case 0x1d0cdcu: goto label_1d0cdc;
        case 0x1d0ce8u: goto label_1d0ce8;
        case 0x1d0cf4u: goto label_1d0cf4;
        case 0x1d0d00u: goto label_1d0d00;
        case 0x1d0d0cu: goto label_1d0d0c;
        case 0x1d0d18u: goto label_1d0d18;
        case 0x1d0d38u: goto label_1d0d38;
        case 0x1d0d6cu: goto label_1d0d6c;
        case 0x1d0db4u: goto label_1d0db4;
        case 0x1d0df8u: goto label_1d0df8;
        case 0x1d0e0cu: goto label_1d0e0c;
        case 0x1d0e38u: goto label_1d0e38;
        case 0x1d0e44u: goto label_1d0e44;
        case 0x1d0e70u: goto label_1d0e70;
        case 0x1d0ea8u: goto label_1d0ea8;
        case 0x1d0efcu: goto label_1d0efc;
        case 0x1d0f04u: goto label_1d0f04;
        case 0x1d0f0cu: goto label_1d0f0c;
        case 0x1d0f38u: goto label_1d0f38;
        case 0x1d0f5cu: goto label_1d0f5c;
        case 0x1d0f78u: goto label_1d0f78;
        case 0x1d0f94u: goto label_1d0f94;
        case 0x1d0f9cu: goto label_1d0f9c;
        case 0x1d0fc4u: goto label_1d0fc4;
        case 0x1d0fe4u: goto label_1d0fe4;
        case 0x1d1004u: goto label_1d1004;
        default: break;
    }

    ctx->pc = 0x1d0c80u;

    // 0x1d0c80: 0x27bdfe90  addiu       $sp, $sp, -0x170
    ctx->pc = 0x1d0c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966928));
    // 0x1d0c84: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d0c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d0c88: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d0c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d0c8c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d0c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d0c90: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0c90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0c94: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0c94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0c98: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d0c98u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0c9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0ca0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d0ca0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0ca4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0ca4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0ca8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d0ca8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0cac: 0x902397b8  lbu         $v1, -0x6848($at)
    ctx->pc = 0x1d0cacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d0cb0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d0cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d0cb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d0cb8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1d0cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1d0cbc: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0CBCu;
    SET_GPR_U32(ctx, 31, 0x1D0CC4u);
    ctx->pc = 0x1D0CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CBCu;
            // 0x1d0cc0: 0x24442100  addiu       $a0, $v0, 0x2100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 8448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CC4u; }
        if (ctx->pc != 0x1D0CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CC4u; }
        if (ctx->pc != 0x1D0CC4u) { return; }
    }
    ctx->pc = 0x1D0CC4u;
label_1d0cc4:
    // 0x1d0cc4: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d0cc8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CC8u;
    SET_GPR_U32(ctx, 31, 0x1D0CD0u);
    ctx->pc = 0x1D0CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CC8u;
            // 0x1d0ccc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CD0u; }
        if (ctx->pc != 0x1D0CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CD0u; }
        if (ctx->pc != 0x1D0CD0u) { return; }
    }
    ctx->pc = 0x1D0CD0u;
label_1d0cd0:
    // 0x1d0cd0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d0cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0cd4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CD4u;
    SET_GPR_U32(ctx, 31, 0x1D0CDCu);
    ctx->pc = 0x1D0CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CD4u;
            // 0x1d0cd8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CDCu; }
        if (ctx->pc != 0x1D0CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CDCu; }
        if (ctx->pc != 0x1D0CDCu) { return; }
    }
    ctx->pc = 0x1D0CDCu;
label_1d0cdc:
    // 0x1d0cdc: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d0ce0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CE0u;
    SET_GPR_U32(ctx, 31, 0x1D0CE8u);
    ctx->pc = 0x1D0CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CE0u;
            // 0x1d0ce4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CE8u; }
        if (ctx->pc != 0x1D0CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CE8u; }
        if (ctx->pc != 0x1D0CE8u) { return; }
    }
    ctx->pc = 0x1D0CE8u;
label_1d0ce8:
    // 0x1d0ce8: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d0ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0cec: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CECu;
    SET_GPR_U32(ctx, 31, 0x1D0CF4u);
    ctx->pc = 0x1D0CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CECu;
            // 0x1d0cf0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CF4u; }
        if (ctx->pc != 0x1D0CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CF4u; }
        if (ctx->pc != 0x1D0CF4u) { return; }
    }
    ctx->pc = 0x1D0CF4u;
label_1d0cf4:
    // 0x1d0cf4: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d0cf8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CF8u;
    SET_GPR_U32(ctx, 31, 0x1D0D00u);
    ctx->pc = 0x1D0CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CF8u;
            // 0x1d0cfc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D00u; }
        if (ctx->pc != 0x1D0D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D00u; }
        if (ctx->pc != 0x1D0D00u) { return; }
    }
    ctx->pc = 0x1D0D00u;
label_1d0d00:
    // 0x1d0d00: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d0d00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0d04: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0D04u;
    SET_GPR_U32(ctx, 31, 0x1D0D0Cu);
    ctx->pc = 0x1D0D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D04u;
            // 0x1d0d08: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D0Cu; }
        if (ctx->pc != 0x1D0D0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D0Cu; }
        if (ctx->pc != 0x1D0D0Cu) { return; }
    }
    ctx->pc = 0x1D0D0Cu;
label_1d0d0c:
    // 0x1d0d0c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0d10: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0D10u;
    SET_GPR_U32(ctx, 31, 0x1D0D18u);
    ctx->pc = 0x1D0D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D10u;
            // 0x1d0d14: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D18u; }
        if (ctx->pc != 0x1D0D18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D18u; }
        if (ctx->pc != 0x1D0D18u) { return; }
    }
    ctx->pc = 0x1D0D18u;
label_1d0d18:
    // 0x1d0d18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0d1c: 0x3c10003c  lui         $s0, 0x3C
    ctx->pc = 0x1d0d1cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)60 << 16));
    // 0x1d0d20: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0d20u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0d24: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D0D24u;
    {
        const bool branch_taken_0x1d0d24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D24u;
            // 0x1d0d28: 0x2610d5d4  addiu       $s0, $s0, -0x2A2C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956500));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0d24) {
            ctx->pc = 0x1D0D6Cu;
            goto label_1d0d6c;
        }
    }
    ctx->pc = 0x1D0D2Cu;
    // 0x1d0d2c: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1d0d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1d0d30: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0D30u;
    SET_GPR_U32(ctx, 31, 0x1D0D38u);
    ctx->pc = 0x1D0D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D30u;
            // 0x1d0d34: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D38u; }
        if (ctx->pc != 0x1D0D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D38u; }
        if (ctx->pc != 0x1D0D38u) { return; }
    }
    ctx->pc = 0x1D0D38u;
label_1d0d38:
    // 0x1d0d38: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1d0d38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1d0d3c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0d3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0d40: 0x326200ff  andi        $v0, $s3, 0xFF
    ctx->pc = 0x1d0d40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0d44: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0d44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0d48: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x1d0d48u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0d4c: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1d0d4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0d50: 0x324200ff  andi        $v0, $s2, 0xFF
    ctx->pc = 0x1d0d50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1d0d54: 0xae000818  sw          $zero, 0x818($s0)
    ctx->pc = 0x1d0d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
    // 0x1d0d58: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1d0d58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1d0d5c: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0d5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0d60: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1d0d60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d0d64: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0D64u;
    SET_GPR_U32(ctx, 31, 0x1D0D6Cu);
    ctx->pc = 0x1D0D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D64u;
            // 0x1d0d68: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D6Cu; }
        if (ctx->pc != 0x1D0D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D6Cu; }
        if (ctx->pc != 0x1D0D6Cu) { return; }
    }
    ctx->pc = 0x1D0D6Cu;
label_1d0d6c:
    // 0x1d0d6c: 0x3c03003c  lui         $v1, 0x3C
    ctx->pc = 0x1d0d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)60 << 16));
    // 0x1d0d70: 0x3c140039  lui         $s4, 0x39
    ctx->pc = 0x1d0d70u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)57 << 16));
    // 0x1d0d74: 0x2463d5d4  addiu       $v1, $v1, -0x2A2C
    ctx->pc = 0x1d0d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956500));
    // 0x1d0d78: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d0d78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d0d7c: 0xac2326b4  sw          $v1, 0x26B4($at)
    ctx->pc = 0x1d0d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9908), GPR_U32(ctx, 3));
    // 0x1d0d80: 0x2694269c  addiu       $s4, $s4, 0x269C
    ctx->pc = 0x1d0d80u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 9884));
    // 0x1d0d84: 0xae830018  sw          $v1, 0x18($s4)
    ctx->pc = 0x1d0d84u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
    // 0x1d0d88: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0d88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0d8c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d0d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d0d90: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d0d90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d0d94: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0d94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0d98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d0d98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0d9c: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1d0d9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1d0da0: 0xae800020  sw          $zero, 0x20($s4)
    ctx->pc = 0x1d0da0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 0));
    // 0x1d0da4: 0x629821  addu        $s3, $v1, $v0
    ctx->pc = 0x1d0da4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d0da8: 0xae800024  sw          $zero, 0x24($s4)
    ctx->pc = 0x1d0da8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 0));
    // 0x1d0dac: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D0DACu;
    SET_GPR_U32(ctx, 31, 0x1D0DB4u);
    ctx->pc = 0x1D0DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DACu;
            // 0x1d0db0: 0xae800028  sw          $zero, 0x28($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DB4u; }
        if (ctx->pc != 0x1D0DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DB4u; }
        if (ctx->pc != 0x1D0DB4u) { return; }
    }
    ctx->pc = 0x1D0DB4u;
label_1d0db4:
    // 0x1d0db4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0db4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0db8: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0db8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0dbc: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1D0DBCu;
    {
        const bool branch_taken_0x1d0dbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DBCu;
            // 0x1d0dc0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0dbc) {
            ctx->pc = 0x1D0E14u;
            goto label_1d0e14;
        }
    }
    ctx->pc = 0x1D0DC4u;
    // 0x1d0dc4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0dc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0dc8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d0dc8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d0dcc: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1d0dccu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0dd0: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0dd4: 0x24a56260  addiu       $a1, $a1, 0x6260
    ctx->pc = 0x1d0dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25184));
    // 0x1d0dd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0dd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0ddc: 0x942943dc  lhu         $t1, 0x43DC($at)
    ctx->pc = 0x1d0ddcu;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0de0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0de4: 0x942a43de  lhu         $t2, 0x43DE($at)
    ctx->pc = 0x1d0de4u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17374)));
    // 0x1d0de8: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d0de8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d0dec: 0x8c268b58  lw          $a2, -0x74A8($at)
    ctx->pc = 0x1d0decu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294937432)));
    // 0x1d0df0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0DF0u;
    SET_GPR_U32(ctx, 31, 0x1D0DF8u);
    ctx->pc = 0x1D0DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DF0u;
            // 0x1d0df4: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DF8u; }
        if (ctx->pc != 0x1D0DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DF8u; }
        if (ctx->pc != 0x1D0DF8u) { return; }
    }
    ctx->pc = 0x1D0DF8u;
label_1d0df8:
    // 0x1d0df8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0dfc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0dfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e00: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0e00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0e04: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D0E04u;
    SET_GPR_U32(ctx, 31, 0x1D0E0Cu);
    ctx->pc = 0x1D0E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E04u;
            // 0x1d0e08: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E0Cu; }
        if (ctx->pc != 0x1D0E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E0Cu; }
        if (ctx->pc != 0x1D0E0Cu) { return; }
    }
    ctx->pc = 0x1D0E0Cu;
label_1d0e0c:
    // 0x1d0e0c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1D0E0Cu;
    {
        const bool branch_taken_0x1d0e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E0Cu;
            // 0x1d0e10: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0e0c) {
            ctx->pc = 0x1D0E48u;
            goto label_1d0e48;
        }
    }
    ctx->pc = 0x1D0E14u;
label_1d0e14:
    // 0x1d0e14: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d0e14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d0e18: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d0e18u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0e1c: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0e20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0e20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0e24: 0x942743dc  lhu         $a3, 0x43DC($at)
    ctx->pc = 0x1d0e24u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0e28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0e28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0e2c: 0x942843de  lhu         $t0, 0x43DE($at)
    ctx->pc = 0x1d0e2cu;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17374)));
    // 0x1d0e30: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0E30u;
    SET_GPR_U32(ctx, 31, 0x1D0E38u);
    ctx->pc = 0x1D0E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E30u;
            // 0x1d0e34: 0x24a56280  addiu       $a1, $a1, 0x6280 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E38u; }
        if (ctx->pc != 0x1D0E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E38u; }
        if (ctx->pc != 0x1D0E38u) { return; }
    }
    ctx->pc = 0x1D0E38u;
label_1d0e38:
    // 0x1d0e38: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0e38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0e3c: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D0E3Cu;
    SET_GPR_U32(ctx, 31, 0x1D0E44u);
    ctx->pc = 0x1D0E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E3Cu;
            // 0x1d0e40: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E44u; }
        if (ctx->pc != 0x1D0E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E44u; }
        if (ctx->pc != 0x1D0E44u) { return; }
    }
    ctx->pc = 0x1D0E44u;
label_1d0e44:
    // 0x1d0e44: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d0e44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d0e48:
    // 0x1d0e48: 0x12000070  beqz        $s0, . + 4 + (0x70 << 2)
    ctx->pc = 0x1D0E48u;
    {
        const bool branch_taken_0x1d0e48 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0e48) {
            ctx->pc = 0x1D100Cu;
            goto label_1d100c;
        }
    }
    ctx->pc = 0x1D0E50u;
    // 0x1d0e50: 0x8e720000  lw          $s2, 0x0($s3)
    ctx->pc = 0x1d0e50u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0e54: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0e54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0e58: 0x24842630  addiu       $a0, $a0, 0x2630
    ctx->pc = 0x1d0e58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9776));
    // 0x1d0e5c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d0e5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d0e60: 0x1288c0  sll         $s1, $s2, 3
    ctx->pc = 0x1d0e60u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x1d0e64: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0e64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e68: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0E68u;
    SET_GPR_U32(ctx, 31, 0x1D0E70u);
    ctx->pc = 0x1D0E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E68u;
            // 0x1d0e6c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E70u; }
        if (ctx->pc != 0x1D0E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E70u; }
        if (ctx->pc != 0x1D0E70u) { return; }
    }
    ctx->pc = 0x1D0E70u;
label_1d0e70:
    // 0x1d0e70: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1d0e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0e74: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0e74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0e78: 0x2221024  and         $v0, $s1, $v0
    ctx->pc = 0x1d0e78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x1d0e7c: 0x24842010  addiu       $a0, $a0, 0x2010
    ctx->pc = 0x1d0e7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8208));
    // 0x1d0e80: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1d0e80u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1d0e84: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x1d0e84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0e88: 0xae820028  sw          $v0, 0x28($s4)
    ctx->pc = 0x1d0e88u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 2));
    // 0x1d0e8c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d0e8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d0e90: 0x8e830028  lw          $v1, 0x28($s4)
    ctx->pc = 0x1d0e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x1d0e94: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0e94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e98: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d0e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d0e9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d0ea0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0EA0u;
    SET_GPR_U32(ctx, 31, 0x1D0EA8u);
    ctx->pc = 0x1D0EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0EA0u;
            // 0x1d0ea4: 0x23080  sll         $a2, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0EA8u; }
        if (ctx->pc != 0x1D0EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0EA8u; }
        if (ctx->pc != 0x1D0EA8u) { return; }
    }
    ctx->pc = 0x1D0EA8u;
label_1d0ea8:
    // 0x1d0ea8: 0x8e850028  lw          $a1, 0x28($s4)
    ctx->pc = 0x1d0ea8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x1d0eac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0eacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0eb0: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1d0eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0eb4: 0x84224200  lh          $v0, 0x4200($at)
    ctx->pc = 0x1d0eb4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 16896)));
    // 0x1d0eb8: 0x52040  sll         $a0, $a1, 1
    ctx->pc = 0x1d0eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1d0ebc: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1d0ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1d0ec0: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1d0ec0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d0ec4: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1d0ec4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1d0ec8: 0x2639821  addu        $s3, $s3, $v1
    ctx->pc = 0x1d0ec8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d0ecc: 0x8e710000  lw          $s1, 0x0($s3)
    ctx->pc = 0x1d0eccu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0ed0: 0x1040003c  beqz        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1D0ED0u;
    {
        const bool branch_taken_0x1d0ed0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0ED0u;
            // 0x1d0ed4: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0ed0) {
            ctx->pc = 0x1D0FC4u;
            goto label_1d0fc4;
        }
    }
    ctx->pc = 0x1D0ED8u;
    // 0x1d0ed8: 0x2a210021  slti        $at, $s1, 0x21
    ctx->pc = 0x1d0ed8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1d0edc: 0x1020002f  beqz        $at, . + 4 + (0x2F << 2)
    ctx->pc = 0x1D0EDCu;
    {
        const bool branch_taken_0x1d0edc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0edc) {
            ctx->pc = 0x1D0F9Cu;
            goto label_1d0f9c;
        }
    }
    ctx->pc = 0x1D0EE4u;
    // 0x1d0ee4: 0x34018001  ori         $at, $zero, 0x8001
    ctx->pc = 0x1d0ee4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x1d0ee8: 0x201082b  sltu        $at, $s0, $at
    ctx->pc = 0x1d0ee8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 1)) ? 1 : 0);
    // 0x1d0eec: 0x14200033  bnez        $at, . + 4 + (0x33 << 2)
    ctx->pc = 0x1D0EECu;
    {
        const bool branch_taken_0x1d0eec = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0EECu;
            // 0x1d0ef0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0eec) {
            ctx->pc = 0x1D0FBCu;
            goto label_1d0fbc;
        }
    }
    ctx->pc = 0x1D0EF4u;
    // 0x1d0ef4: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1D0EF4u;
    {
        const bool branch_taken_0x1d0ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0ef4) {
            ctx->pc = 0x1D0F9Cu;
            goto label_1d0f9c;
        }
    }
    ctx->pc = 0x1D0EFCu;
label_1d0efc:
    // 0x1d0efc: 0xc06c1bc  jal         func_1B06F0
    ctx->pc = 0x1D0EFCu;
    SET_GPR_U32(ctx, 31, 0x1D0F04u);
    ctx->pc = 0x1B06F0u;
    if (runtime->hasFunction(0x1B06F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B06F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F04u; }
        if (ctx->pc != 0x1D0F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B06F0_0x1b06f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F04u; }
        if (ctx->pc != 0x1D0F04u) { return; }
    }
    ctx->pc = 0x1D0F04u;
label_1d0f04:
    // 0x1d0f04: 0xc06bda8  jal         func_1AF6A0
    ctx->pc = 0x1D0F04u;
    SET_GPR_U32(ctx, 31, 0x1D0F0Cu);
    ctx->pc = 0x1D0F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F04u;
            // 0x1d0f08: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF6A0u;
    if (runtime->hasFunction(0x1AF6A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F0Cu; }
        if (ctx->pc != 0x1D0F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F0Cu; }
        if (ctx->pc != 0x1D0F0Cu) { return; }
    }
    ctx->pc = 0x1D0F0Cu;
label_1d0f0c:
    // 0x1d0f0c: 0x2a210021  slti        $at, $s1, 0x21
    ctx->pc = 0x1d0f0cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1d0f10: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1D0F10u;
    {
        const bool branch_taken_0x1d0f10 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F10u;
            // 0x1d0f14: 0x3c080025  lui         $t0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0f10) {
            ctx->pc = 0x1D0F40u;
            goto label_1d0f40;
        }
    }
    ctx->pc = 0x1D0F18u;
    // 0x1d0f18: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f18u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f1c: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f20: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d0f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d0f24: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f28: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f2c: 0x250862a0  addiu       $t0, $t0, 0x62A0
    ctx->pc = 0x1d0f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25248));
    // 0x1d0f30: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F30u;
    SET_GPR_U32(ctx, 31, 0x1D0F38u);
    ctx->pc = 0x1D0F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F30u;
            // 0x1d0f34: 0x220482d  daddu       $t1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F38u; }
        if (ctx->pc != 0x1D0F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F38u; }
        if (ctx->pc != 0x1D0F38u) { return; }
    }
    ctx->pc = 0x1D0F38u;
label_1d0f38:
    // 0x1d0f38: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D0F38u;
    {
        const bool branch_taken_0x1d0f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0f38) {
            ctx->pc = 0x1D0F5Cu;
            goto label_1d0f5c;
        }
    }
    ctx->pc = 0x1D0F40u;
label_1d0f40:
    // 0x1d0f40: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f44: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d0f44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d0f48: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f4c: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f50: 0x250862c0  addiu       $t0, $t0, 0x62C0
    ctx->pc = 0x1d0f50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25280));
    // 0x1d0f54: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F54u;
    SET_GPR_U32(ctx, 31, 0x1D0F5Cu);
    ctx->pc = 0x1D0F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F54u;
            // 0x1d0f58: 0x200482d  daddu       $t1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F5Cu; }
        if (ctx->pc != 0x1D0F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F5Cu; }
        if (ctx->pc != 0x1D0F5Cu) { return; }
    }
    ctx->pc = 0x1D0F5Cu;
label_1d0f5c:
    // 0x1d0f5c: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f5cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f60: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f64: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1d0f64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d0f68: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f6c: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f70: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F70u;
    SET_GPR_U32(ctx, 31, 0x1D0F78u);
    ctx->pc = 0x1D0F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F70u;
            // 0x1d0f74: 0x250862e0  addiu       $t0, $t0, 0x62E0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F78u; }
        if (ctx->pc != 0x1D0F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F78u; }
        if (ctx->pc != 0x1D0F78u) { return; }
    }
    ctx->pc = 0x1D0F78u;
label_1d0f78:
    // 0x1d0f78: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f7c: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f7cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f80: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f84: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0f84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0f88: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f8c: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F8Cu;
    SET_GPR_U32(ctx, 31, 0x1D0F94u);
    ctx->pc = 0x1D0F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F8Cu;
            // 0x1d0f90: 0x250862f0  addiu       $t0, $t0, 0x62F0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F94u; }
        if (ctx->pc != 0x1D0F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F94u; }
        if (ctx->pc != 0x1D0F94u) { return; }
    }
    ctx->pc = 0x1D0F94u;
label_1d0f94:
    // 0x1d0f94: 0xc06eabc  jal         func_1BAAF0
    ctx->pc = 0x1D0F94u;
    SET_GPR_U32(ctx, 31, 0x1D0F9Cu);
    ctx->pc = 0x1D0F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F94u;
            // 0x1d0f98: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BAAF0u;
    if (runtime->hasFunction(0x1BAAF0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F9Cu; }
        if (ctx->pc != 0x1D0F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAAF0_0x1baaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F9Cu; }
        if (ctx->pc != 0x1D0F9Cu) { return; }
    }
    ctx->pc = 0x1D0F9Cu;
label_1d0f9c:
    // 0x1d0f9c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0f9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0fa0: 0x8c224300  lw          $v0, 0x4300($at)
    ctx->pc = 0x1d0fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17152)));
    // 0x1d0fa4: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1d0fa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1d0fa8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1d0fa8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d0fac: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1d0facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1d0fb0: 0x1440ffd2  bnez        $v0, . + 4 + (-0x2E << 2)
    ctx->pc = 0x1D0FB0u;
    {
        const bool branch_taken_0x1d0fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0fb0) {
            ctx->pc = 0x1D0EFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0efc;
        }
    }
    ctx->pc = 0x1D0FB8u;
    // 0x1d0fb8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d0fb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d0fbc:
    // 0x1d0fbc: 0xc06bda8  jal         func_1AF6A0
    ctx->pc = 0x1D0FBCu;
    SET_GPR_U32(ctx, 31, 0x1D0FC4u);
    ctx->pc = 0x1AF6A0u;
    if (runtime->hasFunction(0x1AF6A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FC4u; }
        if (ctx->pc != 0x1D0FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FC4u; }
        if (ctx->pc != 0x1D0FC4u) { return; }
    }
    ctx->pc = 0x1D0FC4u;
label_1d0fc4:
    // 0x1d0fc4: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1d0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1d0fc8: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0fcc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1d0fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1d0fd0: 0x24842030  addiu       $a0, $a0, 0x2030
    ctx->pc = 0x1d0fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8240));
    // 0x1d0fd4: 0x28100  sll         $s0, $v0, 4
    ctx->pc = 0x1d0fd4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1d0fd8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0fd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0fdc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0FDCu;
    SET_GPR_U32(ctx, 31, 0x1D0FE4u);
    ctx->pc = 0x1D0FE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0FDCu;
            // 0x1d0fe0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FE4u; }
        if (ctx->pc != 0x1D0FE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FE4u; }
        if (ctx->pc != 0x1D0FE4u) { return; }
    }
    ctx->pc = 0x1D0FE4u;
label_1d0fe4:
    // 0x1d0fe4: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1d0fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0fe8: 0x3c06003b  lui         $a2, 0x3B
    ctx->pc = 0x1d0fe8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)59 << 16));
    // 0x1d0fec: 0x2021024  and         $v0, $s0, $v0
    ctx->pc = 0x1d0fecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x1d0ff0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d0ff0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0ff4: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1d0ff4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1d0ff8: 0x24c6a6d0  addiu       $a2, $a2, -0x5930
    ctx->pc = 0x1d0ff8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944464));
    // 0x1d0ffc: 0xc163fb0  jal         func_58FEC0
    ctx->pc = 0x1D0FFCu;
    SET_GPR_U32(ctx, 31, 0x1D1004u);
    ctx->pc = 0x1D1000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0FFCu;
            // 0x1d1000: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x58FEC0u;
    {
        auto targetFn = runtime->lookupFunction(0x58FEC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1004u; }
        if (ctx->pc != 0x1D1004u) { return; }
    }
    ctx->pc = 0x1D1004u;
label_1d1004:
    // 0x1d1004: 0xae920020  sw          $s2, 0x20($s4)
    ctx->pc = 0x1d1004u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 18));
    // 0x1d1008: 0xae910024  sw          $s1, 0x24($s4)
    ctx->pc = 0x1d1008u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 17));
label_1d100c:
    // 0x1d100c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d100cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d1010: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d1010u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1014: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1014u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1018: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1018u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d101c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d101cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1020: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1020u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1024: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1024u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1024u;
            // 0x1d1028: 0x27bd0170  addiu       $sp, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D102Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
