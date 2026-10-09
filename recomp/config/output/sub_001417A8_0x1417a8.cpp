#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001417A8
// Address: 0x1417a8 - 0x141800
void sub_001417A8_0x1417a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001417A8_0x1417a8");
#endif

    ctx->pc = 0x1417a8u;

    // 0x1417a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1417a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1417ac: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1417acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1417b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1417b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1417b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1417b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1417b8: 0x8050590  j           func_141640
    ctx->pc = 0x1417B8u;
    ctx->pc = 0x1417BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1417B8u;
            // 0x1417bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141640u;
    if (runtime->hasFunction(0x141640u)) {
        auto targetFn = runtime->lookupFunction(0x141640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141640_0x141640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1417C0u;
    // 0x1417c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1417c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1417c4: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1417c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1417c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1417c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1417cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1417ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1417d0: 0x8050590  j           func_141640
    ctx->pc = 0x1417D0u;
    ctx->pc = 0x1417D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1417D0u;
            // 0x1417d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141640u;
    if (runtime->hasFunction(0x141640u)) {
        auto targetFn = runtime->lookupFunction(0x141640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141640_0x141640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1417D8u;
    // 0x1417d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1417d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1417dc: 0x240403e8  addiu       $a0, $zero, 0x3E8
    ctx->pc = 0x1417dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1417e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1417e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1417e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1417e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1417e8: 0x8050590  j           func_141640
    ctx->pc = 0x1417E8u;
    ctx->pc = 0x1417ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1417E8u;
            // 0x1417ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141640u;
    if (runtime->hasFunction(0x141640u)) {
        auto targetFn = runtime->lookupFunction(0x141640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141640_0x141640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1417F0u;
    // 0x1417f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1417f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1417f4: 0x2463a5f4  addiu       $v1, $v1, -0x5A0C
    ctx->pc = 0x1417f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944244));
    // 0x1417f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1417F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1417FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1417F8u;
            // 0x1417fc: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x141800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
