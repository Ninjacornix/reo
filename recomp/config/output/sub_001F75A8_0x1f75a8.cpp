#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F75A8
// Address: 0x1f75a8 - 0x1f75a9
void sub_001F75A8_0x1f75a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F75A8_0x1f75a8");
#endif

    ctx->pc = 0x1f75a8u;

    // 0x1f75a8: 0x1e40005  .word       0x01E40005                   # INVALID     $t7, $a0, 0x5 # 00000000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f75a8u;
    // Unhandled SPECIAL instruction: 0x5
    ctx->pc = GPR_U32(ctx, 31); return;
}
