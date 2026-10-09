#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140ED8
// Address: 0x140ed8 - 0x140f14
void sub_00140ED8_0x140ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140ED8_0x140ed8");
#endif

    ctx->pc = 0x140ed8u;

    // 0x140ed8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140edc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140edcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140ee0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140ee4: 0x24639a74  addiu       $v1, $v1, -0x658C
    ctx->pc = 0x140ee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941300));
    // 0x140ee8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140eec: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x140eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x140ef0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x140EF0u;
    {
        const bool branch_taken_0x140ef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140EF0u;
            // 0x140ef4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140ef0) {
            ctx->pc = 0x140F08u;
            goto label_140f08;
        }
    }
    ctx->pc = 0x140EF8u;
    // 0x140ef8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140efc: 0x804e4fa  j           func_1393E8
    ctx->pc = 0x140EFCu;
    ctx->pc = 0x140F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140EFCu;
            // 0x140f00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1393E8u;
    if (runtime->hasFunction(0x1393E8u)) {
        auto targetFn = runtime->lookupFunction(0x1393E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001393E8_0x1393e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140F04u;
    // 0x140f04: 0x0  nop
    ctx->pc = 0x140f04u;
    // NOP
label_140f08:
    // 0x140f08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140f08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x140F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F0Cu;
            // 0x140f10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140F08u: goto label_140f08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140F14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
