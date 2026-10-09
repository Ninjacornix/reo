#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FE38
// Address: 0x17fe38 - 0x17fe54
void sub_0017FE38_0x17fe38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FE38_0x17fe38");
#endif

    ctx->pc = 0x17fe38u;

    // 0x17fe38: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x17fe38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17fe3c: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x17fe3cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fe40: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x17fe40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fe44: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x17fe44u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fe48: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x17fe48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17fe4c: 0x3e00008  jr          $ra
    ctx->pc = 0x17FE4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FE4Cu;
            // 0x17fe50: 0xe4800008  swc1        $f0, 0x8($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17FE54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
