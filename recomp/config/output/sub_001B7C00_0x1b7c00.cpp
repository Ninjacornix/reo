#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7C00
// Address: 0x1b7c00 - 0x1b7c90
void sub_001B7C00_0x1b7c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7C00_0x1b7c00");
#endif

    switch (ctx->pc) {
        case 0x1b7c08u: goto label_1b7c08;
        default: break;
    }

    ctx->pc = 0x1b7c00u;

    // 0x1b7c00: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1B7C00u;
    {
        const bool branch_taken_0x1b7c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7C00u;
            // 0x1b7c04: 0x90860000  lbu         $a2, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7c00) {
            ctx->pc = 0x1B7C7Cu;
            goto label_1b7c7c;
        }
    }
    ctx->pc = 0x1B7C08u;
label_1b7c08:
    // 0x1b7c08: 0x90870000  lbu         $a3, 0x0($a0)
    ctx->pc = 0x1b7c08u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b7c0c: 0x28e30080  slti        $v1, $a3, 0x80
    ctx->pc = 0x1b7c0cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b7c10: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B7C10u;
    {
        const bool branch_taken_0x1b7c10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7C10u;
            // 0x1b7c14: 0x28e300e0  slti        $v1, $a3, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7c10) {
            ctx->pc = 0x1B7C24u;
            goto label_1b7c24;
        }
    }
    ctx->pc = 0x1B7C18u;
    // 0x1b7c18: 0x28e100a0  slti        $at, $a3, 0xA0
    ctx->pc = 0x1b7c18u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b7c1c: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B7C1Cu;
    {
        const bool branch_taken_0x1b7c1c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7c1c) {
            ctx->pc = 0x1B7C38u;
            goto label_1b7c38;
        }
    }
    ctx->pc = 0x1B7C24u;
label_1b7c24:
    // 0x1b7c24: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B7C24u;
    {
        const bool branch_taken_0x1b7c24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7c24) {
            ctx->pc = 0x1B7C50u;
            goto label_1b7c50;
        }
    }
    ctx->pc = 0x1B7C2Cu;
    // 0x1b7c2c: 0x28e10100  slti        $at, $a3, 0x100
    ctx->pc = 0x1b7c2cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b7c30: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B7C30u;
    {
        const bool branch_taken_0x1b7c30 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7c30) {
            ctx->pc = 0x1B7C50u;
            goto label_1b7c50;
        }
    }
    ctx->pc = 0x1B7C38u;
label_1b7c38:
    // 0x1b7c38: 0xa0a60000  sb          $a2, 0x0($a1)
    ctx->pc = 0x1b7c38u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1b7c3c: 0x90830001  lbu         $v1, 0x1($a0)
    ctx->pc = 0x1b7c3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1b7c40: 0xa0a30001  sb          $v1, 0x1($a1)
    ctx->pc = 0x1b7c40u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b7c44: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1b7c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1b7c48: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B7C48u;
    {
        const bool branch_taken_0x1b7c48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7C48u;
            // 0x1b7c4c: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7c48) {
            ctx->pc = 0x1B7C78u;
            goto label_1b7c78;
        }
    }
    ctx->pc = 0x1B7C50u;
label_1b7c50:
    // 0x1b7c50: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7c50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7c54: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x1b7c54u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1b7c58: 0x8c2347e8  lw          $v1, 0x47E8($at)
    ctx->pc = 0x1b7c58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18408)));
    // 0x1b7c5c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1b7c5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b7c60: 0x663021  addu        $a2, $v1, $a2
    ctx->pc = 0x1b7c60u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1b7c64: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x1b7c64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b7c68: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1b7c68u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b7c6c: 0x90c30001  lbu         $v1, 0x1($a2)
    ctx->pc = 0x1b7c6cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x1b7c70: 0xa0a30001  sb          $v1, 0x1($a1)
    ctx->pc = 0x1b7c70u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b7c74: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1b7c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
label_1b7c78:
    // 0x1b7c78: 0x90860000  lbu         $a2, 0x0($a0)
    ctx->pc = 0x1b7c78u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_1b7c7c:
    // 0x1b7c7c: 0x14c0ffe2  bnez        $a2, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1B7C7Cu;
    {
        const bool branch_taken_0x1b7c7c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7c7c) {
            ctx->pc = 0x1B7C08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7c08;
        }
    }
    ctx->pc = 0x1B7C84u;
    // 0x1b7c84: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7C84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7C84u;
            // 0x1b7c88: 0xa0a00000  sb          $zero, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7C08u: goto label_1b7c08;
            case 0x1B7C24u: goto label_1b7c24;
            case 0x1B7C38u: goto label_1b7c38;
            case 0x1B7C50u: goto label_1b7c50;
            case 0x1B7C78u: goto label_1b7c78;
            case 0x1B7C7Cu: goto label_1b7c7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7C8Cu;
    // 0x1b7c8c: 0x0  nop
    ctx->pc = 0x1b7c8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
