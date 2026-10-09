#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128710
// Address: 0x128710 - 0x128738
void sub_00128710_0x128710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128710_0x128710");
#endif

    ctx->pc = 0x128710u;

    // 0x128710: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128714: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x128714u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x128718: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12871c: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x12871cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x128720: 0x2508d2d0  addiu       $t0, $t0, -0x2D30
    ctx->pc = 0x128720u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294955728));
    // 0x128724: 0x24090800  addiu       $t1, $zero, 0x800
    ctx->pc = 0x128724u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x128728: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12872c: 0x1024024  and         $t0, $t0, $v0
    ctx->pc = 0x12872cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x128730: 0x804a1f8  j           func_1287E0
    ctx->pc = 0x128730u;
    ctx->pc = 0x128734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128730u;
            // 0x128734: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1287E0u;
    if (runtime->hasFunction(0x1287E0u)) {
        auto targetFn = runtime->lookupFunction(0x1287E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001287E0_0x1287e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128738u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
