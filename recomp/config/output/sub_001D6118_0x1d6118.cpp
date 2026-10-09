#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6118
// Address: 0x1d6118 - 0x1d6148
void sub_001D6118_0x1d6118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6118_0x1d6118");
#endif

    ctx->pc = 0x1d6118u;

    // 0x1d6118: 0x24020038  addiu       $v0, $zero, 0x38
    ctx->pc = 0x1d6118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d611c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d611cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6120: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x1d6120u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1d6124: 0x8ca32844  lw          $v1, 0x2844($a1)
    ctx->pc = 0x1d6124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10308)));
    // 0x1d6128: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d6128u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d612c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d612cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d6130: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1d6130u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1d6134: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1d6134u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1d6138: 0xac600024  sw          $zero, 0x24($v1)
    ctx->pc = 0x1d6138u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 36), GPR_U32(ctx, 0));
    // 0x1d613c: 0xac60001c  sw          $zero, 0x1C($v1)
    ctx->pc = 0x1d613cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 0));
    // 0x1d6140: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6140u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6140u;
            // 0x1d6144: 0xac600020  sw          $zero, 0x20($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6148u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
