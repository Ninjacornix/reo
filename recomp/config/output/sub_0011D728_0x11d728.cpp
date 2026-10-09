#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D728
// Address: 0x11d728 - 0x11d7b0
void sub_0011D728_0x11d728(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D728_0x11d728");
#endif

    switch (ctx->pc) {
        case 0x11d748u: goto label_11d748;
        case 0x11d788u: goto label_11d788;
        default: break;
    }

    ctx->pc = 0x11d728u;

    // 0x11d728: 0x2403005a  addiu       $v1, $zero, 0x5A
    ctx->pc = 0x11d728u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x11d72c: 0xc  syscall     0
    ctx->pc = 0x11d72cu;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d730: 0x3e00008  jr          $ra
    ctx->pc = 0x11D730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D748u: goto label_11d748;
            case 0x11D768u: goto label_11d768;
            case 0x11D788u: goto label_11d788;
            case 0x11D7A4u: goto label_11d7a4;
            case 0x11D7A8u: goto label_11d7a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D738u;
    // 0x11d738: 0x63082  srl         $a2, $a2, 2
    ctx->pc = 0x11d738u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x11d73c: 0x10c0000a  beqz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x11D73Cu;
    {
        const bool branch_taken_0x11d73c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D73Cu;
            // 0x11d740: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d73c) {
            ctx->pc = 0x11D768u;
            goto label_11d768;
        }
    }
    ctx->pc = 0x11D744u;
    // 0x11d744: 0x0  nop
    ctx->pc = 0x11d744u;
    // NOP
label_11d748:
    // 0x11d748: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11d748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11d74c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11d74cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11d750: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11d750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11d754: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11d754u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11d758: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x11d758u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11d75c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11d75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x11d760: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11D760u;
    {
        const bool branch_taken_0x11d760 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d760) {
            ctx->pc = 0x11D748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d748;
        }
    }
    ctx->pc = 0x11D768u;
label_11d768:
    // 0x11d768: 0x3e00008  jr          $ra
    ctx->pc = 0x11D768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D768u;
            // 0x11d76c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D748u: goto label_11d748;
            case 0x11D768u: goto label_11d768;
            case 0x11D788u: goto label_11d788;
            case 0x11D7A4u: goto label_11d7a4;
            case 0x11D7A8u: goto label_11d7a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D770u;
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
            case 0x11D748u: goto label_11d748;
            case 0x11D768u: goto label_11d768;
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
