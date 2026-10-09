#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A37E0
// Address: 0x1a37e0 - 0x1a3840
void sub_001A37E0_0x1a37e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A37E0_0x1a37e0");
#endif

    switch (ctx->pc) {
        case 0x1a37f4u: goto label_1a37f4;
        case 0x1a3810u: goto label_1a3810;
        case 0x1a3818u: goto label_1a3818;
        default: break;
    }

    ctx->pc = 0x1a37e0u;

    // 0x1a37e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a37e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a37e4: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x1a37e4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a37e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a37e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a37ec: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A37ECu;
    SET_GPR_U32(ctx, 31, 0x1A37F4u);
    ctx->pc = 0x1A37F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A37ECu;
            // 0x1a37f0: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A37F4u; }
        if (ctx->pc != 0x1A37F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A37F4u; }
        if (ctx->pc != 0x1A37F4u) { return; }
    }
    ctx->pc = 0x1A37F4u;
label_1a37f4:
    // 0x1a37f4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a37f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a37f8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A37F8u;
    {
        const bool branch_taken_0x1a37f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1A37FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A37F8u;
            // 0x1a37fc: 0x40582d  daddu       $t3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a37f8) {
            ctx->pc = 0x1A3808u;
            goto label_1a3808;
        }
    }
    ctx->pc = 0x1A3800u;
    // 0x1a3800: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A3800u;
    {
        const bool branch_taken_0x1a3800 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3800u;
            // 0x1a3804: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3800) {
            ctx->pc = 0x1A3830u;
            goto label_1a3830;
        }
    }
    ctx->pc = 0x1A3808u;
label_1a3808:
    // 0x1a3808: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A3808u;
    {
        const bool branch_taken_0x1a3808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A380Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3808u;
            // 0x1a380c: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3808) {
            ctx->pc = 0x1A3820u;
            goto label_1a3820;
        }
    }
    ctx->pc = 0x1A3810u;
label_1a3810:
    // 0x1a3810: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A3810u;
    SET_GPR_U32(ctx, 31, 0x1A3818u);
    ctx->pc = 0x1A3814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3810u;
            // 0x1a3814: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3818u; }
        if (ctx->pc != 0x1A3818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3818u; }
        if (ctx->pc != 0x1A3818u) { return; }
    }
    ctx->pc = 0x1A3818u;
label_1a3818:
    // 0x1a3818: 0x1224821  addu        $t1, $t1, $v0
    ctx->pc = 0x1a3818u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x1a381c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1a381cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_1a3820:
    // 0x1a3820: 0x14b102b  sltu        $v0, $t2, $t3
    ctx->pc = 0x1a3820u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
    // 0x1a3824: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A3824u;
    {
        const bool branch_taken_0x1a3824 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3824u;
            // 0x1a3828: 0x180202d  daddu       $a0, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3824) {
            ctx->pc = 0x1A3810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3810;
        }
    }
    ctx->pc = 0x1A382Cu;
    // 0x1a382c: 0x120102d  daddu       $v0, $t1, $zero
    ctx->pc = 0x1a382cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
label_1a3830:
    // 0x1a3830: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3830u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3834: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3834u;
            // 0x1a3838: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A37F4u: goto label_1a37f4;
            case 0x1A3808u: goto label_1a3808;
            case 0x1A3810u: goto label_1a3810;
            case 0x1A3818u: goto label_1a3818;
            case 0x1A3820u: goto label_1a3820;
            case 0x1A3830u: goto label_1a3830;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A383Cu;
    // 0x1a383c: 0x0  nop
    ctx->pc = 0x1a383cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
