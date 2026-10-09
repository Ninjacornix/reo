#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E1B0
// Address: 0x18e1b0 - 0x18e230
void sub_0018E1B0_0x18e1b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E1B0_0x18e1b0");
#endif

    switch (ctx->pc) {
        case 0x18e1bcu: goto label_18e1bc;
        case 0x18e1c4u: goto label_18e1c4;
        default: break;
    }

    ctx->pc = 0x18e1b0u;

    // 0x18e1b0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x18e1b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e1b4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x18E1B4u;
    {
        const bool branch_taken_0x18e1b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E1B4u;
            // 0x18e1b8: 0x240700ff  addiu       $a3, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e1b4) {
            ctx->pc = 0x18E210u;
            goto label_18e210;
        }
    }
    ctx->pc = 0x18E1BCu;
label_18e1bc:
    // 0x18e1bc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x18E1BCu;
    {
        const bool branch_taken_0x18e1bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E1C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E1BCu;
            // 0x18e1c0: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e1bc) {
            ctx->pc = 0x18E200u;
            goto label_18e200;
        }
    }
    ctx->pc = 0x18E1C4u;
label_18e1c4:
    // 0x18e1c4: 0x90830003  lbu         $v1, 0x3($a0)
    ctx->pc = 0x18e1c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x18e1c8: 0x14670003  bne         $v1, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E1C8u;
    {
        const bool branch_taken_0x18e1c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 7));
        if (branch_taken_0x18e1c8) {
            ctx->pc = 0x18E1D8u;
            goto label_18e1d8;
        }
    }
    ctx->pc = 0x18E1D0u;
    // 0x18e1d0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x18E1D0u;
    {
        const bool branch_taken_0x18e1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E1D0u;
            // 0x18e1d4: 0x64030080  daddiu      $v1, $zero, 0x80 (Delay Slot)
        SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e1d0) {
            ctx->pc = 0x18E1F4u;
            goto label_18e1f4;
        }
    }
    ctx->pc = 0x18E1D8u;
label_18e1d8:
    // 0x18e1d8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x18E1D8u;
    {
        const bool branch_taken_0x18e1d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e1d8) {
            ctx->pc = 0x18E1F4u;
            goto label_18e1f4;
        }
    }
    ctx->pc = 0x18E1E0u;
    // 0x18e1e0: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x18e1e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x18e1e4: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x18e1e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x18e1e8: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x18E1E8u;
    {
        const bool branch_taken_0x18e1e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e1e8) {
            ctx->pc = 0x18E1F4u;
            goto label_18e1f4;
        }
    }
    ctx->pc = 0x18E1F0u;
    // 0x18e1f0: 0x64030001  daddiu      $v1, $zero, 0x1
    ctx->pc = 0x18e1f0u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)1);
label_18e1f4:
    // 0x18e1f4: 0xa0830003  sb          $v1, 0x3($a0)
    ctx->pc = 0x18e1f4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x18e1f8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x18e1f8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x18e1fc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x18e1fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
label_18e200:
    // 0x18e200: 0x125182a  slt         $v1, $t1, $a1
    ctx->pc = 0x18e200u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x18e204: 0x1460ffef  bnez        $v1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x18E204u;
    {
        const bool branch_taken_0x18e204 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e204) {
            ctx->pc = 0x18E1C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e1c4;
        }
    }
    ctx->pc = 0x18E20Cu;
    // 0x18e20c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x18e20cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_18e210:
    // 0x18e210: 0x106182a  slt         $v1, $t0, $a2
    ctx->pc = 0x18e210u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x18e214: 0x1460ffe9  bnez        $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x18E214u;
    {
        const bool branch_taken_0x18e214 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e214) {
            ctx->pc = 0x18E1BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e1bc;
        }
    }
    ctx->pc = 0x18E21Cu;
    // 0x18e21c: 0x3e00008  jr          $ra
    ctx->pc = 0x18E21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E1BCu: goto label_18e1bc;
            case 0x18E1C4u: goto label_18e1c4;
            case 0x18E1D8u: goto label_18e1d8;
            case 0x18E1F4u: goto label_18e1f4;
            case 0x18E200u: goto label_18e200;
            case 0x18E210u: goto label_18e210;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E224u;
    // 0x18e224: 0x0  nop
    ctx->pc = 0x18e224u;
    // NOP
    // 0x18e228: 0x0  nop
    ctx->pc = 0x18e228u;
    // NOP
    // 0x18e22c: 0x0  nop
    ctx->pc = 0x18e22cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
