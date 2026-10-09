#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180EF0
// Address: 0x180ef0 - 0x180f24
void sub_00180EF0_0x180ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180EF0_0x180ef0");
#endif

    switch (ctx->pc) {
        case 0x180f14u: goto label_180f14;
        default: break;
    }

    ctx->pc = 0x180ef0u;

    // 0x180ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180ef4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ef8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180efc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x180efcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180f00: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180F00u;
    {
        const bool branch_taken_0x180f00 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x180F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F00u;
            // 0x180f04: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f00) {
            ctx->pc = 0x180F18u;
            goto label_180f18;
        }
    }
    ctx->pc = 0x180F08u;
    // 0x180f08: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180f08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180f0c: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x180F0Cu;
    SET_GPR_U32(ctx, 31, 0x180F14u);
    ctx->pc = 0x180F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180F0Cu;
            // 0x180f10: 0x8c449a20  lw          $a0, -0x65E0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941216)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F14u; }
        if (ctx->pc != 0x180F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F14u; }
        if (ctx->pc != 0x180F14u) { return; }
    }
    ctx->pc = 0x180F14u;
label_180f14:
    // 0x180f14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180f14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180f18:
    // 0x180f18: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x180f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x180F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F1Cu;
            // 0x180f20: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180F14u: goto label_180f14;
            case 0x180F18u: goto label_180f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180F24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
