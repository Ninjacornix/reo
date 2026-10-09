#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00157DC0
// Address: 0x157dc0 - 0x157dd0
void sub_00157DC0_0x157dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00157DC0_0x157dc0");
#endif

    switch (ctx->pc) {
        case 0x157dc8u: goto label_157dc8;
        default: break;
    }

    ctx->pc = 0x157dc0u;

    // 0x157dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x157DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157DC8u: goto label_157dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DC8u;
label_157dc8:
    // 0x157dc8: 0x3e00008  jr          $ra
    ctx->pc = 0x157DC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157DC8u: goto label_157dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
