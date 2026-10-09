#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149218
// Address: 0x149218 - 0x149240
void sub_00149218_0x149218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149218_0x149218");
#endif

    switch (ctx->pc) {
        case 0x14922cu: goto label_14922c;
        default: break;
    }

    ctx->pc = 0x149218u;

    // 0x149218: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x149218u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14921c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14921cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x149220: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x149220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x149224: 0xc052482  jal         func_149208
    ctx->pc = 0x149224u;
    SET_GPR_U32(ctx, 31, 0x14922Cu);
    ctx->pc = 0x149228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149224u;
            // 0x149228: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149208u;
    if (runtime->hasFunction(0x149208u)) {
        auto targetFn = runtime->lookupFunction(0x149208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14922Cu; }
        if (ctx->pc != 0x14922Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149208_0x149208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14922Cu; }
        if (ctx->pc != 0x14922Cu) { return; }
    }
    ctx->pc = 0x14922Cu;
label_14922c:
    // 0x14922c: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x14922cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x149230: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x149230u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x149234: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x149234u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x149238: 0x3e00008  jr          $ra
    ctx->pc = 0x149238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14923Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149238u;
            // 0x14923c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14922Cu: goto label_14922c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149240u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
