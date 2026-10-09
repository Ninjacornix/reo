#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135A58
// Address: 0x135a58 - 0x135ac0
void sub_00135A58_0x135a58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135A58_0x135a58");
#endif

    switch (ctx->pc) {
        case 0x135a78u: goto label_135a78;
        default: break;
    }

    ctx->pc = 0x135a58u;

    // 0x135a58: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x135a58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x135a5c: 0x24a21f28  addiu       $v0, $a1, 0x1F28
    ctx->pc = 0x135a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 7976));
    // 0x135a60: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x135a60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x135a64: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x135a64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x135a68: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x135A68u;
    {
        const bool branch_taken_0x135a68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x135A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135A68u;
            // 0x135a6c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135a68) {
            ctx->pc = 0x135A9Cu;
            goto label_135a9c;
        }
    }
    ctx->pc = 0x135A70u;
    // 0x135a70: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x135a70u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135a74: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x135a74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_135a78:
    // 0x135a78: 0x28820028  slti        $v0, $a0, 0x28
    ctx->pc = 0x135a78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)40) ? 1 : 0);
    // 0x135a7c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135A7Cu;
    {
        const bool branch_taken_0x135a7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x135A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135A7Cu;
            // 0x135a80: 0x24630008  addiu       $v1, $v1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135a7c) {
            ctx->pc = 0x135A9Cu;
            goto label_135a9c;
        }
    }
    ctx->pc = 0x135A84u;
    // 0x135a84: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x135a84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x135a88: 0x0  nop
    ctx->pc = 0x135a88u;
    // NOP
    // 0x135a8c: 0x0  nop
    ctx->pc = 0x135a8cu;
    // NOP
    // 0x135a90: 0x0  nop
    ctx->pc = 0x135a90u;
    // NOP
    // 0x135a94: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x135A94u;
    {
        const bool branch_taken_0x135a94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x135a94) {
            ctx->pc = 0x135A98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135A94u;
            // 0x135a98: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135A78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135a78;
        }
    }
    ctx->pc = 0x135A9Cu;
label_135a9c:
    // 0x135a9c: 0x24030028  addiu       $v1, $zero, 0x28
    ctx->pc = 0x135a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x135aa0: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x135AA0u;
    {
        const bool branch_taken_0x135aa0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x135AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135AA0u;
            // 0x135aa4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135aa0) {
            ctx->pc = 0x135AB4u;
            goto label_135ab4;
        }
    }
    ctx->pc = 0x135AA8u;
    // 0x135aa8: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x135aa8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x135aac: 0x24a21f28  addiu       $v0, $a1, 0x1F28
    ctx->pc = 0x135aacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 7976));
    // 0x135ab0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x135ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_135ab4:
    // 0x135ab4: 0x3e00008  jr          $ra
    ctx->pc = 0x135AB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135A78u: goto label_135a78;
            case 0x135A9Cu: goto label_135a9c;
            case 0x135AB4u: goto label_135ab4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135ABCu;
    // 0x135abc: 0x0  nop
    ctx->pc = 0x135abcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
