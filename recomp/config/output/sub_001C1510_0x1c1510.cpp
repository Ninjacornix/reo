#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1510
// Address: 0x1c1510 - 0x1c1574
void sub_001C1510_0x1c1510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1510_0x1c1510");
#endif

    switch (ctx->pc) {
        case 0x1c1530u: goto label_1c1530;
        case 0x1c1544u: goto label_1c1544;
        case 0x1c1560u: goto label_1c1560;
        default: break;
    }

    ctx->pc = 0x1c1510u;

    // 0x1c1510: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c1510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c1514: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c1514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c1518: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c1518u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c151c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c151cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1520: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1c1520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1524: 0x3c100032  lui         $s0, 0x32
    ctx->pc = 0x1c1524u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)50 << 16));
    // 0x1c1528: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C1528u;
    {
        const bool branch_taken_0x1c1528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C152Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1528u;
            // 0x1c152c: 0x26106c50  addiu       $s0, $s0, 0x6C50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 27728));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1528) {
            ctx->pc = 0x1C1548u;
            goto label_1c1548;
        }
    }
    ctx->pc = 0x1C1530u;
label_1c1530:
    // 0x1c1530: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1c1530u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1c1534: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c1534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c1538: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c153c: 0xc06038a  jal         func_180E28
    ctx->pc = 0x1C153Cu;
    SET_GPR_U32(ctx, 31, 0x1C1544u);
    ctx->pc = 0x1C1540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C153Cu;
            // 0x1c1540: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180E28u;
    if (runtime->hasFunction(0x180E28u)) {
        auto targetFn = runtime->lookupFunction(0x180E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1544u; }
        if (ctx->pc != 0x1C1544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180E28_0x180e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1544u; }
        if (ctx->pc != 0x1C1544u) { return; }
    }
    ctx->pc = 0x1C1544u;
label_1c1544:
    // 0x1c1544: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c1544u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c1548:
    // 0x1c1548: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c1548u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c154c: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1c154cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c1550: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1C1550u;
    {
        const bool branch_taken_0x1c1550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1550u;
            // 0x1c1554: 0x3c020032  lui         $v0, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1550) {
            ctx->pc = 0x1C1530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1530;
        }
    }
    ctx->pc = 0x1C1558u;
    // 0x1c1558: 0xc060334  jal         func_180CD0
    ctx->pc = 0x1C1558u;
    SET_GPR_U32(ctx, 31, 0x1C1560u);
    ctx->pc = 0x180CD0u;
    if (runtime->hasFunction(0x180CD0u)) {
        auto targetFn = runtime->lookupFunction(0x180CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1560u; }
        if (ctx->pc != 0x1C1560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180CD0_0x180cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1560u; }
        if (ctx->pc != 0x1C1560u) { return; }
    }
    ctx->pc = 0x1C1560u;
label_1c1560:
    // 0x1c1560: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c1560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1564: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1564u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1568: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1568u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c156c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C156Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C156Cu;
            // 0x1c1570: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1530u: goto label_1c1530;
            case 0x1C1544u: goto label_1c1544;
            case 0x1C1548u: goto label_1c1548;
            case 0x1C1560u: goto label_1c1560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1574u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
