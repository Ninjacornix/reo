#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CCA80
// Address: 0x1cca80 - 0x1ccad0
void sub_001CCA80_0x1cca80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CCA80_0x1cca80");
#endif

    switch (ctx->pc) {
        case 0x1cca90u: goto label_1cca90;
        default: break;
    }

    ctx->pc = 0x1cca80u;

    // 0x1cca80: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cca80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cca84: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cca84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cca88: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CCA88u;
    {
        const bool branch_taken_0x1cca88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCA8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCA88u;
            // 0x1cca8c: 0x24421640  addiu       $v0, $v0, 0x1640 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cca88) {
            ctx->pc = 0x1CCAACu;
            goto label_1ccaac;
        }
    }
    ctx->pc = 0x1CCA90u;
label_1cca90:
    // 0x1cca90: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1cca90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cca94: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CCA94u;
    {
        const bool branch_taken_0x1cca94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cca94) {
            ctx->pc = 0x1CCAA4u;
            goto label_1ccaa4;
        }
    }
    ctx->pc = 0x1CCA9Cu;
    // 0x1cca9c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CCA9Cu;
    {
        const bool branch_taken_0x1cca9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cca9c) {
            ctx->pc = 0x1CCABCu;
            goto label_1ccabc;
        }
    }
    ctx->pc = 0x1CCAA4u;
label_1ccaa4:
    // 0x1ccaa4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1ccaa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1ccaa8: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1ccaa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_1ccaac:
    // 0x1ccaac: 0x28830100  slti        $v1, $a0, 0x100
    ctx->pc = 0x1ccaacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1ccab0: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1CCAB0u;
    {
        const bool branch_taken_0x1ccab0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ccab0) {
            ctx->pc = 0x1CCA90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cca90;
        }
    }
    ctx->pc = 0x1CCAB8u;
    // 0x1ccab8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ccab8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ccabc:
    // 0x1ccabc: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCA90u: goto label_1cca90;
            case 0x1CCAA4u: goto label_1ccaa4;
            case 0x1CCAACu: goto label_1ccaac;
            case 0x1CCABCu: goto label_1ccabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCAC4u;
    // 0x1ccac4: 0x0  nop
    ctx->pc = 0x1ccac4u;
    // NOP
    // 0x1ccac8: 0x0  nop
    ctx->pc = 0x1ccac8u;
    // NOP
    // 0x1ccacc: 0x0  nop
    ctx->pc = 0x1ccaccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
