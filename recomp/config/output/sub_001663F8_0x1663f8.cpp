#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001663F8
// Address: 0x1663f8 - 0x166428
void sub_001663F8_0x1663f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001663F8_0x1663f8");
#endif

    switch (ctx->pc) {
        case 0x16640cu: goto label_16640c;
        case 0x166414u: goto label_166414;
        default: break;
    }

    ctx->pc = 0x1663f8u;

    // 0x1663f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1663f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1663fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1663fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166400: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166404: 0xc05990a  jal         func_166428
    ctx->pc = 0x166404u;
    SET_GPR_U32(ctx, 31, 0x16640Cu);
    ctx->pc = 0x166408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166404u;
            // 0x166408: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166428u;
    if (runtime->hasFunction(0x166428u)) {
        auto targetFn = runtime->lookupFunction(0x166428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16640Cu; }
        if (ctx->pc != 0x16640Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166428_0x166428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16640Cu; }
        if (ctx->pc != 0x16640Cu) { return; }
    }
    ctx->pc = 0x16640Cu;
label_16640c:
    // 0x16640c: 0xc059926  jal         func_166498
    ctx->pc = 0x16640Cu;
    SET_GPR_U32(ctx, 31, 0x166414u);
    ctx->pc = 0x166410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16640Cu;
            // 0x166410: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166498u;
    if (runtime->hasFunction(0x166498u)) {
        auto targetFn = runtime->lookupFunction(0x166498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166414u; }
        if (ctx->pc != 0x166414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166498_0x166498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166414u; }
        if (ctx->pc != 0x166414u) { return; }
    }
    ctx->pc = 0x166414u;
label_166414:
    // 0x166414: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166414u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166418: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16641c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16641cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166420: 0x3e00008  jr          $ra
    ctx->pc = 0x166420u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166420u;
            // 0x166424: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166428u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
