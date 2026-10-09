#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010CD78
// Address: 0x10cd78 - 0x10cda4
void sub_0010CD78_0x10cd78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010CD78_0x10cd78");
#endif

    ctx->pc = 0x10cd78u;

    // 0x10cd78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10cd78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10cd7c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x10cd7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x10cd80: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10cd80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10cd84: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x10cd84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cd88: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10cd88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cd8c: 0x8c6497f0  lw          $a0, -0x6810($v1)
    ctx->pc = 0x10cd8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294940656)));
    // 0x10cd90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10cd90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10cd94: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x10cd94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cd98: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x10cd98u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cd9c: 0x80432d2  j           func_10CB48
    ctx->pc = 0x10CD9Cu;
    ctx->pc = 0x10CDA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CD9Cu;
            // 0x10cda0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CB48u;
    if (runtime->hasFunction(0x10CB48u)) {
        auto targetFn = runtime->lookupFunction(0x10CB48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010CB48_0x10cb48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10CDA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
