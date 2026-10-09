#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CC10
// Address: 0x12cc10 - 0x12cc50
void sub_0012CC10_0x12cc10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CC10_0x12cc10");
#endif

    switch (ctx->pc) {
        case 0x12cc34u: goto label_12cc34;
        default: break;
    }

    ctx->pc = 0x12cc10u;

    // 0x12cc10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12cc10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12cc14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12cc14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12cc18: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12cc18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cc1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12cc1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12cc20: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12cc20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cc24: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12cc24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12cc28: 0xae110038  sw          $s1, 0x38($s0)
    ctx->pc = 0x12cc28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 17));
    // 0x12cc2c: 0xc048c08  jal         func_123020
    ctx->pc = 0x12CC2Cu;
    SET_GPR_U32(ctx, 31, 0x12CC34u);
    ctx->pc = 0x12CC30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CC2Cu;
            // 0x12cc30: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123020u;
    if (runtime->hasFunction(0x123020u)) {
        auto targetFn = runtime->lookupFunction(0x123020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CC34u; }
        if (ctx->pc != 0x12CC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00123020_0x123020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CC34u; }
        if (ctx->pc != 0x12CC34u) { return; }
    }
    ctx->pc = 0x12CC34u;
label_12cc34:
    // 0x12cc34: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x12cc34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12cc38: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12cc38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cc3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12cc3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cc40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cc40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cc44: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12cc44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12cc48: 0x8048b9c  j           func_122E70
    ctx->pc = 0x12CC48u;
    ctx->pc = 0x12CC4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CC48u;
            // 0x12cc4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122E70u;
    if (runtime->hasFunction(0x122E70u)) {
        auto targetFn = runtime->lookupFunction(0x122E70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122E70_0x122e70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12CC50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
