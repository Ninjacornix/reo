#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107DA8
// Address: 0x107da8 - 0x107df8
void sub_00107DA8_0x107da8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107DA8_0x107da8");
#endif

    ctx->pc = 0x107da8u;

    // 0x107da8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x107da8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x107dac: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x107dacu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x107db0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x107db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x107db4: 0x24639c5c  addiu       $v1, $v1, -0x63A4
    ctx->pc = 0x107db4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941788));
    // 0x107db8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x107db8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x107dbc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x107dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x107dc0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x107DC0u;
    {
        const bool branch_taken_0x107dc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107DC0u;
            // 0x107dc4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107dc0) {
            ctx->pc = 0x107DE8u;
            goto label_107de8;
        }
    }
    ctx->pc = 0x107DC8u;
    // 0x107dc8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x107dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x107dcc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x107dccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107dd0: 0x8c44a470  lw          $a0, -0x5B90($v0)
    ctx->pc = 0x107dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943856)));
    // 0x107dd4: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x107dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x107dd8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x107dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x107ddc: 0xaca39c58  sw          $v1, -0x63A8($a1)
    ctx->pc = 0x107ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294941784), GPR_U32(ctx, 3));
    // 0x107de0: 0x8045190  j           func_114640
    ctx->pc = 0x107DE0u;
    ctx->pc = 0x107DE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107DE0u;
            // 0x107de4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x107DE8u;
label_107de8:
    // 0x107de8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x107de8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107dec: 0x3e00008  jr          $ra
    ctx->pc = 0x107DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107DECu;
            // 0x107df0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107DE8u: goto label_107de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107DF4u;
    // 0x107df4: 0x0  nop
    ctx->pc = 0x107df4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
