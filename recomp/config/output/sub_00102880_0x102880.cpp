#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102880
// Address: 0x102880 - 0x1028bc
void sub_00102880_0x102880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102880_0x102880");
#endif

    switch (ctx->pc) {
        case 0x102890u: goto label_102890;
        default: break;
    }

    ctx->pc = 0x102880u;

    // 0x102880: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x102880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x102884: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x102884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x102888: 0xc040a3c  jal         func_1028F0
    ctx->pc = 0x102888u;
    SET_GPR_U32(ctx, 31, 0x102890u);
    ctx->pc = 0x1028F0u;
    if (runtime->hasFunction(0x1028F0u)) {
        auto targetFn = runtime->lookupFunction(0x1028F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102890u; }
        if (ctx->pc != 0x102890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001028F0_0x1028f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102890u; }
        if (ctx->pc != 0x102890u) { return; }
    }
    ctx->pc = 0x102890u;
label_102890:
    // 0x102890: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x102890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102894: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102894u;
    {
        const bool branch_taken_0x102894 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x102898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102894u;
            // 0x102898: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102894) {
            ctx->pc = 0x1028B0u;
            goto label_1028b0;
        }
    }
    ctx->pc = 0x10289Cu;
    // 0x10289c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x10289cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1028a0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1028a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1028a4: 0x34633810  ori         $v1, $v1, 0x3810
    ctx->pc = 0x1028a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14352);
    // 0x1028a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1028a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1028ac: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1028acu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_1028b0:
    // 0x1028b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1028b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1028b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1028B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1028B4u;
            // 0x1028b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102890u: goto label_102890;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1028BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
