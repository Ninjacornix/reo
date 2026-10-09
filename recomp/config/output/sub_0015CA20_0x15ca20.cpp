#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015CA20
// Address: 0x15ca20 - 0x15ca68
void sub_0015CA20_0x15ca20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015CA20_0x15ca20");
#endif

    switch (ctx->pc) {
        case 0x15ca30u: goto label_15ca30;
        case 0x15ca40u: goto label_15ca40;
        default: break;
    }

    ctx->pc = 0x15ca20u;

    // 0x15ca20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ca20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ca24: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ca24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ca28: 0xc05ce6a  jal         func_1739A8
    ctx->pc = 0x15CA28u;
    SET_GPR_U32(ctx, 31, 0x15CA30u);
    ctx->pc = 0x1739A8u;
    if (runtime->hasFunction(0x1739A8u)) {
        auto targetFn = runtime->lookupFunction(0x1739A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CA30u; }
        if (ctx->pc != 0x15CA30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001739A8_0x1739a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CA30u; }
        if (ctx->pc != 0x15CA30u) { return; }
    }
    ctx->pc = 0x15CA30u;
label_15ca30:
    // 0x15ca30: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15CA30u;
    {
        const bool branch_taken_0x15ca30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA30u;
            // 0x15ca34: 0x2404fece  addiu       $a0, $zero, -0x132 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966990));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ca30) {
            ctx->pc = 0x15CA58u;
            goto label_15ca58;
        }
    }
    ctx->pc = 0x15CA38u;
    // 0x15ca38: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15CA38u;
    SET_GPR_U32(ctx, 31, 0x15CA40u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CA40u; }
        if (ctx->pc != 0x15CA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CA40u; }
        if (ctx->pc != 0x15CA40u) { return; }
    }
    ctx->pc = 0x15CA40u;
label_15ca40:
    // 0x15ca40: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ca40u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ca44: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ca44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ca48: 0x2484e8c0  addiu       $a0, $a0, -0x1740
    ctx->pc = 0x15ca48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961344));
    // 0x15ca4c: 0x8058dd4  j           func_163750
    ctx->pc = 0x15CA4Cu;
    ctx->pc = 0x15CA50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA4Cu;
            // 0x15ca50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15CA54u;
    // 0x15ca54: 0x0  nop
    ctx->pc = 0x15ca54u;
    // NOP
label_15ca58:
    // 0x15ca58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ca58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ca5c: 0x3e00008  jr          $ra
    ctx->pc = 0x15CA5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15CA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA5Cu;
            // 0x15ca60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15CA30u: goto label_15ca30;
            case 0x15CA40u: goto label_15ca40;
            case 0x15CA58u: goto label_15ca58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15CA64u;
    // 0x15ca64: 0x0  nop
    ctx->pc = 0x15ca64u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
