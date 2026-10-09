#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172078
// Address: 0x172078 - 0x1720c8
void sub_00172078_0x172078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172078_0x172078");
#endif

    switch (ctx->pc) {
        case 0x17208cu: goto label_17208c;
        case 0x1720a4u: goto label_1720a4;
        default: break;
    }

    ctx->pc = 0x172078u;

    // 0x172078: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17207c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17207cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172080: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x172084: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x172084u;
    SET_GPR_U32(ctx, 31, 0x17208Cu);
    ctx->pc = 0x172088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172084u;
            // 0x172088: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17208Cu; }
        if (ctx->pc != 0x17208Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17208Cu; }
        if (ctx->pc != 0x17208Cu) { return; }
    }
    ctx->pc = 0x17208Cu;
label_17208c:
    // 0x17208c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17208cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x172090: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x172090u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172094: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x172094u;
    {
        const bool branch_taken_0x172094 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172094u;
            // 0x172098: 0x34a50141  ori         $a1, $a1, 0x141 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)321);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172094) {
            ctx->pc = 0x1720B0u;
            goto label_1720b0;
        }
    }
    ctx->pc = 0x17209Cu;
    // 0x17209c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x17209Cu;
    SET_GPR_U32(ctx, 31, 0x1720A4u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1720A4u; }
        if (ctx->pc != 0x1720A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1720A4u; }
        if (ctx->pc != 0x1720A4u) { return; }
    }
    ctx->pc = 0x1720A4u;
label_1720a4:
    // 0x1720a4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1720A4u;
    {
        const bool branch_taken_0x1720a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1720A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1720A4u;
            // 0x1720a8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1720a4) {
            ctx->pc = 0x1720B4u;
            goto label_1720b4;
        }
    }
    ctx->pc = 0x1720ACu;
    // 0x1720ac: 0x0  nop
    ctx->pc = 0x1720acu;
    // NOP
label_1720b0:
    // 0x1720b0: 0x8e020050  lw          $v0, 0x50($s0)
    ctx->pc = 0x1720b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
label_1720b4:
    // 0x1720b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1720b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1720b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1720b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1720bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1720BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1720C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1720BCu;
            // 0x1720c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17208Cu: goto label_17208c;
            case 0x1720A4u: goto label_1720a4;
            case 0x1720B0u: goto label_1720b0;
            case 0x1720B4u: goto label_1720b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1720C4u;
    // 0x1720c4: 0x0  nop
    ctx->pc = 0x1720c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
