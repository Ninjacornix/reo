#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132DC0
// Address: 0x132dc0 - 0x132df0
void sub_00132DC0_0x132dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132DC0_0x132dc0");
#endif

    switch (ctx->pc) {
        case 0x132dd8u: goto label_132dd8;
        default: break;
    }

    ctx->pc = 0x132dc0u;

    // 0x132dc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132dc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132dc4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132DC4u;
    {
        const bool branch_taken_0x132dc4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DC4u;
            // 0x132dc8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132dc4) {
            ctx->pc = 0x132DE0u;
            goto label_132de0;
        }
    }
    ctx->pc = 0x132DCCu;
    // 0x132dcc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132dccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132dd0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132DD0u;
    SET_GPR_U32(ctx, 31, 0x132DD8u);
    ctx->pc = 0x132DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132DD0u;
            // 0x132dd4: 0x2484b420  addiu       $a0, $a0, -0x4BE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132DD8u; }
        if (ctx->pc != 0x132DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132DD8u; }
        if (ctx->pc != 0x132DD8u) { return; }
    }
    ctx->pc = 0x132DD8u;
label_132dd8:
    // 0x132dd8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132DD8u;
    {
        const bool branch_taken_0x132dd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DD8u;
            // 0x132ddc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132dd8) {
            ctx->pc = 0x132DE4u;
            goto label_132de4;
        }
    }
    ctx->pc = 0x132DE0u;
label_132de0:
    // 0x132de0: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x132de0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
label_132de4:
    // 0x132de4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132de8: 0x3e00008  jr          $ra
    ctx->pc = 0x132DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DE8u;
            // 0x132dec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132DD8u: goto label_132dd8;
            case 0x132DE0u: goto label_132de0;
            case 0x132DE4u: goto label_132de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132DF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
