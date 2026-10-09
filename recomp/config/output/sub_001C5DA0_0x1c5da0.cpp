#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5DA0
// Address: 0x1c5da0 - 0x1c5ec0
void sub_001C5DA0_0x1c5da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5DA0_0x1c5da0");
#endif

    switch (ctx->pc) {
        case 0x1c5dfcu: goto label_1c5dfc;
        case 0x1c5e00u: goto label_1c5e00;
        case 0x1c5e24u: goto label_1c5e24;
        case 0x1c5e54u: goto label_1c5e54;
        case 0x1c5e78u: goto label_1c5e78;
        case 0x1c5e90u: goto label_1c5e90;
        default: break;
    }

    ctx->pc = 0x1c5da0u;

label_1c5da0:
    // 0x1c5da0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1c5da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1c5da4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1c5da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1c5da8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c5da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c5dac: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c5dacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c5db0: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1c5db0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5db4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c5db4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c5db8: 0xa62021  addu        $a0, $a1, $a2
    ctx->pc = 0x1c5db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1c5dbc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5dbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c5dc0: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1c5dc0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5dc4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c5dc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5dc8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1c5dc8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5dcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5dccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5dd0: 0x280902d  daddu       $s2, $s4, $zero
    ctx->pc = 0x1c5dd0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5dd4: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x1c5dd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5dd8: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5DD8u;
    {
        const bool branch_taken_0x1c5dd8 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1C5DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5DD8u;
            // 0x1c5ddc: 0x41843  sra         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5dd8) {
            ctx->pc = 0x1C5DE8u;
            goto label_1c5de8;
        }
    }
    ctx->pc = 0x1C5DE0u;
    // 0x1c5de0: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x1c5de0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1c5de4: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x1c5de4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
label_1c5de8:
    // 0x1c5de8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c5de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c5dec: 0x2a31821  addu        $v1, $s5, $v1
    ctx->pc = 0x1c5decu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x1c5df0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1c5df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c5df4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5DF4u;
    {
        const bool branch_taken_0x1c5df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5DF4u;
            // 0x1c5df8: 0x8c700008  lw          $s0, 0x8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5df4) {
            ctx->pc = 0x1C5E00u;
            goto label_1c5e00;
        }
    }
    ctx->pc = 0x1C5DFCu;
label_1c5dfc:
    // 0x1c5dfc: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1c5dfcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1c5e00:
    // 0x1c5e00: 0x121880  sll         $v1, $s2, 2
    ctx->pc = 0x1c5e00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1c5e04: 0x2a32021  addu        $a0, $s5, $v1
    ctx->pc = 0x1c5e04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x1c5e08: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c5e08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c5e0c: 0x8c630008  lw          $v1, 0x8($v1)
    ctx->pc = 0x1c5e0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1c5e10: 0x70182b  sltu        $v1, $v1, $s0
    ctx->pc = 0x1c5e10u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1c5e14: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C5E14u;
    {
        const bool branch_taken_0x1c5e14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5e14) {
            ctx->pc = 0x1C5DFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5dfc;
        }
    }
    ctx->pc = 0x1C5E1Cu;
    // 0x1c5e1c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5E1Cu;
    {
        const bool branch_taken_0x1c5e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E1Cu;
            // 0x1c5e20: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e1c) {
            ctx->pc = 0x1C5E2Cu;
            goto label_1c5e2c;
        }
    }
    ctx->pc = 0x1C5E24u;
label_1c5e24:
    // 0x1c5e24: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1c5e24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x1c5e28: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1c5e28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_1c5e2c:
    // 0x1c5e2c: 0x2a32821  addu        $a1, $s5, $v1
    ctx->pc = 0x1c5e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x1c5e30: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1c5e30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c5e34: 0x8c630008  lw          $v1, 0x8($v1)
    ctx->pc = 0x1c5e34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1c5e38: 0x203082b  sltu        $at, $s0, $v1
    ctx->pc = 0x1c5e38u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1c5e3c: 0x1420fff9  bnez        $at, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C5E3Cu;
    {
        const bool branch_taken_0x1c5e3c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E3Cu;
            // 0x1c5e40: 0x251082a  slt         $at, $s2, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e3c) {
            ctx->pc = 0x1C5E24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5e24;
        }
    }
    ctx->pc = 0x1C5E44u;
    // 0x1c5e44: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5E44u;
    {
        const bool branch_taken_0x1c5e44 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E44u;
            // 0x1c5e48: 0x2646ffff  addiu       $a2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e44) {
            ctx->pc = 0x1C5E60u;
            goto label_1c5e60;
        }
    }
    ctx->pc = 0x1C5E4Cu;
    // 0x1c5e4c: 0xc0717b0  jal         func_1C5EC0
    ctx->pc = 0x1C5E4Cu;
    SET_GPR_U32(ctx, 31, 0x1C5E54u);
    ctx->pc = 0x1C5EC0u;
    if (runtime->hasFunction(0x1C5EC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C5EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5E54u; }
        if (ctx->pc != 0x1C5E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5EC0_0x1c5ec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5E54u; }
        if (ctx->pc != 0x1C5E54u) { return; }
    }
    ctx->pc = 0x1C5E54u;
label_1c5e54:
    // 0x1c5e54: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1c5e54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1c5e58: 0x1000ffe9  b           . + 4 + (-0x17 << 2)
    ctx->pc = 0x1C5E58u;
    {
        const bool branch_taken_0x1c5e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E58u;
            // 0x1c5e5c: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e58) {
            ctx->pc = 0x1C5E00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5e00;
        }
    }
    ctx->pc = 0x1C5E60u;
label_1c5e60:
    // 0x1c5e60: 0x286082a  slt         $at, $s4, $a2
    ctx->pc = 0x1c5e60u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1c5e64: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C5E64u;
    {
        const bool branch_taken_0x1c5e64 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E64u;
            // 0x1c5e68: 0x26250001  addiu       $a1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e64) {
            ctx->pc = 0x1C5E7Cu;
            goto label_1c5e7c;
        }
    }
    ctx->pc = 0x1C5E6Cu;
    // 0x1c5e6c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1c5e6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5e70: 0xc071768  jal         func_1C5DA0
    ctx->pc = 0x1C5E70u;
    SET_GPR_U32(ctx, 31, 0x1C5E78u);
    ctx->pc = 0x1C5E74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E70u;
            // 0x1c5e74: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5DA0u;
    goto label_1c5da0;
    ctx->pc = 0x1C5E78u;
label_1c5e78:
    // 0x1c5e78: 0x26250001  addiu       $a1, $s1, 0x1
    ctx->pc = 0x1c5e78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c5e7c:
    // 0x1c5e7c: 0xb3082a  slt         $at, $a1, $s3
    ctx->pc = 0x1c5e7cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1c5e80: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5E80u;
    {
        const bool branch_taken_0x1c5e80 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E80u;
            // 0x1c5e84: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5e80) {
            ctx->pc = 0x1C5E90u;
            goto label_1c5e90;
        }
    }
    ctx->pc = 0x1C5E88u;
    // 0x1c5e88: 0xc071768  jal         func_1C5DA0
    ctx->pc = 0x1C5E88u;
    SET_GPR_U32(ctx, 31, 0x1C5E90u);
    ctx->pc = 0x1C5E8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5E88u;
            // 0x1c5e8c: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5DA0u;
    goto label_1c5da0;
    ctx->pc = 0x1C5E90u;
label_1c5e90:
    // 0x1c5e90: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1c5e90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c5e94: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c5e94u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c5e98: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c5e98u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c5e9c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c5e9cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c5ea0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c5ea0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c5ea4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c5ea4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5ea8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5ea8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5eac: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5EACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5EACu;
            // 0x1c5eb0: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5DA0u: goto label_1c5da0;
            case 0x1C5DE8u: goto label_1c5de8;
            case 0x1C5DFCu: goto label_1c5dfc;
            case 0x1C5E00u: goto label_1c5e00;
            case 0x1C5E24u: goto label_1c5e24;
            case 0x1C5E2Cu: goto label_1c5e2c;
            case 0x1C5E54u: goto label_1c5e54;
            case 0x1C5E60u: goto label_1c5e60;
            case 0x1C5E78u: goto label_1c5e78;
            case 0x1C5E7Cu: goto label_1c5e7c;
            case 0x1C5E90u: goto label_1c5e90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5EB4u;
    // 0x1c5eb4: 0x0  nop
    ctx->pc = 0x1c5eb4u;
    // NOP
    // 0x1c5eb8: 0x0  nop
    ctx->pc = 0x1c5eb8u;
    // NOP
    // 0x1c5ebc: 0x0  nop
    ctx->pc = 0x1c5ebcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
