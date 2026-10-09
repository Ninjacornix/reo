#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130EF0
// Address: 0x130ef0 - 0x130f1c
void sub_00130EF0_0x130ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130EF0_0x130ef0");
#endif

    switch (ctx->pc) {
        case 0x130f04u: goto label_130f04;
        default: break;
    }

    ctx->pc = 0x130ef0u;

    // 0x130ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130ef4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130ef8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130efc: 0xc04d7ee  jal         func_135FB8
    ctx->pc = 0x130EFCu;
    SET_GPR_U32(ctx, 31, 0x130F04u);
    ctx->pc = 0x130F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130EFCu;
            // 0x130f00: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135FB8u;
    if (runtime->hasFunction(0x135FB8u)) {
        auto targetFn = runtime->lookupFunction(0x135FB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F04u; }
        if (ctx->pc != 0x130F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135FB8_0x135fb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F04u; }
        if (ctx->pc != 0x130F04u) { return; }
    }
    ctx->pc = 0x130F04u;
label_130f04:
    // 0x130f04: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130f04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130f08: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130f08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130f0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130f0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130f10: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130f10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130f14: 0x3e00008  jr          $ra
    ctx->pc = 0x130F14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130F14u;
            // 0x130f18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130F1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
