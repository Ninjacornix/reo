#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A7C0
// Address: 0x16a7c0 - 0x16ab80
void sub_0016A7C0_0x16a7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A7C0_0x16a7c0");
#endif

    switch (ctx->pc) {
        case 0x16a7f0u: goto label_16a7f0;
        case 0x16a810u: goto label_16a810;
        case 0x16a878u: goto label_16a878;
        case 0x16a8b4u: goto label_16a8b4;
        case 0x16a8c8u: goto label_16a8c8;
        case 0x16a9f0u: goto label_16a9f0;
        case 0x16aa20u: goto label_16aa20;
        case 0x16aa3cu: goto label_16aa3c;
        case 0x16aa50u: goto label_16aa50;
        case 0x16aaf8u: goto label_16aaf8;
        case 0x16ab1cu: goto label_16ab1c;
        case 0x16ab34u: goto label_16ab34;
        case 0x16ab4cu: goto label_16ab4c;
        default: break;
    }

    ctx->pc = 0x16a7c0u;

    // 0x16a7c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16a7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16a7c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a7c8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16a7c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a7cc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a7ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a7d0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x16a7d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a7d4: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x16a7d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a7d8: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x16a7d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a7dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a7e0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a7e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16a7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16a7e8: 0xc05ab60  jal         func_16AD80
    ctx->pc = 0x16A7E8u;
    SET_GPR_U32(ctx, 31, 0x16A7F0u);
    ctx->pc = 0x16A7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A7E8u;
            // 0x16a7ec: 0xe0882d  daddu       $s1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AD80u;
    if (runtime->hasFunction(0x16AD80u)) {
        auto targetFn = runtime->lookupFunction(0x16AD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A7F0u; }
        if (ctx->pc != 0x16A7F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AD80_0x16ad80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A7F0u; }
        if (ctx->pc != 0x16A7F0u) { return; }
    }
    ctx->pc = 0x16A7F0u;
label_16a7f0:
    // 0x16a7f0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16a7f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a7f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16a7f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a7f8: 0x56020006  bnel        $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A7F8u;
    {
        const bool branch_taken_0x16a7f8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x16a7f8) {
            ctx->pc = 0x16A7FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A7F8u;
            // 0x16a7fc: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A814u;
            goto label_16a814;
        }
    }
    ctx->pc = 0x16A800u;
    // 0x16a800: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A800u;
    {
        const bool branch_taken_0x16a800 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A800u;
            // 0x16a804: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a800) {
            ctx->pc = 0x16A810u;
            goto label_16a810;
        }
    }
    ctx->pc = 0x16A808u;
    // 0x16a808: 0x240f809  jalr        $s2
    ctx->pc = 0x16A808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 18);
        SET_GPR_U32(ctx, 31, 0x16A810u);
        ctx->pc = 0x16A80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A808u;
            // 0x16a80c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16A810u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A7F0u: goto label_16a7f0;
            case 0x16A810u: goto label_16a810;
            case 0x16A814u: goto label_16a814;
            case 0x16A878u: goto label_16a878;
            case 0x16A888u: goto label_16a888;
            case 0x16A89Cu: goto label_16a89c;
            case 0x16A8A8u: goto label_16a8a8;
            case 0x16A8B4u: goto label_16a8b4;
            case 0x16A8C8u: goto label_16a8c8;
            case 0x16A8E8u: goto label_16a8e8;
            case 0x16A8F4u: goto label_16a8f4;
            case 0x16A8F8u: goto label_16a8f8;
            case 0x16A934u: goto label_16a934;
            case 0x16A978u: goto label_16a978;
            case 0x16A9F0u: goto label_16a9f0;
            case 0x16AA00u: goto label_16aa00;
            case 0x16AA20u: goto label_16aa20;
            case 0x16AA28u: goto label_16aa28;
            case 0x16AA30u: goto label_16aa30;
            case 0x16AA3Cu: goto label_16aa3c;
            case 0x16AA50u: goto label_16aa50;
            case 0x16AA70u: goto label_16aa70;
            case 0x16AA78u: goto label_16aa78;
            case 0x16AAC8u: goto label_16aac8;
            case 0x16AAD8u: goto label_16aad8;
            case 0x16AADCu: goto label_16aadc;
            case 0x16AAE0u: goto label_16aae0;
            case 0x16AAF8u: goto label_16aaf8;
            case 0x16AB1Cu: goto label_16ab1c;
            case 0x16AB34u: goto label_16ab34;
            case 0x16AB40u: goto label_16ab40;
            case 0x16AB4Cu: goto label_16ab4c;
            case 0x16AB50u: goto label_16ab50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16A810u; }
            if (ctx->pc != 0x16A810u) { return; }
        }
        }
    }
    ctx->pc = 0x16A810u;
label_16a810:
    // 0x16a810: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x16a810u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16a814:
    // 0x16a814: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a814u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a818: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a818u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a81c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a81cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a820: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a820u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a824: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16a824u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a828: 0x3e00008  jr          $ra
    ctx->pc = 0x16A828u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A82Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A828u;
            // 0x16a82c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A7F0u: goto label_16a7f0;
            case 0x16A810u: goto label_16a810;
            case 0x16A814u: goto label_16a814;
            case 0x16A878u: goto label_16a878;
            case 0x16A888u: goto label_16a888;
            case 0x16A89Cu: goto label_16a89c;
            case 0x16A8A8u: goto label_16a8a8;
            case 0x16A8B4u: goto label_16a8b4;
            case 0x16A8C8u: goto label_16a8c8;
            case 0x16A8E8u: goto label_16a8e8;
            case 0x16A8F4u: goto label_16a8f4;
            case 0x16A8F8u: goto label_16a8f8;
            case 0x16A934u: goto label_16a934;
            case 0x16A978u: goto label_16a978;
            case 0x16A9F0u: goto label_16a9f0;
            case 0x16AA00u: goto label_16aa00;
            case 0x16AA20u: goto label_16aa20;
            case 0x16AA28u: goto label_16aa28;
            case 0x16AA30u: goto label_16aa30;
            case 0x16AA3Cu: goto label_16aa3c;
            case 0x16AA50u: goto label_16aa50;
            case 0x16AA70u: goto label_16aa70;
            case 0x16AA78u: goto label_16aa78;
            case 0x16AAC8u: goto label_16aac8;
            case 0x16AAD8u: goto label_16aad8;
            case 0x16AADCu: goto label_16aadc;
            case 0x16AAE0u: goto label_16aae0;
            case 0x16AAF8u: goto label_16aaf8;
            case 0x16AB1Cu: goto label_16ab1c;
            case 0x16AB34u: goto label_16ab34;
            case 0x16AB40u: goto label_16ab40;
            case 0x16AB4Cu: goto label_16ab4c;
            case 0x16AB50u: goto label_16ab50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A830u;
    // 0x16a830: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16a830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16a834: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a838: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16a838u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a83c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16a83cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x16a840: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a844: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16a844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16a848: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x16a848u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a84c: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x16a84cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x16a850: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x16a850u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a854: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x16a854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x16a858: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x16a858u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a85c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a860: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a864: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16a864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a868: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x16a868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x16a86c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16a86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16a870: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A870u;
    SET_GPR_U32(ctx, 31, 0x16A878u);
    ctx->pc = 0x16A874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A870u;
            // 0x16a874: 0x100882d  daddu       $s1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A878u; }
        if (ctx->pc != 0x16A878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A878u; }
        if (ctx->pc != 0x16A878u) { return; }
    }
    ctx->pc = 0x16A878u;
label_16a878:
    // 0x16a878: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A878u;
    {
        const bool branch_taken_0x16a878 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A87Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A878u;
            // 0x16a87c: 0x26b61ae4  addiu       $s6, $s5, 0x1AE4 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 21), 6884));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a878) {
            ctx->pc = 0x16A888u;
            goto label_16a888;
        }
    }
    ctx->pc = 0x16A880u;
    // 0x16a880: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x16A880u;
    {
        const bool branch_taken_0x16a880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A880u;
            // 0x16a884: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a880) {
            ctx->pc = 0x16A978u;
            goto label_16a978;
        }
    }
    ctx->pc = 0x16A888u;
label_16a888:
    // 0x16a888: 0x2413ffff  addiu       $s3, $zero, -0x1
    ctx->pc = 0x16a888u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16a88c: 0x8ed00008  lw          $s0, 0x8($s6)
    ctx->pc = 0x16a88cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x16a890: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x16a890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x16a894: 0x50530001  beql        $v0, $s3, . + 4 + (0x1 << 2)
    ctx->pc = 0x16A894u;
    {
        const bool branch_taken_0x16a894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        if (branch_taken_0x16a894) {
            ctx->pc = 0x16A898u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A894u;
            // 0x16a898: 0xae12002c  sw          $s2, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A89Cu;
            goto label_16a89c;
        }
    }
    ctx->pc = 0x16A89Cu;
label_16a89c:
    // 0x16a89c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x16a89cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x16a8a0: 0x50530001  beql        $v0, $s3, . + 4 + (0x1 << 2)
    ctx->pc = 0x16A8A0u;
    {
        const bool branch_taken_0x16a8a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        if (branch_taken_0x16a8a0) {
            ctx->pc = 0x16A8A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8A0u;
            // 0x16a8a4: 0xae120024  sw          $s2, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8A8u;
            goto label_16a8a8;
        }
    }
    ctx->pc = 0x16A8A8u;
label_16a8a8:
    // 0x16a8a8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x16a8a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a8ac: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A8ACu;
    SET_GPR_U32(ctx, 31, 0x16A8B4u);
    ctx->pc = 0x16A8B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8ACu;
            // 0x16a8b0: 0x2405001e  addiu       $a1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8B4u; }
        if (ctx->pc != 0x16A8B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8B4u; }
        if (ctx->pc != 0x16A8B4u) { return; }
    }
    ctx->pc = 0x16A8B4u;
label_16a8b4:
    // 0x16a8b4: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x16a8b4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a8b8: 0x1293000e  beq         $s4, $s3, . + 4 + (0xE << 2)
    ctx->pc = 0x16A8B8u;
    {
        const bool branch_taken_0x16a8b8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 19));
        ctx->pc = 0x16A8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8B8u;
            // 0x16a8bc: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8b8) {
            ctx->pc = 0x16A8F4u;
            goto label_16a8f4;
        }
    }
    ctx->pc = 0x16A8C0u;
    // 0x16a8c0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A8C0u;
    SET_GPR_U32(ctx, 31, 0x16A8C8u);
    ctx->pc = 0x16A8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8C0u;
            // 0x16a8c4: 0x24050037  addiu       $a1, $zero, 0x37 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8C8u; }
        if (ctx->pc != 0x16A8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8C8u; }
        if (ctx->pc != 0x16A8C8u) { return; }
    }
    ctx->pc = 0x16A8C8u;
label_16a8c8:
    // 0x16a8c8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16A8C8u;
    {
        const bool branch_taken_0x16a8c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a8c8) {
            ctx->pc = 0x16A8CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8C8u;
            // 0x16a8cc: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8E8u;
            goto label_16a8e8;
        }
    }
    ctx->pc = 0x16A8D0u;
    // 0x16a8d0: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x16a8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16a8d4: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x16a8d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16a8d8: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A8D8u;
    {
        const bool branch_taken_0x16a8d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a8d8) {
            ctx->pc = 0x16A8DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8D8u;
            // 0x16a8dc: 0xae14002c  sw          $s4, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8F4u;
            goto label_16a8f4;
        }
    }
    ctx->pc = 0x16A8E0u;
    // 0x16a8e0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16A8E0u;
    {
        const bool branch_taken_0x16a8e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8E0u;
            // 0x16a8e4: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8e0) {
            ctx->pc = 0x16A8F8u;
            goto label_16a8f8;
        }
    }
    ctx->pc = 0x16A8E8u;
label_16a8e8:
    // 0x16a8e8: 0x56420003  bnel        $s2, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A8E8u;
    {
        const bool branch_taken_0x16a8e8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x16a8e8) {
            ctx->pc = 0x16A8ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8E8u;
            // 0x16a8ec: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8F8u;
            goto label_16a8f8;
        }
    }
    ctx->pc = 0x16A8F0u;
    // 0x16a8f0: 0xae14002c  sw          $s4, 0x2C($s0)
    ctx->pc = 0x16a8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 20));
label_16a8f4:
    // 0x16a8f4: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x16a8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_16a8f8:
    // 0x16a8f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16a8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a8fc: 0x1472001e  bne         $v1, $s2, . + 4 + (0x1E << 2)
    ctx->pc = 0x16A8FCu;
    {
        const bool branch_taken_0x16a8fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 18));
        ctx->pc = 0x16A900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8FCu;
            // 0x16a900: 0xae12001c  sw          $s2, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8fc) {
            ctx->pc = 0x16A978u;
            goto label_16a978;
        }
    }
    ctx->pc = 0x16A904u;
    // 0x16a904: 0x622000b  bltzl       $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x16A904u;
    {
        const bool branch_taken_0x16a904 = (GPR_S64(ctx, 17) < 0);
        if (branch_taken_0x16a904) {
            ctx->pc = 0x16A908u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A904u;
            // 0x16a908: 0x8ec50018  lw          $a1, 0x18($s6) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A934u;
            goto label_16a934;
        }
    }
    ctx->pc = 0x16A90Cu;
    // 0x16a90c: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x16a90cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x16a910: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x16a910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x16a914: 0x223202a  slt         $a0, $s1, $v1
    ctx->pc = 0x16a914u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x16a918: 0x222282a  slt         $a1, $s1, $v0
    ctx->pc = 0x16a918u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16a91c: 0x224180b  movn        $v1, $s1, $a0
    ctx->pc = 0x16a91cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 17));
    // 0x16a920: 0x225100b  movn        $v0, $s1, $a1
    ctx->pc = 0x16a920u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 17));
    // 0x16a924: 0x2238823  subu        $s1, $s1, $v1
    ctx->pc = 0x16a924u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x16a928: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x16a928u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x16a92c: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x16a92cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x16a930: 0x8ec50018  lw          $a1, 0x18($s6)
    ctx->pc = 0x16a930u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
label_16a934:
    // 0x16a934: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x16a934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a938: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x16a938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a93c: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16a93cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a940: 0x3c0382d  daddu       $a3, $fp, $zero
    ctx->pc = 0x16a940u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a944: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x16a944u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a948: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x16a948u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a94c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a94cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a950: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a950u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a954: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a954u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a958: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a958u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a95c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a95cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a960: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16a960u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a964: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16a964u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a968: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16a968u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a96c: 0x805aba8  j           func_16AEA0
    ctx->pc = 0x16A96Cu;
    ctx->pc = 0x16A970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A96Cu;
            // 0x16a970: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AEA0u;
    if (runtime->hasFunction(0x16AEA0u)) {
        auto targetFn = runtime->lookupFunction(0x16AEA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016AEA0_0x16aea0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16A974u;
    // 0x16a974: 0x0  nop
    ctx->pc = 0x16a974u;
    // NOP
label_16a978:
    // 0x16a978: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a978u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a97c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a97cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a980: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a980u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a984: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a984u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a988: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a988u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a98c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16a98cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a990: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16a990u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a994: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16a994u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a998: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x16a998u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a99c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16a99cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a9a0: 0x3e00008  jr          $ra
    ctx->pc = 0x16A9A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A9A0u;
            // 0x16a9a4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A7F0u: goto label_16a7f0;
            case 0x16A810u: goto label_16a810;
            case 0x16A814u: goto label_16a814;
            case 0x16A878u: goto label_16a878;
            case 0x16A888u: goto label_16a888;
            case 0x16A89Cu: goto label_16a89c;
            case 0x16A8A8u: goto label_16a8a8;
            case 0x16A8B4u: goto label_16a8b4;
            case 0x16A8C8u: goto label_16a8c8;
            case 0x16A8E8u: goto label_16a8e8;
            case 0x16A8F4u: goto label_16a8f4;
            case 0x16A8F8u: goto label_16a8f8;
            case 0x16A934u: goto label_16a934;
            case 0x16A978u: goto label_16a978;
            case 0x16A9F0u: goto label_16a9f0;
            case 0x16AA00u: goto label_16aa00;
            case 0x16AA20u: goto label_16aa20;
            case 0x16AA28u: goto label_16aa28;
            case 0x16AA30u: goto label_16aa30;
            case 0x16AA3Cu: goto label_16aa3c;
            case 0x16AA50u: goto label_16aa50;
            case 0x16AA70u: goto label_16aa70;
            case 0x16AA78u: goto label_16aa78;
            case 0x16AAC8u: goto label_16aac8;
            case 0x16AAD8u: goto label_16aad8;
            case 0x16AADCu: goto label_16aadc;
            case 0x16AAE0u: goto label_16aae0;
            case 0x16AAF8u: goto label_16aaf8;
            case 0x16AB1Cu: goto label_16ab1c;
            case 0x16AB34u: goto label_16ab34;
            case 0x16AB40u: goto label_16ab40;
            case 0x16AB4Cu: goto label_16ab4c;
            case 0x16AB50u: goto label_16ab50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A9A8u;
    // 0x16a9a8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16a9a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16a9ac: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x16a9acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x16a9b0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x16a9b0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a9b4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x16a9b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16a9b8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a9b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a9bc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a9bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a9c0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x16a9c0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a9c4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16a9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a9c8: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x16a9c8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a9cc: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x16a9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x16a9d0: 0x100f02d  daddu       $fp, $t0, $zero
    ctx->pc = 0x16a9d0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a9d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a9d8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a9dc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16a9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16a9e0: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x16a9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x16a9e4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16a9e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16a9e8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A9E8u;
    SET_GPR_U32(ctx, 31, 0x16A9F0u);
    ctx->pc = 0x16A9ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A9E8u;
            // 0x16a9ec: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A9F0u; }
        if (ctx->pc != 0x16A9F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A9F0u; }
        if (ctx->pc != 0x16A9F0u) { return; }
    }
    ctx->pc = 0x16A9F0u;
label_16a9f0:
    // 0x16a9f0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A9F0u;
    {
        const bool branch_taken_0x16a9f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A9F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A9F0u;
            // 0x16a9f4: 0x26371ae4  addiu       $s7, $s1, 0x1AE4 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 17), 6884));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a9f0) {
            ctx->pc = 0x16AA00u;
            goto label_16aa00;
        }
    }
    ctx->pc = 0x16A9F8u;
    // 0x16a9f8: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x16A9F8u;
    {
        const bool branch_taken_0x16a9f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A9FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A9F8u;
            // 0x16a9fc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a9f8) {
            ctx->pc = 0x16AB50u;
            goto label_16ab50;
        }
    }
    ctx->pc = 0x16AA00u;
label_16aa00:
    // 0x16aa00: 0x2415ffff  addiu       $s5, $zero, -0x1
    ctx->pc = 0x16aa00u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16aa04: 0x8ef00008  lw          $s0, 0x8($s7)
    ctx->pc = 0x16aa04u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 8)));
    // 0x16aa08: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x16aa08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x16aa0c: 0x54550006  bnel        $v0, $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x16AA0Cu;
    {
        const bool branch_taken_0x16aa0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        if (branch_taken_0x16aa0c) {
            ctx->pc = 0x16AA10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA0Cu;
            // 0x16aa10: 0x8e020020  lw          $v0, 0x20($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AA28u;
            goto label_16aa28;
        }
    }
    ctx->pc = 0x16AA14u;
    // 0x16aa14: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16aa14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aa18: 0xc05aae0  jal         func_16AB80
    ctx->pc = 0x16AA18u;
    SET_GPR_U32(ctx, 31, 0x16AA20u);
    ctx->pc = 0x16AA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA18u;
            // 0x16aa1c: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AB80u;
    if (runtime->hasFunction(0x16AB80u)) {
        auto targetFn = runtime->lookupFunction(0x16AB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA20u; }
        if (ctx->pc != 0x16AA20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AB80_0x16ab80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA20u; }
        if (ctx->pc != 0x16AA20u) { return; }
    }
    ctx->pc = 0x16AA20u;
label_16aa20:
    // 0x16aa20: 0xae020028  sw          $v0, 0x28($s0)
    ctx->pc = 0x16aa20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
    // 0x16aa24: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x16aa24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
label_16aa28:
    // 0x16aa28: 0x50550001  beql        $v0, $s5, . + 4 + (0x1 << 2)
    ctx->pc = 0x16AA28u;
    {
        const bool branch_taken_0x16aa28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 21));
        if (branch_taken_0x16aa28) {
            ctx->pc = 0x16AA2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA28u;
            // 0x16aa2c: 0xae160020  sw          $s6, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AA30u;
            goto label_16aa30;
        }
    }
    ctx->pc = 0x16AA30u;
label_16aa30:
    // 0x16aa30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16aa30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aa34: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16AA34u;
    SET_GPR_U32(ctx, 31, 0x16AA3Cu);
    ctx->pc = 0x16AA38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA34u;
            // 0x16aa38: 0x2405001d  addiu       $a1, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA3Cu; }
        if (ctx->pc != 0x16AA3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA3Cu; }
        if (ctx->pc != 0x16AA3Cu) { return; }
    }
    ctx->pc = 0x16AA3Cu;
label_16aa3c:
    // 0x16aa3c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x16aa3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aa40: 0x12550025  beq         $s2, $s5, . + 4 + (0x25 << 2)
    ctx->pc = 0x16AA40u;
    {
        const bool branch_taken_0x16aa40 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 21));
        ctx->pc = 0x16AA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA40u;
            // 0x16aa44: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aa40) {
            ctx->pc = 0x16AAD8u;
            goto label_16aad8;
        }
    }
    ctx->pc = 0x16AA48u;
    // 0x16aa48: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16AA48u;
    SET_GPR_U32(ctx, 31, 0x16AA50u);
    ctx->pc = 0x16AA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA48u;
            // 0x16aa4c: 0x24050037  addiu       $a1, $zero, 0x37 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA50u; }
        if (ctx->pc != 0x16AA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AA50u; }
        if (ctx->pc != 0x16AA50u) { return; }
    }
    ctx->pc = 0x16AA50u;
label_16aa50:
    // 0x16aa50: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16AA50u;
    {
        const bool branch_taken_0x16aa50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16aa50) {
            ctx->pc = 0x16AA54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA50u;
            // 0x16aa54: 0x8e020020  lw          $v0, 0x20($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AA70u;
            goto label_16aa70;
        }
    }
    ctx->pc = 0x16AA58u;
    // 0x16aa58: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x16aa58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x16aa5c: 0x2c2102a  slt         $v0, $s6, $v0
    ctx->pc = 0x16aa5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16aa60: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16AA60u;
    {
        const bool branch_taken_0x16aa60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16AA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA60u;
            // 0x16aa64: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aa60) {
            ctx->pc = 0x16AA78u;
            goto label_16aa78;
        }
    }
    ctx->pc = 0x16AA68u;
    // 0x16aa68: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x16AA68u;
    {
        const bool branch_taken_0x16aa68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA68u;
            // 0x16aa6c: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aa68) {
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AA70u;
label_16aa70:
    // 0x16aa70: 0x16c2001a  bne         $s6, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x16AA70u;
    {
        const bool branch_taken_0x16aa70 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 2));
        ctx->pc = 0x16AA74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA70u;
            // 0x16aa74: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aa70) {
            ctx->pc = 0x16AADCu;
            goto label_16aadc;
        }
    }
    ctx->pc = 0x16AA78u;
label_16aa78:
    // 0x16aa78: 0x10920018  beq         $a0, $s2, . + 4 + (0x18 << 2)
    ctx->pc = 0x16AA78u;
    {
        const bool branch_taken_0x16aa78 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 18));
        ctx->pc = 0x16AA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA78u;
            // 0x16aa7c: 0x2a620004  slti        $v0, $s3, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aa78) {
            ctx->pc = 0x16AADCu;
            goto label_16aadc;
        }
    }
    ctx->pc = 0x16AA80u;
    // 0x16aa80: 0x54400017  bnel        $v0, $zero, . + 4 + (0x17 << 2)
    ctx->pc = 0x16AA80u;
    {
        const bool branch_taken_0x16aa80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16aa80) {
            ctx->pc = 0x16AA84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA80u;
            // 0x16aa84: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AA88u;
    // 0x16aa88: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x16aa88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x16aa8c: 0x54400014  bnel        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x16AA8Cu;
    {
        const bool branch_taken_0x16aa8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16aa8c) {
            ctx->pc = 0x16AA90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA8Cu;
            // 0x16aa90: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AA94u;
    // 0x16aa94: 0x82820001  lb          $v0, 0x1($s4)
    ctx->pc = 0x16aa94u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x16aa98: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x16AA98u;
    {
        const bool branch_taken_0x16aa98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16aa98) {
            ctx->pc = 0x16AA9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AA98u;
            // 0x16aa9c: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AAA0u;
    // 0x16aaa0: 0x92830002  lbu         $v1, 0x2($s4)
    ctx->pc = 0x16aaa0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x16aaa4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16aaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16aaa8: 0x5462000d  bnel        $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16AAA8u;
    {
        const bool branch_taken_0x16aaa8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x16aaa8) {
            ctx->pc = 0x16AAACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAA8u;
            // 0x16aaac: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AAB0u;
    // 0x16aab0: 0x92830003  lbu         $v1, 0x3($s4)
    ctx->pc = 0x16aab0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 3)));
    // 0x16aab4: 0x240200b3  addiu       $v0, $zero, 0xB3
    ctx->pc = 0x16aab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 179));
    // 0x16aab8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16AAB8u;
    {
        const bool branch_taken_0x16aab8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16AABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAB8u;
            // 0x16aabc: 0x240200b8  addiu       $v0, $zero, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aab8) {
            ctx->pc = 0x16AAC8u;
            goto label_16aac8;
        }
    }
    ctx->pc = 0x16AAC0u;
    // 0x16aac0: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16AAC0u;
    {
        const bool branch_taken_0x16aac0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x16aac0) {
            ctx->pc = 0x16AAC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAC0u;
            // 0x16aac4: 0xae160018  sw          $s6, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AAE0u;
            goto label_16aae0;
        }
    }
    ctx->pc = 0x16AAC8u;
label_16aac8:
    // 0x16aac8: 0xae120028  sw          $s2, 0x28($s0)
    ctx->pc = 0x16aac8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 18));
    // 0x16aacc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16AACCu;
    {
        const bool branch_taken_0x16aacc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AACCu;
            // 0x16aad0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aacc) {
            ctx->pc = 0x16AADCu;
            goto label_16aadc;
        }
    }
    ctx->pc = 0x16AAD4u;
    // 0x16aad4: 0x0  nop
    ctx->pc = 0x16aad4u;
    // NOP
label_16aad8:
    // 0x16aad8: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x16aad8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_16aadc:
    // 0x16aadc: 0xae160018  sw          $s6, 0x18($s0)
    ctx->pc = 0x16aadcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 22));
label_16aae0:
    // 0x16aae0: 0x1496001b  bne         $a0, $s6, . + 4 + (0x1B << 2)
    ctx->pc = 0x16AAE0u;
    {
        const bool branch_taken_0x16aae0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 22));
        ctx->pc = 0x16AAE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAE0u;
            // 0x16aae4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aae0) {
            ctx->pc = 0x16AB50u;
            goto label_16ab50;
        }
    }
    ctx->pc = 0x16AAE8u;
    // 0x16aae8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16aae8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aaec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16aaecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aaf0: 0xc05c6b2  jal         func_171AC8
    ctx->pc = 0x16AAF0u;
    SET_GPR_U32(ctx, 31, 0x16AAF8u);
    ctx->pc = 0x16AAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAF0u;
            // 0x16aaf4: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171AC8u;
    if (runtime->hasFunction(0x171AC8u)) {
        auto targetFn = runtime->lookupFunction(0x171AC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AAF8u; }
        if (ctx->pc != 0x16AAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171AC8_0x171ac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AAF8u; }
        if (ctx->pc != 0x16AAF8u) { return; }
    }
    ctx->pc = 0x16AAF8u;
label_16aaf8:
    // 0x16aaf8: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x16aaf8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aafc: 0x1a600014  blez        $s3, . + 4 + (0x14 << 2)
    ctx->pc = 0x16AAFCu;
    {
        const bool branch_taken_0x16aafc = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x16AB00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AAFCu;
            // 0x16ab00: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aafc) {
            ctx->pc = 0x16AB50u;
            goto label_16ab50;
        }
    }
    ctx->pc = 0x16AB04u;
    // 0x16ab04: 0x8ee50014  lw          $a1, 0x14($s7)
    ctx->pc = 0x16ab04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 20)));
    // 0x16ab08: 0x3c0402d  daddu       $t0, $fp, $zero
    ctx->pc = 0x16ab08u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ab0c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16ab0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ab10: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x16ab10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ab14: 0xc05aba8  jal         func_16AEA0
    ctx->pc = 0x16AB14u;
    SET_GPR_U32(ctx, 31, 0x16AB1Cu);
    ctx->pc = 0x16AB18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB14u;
            // 0x16ab18: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AEA0u;
    if (runtime->hasFunction(0x16AEA0u)) {
        auto targetFn = runtime->lookupFunction(0x16AEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB1Cu; }
        if (ctx->pc != 0x16AB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AEA0_0x16aea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB1Cu; }
        if (ctx->pc != 0x16AB1Cu) { return; }
    }
    ctx->pc = 0x16AB1Cu;
label_16ab1c:
    // 0x16ab1c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16ab1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ab20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ab20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ab24: 0x12020006  beq         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16AB24u;
    {
        const bool branch_taken_0x16ab24 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x16AB28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB24u;
            // 0x16ab28: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ab24) {
            ctx->pc = 0x16AB40u;
            goto label_16ab40;
        }
    }
    ctx->pc = 0x16AB2Cu;
    // 0x16ab2c: 0xc05c6ce  jal         func_171B38
    ctx->pc = 0x16AB2Cu;
    SET_GPR_U32(ctx, 31, 0x16AB34u);
    ctx->pc = 0x16AB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB2Cu;
            // 0x16ab30: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171B38u;
    if (runtime->hasFunction(0x171B38u)) {
        auto targetFn = runtime->lookupFunction(0x171B38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB34u; }
        if (ctx->pc != 0x16AB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171B38_0x171b38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB34u; }
        if (ctx->pc != 0x16AB34u) { return; }
    }
    ctx->pc = 0x16AB34u;
label_16ab34:
    // 0x16ab34: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16AB34u;
    {
        const bool branch_taken_0x16ab34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AB38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB34u;
            // 0x16ab38: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ab34) {
            ctx->pc = 0x16AB50u;
            goto label_16ab50;
        }
    }
    ctx->pc = 0x16AB3Cu;
    // 0x16ab3c: 0x0  nop
    ctx->pc = 0x16ab3cu;
    // NOP
label_16ab40:
    // 0x16ab40: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x16ab40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ab44: 0xc05c79a  jal         func_171E68
    ctx->pc = 0x16AB44u;
    SET_GPR_U32(ctx, 31, 0x16AB4Cu);
    ctx->pc = 0x16AB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB44u;
            // 0x16ab48: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171E68u;
    if (runtime->hasFunction(0x171E68u)) {
        auto targetFn = runtime->lookupFunction(0x171E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB4Cu; }
        if (ctx->pc != 0x16AB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171E68_0x171e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AB4Cu; }
        if (ctx->pc != 0x16AB4Cu) { return; }
    }
    ctx->pc = 0x16AB4Cu;
label_16ab4c:
    // 0x16ab4c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x16ab4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16ab50:
    // 0x16ab50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16ab50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ab54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16ab54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16ab58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16ab58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ab5c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16ab5cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ab60: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16ab60u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ab64: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16ab64u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ab68: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16ab68u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ab6c: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16ab6cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16ab70: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x16ab70u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16ab74: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16ab74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16ab78: 0x3e00008  jr          $ra
    ctx->pc = 0x16AB78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AB78u;
            // 0x16ab7c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A7F0u: goto label_16a7f0;
            case 0x16A810u: goto label_16a810;
            case 0x16A814u: goto label_16a814;
            case 0x16A878u: goto label_16a878;
            case 0x16A888u: goto label_16a888;
            case 0x16A89Cu: goto label_16a89c;
            case 0x16A8A8u: goto label_16a8a8;
            case 0x16A8B4u: goto label_16a8b4;
            case 0x16A8C8u: goto label_16a8c8;
            case 0x16A8E8u: goto label_16a8e8;
            case 0x16A8F4u: goto label_16a8f4;
            case 0x16A8F8u: goto label_16a8f8;
            case 0x16A934u: goto label_16a934;
            case 0x16A978u: goto label_16a978;
            case 0x16A9F0u: goto label_16a9f0;
            case 0x16AA00u: goto label_16aa00;
            case 0x16AA20u: goto label_16aa20;
            case 0x16AA28u: goto label_16aa28;
            case 0x16AA30u: goto label_16aa30;
            case 0x16AA3Cu: goto label_16aa3c;
            case 0x16AA50u: goto label_16aa50;
            case 0x16AA70u: goto label_16aa70;
            case 0x16AA78u: goto label_16aa78;
            case 0x16AAC8u: goto label_16aac8;
            case 0x16AAD8u: goto label_16aad8;
            case 0x16AADCu: goto label_16aadc;
            case 0x16AAE0u: goto label_16aae0;
            case 0x16AAF8u: goto label_16aaf8;
            case 0x16AB1Cu: goto label_16ab1c;
            case 0x16AB34u: goto label_16ab34;
            case 0x16AB40u: goto label_16ab40;
            case 0x16AB4Cu: goto label_16ab4c;
            case 0x16AB50u: goto label_16ab50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AB80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
