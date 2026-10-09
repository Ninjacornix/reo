#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A36E0
// Address: 0x1a36e0 - 0x1a3760
void sub_001A36E0_0x1a36e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A36E0_0x1a36e0");
#endif

    switch (ctx->pc) {
        case 0x1a36f8u: goto label_1a36f8;
        case 0x1a372cu: goto label_1a372c;
        default: break;
    }

    ctx->pc = 0x1a36e0u;

    // 0x1a36e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a36e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a36e4: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a36e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a36e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a36e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a36ec: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a36ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a36f0: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A36F0u;
    SET_GPR_U32(ctx, 31, 0x1A36F8u);
    ctx->pc = 0x1A36F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A36F0u;
            // 0x1a36f4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A36F8u; }
        if (ctx->pc != 0x1A36F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A36F8u; }
        if (ctx->pc != 0x1A36F8u) { return; }
    }
    ctx->pc = 0x1A36F8u;
label_1a36f8:
    // 0x1a36f8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A36F8u;
    {
        const bool branch_taken_0x1a36f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a36f8) {
            ctx->pc = 0x1A3708u;
            goto label_1a3708;
        }
    }
    ctx->pc = 0x1A3700u;
    // 0x1a3700: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A3700u;
    {
        const bool branch_taken_0x1a3700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3700u;
            // 0x1a3704: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3700) {
            ctx->pc = 0x1A374Cu;
            goto label_1a374c;
        }
    }
    ctx->pc = 0x1A3708u;
label_1a3708:
    // 0x1a3708: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a3708u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a370c: 0x103082b  sltu        $at, $t0, $v1
    ctx->pc = 0x1a370cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a3710: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3710u;
    {
        const bool branch_taken_0x1a3710 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3710) {
            ctx->pc = 0x1A3720u;
            goto label_1a3720;
        }
    }
    ctx->pc = 0x1A3718u;
    // 0x1a3718: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A3718u;
    {
        const bool branch_taken_0x1a3718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A371Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3718u;
            // 0x1a371c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3718) {
            ctx->pc = 0x1A374Cu;
            goto label_1a374c;
        }
    }
    ctx->pc = 0x1A3720u;
label_1a3720:
    // 0x1a3720: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a3720u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1a3724: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3724u;
    {
        const bool branch_taken_0x1a3724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3724u;
            // 0x1a3728: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3724) {
            ctx->pc = 0x1A3738u;
            goto label_1a3738;
        }
    }
    ctx->pc = 0x1A372Cu;
label_1a372c:
    // 0x1a372c: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1a372cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a3730: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a3730u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a3734: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a3734u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1a3738:
    // 0x1a3738: 0x88182a  slt         $v1, $a0, $t0
    ctx->pc = 0x1a3738u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1a373c: 0x0  nop
    ctx->pc = 0x1a373cu;
    // NOP
    // 0x1a3740: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A3740u;
    {
        const bool branch_taken_0x1a3740 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3740) {
            ctx->pc = 0x1A372Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a372c;
        }
    }
    ctx->pc = 0x1A3748u;
    // 0x1a3748: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a3748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1a374c:
    // 0x1a374c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a374cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3750: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3750u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3750u;
            // 0x1a3754: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A36F8u: goto label_1a36f8;
            case 0x1A3708u: goto label_1a3708;
            case 0x1A3720u: goto label_1a3720;
            case 0x1A372Cu: goto label_1a372c;
            case 0x1A3738u: goto label_1a3738;
            case 0x1A374Cu: goto label_1a374c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3758u;
    // 0x1a3758: 0x0  nop
    ctx->pc = 0x1a3758u;
    // NOP
    // 0x1a375c: 0x0  nop
    ctx->pc = 0x1a375cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
