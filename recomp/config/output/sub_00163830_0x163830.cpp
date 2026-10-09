#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163830
// Address: 0x163830 - 0x163854
void sub_00163830_0x163830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163830_0x163830");
#endif

    switch (ctx->pc) {
        case 0x163840u: goto label_163840;
        default: break;
    }

    ctx->pc = 0x163830u;

    // 0x163830: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163834: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163838: 0xc05d4b8  jal         func_1752E0
    ctx->pc = 0x163838u;
    SET_GPR_U32(ctx, 31, 0x163840u);
    ctx->pc = 0x1752E0u;
    if (runtime->hasFunction(0x1752E0u)) {
        auto targetFn = runtime->lookupFunction(0x1752E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163840u; }
        if (ctx->pc != 0x163840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752E0_0x1752e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163840u; }
        if (ctx->pc != 0x163840u) { return; }
    }
    ctx->pc = 0x163840u;
label_163840:
    // 0x163840: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x163840u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x163844: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163848: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x163848u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x16384c: 0x3e00008  jr          $ra
    ctx->pc = 0x16384Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16384Cu;
            // 0x163850: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163840u: goto label_163840;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163854u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
