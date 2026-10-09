#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EBA8
// Address: 0x13eba8 - 0x13ebd8
void sub_0013EBA8_0x13eba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EBA8_0x13eba8");
#endif

    switch (ctx->pc) {
        case 0x13ebc0u: goto label_13ebc0;
        default: break;
    }

    ctx->pc = 0x13eba8u;

    // 0x13eba8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13eba8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ebac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ebacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebb0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ebb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ebb4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13ebb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13ebb8: 0xc04faf6  jal         func_13EBD8
    ctx->pc = 0x13EBB8u;
    SET_GPR_U32(ctx, 31, 0x13EBC0u);
    ctx->pc = 0x13EBBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EBB8u;
            // 0x13ebbc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EBD8u;
    if (runtime->hasFunction(0x13EBD8u)) {
        auto targetFn = runtime->lookupFunction(0x13EBD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EBC0u; }
        if (ctx->pc != 0x13EBC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EBD8_0x13ebd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EBC0u; }
        if (ctx->pc != 0x13EBC0u) { return; }
    }
    ctx->pc = 0x13EBC0u;
label_13ebc0:
    // 0x13ebc0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13ebc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ebc4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13ebc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ebc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ebcc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ebccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebd0: 0x804fb14  j           func_13EC50
    ctx->pc = 0x13EBD0u;
    ctx->pc = 0x13EBD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EBD0u;
            // 0x13ebd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC50u;
    if (runtime->hasFunction(0x13EC50u)) {
        auto targetFn = runtime->lookupFunction(0x13EC50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EC50_0x13ec50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EBD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
