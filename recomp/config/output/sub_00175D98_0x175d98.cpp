#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175D98
// Address: 0x175d98 - 0x175dfc
void sub_00175D98_0x175d98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175D98_0x175d98");
#endif

    switch (ctx->pc) {
        case 0x175dc8u: goto label_175dc8;
        case 0x175ddcu: goto label_175ddc;
        default: break;
    }

    ctx->pc = 0x175d98u;

    // 0x175d98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175d98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175d9c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x175d9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x175da0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175da0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175da4: 0x2463f138  addiu       $v1, $v1, -0xEC8
    ctx->pc = 0x175da4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963512));
    // 0x175da8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175da8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175dac: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x175dacu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x175db0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x175db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x175db4: 0x24700054  addiu       $s0, $v1, 0x54
    ctx->pc = 0x175db4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 84));
    // 0x175db8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x175db8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x175dbc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x175dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x175dc0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x175dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x175dc4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x175dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_175dc8:
    // 0x175dc8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x175dc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x175dcc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x175DCCu;
    {
        const bool branch_taken_0x175dcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175DCCu;
            // 0x175dd0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175dcc) {
            ctx->pc = 0x175DDCu;
            goto label_175ddc;
        }
    }
    ctx->pc = 0x175DD4u;
    // 0x175dd4: 0xc05d780  jal         func_175E00
    ctx->pc = 0x175DD4u;
    SET_GPR_U32(ctx, 31, 0x175DDCu);
    ctx->pc = 0x175E00u;
    if (runtime->hasFunction(0x175E00u)) {
        auto targetFn = runtime->lookupFunction(0x175E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175DDCu; }
        if (ctx->pc != 0x175DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175E00_0x175e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175DDCu; }
        if (ctx->pc != 0x175DDCu) { return; }
    }
    ctx->pc = 0x175DDCu;
label_175ddc:
    // 0x175ddc: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x175ddcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x175de0: 0x623fff9  bgezl       $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x175DE0u;
    {
        const bool branch_taken_0x175de0 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x175de0) {
            ctx->pc = 0x175DE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175DE0u;
            // 0x175de4: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x175DC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175dc8;
        }
    }
    ctx->pc = 0x175DE8u;
    // 0x175de8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175de8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175dec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175decu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175df0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175df0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175df4: 0x3e00008  jr          $ra
    ctx->pc = 0x175DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175DF4u;
            // 0x175df8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175DC8u: goto label_175dc8;
            case 0x175DDCu: goto label_175ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175DFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
