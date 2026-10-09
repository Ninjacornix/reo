#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167D20
// Address: 0x167d20 - 0x167d70
void sub_00167D20_0x167d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167D20_0x167d20");
#endif

    switch (ctx->pc) {
        case 0x167d30u: goto label_167d30;
        case 0x167d58u: goto label_167d58;
        default: break;
    }

    ctx->pc = 0x167d20u;

    // 0x167d20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x167d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167d24: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x167d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x167d28: 0xc059bfa  jal         func_166FE8
    ctx->pc = 0x167D28u;
    SET_GPR_U32(ctx, 31, 0x167D30u);
    ctx->pc = 0x167D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167D28u;
            // 0x167d2c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FE8u;
    if (runtime->hasFunction(0x166FE8u)) {
        auto targetFn = runtime->lookupFunction(0x166FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D30u; }
        if (ctx->pc != 0x167D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FE8_0x166fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D30u; }
        if (ctx->pc != 0x167D30u) { return; }
    }
    ctx->pc = 0x167D30u;
label_167d30:
    // 0x167d30: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x167d30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167d34: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x167d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x167d38: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x167d38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167d3c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x167d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x167d40: 0x3e00008  jr          $ra
    ctx->pc = 0x167D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167D40u;
            // 0x167d44: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167D30u: goto label_167d30;
            case 0x167D58u: goto label_167d58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167D48u;
    // 0x167d48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x167d48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167d4c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x167d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x167d50: 0xc059bf4  jal         func_166FD0
    ctx->pc = 0x167D50u;
    SET_GPR_U32(ctx, 31, 0x167D58u);
    ctx->pc = 0x167D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167D50u;
            // 0x167d54: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FD0u;
    if (runtime->hasFunction(0x166FD0u)) {
        auto targetFn = runtime->lookupFunction(0x166FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D58u; }
        if (ctx->pc != 0x167D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FD0_0x166fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167D58u; }
        if (ctx->pc != 0x167D58u) { return; }
    }
    ctx->pc = 0x167D58u;
label_167d58:
    // 0x167d58: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x167d58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167d5c: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x167d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x167d60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x167d60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167d64: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x167d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x167d68: 0x3e00008  jr          $ra
    ctx->pc = 0x167D68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167D68u;
            // 0x167d6c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167D30u: goto label_167d30;
            case 0x167D58u: goto label_167d58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167D70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
