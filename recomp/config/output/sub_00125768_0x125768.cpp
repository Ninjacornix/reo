#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125768
// Address: 0x125768 - 0x125878
void sub_00125768_0x125768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125768_0x125768");
#endif

    switch (ctx->pc) {
        case 0x125840u: goto label_125840;
        case 0x125854u: goto label_125854;
        default: break;
    }

    ctx->pc = 0x125768u;

label_125768:
    // 0x125768: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125768u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12576c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12576cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x125770: 0x84830098  lh          $v1, 0x98($a0)
    ctx->pc = 0x125770u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 152)));
    // 0x125774: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x125774u;
    {
        const bool branch_taken_0x125774 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x125778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125774u;
            // 0x125778: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125774) {
            ctx->pc = 0x125788u;
            goto label_125788;
        }
    }
    ctx->pc = 0x12577Cu;
    // 0x12577c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12577cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125780: 0x80495a6  j           func_125698
    ctx->pc = 0x125780u;
    ctx->pc = 0x125784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125780u;
            // 0x125784: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125698u;
    if (runtime->hasFunction(0x125698u)) {
        auto targetFn = runtime->lookupFunction(0x125698u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125698_0x125698(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125788u;
label_125788:
    // 0x125788: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x125788u;
    {
        const bool branch_taken_0x125788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x125788) {
            ctx->pc = 0x12578Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125788u;
            // 0x12578c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1257A0u;
            goto label_1257a0;
        }
    }
    ctx->pc = 0x125790u;
    // 0x125790: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x125790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125794: 0x8048c22  j           func_123088
    ctx->pc = 0x125794u;
    ctx->pc = 0x125798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125794u;
            // 0x125798: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123088u;
    if (runtime->hasFunction(0x123088u)) {
        auto targetFn = runtime->lookupFunction(0x123088u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123088_0x123088(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12579Cu;
    // 0x12579c: 0x0  nop
    ctx->pc = 0x12579cu;
    // NOP
label_1257a0:
    // 0x1257a0: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1257A0u;
    {
        const bool branch_taken_0x1257a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1257a0) {
            ctx->pc = 0x1257A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1257A0u;
            // 0x1257a4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1257B8u;
            goto label_1257b8;
        }
    }
    ctx->pc = 0x1257A8u;
    // 0x1257a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1257a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1257ac: 0x80496a4  j           func_125A90
    ctx->pc = 0x1257ACu;
    ctx->pc = 0x1257B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1257ACu;
            // 0x1257b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125A90u;
    if (runtime->hasFunction(0x125A90u)) {
        auto targetFn = runtime->lookupFunction(0x125A90u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125A90_0x125a90(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1257B4u;
    // 0x1257b4: 0x0  nop
    ctx->pc = 0x1257b4u;
    // NOP
label_1257b8:
    // 0x1257b8: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1257B8u;
    {
        const bool branch_taken_0x1257b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1257b8) {
            ctx->pc = 0x1257BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1257B8u;
            // 0x1257bc: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1257D0u;
            goto label_1257d0;
        }
    }
    ctx->pc = 0x1257C0u;
    // 0x1257c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1257c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1257c4: 0x8048e86  j           func_123A18
    ctx->pc = 0x1257C4u;
    ctx->pc = 0x1257C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1257C4u;
            // 0x1257c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123A18u;
    if (runtime->hasFunction(0x123A18u)) {
        auto targetFn = runtime->lookupFunction(0x123A18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123A18_0x123a18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1257CCu;
    // 0x1257cc: 0x0  nop
    ctx->pc = 0x1257ccu;
    // NOP
label_1257d0:
    // 0x1257d0: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1257D0u;
    {
        const bool branch_taken_0x1257d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1257d0) {
            ctx->pc = 0x1257D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1257D0u;
            // 0x1257d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1257E8u;
            goto label_1257e8;
        }
    }
    ctx->pc = 0x1257D8u;
    // 0x1257d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1257d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1257dc: 0x8049120  j           func_124480
    ctx->pc = 0x1257DCu;
    ctx->pc = 0x1257E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1257DCu;
            // 0x1257e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124480u;
    if (runtime->hasFunction(0x124480u)) {
        auto targetFn = runtime->lookupFunction(0x124480u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124480_0x124480(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1257E4u;
    // 0x1257e4: 0x0  nop
    ctx->pc = 0x1257e4u;
    // NOP
label_1257e8:
    // 0x1257e8: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1257E8u;
    {
        const bool branch_taken_0x1257e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1257e8) {
            ctx->pc = 0x1257ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1257E8u;
            // 0x1257ec: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125800u;
            goto label_125800;
        }
    }
    ctx->pc = 0x1257F0u;
    // 0x1257f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1257f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1257f4: 0x804991e  j           func_126478
    ctx->pc = 0x1257F4u;
    ctx->pc = 0x1257F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1257F4u;
            // 0x1257f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126478u;
    if (runtime->hasFunction(0x126478u)) {
        auto targetFn = runtime->lookupFunction(0x126478u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00126478_0x126478(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1257FCu;
    // 0x1257fc: 0x0  nop
    ctx->pc = 0x1257fcu;
    // NOP
label_125800:
    // 0x125800: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x125800u;
    {
        const bool branch_taken_0x125800 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x125804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125800u;
            // 0x125804: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125800) {
            ctx->pc = 0x125810u;
            goto label_125810;
        }
    }
    ctx->pc = 0x125808u;
    // 0x125808: 0x8048bb0  j           func_122EC0
    ctx->pc = 0x125808u;
    ctx->pc = 0x12580Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125808u;
            // 0x12580c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122EC0u;
    if (runtime->hasFunction(0x122EC0u)) {
        auto targetFn = runtime->lookupFunction(0x122EC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122EC0_0x122ec0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125810u;
label_125810:
    // 0x125810: 0x3e00008  jr          $ra
    ctx->pc = 0x125810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125810u;
            // 0x125814: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125768u: goto label_125768;
            case 0x125788u: goto label_125788;
            case 0x1257A0u: goto label_1257a0;
            case 0x1257B8u: goto label_1257b8;
            case 0x1257D0u: goto label_1257d0;
            case 0x1257E8u: goto label_1257e8;
            case 0x125800u: goto label_125800;
            case 0x125810u: goto label_125810;
            case 0x125840u: goto label_125840;
            case 0x125854u: goto label_125854;
            case 0x125858u: goto label_125858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125818u;
    // 0x125818: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12581c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12581cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x125820: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125824: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125828: 0x2450b958  addiu       $s0, $v0, -0x46A8
    ctx->pc = 0x125828u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949208));
    // 0x12582c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12582cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125830: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x125830u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x125834: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125838: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x125838u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12583c: 0x0  nop
    ctx->pc = 0x12583cu;
    // NOP
label_125840:
    // 0x125840: 0x86020000  lh          $v0, 0x0($s0)
    ctx->pc = 0x125840u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x125844: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x125844u;
    {
        const bool branch_taken_0x125844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x125844) {
            ctx->pc = 0x125848u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125844u;
            // 0x125848: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125858u;
            goto label_125858;
        }
    }
    ctx->pc = 0x12584Cu;
    // 0x12584c: 0xc0495da  jal         func_125768
    ctx->pc = 0x12584Cu;
    SET_GPR_U32(ctx, 31, 0x125854u);
    ctx->pc = 0x125850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12584Cu;
            // 0x125850: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125768u;
    goto label_125768;
    ctx->pc = 0x125854u;
label_125854:
    // 0x125854: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x125854u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_125858:
    // 0x125858: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125858u;
    {
        const bool branch_taken_0x125858 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x12585Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125858u;
            // 0x12585c: 0x261000e4  addiu       $s0, $s0, 0xE4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 228));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125858) {
            ctx->pc = 0x125840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125840;
        }
    }
    ctx->pc = 0x125860u;
    // 0x125860: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125864: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125864u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125868: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x125868u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12586c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12586cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125870: 0x3e00008  jr          $ra
    ctx->pc = 0x125870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125870u;
            // 0x125874: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125768u: goto label_125768;
            case 0x125788u: goto label_125788;
            case 0x1257A0u: goto label_1257a0;
            case 0x1257B8u: goto label_1257b8;
            case 0x1257D0u: goto label_1257d0;
            case 0x1257E8u: goto label_1257e8;
            case 0x125800u: goto label_125800;
            case 0x125810u: goto label_125810;
            case 0x125840u: goto label_125840;
            case 0x125854u: goto label_125854;
            case 0x125858u: goto label_125858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125878u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
