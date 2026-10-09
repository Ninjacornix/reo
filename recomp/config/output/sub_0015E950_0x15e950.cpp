#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E950
// Address: 0x15e950 - 0x15e978
void sub_0015E950_0x15e950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E950_0x15e950");
#endif

    switch (ctx->pc) {
        case 0x15e964u: goto label_15e964;
        default: break;
    }

    ctx->pc = 0x15e950u;

    // 0x15e950: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e954: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e958: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15e958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15e95c: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15E95Cu;
    SET_GPR_U32(ctx, 31, 0x15E964u);
    ctx->pc = 0x15E960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E95Cu;
            // 0x15e960: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E964u; }
        if (ctx->pc != 0x15E964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E964u; }
        if (ctx->pc != 0x15E964u) { return; }
    }
    ctx->pc = 0x15E964u;
label_15e964:
    // 0x15e964: 0xac50003c  sw          $s0, 0x3C($v0)
    ctx->pc = 0x15e964u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 16));
    // 0x15e968: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15e968u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e96c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e96cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e970: 0x3e00008  jr          $ra
    ctx->pc = 0x15E970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E970u;
            // 0x15e974: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E964u: goto label_15e964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E978u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
