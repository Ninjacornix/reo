#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F75AC
// Address: 0x1f75ac - 0x1f75c0
void sub_001F75AC_0x1f75ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F75AC_0x1f75ac");
#endif

    ctx->pc = 0x1f75acu;

    // 0x1f75ac: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f75acu;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    // 0x1f75b0: 0x1e50006  srlv        $zero, $a1, $t7
    ctx->pc = 0x1f75b0u;
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 5), GPR_U32(ctx, 15) & 0x1F));
    // 0x1f75b4: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f75b4u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    // 0x1f75b8: 0x1e60007  srav        $zero, $a2, $t7
    ctx->pc = 0x1f75b8u;
    SET_GPR_S32(ctx, 0, SRA32(GPR_S32(ctx, 6), GPR_U32(ctx, 15) & 0x1F));
    // 0x1f75bc: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f75bcu;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    ctx->pc = GPR_U32(ctx, 31); return;
}
