#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AA3D0
// Address: 0x1aa3d0 - 0x1aa3e0
void sub_001AA3D0_0x1aa3d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AA3D0_0x1aa3d0");
#endif

    ctx->pc = 0x1aa3d0u;

    // 0x1aa3d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA3D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AA3D8u;
    // 0x1aa3d8: 0x0  nop
    ctx->pc = 0x1aa3d8u;
    // NOP
    // 0x1aa3dc: 0x0  nop
    ctx->pc = 0x1aa3dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
