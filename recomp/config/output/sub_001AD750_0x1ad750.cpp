#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD750
// Address: 0x1ad750 - 0x1ad788
void sub_001AD750_0x1ad750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD750_0x1ad750");
#endif

    switch (ctx->pc) {
        case 0x1ad774u: goto label_1ad774;
        case 0x1ad77cu: goto label_1ad77c;
        default: break;
    }

    ctx->pc = 0x1ad750u;

    // 0x1ad750: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ad750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ad754: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ad754u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ad758: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ad758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ad75c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad75cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad760: 0x8c223944  lw          $v0, 0x3944($at)
    ctx->pc = 0x1ad760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14660)));
    // 0x1ad764: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD764u;
    {
        const bool branch_taken_0x1ad764 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD764u;
            // 0x1ad768: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad764) {
            ctx->pc = 0x1AD774u;
            goto label_1ad774;
        }
    }
    ctx->pc = 0x1AD76Cu;
    // 0x1ad76c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1AD76Cu;
    SET_GPR_U32(ctx, 31, 0x1AD774u);
    ctx->pc = 0x1AD770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD76Cu;
            // 0x1ad770: 0x8c640104  lw          $a0, 0x104($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 260)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD774u; }
        if (ctx->pc != 0x1AD774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD774u; }
        if (ctx->pc != 0x1AD774u) { return; }
    }
    ctx->pc = 0x1AD774u;
label_1ad774:
    // 0x1ad774: 0xc06b570  jal         func_1AD5C0
    ctx->pc = 0x1AD774u;
    SET_GPR_U32(ctx, 31, 0x1AD77Cu);
    ctx->pc = 0x1AD5C0u;
    if (runtime->hasFunction(0x1AD5C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD77Cu; }
        if (ctx->pc != 0x1AD77Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD5C0_0x1ad5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD77Cu; }
        if (ctx->pc != 0x1AD77Cu) { return; }
    }
    ctx->pc = 0x1AD77Cu;
label_1ad77c:
    // 0x1ad77c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ad77cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad780: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD780u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD780u;
            // 0x1ad784: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD774u: goto label_1ad774;
            case 0x1AD77Cu: goto label_1ad77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD788u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
