#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C680
// Address: 0x18c680 - 0x18c6e0
void sub_0018C680_0x18c680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C680_0x18c680");
#endif

    ctx->pc = 0x18c680u;

    // 0x18c680: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x18c680u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x18c684: 0x6493c  dsll32      $t1, $a2, 4
    ctx->pc = 0x18c684u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 6) << (32 + 4));
    // 0x18c688: 0xc31024  and         $v0, $a2, $v1
    ctx->pc = 0x18c688u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x18c68c: 0x9493e  dsrl32      $t1, $t1, 4
    ctx->pc = 0x18c68cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) >> (32 + 4));
    // 0x18c690: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x18C690u;
    {
        const bool branch_taken_0x18c690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x18C694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C690u;
            // 0x18c694: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c690) {
            ctx->pc = 0x18C69Cu;
            goto label_18c69c;
        }
    }
    ctx->pc = 0x18C698u;
    // 0x18c698: 0x3c088000  lui         $t0, 0x8000
    ctx->pc = 0x18c698u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32768 << 16));
label_18c69c:
    // 0x18c69c: 0x3c063000  lui         $a2, 0x3000
    ctx->pc = 0x18c69cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)12288 << 16));
    // 0x18c6a0: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x18c6a0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18c6a4: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x18c6a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x18c6a8: 0x1281825  or          $v1, $t1, $t0
    ctx->pc = 0x18c6a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x18c6ac: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x18c6acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x18c6b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c6b4: 0x14e20005  bne         $a3, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18C6B4u;
    {
        const bool branch_taken_0x18c6b4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x18C6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C6B4u;
            // 0x18c6b8: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c6b4) {
            ctx->pc = 0x18C6CCu;
            goto label_18c6cc;
        }
    }
    ctx->pc = 0x18C6BCu;
    // 0x18c6bc: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x18c6bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18c6c0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x18c6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x18c6c4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x18c6c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c6c8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18c6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_18c6cc:
    // 0x18c6cc: 0x3e00008  jr          $ra
    ctx->pc = 0x18C6CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C6D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C6CCu;
            // 0x18c6d0: 0x24820010  addiu       $v0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C69Cu: goto label_18c69c;
            case 0x18C6CCu: goto label_18c6cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C6D4u;
    // 0x18c6d4: 0x0  nop
    ctx->pc = 0x18c6d4u;
    // NOP
    // 0x18c6d8: 0x0  nop
    ctx->pc = 0x18c6d8u;
    // NOP
    // 0x18c6dc: 0x0  nop
    ctx->pc = 0x18c6dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
