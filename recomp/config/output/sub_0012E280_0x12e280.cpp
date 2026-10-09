#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E280
// Address: 0x12e280 - 0x12e320
void sub_0012E280_0x12e280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E280_0x12e280");
#endif

    switch (ctx->pc) {
        case 0x12e294u: goto label_12e294;
        case 0x12e2b8u: goto label_12e2b8;
        default: break;
    }

    ctx->pc = 0x12e280u;

    // 0x12e280: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e284: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12e284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12e288: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12e288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12e28c: 0xc04b84e  jal         func_12E138
    ctx->pc = 0x12E28Cu;
    SET_GPR_U32(ctx, 31, 0x12E294u);
    ctx->pc = 0x12E290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E28Cu;
            // 0x12e290: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E138u;
    if (runtime->hasFunction(0x12E138u)) {
        auto targetFn = runtime->lookupFunction(0x12E138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E294u; }
        if (ctx->pc != 0x12E294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E138_0x12e138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E294u; }
        if (ctx->pc != 0x12E294u) { return; }
    }
    ctx->pc = 0x12E294u;
label_12e294:
    // 0x12e294: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x12e294u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e298: 0x1100001c  beqz        $t0, . + 4 + (0x1C << 2)
    ctx->pc = 0x12E298u;
    {
        const bool branch_taken_0x12e298 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E298u;
            // 0x12e29c: 0x3c030022  lui         $v1, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e298) {
            ctx->pc = 0x12E30Cu;
            goto label_12e30c;
        }
    }
    ctx->pc = 0x12E2A0u;
    // 0x12e2a0: 0x24649fa0  addiu       $a0, $v1, -0x6060
    ctx->pc = 0x12e2a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294942624));
    // 0x12e2a4: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x12e2a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12e2a8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x12E2A8u;
    {
        const bool branch_taken_0x12e2a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E2ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E2A8u;
            // 0x12e2ac: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e2a8) {
            ctx->pc = 0x12E2E8u;
            goto label_12e2e8;
        }
    }
    ctx->pc = 0x12E2B0u;
    // 0x12e2b0: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x12e2b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e2b4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x12e2b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_12e2b8:
    // 0x12e2b8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12e2b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x12e2bc: 0x24c60090  addiu       $a2, $a2, 0x90
    ctx->pc = 0x12e2bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 144));
    // 0x12e2c0: 0x28e30010  slti        $v1, $a3, 0x10
    ctx->pc = 0x12e2c0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x12e2c4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x12E2C4u;
    {
        const bool branch_taken_0x12e2c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E2C4u;
            // 0x12e2c8: 0x24a50090  addiu       $a1, $a1, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e2c4) {
            ctx->pc = 0x12E2ECu;
            goto label_12e2ec;
        }
    }
    ctx->pc = 0x12E2CCu;
    // 0x12e2cc: 0x80c20000  lb          $v0, 0x0($a2)
    ctx->pc = 0x12e2ccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12e2d0: 0x0  nop
    ctx->pc = 0x12e2d0u;
    // NOP
    // 0x12e2d4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12E2D4u;
    {
        const bool branch_taken_0x12e2d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E2D4u;
            // 0x12e2d8: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e2d4) {
            ctx->pc = 0x12E2B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e2b8;
        }
    }
    ctx->pc = 0x12E2DCu;
    // 0x12e2dc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x12E2DCu;
    {
        const bool branch_taken_0x12e2dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E2E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E2DCu;
            // 0x12e2e0: 0xac900014  sw          $s0, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e2dc) {
            ctx->pc = 0x12E2F0u;
            goto label_12e2f0;
        }
    }
    ctx->pc = 0x12E2E4u;
    // 0x12e2e4: 0x0  nop
    ctx->pc = 0x12e2e4u;
    // NOP
label_12e2e8:
    // 0x12e2e8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12e2e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_12e2ec:
    // 0x12e2ec: 0xac900014  sw          $s0, 0x14($a0)
    ctx->pc = 0x12e2ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 16));
label_12e2f0:
    // 0x12e2f0: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12E2F0u;
    {
        const bool branch_taken_0x12e2f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E2F0u;
            // 0x12e2f4: 0xac880088  sw          $t0, 0x88($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e2f0) {
            ctx->pc = 0x12E308u;
            goto label_12e308;
        }
    }
    ctx->pc = 0x12E2F8u;
    // 0x12e2f8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12e2f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12e2fc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12e2fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e300: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12E300u;
    {
        const bool branch_taken_0x12e300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E300u;
            // 0x12e304: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e300) {
            ctx->pc = 0x12E30Cu;
            goto label_12e30c;
        }
    }
    ctx->pc = 0x12E308u;
label_12e308:
    // 0x12e308: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12e308u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12e30c:
    // 0x12e30c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12e30cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e310: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12e310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12e314: 0x3e00008  jr          $ra
    ctx->pc = 0x12E314u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E314u;
            // 0x12e318: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E294u: goto label_12e294;
            case 0x12E2B8u: goto label_12e2b8;
            case 0x12E2E8u: goto label_12e2e8;
            case 0x12E2ECu: goto label_12e2ec;
            case 0x12E2F0u: goto label_12e2f0;
            case 0x12E308u: goto label_12e308;
            case 0x12E30Cu: goto label_12e30c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E31Cu;
    // 0x12e31c: 0x0  nop
    ctx->pc = 0x12e31cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
