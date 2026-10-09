#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF5D0
// Address: 0x1af5d0 - 0x1af6a0
void sub_001AF5D0_0x1af5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF5D0_0x1af5d0");
#endif

    switch (ctx->pc) {
        case 0x1af5d8u: goto label_1af5d8;
        case 0x1af628u: goto label_1af628;
        case 0x1af654u: goto label_1af654;
        default: break;
    }

    ctx->pc = 0x1af5d0u;

    // 0x1af5d0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1af5d0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1af5d4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1af5d4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1af5d8:
    // 0x1af5d8: 0x15000005  bnez        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AF5D8u;
    {
        const bool branch_taken_0x1af5d8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AF5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF5D8u;
            // 0x1af5dc: 0x1281824  and         $v1, $t1, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af5d8) {
            ctx->pc = 0x1AF5F0u;
            goto label_1af5f0;
        }
    }
    ctx->pc = 0x1AF5E0u;
    // 0x1af5e0: 0x84890000  lh          $t1, 0x0($a0)
    ctx->pc = 0x1af5e0u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af5e4: 0x34088000  ori         $t0, $zero, 0x8000
    ctx->pc = 0x1af5e4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1af5e8: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1af5e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1af5ec: 0x1281824  and         $v1, $t1, $t0
    ctx->pc = 0x1af5ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & GPR_U64(ctx, 8));
label_1af5f0:
    // 0x1af5f0: 0x10600021  beqz        $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x1AF5F0u;
    {
        const bool branch_taken_0x1af5f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af5f0) {
            ctx->pc = 0x1AF678u;
            goto label_1af678;
        }
    }
    ctx->pc = 0x1AF5F8u;
    // 0x1af5f8: 0x94830000  lhu         $v1, 0x0($a0)
    ctx->pc = 0x1af5f8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af5fc: 0x33ac2  srl         $a3, $v1, 11
    ctx->pc = 0x1af5fcu;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 3), 11));
    // 0x1af600: 0x10e00003  beqz        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AF600u;
    {
        const bool branch_taken_0x1af600 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF600u;
            // 0x1af604: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af600) {
            ctx->pc = 0x1AF610u;
            goto label_1af610;
        }
    }
    ctx->pc = 0x1AF608u;
    // 0x1af608: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AF608u;
    {
        const bool branch_taken_0x1af608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF608u;
            // 0x1af60c: 0x306307ff  andi        $v1, $v1, 0x7FF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2047);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af608) {
            ctx->pc = 0x1AF618u;
            goto label_1af618;
        }
    }
    ctx->pc = 0x1AF610u;
label_1af610:
    // 0x1af610: 0x94870000  lhu         $a3, 0x0($a0)
    ctx->pc = 0x1af610u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af614: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1af614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
label_1af618:
    // 0x1af618: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AF618u;
    {
        const bool branch_taken_0x1af618 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af618) {
            ctx->pc = 0x1AF64Cu;
            goto label_1af64c;
        }
    }
    ctx->pc = 0x1AF620u;
    // 0x1af620: 0x10e0001c  beqz        $a3, . + 4 + (0x1C << 2)
    ctx->pc = 0x1AF620u;
    {
        const bool branch_taken_0x1af620 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af620) {
            ctx->pc = 0x1AF694u;
            goto label_1af694;
        }
    }
    ctx->pc = 0x1AF628u;
label_1af628:
    // 0x1af628: 0xa4a00000  sh          $zero, 0x0($a1)
    ctx->pc = 0x1af628u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1af62c: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x1af62cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1af630: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1af630u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x1af634: 0x0  nop
    ctx->pc = 0x1af634u;
    // NOP
    // 0x1af638: 0x0  nop
    ctx->pc = 0x1af638u;
    // NOP
    // 0x1af63c: 0x14e0fffa  bnez        $a3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AF63Cu;
    {
        const bool branch_taken_0x1af63c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af63c) {
            ctx->pc = 0x1AF628u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af628;
        }
    }
    ctx->pc = 0x1AF644u;
    // 0x1af644: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1AF644u;
    {
        const bool branch_taken_0x1af644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF644u;
            // 0x1af648: 0x84043  sra         $t0, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af644) {
            ctx->pc = 0x1AF68Cu;
            goto label_1af68c;
        }
    }
    ctx->pc = 0x1AF64Cu;
label_1af64c:
    // 0x1af64c: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1af64cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1af650: 0xa33023  subu        $a2, $a1, $v1
    ctx->pc = 0x1af650u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_1af654:
    // 0x1af654: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x1af654u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1af658: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x1af658u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1af65c: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1af65cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1af660: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x1af660u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x1af664: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1af664u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x1af668: 0x14e0fffa  bnez        $a3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AF668u;
    {
        const bool branch_taken_0x1af668 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af668) {
            ctx->pc = 0x1AF654u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af654;
        }
    }
    ctx->pc = 0x1AF670u;
    // 0x1af670: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AF670u;
    {
        const bool branch_taken_0x1af670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af670) {
            ctx->pc = 0x1AF688u;
            goto label_1af688;
        }
    }
    ctx->pc = 0x1AF678u;
label_1af678:
    // 0x1af678: 0x94830000  lhu         $v1, 0x0($a0)
    ctx->pc = 0x1af678u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1af67c: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1af67cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1af680: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1af680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1af684: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1af684u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
label_1af688:
    // 0x1af688: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x1af688u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
label_1af68c:
    // 0x1af68c: 0x1000ffd2  b           . + 4 + (-0x2E << 2)
    ctx->pc = 0x1AF68Cu;
    {
        const bool branch_taken_0x1af68c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af68c) {
            ctx->pc = 0x1AF5D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af5d8;
        }
    }
    ctx->pc = 0x1AF694u;
label_1af694:
    // 0x1af694: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF5D8u: goto label_1af5d8;
            case 0x1AF5F0u: goto label_1af5f0;
            case 0x1AF610u: goto label_1af610;
            case 0x1AF618u: goto label_1af618;
            case 0x1AF628u: goto label_1af628;
            case 0x1AF64Cu: goto label_1af64c;
            case 0x1AF654u: goto label_1af654;
            case 0x1AF678u: goto label_1af678;
            case 0x1AF688u: goto label_1af688;
            case 0x1AF68Cu: goto label_1af68c;
            case 0x1AF694u: goto label_1af694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF69Cu;
    // 0x1af69c: 0x0  nop
    ctx->pc = 0x1af69cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
