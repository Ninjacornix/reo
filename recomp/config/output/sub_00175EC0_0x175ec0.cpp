#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175EC0
// Address: 0x175ec0 - 0x175ef8
void sub_00175EC0_0x175ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175EC0_0x175ec0");
#endif

    ctx->pc = 0x175ec0u;

    // 0x175ec0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x175ec0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175ec4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x175ec4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x175ec8: 0x8ca30048  lw          $v1, 0x48($a1)
    ctx->pc = 0x175ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 72)));
    // 0x175ecc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x175eccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175ed0: 0x14640006  bne         $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x175ED0u;
    {
        const bool branch_taken_0x175ed0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x175ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175ED0u;
            // 0x175ed4: 0x24a6094c  addiu       $a2, $a1, 0x94C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 2380));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175ed0) {
            ctx->pc = 0x175EECu;
            goto label_175eec;
        }
    }
    ctx->pc = 0x175ED8u;
    // 0x175ed8: 0x8ca30050  lw          $v1, 0x50($a1)
    ctx->pc = 0x175ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 80)));
    // 0x175edc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x175EDCu;
    {
        const bool branch_taken_0x175edc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x175edc) {
            ctx->pc = 0x175EECu;
            goto label_175eec;
        }
    }
    ctx->pc = 0x175EE4u;
    // 0x175ee4: 0x8cc20018  lw          $v0, 0x18($a2)
    ctx->pc = 0x175ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x175ee8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x175ee8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_175eec:
    // 0x175eec: 0x3e00008  jr          $ra
    ctx->pc = 0x175EECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175EECu: goto label_175eec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175EF4u;
    // 0x175ef4: 0x0  nop
    ctx->pc = 0x175ef4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
