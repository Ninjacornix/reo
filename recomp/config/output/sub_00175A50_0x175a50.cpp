#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175A50
// Address: 0x175a50 - 0x175c50
void sub_00175A50_0x175a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175A50_0x175a50");
#endif

    switch (ctx->pc) {
        case 0x175a78u: goto label_175a78;
        case 0x175a8cu: goto label_175a8c;
        case 0x175a9cu: goto label_175a9c;
        case 0x175ab0u: goto label_175ab0;
        case 0x175ac0u: goto label_175ac0;
        case 0x175ad4u: goto label_175ad4;
        case 0x175ae4u: goto label_175ae4;
        case 0x175af4u: goto label_175af4;
        case 0x175b00u: goto label_175b00;
        case 0x175b0cu: goto label_175b0c;
        case 0x175b18u: goto label_175b18;
        case 0x175b28u: goto label_175b28;
        case 0x175b58u: goto label_175b58;
        case 0x175b90u: goto label_175b90;
        default: break;
    }

    ctx->pc = 0x175a50u;

    // 0x175a50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175a54: 0x3c020017  lui         $v0, 0x17
    ctx->pc = 0x175a54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23 << 16));
    // 0x175a58: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175a5c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x175a5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175a60: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x175a60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175a64: 0x244564b0  addiu       $a1, $v0, 0x64B0
    ctx->pc = 0x175a64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 25776));
    // 0x175a68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175a6c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x175a6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x175a70: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175A70u;
    SET_GPR_U32(ctx, 31, 0x175A78u);
    ctx->pc = 0x175A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175A70u;
            // 0x175a74: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A78u; }
        if (ctx->pc != 0x175A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A78u; }
        if (ctx->pc != 0x175A78u) { return; }
    }
    ctx->pc = 0x175A78u;
label_175a78:
    // 0x175a78: 0x3c050017  lui         $a1, 0x17
    ctx->pc = 0x175a78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)23 << 16));
    // 0x175a7c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x175a7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175a80: 0x24a564f8  addiu       $a1, $a1, 0x64F8
    ctx->pc = 0x175a80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25848));
    // 0x175a84: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175A84u;
    SET_GPR_U32(ctx, 31, 0x175A8Cu);
    ctx->pc = 0x175A88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175A84u;
            // 0x175a88: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A8Cu; }
        if (ctx->pc != 0x175A8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A8Cu; }
        if (ctx->pc != 0x175A8Cu) { return; }
    }
    ctx->pc = 0x175A8Cu;
label_175a8c:
    // 0x175a8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x175a8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175a90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x175a90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175a94: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175A94u;
    SET_GPR_U32(ctx, 31, 0x175A9Cu);
    ctx->pc = 0x175A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175A94u;
            // 0x175a98: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A9Cu; }
        if (ctx->pc != 0x175A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175A9Cu; }
        if (ctx->pc != 0x175A9Cu) { return; }
    }
    ctx->pc = 0x175A9Cu;
label_175a9c:
    // 0x175a9c: 0x3c050017  lui         $a1, 0x17
    ctx->pc = 0x175a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)23 << 16));
    // 0x175aa0: 0x24a56558  addiu       $a1, $a1, 0x6558
    ctx->pc = 0x175aa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25944));
    // 0x175aa4: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x175aa4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x175aa8: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175AA8u;
    SET_GPR_U32(ctx, 31, 0x175AB0u);
    ctx->pc = 0x175AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175AA8u;
            // 0x175aac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AB0u; }
        if (ctx->pc != 0x175AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AB0u; }
        if (ctx->pc != 0x175AB0u) { return; }
    }
    ctx->pc = 0x175AB0u;
label_175ab0:
    // 0x175ab0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x175ab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175ab4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x175ab4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175ab8: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175AB8u;
    SET_GPR_U32(ctx, 31, 0x175AC0u);
    ctx->pc = 0x175ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175AB8u;
            // 0x175abc: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AC0u; }
        if (ctx->pc != 0x175AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AC0u; }
        if (ctx->pc != 0x175AC0u) { return; }
    }
    ctx->pc = 0x175AC0u;
label_175ac0:
    // 0x175ac0: 0x3c050017  lui         $a1, 0x17
    ctx->pc = 0x175ac0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)23 << 16));
    // 0x175ac4: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x175ac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x175ac8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x175ac8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175acc: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x175ACCu;
    SET_GPR_U32(ctx, 31, 0x175AD4u);
    ctx->pc = 0x175AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175ACCu;
            // 0x175ad0: 0x24a56578  addiu       $a1, $a1, 0x6578 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AD4u; }
        if (ctx->pc != 0x175AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AD4u; }
        if (ctx->pc != 0x175AD4u) { return; }
    }
    ctx->pc = 0x175AD4u;
label_175ad4:
    // 0x175ad4: 0xae200018  sw          $zero, 0x18($s1)
    ctx->pc = 0x175ad4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 0));
    // 0x175ad8: 0x26240094  addiu       $a0, $s1, 0x94
    ctx->pc = 0x175ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 148));
    // 0x175adc: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175ADCu;
    SET_GPR_U32(ctx, 31, 0x175AE4u);
    ctx->pc = 0x175AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175ADCu;
            // 0x175ae0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AE4u; }
        if (ctx->pc != 0x175AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AE4u; }
        if (ctx->pc != 0x175AE4u) { return; }
    }
    ctx->pc = 0x175AE4u;
label_175ae4:
    // 0x175ae4: 0x2624001c  addiu       $a0, $s1, 0x1C
    ctx->pc = 0x175ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 28));
    // 0x175ae8: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x175ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
    // 0x175aec: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175AECu;
    SET_GPR_U32(ctx, 31, 0x175AF4u);
    ctx->pc = 0x175AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175AECu;
            // 0x175af0: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AF4u; }
        if (ctx->pc != 0x175AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175AF4u; }
        if (ctx->pc != 0x175AF4u) { return; }
    }
    ctx->pc = 0x175AF4u;
label_175af4:
    // 0x175af4: 0x26240044  addiu       $a0, $s1, 0x44
    ctx->pc = 0x175af4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 68));
    // 0x175af8: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175AF8u;
    SET_GPR_U32(ctx, 31, 0x175B00u);
    ctx->pc = 0x175AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175AF8u;
            // 0x175afc: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B00u; }
        if (ctx->pc != 0x175B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B00u; }
        if (ctx->pc != 0x175B00u) { return; }
    }
    ctx->pc = 0x175B00u;
label_175b00:
    // 0x175b00: 0x2624006c  addiu       $a0, $s1, 0x6C
    ctx->pc = 0x175b00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 108));
    // 0x175b04: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175B04u;
    SET_GPR_U32(ctx, 31, 0x175B0Cu);
    ctx->pc = 0x175B08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175B04u;
            // 0x175b08: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B0Cu; }
        if (ctx->pc != 0x175B0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B0Cu; }
        if (ctx->pc != 0x175B0Cu) { return; }
    }
    ctx->pc = 0x175B0Cu;
label_175b0c:
    // 0x175b0c: 0x262400bc  addiu       $a0, $s1, 0xBC
    ctx->pc = 0x175b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 188));
    // 0x175b10: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175B10u;
    SET_GPR_U32(ctx, 31, 0x175B18u);
    ctx->pc = 0x175B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175B10u;
            // 0x175b14: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B18u; }
        if (ctx->pc != 0x175B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B18u; }
        if (ctx->pc != 0x175B18u) { return; }
    }
    ctx->pc = 0x175B18u;
label_175b18:
    // 0x175b18: 0x262400e4  addiu       $a0, $s1, 0xE4
    ctx->pc = 0x175b18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 228));
    // 0x175b1c: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x175b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
    // 0x175b20: 0xc05d714  jal         func_175C50
    ctx->pc = 0x175B20u;
    SET_GPR_U32(ctx, 31, 0x175B28u);
    ctx->pc = 0x175B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175B20u;
            // 0x175b24: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B28u; }
        if (ctx->pc != 0x175B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175B28u; }
        if (ctx->pc != 0x175B28u) { return; }
    }
    ctx->pc = 0x175B28u;
label_175b28:
    // 0x175b28: 0xae20010c  sw          $zero, 0x10C($s1)
    ctx->pc = 0x175b28u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 268), GPR_U32(ctx, 0));
    // 0x175b2c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x175b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x175b30: 0xae200110  sw          $zero, 0x110($s1)
    ctx->pc = 0x175b30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 272), GPR_U32(ctx, 0));
    // 0x175b34: 0xae20011c  sw          $zero, 0x11C($s1)
    ctx->pc = 0x175b34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 284), GPR_U32(ctx, 0));
    // 0x175b38: 0x26240008  addiu       $a0, $s1, 0x8
    ctx->pc = 0x175b38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x175b3c: 0xae200120  sw          $zero, 0x120($s1)
    ctx->pc = 0x175b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 288), GPR_U32(ctx, 0));
    // 0x175b40: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x175b40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x175b44: 0xae200124  sw          $zero, 0x124($s1)
    ctx->pc = 0x175b44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 292), GPR_U32(ctx, 0));
    // 0x175b48: 0xae220118  sw          $v0, 0x118($s1)
    ctx->pc = 0x175b48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 280), GPR_U32(ctx, 2));
    // 0x175b4c: 0xae220114  sw          $v0, 0x114($s1)
    ctx->pc = 0x175b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 276), GPR_U32(ctx, 2));
    // 0x175b50: 0x262201a4  addiu       $v0, $s1, 0x1A4
    ctx->pc = 0x175b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 420));
    // 0x175b54: 0x0  nop
    ctx->pc = 0x175b54u;
    // NOP
label_175b58:
    // 0x175b58: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x175b58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x175b5c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x175b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x175b60: 0x0  nop
    ctx->pc = 0x175b60u;
    // NOP
    // 0x175b64: 0x0  nop
    ctx->pc = 0x175b64u;
    // NOP
    // 0x175b68: 0x0  nop
    ctx->pc = 0x175b68u;
    // NOP
    // 0x175b6c: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x175B6Cu;
    {
        const bool branch_taken_0x175b6c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x175B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175B6Cu;
            // 0x175b70: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175b6c) {
            ctx->pc = 0x175B58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175b58;
        }
    }
    ctx->pc = 0x175B74u;
    // 0x175b74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x175b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175b78: 0xae2001ac  sw          $zero, 0x1AC($s1)
    ctx->pc = 0x175b78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 428), GPR_U32(ctx, 0));
    // 0x175b7c: 0xae2001b0  sw          $zero, 0x1B0($s1)
    ctx->pc = 0x175b7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 432), GPR_U32(ctx, 0));
    // 0x175b80: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x175b80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x175b84: 0xae2001b4  sw          $zero, 0x1B4($s1)
    ctx->pc = 0x175b84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 436), GPR_U32(ctx, 0));
    // 0x175b88: 0xae2201a8  sw          $v0, 0x1A8($s1)
    ctx->pc = 0x175b88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 424), GPR_U32(ctx, 2));
    // 0x175b8c: 0x2482022c  addiu       $v0, $a0, 0x22C
    ctx->pc = 0x175b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 556));
label_175b90:
    // 0x175b90: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x175b90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x175b94: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x175b94u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x175b98: 0x0  nop
    ctx->pc = 0x175b98u;
    // NOP
    // 0x175b9c: 0x0  nop
    ctx->pc = 0x175b9cu;
    // NOP
    // 0x175ba0: 0x0  nop
    ctx->pc = 0x175ba0u;
    // NOP
    // 0x175ba4: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x175BA4u;
    {
        const bool branch_taken_0x175ba4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x175BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175BA4u;
            // 0x175ba8: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175ba4) {
            ctx->pc = 0x175B90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175b90;
        }
    }
    ctx->pc = 0x175BACu;
    // 0x175bac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x175bacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x175bb0: 0xae200264  sw          $zero, 0x264($s1)
    ctx->pc = 0x175bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 612), GPR_U32(ctx, 0));
    // 0x175bb4: 0xae220288  sw          $v0, 0x288($s1)
    ctx->pc = 0x175bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 648), GPR_U32(ctx, 2));
    // 0x175bb8: 0x2402fffb  addiu       $v0, $zero, -0x5
    ctx->pc = 0x175bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x175bbc: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x175bbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x175bc0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x175bc0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x175bc4: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x175bc4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x175bc8: 0x8e270264  lw          $a3, 0x264($s1)
    ctx->pc = 0x175bc8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 612)));
    // 0x175bcc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x175bccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175bd0: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x175bd0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x175bd4: 0x240403e8  addiu       $a0, $zero, 0x3E8
    ctx->pc = 0x175bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x175bd8: 0x24050064  addiu       $a1, $zero, 0x64
    ctx->pc = 0x175bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x175bdc: 0xae220294  sw          $v0, 0x294($s1)
    ctx->pc = 0x175bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 660), GPR_U32(ctx, 2));
    // 0x175be0: 0xae26025c  sw          $a2, 0x25C($s1)
    ctx->pc = 0x175be0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 604), GPR_U32(ctx, 6));
    // 0x175be4: 0xae200298  sw          $zero, 0x298($s1)
    ctx->pc = 0x175be4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 664), GPR_U32(ctx, 0));
    // 0x175be8: 0xae240268  sw          $a0, 0x268($s1)
    ctx->pc = 0x175be8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 616), GPR_U32(ctx, 4));
    // 0x175bec: 0xae250278  sw          $a1, 0x278($s1)
    ctx->pc = 0x175becu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 632), GPR_U32(ctx, 5));
    // 0x175bf0: 0xe6200284  swc1        $f0, 0x284($s1)
    ctx->pc = 0x175bf0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 644), bits); }
    // 0x175bf4: 0xae27028c  sw          $a3, 0x28C($s1)
    ctx->pc = 0x175bf4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 652), GPR_U32(ctx, 7));
    // 0x175bf8: 0xae23029c  sw          $v1, 0x29C($s1)
    ctx->pc = 0x175bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 668), GPR_U32(ctx, 3));
    // 0x175bfc: 0xae220238  sw          $v0, 0x238($s1)
    ctx->pc = 0x175bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 568), GPR_U32(ctx, 2));
    // 0x175c00: 0xae23023c  sw          $v1, 0x23C($s1)
    ctx->pc = 0x175c00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 572), GPR_U32(ctx, 3));
    // 0x175c04: 0xae220240  sw          $v0, 0x240($s1)
    ctx->pc = 0x175c04u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 576), GPR_U32(ctx, 2));
    // 0x175c08: 0xae230244  sw          $v1, 0x244($s1)
    ctx->pc = 0x175c08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 580), GPR_U32(ctx, 3));
    // 0x175c0c: 0xae220248  sw          $v0, 0x248($s1)
    ctx->pc = 0x175c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 584), GPR_U32(ctx, 2));
    // 0x175c10: 0xae23024c  sw          $v1, 0x24C($s1)
    ctx->pc = 0x175c10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 588), GPR_U32(ctx, 3));
    // 0x175c14: 0xae220250  sw          $v0, 0x250($s1)
    ctx->pc = 0x175c14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 592), GPR_U32(ctx, 2));
    // 0x175c18: 0xae260254  sw          $a2, 0x254($s1)
    ctx->pc = 0x175c18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 596), GPR_U32(ctx, 6));
    // 0x175c1c: 0xae200258  sw          $zero, 0x258($s1)
    ctx->pc = 0x175c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 600), GPR_U32(ctx, 0));
    // 0x175c20: 0xae200260  sw          $zero, 0x260($s1)
    ctx->pc = 0x175c20u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 608), GPR_U32(ctx, 0));
    // 0x175c24: 0xae20026c  sw          $zero, 0x26C($s1)
    ctx->pc = 0x175c24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 620), GPR_U32(ctx, 0));
    // 0x175c28: 0xae200270  sw          $zero, 0x270($s1)
    ctx->pc = 0x175c28u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 624), GPR_U32(ctx, 0));
    // 0x175c2c: 0xae230274  sw          $v1, 0x274($s1)
    ctx->pc = 0x175c2cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 628), GPR_U32(ctx, 3));
    // 0x175c30: 0xe620027c  swc1        $f0, 0x27C($s1)
    ctx->pc = 0x175c30u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 636), bits); }
    // 0x175c34: 0xae200280  sw          $zero, 0x280($s1)
    ctx->pc = 0x175c34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 640), GPR_U32(ctx, 0));
    // 0x175c38: 0xae200290  sw          $zero, 0x290($s1)
    ctx->pc = 0x175c38u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 656), GPR_U32(ctx, 0));
    // 0x175c3c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175c3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175c40: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175c40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175c44: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175c44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175c48: 0x3e00008  jr          $ra
    ctx->pc = 0x175C48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175C48u;
            // 0x175c4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175A78u: goto label_175a78;
            case 0x175A8Cu: goto label_175a8c;
            case 0x175A9Cu: goto label_175a9c;
            case 0x175AB0u: goto label_175ab0;
            case 0x175AC0u: goto label_175ac0;
            case 0x175AD4u: goto label_175ad4;
            case 0x175AE4u: goto label_175ae4;
            case 0x175AF4u: goto label_175af4;
            case 0x175B00u: goto label_175b00;
            case 0x175B0Cu: goto label_175b0c;
            case 0x175B18u: goto label_175b18;
            case 0x175B28u: goto label_175b28;
            case 0x175B58u: goto label_175b58;
            case 0x175B90u: goto label_175b90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175C50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
