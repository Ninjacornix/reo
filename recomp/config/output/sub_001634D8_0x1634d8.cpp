#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001634D8
// Address: 0x1634d8 - 0x163508
void sub_001634D8_0x1634d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001634D8_0x1634d8");
#endif

    switch (ctx->pc) {
        case 0x1634f4u: goto label_1634f4;
        default: break;
    }

    ctx->pc = 0x1634d8u;

    // 0x1634d8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1634d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1634dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1634e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1634e4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1634e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1634e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1634ec: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x1634ECu;
    SET_GPR_U32(ctx, 31, 0x1634F4u);
    ctx->pc = 0x1634F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1634ECu;
            // 0x1634f0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1634F4u; }
        if (ctx->pc != 0x1634F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1634F4u; }
        if (ctx->pc != 0x1634F4u) { return; }
    }
    ctx->pc = 0x1634F4u;
label_1634f4:
    // 0x1634f4: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1634f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1634f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1634f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1634fc: 0xac620740  sw          $v0, 0x740($v1)
    ctx->pc = 0x1634fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1856), GPR_U32(ctx, 2));
    // 0x163500: 0x3e00008  jr          $ra
    ctx->pc = 0x163500u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163500u;
            // 0x163504: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1634F4u: goto label_1634f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163508u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
