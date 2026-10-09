#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164B70
// Address: 0x164b70 - 0x164ba0
void sub_00164B70_0x164b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164B70_0x164b70");
#endif

    switch (ctx->pc) {
        case 0x164b90u: goto label_164b90;
        default: break;
    }

    ctx->pc = 0x164b70u;

    // 0x164b70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164b74: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x164b74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x164b78: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164b7c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x164b7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b80: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x164b80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b84: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x164b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x164b88: 0x40f809  jalr        $v0
    ctx->pc = 0x164B88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x164B90u);
        ctx->pc = 0x164B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164B88u;
            // 0x164b8c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x164B90u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164B90u: goto label_164b90;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x164B90u; }
            if (ctx->pc != 0x164B90u) { return; }
        }
        }
    }
    ctx->pc = 0x164B90u;
label_164b90:
    // 0x164b90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164b90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164b94: 0x3e00008  jr          $ra
    ctx->pc = 0x164B94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164B94u;
            // 0x164b98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164B90u: goto label_164b90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164B9Cu;
    // 0x164b9c: 0x0  nop
    ctx->pc = 0x164b9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
