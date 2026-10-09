#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001159D0
// Address: 0x1159d0 - 0x115a10
void sub_001159D0_0x1159d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001159D0_0x1159d0");
#endif

    ctx->pc = 0x1159d0u;

    // 0x1159d0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1159d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1159d4: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1159d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1159d8: 0x8ca4000c  lw          $a0, 0xC($a1)
    ctx->pc = 0x1159d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1159dc: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1159dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1159e0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1159e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1159e4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1159e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1159e8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1159e8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1159ec: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1159ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1159f0: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1159f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1159f4: 0x14830003  bne         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1159F4u;
    {
        const bool branch_taken_0x1159f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1159F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1159F4u;
            // 0x1159f8: 0xaca4000c  sw          $a0, 0xC($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1159f4) {
            ctx->pc = 0x115A04u;
            goto label_115a04;
        }
    }
    ctx->pc = 0x1159FCu;
    // 0x1159fc: 0x24a20010  addiu       $v0, $a1, 0x10
    ctx->pc = 0x1159fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x115a00: 0xaca2000c  sw          $v0, 0xC($a1)
    ctx->pc = 0x115a00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 2));
label_115a04:
    // 0x115a04: 0x3e00008  jr          $ra
    ctx->pc = 0x115A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115A04u: goto label_115a04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115A0Cu;
    // 0x115a0c: 0x0  nop
    ctx->pc = 0x115a0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
