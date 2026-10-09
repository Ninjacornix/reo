#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9C80
// Address: 0x1a9c80 - 0x1a9d60
void sub_001A9C80_0x1a9c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9C80_0x1a9c80");
#endif

    switch (ctx->pc) {
        case 0x1a9c98u: goto label_1a9c98;
        case 0x1a9ca8u: goto label_1a9ca8;
        case 0x1a9cc8u: goto label_1a9cc8;
        case 0x1a9cd0u: goto label_1a9cd0;
        case 0x1a9ce8u: goto label_1a9ce8;
        case 0x1a9cf4u: goto label_1a9cf4;
        case 0x1a9d0cu: goto label_1a9d0c;
        case 0x1a9d14u: goto label_1a9d14;
        default: break;
    }

    ctx->pc = 0x1a9c80u;

    // 0x1a9c80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a9c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a9c84: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1a9c84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1a9c88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a9c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a9c8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a9c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a9c90: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9C90u;
    SET_GPR_U32(ctx, 31, 0x1A9C98u);
    ctx->pc = 0x1A9C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9C90u;
            // 0x1a9c94: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9C98u; }
        if (ctx->pc != 0x1A9C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9C98u; }
        if (ctx->pc != 0x1A9C98u) { return; }
    }
    ctx->pc = 0x1A9C98u;
label_1a9c98:
    // 0x1a9c98: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9C98u;
    {
        const bool branch_taken_0x1a9c98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9C98u;
            // 0x1a9c9c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9c98) {
            ctx->pc = 0x1A9CA8u;
            goto label_1a9ca8;
        }
    }
    ctx->pc = 0x1A9CA0u;
    // 0x1a9ca0: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9CA0u;
    SET_GPR_U32(ctx, 31, 0x1A9CA8u);
    ctx->pc = 0x1A9CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CA0u;
            // 0x1a9ca4: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CA8u; }
        if (ctx->pc != 0x1A9CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CA8u; }
        if (ctx->pc != 0x1A9CA8u) { return; }
    }
    ctx->pc = 0x1A9CA8u;
label_1a9ca8:
    // 0x1a9ca8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9CA8u;
    {
        const bool branch_taken_0x1a9ca8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9ca8) {
            ctx->pc = 0x1A9CB8u;
            goto label_1a9cb8;
        }
    }
    ctx->pc = 0x1A9CB0u;
    // 0x1a9cb0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A9CB0u;
    {
        const bool branch_taken_0x1a9cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CB0u;
            // 0x1a9cb4: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9cb0) {
            ctx->pc = 0x1A9CBCu;
            goto label_1a9cbc;
        }
    }
    ctx->pc = 0x1A9CB8u;
label_1a9cb8:
    // 0x1a9cb8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1a9cb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1a9cbc:
    // 0x1a9cbc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1a9cbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9cc0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9CC0u;
    SET_GPR_U32(ctx, 31, 0x1A9CC8u);
    ctx->pc = 0x1A9CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CC0u;
            // 0x1a9cc4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CC8u; }
        if (ctx->pc != 0x1A9CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CC8u; }
        if (ctx->pc != 0x1A9CC8u) { return; }
    }
    ctx->pc = 0x1A9CC8u;
label_1a9cc8:
    // 0x1a9cc8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1A9CC8u;
    SET_GPR_U32(ctx, 31, 0x1A9CD0u);
    ctx->pc = 0x1A9CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CC8u;
            // 0x1a9ccc: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CD0u; }
        if (ctx->pc != 0x1A9CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CD0u; }
        if (ctx->pc != 0x1A9CD0u) { return; }
    }
    ctx->pc = 0x1A9CD0u;
label_1a9cd0:
    // 0x1a9cd0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9CD0u;
    {
        const bool branch_taken_0x1a9cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CD0u;
            // 0x1a9cd4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9cd0) {
            ctx->pc = 0x1A9CE0u;
            goto label_1a9ce0;
        }
    }
    ctx->pc = 0x1A9CD8u;
    // 0x1a9cd8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1A9CD8u;
    {
        const bool branch_taken_0x1a9cd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CD8u;
            // 0x1a9cdc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9cd8) {
            ctx->pc = 0x1A9D44u;
            goto label_1a9d44;
        }
    }
    ctx->pc = 0x1A9CE0u;
label_1a9ce0:
    // 0x1a9ce0: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1A9CE0u;
    SET_GPR_U32(ctx, 31, 0x1A9CE8u);
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CE8u; }
        if (ctx->pc != 0x1A9CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CE8u; }
        if (ctx->pc != 0x1A9CE8u) { return; }
    }
    ctx->pc = 0x1A9CE8u;
label_1a9ce8:
    // 0x1a9ce8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a9ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9cec: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1A9CECu;
    SET_GPR_U32(ctx, 31, 0x1A9CF4u);
    ctx->pc = 0x1A9CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CECu;
            // 0x1a9cf0: 0x2405002e  addiu       $a1, $zero, 0x2E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CF4u; }
        if (ctx->pc != 0x1A9CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9CF4u; }
        if (ctx->pc != 0x1A9CF4u) { return; }
    }
    ctx->pc = 0x1A9CF4u;
label_1a9cf4:
    // 0x1a9cf4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9CF4u;
    {
        const bool branch_taken_0x1a9cf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9CF4u;
            // 0x1a9cf8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9cf4) {
            ctx->pc = 0x1A9D04u;
            goto label_1a9d04;
        }
    }
    ctx->pc = 0x1A9CFCu;
    // 0x1a9cfc: 0x2403005f  addiu       $v1, $zero, 0x5F
    ctx->pc = 0x1a9cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1a9d00: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1a9d00u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
label_1a9d04:
    // 0x1a9d04: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A9D04u;
    {
        const bool branch_taken_0x1a9d04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9d04) {
            ctx->pc = 0x1A9D28u;
            goto label_1a9d28;
        }
    }
    ctx->pc = 0x1A9D0Cu;
label_1a9d0c:
    // 0x1a9d0c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1A9D0Cu;
    SET_GPR_U32(ctx, 31, 0x1A9D14u);
    ctx->pc = 0x1A9D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D0Cu;
            // 0x1a9d10: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9D14u; }
        if (ctx->pc != 0x1A9D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9D14u; }
        if (ctx->pc != 0x1A9D14u) { return; }
    }
    ctx->pc = 0x1A9D14u;
label_1a9d14:
    // 0x1a9d14: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9D14u;
    {
        const bool branch_taken_0x1a9d14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a9d14) {
            ctx->pc = 0x1A9D24u;
            goto label_1a9d24;
        }
    }
    ctx->pc = 0x1A9D1Cu;
    // 0x1a9d1c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A9D1Cu;
    {
        const bool branch_taken_0x1a9d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D1Cu;
            // 0x1a9d20: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9d1c) {
            ctx->pc = 0x1A9D44u;
            goto label_1a9d44;
        }
    }
    ctx->pc = 0x1A9D24u;
label_1a9d24:
    // 0x1a9d24: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a9d24u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a9d28:
    // 0x1a9d28: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1a9d28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1a9d2c: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1a9d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1a9d30: 0x244222a0  addiu       $v0, $v0, 0x22A0
    ctx->pc = 0x1a9d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8864));
    // 0x1a9d34: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a9d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a9d38: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1a9d38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a9d3c: 0x14a0fff3  bnez        $a1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A9D3Cu;
    {
        const bool branch_taken_0x1a9d3c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D3Cu;
            // 0x1a9d40: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9d3c) {
            ctx->pc = 0x1A9D0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9d0c;
        }
    }
    ctx->pc = 0x1A9D44u;
label_1a9d44:
    // 0x1a9d44: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a9d44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a9d48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a9d48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9d4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9D4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D4Cu;
            // 0x1a9d50: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9C98u: goto label_1a9c98;
            case 0x1A9CA8u: goto label_1a9ca8;
            case 0x1A9CB8u: goto label_1a9cb8;
            case 0x1A9CBCu: goto label_1a9cbc;
            case 0x1A9CC8u: goto label_1a9cc8;
            case 0x1A9CD0u: goto label_1a9cd0;
            case 0x1A9CE0u: goto label_1a9ce0;
            case 0x1A9CE8u: goto label_1a9ce8;
            case 0x1A9CF4u: goto label_1a9cf4;
            case 0x1A9D04u: goto label_1a9d04;
            case 0x1A9D0Cu: goto label_1a9d0c;
            case 0x1A9D14u: goto label_1a9d14;
            case 0x1A9D24u: goto label_1a9d24;
            case 0x1A9D28u: goto label_1a9d28;
            case 0x1A9D44u: goto label_1a9d44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9D54u;
    // 0x1a9d54: 0x0  nop
    ctx->pc = 0x1a9d54u;
    // NOP
    // 0x1a9d58: 0x0  nop
    ctx->pc = 0x1a9d58u;
    // NOP
    // 0x1a9d5c: 0x0  nop
    ctx->pc = 0x1a9d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
