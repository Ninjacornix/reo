#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102BB0
// Address: 0x102bb0 - 0x102bec
void sub_00102BB0_0x102bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102BB0_0x102bb0");
#endif

    switch (ctx->pc) {
        case 0x102bc0u: goto label_102bc0;
        default: break;
    }

    ctx->pc = 0x102bb0u;

    // 0x102bb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x102bb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x102bb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x102bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x102bb8: 0xc040b08  jal         func_102C20
    ctx->pc = 0x102BB8u;
    SET_GPR_U32(ctx, 31, 0x102BC0u);
    ctx->pc = 0x102C20u;
    if (runtime->hasFunction(0x102C20u)) {
        auto targetFn = runtime->lookupFunction(0x102C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102BC0u; }
        if (ctx->pc != 0x102BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102C20_0x102c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102BC0u; }
        if (ctx->pc != 0x102BC0u) { return; }
    }
    ctx->pc = 0x102BC0u;
label_102bc0:
    // 0x102bc0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x102bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102bc4: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102BC4u;
    {
        const bool branch_taken_0x102bc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x102BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BC4u;
            // 0x102bc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102bc4) {
            ctx->pc = 0x102BE0u;
            goto label_102be0;
        }
    }
    ctx->pc = 0x102BCCu;
    // 0x102bcc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102bccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102bd0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x102bd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x102bd4: 0x34633c10  ori         $v1, $v1, 0x3C10
    ctx->pc = 0x102bd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15376);
    // 0x102bd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102bdc: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x102bdcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_102be0:
    // 0x102be0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x102be0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102be4: 0x3e00008  jr          $ra
    ctx->pc = 0x102BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BE4u;
            // 0x102be8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102BECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
