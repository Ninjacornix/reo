#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8840
// Address: 0x1c8840 - 0x1c8850
void sub_001C8840_0x1c8840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8840_0x1c8840");
#endif

    ctx->pc = 0x1c8840u;

    // 0x1c8840: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8840u;
            // 0x1c8844: 0xc4800070  lwc1        $f0, 0x70($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8848u;
    // 0x1c8848: 0x0  nop
    ctx->pc = 0x1c8848u;
    // NOP
    // 0x1c884c: 0x0  nop
    ctx->pc = 0x1c884cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
