#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B48E0
// Address: 0x1b48e0 - 0x1b493c
void sub_001B48E0_0x1b48e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B48E0_0x1b48e0");
#endif

    switch (ctx->pc) {
        case 0x1b4920u: goto label_1b4920;
        default: break;
    }

    ctx->pc = 0x1b48e0u;

    // 0x1b48e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b48e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b48e4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1b48e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b48e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b48e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b48ec: 0xc0502d  daddu       $t2, $a2, $zero
    ctx->pc = 0x1b48ecu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b48f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b48f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b48f4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1b48f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b48f8: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x1b48f8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b48fc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1b48fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4900: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x1b4900u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4904: 0x140382d  daddu       $a3, $t2, $zero
    ctx->pc = 0x1b4904u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4908: 0x120802d  daddu       $s0, $t1, $zero
    ctx->pc = 0x1b4908u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b490c: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x1b490cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4910: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b4910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4914: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1b4914u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4918: 0xc06d1b8  jal         func_1B46E0
    ctx->pc = 0x1B4918u;
    SET_GPR_U32(ctx, 31, 0x1B4920u);
    ctx->pc = 0x1B491Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4918u;
            // 0x1b491c: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B46E0u;
    if (runtime->hasFunction(0x1B46E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B46E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4920u; }
        if (ctx->pc != 0x1B4920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B46E0_0x1b46e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4920u; }
        if (ctx->pc != 0x1B4920u) { return; }
    }
    ctx->pc = 0x1B4920u;
label_1b4920:
    // 0x1b4920: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B4920u;
    {
        const bool branch_taken_0x1b4920 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4920) {
            ctx->pc = 0x1B492Cu;
            goto label_1b492c;
        }
    }
    ctx->pc = 0x1B4928u;
    // 0x1b4928: 0xa0500000  sb          $s0, 0x0($v0)
    ctx->pc = 0x1b4928u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 16));
label_1b492c:
    // 0x1b492c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b492cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4930: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4930u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4934: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4934u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4934u;
            // 0x1b4938: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4920u: goto label_1b4920;
            case 0x1B492Cu: goto label_1b492c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B493Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
