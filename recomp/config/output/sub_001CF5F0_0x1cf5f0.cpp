#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF5F0
// Address: 0x1cf5f0 - 0x1cf6b0
void sub_001CF5F0_0x1cf5f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF5F0_0x1cf5f0");
#endif

    switch (ctx->pc) {
        case 0x1cf648u: goto label_1cf648;
        case 0x1cf65cu: goto label_1cf65c;
        default: break;
    }

    ctx->pc = 0x1cf5f0u;

    // 0x1cf5f0: 0x8c8a0808  lw          $t2, 0x808($a0)
    ctx->pc = 0x1cf5f0u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 2056)));
    // 0x1cf5f4: 0x15400003  bnez        $t2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF5F4u;
    {
        const bool branch_taken_0x1cf5f4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5F4u;
            // 0x1cf5f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf5f4) {
            ctx->pc = 0x1CF604u;
            goto label_1cf604;
        }
    }
    ctx->pc = 0x1CF5FCu;
    // 0x1cf5fc: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1CF5FCu;
    {
        const bool branch_taken_0x1cf5fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf5fc) {
            ctx->pc = 0x1CF6A0u;
            goto label_1cf6a0;
        }
    }
    ctx->pc = 0x1CF604u;
label_1cf604:
    // 0x1cf604: 0x94880812  lhu         $t0, 0x812($a0)
    ctx->pc = 0x1cf604u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2066)));
    // 0x1cf608: 0x1d000003  bgtz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF608u;
    {
        const bool branch_taken_0x1cf608 = (GPR_S64(ctx, 8) > 0);
        ctx->pc = 0x1CF60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF608u;
            // 0x1cf60c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf608) {
            ctx->pc = 0x1CF618u;
            goto label_1cf618;
        }
    }
    ctx->pc = 0x1CF610u;
    // 0x1cf610: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1CF610u;
    {
        const bool branch_taken_0x1cf610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf610) {
            ctx->pc = 0x1CF6A0u;
            goto label_1cf6a0;
        }
    }
    ctx->pc = 0x1CF618u;
label_1cf618:
    // 0x1cf618: 0x8ca40808  lw          $a0, 0x808($a1)
    ctx->pc = 0x1cf618u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 2056)));
    // 0x1cf61c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF61Cu;
    {
        const bool branch_taken_0x1cf61c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF61Cu;
            // 0x1cf620: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf61c) {
            ctx->pc = 0x1CF62Cu;
            goto label_1cf62c;
        }
    }
    ctx->pc = 0x1CF624u;
    // 0x1cf624: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1CF624u;
    {
        const bool branch_taken_0x1cf624 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf624) {
            ctx->pc = 0x1CF6A0u;
            goto label_1cf6a0;
        }
    }
    ctx->pc = 0x1CF62Cu;
label_1cf62c:
    // 0x1cf62c: 0x94a70812  lhu         $a3, 0x812($a1)
    ctx->pc = 0x1cf62cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2066)));
    // 0x1cf630: 0x1ce00003  bgtz        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF630u;
    {
        const bool branch_taken_0x1cf630 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1CF634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF630u;
            // 0x1cf634: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf630) {
            ctx->pc = 0x1CF640u;
            goto label_1cf640;
        }
    }
    ctx->pc = 0x1CF638u;
    // 0x1cf638: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CF638u;
    {
        const bool branch_taken_0x1cf638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF638u;
            // 0x1cf63c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf638) {
            ctx->pc = 0x1CF6A0u;
            goto label_1cf6a0;
        }
    }
    ctx->pc = 0x1CF640u;
label_1cf640:
    // 0x1cf640: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CF640u;
    {
        const bool branch_taken_0x1cf640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF640u;
            // 0x1cf644: 0xc8102a  slt         $v0, $a2, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf640) {
            ctx->pc = 0x1CF698u;
            goto label_1cf698;
        }
    }
    ctx->pc = 0x1CF648u;
label_1cf648:
    // 0x1cf648: 0x8d430000  lw          $v1, 0x0($t2)
    ctx->pc = 0x1cf648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1cf64c: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1CF64Cu;
    {
        const bool branch_taken_0x1cf64c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF64Cu;
            // 0x1cf650: 0x80482d  daddu       $t1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf64c) {
            ctx->pc = 0x1CF68Cu;
            goto label_1cf68c;
        }
    }
    ctx->pc = 0x1CF654u;
    // 0x1cf654: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CF654u;
    {
        const bool branch_taken_0x1cf654 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF654u;
            // 0x1cf658: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf654) {
            ctx->pc = 0x1CF680u;
            goto label_1cf680;
        }
    }
    ctx->pc = 0x1CF65Cu;
label_1cf65c:
    // 0x1cf65c: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x1cf65cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1cf660: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF660u;
    {
        const bool branch_taken_0x1cf660 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf660) {
            ctx->pc = 0x1CF678u;
            goto label_1cf678;
        }
    }
    ctx->pc = 0x1CF668u;
    // 0x1cf668: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF668u;
    {
        const bool branch_taken_0x1cf668 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1cf668) {
            ctx->pc = 0x1CF678u;
            goto label_1cf678;
        }
    }
    ctx->pc = 0x1CF670u;
    // 0x1cf670: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CF670u;
    {
        const bool branch_taken_0x1cf670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF670u;
            // 0x1cf674: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf670) {
            ctx->pc = 0x1CF6A0u;
            goto label_1cf6a0;
        }
    }
    ctx->pc = 0x1CF678u;
label_1cf678:
    // 0x1cf678: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cf678u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cf67c: 0x25290098  addiu       $t1, $t1, 0x98
    ctx->pc = 0x1cf67cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 152));
label_1cf680:
    // 0x1cf680: 0xa7102a  slt         $v0, $a1, $a3
    ctx->pc = 0x1cf680u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1cf684: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1CF684u;
    {
        const bool branch_taken_0x1cf684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf684) {
            ctx->pc = 0x1CF65Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf65c;
        }
    }
    ctx->pc = 0x1CF68Cu;
label_1cf68c:
    // 0x1cf68c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1cf68cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1cf690: 0x254a0098  addiu       $t2, $t2, 0x98
    ctx->pc = 0x1cf690u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 152));
    // 0x1cf694: 0xc8102a  slt         $v0, $a2, $t0
    ctx->pc = 0x1cf694u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
label_1cf698:
    // 0x1cf698: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1CF698u;
    {
        const bool branch_taken_0x1cf698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF698u;
            // 0x1cf69c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf698) {
            ctx->pc = 0x1CF648u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf648;
        }
    }
    ctx->pc = 0x1CF6A0u;
label_1cf6a0:
    // 0x1cf6a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF6A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF604u: goto label_1cf604;
            case 0x1CF618u: goto label_1cf618;
            case 0x1CF62Cu: goto label_1cf62c;
            case 0x1CF640u: goto label_1cf640;
            case 0x1CF648u: goto label_1cf648;
            case 0x1CF65Cu: goto label_1cf65c;
            case 0x1CF678u: goto label_1cf678;
            case 0x1CF680u: goto label_1cf680;
            case 0x1CF68Cu: goto label_1cf68c;
            case 0x1CF698u: goto label_1cf698;
            case 0x1CF6A0u: goto label_1cf6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF6A8u;
    // 0x1cf6a8: 0x0  nop
    ctx->pc = 0x1cf6a8u;
    // NOP
    // 0x1cf6ac: 0x0  nop
    ctx->pc = 0x1cf6acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
