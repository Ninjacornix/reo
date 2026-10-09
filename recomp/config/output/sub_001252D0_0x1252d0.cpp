#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001252D0
// Address: 0x1252d0 - 0x125318
void sub_001252D0_0x1252d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001252D0_0x1252d0");
#endif

    switch (ctx->pc) {
        case 0x125304u: goto label_125304;
        default: break;
    }

    ctx->pc = 0x1252d0u;

    // 0x1252d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1252d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1252d4: 0x24820048  addiu       $v0, $a0, 0x48
    ctx->pc = 0x1252d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 72));
    // 0x1252d8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1252d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1252dc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1252dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1252e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1252e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1252e4: 0x8c470020  lw          $a3, 0x20($v0)
    ctx->pc = 0x1252e4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1252e8: 0x8c900008  lw          $s0, 0x8($a0)
    ctx->pc = 0x1252e8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1252ec: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1252ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1252f0: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1252f0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1252f4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1252f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1252f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1252f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1252fc: 0xc04d3e8  jal         func_134FA0
    ctx->pc = 0x1252FCu;
    SET_GPR_U32(ctx, 31, 0x125304u);
    ctx->pc = 0x125300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1252FCu;
            // 0x125300: 0x673821  addu        $a3, $v1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134FA0u;
    if (runtime->hasFunction(0x134FA0u)) {
        auto targetFn = runtime->lookupFunction(0x134FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125304u; }
        if (ctx->pc != 0x125304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134FA0_0x134fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125304u; }
        if (ctx->pc != 0x125304u) { return; }
    }
    ctx->pc = 0x125304u;
label_125304:
    // 0x125304: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125308: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x125308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12530c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12530cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125310: 0x804d400  j           func_135000
    ctx->pc = 0x125310u;
    ctx->pc = 0x125314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125310u;
            // 0x125314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135000u;
    if (runtime->hasFunction(0x135000u)) {
        auto targetFn = runtime->lookupFunction(0x135000u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135000_0x135000(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
