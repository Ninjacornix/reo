#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020AB78
// Address: 0x20ab78 - 0x20abc0
void sub_0020AB78_0x20ab78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020AB78_0x20ab78");
#endif

    ctx->pc = 0x20ab78u;

    // 0x20ab78: 0x40  sll         $zero, $zero, 1
    ctx->pc = 0x20ab78u;
    
    // 0x20ab7c: 0x0  nop
    ctx->pc = 0x20ab7cu;
    // NOP
    // 0x20ab80: 0x0  nop
    ctx->pc = 0x20ab80u;
    // NOP
    // 0x20ab84: 0x0  nop
    ctx->pc = 0x20ab84u;
    // NOP
    // 0x20ab88: 0x0  nop
    ctx->pc = 0x20ab88u;
    // NOP
    // 0x20ab8c: 0x0  nop
    ctx->pc = 0x20ab8cu;
    // NOP
    // 0x20ab90: 0x0  nop
    ctx->pc = 0x20ab90u;
    // NOP
    // 0x20ab94: 0x0  nop
    ctx->pc = 0x20ab94u;
    // NOP
    // 0x20ab98: 0x0  nop
    ctx->pc = 0x20ab98u;
    // NOP
    // 0x20ab9c: 0x0  nop
    ctx->pc = 0x20ab9cu;
    // NOP
    // 0x20aba0: 0x800125ec  lb          $at, 0x25EC($zero)
    ctx->pc = 0x20aba0u;
    SET_GPR_S32(ctx, 1, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 9708)));
    // 0x20aba4: 0x800125f4  lb          $at, 0x25F4($zero)
    ctx->pc = 0x20aba4u;
    SET_GPR_S32(ctx, 1, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 9716)));
    // 0x20aba8: 0x80004970  lb          $zero, 0x4970($zero)
    ctx->pc = 0x20aba8u;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 18800)));
    // 0x20abac: 0x80004288  lb          $zero, 0x4288($zero)
    ctx->pc = 0x20abacu;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 17032)));
    // 0x20abb0: 0x800021b0  lb          $zero, 0x21B0($zero)
    ctx->pc = 0x20abb0u;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 8624)));
    // 0x20abb4: 0x80004e68  lb          $zero, 0x4E68($zero)
    ctx->pc = 0x20abb4u;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 20072)));
    // 0x20abb8: 0x80003f00  lb          $zero, 0x3F00($zero)
    ctx->pc = 0x20abb8u;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 16128)));
    // 0x20abbc: 0x80003e00  lb          $zero, 0x3E00($zero)
    ctx->pc = 0x20abbcu;
    SET_GPR_S32(ctx, 0, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 15872)));
    ctx->pc = GPR_U32(ctx, 31); return;
}
