#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A35F0
// Address: 0x1a35f0 - 0x1a36a0
void sub_001A35F0_0x1a35f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A35F0_0x1a35f0");
#endif

    switch (ctx->pc) {
        case 0x1a360cu: goto label_1a360c;
        case 0x1a3668u: goto label_1a3668;
        default: break;
    }

    ctx->pc = 0x1a35f0u;

    // 0x1a35f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a35f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a35f4: 0x10a20015  beq         $a1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1A35F4u;
    {
        const bool branch_taken_0x1a35f4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a35f4) {
            ctx->pc = 0x1A364Cu;
            goto label_1a364c;
        }
    }
    ctx->pc = 0x1A35FCu;
    // 0x1a35fc: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1a35fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a3600: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1a3600u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3604: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A3604u;
    {
        const bool branch_taken_0x1a3604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3604u;
            // 0x1a3608: 0x2484000c  addiu       $a0, $a0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3604) {
            ctx->pc = 0x1A3638u;
            goto label_1a3638;
        }
    }
    ctx->pc = 0x1A360Cu;
label_1a360c:
    // 0x1a360c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a360cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a3610: 0x14450006  bne         $v0, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A3610u;
    {
        const bool branch_taken_0x1a3610 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a3610) {
            ctx->pc = 0x1A362Cu;
            goto label_1a362c;
        }
    }
    ctx->pc = 0x1A3618u;
    // 0x1a3618: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3618u;
    {
        const bool branch_taken_0x1a3618 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A361Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3618u;
            // 0x1a361c: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3618) {
            ctx->pc = 0x1A3628u;
            goto label_1a3628;
        }
    }
    ctx->pc = 0x1A3620u;
    // 0x1a3620: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1A3620u;
    {
        const bool branch_taken_0x1a3620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a3620) {
            ctx->pc = 0x1A3690u;
            goto label_1a3690;
        }
    }
    ctx->pc = 0x1A3628u;
label_1a3628:
    // 0x1a3628: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1a3628u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_1a362c:
    // 0x1a362c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a362cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a3630: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a3630u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1a3634: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3634u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3638:
    // 0x1a3638: 0xe3102a  slt         $v0, $a3, $v1
    ctx->pc = 0x1a3638u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a363c: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A363Cu;
    {
        const bool branch_taken_0x1a363c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a363c) {
            ctx->pc = 0x1A360Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a360c;
        }
    }
    ctx->pc = 0x1A3644u;
    // 0x1a3644: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A3644u;
    {
        const bool branch_taken_0x1a3644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3644u;
            // 0x1a3648: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3644) {
            ctx->pc = 0x1A3690u;
            goto label_1a3690;
        }
    }
    ctx->pc = 0x1A364Cu;
label_1a364c:
    // 0x1a364c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1a364cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a3650: 0xc2082b  sltu        $at, $a2, $v0
    ctx->pc = 0x1a3650u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1a3654: 0x1020000d  beqz        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1A3654u;
    {
        const bool branch_taken_0x1a3654 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a3654) {
            ctx->pc = 0x1A368Cu;
            goto label_1a368c;
        }
    }
    ctx->pc = 0x1A365Cu;
    // 0x1a365c: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1a365cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a3660: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3660u;
    {
        const bool branch_taken_0x1a3660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3660u;
            // 0x1a3664: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3660) {
            ctx->pc = 0x1A3674u;
            goto label_1a3674;
        }
    }
    ctx->pc = 0x1A3668u;
label_1a3668:
    // 0x1a3668: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a3668u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a366c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a366cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3670: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3670u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3674:
    // 0x1a3674: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x1a3674u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1a3678: 0x0  nop
    ctx->pc = 0x1a3678u;
    // NOP
    // 0x1a367c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A367Cu;
    {
        const bool branch_taken_0x1a367c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a367c) {
            ctx->pc = 0x1A3668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3668;
        }
    }
    ctx->pc = 0x1A3684u;
    // 0x1a3684: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A3684u;
    {
        const bool branch_taken_0x1a3684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3684u;
            // 0x1a3688: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3684) {
            ctx->pc = 0x1A3690u;
            goto label_1a3690;
        }
    }
    ctx->pc = 0x1A368Cu;
label_1a368c:
    // 0x1a368c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a368cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a3690:
    // 0x1a3690: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3690u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A360Cu: goto label_1a360c;
            case 0x1A3628u: goto label_1a3628;
            case 0x1A362Cu: goto label_1a362c;
            case 0x1A3638u: goto label_1a3638;
            case 0x1A364Cu: goto label_1a364c;
            case 0x1A3668u: goto label_1a3668;
            case 0x1A3674u: goto label_1a3674;
            case 0x1A368Cu: goto label_1a368c;
            case 0x1A3690u: goto label_1a3690;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3698u;
    // 0x1a3698: 0x0  nop
    ctx->pc = 0x1a3698u;
    // NOP
    // 0x1a369c: 0x0  nop
    ctx->pc = 0x1a369cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
