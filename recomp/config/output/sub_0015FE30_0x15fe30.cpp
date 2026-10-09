#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FE30
// Address: 0x15fe30 - 0x15fe84
void sub_0015FE30_0x15fe30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FE30_0x15fe30");
#endif

    switch (ctx->pc) {
        case 0x15fe44u: goto label_15fe44;
        case 0x15fe5cu: goto label_15fe5c;
        case 0x15fe70u: goto label_15fe70;
        default: break;
    }

    ctx->pc = 0x15fe30u;

    // 0x15fe30: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15fe30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15fe34: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x15fe34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x15fe38: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x15fe38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x15fe3c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FE3Cu;
    SET_GPR_U32(ctx, 31, 0x15FE44u);
    ctx->pc = 0x15FE40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE3Cu;
            // 0x15fe40: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE44u; }
        if (ctx->pc != 0x15FE44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE44u; }
        if (ctx->pc != 0x15FE44u) { return; }
    }
    ctx->pc = 0x15FE44u;
label_15fe44:
    // 0x15fe44: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15fe44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fe48: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15FE48u;
    {
        const bool branch_taken_0x15fe48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE48u;
            // 0x15fe4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fe48) {
            ctx->pc = 0x15FE68u;
            goto label_15fe68;
        }
    }
    ctx->pc = 0x15FE50u;
    // 0x15fe50: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fe50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fe54: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FE54u;
    SET_GPR_U32(ctx, 31, 0x15FE5Cu);
    ctx->pc = 0x15FE58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE54u;
            // 0x15fe58: 0x2484f4b8  addiu       $a0, $a0, -0xB48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE5Cu; }
        if (ctx->pc != 0x15FE5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE5Cu; }
        if (ctx->pc != 0x15FE5Cu) { return; }
    }
    ctx->pc = 0x15FE5Cu;
label_15fe5c:
    // 0x15fe5c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15FE5Cu;
    {
        const bool branch_taken_0x15fe5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE5Cu;
            // 0x15fe60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fe5c) {
            ctx->pc = 0x15FE74u;
            goto label_15fe74;
        }
    }
    ctx->pc = 0x15FE64u;
    // 0x15fe64: 0x0  nop
    ctx->pc = 0x15fe64u;
    // NOP
label_15fe68:
    // 0x15fe68: 0xc057fa8  jal         func_15FEA0
    ctx->pc = 0x15FE68u;
    SET_GPR_U32(ctx, 31, 0x15FE70u);
    ctx->pc = 0x15FEA0u;
    if (runtime->hasFunction(0x15FEA0u)) {
        auto targetFn = runtime->lookupFunction(0x15FEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE70u; }
        if (ctx->pc != 0x15FE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FEA0_0x15fea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE70u; }
        if (ctx->pc != 0x15FE70u) { return; }
    }
    ctx->pc = 0x15FE70u;
label_15fe70:
    // 0x15fe70: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x15fe70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_15fe74:
    // 0x15fe74: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x15fe74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15fe78: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x15fe78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15fe7c: 0x3e00008  jr          $ra
    ctx->pc = 0x15FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE7Cu;
            // 0x15fe80: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FE84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
