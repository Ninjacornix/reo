#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5540
// Address: 0x1b5540 - 0x1b55a0
void sub_001B5540_0x1b5540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5540_0x1b5540");
#endif

    switch (ctx->pc) {
        case 0x1b5594u: goto label_1b5594;
        default: break;
    }

    ctx->pc = 0x1b5540u;

    // 0x1b5540: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b5540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b5544: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5544u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5548: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b5548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b554c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b554cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b5550: 0x902343c3  lbu         $v1, 0x43C3($at)
    ctx->pc = 0x1b5550u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1b5554: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B5554u;
    {
        const bool branch_taken_0x1b5554 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B5558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5554u;
            // 0x1b5558: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5554) {
            ctx->pc = 0x1B5570u;
            goto label_1b5570;
        }
    }
    ctx->pc = 0x1B555Cu;
    // 0x1b555c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b555cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b5560: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5564: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1b5564u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5568: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B5568u;
    {
        const bool branch_taken_0x1b5568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B556Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5568u;
            // 0x1b556c: 0xa02343ea  sb          $v1, 0x43EA($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5568) {
            ctx->pc = 0x1B5594u;
            goto label_1b5594;
        }
    }
    ctx->pc = 0x1B5570u;
label_1b5570:
    // 0x1b5570: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b5570u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b5574: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5574u;
    {
        const bool branch_taken_0x1b5574 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5574u;
            // 0x1b5578: 0x24060080  addiu       $a2, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5574) {
            ctx->pc = 0x1B558Cu;
            goto label_1b558c;
        }
    }
    ctx->pc = 0x1B557Cu;
    // 0x1b557c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b557cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5580: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b5580u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5584: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B5584u;
    {
        const bool branch_taken_0x1b5584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5584u;
            // 0x1b5588: 0xa02043ea  sb          $zero, 0x43EA($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5584) {
            ctx->pc = 0x1B5594u;
            goto label_1b5594;
        }
    }
    ctx->pc = 0x1B558Cu;
label_1b558c:
    // 0x1b558c: 0xc06d4ac  jal         func_1B52B0
    ctx->pc = 0x1B558Cu;
    SET_GPR_U32(ctx, 31, 0x1B5594u);
    ctx->pc = 0x1B52B0u;
    if (runtime->hasFunction(0x1B52B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B52B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5594u; }
        if (ctx->pc != 0x1B5594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B52B0_0x1b52b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5594u; }
        if (ctx->pc != 0x1B5594u) { return; }
    }
    ctx->pc = 0x1B5594u;
label_1b5594:
    // 0x1b5594: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b5594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5598: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B559Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5598u;
            // 0x1b559c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5570u: goto label_1b5570;
            case 0x1B558Cu: goto label_1b558c;
            case 0x1B5594u: goto label_1b5594;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B55A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
