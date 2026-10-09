#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155B90
// Address: 0x155b90 - 0x155bc4
void sub_00155B90_0x155b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155B90_0x155b90");
#endif

    switch (ctx->pc) {
        case 0x155ba0u: goto label_155ba0;
        default: break;
    }

    ctx->pc = 0x155b90u;

    // 0x155b90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155b90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155b94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155b94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155b98: 0xc0556f2  jal         func_155BC8
    ctx->pc = 0x155B98u;
    SET_GPR_U32(ctx, 31, 0x155BA0u);
    ctx->pc = 0x155BC8u;
    if (runtime->hasFunction(0x155BC8u)) {
        auto targetFn = runtime->lookupFunction(0x155BC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155BA0u; }
        if (ctx->pc != 0x155BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155BC8_0x155bc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155BA0u; }
        if (ctx->pc != 0x155BA0u) { return; }
    }
    ctx->pc = 0x155BA0u;
label_155ba0:
    // 0x155ba0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x155ba0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155ba4: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x155BA4u;
    {
        const bool branch_taken_0x155ba4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x155BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BA4u;
            // 0x155ba8: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155ba4) {
            ctx->pc = 0x155BB8u;
            goto label_155bb8;
        }
    }
    ctx->pc = 0x155BACu;
    // 0x155bac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155bacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155bb0: 0x8055706  j           func_155C18
    ctx->pc = 0x155BB0u;
    ctx->pc = 0x155BB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155BB0u;
            // 0x155bb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155C18u;
    if (runtime->hasFunction(0x155C18u)) {
        auto targetFn = runtime->lookupFunction(0x155C18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00155C18_0x155c18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155BB8u;
label_155bb8:
    // 0x155bb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155bb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x155BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BBCu;
            // 0x155bc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BA0u: goto label_155ba0;
            case 0x155BB8u: goto label_155bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155BC4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
