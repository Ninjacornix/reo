#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181ED8
// Address: 0x181ed8 - 0x181f14
void sub_00181ED8_0x181ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181ED8_0x181ed8");
#endif

    switch (ctx->pc) {
        case 0x181ee8u: goto label_181ee8;
        case 0x181f04u: goto label_181f04;
        default: break;
    }

    ctx->pc = 0x181ed8u;

    // 0x181ed8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181edc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181ee0: 0xc06048c  jal         func_181230
    ctx->pc = 0x181EE0u;
    SET_GPR_U32(ctx, 31, 0x181EE8u);
    ctx->pc = 0x181230u;
    if (runtime->hasFunction(0x181230u)) {
        auto targetFn = runtime->lookupFunction(0x181230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EE8u; }
        if (ctx->pc != 0x181EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181230_0x181230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181EE8u; }
        if (ctx->pc != 0x181EE8u) { return; }
    }
    ctx->pc = 0x181EE8u;
label_181ee8:
    // 0x181ee8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181ee8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181eec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181eecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181ef0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181ef0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181ef4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181EF4u;
    {
        const bool branch_taken_0x181ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181EF4u;
            // 0x181ef8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ef4) {
            ctx->pc = 0x181F08u;
            goto label_181f08;
        }
    }
    ctx->pc = 0x181EFCu;
    // 0x181efc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181EFCu;
    SET_GPR_U32(ctx, 31, 0x181F04u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F04u; }
        if (ctx->pc != 0x181F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181F04u; }
        if (ctx->pc != 0x181F04u) { return; }
    }
    ctx->pc = 0x181F04u;
label_181f04:
    // 0x181f04: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x181f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_181f08:
    // 0x181f08: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x181f08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x181F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181F0Cu;
            // 0x181f10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181EE8u: goto label_181ee8;
            case 0x181F04u: goto label_181f04;
            case 0x181F08u: goto label_181f08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181F14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
