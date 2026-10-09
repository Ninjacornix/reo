#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7593
// Address: 0x1f7593 - 0x1f7594
void sub_001F7593_0x1f7593(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7593_0x1f7593");
#endif

    ctx->pc = 0x1f7593u;

    // 0x1f7593: 0x2ff01  .word       0x0002FF01                   # INVALID     $zero, $v0, -0xFF # 00000000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f7593u;
    // Unhandled SPECIAL instruction: 0x1
    ctx->pc = GPR_U32(ctx, 31); return;
}
