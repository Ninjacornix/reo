#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010F780
// Address: 0x10f780 - 0x10f880
void sub_0010F780_0x10f780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010F780_0x10f780");
#endif

    switch (ctx->pc) {
        case 0x10f7b0u: goto label_10f7b0;
        case 0x10f7e8u: goto label_10f7e8;
        case 0x10f7ecu: goto label_10f7ec;
        case 0x10f7f4u: goto label_10f7f4;
        case 0x10f848u: goto label_10f848;
        default: break;
    }

    ctx->pc = 0x10f780u;

    // 0x10f780: 0x80a60000  lb          $a2, 0x0($a1)
    ctx->pc = 0x10f780u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f784: 0x2402005e  addiu       $v0, $zero, 0x5E
    ctx->pc = 0x10f784u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x10f788: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F788u;
    {
        const bool branch_taken_0x10f788 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x10F78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F788u;
            // 0x10f78c: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f788) {
            ctx->pc = 0x10F7A0u;
            goto label_10f7a0;
        }
    }
    ctx->pc = 0x10F790u;
    // 0x10f790: 0x80a60000  lb          $a2, 0x0($a1)
    ctx->pc = 0x10f790u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f794: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10f794u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10f798: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10F798u;
    {
        const bool branch_taken_0x10f798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F79Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F798u;
            // 0x10f79c: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f798) {
            ctx->pc = 0x10F7A4u;
            goto label_10f7a4;
        }
    }
    ctx->pc = 0x10F7A0u;
label_10f7a0:
    // 0x10f7a0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x10f7a0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10f7a4:
    // 0x10f7a4: 0x240700ff  addiu       $a3, $zero, 0xFF
    ctx->pc = 0x10f7a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x10f7a8: 0x248200ff  addiu       $v0, $a0, 0xFF
    ctx->pc = 0x10f7a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
    // 0x10f7ac: 0x0  nop
    ctx->pc = 0x10f7acu;
    // NOP
label_10f7b0:
    // 0x10f7b0: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10f7b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10f7b4: 0xa0480000  sb          $t0, 0x0($v0)
    ctx->pc = 0x10f7b4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x10f7b8: 0x0  nop
    ctx->pc = 0x10f7b8u;
    // NOP
    // 0x10f7bc: 0x0  nop
    ctx->pc = 0x10f7bcu;
    // NOP
    // 0x10f7c0: 0x0  nop
    ctx->pc = 0x10f7c0u;
    // NOP
    // 0x10f7c4: 0x4e1fffa  bgez        $a3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10F7C4u;
    {
        const bool branch_taken_0x10f7c4 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x10F7C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F7C4u;
            // 0x10f7c8: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f7c4) {
            ctx->pc = 0x10F7B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7b0;
        }
    }
    ctx->pc = 0x10F7CCu;
    // 0x10f7cc: 0x10c0002a  beqz        $a2, . + 4 + (0x2A << 2)
    ctx->pc = 0x10F7CCu;
    {
        const bool branch_taken_0x10f7cc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F7D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F7CCu;
            // 0x10f7d0: 0x24a2ffff  addiu       $v0, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f7cc) {
            ctx->pc = 0x10F878u;
            goto label_10f878;
        }
    }
    ctx->pc = 0x10F7D4u;
    // 0x10f7d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10f7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10f7d8: 0x240a002d  addiu       $t2, $zero, 0x2D
    ctx->pc = 0x10f7d8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10f7dc: 0x484023  subu        $t0, $v0, $t0
    ctx->pc = 0x10f7dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x10f7e0: 0x2409005d  addiu       $t1, $zero, 0x5D
    ctx->pc = 0x10f7e0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
    // 0x10f7e4: 0x0  nop
    ctx->pc = 0x10f7e4u;
    // NOP
label_10f7e8:
    // 0x10f7e8: 0x861021  addu        $v0, $a0, $a2
    ctx->pc = 0x10f7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_10f7ec:
    // 0x10f7ec: 0xa0480000  sb          $t0, 0x0($v0)
    ctx->pc = 0x10f7ecu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x10f7f0: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x10f7f0u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
label_10f7f4:
    // 0x10f7f4: 0x10ea000c  beq         $a3, $t2, . + 4 + (0xC << 2)
    ctx->pc = 0x10F7F4u;
    {
        const bool branch_taken_0x10f7f4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 10));
        ctx->pc = 0x10F7F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F7F4u;
            // 0x10f7f8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f7f4) {
            ctx->pc = 0x10F828u;
            goto label_10f828;
        }
    }
    ctx->pc = 0x10F7FCu;
    // 0x10f7fc: 0x28e2002e  slti        $v0, $a3, 0x2E
    ctx->pc = 0x10f7fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)46) ? 1 : 0);
    // 0x10f800: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F800u;
    {
        const bool branch_taken_0x10f800 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f800) {
            ctx->pc = 0x10F818u;
            goto label_10f818;
        }
    }
    ctx->pc = 0x10F808u;
    // 0x10f808: 0x10e0001b  beqz        $a3, . + 4 + (0x1B << 2)
    ctx->pc = 0x10F808u;
    {
        const bool branch_taken_0x10f808 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F808u;
            // 0x10f80c: 0x24a2ffff  addiu       $v0, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f808) {
            ctx->pc = 0x10F878u;
            goto label_10f878;
        }
    }
    ctx->pc = 0x10F810u;
    // 0x10f810: 0x1000fff5  b           . + 4 + (-0xB << 2)
    ctx->pc = 0x10F810u;
    {
        const bool branch_taken_0x10f810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F810u;
            // 0x10f814: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f810) {
            ctx->pc = 0x10F7E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7e8;
        }
    }
    ctx->pc = 0x10F818u;
label_10f818:
    // 0x10f818: 0x10e90017  beq         $a3, $t1, . + 4 + (0x17 << 2)
    ctx->pc = 0x10F818u;
    {
        const bool branch_taken_0x10f818 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 9));
        ctx->pc = 0x10F81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F818u;
            // 0x10f81c: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f818) {
            ctx->pc = 0x10F878u;
            goto label_10f878;
        }
    }
    ctx->pc = 0x10F820u;
    // 0x10f820: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x10F820u;
    {
        const bool branch_taken_0x10f820 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F820u;
            // 0x10f824: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f820) {
            ctx->pc = 0x10F870u;
            goto label_10f870;
        }
    }
    ctx->pc = 0x10F828u;
label_10f828:
    // 0x10f828: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x10f828u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f82c: 0x50e9ffee  beql        $a3, $t1, . + 4 + (-0x12 << 2)
    ctx->pc = 0x10F82Cu;
    {
        const bool branch_taken_0x10f82c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 9));
        if (branch_taken_0x10f82c) {
            ctx->pc = 0x10F830u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F82Cu;
            // 0x10f830: 0x2406002d  addiu       $a2, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F7E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7e8;
        }
    }
    ctx->pc = 0x10F834u;
    // 0x10f834: 0xe6102a  slt         $v0, $a3, $a2
    ctx->pc = 0x10f834u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x10f838: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x10F838u;
    {
        const bool branch_taken_0x10f838 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f838) {
            ctx->pc = 0x10F83Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F838u;
            // 0x10f83c: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F848u;
            goto label_10f848;
        }
    }
    ctx->pc = 0x10F840u;
    // 0x10f840: 0x1000ffe9  b           . + 4 + (-0x17 << 2)
    ctx->pc = 0x10F840u;
    {
        const bool branch_taken_0x10f840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F840u;
            // 0x10f844: 0x2406002d  addiu       $a2, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f840) {
            ctx->pc = 0x10F7E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7e8;
        }
    }
    ctx->pc = 0x10F848u;
label_10f848:
    // 0x10f848: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10f848u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x10f84c: 0x861021  addu        $v0, $a0, $a2
    ctx->pc = 0x10f84cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x10f850: 0xc7182a  slt         $v1, $a2, $a3
    ctx->pc = 0x10f850u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x10f854: 0x0  nop
    ctx->pc = 0x10f854u;
    // NOP
    // 0x10f858: 0x0  nop
    ctx->pc = 0x10f858u;
    // NOP
    // 0x10f85c: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10F85Cu;
    {
        const bool branch_taken_0x10f85c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F85Cu;
            // 0x10f860: 0xa0480000  sb          $t0, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f85c) {
            ctx->pc = 0x10F848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f848;
        }
    }
    ctx->pc = 0x10F864u;
    // 0x10f864: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x10F864u;
    {
        const bool branch_taken_0x10f864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F864u;
            // 0x10f868: 0x80a70000  lb          $a3, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f864) {
            ctx->pc = 0x10F7F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7f4;
        }
    }
    ctx->pc = 0x10F86Cu;
    // 0x10f86c: 0x0  nop
    ctx->pc = 0x10f86cu;
    // NOP
label_10f870:
    // 0x10f870: 0x1000ffde  b           . + 4 + (-0x22 << 2)
    ctx->pc = 0x10F870u;
    {
        const bool branch_taken_0x10f870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F870u;
            // 0x10f874: 0x861021  addu        $v0, $a0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f870) {
            ctx->pc = 0x10F7ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f7ec;
        }
    }
    ctx->pc = 0x10F878u;
label_10f878:
    // 0x10f878: 0x3e00008  jr          $ra
    ctx->pc = 0x10F878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F7A0u: goto label_10f7a0;
            case 0x10F7A4u: goto label_10f7a4;
            case 0x10F7B0u: goto label_10f7b0;
            case 0x10F7E8u: goto label_10f7e8;
            case 0x10F7ECu: goto label_10f7ec;
            case 0x10F7F4u: goto label_10f7f4;
            case 0x10F818u: goto label_10f818;
            case 0x10F828u: goto label_10f828;
            case 0x10F848u: goto label_10f848;
            case 0x10F870u: goto label_10f870;
            case 0x10F878u: goto label_10f878;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
