#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001050B0
// Address: 0x1050b0 - 0x105300
void sub_001050B0_0x1050b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001050B0_0x1050b0");
#endif

    switch (ctx->pc) {
        case 0x105128u: goto label_105128;
        case 0x105160u: goto label_105160;
        case 0x105180u: goto label_105180;
        case 0x105194u: goto label_105194;
        case 0x105210u: goto label_105210;
        case 0x105238u: goto label_105238;
        case 0x10524cu: goto label_10524c;
        case 0x10525cu: goto label_10525c;
        case 0x105294u: goto label_105294;
        case 0x1052ccu: goto label_1052cc;
        default: break;
    }

    ctx->pc = 0x1050b0u;

    // 0x1050b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1050b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1050b4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1050b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1050b8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1050b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1050bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1050bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1050c0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1050c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1050c4: 0x1620000c  bnez        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x1050C4u;
    {
        const bool branch_taken_0x1050c4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1050C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1050C4u;
            // 0x1050c8: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1050c4) {
            ctx->pc = 0x1050F8u;
            goto label_1050f8;
        }
    }
    ctx->pc = 0x1050CCu;
    // 0x1050cc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1050ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1050d0: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x1050d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x1050d4: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x1050d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x1050d8: 0x24a550b0  addiu       $a1, $a1, 0x50B0
    ctx->pc = 0x1050d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20656));
    // 0x1050dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1050dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1050e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1050e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1050e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1050e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1050e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1050e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1050ec: 0x80419ce  j           func_106738
    ctx->pc = 0x1050ECu;
    ctx->pc = 0x1050F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1050ECu;
            // 0x1050f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106738u;
    if (runtime->hasFunction(0x106738u)) {
        auto targetFn = runtime->lookupFunction(0x106738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00106738_0x106738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1050F4u;
    // 0x1050f4: 0x0  nop
    ctx->pc = 0x1050f4u;
    // NOP
label_1050f8:
    // 0x1050f8: 0x8e230054  lw          $v1, 0x54($s1)
    ctx->pc = 0x1050f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1050fc: 0x54600006  bnel        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1050FCu;
    {
        const bool branch_taken_0x1050fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1050fc) {
            ctx->pc = 0x105100u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1050FCu;
            // 0x105100: 0x8c620038  lw          $v0, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105118u;
            goto label_105118;
        }
    }
    ctx->pc = 0x105104u;
    // 0x105104: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x105104u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105108: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x105108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10510c: 0xae230054  sw          $v1, 0x54($s1)
    ctx->pc = 0x10510cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 84), GPR_U32(ctx, 3));
    // 0x105110: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x105110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
    // 0x105114: 0x0  nop
    ctx->pc = 0x105114u;
    // NOP
label_105118:
    // 0x105118: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x105118u;
    {
        const bool branch_taken_0x105118 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x105118) {
            ctx->pc = 0x10511Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105118u;
            // 0x10511c: 0x8623000c  lh          $v1, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10512Cu;
            goto label_10512c;
        }
    }
    ctx->pc = 0x105120u;
    // 0x105120: 0xc041544  jal         func_105510
    ctx->pc = 0x105120u;
    SET_GPR_U32(ctx, 31, 0x105128u);
    ctx->pc = 0x105124u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105120u;
            // 0x105124: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105128u; }
        if (ctx->pc != 0x105128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105128u; }
        if (ctx->pc != 0x105128u) { return; }
    }
    ctx->pc = 0x105128u;
label_105128:
    // 0x105128: 0x8623000c  lh          $v1, 0xC($s1)
    ctx->pc = 0x105128u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
label_10512c:
    // 0x10512c: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x10512cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x105130: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x105130u;
    {
        const bool branch_taken_0x105130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105130u;
            // 0x105134: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105130) {
            ctx->pc = 0x1051ACu;
            goto label_1051ac;
        }
    }
    ctx->pc = 0x105138u;
    // 0x105138: 0x8e320010  lw          $s2, 0x10($s1)
    ctx->pc = 0x105138u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x10513c: 0x1240001b  beqz        $s2, . + 4 + (0x1B << 2)
    ctx->pc = 0x10513Cu;
    {
        const bool branch_taken_0x10513c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x105140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10513Cu;
            // 0x105140: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10513c) {
            ctx->pc = 0x1051ACu;
            goto label_1051ac;
        }
    }
    ctx->pc = 0x105144u;
    // 0x105144: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x105144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x105148: 0x30630003  andi        $v1, $v1, 0x3
    ctx->pc = 0x105148u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x10514c: 0xae320000  sw          $s2, 0x0($s1)
    ctx->pc = 0x10514cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
    // 0x105150: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x105150u;
    {
        const bool branch_taken_0x105150 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x105154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105150u;
            // 0x105154: 0x528023  subu        $s0, $v0, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105150) {
            ctx->pc = 0x105178u;
            goto label_105178;
        }
    }
    ctx->pc = 0x105158u;
    // 0x105158: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x105158u;
    {
        const bool branch_taken_0x105158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10515Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105158u;
            // 0x10515c: 0x8e240014  lw          $a0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105158) {
            ctx->pc = 0x105178u;
            goto label_105178;
        }
    }
    ctx->pc = 0x105160u;
label_105160:
    // 0x105160: 0x9623000c  lhu         $v1, 0xC($s1)
    ctx->pc = 0x105160u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x105164: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x105164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105168: 0x34630040  ori         $v1, $v1, 0x40
    ctx->pc = 0x105168u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)64);
    // 0x10516c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x10516Cu;
    {
        const bool branch_taken_0x10516c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10516Cu;
            // 0x105170: 0xa623000c  sh          $v1, 0xC($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10516c) {
            ctx->pc = 0x1051ACu;
            goto label_1051ac;
        }
    }
    ctx->pc = 0x105174u;
    // 0x105174: 0x0  nop
    ctx->pc = 0x105174u;
    // NOP
label_105178:
    // 0x105178: 0x1a00000b  blez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x105178u;
    {
        const bool branch_taken_0x105178 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10517Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105178u;
            // 0x10517c: 0xae240008  sw          $a0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105178) {
            ctx->pc = 0x1051A8u;
            goto label_1051a8;
        }
    }
    ctx->pc = 0x105180u;
label_105180:
    // 0x105180: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x105180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x105184: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x105184u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105188: 0x8e24001c  lw          $a0, 0x1C($s1)
    ctx->pc = 0x105188u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x10518c: 0x40f809  jalr        $v0
    ctx->pc = 0x10518Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x105194u);
        ctx->pc = 0x105190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10518Cu;
            // 0x105190: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x105194u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1050F8u: goto label_1050f8;
            case 0x105118u: goto label_105118;
            case 0x105128u: goto label_105128;
            case 0x10512Cu: goto label_10512c;
            case 0x105160u: goto label_105160;
            case 0x105178u: goto label_105178;
            case 0x105180u: goto label_105180;
            case 0x105194u: goto label_105194;
            case 0x1051A8u: goto label_1051a8;
            case 0x1051ACu: goto label_1051ac;
            case 0x105210u: goto label_105210;
            case 0x105238u: goto label_105238;
            case 0x105248u: goto label_105248;
            case 0x10524Cu: goto label_10524c;
            case 0x10525Cu: goto label_10525c;
            case 0x105278u: goto label_105278;
            case 0x10527Cu: goto label_10527c;
            case 0x105294u: goto label_105294;
            case 0x1052CCu: goto label_1052cc;
            case 0x1052D8u: goto label_1052d8;
            case 0x1052DCu: goto label_1052dc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x105194u; }
            if (ctx->pc != 0x105194u) { return; }
        }
        }
    }
    ctx->pc = 0x105194u;
label_105194:
    // 0x105194: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x105194u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105198: 0x1860fff1  blez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x105198u;
    {
        const bool branch_taken_0x105198 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x10519Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105198u;
            // 0x10519c: 0x2038023  subu        $s0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105198) {
            ctx->pc = 0x105160u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105160;
        }
    }
    ctx->pc = 0x1051A0u;
    // 0x1051a0: 0x1e00fff7  bgtz        $s0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1051A0u;
    {
        const bool branch_taken_0x1051a0 = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x1051A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1051A0u;
            // 0x1051a4: 0x2439021  addu        $s2, $s2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1051a0) {
            ctx->pc = 0x105180u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105180;
        }
    }
    ctx->pc = 0x1051A8u;
label_1051a8:
    // 0x1051a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1051a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1051ac:
    // 0x1051ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1051acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1051b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1051b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1051b4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1051b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1051b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1051b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1051bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1051BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1051C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1051BCu;
            // 0x1051c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1050F8u: goto label_1050f8;
            case 0x105118u: goto label_105118;
            case 0x105128u: goto label_105128;
            case 0x10512Cu: goto label_10512c;
            case 0x105160u: goto label_105160;
            case 0x105178u: goto label_105178;
            case 0x105180u: goto label_105180;
            case 0x105194u: goto label_105194;
            case 0x1051A8u: goto label_1051a8;
            case 0x1051ACu: goto label_1051ac;
            case 0x105210u: goto label_105210;
            case 0x105238u: goto label_105238;
            case 0x105248u: goto label_105248;
            case 0x10524Cu: goto label_10524c;
            case 0x10525Cu: goto label_10525c;
            case 0x105278u: goto label_105278;
            case 0x10527Cu: goto label_10527c;
            case 0x105294u: goto label_105294;
            case 0x1052CCu: goto label_1052cc;
            case 0x1052D8u: goto label_1052d8;
            case 0x1052DCu: goto label_1052dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1051C4u;
    // 0x1051c4: 0x0  nop
    ctx->pc = 0x1051c4u;
    // NOP
    // 0x1051c8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1051c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1051cc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1051ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1051d0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1051d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1051d4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1051d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1051d8: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1051d8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1051dc: 0x2a620002  slti        $v0, $s3, 0x2
    ctx->pc = 0x1051dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1051e0: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x1051e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x1051e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1051e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1051e8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1051e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1051ec: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1051ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1051f0: 0x2a0a02d  daddu       $s4, $s5, $zero
    ctx->pc = 0x1051f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1051f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1051f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1051f8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1051f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1051fc: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1051FCu;
    {
        const bool branch_taken_0x1051fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1051FCu;
            // 0x105200: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1051fc) {
            ctx->pc = 0x105248u;
            goto label_105248;
        }
    }
    ctx->pc = 0x105204u;
    // 0x105204: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x105204u;
    {
        const bool branch_taken_0x105204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105204u;
            // 0x105208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105204) {
            ctx->pc = 0x1052DCu;
            goto label_1052dc;
        }
    }
    ctx->pc = 0x10520Cu;
    // 0x10520c: 0x0  nop
    ctx->pc = 0x10520cu;
    // NOP
label_105210:
    // 0x105210: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x105210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x105214: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x105214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x105218: 0x728023  subu        $s0, $v1, $s2
    ctx->pc = 0x105218u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x10521c: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x10521cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x105220: 0x501023  subu        $v0, $v0, $s0
    ctx->pc = 0x105220u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x105224: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x105224u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105228: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x105228u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x10522c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10522cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105230: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x105230u;
    SET_GPR_U32(ctx, 31, 0x105238u);
    ctx->pc = 0x105234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105230u;
            // 0x105234: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105238u; }
        if (ctx->pc != 0x105238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105238u; }
        if (ctx->pc != 0x105238u) { return; }
    }
    ctx->pc = 0x105238u;
label_105238:
    // 0x105238: 0x2901821  addu        $v1, $s4, $s0
    ctx->pc = 0x105238u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x10523c: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x10523Cu;
    {
        const bool branch_taken_0x10523c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10523Cu;
            // 0x105240: 0xa0600000  sb          $zero, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10523c) {
            ctx->pc = 0x1052D8u;
            goto label_1052d8;
        }
    }
    ctx->pc = 0x105244u;
    // 0x105244: 0x0  nop
    ctx->pc = 0x105244u;
    // NOP
label_105248:
    // 0x105248: 0x8e300004  lw          $s0, 0x4($s1)
    ctx->pc = 0x105248u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_10524c:
    // 0x10524c: 0x5600000b  bnel        $s0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x10524Cu;
    {
        const bool branch_taken_0x10524c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x10524c) {
            ctx->pc = 0x105250u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10524Cu;
            // 0x105250: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10527Cu;
            goto label_10527c;
        }
    }
    ctx->pc = 0x105254u;
    // 0x105254: 0xc042814  jal         func_10A050
    ctx->pc = 0x105254u;
    SET_GPR_U32(ctx, 31, 0x10525Cu);
    ctx->pc = 0x105258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105254u;
            // 0x105258: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10525Cu; }
        if (ctx->pc != 0x10525Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10525Cu; }
        if (ctx->pc != 0x10525Cu) { return; }
    }
    ctx->pc = 0x10525Cu;
label_10525c:
    // 0x10525c: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10525Cu;
    {
        const bool branch_taken_0x10525c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10525c) {
            ctx->pc = 0x105260u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10525Cu;
            // 0x105260: 0x8e300004  lw          $s0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105278u;
            goto label_105278;
        }
    }
    ctx->pc = 0x105264u;
    // 0x105264: 0x5695001c  bnel        $s4, $s5, . + 4 + (0x1C << 2)
    ctx->pc = 0x105264u;
    {
        const bool branch_taken_0x105264 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 21));
        if (branch_taken_0x105264) {
            ctx->pc = 0x105268u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105264u;
            // 0x105268: 0xa2800000  sb          $zero, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1052D8u;
            goto label_1052d8;
        }
    }
    ctx->pc = 0x10526Cu;
    // 0x10526c: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x10526Cu;
    {
        const bool branch_taken_0x10526c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10526Cu;
            // 0x105270: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10526c) {
            ctx->pc = 0x1052DCu;
            goto label_1052dc;
        }
    }
    ctx->pc = 0x105274u;
    // 0x105274: 0x0  nop
    ctx->pc = 0x105274u;
    // NOP
label_105278:
    // 0x105278: 0x8e320000  lw          $s2, 0x0($s1)
    ctx->pc = 0x105278u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_10527c:
    // 0x10527c: 0x270102b  sltu        $v0, $s3, $s0
    ctx->pc = 0x10527cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x105280: 0x262800b  movn        $s0, $s3, $v0
    ctx->pc = 0x105280u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 19));
    // 0x105284: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x105284u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x105288: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x105288u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10528c: 0xc041e4e  jal         func_107938
    ctx->pc = 0x10528Cu;
    SET_GPR_U32(ctx, 31, 0x105294u);
    ctx->pc = 0x105290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10528Cu;
            // 0x105290: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107938u;
    if (runtime->hasFunction(0x107938u)) {
        auto targetFn = runtime->lookupFunction(0x107938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105294u; }
        if (ctx->pc != 0x105294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107938_0x107938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105294u; }
        if (ctx->pc != 0x105294u) { return; }
    }
    ctx->pc = 0x105294u;
label_105294:
    // 0x105294: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x105294u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105298: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x105298u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10529c: 0x2709823  subu        $s3, $s3, $s0
    ctx->pc = 0x10529cu;
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x1052a0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1052a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1052a4: 0x1460ffda  bnez        $v1, . + 4 + (-0x26 << 2)
    ctx->pc = 0x1052A4u;
    {
        const bool branch_taken_0x1052a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1052A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1052A4u;
            // 0x1052a8: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1052a4) {
            ctx->pc = 0x105210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105210;
        }
    }
    ctx->pc = 0x1052ACu;
    // 0x1052ac: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1052acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1052b0: 0x290a021  addu        $s4, $s4, $s0
    ctx->pc = 0x1052b0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x1052b4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1052b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1052b8: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1052b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1052bc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1052bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1052c0: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1052c0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1052c4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1052C4u;
    SET_GPR_U32(ctx, 31, 0x1052CCu);
    ctx->pc = 0x1052C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1052C4u;
            // 0x1052c8: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1052CCu; }
        if (ctx->pc != 0x1052CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1052CCu; }
        if (ctx->pc != 0x1052CCu) { return; }
    }
    ctx->pc = 0x1052CCu;
label_1052cc:
    // 0x1052cc: 0x5660ffdf  bnel        $s3, $zero, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1052CCu;
    {
        const bool branch_taken_0x1052cc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x1052cc) {
            ctx->pc = 0x1052D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1052CCu;
            // 0x1052d0: 0x8e300004  lw          $s0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10524Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10524c;
        }
    }
    ctx->pc = 0x1052D4u;
    // 0x1052d4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1052d4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
label_1052d8:
    // 0x1052d8: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x1052d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_1052dc:
    // 0x1052dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1052dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1052e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1052e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1052e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1052e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1052e8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1052e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1052ec: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1052ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1052f0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1052f0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1052f4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1052f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1052f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1052F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1052FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1052F8u;
            // 0x1052fc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1050F8u: goto label_1050f8;
            case 0x105118u: goto label_105118;
            case 0x105128u: goto label_105128;
            case 0x10512Cu: goto label_10512c;
            case 0x105160u: goto label_105160;
            case 0x105178u: goto label_105178;
            case 0x105180u: goto label_105180;
            case 0x105194u: goto label_105194;
            case 0x1051A8u: goto label_1051a8;
            case 0x1051ACu: goto label_1051ac;
            case 0x105210u: goto label_105210;
            case 0x105238u: goto label_105238;
            case 0x105248u: goto label_105248;
            case 0x10524Cu: goto label_10524c;
            case 0x10525Cu: goto label_10525c;
            case 0x105278u: goto label_105278;
            case 0x10527Cu: goto label_10527c;
            case 0x105294u: goto label_105294;
            case 0x1052CCu: goto label_1052cc;
            case 0x1052D8u: goto label_1052d8;
            case 0x1052DCu: goto label_1052dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105300u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
