#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001226C0
// Address: 0x1226c0 - 0x122708
void sub_001226C0_0x1226c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001226C0_0x1226c0");
#endif

    switch (ctx->pc) {
        case 0x1226d8u: goto label_1226d8;
        default: break;
    }

    ctx->pc = 0x1226c0u;

    // 0x1226c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1226c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1226c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1226c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1226c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1226c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1226cc: 0x8048070  j           func_1201C0
    ctx->pc = 0x1226CCu;
    ctx->pc = 0x1226D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1226CCu;
            // 0x1226d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1201C0u;
    if (runtime->hasFunction(0x1201C0u)) {
        auto targetFn = runtime->lookupFunction(0x1201C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001201C0_0x1201c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1226D4u;
    // 0x1226d4: 0x0  nop
    ctx->pc = 0x1226d4u;
    // NOP
label_1226d8:
    // 0x1226d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1226d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1226dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1226dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1226e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1226e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1226e4: 0x8048138  j           func_1204E0
    ctx->pc = 0x1226E4u;
    ctx->pc = 0x1226E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1226E4u;
            // 0x1226e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1204E0u;
    if (runtime->hasFunction(0x1204E0u)) {
        auto targetFn = runtime->lookupFunction(0x1204E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001204E0_0x1204e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1226ECu;
    // 0x1226ec: 0x0  nop
    ctx->pc = 0x1226ecu;
    // NOP
    // 0x1226f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1226f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1226f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1226f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1226f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1226f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1226fc: 0x8048242  j           func_120908
    ctx->pc = 0x1226FCu;
    ctx->pc = 0x122700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1226FCu;
            // 0x122700: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x120908u;
    if (runtime->hasFunction(0x120908u)) {
        auto targetFn = runtime->lookupFunction(0x120908u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00120908_0x120908(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x122704u;
    // 0x122704: 0x0  nop
    ctx->pc = 0x122704u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
