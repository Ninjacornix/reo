#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180310
// Address: 0x180310 - 0x180378
void sub_00180310_0x180310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180310_0x180310");
#endif

    switch (ctx->pc) {
        case 0x180338u: goto label_180338;
        case 0x18034cu: goto label_18034c;
        default: break;
    }

    ctx->pc = 0x180310u;

    // 0x180310: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x180310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x180314: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x180314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x180318: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x180318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x18031c: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x18031cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x180320: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180324: 0x24716188  addiu       $s1, $v1, 0x6188
    ctx->pc = 0x180324u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 24968));
    // 0x180328: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x180328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18032c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x18032cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180330: 0xac40f9e0  sw          $zero, -0x620($v0)
    ctx->pc = 0x180330u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294965728), GPR_U32(ctx, 0));
    // 0x180334: 0x0  nop
    ctx->pc = 0x180334u;
    // NOP
label_180338:
    // 0x180338: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x180338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18033c: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x18033Cu;
    {
        const bool branch_taken_0x18033c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18033c) {
            ctx->pc = 0x180340u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18033Cu;
            // 0x180340: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180354u;
            goto label_180354;
        }
    }
    ctx->pc = 0x180344u;
    // 0x180344: 0xc060120  jal         func_180480
    ctx->pc = 0x180344u;
    SET_GPR_U32(ctx, 31, 0x18034Cu);
    ctx->pc = 0x180348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180344u;
            // 0x180348: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180480u;
    if (runtime->hasFunction(0x180480u)) {
        auto targetFn = runtime->lookupFunction(0x180480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18034Cu; }
        if (ctx->pc != 0x18034Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180480_0x180480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18034Cu; }
        if (ctx->pc != 0x18034Cu) { return; }
    }
    ctx->pc = 0x18034Cu;
label_18034c:
    // 0x18034c: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18034Cu;
    {
        const bool branch_taken_0x18034c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x180350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18034Cu;
            // 0x180350: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18034c) {
            ctx->pc = 0x180364u;
            goto label_180364;
        }
    }
    ctx->pc = 0x180354u;
label_180354:
    // 0x180354: 0x2a020010  slti        $v0, $s0, 0x10
    ctx->pc = 0x180354u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x180358: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x180358u;
    {
        const bool branch_taken_0x180358 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180358u;
            // 0x18035c: 0x26310334  addiu       $s1, $s1, 0x334 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 820));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180358) {
            ctx->pc = 0x180338u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_180338;
        }
    }
    ctx->pc = 0x180360u;
    // 0x180360: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x180360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_180364:
    // 0x180364: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x180364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x180368: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x180368u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18036c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18036cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180370: 0x3e00008  jr          $ra
    ctx->pc = 0x180370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180370u;
            // 0x180374: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180338u: goto label_180338;
            case 0x18034Cu: goto label_18034c;
            case 0x180354u: goto label_180354;
            case 0x180364u: goto label_180364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180378u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
