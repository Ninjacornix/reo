#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181E98
// Address: 0x181e98 - 0x181ed4
void sub_00181E98_0x181e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181E98_0x181e98");
#endif

    switch (ctx->pc) {
        case 0x181ea8u: goto label_181ea8;
        case 0x181ec4u: goto label_181ec4;
        default: break;
    }

    ctx->pc = 0x181e98u;

    // 0x181e98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181e9c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181ea0: 0xc0603f8  jal         func_180FE0
    ctx->pc = 0x181EA0u;
    SET_GPR_U32(ctx, 31, 0x181EA8u);
    ctx->pc = 0x180FE0u;
    if (runtime->hasFunction(0x180FE0u)) {
        auto targetFn = runtime->lookupFunction(0x180FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EA8u; }
        if (ctx->pc != 0x181EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180FE0_0x180fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EA8u; }
        if (ctx->pc != 0x181EA8u) { return; }
    }
    ctx->pc = 0x181EA8u;
label_181ea8:
    // 0x181ea8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181ea8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181eacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181eb0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181eb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eb4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181EB4u;
    {
        const bool branch_taken_0x181eb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181EB4u;
            // 0x181eb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181eb4) {
            ctx->pc = 0x181EC8u;
            goto label_181ec8;
        }
    }
    ctx->pc = 0x181EBCu;
    // 0x181ebc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181EBCu;
    SET_GPR_U32(ctx, 31, 0x181EC4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EC4u; }
        if (ctx->pc != 0x181EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EC4u; }
        if (ctx->pc != 0x181EC4u) { return; }
    }
    ctx->pc = 0x181EC4u;
label_181ec4:
    // 0x181ec4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181ec8:
    // 0x181ec8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x181ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181ECCu;
            // 0x181ed0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181EA8u: goto label_181ea8;
            case 0x181EC4u: goto label_181ec4;
            case 0x181EC8u: goto label_181ec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181ED4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
