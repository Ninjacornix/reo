#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E440
// Address: 0x19e440 - 0x19e490
void sub_0019E440_0x19e440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E440_0x19e440");
#endif

    switch (ctx->pc) {
        case 0x19e468u: goto label_19e468;
        case 0x19e478u: goto label_19e478;
        default: break;
    }

    ctx->pc = 0x19e440u;

    // 0x19e440: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19e440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19e444: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19e444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19e448: 0x11020009  beq         $t0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x19E448u;
    {
        const bool branch_taken_0x19e448 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 2));
        ctx->pc = 0x19E44Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E448u;
            // 0x19e44c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e448) {
            ctx->pc = 0x19E470u;
            goto label_19e470;
        }
    }
    ctx->pc = 0x19E450u;
    // 0x19e450: 0x11000003  beqz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E450u;
    {
        const bool branch_taken_0x19e450 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x19e450) {
            ctx->pc = 0x19E460u;
            goto label_19e460;
        }
    }
    ctx->pc = 0x19E458u;
    // 0x19e458: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19E458u;
    {
        const bool branch_taken_0x19e458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E458u;
            // 0x19e45c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e458) {
            ctx->pc = 0x19E47Cu;
            goto label_19e47c;
        }
    }
    ctx->pc = 0x19E460u;
label_19e460:
    // 0x19e460: 0xc067924  jal         func_19E490
    ctx->pc = 0x19E460u;
    SET_GPR_U32(ctx, 31, 0x19E468u);
    ctx->pc = 0x19E490u;
    if (runtime->hasFunction(0x19E490u)) {
        auto targetFn = runtime->lookupFunction(0x19E490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E468u; }
        if (ctx->pc != 0x19E468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E490_0x19e490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E468u; }
        if (ctx->pc != 0x19E468u) { return; }
    }
    ctx->pc = 0x19E468u;
label_19e468:
    // 0x19e468: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x19E468u;
    {
        const bool branch_taken_0x19e468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E468u;
            // 0x19e46c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e468) {
            ctx->pc = 0x19E47Cu;
            goto label_19e47c;
        }
    }
    ctx->pc = 0x19E470u;
label_19e470:
    // 0x19e470: 0xc0679f4  jal         func_19E7D0
    ctx->pc = 0x19E470u;
    SET_GPR_U32(ctx, 31, 0x19E478u);
    ctx->pc = 0x19E7D0u;
    if (runtime->hasFunction(0x19E7D0u)) {
        auto targetFn = runtime->lookupFunction(0x19E7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E478u; }
        if (ctx->pc != 0x19E478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E7D0_0x19e7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E478u; }
        if (ctx->pc != 0x19E478u) { return; }
    }
    ctx->pc = 0x19E478u;
label_19e478:
    // 0x19e478: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x19e478u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19e47c:
    // 0x19e47c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19e47cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e480: 0x3e00008  jr          $ra
    ctx->pc = 0x19E480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E480u;
            // 0x19e484: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E460u: goto label_19e460;
            case 0x19E468u: goto label_19e468;
            case 0x19E470u: goto label_19e470;
            case 0x19E478u: goto label_19e478;
            case 0x19E47Cu: goto label_19e47c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E488u;
    // 0x19e488: 0x0  nop
    ctx->pc = 0x19e488u;
    // NOP
    // 0x19e48c: 0x0  nop
    ctx->pc = 0x19e48cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
