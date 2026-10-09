#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019DCD0
// Address: 0x19dcd0 - 0x19dd30
void sub_0019DCD0_0x19dcd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019DCD0_0x19dcd0");
#endif

    ctx->pc = 0x19dcd0u;

    // 0x19dcd0: 0x8483001c  lh          $v1, 0x1C($a0)
    ctx->pc = 0x19dcd0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x19dcd4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x19dcd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19dcd8: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19DCD8u;
    {
        const bool branch_taken_0x19dcd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x19dcd8) {
            ctx->pc = 0x19DCE8u;
            goto label_19dce8;
        }
    }
    ctx->pc = 0x19DCE0u;
    // 0x19dce0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x19DCE0u;
    {
        const bool branch_taken_0x19dce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DCE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DCE0u;
            // 0x19dce4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19dce0) {
            ctx->pc = 0x19DD1Cu;
            goto label_19dd1c;
        }
    }
    ctx->pc = 0x19DCE8u;
label_19dce8:
    // 0x19dce8: 0x8c840020  lw          $a0, 0x20($a0)
    ctx->pc = 0x19dce8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x19dcec: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x19dcecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19dcf0: 0x10830009  beq         $a0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x19DCF0u;
    {
        const bool branch_taken_0x19dcf0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19dcf0) {
            ctx->pc = 0x19DD18u;
            goto label_19dd18;
        }
    }
    ctx->pc = 0x19DCF8u;
    // 0x19dcf8: 0x10850005  beq         $a0, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x19DCF8u;
    {
        const bool branch_taken_0x19dcf8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 5));
        if (branch_taken_0x19dcf8) {
            ctx->pc = 0x19DD10u;
            goto label_19dd10;
        }
    }
    ctx->pc = 0x19DD00u;
    // 0x19dd00: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19DD00u;
    {
        const bool branch_taken_0x19dd00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19dd00) {
            ctx->pc = 0x19DD10u;
            goto label_19dd10;
        }
    }
    ctx->pc = 0x19DD08u;
    // 0x19dd08: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x19DD08u;
    {
        const bool branch_taken_0x19dd08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19dd08) {
            ctx->pc = 0x19DD1Cu;
            goto label_19dd1c;
        }
    }
    ctx->pc = 0x19DD10u;
label_19dd10:
    // 0x19dd10: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19DD10u;
    {
        const bool branch_taken_0x19dd10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DD10u;
            // 0x19dd14: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19dd10) {
            ctx->pc = 0x19DD1Cu;
            goto label_19dd1c;
        }
    }
    ctx->pc = 0x19DD18u;
label_19dd18:
    // 0x19dd18: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x19dd18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_19dd1c:
    // 0x19dd1c: 0x3e00008  jr          $ra
    ctx->pc = 0x19DD1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19DCE8u: goto label_19dce8;
            case 0x19DD10u: goto label_19dd10;
            case 0x19DD18u: goto label_19dd18;
            case 0x19DD1Cu: goto label_19dd1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19DD24u;
    // 0x19dd24: 0x0  nop
    ctx->pc = 0x19dd24u;
    // NOP
    // 0x19dd28: 0x0  nop
    ctx->pc = 0x19dd28u;
    // NOP
    // 0x19dd2c: 0x0  nop
    ctx->pc = 0x19dd2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
