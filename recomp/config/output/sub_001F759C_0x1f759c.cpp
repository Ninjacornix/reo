#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F759C
// Address: 0x1f759c - 0x1f75a8
void sub_001F759C_0x1f759c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F759C_0x1f759c");
#endif

    ctx->pc = 0x1f759cu;

    // 0x1f759c: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f759cu;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    // 0x1f75a0: 0x1e30004  sllv        $zero, $v1, $t7
    ctx->pc = 0x1f75a0u;
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 15) & 0x1F));
    // 0x1f75a4: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f75a4u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    ctx->pc = GPR_U32(ctx, 31); return;
}
