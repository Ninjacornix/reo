#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001280A8
// Address: 0x1280a8 - 0x1280cc
void sub_001280A8_0x1280a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001280A8_0x1280a8");
#endif

    ctx->pc = 0x1280a8u;

    // 0x1280a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1280a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1280ac: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1280acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1280b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1280b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1280b4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1280b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1280b8: 0xac44c7b0  sw          $a0, -0x3850($v0)
    ctx->pc = 0x1280b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294952880), GPR_U32(ctx, 4));
    // 0x1280bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1280bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1280c0: 0xac65c7b4  sw          $a1, -0x384C($v1)
    ctx->pc = 0x1280c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294952884), GPR_U32(ctx, 5));
    // 0x1280c4: 0x805076c  j           func_141DB0
    ctx->pc = 0x1280C4u;
    ctx->pc = 0x1280C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1280C4u;
            // 0x1280c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DB0u;
    if (runtime->hasFunction(0x141DB0u)) {
        auto targetFn = runtime->lookupFunction(0x141DB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141DB0_0x141db0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1280CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
