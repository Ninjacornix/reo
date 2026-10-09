#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F080
// Address: 0x13f080 - 0x13f0b4
void sub_0013F080_0x13f080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F080_0x13f080");
#endif

    ctx->pc = 0x13f080u;

    // 0x13f080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f084: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13f084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13f088: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13F088u;
    {
        const bool branch_taken_0x13f088 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13F08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F088u;
            // 0x13f08c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f088) {
            ctx->pc = 0x13F0A8u;
            goto label_13f0a8;
        }
    }
    ctx->pc = 0x13F090u;
    // 0x13f090: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f090u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f094: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f098: 0x2484d8e0  addiu       $a0, $a0, -0x2720
    ctx->pc = 0x13f098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957280));
    // 0x13f09c: 0x8045a12  j           func_116848
    ctx->pc = 0x13F09Cu;
    ctx->pc = 0x13F0A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F09Cu;
            // 0x13f0a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F0A4u;
    // 0x13f0a4: 0x0  nop
    ctx->pc = 0x13f0a4u;
    // NOP
label_13f0a8:
    // 0x13f0a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f0a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f0ac: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0ACu;
            // 0x13f0b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F0A8u: goto label_13f0a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
