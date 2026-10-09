#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C6E0
// Address: 0x18c6e0 - 0x18c730
void sub_0018C6E0_0x18c6e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C6E0_0x18c6e0");
#endif

    ctx->pc = 0x18c6e0u;

    // 0x18c6e0: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x18c6e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x18c6e4: 0x6493c  dsll32      $t1, $a2, 4
    ctx->pc = 0x18c6e4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 6) << (32 + 4));
    // 0x18c6e8: 0xc31024  and         $v0, $a2, $v1
    ctx->pc = 0x18c6e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x18c6ec: 0x9493e  dsrl32      $t1, $t1, 4
    ctx->pc = 0x18c6ecu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) >> (32 + 4));
    // 0x18c6f0: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x18C6F0u;
    {
        const bool branch_taken_0x18c6f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x18C6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C6F0u;
            // 0x18c6f4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c6f0) {
            ctx->pc = 0x18C6FCu;
            goto label_18c6fc;
        }
    }
    ctx->pc = 0x18C6F8u;
    // 0x18c6f8: 0x3c088000  lui         $t0, 0x8000
    ctx->pc = 0x18c6f8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32768 << 16));
label_18c6fc:
    // 0x18c6fc: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x18c6fcu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18c700: 0x1281825  or          $v1, $t1, $t0
    ctx->pc = 0x18c700u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x18c704: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x18c704u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x18c708: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c70c: 0x14e20005  bne         $a3, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18C70Cu;
    {
        const bool branch_taken_0x18c70c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x18C710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C70Cu;
            // 0x18c710: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c70c) {
            ctx->pc = 0x18C724u;
            goto label_18c724;
        }
    }
    ctx->pc = 0x18C714u;
    // 0x18c714: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x18c714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18c718: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x18c718u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x18c71c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x18c71cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c720: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18c720u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_18c724:
    // 0x18c724: 0x3e00008  jr          $ra
    ctx->pc = 0x18C724u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C724u;
            // 0x18c728: 0x24820010  addiu       $v0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C6FCu: goto label_18c6fc;
            case 0x18C724u: goto label_18c724;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C72Cu;
    // 0x18c72c: 0x0  nop
    ctx->pc = 0x18c72cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
