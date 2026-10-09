#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FFF8
// Address: 0x12fff8 - 0x130038
void sub_0012FFF8_0x12fff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FFF8_0x12fff8");
#endif

    ctx->pc = 0x12fff8u;

    // 0x12fff8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12fff8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12fffc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12fffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130000: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x130000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x130004: 0x80830001  lb          $v1, 0x1($a0)
    ctx->pc = 0x130004u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x130008: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x130008u;
    {
        const bool branch_taken_0x130008 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x13000Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130008u;
            // 0x13000c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130008) {
            ctx->pc = 0x130020u;
            goto label_130020;
        }
    }
    ctx->pc = 0x130010u;
    // 0x130010: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x130010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130014: 0x804bf7c  j           func_12FDF0
    ctx->pc = 0x130014u;
    ctx->pc = 0x130018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130014u;
            // 0x130018: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FDF0u;
    if (runtime->hasFunction(0x12FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x12FDF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012FDF0_0x12fdf0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13001Cu;
    // 0x13001c: 0x0  nop
    ctx->pc = 0x13001cu;
    // NOP
label_130020:
    // 0x130020: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x130020u;
    {
        const bool branch_taken_0x130020 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x130024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130020u;
            // 0x130024: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130020) {
            ctx->pc = 0x130030u;
            goto label_130030;
        }
    }
    ctx->pc = 0x130028u;
    // 0x130028: 0x804bfd8  j           func_12FF60
    ctx->pc = 0x130028u;
    ctx->pc = 0x13002Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130028u;
            // 0x13002c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FF60u;
    if (runtime->hasFunction(0x12FF60u)) {
        auto targetFn = runtime->lookupFunction(0x12FF60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012FF60_0x12ff60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130030u;
label_130030:
    // 0x130030: 0x3e00008  jr          $ra
    ctx->pc = 0x130030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130030u;
            // 0x130034: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130020u: goto label_130020;
            case 0x130030u: goto label_130030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
