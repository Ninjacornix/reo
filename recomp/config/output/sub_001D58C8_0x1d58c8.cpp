#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D58C8
// Address: 0x1d58c8 - 0x1d5918
void sub_001D58C8_0x1d58c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D58C8_0x1d58c8");
#endif

    ctx->pc = 0x1d58c8u;

    // 0x1d58c8: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d58c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d58cc: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1d58ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d58d0: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d58d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d58d4: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x1d58d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d58d8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D58D8u;
    {
        const bool branch_taken_0x1d58d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D58DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58D8u;
            // 0x1d58dc: 0x24642840  addiu       $a0, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d58d8) {
            ctx->pc = 0x1D58E8u;
            goto label_1d58e8;
        }
    }
    ctx->pc = 0x1D58E0u;
    // 0x1d58e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D58E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D58E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58E0u;
            // 0x1d58e4: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D58E8u: goto label_1d58e8;
            case 0x1D58FCu: goto label_1d58fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D58E8u;
label_1d58e8:
    // 0x1d58e8: 0x2ca20003  sltiu       $v0, $a1, 0x3
    ctx->pc = 0x1d58e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d58ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D58ECu;
    {
        const bool branch_taken_0x1d58ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D58F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58ECu;
            // 0x1d58f0: 0x24030038  addiu       $v1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d58ec) {
            ctx->pc = 0x1D58FCu;
            goto label_1d58fc;
        }
    }
    ctx->pc = 0x1D58F4u;
    // 0x1d58f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D58F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D58F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58F4u;
            // 0x1d58f8: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D58E8u: goto label_1d58e8;
            case 0x1D58FCu: goto label_1d58fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D58FCu;
label_1d58fc:
    // 0x1d58fc: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1d58fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d5900: 0xc31818  mult        $v1, $a2, $v1
    ctx->pc = 0x1d5900u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d5904: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5904u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5908: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d5908u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d590c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D590Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D590Cu;
            // 0x1d5910: 0xac650008  sw          $a1, 0x8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D58E8u: goto label_1d58e8;
            case 0x1D58FCu: goto label_1d58fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5914u;
    // 0x1d5914: 0x0  nop
    ctx->pc = 0x1d5914u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
