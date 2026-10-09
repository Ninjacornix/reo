#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EE48
// Address: 0x15ee48 - 0x15ee88
void sub_0015EE48_0x15ee48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EE48_0x15ee48");
#endif

    switch (ctx->pc) {
        case 0x15ee58u: goto label_15ee58;
        case 0x15ee68u: goto label_15ee68;
        case 0x15ee74u: goto label_15ee74;
        default: break;
    }

    ctx->pc = 0x15ee48u;

    // 0x15ee48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ee48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee4c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ee4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ee50: 0xc05c89e  jal         func_172278
    ctx->pc = 0x15EE50u;
    SET_GPR_U32(ctx, 31, 0x15EE58u);
    ctx->pc = 0x15EE54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE50u;
            // 0x15ee54: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172278u;
    if (runtime->hasFunction(0x172278u)) {
        auto targetFn = runtime->lookupFunction(0x172278u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE58u; }
        if (ctx->pc != 0x15EE58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172278_0x172278(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE58u; }
        if (ctx->pc != 0x15EE58u) { return; }
    }
    ctx->pc = 0x15EE58u;
label_15ee58:
    // 0x15ee58: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15EE58u;
    {
        const bool branch_taken_0x15ee58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE58u;
            // 0x15ee5c: 0x2404fec9  addiu       $a0, $zero, -0x137 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966985));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ee58) {
            ctx->pc = 0x15EE78u;
            goto label_15ee78;
        }
    }
    ctx->pc = 0x15EE60u;
    // 0x15ee60: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15EE60u;
    SET_GPR_U32(ctx, 31, 0x15EE68u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE68u; }
        if (ctx->pc != 0x15EE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE68u; }
        if (ctx->pc != 0x15EE68u) { return; }
    }
    ctx->pc = 0x15EE68u;
label_15ee68:
    // 0x15ee68: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ee68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ee6c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15EE6Cu;
    SET_GPR_U32(ctx, 31, 0x15EE74u);
    ctx->pc = 0x15EE70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE6Cu;
            // 0x15ee70: 0x2484eff0  addiu       $a0, $a0, -0x1010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE74u; }
        if (ctx->pc != 0x15EE74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE74u; }
        if (ctx->pc != 0x15EE74u) { return; }
    }
    ctx->pc = 0x15EE74u;
label_15ee74:
    // 0x15ee74: 0x2402fec9  addiu       $v0, $zero, -0x137
    ctx->pc = 0x15ee74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966985));
label_15ee78:
    // 0x15ee78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ee78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee7c: 0x3e00008  jr          $ra
    ctx->pc = 0x15EE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE7Cu;
            // 0x15ee80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE58u: goto label_15ee58;
            case 0x15EE68u: goto label_15ee68;
            case 0x15EE74u: goto label_15ee74;
            case 0x15EE78u: goto label_15ee78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE84u;
    // 0x15ee84: 0x0  nop
    ctx->pc = 0x15ee84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
