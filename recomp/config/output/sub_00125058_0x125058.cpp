#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125058
// Address: 0x125058 - 0x12509c
void sub_00125058_0x125058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125058_0x125058");
#endif

    switch (ctx->pc) {
        case 0x12506cu: goto label_12506c;
        default: break;
    }

    ctx->pc = 0x125058u;

    // 0x125058: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12505c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12505cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125060: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x125060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x125064: 0xc042c56  jal         func_10B158
    ctx->pc = 0x125064u;
    SET_GPR_U32(ctx, 31, 0x12506Cu);
    ctx->pc = 0x125068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125064u;
            // 0x125068: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12506Cu; }
        if (ctx->pc != 0x12506Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12506Cu; }
        if (ctx->pc != 0x12506Cu) { return; }
    }
    ctx->pc = 0x12506Cu;
label_12506c:
    // 0x12506c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12506cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125070: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125074: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x125074u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x125078: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x125078u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x12507c: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x12507cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x125080: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125084: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x125084u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125088: 0x24c6b94c  addiu       $a2, $a2, -0x46B4
    ctx->pc = 0x125088u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294949196));
    // 0x12508c: 0x24e7b94e  addiu       $a3, $a3, -0x46B2
    ctx->pc = 0x12508cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294949198));
    // 0x125090: 0x2508b950  addiu       $t0, $t0, -0x46B0
    ctx->pc = 0x125090u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294949200));
    // 0x125094: 0x8049156  j           func_124558
    ctx->pc = 0x125094u;
    ctx->pc = 0x125098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125094u;
            // 0x125098: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124558_0x124558(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12509Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
