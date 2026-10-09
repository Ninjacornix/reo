#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001673D8
// Address: 0x1673d8 - 0x167430
void sub_001673D8_0x1673d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001673D8_0x1673d8");
#endif

    switch (ctx->pc) {
        case 0x167400u: goto label_167400;
        case 0x167418u: goto label_167418;
        default: break;
    }

    ctx->pc = 0x1673d8u;

    // 0x1673d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1673d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1673dc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1673dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1673e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1673e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1673e4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1673e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1673e8: 0x2cb10001  sltiu       $s1, $a1, 0x1
    ctx->pc = 0x1673e8u;
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1673ec: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1673ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1673f0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1673f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1673f4: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1673f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1673f8: 0x40f809  jalr        $v0
    ctx->pc = 0x1673F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x167400u);
        ctx->pc = 0x1673FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1673F8u;
            // 0x1673fc: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x167400u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167400u: goto label_167400;
            case 0x167418u: goto label_167418;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x167400u; }
            if (ctx->pc != 0x167400u) { return; }
        }
        }
    }
    ctx->pc = 0x167400u;
label_167400:
    // 0x167400: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x167400u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x167404: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x167404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167408: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x167408u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16740c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x16740cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x167410: 0x40f809  jalr        $v0
    ctx->pc = 0x167410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x167418u);
        ctx->pc = 0x167414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167410u;
            // 0x167414: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x167418u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167400u: goto label_167400;
            case 0x167418u: goto label_167418;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x167418u; }
            if (ctx->pc != 0x167418u) { return; }
        }
        }
    }
    ctx->pc = 0x167418u;
label_167418:
    // 0x167418: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x167418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16741c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16741cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x167420: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167420u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167424: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x167424u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167428: 0x3e00008  jr          $ra
    ctx->pc = 0x167428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16742Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167428u;
            // 0x16742c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167400u: goto label_167400;
            case 0x167418u: goto label_167418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167430u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
