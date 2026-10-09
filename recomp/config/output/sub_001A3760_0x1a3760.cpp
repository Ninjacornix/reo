#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3760
// Address: 0x1a3760 - 0x1a37e0
void sub_001A3760_0x1a3760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3760_0x1a3760");
#endif

    switch (ctx->pc) {
        case 0x1a3778u: goto label_1a3778;
        case 0x1a37acu: goto label_1a37ac;
        default: break;
    }

    ctx->pc = 0x1a3760u;

    // 0x1a3760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3764: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a3764u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3768: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a376c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a376cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a3770: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3770u;
    SET_GPR_U32(ctx, 31, 0x1A3778u);
    ctx->pc = 0x1A3774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3770u;
            // 0x1a3774: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3778u; }
        if (ctx->pc != 0x1A3778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3778u; }
        if (ctx->pc != 0x1A3778u) { return; }
    }
    ctx->pc = 0x1A3778u;
label_1a3778:
    // 0x1a3778: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3778u;
    {
        const bool branch_taken_0x1a3778 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3778) {
            ctx->pc = 0x1A3788u;
            goto label_1a3788;
        }
    }
    ctx->pc = 0x1A3780u;
    // 0x1a3780: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A3780u;
    {
        const bool branch_taken_0x1a3780 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3780u;
            // 0x1a3784: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3780) {
            ctx->pc = 0x1A37CCu;
            goto label_1a37cc;
        }
    }
    ctx->pc = 0x1A3788u;
label_1a3788:
    // 0x1a3788: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a3788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a378c: 0x103082b  sltu        $at, $t0, $v1
    ctx->pc = 0x1a378cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a3790: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3790u;
    {
        const bool branch_taken_0x1a3790 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3790) {
            ctx->pc = 0x1A37A0u;
            goto label_1a37a0;
        }
    }
    ctx->pc = 0x1A3798u;
    // 0x1a3798: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A3798u;
    {
        const bool branch_taken_0x1a3798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A379Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3798u;
            // 0x1a379c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3798) {
            ctx->pc = 0x1A37CCu;
            goto label_1a37cc;
        }
    }
    ctx->pc = 0x1A37A0u;
label_1a37a0:
    // 0x1a37a0: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a37a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1a37a4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A37A4u;
    {
        const bool branch_taken_0x1a37a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A37A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A37A4u;
            // 0x1a37a8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a37a4) {
            ctx->pc = 0x1A37B8u;
            goto label_1a37b8;
        }
    }
    ctx->pc = 0x1A37ACu;
label_1a37ac:
    // 0x1a37ac: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1a37acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a37b0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a37b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a37b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a37b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1a37b8:
    // 0x1a37b8: 0x88182a  slt         $v1, $a0, $t0
    ctx->pc = 0x1a37b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1a37bc: 0x0  nop
    ctx->pc = 0x1a37bcu;
    // NOP
    // 0x1a37c0: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A37C0u;
    {
        const bool branch_taken_0x1a37c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a37c0) {
            ctx->pc = 0x1A37ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a37ac;
        }
    }
    ctx->pc = 0x1A37C8u;
    // 0x1a37c8: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a37c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1a37cc:
    // 0x1a37cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a37ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a37d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A37D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A37D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A37D0u;
            // 0x1a37d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3778u: goto label_1a3778;
            case 0x1A3788u: goto label_1a3788;
            case 0x1A37A0u: goto label_1a37a0;
            case 0x1A37ACu: goto label_1a37ac;
            case 0x1A37B8u: goto label_1a37b8;
            case 0x1A37CCu: goto label_1a37cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A37D8u;
    // 0x1a37d8: 0x0  nop
    ctx->pc = 0x1a37d8u;
    // NOP
    // 0x1a37dc: 0x0  nop
    ctx->pc = 0x1a37dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
