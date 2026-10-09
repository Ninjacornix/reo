#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B29E0
// Address: 0x1b29e0 - 0x1b2a70
void sub_001B29E0_0x1b29e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B29E0_0x1b29e0");
#endif

    switch (ctx->pc) {
        case 0x1b2a10u: goto label_1b2a10;
        default: break;
    }

    ctx->pc = 0x1b29e0u;

    // 0x1b29e0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b29e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b29e4: 0x3c08002c  lui         $t0, 0x2C
    ctx->pc = 0x1b29e4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)44 << 16));
    // 0x1b29e8: 0x84228eac  lh          $v0, -0x7154($at)
    ctx->pc = 0x1b29e8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294938284)));
    // 0x1b29ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B29ECu;
    {
        const bool branch_taken_0x1b29ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B29F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B29ECu;
            // 0x1b29f0: 0x25088ea0  addiu       $t0, $t0, -0x7160 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294938272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b29ec) {
            ctx->pc = 0x1B29FCu;
            goto label_1b29fc;
        }
    }
    ctx->pc = 0x1B29F4u;
    // 0x1b29f4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1B29F4u;
    {
        const bool branch_taken_0x1b29f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B29F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B29F4u;
            // 0x1b29f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b29f4) {
            ctx->pc = 0x1B2A5Cu;
            goto label_1b2a5c;
        }
    }
    ctx->pc = 0x1B29FCu;
label_1b29fc:
    // 0x1b29fc: 0x8503000c  lh          $v1, 0xC($t0)
    ctx->pc = 0x1b29fcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x1b2a00: 0x4343c  dsll32      $a2, $a0, 16
    ctx->pc = 0x1b2a00u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1b2a04: 0x6343f  dsra32      $a2, $a2, 16
    ctx->pc = 0x1b2a04u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x1b2a08: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B2A08u;
    {
        const bool branch_taken_0x1b2a08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2A08u;
            // 0x1b2a0c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2a08) {
            ctx->pc = 0x1B2A4Cu;
            goto label_1b2a4c;
        }
    }
    ctx->pc = 0x1B2A10u;
label_1b2a10:
    // 0x1b2a10: 0x90820274  lbu         $v0, 0x274($a0)
    ctx->pc = 0x1b2a10u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 628)));
    // 0x1b2a14: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B2A14u;
    {
        const bool branch_taken_0x1b2a14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2A14u;
            // 0x1b2a18: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2a14) {
            ctx->pc = 0x1B2A48u;
            goto label_1b2a48;
        }
    }
    ctx->pc = 0x1B2A1Cu;
    // 0x1b2a1c: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x1b2a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1b2a20: 0x844201ac  lh          $v0, 0x1AC($v0)
    ctx->pc = 0x1b2a20u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 428)));
    // 0x1b2a24: 0x14460008  bne         $v0, $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B2A24u;
    {
        const bool branch_taken_0x1b2a24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        if (branch_taken_0x1b2a24) {
            ctx->pc = 0x1B2A48u;
            goto label_1b2a48;
        }
    }
    ctx->pc = 0x1B2A2Cu;
    // 0x1b2a2c: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1b2a2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1b2a30: 0x71080  sll         $v0, $a3, 2
    ctx->pc = 0x1b2a30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1b2a34: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b2a34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b2a38: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1b2a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1b2a3c: 0xa0830274  sb          $v1, 0x274($a0)
    ctx->pc = 0x1b2a3cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 628), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b2a40: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2A40u;
    {
        const bool branch_taken_0x1b2a40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2A40u;
            // 0x1b2a44: 0x8c42001c  lw          $v0, 0x1C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2a40) {
            ctx->pc = 0x1B2A5Cu;
            goto label_1b2a5c;
        }
    }
    ctx->pc = 0x1B2A48u;
label_1b2a48:
    // 0x1b2a48: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b2a48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1b2a4c:
    // 0x1b2a4c: 0xe3102a  slt         $v0, $a3, $v1
    ctx->pc = 0x1b2a4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b2a50: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1B2A50u;
    {
        const bool branch_taken_0x1b2a50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2A50u;
            // 0x1b2a54: 0x1072021  addu        $a0, $t0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2a50) {
            ctx->pc = 0x1B2A10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2a10;
        }
    }
    ctx->pc = 0x1B2A58u;
    // 0x1b2a58: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b2a58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b2a5c:
    // 0x1b2a5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2A5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B29FCu: goto label_1b29fc;
            case 0x1B2A10u: goto label_1b2a10;
            case 0x1B2A48u: goto label_1b2a48;
            case 0x1B2A4Cu: goto label_1b2a4c;
            case 0x1B2A5Cu: goto label_1b2a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2A64u;
    // 0x1b2a64: 0x0  nop
    ctx->pc = 0x1b2a64u;
    // NOP
    // 0x1b2a68: 0x0  nop
    ctx->pc = 0x1b2a68u;
    // NOP
    // 0x1b2a6c: 0x0  nop
    ctx->pc = 0x1b2a6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
