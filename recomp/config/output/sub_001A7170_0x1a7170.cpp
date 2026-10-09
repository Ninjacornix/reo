#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7170
// Address: 0x1a7170 - 0x1a71e0
void sub_001A7170_0x1a7170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7170_0x1a7170");
#endif

    switch (ctx->pc) {
        case 0x1a718cu: goto label_1a718c;
        case 0x1a7198u: goto label_1a7198;
        case 0x1a71bcu: goto label_1a71bc;
        default: break;
    }

    ctx->pc = 0x1a7170u;

    // 0x1a7170: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a7170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a7174: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a7174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a7178: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a7178u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a717c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a717cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a7180: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a7180u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7184: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1a7184u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7188: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1a7188u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1a718c:
    // 0x1a718c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a718cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7190: 0xc045e06  jal         func_117818
    ctx->pc = 0x1A7190u;
    SET_GPR_U32(ctx, 31, 0x1A7198u);
    ctx->pc = 0x1A7194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7190u;
            // 0x1a7194: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7198u; }
        if (ctx->pc != 0x1A7198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7198u; }
        if (ctx->pc != 0x1A7198u) { return; }
    }
    ctx->pc = 0x1A7198u;
label_1a7198:
    // 0x1a7198: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A7198u;
    {
        const bool branch_taken_0x1a7198 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1a7198) {
            ctx->pc = 0x1A71A8u;
            goto label_1a71a8;
        }
    }
    ctx->pc = 0x1A71A0u;
    // 0x1a71a0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A71A0u;
    {
        const bool branch_taken_0x1a71a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A71A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71A0u;
            // 0x1a71a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a71a0) {
            ctx->pc = 0x1A71C8u;
            goto label_1a71c8;
        }
    }
    ctx->pc = 0x1A71A8u;
label_1a71a8:
    // 0x1a71a8: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x1a71a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1a71ac: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A71ACu;
    {
        const bool branch_taken_0x1a71ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A71B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71ACu;
            // 0x1a71b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a71ac) {
            ctx->pc = 0x1A71C8u;
            goto label_1a71c8;
        }
    }
    ctx->pc = 0x1A71B4u;
    // 0x1a71b4: 0xc069c30  jal         func_1A70C0
    ctx->pc = 0x1A71B4u;
    SET_GPR_U32(ctx, 31, 0x1A71BCu);
    ctx->pc = 0x1A71B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71B4u;
            // 0x1a71b8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A70C0u;
    if (runtime->hasFunction(0x1A70C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A70C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A71BCu; }
        if (ctx->pc != 0x1A71BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A70C0_0x1a70c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A71BCu; }
        if (ctx->pc != 0x1A71BCu) { return; }
    }
    ctx->pc = 0x1A71BCu;
label_1a71bc:
    // 0x1a71bc: 0x441fff3  bgez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A71BCu;
    {
        const bool branch_taken_0x1a71bc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A71C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71BCu;
            // 0x1a71c0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a71bc) {
            ctx->pc = 0x1A718Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a718c;
        }
    }
    ctx->pc = 0x1A71C4u;
    // 0x1a71c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a71c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a71c8:
    // 0x1a71c8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a71c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a71cc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a71ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a71d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a71d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a71d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A71D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A71D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A71D4u;
            // 0x1a71d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A718Cu: goto label_1a718c;
            case 0x1A7198u: goto label_1a7198;
            case 0x1A71A8u: goto label_1a71a8;
            case 0x1A71BCu: goto label_1a71bc;
            case 0x1A71C8u: goto label_1a71c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A71DCu;
    // 0x1a71dc: 0x0  nop
    ctx->pc = 0x1a71dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
