#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E2B0
// Address: 0x15e2b0 - 0x15e318
void sub_0015E2B0_0x15e2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E2B0_0x15e2b0");
#endif

    switch (ctx->pc) {
        case 0x15e304u: goto label_15e304;
        default: break;
    }

    ctx->pc = 0x15e2b0u;

    // 0x15e2b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e2b4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15e2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15e2b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e2b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e2bc: 0x2c850003  sltiu       $a1, $a0, 0x3
    ctx->pc = 0x15e2bcu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15e2c0: 0x10820011  beq         $a0, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x15E2C0u;
    {
        const bool branch_taken_0x15e2c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15E2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2C0u;
            // 0x15e2c4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e2c0) {
            ctx->pc = 0x15E308u;
            goto label_15e308;
        }
    }
    ctx->pc = 0x15E2C8u;
    // 0x15e2c8: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15E2C8u;
    {
        const bool branch_taken_0x15e2c8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x15e2c8) {
            ctx->pc = 0x15E2CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2C8u;
            // 0x15e2cc: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E2E0u;
            goto label_15e2e0;
        }
    }
    ctx->pc = 0x15E2D0u;
    // 0x15e2d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15e2d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e2d4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x15E2D4u;
    {
        const bool branch_taken_0x15e2d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2D4u;
            // 0x15e2d8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e2d4) {
            ctx->pc = 0x15E2F0u;
            goto label_15e2f0;
        }
    }
    ctx->pc = 0x15E2DCu;
    // 0x15e2dc: 0x0  nop
    ctx->pc = 0x15e2dcu;
    // NOP
label_15e2e0:
    // 0x15e2e0: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15E2E0u;
    {
        const bool branch_taken_0x15e2e0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15E2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2E0u;
            // 0x15e2e4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e2e0) {
            ctx->pc = 0x15E308u;
            goto label_15e308;
        }
    }
    ctx->pc = 0x15E2E8u;
    // 0x15e2e8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x15e2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15e2ec: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x15e2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_15e2f0:
    // 0x15e2f0: 0x10820006  beq         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15E2F0u;
    {
        const bool branch_taken_0x15e2f0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15E2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2F0u;
            // 0x15e2f4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e2f0) {
            ctx->pc = 0x15E30Cu;
            goto label_15e30c;
        }
    }
    ctx->pc = 0x15E2F8u;
    // 0x15e2f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e2fc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15E2FCu;
    SET_GPR_U32(ctx, 31, 0x15E304u);
    ctx->pc = 0x15E300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2FCu;
            // 0x15e300: 0x2484ed00  addiu       $a0, $a0, -0x1300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E304u; }
        if (ctx->pc != 0x15E304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E304u; }
        if (ctx->pc != 0x15E304u) { return; }
    }
    ctx->pc = 0x15E304u;
label_15e304:
    // 0x15e304: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15e304u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_15e308:
    // 0x15e308: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15e308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15e30c:
    // 0x15e30c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x15e30cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e310: 0x3e00008  jr          $ra
    ctx->pc = 0x15E310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E310u;
            // 0x15e314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E2E0u: goto label_15e2e0;
            case 0x15E2F0u: goto label_15e2f0;
            case 0x15E304u: goto label_15e304;
            case 0x15E308u: goto label_15e308;
            case 0x15E30Cu: goto label_15e30c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
