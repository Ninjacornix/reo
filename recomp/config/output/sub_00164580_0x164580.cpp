#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164580
// Address: 0x164580 - 0x1645c0
void sub_00164580_0x164580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164580_0x164580");
#endif

    switch (ctx->pc) {
        case 0x164594u: goto label_164594;
        default: break;
    }

    ctx->pc = 0x164580u;

    // 0x164580: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164588: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x164588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16458c: 0xc04c390  jal         func_130E40
    ctx->pc = 0x16458Cu;
    SET_GPR_U32(ctx, 31, 0x164594u);
    ctx->pc = 0x164590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16458Cu;
            // 0x164590: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E40u;
    if (runtime->hasFunction(0x130E40u)) {
        auto targetFn = runtime->lookupFunction(0x130E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164594u; }
        if (ctx->pc != 0x164594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E40_0x130e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164594u; }
        if (ctx->pc != 0x164594u) { return; }
    }
    ctx->pc = 0x164594u;
label_164594:
    // 0x164594: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x164594u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x164598: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x164598u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16459c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16459cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1645a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1645A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1645A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1645A0u;
            // 0x1645a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164594u: goto label_164594;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1645A8u;
    // 0x1645a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1645a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1645ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1645acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1645b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1645b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1645b4: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x1645B4u;
    ctx->pc = 0x1645B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1645B4u;
            // 0x1645b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1645BCu;
    // 0x1645bc: 0x0  nop
    ctx->pc = 0x1645bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
