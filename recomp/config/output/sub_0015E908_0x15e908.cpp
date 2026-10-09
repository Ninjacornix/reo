#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E908
// Address: 0x15e908 - 0x15e930
void sub_0015E908_0x15e908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E908_0x15e908");
#endif

    switch (ctx->pc) {
        case 0x15e91cu: goto label_15e91c;
        default: break;
    }

    ctx->pc = 0x15e908u;

    // 0x15e908: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e90c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e910: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15e910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15e914: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15E914u;
    SET_GPR_U32(ctx, 31, 0x15E91Cu);
    ctx->pc = 0x15E918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E914u;
            // 0x15e918: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E91Cu; }
        if (ctx->pc != 0x15E91Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E91Cu; }
        if (ctx->pc != 0x15E91Cu) { return; }
    }
    ctx->pc = 0x15E91Cu;
label_15e91c:
    // 0x15e91c: 0xac500038  sw          $s0, 0x38($v0)
    ctx->pc = 0x15e91cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 16));
    // 0x15e920: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15e920u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e924: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e924u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e928: 0x3e00008  jr          $ra
    ctx->pc = 0x15E928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E928u;
            // 0x15e92c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E91Cu: goto label_15e91c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
