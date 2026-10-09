#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3AA0
// Address: 0x1a3aa0 - 0x1a3b80
void sub_001A3AA0_0x1a3aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3AA0_0x1a3aa0");
#endif

    switch (ctx->pc) {
        case 0x1a3abcu: goto label_1a3abc;
        case 0x1a3adcu: goto label_1a3adc;
        case 0x1a3af4u: goto label_1a3af4;
        case 0x1a3b1cu: goto label_1a3b1c;
        default: break;
    }

    ctx->pc = 0x1a3aa0u;

    // 0x1a3aa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3aa4: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1a3aa4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3aa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3aac: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1a3aacu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ab0: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1a3ab0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ab4: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A3AB4u;
    SET_GPR_U32(ctx, 31, 0x1A3ABCu);
    ctx->pc = 0x1A3AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AB4u;
            // 0x1a3ab8: 0x80582d  daddu       $t3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ABCu; }
        if (ctx->pc != 0x1A3ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ABCu; }
        if (ctx->pc != 0x1A3ABCu) { return; }
    }
    ctx->pc = 0x1A3ABCu;
label_1a3abc:
    // 0x1a3abc: 0x4a082a  slt         $at, $v0, $t2
    ctx->pc = 0x1a3abcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a3ac0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3AC0u;
    {
        const bool branch_taken_0x1a3ac0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AC0u;
            // 0x1a3ac4: 0x160202d  daddu       $a0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ac0) {
            ctx->pc = 0x1A3AD0u;
            goto label_1a3ad0;
        }
    }
    ctx->pc = 0x1A3AC8u;
    // 0x1a3ac8: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1A3AC8u;
    {
        const bool branch_taken_0x1a3ac8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AC8u;
            // 0x1a3acc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ac8) {
            ctx->pc = 0x1A3B70u;
            goto label_1a3b70;
        }
    }
    ctx->pc = 0x1A3AD0u;
label_1a3ad0:
    // 0x1a3ad0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a3ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a3ad4: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3AD4u;
    SET_GPR_U32(ctx, 31, 0x1A3ADCu);
    ctx->pc = 0x1A3AD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AD4u;
            // 0x1a3ad8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ADCu; }
        if (ctx->pc != 0x1A3ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ADCu; }
        if (ctx->pc != 0x1A3ADCu) { return; }
    }
    ctx->pc = 0x1A3ADCu;
label_1a3adc:
    // 0x1a3adc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3ADCu;
    {
        const bool branch_taken_0x1a3adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3ADCu;
            // 0x1a3ae0: 0x2444000c  addiu       $a0, $v0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3adc) {
            ctx->pc = 0x1A3AECu;
            goto label_1a3aec;
        }
    }
    ctx->pc = 0x1A3AE4u;
    // 0x1a3ae4: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1A3AE4u;
    {
        const bool branch_taken_0x1a3ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AE4u;
            // 0x1a3ae8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ae4) {
            ctx->pc = 0x1A3B70u;
            goto label_1a3b70;
        }
    }
    ctx->pc = 0x1A3AECu;
label_1a3aec:
    // 0x1a3aec: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3AECu;
    {
        const bool branch_taken_0x1a3aec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3AECu;
            // 0x1a3af0: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3aec) {
            ctx->pc = 0x1A3B00u;
            goto label_1a3b00;
        }
    }
    ctx->pc = 0x1A3AF4u;
label_1a3af4:
    // 0x1a3af4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a3af4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a3af8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a3af8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3afc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3b00:
    // 0x1a3b00: 0x6a102a  slt         $v0, $v1, $t2
    ctx->pc = 0x1a3b00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a3b04: 0x0  nop
    ctx->pc = 0x1a3b04u;
    // NOP
    // 0x1a3b08: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A3B08u;
    {
        const bool branch_taken_0x1a3b08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3b08) {
            ctx->pc = 0x1A3AF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3af4;
        }
    }
    ctx->pc = 0x1A3B10u;
    // 0x1a3b10: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1a3b10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a3b14: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3B14u;
    {
        const bool branch_taken_0x1a3b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B14u;
            // 0x1a3b18: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3b14) {
            ctx->pc = 0x1A3B38u;
            goto label_1a3b38;
        }
    }
    ctx->pc = 0x1A3B1Cu;
label_1a3b1c:
    // 0x1a3b1c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a3b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a3b20: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a3b20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3b24: 0x2107c  dsll32      $v0, $v0, 1
    ctx->pc = 0x1a3b24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 1));
    // 0x1a3b28: 0x2107e  dsrl32      $v0, $v0, 1
    ctx->pc = 0x1a3b28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 1));
    // 0x1a3b2c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a3b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a3b30: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1a3b30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1a3b34: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3b34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3b38:
    // 0x1a3b38: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x1a3b38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1a3b3c: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A3B3Cu;
    {
        const bool branch_taken_0x1a3b3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3b3c) {
            ctx->pc = 0x1A3B1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3b1c;
        }
    }
    ctx->pc = 0x1A3B44u;
    // 0x1a3b44: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a3b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a3b48: 0x2107c  dsll32      $v0, $v0, 1
    ctx->pc = 0x1a3b48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 1));
    // 0x1a3b4c: 0x2107e  dsrl32      $v0, $v0, 1
    ctx->pc = 0x1a3b4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 1));
    // 0x1a3b50: 0x102102a  slt         $v0, $t0, $v0
    ctx->pc = 0x1a3b50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a3b54: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3B54u;
    {
        const bool branch_taken_0x1a3b54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B54u;
            // 0x1a3b58: 0x24830004  addiu       $v1, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3b54) {
            ctx->pc = 0x1A3B64u;
            goto label_1a3b64;
        }
    }
    ctx->pc = 0x1A3B5Cu;
    // 0x1a3b5c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3B5Cu;
    {
        const bool branch_taken_0x1a3b5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B5Cu;
            // 0x1a3b60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3b5c) {
            ctx->pc = 0x1A3B70u;
            goto label_1a3b70;
        }
    }
    ctx->pc = 0x1A3B64u;
label_1a3b64:
    // 0x1a3b64: 0x81080  sll         $v0, $t0, 2
    ctx->pc = 0x1a3b64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1a3b68: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a3b68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a3b6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a3b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1a3b70:
    // 0x1a3b70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3b74: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3B74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B74u;
            // 0x1a3b78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3ABCu: goto label_1a3abc;
            case 0x1A3AD0u: goto label_1a3ad0;
            case 0x1A3ADCu: goto label_1a3adc;
            case 0x1A3AECu: goto label_1a3aec;
            case 0x1A3AF4u: goto label_1a3af4;
            case 0x1A3B00u: goto label_1a3b00;
            case 0x1A3B1Cu: goto label_1a3b1c;
            case 0x1A3B38u: goto label_1a3b38;
            case 0x1A3B64u: goto label_1a3b64;
            case 0x1A3B70u: goto label_1a3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3B7Cu;
    // 0x1a3b7c: 0x0  nop
    ctx->pc = 0x1a3b7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
