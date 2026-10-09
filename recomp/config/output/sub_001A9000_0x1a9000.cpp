#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9000
// Address: 0x1a9000 - 0x1a903c
void sub_001A9000_0x1a9000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9000_0x1a9000");
#endif

    switch (ctx->pc) {
        case 0x1a9010u: goto label_1a9010;
        case 0x1a9028u: goto label_1a9028;
        default: break;
    }

    ctx->pc = 0x1a9000u;

    // 0x1a9000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9004: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a9008: 0xc057a80  jal         func_15EA00
    ctx->pc = 0x1A9008u;
    SET_GPR_U32(ctx, 31, 0x1A9010u);
    ctx->pc = 0x15EA00u;
    if (runtime->hasFunction(0x15EA00u)) {
        auto targetFn = runtime->lookupFunction(0x15EA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9010u; }
        if (ctx->pc != 0x1A9010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EA00_0x15ea00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9010u; }
        if (ctx->pc != 0x1A9010u) { return; }
    }
    ctx->pc = 0x1A9010u;
label_1a9010:
    // 0x1a9010: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9010u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9014: 0x8c230ec0  lw          $v1, 0xEC0($at)
    ctx->pc = 0x1a9014u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a9018: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A9018u;
    {
        const bool branch_taken_0x1a9018 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9018) {
            ctx->pc = 0x1A9030u;
            goto label_1a9030;
        }
    }
    ctx->pc = 0x1A9020u;
    // 0x1a9020: 0xc04ae00  jal         func_12B800
    ctx->pc = 0x1A9020u;
    SET_GPR_U32(ctx, 31, 0x1A9028u);
    ctx->pc = 0x12B800u;
    if (runtime->hasFunction(0x12B800u)) {
        auto targetFn = runtime->lookupFunction(0x12B800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9028u; }
        if (ctx->pc != 0x1A9028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B800_0x12b800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9028u; }
        if (ctx->pc != 0x1A9028u) { return; }
    }
    ctx->pc = 0x1A9028u;
label_1a9028:
    // 0x1a9028: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9028u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a902c: 0xac200ec0  sw          $zero, 0xEC0($at)
    ctx->pc = 0x1a902cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 3776), GPR_U32(ctx, 0));
label_1a9030:
    // 0x1a9030: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a9030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9034: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9034u;
            // 0x1a9038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9010u: goto label_1a9010;
            case 0x1A9028u: goto label_1a9028;
            case 0x1A9030u: goto label_1a9030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A903Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
