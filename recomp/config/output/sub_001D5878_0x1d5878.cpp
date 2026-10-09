#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5878
// Address: 0x1d5878 - 0x1d58c8
void sub_001D5878_0x1d5878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5878_0x1d5878");
#endif

    ctx->pc = 0x1d5878u;

    // 0x1d5878: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5878u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d587c: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1d587cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5880: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d5880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d5884: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x1d5884u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5888: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5888u;
    {
        const bool branch_taken_0x1d5888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D588Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5888u;
            // 0x1d588c: 0x24642840  addiu       $a0, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5888) {
            ctx->pc = 0x1D5898u;
            goto label_1d5898;
        }
    }
    ctx->pc = 0x1D5890u;
    // 0x1d5890: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5890u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5890u;
            // 0x1d5894: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5898u: goto label_1d5898;
            case 0x1D58ACu: goto label_1d58ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5898u;
label_1d5898:
    // 0x1d5898: 0x2ca20002  sltiu       $v0, $a1, 0x2
    ctx->pc = 0x1d5898u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d589c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D589Cu;
    {
        const bool branch_taken_0x1d589c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D58A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D589Cu;
            // 0x1d58a0: 0x24030038  addiu       $v1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d589c) {
            ctx->pc = 0x1D58ACu;
            goto label_1d58ac;
        }
    }
    ctx->pc = 0x1D58A4u;
    // 0x1d58a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D58A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D58A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58A4u;
            // 0x1d58a8: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5898u: goto label_1d5898;
            case 0x1D58ACu: goto label_1d58ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D58ACu;
label_1d58ac:
    // 0x1d58ac: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1d58acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d58b0: 0xc31818  mult        $v1, $a2, $v1
    ctx->pc = 0x1d58b0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d58b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d58b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d58b8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d58b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d58bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D58BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D58C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D58BCu;
            // 0x1d58c0: 0xac650004  sw          $a1, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5898u: goto label_1d5898;
            case 0x1D58ACu: goto label_1d58ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D58C4u;
    // 0x1d58c4: 0x0  nop
    ctx->pc = 0x1d58c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
