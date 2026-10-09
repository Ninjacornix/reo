#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00127690
// Address: 0x127690 - 0x1276d8
void sub_00127690_0x127690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00127690_0x127690");
#endif

    ctx->pc = 0x127690u;

    // 0x127690: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x127690u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x127694: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x127694u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127698: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127698u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x12769c: 0x8c43c7a8  lw          $v1, -0x3858($v0)
    ctx->pc = 0x12769cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294952872)));
    // 0x1276a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1276a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1276a4: 0xb6403  sra         $t4, $t3, 16
    ctx->pc = 0x1276a4u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 11), 16));
    // 0x1276a8: 0xa1403  sra         $v0, $t2, 16
    ctx->pc = 0x1276a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 10), 16));
    // 0x1276ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1276acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1276b0: 0x40502d  daddu       $t2, $v0, $zero
    ctx->pc = 0x1276b0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276b4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1276B4u;
    {
        const bool branch_taken_0x1276b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1276B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1276B4u;
            // 0x1276b8: 0x180582d  daddu       $t3, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1276b4) {
            ctx->pc = 0x1276C8u;
            goto label_1276c8;
        }
    }
    ctx->pc = 0x1276BCu;
    // 0x1276bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1276bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276c0: 0x8049c56  j           func_127158
    ctx->pc = 0x1276C0u;
    ctx->pc = 0x1276C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1276C0u;
            // 0x1276c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x127158u;
    if (runtime->hasFunction(0x127158u)) {
        auto targetFn = runtime->lookupFunction(0x127158u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00127158_0x127158(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1276C8u;
label_1276c8:
    // 0x1276c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1276c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276cc: 0x40502d  daddu       $t2, $v0, $zero
    ctx->pc = 0x1276ccu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276d0: 0x8049cfc  j           func_1273F0
    ctx->pc = 0x1276D0u;
    ctx->pc = 0x1276D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1276D0u;
            // 0x1276d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1273F0u;
    if (runtime->hasFunction(0x1273F0u)) {
        auto targetFn = runtime->lookupFunction(0x1273F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001273F0_0x1273f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1276D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
