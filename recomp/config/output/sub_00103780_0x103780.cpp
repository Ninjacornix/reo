#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103780
// Address: 0x103780 - 0x1037a8
void sub_00103780_0x103780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103780_0x103780");
#endif

    switch (ctx->pc) {
        case 0x103794u: goto label_103794;
        default: break;
    }

    ctx->pc = 0x103780u;

    // 0x103780: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x103780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x103784: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x103784u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103788: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x103788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10378c: 0xc0432c6  jal         func_10CB18
    ctx->pc = 0x10378Cu;
    SET_GPR_U32(ctx, 31, 0x103794u);
    ctx->pc = 0x103790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10378Cu;
            // 0x103790: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CB18u;
    if (runtime->hasFunction(0x10CB18u)) {
        auto targetFn = runtime->lookupFunction(0x10CB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103794u; }
        if (ctx->pc != 0x103794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CB18_0x10cb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103794u; }
        if (ctx->pc != 0x103794u) { return; }
    }
    ctx->pc = 0x103794u;
label_103794:
    // 0x103794: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x103794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103798: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x103798u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10379c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10379cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1037a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1037A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1037A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1037A0u;
            // 0x1037a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103794u: goto label_103794;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1037A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
