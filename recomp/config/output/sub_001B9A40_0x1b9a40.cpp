#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9A40
// Address: 0x1b9a40 - 0x1b9ba0
void sub_001B9A40_0x1b9a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9A40_0x1b9a40");
#endif

    switch (ctx->pc) {
        case 0x1b9a58u: goto label_1b9a58;
        case 0x1b9ac0u: goto label_1b9ac0;
        case 0x1b9aecu: goto label_1b9aec;
        case 0x1b9b10u: goto label_1b9b10;
        case 0x1b9b3cu: goto label_1b9b3c;
        case 0x1b9b68u: goto label_1b9b68;
        case 0x1b9b8cu: goto label_1b9b8c;
        default: break;
    }

    ctx->pc = 0x1b9a40u;

    // 0x1b9a40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9a44: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b9a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b9a48: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9a48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9a4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9a4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9a50: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b9a50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9a54: 0x111900  sll         $v1, $s1, 4
    ctx->pc = 0x1b9a54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_1b9a58:
    // 0x1b9a58: 0x3c02003c  lui         $v0, 0x3C
    ctx->pc = 0x1b9a58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)60 << 16));
    // 0x1b9a5c: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1b9a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b9a60: 0x24422750  addiu       $v0, $v0, 0x2750
    ctx->pc = 0x1b9a60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10064));
    // 0x1b9a64: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b9a64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9a68: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b9a68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9a6c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1b9a6cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b9a70: 0x1040003d  beqz        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1B9A70u;
    {
        const bool branch_taken_0x1b9a70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a70) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9A78u;
    // 0x1b9a78: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1b9a78u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1b9a7c: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x1B9A7Cu;
    {
        const bool branch_taken_0x1b9a7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a7c) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9A84u;
    // 0x1b9a84: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1b9a84u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b9a88: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B9A88u;
    {
        const bool branch_taken_0x1b9a88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9A88u;
            // 0x1b9a8c: 0x21e3c  dsll32      $v1, $v0, 24 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9a88) {
            ctx->pc = 0x1B9AF4u;
            goto label_1b9af4;
        }
    }
    ctx->pc = 0x1B9A90u;
    // 0x1b9a90: 0x8e030024  lw          $v1, 0x24($s0)
    ctx->pc = 0x1b9a90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1b9a94: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1B9A94u;
    {
        const bool branch_taken_0x1b9a94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a94) {
            ctx->pc = 0x1B9AC8u;
            goto label_1b9ac8;
        }
    }
    ctx->pc = 0x1B9A9Cu;
    // 0x1b9a9c: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9a9cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9aa0: 0x24670008  addiu       $a3, $v1, 0x8
    ctx->pc = 0x1b9aa0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1b9aa4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9aa8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9aa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9aac: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9aacu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9ab0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9ab0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ab4: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9ab4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ab8: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9AB8u;
    SET_GPR_U32(ctx, 31, 0x1B9AC0u);
    ctx->pc = 0x1B9ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AB8u;
            // 0x1b9abc: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AC0u; }
        if (ctx->pc != 0x1B9AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AC0u; }
        if (ctx->pc != 0x1B9AC0u) { return; }
    }
    ctx->pc = 0x1B9AC0u;
label_1b9ac0:
    // 0x1b9ac0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1B9AC0u;
    {
        const bool branch_taken_0x1b9ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AC0u;
            // 0x1b9ac4: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9ac0) {
            ctx->pc = 0x1B9B6Cu;
            goto label_1b9b6c;
        }
    }
    ctx->pc = 0x1B9AC8u;
label_1b9ac8:
    // 0x1b9ac8: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9ac8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9acc: 0x2607002c  addiu       $a3, $s0, 0x2C
    ctx->pc = 0x1b9accu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x1b9ad0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9ad4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9ad4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ad8: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9ad8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9adc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9adcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ae0: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9ae0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ae4: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9AE4u;
    SET_GPR_U32(ctx, 31, 0x1B9AECu);
    ctx->pc = 0x1B9AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AE4u;
            // 0x1b9ae8: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AECu; }
        if (ctx->pc != 0x1B9AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AECu; }
        if (ctx->pc != 0x1B9AECu) { return; }
    }
    ctx->pc = 0x1B9AECu;
label_1b9aec:
    // 0x1b9aec: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1B9AECu;
    {
        const bool branch_taken_0x1b9aec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9aec) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9AF4u;
label_1b9af4:
    // 0x1b9af4: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1b9af4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1b9af8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b9af8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9afc: 0x1462001a  bne         $v1, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B9AFCu;
    {
        const bool branch_taken_0x1b9afc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b9afc) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9B04u;
    // 0x1b9b04: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x1b9b04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1b9b08: 0xc06e65c  jal         func_1B9970
    ctx->pc = 0x1B9B08u;
    SET_GPR_U32(ctx, 31, 0x1B9B10u);
    ctx->pc = 0x1B9B0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B08u;
            // 0x1b9b0c: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B9970u;
    if (runtime->hasFunction(0x1B9970u)) {
        auto targetFn = runtime->lookupFunction(0x1B9970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B10u; }
        if (ctx->pc != 0x1B9B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B9970_0x1b9970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B10u; }
        if (ctx->pc != 0x1B9B10u) { return; }
    }
    ctx->pc = 0x1B9B10u;
label_1b9b10:
    // 0x1b9b10: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B9B10u;
    {
        const bool branch_taken_0x1b9b10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9b10) {
            ctx->pc = 0x1B9B44u;
            goto label_1b9b44;
        }
    }
    ctx->pc = 0x1B9B18u;
    // 0x1b9b18: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9b18u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9b1c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9b1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9b20: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9b20u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b24: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x1b9b24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1b9b28: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9b28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9b2c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9b2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b30: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9b30u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b34: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9B34u;
    SET_GPR_U32(ctx, 31, 0x1B9B3Cu);
    ctx->pc = 0x1B9B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B34u;
            // 0x1b9b38: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B3Cu; }
        if (ctx->pc != 0x1B9B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B3Cu; }
        if (ctx->pc != 0x1B9B3Cu) { return; }
    }
    ctx->pc = 0x1B9B3Cu;
label_1b9b3c:
    // 0x1b9b3c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B9B3Cu;
    {
        const bool branch_taken_0x1b9b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9b3c) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9B44u;
label_1b9b44:
    // 0x1b9b44: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9b44u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9b48: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9b48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9b4c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9b4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b50: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b9b50u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b54: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9b54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9b58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9b58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b5c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9b5cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b60: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9B60u;
    SET_GPR_U32(ctx, 31, 0x1B9B68u);
    ctx->pc = 0x1B9B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B60u;
            // 0x1b9b64: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B68u; }
        if (ctx->pc != 0x1B9B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B68u; }
        if (ctx->pc != 0x1B9B68u) { return; }
    }
    ctx->pc = 0x1B9B68u;
label_1b9b68:
    // 0x1b9b68: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b9b68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b9b6c:
    // 0x1b9b6c: 0x2a220004  slti        $v0, $s1, 0x4
    ctx->pc = 0x1b9b6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b9b70: 0x1440ffb9  bnez        $v0, . + 4 + (-0x47 << 2)
    ctx->pc = 0x1B9B70u;
    {
        const bool branch_taken_0x1b9b70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B70u;
            // 0x1b9b74: 0x111900  sll         $v1, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9b70) {
            ctx->pc = 0x1B9A58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b9a58;
        }
    }
    ctx->pc = 0x1B9B78u;
    // 0x1b9b78: 0x3c04003c  lui         $a0, 0x3C
    ctx->pc = 0x1b9b78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)60 << 16));
    // 0x1b9b7c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b9b7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b80: 0x24842750  addiu       $a0, $a0, 0x2750
    ctx->pc = 0x1b9b80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10064));
    // 0x1b9b84: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B9B84u;
    SET_GPR_U32(ctx, 31, 0x1B9B8Cu);
    ctx->pc = 0x1B9B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B84u;
            // 0x1b9b88: 0x240600f0  addiu       $a2, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B8Cu; }
        if (ctx->pc != 0x1B9B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B8Cu; }
        if (ctx->pc != 0x1B9B8Cu) { return; }
    }
    ctx->pc = 0x1B9B8Cu;
label_1b9b8c:
    // 0x1b9b8c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b9b8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9b90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9b90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9b94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9b94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9b98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B98u;
            // 0x1b9b9c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9BA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
