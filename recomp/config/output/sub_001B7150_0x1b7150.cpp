#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7150
// Address: 0x1b7150 - 0x1b71d0
void sub_001B7150_0x1b7150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7150_0x1b7150");
#endif

    switch (ctx->pc) {
        case 0x1b716cu: goto label_1b716c;
        case 0x1b71a0u: goto label_1b71a0;
        default: break;
    }

    ctx->pc = 0x1b7150u;

    // 0x1b7150: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b7150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b7154: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b7154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b7158: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1b7158u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b715c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b715cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b7160: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b7160u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7164: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B7164u;
    {
        const bool branch_taken_0x1b7164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7164u;
            // 0x1b7168: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7164) {
            ctx->pc = 0x1B71A8u;
            goto label_1b71a8;
        }
    }
    ctx->pc = 0x1B716Cu;
label_1b716c:
    // 0x1b716c: 0x103180  sll         $a2, $s0, 6
    ctx->pc = 0x1b716cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
    // 0x1b7170: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1b7170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1b7174: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1b7174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7178: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x1b7178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1b717c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1b717cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b7180: 0x8e220058  lw          $v0, 0x58($s1)
    ctx->pc = 0x1b7180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x1b7184: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1b7184u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7188: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b7188u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b718c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b718cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7190: 0x240b0008  addiu       $t3, $zero, 0x8
    ctx->pc = 0x1b7190u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b7194: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x1b7194u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1b7198: 0xc06dbf4  jal         func_1B6FD0
    ctx->pc = 0x1B7198u;
    SET_GPR_U32(ctx, 31, 0x1B71A0u);
    ctx->pc = 0x1B719Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7198u;
            // 0x1b719c: 0x503021  addu        $a2, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6FD0u;
    if (runtime->hasFunction(0x1B6FD0u)) {
        auto targetFn = runtime->lookupFunction(0x1B6FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B71A0u; }
        if (ctx->pc != 0x1B71A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6FD0_0x1b6fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B71A0u; }
        if (ctx->pc != 0x1B71A0u) { return; }
    }
    ctx->pc = 0x1B71A0u;
label_1b71a0:
    // 0x1b71a0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b71a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71a4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b71a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1b71a8:
    // 0x1b71a8: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x1b71a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1b71ac: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x1b71acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1b71b0: 0x1440ffee  bnez        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x1B71B0u;
    {
        const bool branch_taken_0x1b71b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B71B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B71B0u;
            // 0x1b71b4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b71b0) {
            ctx->pc = 0x1B716Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b716c;
        }
    }
    ctx->pc = 0x1B71B8u;
    // 0x1b71b8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b71b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b71bc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1b71bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71c0: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1b71c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b71c4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b71c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b71c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B71C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B71CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B71C8u;
            // 0x1b71cc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B716Cu: goto label_1b716c;
            case 0x1B71A0u: goto label_1b71a0;
            case 0x1B71A8u: goto label_1b71a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B71D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
