#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170590
// Address: 0x170590 - 0x170630
void sub_00170590_0x170590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170590_0x170590");
#endif

    switch (ctx->pc) {
        case 0x1705a8u: goto label_1705a8;
        case 0x1705d0u: goto label_1705d0;
        case 0x170618u: goto label_170618;
        default: break;
    }

    ctx->pc = 0x170590u;

    // 0x170590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170594: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x170594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x170598: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170598u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17059c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17059cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1705a0: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1705A0u;
    SET_GPR_U32(ctx, 31, 0x1705A8u);
    ctx->pc = 0x1705A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1705A0u;
            // 0x1705a4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1705A8u; }
        if (ctx->pc != 0x1705A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1705A8u; }
        if (ctx->pc != 0x1705A8u) { return; }
    }
    ctx->pc = 0x1705A8u;
label_1705a8:
    // 0x1705a8: 0x8e051b30  lw          $a1, 0x1B30($s0)
    ctx->pc = 0x1705a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
    // 0x1705ac: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1705acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1705b0: 0x8ca20138  lw          $v0, 0x138($a1)
    ctx->pc = 0x1705b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 312)));
    // 0x1705b4: 0x18400011  blez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1705B4u;
    {
        const bool branch_taken_0x1705b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1705B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1705B4u;
            // 0x1705b8: 0x24a4013c  addiu       $a0, $a1, 0x13C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1705b4) {
            ctx->pc = 0x1705FCu;
            goto label_1705fc;
        }
    }
    ctx->pc = 0x1705BCu;
    // 0x1705bc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1705bcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1705c0: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1705c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1705c4: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1705c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1705c8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1705c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1705cc: 0x0  nop
    ctx->pc = 0x1705ccu;
    // NOP
label_1705d0:
    // 0x1705d0: 0x10470003  beq         $v0, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1705D0u;
    {
        const bool branch_taken_0x1705d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        ctx->pc = 0x1705D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1705D0u;
            // 0x1705d4: 0x24840080  addiu       $a0, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1705d0) {
            ctx->pc = 0x1705E0u;
            goto label_1705e0;
        }
    }
    ctx->pc = 0x1705D8u;
    // 0x1705d8: 0x54460003  bnel        $v0, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1705D8u;
    {
        const bool branch_taken_0x1705d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        if (branch_taken_0x1705d8) {
            ctx->pc = 0x1705DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1705D8u;
            // 0x1705dc: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1705E8u;
            goto label_1705e8;
        }
    }
    ctx->pc = 0x1705E0u;
label_1705e0:
    // 0x1705e0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1705e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1705e4: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1705e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_1705e8:
    // 0x1705e8: 0x0  nop
    ctx->pc = 0x1705e8u;
    // NOP
    // 0x1705ec: 0x0  nop
    ctx->pc = 0x1705ecu;
    // NOP
    // 0x1705f0: 0x0  nop
    ctx->pc = 0x1705f0u;
    // NOP
    // 0x1705f4: 0x5460fff6  bnel        $v1, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x1705F4u;
    {
        const bool branch_taken_0x1705f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1705f4) {
            ctx->pc = 0x1705F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1705F4u;
            // 0x1705f8: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1705D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1705d0;
        }
    }
    ctx->pc = 0x1705FCu;
label_1705fc:
    // 0x1705fc: 0x8ca3007c  lw          $v1, 0x7C($a1)
    ctx->pc = 0x1705fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 124)));
    // 0x170600: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170604: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x170604u;
    {
        const bool branch_taken_0x170604 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x170608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170604u;
            // 0x170608: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170604) {
            ctx->pc = 0x170610u;
            goto label_170610;
        }
    }
    ctx->pc = 0x17060Cu;
    // 0x17060c: 0x50800a  movz        $s0, $v0, $s0
    ctx->pc = 0x17060cu;
    if (GPR_U64(ctx, 16) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
label_170610:
    // 0x170610: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x170610u;
    SET_GPR_U32(ctx, 31, 0x170618u);
    ctx->pc = 0x170614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170610u;
            // 0x170614: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170618u; }
        if (ctx->pc != 0x170618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170618u; }
        if (ctx->pc != 0x170618u) { return; }
    }
    ctx->pc = 0x170618u;
label_170618:
    // 0x170618: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x170618u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17061c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17061cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170620: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x170620u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170624: 0x3e00008  jr          $ra
    ctx->pc = 0x170624u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170624u;
            // 0x170628: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1705A8u: goto label_1705a8;
            case 0x1705D0u: goto label_1705d0;
            case 0x1705E0u: goto label_1705e0;
            case 0x1705E8u: goto label_1705e8;
            case 0x1705FCu: goto label_1705fc;
            case 0x170610u: goto label_170610;
            case 0x170618u: goto label_170618;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17062Cu;
    // 0x17062c: 0x0  nop
    ctx->pc = 0x17062cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
