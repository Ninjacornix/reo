#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190060
// Address: 0x190060 - 0x190070
void sub_00190060_0x190060(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190060_0x190060");
#endif

    ctx->pc = 0x190060u;

    // 0x190060: 0xe48c0030  swc1        $f12, 0x30($a0)
    ctx->pc = 0x190060u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x190064: 0xe48d0034  swc1        $f13, 0x34($a0)
    ctx->pc = 0x190064u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x190068: 0x3e00008  jr          $ra
    ctx->pc = 0x190068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19006Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190068u;
            // 0x19006c: 0xe48e0038  swc1        $f14, 0x38($a0) (Delay Slot)
        { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x190070u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
