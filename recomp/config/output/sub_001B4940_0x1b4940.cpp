#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4940
// Address: 0x1b4940 - 0x1b49ac
void sub_001B4940_0x1b4940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4940_0x1b4940");
#endif

    switch (ctx->pc) {
        case 0x1b495cu: goto label_1b495c;
        case 0x1b4988u: goto label_1b4988;
        default: break;
    }

    ctx->pc = 0x1b4940u;

    // 0x1b4940: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4944: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b4948: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4948u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b494c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b494cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4950: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b4950u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b4954: 0x263151d0  addiu       $s1, $s1, 0x51D0
    ctx->pc = 0x1b4954u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20944));
    // 0x1b4958: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b4958u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b495c:
    // 0x1b495c: 0x86230000  lh          $v1, 0x0($s1)
    ctx->pc = 0x1b495cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b4960: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B4960u;
    {
        const bool branch_taken_0x1b4960 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4960) {
            ctx->pc = 0x1B4988u;
            goto label_1b4988;
        }
    }
    ctx->pc = 0x1B4968u;
    // 0x1b4968: 0x86230006  lh          $v1, 0x6($s1)
    ctx->pc = 0x1b4968u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 6)));
    // 0x1b496c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B496Cu;
    {
        const bool branch_taken_0x1b496c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b496c) {
            ctx->pc = 0x1B4988u;
            goto label_1b4988;
        }
    }
    ctx->pc = 0x1B4974u;
    // 0x1b4974: 0x9223000b  lbu         $v1, 0xB($s1)
    ctx->pc = 0x1b4974u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 11)));
    // 0x1b4978: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4978u;
    {
        const bool branch_taken_0x1b4978 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B497Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4978u;
            // 0x1b497c: 0x2624000c  addiu       $a0, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4978) {
            ctx->pc = 0x1B4988u;
            goto label_1b4988;
        }
    }
    ctx->pc = 0x1B4980u;
    // 0x1b4980: 0xc06d26c  jal         func_1B49B0
    ctx->pc = 0x1B4980u;
    SET_GPR_U32(ctx, 31, 0x1B4988u);
    ctx->pc = 0x1B49B0u;
    if (runtime->hasFunction(0x1B49B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B49B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4988u; }
        if (ctx->pc != 0x1B4988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B49B0_0x1b49b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4988u; }
        if (ctx->pc != 0x1B4988u) { return; }
    }
    ctx->pc = 0x1B4988u;
label_1b4988:
    // 0x1b4988: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b4988u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b498c: 0x2a030020  slti        $v1, $s0, 0x20
    ctx->pc = 0x1b498cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b4990: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1B4990u;
    {
        const bool branch_taken_0x1b4990 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4990u;
            // 0x1b4994: 0x2631008c  addiu       $s1, $s1, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4990) {
            ctx->pc = 0x1B495Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b495c;
        }
    }
    ctx->pc = 0x1B4998u;
    // 0x1b4998: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b4998u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b499c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b499cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b49a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b49a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b49a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B49A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B49A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B49A4u;
            // 0x1b49a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B495Cu: goto label_1b495c;
            case 0x1B4988u: goto label_1b4988;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B49ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
