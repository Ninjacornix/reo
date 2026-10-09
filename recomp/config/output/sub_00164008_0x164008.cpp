#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164008
// Address: 0x164008 - 0x164038
void sub_00164008_0x164008(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164008_0x164008");
#endif

    switch (ctx->pc) {
        case 0x164018u: goto label_164018;
        case 0x16402cu: goto label_16402c;
        default: break;
    }

    ctx->pc = 0x164008u;

    // 0x164008: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164008u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16400c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16400cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164010: 0xc05799e  jal         func_15E678
    ctx->pc = 0x164010u;
    SET_GPR_U32(ctx, 31, 0x164018u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164018u; }
        if (ctx->pc != 0x164018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164018u; }
        if (ctx->pc != 0x164018u) { return; }
    }
    ctx->pc = 0x164018u;
label_164018:
    // 0x164018: 0x8c430048  lw          $v1, 0x48($v0)
    ctx->pc = 0x164018u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x16401c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16401Cu;
    {
        const bool branch_taken_0x16401c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x164020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16401Cu;
            // 0x164020: 0x8c44004c  lw          $a0, 0x4C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 76)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16401c) {
            ctx->pc = 0x16402Cu;
            goto label_16402c;
        }
    }
    ctx->pc = 0x164024u;
    // 0x164024: 0x60f809  jalr        $v1
    ctx->pc = 0x164024u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x16402Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16402Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164018u: goto label_164018;
            case 0x16402Cu: goto label_16402c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16402Cu; }
            if (ctx->pc != 0x16402Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16402Cu;
label_16402c:
    // 0x16402c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16402cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164030: 0x3e00008  jr          $ra
    ctx->pc = 0x164030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164030u;
            // 0x164034: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164018u: goto label_164018;
            case 0x16402Cu: goto label_16402c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
