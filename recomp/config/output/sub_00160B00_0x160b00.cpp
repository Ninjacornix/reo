#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B00
// Address: 0x160b00 - 0x160b40
void sub_00160B00_0x160b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B00_0x160b00");
#endif

    switch (ctx->pc) {
        case 0x160b10u: goto label_160b10;
        default: break;
    }

    ctx->pc = 0x160b00u;

    // 0x160b00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160b04: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160b08: 0xc05f388  jal         func_17CE20
    ctx->pc = 0x160B08u;
    SET_GPR_U32(ctx, 31, 0x160B10u);
    ctx->pc = 0x17CE20u;
    if (runtime->hasFunction(0x17CE20u)) {
        auto targetFn = runtime->lookupFunction(0x17CE20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160B10u; }
        if (ctx->pc != 0x160B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE20_0x17ce20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160B10u; }
        if (ctx->pc != 0x160B10u) { return; }
    }
    ctx->pc = 0x160B10u;
label_160b10:
    // 0x160b10: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160b10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160b14: 0x3c040016  lui         $a0, 0x16
    ctx->pc = 0x160b14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)22 << 16));
    // 0x160b18: 0x24840b28  addiu       $a0, $a0, 0xB28
    ctx->pc = 0x160b18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2856));
    // 0x160b1c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x160b1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160b20: 0x805f3d2  j           func_17CF48
    ctx->pc = 0x160B20u;
    ctx->pc = 0x160B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160B20u;
            // 0x160b24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CF48u;
    if (runtime->hasFunction(0x17CF48u)) {
        auto targetFn = runtime->lookupFunction(0x17CF48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CF48_0x17cf48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B28u;
    // 0x160b28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160b28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160b2c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x160b2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160b30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160b30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160b34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160b38: 0x8058dd4  j           func_163750
    ctx->pc = 0x160B38u;
    ctx->pc = 0x160B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160B38u;
            // 0x160b3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
