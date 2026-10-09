#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F70
// Address: 0x124f70 - 0x124fb0
void sub_00124F70_0x124f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F70_0x124f70");
#endif

    switch (ctx->pc) {
        case 0x124f90u: goto label_124f90;
        default: break;
    }

    ctx->pc = 0x124f70u;

    // 0x124f70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124f74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124f78: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124f78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124f7c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x124f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124f80: 0x260500a8  addiu       $a1, $s0, 0xA8
    ctx->pc = 0x124f80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 168));
    // 0x124f84: 0x260600ac  addiu       $a2, $s0, 0xAC
    ctx->pc = 0x124f84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 172));
    // 0x124f88: 0xc04d3c0  jal         func_134F00
    ctx->pc = 0x124F88u;
    SET_GPR_U32(ctx, 31, 0x124F90u);
    ctx->pc = 0x124F8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124F88u;
            // 0x124f8c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F00u;
    if (runtime->hasFunction(0x134F00u)) {
        auto targetFn = runtime->lookupFunction(0x134F00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124F90u; }
        if (ctx->pc != 0x124F90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F00_0x134f00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124F90u; }
        if (ctx->pc != 0x124F90u) { return; }
    }
    ctx->pc = 0x124F90u;
label_124f90:
    // 0x124f90: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124f90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124f94: 0x260700a6  addiu       $a3, $s0, 0xA6
    ctx->pc = 0x124f94u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 166));
    // 0x124f98: 0x260500a2  addiu       $a1, $s0, 0xA2
    ctx->pc = 0x124f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 162));
    // 0x124f9c: 0x260600a4  addiu       $a2, $s0, 0xA4
    ctx->pc = 0x124f9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 164));
    // 0x124fa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fa4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x124fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fa8: 0x804d3ce  j           func_134F38
    ctx->pc = 0x124FA8u;
    ctx->pc = 0x124FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FA8u;
            // 0x124fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F38u;
    if (runtime->hasFunction(0x134F38u)) {
        auto targetFn = runtime->lookupFunction(0x134F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00134F38_0x134f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
