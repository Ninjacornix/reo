#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001371F0
// Address: 0x1371f0 - 0x1372b0
void sub_001371F0_0x1371f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001371F0_0x1371f0");
#endif

    switch (ctx->pc) {
        case 0x13721cu: goto label_13721c;
        case 0x137240u: goto label_137240;
        case 0x137264u: goto label_137264;
        case 0x137284u: goto label_137284;
        default: break;
    }

    ctx->pc = 0x1371f0u;

    // 0x1371f0: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x1371f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x1371f4: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x1371f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x1371f8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1371f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1371fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137200: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x137200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x137204: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x137204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x137208: 0xffb40280  sd          $s4, 0x280($sp)
    ctx->pc = 0x137208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 20));
    // 0x13720c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13720cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x137210: 0xffbf0288  sd          $ra, 0x288($sp)
    ctx->pc = 0x137210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
    // 0x137214: 0xc04d558  jal         func_135560
    ctx->pc = 0x137214u;
    SET_GPR_U32(ctx, 31, 0x13721Cu);
    ctx->pc = 0x137218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137214u;
            // 0x137218: 0xa0a02d  daddu       $s4, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13721Cu; }
        if (ctx->pc != 0x13721Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13721Cu; }
        if (ctx->pc != 0x13721Cu) { return; }
    }
    ctx->pc = 0x13721Cu;
label_13721c:
    // 0x13721c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x13721cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137220: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x137220u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137224: 0x27b30130  addiu       $s3, $sp, 0x130
    ctx->pc = 0x137224u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x137228: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x137228u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13722c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x13722cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137230: 0x12200017  beqz        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x137230u;
    {
        const bool branch_taken_0x137230 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x137234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137230u;
            // 0x137234: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137230) {
            ctx->pc = 0x137290u;
            goto label_137290;
        }
    }
    ctx->pc = 0x137238u;
    // 0x137238: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x137238u;
    SET_GPR_U32(ctx, 31, 0x137240u);
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137240u; }
        if (ctx->pc != 0x137240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137240u; }
        if (ctx->pc != 0x137240u) { return; }
    }
    ctx->pc = 0x137240u;
label_137240:
    // 0x137240: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x137240u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137244: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x137244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x137248: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x137248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13724c: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x13724cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137250: 0x240500cc  addiu       $a1, $zero, 0xCC
    ctx->pc = 0x137250u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
    // 0x137254: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x137254u;
    {
        const bool branch_taken_0x137254 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x137258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137254u;
            // 0x137258: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137254) {
            ctx->pc = 0x137290u;
            goto label_137290;
        }
    }
    ctx->pc = 0x13725Cu;
    // 0x13725c: 0x60f809  jalr        $v1
    ctx->pc = 0x13725Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x137264u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x137264u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137264u; }
            if (ctx->pc != 0x137264u) { return; }
        }
        }
    }
    ctx->pc = 0x137264u;
label_137264:
    // 0x137264: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x137264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137268: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x137268u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13726c: 0x8e220060  lw          $v0, 0x60($s1)
    ctx->pc = 0x13726cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x137270: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x137270u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137274: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x137274u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137278: 0x240500cd  addiu       $a1, $zero, 0xCD
    ctx->pc = 0x137278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 205));
    // 0x13727c: 0x40f809  jalr        $v0
    ctx->pc = 0x13727Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x137284u);
        ctx->pc = 0x137280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13727Cu;
            // 0x137280: 0x10803c  dsll32      $s0, $s0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x137284u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137284u; }
            if (ctx->pc != 0x137284u) { return; }
        }
        }
    }
    ctx->pc = 0x137284u;
label_137284:
    // 0x137284: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x137284u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x137288: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x137288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x13728c: 0x202102d  daddu       $v0, $s0, $v0
    ctx->pc = 0x13728cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_137290:
    // 0x137290: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x137290u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x137294: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x137294u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x137298: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x137298u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13729c: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x13729cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x1372a0: 0xdfb40280  ld          $s4, 0x280($sp)
    ctx->pc = 0x1372a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x1372a4: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x1372a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x1372a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1372A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1372ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372A8u;
            // 0x1372ac: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1372B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
