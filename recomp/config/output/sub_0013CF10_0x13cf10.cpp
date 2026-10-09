#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CF10
// Address: 0x13cf10 - 0x13cf78
void sub_0013CF10_0x13cf10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CF10_0x13cf10");
#endif

    switch (ctx->pc) {
        case 0x13cf54u: goto label_13cf54;
        default: break;
    }

    ctx->pc = 0x13cf10u;

    // 0x13cf10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13cf10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13cf14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13cf14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13cf18: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13cf18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cf1c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13CF1Cu;
    {
        const bool branch_taken_0x13cf1c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF1Cu;
            // 0x13cf20: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cf1c) {
            ctx->pc = 0x13CF40u;
            goto label_13cf40;
        }
    }
    ctx->pc = 0x13CF24u;
    // 0x13cf24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cf24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cf28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cf28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cf2c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13cf2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cf30: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13cf30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13cf34: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13CF34u;
    ctx->pc = 0x13CF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF34u;
            // 0x13cf38: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CF3Cu;
    // 0x13cf3c: 0x0  nop
    ctx->pc = 0x13cf3cu;
    // NOP
label_13cf40:
    // 0x13cf40: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x13cf40u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x13cf44: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x13CF44u;
    {
        const bool branch_taken_0x13cf44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13cf44) {
            ctx->pc = 0x13CF48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF44u;
            // 0x13cf48: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CF58u;
            goto label_13cf58;
        }
    }
    ctx->pc = 0x13CF4Cu;
    // 0x13cf4c: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x13CF4Cu;
    SET_GPR_U32(ctx, 31, 0x13CF54u);
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CF54u; }
        if (ctx->pc != 0x13CF54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CF54u; }
        if (ctx->pc != 0x13CF54u) { return; }
    }
    ctx->pc = 0x13CF54u;
label_13cf54:
    // 0x13cf54: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x13cf54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
label_13cf58:
    // 0x13cf58: 0x58400002  blezl       $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x13CF58u;
    {
        const bool branch_taken_0x13cf58 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x13cf58) {
            ctx->pc = 0x13CF5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF58u;
            // 0x13cf5c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CF64u;
            goto label_13cf64;
        }
    }
    ctx->pc = 0x13CF60u;
    // 0x13cf60: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x13cf60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_13cf64:
    // 0x13cf64: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x13cf64u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x13cf68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cf68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cf6c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13cf6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cf70: 0x3e00008  jr          $ra
    ctx->pc = 0x13CF70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CF74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF70u;
            // 0x13cf74: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CF40u: goto label_13cf40;
            case 0x13CF54u: goto label_13cf54;
            case 0x13CF58u: goto label_13cf58;
            case 0x13CF64u: goto label_13cf64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CF78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
