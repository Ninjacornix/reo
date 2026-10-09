#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EF58
// Address: 0x15ef58 - 0x15efa0
void sub_0015EF58_0x15ef58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EF58_0x15ef58");
#endif

    switch (ctx->pc) {
        case 0x15ef68u: goto label_15ef68;
        case 0x15ef8cu: goto label_15ef8c;
        default: break;
    }

    ctx->pc = 0x15ef58u;

    // 0x15ef58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ef58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ef5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ef5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ef60: 0xc05c81e  jal         func_172078
    ctx->pc = 0x15EF60u;
    SET_GPR_U32(ctx, 31, 0x15EF68u);
    ctx->pc = 0x15EF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF60u;
            // 0x15ef64: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172078u;
    if (runtime->hasFunction(0x172078u)) {
        auto targetFn = runtime->lookupFunction(0x172078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF68u; }
        if (ctx->pc != 0x15EF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172078_0x172078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF68u; }
        if (ctx->pc != 0x15EF68u) { return; }
    }
    ctx->pc = 0x15EF68u;
label_15ef68:
    // 0x15ef68: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15ef68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ef6c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15EF6Cu;
    {
        const bool branch_taken_0x15ef6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF6Cu;
            // 0x15ef70: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef6c) {
            ctx->pc = 0x15EF90u;
            goto label_15ef90;
        }
    }
    ctx->pc = 0x15EF74u;
    // 0x15ef74: 0x10440006  beq         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15EF74u;
    {
        const bool branch_taken_0x15ef74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x15EF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF74u;
            // 0x15ef78: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef74) {
            ctx->pc = 0x15EF90u;
            goto label_15ef90;
        }
    }
    ctx->pc = 0x15EF7Cu;
    // 0x15ef7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ef7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ef80: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15ef80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ef84: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15EF84u;
    SET_GPR_U32(ctx, 31, 0x15EF8Cu);
    ctx->pc = 0x15EF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF84u;
            // 0x15ef88: 0x2484f030  addiu       $a0, $a0, -0xFD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF8Cu; }
        if (ctx->pc != 0x15EF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF8Cu; }
        if (ctx->pc != 0x15EF8Cu) { return; }
    }
    ctx->pc = 0x15EF8Cu;
label_15ef8c:
    // 0x15ef8c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x15ef8cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15ef90:
    // 0x15ef90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef94: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x15ef94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ef98: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF98u;
            // 0x15ef9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EF68u: goto label_15ef68;
            case 0x15EF8Cu: goto label_15ef8c;
            case 0x15EF90u: goto label_15ef90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EFA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
