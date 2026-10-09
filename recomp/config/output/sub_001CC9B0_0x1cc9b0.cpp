#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC9B0
// Address: 0x1cc9b0 - 0x1cca30
void sub_001CC9B0_0x1cc9b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC9B0_0x1cc9b0");
#endif

    switch (ctx->pc) {
        case 0x1cc9d0u: goto label_1cc9d0;
        case 0x1cc9e4u: goto label_1cc9e4;
        case 0x1cc9f4u: goto label_1cc9f4;
        default: break;
    }

    ctx->pc = 0x1cc9b0u;

    // 0x1cc9b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cc9b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cc9b4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cc9b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cc9b8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cc9b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cc9bc: 0x3c110034  lui         $s1, 0x34
    ctx->pc = 0x1cc9bcu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)52 << 16));
    // 0x1cc9c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cc9c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc9c4: 0x26311640  addiu       $s1, $s1, 0x1640
    ctx->pc = 0x1cc9c4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 5696));
    // 0x1cc9c8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1cc9c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cc9cc: 0x26310010  addiu       $s1, $s1, 0x10
    ctx->pc = 0x1cc9ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
label_1cc9d0:
    // 0x1cc9d0: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1cc9d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cc9d4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC9D4u;
    {
        const bool branch_taken_0x1cc9d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc9d4) {
            ctx->pc = 0x1CC9E4u;
            goto label_1cc9e4;
        }
    }
    ctx->pc = 0x1CC9DCu;
    // 0x1cc9dc: 0xc07328c  jal         func_1CCA30
    ctx->pc = 0x1CC9DCu;
    SET_GPR_U32(ctx, 31, 0x1CC9E4u);
    ctx->pc = 0x1CCA30u;
    if (runtime->hasFunction(0x1CCA30u)) {
        auto targetFn = runtime->lookupFunction(0x1CCA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC9E4u; }
        if (ctx->pc != 0x1CC9E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA30_0x1cca30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC9E4u; }
        if (ctx->pc != 0x1CC9E4u) { return; }
    }
    ctx->pc = 0x1CC9E4u;
label_1cc9e4:
    // 0x1cc9e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1cc9e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc9e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc9e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc9ec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC9ECu;
    SET_GPR_U32(ctx, 31, 0x1CC9F4u);
    ctx->pc = 0x1CC9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC9ECu;
            // 0x1cc9f0: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC9F4u; }
        if (ctx->pc != 0x1CC9F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC9F4u; }
        if (ctx->pc != 0x1CC9F4u) { return; }
    }
    ctx->pc = 0x1CC9F4u;
label_1cc9f4:
    // 0x1cc9f4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cc9f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cc9f8: 0x2a030100  slti        $v1, $s0, 0x100
    ctx->pc = 0x1cc9f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cc9fc: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1CC9FCu;
    {
        const bool branch_taken_0x1cc9fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CCA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC9FCu;
            // 0x1cca00: 0x26310010  addiu       $s1, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc9fc) {
            ctx->pc = 0x1CC9D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cc9d0;
        }
    }
    ctx->pc = 0x1CCA04u;
    // 0x1cca04: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cca04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cca08: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cca08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cca0c: 0xac2366c8  sw          $v1, 0x66C8($at)
    ctx->pc = 0x1cca0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26312), GPR_U32(ctx, 3));
    // 0x1cca10: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cca10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cca14: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cca14u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cca18: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cca18u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cca1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCA1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CCA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCA1Cu;
            // 0x1cca20: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC9D0u: goto label_1cc9d0;
            case 0x1CC9E4u: goto label_1cc9e4;
            case 0x1CC9F4u: goto label_1cc9f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCA24u;
    // 0x1cca24: 0x0  nop
    ctx->pc = 0x1cca24u;
    // NOP
    // 0x1cca28: 0x0  nop
    ctx->pc = 0x1cca28u;
    // NOP
    // 0x1cca2c: 0x0  nop
    ctx->pc = 0x1cca2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
