#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D770
// Address: 0x11d770 - 0x11d7b0
void sub_0011D770_0x11d770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D770_0x11d770");
#endif

    switch (ctx->pc) {
        case 0x11d788u: goto label_11d788;
        default: break;
    }

    ctx->pc = 0x11d770u;

    // 0x11d770: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x11d770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x11d774: 0x1046000b  beq         $v0, $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x11D774u;
    {
        const bool branch_taken_0x11d774 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x11D778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D774u;
            // 0x11d778: 0x85102b  sltu        $v0, $a0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d774) {
            ctx->pc = 0x11D7A4u;
            goto label_11d7a4;
        }
    }
    ctx->pc = 0x11D77Cu;
    // 0x11d77c: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x11D77Cu;
    {
        const bool branch_taken_0x11d77c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11d77c) {
            ctx->pc = 0x11D780u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D77Cu;
            // 0x11d780: 0x2200a  movz        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D7A8u;
            goto label_11d7a8;
        }
    }
    ctx->pc = 0x11D784u;
    // 0x11d784: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11d784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
label_11d788:
    // 0x11d788: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x11d788u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x11d78c: 0x10460005  beq         $v0, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x11D78Cu;
    {
        const bool branch_taken_0x11d78c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x11D790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D78Cu;
            // 0x11d790: 0x85102b  sltu        $v0, $a0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d78c) {
            ctx->pc = 0x11D7A4u;
            goto label_11d7a4;
        }
    }
    ctx->pc = 0x11D794u;
    // 0x11d794: 0x5440fffc  bnel        $v0, $zero, . + 4 + (-0x4 << 2)
    ctx->pc = 0x11D794u;
    {
        const bool branch_taken_0x11d794 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d794) {
            ctx->pc = 0x11D798u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D794u;
            // 0x11d798: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D788u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d788;
        }
    }
    ctx->pc = 0x11D79Cu;
    // 0x11d79c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11D79Cu;
    {
        const bool branch_taken_0x11d79c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D79Cu;
            // 0x11d7a0: 0x2200a  movz        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d79c) {
            ctx->pc = 0x11D7A8u;
            goto label_11d7a8;
        }
    }
    ctx->pc = 0x11D7A4u;
label_11d7a4:
    // 0x11d7a4: 0x2200a  movz        $a0, $zero, $v0
    ctx->pc = 0x11d7a4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
label_11d7a8:
    // 0x11d7a8: 0x3e00008  jr          $ra
    ctx->pc = 0x11D7A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D7A8u;
            // 0x11d7ac: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D788u: goto label_11d788;
            case 0x11D7A4u: goto label_11d7a4;
            case 0x11D7A8u: goto label_11d7a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D7B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
