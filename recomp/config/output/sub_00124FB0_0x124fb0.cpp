#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124FB0
// Address: 0x124fb0 - 0x124ff0
void sub_00124FB0_0x124fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124FB0_0x124fb0");
#endif

    switch (ctx->pc) {
        case 0x124fd0u: goto label_124fd0;
        default: break;
    }

    ctx->pc = 0x124fb0u;

    // 0x124fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124fb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124fb8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124fb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124fbc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x124fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124fc0: 0x260500a8  addiu       $a1, $s0, 0xA8
    ctx->pc = 0x124fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 168));
    // 0x124fc4: 0x260600ac  addiu       $a2, $s0, 0xAC
    ctx->pc = 0x124fc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 172));
    // 0x124fc8: 0xc04d3b6  jal         func_134ED8
    ctx->pc = 0x124FC8u;
    SET_GPR_U32(ctx, 31, 0x124FD0u);
    ctx->pc = 0x124FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FC8u;
            // 0x124fcc: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134ED8u;
    if (runtime->hasFunction(0x134ED8u)) {
        auto targetFn = runtime->lookupFunction(0x134ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124FD0u; }
        if (ctx->pc != 0x124FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134ED8_0x134ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124FD0u; }
        if (ctx->pc != 0x124FD0u) { return; }
    }
    ctx->pc = 0x124FD0u;
label_124fd0:
    // 0x124fd0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124fd4: 0x860700a6  lh          $a3, 0xA6($s0)
    ctx->pc = 0x124fd4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 166)));
    // 0x124fd8: 0x860500a2  lh          $a1, 0xA2($s0)
    ctx->pc = 0x124fd8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 162)));
    // 0x124fdc: 0x860600a4  lh          $a2, 0xA4($s0)
    ctx->pc = 0x124fdcu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 164)));
    // 0x124fe0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x124fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fe4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124fe4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fe8: 0x804d3ca  j           func_134F28
    ctx->pc = 0x124FE8u;
    ctx->pc = 0x124FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FE8u;
            // 0x124fec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F28u;
    if (runtime->hasFunction(0x134F28u)) {
        auto targetFn = runtime->lookupFunction(0x134F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00134F28_0x134f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124FF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
