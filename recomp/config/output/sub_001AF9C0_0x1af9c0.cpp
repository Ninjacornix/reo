#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF9C0
// Address: 0x1af9c0 - 0x1afa00
void sub_001AF9C0_0x1af9c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF9C0_0x1af9c0");
#endif

    switch (ctx->pc) {
        case 0x1af9dcu: goto label_1af9dc;
        default: break;
    }

    ctx->pc = 0x1af9c0u;

    // 0x1af9c0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af9c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af9c4: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1af9c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1af9c8: 0xac208e10  sw          $zero, -0x71F0($at)
    ctx->pc = 0x1af9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938128), GPR_U32(ctx, 0));
    // 0x1af9cc: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af9ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af9d0: 0xac208e08  sw          $zero, -0x71F8($at)
    ctx->pc = 0x1af9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938120), GPR_U32(ctx, 0));
    // 0x1af9d4: 0x3c04002c  lui         $a0, 0x2C
    ctx->pc = 0x1af9d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)44 << 16));
    // 0x1af9d8: 0x24848e20  addiu       $a0, $a0, -0x71E0
    ctx->pc = 0x1af9d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294938144));
label_1af9dc:
    // 0x1af9dc: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1af9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1af9e0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1af9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1af9e4: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1af9e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1af9e8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1af9e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1af9ec: 0x0  nop
    ctx->pc = 0x1af9ecu;
    // NOP
    // 0x1af9f0: 0x4a1fffa  bgez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AF9F0u;
    {
        const bool branch_taken_0x1af9f0 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1af9f0) {
            ctx->pc = 0x1AF9DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af9dc;
        }
    }
    ctx->pc = 0x1AF9F8u;
    // 0x1af9f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF9F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF9DCu: goto label_1af9dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFA00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
