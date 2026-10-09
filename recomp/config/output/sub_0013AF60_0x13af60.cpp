#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AF60
// Address: 0x13af60 - 0x13af98
void sub_0013AF60_0x13af60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AF60_0x13af60");
#endif

    switch (ctx->pc) {
        case 0x13af7cu: goto label_13af7c;
        case 0x13af84u: goto label_13af84;
        default: break;
    }

    ctx->pc = 0x13af60u;

    // 0x13af60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13af60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13af64: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13af64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13af68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13af68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13af6c: 0x2442da78  addiu       $v0, $v0, -0x2588
    ctx->pc = 0x13af6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957688));
    // 0x13af70: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13af70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13af74: 0xc04f286  jal         func_13CA18
    ctx->pc = 0x13AF74u;
    SET_GPR_U32(ctx, 31, 0x13AF7Cu);
    ctx->pc = 0x13AF78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AF74u;
            // 0x13af78: 0x8c430000  lw          $v1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AF7Cu; }
        if (ctx->pc != 0x13AF7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CA18_0x13ca18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AF7Cu; }
        if (ctx->pc != 0x13AF7Cu) { return; }
    }
    ctx->pc = 0x13AF7Cu;
label_13af7c:
    // 0x13af7c: 0xc04f2aa  jal         func_13CAA8
    ctx->pc = 0x13AF7Cu;
    SET_GPR_U32(ctx, 31, 0x13AF84u);
    ctx->pc = 0x13AF80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AF7Cu;
            // 0x13af80: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CAA8u;
    if (runtime->hasFunction(0x13CAA8u)) {
        auto targetFn = runtime->lookupFunction(0x13CAA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AF84u; }
        if (ctx->pc != 0x13AF84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CAA8_0x13caa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AF84u; }
        if (ctx->pc != 0x13AF84u) { return; }
    }
    ctx->pc = 0x13AF84u;
label_13af84:
    // 0x13af84: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13af84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13af88: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13af88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13af8c: 0x2442da88  addiu       $v0, $v0, -0x2578
    ctx->pc = 0x13af8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957704));
    // 0x13af90: 0x3e00008  jr          $ra
    ctx->pc = 0x13AF90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AF90u;
            // 0x13af94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AF7Cu: goto label_13af7c;
            case 0x13AF84u: goto label_13af84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AF98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
