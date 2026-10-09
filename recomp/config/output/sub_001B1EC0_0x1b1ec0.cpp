#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1EC0
// Address: 0x1b1ec0 - 0x1b1f10
void sub_001B1EC0_0x1b1ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1EC0_0x1b1ec0");
#endif

    switch (ctx->pc) {
        case 0x1b1ed4u: goto label_1b1ed4;
        case 0x1b1ee8u: goto label_1b1ee8;
        default: break;
    }

    ctx->pc = 0x1b1ec0u;

    // 0x1b1ec0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b1ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b1ec4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b1ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b1ec8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1ec8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1ecc: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b1eccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1ed0: 0x24031f44  addiu       $v1, $zero, 0x1F44
    ctx->pc = 0x1b1ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
label_1b1ed4:
    // 0x1b1ed4: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b1ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b1ed8: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x1b1ed8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b1edc: 0x24423750  addiu       $v0, $v0, 0x3750
    ctx->pc = 0x1b1edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14160));
    // 0x1b1ee0: 0xc06c6f0  jal         func_1B1BC0
    ctx->pc = 0x1B1EE0u;
    SET_GPR_U32(ctx, 31, 0x1B1EE8u);
    ctx->pc = 0x1B1EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1EE0u;
            // 0x1b1ee4: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BC0u;
    if (runtime->hasFunction(0x1B1BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1EE8u; }
        if (ctx->pc != 0x1B1EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BC0_0x1b1bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1EE8u; }
        if (ctx->pc != 0x1B1EE8u) { return; }
    }
    ctx->pc = 0x1B1EE8u;
label_1b1ee8:
    // 0x1b1ee8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b1ee8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b1eec: 0x2a03000a  slti        $v1, $s0, 0xA
    ctx->pc = 0x1b1eecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1b1ef0: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B1EF0u;
    {
        const bool branch_taken_0x1b1ef0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1EF0u;
            // 0x1b1ef4: 0x24031f44  addiu       $v1, $zero, 0x1F44 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1ef0) {
            ctx->pc = 0x1B1ED4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1ed4;
        }
    }
    ctx->pc = 0x1B1EF8u;
    // 0x1b1ef8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b1ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1efc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1efcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1f00: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F00u;
            // 0x1b1f04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1ED4u: goto label_1b1ed4;
            case 0x1B1EE8u: goto label_1b1ee8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1F08u;
    // 0x1b1f08: 0x0  nop
    ctx->pc = 0x1b1f08u;
    // NOP
    // 0x1b1f0c: 0x0  nop
    ctx->pc = 0x1b1f0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
