#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133618
// Address: 0x133618 - 0x133630
void sub_00133618_0x133618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133618_0x133618");
#endif

    ctx->pc = 0x133618u;

    // 0x133618: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13361c: 0x3c064000  lui         $a2, 0x4000
    ctx->pc = 0x13361cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)16384 << 16));
    // 0x133620: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x133620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133624: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133628: 0x804cd8c  j           func_133630
    ctx->pc = 0x133628u;
    ctx->pc = 0x13362Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133628u;
            // 0x13362c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133630u;
    if (runtime->hasFunction(0x133630u)) {
        auto targetFn = runtime->lookupFunction(0x133630u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00133630_0x133630(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133630u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
