#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001646D8
// Address: 0x1646d8 - 0x164700
void sub_001646D8_0x1646d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001646D8_0x1646d8");
#endif

    switch (ctx->pc) {
        case 0x1646ecu: goto label_1646ec;
        default: break;
    }

    ctx->pc = 0x1646d8u;

    // 0x1646d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1646d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1646dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1646dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1646e0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1646e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1646e4: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x1646E4u;
    SET_GPR_U32(ctx, 31, 0x1646ECu);
    ctx->pc = 0x1646E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1646E4u;
            // 0x1646e8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1646ECu; }
        if (ctx->pc != 0x1646ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1646ECu; }
        if (ctx->pc != 0x1646ECu) { return; }
    }
    ctx->pc = 0x1646ECu;
label_1646ec:
    // 0x1646ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1646ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1646f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1646f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1646f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1646f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1646f8: 0x804c148  j           func_130520
    ctx->pc = 0x1646F8u;
    ctx->pc = 0x1646FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1646F8u;
            // 0x1646fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130520_0x130520(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164700u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
