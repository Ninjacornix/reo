#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7BC0
// Address: 0x1c7bc0 - 0x1c7c00
void sub_001C7BC0_0x1c7bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7BC0_0x1c7bc0");
#endif

    switch (ctx->pc) {
        case 0x1c7be0u: goto label_1c7be0;
        default: break;
    }

    ctx->pc = 0x1c7bc0u;

    // 0x1c7bc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c7bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c7bc4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c7bc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7bc8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c7bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c7bcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7bccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7bd0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c7bd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7bd4: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1c7bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1c7bd8: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C7BD8u;
    SET_GPR_U32(ctx, 31, 0x1C7BE0u);
    ctx->pc = 0x1C7BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7BD8u;
            // 0x1c7bdc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7BE0u; }
        if (ctx->pc != 0x1C7BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7BE0u; }
        if (ctx->pc != 0x1C7BE0u) { return; }
    }
    ctx->pc = 0x1C7BE0u;
label_1c7be0:
    // 0x1c7be0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7be0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7be4: 0xac3051b4  sw          $s0, 0x51B4($at)
    ctx->pc = 0x1c7be4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20916), GPR_U32(ctx, 16));
    // 0x1c7be8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c7be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7bec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7becu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7bf0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7BF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7BF0u;
            // 0x1c7bf4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7BE0u: goto label_1c7be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7BF8u;
    // 0x1c7bf8: 0x0  nop
    ctx->pc = 0x1c7bf8u;
    // NOP
    // 0x1c7bfc: 0x0  nop
    ctx->pc = 0x1c7bfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
