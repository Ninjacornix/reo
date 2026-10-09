#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001874A8
// Address: 0x1874a8 - 0x187520
void sub_001874A8_0x1874a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001874A8_0x1874a8");
#endif

    switch (ctx->pc) {
        case 0x1874f0u: goto label_1874f0;
        default: break;
    }

    ctx->pc = 0x1874a8u;

    // 0x1874a8: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1874a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1874ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1874acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1874b0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1874b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1874b4: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1874b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1874b8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1874b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1874bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1874bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1874c0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1874c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1874c4: 0x2421fa18  addiu       $at, $at, -0x5E8
    ctx->pc = 0x1874c4u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294965784));
    // 0x1874c8: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x1874c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1874cc: 0x9444002a  lhu         $a0, 0x2A($v0)
    ctx->pc = 0x1874ccu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 42)));
    // 0x1874d0: 0x244600d0  addiu       $a2, $v0, 0xD0
    ctx->pc = 0x1874d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 208));
    // 0x1874d4: 0x9443002c  lhu         $v1, 0x2C($v0)
    ctx->pc = 0x1874d4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1874d8: 0xa42818  mult        $a1, $a1, $a0
    ctx->pc = 0x1874d8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1874dc: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1874DCu;
    {
        const bool branch_taken_0x1874dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1874dc) {
            ctx->pc = 0x1874E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1874DCu;
            // 0x1874e0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1874E4u;
            goto label_1874e4;
        }
    }
    ctx->pc = 0x1874E4u;
label_1874e4:
    // 0x1874e4: 0xa3001a  div         $zero, $a1, $v1
    ctx->pc = 0x1874e4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1874e8: 0x2812  mflo        $a1
    ctx->pc = 0x1874e8u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1874ec: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1874ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
label_1874f0:
    // 0x1874f0: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1874f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1874f4: 0x10650008  beq         $v1, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1874F4u;
    {
        const bool branch_taken_0x1874f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1874F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1874F4u;
            // 0x1874f8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1874f4) {
            ctx->pc = 0x187518u;
            goto label_187518;
        }
    }
    ctx->pc = 0x1874FCu;
    // 0x1874fc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1874fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x187500: 0x28e20020  slti        $v0, $a3, 0x20
    ctx->pc = 0x187500u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x187504: 0x0  nop
    ctx->pc = 0x187504u;
    // NOP
    // 0x187508: 0x0  nop
    ctx->pc = 0x187508u;
    // NOP
    // 0x18750c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x18750Cu;
    {
        const bool branch_taken_0x18750c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18750c) {
            ctx->pc = 0x187510u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18750Cu;
            // 0x187510: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1874F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1874f0;
        }
    }
    ctx->pc = 0x187514u;
    // 0x187514: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x187514u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_187518:
    // 0x187518: 0x3e00008  jr          $ra
    ctx->pc = 0x187518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1874E4u: goto label_1874e4;
            case 0x1874F0u: goto label_1874f0;
            case 0x187518u: goto label_187518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
