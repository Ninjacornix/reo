#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124EF8
// Address: 0x124ef8 - 0x124f48
void sub_00124EF8_0x124ef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124EF8_0x124ef8");
#endif

    switch (ctx->pc) {
        case 0x124f00u: goto label_124f00;
        case 0x124f08u: goto label_124f08;
        case 0x124f10u: goto label_124f10;
        case 0x124f18u: goto label_124f18;
        case 0x124f38u: goto label_124f38;
        case 0x124f40u: goto label_124f40;
        default: break;
    }

    ctx->pc = 0x124ef8u;

    // 0x124ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x124EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EF8u;
            // 0x124efc: 0x8c820018  lw          $v0, 0x18($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F00u;
label_124f00:
    // 0x124f00: 0x3e00008  jr          $ra
    ctx->pc = 0x124F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F00u;
            // 0x124f04: 0x8482001c  lh          $v0, 0x1C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F08u;
label_124f08:
    // 0x124f08: 0x3e00008  jr          $ra
    ctx->pc = 0x124F08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F08u;
            // 0x124f0c: 0x8c820020  lw          $v0, 0x20($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F10u;
label_124f10:
    // 0x124f10: 0x3e00008  jr          $ra
    ctx->pc = 0x124F10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F10u;
            // 0x124f14: 0x84820024  lh          $v0, 0x24($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 36)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F18u;
label_124f18:
    // 0x124f18: 0x3e00008  jr          $ra
    ctx->pc = 0x124F18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F18u;
            // 0x124f1c: 0x8c820028  lw          $v0, 0x28($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F20u;
    // 0x124f20: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x124F20u;
    {
        const bool branch_taken_0x124f20 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x124F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F20u;
            // 0x124f24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124f20) {
            ctx->pc = 0x124F2Cu;
            goto label_124f2c;
        }
    }
    ctx->pc = 0x124F28u;
    // 0x124f28: 0x8c82002c  lw          $v0, 0x2C($a0)
    ctx->pc = 0x124f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
label_124f2c:
    // 0x124f2c: 0x3e00008  jr          $ra
    ctx->pc = 0x124F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F34u;
    // 0x124f34: 0x0  nop
    ctx->pc = 0x124f34u;
    // NOP
label_124f38:
    // 0x124f38: 0x3e00008  jr          $ra
    ctx->pc = 0x124F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F38u;
            // 0x124f3c: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F40u;
label_124f40:
    // 0x124f40: 0x3e00008  jr          $ra
    ctx->pc = 0x124F40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F40u;
            // 0x124f44: 0x8c820034  lw          $v0, 0x34($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F00u: goto label_124f00;
            case 0x124F08u: goto label_124f08;
            case 0x124F10u: goto label_124f10;
            case 0x124F18u: goto label_124f18;
            case 0x124F2Cu: goto label_124f2c;
            case 0x124F38u: goto label_124f38;
            case 0x124F40u: goto label_124f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
