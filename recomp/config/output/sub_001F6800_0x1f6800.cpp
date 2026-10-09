#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6800
// Address: 0x1f6800 - 0x1f6844
void sub_001F6800_0x1f6800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6800_0x1f6800");
#endif

    ctx->pc = 0x1f6800u;

    // 0x1f6800: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f6800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6804: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6808: 0xac820088  sw          $v0, 0x88($a0)
    ctx->pc = 0x1f6808u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 2));
    // 0x1f680c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1f680cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6810: 0xac800090  sw          $zero, 0x90($a0)
    ctx->pc = 0x1f6810u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 0));
    // 0x1f6814: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f6814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f6818: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6818u;
    {
        const bool branch_taken_0x1f6818 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F681Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6818u;
            // 0x1f681c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6818) {
            ctx->pc = 0x1F683Cu;
            goto label_1f683c;
        }
    }
    ctx->pc = 0x1F6820u;
    // 0x1f6820: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f6820u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f6824: 0x8c2257c0  lw          $v0, 0x57C0($at)
    ctx->pc = 0x1f6824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22464)));
    // 0x1f6828: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6828u;
    {
        const bool branch_taken_0x1f6828 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F682Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6828u;
            // 0x1f682c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6828) {
            ctx->pc = 0x1F6838u;
            goto label_1f6838;
        }
    }
    ctx->pc = 0x1F6830u;
    // 0x1f6830: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6834: 0xac22eaf0  sw          $v0, -0x1510($at)
    ctx->pc = 0x1f6834u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 2));
label_1f6838:
    // 0x1f6838: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6838u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f683c:
    // 0x1f683c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F683Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6844u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
