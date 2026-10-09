#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013DE40
// Address: 0x13de40 - 0x13df20
void sub_0013DE40_0x13de40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013DE40_0x13de40");
#endif

    switch (ctx->pc) {
        case 0x13de70u: goto label_13de70;
        case 0x13de80u: goto label_13de80;
        case 0x13de9cu: goto label_13de9c;
        case 0x13deb0u: goto label_13deb0;
        case 0x13dec4u: goto label_13dec4;
        case 0x13df00u: goto label_13df00;
        default: break;
    }

    ctx->pc = 0x13de40u;

    // 0x13de40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13de40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13de44: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13de44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13de48: 0x3c120022  lui         $s2, 0x22
    ctx->pc = 0x13de48u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)34 << 16));
    // 0x13de4c: 0x8e421438  lw          $v0, 0x1438($s2)
    ctx->pc = 0x13de4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 5176)));
    // 0x13de50: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13de50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13de54: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13de54u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13de58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13de58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13de5c: 0x1840001e  blez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x13DE5Cu;
    {
        const bool branch_taken_0x13de5c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13DE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DE5Cu;
            // 0x13de60: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13de5c) {
            ctx->pc = 0x13DED8u;
            goto label_13ded8;
        }
    }
    ctx->pc = 0x13DE64u;
    // 0x13de64: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13de64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13de68: 0x24501480  addiu       $s0, $v0, 0x1480
    ctx->pc = 0x13de68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 5248));
    // 0x13de6c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x13de6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_13de70:
    // 0x13de70: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13DE70u;
    {
        const bool branch_taken_0x13de70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13DE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DE70u;
            // 0x13de74: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13de70) {
            ctx->pc = 0x13DE80u;
            goto label_13de80;
        }
    }
    ctx->pc = 0x13DE78u;
    // 0x13de78: 0xc0502fc  jal         func_140BF0
    ctx->pc = 0x13DE78u;
    SET_GPR_U32(ctx, 31, 0x13DE80u);
    ctx->pc = 0x140BF0u;
    if (runtime->hasFunction(0x140BF0u)) {
        auto targetFn = runtime->lookupFunction(0x140BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DE80u; }
        if (ctx->pc != 0x13DE80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140BF0_0x140bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DE80u; }
        if (ctx->pc != 0x13DE80u) { return; }
    }
    ctx->pc = 0x13DE80u;
label_13de80:
    // 0x13de80: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x13de80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x13de84: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13DE84u;
    {
        const bool branch_taken_0x13de84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13DE88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DE84u;
            // 0x13de88: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13de84) {
            ctx->pc = 0x13DE9Cu;
            goto label_13de9c;
        }
    }
    ctx->pc = 0x13DE8Cu;
    // 0x13de8c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x13de8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13de90: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x13de90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x13de94: 0x60f809  jalr        $v1
    ctx->pc = 0x13DE94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x13DE9Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x13DE9Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DE70u: goto label_13de70;
            case 0x13DE80u: goto label_13de80;
            case 0x13DE9Cu: goto label_13de9c;
            case 0x13DEB0u: goto label_13deb0;
            case 0x13DEB4u: goto label_13deb4;
            case 0x13DEC4u: goto label_13dec4;
            case 0x13DED8u: goto label_13ded8;
            case 0x13DF00u: goto label_13df00;
            case 0x13DF0Cu: goto label_13df0c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13DE9Cu; }
            if (ctx->pc != 0x13DE9Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13DE9Cu;
label_13de9c:
    // 0x13de9c: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x13de9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13dea0: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x13DEA0u;
    {
        const bool branch_taken_0x13dea0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dea0) {
            ctx->pc = 0x13DEA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DEA0u;
            // 0x13dea4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DEB4u;
            goto label_13deb4;
        }
    }
    ctx->pc = 0x13DEA8u;
    // 0x13dea8: 0xc050562  jal         func_141588
    ctx->pc = 0x13DEA8u;
    SET_GPR_U32(ctx, 31, 0x13DEB0u);
    ctx->pc = 0x141588u;
    if (runtime->hasFunction(0x141588u)) {
        auto targetFn = runtime->lookupFunction(0x141588u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEB0u; }
        if (ctx->pc != 0x13DEB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141588_0x141588(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEB0u; }
        if (ctx->pc != 0x13DEB0u) { return; }
    }
    ctx->pc = 0x13DEB0u;
label_13deb0:
    // 0x13deb0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13deb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_13deb4:
    // 0x13deb4: 0x26100018  addiu       $s0, $s0, 0x18
    ctx->pc = 0x13deb4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x13deb8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13deb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13debc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13DEBCu;
    SET_GPR_U32(ctx, 31, 0x13DEC4u);
    ctx->pc = 0x13DEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DEBCu;
            // 0x13dec0: 0x24060018  addiu       $a2, $zero, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEC4u; }
        if (ctx->pc != 0x13DEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEC4u; }
        if (ctx->pc != 0x13DEC4u) { return; }
    }
    ctx->pc = 0x13DEC4u;
label_13dec4:
    // 0x13dec4: 0x8e431438  lw          $v1, 0x1438($s2)
    ctx->pc = 0x13dec4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 5176)));
    // 0x13dec8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13dec8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13decc: 0x223182a  slt         $v1, $s1, $v1
    ctx->pc = 0x13deccu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13ded0: 0x5460ffe7  bnel        $v1, $zero, . + 4 + (-0x19 << 2)
    ctx->pc = 0x13DED0u;
    {
        const bool branch_taken_0x13ded0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13ded0) {
            ctx->pc = 0x13DED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DED0u;
            // 0x13ded4: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DE70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13de70;
        }
    }
    ctx->pc = 0x13DED8u;
label_13ded8:
    // 0x13ded8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ded8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13dedc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x13dedcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13dee0: 0x2451144c  addiu       $s1, $v0, 0x144C
    ctx->pc = 0x13dee0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 5196));
    // 0x13dee4: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x13dee4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13dee8: 0x14640008  bne         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13DEE8u;
    {
        const bool branch_taken_0x13dee8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x13DEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DEE8u;
            // 0x13deec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dee8) {
            ctx->pc = 0x13DF0Cu;
            goto label_13df0c;
        }
    }
    ctx->pc = 0x13DEF0u;
    // 0x13def0: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13def0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13def4: 0x26101444  addiu       $s0, $s0, 0x1444
    ctx->pc = 0x13def4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5188));
    // 0x13def8: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x13DEF8u;
    SET_GPR_U32(ctx, 31, 0x13DF00u);
    ctx->pc = 0x13DEFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DEF8u;
            // 0x13defc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DF00u; }
        if (ctx->pc != 0x13DF00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DF00u; }
        if (ctx->pc != 0x13DF00u) { return; }
    }
    ctx->pc = 0x13DF00u;
label_13df00:
    // 0x13df00: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13df00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13df04: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x13df04u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13df08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13df08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13df0c:
    // 0x13df0c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13df0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13df10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13df10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13df14: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13df14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13df18: 0x3e00008  jr          $ra
    ctx->pc = 0x13DF18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DF1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DF18u;
            // 0x13df1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DE70u: goto label_13de70;
            case 0x13DE80u: goto label_13de80;
            case 0x13DE9Cu: goto label_13de9c;
            case 0x13DEB0u: goto label_13deb0;
            case 0x13DEB4u: goto label_13deb4;
            case 0x13DEC4u: goto label_13dec4;
            case 0x13DED8u: goto label_13ded8;
            case 0x13DF00u: goto label_13df00;
            case 0x13DF0Cu: goto label_13df0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DF20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
