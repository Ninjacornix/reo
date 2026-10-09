#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E58
// Address: 0x130e58 - 0x130e84
void sub_00130E58_0x130e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E58_0x130e58");
#endif

    switch (ctx->pc) {
        case 0x130e70u: goto label_130e70;
        default: break;
    }

    ctx->pc = 0x130e58u;

    // 0x130e58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130e5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130e60: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x130e60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130e64: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130e68: 0xc04d7d4  jal         func_135F50
    ctx->pc = 0x130E68u;
    SET_GPR_U32(ctx, 31, 0x130E70u);
    ctx->pc = 0x130E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130E68u;
            // 0x130e6c: 0x8c840008  lw          $a0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135F50u;
    if (runtime->hasFunction(0x135F50u)) {
        auto targetFn = runtime->lookupFunction(0x135F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130E70u; }
        if (ctx->pc != 0x130E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135F50_0x135f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130E70u; }
        if (ctx->pc != 0x130E70u) { return; }
    }
    ctx->pc = 0x130E70u;
label_130e70:
    // 0x130e70: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130e70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130e74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130e74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130e78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130e78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130e7c: 0x3e00008  jr          $ra
    ctx->pc = 0x130E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E7Cu;
            // 0x130e80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
