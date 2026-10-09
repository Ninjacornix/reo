#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C530
// Address: 0x17c530 - 0x17c590
void sub_0017C530_0x17c530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C530_0x17c530");
#endif

    switch (ctx->pc) {
        case 0x17c57cu: goto label_17c57c;
        default: break;
    }

    ctx->pc = 0x17c530u;

    // 0x17c530: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c534: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x17c534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c538: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c53c: 0x2c850011  sltiu       $a1, $a0, 0x11
    ctx->pc = 0x17c53cu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)17) ? 1 : 0);
    // 0x17c540: 0x1082000f  beq         $a0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17C540u;
    {
        const bool branch_taken_0x17c540 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x17C544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C540u;
            // 0x17c544: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c540) {
            ctx->pc = 0x17C580u;
            goto label_17c580;
        }
    }
    ctx->pc = 0x17C548u;
    // 0x17c548: 0x14a00008  bnez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17C548u;
    {
        const bool branch_taken_0x17c548 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C548u;
            // 0x17c54c: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c548) {
            ctx->pc = 0x17C56Cu;
            goto label_17c56c;
        }
    }
    ctx->pc = 0x17C550u;
    // 0x17c550: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x17c550u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x17c554: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x17C554u;
    {
        const bool branch_taken_0x17c554 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x17C558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C554u;
            // 0x17c558: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c554) {
            ctx->pc = 0x17C580u;
            goto label_17c580;
        }
    }
    ctx->pc = 0x17C55Cu;
    // 0x17c55c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x17c55cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x17c560: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17C560u;
    {
        const bool branch_taken_0x17c560 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x17C564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C560u;
            // 0x17c564: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c560) {
            ctx->pc = 0x17C580u;
            goto label_17c580;
        }
    }
    ctx->pc = 0x17C568u;
    // 0x17c568: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c568u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
label_17c56c:
    // 0x17c56c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17c56cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c570: 0x24c610c0  addiu       $a2, $a2, 0x10C0
    ctx->pc = 0x17c570u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4288));
    // 0x17c574: 0xc05f472  jal         func_17D1C8
    ctx->pc = 0x17C574u;
    SET_GPR_U32(ctx, 31, 0x17C57Cu);
    ctx->pc = 0x17C578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C574u;
            // 0x17c578: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C57Cu; }
        if (ctx->pc != 0x17C57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C57Cu; }
        if (ctx->pc != 0x17C57Cu) { return; }
    }
    ctx->pc = 0x17C57Cu;
label_17c57c:
    // 0x17c57c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x17c57cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17c580:
    // 0x17c580: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c584: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x17c584u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c588: 0x3e00008  jr          $ra
    ctx->pc = 0x17C588u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C588u;
            // 0x17c58c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C56Cu: goto label_17c56c;
            case 0x17C57Cu: goto label_17c57c;
            case 0x17C580u: goto label_17c580;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
