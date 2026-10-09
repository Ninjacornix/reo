#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E678
// Address: 0x15e678 - 0x15e6a0
void sub_0015E678_0x15e678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E678_0x15e678");
#endif

    ctx->pc = 0x15e678u;

    // 0x15e678: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15e678u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15e67c: 0x3e00008  jr          $ra
    ctx->pc = 0x15E67Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E67Cu;
            // 0x15e680: 0x2442de58  addiu       $v0, $v0, -0x21A8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958680));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15E684u;
    // 0x15e684: 0x0  nop
    ctx->pc = 0x15e684u;
    // NOP
    // 0x15e688: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e68c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x15e68cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e690: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e694: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15e694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e698: 0x8058dd4  j           func_163750
    ctx->pc = 0x15E698u;
    ctx->pc = 0x15E69Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E698u;
            // 0x15e69c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E6A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
