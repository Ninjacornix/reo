#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6A90
// Address: 0x1d6a90 - 0x1d6af0
void sub_001D6A90_0x1d6a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6A90_0x1d6a90");
#endif

    switch (ctx->pc) {
        case 0x1d6aacu: goto label_1d6aac;
        case 0x1d6ab8u: goto label_1d6ab8;
        default: break;
    }

    ctx->pc = 0x1d6a90u;

    // 0x1d6a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d6a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d6a94: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x1d6a94u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1d6a98: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d6a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d6a9c: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d6a9cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d6aa0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6aa0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6aa4: 0xc075f70  jal         func_1D7DC0
    ctx->pc = 0x1D6AA4u;
    SET_GPR_U32(ctx, 31, 0x1D6AACu);
    ctx->pc = 0x1D6AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6AA4u;
            // 0x1d6aa8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7DC0u;
    if (runtime->hasFunction(0x1D7DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6AACu; }
        if (ctx->pc != 0x1D6AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7DC0_0x1d7dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6AACu; }
        if (ctx->pc != 0x1D6AACu) { return; }
    }
    ctx->pc = 0x1D6AACu;
label_1d6aac:
    // 0x1d6aac: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6aacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6ab0: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6AB0u;
    SET_GPR_U32(ctx, 31, 0x1D6AB8u);
    ctx->pc = 0x1D6AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6AB0u;
            // 0x1d6ab4: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6AB8u; }
        if (ctx->pc != 0x1D6AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6AB8u; }
        if (ctx->pc != 0x1D6AB8u) { return; }
    }
    ctx->pc = 0x1D6AB8u;
label_1d6ab8:
    // 0x1d6ab8: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6AB8u;
    {
        const bool branch_taken_0x1d6ab8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d6ab8) {
            ctx->pc = 0x1D6AC8u;
            goto label_1d6ac8;
        }
    }
    ctx->pc = 0x1D6AC0u;
    // 0x1d6ac0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D6AC0u;
    {
        const bool branch_taken_0x1d6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6ac0) {
            ctx->pc = 0x1D6AD8u;
            goto label_1d6ad8;
        }
    }
    ctx->pc = 0x1D6AC8u;
label_1d6ac8:
    // 0x1d6ac8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6AC8u;
    {
        const bool branch_taken_0x1d6ac8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d6ac8) {
            ctx->pc = 0x1D6AD8u;
            goto label_1d6ad8;
        }
    }
    ctx->pc = 0x1D6AD0u;
    // 0x1d6ad0: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d6ad0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d6ad4: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6ad4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
label_1d6ad8:
    // 0x1d6ad8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d6ad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6adc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6adcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6AE0u;
            // 0x1d6ae4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6AACu: goto label_1d6aac;
            case 0x1D6AB8u: goto label_1d6ab8;
            case 0x1D6AC8u: goto label_1d6ac8;
            case 0x1D6AD8u: goto label_1d6ad8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6AE8u;
    // 0x1d6ae8: 0x0  nop
    ctx->pc = 0x1d6ae8u;
    // NOP
    // 0x1d6aec: 0x0  nop
    ctx->pc = 0x1d6aecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
