#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F75AA
// Address: 0x1f75aa - 0x1f75ab
void sub_001F75AA_0x1f75aa(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F75AA_0x1f75aa");
#endif

    ctx->pc = 0x1f75aau;

    // 0x1f75aa: 0x2ff01e4  .word       0x02FF01E4                   # and         $zero, $s7, $ra # 000001C0 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f75aau;
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 23) & GPR_U64(ctx, 31));
    ctx->pc = GPR_U32(ctx, 31); return;
}
