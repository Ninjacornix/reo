#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0370
// Address: 0x1c0370 - 0x1c03a0
void sub_001C0370_0x1c0370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0370_0x1c0370");
#endif

    ctx->pc = 0x1c0370u;

    // 0x1c0370: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0370u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0374: 0xac246cf0  sw          $a0, 0x6CF0($at)
    ctx->pc = 0x1c0374u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27888), GPR_U32(ctx, 4));
    // 0x1c0378: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0378u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c037c: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c037cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c0380: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0380u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0384: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c0384u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c0388: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0388u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c038c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C038Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C038Cu;
            // 0x1c0390: 0xac206ce8  sw          $zero, 0x6CE8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C0394u;
    // 0x1c0394: 0x0  nop
    ctx->pc = 0x1c0394u;
    // NOP
    // 0x1c0398: 0x0  nop
    ctx->pc = 0x1c0398u;
    // NOP
    // 0x1c039c: 0x0  nop
    ctx->pc = 0x1c039cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
