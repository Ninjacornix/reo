#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107C68
// Address: 0x107c68 - 0x107d28
void sub_00107C68_0x107c68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107C68_0x107c68");
#endif

    switch (ctx->pc) {
        case 0x107ca4u: goto label_107ca4;
        case 0x107cc8u: goto label_107cc8;
        case 0x107d04u: goto label_107d04;
        default: break;
    }

    ctx->pc = 0x107c68u;

    // 0x107c68: 0x2cc20008  sltiu       $v0, $a2, 0x8
    ctx->pc = 0x107c68u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x107c6c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x107C6Cu;
    {
        const bool branch_taken_0x107c6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107C6Cu;
            // 0x107c70: 0x80182d  daddu       $v1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107c6c) {
            ctx->pc = 0x107CE8u;
            goto label_107ce8;
        }
    }
    ctx->pc = 0x107C74u;
    // 0x107c74: 0x3082000f  andi        $v0, $a0, 0xF
    ctx->pc = 0x107c74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x107c78: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x107C78u;
    {
        const bool branch_taken_0x107c78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107C78u;
            // 0x107c7c: 0x80382d  daddu       $a3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107c78) {
            ctx->pc = 0x107CE8u;
            goto label_107ce8;
        }
    }
    ctx->pc = 0x107C80u;
    // 0x107c80: 0x30a900ff  andi        $t1, $a1, 0xFF
    ctx->pc = 0x107c80u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x107c84: 0x2cca0020  sltiu       $t2, $a2, 0x20
    ctx->pc = 0x107c84u;
    SET_GPR_U64(ctx, 10, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x107c88: 0x120402d  daddu       $t0, $t1, $zero
    ctx->pc = 0x107c88u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107c8c: 0x81a38  dsll        $v1, $t0, 8
    ctx->pc = 0x107c8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) << 8);
    // 0x107c90: 0x694025  or          $t0, $v1, $t1
    ctx->pc = 0x107c90u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) | GPR_U64(ctx, 9));
    // 0x107c94: 0x70081ee9  pcpyh       $v1, $t0
    ctx->pc = 0x107c94u;
    { __m128i src = GPR_VEC(ctx, 0); uint16_t l = _mm_extract_epi16(src, 0); uint16_t h = _mm_extract_epi16(src, 4); 
   SET_GPR_VEC(ctx, 3, _mm_set_epi16(h,h,h,h, l,l,l,l)); }
    // 0x107c98: 0x1540000e  bnez        $t2, . + 4 + (0xE << 2)
    ctx->pc = 0x107C98u;
    {
        const bool branch_taken_0x107c98 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x107C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107C98u;
            // 0x107c9c: 0x2cc20008  sltiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x107c98) {
            ctx->pc = 0x107CD4u;
            goto label_107cd4;
        }
    }
    ctx->pc = 0x107CA0u;
    // 0x107ca0: 0x70634389  pcpyld      $t0, $v1, $v1
    ctx->pc = 0x107ca0u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
label_107ca4:
    // 0x107ca4: 0x7ce80000  sq          $t0, 0x0($a3)
    ctx->pc = 0x107ca4u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), GPR_VEC(ctx, 8));
    // 0x107ca8: 0x24c6ffe0  addiu       $a2, $a2, -0x20
    ctx->pc = 0x107ca8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967264));
    // 0x107cac: 0x24e70010  addiu       $a3, $a3, 0x10
    ctx->pc = 0x107cacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x107cb0: 0x2cc20020  sltiu       $v0, $a2, 0x20
    ctx->pc = 0x107cb0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x107cb4: 0x7ce80000  sq          $t0, 0x0($a3)
    ctx->pc = 0x107cb4u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), GPR_VEC(ctx, 8));
    // 0x107cb8: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107CB8u;
    {
        const bool branch_taken_0x107cb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107CB8u;
            // 0x107cbc: 0x24e70010  addiu       $a3, $a3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107cb8) {
            ctx->pc = 0x107CA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107ca4;
        }
    }
    ctx->pc = 0x107CC0u;
    // 0x107cc0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x107CC0u;
    {
        const bool branch_taken_0x107cc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107CC0u;
            // 0x107cc4: 0x2cc20008  sltiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x107cc0) {
            ctx->pc = 0x107CD4u;
            goto label_107cd4;
        }
    }
    ctx->pc = 0x107CC8u;
label_107cc8:
    // 0x107cc8: 0x24c6fff8  addiu       $a2, $a2, -0x8
    ctx->pc = 0x107cc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967288));
    // 0x107ccc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x107cccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x107cd0: 0x2cc20008  sltiu       $v0, $a2, 0x8
    ctx->pc = 0x107cd0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
label_107cd4:
    // 0x107cd4: 0x0  nop
    ctx->pc = 0x107cd4u;
    // NOP
    // 0x107cd8: 0x0  nop
    ctx->pc = 0x107cd8u;
    // NOP
    // 0x107cdc: 0x5040fffa  beql        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107CDCu;
    {
        const bool branch_taken_0x107cdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x107cdc) {
            ctx->pc = 0x107CE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107CDCu;
            // 0x107ce0: 0xfce30000  sd          $v1, 0x0($a3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 7), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107CC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107cc8;
        }
    }
    ctx->pc = 0x107CE4u;
    // 0x107ce4: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x107ce4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_107ce8:
    // 0x107ce8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x107ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x107cec: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107cecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x107cf0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x107cf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x107cf4: 0x10c2000a  beq         $a2, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x107CF4u;
    {
        const bool branch_taken_0x107cf4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x107cf4) {
            ctx->pc = 0x107D20u;
            goto label_107d20;
        }
    }
    ctx->pc = 0x107CFCu;
    // 0x107cfc: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x107cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x107d00: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x107d00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_107d04:
    // 0x107d04: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x107d04u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x107d08: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x107d08u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x107d0c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x107d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x107d10: 0x0  nop
    ctx->pc = 0x107d10u;
    // NOP
    // 0x107d14: 0x0  nop
    ctx->pc = 0x107d14u;
    // NOP
    // 0x107d18: 0x14c2fffa  bne         $a2, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107D18u;
    {
        const bool branch_taken_0x107d18 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x107d18) {
            ctx->pc = 0x107D04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107d04;
        }
    }
    ctx->pc = 0x107D20u;
label_107d20:
    // 0x107d20: 0x3e00008  jr          $ra
    ctx->pc = 0x107D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107D20u;
            // 0x107d24: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107CA4u: goto label_107ca4;
            case 0x107CC8u: goto label_107cc8;
            case 0x107CD4u: goto label_107cd4;
            case 0x107CE8u: goto label_107ce8;
            case 0x107D04u: goto label_107d04;
            case 0x107D20u: goto label_107d20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107D28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
