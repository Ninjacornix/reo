#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1FB0
// Address: 0x1c1fb0 - 0x1c1ff8
void sub_001C1FB0_0x1c1fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1FB0_0x1c1fb0");
#endif

    switch (ctx->pc) {
        case 0x1c1fe4u: goto label_1c1fe4;
        default: break;
    }

    ctx->pc = 0x1c1fb0u;

    // 0x1c1fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c1fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c1fb4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1fb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1fb8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c1fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c1fbc: 0x8c234484  lw          $v1, 0x4484($at)
    ctx->pc = 0x1c1fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17540)));
    // 0x1c1fc0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1FC0u;
    {
        const bool branch_taken_0x1c1fc0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1FC0u;
            // 0x1c1fc4: 0x41200  sll         $v0, $a0, 8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1fc0) {
            ctx->pc = 0x1C1FD0u;
            goto label_1c1fd0;
        }
    }
    ctx->pc = 0x1C1FC8u;
    // 0x1c1fc8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1FC8u;
    {
        const bool branch_taken_0x1c1fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1FC8u;
            // 0x1c1fcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1fc8) {
            ctx->pc = 0x1C1FECu;
            goto label_1c1fec;
        }
    }
    ctx->pc = 0x1C1FD0u;
label_1c1fd0:
    // 0x1c1fd0: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c1fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c1fd4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1c1fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c1fd8: 0x24a56d10  addiu       $a1, $a1, 0x6D10
    ctx->pc = 0x1c1fd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27920));
    // 0x1c1fdc: 0xc07071c  jal         func_1C1C70
    ctx->pc = 0x1C1FDCu;
    SET_GPR_U32(ctx, 31, 0x1C1FE4u);
    ctx->pc = 0x1C1FE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1FDCu;
            // 0x1c1fe0: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1C70u;
    if (runtime->hasFunction(0x1C1C70u)) {
        auto targetFn = runtime->lookupFunction(0x1C1C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1FE4u; }
        if (ctx->pc != 0x1C1FE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1C70_0x1c1c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1FE4u; }
        if (ctx->pc != 0x1C1FE4u) { return; }
    }
    ctx->pc = 0x1C1FE4u;
label_1c1fe4:
    // 0x1c1fe4: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c1fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c1fe8: 0x24426d10  addiu       $v0, $v0, 0x6D10
    ctx->pc = 0x1c1fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27920));
label_1c1fec:
    // 0x1c1fec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c1fecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1FF0u;
            // 0x1c1ff4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1FD0u: goto label_1c1fd0;
            case 0x1C1FE4u: goto label_1c1fe4;
            case 0x1C1FECu: goto label_1c1fec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1FF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
