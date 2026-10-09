#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5B40
// Address: 0x1a5b40 - 0x1a5bd0
void sub_001A5B40_0x1a5b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5B40_0x1a5b40");
#endif

    switch (ctx->pc) {
        case 0x1a5b6cu: goto label_1a5b6c;
        case 0x1a5b9cu: goto label_1a5b9c;
        default: break;
    }

    ctx->pc = 0x1a5b40u;

    // 0x1a5b40: 0xa4082b  sltu        $at, $a1, $a0
    ctx->pc = 0x1a5b40u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1a5b44: 0x10200013  beqz        $at, . + 4 + (0x13 << 2)
    ctx->pc = 0x1A5B44u;
    {
        const bool branch_taken_0x1a5b44 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B44u;
            // 0x1a5b48: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b44) {
            ctx->pc = 0x1A5B94u;
            goto label_1a5b94;
        }
    }
    ctx->pc = 0x1A5B4Cu;
    // 0x1a5b4c: 0xa61821  addu        $v1, $a1, $a2
    ctx->pc = 0x1a5b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1a5b50: 0x83082b  sltu        $at, $a0, $v1
    ctx->pc = 0x1a5b50u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a5b54: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1A5B54u;
    {
        const bool branch_taken_0x1a5b54 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B54u;
            // 0x1a5b58: 0x24c3ffff  addiu       $v1, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b54) {
            ctx->pc = 0x1A5B94u;
            goto label_1a5b94;
        }
    }
    ctx->pc = 0x1A5B5Cu;
    // 0x1a5b5c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1a5b5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5b60: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1a5b60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a5b64: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A5B64u;
    {
        const bool branch_taken_0x1a5b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B64u;
            // 0x1a5b68: 0xa32821  addu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b64) {
            ctx->pc = 0x1A5B80u;
            goto label_1a5b80;
        }
    }
    ctx->pc = 0x1A5B6Cu;
label_1a5b6c:
    // 0x1a5b6c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a5b6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1a5b70: 0x2465ffff  addiu       $a1, $v1, -0x1
    ctx->pc = 0x1a5b70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a5b74: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x1a5b74u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a5b78: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1a5b78u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a5b7c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a5b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_1a5b80:
    // 0x1a5b80: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x1a5b80u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1a5b84: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A5B84u;
    {
        const bool branch_taken_0x1a5b84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B84u;
            // 0x1a5b88: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b84) {
            ctx->pc = 0x1A5B6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5b6c;
        }
    }
    ctx->pc = 0x1A5B8Cu;
    // 0x1a5b8c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A5B8Cu;
    {
        const bool branch_taken_0x1a5b8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5b8c) {
            ctx->pc = 0x1A5BBCu;
            goto label_1a5bbc;
        }
    }
    ctx->pc = 0x1A5B94u;
label_1a5b94:
    // 0x1a5b94: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A5B94u;
    {
        const bool branch_taken_0x1a5b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B94u;
            // 0x1a5b98: 0xe6182a  slt         $v1, $a3, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b94) {
            ctx->pc = 0x1A5BB4u;
            goto label_1a5bb4;
        }
    }
    ctx->pc = 0x1A5B9Cu;
label_1a5b9c:
    // 0x1a5b9c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a5b9cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1a5ba0: 0x24650001  addiu       $a1, $v1, 0x1
    ctx->pc = 0x1a5ba0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a5ba4: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x1a5ba4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a5ba8: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1a5ba8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a5bac: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a5bacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a5bb0: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x1a5bb0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
label_1a5bb4:
    // 0x1a5bb4: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A5BB4u;
    {
        const bool branch_taken_0x1a5bb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5BB4u;
            // 0x1a5bb8: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5bb4) {
            ctx->pc = 0x1A5B9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5b9c;
        }
    }
    ctx->pc = 0x1A5BBCu;
label_1a5bbc:
    // 0x1a5bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5B6Cu: goto label_1a5b6c;
            case 0x1A5B80u: goto label_1a5b80;
            case 0x1A5B94u: goto label_1a5b94;
            case 0x1A5B9Cu: goto label_1a5b9c;
            case 0x1A5BB4u: goto label_1a5bb4;
            case 0x1A5BBCu: goto label_1a5bbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5BC4u;
    // 0x1a5bc4: 0x0  nop
    ctx->pc = 0x1a5bc4u;
    // NOP
    // 0x1a5bc8: 0x0  nop
    ctx->pc = 0x1a5bc8u;
    // NOP
    // 0x1a5bcc: 0x0  nop
    ctx->pc = 0x1a5bccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
