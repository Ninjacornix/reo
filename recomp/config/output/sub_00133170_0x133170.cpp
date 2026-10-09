#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133170
// Address: 0x133170 - 0x1331a8
void sub_00133170_0x133170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133170_0x133170");
#endif

    switch (ctx->pc) {
        case 0x133188u: goto label_133188;
        default: break;
    }

    ctx->pc = 0x133170u;

    // 0x133170: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133174: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x133174u;
    {
        const bool branch_taken_0x133174 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x133178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133174u;
            // 0x133178: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133174) {
            ctx->pc = 0x133198u;
            goto label_133198;
        }
    }
    ctx->pc = 0x13317Cu;
    // 0x13317c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13317cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x133180: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x133180u;
    SET_GPR_U32(ctx, 31, 0x133188u);
    ctx->pc = 0x133184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133180u;
            // 0x133184: 0x2484b518  addiu       $a0, $a0, -0x4AE8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133188u; }
        if (ctx->pc != 0x133188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133188u; }
        if (ctx->pc != 0x133188u) { return; }
    }
    ctx->pc = 0x133188u;
label_133188:
    // 0x133188: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x133188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x13318c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13318cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133190: 0x3e00008  jr          $ra
    ctx->pc = 0x133190u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133190u;
            // 0x133194: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133188u: goto label_133188;
            case 0x133198u: goto label_133198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133198u;
label_133198:
    // 0x133198: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x133198u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13319c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13319cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1331a0: 0x804b5b8  j           func_12D6E0
    ctx->pc = 0x1331A0u;
    ctx->pc = 0x1331A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1331A0u;
            // 0x1331a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E0u;
    if (runtime->hasFunction(0x12D6E0u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D6E0_0x12d6e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1331A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
