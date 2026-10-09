#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FD58
// Address: 0x15fd58 - 0x15fdac
void sub_0015FD58_0x15fd58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FD58_0x15fd58");
#endif

    switch (ctx->pc) {
        case 0x15fd6cu: goto label_15fd6c;
        case 0x15fd84u: goto label_15fd84;
        case 0x15fd98u: goto label_15fd98;
        default: break;
    }

    ctx->pc = 0x15fd58u;

    // 0x15fd58: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15fd58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15fd5c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x15fd5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x15fd60: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x15fd60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x15fd64: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FD64u;
    SET_GPR_U32(ctx, 31, 0x15FD6Cu);
    ctx->pc = 0x15FD68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD64u;
            // 0x15fd68: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD6Cu; }
        if (ctx->pc != 0x15FD6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD6Cu; }
        if (ctx->pc != 0x15FD6Cu) { return; }
    }
    ctx->pc = 0x15FD6Cu;
label_15fd6c:
    // 0x15fd6c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15fd6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fd70: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15FD70u;
    {
        const bool branch_taken_0x15fd70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD70u;
            // 0x15fd74: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd70) {
            ctx->pc = 0x15FD90u;
            goto label_15fd90;
        }
    }
    ctx->pc = 0x15FD78u;
    // 0x15fd78: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fd78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fd7c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FD7Cu;
    SET_GPR_U32(ctx, 31, 0x15FD84u);
    ctx->pc = 0x15FD80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD7Cu;
            // 0x15fd80: 0x2484f428  addiu       $a0, $a0, -0xBD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD84u; }
        if (ctx->pc != 0x15FD84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD84u; }
        if (ctx->pc != 0x15FD84u) { return; }
    }
    ctx->pc = 0x15FD84u;
label_15fd84:
    // 0x15fd84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15FD84u;
    {
        const bool branch_taken_0x15fd84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FD88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD84u;
            // 0x15fd88: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd84) {
            ctx->pc = 0x15FD9Cu;
            goto label_15fd9c;
        }
    }
    ctx->pc = 0x15FD8Cu;
    // 0x15fd8c: 0x0  nop
    ctx->pc = 0x15fd8cu;
    // NOP
label_15fd90:
    // 0x15fd90: 0xc057fa8  jal         func_15FEA0
    ctx->pc = 0x15FD90u;
    SET_GPR_U32(ctx, 31, 0x15FD98u);
    ctx->pc = 0x15FEA0u;
    if (runtime->hasFunction(0x15FEA0u)) {
        auto targetFn = runtime->lookupFunction(0x15FEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD98u; }
        if (ctx->pc != 0x15FD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FEA0_0x15fea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD98u; }
        if (ctx->pc != 0x15FD98u) { return; }
    }
    ctx->pc = 0x15FD98u;
label_15fd98:
    // 0x15fd98: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x15fd98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_15fd9c:
    // 0x15fd9c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x15fd9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15fda0: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x15fda0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15fda4: 0x3e00008  jr          $ra
    ctx->pc = 0x15FDA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDA4u;
            // 0x15fda8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FDACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
