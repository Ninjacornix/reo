#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001583F0
// Address: 0x1583f0 - 0x158428
void sub_001583F0_0x1583f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001583F0_0x1583f0");
#endif

    switch (ctx->pc) {
        case 0x158400u: goto label_158400;
        default: break;
    }

    ctx->pc = 0x1583f0u;

    // 0x1583f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1583f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1583f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1583f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1583f8: 0xc05610a  jal         func_158428
    ctx->pc = 0x1583F8u;
    SET_GPR_U32(ctx, 31, 0x158400u);
    ctx->pc = 0x158428u;
    if (runtime->hasFunction(0x158428u)) {
        auto targetFn = runtime->lookupFunction(0x158428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158400u; }
        if (ctx->pc != 0x158400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158428_0x158428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158400u; }
        if (ctx->pc != 0x158400u) { return; }
    }
    ctx->pc = 0x158400u;
label_158400:
    // 0x158400: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x158400u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158404: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x158404u;
    {
        const bool branch_taken_0x158404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x158408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158404u;
            // 0x158408: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158404) {
            ctx->pc = 0x158418u;
            goto label_158418;
        }
    }
    ctx->pc = 0x15840Cu;
    // 0x15840c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15840cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158410: 0x8056120  j           func_158480
    ctx->pc = 0x158410u;
    ctx->pc = 0x158414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158410u;
            // 0x158414: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158480u;
    if (runtime->hasFunction(0x158480u)) {
        auto targetFn = runtime->lookupFunction(0x158480u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158480_0x158480(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x158418u;
label_158418:
    // 0x158418: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x158418u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15841c: 0x3e00008  jr          $ra
    ctx->pc = 0x15841Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15841Cu;
            // 0x158420: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158400u: goto label_158400;
            case 0x158418u: goto label_158418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158424u;
    // 0x158424: 0x0  nop
    ctx->pc = 0x158424u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
