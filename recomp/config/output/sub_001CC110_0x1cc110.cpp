#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC110
// Address: 0x1cc110 - 0x1cc140
void sub_001CC110_0x1cc110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC110_0x1cc110");
#endif

    switch (ctx->pc) {
        case 0x1cc130u: goto label_1cc130;
        default: break;
    }

    ctx->pc = 0x1cc110u;

    // 0x1cc110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc114: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc114u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc118: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1cc118u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1cc11c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc11cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc120: 0x2484b630  addiu       $a0, $a0, -0x49D0
    ctx->pc = 0x1cc120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
    // 0x1cc124: 0x24a5b230  addiu       $a1, $a1, -0x4DD0
    ctx->pc = 0x1cc124u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294947376));
    // 0x1cc128: 0xc071f34  jal         func_1C7CD0
    ctx->pc = 0x1CC128u;
    SET_GPR_U32(ctx, 31, 0x1CC130u);
    ctx->pc = 0x1CC12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC128u;
            // 0x1cc12c: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CD0u;
    if (runtime->hasFunction(0x1C7CD0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC130u; }
        if (ctx->pc != 0x1CC130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CD0_0x1c7cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC130u; }
        if (ctx->pc != 0x1CC130u) { return; }
    }
    ctx->pc = 0x1CC130u;
label_1cc130:
    // 0x1cc130: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc130u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc134: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cc134u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc138: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC13Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC138u;
            // 0x1cc13c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC130u: goto label_1cc130;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
