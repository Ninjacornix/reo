#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6720
// Address: 0x1a6720 - 0x1a6760
void sub_001A6720_0x1a6720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6720_0x1a6720");
#endif

    switch (ctx->pc) {
        case 0x1a6744u: goto label_1a6744;
        case 0x1a674cu: goto label_1a674c;
        case 0x1a6754u: goto label_1a6754;
        default: break;
    }

    ctx->pc = 0x1a6720u;

    // 0x1a6720: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a6720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a6724: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6724u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6728: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a6728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a672c: 0x24630a10  addiu       $v1, $v1, 0xA10
    ctx->pc = 0x1a672cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2576));
    // 0x1a6730: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x1a6730u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a6734: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A6734u;
    {
        const bool branch_taken_0x1a6734 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6734) {
            ctx->pc = 0x1A6744u;
            goto label_1a6744;
        }
    }
    ctx->pc = 0x1A673Cu;
    // 0x1a673c: 0xc060120  jal         func_180480
    ctx->pc = 0x1A673Cu;
    SET_GPR_U32(ctx, 31, 0x1A6744u);
    ctx->pc = 0x1A6740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A673Cu;
            // 0x1a6740: 0x90640006  lbu         $a0, 0x6($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180480u;
    if (runtime->hasFunction(0x180480u)) {
        auto targetFn = runtime->lookupFunction(0x180480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6744u; }
        if (ctx->pc != 0x1A6744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180480_0x180480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6744u; }
        if (ctx->pc != 0x1A6744u) { return; }
    }
    ctx->pc = 0x1A6744u;
label_1a6744:
    // 0x1a6744: 0xc0600c4  jal         func_180310
    ctx->pc = 0x1A6744u;
    SET_GPR_U32(ctx, 31, 0x1A674Cu);
    ctx->pc = 0x180310u;
    if (runtime->hasFunction(0x180310u)) {
        auto targetFn = runtime->lookupFunction(0x180310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A674Cu; }
        if (ctx->pc != 0x1A674Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180310_0x180310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A674Cu; }
        if (ctx->pc != 0x1A674Cu) { return; }
    }
    ctx->pc = 0x1A674Cu;
label_1a674c:
    // 0x1a674c: 0xc0622de  jal         func_188B78
    ctx->pc = 0x1A674Cu;
    SET_GPR_U32(ctx, 31, 0x1A6754u);
    ctx->pc = 0x188B78u;
    if (runtime->hasFunction(0x188B78u)) {
        auto targetFn = runtime->lookupFunction(0x188B78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6754u; }
        if (ctx->pc != 0x1A6754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188B78_0x188b78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6754u; }
        if (ctx->pc != 0x1A6754u) { return; }
    }
    ctx->pc = 0x1A6754u;
label_1a6754:
    // 0x1a6754: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a6754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a6758: 0x3e00008  jr          $ra
    ctx->pc = 0x1A6758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A675Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6758u;
            // 0x1a675c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A6744u: goto label_1a6744;
            case 0x1A674Cu: goto label_1a674c;
            case 0x1A6754u: goto label_1a6754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6760u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
