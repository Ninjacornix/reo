#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E350
// Address: 0x17e350 - 0x17e364
void sub_0017E350_0x17e350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E350_0x17e350");
#endif

    ctx->pc = 0x17e350u;

    // 0x17e350: 0xc480003c  lwc1        $f0, 0x3C($a0)
    ctx->pc = 0x17e350u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17e354: 0xe4a00000  swc1        $f0, 0x0($a1)
    ctx->pc = 0x17e354u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x17e358: 0xc4810040  lwc1        $f1, 0x40($a0)
    ctx->pc = 0x17e358u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17e35c: 0x3e00008  jr          $ra
    ctx->pc = 0x17E35Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E35Cu;
            // 0x17e360: 0xe4c10000  swc1        $f1, 0x0($a2) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17E364u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
