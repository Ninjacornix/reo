#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015C890
// Address: 0x15c890 - 0x15c8c0
void sub_0015C890_0x15c890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015C890_0x15c890");
#endif

    ctx->pc = 0x15c890u;

    // 0x15c890: 0x248200bc  addiu       $v0, $a0, 0xBC
    ctx->pc = 0x15c890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 188));
    // 0x15c894: 0xc73023  subu        $a2, $a2, $a3
    ctx->pc = 0x15c894u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x15c898: 0xa71821  addu        $v1, $a1, $a3
    ctx->pc = 0x15c898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x15c89c: 0xac8700dc  sw          $a3, 0xDC($a0)
    ctx->pc = 0x15c89cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 220), GPR_U32(ctx, 7));
    // 0x15c8a0: 0xac8000e4  sw          $zero, 0xE4($a0)
    ctx->pc = 0x15c8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 228), GPR_U32(ctx, 0));
    // 0x15c8a4: 0xac8500d8  sw          $a1, 0xD8($a0)
    ctx->pc = 0x15c8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 5));
    // 0x15c8a8: 0xac8000e0  sw          $zero, 0xE0($a0)
    ctx->pc = 0x15c8a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 224), GPR_U32(ctx, 0));
    // 0x15c8ac: 0xac8200d4  sw          $v0, 0xD4($a0)
    ctx->pc = 0x15c8acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 2));
    // 0x15c8b0: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x15c8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x15c8b4: 0xac470008  sw          $a3, 0x8($v0)
    ctx->pc = 0x15c8b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 7));
    // 0x15c8b8: 0x3e00008  jr          $ra
    ctx->pc = 0x15C8B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15C8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C8B8u;
            // 0x15c8bc: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15C8C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
