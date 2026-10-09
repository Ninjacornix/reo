#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB330
// Address: 0x1ab330 - 0x1ab370
void sub_001AB330_0x1ab330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB330_0x1ab330");
#endif

    switch (ctx->pc) {
        case 0x1ab34cu: goto label_1ab34c;
        case 0x1ab364u: goto label_1ab364;
        default: break;
    }

    ctx->pc = 0x1ab330u;

    // 0x1ab330: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ab330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ab334: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1ab334u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab338: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ab338u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ab33c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ab33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ab340: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab340u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab344: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AB344u;
    SET_GPR_U32(ctx, 31, 0x1AB34Cu);
    ctx->pc = 0x1AB348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB344u;
            // 0x1ab348: 0x24a5fcd8  addiu       $a1, $a1, -0x328 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966488));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB34Cu; }
        if (ctx->pc != 0x1AB34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB34Cu; }
        if (ctx->pc != 0x1AB34Cu) { return; }
    }
    ctx->pc = 0x1AB34Cu;
label_1ab34c:
    // 0x1ab34c: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1ab34cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1ab350: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab350u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab354: 0x24a52970  addiu       $a1, $a1, 0x2970
    ctx->pc = 0x1ab354u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10608));
    // 0x1ab358: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1ab358u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ab35c: 0xc06a6b0  jal         func_1A9AC0
    ctx->pc = 0x1AB35Cu;
    SET_GPR_U32(ctx, 31, 0x1AB364u);
    ctx->pc = 0x1AB360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB35Cu;
            // 0x1ab360: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB364u; }
        if (ctx->pc != 0x1AB364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB364u; }
        if (ctx->pc != 0x1AB364u) { return; }
    }
    ctx->pc = 0x1AB364u;
label_1ab364:
    // 0x1ab364: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ab364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab368: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB368u;
            // 0x1ab36c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB34Cu: goto label_1ab34c;
            case 0x1AB364u: goto label_1ab364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB370u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
