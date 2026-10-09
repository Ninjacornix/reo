#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180F28
// Address: 0x180f28 - 0x180f5c
void sub_00180F28_0x180f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180F28_0x180f28");
#endif

    switch (ctx->pc) {
        case 0x180f4cu: goto label_180f4c;
        default: break;
    }

    ctx->pc = 0x180f28u;

    // 0x180f28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180f28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180f2c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180f30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180f34: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x180f34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180f38: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180F38u;
    {
        const bool branch_taken_0x180f38 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x180F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F38u;
            // 0x180f3c: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f38) {
            ctx->pc = 0x180F50u;
            goto label_180f50;
        }
    }
    ctx->pc = 0x180F40u;
    // 0x180f40: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180f40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180f44: 0xc045130  jal         func_1144C0
    ctx->pc = 0x180F44u;
    SET_GPR_U32(ctx, 31, 0x180F4Cu);
    ctx->pc = 0x180F48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180F44u;
            // 0x180f48: 0x8c449a20  lw          $a0, -0x65E0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941216)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144C0u;
    if (runtime->hasFunction(0x1144C0u)) {
        auto targetFn = runtime->lookupFunction(0x1144C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F4Cu; }
        if (ctx->pc != 0x180F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144C0_0x1144c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F4Cu; }
        if (ctx->pc != 0x180F4Cu) { return; }
    }
    ctx->pc = 0x180F4Cu;
label_180f4c:
    // 0x180f4c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180f4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180f50:
    // 0x180f50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x180f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180f54: 0x3e00008  jr          $ra
    ctx->pc = 0x180F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F54u;
            // 0x180f58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180F4Cu: goto label_180f4c;
            case 0x180F50u: goto label_180f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180F5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
