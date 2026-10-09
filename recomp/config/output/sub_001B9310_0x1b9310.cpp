#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9310
// Address: 0x1b9310 - 0x1b9358
void sub_001B9310_0x1b9310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9310_0x1b9310");
#endif

    switch (ctx->pc) {
        case 0x1b934cu: goto label_1b934c;
        default: break;
    }

    ctx->pc = 0x1b9310u;

    // 0x1b9310: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b9310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b9314: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b9314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b9318: 0x90860554  lbu         $a2, 0x554($a0)
    ctx->pc = 0x1b9318u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1364)));
    // 0x1b931c: 0x14c00004  bnez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B931Cu;
    {
        const bool branch_taken_0x1b931c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b931c) {
            ctx->pc = 0x1B9330u;
            goto label_1b9330;
        }
    }
    ctx->pc = 0x1B9324u;
    // 0x1b9324: 0x90830033  lbu         $v1, 0x33($a0)
    ctx->pc = 0x1b9324u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 51)));
    // 0x1b9328: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B9328u;
    {
        const bool branch_taken_0x1b9328 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9328) {
            ctx->pc = 0x1B934Cu;
            goto label_1b934c;
        }
    }
    ctx->pc = 0x1B9330u;
label_1b9330:
    // 0x1b9330: 0x908a0033  lbu         $t2, 0x33($a0)
    ctx->pc = 0x1b9330u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 51)));
    // 0x1b9334: 0x24870038  addiu       $a3, $a0, 0x38
    ctx->pc = 0x1b9334u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x1b9338: 0x30c600ff  andi        $a2, $a2, 0xFF
    ctx->pc = 0x1b9338u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1b933c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b933cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9340: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9340u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9344: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9344u;
    SET_GPR_U32(ctx, 31, 0x1B934Cu);
    ctx->pc = 0x1B9348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9344u;
            // 0x1b9348: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B934Cu; }
        if (ctx->pc != 0x1B934Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B934Cu; }
        if (ctx->pc != 0x1B934Cu) { return; }
    }
    ctx->pc = 0x1B934Cu;
label_1b934c:
    // 0x1b934c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b934cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9350: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9350u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9350u;
            // 0x1b9354: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9358u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
