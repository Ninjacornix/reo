#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E768
// Address: 0x16e768 - 0x16e7c8
void sub_0016E768_0x16e768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E768_0x16e768");
#endif

    ctx->pc = 0x16e768u;

    // 0x16e768: 0x8c821b30  lw          $v0, 0x1B30($a0)
    ctx->pc = 0x16e768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x16e76c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x16e76cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e770: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x16e770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16e774: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x16e774u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e778: 0x8c450074  lw          $a1, 0x74($v0)
    ctx->pc = 0x16e778u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 116)));
    // 0x16e77c: 0x10a3000c  beq         $a1, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x16E77Cu;
    {
        const bool branch_taken_0x16e77c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x16E780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E77Cu;
            // 0x16e780: 0x2ca20004  sltiu       $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e77c) {
            ctx->pc = 0x16E7B0u;
            goto label_16e7b0;
        }
    }
    ctx->pc = 0x16E784u;
    // 0x16e784: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16E784u;
    {
        const bool branch_taken_0x16e784 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E784u;
            // 0x16e788: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e784) {
            ctx->pc = 0x16E7BCu;
            goto label_16e7bc;
        }
    }
    ctx->pc = 0x16E78Cu;
    // 0x16e78c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x16e78cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e790: 0x14a2000a  bne         $a1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16E790u;
    {
        const bool branch_taken_0x16e790 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x16E794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E790u;
            // 0x16e794: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e790) {
            ctx->pc = 0x16E7BCu;
            goto label_16e7bc;
        }
    }
    ctx->pc = 0x16E798u;
    // 0x16e798: 0x2482fffe  addiu       $v0, $a0, -0x2
    ctx->pc = 0x16e798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x16e79c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16e79cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16e7a0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16E7A0u;
    {
        const bool branch_taken_0x16e7a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e7a0) {
            ctx->pc = 0x16E7A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E7A0u;
            // 0x16e7a4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E7B8u;
            goto label_16e7b8;
        }
    }
    ctx->pc = 0x16E7A8u;
    // 0x16e7a8: 0x3e00008  jr          $ra
    ctx->pc = 0x16E7A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E7A8u;
            // 0x16e7ac: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E7B0u: goto label_16e7b0;
            case 0x16E7B8u: goto label_16e7b8;
            case 0x16E7BCu: goto label_16e7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E7B0u;
label_16e7b0:
    // 0x16e7b0: 0x851026  xor         $v0, $a0, $a1
    ctx->pc = 0x16e7b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 5));
    // 0x16e7b4: 0x2c460001  sltiu       $a2, $v0, 0x1
    ctx->pc = 0x16e7b4u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16e7b8:
    // 0x16e7b8: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x16e7b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_16e7bc:
    // 0x16e7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x16E7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E7B0u: goto label_16e7b0;
            case 0x16E7B8u: goto label_16e7b8;
            case 0x16E7BCu: goto label_16e7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E7C4u;
    // 0x16e7c4: 0x0  nop
    ctx->pc = 0x16e7c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
