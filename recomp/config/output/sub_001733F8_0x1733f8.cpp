#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001733F8
// Address: 0x1733f8 - 0x1734b4
void sub_001733F8_0x1733f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001733F8_0x1733f8");
#endif

    switch (ctx->pc) {
        case 0x17340cu: goto label_17340c;
        case 0x173430u: goto label_173430;
        case 0x1734a0u: goto label_1734a0;
        default: break;
    }

    ctx->pc = 0x1733f8u;

    // 0x1733f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1733f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1733fc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1733fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x173400: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x173400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x173404: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x173404u;
    SET_GPR_U32(ctx, 31, 0x17340Cu);
    ctx->pc = 0x173408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173404u;
            // 0x173408: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17340Cu; }
        if (ctx->pc != 0x17340Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17340Cu; }
        if (ctx->pc != 0x17340Cu) { return; }
    }
    ctx->pc = 0x17340Cu;
label_17340c:
    // 0x17340c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x17340cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x173410: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173410u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173414: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x173414u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x173418: 0x2446f18c  addiu       $a2, $v0, -0xE74
    ctx->pc = 0x173418u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17341c: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x17341cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x173420: 0x24070006  addiu       $a3, $zero, 0x6
    ctx->pc = 0x173420u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x173424: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x173424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173428: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x173428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x17342c: 0x0  nop
    ctx->pc = 0x17342cu;
    // NOP
label_173430:
    // 0x173430: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x173430u;
    {
        const bool branch_taken_0x173430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173430u;
            // 0x173434: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173430) {
            ctx->pc = 0x17346Cu;
            goto label_17346c;
        }
    }
    ctx->pc = 0x173438u;
    // 0x173438: 0x8c420048  lw          $v0, 0x48($v0)
    ctx->pc = 0x173438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17343c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17343Cu;
    {
        const bool branch_taken_0x17343c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17343Cu;
            // 0x173440: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17343c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173444u;
    // 0x173444: 0x10470004  beq         $v0, $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x173444u;
    {
        const bool branch_taken_0x173444 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        ctx->pc = 0x173448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173444u;
            // 0x173448: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173444) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x17344Cu;
    // 0x17344c: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17344Cu;
    {
        const bool branch_taken_0x17344c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x173450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17344Cu;
            // 0x173450: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17344c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173454u;
    // 0x173454: 0x24100002  addiu       $s0, $zero, 0x2
    ctx->pc = 0x173454u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_173458:
    // 0x173458: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x173458u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x17345c: 0x3a22021  addu        $a0, $sp, $v0
    ctx->pc = 0x17345cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x173460: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x173460u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x173464: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x173464u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x173468: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x173468u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
label_17346c:
    // 0x17346c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x17346cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x173470: 0x4a3ffef  bgezl       $a1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x173470u;
    {
        const bool branch_taken_0x173470 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x173470) {
            ctx->pc = 0x173474u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173470u;
            // 0x173474: 0x8cc20000  lw          $v0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173430u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173430;
        }
    }
    ctx->pc = 0x173478u;
    // 0x173478: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x173478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x17347c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17347Cu;
    {
        const bool branch_taken_0x17347c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17347Cu;
            // 0x173480: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17347c) {
            ctx->pc = 0x173490u;
            goto label_173490;
        }
    }
    ctx->pc = 0x173484u;
    // 0x173484: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x173484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173488: 0x24100002  addiu       $s0, $zero, 0x2
    ctx->pc = 0x173488u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17348c: 0x2800a  movz        $s0, $zero, $v0
    ctx->pc = 0x17348cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 0));
label_173490:
    // 0x173490: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173490u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173494: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x173494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x173498: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x173498u;
    SET_GPR_U32(ctx, 31, 0x1734A0u);
    ctx->pc = 0x17349Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173498u;
            // 0x17349c: 0xac50f120  sw          $s0, -0xEE0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963488), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734A0u; }
        if (ctx->pc != 0x1734A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734A0u; }
        if (ctx->pc != 0x1734A0u) { return; }
    }
    ctx->pc = 0x1734A0u;
label_1734a0:
    // 0x1734a0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1734a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1734a4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1734a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1734a8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1734a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1734ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1734ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1734B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1734ACu;
            // 0x1734b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17340Cu: goto label_17340c;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            case 0x1734A0u: goto label_1734a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1734B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
