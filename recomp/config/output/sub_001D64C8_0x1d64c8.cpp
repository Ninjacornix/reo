#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D64C8
// Address: 0x1d64c8 - 0x1d6538
void sub_001D64C8_0x1d64c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D64C8_0x1d64c8");
#endif

    switch (ctx->pc) {
        case 0x1d64f8u: goto label_1d64f8;
        default: break;
    }

    ctx->pc = 0x1d64c8u;

    // 0x1d64c8: 0x24020054  addiu       $v0, $zero, 0x54
    ctx->pc = 0x1d64c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
    // 0x1d64cc: 0x30880001  andi        $t0, $a0, 0x1
    ctx->pc = 0x1d64ccu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1d64d0: 0x1022018  mult        $a0, $t0, $v0
    ctx->pc = 0x1d64d0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1d64d4: 0x3c090025  lui         $t1, 0x25
    ctx->pc = 0x1d64d4u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)37 << 16));
    // 0x1d64d8: 0x25267b58  addiu       $a2, $t1, 0x7B58
    ctx->pc = 0x1d64d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), 31576));
    // 0x1d64dc: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1d64dcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d64e0: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1d64e0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d64e4: 0x861021  addu        $v0, $a0, $a2
    ctx->pc = 0x1d64e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1d64e8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1d64e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d64ec: 0x10a3000d  beq         $a1, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1D64ECu;
    {
        const bool branch_taken_0x1d64ec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D64F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D64ECu;
            // 0x1d64f0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d64ec) {
            ctx->pc = 0x1D6524u;
            goto label_1d6524;
        }
    }
    ctx->pc = 0x1D64F4u;
    // 0x1d64f4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d64f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1d64f8:
    // 0x1d64f8: 0x2ce20015  sltiu       $v0, $a3, 0x15
    ctx->pc = 0x1d64f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
    // 0x1d64fc: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D64FCu;
    {
        const bool branch_taken_0x1d64fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D64FCu;
            // 0x1d6500: 0x24030054  addiu       $v1, $zero, 0x54 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d64fc) {
            ctx->pc = 0x1D6530u;
            goto label_1d6530;
        }
    }
    ctx->pc = 0x1D6504u;
    // 0x1d6504: 0x72080  sll         $a0, $a3, 2
    ctx->pc = 0x1d6504u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1d6508: 0x1031818  mult        $v1, $t0, $v1
    ctx->pc = 0x1d6508u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d650c: 0x25267b58  addiu       $a2, $t1, 0x7B58
    ctx->pc = 0x1d650cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), 31576));
    // 0x1d6510: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1d6510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d6514: 0x861021  addu        $v0, $a0, $a2
    ctx->pc = 0x1d6514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1d6518: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1d6518u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d651c: 0x1543fff6  bne         $t2, $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D651Cu;
    {
        const bool branch_taken_0x1d651c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D6520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D651Cu;
            // 0x1d6520: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d651c) {
            ctx->pc = 0x1D64F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d64f8;
        }
    }
    ctx->pc = 0x1D6524u;
label_1d6524:
    // 0x1d6524: 0xc41021  addu        $v0, $a2, $a0
    ctx->pc = 0x1d6524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1d6528: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1d6528u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1d652c: 0x34654000  ori         $a1, $v1, 0x4000
    ctx->pc = 0x1d652cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16384);
label_1d6530:
    // 0x1d6530: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6530u;
            // 0x1d6534: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D64F8u: goto label_1d64f8;
            case 0x1D6524u: goto label_1d6524;
            case 0x1D6530u: goto label_1d6530;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6538u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
