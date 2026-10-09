#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A31B0
// Address: 0x1a31b0 - 0x1a3210
void sub_001A31B0_0x1a31b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A31B0_0x1a31b0");
#endif

    switch (ctx->pc) {
        case 0x1a31c0u: goto label_1a31c0;
        case 0x1a31d0u: goto label_1a31d0;
        case 0x1a31ecu: goto label_1a31ec;
        default: break;
    }

    ctx->pc = 0x1a31b0u;

    // 0x1a31b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a31b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a31b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a31b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a31b8: 0xc068d64  jal         func_1A3590
    ctx->pc = 0x1A31B8u;
    SET_GPR_U32(ctx, 31, 0x1A31C0u);
    ctx->pc = 0x1A31BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31B8u;
            // 0x1a31bc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3590u;
    if (runtime->hasFunction(0x1A3590u)) {
        auto targetFn = runtime->lookupFunction(0x1A3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31C0u; }
        if (ctx->pc != 0x1A31C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3590_0x1a3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31C0u; }
        if (ctx->pc != 0x1A31C0u) { return; }
    }
    ctx->pc = 0x1A31C0u;
label_1a31c0:
    // 0x1a31c0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a31c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a31c4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a31c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a31c8: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A31C8u;
    SET_GPR_U32(ctx, 31, 0x1A31D0u);
    ctx->pc = 0x1A31CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31C8u;
            // 0x1a31cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31D0u; }
        if (ctx->pc != 0x1A31D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31D0u; }
        if (ctx->pc != 0x1A31D0u) { return; }
    }
    ctx->pc = 0x1A31D0u;
label_1a31d0:
    // 0x1a31d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A31D0u;
    {
        const bool branch_taken_0x1a31d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A31D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31D0u;
            // 0x1a31d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a31d0) {
            ctx->pc = 0x1A31E0u;
            goto label_1a31e0;
        }
    }
    ctx->pc = 0x1A31D8u;
    // 0x1a31d8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A31D8u;
    {
        const bool branch_taken_0x1a31d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A31DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31D8u;
            // 0x1a31dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a31d8) {
            ctx->pc = 0x1A3200u;
            goto label_1a3200;
        }
    }
    ctx->pc = 0x1A31E0u;
label_1a31e0:
    // 0x1a31e0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a31e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a31e4: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A31E4u;
    SET_GPR_U32(ctx, 31, 0x1A31ECu);
    ctx->pc = 0x1A31E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31E4u;
            // 0x1a31e8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31ECu; }
        if (ctx->pc != 0x1A31ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A31ECu; }
        if (ctx->pc != 0x1A31ECu) { return; }
    }
    ctx->pc = 0x1A31ECu;
label_1a31ec:
    // 0x1a31ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A31ECu;
    {
        const bool branch_taken_0x1a31ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a31ec) {
            ctx->pc = 0x1A31FCu;
            goto label_1a31fc;
        }
    }
    ctx->pc = 0x1A31F4u;
    // 0x1a31f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A31F4u;
    {
        const bool branch_taken_0x1a31f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A31F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A31F4u;
            // 0x1a31f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a31f4) {
            ctx->pc = 0x1A3200u;
            goto label_1a3200;
        }
    }
    ctx->pc = 0x1A31FCu;
label_1a31fc:
    // 0x1a31fc: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a31fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1a3200:
    // 0x1a3200: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a3200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a3204: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a3204u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3208: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A320Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3208u;
            // 0x1a320c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A31C0u: goto label_1a31c0;
            case 0x1A31D0u: goto label_1a31d0;
            case 0x1A31E0u: goto label_1a31e0;
            case 0x1A31ECu: goto label_1a31ec;
            case 0x1A31FCu: goto label_1a31fc;
            case 0x1A3200u: goto label_1a3200;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3210u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
