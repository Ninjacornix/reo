#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A99E0
// Address: 0x1a99e0 - 0x1a9ac0
void sub_001A99E0_0x1a99e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A99E0_0x1a99e0");
#endif

    switch (ctx->pc) {
        case 0x1a99f8u: goto label_1a99f8;
        case 0x1a9a08u: goto label_1a9a08;
        case 0x1a9a28u: goto label_1a9a28;
        case 0x1a9a30u: goto label_1a9a30;
        case 0x1a9a48u: goto label_1a9a48;
        case 0x1a9a54u: goto label_1a9a54;
        case 0x1a9a6cu: goto label_1a9a6c;
        case 0x1a9a74u: goto label_1a9a74;
        default: break;
    }

    ctx->pc = 0x1a99e0u;

    // 0x1a99e0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a99e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a99e4: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1a99e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1a99e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a99e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a99ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a99ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a99f0: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A99F0u;
    SET_GPR_U32(ctx, 31, 0x1A99F8u);
    ctx->pc = 0x1A99F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A99F0u;
            // 0x1a99f4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A99F8u; }
        if (ctx->pc != 0x1A99F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A99F8u; }
        if (ctx->pc != 0x1A99F8u) { return; }
    }
    ctx->pc = 0x1A99F8u;
label_1a99f8:
    // 0x1a99f8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A99F8u;
    {
        const bool branch_taken_0x1a99f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A99FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A99F8u;
            // 0x1a99fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a99f8) {
            ctx->pc = 0x1A9A08u;
            goto label_1a9a08;
        }
    }
    ctx->pc = 0x1A9A00u;
    // 0x1a9a00: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9A00u;
    SET_GPR_U32(ctx, 31, 0x1A9A08u);
    ctx->pc = 0x1A9A04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A00u;
            // 0x1a9a04: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A08u; }
        if (ctx->pc != 0x1A9A08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A08u; }
        if (ctx->pc != 0x1A9A08u) { return; }
    }
    ctx->pc = 0x1A9A08u;
label_1a9a08:
    // 0x1a9a08: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9A08u;
    {
        const bool branch_taken_0x1a9a08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9a08) {
            ctx->pc = 0x1A9A18u;
            goto label_1a9a18;
        }
    }
    ctx->pc = 0x1A9A10u;
    // 0x1a9a10: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9A10u;
    {
        const bool branch_taken_0x1a9a10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A10u;
            // 0x1a9a14: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a10) {
            ctx->pc = 0x1A9A1Cu;
            goto label_1a9a1c;
        }
    }
    ctx->pc = 0x1A9A18u;
label_1a9a18:
    // 0x1a9a18: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1a9a18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1a9a1c:
    // 0x1a9a1c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1a9a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9a20: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9A20u;
    SET_GPR_U32(ctx, 31, 0x1A9A28u);
    ctx->pc = 0x1A9A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A20u;
            // 0x1a9a24: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A28u; }
        if (ctx->pc != 0x1A9A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A28u; }
        if (ctx->pc != 0x1A9A28u) { return; }
    }
    ctx->pc = 0x1A9A28u;
label_1a9a28:
    // 0x1a9a28: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1A9A28u;
    SET_GPR_U32(ctx, 31, 0x1A9A30u);
    ctx->pc = 0x1A9A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A28u;
            // 0x1a9a2c: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A30u; }
        if (ctx->pc != 0x1A9A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A30u; }
        if (ctx->pc != 0x1A9A30u) { return; }
    }
    ctx->pc = 0x1A9A30u;
label_1a9a30:
    // 0x1a9a30: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9A30u;
    {
        const bool branch_taken_0x1a9a30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A30u;
            // 0x1a9a34: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a30) {
            ctx->pc = 0x1A9A40u;
            goto label_1a9a40;
        }
    }
    ctx->pc = 0x1A9A38u;
    // 0x1a9a38: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1A9A38u;
    {
        const bool branch_taken_0x1a9a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A38u;
            // 0x1a9a3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a38) {
            ctx->pc = 0x1A9AA4u;
            goto label_1a9aa4;
        }
    }
    ctx->pc = 0x1A9A40u;
label_1a9a40:
    // 0x1a9a40: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1A9A40u;
    SET_GPR_U32(ctx, 31, 0x1A9A48u);
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A48u; }
        if (ctx->pc != 0x1A9A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A48u; }
        if (ctx->pc != 0x1A9A48u) { return; }
    }
    ctx->pc = 0x1A9A48u;
label_1a9a48:
    // 0x1a9a48: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a9a48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9a4c: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9A4Cu;
    SET_GPR_U32(ctx, 31, 0x1A9A54u);
    ctx->pc = 0x1A9A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A4Cu;
            // 0x1a9a50: 0x2405002e  addiu       $a1, $zero, 0x2E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A54u; }
        if (ctx->pc != 0x1A9A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A54u; }
        if (ctx->pc != 0x1A9A54u) { return; }
    }
    ctx->pc = 0x1A9A54u;
label_1a9a54:
    // 0x1a9a54: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9A54u;
    {
        const bool branch_taken_0x1a9a54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A54u;
            // 0x1a9a58: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a54) {
            ctx->pc = 0x1A9A64u;
            goto label_1a9a64;
        }
    }
    ctx->pc = 0x1A9A5Cu;
    // 0x1a9a5c: 0x2403005f  addiu       $v1, $zero, 0x5F
    ctx->pc = 0x1a9a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1a9a60: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1a9a60u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
label_1a9a64:
    // 0x1a9a64: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A9A64u;
    {
        const bool branch_taken_0x1a9a64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9a64) {
            ctx->pc = 0x1A9A88u;
            goto label_1a9a88;
        }
    }
    ctx->pc = 0x1A9A6Cu;
label_1a9a6c:
    // 0x1a9a6c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1A9A6Cu;
    SET_GPR_U32(ctx, 31, 0x1A9A74u);
    ctx->pc = 0x1A9A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A6Cu;
            // 0x1a9a70: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A74u; }
        if (ctx->pc != 0x1A9A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9A74u; }
        if (ctx->pc != 0x1A9A74u) { return; }
    }
    ctx->pc = 0x1A9A74u;
label_1a9a74:
    // 0x1a9a74: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9A74u;
    {
        const bool branch_taken_0x1a9a74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a9a74) {
            ctx->pc = 0x1A9A84u;
            goto label_1a9a84;
        }
    }
    ctx->pc = 0x1A9A7Cu;
    // 0x1a9a7c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A9A7Cu;
    {
        const bool branch_taken_0x1a9a7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A7Cu;
            // 0x1a9a80: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a7c) {
            ctx->pc = 0x1A9AA4u;
            goto label_1a9aa4;
        }
    }
    ctx->pc = 0x1A9A84u;
label_1a9a84:
    // 0x1a9a84: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a9a84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a9a88:
    // 0x1a9a88: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1a9a88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1a9a8c: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1a9a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1a9a90: 0x24422230  addiu       $v0, $v0, 0x2230
    ctx->pc = 0x1a9a90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8752));
    // 0x1a9a94: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a9a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a9a98: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1a9a98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a9a9c: 0x14a0fff3  bnez        $a1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A9A9Cu;
    {
        const bool branch_taken_0x1a9a9c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9A9Cu;
            // 0x1a9aa0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9a9c) {
            ctx->pc = 0x1A9A6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9a6c;
        }
    }
    ctx->pc = 0x1A9AA4u;
label_1a9aa4:
    // 0x1a9aa4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a9aa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a9aa8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a9aa8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9aac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9AACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9AACu;
            // 0x1a9ab0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A99F8u: goto label_1a99f8;
            case 0x1A9A08u: goto label_1a9a08;
            case 0x1A9A18u: goto label_1a9a18;
            case 0x1A9A1Cu: goto label_1a9a1c;
            case 0x1A9A28u: goto label_1a9a28;
            case 0x1A9A30u: goto label_1a9a30;
            case 0x1A9A40u: goto label_1a9a40;
            case 0x1A9A48u: goto label_1a9a48;
            case 0x1A9A54u: goto label_1a9a54;
            case 0x1A9A64u: goto label_1a9a64;
            case 0x1A9A6Cu: goto label_1a9a6c;
            case 0x1A9A74u: goto label_1a9a74;
            case 0x1A9A84u: goto label_1a9a84;
            case 0x1A9A88u: goto label_1a9a88;
            case 0x1A9AA4u: goto label_1a9aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9AB4u;
    // 0x1a9ab4: 0x0  nop
    ctx->pc = 0x1a9ab4u;
    // NOP
    // 0x1a9ab8: 0x0  nop
    ctx->pc = 0x1a9ab8u;
    // NOP
    // 0x1a9abc: 0x0  nop
    ctx->pc = 0x1a9abcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
