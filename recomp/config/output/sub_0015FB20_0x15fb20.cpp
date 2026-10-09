#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FB20
// Address: 0x15fb20 - 0x15fbb0
void sub_0015FB20_0x15fb20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FB20_0x15fb20");
#endif

    switch (ctx->pc) {
        case 0x15fb34u: goto label_15fb34;
        case 0x15fb48u: goto label_15fb48;
        case 0x15fb74u: goto label_15fb74;
        case 0x15fb88u: goto label_15fb88;
        default: break;
    }

    ctx->pc = 0x15fb20u;

    // 0x15fb20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fb20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fb24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fb28: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15fb28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15fb2c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FB2Cu;
    SET_GPR_U32(ctx, 31, 0x15FB34u);
    ctx->pc = 0x15FB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB2Cu;
            // 0x15fb30: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB34u; }
        if (ctx->pc != 0x15FB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB34u; }
        if (ctx->pc != 0x15FB34u) { return; }
    }
    ctx->pc = 0x15FB34u;
label_15fb34:
    // 0x15fb34: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15FB34u;
    {
        const bool branch_taken_0x15fb34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15fb34) {
            ctx->pc = 0x15FB38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB34u;
            // 0x15fb38: 0x8e020040  lw          $v0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15FB4Cu;
            goto label_15fb4c;
        }
    }
    ctx->pc = 0x15FB3Cu;
    // 0x15fb3c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fb3cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fb40: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FB40u;
    SET_GPR_U32(ctx, 31, 0x15FB48u);
    ctx->pc = 0x15FB44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB40u;
            // 0x15fb44: 0x2484f2d8  addiu       $a0, $a0, -0xD28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB48u; }
        if (ctx->pc != 0x15FB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB48u; }
        if (ctx->pc != 0x15FB48u) { return; }
    }
    ctx->pc = 0x15FB48u;
label_15fb48:
    // 0x15fb48: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15fb48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15fb4c:
    // 0x15fb4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fb4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fb50: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15fb50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fb54: 0x3e00008  jr          $ra
    ctx->pc = 0x15FB54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB54u;
            // 0x15fb58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FB34u: goto label_15fb34;
            case 0x15FB48u: goto label_15fb48;
            case 0x15FB4Cu: goto label_15fb4c;
            case 0x15FB74u: goto label_15fb74;
            case 0x15FB88u: goto label_15fb88;
            case 0x15FBA0u: goto label_15fba0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FB5Cu;
    // 0x15fb5c: 0x0  nop
    ctx->pc = 0x15fb5cu;
    // NOP
    // 0x15fb60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fb60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fb64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fb64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fb68: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15fb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15fb6c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FB6Cu;
    SET_GPR_U32(ctx, 31, 0x15FB74u);
    ctx->pc = 0x15FB70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB6Cu;
            // 0x15fb70: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB74u; }
        if (ctx->pc != 0x15FB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB74u; }
        if (ctx->pc != 0x15FB74u) { return; }
    }
    ctx->pc = 0x15FB74u;
label_15fb74:
    // 0x15fb74: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15FB74u;
    {
        const bool branch_taken_0x15fb74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB74u;
            // 0x15fb78: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fb74) {
            ctx->pc = 0x15FBA0u;
            goto label_15fba0;
        }
    }
    ctx->pc = 0x15FB7Cu;
    // 0x15fb7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fb7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fb80: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FB80u;
    SET_GPR_U32(ctx, 31, 0x15FB88u);
    ctx->pc = 0x15FB84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB80u;
            // 0x15fb84: 0x2484f308  addiu       $a0, $a0, -0xCF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB88u; }
        if (ctx->pc != 0x15FB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FB88u; }
        if (ctx->pc != 0x15FB88u) { return; }
    }
    ctx->pc = 0x15FB88u;
label_15fb88:
    // 0x15fb88: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15fb88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fb8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fb8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fb90: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15fb90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fb94: 0x3e00008  jr          $ra
    ctx->pc = 0x15FB94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FB98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB94u;
            // 0x15fb98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FB34u: goto label_15fb34;
            case 0x15FB48u: goto label_15fb48;
            case 0x15FB4Cu: goto label_15fb4c;
            case 0x15FB74u: goto label_15fb74;
            case 0x15FB88u: goto label_15fb88;
            case 0x15FBA0u: goto label_15fba0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FB9Cu;
    // 0x15fb9c: 0x0  nop
    ctx->pc = 0x15fb9cu;
    // NOP
label_15fba0:
    // 0x15fba0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fba0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fba4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15fba4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fba8: 0x8057ff8  j           func_15FFE0
    ctx->pc = 0x15FBA8u;
    ctx->pc = 0x15FBACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FBA8u;
            // 0x15fbac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFE0u;
    if (runtime->hasFunction(0x15FFE0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FFE0_0x15ffe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FBB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
