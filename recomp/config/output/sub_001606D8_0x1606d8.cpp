#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001606D8
// Address: 0x1606d8 - 0x16070c
void sub_001606D8_0x1606d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001606D8_0x1606d8");
#endif

    ctx->pc = 0x1606d8u;

    // 0x1606d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1606d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1606dc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1606dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1606e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1606e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1606e4: 0x24050025  addiu       $a1, $zero, 0x25
    ctx->pc = 0x1606e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1606e8: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1606E8u;
    {
        const bool branch_taken_0x1606e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1606ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1606E8u;
            // 0x1606ec: 0x8c820040  lw          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1606e8) {
            ctx->pc = 0x160700u;
            goto label_160700;
        }
    }
    ctx->pc = 0x1606F0u;
    // 0x1606f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1606f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1606f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1606f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1606f8: 0x805d4ce  j           func_175338
    ctx->pc = 0x1606F8u;
    ctx->pc = 0x1606FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1606F8u;
            // 0x1606fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160700u;
label_160700:
    // 0x160700: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160700u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160704: 0x3e00008  jr          $ra
    ctx->pc = 0x160704u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160704u;
            // 0x160708: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160700u: goto label_160700;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16070Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
