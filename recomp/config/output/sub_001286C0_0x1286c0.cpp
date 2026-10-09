#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001286C0
// Address: 0x1286c0 - 0x128710
void sub_001286C0_0x1286c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001286C0_0x1286c0");
#endif

    ctx->pc = 0x1286c0u;

    // 0x1286c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1286c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1286c4: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x1286c4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x1286c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1286c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1286cc: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1286ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1286d0: 0x2508d2d0  addiu       $t0, $t0, -0x2D30
    ctx->pc = 0x1286d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294955728));
    // 0x1286d4: 0x24090800  addiu       $t1, $zero, 0x800
    ctx->pc = 0x1286d4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1286d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1286d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1286dc: 0x1024024  and         $t0, $t0, $v0
    ctx->pc = 0x1286dcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x1286e0: 0x804a1d8  j           func_128760
    ctx->pc = 0x1286E0u;
    ctx->pc = 0x1286E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1286E0u;
            // 0x1286e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128760u;
    if (runtime->hasFunction(0x128760u)) {
        auto targetFn = runtime->lookupFunction(0x128760u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00128760_0x128760(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1286E8u;
    // 0x1286e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1286e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1286ec: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x1286ecu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x1286f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1286f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1286f4: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1286f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1286f8: 0x2508d2d0  addiu       $t0, $t0, -0x2D30
    ctx->pc = 0x1286f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294955728));
    // 0x1286fc: 0x24090800  addiu       $t1, $zero, 0x800
    ctx->pc = 0x1286fcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x128700: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128700u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128704: 0x1024024  and         $t0, $t0, $v0
    ctx->pc = 0x128704u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x128708: 0x804a1ea  j           func_1287A8
    ctx->pc = 0x128708u;
    ctx->pc = 0x12870Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128708u;
            // 0x12870c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1287A8u;
    if (runtime->hasFunction(0x1287A8u)) {
        auto targetFn = runtime->lookupFunction(0x1287A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001287A8_0x1287a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128710u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
