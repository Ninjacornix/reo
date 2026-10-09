#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107A18
// Address: 0x107a18 - 0x107ab0
void sub_00107A18_0x107a18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107A18_0x107a18");
#endif

    switch (ctx->pc) {
        case 0x107a30u: goto label_107a30;
        case 0x107a80u: goto label_107a80;
        default: break;
    }

    ctx->pc = 0x107a18u;

    // 0x107a18: 0x2cc20010  sltiu       $v0, $a2, 0x10
    ctx->pc = 0x107a18u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x107a1c: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x107A1Cu;
    {
        const bool branch_taken_0x107a1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A1Cu;
            // 0x107a20: 0x851025  or          $v0, $a0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107a1c) {
            ctx->pc = 0x107A64u;
            goto label_107a64;
        }
    }
    ctx->pc = 0x107A24u;
    // 0x107a24: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x107a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x107a28: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x107A28u;
    {
        const bool branch_taken_0x107a28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x107a28) {
            ctx->pc = 0x107A64u;
            goto label_107a64;
        }
    }
    ctx->pc = 0x107A30u;
label_107a30:
    // 0x107a30: 0x78830000  lq          $v1, 0x0($a0)
    ctx->pc = 0x107a30u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x107a34: 0x2cc70020  sltiu       $a3, $a2, 0x20
    ctx->pc = 0x107a34u;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x107a38: 0x78a20000  lq          $v0, 0x0($a1)
    ctx->pc = 0x107a38u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107a3c: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x107a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x107a40: 0x704344c9  pxor        $t0, $v0, $v1
    ctx->pc = 0x107a40u;
    SET_GPR_VEC(ctx, 8, PS2_PXOR(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x107a44: 0x24a20010  addiu       $v0, $a1, 0x10
    ctx->pc = 0x107a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x107a48: 0x710753a9  pcpyud      $t2, $t0, $a3
    ctx->pc = 0x107a48u;
    SET_GPR_VEC(ctx, 10, _mm_unpackhi_epi64(GPR_VEC(ctx, 8), GPR_VEC(ctx, 7)));
    // 0x107a4c: 0x1484825  or          $t1, $t2, $t0
    ctx->pc = 0x107a4cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 10) | GPR_U64(ctx, 8));
    // 0x107a50: 0x49280a  movz        $a1, $v0, $t1
    ctx->pc = 0x107a50u;
    if (GPR_U64(ctx, 9) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x107a54: 0x55200003  bnel        $t1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x107A54u;
    {
        const bool branch_taken_0x107a54 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x107a54) {
            ctx->pc = 0x107A58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107A54u;
            // 0x107a58: 0x2484fff0  addiu       $a0, $a0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107A64u;
            goto label_107a64;
        }
    }
    ctx->pc = 0x107A5Cu;
    // 0x107a5c: 0x10e0fff4  beqz        $a3, . + 4 + (-0xC << 2)
    ctx->pc = 0x107A5Cu;
    {
        const bool branch_taken_0x107a5c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x107A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A5Cu;
            // 0x107a60: 0x24c6fff0  addiu       $a2, $a2, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107a5c) {
            ctx->pc = 0x107A30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107a30;
        }
    }
    ctx->pc = 0x107A64u;
label_107a64:
    // 0x107a64: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x107a64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x107a68: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107a68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x107a6c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x107a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x107a70: 0x10c2000c  beq         $a2, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x107A70u;
    {
        const bool branch_taken_0x107a70 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x107a70) {
            ctx->pc = 0x107AA4u;
            goto label_107aa4;
        }
    }
    ctx->pc = 0x107A78u;
    // 0x107a78: 0x3c07ffff  lui         $a3, 0xFFFF
    ctx->pc = 0x107a78u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65535 << 16));
    // 0x107a7c: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    ctx->pc = 0x107a7cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
label_107a80:
    // 0x107a80: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x107a80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x107a84: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x107a84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x107a88: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x107A88u;
    {
        const bool branch_taken_0x107a88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x107A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A88u;
            // 0x107a8c: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107a88) {
            ctx->pc = 0x107A98u;
            goto label_107a98;
        }
    }
    ctx->pc = 0x107A90u;
    // 0x107a90: 0x3e00008  jr          $ra
    ctx->pc = 0x107A90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A90u;
            // 0x107a94: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107A30u: goto label_107a30;
            case 0x107A64u: goto label_107a64;
            case 0x107A80u: goto label_107a80;
            case 0x107A98u: goto label_107a98;
            case 0x107AA4u: goto label_107aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107A98u;
label_107a98:
    // 0x107a98: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107a98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x107a9c: 0x14c7fff8  bne         $a2, $a3, . + 4 + (-0x8 << 2)
    ctx->pc = 0x107A9Cu;
    {
        const bool branch_taken_0x107a9c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 7));
        ctx->pc = 0x107AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A9Cu;
            // 0x107aa0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107a9c) {
            ctx->pc = 0x107A80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107a80;
        }
    }
    ctx->pc = 0x107AA4u;
label_107aa4:
    // 0x107aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x107AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107AA4u;
            // 0x107aa8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107A30u: goto label_107a30;
            case 0x107A64u: goto label_107a64;
            case 0x107A80u: goto label_107a80;
            case 0x107A98u: goto label_107a98;
            case 0x107AA4u: goto label_107aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107AACu;
    // 0x107aac: 0x0  nop
    ctx->pc = 0x107aacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
