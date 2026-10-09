#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115868
// Address: 0x115868 - 0x11588c
void sub_00115868_0x115868(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115868_0x115868");
#endif

    switch (ctx->pc) {
        case 0x115880u: goto label_115880;
        default: break;
    }

    ctx->pc = 0x115868u;

    // 0x115868: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115868u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11586c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11586cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115870: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115870u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115874: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115878: 0xc045294  jal         func_114A50
    ctx->pc = 0x115878u;
    SET_GPR_U32(ctx, 31, 0x115880u);
    ctx->pc = 0x11587Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115878u;
            // 0x11587c: 0x24040021  addiu       $a0, $zero, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115880u; }
        if (ctx->pc != 0x115880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115880u; }
        if (ctx->pc != 0x115880u) { return; }
    }
    ctx->pc = 0x115880u;
label_115880:
    // 0x115880: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115884: 0x3e00008  jr          $ra
    ctx->pc = 0x115884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115884u;
            // 0x115888: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115880u: goto label_115880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11588Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
