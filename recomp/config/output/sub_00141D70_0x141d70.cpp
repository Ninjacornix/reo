#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141D70
// Address: 0x141d70 - 0x141dac
void sub_00141D70_0x141d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141D70_0x141d70");
#endif

    switch (ctx->pc) {
        case 0x141da0u: goto label_141da0;
        default: break;
    }

    ctx->pc = 0x141d70u;

    // 0x141d70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141d74: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141d74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141d78: 0x244249a0  addiu       $v0, $v0, 0x49A0
    ctx->pc = 0x141d78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18848));
    // 0x141d7c: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x141d7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x141d80: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141d80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141d84: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x141d84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x141d88: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x141d88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x141d8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x141d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141d90: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x141D90u;
    {
        const bool branch_taken_0x141d90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x141d90) {
            ctx->pc = 0x141D94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141D90u;
            // 0x141d94: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141DA4u;
            goto label_141da4;
        }
    }
    ctx->pc = 0x141D98u;
    // 0x141d98: 0x40f809  jalr        $v0
    ctx->pc = 0x141D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141DA0u);
        ctx->pc = 0x141D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141D98u;
            // 0x141d9c: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141DA0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141DA0u: goto label_141da0;
            case 0x141DA4u: goto label_141da4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141DA0u; }
            if (ctx->pc != 0x141DA0u) { return; }
        }
        }
    }
    ctx->pc = 0x141DA0u;
label_141da0:
    // 0x141da0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_141da4:
    // 0x141da4: 0x3e00008  jr          $ra
    ctx->pc = 0x141DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141DA4u;
            // 0x141da8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141DA0u: goto label_141da0;
            case 0x141DA4u: goto label_141da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141DACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
