#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC550
// Address: 0x1cc550 - 0x1cc5b0
void sub_001CC550_0x1cc550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC550_0x1cc550");
#endif

    switch (ctx->pc) {
        case 0x1cc598u: goto label_1cc598;
        default: break;
    }

    ctx->pc = 0x1cc550u;

    // 0x1cc550: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc550u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc554: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cc554u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cc558: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc558u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc55c: 0x24630a40  addiu       $v1, $v1, 0xA40
    ctx->pc = 0x1cc55cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2624));
    // 0x1cc560: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc564: 0xac230a20  sw          $v1, 0xA20($at)
    ctx->pc = 0x1cc564u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2592), GPR_U32(ctx, 3));
    // 0x1cc568: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc56c: 0x8c240a20  lw          $a0, 0xA20($at)
    ctx->pc = 0x1cc56cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2592)));
    // 0x1cc570: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CC570u;
    {
        const bool branch_taken_0x1cc570 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc570) {
            ctx->pc = 0x1CC598u;
            goto label_1cc598;
        }
    }
    ctx->pc = 0x1CC578u;
    // 0x1cc578: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1cc578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1cc57c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CC57Cu;
    {
        const bool branch_taken_0x1cc57c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc57c) {
            ctx->pc = 0x1CC598u;
            goto label_1cc598;
        }
    }
    ctx->pc = 0x1CC584u;
    // 0x1cc584: 0x8c830084  lw          $v1, 0x84($a0)
    ctx->pc = 0x1cc584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 132)));
    // 0x1cc588: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC588u;
    {
        const bool branch_taken_0x1cc588 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc588) {
            ctx->pc = 0x1CC598u;
            goto label_1cc598;
        }
    }
    ctx->pc = 0x1CC590u;
    // 0x1cc590: 0xc07316c  jal         func_1CC5B0
    ctx->pc = 0x1CC590u;
    SET_GPR_U32(ctx, 31, 0x1CC598u);
    ctx->pc = 0x1CC5B0u;
    if (runtime->hasFunction(0x1CC5B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC598u; }
        if (ctx->pc != 0x1CC598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC5B0_0x1cc5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC598u; }
        if (ctx->pc != 0x1CC598u) { return; }
    }
    ctx->pc = 0x1CC598u;
label_1cc598:
    // 0x1cc598: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc598u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc59c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC59Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC5A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC59Cu;
            // 0x1cc5a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC598u: goto label_1cc598;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC5A4u;
    // 0x1cc5a4: 0x0  nop
    ctx->pc = 0x1cc5a4u;
    // NOP
    // 0x1cc5a8: 0x0  nop
    ctx->pc = 0x1cc5a8u;
    // NOP
    // 0x1cc5ac: 0x0  nop
    ctx->pc = 0x1cc5acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
