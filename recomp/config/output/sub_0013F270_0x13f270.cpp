#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F270
// Address: 0x13f270 - 0x13f2c0
void sub_0013F270_0x13f270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F270_0x13f270");
#endif

    switch (ctx->pc) {
        case 0x13f288u: goto label_13f288;
        default: break;
    }

    ctx->pc = 0x13f270u;

    // 0x13f270: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f274: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f278: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f278u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f27c: 0x80505ba  j           func_1416E8
    ctx->pc = 0x13F27Cu;
    ctx->pc = 0x13F280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F27Cu;
            // 0x13f280: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F284u;
    // 0x13f284: 0x0  nop
    ctx->pc = 0x13f284u;
    // NOP
label_13f288:
    // 0x13f288: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f28c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f28cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f290: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f294: 0x805062a  j           func_1418A8
    ctx->pc = 0x13F294u;
    ctx->pc = 0x13F298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F294u;
            // 0x13f298: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001418A8_0x1418a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F29Cu;
    // 0x13f29c: 0x0  nop
    ctx->pc = 0x13f29cu;
    // NOP
    // 0x13f2a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f2a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f2a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f2a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f2a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f2a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f2ac: 0x2484da18  addiu       $a0, $a0, -0x25E8
    ctx->pc = 0x13f2acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957592));
    // 0x13f2b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f2b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f2b4: 0x804fca2  j           func_13F288
    ctx->pc = 0x13F2B4u;
    ctx->pc = 0x13F2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F2B4u;
            // 0x13f2b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F288u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_13f288;
    ctx->pc = 0x13F2BCu;
    // 0x13f2bc: 0x0  nop
    ctx->pc = 0x13f2bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
