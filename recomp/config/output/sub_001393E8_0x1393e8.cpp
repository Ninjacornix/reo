#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001393E8
// Address: 0x1393e8 - 0x139460
void sub_001393E8_0x1393e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001393E8_0x1393e8");
#endif

    switch (ctx->pc) {
        case 0x139428u: goto label_139428;
        case 0x13943cu: goto label_13943c;
        default: break;
    }

    ctx->pc = 0x1393e8u;

    // 0x1393e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1393e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1393ec: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1393ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1393f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1393f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1393f4: 0x2463c42c  addiu       $v1, $v1, -0x3BD4
    ctx->pc = 0x1393f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294951980));
    // 0x1393f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1393f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1393fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1393fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x139400: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x139400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x139404: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x139404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x139408: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x139408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13940c: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13940Cu;
    {
        const bool branch_taken_0x13940c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x139410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13940Cu;
            // 0x139410: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13940c) {
            ctx->pc = 0x139448u;
            goto label_139448;
        }
    }
    ctx->pc = 0x139414u;
    // 0x139414: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139414u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139418: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x139418u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13941c: 0x2450c430  addiu       $s0, $v0, -0x3BD0
    ctx->pc = 0x13941cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294951984));
    // 0x139420: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x139420u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x139424: 0x0  nop
    ctx->pc = 0x139424u;
    // NOP
label_139428:
    // 0x139428: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x139428u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13942c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13942Cu;
    {
        const bool branch_taken_0x13942c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13942c) {
            ctx->pc = 0x139430u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13942Cu;
            // 0x139430: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139440u;
            goto label_139440;
        }
    }
    ctx->pc = 0x139434u;
    // 0x139434: 0xc04e444  jal         func_139110
    ctx->pc = 0x139434u;
    SET_GPR_U32(ctx, 31, 0x13943Cu);
    ctx->pc = 0x139438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139434u;
            // 0x139438: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139110u;
    if (runtime->hasFunction(0x139110u)) {
        auto targetFn = runtime->lookupFunction(0x139110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13943Cu; }
        if (ctx->pc != 0x13943Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13943Cu; }
        if (ctx->pc != 0x13943Cu) { return; }
    }
    ctx->pc = 0x13943Cu;
label_13943c:
    // 0x13943c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13943cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_139440:
    // 0x139440: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x139440u;
    {
        const bool branch_taken_0x139440 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x139444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139440u;
            // 0x139444: 0x26100044  addiu       $s0, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139440) {
            ctx->pc = 0x139428u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139428;
        }
    }
    ctx->pc = 0x139448u;
label_139448:
    // 0x139448: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13944c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13944cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139450: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x139450u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139454: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x139454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139458: 0x3e00008  jr          $ra
    ctx->pc = 0x139458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13945Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139458u;
            // 0x13945c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139428u: goto label_139428;
            case 0x13943Cu: goto label_13943c;
            case 0x139440u: goto label_139440;
            case 0x139448u: goto label_139448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
