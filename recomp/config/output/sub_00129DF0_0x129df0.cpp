#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129DF0
// Address: 0x129df0 - 0x129e18
void sub_00129DF0_0x129df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129DF0_0x129df0");
#endif

    switch (ctx->pc) {
        case 0x129e0cu: goto label_129e0c;
        default: break;
    }

    ctx->pc = 0x129df0u;

    // 0x129df0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x129df4: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x129df4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129df8: 0x100482d  daddu       $t1, $t0, $zero
    ctx->pc = 0x129df8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129dfc: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x129dfcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e00: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x129e00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x129e04: 0xc04a786  jal         func_129E18
    ctx->pc = 0x129E04u;
    SET_GPR_U32(ctx, 31, 0x129E0Cu);
    ctx->pc = 0x129E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129E04u;
            // 0x129e08: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E0Cu; }
        if (ctx->pc != 0x129E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E0Cu; }
        if (ctx->pc != 0x129E0Cu) { return; }
    }
    ctx->pc = 0x129E0Cu;
label_129e0c:
    // 0x129e0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x129e0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129e10: 0x3e00008  jr          $ra
    ctx->pc = 0x129E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129E10u;
            // 0x129e14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129E0Cu: goto label_129e0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129E18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
