#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192980
// Address: 0x192980 - 0x192a00
void sub_00192980_0x192980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192980_0x192980");
#endif

    switch (ctx->pc) {
        case 0x1929acu: goto label_1929ac;
        case 0x1929d0u: goto label_1929d0;
        default: break;
    }

    ctx->pc = 0x192980u;

    // 0x192980: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x192980u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x192984: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x192984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x192988: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x192988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19298c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19298cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x192990: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x192990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192994: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192998: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x192998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19299c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19299cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1929a0: 0x84910000  lh          $s1, 0x0($a0)
    ctx->pc = 0x1929a0u;
    SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1929a4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1929A4u;
    {
        const bool branch_taken_0x1929a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1929A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1929A4u;
            // 0x1929a8: 0x24900002  addiu       $s0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1929a4) {
            ctx->pc = 0x1929D8u;
            goto label_1929d8;
        }
    }
    ctx->pc = 0x1929ACu;
label_1929ac:
    // 0x1929ac: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1929acu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1929b0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1929b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1929b4: 0x121180  sll         $v0, $s2, 6
    ctx->pc = 0x1929b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
    // 0x1929b8: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x1929b8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x1929bc: 0x412821  addu        $a1, $v0, $at
    ctx->pc = 0x1929bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x1929c0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1929c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1929c4: 0x31180  sll         $v0, $v1, 6
    ctx->pc = 0x1929c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1929c8: 0xc0626f8  jal         func_189BE0
    ctx->pc = 0x1929C8u;
    SET_GPR_U32(ctx, 31, 0x1929D0u);
    ctx->pc = 0x1929CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1929C8u;
            // 0x1929cc: 0x2622021  addu        $a0, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189BE0u;
    if (runtime->hasFunction(0x189BE0u)) {
        auto targetFn = runtime->lookupFunction(0x189BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1929D0u; }
        if (ctx->pc != 0x1929D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189BE0_0x189be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1929D0u; }
        if (ctx->pc != 0x1929D0u) { return; }
    }
    ctx->pc = 0x1929D0u;
label_1929d0:
    // 0x1929d0: 0x26100002  addiu       $s0, $s0, 0x2
    ctx->pc = 0x1929d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1929d4: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1929d4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1929d8:
    // 0x1929d8: 0x251182a  slt         $v1, $s2, $s1
    ctx->pc = 0x1929d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1929dc: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1929DCu;
    {
        const bool branch_taken_0x1929dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1929dc) {
            ctx->pc = 0x1929ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1929ac;
        }
    }
    ctx->pc = 0x1929E4u;
    // 0x1929e4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1929e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1929e8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1929e8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1929ec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1929ecu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1929f0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1929f0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1929f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1929f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1929f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1929F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1929FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1929F8u;
            // 0x1929fc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1929ACu: goto label_1929ac;
            case 0x1929D0u: goto label_1929d0;
            case 0x1929D8u: goto label_1929d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192A00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
