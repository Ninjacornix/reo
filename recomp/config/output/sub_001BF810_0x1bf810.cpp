#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BF810
// Address: 0x1bf810 - 0x1bf840
void sub_001BF810_0x1bf810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BF810_0x1bf810");
#endif

    switch (ctx->pc) {
        case 0x1bf828u: goto label_1bf828;
        default: break;
    }

    ctx->pc = 0x1bf810u;

    // 0x1bf810: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1bf810u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bf814: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bf814u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bf818: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bf818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bf81c: 0x24440018  addiu       $a0, $v0, 0x18
    ctx->pc = 0x1bf81cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x1bf820: 0xc060772  jal         func_181DC8
    ctx->pc = 0x1BF820u;
    SET_GPR_U32(ctx, 31, 0x1BF828u);
    ctx->pc = 0x1BF824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF820u;
            // 0x1bf824: 0x2445001c  addiu       $a1, $v0, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181DC8u;
    if (runtime->hasFunction(0x181DC8u)) {
        auto targetFn = runtime->lookupFunction(0x181DC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF828u; }
        if (ctx->pc != 0x1BF828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181DC8_0x181dc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF828u; }
        if (ctx->pc != 0x1BF828u) { return; }
    }
    ctx->pc = 0x1BF828u;
label_1bf828:
    // 0x1bf828: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bf828u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bf82c: 0x401026  xor         $v0, $v0, $zero
    ctx->pc = 0x1bf82cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 0));
    // 0x1bf830: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1bf830u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1bf834: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1bf834u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1bf838: 0x3e00008  jr          $ra
    ctx->pc = 0x1BF838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BF83Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF838u;
            // 0x1bf83c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BF828u: goto label_1bf828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BF840u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
