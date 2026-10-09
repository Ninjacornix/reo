#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115958
// Address: 0x115958 - 0x11597c
void sub_00115958_0x115958(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115958_0x115958");
#endif

    switch (ctx->pc) {
        case 0x115970u: goto label_115970;
        default: break;
    }

    ctx->pc = 0x115958u;

    // 0x115958: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115958u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11595c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11595cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115960: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115964: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115968: 0xc045294  jal         func_114A50
    ctx->pc = 0x115968u;
    SET_GPR_U32(ctx, 31, 0x115970u);
    ctx->pc = 0x11596Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115968u;
            // 0x11596c: 0x2404fff7  addiu       $a0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115970u; }
        if (ctx->pc != 0x115970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115970u; }
        if (ctx->pc != 0x115970u) { return; }
    }
    ctx->pc = 0x115970u;
label_115970:
    // 0x115970: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115970u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115974: 0x3e00008  jr          $ra
    ctx->pc = 0x115974u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115974u;
            // 0x115978: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115970u: goto label_115970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11597Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
