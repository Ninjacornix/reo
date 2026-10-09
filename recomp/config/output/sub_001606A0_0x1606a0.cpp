#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001606A0
// Address: 0x1606a0 - 0x1606d4
void sub_001606A0_0x1606a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001606A0_0x1606a0");
#endif

    ctx->pc = 0x1606a0u;

    // 0x1606a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1606a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1606a4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1606a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1606a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1606a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1606ac: 0x24050024  addiu       $a1, $zero, 0x24
    ctx->pc = 0x1606acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1606b0: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1606B0u;
    {
        const bool branch_taken_0x1606b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1606B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1606B0u;
            // 0x1606b4: 0x8c820040  lw          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1606b0) {
            ctx->pc = 0x1606C8u;
            goto label_1606c8;
        }
    }
    ctx->pc = 0x1606B8u;
    // 0x1606b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1606b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1606bc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1606bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1606c0: 0x805d4ce  j           func_175338
    ctx->pc = 0x1606C0u;
    ctx->pc = 0x1606C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1606C0u;
            // 0x1606c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1606C8u;
label_1606c8:
    // 0x1606c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1606c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1606cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1606CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1606D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1606CCu;
            // 0x1606d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1606C8u: goto label_1606c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1606D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
