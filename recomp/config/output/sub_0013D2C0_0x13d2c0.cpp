#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D2C0
// Address: 0x13d2c0 - 0x13d354
void sub_0013D2C0_0x13d2c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D2C0_0x13d2c0");
#endif

    switch (ctx->pc) {
        case 0x13d2d8u: goto label_13d2d8;
        case 0x13d2f8u: goto label_13d2f8;
        case 0x13d334u: goto label_13d334;
        default: break;
    }

    ctx->pc = 0x13d2c0u;

    // 0x13d2c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d2c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d2c4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D2C4u;
    {
        const bool branch_taken_0x13d2c4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2C4u;
            // 0x13d2c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2c4) {
            ctx->pc = 0x13D2E0u;
            goto label_13d2e0;
        }
    }
    ctx->pc = 0x13D2CCu;
    // 0x13d2cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d2d0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D2D0u;
    SET_GPR_U32(ctx, 31, 0x13D2D8u);
    ctx->pc = 0x13D2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2D0u;
            // 0x13d2d4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D2D8u; }
        if (ctx->pc != 0x13D2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D2D8u; }
        if (ctx->pc != 0x13D2D8u) { return; }
    }
    ctx->pc = 0x13D2D8u;
label_13d2d8:
    // 0x13d2d8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D2D8u;
    {
        const bool branch_taken_0x13d2d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2D8u;
            // 0x13d2dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2d8) {
            ctx->pc = 0x13D348u;
            goto label_13d348;
        }
    }
    ctx->pc = 0x13D2E0u;
label_13d2e0:
    // 0x13d2e0: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d2e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d2e4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d2e8: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D2E8u;
    {
        const bool branch_taken_0x13d2e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2E8u;
            // 0x13d2ec: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2e8) {
            ctx->pc = 0x13D31Cu;
            goto label_13d31c;
        }
    }
    ctx->pc = 0x13D2F0u;
    // 0x13d2f0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d2f4: 0x0  nop
    ctx->pc = 0x13d2f4u;
    // NOP
label_13d2f8:
    // 0x13d2f8: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d2f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d2fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D2FCu;
    {
        const bool branch_taken_0x13d2fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2FCu;
            // 0x13d300: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d2fc) {
            ctx->pc = 0x13D31Cu;
            goto label_13d31c;
        }
    }
    ctx->pc = 0x13D304u;
    // 0x13d304: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d308: 0x0  nop
    ctx->pc = 0x13d308u;
    // NOP
    // 0x13d30c: 0x0  nop
    ctx->pc = 0x13d30cu;
    // NOP
    // 0x13d310: 0x0  nop
    ctx->pc = 0x13d310u;
    // NOP
    // 0x13d314: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D314u;
    {
        const bool branch_taken_0x13d314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d314) {
            ctx->pc = 0x13D318u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D314u;
            // 0x13d318: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D2F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d2f8;
        }
    }
    ctx->pc = 0x13D31Cu;
label_13d31c:
    // 0x13d31c: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d320: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D320u;
    {
        const bool branch_taken_0x13d320 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d320) {
            ctx->pc = 0x13D324u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D320u;
            // 0x13d324: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D340u;
            goto label_13d340;
        }
    }
    ctx->pc = 0x13D328u;
    // 0x13d328: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d328u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d32c: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D32Cu;
    SET_GPR_U32(ctx, 31, 0x13D334u);
    ctx->pc = 0x13D330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D32Cu;
            // 0x13d330: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D334u; }
        if (ctx->pc != 0x13D334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D334u; }
        if (ctx->pc != 0x13D334u) { return; }
    }
    ctx->pc = 0x13D334u;
label_13d334:
    // 0x13d334: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D334u;
    {
        const bool branch_taken_0x13d334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D334u;
            // 0x13d338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d334) {
            ctx->pc = 0x13D348u;
            goto label_13d348;
        }
    }
    ctx->pc = 0x13D33Cu;
    // 0x13d33c: 0x0  nop
    ctx->pc = 0x13d33cu;
    // NOP
label_13d340:
    // 0x13d340: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d340u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d344: 0x8c620054  lw          $v0, 0x54($v1)
    ctx->pc = 0x13d344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 84)));
label_13d348:
    // 0x13d348: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d34c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D34Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D34Cu;
            // 0x13d350: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D2D8u: goto label_13d2d8;
            case 0x13D2E0u: goto label_13d2e0;
            case 0x13D2F8u: goto label_13d2f8;
            case 0x13D31Cu: goto label_13d31c;
            case 0x13D334u: goto label_13d334;
            case 0x13D340u: goto label_13d340;
            case 0x13D348u: goto label_13d348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D354u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
