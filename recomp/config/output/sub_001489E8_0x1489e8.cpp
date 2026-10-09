#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001489E8
// Address: 0x1489e8 - 0x148db8
void sub_001489E8_0x1489e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001489E8_0x1489e8");
#endif

    switch (ctx->pc) {
        case 0x148a04u: goto label_148a04;
        case 0x148a34u: goto label_148a34;
        case 0x148a40u: goto label_148a40;
        case 0x148a64u: goto label_148a64;
        case 0x148a74u: goto label_148a74;
        case 0x148a80u: goto label_148a80;
        case 0x148a88u: goto label_148a88;
        case 0x148aa4u: goto label_148aa4;
        case 0x148ab0u: goto label_148ab0;
        case 0x148ac0u: goto label_148ac0;
        case 0x148accu: goto label_148acc;
        case 0x148ad4u: goto label_148ad4;
        case 0x148af0u: goto label_148af0;
        case 0x148af8u: goto label_148af8;
        case 0x148c38u: goto label_148c38;
        case 0x148c4cu: goto label_148c4c;
        case 0x148c64u: goto label_148c64;
        case 0x148c7cu: goto label_148c7c;
        case 0x148cccu: goto label_148ccc;
        case 0x148cdcu: goto label_148cdc;
        case 0x148cecu: goto label_148cec;
        case 0x148cfcu: goto label_148cfc;
        case 0x148d0cu: goto label_148d0c;
        case 0x148d1cu: goto label_148d1c;
        case 0x148d2cu: goto label_148d2c;
        case 0x148d3cu: goto label_148d3c;
        case 0x148d4cu: goto label_148d4c;
        default: break;
    }

    ctx->pc = 0x1489e8u;

    // 0x1489e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1489e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1489ec: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1489ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1489f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1489f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1489f4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1489f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1489f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1489f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1489fc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1489FCu;
    SET_GPR_U32(ctx, 31, 0x148A04u);
    ctx->pc = 0x148A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1489FCu;
            // 0x148a00: 0xae0000ec  sw          $zero, 0xEC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 236), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A04u; }
        if (ctx->pc != 0x148A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A04u; }
        if (ctx->pc != 0x148A04u) { return; }
    }
    ctx->pc = 0x148A04u;
label_148a04:
    // 0x148a04: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x148a04u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a08: 0x31202  srl         $v0, $v1, 8
    ctx->pc = 0x148a08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x148a0c: 0x30420fff  andi        $v0, $v0, 0xFFF
    ctx->pc = 0x148a0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4095);
    // 0x148a10: 0x31d02  srl         $v1, $v1, 20
    ctx->pc = 0x148a10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 20));
    // 0x148a14: 0xae03013c  sw          $v1, 0x13C($s0)
    ctx->pc = 0x148a14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 316), GPR_U32(ctx, 3));
    // 0x148a18: 0x28440af1  slti        $a0, $v0, 0xAF1
    ctx->pc = 0x148a18u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2801) ? 1 : 0);
    // 0x148a1c: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x148A1Cu;
    {
        const bool branch_taken_0x148a1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x148A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148A1Cu;
            // 0x148a20: 0xae020140  sw          $v0, 0x140($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 320), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148a1c) {
            ctx->pc = 0x148A34u;
            goto label_148a34;
        }
    }
    ctx->pc = 0x148A24u;
    // 0x148a24: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x148a24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x148a28: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148a28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a2c: 0xc05221c  jal         func_148870
    ctx->pc = 0x148A2Cu;
    SET_GPR_U32(ctx, 31, 0x148A34u);
    ctx->pc = 0x148A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A2Cu;
            // 0x148a30: 0x24a5e148  addiu       $a1, $a1, -0x1EB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A34u; }
        if (ctx->pc != 0x148A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A34u; }
        if (ctx->pc != 0x148A34u) { return; }
    }
    ctx->pc = 0x148A34u;
label_148a34:
    // 0x148a34: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148a34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a38: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x148A38u;
    SET_GPR_U32(ctx, 31, 0x148A40u);
    ctx->pc = 0x148A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A38u;
            // 0x148a3c: 0x2405001e  addiu       $a1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A40u; }
        if (ctx->pc != 0x148A40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A40u; }
        if (ctx->pc != 0x148A40u) { return; }
    }
    ctx->pc = 0x148A40u;
label_148a40:
    // 0x148a40: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x148a40u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a44: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148a44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a48: 0x31042  srl         $v0, $v1, 1
    ctx->pc = 0x148a48u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x148a4c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x148a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148a50: 0x31b02  srl         $v1, $v1, 12
    ctx->pc = 0x148a50u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 12));
    // 0x148a54: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x148a54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x148a58: 0xae03014c  sw          $v1, 0x14C($s0)
    ctx->pc = 0x148a58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 332), GPR_U32(ctx, 3));
    // 0x148a5c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x148A5Cu;
    SET_GPR_U32(ctx, 31, 0x148A64u);
    ctx->pc = 0x148A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A5Cu;
            // 0x148a60: 0xae020150  sw          $v0, 0x150($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 336), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A64u; }
        if (ctx->pc != 0x148A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A64u; }
        if (ctx->pc != 0x148A64u) { return; }
    }
    ctx->pc = 0x148A64u;
label_148a64:
    // 0x148a64: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x148A64u;
    {
        const bool branch_taken_0x148a64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148A64u;
            // 0x148a68: 0xae020858  sw          $v0, 0x858($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2136), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148a64) {
            ctx->pc = 0x148A90u;
            goto label_148a90;
        }
    }
    ctx->pc = 0x148A6Cu;
    // 0x148a6c: 0xc051496  jal         func_145258
    ctx->pc = 0x148A6Cu;
    SET_GPR_U32(ctx, 31, 0x148A74u);
    ctx->pc = 0x148A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A6Cu;
            // 0x148a70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A74u; }
        if (ctx->pc != 0x148A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A74u; }
        if (ctx->pc != 0x148A74u) { return; }
    }
    ctx->pc = 0x148A74u;
label_148a74:
    // 0x148a74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148a74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a78: 0xc05148a  jal         func_145228
    ctx->pc = 0x148A78u;
    SET_GPR_U32(ctx, 31, 0x148A80u);
    ctx->pc = 0x148A7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A78u;
            // 0x148a7c: 0x3c055000  lui         $a1, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20480 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A80u; }
        if (ctx->pc != 0x148A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A80u; }
        if (ctx->pc != 0x148A80u) { return; }
    }
    ctx->pc = 0x148A80u;
label_148a80:
    // 0x148a80: 0xc051496  jal         func_145258
    ctx->pc = 0x148A80u;
    SET_GPR_U32(ctx, 31, 0x148A88u);
    ctx->pc = 0x148A84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A80u;
            // 0x148a84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A88u; }
        if (ctx->pc != 0x148A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148A88u; }
        if (ctx->pc != 0x148A88u) { return; }
    }
    ctx->pc = 0x148A88u;
label_148a88:
    // 0x148a88: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x148A88u;
    {
        const bool branch_taken_0x148a88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148A88u;
            // 0x148a8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148a88) {
            ctx->pc = 0x148AA8u;
            goto label_148aa8;
        }
    }
    ctx->pc = 0x148A90u;
label_148a90:
    // 0x148a90: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x148a90u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x148a94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148a94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148a98: 0x24c6a780  addiu       $a2, $a2, -0x5880
    ctx->pc = 0x148a98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944640));
    // 0x148a9c: 0xc0523a6  jal         func_148E98
    ctx->pc = 0x148A9Cu;
    SET_GPR_U32(ctx, 31, 0x148AA4u);
    ctx->pc = 0x148AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148A9Cu;
            // 0x148aa0: 0x3c055000  lui         $a1, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20480 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148E98u;
    if (runtime->hasFunction(0x148E98u)) {
        auto targetFn = runtime->lookupFunction(0x148E98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AA4u; }
        if (ctx->pc != 0x148AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148E98_0x148e98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AA4u; }
        if (ctx->pc != 0x148AA4u) { return; }
    }
    ctx->pc = 0x148AA4u;
label_148aa4:
    // 0x148aa4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148aa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_148aa8:
    // 0x148aa8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x148AA8u;
    SET_GPR_U32(ctx, 31, 0x148AB0u);
    ctx->pc = 0x148AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148AA8u;
            // 0x148aac: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AB0u; }
        if (ctx->pc != 0x148AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AB0u; }
        if (ctx->pc != 0x148AB0u) { return; }
    }
    ctx->pc = 0x148AB0u;
label_148ab0:
    // 0x148ab0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x148AB0u;
    {
        const bool branch_taken_0x148ab0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148AB0u;
            // 0x148ab4: 0xae02085c  sw          $v0, 0x85C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2140), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148ab0) {
            ctx->pc = 0x148ADCu;
            goto label_148adc;
        }
    }
    ctx->pc = 0x148AB8u;
    // 0x148ab8: 0xc051496  jal         func_145258
    ctx->pc = 0x148AB8u;
    SET_GPR_U32(ctx, 31, 0x148AC0u);
    ctx->pc = 0x148ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148AB8u;
            // 0x148abc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AC0u; }
        if (ctx->pc != 0x148AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AC0u; }
        if (ctx->pc != 0x148AC0u) { return; }
    }
    ctx->pc = 0x148AC0u;
label_148ac0:
    // 0x148ac0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148ac0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ac4: 0xc05148a  jal         func_145228
    ctx->pc = 0x148AC4u;
    SET_GPR_U32(ctx, 31, 0x148ACCu);
    ctx->pc = 0x148AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148AC4u;
            // 0x148ac8: 0x3c055800  lui         $a1, 0x5800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22528 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ACCu; }
        if (ctx->pc != 0x148ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ACCu; }
        if (ctx->pc != 0x148ACCu) { return; }
    }
    ctx->pc = 0x148ACCu;
label_148acc:
    // 0x148acc: 0xc051496  jal         func_145258
    ctx->pc = 0x148ACCu;
    SET_GPR_U32(ctx, 31, 0x148AD4u);
    ctx->pc = 0x148AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148ACCu;
            // 0x148ad0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AD4u; }
        if (ctx->pc != 0x148AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AD4u; }
        if (ctx->pc != 0x148AD4u) { return; }
    }
    ctx->pc = 0x148AD4u;
label_148ad4:
    // 0x148ad4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x148AD4u;
    {
        const bool branch_taken_0x148ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x148ad4) {
            ctx->pc = 0x148AF0u;
            goto label_148af0;
        }
    }
    ctx->pc = 0x148ADCu;
label_148adc:
    // 0x148adc: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x148adcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x148ae0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148ae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ae4: 0x24c6a7c0  addiu       $a2, $a2, -0x5840
    ctx->pc = 0x148ae4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944704));
    // 0x148ae8: 0xc0523a6  jal         func_148E98
    ctx->pc = 0x148AE8u;
    SET_GPR_U32(ctx, 31, 0x148AF0u);
    ctx->pc = 0x148AECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148AE8u;
            // 0x148aec: 0x3c055800  lui         $a1, 0x5800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22528 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148E98u;
    if (runtime->hasFunction(0x148E98u)) {
        auto targetFn = runtime->lookupFunction(0x148E98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AF0u; }
        if (ctx->pc != 0x148AF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148E98_0x148e98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AF0u; }
        if (ctx->pc != 0x148AF0u) { return; }
    }
    ctx->pc = 0x148AF0u;
label_148af0:
    // 0x148af0: 0xc05178a  jal         func_145E28
    ctx->pc = 0x148AF0u;
    SET_GPR_U32(ctx, 31, 0x148AF8u);
    ctx->pc = 0x148AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148AF0u;
            // 0x148af4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145E28u;
    if (runtime->hasFunction(0x145E28u)) {
        auto targetFn = runtime->lookupFunction(0x145E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AF8u; }
        if (ctx->pc != 0x148AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145E28_0x145e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148AF8u; }
        if (ctx->pc != 0x148AF8u) { return; }
    }
    ctx->pc = 0x148AF8u;
label_148af8:
    // 0x148af8: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x148af8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x148afc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x148afcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x148b00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x148b00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148b04: 0x80522c4  j           func_148B10
    ctx->pc = 0x148B04u;
    ctx->pc = 0x148B08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148B04u;
            // 0x148b08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148B10u;
    goto label_148b10;
    ctx->pc = 0x148B0Cu;
    // 0x148b0c: 0x0  nop
    ctx->pc = 0x148b0cu;
    // NOP
label_148b10:
    // 0x148b10: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x148b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x148b14: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x148b14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148b18: 0xffbf00e0  sd          $ra, 0xE0($sp)
    ctx->pc = 0x148b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 31));
    // 0x148b1c: 0xffb700c0  sd          $s7, 0xC0($sp)
    ctx->pc = 0x148b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 23));
    // 0x148b20: 0xffb600b0  sd          $s6, 0xB0($sp)
    ctx->pc = 0x148b20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 22));
    // 0x148b24: 0xffb500a0  sd          $s5, 0xA0($sp)
    ctx->pc = 0x148b24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 21));
    // 0x148b28: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x148b28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x148b2c: 0xffb30080  sd          $s3, 0x80($sp)
    ctx->pc = 0x148b2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 19));
    // 0x148b30: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x148b30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x148b34: 0xffb10060  sd          $s1, 0x60($sp)
    ctx->pc = 0x148b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x148b38: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x148b38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x148b3c: 0xffbe00d0  sd          $fp, 0xD0($sp)
    ctx->pc = 0x148b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 30));
    // 0x148b40: 0x8cbe0040  lw          $fp, 0x40($a1)
    ctx->pc = 0x148b40u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x148b44: 0x8fc60860  lw          $a2, 0x860($fp)
    ctx->pc = 0x148b44u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 2144)));
    // 0x148b48: 0x54c0000b  bnel        $a2, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x148B48u;
    {
        const bool branch_taken_0x148b48 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x148b48) {
            ctx->pc = 0x148B4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x148B48u;
            // 0x148b4c: 0x8fc2013c  lw          $v0, 0x13C($fp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 316)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x148B78u;
            goto label_148b78;
        }
    }
    ctx->pc = 0x148B50u;
    // 0x148b50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148b54: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x148b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x148b58: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x148b58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x148b5c: 0xafc3018c  sw          $v1, 0x18C($fp)
    ctx->pc = 0x148b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 396), GPR_U32(ctx, 3));
    // 0x148b60: 0xafc20194  sw          $v0, 0x194($fp)
    ctx->pc = 0x148b60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 404), GPR_U32(ctx, 2));
    // 0x148b64: 0xafc4015c  sw          $a0, 0x15C($fp)
    ctx->pc = 0x148b64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 348), GPR_U32(ctx, 4));
    // 0x148b68: 0xafc20154  sw          $v0, 0x154($fp)
    ctx->pc = 0x148b68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 340), GPR_U32(ctx, 2));
    // 0x148b6c: 0xafc20158  sw          $v0, 0x158($fp)
    ctx->pc = 0x148b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 344), GPR_U32(ctx, 2));
    // 0x148b70: 0xafc201a0  sw          $v0, 0x1A0($fp)
    ctx->pc = 0x148b70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 416), GPR_U32(ctx, 2));
    // 0x148b74: 0x8fc2013c  lw          $v0, 0x13C($fp)
    ctx->pc = 0x148b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 316)));
label_148b78:
    // 0x148b78: 0x2442000f  addiu       $v0, $v0, 0xF
    ctx->pc = 0x148b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x148b7c: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x148b7cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x148b80: 0x10c00008  beqz        $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x148B80u;
    {
        const bool branch_taken_0x148b80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x148B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148B80u;
            // 0x148b84: 0xafc20144  sw          $v0, 0x144($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 324), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148b80) {
            ctx->pc = 0x148BA4u;
            goto label_148ba4;
        }
    }
    ctx->pc = 0x148B88u;
    // 0x148b88: 0x8fc20154  lw          $v0, 0x154($fp)
    ctx->pc = 0x148b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 340)));
    // 0x148b8c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x148B8Cu;
    {
        const bool branch_taken_0x148b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x148B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148B8Cu;
            // 0x148b90: 0x8fc20140  lw          $v0, 0x140($fp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148b8c) {
            ctx->pc = 0x148BA8u;
            goto label_148ba8;
        }
    }
    ctx->pc = 0x148B94u;
    // 0x148b94: 0x2442001f  addiu       $v0, $v0, 0x1F
    ctx->pc = 0x148b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x148b98: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x148b98u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x148b9c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x148B9Cu;
    {
        const bool branch_taken_0x148b9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148B9Cu;
            // 0x148ba0: 0x21040  sll         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148b9c) {
            ctx->pc = 0x148BB0u;
            goto label_148bb0;
        }
    }
    ctx->pc = 0x148BA4u;
label_148ba4:
    // 0x148ba4: 0x8fc20140  lw          $v0, 0x140($fp)
    ctx->pc = 0x148ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 320)));
label_148ba8:
    // 0x148ba8: 0x2442000f  addiu       $v0, $v0, 0xF
    ctx->pc = 0x148ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x148bac: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x148bacu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
label_148bb0:
    // 0x148bb0: 0xafc20148  sw          $v0, 0x148($fp)
    ctx->pc = 0x148bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 328), GPR_U32(ctx, 2));
    // 0x148bb4: 0x2b100  sll         $s6, $v0, 4
    ctx->pc = 0x148bb4u;
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x148bb8: 0x8fc20144  lw          $v0, 0x144($fp)
    ctx->pc = 0x148bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 324)));
    // 0x148bbc: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x148bbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x148bc0: 0x2b900  sll         $s7, $v0, 4
    ctx->pc = 0x148bc0u;
    SET_GPR_S32(ctx, 23, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x148bc4: 0x16e30004  bne         $s7, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x148BC4u;
    {
        const bool branch_taken_0x148bc4 = (GPR_U64(ctx, 23) != GPR_U64(ctx, 3));
        ctx->pc = 0x148BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148BC4u;
            // 0x148bc8: 0x27c20540  addiu       $v0, $fp, 0x540 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148bc4) {
            ctx->pc = 0x148BD8u;
            goto label_148bd8;
        }
    }
    ctx->pc = 0x148BCCu;
    // 0x148bcc: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x148bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x148bd0: 0x12c2006d  beq         $s6, $v0, . + 4 + (0x6D << 2)
    ctx->pc = 0x148BD0u;
    {
        const bool branch_taken_0x148bd0 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 2));
        ctx->pc = 0x148BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148BD0u;
            // 0x148bd4: 0x27c20540  addiu       $v0, $fp, 0x540 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148bd0) {
            ctx->pc = 0x148D88u;
            goto label_148d88;
        }
    }
    ctx->pc = 0x148BD8u;
label_148bd8:
    // 0x148bd8: 0xacb60004  sw          $s6, 0x4($a1)
    ctx->pc = 0x148bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 22));
    // 0x148bdc: 0x24100180  addiu       $s0, $zero, 0x180
    ctx->pc = 0x148bdcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x148be0: 0xacb70000  sw          $s7, 0x0($a1)
    ctx->pc = 0x148be0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 23));
    // 0x148be4: 0x2d08018  mult        $s0, $s6, $s0
    ctx->pc = 0x148be4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x148be8: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x148be8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x148bec: 0x27d10120  addiu       $s1, $fp, 0x120
    ctx->pc = 0x148becu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 30), 288));
    // 0x148bf0: 0x27c20338  addiu       $v0, $fp, 0x338
    ctx->pc = 0x148bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 824));
    // 0x148bf4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148bf4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148bf8: 0xafa20030  sw          $v0, 0x30($sp)
    ctx->pc = 0x148bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0x148bfc: 0x27d30200  addiu       $s3, $fp, 0x200
    ctx->pc = 0x148bfcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 30), 512));
    // 0x148c00: 0x27c203a0  addiu       $v0, $fp, 0x3A0
    ctx->pc = 0x148c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 928));
    // 0x148c04: 0x2f08018  mult        $s0, $s7, $s0
    ctx->pc = 0x148c04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x148c08: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x148c08u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x148c0c: 0x27d40268  addiu       $s4, $fp, 0x268
    ctx->pc = 0x148c0cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 30), 616));
    // 0x148c10: 0x27c20408  addiu       $v0, $fp, 0x408
    ctx->pc = 0x148c10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1032));
    // 0x148c14: 0x27d502d0  addiu       $s5, $fp, 0x2D0
    ctx->pc = 0x148c14u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 30), 720));
    // 0x148c18: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x148c18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x148c1c: 0x169043  sra         $s2, $s6, 1
    ctx->pc = 0x148c1cu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 22), 1));
    // 0x148c20: 0x27c20470  addiu       $v0, $fp, 0x470
    ctx->pc = 0x148c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1136));
    // 0x148c24: 0x108202  srl         $s0, $s0, 8
    ctx->pc = 0x148c24u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x148c28: 0xafa2003c  sw          $v0, 0x3C($sp)
    ctx->pc = 0x148c28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
    // 0x148c2c: 0x27c204d8  addiu       $v0, $fp, 0x4D8
    ctx->pc = 0x148c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1240));
    // 0x148c30: 0xc052036  jal         func_1480D8
    ctx->pc = 0x148C30u;
    SET_GPR_U32(ctx, 31, 0x148C38u);
    ctx->pc = 0x148C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148C30u;
            // 0x148c34: 0xafa20040  sw          $v0, 0x40($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1480D8u;
    if (runtime->hasFunction(0x1480D8u)) {
        auto targetFn = runtime->lookupFunction(0x1480D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C38u; }
        if (ctx->pc != 0x148C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001480D8_0x1480d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C38u; }
        if (ctx->pc != 0x148C38u) { return; }
    }
    ctx->pc = 0x148C38u;
label_148c38:
    // 0x148c38: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x148c38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c3c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x148c3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c40: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x148c40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c44: 0xc05203a  jal         func_1480E8
    ctx->pc = 0x148C44u;
    SET_GPR_U32(ctx, 31, 0x148C4Cu);
    ctx->pc = 0x148C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148C44u;
            // 0x148c48: 0x24070040  addiu       $a3, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1480E8u;
    if (runtime->hasFunction(0x1480E8u)) {
        auto targetFn = runtime->lookupFunction(0x1480E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C4Cu; }
        if (ctx->pc != 0x148C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001480E8_0x1480e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C4Cu; }
        if (ctx->pc != 0x148C4Cu) { return; }
    }
    ctx->pc = 0x148C4Cu;
label_148c4c:
    // 0x148c4c: 0xafc20114  sw          $v0, 0x114($fp)
    ctx->pc = 0x148c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 276), GPR_U32(ctx, 2));
    // 0x148c50: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x148c50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c54: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x148c54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c58: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x148c58u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c5c: 0xc05203a  jal         func_1480E8
    ctx->pc = 0x148C5Cu;
    SET_GPR_U32(ctx, 31, 0x148C64u);
    ctx->pc = 0x148C60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148C5Cu;
            // 0x148c60: 0x24070040  addiu       $a3, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1480E8u;
    if (runtime->hasFunction(0x1480E8u)) {
        auto targetFn = runtime->lookupFunction(0x1480E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C64u; }
        if (ctx->pc != 0x148C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001480E8_0x1480e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C64u; }
        if (ctx->pc != 0x148C64u) { return; }
    }
    ctx->pc = 0x148C64u;
label_148c64:
    // 0x148c64: 0xafc20118  sw          $v0, 0x118($fp)
    ctx->pc = 0x148c64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 280), GPR_U32(ctx, 2));
    // 0x148c68: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x148c68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c6c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x148c6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c70: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x148c70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c74: 0xc05203a  jal         func_1480E8
    ctx->pc = 0x148C74u;
    SET_GPR_U32(ctx, 31, 0x148C7Cu);
    ctx->pc = 0x148C78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148C74u;
            // 0x148c78: 0x24070040  addiu       $a3, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1480E8u;
    if (runtime->hasFunction(0x1480E8u)) {
        auto targetFn = runtime->lookupFunction(0x1480E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C7Cu; }
        if (ctx->pc != 0x148C7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001480E8_0x1480e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148C7Cu; }
        if (ctx->pc != 0x148C7Cu) { return; }
    }
    ctx->pc = 0x148C7Cu;
label_148c7c:
    // 0x148c7c: 0x8fa80034  lw          $t0, 0x34($sp)
    ctx->pc = 0x148c7cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x148c80: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x148c80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c84: 0x8fa90038  lw          $t1, 0x38($sp)
    ctx->pc = 0x148c84u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x148c88: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x148c88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c8c: 0x8faa003c  lw          $t2, 0x3C($sp)
    ctx->pc = 0x148c8cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x148c90: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x148c90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148c94: 0x8fab0040  lw          $t3, 0x40($sp)
    ctx->pc = 0x148c94u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148c98: 0xafc2011c  sw          $v0, 0x11C($fp)
    ctx->pc = 0x148c98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 284), GPR_U32(ctx, 2));
    // 0x148c9c: 0x8fa20044  lw          $v0, 0x44($sp)
    ctx->pc = 0x148c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x148ca0: 0x8fa70030  lw          $a3, 0x30($sp)
    ctx->pc = 0x148ca0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148ca4: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x148ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x148ca8: 0x8fc20114  lw          $v0, 0x114($fp)
    ctx->pc = 0x148ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 276)));
    // 0x148cac: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x148cacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x148cb0: 0x8fc30118  lw          $v1, 0x118($fp)
    ctx->pc = 0x148cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x148cb4: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x148cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x148cb8: 0x8fc2011c  lw          $v0, 0x11C($fp)
    ctx->pc = 0x148cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 284)));
    // 0x148cbc: 0xafb70020  sw          $s7, 0x20($sp)
    ctx->pc = 0x148cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 23));
    // 0x148cc0: 0xafb60028  sw          $s6, 0x28($sp)
    ctx->pc = 0x148cc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
    // 0x148cc4: 0xc05236e  jal         func_148DB8
    ctx->pc = 0x148CC4u;
    SET_GPR_U32(ctx, 31, 0x148CCCu);
    ctx->pc = 0x148CC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148CC4u;
            // 0x148cc8: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148DB8u;
    if (runtime->hasFunction(0x148DB8u)) {
        auto targetFn = runtime->lookupFunction(0x148DB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CCCu; }
        if (ctx->pc != 0x148CCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148DB8_0x148db8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CCCu; }
        if (ctx->pc != 0x148CCCu) { return; }
    }
    ctx->pc = 0x148CCCu;
label_148ccc:
    // 0x148ccc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x148cccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148cd0: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148cd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148cd4: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148CD4u;
    SET_GPR_U32(ctx, 31, 0x148CDCu);
    ctx->pc = 0x148CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148CD4u;
            // 0x148cd8: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CDCu; }
        if (ctx->pc != 0x148CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CDCu; }
        if (ctx->pc != 0x148CDCu) { return; }
    }
    ctx->pc = 0x148CDCu;
label_148cdc:
    // 0x148cdc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x148cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ce0: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ce4: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148CE4u;
    SET_GPR_U32(ctx, 31, 0x148CECu);
    ctx->pc = 0x148CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148CE4u;
            // 0x148ce8: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CECu; }
        if (ctx->pc != 0x148CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CECu; }
        if (ctx->pc != 0x148CECu) { return; }
    }
    ctx->pc = 0x148CECu;
label_148cec:
    // 0x148cec: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x148cecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148cf0: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148cf0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148cf4: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148CF4u;
    SET_GPR_U32(ctx, 31, 0x148CFCu);
    ctx->pc = 0x148CF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148CF4u;
            // 0x148cf8: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CFCu; }
        if (ctx->pc != 0x148CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148CFCu; }
        if (ctx->pc != 0x148CFCu) { return; }
    }
    ctx->pc = 0x148CFCu;
label_148cfc:
    // 0x148cfc: 0x8fa40030  lw          $a0, 0x30($sp)
    ctx->pc = 0x148cfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148d00: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d04: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148D04u;
    SET_GPR_U32(ctx, 31, 0x148D0Cu);
    ctx->pc = 0x148D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D04u;
            // 0x148d08: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D0Cu; }
        if (ctx->pc != 0x148D0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D0Cu; }
        if (ctx->pc != 0x148D0Cu) { return; }
    }
    ctx->pc = 0x148D0Cu;
label_148d0c:
    // 0x148d0c: 0x8fa40034  lw          $a0, 0x34($sp)
    ctx->pc = 0x148d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x148d10: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d14: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148D14u;
    SET_GPR_U32(ctx, 31, 0x148D1Cu);
    ctx->pc = 0x148D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D14u;
            // 0x148d18: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D1Cu; }
        if (ctx->pc != 0x148D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D1Cu; }
        if (ctx->pc != 0x148D1Cu) { return; }
    }
    ctx->pc = 0x148D1Cu;
label_148d1c:
    // 0x148d1c: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x148d1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x148d20: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d24: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148D24u;
    SET_GPR_U32(ctx, 31, 0x148D2Cu);
    ctx->pc = 0x148D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D24u;
            // 0x148d28: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D2Cu; }
        if (ctx->pc != 0x148D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D2Cu; }
        if (ctx->pc != 0x148D2Cu) { return; }
    }
    ctx->pc = 0x148D2Cu;
label_148d2c:
    // 0x148d2c: 0x8fa4003c  lw          $a0, 0x3C($sp)
    ctx->pc = 0x148d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x148d30: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d34: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148D34u;
    SET_GPR_U32(ctx, 31, 0x148D3Cu);
    ctx->pc = 0x148D38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D34u;
            // 0x148d38: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D3Cu; }
        if (ctx->pc != 0x148D3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D3Cu; }
        if (ctx->pc != 0x148D3Cu) { return; }
    }
    ctx->pc = 0x148D3Cu;
label_148d3c:
    // 0x148d3c: 0x8fa40040  lw          $a0, 0x40($sp)
    ctx->pc = 0x148d3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148d40: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d44: 0xc052272  jal         func_1489C8
    ctx->pc = 0x148D44u;
    SET_GPR_U32(ctx, 31, 0x148D4Cu);
    ctx->pc = 0x148D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D44u;
            // 0x148d48: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D4Cu; }
        if (ctx->pc != 0x148D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489C8_0x1489c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148D4Cu; }
        if (ctx->pc != 0x148D4Cu) { return; }
    }
    ctx->pc = 0x148D4Cu;
label_148d4c:
    // 0x148d4c: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x148d4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d50: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x148d50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148d54: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x148d54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x148d58: 0xdfbf00e0  ld          $ra, 0xE0($sp)
    ctx->pc = 0x148d58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x148d5c: 0xdfbe00d0  ld          $fp, 0xD0($sp)
    ctx->pc = 0x148d5cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x148d60: 0xdfb700c0  ld          $s7, 0xC0($sp)
    ctx->pc = 0x148d60u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x148d64: 0xdfb600b0  ld          $s6, 0xB0($sp)
    ctx->pc = 0x148d64u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x148d68: 0xdfb500a0  ld          $s5, 0xA0($sp)
    ctx->pc = 0x148d68u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x148d6c: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x148d6cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x148d70: 0xdfb30080  ld          $s3, 0x80($sp)
    ctx->pc = 0x148d70u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x148d74: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x148d74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x148d78: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x148d78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x148d7c: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x148d7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x148d80: 0x8052272  j           func_1489C8
    ctx->pc = 0x148D80u;
    ctx->pc = 0x148D84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148D80u;
            // 0x148d84: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489C8u;
    if (runtime->hasFunction(0x1489C8u)) {
        auto targetFn = runtime->lookupFunction(0x1489C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001489C8_0x1489c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x148D88u;
label_148d88:
    // 0x148d88: 0xdfbf00e0  ld          $ra, 0xE0($sp)
    ctx->pc = 0x148d88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x148d8c: 0xdfbe00d0  ld          $fp, 0xD0($sp)
    ctx->pc = 0x148d8cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x148d90: 0xdfb700c0  ld          $s7, 0xC0($sp)
    ctx->pc = 0x148d90u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x148d94: 0xdfb600b0  ld          $s6, 0xB0($sp)
    ctx->pc = 0x148d94u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x148d98: 0xdfb500a0  ld          $s5, 0xA0($sp)
    ctx->pc = 0x148d98u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x148d9c: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x148d9cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x148da0: 0xdfb30080  ld          $s3, 0x80($sp)
    ctx->pc = 0x148da0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x148da4: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x148da4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x148da8: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x148da8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x148dac: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x148dacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x148db0: 0x3e00008  jr          $ra
    ctx->pc = 0x148DB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148DB0u;
            // 0x148db4: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148A04u: goto label_148a04;
            case 0x148A34u: goto label_148a34;
            case 0x148A40u: goto label_148a40;
            case 0x148A64u: goto label_148a64;
            case 0x148A74u: goto label_148a74;
            case 0x148A80u: goto label_148a80;
            case 0x148A88u: goto label_148a88;
            case 0x148A90u: goto label_148a90;
            case 0x148AA4u: goto label_148aa4;
            case 0x148AA8u: goto label_148aa8;
            case 0x148AB0u: goto label_148ab0;
            case 0x148AC0u: goto label_148ac0;
            case 0x148ACCu: goto label_148acc;
            case 0x148AD4u: goto label_148ad4;
            case 0x148ADCu: goto label_148adc;
            case 0x148AF0u: goto label_148af0;
            case 0x148AF8u: goto label_148af8;
            case 0x148B10u: goto label_148b10;
            case 0x148B78u: goto label_148b78;
            case 0x148BA4u: goto label_148ba4;
            case 0x148BA8u: goto label_148ba8;
            case 0x148BB0u: goto label_148bb0;
            case 0x148BD8u: goto label_148bd8;
            case 0x148C38u: goto label_148c38;
            case 0x148C4Cu: goto label_148c4c;
            case 0x148C64u: goto label_148c64;
            case 0x148C7Cu: goto label_148c7c;
            case 0x148CCCu: goto label_148ccc;
            case 0x148CDCu: goto label_148cdc;
            case 0x148CECu: goto label_148cec;
            case 0x148CFCu: goto label_148cfc;
            case 0x148D0Cu: goto label_148d0c;
            case 0x148D1Cu: goto label_148d1c;
            case 0x148D2Cu: goto label_148d2c;
            case 0x148D3Cu: goto label_148d3c;
            case 0x148D4Cu: goto label_148d4c;
            case 0x148D88u: goto label_148d88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148DB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
