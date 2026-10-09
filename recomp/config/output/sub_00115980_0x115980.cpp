#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115980
// Address: 0x115980 - 0x1159a8
void sub_00115980_0x115980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115980_0x115980");
#endif

    switch (ctx->pc) {
        case 0x115998u: goto label_115998;
        default: break;
    }

    ctx->pc = 0x115980u;

    // 0x115980: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115980u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115984: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x115984u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115988: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115988u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11598c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11598cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115990: 0xc045294  jal         func_114A50
    ctx->pc = 0x115990u;
    SET_GPR_U32(ctx, 31, 0x115998u);
    ctx->pc = 0x115994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115990u;
            // 0x115994: 0x24040010  addiu       $a0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115998u; }
        if (ctx->pc != 0x115998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115998u; }
        if (ctx->pc != 0x115998u) { return; }
    }
    ctx->pc = 0x115998u;
label_115998:
    // 0x115998: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115998u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11599c: 0x3e00008  jr          $ra
    ctx->pc = 0x11599Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1159A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11599Cu;
            // 0x1159a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115998u: goto label_115998;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1159A4u;
    // 0x1159a4: 0x0  nop
    ctx->pc = 0x1159a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
