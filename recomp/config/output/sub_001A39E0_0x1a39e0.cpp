#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A39E0
// Address: 0x1a39e0 - 0x1a3aa0
void sub_001A39E0_0x1a39e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A39E0_0x1a39e0");
#endif

    switch (ctx->pc) {
        case 0x1a39f8u: goto label_1a39f8;
        case 0x1a3a18u: goto label_1a3a18;
        case 0x1a3a30u: goto label_1a3a30;
        case 0x1a3a5cu: goto label_1a3a5c;
        default: break;
    }

    ctx->pc = 0x1a39e0u;

    // 0x1a39e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a39e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a39e4: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1a39e4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a39e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a39e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a39ec: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1a39ecu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a39f0: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A39F0u;
    SET_GPR_U32(ctx, 31, 0x1A39F8u);
    ctx->pc = 0x1A39F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A39F0u;
            // 0x1a39f4: 0x80582d  daddu       $t3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A39F8u; }
        if (ctx->pc != 0x1A39F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A39F8u; }
        if (ctx->pc != 0x1A39F8u) { return; }
    }
    ctx->pc = 0x1A39F8u;
label_1a39f8:
    // 0x1a39f8: 0x4a082a  slt         $at, $v0, $t2
    ctx->pc = 0x1a39f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a39fc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A39FCu;
    {
        const bool branch_taken_0x1a39fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A39FCu;
            // 0x1a3a00: 0x160202d  daddu       $a0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a39fc) {
            ctx->pc = 0x1A3A0Cu;
            goto label_1a3a0c;
        }
    }
    ctx->pc = 0x1A3A04u;
    // 0x1a3a04: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1A3A04u;
    {
        const bool branch_taken_0x1a3a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A04u;
            // 0x1a3a08: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a04) {
            ctx->pc = 0x1A3A88u;
            goto label_1a3a88;
        }
    }
    ctx->pc = 0x1A3A0Cu;
label_1a3a0c:
    // 0x1a3a0c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a3a0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a3a10: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3A10u;
    SET_GPR_U32(ctx, 31, 0x1A3A18u);
    ctx->pc = 0x1A3A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A10u;
            // 0x1a3a14: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3A18u; }
        if (ctx->pc != 0x1A3A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3A18u; }
        if (ctx->pc != 0x1A3A18u) { return; }
    }
    ctx->pc = 0x1A3A18u;
label_1a3a18:
    // 0x1a3a18: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3A18u;
    {
        const bool branch_taken_0x1a3a18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A18u;
            // 0x1a3a1c: 0x2444000c  addiu       $a0, $v0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a18) {
            ctx->pc = 0x1A3A28u;
            goto label_1a3a28;
        }
    }
    ctx->pc = 0x1A3A20u;
    // 0x1a3a20: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1A3A20u;
    {
        const bool branch_taken_0x1a3a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A20u;
            // 0x1a3a24: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a20) {
            ctx->pc = 0x1A3A88u;
            goto label_1a3a88;
        }
    }
    ctx->pc = 0x1A3A28u;
label_1a3a28:
    // 0x1a3a28: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3A28u;
    {
        const bool branch_taken_0x1a3a28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A28u;
            // 0x1a3a2c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a28) {
            ctx->pc = 0x1A3A3Cu;
            goto label_1a3a3c;
        }
    }
    ctx->pc = 0x1A3A30u;
label_1a3a30:
    // 0x1a3a30: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a3a30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a3a34: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a3a34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3a38: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3a38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3a3c:
    // 0x1a3a3c: 0x6a102a  slt         $v0, $v1, $t2
    ctx->pc = 0x1a3a3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a3a40: 0x0  nop
    ctx->pc = 0x1a3a40u;
    // NOP
    // 0x1a3a44: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A3A44u;
    {
        const bool branch_taken_0x1a3a44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3a44) {
            ctx->pc = 0x1A3A30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3a30;
        }
    }
    ctx->pc = 0x1A3A4Cu;
    // 0x1a3a4c: 0x2485000c  addiu       $a1, $a0, 0xC
    ctx->pc = 0x1a3a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a3a50: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a3a50u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a3a54: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A3A54u;
    {
        const bool branch_taken_0x1a3a54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A54u;
            // 0x1a3a58: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a54) {
            ctx->pc = 0x1A3A7Cu;
            goto label_1a3a7c;
        }
    }
    ctx->pc = 0x1A3A5Cu;
label_1a3a5c:
    // 0x1a3a5c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a3a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a3a60: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a3a60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a3a64: 0x434024  and         $t0, $v0, $v1
    ctx->pc = 0x1a3a64u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1a3a68: 0x2107c  dsll32      $v0, $v0, 1
    ctx->pc = 0x1a3a68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 1));
    // 0x1a3a6c: 0x2107e  dsrl32      $v0, $v0, 1
    ctx->pc = 0x1a3a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 1));
    // 0x1a3a70: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a3a70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a3a74: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1a3a74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1a3a78: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1a3a78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1a3a7c:
    // 0x1a3a7c: 0x124082a  slt         $at, $t1, $a0
    ctx->pc = 0x1a3a7cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a3a80: 0x1020fff6  beqz        $at, . + 4 + (-0xA << 2)
    ctx->pc = 0x1A3A80u;
    {
        const bool branch_taken_0x1a3a80 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A80u;
            // 0x1a3a84: 0x8102b  sltu        $v0, $zero, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3a80) {
            ctx->pc = 0x1A3A5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3a5c;
        }
    }
    ctx->pc = 0x1A3A88u;
label_1a3a88:
    // 0x1a3a88: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3a88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3a8c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3A8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3A8Cu;
            // 0x1a3a90: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A39F8u: goto label_1a39f8;
            case 0x1A3A0Cu: goto label_1a3a0c;
            case 0x1A3A18u: goto label_1a3a18;
            case 0x1A3A28u: goto label_1a3a28;
            case 0x1A3A30u: goto label_1a3a30;
            case 0x1A3A3Cu: goto label_1a3a3c;
            case 0x1A3A5Cu: goto label_1a3a5c;
            case 0x1A3A7Cu: goto label_1a3a7c;
            case 0x1A3A88u: goto label_1a3a88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3A94u;
    // 0x1a3a94: 0x0  nop
    ctx->pc = 0x1a3a94u;
    // NOP
    // 0x1a3a98: 0x0  nop
    ctx->pc = 0x1a3a98u;
    // NOP
    // 0x1a3a9c: 0x0  nop
    ctx->pc = 0x1a3a9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
