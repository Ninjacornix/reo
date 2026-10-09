#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191ED0
// Address: 0x191ed0 - 0x191eec
void sub_00191ED0_0x191ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191ED0_0x191ed0");
#endif

    ctx->pc = 0x191ed0u;

    // 0x191ed0: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x191ed0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191ed4: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x191ed4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191ed8: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x191ed8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191edc: 0xe4820000  swc1        $f2, 0x0($a0)
    ctx->pc = 0x191edcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191ee0: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x191ee0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x191EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191EE4u;
            // 0x191ee8: 0xe4800008  swc1        $f0, 0x8($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191EECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
