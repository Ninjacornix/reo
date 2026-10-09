#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192A60
// Address: 0x192a60 - 0x192b70
void sub_00192A60_0x192a60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192A60_0x192a60");
#endif

    switch (ctx->pc) {
        case 0x192a64u: goto label_192a64;
        case 0x192aa0u: goto label_192aa0;
        case 0x192ad4u: goto label_192ad4;
        case 0x192b04u: goto label_192b04;
        case 0x192b44u: goto label_192b44;
        case 0x192b54u: goto label_192b54;
        default: break;
    }

    ctx->pc = 0x192a60u;

    // 0x192a60: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x192a60u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_192a64:
    // 0x192a64: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x192a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x192a68: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x192a68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x192a6c: 0xac8200d8  sw          $v0, 0xD8($a0)
    ctx->pc = 0x192a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 2));
    // 0x192a70: 0x8c22fe40  lw          $v0, -0x1C0($at)
    ctx->pc = 0x192a70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966848)));
    // 0x192a74: 0xac8200d4  sw          $v0, 0xD4($a0)
    ctx->pc = 0x192a74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 2));
    // 0x192a78: 0x8c8200d0  lw          $v0, 0xD0($a0)
    ctx->pc = 0x192a78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 208)));
    // 0x192a7c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192A7Cu;
    {
        const bool branch_taken_0x192a7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x192A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192A7Cu;
            // 0x192a80: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192a7c) {
            ctx->pc = 0x192A8Cu;
            goto label_192a8c;
        }
    }
    ctx->pc = 0x192A84u;
    // 0x192a84: 0x1000fff7  b           . + 4 + (-0x9 << 2)
    ctx->pc = 0x192A84u;
    {
        const bool branch_taken_0x192a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192A84u;
            // 0x192a88: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192a84) {
            ctx->pc = 0x192A64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192a64;
        }
    }
    ctx->pc = 0x192A8Cu;
label_192a8c:
    // 0x192a8c: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192a90: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x192A90u;
    {
        const bool branch_taken_0x192a90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192a90) {
            ctx->pc = 0x192AB8u;
            goto label_192ab8;
        }
    }
    ctx->pc = 0x192A98u;
    // 0x192a98: 0x1000fff2  b           . + 4 + (-0xE << 2)
    ctx->pc = 0x192A98u;
    {
        const bool branch_taken_0x192a98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192A98u;
            // 0x192a9c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192a98) {
            ctx->pc = 0x192A64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192a64;
        }
    }
    ctx->pc = 0x192AA0u;
label_192aa0:
    // 0x192aa0: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192aa4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192AA4u;
    {
        const bool branch_taken_0x192aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192aa4) {
            ctx->pc = 0x192AB4u;
            goto label_192ab4;
        }
    }
    ctx->pc = 0x192AACu;
    // 0x192aac: 0x1000ffed  b           . + 4 + (-0x13 << 2)
    ctx->pc = 0x192AACu;
    {
        const bool branch_taken_0x192aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AACu;
            // 0x192ab0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192aac) {
            ctx->pc = 0x192A64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192a64;
        }
    }
    ctx->pc = 0x192AB4u;
label_192ab4:
    // 0x192ab4: 0x8c8400c8  lw          $a0, 0xC8($a0)
    ctx->pc = 0x192ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 200)));
label_192ab8:
    // 0x192ab8: 0x1483fff9  bne         $a0, $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192AB8u;
    {
        const bool branch_taken_0x192ab8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x192ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AB8u;
            // 0x192abc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192ab8) {
            ctx->pc = 0x192AA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192aa0;
        }
    }
    ctx->pc = 0x192AC0u;
    // 0x192ac0: 0x3e00008  jr          $ra
    ctx->pc = 0x192AC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192A64u: goto label_192a64;
            case 0x192A8Cu: goto label_192a8c;
            case 0x192AA0u: goto label_192aa0;
            case 0x192AB4u: goto label_192ab4;
            case 0x192AB8u: goto label_192ab8;
            case 0x192AD4u: goto label_192ad4;
            case 0x192AF0u: goto label_192af0;
            case 0x192B04u: goto label_192b04;
            case 0x192B18u: goto label_192b18;
            case 0x192B1Cu: goto label_192b1c;
            case 0x192B44u: goto label_192b44;
            case 0x192B54u: goto label_192b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192AC8u;
    // 0x192ac8: 0x0  nop
    ctx->pc = 0x192ac8u;
    // NOP
    // 0x192acc: 0x0  nop
    ctx->pc = 0x192accu;
    // NOP
    // 0x192ad0: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x192ad0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_192ad4:
    // 0x192ad4: 0xac8000d4  sw          $zero, 0xD4($a0)
    ctx->pc = 0x192ad4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 0));
    // 0x192ad8: 0xac8000d8  sw          $zero, 0xD8($a0)
    ctx->pc = 0x192ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 0));
    // 0x192adc: 0x8c8200d0  lw          $v0, 0xD0($a0)
    ctx->pc = 0x192adcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 208)));
    // 0x192ae0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192AE0u;
    {
        const bool branch_taken_0x192ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192ae0) {
            ctx->pc = 0x192AF0u;
            goto label_192af0;
        }
    }
    ctx->pc = 0x192AE8u;
    // 0x192ae8: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x192AE8u;
    {
        const bool branch_taken_0x192ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AE8u;
            // 0x192aec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192ae8) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192AF0u;
label_192af0:
    // 0x192af0: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192af0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192af4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x192AF4u;
    {
        const bool branch_taken_0x192af4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192af4) {
            ctx->pc = 0x192B1Cu;
            goto label_192b1c;
        }
    }
    ctx->pc = 0x192AFCu;
    // 0x192afc: 0x1000fff5  b           . + 4 + (-0xB << 2)
    ctx->pc = 0x192AFCu;
    {
        const bool branch_taken_0x192afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AFCu;
            // 0x192b00: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192afc) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192B04u;
label_192b04:
    // 0x192b04: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192b08: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192B08u;
    {
        const bool branch_taken_0x192b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192b08) {
            ctx->pc = 0x192B18u;
            goto label_192b18;
        }
    }
    ctx->pc = 0x192B10u;
    // 0x192b10: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x192B10u;
    {
        const bool branch_taken_0x192b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B10u;
            // 0x192b14: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b10) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192B18u;
label_192b18:
    // 0x192b18: 0x8c8400c8  lw          $a0, 0xC8($a0)
    ctx->pc = 0x192b18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 200)));
label_192b1c:
    // 0x192b1c: 0x1483fff9  bne         $a0, $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192B1Cu;
    {
        const bool branch_taken_0x192b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x192B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B1Cu;
            // 0x192b20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b1c) {
            ctx->pc = 0x192B04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192b04;
        }
    }
    ctx->pc = 0x192B24u;
    // 0x192b24: 0x3e00008  jr          $ra
    ctx->pc = 0x192B24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192A64u: goto label_192a64;
            case 0x192A8Cu: goto label_192a8c;
            case 0x192AA0u: goto label_192aa0;
            case 0x192AB4u: goto label_192ab4;
            case 0x192AB8u: goto label_192ab8;
            case 0x192AD4u: goto label_192ad4;
            case 0x192AF0u: goto label_192af0;
            case 0x192B04u: goto label_192b04;
            case 0x192B18u: goto label_192b18;
            case 0x192B1Cu: goto label_192b1c;
            case 0x192B44u: goto label_192b44;
            case 0x192B54u: goto label_192b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192B2Cu;
    // 0x192b2c: 0x0  nop
    ctx->pc = 0x192b2cu;
    // NOP
    // 0x192b30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x192b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x192b34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x192b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x192b38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192b38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192b3c: 0xc064b44  jal         func_192D10
    ctx->pc = 0x192B3Cu;
    SET_GPR_U32(ctx, 31, 0x192B44u);
    ctx->pc = 0x192B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192B3Cu;
            // 0x192b40: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B44u; }
        if (ctx->pc != 0x192B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B44u; }
        if (ctx->pc != 0x192B44u) { return; }
    }
    ctx->pc = 0x192B44u;
label_192b44:
    // 0x192b44: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192B44u;
    {
        const bool branch_taken_0x192b44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B44u;
            // 0x192b48: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b44) {
            ctx->pc = 0x192B54u;
            goto label_192b54;
        }
    }
    ctx->pc = 0x192B4Cu;
    // 0x192b4c: 0xc064adc  jal         func_192B70
    ctx->pc = 0x192B4Cu;
    SET_GPR_U32(ctx, 31, 0x192B54u);
    ctx->pc = 0x192B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192B4Cu;
            // 0x192b50: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192B70u;
    if (runtime->hasFunction(0x192B70u)) {
        auto targetFn = runtime->lookupFunction(0x192B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B54u; }
        if (ctx->pc != 0x192B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192B70_0x192b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B54u; }
        if (ctx->pc != 0x192B54u) { return; }
    }
    ctx->pc = 0x192B54u;
label_192b54:
    // 0x192b54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x192b54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192b58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192b5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192b5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192b60: 0x3e00008  jr          $ra
    ctx->pc = 0x192B60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B60u;
            // 0x192b64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192A64u: goto label_192a64;
            case 0x192A8Cu: goto label_192a8c;
            case 0x192AA0u: goto label_192aa0;
            case 0x192AB4u: goto label_192ab4;
            case 0x192AB8u: goto label_192ab8;
            case 0x192AD4u: goto label_192ad4;
            case 0x192AF0u: goto label_192af0;
            case 0x192B04u: goto label_192b04;
            case 0x192B18u: goto label_192b18;
            case 0x192B1Cu: goto label_192b1c;
            case 0x192B44u: goto label_192b44;
            case 0x192B54u: goto label_192b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192B68u;
    // 0x192b68: 0x0  nop
    ctx->pc = 0x192b68u;
    // NOP
    // 0x192b6c: 0x0  nop
    ctx->pc = 0x192b6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
