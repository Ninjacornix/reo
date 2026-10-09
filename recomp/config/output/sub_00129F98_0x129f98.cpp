#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129F98
// Address: 0x129f98 - 0x129fcc
void sub_00129F98_0x129f98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129F98_0x129f98");
#endif

    ctx->pc = 0x129f98u;

    // 0x129f98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129f98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129f9c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x129f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129fa0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x129fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x129fa4: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x129fa4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x129fa8: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x129FA8u;
    {
        const bool branch_taken_0x129fa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x129FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129FA8u;
            // 0x129fac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129fa8) {
            ctx->pc = 0x129FC0u;
            goto label_129fc0;
        }
    }
    ctx->pc = 0x129FB0u;
    // 0x129fb0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129fb4: 0x2484a288  addiu       $a0, $a0, -0x5D78
    ctx->pc = 0x129fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943368));
    // 0x129fb8: 0x804a034  j           func_1280D0
    ctx->pc = 0x129FB8u;
    ctx->pc = 0x129FBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129FB8u;
            // 0x129fbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x129FC0u;
label_129fc0:
    // 0x129fc0: 0xac85002c  sw          $a1, 0x2C($a0)
    ctx->pc = 0x129fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
    // 0x129fc4: 0x3e00008  jr          $ra
    ctx->pc = 0x129FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129FC4u;
            // 0x129fc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FC0u: goto label_129fc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129FCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
