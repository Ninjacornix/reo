#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001753F0
// Address: 0x1753f0 - 0x175460
void sub_001753F0_0x1753f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001753F0_0x1753f0");
#endif

    switch (ctx->pc) {
        case 0x175420u: goto label_175420;
        case 0x175438u: goto label_175438;
        default: break;
    }

    ctx->pc = 0x1753f0u;

    // 0x1753f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1753f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1753f4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1753f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1753f8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1753f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1753fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1753fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175400: 0x24100007  addiu       $s0, $zero, 0x7
    ctx->pc = 0x175400u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x175404: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175408: 0x2451f18c  addiu       $s1, $v0, -0xE74
    ctx->pc = 0x175408u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17540c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17540cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175410: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x175410u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175414: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x175414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x175418: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x175418u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17541c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x17541cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_175420:
    // 0x175420: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x175420u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x175424: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x175424u;
    {
        const bool branch_taken_0x175424 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175424u;
            // 0x175428: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175424) {
            ctx->pc = 0x175438u;
            goto label_175438;
        }
    }
    ctx->pc = 0x17542Cu;
    // 0x17542c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x17542cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175430: 0xc05d518  jal         func_175460
    ctx->pc = 0x175430u;
    SET_GPR_U32(ctx, 31, 0x175438u);
    ctx->pc = 0x175434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175430u;
            // 0x175434: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175438u; }
        if (ctx->pc != 0x175438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175438u; }
        if (ctx->pc != 0x175438u) { return; }
    }
    ctx->pc = 0x175438u;
label_175438:
    // 0x175438: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x175438u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x17543c: 0x603fff8  bgezl       $s0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17543Cu;
    {
        const bool branch_taken_0x17543c = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x17543c) {
            ctx->pc = 0x175440u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17543Cu;
            // 0x175440: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x175420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_175420;
        }
    }
    ctx->pc = 0x175444u;
    // 0x175444: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175444u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175448: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175448u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17544c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17544cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175450: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x175450u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175454: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x175454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x175458: 0x3e00008  jr          $ra
    ctx->pc = 0x175458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17545Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175458u;
            // 0x17545c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175420u: goto label_175420;
            case 0x175438u: goto label_175438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
