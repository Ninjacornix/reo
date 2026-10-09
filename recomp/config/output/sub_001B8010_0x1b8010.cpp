#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8010
// Address: 0x1b8010 - 0x1b80b0
void sub_001B8010_0x1b8010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8010_0x1b8010");
#endif

    switch (ctx->pc) {
        case 0x1b802cu: goto label_1b802c;
        case 0x1b8078u: goto label_1b8078;
        case 0x1b8088u: goto label_1b8088;
        default: break;
    }

    ctx->pc = 0x1b8010u;

    // 0x1b8010: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b8010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b8014: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b8014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b8018: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8018u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b801c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b801cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8020: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b8020u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8024: 0x3c100031  lui         $s0, 0x31
    ctx->pc = 0x1b8024u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49 << 16));
    // 0x1b8028: 0x26106350  addiu       $s0, $s0, 0x6350
    ctx->pc = 0x1b8028u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 25424));
label_1b802c:
    // 0x1b802c: 0x2a21000c  slti        $at, $s1, 0xC
    ctx->pc = 0x1b802cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x1b8030: 0x10200015  beqz        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B8030u;
    {
        const bool branch_taken_0x1b8030 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8030) {
            ctx->pc = 0x1B8088u;
            goto label_1b8088;
        }
    }
    ctx->pc = 0x1B8038u;
    // 0x1b8038: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1b8038u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b803c: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1b803cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1b8040: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8040u;
    {
        const bool branch_taken_0x1b8040 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B8044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8040u;
            // 0x1b8044: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8040) {
            ctx->pc = 0x1B8064u;
            goto label_1b8064;
        }
    }
    ctx->pc = 0x1B8048u;
    // 0x1b8048: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B8048u;
    {
        const bool branch_taken_0x1b8048 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b8048) {
            ctx->pc = 0x1B8064u;
            goto label_1b8064;
        }
    }
    ctx->pc = 0x1B8050u;
    // 0x1b8050: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1b8050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b8054: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B8054u;
    {
        const bool branch_taken_0x1b8054 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b8054) {
            ctx->pc = 0x1B8064u;
            goto label_1b8064;
        }
    }
    ctx->pc = 0x1B805Cu;
    // 0x1b805c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B805Cu;
    {
        const bool branch_taken_0x1b805c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B805Cu;
            // 0x1b8060: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b805c) {
            ctx->pc = 0x1B807Cu;
            goto label_1b807c;
        }
    }
    ctx->pc = 0x1B8064u;
label_1b8064:
    // 0x1b8064: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1b8064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1b8068: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B8068u;
    {
        const bool branch_taken_0x1b8068 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8068) {
            ctx->pc = 0x1B8078u;
            goto label_1b8078;
        }
    }
    ctx->pc = 0x1B8070u;
    // 0x1b8070: 0x40f809  jalr        $v0
    ctx->pc = 0x1B8070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B8078u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B8078u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B802Cu: goto label_1b802c;
            case 0x1B8064u: goto label_1b8064;
            case 0x1B8078u: goto label_1b8078;
            case 0x1B807Cu: goto label_1b807c;
            case 0x1B8088u: goto label_1b8088;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B8078u; }
            if (ctx->pc != 0x1B8078u) { return; }
        }
        }
    }
    ctx->pc = 0x1B8078u;
label_1b8078:
    // 0x1b8078: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b8078u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b807c:
    // 0x1b807c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b807cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8080: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B8080u;
    SET_GPR_U32(ctx, 31, 0x1B8088u);
    ctx->pc = 0x1B8084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8080u;
            // 0x1b8084: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8088u; }
        if (ctx->pc != 0x1B8088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8088u; }
        if (ctx->pc != 0x1B8088u) { return; }
    }
    ctx->pc = 0x1B8088u;
label_1b8088:
    // 0x1b8088: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b8088u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b808c: 0x2a230010  slti        $v1, $s1, 0x10
    ctx->pc = 0x1b808cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b8090: 0x1460ffe6  bnez        $v1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1B8090u;
    {
        const bool branch_taken_0x1b8090 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8090u;
            // 0x1b8094: 0x26100020  addiu       $s0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8090) {
            ctx->pc = 0x1B802Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b802c;
        }
    }
    ctx->pc = 0x1B8098u;
    // 0x1b8098: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b8098u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b809c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b809cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b80a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b80a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b80a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B80A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B80A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B80A4u;
            // 0x1b80a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B802Cu: goto label_1b802c;
            case 0x1B8064u: goto label_1b8064;
            case 0x1B8078u: goto label_1b8078;
            case 0x1B807Cu: goto label_1b807c;
            case 0x1B8088u: goto label_1b8088;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B80ACu;
    // 0x1b80ac: 0x0  nop
    ctx->pc = 0x1b80acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
