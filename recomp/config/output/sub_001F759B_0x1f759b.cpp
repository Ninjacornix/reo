#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F759B
// Address: 0x1f759b - 0x1f759c
void sub_001F759B_0x1f759b(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F759B_0x1f759b");
#endif

    ctx->pc = 0x1f759bu;

    // 0x1f759b: 0x2ff01  .word       0x0002FF01                   # INVALID     $zero, $v0, -0xFF # 00000000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f759bu;
    // Unhandled SPECIAL instruction: 0x1
    ctx->pc = GPR_U32(ctx, 31); return;
}
