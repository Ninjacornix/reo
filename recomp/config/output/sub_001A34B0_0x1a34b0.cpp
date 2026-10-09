#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A34B0
// Address: 0x1a34b0 - 0x1a3500
void sub_001A34B0_0x1a34b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A34B0_0x1a34b0");
#endif

    switch (ctx->pc) {
        case 0x1a34c0u: goto label_1a34c0;
        case 0x1a34dcu: goto label_1a34dc;
        default: break;
    }

    ctx->pc = 0x1a34b0u;

    // 0x1a34b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a34b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a34b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a34b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a34b8: 0xc068c84  jal         func_1A3210
    ctx->pc = 0x1A34B8u;
    SET_GPR_U32(ctx, 31, 0x1A34C0u);
    ctx->pc = 0x1A3210u;
    if (runtime->hasFunction(0x1A3210u)) {
        auto targetFn = runtime->lookupFunction(0x1A3210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A34C0u; }
        if (ctx->pc != 0x1A34C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3210_0x1a3210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A34C0u; }
        if (ctx->pc != 0x1A34C0u) { return; }
    }
    ctx->pc = 0x1A34C0u;
label_1a34c0:
    // 0x1a34c0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A34C0u;
    {
        const bool branch_taken_0x1a34c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A34C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A34C0u;
            // 0x1a34c4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a34c0) {
            ctx->pc = 0x1A34D0u;
            goto label_1a34d0;
        }
    }
    ctx->pc = 0x1A34C8u;
    // 0x1a34c8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A34C8u;
    {
        const bool branch_taken_0x1a34c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A34CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A34C8u;
            // 0x1a34cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a34c8) {
            ctx->pc = 0x1A34F0u;
            goto label_1a34f0;
        }
    }
    ctx->pc = 0x1A34D0u;
label_1a34d0:
    // 0x1a34d0: 0x3c050005  lui         $a1, 0x5
    ctx->pc = 0x1a34d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)5 << 16));
    // 0x1a34d4: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A34D4u;
    SET_GPR_U32(ctx, 31, 0x1A34DCu);
    ctx->pc = 0x1A34D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A34D4u;
            // 0x1a34d8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A34DCu; }
        if (ctx->pc != 0x1A34DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A34DCu; }
        if (ctx->pc != 0x1A34DCu) { return; }
    }
    ctx->pc = 0x1A34DCu;
label_1a34dc:
    // 0x1a34dc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A34DCu;
    {
        const bool branch_taken_0x1a34dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a34dc) {
            ctx->pc = 0x1A34ECu;
            goto label_1a34ec;
        }
    }
    ctx->pc = 0x1A34E4u;
    // 0x1a34e4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A34E4u;
    {
        const bool branch_taken_0x1a34e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A34E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A34E4u;
            // 0x1a34e8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a34e4) {
            ctx->pc = 0x1A34F0u;
            goto label_1a34f0;
        }
    }
    ctx->pc = 0x1A34ECu;
label_1a34ec:
    // 0x1a34ec: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a34ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1a34f0:
    // 0x1a34f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a34f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a34f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A34F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A34F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A34F4u;
            // 0x1a34f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A34C0u: goto label_1a34c0;
            case 0x1A34D0u: goto label_1a34d0;
            case 0x1A34DCu: goto label_1a34dc;
            case 0x1A34ECu: goto label_1a34ec;
            case 0x1A34F0u: goto label_1a34f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A34FCu;
    // 0x1a34fc: 0x0  nop
    ctx->pc = 0x1a34fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
