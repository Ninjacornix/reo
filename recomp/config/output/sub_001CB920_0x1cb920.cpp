#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB920
// Address: 0x1cb920 - 0x1cb970
void sub_001CB920_0x1cb920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB920_0x1cb920");
#endif

    switch (ctx->pc) {
        case 0x1cb938u: goto label_1cb938;
        case 0x1cb944u: goto label_1cb944;
        case 0x1cb950u: goto label_1cb950;
        default: break;
    }

    ctx->pc = 0x1cb920u;

    // 0x1cb920: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb924: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb928: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb92c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb92cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb930: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CB930u;
    SET_GPR_U32(ctx, 31, 0x1CB938u);
    ctx->pc = 0x1CB934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB930u;
            // 0x1cb934: 0xac22da08  sw          $v0, -0x25F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957576), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB938u; }
        if (ctx->pc != 0x1CB938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB938u; }
        if (ctx->pc != 0x1CB938u) { return; }
    }
    ctx->pc = 0x1CB938u;
label_1cb938:
    // 0x1cb938: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb938u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb93c: 0xc045198  jal         func_114660
    ctx->pc = 0x1CB93Cu;
    SET_GPR_U32(ctx, 31, 0x1CB944u);
    ctx->pc = 0x1CB940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB93Cu;
            // 0x1cb940: 0x8c246000  lw          $a0, 0x6000($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB944u; }
        if (ctx->pc != 0x1CB944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB944u; }
        if (ctx->pc != 0x1CB944u) { return; }
    }
    ctx->pc = 0x1CB944u;
label_1cb944:
    // 0x1cb944: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb944u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb948: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CB948u;
    SET_GPR_U32(ctx, 31, 0x1CB950u);
    ctx->pc = 0x1CB94Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB948u;
            // 0x1cb94c: 0x8c246000  lw          $a0, 0x6000($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB950u; }
        if (ctx->pc != 0x1CB950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB950u; }
        if (ctx->pc != 0x1CB950u) { return; }
    }
    ctx->pc = 0x1CB950u;
label_1cb950:
    // 0x1cb950: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb950u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb954: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb954u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb958: 0xac236000  sw          $v1, 0x6000($at)
    ctx->pc = 0x1cb958u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24576), GPR_U32(ctx, 3));
    // 0x1cb95c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb95cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb960: 0xac235ff8  sw          $v1, 0x5FF8($at)
    ctx->pc = 0x1cb960u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24568), GPR_U32(ctx, 3));
    // 0x1cb964: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb968: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB968u;
            // 0x1cb96c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB938u: goto label_1cb938;
            case 0x1CB944u: goto label_1cb944;
            case 0x1CB950u: goto label_1cb950;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB970u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
