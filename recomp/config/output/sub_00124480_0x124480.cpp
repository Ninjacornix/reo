#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124480
// Address: 0x124480 - 0x1244c0
void sub_00124480_0x124480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124480_0x124480");
#endif

    ctx->pc = 0x124480u;

    // 0x124480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124484: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124488: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x124488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12448c: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x12448cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x124490: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x124490u;
    {
        const bool branch_taken_0x124490 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124490u;
            // 0x124494: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124490) {
            ctx->pc = 0x1244A8u;
            goto label_1244a8;
        }
    }
    ctx->pc = 0x124498u;
    // 0x124498: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x124498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12449c: 0x80490b6  j           func_1242D8
    ctx->pc = 0x12449Cu;
    ctx->pc = 0x1244A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12449Cu;
            // 0x1244a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1242D8u;
    if (runtime->hasFunction(0x1242D8u)) {
        auto targetFn = runtime->lookupFunction(0x1242D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001242D8_0x1242d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1244A4u;
    // 0x1244a4: 0x0  nop
    ctx->pc = 0x1244a4u;
    // NOP
label_1244a8:
    // 0x1244a8: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1244A8u;
    {
        const bool branch_taken_0x1244a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1244ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244A8u;
            // 0x1244ac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1244a8) {
            ctx->pc = 0x1244B8u;
            goto label_1244b8;
        }
    }
    ctx->pc = 0x1244B0u;
    // 0x1244b0: 0x8049056  j           func_124158
    ctx->pc = 0x1244B0u;
    ctx->pc = 0x1244B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1244B0u;
            // 0x1244b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124158u;
    if (runtime->hasFunction(0x124158u)) {
        auto targetFn = runtime->lookupFunction(0x124158u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124158_0x124158(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1244B8u;
label_1244b8:
    // 0x1244b8: 0x8048ff0  j           func_123FC0
    ctx->pc = 0x1244B8u;
    ctx->pc = 0x1244BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1244B8u;
            // 0x1244bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123FC0u;
    if (runtime->hasFunction(0x123FC0u)) {
        auto targetFn = runtime->lookupFunction(0x123FC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123FC0_0x123fc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1244C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
