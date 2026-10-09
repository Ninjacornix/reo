#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5830
// Address: 0x1d5830 - 0x1d5878
void sub_001D5830_0x1d5830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5830_0x1d5830");
#endif

    ctx->pc = 0x1d5830u;

    // 0x1d5830: 0x4a0000e  bltz        $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1D5830u;
    {
        const bool branch_taken_0x1d5830 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1D5834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5830u;
            // 0x1d5834: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5830) {
            ctx->pc = 0x1D586Cu;
            goto label_1d586c;
        }
    }
    ctx->pc = 0x1D5838u;
    // 0x1d5838: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5838u;
    {
        const bool branch_taken_0x1d5838 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1D583Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5838u;
            // 0x1d583c: 0x24030038  addiu       $v1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5838) {
            ctx->pc = 0x1D5848u;
            goto label_1d5848;
        }
    }
    ctx->pc = 0x1D5840u;
    // 0x1d5840: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5840u;
            // 0x1d5844: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5848u: goto label_1d5848;
            case 0x1D586Cu: goto label_1d586c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5848u;
label_1d5848:
    // 0x1d5848: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5848u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d584c: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1d584cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d5850: 0x8c442844  lw          $a0, 0x2844($v0)
    ctx->pc = 0x1d5850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10308)));
    // 0x1d5854: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5858: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d5858u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d585c: 0xac66001c  sw          $a2, 0x1C($v1)
    ctx->pc = 0x1d585cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 6));
    // 0x1d5860: 0xac650018  sw          $a1, 0x18($v1)
    ctx->pc = 0x1d5860u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 5));
    // 0x1d5864: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5864u;
            // 0x1d5868: 0xac600014  sw          $zero, 0x14($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5848u: goto label_1d5848;
            case 0x1D586Cu: goto label_1d586c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D586Cu;
label_1d586c:
    // 0x1d586c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D586Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5848u: goto label_1d5848;
            case 0x1D586Cu: goto label_1d586c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5874u;
    // 0x1d5874: 0x0  nop
    ctx->pc = 0x1d5874u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
